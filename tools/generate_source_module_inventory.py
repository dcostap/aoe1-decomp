"""Build a deterministic inventory of the recovered source-module groups.

The translation-unit manifest records the compiler-facing wrapper and owner
paths.  The preserved PDB records the original source module, source lines,
and decorated ownership.  This tool joins those two evidence sets with the
live status rows.  It does not invent an owner or claim an exact anchor when
the owner has no current diff artifact.
"""

from __future__ import annotations

import argparse
import csv
import json
from pathlib import Path
from typing import Any, Iterable

from build_cache import build_input_manifest, load_build_manifest
from common import (
    BUILD_DIR,
    REPO_ROOT,
    load_pdb_function_line_changes,
    load_pdb_function_source_map,
    load_toolchain,
    slugify_name,
    source_module_for_name,
    validate_auxiliary_contributions,
    validate_source_modules,
    load_translation_units,
)
from status_core import build_status_rows
from function_diagnostics import owning_function_symbol_validation
from validate_translation_units import validate_translation_units


SCHEMA_VERSION = 1
DEFAULT_JSON_PATH = BUILD_DIR / "source_module_inventory.json"
DEFAULT_CSV_PATH = BUILD_DIR / "source_module_inventory.csv"


def _as_int(value: object) -> int | None:
    if value in (None, ""):
        return None
    try:
        return int(str(value), 10)
    except (TypeError, ValueError):
        return None


def _portable(value: object) -> str:
    return str(value or "").replace("\\", "/").strip()


def _source_file(row: dict[str, str] | None) -> str:
    if not row:
        return ""
    primary = str(row.get("primary_source_file") or "").strip()
    if primary:
        return primary
    direct = str(row.get("direct_source_path") or "").strip()
    if direct:
        return direct.replace("\\", "/").rsplit("/", 1)[-1]
    return ""


def _class_owner(symbol_name: str) -> str:
    if "::" not in symbol_name:
        return ""
    return symbol_name.rsplit("::", 1)[0].strip()


def _line_data(
    va: str,
    source_row: dict[str, str] | None,
    line_rows: dict[str, list[dict[str, str]]],
) -> dict[str, Any]:
    changes = line_rows.get(va.upper(), [])
    source_lines: list[int] = []
    for change in changes:
        line = _as_int(change.get("line_number"))
        if line is not None and (not source_lines or source_lines[-1] != line):
            source_lines.append(line)

    line_start = _as_int(source_row.get("line_start")) if source_row else None
    line_end = _as_int(source_row.get("line_end")) if source_row else None
    if source_lines:
        # The first PDB line change is the most direct address-to-line anchor.
        line_start = source_lines[0]
        line_end = source_lines[-1]

    return {
        "source_line": line_start,
        "source_line_end": line_end,
        "source_line_sequence": source_lines,
        "pdb_line_record_count": _as_int(source_row.get("line_record_count")) if source_row else None,
        "pdb_line_change_count": _as_int(source_row.get("line_change_count")) if source_row else len(changes),
    }


def _exact_fields(
    row: dict[str, str] | None,
    *,
    expected_va: str,
    diff_path: Path,
    expected_source: Path,
    input_paths: Iterable[Path],
    expected_pdb_symbol: str,
    expected_build_fingerprint: str | None = None,
) -> tuple[str, bool, str]:
    """Return status, anchor state, and the evidence source.

    ``status_core`` uses the matching source bank as a compact default when a
    diff file is absent.  That default is useful for status views, but it is
    not an exact anchor for this evidence inventory.  Require the generated
    diff artifact before setting ``exact_anchor``.
    """

    raw_status = str((row or {}).get("diff_result") or "").strip().upper()
    if not raw_status:
        return "UNVALIDATED", False, ""

    freshness = _diff_freshness(
        diff_path,
        expected_source=expected_source,
        input_paths=input_paths,
        expected_build_fingerprint=expected_build_fingerprint,
    )
    if not freshness[0]:
        return "UNVALIDATED", False, freshness[1]

    try:
        diff_payload = json.loads(diff_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return "UNVALIDATED", False, "invalid-diff-artifact"
    if str(diff_payload.get("va") or "").strip().upper() != expected_va.upper():
        return "UNVALIDATED", False, "stale-va-artifact"
    rebuilt_extraction = diff_payload.get("rebuilt_extraction")
    rebuilt_symbol_data = rebuilt_extraction.get("symbol") if isinstance(rebuilt_extraction, dict) else None
    rebuilt_symbol = str(
        (rebuilt_symbol_data.get("name") if isinstance(rebuilt_symbol_data, dict) else "") or ""
    ).strip()
    expected_name = str((row or {}).get("name") or "").strip()
    owner_validation = owning_function_symbol_validation(
        expected_name,
        rebuilt_symbol,
        expected_pdb_symbol,
    )
    if owner_validation["status"] != "match":
        status = "MISMATCH" if owner_validation["status"] == "mismatch" else "UNVALIDATED"
        return status, False, "pdb-owner-mismatch"

    diff_bytes = str((row or {}).get("positional_diff_bytes") or "").strip()
    if raw_status == "MATCH" and not diff_bytes:
        return "UNVALIDATED", False, "live-status-row"
    has_zero_diff = diff_bytes in {"0", "0.0"}
    if raw_status == "MATCH" and has_zero_diff:
        status = "MATCH"
    elif raw_status == "MATCH":
        status = "MISMATCH"
    else:
        status = raw_status

    evidence = _portable(diff_path.relative_to(REPO_ROOT))
    return status, bool(status == "MATCH"), evidence


def _diff_freshness(
    diff_path: Path,
    *,
    expected_source: Path,
    input_paths: Iterable[Path],
    expected_build_fingerprint: str | None = None,
) -> tuple[bool, str]:
    """Check that a diff artifact represents the current grouped source.

    A diff JSON can remain after a function was compiled in isolation.  The
    rebuilt source-map path and input mtimes prevent that artifact from being
    reported as a grouped exact result.
    """

    if not diff_path.is_file():
        return False, "missing-diff-artifact"
    try:
        payload = json.loads(diff_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return False, "invalid-diff-artifact"

    rebuilt_source_map = payload.get("rebuilt_source_map")
    rebuilt_source = str(
        (rebuilt_source_map.get("source") if isinstance(rebuilt_source_map, dict) else "") or ""
    ).strip()
    expected = expected_source.resolve()
    if not rebuilt_source:
        return False, "missing-source-context"
    rebuilt = Path(rebuilt_source.replace("\\", "/"))
    if not rebuilt.is_absolute():
        rebuilt = REPO_ROOT / rebuilt
    try:
        rebuilt = rebuilt.resolve()
    except OSError:
        pass
    if rebuilt != expected:
        return False, "stale-source-context"

    if expected_build_fingerprint is not None:
        rebuilt_extraction = payload.get("rebuilt_extraction")
        artifact_fingerprint = str(payload.get("build_input_fingerprint") or "").strip()
        if not artifact_fingerprint and isinstance(rebuilt_extraction, dict):
            artifact_fingerprint = str(
                rebuilt_extraction.get("build_input_fingerprint") or ""
            ).strip()
        if not artifact_fingerprint:
            return False, "missing-build-fingerprint"
        if artifact_fingerprint != expected_build_fingerprint:
            return False, "stale-build-inputs"

    try:
        artifact_mtime = diff_path.stat().st_mtime_ns
    except OSError:
        return False, "missing-diff-artifact"
    for path in input_paths:
        if not path.exists():
            continue
        try:
            if path.stat().st_mtime_ns > artifact_mtime:
                return False, "stale-source-input"
        except OSError:
            return False, "unreadable-source-input"
    return True, _portable(diff_path.relative_to(REPO_ROOT))


def _owner_context_flags(
    *,
    source_file: str,
    source_line: int | None,
    class_owner: str,
    exact_anchor: bool,
    custom_flags: bool,
) -> list[str]:
    flags: list[str] = []
    if source_file:
        flags.append("pdb_source_module")
    if source_line is not None:
        flags.append("source_line")
    if class_owner:
        flags.append("class_ownership")
    if exact_anchor:
        flags.append("exact_anchor")
    if custom_flags:
        flags.append("custom_flags")
    return flags


def _module_context(
    owners: list[dict[str, Any]],
    *,
    source_files: list[str],
    custom_flags: bool,
) -> dict[str, Any]:
    lines = [owner["source_line"] for owner in owners]
    known_lines = all(line is not None for line in lines)
    nondecreasing_lines = known_lines and all(
        lines[index] <= lines[index + 1] for index in range(len(lines) - 1)
    )
    known_classes = all(bool(owner["class_owner"]) for owner in owners)
    class_owners = sorted({owner["class_owner"] for owner in owners if owner["class_owner"]})
    exact_anchor_count = sum(1 for owner in owners if owner["exact_anchor"])
    source_module_known = bool(source_files) and len(source_files) == 1

    flags: list[str] = []
    if source_module_known:
        flags.append("pdb_source_module")
    if nondecreasing_lines:
        flags.append("source_line_order")
    if known_classes:
        flags.append("class_ownership")
    if len(owners) >= 2:
        flags.append("address_sequence")
    if exact_anchor_count:
        flags.append("exact_anchor")
    if custom_flags:
        flags.append("custom_flags")

    if known_lines:
        line_order = "known" if nondecreasing_lines else "conflict"
    else:
        line_order = "unknown"
    if not owners:
        class_ownership = "unknown"
    elif known_classes:
        class_ownership = "known"
    elif class_owners:
        class_ownership = "partial"
    else:
        class_ownership = "unknown"

    return {
        "flags": flags,
        "pdb_source_module_known": source_module_known,
        "source_line_order": line_order,
        "class_ownership": class_ownership,
        "class_owners": class_owners,
        "address_sequence_known": len(owners) >= 2,
        "exact_anchor_count": exact_anchor_count,
        "custom_flags": custom_flags,
    }


def _current_build_fingerprint(source: Path, flags: Path) -> str:
    """Return the current compiler-input fingerprint for one source module."""
    try:
        manifest = build_input_manifest(source, flags, load_toolchain())
    except (KeyError, OSError, ValueError):
        return ""
    return str(manifest.get("fingerprint") or "").strip()


def _strict_build_fingerprint(group_name: str, source: Path, flags: Path) -> str:
    """Return a fingerprint only when the current grouped build is present."""
    fingerprint = _current_build_fingerprint(source, flags)
    slug = f"tu_{slugify_name(group_name)}"
    if not fingerprint:
        return ""
    if not (BUILD_DIR / "obj" / f"{slug}.obj").is_file():
        return ""
    build_manifest = load_build_manifest(
        BUILD_DIR / "manifests" / f"build_{slug}.json"
    )
    if (
        not build_manifest
        or build_manifest.get("returncode") != 0
        or build_manifest.get("input_fingerprint") != fingerprint
    ):
        return ""
    return fingerprint


def build_source_module_inventory(
    groups: Iterable[dict[str, object]] | None = None,
    *,
    require_fresh_build: bool = False,
) -> dict[str, Any]:
    """Join the configured groups with PDB metadata and live status.

    The returned list keeps one entry per configured compiler-facing group.
    Owners are sorted by their original image address, not by source-file
    spelling or current source-bank placement.
    """

    configured_groups = list(load_translation_units() if groups is None else groups)
    manifest_issues = validate_translation_units(configured_groups)
    if manifest_issues:
        raise ValueError("; ".join(str(issue) for issue in manifest_issues))
    auxiliary_issues = validate_auxiliary_contributions()
    if auxiliary_issues:
        raise ValueError("; ".join(auxiliary_issues))
    source_map = load_pdb_function_source_map()
    line_changes = load_pdb_function_line_changes()
    all_vas: set[str] = set()
    for group in configured_groups:
        module_name = str(group.get("module") or "").strip()
        source_module = source_module_for_name(module_name) if module_name else None
        if source_module is not None:
            functions = source_module["functions"]
            assert isinstance(functions, dict)
            all_vas.update(str(va).upper() for va in functions)
        else:
            all_vas.update(str(va).upper() for va in (group.get("owners") or {}))
    status_rows = build_status_rows(
        include_source_preview=False,
        include_source_notes=False,
        include_diff_metrics=True,
        include_comment_lines=False,
        include_vas=all_vas,
    )
    status_by_va = {str(row["va"]).upper(): row for row in status_rows}

    modules: list[dict[str, Any]] = []
    for group in configured_groups:
        group_name = str(group.get("name") or "").strip()
        wrapper_source = _portable(group.get("source"))
        raw_flags = _portable(group.get("flags")) or "config/flags/default.rsp"
        custom_flags = raw_flags != "config/flags/default.rsp"
        raw_owners = group.get("owners") or {}
        if not isinstance(raw_owners, dict):
            raise ValueError(f"translation-unit group {group_name!r} has no owner map")
        module_name = str(group.get("module") or "").strip()
        source_module = source_module_for_name(module_name) if module_name else None
        registered_vas = {str(va).upper() for va in raw_owners}
        if source_module is not None:
            functions = source_module["functions"]
            assert isinstance(functions, dict)
            owner_paths = {
                str(va).upper(): str(source_module["source"])
                for va in functions
            }
        else:
            owner_paths = {str(va).upper(): value for va, value in raw_owners.items()}
        ordered_vas = sorted(owner_paths, key=lambda value: int(value, 16))
        wrapper_path = REPO_ROOT / wrapper_source
        input_paths = [wrapper_path]
        input_paths.extend(REPO_ROOT / _portable(owner_paths[va]) for va in ordered_vas)
        if source_module is not None and str(source_module.get("header") or ""):
            input_paths.append(REPO_ROOT / _portable(source_module["header"]))
        flags_path = REPO_ROOT / raw_flags
        input_paths.append(flags_path)
        build_fingerprint: str | None = None
        has_diff_artifact = any(
            (
                BUILD_DIR
                / "diff"
                / f"{str((status_by_va.get(va) or {}).get('slug') or Path(_portable(owner_paths[va])).stem)}.json"
            ).is_file()
            for va in ordered_vas
        )
        if require_fresh_build and has_diff_artifact:
            # Strict inventories may use an exact anchor only when its diff
            # carries the fingerprint for the current grouped compiler input.
            # A missing fingerprint is stale evidence, not a reason to trust it.
            build_fingerprint = _strict_build_fingerprint(
                group_name, wrapper_path, flags_path
            )
        owners: list[dict[str, Any]] = []
        for index, va in enumerate(ordered_vas, start=1):
            source_row = source_map.get(va)
            line_data = _line_data(va, source_row, line_changes)
            source_file = _source_file(source_row)
            symbol_name = str((source_row or {}).get("symbol_name") or "").strip()
            class_owner = _class_owner(symbol_name)
            status_row = status_by_va.get(va)
            slug = str((status_row or {}).get("slug") or "").strip()
            if not slug:
                owner_path = _portable(owner_paths[va])
                slug = Path(owner_path).stem
            diff_path = BUILD_DIR / "diff" / f"{slug}.json"
            exact_status, exact_anchor, exact_evidence = _exact_fields(
                status_row,
                expected_va=va,
                diff_path=diff_path,
                expected_source=wrapper_path,
                input_paths=input_paths,
                expected_pdb_symbol=symbol_name,
                expected_build_fingerprint=build_fingerprint,
            )
            owner = {
                "address_order": index,
                "va": va,
                "owner_path": _portable(owner_paths[va]),
                "registered_owner": va in registered_vas,
                "recovery_note_path": (
                    str((functions.get(va) or {}).get("note_path") or "")
                    if source_module is not None
                    else ""
                ),
                "name": str((status_row or {}).get("name") or "").strip(),
                "symbol_name": symbol_name,
                "class_owner": class_owner,
                "pdb_source_file": source_file,
                "pdb_source_path": str((source_row or {}).get("primary_source_path") or "").strip(),
                **line_data,
                "bank": str((status_row or {}).get("source_bucket") or "unknown"),
                "corpus_bucket": str((status_row or {}).get("corpus_bucket") or "unknown"),
                "exact_status": exact_status,
                "exact_anchor": exact_anchor,
                "exact_evidence": exact_evidence,
                "uses_custom_flags": custom_flags,
                "context_flags": _owner_context_flags(
                    source_file=source_file,
                    source_line=line_data["source_line"],
                    class_owner=class_owner,
                    exact_anchor=exact_anchor,
                    custom_flags=custom_flags,
                ),
            }
            owners.append(owner)

        source_files = sorted({owner["pdb_source_file"] for owner in owners if owner["pdb_source_file"]})
        pdb_module_name = source_files[0] if len(source_files) == 1 else ""
        context = _module_context(owners, source_files=source_files, custom_flags=custom_flags)
        modules.append(
            {
                "name": group_name,
                "module_name": pdb_module_name or group_name,
                "module_name_source": "pdb_source_file" if pdb_module_name else "translation_unit_name",
                "pdb_source_files": source_files,
                "translation_unit_source": wrapper_source,
                "flags": raw_flags,
                "uses_custom_flags": custom_flags,
                "owner_count": len(owners),
                "registered_owner_count": sum(owner["registered_owner"] for owner in owners),
                # Count only anchors backed by a generated diff artifact.  A
                # matching-bank row without that artifact remains unvalidated.
                "exact_owner_count": sum(1 for owner in owners if owner["exact_anchor"]),
                "owners": owners,
                "context": context,
            }
        )

    return {
        "schema_version": SCHEMA_VERSION,
        "translation_unit_count": len(modules),
        "owner_count": sum(module["owner_count"] for module in modules),
        "registered_owner_count": sum(module["registered_owner_count"] for module in modules),
        "modules": modules,
    }


CSV_FIELDS = [
    "name",
    "module_name",
    "module_name_source",
    "pdb_source_files",
    "translation_unit_source",
    "flags",
    "uses_custom_flags",
    "owner_count",
    "registered_owner_count",
    "exact_owner_count",
    "address_order",
    "va",
    "owner_path",
    "registered_owner",
    "recovery_note_path",
    "owner_name",
    "symbol_name",
    "class_owner",
    "pdb_source_file",
    "pdb_source_path",
    "source_line",
    "source_line_end",
    "bank",
    "corpus_bucket",
    "exact_status",
    "exact_anchor",
    "exact_evidence",
    "context_flags",
]


def _csv_rows(inventory: dict[str, Any]) -> Iterable[dict[str, str]]:
    for module in inventory["modules"]:
        for owner in module["owners"]:
            yield {
                "name": str(module["name"]),
                "module_name": str(module["module_name"]),
                "module_name_source": str(module["module_name_source"]),
                "pdb_source_files": ";".join(module["pdb_source_files"]),
                "translation_unit_source": str(module["translation_unit_source"]),
                "flags": str(module["flags"]),
                "uses_custom_flags": str(module["uses_custom_flags"]).lower(),
                "owner_count": str(module["owner_count"]),
                "registered_owner_count": str(module["registered_owner_count"]),
                "exact_owner_count": str(module["exact_owner_count"]),
                "address_order": str(owner["address_order"]),
                "va": str(owner["va"]),
                "owner_path": str(owner["owner_path"]),
                "registered_owner": str(owner["registered_owner"]).lower(),
                "recovery_note_path": str(owner["recovery_note_path"]),
                "owner_name": str(owner["name"]),
                "symbol_name": str(owner["symbol_name"]),
                "class_owner": str(owner["class_owner"]),
                "pdb_source_file": str(owner["pdb_source_file"]),
                "pdb_source_path": str(owner["pdb_source_path"]),
                "source_line": "" if owner["source_line"] is None else str(owner["source_line"]),
                "source_line_end": "" if owner["source_line_end"] is None else str(owner["source_line_end"]),
                "bank": str(owner["bank"]),
                "corpus_bucket": str(owner["corpus_bucket"]),
                "exact_status": str(owner["exact_status"]),
                "exact_anchor": str(owner["exact_anchor"]).lower(),
                "exact_evidence": str(owner["exact_evidence"]),
                "context_flags": ";".join(owner["context_flags"]),
            }


def write_inventory(inventory: dict[str, Any], output_path: Path, output_format: str) -> None:
    output_path = output_path.resolve()
    build_root = BUILD_DIR.resolve()
    if build_root not in output_path.parents:
        raise ValueError(f"generated output must stay under {build_root}")
    output_path.parent.mkdir(parents=True, exist_ok=True)
    if output_format == "json":
        output_path.write_text(
            json.dumps(inventory, indent=2, sort_keys=True) + "\n",
            encoding="utf-8",
            newline="\n",
        )
        return
    with output_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=CSV_FIELDS)
        writer.writeheader()
        writer.writerows(_csv_rows(inventory))


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate PDB-backed source-module and translation-unit context inventory."
    )
    parser.add_argument("--format", choices=("json", "csv"), default="json")
    parser.add_argument("--output", type=Path, help="Generated output path under build/.")
    parser.add_argument(
        "--strict",
        action="store_true",
        help="Fail when an owner lacks PDB source metadata or a group has mixed PDB modules.",
    )
    return parser.parse_args()


def _validate_strict(inventory: dict[str, Any]) -> None:
    source_module_issues = validate_source_modules()
    if source_module_issues:
        raise ValueError("; ".join(source_module_issues))
    for module in inventory["modules"]:
        if len(module["pdb_source_files"]) != 1:
            raise ValueError(f"{module['name']}: PDB source module is missing or mixed")
        for owner in module["owners"]:
            if not owner["pdb_source_file"] or owner["source_line"] is None:
                raise ValueError(f"{module['name']} {owner['va']}: incomplete PDB source metadata")


def main() -> None:
    args = parse_args()
    inventory = build_source_module_inventory(require_fresh_build=args.strict)
    if args.strict:
        _validate_strict(inventory)
    output = args.output or (DEFAULT_JSON_PATH if args.format == "json" else DEFAULT_CSV_PATH)
    write_inventory(inventory, output, args.format)
    print(
        f"Wrote {output}\n"
        f"Translation units: {inventory['translation_unit_count']}\n"
        f"Owners: {inventory['owner_count']}\n"
        f"Registered owners: {inventory['registered_owner_count']}"
    )


if __name__ == "__main__":
    main()
