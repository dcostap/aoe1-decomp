from __future__ import annotations

import csv
import difflib
import json
import os
import struct
from dataclasses import dataclass
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
CONFIG_DIR = REPO_ROOT / "config"
INVENTORY_DIR = REPO_ROOT / "inventory"
BUILD_DIR = REPO_ROOT / "build"
PDB_INVENTORY_DIR = INVENTORY_DIR / "pdb"
TOOLCHAIN_SUPPLIED_FUNCTIONS_PATH = CONFIG_DIR / "toolchain_supplied_functions.txt"
TOOLCHAIN_SUPPLIED_REGIONS_PATH = CONFIG_DIR / "toolchain_supplied_regions.txt"
ASM_SPECIAL_FUNCTIONS_PATH = CONFIG_DIR / "asm_special_functions.txt"
ASM_SPECIAL_REGIONS_PATH = CONFIG_DIR / "asm_special_regions.txt"
PARENT_OWNED_FRAGMENTS_PATH = CONFIG_DIR / "parent_owned_fragments.txt"


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


def load_optional_csv(path: Path) -> list[dict[str, str]]:
    if not path.exists():
        return []
    with path.open("r", encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def _load_name_manifest(path: Path) -> set[str]:
    names: set[str] = set()
    if not path.exists():
        return names

    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        names.add(line)
    return names


def load_toolchain_supplied_function_names() -> set[str]:
    return _load_name_manifest(TOOLCHAIN_SUPPLIED_FUNCTIONS_PATH)


def is_toolchain_supplied_function_name(name: str, configured_names: set[str] | None = None) -> bool:
    names = configured_names if configured_names is not None else load_toolchain_supplied_function_names()
    return name in names


def load_asm_special_function_names() -> set[str]:
    return _load_name_manifest(ASM_SPECIAL_FUNCTIONS_PATH)


def is_asm_special_function_name(name: str, configured_names: set[str] | None = None) -> bool:
    names = configured_names if configured_names is not None else load_asm_special_function_names()
    return name in names


def _load_region_manifest(path: Path, label: str) -> list[tuple[int, int, str]]:
    regions: list[tuple[int, int, str]] = []
    if not path.exists():
        return regions

    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 1)
        range_text = parts[0]
        reason = parts[1].strip() if len(parts) > 1 else ""
        if "-" not in range_text:
            raise ValueError(f"Invalid {label} region line: {raw_line}")
        start_text, end_text = range_text.split("-", 1)
        start = parse_hex(start_text)
        end = parse_hex(end_text)
        if start is None or end is None:
            raise ValueError(f"Invalid {label} region bounds: {raw_line}")
        if end < start:
            raise ValueError(f"{label} region end before start: {raw_line}")
        regions.append((start, end, reason))
    return regions


def _region_for_va(va: int, regions: list[tuple[int, int, str]]) -> tuple[int, int, str] | None:
    for start, end, reason in regions:
        if start <= va <= end:
            return (start, end, reason)
    return None


def load_toolchain_supplied_regions() -> list[tuple[int, int, str]]:
    return _load_region_manifest(TOOLCHAIN_SUPPLIED_REGIONS_PATH, "toolchain supplied")


def toolchain_supplied_region_for_va(
    va: int, configured_regions: list[tuple[int, int, str]] | None = None
) -> tuple[int, int, str] | None:
    regions = configured_regions if configured_regions is not None else load_toolchain_supplied_regions()
    return _region_for_va(va, regions)


def load_asm_special_regions() -> list[tuple[int, int, str]]:
    return _load_region_manifest(ASM_SPECIAL_REGIONS_PATH, "asm special")


def asm_special_region_for_va(va: int, configured_regions: list[tuple[int, int, str]] | None = None) -> tuple[int, int, str] | None:
    regions = configured_regions if configured_regions is not None else load_asm_special_regions()
    return _region_for_va(va, regions)


def load_parent_owned_fragments() -> dict[int, tuple[int, str, str]]:
    """Load fragment VA -> (parent VA, parent name, reason).

    Parent-owned fragments are real game-code bytes that the disassembler/PDB
    split out as FUN_ entries even though they are basic blocks inside a larger
    source function. They are excluded from the normal one-function corpus and
    should be matched by matching their parent function.
    """
    fragments: dict[int, tuple[int, str, str]] = {}
    if not PARENT_OWNED_FRAGMENTS_PATH.exists():
        return fragments

    for raw_line in PARENT_OWNED_FRAGMENTS_PATH.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 3)
        if len(parts) < 2:
            raise ValueError(f"Invalid parent-owned fragment line: {raw_line}")
        fragment_va = parse_hex(parts[0])
        parent_va = parse_hex(parts[1])
        if fragment_va is None or parent_va is None:
            raise ValueError(f"Invalid parent-owned fragment VA: {raw_line}")
        parent_name = parts[2] if len(parts) >= 3 else ""
        reason = parts[3] if len(parts) >= 4 else ""
        fragments[fragment_va] = (parent_va, parent_name, reason)
    return fragments


def parent_owned_fragment_for_va(
    va: int, configured_fragments: dict[int, tuple[int, str, str]] | None = None
) -> tuple[int, str, str] | None:
    fragments = configured_fragments if configured_fragments is not None else load_parent_owned_fragments()
    return fragments.get(va)


def classify_corpus_bucket(
    record: dict[str, str],
    toolchain_supplied_names: set[str] | None = None,
    toolchain_supplied_regions: list[tuple[int, int, str]] | None = None,
    asm_special_names: set[str] | None = None,
    asm_special_regions: list[tuple[int, int, str]] | None = None,
    parent_owned_fragments: dict[int, tuple[int, str, str]] | None = None,
) -> tuple[str, str]:
    name = record["name"]
    va = int(record["va"], 16)

    parent_fragment = parent_owned_fragment_for_va(va, parent_owned_fragments)
    if parent_fragment is not None:
        parent_va, parent_name, reason = parent_fragment
        detail = f"parent {parent_va:08X}"
        if parent_name:
            detail += f" {parent_name}"
        if reason:
            detail += f" {reason}"
        return "parent_owned_fragment", detail

    if is_toolchain_supplied_function_name(name, toolchain_supplied_names):
        return "toolchain_supplied", "manifest-name"

    toolchain_region = toolchain_supplied_region_for_va(va, toolchain_supplied_regions)
    if toolchain_region is not None:
        start, end, reason = toolchain_region
        range_reason = reason or f"range {start:08X}-{end:08X}"
        return "toolchain_supplied", range_reason

    if is_asm_special_function_name(name, asm_special_names):
        return "asm_special", "manifest-name"

    region = asm_special_region_for_va(va, asm_special_regions)
    if region is not None:
        start, end, reason = region
        range_reason = reason or f"range {start:08X}-{end:08X}"
        return "asm_region", range_reason

    return "normal", ""


def load_pdb_function_source_map() -> dict[str, dict[str, str]]:
    rows = load_optional_csv(PDB_INVENTORY_DIR / "function_source_map.csv")
    return {row["va"].upper(): row for row in rows}


def load_pdb_function_line_changes() -> dict[str, list[dict[str, str]]]:
    rows = load_optional_csv(PDB_INVENTORY_DIR / "function_line_changes.csv")
    grouped: dict[str, list[dict[str, str]]] = {}
    for row in rows:
        grouped.setdefault(row["va"].upper(), []).append(row)
    for records in grouped.values():
        records.sort(key=lambda row: row["address"].upper())
    return grouped


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
        REPO_ROOT / "src" / "accepted_drift" / f"{slug}.c",
        REPO_ROOT / "src" / "accepted_drift" / f"{slug}.cpp",
        REPO_ROOT / "src" / "scratch" / f"{slug}.c",
        REPO_ROOT / "src" / "scratch" / f"{slug}.cpp",
    ]
    for candidate in candidates:
        if candidate.exists():
            return candidate
    return REPO_ROOT / "src" / "scratch" / f"{slug}.c"


def positional_byte_diff_metrics(left: bytes, right: bytes) -> dict[str, int | float | str]:
    """Return strict byte-at-same-offset metrics used for exact parity."""
    compare_size = max(len(left), len(right))
    first_mismatch: int | None = None
    diff_bytes = 0
    diff_spans = 0
    in_span = False
    for index in range(compare_size):
        lval = left[index] if index < len(left) else None
        rval = right[index] if index < len(right) else None
        different = lval != rval
        if different:
            diff_bytes += 1
            if first_mismatch is None:
                first_mismatch = index
            if not in_span:
                diff_spans += 1
                in_span = True
        else:
            in_span = False
    diff_percent = 0.0 if compare_size == 0 else (diff_bytes / compare_size) * 100.0
    return {
        "original_size": len(left),
        "rebuilt_size": len(right),
        "compare_size": compare_size,
        "diff_bytes": diff_bytes,
        "diff_percent": diff_percent,
        "diff_spans": diff_spans,
        "first_mismatch_offset": "" if first_mismatch is None else str(first_mismatch),
        "result": "MATCH" if diff_bytes == 0 else "MISMATCH",
    }


def edit_diff_metrics(left: bytes, right: bytes) -> dict[str, int | float | bool | list[dict[str, int | str]]]:
    """Return a resynchronizing edit-diff diagnostic over byte sequences.

    This is Git-like/LCS-style closeness information. It is useful for humans
    because a one-byte insertion near the start no longer makes every later byte
    look unrelated. It is not the exact-layout gate; byte_diff_metrics keeps the
    positional result for that.
    """
    matcher = difflib.SequenceMatcher(a=left, b=right, autojunk=False)
    opcodes: list[dict[str, int | str]] = []
    equal_bytes = 0
    insert_bytes = 0
    delete_bytes = 0
    replace_bytes = 0

    for tag, i1, i2, j1, j2 in matcher.get_opcodes():
        left_size = i2 - i1
        right_size = j2 - j1
        if tag == "equal":
            equal_bytes += left_size
        elif tag == "insert":
            insert_bytes += right_size
        elif tag == "delete":
            delete_bytes += left_size
        elif tag == "replace":
            replace_bytes += max(left_size, right_size)
        opcodes.append({"tag": tag, "i1": i1, "i2": i2, "j1": j1, "j2": j2})

    edit_bytes = insert_bytes + delete_bytes + replace_bytes
    compare_size = max(len(left), len(right))
    edit_percent = 0.0 if compare_size == 0 else (edit_bytes / compare_size) * 100.0
    total_size = len(left) + len(right)
    edit_cost_percent_total = 0.0 if total_size == 0 else (edit_bytes / total_size) * 100.0
    resync_similarity_percent = 100.0 if compare_size == 0 else (equal_bytes / compare_size) * 100.0
    positional = positional_byte_diff_metrics(left, right)
    positional_diff_bytes = int(positional["diff_bytes"])
    shifted = (
        edit_bytes > 0
        and (insert_bytes > 0 or delete_bytes > 0)
        and edit_bytes < positional_diff_bytes
        and equal_bytes >= max(1, min(len(left), len(right)) // 2)
    )

    return {
        "edit_diff_bytes": edit_bytes,
        "edit_diff_percent": edit_percent,
        "edit_cost_percent_total": edit_cost_percent_total,
        "resync_similarity_percent": resync_similarity_percent,
        "edit_equal_bytes": equal_bytes,
        "edit_insert_bytes": insert_bytes,
        "edit_delete_bytes": delete_bytes,
        "edit_replace_bytes": replace_bytes,
        "edit_opcode_count": len(opcodes),
        "edit_opcodes": opcodes,
        "likely_shifted_alignment": shifted,
    }


def byte_diff_metrics(left: bytes, right: bytes) -> dict[str, int | float | str | bool | list[dict[str, int | str]]]:
    """Return stable byte-diff metrics used by diff/status/dashboard tools.

    Legacy diff_* keys remain the strict positional byte-at-offset metrics.
    New edit_* keys are resynchronizing human-diagnostic metrics.
    """
    positional = positional_byte_diff_metrics(left, right)
    edit = edit_diff_metrics(left, right)
    return {
        **positional,
        "positional_diff_bytes": positional["diff_bytes"],
        "positional_diff_percent": positional["diff_percent"],
        "positional_diff_spans": positional["diff_spans"],
        **edit,
    }


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
