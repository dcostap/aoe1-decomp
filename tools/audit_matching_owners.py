from __future__ import annotations

import argparse
import json
from collections import Counter
from pathlib import Path
from typing import Any

from build_cache import build_input_manifest, build_manifest_matches
from common import (
    BUILD_DIR,
    REPO_ROOT,
    classify_corpus_bucket,
    compiler_artifact_slug,
    compiler_source_path,
    function_slug,
    load_functions,
    load_pdb_function_source_map,
    load_function_modules,
    load_toolchain,
    preferred_flags_rsp_path,
    preferred_source_path,
    matching_build_for_va,
)
from function_diagnostics import owning_function_symbol_validation


def owner_mismatch_kind(validation: dict[str, str]) -> str:
    """Classify an owner mismatch without treating it as byte equivalence."""
    if validation.get("expected_owner") != validation.get("rebuilt_owner"):
        expected = validation.get("expected_owner", "")
        rebuilt = validation.get("rebuilt_owner", "")
        if expected and not rebuilt:
            return "free_function_owner"
        if not expected and rebuilt:
            return "unexpected_class_owner"
        return "class_owner"
    return "method_or_kind"


def audit_status(
    *,
    metadata_state: str,
    diff_state: str,
    owner_status: str,
    pdb_owner: str,
    checker_status: str,
) -> str:
    """Return the conservative audit status for one function.

    A byte MATCH is valid only when current metadata exists and the PDB owner
    check is valid. Missing or stale evidence never becomes an exact claim.
    """
    stale_suffix = "_STALE"
    if metadata_state == "missing":
        return "MISSING_METADATA"
    if not pdb_owner:
        return "PDB_OWNER_MISSING" if metadata_state == "fresh" else "PDB_OWNER_MISSING" + stale_suffix
    if owner_status == "mismatch":
        return "OWNER_MISMATCH" if metadata_state == "fresh" else "OWNER_MISMATCH" + stale_suffix
    if owner_status != "match":
        return "OWNER_UNVERIFIED" if metadata_state == "fresh" else "OWNER_UNVERIFIED" + stale_suffix
    if metadata_state != "fresh":
        return "MISSING_METADATA" if metadata_state == "missing" else "STALE_METADATA"
    if diff_state != "fresh":
        return "OWNER_MATCH_NO_DIFF"
    return "MATCH" if checker_status == "MATCH" else "MISMATCH"


def _repair_reason(status: str, mismatch_kind: str) -> str:
    if status == "DUPLICATE_SOURCE_OWNER":
        return "keep one compiler-facing source owner"
    if status in {"OWNER_MISMATCH", "OWNER_MISMATCH_STALE"}:
        if mismatch_kind in {"class_owner", "free_function_owner", "unexpected_class_owner"}:
            return "repair class/free-function owner"
        return "repair method or function kind"
    if status in {"PDB_OWNER_MISSING", "PDB_OWNER_MISSING_STALE"}:
        return "restore or verify PDB owner evidence"
    if status in {"OWNER_UNVERIFIED", "OWNER_UNVERIFIED_STALE"}:
        return "verify special or overloaded owner identity"
    if status in {"STALE_METADATA", "MISSING_METADATA"}:
        return "rebuild metadata"
    if status == "OWNER_MATCH_NO_DIFF":
        return "run the current function checker"
    if status == "MISMATCH":
        return "continue byte matching"
    return ""


def _metadata_paths(record: dict[str, str]) -> tuple[Path, Path, Path, Path]:
    slug = function_slug(record)
    artifact_slug = compiler_artifact_slug(record)
    asm_dir = BUILD_DIR / "asm"
    return (
        asm_dir / f"rebuilt_{slug}.json",
        BUILD_DIR / "diff" / f"{slug}.json",
        BUILD_DIR / "obj" / f"{artifact_slug}.obj",
        BUILD_DIR / "manifests" / f"build_{artifact_slug}.json",
    )


def _build_state(
    record: dict[str, str],
    toolchain: dict[str, Any],
    cache: dict[tuple[str, str], tuple[bool, Path]],
) -> tuple[bool, Path]:
    source = compiler_source_path(record)
    rsp = preferred_flags_rsp_path(record, toolchain)
    key = (str(source.resolve()), str(rsp.resolve()))
    if key not in cache:
        artifact_slug = compiler_artifact_slug(record)
        object_path = BUILD_DIR / "obj" / f"{artifact_slug}.obj"
        manifest_path = BUILD_DIR / "manifests" / f"build_{artifact_slug}.json"
        try:
            fingerprint = str(build_input_manifest(source, rsp, toolchain)["fingerprint"])
            current = build_manifest_matches(manifest_path, fingerprint, object_path)
        except (OSError, KeyError, TypeError, ValueError):
            current = False
        cache[key] = (current, object_path)
    return cache[key]


def _read_json(path: Path) -> dict[str, Any] | None:
    if not path.is_file():
        return None
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return None
    return value if isinstance(value, dict) else None


def _relative(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(REPO_ROOT.resolve())).replace("\\", "/")
    except ValueError:
        return str(path).replace("\\", "/")


def collect_audit_rows(repo_root: Path = REPO_ROOT) -> list[dict[str, Any]]:
    records = {int(row["va"], 16): row for row in load_functions()}
    pdb_rows = load_pdb_function_source_map()
    toolchain = load_toolchain()
    build_cache: dict[tuple[str, str], tuple[bool, Path]] = {}
    rows: list[dict[str, Any]] = []

    normal_sources: list[tuple[str, int, dict[str, str]]] = []
    for module in load_function_modules():
        source_path = str(module["source"]).replace("\\", "/")
        functions = module["functions"]
        assert isinstance(functions, dict)
        for va_text, entry in functions.items():
            if str(entry.get("status") or "") != "matching":
                continue
            va = int(str(va_text), 16)
            record = records.get(va)
            if record is None:
                raise ValueError(f"{source_path}: no inventory record for {va:08X}")
            bucket, _ = classify_corpus_bucket(record)
            if bucket != "normal":
                continue
            normal_sources.append((source_path, va, record))

    source_paths_by_va: dict[int, list[str]] = {}
    for source_path, va, _ in normal_sources:
        source_paths_by_va.setdefault(va, []).append(source_path)

    for source_path, va, record in normal_sources:
        bucket, _ = classify_corpus_bucket(record)

        metadata_path, diff_path, object_path, manifest_path = _metadata_paths(record)
        metadata = _read_json(metadata_path)
        pdb_row = pdb_rows.get(f"{va:08X}", {})
        pdb_owner = str(pdb_row.get("symbol_name") or "").strip()
        symbol = (metadata or {}).get("symbol")
        rebuilt_symbol = str(symbol.get("name") or "").strip() if isinstance(symbol, dict) else ""
        validation = owning_function_symbol_validation(record["name"], rebuilt_symbol, pdb_owner)

        if metadata is None:
            metadata_state = "missing"
        else:
            build_current, current_object = _build_state(record, toolchain, build_cache)
            metadata_current = (
                build_current
                and current_object.is_file()
                and metadata_path.stat().st_mtime_ns >= current_object.stat().st_mtime_ns
            )
            metadata_state = "fresh" if metadata_current else "stale"

        checker_status = ""
        diff_state = "missing"
        diff = _read_json(diff_path)
        if diff is not None:
            checker_status = str(diff.get("result") or "")
            if metadata_state == "fresh" and diff_path.stat().st_mtime_ns >= metadata_path.stat().st_mtime_ns:
                diff_state = "fresh"
            else:
                diff_state = "stale"

        status = audit_status(
            metadata_state=metadata_state,
            diff_state=diff_state,
            owner_status=validation["status"],
            pdb_owner=pdb_owner,
            checker_status=checker_status,
        )
        canonical_source = _relative(preferred_source_path(record))
        duplicate_source_owner = len(source_paths_by_va[va]) > 1
        if duplicate_source_owner:
            status = "DUPLICATE_SOURCE_OWNER"
        mismatch_kind = owner_mismatch_kind(validation) if validation["status"] == "mismatch" else ""
        reason = _repair_reason(status, mismatch_kind)
        group = matching_build_for_va(va)
        row = {
            "va": f"{va:08X}",
            "name": record["name"],
            "source": source_path,
            "canonical_source": canonical_source,
            "source_owner_status": (
                "canonical"
                if source_path.casefold() == canonical_source.casefold()
                else "duplicate"
            ),
            "duplicate_source_owner": duplicate_source_owner,
            "bank": "matching",
            "corpus_bucket": bucket,
            "grouped_tu": "" if group is None else str(group["name"]),
            "pdb_qualified_owner": pdb_owner,
            "rebuilt_decorated_symbol": rebuilt_symbol,
            "owner_status": validation["status"],
            "owner_expected_name": validation["expected"],
            "owner_expected_class": validation["expected_owner"],
            "owner_rebuilt_class": validation["rebuilt_owner"],
            "owner_mismatch_kind": mismatch_kind,
            "metadata_state": metadata_state,
            "checker_status": checker_status,
            "diff_state": diff_state,
            "status": status,
            "repair_reason": reason,
            "metadata_path": _relative(metadata_path) if metadata is not None else "",
            "diff_path": _relative(diff_path) if diff is not None else "",
            "manifest_path": _relative(manifest_path),
            "object_path": _relative(object_path),
        }
        rows.append(row)

    rows.sort(key=lambda row: int(str(row["va"]), 16))
    return rows


def collect_function_audit_rows(path: Path) -> list[dict[str, Any]]:
    """Use one complete grouped audit without rebuilding dependency fingerprints."""
    report = json.loads(path.read_text(encoding="utf-8"))
    summary = report.get("summary") or {}
    if summary.get("compile_error_count") != 0:
        raise ValueError(f"{path}: grouped audit has compile errors")
    if summary.get("compiled_group_count") != summary.get("group_count"):
        raise ValueError(f"{path}: grouped audit is incomplete")

    rows: list[dict[str, Any]] = []
    for audit_row in report.get("rows") or []:
        if audit_row.get("source_bucket") != "matching":
            continue
        va = str(audit_row.get("va") or "")
        owner_status = str(audit_row.get("owner_status") or "unverified")
        checker_status = str(audit_row.get("grouped_result") or "")
        category = str(audit_row.get("category") or "")
        duplicate = len(audit_row.get("matching_groups") or []) > 1
        if duplicate:
            status = "DUPLICATE_SOURCE_OWNER"
        elif owner_status == "mismatch":
            status = "OWNER_MISMATCH"
        elif owner_status != "match":
            status = "OWNER_UNVERIFIED"
        elif category == "matching_result" and checker_status == "MATCH":
            status = "MATCH"
        else:
            status = "MISMATCH"
        mismatch_kind = ""
        reason = _repair_reason(status, mismatch_kind)
        source = str(audit_row.get("source_path") or "")
        rows.append(
            {
                "va": va,
                "name": str(audit_row.get("name") or ""),
                "source": source,
                "canonical_source": source,
                "source_owner_status": "duplicate" if duplicate else "canonical",
                "duplicate_source_owner": duplicate,
                "bank": "matching",
                "corpus_bucket": "normal",
                "grouped_tu": str(audit_row.get("group") or ""),
                "pdb_qualified_owner": str(audit_row.get("expected_symbol") or ""),
                "rebuilt_decorated_symbol": str(audit_row.get("symbol") or ""),
                "owner_status": owner_status,
                "owner_expected_name": str(audit_row.get("expected_owner_name") or ""),
                "owner_expected_class": "",
                "owner_rebuilt_class": "",
                "owner_mismatch_kind": mismatch_kind,
                "metadata_state": "grouped",
                "checker_status": checker_status,
                "diff_state": "grouped",
                "status": status,
                "repair_reason": reason,
                "metadata_path": str(path),
                "diff_path": str(path),
                "manifest_path": "",
                "object_path": "",
            }
        )
    rows.sort(key=lambda row: int(str(row["va"]), 16))
    return rows


def build_report(rows: list[dict[str, Any]]) -> dict[str, Any]:
    rows = sorted(rows, key=lambda row: int(str(row["va"]), 16))
    status_counts = Counter(str(row["status"]) for row in rows)
    owner_counts = Counter(str(row["owner_status"]) for row in rows)
    metadata_counts = Counter(str(row["metadata_state"]) for row in rows)
    checker_counts = Counter(str(row["checker_status"] or "UNAVAILABLE") for row in rows)
    duplicate_vas = {str(row["va"]) for row in rows if row.get("duplicate_source_owner", False)}
    repair_queue = [
        {
            "va": row["va"],
            "status": row["status"],
            "reason": row["repair_reason"],
            "owner_mismatch_kind": row["owner_mismatch_kind"],
            "pdb_qualified_owner": row["pdb_qualified_owner"],
            "rebuilt_decorated_symbol": row["rebuilt_decorated_symbol"],
            "source": row["source"],
            "grouped_tu": row["grouped_tu"],
        }
        for row in rows
        if row["repair_reason"]
    ]
    repair_queue.sort(key=lambda row: int(str(row["va"]), 16))
    exact_claims = sum(
        row["status"] == "MATCH" and row["owner_status"] == "match" for row in rows
    )
    return {
        "schema": 1,
        "scope": "matching-status normal functions with one compiler source",
        "summary": {
            "normal_functions": len({str(row["va"]) for row in rows}),
            "normal_function_entries": len(rows),
            "duplicate_source_owner_va_count": len(duplicate_vas),
            "duplicate_source_owner_entry_count": sum(
                row.get("duplicate_source_owner", False) for row in rows
            ),
            "status_counts": dict(sorted(status_counts.items())),
            "owner_status_counts": dict(sorted(owner_counts.items())),
            "metadata_state_counts": dict(sorted(metadata_counts.items())),
            "checker_status_counts": dict(sorted(checker_counts.items())),
            "owner_mismatch_count": sum(row["owner_status"] == "mismatch" for row in rows),
            "class_or_free_owner_mismatch_count": sum(
                row["owner_mismatch_kind"] in {"class_owner", "free_function_owner", "unexpected_class_owner"}
                for row in rows
            ),
            "exact_claim_count": exact_claims,
            "repair_queue_count": len(repair_queue),
        },
        "repair_queue": repair_queue,
        "rows": rows,
    }


def write_text_report(report: dict[str, Any], path: Path) -> None:
    summary = report["summary"]
    lines = [
        "Matching owner audit",
        f"Scope: {report['scope']}",
        f"Normal functions: {summary['normal_functions']}",
        f"Tracked source entries: {summary['normal_function_entries']}",
        f"Duplicate source-owner VAs: {summary['duplicate_source_owner_va_count']}",
        f"Owner mismatches: {summary['owner_mismatch_count']}",
        f"Class/free-function owner mismatches: {summary['class_or_free_owner_mismatch_count']}",
        f"Exact claims with verified owner: {summary['exact_claim_count']}",
        f"Repair queue: {summary['repair_queue_count']}",
        "",
        "Status counts:",
    ]
    lines.extend(f"  {key}: {value}" for key, value in summary["status_counts"].items())
    lines.extend(["", "Repair queue:"])
    for row in report["repair_queue"]:
        lines.append(
            f"  P{row['priority']} {row['va']} {row['status']} {row['source']}"
            f" | {row['pdb_qualified_owner'] or '<no PDB owner>'}"
            f" | {row['rebuilt_decorated_symbol'] or '<no rebuilt symbol>'}"
            f" | TU={row['grouped_tu'] or '-'}"
            f" | {row['reason']}"
        )
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Audit PDB-qualified owners and current rebuilt symbols for every "
            "matching-status normal function."
        )
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=BUILD_DIR / "matching_owner_audit.json",
        help="Deterministic JSON report path.",
    )
    parser.add_argument(
        "--text-output",
        type=Path,
        default=BUILD_DIR / "matching_owner_audit.txt",
        help="Deterministic text report path.",
    )
    parser.add_argument(
        "--function-report",
        type=Path,
        help="Use one complete grouped-observation report instead of stale per-function artifacts.",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    rows = (
        collect_function_audit_rows(args.function_report)
        if args.function_report is not None
        else collect_audit_rows()
    )
    report = build_report(rows)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    write_text_report(report, args.text_output)
    summary = report["summary"]
    print(
        f"Audited {summary['normal_functions']} normal functions; "
        f"owner mismatches={summary['owner_mismatch_count']}; "
        f"class/free mismatches={summary['class_or_free_owner_mismatch_count']}; "
        f"repair queue={summary['repair_queue_count']}"
    )
    print(f"Wrote {args.output}")
    print(f"Wrote {args.text_output}")


if __name__ == "__main__":
    main()
