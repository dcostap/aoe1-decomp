from __future__ import annotations

"""Compile and compare one unregistered or proposed translation unit."""

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

from coff import load_coff_object
from common import (
    REPO_ROOT,
    function_record_by_va,
    load_compiler_generated_functions,
    load_pdb_function_source_map,
    pdb_module_stream_procedure_for_va,
    preferred_source_path,
    repo_path,
    slugify_name,
    source_module_entry_for_va,
)
from translation_unit_prefixes import _compile_wrapper, compare_object_owner


_INCLUDE = re.compile(r'^\s*#\s*include\s*"([^"]+)"(?:\s*//.*)?\s*$')
_SOURCE_BANKS = {"matching", "accepted_drift", "verified_logic", "scratch"}
_INLINE_ASM = re.compile(r"\b(?:__asm|_asm)\b")
_FAKE_VIRTUAL_SLOT = re.compile(
    r"\bvirtual\b[^;{]*(?:\bvf[0-9A-Fa-f]{2,}\b|\bvpad[0-9A-Fa-f]{2,}\b)"
)
_TOKEN_PASTED_VIRTUAL = re.compile(r"\bvirtual\b[^;{]*##")
_RAW_VTABLE_FIELD = re.compile(r"\bvoid\s*\*\s*(?:vtable_ptr|vptr)\s*;")
_COFF_WEAK_EXTERNAL = 105  # IMAGE_SYM_CLASS_WEAK_EXTERNAL
_COFF_WEAK_EXTERN_SEARCH_LIBRARY = 2  # IMAGE_WEAK_EXTERN_SEARCH_LIBRARY
_COMPILER_GENERATED_DELETING_DESTRUCTOR = "compiler_generated_deleting_destructor"


def _generated_fallback_symbol(expected_symbol: str) -> str:
    """Return the scalar destructor symbol paired with a vector destructor."""
    if not expected_symbol.startswith("??_E"):
        raise ValueError(
            f"Generated destructor symbol must be a ??_E symbol: {expected_symbol!r}"
        )
    suffix = expected_symbol[4:]
    owner = suffix.split("@@", 1)[0]
    if not owner or "@@" not in suffix or any(character.isspace() for character in expected_symbol):
        raise ValueError(f"Generated destructor symbol is not a decorated ??_E name: {expected_symbol!r}")
    return "??_G" + suffix


def _compiler_generated_destructor_symbols(obj, va: int, expected_symbol: str):
    """Validate one authentic VC5 weak vector-destructor pair.

    VC5 emits an undefined ``??_G`` declaration, a weak ``??_E`` symbol whose
    auxiliary record points at that declaration, and a defined ``??_G`` body.
    The body is the only bytes that can be compared to the executable range.
    """
    fallback_name = _generated_fallback_symbol(expected_symbol)
    candidates = [symbol for symbol in obj.symbols if symbol.name == expected_symbol]
    if len(candidates) != 1:
        raise ValueError(
            f"{va:08X} expected one weak external {expected_symbol!r}; "
            f"found {len(candidates)}"
        )
    weak_symbol = candidates[0]
    if (
        weak_symbol.storage_class != _COFF_WEAK_EXTERNAL
        or weak_symbol.section_number != 0
        or not getattr(weak_symbol, "is_function", False)
    ):
        raise ValueError(f"{va:08X} expected {expected_symbol!r} as an undefined COFF WeakExternal")
    if weak_symbol.auxiliary_count != 1:
        raise ValueError(f"{va:08X} weak external {expected_symbol!r} has no single fallback record")
    tag_index = getattr(weak_symbol, "weak_external_tag_index", None)
    characteristics = getattr(weak_symbol, "weak_external_characteristics", None)
    if tag_index is None:
        raise ValueError(f"{va:08X} weak external {expected_symbol!r} has no fallback index")
    if characteristics != _COFF_WEAK_EXTERN_SEARCH_LIBRARY:
        raise ValueError(
            f"{va:08X} weak external {expected_symbol!r} is not a VC5 fallback weak external"
        )

    symbol_by_index = {symbol.index: symbol for symbol in obj.symbols}
    tagged_symbol = symbol_by_index.get(tag_index)
    if (
        tagged_symbol is None
        or tagged_symbol.name != fallback_name
        or not getattr(tagged_symbol, "is_function", False)
    ):
        tagged_name = "<missing>" if tagged_symbol is None else tagged_symbol.name
        raise ValueError(
            f"{va:08X} weak external {expected_symbol!r} falls back to {tagged_name!r}, "
            f"not same-class {fallback_name!r}"
        )
    defined = [
        symbol
        for symbol in obj.symbols
        if symbol.name == fallback_name
        and symbol.section_number > 0
        and getattr(symbol, "is_function", False)
    ]
    if len(defined) != 1:
        raise ValueError(
            f"{va:08X} expected one defined same-class fallback {fallback_name!r}; "
            f"found {len(defined)}"
        )
    return weak_symbol, tagged_symbol, defined[0]


def _weak_fallback_entry(va: str, expected_symbol: str) -> bool:
    """Return whether one generated entry can use the VC5 weak fallback form."""
    return (
        load_compiler_generated_functions().get(int(va, 16))
        == _COMPILER_GENERATED_DELETING_DESTRUCTOR
        and expected_symbol.startswith("??_E")
    )


def _has_weak_external(obj, expected_symbol: str) -> bool:
    return any(
        symbol.name == expected_symbol
        and symbol.storage_class == _COFF_WEAK_EXTERNAL
        and symbol.section_number == 0
        for symbol in obj.symbols
    )


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=(
            "Compile one candidate translation unit and compare exact, observed, "
            "and compiler-generated functions without changing global config."
        ),
        epilog=(
            "Proposal schema:\n"
            "  {\n"
            "    \"schema\": 1, \"name\": \"module_name\",\n"
            "    \"module\": \"PDB_file.cpp\", \"source\": \"src/module_tu.cpp\",\n"
            "    \"flags\": \"config/flags/module.rsp\",\n"
            "    \"owners\": {\"00401000\": \"src/matching/00401000_name.cpp\"},\n"
            "    \"observed\": {\"00401100\": {\"source\": \"src/scratch/00401100_name.cpp\", \"status\": \"scratch\"}},\n"
            "    \"generated\": {\"00401200\": \"??_EClass@@UAEPAXI@Z\"},\n"
            "    \"symbols\": {\"00401000\": \"?name@Class@@QAEXXZ\"}\n"
            "  }"
        ),
    )
    parser.add_argument("--proposal", type=Path, required=True, help="Candidate proposal JSON.")
    parser.add_argument(
        "--output-dir",
        type=Path,
        help="Output directory. The default is build/candidate_tus/<proposal name>.",
    )
    return parser.parse_args()


def _normalized_module(value: str) -> str:
    return value.replace("/", "\\").casefold()


def _resolve(value: object) -> Path:
    return repo_path(str(value or "").strip().replace("\\", "/"))


def _va(value: object) -> int:
    text = str(value).strip()
    if not re.fullmatch(r"[0-9A-Fa-f]{8}", text):
        raise ValueError(f"Invalid function VA {value!r}")
    return int(text, 16)


def _observed_entries(value: object) -> dict[str, dict[str, str]]:
    if value is None:
        return {}
    if not isinstance(value, dict):
        raise ValueError("observed must be an object")
    result: dict[str, dict[str, str]] = {}
    for raw_va, raw_entry in value.items():
        va = f"{_va(raw_va):08X}"
        if isinstance(raw_entry, str):
            entry = {"source": raw_entry, "status": "observe"}
        elif isinstance(raw_entry, dict):
            entry = {
                "source": str(raw_entry.get("source") or ""),
                "status": str(raw_entry.get("status") or "observe"),
            }
        else:
            raise ValueError(f"Observed entry {va} must be a path or object")
        if not entry["source"]:
            raise ValueError(f"Observed entry {va} has no source")
        result[va] = entry
    return result


def _generated_entries(value: object) -> dict[str, str]:
    if value is None:
        return {}
    if not isinstance(value, dict):
        raise ValueError("generated must be an object")
    result: dict[str, str] = {}
    for raw_va, raw_symbol in value.items():
        va = f"{_va(raw_va):08X}"
        symbol = str(raw_symbol or "").strip()
        if not symbol or any(character.isspace() for character in symbol):
            raise ValueError(f"Generated entry {va} needs one exact decorated symbol")
        result[va] = symbol
    return result


def load_proposal(path: Path) -> dict[str, object]:
    payload = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        raise ValueError("Proposal root must be an object")
    if payload.get("schema") != 1:
        raise ValueError("Proposal schema must be 1")
    for key in ("name", "module", "source", "flags"):
        if not str(payload.get(key) or "").strip():
            raise ValueError(f"Proposal needs {key}")
    raw_owners = payload.get("owners")
    if raw_owners is None:
        raw_owners = {}
    if not isinstance(raw_owners, dict):
        raise ValueError("owners must be an object")
    owners = {f"{_va(va):08X}": str(source) for va, source in raw_owners.items()}
    observed = _observed_entries(payload.get("observed"))
    generated = _generated_entries(payload.get("generated"))
    all_vas = list(owners) + list(observed) + list(generated)
    if not all_vas:
        raise ValueError("Proposal has no functions to check")
    if len(all_vas) != len(set(all_vas)):
        raise ValueError("A VA appears in more than one proposal section")
    symbols = payload.get("symbols") or {}
    if not isinstance(symbols, dict):
        raise ValueError("symbols must be an object")
    normalized_symbols = {f"{_va(va):08X}": str(symbol) for va, symbol in symbols.items()}
    unknown_symbols = set(normalized_symbols) - set(owners) - set(observed)
    if unknown_symbols:
        raise ValueError(f"symbols contain unknown VAs: {sorted(unknown_symbols)}")
    payload = dict(payload)
    payload["owners"] = owners
    payload["observed"] = observed
    payload["generated"] = generated
    payload["symbols"] = normalized_symbols
    return payload


def _source_includes(wrapper: Path) -> list[tuple[int, Path]]:
    result: list[tuple[int, Path]] = []
    for index, line in enumerate(wrapper.read_text(encoding="utf-8").splitlines()):
        match = _INCLUDE.match(line)
        if match is None:
            continue
        result.append(
            (index, (wrapper.parent / match.group(1).replace("\\", "/")).resolve())
        )
    return result


def _source_closure(source: Path) -> list[Path]:
    result: list[Path] = []
    pending = [source.resolve()]
    seen: set[Path] = set()
    while pending:
        current = pending.pop()
        if current in seen or not current.is_file():
            continue
        seen.add(current)
        result.append(current)
        try:
            lines = current.read_text(encoding="utf-8").splitlines()
        except OSError:
            continue
        for line in lines:
            match = _INCLUDE.match(line)
            if match is None:
                continue
            included = (current.parent / match.group(1).replace("\\", "/")).resolve()
            try:
                included.relative_to(REPO_ROOT.resolve())
            except ValueError:
                continue
            pending.append(included)
    return result


def _source_policy_issues(wrapper: Path) -> list[str]:
    findings: dict[tuple[Path, str], list[int]] = {}
    for source in _source_closure(wrapper):
        in_block_comment = False
        for line_number, raw_line in enumerate(
            source.read_text(encoding="utf-8").splitlines(), start=1
        ):
            line = raw_line
            if in_block_comment:
                if "*/" not in line:
                    continue
                line = line.split("*/", 1)[1]
                in_block_comment = False
            while "/*" in line:
                before, after = line.split("/*", 1)
                if "*/" in after:
                    line = before + after.split("*/", 1)[1]
                else:
                    line = before
                    in_block_comment = True
                    break
            line = line.split("//", 1)[0]
            if _INLINE_ASM.search(line):
                findings.setdefault((source, "inline assembly"), []).append(line_number)
            if _FAKE_VIRTUAL_SLOT.search(line) or _TOKEN_PASTED_VIRTUAL.search(line):
                findings.setdefault((source, "placeholder virtual slots"), []).append(line_number)
            if _RAW_VTABLE_FIELD.search(line):
                findings.setdefault((source, "raw vtable fields"), []).append(line_number)
    issues: list[str] = []
    for (source, kind), lines in sorted(
        findings.items(), key=lambda item: (str(item[0][0]).casefold(), item[0][1])
    ):
        suffix = f"line {lines[0]}" if len(lines) == 1 else f"{len(lines)} lines; first {lines[0]}"
        issues.append(f"source policy forbids {kind} in {source} ({suffix})")
    return issues


def _newline_style(data: bytes) -> str:
    line_feeds = data.count(b"\n")
    if line_feeds == 0:
        return "none"
    crlf = data.count(b"\r\n")
    if crlf == line_feeds:
        return "CRLF"
    if crlf == 0:
        return "LF"
    return "mixed"


def _line_ending_warnings(payload: dict[str, object]) -> list[str]:
    owners = payload["owners"]
    observed = payload["observed"]
    assert isinstance(owners, dict)
    assert isinstance(observed, dict)
    checks: dict[str, str] = dict(owners)
    checks.update({va: entry["source"] for va, entry in observed.items()})
    warnings: list[str] = []
    for va, source_value in checks.items():
        source = _resolve(source_value)
        try:
            relative = source.resolve().relative_to(REPO_ROOT.resolve())
        except ValueError:
            continue
        completed = subprocess.run(
            ["git", "show", f"HEAD:{relative.as_posix()}"],
            cwd=REPO_ROOT,
            capture_output=True,
            check=False,
        )
        if completed.returncode != 0 or not source.is_file():
            continue
        old_style = _newline_style(completed.stdout)
        new_style = _newline_style(source.read_bytes())
        if old_style != new_style:
            warnings.append(f"{va} line endings changed: {old_style} -> {new_style}")
    return warnings


def validate_proposal(payload: dict[str, object]) -> list[str]:
    issues: list[str] = []
    wrapper = _resolve(payload["source"])
    flags = _resolve(payload["flags"])
    if not wrapper.is_file():
        issues.append(f"missing wrapper: {wrapper}")
    if not flags.is_file():
        issues.append(f"missing flags: {flags}")
    if issues:
        return issues
    issues.extend(_source_policy_issues(wrapper))

    owners = payload["owners"]
    observed = payload["observed"]
    generated = payload.get("generated") or {}
    assert isinstance(owners, dict)
    assert isinstance(observed, dict)
    assert isinstance(generated, dict)
    for va, expected_symbol in generated.items():
        if _weak_fallback_entry(va, expected_symbol):
            try:
                _generated_fallback_symbol(expected_symbol)
            except ValueError as error:
                issues.append(str(error))
    checks: dict[str, str] = dict(owners)
    checks.update({va: entry["source"] for va, entry in observed.items()})
    pdb_map = load_pdb_function_source_map()
    proposal_module = _normalized_module(str(payload["module"]))
    proposal_name = Path(str(payload["module"]).replace("\\", "/")).name.casefold()
    include_rows = _source_includes(wrapper)
    include_positions: list[tuple[int, int, str]] = []

    for va, source_value in checks.items():
        source = _resolve(source_value)
        if not source.is_file():
            issues.append(f"{va} source is missing: {source}")
            continue
        record = function_record_by_va(int(va, 16))
        if source.resolve() != preferred_source_path(record).resolve():
            issues.append(f"{va} is not the canonical source: {source_value}")
        module_entry = source_module_entry_for_va(va)
        direct_module = False
        source_module = None
        if module_entry is not None and source.resolve() == wrapper.resolve():
            source_module = module_entry["module"]
            assert isinstance(source_module, dict)
            direct_module = _resolve(source_module["source"]).resolve() == wrapper.resolve()
        if va in owners:
            if direct_module:
                if str(module_entry["status"]) != "matching":
                    issues.append(f"{va} exact owner is not matching in its source module")
            else:
                matching = (REPO_ROOT / "src" / "matching").resolve()
                try:
                    source.resolve().relative_to(matching)
                except ValueError:
                    issues.append(f"{va} exact owner is not in src/matching: {source_value}")
        positions = [] if direct_module else [
            index for index, included in include_rows if included == source.resolve()
        ]
        if not direct_module and len(positions) != 1:
            issues.append(f"{va} source include count is {len(positions)}, expected 1")
        pdb = pdb_map.get(va, {})
        pdb_module = str(pdb.get("primary_source_path") or pdb.get("primary_source_file") or "")
        pdb_name = Path(pdb_module.replace("\\", "/")).name.casefold()
        pdb_symbol = str(pdb.get("symbol_name") or "").strip()
        if va in owners and not pdb_symbol:
            issues.append(f"{va} has no PDB-qualified symbol ownership")
        stream_owner = None
        if source_module is not None and source_module.get("pdb_no_line_info"):
            stream_owner = pdb_module_stream_procedure_for_va(source_module, va)
        if va in owners and source_module is not None and source_module.get("pdb_no_line_info"):
            if stream_owner is None:
                issues.append(f"{va} has no PDB module-stream ownership")
            elif str(stream_owner.get("name") or "") != pdb_symbol:
                issues.append(f"{va} PDB module-stream symbol does not match PDB ownership")
        no_line_observation = bool(
            source_module
            and source_module.get("pdb_no_line_info")
            and va not in owners
            and not pdb_module
            and _normalized_module(str(source_module["pdb_source_path"])) == proposal_module
        )
        no_line_owner = bool(
            source_module
            and source_module.get("pdb_no_line_info")
            and va in owners
            and stream_owner is not None
            and pdb_symbol
            and str(stream_owner.get("name") or "") == pdb_symbol
            and _normalized_module(str(source_module["pdb_source_path"])) == proposal_module
        )
        if (
            _normalized_module(pdb_module) != proposal_module
            and pdb_name != proposal_name
            and not no_line_observation
            and not no_line_owner
        ):
            issues.append(f"{va} PDB module {pdb_module!r} does not match {payload['module']!r}")
        try:
            line_start = int(str(pdb.get("line_start") or 0))
        except ValueError:
            line_start = 0
        if positions:
            include_positions.append((positions[0], line_start, va))

    proposal_sources = {_resolve(path).resolve() for path in checks.values()}
    for _, included in include_rows:
        try:
            relative = included.relative_to((REPO_ROOT / "src").resolve())
        except ValueError:
            continue
        if relative.parts and relative.parts[0] in _SOURCE_BANKS and included not in proposal_sources:
            issues.append(f"unlisted owner include: {included}")

    ordered = sorted(include_positions)
    pdb_lines = [line for _, line, _ in ordered if line > 0]
    if pdb_lines != sorted(pdb_lines):
        issues.append("wrapper owner includes are not in PDB source-line order")
    return issues


def _result_row(kind: str, status: str, result: dict[str, object]) -> dict[str, object]:
    relocations = result["relocations"]
    assert isinstance(relocations, dict)
    owner = result["owner_symbol"]
    assert isinstance(owner, dict)
    return {
        "va": result["va"],
        "kind": kind,
        "status": status,
        "result": result["result"],
        "diff_bytes": result["diff_bytes"],
        "diff_percent": result["diff_percent"],
        "original_size": result["original_size"],
        "rebuilt_size": result["rebuilt_size"],
        "owner_status": owner.get("status", ""),
        "relocation_target_mismatches": len(relocations.get("target_mismatches") or []),
        "boundary_escape_count": len(result["boundary_escape_offsets"]),
        "symbol": result["symbol"],
        "expected_symbol": result.get("expected_symbol", ""),
        "fallback_symbol": result.get("fallback_symbol", ""),
        "error": "",
    }


def _error_row(kind: str, status: str, va: str, error: Exception) -> dict[str, object]:
    return {
        "va": va,
        "kind": kind,
        "status": status,
        "result": "ERROR",
        "diff_bytes": "-",
        "diff_percent": "",
        "original_size": "",
        "rebuilt_size": "",
        "owner_status": "error",
        "relocation_target_mismatches": "-",
        "boundary_escape_count": "-",
        "symbol": "",
        "expected_symbol": "",
        "fallback_symbol": "",
        "error": str(error),
    }


def _compare_generated_destructor(obj, va: int, group: dict[str, object]) -> dict[str, object]:
    """Compare a generated VA through its authentic ``??_G`` fallback body."""
    va_text = f"{va:08X}"
    symbols = group.get("symbols")
    expected_symbol = symbols.get(va_text) if isinstance(symbols, dict) else None
    if not expected_symbol:
        raise ValueError(f"{va_text} has no expected generated symbol")
    if not _weak_fallback_entry(va_text, str(expected_symbol)):
        raise ValueError(f"{va_text} is not a weak generated deleting-destructor entry")
    _, _, fallback_symbol = _compiler_generated_destructor_symbols(
        obj, va, str(expected_symbol)
    )

    fallback_group = dict(group)
    fallback_symbols = dict(symbols) if isinstance(symbols, dict) else {}
    fallback_symbols[va_text] = fallback_symbol.name
    fallback_group["symbols"] = fallback_symbols
    result = compare_object_owner(
        obj,
        va,
        fallback_group,
        require_owner=False,
    )
    if result.get("symbol") != fallback_symbol.name:
        raise ValueError(
            f"{va_text} comparison selected {result.get('symbol')!r}, "
            f"not fallback {fallback_symbol.name!r}"
        )
    # Keep both names in the machine-readable report.  ``symbol`` remains the
    # body symbol selected by the comparison, while the expected weak symbol
    # records the linker identity that justified selecting that body.
    result["expected_symbol"] = str(expected_symbol)
    result["fallback_symbol"] = fallback_symbol.name
    return result


def _compare_generated_entry(obj, va: int, group: dict[str, object]) -> dict[str, object]:
    """Use weak fallback comparison only for a weak deleting destructor."""
    va_text = f"{va:08X}"
    symbols = group.get("symbols")
    expected_symbol = symbols.get(va_text) if isinstance(symbols, dict) else None
    if not expected_symbol:
        raise ValueError(f"{va_text} has no expected generated symbol")
    expected_symbol = str(expected_symbol)
    if _weak_fallback_entry(va_text, expected_symbol) and _has_weak_external(
        obj, expected_symbol
    ):
        return _compare_generated_destructor(obj, va, group)
    return compare_object_owner(obj, va, group, require_owner=False)


def _render(rows: list[dict[str, object]]) -> str:
    lines = [
        "VA        KIND       STATUS           RESULT    DIFF  OWNER      RELOCS  BOUNDARY",
    ]
    for row in rows:
        lines.append(
            f"{row['va']}  {row['kind']:<9}  {row['status']:<15}  {row['result']:<8}  "
            f"{row['diff_bytes']:>4}  {row['owner_status']:<9}  "
            f"{row['relocation_target_mismatches']:>6}  {row['boundary_escape_count']:>8}"
        )
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    try:
        payload = load_proposal(args.proposal)
    except (OSError, ValueError, json.JSONDecodeError) as error:
        print(f"Invalid proposal: {error}", file=sys.stderr)
        return 2
    issues = validate_proposal(payload)
    if issues:
        for issue in issues:
            print(f"proposal: {issue}", file=sys.stderr)
        return 2
    warnings = _line_ending_warnings(payload)
    for warning in warnings:
        print(f"warning: {warning}", file=sys.stderr)

    name = slugify_name(str(payload["name"]))
    output_dir = args.output_dir or REPO_ROOT / "build" / "candidate_tus" / name
    output_dir.mkdir(parents=True, exist_ok=True)
    wrapper = _resolve(payload["source"])
    flags = _resolve(payload["flags"])
    object_path = output_dir / f"{name}.obj"
    manifest_path = output_dir / "build.json"
    report_path = output_dir / "report.json"
    text_path = output_dir / "report.txt"
    if object_path.exists():
        object_path.unlink()
    try:
        manifest = _compile_wrapper(wrapper, object_path, flags, wrapper.parent)
    except RuntimeError as error:
        print(f"Candidate compile failed:\n{error}", file=sys.stderr)
        return 2
    manifest_path.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    obj = load_coff_object(object_path)

    owners = payload["owners"]
    observed = payload["observed"]
    generated = payload["generated"]
    symbols = payload["symbols"]
    assert isinstance(owners, dict)
    assert isinstance(observed, dict)
    assert isinstance(generated, dict)
    assert isinstance(symbols, dict)
    selection_group = {
        "owners": {**owners, **{va: entry["source"] for va, entry in observed.items()}},
        "symbols": {**symbols, **generated},
    }
    rows: list[dict[str, object]] = []
    for va in owners:
        try:
            result = compare_object_owner(obj, int(va, 16), selection_group)
        except (KeyError, ValueError) as error:
            rows.append(_error_row("exact", "matching", va, error))
        else:
            rows.append(_result_row("exact", "matching", result))
    for va, entry in observed.items():
        try:
            result = compare_object_owner(obj, int(va, 16), selection_group)
        except (KeyError, ValueError) as error:
            rows.append(_error_row("observed", entry["status"], va, error))
        else:
            rows.append(_result_row("observed", entry["status"], result))
    for va in generated:
        try:
            result = _compare_generated_entry(obj, int(va, 16), selection_group)
        except (KeyError, ValueError) as error:
            rows.append(_error_row("generated", "compiler_generated", va, error))
        else:
            rows.append(_result_row("generated", "compiler_generated", result))

    summary = {
        "exact_total": len(owners),
        "exact_matches": sum(row["kind"] == "exact" and row["result"] == "MATCH" for row in rows),
        "observed_total": len(observed),
        "observed_matches": sum(row["kind"] == "observed" and row["result"] == "MATCH" for row in rows),
        "generated_total": len(generated),
        "generated_matches": sum(row["kind"] == "generated" and row["result"] == "MATCH" for row in rows),
        "comparison_errors": sum(row["result"] == "ERROR" for row in rows),
        "compiled_total": len(rows),
        "compiled_matches": sum(row["result"] == "MATCH" for row in rows),
    }
    summary["full_module_exact"] = summary["compiled_matches"] == summary["compiled_total"]
    success = (
        summary["exact_matches"] == summary["exact_total"]
        and summary["generated_matches"] == summary["generated_total"]
        and summary["comparison_errors"] == 0
    )
    report = {
        "schema": 1,
        "proposal": str(args.proposal),
        "name": payload["name"],
        "module": payload["module"],
        "source": payload["source"],
        "flags": payload["flags"],
        "success": success,
        "proposal_valid": success,
        "warnings": warnings,
        "summary": summary,
        "rows": rows,
    }
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    text = _render(rows)
    text_path.write_text(text, encoding="utf-8")
    print(text, end="")
    print(json.dumps(summary, sort_keys=True))
    print(f"Wrote {report_path}")
    print(f"Wrote {text_path}")
    return 0 if success else 1


if __name__ == "__main__":
    raise SystemExit(main())
