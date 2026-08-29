"""Audit compiler flags at the source-module and translation-unit boundary.

The preserved PDB identifies the original source module.  A response file
named after one function does not prove that its flags belong to the whole
module.  This tool compares those per-function candidates with each configured
grouped translation unit and reports the differences.

The report is evidence only.  It does not edit ``config`` or source banks.
Generated output belongs under ``build``.
"""

from __future__ import annotations

import argparse
import json
import re
from collections import Counter, defaultdict
from pathlib import Path
from typing import Any, Callable, Iterable

from common import (
    BUILD_DIR,
    REPO_ROOT,
    classify_corpus_bucket,
    function_slug,
    load_binaries,
    load_functions,
    load_layout,
    load_pdb_function_source_map,
    load_translation_units,
    parse_hex,
    preferred_source_path,
    repo_path,
    load_pe_image,
)
from function_diagnostics import decode_instructions, prologue_summary


SCHEMA_VERSION = 1
DEFAULT_OUTPUT = BUILD_DIR / "compiler_flag_audit.json"
_TOKEN_RE = re.compile(r'"[^"\r\n]*"|[^\s]+')
_VA_STEM_RE = re.compile(r"^[0-9A-Fa-f]{8}(?:_|$)")
_LANGUAGE_EXTENSIONS = {
    ".c": "c",
    ".cc": "cpp",
    ".cpp": "cpp",
    ".cxx": "cpp",
    ".h": "unknown",
    ".hh": "cpp",
    ".hpp": "cpp",
    ".hxx": "cpp",
}


def _portable(value: object) -> str:
    return str(value or "").replace("\\", "/").strip()


def _resolve(value: object, root: Path = REPO_ROOT) -> Path:
    raw = _portable(value)
    path = Path(raw)
    return path if path.is_absolute() else root / path


def _display(path: Path, root: Path = REPO_ROOT) -> str:
    try:
        return path.resolve().relative_to(root.resolve()).as_posix()
    except ValueError:
        return _portable(path)


def _strip_comments(line: str) -> str:
    # Response files in this repository use C++ comments.  Do not strip a
    # slash pair inside a quoted include path.
    quoted = False
    for index in range(len(line) - 1):
        character = line[index]
        if character == '"':
            quoted = not quoted
        if not quoted and line[index : index + 2] == "//":
            return line[:index]
    return line


def tokenize_response_flags(text: str) -> tuple[str, ...]:
    """Return deterministic response-file tokens with comments removed."""
    tokens: list[str] = []
    for raw_line in text.splitlines():
        tokens.extend(_TOKEN_RE.findall(_strip_comments(raw_line)))
    return tuple(tokens)


def _switch(token: str) -> str:
    value = token.strip().strip('"').replace("\\", "/")
    if value.startswith(("/", "-")):
        return value[1:]
    return value


def _last_matching_switch(tokens: Iterable[str], names: set[str]) -> str | None:
    wanted = {name.casefold() for name in names}
    result: str | None = None
    for token in tokens:
        switch = _switch(token).casefold()
        if switch in wanted:
            result = switch
    return result


def _language_from_suffix(value: object) -> str:
    suffix = Path(_portable(value)).suffix.casefold()
    return _LANGUAGE_EXTENSIONS.get(suffix, "unknown")


def _canonical_tokens(tokens: Iterable[str]) -> tuple[str, ...]:
    """Return effective switches and stable extras for equality checks."""
    tokens = tuple(tokens)
    ignored = {"nologo", "c"}
    switch_groups = (
        {"o1", "o2", "od", "ox"},
        {"oy", "oy-"},
        {"gx", "gx-"},
        {"tc", "tp"},
        {"ob0", "ob1", "ob2"},
        {"oi", "oi-"},
        {"og", "og-"},
        {"oa", "oa-"},
        {"gd", "gr", "gz"},
    )
    recognized = set().union(*switch_groups)
    values: list[str] = []
    effective: list[str] = []
    for token in tokens:
        normalized = _switch(token).casefold()
        if normalized in ignored or normalized.startswith("@"):
            continue
        if normalized not in recognized:
            values.append(normalized)
    for names in switch_groups:
        last = _last_matching_switch(tokens, names)
        if last is not None:
            effective.append(last)
    return tuple(sorted(values + effective))


def flag_settings(tokens: Iterable[str], *, input_language: str = "unknown") -> dict[str, str]:
    """Extract code-generation settings whose last occurrence wins."""
    token_list = tuple(tokens)
    language_switch = _last_matching_switch(token_list, {"tc", "tp"})
    language = {"tc": "c", "tp": "cpp"}.get(language_switch or "", input_language)
    optimization: str | None = None
    frame: str | None = None
    for token in token_list:
        switch = _switch(token).casefold()
        if switch in {"o1", "o2", "od", "ox"}:
            optimization = switch
        elif switch == "oy":
            frame = "omit"
        elif switch == "oy-":
            frame = "keep"

    return {
        "language": language,
        "optimization": optimization or "unspecified",
        "frame": frame or "unspecified",
        "eh": {"gx": "enabled", "gx-": "disabled"}.get(
            _last_matching_switch(token_list, {"gx", "gx-"}) or "", "unspecified"
        ),
        "inline": _last_matching_switch(token_list, {"ob0", "ob1", "ob2"}) or "unspecified",
        "intrinsics": {"oi": "enabled", "oi-": "disabled"}.get(
            _last_matching_switch(token_list, {"oi", "oi-"}) or "", "unspecified"
        ),
        "global_optimization": _last_matching_switch(token_list, {"og", "og-"}) or "unspecified",
        "alias_analysis": _last_matching_switch(token_list, {"oa", "oa-"}) or "unspecified",
        "calling_convention": _last_matching_switch(token_list, {"gd", "gr", "gz"}) or "unspecified",
    }


def flag_record(
    path: Path,
    text: str,
    *,
    input_language: str = "unknown",
    root: Path = REPO_ROOT,
) -> dict[str, Any]:
    tokens = tokenize_response_flags(text)
    settings = flag_settings(tokens, input_language=input_language)
    return {
        "path": _display(path, root),
        "tokens": list(tokens),
        "signature": list(_canonical_tokens(tokens)),
        "settings": settings,
    }


def _flag_equal(left: dict[str, Any], right: dict[str, Any]) -> bool:
    return tuple(left.get("signature") or ()) == tuple(right.get("signature") or ())


def _module_key(source_row: dict[str, str] | None) -> str:
    if not source_row:
        return ""
    path = _portable(source_row.get("primary_source_path"))
    file_name = str(source_row.get("primary_source_file") or "").strip()
    value = path or file_name
    return value.casefold()


def _module_name(source_row: dict[str, str] | None) -> str:
    if not source_row:
        return ""
    value = str(source_row.get("primary_source_file") or "").strip()
    if value:
        return value
    return Path(_portable(source_row.get("primary_source_path"))).name


def _expected_language(
    source_row: dict[str, str] | None,
    owner_path: Path,
) -> str:
    module_language = _language_from_suffix(
        str((source_row or {}).get("primary_source_file") or "")
    )
    if module_language != "unknown":
        return module_language
    return _language_from_suffix(owner_path)


def _read_flags(
    path: Path,
    *,
    default_path: Path,
    input_language: str,
    root: Path,
    loader: Callable[[Path], str] | None = None,
) -> tuple[dict[str, Any], bool]:
    """Read one response file, falling back to default, and mark custom use."""
    if path.is_file():
        text = loader(path) if loader is not None else path.read_text(encoding="utf-8", errors="replace")
        return flag_record(path, text, input_language=input_language, root=root), path.resolve() != default_path.resolve()
    text = loader(default_path) if loader is not None else default_path.read_text(encoding="utf-8", errors="replace")
    return flag_record(default_path, text, input_language=input_language, root=root), False


def _owner_language_from_group(group: dict[str, object], root: Path) -> str:
    source = _resolve(group.get("source"), root)
    return _language_from_suffix(source)


def _frame_need(instructions: list[Any]) -> tuple[bool | None, int | None]:
    summary = prologue_summary(instructions)
    frame_size = summary.get("frame_size")
    # ``push ebp`` can save EBP as an ordinary callee-saved register while
    # FPO remains active.  Only the frame-base assignment proves an EBP frame.
    frame_pointer = any(
        instruction.text.casefold() == "mov ebp,esp"
        for instruction in instructions[:16]
    )
    if not instructions:
        return None, None
    return frame_pointer, None if frame_size is None else int(frame_size)


def original_needs_for_record(
    record: dict[str, str],
    *,
    image: Any,
    layout_by_va: dict[str, dict[str, Any]],
) -> dict[str, Any]:
    """Extract conservative EH and frame evidence from the original image."""
    va = str(record["va"]).upper()
    entry = layout_by_va.get(va)
    ranges = list((entry or {}).get("body_ranges") or [])
    if not ranges:
        size = int(record.get("size_bytes") or 0)
        ranges = [{"start": va, "end": f"{int(va, 16) + max(size, 1) - 1:08X}"}]

    all_instructions: list[Any] = []
    first_instructions: list[Any] = []
    evidence_ranges: list[str] = []
    for index, body_range in enumerate(ranges):
        start = parse_hex(str(body_range.get("start") or ""))
        end = parse_hex(str(body_range.get("end") or ""))
        if start is None or end is None or end < start:
            continue
        try:
            data = image.read_va_range(start, end)
            decoded = decode_instructions(data, start)
        except (KeyError, ValueError, IndexError):
            continue
        if index == 0:
            first_instructions = decoded
        all_instructions.extend(decoded)
        evidence_ranges.append(f"{start:08X}-{end:08X}")

    frame_pointer, frame_size = _frame_need(first_instructions)
    eh = None
    if all_instructions:
        eh = any("fs:" in instruction.text.casefold() for instruction in all_instructions)
    return {
        "eh": eh,
        "frame_pointer": frame_pointer,
        "frame_size": frame_size,
        "evidence": {
            "source": "original_exe",
            "layout": "orig/ghidra_layout_alpha.json",
            "ranges": evidence_ranges,
        },
    }


def load_original_needs(records: Iterable[dict[str, str]]) -> dict[str, dict[str, Any]]:
    """Load original EH/frame evidence for the supplied records."""
    binaries = load_binaries()
    image = load_pe_image(repo_path(binaries["original_exe"]))
    layout = load_layout(repo_path(binaries["ghidra_layout"]))
    layout_by_va = {
        str(entry.get("start") or "").upper(): entry
        for entry in layout.get("functions", [])
        if isinstance(entry, dict) and entry.get("start")
    }
    return {
        str(record["va"]).upper(): original_needs_for_record(
            record, image=image, layout_by_va=layout_by_va
        )
        for record in records
    }


def _current_group_maps(groups: Iterable[dict[str, object]]) -> tuple[dict[str, dict[str, object]], dict[str, list[str]]]:
    by_va: dict[str, dict[str, object]] = {}
    duplicates: dict[str, list[str]] = defaultdict(list)
    for group in groups:
        name = str(group.get("name") or "").strip()
        owners = group.get("owners") or {}
        if not isinstance(owners, dict):
            continue
        for raw_va in owners:
            va = str(raw_va).upper()
            if va in by_va:
                duplicates[va].extend([str(by_va[va].get("name") or ""), name])
            by_va[va] = group
    return by_va, duplicates


def _issue(code: str, severity: str, scope: str, message: str, *, vas: Iterable[str] = ()) -> dict[str, Any]:
    return {
        "code": code,
        "severity": severity,
        "scope": scope,
        "message": message,
        "vas": sorted({str(value).upper() for value in vas}),
    }


def _setting_mismatch(owner: dict[str, Any], key: str, expected: str, *, allow_unspecified: bool = False) -> bool:
    actual = str(((owner.get("effective_flags") or {}).get("settings") or {}).get(key) or "")
    if expected == "unknown" or (allow_unspecified and actual == "unspecified"):
        return False
    return actual != expected


def _owner_row(
    record: dict[str, str],
    source_row: dict[str, str] | None,
    group: dict[str, object] | None,
    *,
    default_path: Path,
    root: Path,
    loader: Callable[[Path], str] | None,
    original_needs: dict[str, Any] | None,
) -> dict[str, Any]:
    va = str(record["va"]).upper()
    owner_path = preferred_source_path(record)
    if group is not None:
        owner_map = group.get("owners") or {}
        configured_path = owner_map.get(va) if isinstance(owner_map, dict) else None
        if configured_path:
            owner_path = _resolve(configured_path, root)
    expected_language = _expected_language(source_row, owner_path)
    individual_path = root / "config" / "flags" / f"{record.get('slug') or function_slug(record)}.rsp"
    individual_flags, individual_custom = _read_flags(
        individual_path,
        default_path=default_path,
        input_language=(expected_language if expected_language != "unknown" else _language_from_suffix(owner_path)),
        root=root,
        loader=loader,
    )

    configured_path: Path | None = None
    configured_flags: dict[str, Any] | None = None
    group_name = ""
    wrapper_language = "unknown"
    if group is not None:
        group_name = str(group.get("name") or "")
        configured_path = _resolve(group.get("flags") or default_path, root)
        wrapper_language = _owner_language_from_group(group, root)
        configured_flags, _ = _read_flags(
            configured_path,
            default_path=default_path,
            input_language=wrapper_language,
            root=root,
            loader=loader,
        )
    effective_flags = configured_flags or individual_flags
    needs = original_needs or {"eh": None, "frame_pointer": None, "frame_size": None, "evidence": {}}
    source_module = _module_name(source_row)
    source_module_key = _module_key(source_row)
    stale_exception = bool(
        group is not None
        and individual_custom
        and configured_flags is not None
        and not _flag_equal(individual_flags, configured_flags)
    )
    return {
        "va": va,
        "name": str(record.get("name") or ""),
        "owner_path": _display(owner_path, root),
        "group": group_name,
        "pdb_module": source_module,
        "pdb_module_key": source_module_key,
        "pdb_source_path": _portable((source_row or {}).get("primary_source_path")),
        "expected_language": expected_language,
        "wrapper_language": wrapper_language,
        "individual_flags": individual_flags,
        "individual_flags_custom": individual_custom,
        "configured_tu_flags": configured_flags,
        "effective_flags": effective_flags,
        "configured_flags_path": "" if configured_path is None else _display(configured_path, root),
        "stale_per_function_exception": stale_exception,
        "original_needs": needs,
    }


def _module_summary(
    module_key: str,
    module_name: str,
    owners: list[dict[str, Any]],
    *,
    kind: str,
    current_group_names: list[str] = [],
) -> tuple[dict[str, Any], list[dict[str, Any]]]:
    issues: list[dict[str, Any]] = []
    individual_groups: dict[tuple[str, ...], list[dict[str, Any]]] = defaultdict(list)
    for owner in owners:
        signature = tuple(owner["individual_flags"].get("signature") or ())
        individual_groups[signature].append(owner)
    effective_groups: dict[tuple[str, ...], list[dict[str, Any]]] = defaultdict(list)
    for owner in owners:
        signature = tuple(owner["effective_flags"].get("signature") or ())
        effective_groups[signature].append(owner)

    languages = sorted({owner["expected_language"] for owner in owners if owner["expected_language"] != "unknown"})
    frame_needs = sorted({owner["original_needs"].get("frame_pointer") for owner in owners if owner["original_needs"].get("frame_pointer") is not None})
    eh_needs = sorted({owner["original_needs"].get("eh") for owner in owners if owner["original_needs"].get("eh") is not None})
    if len(individual_groups) > 1:
        issues.append(
            _issue(
                "incompatible_custom_overlay",
                "error",
                f"{kind}:{module_name}",
                f"{module_name} has {len(individual_groups)} distinct per-function flag sets; one module flag set is not proved.",
                vas=[owner["va"] for owner in owners],
            )
        )
    if len(languages) > 1:
        issues.append(
            _issue(
                "mixed_language",
                "error",
                f"{kind}:{module_name}",
                f"{module_name} has mixed PDB language evidence: {', '.join(languages)}.",
                vas=[owner["va"] for owner in owners],
            )
        )
    if len(frame_needs) > 1:
        issues.append(
            _issue(
                "mixed_frame_need",
                "warning",
                f"{kind}:{module_name}",
                f"{module_name} has both frame-pointer and FPO original prologues; verify one grouped flag set.",
                vas=[owner["va"] for owner in owners],
            )
        )
    if kind == "current" and len(current_group_names) > 1:
        issues.append(
            _issue(
                "mixed_current_translation_units",
                "error",
                f"{kind}:{module_name}",
                f"{module_name} is split across configured translation units: {', '.join(current_group_names)}.",
                vas=[owner["va"] for owner in owners],
            )
        )

    for owner in owners:
        expected_language = owner["expected_language"]
        actual_language = str(owner["effective_flags"]["settings"].get("language") or "")
        if expected_language != "unknown" and actual_language != expected_language:
            issues.append(
                _issue(
                    "language_mismatch",
                    "error",
                    f"{kind}:{module_name}",
                    f"owner {owner['va']} expects {expected_language} from PDB/source evidence but its effective flags are {actual_language}.",
                    vas=[owner["va"]],
                )
            )

    summary = {
        "kind": kind,
        "module": module_name,
        "module_key": module_key,
        "owner_count": len(owners),
        "owners": sorted(owners, key=lambda owner: int(owner["va"], 16)),
        "individual_flag_set_count": len(individual_groups),
        "effective_flag_set_count": len(effective_groups),
        "individual_flag_sets": [
            {
                "signature": list(signature),
                "owners": [owner["va"] for owner in sorted(rows, key=lambda row: int(row["va"], 16))],
            }
            for signature, rows in sorted(individual_groups.items(), key=lambda item: item[0])
        ],
        "pdb_languages": languages,
        "original_eh_needs": eh_needs,
        "original_frame_pointer_needs": frame_needs,
        "current_groups": current_group_names,
        "issues": issues,
    }
    return summary, issues


def audit_translation_units(
    *,
    groups: Iterable[dict[str, object]] | None = None,
    records: Iterable[dict[str, str]] | None = None,
    source_map: dict[str, dict[str, str]] | None = None,
    original_needs: dict[str, dict[str, Any]] | None = None,
    root: Path = REPO_ROOT,
    flag_loader: Callable[[Path], str] | None = None,
) -> dict[str, Any]:
    """Build a stable audit report from configured groups and owner evidence."""
    configured_groups = list(load_translation_units() if groups is None else groups)
    configured_records = list(load_functions() if records is None else records)
    source_rows_raw = load_pdb_function_source_map() if source_map is None else source_map
    source_rows = {str(key).upper(): value for key, value in source_rows_raw.items()}
    root = root.resolve()
    default_path = _resolve("config/flags/default.rsp", root)
    group_by_va, duplicate_groups = _current_group_maps(configured_groups)
    if original_needs is None:
        original_needs = load_original_needs(configured_records)
    needs_by_va = {str(key).upper(): value for key, value in original_needs.items()}

    proposed_owners: dict[str, list[dict[str, Any]]] = defaultdict(list)
    current_rows: dict[str, list[dict[str, Any]]] = defaultdict(list)
    included_vas: set[str] = set()
    for record in configured_records:
        va = str(record.get("va") or "").upper()
        source_row = source_rows.get(va)
        bucket, _ = classify_corpus_bucket(record)
        if va not in group_by_va and (not _module_key(source_row) or bucket != "normal"):
            continue
        owner = _owner_row(
            record,
            source_row,
            group_by_va.get(va),
            default_path=default_path,
            root=root,
            loader=flag_loader,
            original_needs=needs_by_va.get(va),
        )
        included_vas.add(va)
        if owner["group"]:
            current_rows[owner["group"]].append(owner)
        if owner["pdb_module_key"]:
            proposed_owners[owner["pdb_module_key"]].append(owner)

    issues: list[dict[str, Any]] = []
    current_units: list[dict[str, Any]] = []
    for group in configured_groups:
        name = str(group.get("name") or "")
        owners = current_rows.get(name, [])
        modules = sorted({owner["pdb_module"] for owner in owners if owner["pdb_module"]})
        languages = sorted(
            {owner["expected_language"] for owner in owners if owner["expected_language"] != "unknown"}
        )
        frame_needs = sorted(
            {
                owner["original_needs"].get("frame_pointer")
                for owner in owners
                if owner["original_needs"].get("frame_pointer") is not None
            }
        )
        eh_needs = sorted(
            {
                owner["original_needs"].get("eh")
                for owner in owners
                if owner["original_needs"].get("eh") is not None
            }
        )
        unit_issues: list[dict[str, Any]] = []
        if len(modules) > 1:
            unit_issues.append(
                _issue(
                    "mixed_pdb_module",
                    "error",
                    f"current:{name}",
                    f"configured translation unit has multiple PDB modules: {', '.join(modules)}.",
                    vas=[owner["va"] for owner in owners],
                )
            )
        if len(languages) > 1:
            unit_issues.append(
                _issue(
                    "mixed_language",
                    "error",
                    f"current:{name}",
                    f"configured translation unit has mixed PDB language evidence: {', '.join(languages)}.",
                    vas=[owner["va"] for owner in owners],
                )
            )
        if len(frame_needs) > 1:
            unit_issues.append(
                _issue(
                    "mixed_frame_need",
                    "warning",
                    f"current:{name}",
                    "configured translation unit has both frame-pointer and FPO original prologues; grouped output is authoritative.",
                    vas=[owner["va"] for owner in owners],
                )
            )
        for owner in owners:
            if owner["stale_per_function_exception"]:
                unit_issues.append(
                    _issue(
                        "stale_per_function_exception",
                        "error",
                        f"current:{name}",
                        f"owner {owner['va']} has custom flags {owner['individual_flags']['path']} that differ from the configured TU flags.",
                        vas=[owner["va"]],
                    )
                )
            expected_language = owner["expected_language"]
            if _setting_mismatch(owner, "language", expected_language):
                unit_issues.append(
                    _issue(
                        "language_mismatch",
                        "error",
                        f"current:{name}",
                        f"owner {owner['va']} expects {expected_language} from PDB/source evidence but the TU is {owner['effective_flags']['settings']['language']}.",
                        vas=[owner["va"]],
                    )
                )
            if owner["original_needs"].get("eh") is True and owner["effective_flags"]["settings"].get("eh") != "enabled":
                unit_issues.append(
                    _issue(
                        "eh_flag_missing",
                        "error",
                        f"current:{name}",
                        f"owner {owner['va']} has original EH setup but the TU does not enable /GX.",
                        vas=[owner["va"]],
                    )
                )
            if owner["original_needs"].get("frame_pointer") is True and owner["effective_flags"]["settings"].get("frame") == "omit":
                unit_issues.append(
                    _issue(
                        "frame_flag_conflict",
                        "warning",
                        f"current:{name}",
                        f"owner {owner['va']} has an original EBP frame while the TU requests /Oy; the compiler can retain EBP when required.",
                        vas=[owner["va"]],
                    )
                )
        flags_value = _portable(group.get("flags")) or _display(default_path, root)
        if len(owners) > 1 and _VA_STEM_RE.match(Path(flags_value).stem):
            unit_issues.append(
                _issue(
                    "target_named_tu_flags",
                    "warning",
                    f"current:{name}",
                    f"group flags {flags_value} are named after one target and can hide owner-specific exceptions.",
                    vas=[owner["va"] for owner in owners],
                )
            )
        issues.extend(unit_issues)
        current_units.append(
            {
                "name": name,
                "source": _portable(group.get("source")),
                "flags": flags_value,
                "owner_count": len(owners),
                "pdb_modules": modules,
                "pdb_languages": languages,
                "original_eh_needs": eh_needs,
                "original_frame_pointer_needs": frame_needs,
                "owners": sorted(owners, key=lambda owner: int(owner["va"], 16)),
                "issues": unit_issues,
            }
        )

    proposed_units: list[dict[str, Any]] = []
    for module_key, owners in sorted(proposed_owners.items(), key=lambda item: (_module_name(source_rows.get(item[1][0]["va"])), item[0])):
        module_name = owners[0]["pdb_module"] or module_key
        current_names = sorted({owner["group"] for owner in owners if owner["group"]})
        summary, module_issues = _module_summary(
            module_key,
            module_name,
            owners,
            kind="proposed",
            current_group_names=current_names,
        )
        issues.extend(module_issues)
        proposed_units.append(summary)

    for va, names in sorted(duplicate_groups.items()):
        issues.append(
            _issue(
                "duplicate_current_owner",
                "error",
                "manifest",
                f"owner {va} is assigned to multiple translation units: {', '.join(sorted(set(names)))}.",
                vas=[va],
            )
        )

    counts = Counter(issue["code"] for issue in issues)
    migration_plan = [
        {
            "step": 1,
            "action": "Freeze evidence",
            "detail": "Use the PDB module path, original EXE EH setup, original prologue, and wrapper language as the owner evidence.",
        },
        {
            "step": 2,
            "action": "Replace target-named TU flags",
            "detail": "Give each source-module group one reviewed module-level response file. Copy no per-function overlay without evidence.",
        },
        {
            "step": 3,
            "action": "Resolve stale exceptions",
            "detail": "For each stale per-function response file, either prove the flag is module-wide or keep the owner out of that grouped TU.",
        },
        {
            "step": 4,
            "action": "Split incompatible modules",
            "detail": "Split C/C++ language, EH, or EBP/FPO basins before testing source-shape changes.",
        },
        {
            "step": 5,
            "action": "Revalidate anchors",
            "detail": "Rebuild all owners together and run check_function.py for every exact claim after each flag migration.",
        },
    ]
    return {
        "schema_version": SCHEMA_VERSION,
        "evidence": {
            "pdb": "inventory/pdb/function_source_map.csv",
            "original_image": "config/binaries.json -> original_exe",
            "original_layout": "config/binaries.json -> ghidra_layout",
            "configured_translation_units": "config/translation_units.json",
            "response_files": "config/flags/*.rsp",
        },
        "summary": {
            "owner_count": len(included_vas),
            "current_translation_unit_count": len(current_units),
            "proposed_module_count": len(proposed_units),
            "issue_count": len(issues),
            "issue_counts": dict(sorted(counts.items())),
            "blocking_issue_count": sum(
                1
                for issue in issues
                if issue["severity"] == "error"
                and not str(issue.get("scope") or "").startswith("proposed:")
            ),
        },
        "current_translation_units": current_units,
        "proposed_translation_units": proposed_units,
        "issues": issues,
        "migration_plan": migration_plan,
    }


def write_report(report: dict[str, Any], output: Path, *, root: Path = REPO_ROOT) -> None:
    output = output.resolve()
    build_root = (root / "build").resolve()
    if build_root not in output.parents and output != build_root:
        raise ValueError(f"generated output must stay under {build_root}")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Audit grouped and proposed translation-unit compiler flags against PDB and original-code evidence."
    )
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT, help="JSON report path under build/.")
    parser.add_argument("--no-original-needs", action="store_true", help="Skip original EXE EH/frame extraction.")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    needs = None
    records = load_functions()
    if args.no_original_needs:
        needs = {str(record["va"]).upper(): {"eh": None, "frame_pointer": None, "frame_size": None, "evidence": {}} for record in records}
    report = audit_translation_units(original_needs=needs, records=records)
    write_report(report, args.output)
    print(json.dumps(report["summary"], sort_keys=True))
    print(f"Wrote {args.output}")
    return 1 if report["summary"]["blocking_issue_count"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
