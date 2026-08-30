from __future__ import annotations

"""Compile source files and compare functions from complete COFF objects."""

import json
import subprocess
import sys
from pathlib import Path

from build_cache import compiler_admission
from coff import function_symbol_section
from common import (
    REPO_ROOT,
    byte_diff_metrics,
    function_record_by_va,
    function_slug,
    load_pdb_function_source_map,
    load_toolchain,
    repo_path,
    tool_env,
)
from extract_obj_function import (
    extraction_extent,
    select_exact_function_symbol,
    select_record_function_symbol,
)
from function_diagnostics import compatible_relocation_masks, owning_function_symbol_validation


def _configured_symbol(module: dict[str, object], va: int) -> str:
    va_text = f"{va:08X}"
    functions = module.get("functions")
    if isinstance(functions, dict):
        entry = functions.get(va_text)
        if isinstance(entry, dict):
            symbol = str(entry.get("symbol") or "")
            if symbol:
                return symbol
        elif isinstance(entry, str):
            return entry
    symbols = module.get("symbols")
    if isinstance(symbols, dict):
        return str(symbols.get(va_text) or "")
    return ""


def select_configured_symbol(obj, va: int, module: dict[str, object]):
    exact_name = _configured_symbol(module, va)
    if exact_name:
        return select_exact_function_symbol(obj, exact_name)
    record = function_record_by_va(va)
    return select_record_function_symbol(obj, record["name"])


def _original_artifacts(va: int) -> tuple[bytes, dict[str, object]]:
    record = function_record_by_va(va)
    slug = function_slug(record)
    asm_dir = REPO_ROOT / "build" / "asm"
    bin_path = asm_dir / f"orig_{slug}.bin"
    json_path = asm_dir / f"orig_{slug}.json"
    if not bin_path.is_file() or not json_path.is_file():
        command = [
            sys.executable,
            str(REPO_ROOT / "tools" / "extract_original_function.py"),
            "--va",
            f"{va:08X}",
        ]
        result = subprocess.run(command, capture_output=True, text=True)
        if result.returncode != 0:
            raise RuntimeError(result.stdout + result.stderr)
    return bin_path.read_bytes(), json.loads(json_path.read_text(encoding="utf-8"))


def compare_object_function(
    obj,
    va: int,
    module: dict[str, object],
    expected_pdb_symbol: str = "",
    *,
    require_owner: bool = True,
) -> dict[str, object]:
    record = function_record_by_va(va)
    symbol = select_configured_symbol(obj, va, module)
    section = function_symbol_section(obj, symbol)
    expected_size = int(record["size_bytes"], 10)
    symbol_by_index = {candidate.index: candidate for candidate in obj.symbols}
    indirect_targets: list[int] = []
    for relocation in section.relocations:
        if relocation.offset < expected_size:
            continue
        target_symbol = symbol_by_index.get(relocation.symbol_index)
        if target_symbol is not None and target_symbol.section_number == symbol.section_number:
            indirect_targets.append(target_symbol.value - symbol.value)
    extent = extraction_extent(section.data, expected_size, indirect_targets)
    rebuilt = section.data[: int(extent["comparison_size"])]
    relocations = [
        {
            "offset": relocation.offset,
            "type": f"0x{relocation.reloc_type:04X}",
            "width": relocation.width,
            "symbol_name": relocation.symbol_name,
        }
        for relocation in section.relocations
        if relocation.offset < len(rebuilt)
    ]
    original, original_meta = _original_artifacts(va)
    masked_original, masked_rebuilt, relocation_validation = compatible_relocation_masks(
        original,
        rebuilt,
        relocations,
        va,
        original_meta.get("ranges") or [],
    )
    metrics = byte_diff_metrics(masked_original, masked_rebuilt)
    if not expected_pdb_symbol:
        expected_pdb_symbol = str(
            (load_pdb_function_source_map().get(f"{va:08X}") or {}).get("symbol_name") or ""
        ).strip()
    owner_validation = owning_function_symbol_validation(
        record["name"], symbol.name, expected_pdb_symbol
    )
    owner_match = owner_validation["status"] == "match"
    exact = bool(
        metrics["result"] == "MATCH"
        and not relocation_validation["target_mismatches"]
        and not extent["has_code_overflow"]
        and (owner_match or not require_owner)
    )
    return {
        "va": f"{va:08X}",
        "name": record["name"],
        "symbol": symbol.name,
        "result": "MATCH" if exact else "MISMATCH",
        "diff_bytes": metrics["diff_bytes"],
        "diff_percent": metrics["diff_percent"],
        "original_size": len(original),
        "rebuilt_size": len(rebuilt),
        "boundary_escape_offsets": extent["boundary_escape_offsets"],
        "relocations": relocation_validation,
        "owner_symbol": owner_validation,
    }


def compile_source(
    source_path: Path,
    object_path: Path,
    response_path: Path,
    include_dir: Path,
) -> dict[str, object]:
    toolchain = load_toolchain()
    compiler = repo_path(toolchain["compiler"]["cl"])
    command = [
        str(compiler),
        f"@{response_path}",
        f"/I{include_dir}",
        f"/Fo{object_path}",
        str(source_path),
    ]
    with compiler_admission():
        result = subprocess.run(
            command, capture_output=True, text=True, env=tool_env(toolchain)
        )
    manifest = {
        "command": command,
        "source": str(source_path),
        "object": str(object_path),
        "response_file": str(response_path),
        "returncode": result.returncode,
        "stdout": result.stdout,
        "stderr": result.stderr,
    }
    if result.returncode != 0 or not object_path.is_file():
        raise RuntimeError(result.stdout + result.stderr)
    return manifest
