from __future__ import annotations

import csv
import difflib
import hashlib
import json
import os
import struct
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parent.parent
CONFIG_DIR = REPO_ROOT / "config"
FUNCTIONS_CONFIG_DIR = CONFIG_DIR / "functions"
FLAGS_DIR = CONFIG_DIR / "flags"
INVENTORY_DIR = REPO_ROOT / "inventory"
BUILD_DIR = REPO_ROOT / "build"
PDB_INVENTORY_DIR = INVENTORY_DIR / "pdb"
FUNCTION_DECOMP_NOTES_DIR = REPO_ROOT / "decomp_notes" / "functions"
TOOLCHAIN_SUPPLIED_FUNCTIONS_PATH = CONFIG_DIR / "toolchain_supplied_functions.txt"
TOOLCHAIN_SUPPLIED_REGIONS_PATH = CONFIG_DIR / "toolchain_supplied_regions.txt"
ASM_SPECIAL_FUNCTIONS_PATH = CONFIG_DIR / "asm_special_functions.txt"
ASM_SPECIAL_REGIONS_PATH = CONFIG_DIR / "asm_special_regions.txt"
PARENT_OWNED_FRAGMENTS_PATH = CONFIG_DIR / "parent_owned_fragments.txt"
PADDING_ONLY_FUNCTIONS_PATH = CONFIG_DIR / "padding_only_functions.txt"
COMPILER_GENERATED_FUNCTIONS_PATH = CONFIG_DIR / "compiler_generated_functions.txt"


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


@lru_cache(maxsize=1)
def load_functions() -> list[dict[str, str]]:
    with (INVENTORY_DIR / "all_functions.csv").open("r", encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


@lru_cache(maxsize=1)
def function_records_by_va() -> dict[str, dict[str, str]]:
    """Return the immutable function inventory indexed by normalized VA."""
    return {record["va"].upper(): record for record in load_functions()}


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


@lru_cache(maxsize=1)
def load_padding_only_functions() -> dict[int, str]:
    """Load padding-only VA -> reason metadata."""
    functions: dict[int, str] = {}
    if not PADDING_ONLY_FUNCTIONS_PATH.exists():
        return functions

    for raw_line in PADDING_ONLY_FUNCTIONS_PATH.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 1)
        va = parse_hex(parts[0])
        if va is None:
            raise ValueError(f"Invalid padding-only function VA: {raw_line}")
        functions[va] = parts[1].strip() if len(parts) > 1 else ""
    return functions


@lru_cache(maxsize=1)
def load_compiler_generated_functions() -> dict[int, str]:
    """Load compiler-generated VA -> reason metadata."""
    functions: dict[int, str] = {}
    if not COMPILER_GENERATED_FUNCTIONS_PATH.exists():
        return functions

    for raw_line in COMPILER_GENERATED_FUNCTIONS_PATH.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 1)
        va = parse_hex(parts[0])
        if va is None:
            raise ValueError(f"Invalid compiler-generated function VA: {raw_line}")
        functions[va] = parts[1].strip() if len(parts) > 1 else ""
    return functions


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
    padding_only_functions: dict[int, str] | None = None,
    compiler_generated_functions: dict[int, str] | None = None,
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

    padding_functions = padding_only_functions if padding_only_functions is not None else load_padding_only_functions()
    if va in padding_functions:
        return "padding_only", padding_functions[va] or "manifest-va"

    generated_functions = (
        compiler_generated_functions
        if compiler_generated_functions is not None
        else load_compiler_generated_functions()
    )
    if va in generated_functions:
        return "compiler_generated", generated_functions[va] or "manifest-va"

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
    try:
        return function_records_by_va()[target]
    except KeyError as error:
        raise KeyError(f"No function record for VA {target}") from error


def function_decomp_note_relative_path(va: str) -> Path:
    """Return the optional tracked note path for one function."""
    va_text = str(va).upper()
    if len(va_text) != 8 or any(character not in "0123456789ABCDEF" for character in va_text):
        raise ValueError(f"Invalid function VA: {va!r}")
    return Path("decomp_notes") / "functions" / va_text[:4] / f"{va_text}.md"


def module_decomp_note_relative_path(module_name: str) -> Path:
    """Return the optional tracked note path for one source module."""
    name = str(module_name).strip()
    if not name or Path(name).name != name:
        raise ValueError(f"Invalid source-module name: {module_name!r}")
    return Path("decomp_notes") / f"{name}.md"


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


_FUNCTION_STATUSES = {
    "matching",
    "accepted_drift",
    "verified_logic",
    "scratch",
    "unresolved",
}


@lru_cache(maxsize=1)
def load_function_modules() -> list[dict[str, object]]:
    """Load the canonical function registry grouped by natural source file."""
    if not FUNCTIONS_CONFIG_DIR.exists():
        return []
    module_paths = sorted(FUNCTIONS_CONFIG_DIR.rglob("*.json"))

    modules: list[dict[str, object]] = []
    seen_names: set[str] = set()
    seen_sources: set[str] = set()
    seen_vas: set[str] = set()
    for module_path in module_paths:
        raw_module = load_json(module_path)
        label = module_path.relative_to(REPO_ROOT).as_posix()
        if not isinstance(raw_module, dict):
            raise ValueError(f"{label}: module must be an object")
        if raw_module.get("schema") != 1:
            raise ValueError(f"{label}: schema must be 1")

        relative_registry = module_path.relative_to(FUNCTIONS_CONFIG_DIR).as_posix()
        if not relative_registry.endswith(".json"):
            raise ValueError(f"{label}: registry file must end in .json")
        source = relative_registry[:-5]
        source_path = Path(source)
        suffix = source_path.suffix.casefold()
        if (
            not source_path.parts
            or source_path.parts[0] not in {"src", "include"}
            or suffix not in {".c", ".cc", ".cpp", ".cxx", ".h", ".hpp"}
        ):
            raise ValueError(f"{label}: registry path does not name a natural source file")
        name = source_path.stem.casefold()
        if suffix in {".h", ".hpp"}:
            name += "_h"

        pdb_source_path = str(raw_module.get("pdb_source_path") or "").strip()
        pdb_no_line_info = raw_module.get("pdb_no_line_info", False)
        pdb_module_stream_evidence = str(
            raw_module.get("pdb_module_stream_evidence") or ""
        ).replace("\\", "/").strip()
        header = str(raw_module.get("header") or "").replace("\\", "/").strip()
        raw_build = raw_module.get("build")
        raw_functions = raw_module.get("functions")
        if not source or not pdb_source_path or not isinstance(raw_functions, dict) or not raw_functions:
            raise ValueError(
                f"{label}: module needs pdb_source_path and functions"
            )
        if source in seen_sources:
            raise ValueError(f"{label}: duplicate source {source!r}")
        seen_sources.add(source)
        if not isinstance(pdb_no_line_info, bool):
            raise ValueError(f"{label}: pdb_no_line_info must be Boolean")
        if pdb_no_line_info and not pdb_module_stream_evidence:
            raise ValueError(
                f"{label}: pdb_no_line_info needs pdb_module_stream_evidence"
            )
        if name in seen_names:
            raise ValueError(f"{label}: duplicate module name {name!r}")
        seen_names.add(name)

        build: dict[str, str] | None = None
        if raw_build is not None:
            if not isinstance(raw_build, dict):
                raise ValueError(f"{label}: build must be an object")
            profile = str(raw_build.get("flags") or "").strip()
            if not profile or Path(profile).name != profile:
                raise ValueError(f"{label}: build needs one flag profile name")
            flags_path = FLAGS_DIR / f"{profile}.rsp"
            build = {
                "flags": profile,
                "flags_path": flags_path.relative_to(REPO_ROOT).as_posix(),
            }

        functions: dict[str, dict[str, str]] = {}
        for raw_va, raw_entry in raw_functions.items():
            va = str(raw_va).upper()
            if len(va) != 8 or any(character not in "0123456789ABCDEF" for character in va):
                raise ValueError(f"{label}: invalid function VA {raw_va!r}")
            if va in seen_vas:
                raise ValueError(f"{label}: VA {va} appears in multiple modules")
            if not isinstance(raw_entry, dict):
                raise ValueError(f"{label}: {va} must be an object")
            status = str(raw_entry.get("status") or "").strip()
            if status not in _FUNCTION_STATUSES:
                raise ValueError(
                    f"{label}: {va} has invalid status {status!r}"
                )
            symbol = str(raw_entry.get("symbol") or "").strip()
            if symbol and any(character.isspace() for character in symbol):
                raise ValueError(f"{label}: {va} has invalid symbol")
            if build is not None and not symbol:
                raise ValueError(f"{label}: buildable function {va} needs a symbol")
            if build is None and symbol:
                raise ValueError(f"{label}: function {va} has a symbol without a build")
            if build is None and status != "unresolved":
                raise ValueError(
                    f"{label}: function {va} without a build must be unresolved"
                )
            seen_vas.add(va)
            functions[va] = {"status": status}
            if symbol:
                functions[va]["symbol"] = symbol
        modules.append(
            {
                "name": name,
                "source": source,
                "header": header,
                "pdb_source_path": pdb_source_path,
                "pdb_no_line_info": pdb_no_line_info,
                "pdb_module_stream_evidence": pdb_module_stream_evidence,
                "build": build,
                "functions": functions,
            }
        )
    return modules


def function_module_for_name(name: str) -> dict[str, object] | None:
    for module in load_function_modules():
        if str(module["name"]) == name:
            return module
    return None


@lru_cache(maxsize=1)
def function_entries_by_va() -> dict[str, dict[str, object]]:
    entries: dict[str, dict[str, object]] = {}
    for module in load_function_modules():
        functions = module["functions"]
        assert isinstance(functions, dict)
        for va, entry in functions.items():
            if isinstance(entry, dict):
                entries[str(va).upper()] = {"module": module, **entry}
    return entries


def function_entry_for_va(va: int | str) -> dict[str, object] | None:
    va_text = f"{va:08X}" if isinstance(va, int) else str(va).upper()
    return function_entries_by_va().get(va_text)


def _sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def pdb_module_stream_evidence_issues(module: dict[str, object]) -> list[str]:
    """Validate one immutable PDB stream dump for a no-line compiland."""
    name = str(module["name"])
    evidence_path = repo_path(str(module["pdb_module_stream_evidence"]))
    if not evidence_path.is_file():
        return [f"{name}: PDB module-stream evidence is missing: {evidence_path}"]
    try:
        evidence = load_json(evidence_path)
    except (OSError, json.JSONDecodeError) as error:
        return [f"{name}: invalid PDB module-stream evidence: {error}"]
    if evidence.get("schema") != 1:
        return [f"{name}: PDB module-stream evidence has invalid schema"]

    binaries = load_binaries()
    pdb_path = repo_path(str(binaries["original_pdb"]))
    evidence_pdb = repo_path(str(evidence.get("pdb_path") or ""))
    if evidence_pdb.resolve() != pdb_path.resolve():
        return [f"{name}: PDB module-stream evidence uses another PDB"]
    if str(evidence.get("pdb_sha256") or "") != _sha256(pdb_path):
        return [f"{name}: PDB module-stream evidence hash does not match the original PDB"]

    expected_object = str(module["pdb_source_path"]).replace("/", "\\").casefold()
    object_path = str(evidence.get("object_path") or "").replace("/", "\\").casefold()
    if object_path != expected_object:
        return [f"{name}: PDB module-stream evidence has another object path"]

    raw_path = repo_path(str(evidence.get("raw_dump") or ""))
    if not raw_path.is_file():
        return [f"{name}: PDB module-stream raw dump is missing: {raw_path}"]
    if str(evidence.get("raw_dump_sha256") or "") != _sha256(raw_path):
        return [f"{name}: PDB module-stream raw dump hash does not match"]
    raw_dump = raw_path.read_text(encoding="utf-8")
    expected_header = f'** Module: "{evidence.get("object_path")}"'
    if expected_header not in raw_dump:
        return [f"{name}: PDB module-stream raw dump has another object path"]

    procedures = evidence.get("procedures")
    procedure_count = evidence.get("procedure_count")
    if not isinstance(procedures, list) or procedure_count != len(procedures):
        return [f"{name}: PDB module-stream procedure metadata is invalid"]
    if raw_dump.count("S_GPROC32:") != len(procedures):
        return [f"{name}: PDB module-stream procedure metadata does not match the raw dump"]
    return []


def pdb_module_stream_procedure_for_va(
    module: dict[str, object], va: str
) -> dict[str, object] | None:
    """Return one verified no-line module-stream procedure record."""
    if pdb_module_stream_evidence_issues(module):
        return None
    evidence_path = repo_path(str(module["pdb_module_stream_evidence"]))
    evidence = load_json(evidence_path)
    procedures = evidence["procedures"]
    assert isinstance(procedures, list)
    target = str(va).upper()
    for procedure in procedures:
        if not isinstance(procedure, dict):
            continue
        if str(procedure.get("va") or "").upper() == target:
            return procedure
    return None


def validate_function_registry() -> list[str]:
    """Return durable function-registry problems."""
    records = {row["va"].upper(): row for row in load_functions()}
    pdb_sources = load_pdb_function_source_map()
    issues: list[str] = []
    configured_vas: set[str] = set()
    used_profiles: set[str] = set()
    for module in load_function_modules():
        name = str(module["name"])
        source = repo_path(str(module["source"]))
        if not source.is_file():
            issues.append(f"{name}: module source is missing: {source}")
        header_value = str(module.get("header") or "")
        if header_value and not repo_path(header_value).is_file():
            issues.append(f"{name}: module header is missing: {repo_path(header_value)}")
        expected_pdb_path = str(module["pdb_source_path"]).replace("/", "\\").casefold()
        no_line_info = bool(module.get("pdb_no_line_info"))
        if no_line_info:
            issues.extend(pdb_module_stream_evidence_issues(module))
        build = module.get("build")
        if isinstance(build, dict):
            used_profiles.add(str(build["flags"]))
            flags_path = repo_path(str(build["flags_path"]))
            if not flags_path.is_file():
                issues.append(f"{name}: compiler flag profile is missing: {flags_path}")
        functions = module["functions"]
        assert isinstance(functions, dict)
        for va, entry in functions.items():
            configured_vas.add(va)
            if va not in records:
                issues.append(f"{name}: function {va} is absent from inventory")
                continue
            pdb_entry = pdb_sources.get(va)
            pdb_path = str((pdb_entry or {}).get("primary_source_path") or "")
            if no_line_info:
                if pdb_entry is None:
                    issues.append(f"{name}: function {va} has no PDB function record")
                elif pdb_entry.get("has_line_info") != "0" or pdb_path:
                    issues.append(
                        f"{name}: function {va} has PDB line/source data despite pdb_no_line_info"
                    )
                continue
            if pdb_path.replace("/", "\\").casefold() != expected_pdb_path:
                issues.append(
                    f"{name}: function {va} PDB source {pdb_path!r} does not match {module['pdb_source_path']!r}"
                )
    normal_vas = {
        va
        for va, record in records.items()
        if classify_corpus_bucket(record)[0] == "normal"
    }
    for va in sorted(normal_vas - configured_vas):
        issues.append(f"function {va} is absent from the function registry")
    for va in sorted(configured_vas - normal_vas):
        issues.append(f"non-normal function {va} appears in the function registry")
    profile_paths = sorted(FLAGS_DIR.glob("*.rsp")) if FLAGS_DIR.is_dir() else []
    available_profiles = {path.stem for path in profile_paths}
    for profile in sorted(used_profiles - available_profiles):
        issues.append(f"compiler flag profile {profile!r} is missing")
    for profile in sorted(available_profiles - used_profiles):
        issues.append(f"compiler flag profile {profile!r} is unused")
    profiles_by_signature: dict[tuple[str, ...], list[str]] = {}
    for path in profile_paths:
        signature = tuple(path.read_text(encoding="utf-8").split())
        profiles_by_signature.setdefault(signature, []).append(path.stem)
    for names in profiles_by_signature.values():
        if len(names) > 1:
            issues.append(
                "compiler flag profiles have duplicate settings: " + ", ".join(names)
            )
    return issues


def load_build_modules() -> list[dict[str, object]]:
    """Return natural source modules that have a proven compiler recipe."""
    return [module for module in load_function_modules() if module.get("build")]


def matching_build_for_va(va: int) -> dict[str, object] | None:
    """Return the build module for one matching function."""
    entry = function_entry_for_va(va)
    if entry is None or entry.get("status") != "matching":
        return None
    module = entry["module"]
    assert isinstance(module, dict)
    if module.get("build") is None:
        return None
    validate_build_module(module)
    return module


def build_module_for_va(va: int) -> dict[str, object] | None:
    """Return the proven compiler recipe for one function."""
    entry = function_entry_for_va(va)
    if entry is None or not entry.get("symbol"):
        return None
    module = entry["module"]
    assert isinstance(module, dict)
    validate_build_module(module)
    return module


def build_module_for_source(source_path: Path) -> dict[str, object] | None:
    try:
        relative = source_path.resolve().relative_to(REPO_ROOT.resolve()).as_posix()
    except ValueError:
        return None
    for module in load_build_modules():
        if str(module["source"]) == relative:
            validate_build_module(module)
            return module
    return None


def build_module_signature(module: dict[str, object]) -> dict[str, object]:
    """Return the status-neutral inputs that define one module build."""
    functions = module["functions"]
    assert isinstance(functions, dict)
    return {
        "name": module["name"],
        "source": module["source"],
        "build": module["build"],
        "functions": {
            va: entry["symbol"]
            for va, entry in functions.items()
            if isinstance(entry, dict)
        },
    }


def validate_build_module(module: dict[str, object]) -> None:
    """Verify one natural source build once per process."""
    payload = json.dumps(module, sort_keys=True, separators=(",", ":"))
    _validate_build_module_cached(payload)


@lru_cache(maxsize=None)
def _validate_build_module_cached(payload: str) -> None:
    module = json.loads(payload)
    _validate_build_module_uncached(module)


def _validate_build_module_uncached(module: dict[str, object]) -> None:
    source = repo_path(str(module["source"]))
    build = module.get("build")
    functions = module.get("functions")
    if (
        not source.is_file()
        or not isinstance(build, dict)
        or not isinstance(functions, dict)
        or not functions
    ):
        raise ValueError(f"build module is incomplete: {source}")
    flags_path = repo_path(str(build.get("flags_path") or ""))
    if not flags_path.is_file():
        raise ValueError(f"build module flag profile is missing: {flags_path}")
    for va, entry in functions.items():
        if not isinstance(entry, dict) or not str(entry.get("symbol") or ""):
            raise ValueError(f"buildable function {va} has no symbol")


def compiler_source_path(record: dict[str, str]) -> Path:
    module = build_module_for_va(int(record["va"], 16))
    if module is not None:
        return repo_path(str(module["source"]))
    return preferred_source_path(record)


def compiler_artifact_slug(record: dict[str, str]) -> str:
    module = build_module_for_va(int(record["va"], 16))
    if module is not None:
        return f"tu_{slugify_name(str(module['name']))}"
    return function_slug(record)


def preferred_source_path(record: dict[str, str]) -> Path:
    entry = function_entry_for_va(record["va"])
    if entry is not None:
        module = entry["module"]
        assert isinstance(module, dict)
        return repo_path(str(module["source"]))
    raise FileNotFoundError(
        f"No natural source is configured for {record['va']} {record['name']}"
    )


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
    module = build_module_for_va(int(record["va"], 16))
    if module is not None:
        build = module["build"]
        assert isinstance(build, dict)
        return repo_path(str(build["flags_path"]))
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


def owned_function_ranges(
    layout: dict,
    owner_va: int,
    parent_owned_fragments: dict[int, tuple[int, str, str]] | None = None,
) -> tuple[list[tuple[int, int]], list[int]]:
    """Resolve one owner's body without dropping reviewed internal fragments.

    Ghidra can promote an internal block to a separate FUN_ entry.  The
    parent-fragment manifest restores that block to its source owner.  Do not
    concatenate any remaining unowned gap: it could contain unrelated bytes.
    """
    def layout_ranges(layout_function: dict) -> list[tuple[int, int]]:
        ranges: list[tuple[int, int]] = []
        for body_range in layout_function.get("body_ranges", []):
            start = parse_hex(body_range.get("start"))
            end = parse_hex(body_range.get("end"))
            if start is None or end is None:
                continue
            if end < start:
                raise ValueError(
                    f"Original function {format_hex(owner_va)} has a reversed body range "
                    f"{format_hex(start)}-{format_hex(end)}"
                )
            ranges.append((start, end))
        return ranges

    ranges = layout_ranges(function_by_start(layout, owner_va))
    fragments = parent_owned_fragments
    if fragments is None:
        fragments = load_parent_owned_fragments()

    included_fragments: list[int] = []
    for fragment_va, (parent_va, _parent_name, _reason) in fragments.items():
        if parent_va != owner_va:
            continue
        fragment_ranges = layout_ranges(function_by_start(layout, fragment_va))
        if not fragment_ranges:
            raise ValueError(
                f"Parent-owned fragment {format_hex(fragment_va)} has no body range"
            )
        ranges.extend(fragment_ranges)
        included_fragments.append(fragment_va)

    if not ranges:
        raise ValueError(f"Original function {format_hex(owner_va)} has no body range")

    ranges.sort()
    merged: list[tuple[int, int]] = []
    for start, end in ranges:
        if not merged:
            merged.append((start, end))
            continue
        previous_start, previous_end = merged[-1]
        if start > previous_end + 1:
            raise ValueError(
                f"Original function {format_hex(owner_va)} has an unowned gap "
                f"{format_hex(previous_end + 1)}-{format_hex(start - 1)}; "
                "refusing to concatenate disjoint ranges"
            )
        merged[-1] = (previous_start, max(previous_end, end))

    return merged, sorted(included_fragments)
