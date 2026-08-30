from __future__ import annotations

import argparse
import csv
import re
from pathlib import Path

from common import ensure_dir, load_binaries, repo_path, slugify_name


SIZE_RE = re.compile(r"^// Size: 0x([0-9A-Fa-f]+) \((\d+) bytes\)$")
TYPE_RE = re.compile(r"^(class|struct) (.+?)(?: : public (.+?))? \{$")
FIELD_RE = re.compile(r"^\s*(.+?); // \+(0x[0-9A-Fa-f]+) \(Size: (0x[0-9A-Fa-f]+)\)$")
GAP_RE = re.compile(r"^\s*(.+?); // (0x[0-9A-Fa-f]+) \(Gap: ([0-9A-Fa-f]+|\d+)\)$")


def parse_types(lines: list[str]) -> list[dict[str, object]]:
    entries: list[dict[str, object]] = []
    index = 0
    while index < len(lines) - 1:
        size_match = SIZE_RE.match(lines[index])
        type_match = TYPE_RE.match(lines[index + 1])
        if size_match is None or type_match is None:
            index += 1
            continue

        body_start = index + 1
        body_end = body_start
        while body_end < len(lines) and lines[body_end].strip() != "};":
            body_end += 1
        if body_end >= len(lines):
            break

        field_count = 0
        gap_count = 0
        member_rows: list[dict[str, str]] = []
        for member_line in lines[body_start + 1 : body_end]:
            field_match = FIELD_RE.match(member_line)
            if field_match:
                member_rows.append(
                    {
                        "kind": "field",
                        "declaration": field_match.group(1).strip(),
                        "offset_hex": field_match.group(2).lower(),
                        "size_hex": field_match.group(3).lower(),
                    }
                )
                field_count += 1
                continue

            gap_match = GAP_RE.match(member_line)
            if gap_match:
                raw_gap = gap_match.group(3)
                gap_size = int(raw_gap, 16) if raw_gap.lower().startswith("0x") else int(raw_gap, 10)
                member_rows.append(
                    {
                        "kind": "gap",
                        "declaration": gap_match.group(1).strip(),
                        "offset_hex": gap_match.group(2).lower(),
                        "size_hex": f"0x{gap_size:X}".lower(),
                    }
                )
                gap_count += 1

        entries.append(
            {
                "kind": type_match.group(1),
                "name": type_match.group(2),
                "base": type_match.group(3) or "",
                "size_hex": f"0x{int(size_match.group(1), 16):X}",
                "size_bytes": int(size_match.group(2)),
                "start_line": index + 1,
                "end_line": body_end + 1,
                "field_count": field_count,
                "gap_count": gap_count,
                "body_lines": lines[index : body_end + 1],
                "members": member_rows,
            }
        )
        index = body_end + 1

    return entries


def write_type_packets(entries: list[dict[str, object]], packet_root: Path) -> None:
    ensure_dir(packet_root)
    for entry in entries:
        name = str(entry["name"])
        slug = slugify_name(name)
        packet_path = packet_root / f"{slug}.txt"

        packet_lines: list[str] = [
            f"Name: {name}",
            f"Kind: {entry['kind']}",
            f"Base: {entry['base'] or '<none>'}",
            f"SizeBytes: {entry['size_bytes']}",
            f"SizeHex: {entry['size_hex']}",
            f"FieldCount: {entry['field_count']}",
            f"GapCount: {entry['gap_count']}",
            f"SourceLines: {entry['start_line']}-{entry['end_line']}",
            "",
            "=== Body ===",
        ]
        packet_lines.extend(str(line) for line in entry["body_lines"])

        members = entry["members"]
        if members:
            packet_lines.append("")
            packet_lines.append("=== Members ===")
            for member in members:
                packet_lines.append(
                    f"{member['kind']}: {member['offset_hex']} size {member['size_hex']} :: {member['declaration']}"
                )

        packet_path.write_text("\n".join(packet_lines) + "\n", encoding="utf-8")


def main() -> None:
    argparse.ArgumentParser(
        description="Generate type reference files from the configured type dump."
    ).parse_args()

    binaries = load_binaries()
    source_path = repo_path(binaries["type_dump"])
    source_text = source_path.read_text(encoding="utf-8", errors="replace")
    lines = source_text.splitlines()
    entries = parse_types(lines)

    inventory_root = repo_path("inventory") / "types"
    dumps_root = inventory_root / "dumps"
    ensure_dir(inventory_root)

    reference_header_path = inventory_root / "all_types_reference.h"
    reference_header_path.write_text(source_text, encoding="utf-8")

    csv_path = inventory_root / "all_types.csv"
    with csv_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "name",
                "kind",
                "base",
                "size_bytes",
                "size_hex",
                "field_count",
                "gap_count",
                "start_line",
                "end_line",
            ],
        )
        writer.writeheader()
        for entry in entries:
            writer.writerow(
                {
                    "name": entry["name"],
                    "kind": entry["kind"],
                    "base": entry["base"],
                    "size_bytes": entry["size_bytes"],
                    "size_hex": entry["size_hex"],
                    "field_count": entry["field_count"],
                    "gap_count": entry["gap_count"],
                    "start_line": entry["start_line"],
                    "end_line": entry["end_line"],
                }
            )

    write_type_packets(entries, dumps_root)

    print(f"Wrote {reference_header_path}")
    print(f"Wrote {csv_path}")
    print(f"Wrote {len(entries)} type packets under {dumps_root}")


if __name__ == "__main__":
    main()
