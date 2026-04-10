from __future__ import annotations

import csv
import json
import os
import struct
from dataclasses import dataclass
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
CONFIG_DIR = REPO_ROOT / "config"
INVENTORY_DIR = REPO_ROOT / "inventory"
BUILD_DIR = REPO_ROOT / "build"


def repo_path(value: str | Path) -> Path:
    path = Path(value)
    return path if path.is_absolute() else (REPO_ROOT / path)


def load_json(path: Path) -> dict:
    with path.open("r", encoding="utf-8") as handle:
        return json.load(handle)


def load_toolchain() -> dict:
    return load_json(CONFIG_DIR / "toolchain.json")


def load_binaries() -> dict:
    return load_json(CONFIG_DIR / "binaries.json")


def load_functions() -> list[dict[str, str]]:
    with (INVENTORY_DIR / "all_functions.csv").open("r", encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def function_record_by_va(va: int) -> dict[str, str]:
    target = f"{va:08X}"
    for record in load_functions():
        if record["va"].upper() == target:
            return record
    raise KeyError(f"No function record for VA {target}")


def parse_hex(value: str | None) -> int | None:
    if value is None:
        return None
    cleaned = value.strip()
    if cleaned.lower().startswith("0x"):
        return int(cleaned, 16)
    return int(cleaned, 16)


def format_hex(value: int) -> str:
    return f"{value:08X}"


def slugify_name(name: str) -> str:
    chunks: list[str] = []
    for ch in name:
        if ch.isalnum():
            chunks.append(ch)
        else:
            chunks.append("_")
    slug = "".join(chunks).strip("_")
    while "__" in slug:
        slug = slug.replace("__", "_")
    return slug or "unnamed"


def function_slug(record: dict[str, str]) -> str:
    return f"{record['va'].upper()}_{slugify_name(record['name'])}"


def preferred_source_path(record: dict[str, str]) -> Path:
    slug = function_slug(record)
    candidates = [
        REPO_ROOT / "src" / "matching" / f"{slug}.c",
        REPO_ROOT / "src" / "matching" / f"{slug}.cpp",
        REPO_ROOT / "src" / "scratch" / f"{slug}.c",
        REPO_ROOT / "src" / "scratch" / f"{slug}.cpp",
    ]
    for candidate in candidates:
        if candidate.exists():
            return candidate
    return REPO_ROOT / "src" / "scratch" / f"{slug}.c"


def preferred_flags_rsp_path(record: dict[str, str], toolchain: dict) -> Path:
    slug = function_slug(record)
    candidate = CONFIG_DIR / "flags" / f"{slug}.rsp"
    if candidate.exists():
        return candidate
    return repo_path(toolchain["compiler"]["default_rsp"])


def ensure_dir(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def ensure_build_subdir(name: str) -> Path:
    path = BUILD_DIR / name
    ensure_dir(path)
    return path


def tool_env(config: dict) -> dict[str, str]:
    env: dict[str, str] = {}
    for key in ("COMSPEC", "PATHEXT", "SystemRoot", "WINDIR"):
        value = os.environ.get(key)
        if value:
            env[key] = value

    path_items = [str(repo_path(item)) for item in config["environment"]["path_prepend"]]
    system_root = env.get("SystemRoot") or env.get("WINDIR")
    if system_root:
        path_items.extend([str(Path(system_root) / "System32"), system_root])

    env["PATH"] = ";".join(path_items)
    env["INCLUDE"] = ";".join(str(repo_path(item)) for item in config["environment"]["include"])
    env["LIB"] = ";".join(str(repo_path(item)) for item in config["environment"]["lib"])

    temp_dir = ensure_build_subdir("tmp")
    env["TEMP"] = str(temp_dir)
    env["TMP"] = str(temp_dir)
    return env


@dataclass(frozen=True)
class Section:
    name: str
    virtual_address: int
    virtual_size: int
    raw_size: int
    raw_pointer: int
    characteristics: int

    @property
    def end_virtual_address(self) -> int:
        return self.virtual_address + max(self.virtual_size, self.raw_size)


@dataclass(frozen=True)
class PeImage:
    image_base: int
    sections: list[Section]
    data: bytes

    def section_for_va(self, va: int) -> Section | None:
        rva = va - self.image_base
        for section in self.sections:
            if section.virtual_address <= rva < section.end_virtual_address:
                return section
        return None

    def file_offset_for_va(self, va: int) -> int | None:
        section = self.section_for_va(va)
        if section is None:
            return None
        rva = va - self.image_base
        offset_in_section = rva - section.virtual_address
        if offset_in_section >= section.raw_size:
            return None
        return section.raw_pointer + offset_in_section

    def read_va_range(self, start_va: int, end_va: int) -> bytes:
        chunks = bytearray()
        current = start_va
        while current <= end_va:
            section = self.section_for_va(current)
            if section is None:
                raise ValueError(f"VA {current:08X} is not inside any section")
            section_data_end = self.image_base + section.virtual_address + section.raw_size - 1
            chunk_end = min(end_va, section_data_end)
            start_offset = self.file_offset_for_va(current)
            end_offset = self.file_offset_for_va(chunk_end)
            if start_offset is None or end_offset is None:
                raise ValueError(f"VA range {current:08X}-{chunk_end:08X} is outside raw section data")
            chunks.extend(self.data[start_offset : end_offset + 1])
            current = chunk_end + 1
        return bytes(chunks)


def load_pe_image(path: Path) -> PeImage:
    data = path.read_bytes()
    if data[:2] != b"MZ":
        raise ValueError(f"{path} is not an MZ executable")

    pe_offset = struct.unpack_from("<I", data, 0x3C)[0]
    if data[pe_offset : pe_offset + 4] != b"PE\x00\x00":
        raise ValueError(f"{path} is not a PE executable")

    file_header_offset = pe_offset + 4
    machine, number_of_sections, _, _, _, size_of_optional_header, _ = struct.unpack_from(
        "<HHIIIHH", data, file_header_offset
    )
    if machine != 0x14C:
        raise ValueError(f"Unsupported machine type 0x{machine:04X}")

    optional_header_offset = file_header_offset + 20
    magic = struct.unpack_from("<H", data, optional_header_offset)[0]
    if magic != 0x10B:
        raise ValueError(f"Unsupported PE optional header magic 0x{magic:04X}")

    image_base = struct.unpack_from("<I", data, optional_header_offset + 28)[0]
    section_table_offset = optional_header_offset + size_of_optional_header

    sections: list[Section] = []
    for index in range(number_of_sections):
        offset = section_table_offset + index * 40
        raw_name = struct.unpack_from("8s", data, offset)[0]
        name = raw_name.split(b"\x00", 1)[0].decode("ascii", errors="replace")
        virtual_size, virtual_address, raw_size, raw_pointer = struct.unpack_from("<IIII", data, offset + 8)
        characteristics = struct.unpack_from("<I", data, offset + 36)[0]
        sections.append(
            Section(
                name=name,
                virtual_address=virtual_address,
                virtual_size=virtual_size,
                raw_size=raw_size,
                raw_pointer=raw_pointer,
                characteristics=characteristics,
            )
        )

    return PeImage(image_base=image_base, sections=sections, data=data)


def load_layout(path: Path) -> dict:
    return load_json(path)


def function_by_start(layout: dict, start_va: int) -> dict:
    target = format_hex(start_va)
    for entry in layout.get("functions", []):
        if entry.get("start", "").upper() == target:
            return entry
    raise KeyError(f"No layout function starting at {target}")
