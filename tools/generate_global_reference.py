from __future__ import annotations

import argparse
import csv
import math
import re
import struct
from pathlib import Path

from common import ensure_dir, format_hex, load_binaries, load_pe_image, repo_path


GLOBAL_NAME_RE = re.compile(r"\b((?:DAT|PTR)_[0-9A-Fa-f]{8}|(?:s|u)_[A-Za-z0-9_]+_[0-9A-Fa-f]{8})\b")

HINT_SPECS: list[tuple[str, str, int]] = [
    ("double ptr", "double", 8),
    ("float ptr", "float", 4),
    ("qword ptr", "qword", 8),
    ("dword ptr", "dword", 4),
    ("word ptr", "word", 2),
    ("byte ptr", "byte", 1),
]


def parse_va_from_name(name: str) -> int:
    return int(name.rsplit("_", 1)[1], 16)


def section_flags(characteristics: int) -> tuple[bool, bool]:
    executable = (characteristics & 0x20000000) != 0
    writable = (characteristics & 0x80000000) != 0
    return executable, writable


def infer_hint(line: str) -> tuple[str, int] | None:
    lowered = line.lower()
    for needle, hint, size in HINT_SPECS:
        if needle in lowered:
            return hint, size
    if "offset " in lowered:
        return "address", 4
    return None


def read_raw_bytes(image, va: int, size: int) -> bytes:
    try:
        return image.read_va_range(va, va + size - 1)
    except Exception:
        return b""


def read_c_string(image, va: int, max_length: int = 256) -> bytes:
    data = bytearray()
    for offset in range(max_length):
        raw = read_raw_bytes(image, va + offset, 1)
        if len(raw) != 1:
            break
        data.extend(raw)
        if raw == b"\x00":
            break
    return bytes(data)


def format_byte_list(data: bytes) -> str:
    return ", ".join(f"0x{byte:02X}" for byte in data)


def choose_emit_type(entry: dict[str, object]) -> tuple[str, str, str]:
    primary_name = str(entry["primary_name"])
    hints = set(str(hint) for hint in entry["hints"])
    raw_bytes = bytes(entry["raw_bytes"])
    if str(entry["section_flags"]).startswith("x"):
        return "", "", ""

    if primary_name.startswith("s_"):
        return "const char", str(len(raw_bytes)), "array"
    if primary_name.startswith("u_"):
        return "const unsigned char", str(len(raw_bytes)), "array"
    if primary_name.startswith("PTR_") or hints == {"address"} or hints == {"dword", "address"}:
        return "void*", "", "scalar"
    if hints == {"float"}:
        return "float", "", "scalar"
    if hints == {"double"}:
        return "double", "", "scalar"
    if hints == {"byte"}:
        return "unsigned char", "", "scalar"
    if hints == {"word"}:
        return "unsigned short", "", "scalar"
    if hints == {"dword"}:
        return "unsigned int", "", "scalar"
    if hints == {"qword"}:
        return "unsigned __int64", "", "scalar"
    return "", "", ""


def choose_initializer(entry: dict[str, object]) -> str:
    emit_type = str(entry["emit_c_type"])
    emit_mode = str(entry["emit_mode"])
    raw_bytes = bytes(entry["raw_bytes"])

    if emit_mode == "array":
        return "{ " + format_byte_list(raw_bytes) + " }"

    if emit_type == "float" and len(raw_bytes) == 4:
        value = struct.unpack("<f", raw_bytes)[0]
        if math.isfinite(value):
            text = format(value, ".9g")
            if "." not in text and "e" not in text and "E" not in text:
                text += ".0"
            return text + "f"
    if emit_type == "double" and len(raw_bytes) == 8:
        value = struct.unpack("<d", raw_bytes)[0]
        if math.isfinite(value):
            text = format(value, ".17g")
            if "." not in text and "e" not in text and "E" not in text:
                text += ".0"
            return text
    if emit_type == "void*" and len(raw_bytes) == 4:
        value = struct.unpack("<I", raw_bytes)[0]
        return f"(void*)0x{value:08X}"
    if emit_type == "unsigned char" and len(raw_bytes) == 1:
        return f"0x{raw_bytes[0]:02X}"
    if emit_type == "unsigned short" and len(raw_bytes) == 2:
        value = struct.unpack("<H", raw_bytes)[0]
        return f"0x{value:04X}"
    if emit_type == "unsigned int" and len(raw_bytes) == 4:
        value = struct.unpack("<I", raw_bytes)[0]
        return f"0x{value:08X}u"
    if emit_type == "unsigned __int64" and len(raw_bytes) == 8:
        value = struct.unpack("<Q", raw_bytes)[0]
        return f"0x{value:016X}ui64"
    return ""


def build_global_rows(listing_path: Path, image) -> list[dict[str, object]]:
    entries: dict[int, dict[str, object]] = {}
    lines = listing_path.read_text(encoding="utf-8", errors="replace").splitlines()

    for line in lines:
        hint_info = infer_hint(line)
        for match in GLOBAL_NAME_RE.finditer(line):
            name = match.group(1)
            va = parse_va_from_name(name)
            if va < image.image_base:
                continue

            section = image.section_for_va(va)
            if section is None:
                continue

            entry = entries.setdefault(
                va,
                {
                    "va": format_hex(va),
                    "primary_name": name,
                    "aliases": set(),
                    "hints": set(),
                    "references": [],
                    "section_name": section.name,
                    "section_start": format_hex(image.image_base + section.virtual_address),
                    "section_end": format_hex(image.image_base + section.end_virtual_address - 1),
                    "raw_bytes": b"",
                    "size_bytes": 0,
                },
            )

            entry["aliases"].add(name)
            if name.startswith(("s_", "u_")) and not str(entry["primary_name"]).startswith(("s_", "u_")):
                entry["primary_name"] = name

            if len(entry["references"]) < 5:
                entry["references"].append(line.rstrip())

            if hint_info is not None:
                hint, size = hint_info
                entry["hints"].add(hint)
                if size > int(entry["size_bytes"]):
                    entry["size_bytes"] = size

    rows: list[dict[str, object]] = []
    for va, entry in sorted(entries.items()):
        primary_name = str(entry["primary_name"])
        if primary_name.startswith(("s_", "u_")):
            raw_bytes = read_c_string(image, va)
            if not raw_bytes:
                raw_bytes = b"\x00"
            entry["raw_bytes"] = raw_bytes
            entry["size_bytes"] = len(raw_bytes)
        else:
            if int(entry["size_bytes"]) <= 0:
                entry["size_bytes"] = 4 if primary_name.startswith("PTR_") else 0
            size_bytes = int(entry["size_bytes"])
            entry["raw_bytes"] = read_raw_bytes(image, va, size_bytes) if size_bytes > 0 else b""

        executable, writable = section_flags(image.section_for_va(va).characteristics)
        entry["section_flags"] = ("x" if executable else "-") + ("w" if writable else "r")
        entry["emit_c_type"], entry["emit_array_length"], entry["emit_mode"] = choose_emit_type(entry)
        entry["emit_initializer"] = choose_initializer(entry) if entry["emit_c_type"] else ""
        entry["byte_preview"] = bytes(entry["raw_bytes"][:16]).hex()
        rows.append(entry)

    return rows


def write_global_packets(rows: list[dict[str, object]], packet_root: Path) -> None:
    ensure_dir(packet_root)
    for row in rows:
        va = str(row["va"])
        slug = f"{va}_{str(row['primary_name'])}"
        packet_path = packet_root / f"{slug}.txt"
        packet_lines = [
            f"VA: {va}",
            f"PrimaryName: {row['primary_name']}",
            f"Aliases: {', '.join(sorted(str(alias) for alias in row['aliases']))}",
            f"Section: {row['section_name']}",
            f"SectionFlags: {row['section_flags']}",
            f"SizeBytes: {row['size_bytes']}",
            f"Hints: {', '.join(sorted(str(hint) for hint in row['hints'])) or '<none>'}",
            f"EmitType: {row['emit_c_type'] or '<skip>'}",
            f"EmitInitializer: {row['emit_initializer'] or '<none>'}",
            f"BytePreview: {row['byte_preview'] or '<none>'}",
            "",
            "=== FirstReferences ===",
        ]
        packet_lines.extend(str(reference) for reference in row["references"])
        packet_lines.append("")
        packet_lines.append("=== RawBytes ===")
        packet_lines.append(format_byte_list(bytes(row["raw_bytes"])) or "<none>")
        packet_path.write_text("\n".join(packet_lines) + "\n", encoding="utf-8")


def write_section_inventory(image, data_root: Path) -> None:
    ensure_dir(data_root)
    csv_path = data_root / "section_inventory.csv"
    with csv_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=["name", "start_va", "end_va", "virtual_size", "raw_size", "flags"],
        )
        writer.writeheader()
        for section in image.sections:
            executable, writable = section_flags(section.characteristics)
            writer.writerow(
                {
                    "name": section.name,
                    "start_va": format_hex(image.image_base + section.virtual_address),
                    "end_va": format_hex(image.image_base + section.end_virtual_address - 1),
                    "virtual_size": section.virtual_size,
                    "raw_size": section.raw_size,
                    "flags": ("x" if executable else "-") + ("w" if writable else "r"),
                }
            )


def main() -> None:
    argparse.ArgumentParser(
        description="Generate global-object reference packets from the original executable."
    ).parse_args()

    binaries = load_binaries()
    image = load_pe_image(repo_path(binaries["original_exe"]))
    listing_path = repo_path(binaries["ghidra_listing"])

    rows = build_global_rows(listing_path, image)

    inventory_root = repo_path("inventory") / "globals"
    dumps_root = inventory_root / "dumps"
    data_root = inventory_root / "data"
    ensure_dir(inventory_root)

    csv_path = inventory_root / "all_globals.csv"
    with csv_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "va",
                "primary_name",
                "aliases",
                "section_name",
                "section_start",
                "section_end",
                "section_flags",
                "size_bytes",
                "hints",
                "emit_c_type",
                "emit_array_length",
                "emit_mode",
                "emit_initializer",
                "byte_preview",
            ],
        )
        writer.writeheader()
        for row in rows:
            writer.writerow(
                {
                    "va": row["va"],
                    "primary_name": row["primary_name"],
                    "aliases": ",".join(sorted(str(alias) for alias in row["aliases"])),
                    "section_name": row["section_name"],
                    "section_start": row["section_start"],
                    "section_end": row["section_end"],
                    "section_flags": row["section_flags"],
                    "size_bytes": row["size_bytes"],
                    "hints": ",".join(sorted(str(hint) for hint in row["hints"])),
                    "emit_c_type": row["emit_c_type"],
                    "emit_array_length": row["emit_array_length"],
                    "emit_mode": row["emit_mode"],
                    "emit_initializer": row["emit_initializer"],
                    "byte_preview": row["byte_preview"],
                }
            )

    write_global_packets(rows, dumps_root)
    write_section_inventory(image, data_root)

    print(f"Wrote {csv_path}")
    print(f"Wrote {len(rows)} global packets under {dumps_root}")
    print(f"Wrote {data_root / 'section_inventory.csv'}")


if __name__ == "__main__":
    main()
