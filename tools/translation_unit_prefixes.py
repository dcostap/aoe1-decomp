from __future__ import annotations

import argparse
import json
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path

from coff import function_symbol_section, load_coff_object
from common import (
    REPO_ROOT,
    byte_diff_metrics,
    function_record_by_va,
    function_slug,
    load_pdb_function_source_map,
    load_toolchain,
    preferred_source_path,
    source_module_entry_for_va,
    repo_path,
    tool_env,
    translation_unit_for_va,
    validate_translation_unit,
)
from extract_obj_function import (
    extraction_extent,
    select_exact_function_symbol,
    select_record_function_symbol,
)
from function_diagnostics import compatible_relocation_masks, owning_function_symbol_validation
from validate_translation_units import validate_translation_units


@dataclass(frozen=True)
class PdbOwner:
    va: int
    symbol_name: str
    source_path: str
    source_file: str
    line_start: int
    line_end: int
    class_owner: str


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=(
            "Compile one target alone and after each authentic source prefix.\n"
            "\n"
            "The tool accepts only canonical matching owners from the target's configured\n"
            "translation unit. PDB source path and source-line order must agree. Class and\n"
            "linked address order remain reported evidence. Each prefix owner must still match.\n"
            "Generated wrappers and compiler output stay under build/tu_prefixes."
        ),
    )
    parser.add_argument("--va", required=True, help="Target VA in hex, for example 0044B2B0.")
    parser.add_argument(
        "--prefix-va",
        action="append",
        default=[],
        metavar="VA",
        help=(
            "Earlier owner to add. Repeat in source order. By default, use all valid earlier "
            "owners from the configured translation unit."
        ),
    )
    return parser.parse_args()


def _class_owner(symbol_name: str) -> str:
    if "::" not in symbol_name:
        return ""
    return symbol_name.rsplit("::", 1)[0].strip()


def pdb_owner_for_va(va: int, source_map: dict[str, dict[str, str]]) -> PdbOwner:
    key = f"{va:08X}"
    row = source_map.get(key)
    if row is None:
        raise ValueError(f"{key} has no PDB source record")
    if row.get("has_line_info") != "1" or row.get("unique_file_count") != "1":
        raise ValueError(f"{key} does not have one unambiguous PDB source file")
    source_path = str(row.get("primary_source_path") or "").strip()
    source_file = str(row.get("primary_source_file") or "").strip()
    if not source_path or not source_file:
        raise ValueError(f"{key} has no PDB primary source path")
    try:
        line_start = int(str(row.get("line_start") or ""), 10)
        line_end = int(str(row.get("line_end") or ""), 10)
    except ValueError as error:
        raise ValueError(f"{key} has invalid PDB source lines") from error
    if line_start <= 0 or line_end < line_start:
        raise ValueError(f"{key} has invalid PDB source range {line_start}-{line_end}")
    symbol_name = str(row.get("symbol_name") or "").strip()
    if not symbol_name:
        raise ValueError(f"{key} has no PDB-qualified symbol ownership")
    return PdbOwner(
        va=va,
        symbol_name=symbol_name,
        source_path=source_path,
        source_file=source_file,
        line_start=line_start,
        line_end=line_end,
        class_owner=_class_owner(symbol_name),
    )


def _normalized_pdb_path(value: str) -> str:
    return value.replace("/", "\\").casefold()


def _matching_owner_path(va: int) -> Path:
    path = preferred_source_path(function_record_by_va(va)).resolve()
    if not _is_matching_owner_path(va, path):
        raise ValueError(
            f"{va:08X} is not an exact anchor in a current matching owner: {path}"
        )
    if not path.is_file():
        raise ValueError(f"{va:08X} canonical owner is missing: {path}")
    return path


def _is_matching_owner_path(va: int, owner_path: Path) -> bool:
    """Return whether a path is a current matching-bank owner.

    A natural source module is the compiler-facing owner after reunification.
    Keep the legacy matching-bank path valid for pre-reunification groups and
    test fixtures.
    """
    resolved = owner_path.resolve()
    matching_dir = (REPO_ROOT / "src" / "matching").resolve()
    try:
        resolved.relative_to(matching_dir)
    except ValueError:
        pass
    else:
        return True

    return _natural_matching_owner_path(va, resolved)


def _natural_matching_owner_path(va: int, owner_path: Path) -> bool:
    """Return whether a matching VA uses its natural source-module path."""
    entry = source_module_entry_for_va(va)
    if entry is None or str(entry.get("status") or "") != "matching":
        return False
    module = entry.get("module")
    if not isinstance(module, dict):
        return False
    source = repo_path(str(module.get("source") or "")).resolve()
    return owner_path.resolve() == source


def validate_authentic_prefix(
    target: PdbOwner,
    prefixes: list[PdbOwner],
    owner_paths: dict[int, Path],
) -> list[dict[str, str]]:
    seen: set[int] = set()
    previous: PdbOwner | None = None
    target_path = _normalized_pdb_path(target.source_path)
    address_conflicts: list[dict[str, str]] = []
    for prefix in prefixes:
        if prefix.va == target.va:
            raise ValueError("The target cannot also be a prefix owner")
        if prefix.va in seen:
            raise ValueError(f"Duplicate prefix owner {prefix.va:08X}")
        seen.add(prefix.va)
        if _normalized_pdb_path(prefix.source_path) != target_path:
            raise ValueError(
                f"{prefix.va:08X} and {target.va:08X} have different PDB source modules"
            )
        if prefix.line_end >= target.line_start:
            raise ValueError(
                f"{prefix.va:08X} PDB lines {prefix.line_start}-{prefix.line_end} "
                f"do not precede target line {target.line_start}"
            )
        if prefix.va >= target.va:
            address_conflicts.append(
                {
                    "earlier_source_va": f"{prefix.va:08X}",
                    "later_source_va": f"{target.va:08X}",
                    "detail": "PDB source order and linked address order differ",
                }
            )
        if previous is not None:
            if prefix.line_start <= previous.line_end:
                raise ValueError(
                    f"PDB source ranges for {previous.va:08X} and {prefix.va:08X} overlap or reverse"
                )
            if prefix.va <= previous.va:
                address_conflicts.append(
                    {
                        "earlier_source_va": f"{previous.va:08X}",
                        "later_source_va": f"{prefix.va:08X}",
                        "detail": "PDB source order and linked address order differ",
                    }
                )
        owner_path = owner_paths.get(prefix.va)
        if owner_path is None:
            raise ValueError(f"{prefix.va:08X} has no configured compiler-facing owner")
        if not _is_matching_owner_path(prefix.va, owner_path):
            raise ValueError(
                f"{prefix.va:08X} is not an exact anchor in a current matching owner: {owner_path}"
            )
        previous = prefix

    resolved = [owner_paths[prefix.va].resolve() for prefix in prefixes]
    if len(resolved) != len(set(resolved)) and not all(
        _natural_matching_owner_path(prefix.va, owner_paths[prefix.va])
        for prefix in prefixes
    ):
        raise ValueError("Two prefix VAs use the same compiler-facing owner")
    return address_conflicts


def _owner_include_lines(group: dict[str, object], wrapper_path: Path) -> dict[int, str]:
    owners = group.get("owners")
    if not isinstance(owners, dict):
        raise ValueError("Translation unit owners are missing")
    result: dict[int, str] = {}
    for raw_va, raw_path in owners.items():
        owner_path = repo_path(str(raw_path)).resolve()
        include_name = str(owner_path.relative_to(wrapper_path.resolve().parent)).replace("\\", "/")
        result[int(str(raw_va), 16)] = f'#include "{include_name}"'
    return result


def render_filtered_wrapper(
    wrapper_text: str,
    include_lines: dict[int, str],
    selected_vas: list[int],
) -> str:
    if len(selected_vas) != len(set(selected_vas)):
        raise ValueError("A generated translation unit cannot include one owner twice")
    unknown = [va for va in selected_vas if va not in include_lines]
    if unknown:
        raise ValueError(f"Owners are not configured in this translation unit: {unknown}")

    source_lines = wrapper_text.splitlines()
    owner_line_to_va = {line: va for va, line in include_lines.items()}
    owner_indexes = [
        index for index, line in enumerate(source_lines) if line.strip() in owner_line_to_va
    ]
    if len(owner_indexes) != len(include_lines):
        raise ValueError("Configured wrapper does not contain each owner include exactly once")
    configured_order = [owner_line_to_va[source_lines[index].strip()] for index in owner_indexes]
    if configured_order != list(include_lines):
        raise ValueError("Configured wrapper owner includes are out of manifest order")
    selected_order = [va for va in configured_order if va in set(selected_vas)]
    if selected_order != selected_vas:
        raise ValueError("Selected owners must keep configured wrapper order")
    for index, line in enumerate(source_lines):
        stripped = line.strip()
        if index in owner_indexes or not stripped:
            continue
        if stripped.startswith(("#", "//", "/*", "*", "*/")):
            continue
        raise ValueError(
            "Configured wrapper contains code outside canonical owner includes; "
            "synthetic context is not allowed"
        )

    selected = set(selected_vas)
    generated: list[str] = []
    for line in source_lines:
        va = owner_line_to_va.get(line.strip())
        if va is not None:
            if va in selected:
                generated.append(line)
            continue
        generated.append(line)
    return "\n".join(generated) + "\n"


def _select_symbol(obj, va: int, group: dict[str, object]):
    symbols = group.get("symbols")
    exact_name = symbols.get(f"{va:08X}") if isinstance(symbols, dict) else None
    if exact_name:
        return select_exact_function_symbol(obj, str(exact_name))
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


def compare_object_owner(
    obj,
    va: int,
    group: dict[str, object],
    expected_pdb_symbol: str = "",
    *,
    require_owner: bool = True,
) -> dict[str, object]:
    record = function_record_by_va(va)
    symbol = _select_symbol(obj, va, group)
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


def _compile_wrapper(source_path: Path, obj_path: Path, rsp_path: Path, wrapper_dir: Path) -> dict[str, object]:
    toolchain = load_toolchain()
    compiler = repo_path(toolchain["compiler"]["cl"])
    command = [
        str(compiler),
        f"@{rsp_path}",
        f"/I{wrapper_dir}",
        f"/Fo{obj_path}",
        str(source_path),
    ]
    result = subprocess.run(command, capture_output=True, text=True, env=tool_env(toolchain))
    manifest = {
        "command": command,
        "source": str(source_path),
        "object": str(obj_path),
        "response_file": str(rsp_path),
        "returncode": result.returncode,
        "stdout": result.stdout,
        "stderr": result.stderr,
    }
    if result.returncode != 0 or not obj_path.is_file():
        raise RuntimeError(result.stdout + result.stderr)
    return manifest


def _default_prefixes(
    target: PdbOwner,
    group: dict[str, object],
    source_map: dict[str, dict[str, str]],
) -> list[PdbOwner]:
    owners = group.get("owners")
    assert isinstance(owners, dict)
    candidates: list[PdbOwner] = []
    for raw_va in owners:
        va = int(str(raw_va), 16)
        if va == target.va:
            continue
        try:
            owner = pdb_owner_for_va(va, source_map)
        except ValueError:
            continue
        if (
            _normalized_pdb_path(owner.source_path) == _normalized_pdb_path(target.source_path)
            and owner.line_end < target.line_start
        ):
            candidates.append(owner)
    return sorted(candidates, key=lambda owner: (owner.line_start, owner.va))


def main() -> None:
    args = parse_args()
    target_va = int(args.va, 16)
    group = translation_unit_for_va(target_va)
    if group is None:
        raise SystemExit(
            f"{target_va:08X} has no configured translation unit. "
            "The tool rejects ad hoc wrapper and source inputs."
        )
    validate_translation_unit(group)
    manifest_issues = validate_translation_units([group])
    if manifest_issues:
        raise SystemExit(
            "Invalid translation-unit manifest: "
            + "; ".join(str(issue) for issue in manifest_issues)
        )
    owners = group.get("owners")
    assert isinstance(owners, dict)
    owner_paths = {int(str(va), 16): repo_path(str(path)) for va, path in owners.items()}
    source_map = load_pdb_function_source_map()
    target = pdb_owner_for_va(target_va, source_map)
    if args.prefix_va:
        prefixes = [pdb_owner_for_va(int(value, 16), source_map) for value in args.prefix_va]
    else:
        prefixes = _default_prefixes(target, group, source_map)
    for prefix in prefixes:
        configured = owner_paths.get(prefix.va)
        if configured is None:
            raise SystemExit(
                f"{prefix.va:08X} is not an owner in target translation unit {group['name']}"
            )
        canonical = _matching_owner_path(prefix.va)
        if configured.resolve() != canonical:
            raise SystemExit(
                f"{prefix.va:08X} configured owner is not canonical: {configured} != {canonical}"
            )
    address_conflicts = validate_authentic_prefix(target, prefixes, owner_paths)
    pdb_symbols = {owner.va: owner.symbol_name for owner in [*prefixes, target]}

    wrapper_path = repo_path(str(group["source"]))
    wrapper_text = wrapper_path.read_text(encoding="utf-8")
    include_lines = _owner_include_lines(group, wrapper_path)
    flags_value = str(group.get("flags") or "").strip()
    toolchain = load_toolchain()
    rsp_path = repo_path(flags_value or str(toolchain["compiler"]["default_rsp"]))
    output_dir = REPO_ROOT / "build" / "tu_prefixes" / function_slug(function_record_by_va(target_va))
    output_dir.mkdir(parents=True, exist_ok=True)

    plans: list[tuple[str, list[int], list[int]]] = [("00_target_only", [target_va], [])]
    for index, prefix in enumerate(prefixes, 1):
        anchor_vas = [owner.va for owner in prefixes[:index]]
        plans.append((f"{index:02d}_through_{prefix.va:08X}", anchor_vas + [target_va], anchor_vas))

    report: dict[str, object] = {
        "schema": 1,
        "target": f"{target_va:08X}",
        "translation_unit": group["name"],
        "pdb_source_path": target.source_path,
        "pdb_source_lines": [target.line_start, target.line_end],
        "class_owner": target.class_owner,
        "address_sequence_conflicts": address_conflicts,
        "prefixes": [f"{owner.va:08X}" for owner in prefixes],
        "prefix_evidence": [
            {
                "va": f"{owner.va:08X}",
                "symbol_name": owner.symbol_name,
                "source_path": owner.source_path,
                "source_lines": [owner.line_start, owner.line_end],
                "class_owner": owner.class_owner,
                "compiler_owner": str(owner_paths[owner.va]),
            }
            for owner in prefixes
        ],
        "contexts": [],
    }
    contexts = report["contexts"]
    assert isinstance(contexts, list)
    for label, selected_vas, anchor_vas in plans:
        generated_path = output_dir / f"{label}{wrapper_path.suffix}"
        obj_path = output_dir / f"{label}.obj"
        manifest_path = output_dir / f"{label}.build.json"
        generated_path.write_text(
            render_filtered_wrapper(wrapper_text, include_lines, selected_vas),
            encoding="utf-8",
        )
        if obj_path.exists():
            obj_path.unlink()
        manifest = _compile_wrapper(generated_path, obj_path, rsp_path, wrapper_path.parent)
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
        obj = load_coff_object(obj_path)
        anchor_results = [
            compare_object_owner(obj, va, group, pdb_symbols.get(va, "")) for va in anchor_vas
        ]
        anchors_valid = all(row["result"] == "MATCH" for row in anchor_results)
        target_result = compare_object_owner(obj, target_va, group, pdb_symbols.get(target_va, ""))
        context_result = {
            "label": label,
            "source": str(generated_path),
            "object": str(obj_path),
            "owners": [f"{va:08X}" for va in selected_vas],
            "anchors_valid": anchors_valid,
            "anchors": anchor_results,
            "target": target_result,
            "claim": target_result["result"] if anchors_valid else "INVALID_CONTEXT",
        }
        contexts.append(context_result)
        anchor_text = f"anchors {len(anchor_results)}/{len(anchor_results)}"
        if not anchors_valid:
            anchor_text = (
                f"anchors {sum(row['result'] == 'MATCH' for row in anchor_results)}/"
                f"{len(anchor_results)}"
            )
        print(
            f"{label}: {anchor_text}; target {context_result['claim']} "
            f"({target_result['diff_bytes']} bytes, {float(target_result['diff_percent']):.4f}%)"
        )

    report_path = output_dir / "report.json"
    report_path.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(f"PDB source: {target.source_path} lines {target.line_start}-{target.line_end}")
    print(f"Wrote {report_path}")
    invalid = [row for row in contexts if row["claim"] == "INVALID_CONTEXT"]
    if invalid:
        raise SystemExit("One or more contexts failed exact-anchor validation")


if __name__ == "__main__":
    main()
