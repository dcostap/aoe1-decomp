from __future__ import annotations

import argparse
import csv
import json
import os
import sys
from collections import Counter
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from coff import load_coff_object
from common import (
    REPO_ROOT,
    function_record_by_va,
    function_slug,
    load_pdb_function_source_map,
    load_build_modules,
    repo_path,
)
from extract_obj_function import select_record_function_symbol
from original_fpo import load_original_owner_symbols
from status_core import build_status_rows
from function_compare import compile_source, compare_object_function
from validate_candidate_tu import _source_closure, _source_policy_issues


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Compile authentic translation units and compare every included normal "
            "function."
        )
    )
    parser.add_argument(
        "--group",
        action="append",
        default=[],
        help="Audit only this configured group. Repeat for more groups.",
    )
    parser.add_argument(
        "--jobs",
        type=int,
        default=min(40, os.cpu_count() or 1),
        help="Maximum groups compiled in parallel. Default: up to 40.",
    )
    parser.add_argument(
        "--output-dir",
        default="build/audits/translation_units",
        help="Directory for objects and JSON, CSV, and text reports.",
    )
    parser.add_argument(
        "--print-full",
        action="store_true",
        help="Print the full row dump. Reports always contain the full results.",
    )
    return parser.parse_args()


def isolated_symbol_name(va: int) -> str:
    record = function_record_by_va(va)
    metadata_path = REPO_ROOT / "build" / "asm" / f"rebuilt_{function_slug(record)}.json"
    if metadata_path.is_file():
        try:
            metadata = json.loads(metadata_path.read_text(encoding="utf-8"))
            symbol = metadata.get("symbol") or {}
            name = str(symbol.get("name") or "")
            if name:
                return name
        except (OSError, ValueError, json.JSONDecodeError):
            pass
    object_path = REPO_ROOT / "build" / "obj" / f"{function_slug(record)}.obj"
    if not object_path.is_file():
        return ""
    try:
        obj = load_coff_object(object_path)
        return str(select_record_function_symbol(obj, record["name"]).name)
    except (KeyError, ValueError):
        return ""


def integer(value: object) -> int | None:
    try:
        return int(str(value))
    except (TypeError, ValueError):
        return None


def classify(
    status: dict[str, str],
    comparison: dict[str, object],
    matching_here: bool,
    matching_anywhere: bool,
    policy_issues: list[str],
) -> tuple[str, str, str]:
    result = str(comparison.get("result") or "ERROR")
    old_result = str(status.get("diff_result") or "UNKNOWN")
    old_diff = integer(status.get("diff_bytes"))
    new_diff = integer(comparison.get("diff_bytes"))
    owner_status = str(comparison.get("owner_status") or "")
    relocation_errors = integer(comparison.get("relocation_target_mismatches")) or 0
    boundary_errors = integer(comparison.get("boundary_escape_count")) or 0

    if result == "MATCH":
        if matching_here:
            category = "matching_result"
            action = "none"
            reason = "The matching function remains exact in its natural translation unit."
        elif matching_anywhere:
            category = "matching_elsewhere_result"
            action = "none"
            reason = "The function is exact here and already matches in another module."
        elif policy_issues:
            category = "grouped_match_policy_review"
            action = "repair_policy_then_review_promotion"
            reason = "Grouped code is exact, but source-policy findings block promotion."
        else:
            category = "grouped_match_needs_review"
            action = "review_for_promotion"
            reason = "A non-matching function now produces an exact result."
    elif result == "MISMATCH":
        if matching_here:
            category = "matching_regression"
            action = "repair_before_integration"
            reason = "A matching function no longer produces an exact result."
        elif matching_anywhere:
            category = "matching_elsewhere_mismatch"
            action = "review_context_ownership"
            reason = "The owner is exact in another group but differs in this included context."
        elif new_diff == 0 and owner_status != "match":
            category = "ownership_problem"
            action = "investigate_ownership"
            reason = "Bytes match, but the owning symbol is not proved."
        elif relocation_errors:
            category = "relocation_problem"
            action = "repair_relocation_targets"
            reason = "One or more direct relocation targets differ from the original."
        elif boundary_errors:
            category = "boundary_problem"
            action = "repair_boundary_or_classification"
            reason = "Emitted code escapes the original function boundary."
        elif status.get("source_bucket") == "accepted_drift":
            category = "accepted_drift_observed"
            action = "hold_accepted_drift"
            reason = "Accepted drift stays closed without specific new evidence."
        else:
            category = "grouped_mismatch"
            action = "assign_matching_worker"
            reason = "The function is in its natural translation unit but still differs."
    elif result == "NOT_EMITTED":
        if matching_here:
            category = "matching_regression"
            action = "repair_before_integration"
            reason = "A matching function no longer emits its required symbol."
        elif matching_anywhere:
            category = "matching_elsewhere_missing"
            action = "review_context_ownership"
            reason = "The required symbol is absent here but owned by another group."
        elif status.get("source_bucket") == "accepted_drift":
            category = "accepted_drift_not_emitted"
            action = "hold_accepted_drift"
            reason = "Accepted drift stays closed when its symbol is absent."
        else:
            category = "missing_grouped_symbol"
            action = "repair_missing_symbol"
            reason = "The natural translation unit does not emit the expected normal symbol."
    else:
        category = "grouped_comparison_error"
        action = "investigate_comparison_error"
        reason = str(comparison.get("error") or "Grouped comparison did not complete.")

    if old_diff is not None and new_diff is not None:
        delta = new_diff - old_diff
        if delta < 0:
            change = f"improved_by_{-delta}_bytes"
        elif delta > 0:
            change = f"worsened_by_{delta}_bytes"
        else:
            change = "same_diff_count"
    elif old_result != result:
        change = f"{old_result.lower()}_to_{result.lower()}"
    else:
        change = "no_comparable_previous_metric"
    return category, action, f"{reason} Previous recorded check: {old_result}; {change}."


def difficulty_band(row: dict[str, object]) -> str:
    if row["category"] in {
        "ownership_problem",
        "relocation_problem",
        "boundary_problem",
        "matching_regression",
        "missing_grouped_symbol",
    }:
        return "structural"
    difference = integer(row.get("grouped_diff_bytes"))
    if difference is None:
        return "unknown"
    if difference <= 1:
        return "0-1"
    if difference <= 4:
        return "2-4"
    if difference <= 16:
        return "5-16"
    if difference <= 64:
        return "17-64"
    return "65+"


def compile_and_compare_group(
    group: dict[str, object],
    targets: list[dict[str, object]],
    original_symbols: dict[str, str],
    pdb_owner_names: dict[str, str],
    matching_groups_by_va: dict[str, list[str]],
    output_dir: Path,
) -> dict[str, object]:
    name = str(group["name"])
    wrapper = repo_path(str(group["source"]))
    build = group["build"]
    assert isinstance(build, dict)
    flags = repo_path(str(build["flags_path"]))
    object_path = output_dir / "objects" / f"{name}.obj"
    object_path.parent.mkdir(parents=True, exist_ok=True)
    try:
        compile_source(wrapper, object_path, flags, wrapper.parent)
        obj = load_coff_object(object_path)
    except (OSError, RuntimeError, ValueError) as error:
        return {
            "group": name,
            "source": str(group["source"]),
            "flags": str(build["flags_path"]),
            "compile_error": str(error),
            "rows": [],
        }

    functions = group["functions"]
    assert isinstance(functions, dict)
    rows: list[dict[str, object]] = []
    for target in targets:
        status = target["status"]
        assert isinstance(status, dict)
        va = str(status["va"]).upper()
        function_entry = functions.get(va)
        assert isinstance(function_entry, dict)
        expected_symbol = str(function_entry.get("symbol") or original_symbols.get(va) or "")
        if not expected_symbol:
            expected_symbol = isolated_symbol_name(int(va, 16))
        expected_owner_name = pdb_owner_names.get(va, "")
        try:
            result = compare_object_function(obj, int(va, 16), group, expected_owner_name)
            relocations = result["relocations"]
            owner = result["owner_symbol"]
            assert isinstance(relocations, dict)
            assert isinstance(owner, dict)
            comparison: dict[str, object] = {
                "result": result["result"],
                "diff_bytes": result["diff_bytes"],
                "diff_percent": result["diff_percent"],
                "original_size": result["original_size"],
                "rebuilt_size": result["rebuilt_size"],
                "owner_status": owner.get("status", ""),
                "relocation_target_mismatches": len(
                    relocations.get("target_mismatches") or []
                ),
                "boundary_escape_count": len(result["boundary_escape_offsets"]),
                "symbol": result["symbol"],
                "expected_symbol": expected_symbol,
                "expected_owner_name": expected_owner_name,
                "error": "",
            }
        except (KeyError, OSError, RuntimeError, ValueError) as error:
            message = str(error)
            missing_symbol = (
                "Expected one defined function" in message and "found []" in message
            )
            comparison = {
                "result": "NOT_EMITTED" if missing_symbol else "ERROR",
                "diff_bytes": "",
                "diff_percent": "",
                "original_size": "",
                "rebuilt_size": "",
                "owner_status": "error",
                "relocation_target_mismatches": "",
                "boundary_escape_count": "",
                "symbol": "",
                "expected_symbol": expected_symbol,
                "expected_owner_name": expected_owner_name,
                "error": message,
            }

        matching_here = function_entry.get("status") == "matching"
        matching_groups = matching_groups_by_va.get(va, [])
        matching_anywhere = bool(matching_groups)
        policy_issues = target["policy_issues"]
        assert isinstance(policy_issues, list)
        category, action, reason = classify(
            status,
            comparison,
            matching_here,
            matching_anywhere,
            policy_issues,
        )
        row = {
                "group": name,
                "va": va,
                "name": status["name"],
                "source_path": status["source_path"],
                "source_bucket": status["source_bucket"],
                "matching_in_group": matching_here,
                "matching_anywhere": matching_anywhere,
                "matching_groups": matching_groups,
                "previous_result": status.get("diff_result") or "UNKNOWN",
                "previous_diff_bytes": status.get("diff_bytes") or "",
                "grouped_result": comparison["result"],
                "grouped_diff_bytes": comparison["diff_bytes"],
                "grouped_diff_percent": comparison["diff_percent"],
                "owner_status": comparison["owner_status"],
                "relocation_target_mismatches": comparison[
                    "relocation_target_mismatches"
                ],
                "boundary_escape_count": comparison["boundary_escape_count"],
                "symbol": comparison["symbol"],
                "expected_symbol": comparison["expected_symbol"],
                "expected_owner_name": comparison["expected_owner_name"],
                "policy_issues": policy_issues,
                "category": category,
                "recommended_action": action,
                "reason": reason,
                "error": comparison["error"],
            }
        row["difficulty_band"] = difficulty_band(row)
        rows.append(row)
    return {
        "group": name,
        "source": str(group["source"]),
        "flags": str(build["flags_path"]),
        "compile_error": "",
        "rows": rows,
    }


def text_report(report: dict[str, object]) -> str:
    summary = report["summary"]
    assert isinstance(summary, dict)
    rows = report["rows"]
    assert isinstance(rows, list)
    lines = [
        "Translation-unit function sweep",
        f"Groups requested: {summary['group_count']}",
        f"Groups compiled: {summary['compiled_group_count']}",
        f"Included normal functions: {summary['function_count']}",
        f"Exact validation targets: {summary['matching_count']}",
        f"Other configured functions: {summary['nonmatching_count']}",
        "",
        "Categories:",
    ]
    category_counts = summary["category_counts"]
    assert isinstance(category_counts, dict)
    for category, count in sorted(
        category_counts.items(), key=lambda item: (-int(item[1]), item[0])
    ):
        lines.append(f"  {int(count):5}  {category}")
    lines.extend(
        [
            "",
            "Full results:",
            "GROUP                      VA        OLD_BUCKET       OLD      OLD_DIFF  GROUPED   NEW_DIFF  OWNER       RELOC  BOUND  ACTION",
        ]
    )
    for row in rows:
        assert isinstance(row, dict)
        lines.append(
            f"{str(row['group']):<26} "
            f"{str(row['va']):<8}  "
            f"{str(row['source_bucket']):<15}  "
            f"{str(row['previous_result']):<8} "
            f"{str(row['previous_diff_bytes']):>8}  "
            f"{str(row['grouped_result']):<8} "
            f"{str(row['grouped_diff_bytes']):>8}  "
            f"{str(row['owner_status']):<10}  "
            f"{str(row['relocation_target_mismatches']):>5}  "
            f"{str(row['boundary_escape_count']):>5}  "
            f"{row['recommended_action']}"
        )
    candidates = [
        row
        for row in rows
        if isinstance(row, dict) and row["recommended_action"] != "none"
    ]
    lines.extend(["", "Action queue:"])
    for row in candidates:
        lines.append(
            f"  {row['va']} {row['name']} [{row['group']}] "
            f"{row['recommended_action']}: {row['reason']}"
        )
        if row["error"]:
            lines.append(f"    error: {row['error']}")
        for issue in row["policy_issues"]:
            lines.append(f"    policy: {issue}")
    return "\n".join(lines) + "\n"


def console_summary(report: dict[str, object]) -> str:
    summary = report["summary"]
    assert isinstance(summary, dict)
    lines = [
        "Translation-unit function sweep",
        f"Groups requested: {summary['group_count']}",
        f"Groups compiled: {summary['compiled_group_count']}",
        f"Included normal functions: {summary['function_count']}",
        f"Exact validation targets: {summary['matching_count']}",
        f"Other configured functions: {summary['nonmatching_count']}",
        "Categories:",
    ]
    category_counts = summary["category_counts"]
    assert isinstance(category_counts, dict)
    for category, count in sorted(
        category_counts.items(), key=lambda item: (-int(item[1]), item[0])
    ):
        lines.append(f"  {int(count):5}  {category}")
    return "\n".join(lines)


def build_queue(
    groups: list[dict[str, object]], rows: list[dict[str, object]]
) -> dict[str, object]:
    group_order = {str(group["name"]): index for index, group in enumerate(groups)}
    group_coverage = Counter(str(row["group"]) for row in rows)
    contexts_by_va: dict[str, list[dict[str, object]]] = {}
    for row in rows:
        contexts_by_va.setdefault(str(row["va"]), []).append(row)

    assignments: list[dict[str, object]] = []
    assigned_group_by_va: dict[str, str] = {}
    for va, contexts in sorted(contexts_by_va.items()):
        matching_groups = {
            str(group_name)
            for context in contexts
            for group_name in context.get("matching_groups", [])
        }
        matching_contexts = [
            context for context in contexts if str(context["group"]) in matching_groups
        ]
        exact_contexts = [
            context for context in contexts if context["grouped_result"] == "MATCH"
        ]
        candidates = matching_contexts or exact_contexts or contexts
        canonical = max(
            candidates,
            key=lambda context: (
                int(group_coverage[str(context["group"])]),
                -int(group_order[str(context["group"])]),
            ),
        )
        canonical_group = str(canonical["group"])
        assigned_group_by_va[va] = canonical_group
        assignments.append(
            {
                "va": va,
                "name": canonical["name"],
                "source_path": canonical["source_path"],
                "canonical_group": canonical_group,
                "selection_reason": (
                    "matching function context"
                    if matching_contexts
                    else "largest exact context"
                    if exact_contexts
                    else "largest included context"
                ),
                "contexts": [
                    {
                        "group": context["group"],
                        "grouped_result": context["grouped_result"],
                        "grouped_diff_bytes": context["grouped_diff_bytes"],
                        "category": context["category"],
                    }
                    for context in sorted(
                        contexts, key=lambda item: group_order[str(item["group"])]
                    )
                ],
            }
        )

    group_metadata = {
        str(group["name"]): {
            "source": str(group["source"]),
            "flags": str(group["build"]["flags_path"]),
        }
        for group in groups
    }
    packets: list[dict[str, object]] = []
    for group in groups:
        name = str(group["name"])
        all_group_rows = [row for row in rows if row["group"] == name]
        group_rows = [
            row
            for row in all_group_rows
            if assigned_group_by_va[str(row["va"])] == name
        ]
        duplicate_contexts = [
            row
            for row in all_group_rows
            if assigned_group_by_va[str(row["va"])] != name
        ]
        promotions = [
            row for row in group_rows if row["recommended_action"] == "review_for_promotion"
        ]
        policy_reviews = [
            row
            for row in group_rows
            if row["recommended_action"] == "repair_policy_then_review_promotion"
        ]
        ownership = [
            row for row in group_rows if row["recommended_action"] == "investigate_ownership"
        ]
        structural = [
            row
            for row in group_rows
            if row["recommended_action"]
            in {
                "repair_before_integration",
                "repair_relocation_targets",
                "repair_boundary_or_classification",
                "repair_missing_symbol",
            }
        ]
        codegen = [
            row for row in group_rows if row["recommended_action"] == "assign_matching_worker"
        ]
        accepted_holds = [
            row for row in group_rows if row["recommended_action"] == "hold_accepted_drift"
        ]
        context_reviews = [
            row for row in group_rows if row["recommended_action"] == "review_context_ownership"
        ]
        errors = [
            row
            for row in group_rows
            if row["recommended_action"] == "investigate_comparison_error"
        ]
        editable = sorted(
            {
                str(row["source_path"])
                for row in [*structural, *codegen]
                if row["source_path"]
            }
        )
        packets.append(
            {
                "group": name,
                **group_metadata[name],
                "promotion_candidates": promotions,
                "promotion_policy_reviews": policy_reviews,
                "ownership_investigations": ownership,
                "structural_repairs": structural,
                "codegen_repairs": codegen,
                "accepted_drift_holds": accepted_holds,
                "context_ownership_reviews": context_reviews,
                "comparison_errors": errors,
                "noncanonical_contexts": duplicate_contexts,
                "captain_editable_files": editable,
                "captain_task_count": len(ownership) + len(structural) + len(codegen),
                "main_agent_task_count": (
                    len(promotions)
                    + len(policy_reviews)
                    + len(context_reviews)
                    + len(errors)
                ),
            }
        )
    return {
        "schema": 1,
        "group_count": len(packets),
        "captain_task_count": sum(int(packet["captain_task_count"]) for packet in packets),
        "main_agent_task_count": sum(
            int(packet["main_agent_task_count"]) for packet in packets
        ),
        "assignments": assignments,
        "packets": packets,
    }


def queue_text(queue: dict[str, object]) -> str:
    packets = queue["packets"]
    assert isinstance(packets, list)
    lines = [
        "Translation-unit repair queue",
        f"Groups: {queue['group_count']}",
        f"Matching-worker tasks: {queue['captain_task_count']}",
        f"Main-agent tasks: {queue['main_agent_task_count']}",
        "",
    ]
    for packet in packets:
        assert isinstance(packet, dict)
        lines.extend(
            [
                f"[{packet['group']}] {packet['source']}",
                f"  promotions: {len(packet['promotion_candidates'])}",
                f"  promotion policy reviews: {len(packet['promotion_policy_reviews'])}",
                f"  ownership: {len(packet['ownership_investigations'])}",
                f"  structural: {len(packet['structural_repairs'])}",
                f"  codegen: {len(packet['codegen_repairs'])}",
                f"  accepted drift holds: {len(packet['accepted_drift_holds'])}",
                f"  context reviews: {len(packet['context_ownership_reviews'])}",
                f"  comparison errors: {len(packet['comparison_errors'])}",
                f"  noncanonical contexts: {len(packet['noncanonical_contexts'])}",
            ]
        )
        for label, key in (
            ("promote", "promotion_candidates"),
            ("policy", "promotion_policy_reviews"),
            ("ownership", "ownership_investigations"),
            ("structural", "structural_repairs"),
            ("codegen", "codegen_repairs"),
        ):
            for row in packet[key]:
                lines.append(
                    f"    {label:<10} {row['va']} {row['name']} "
                    f"diff={row['grouped_diff_bytes']} band={row['difficulty_band']}"
                )
        lines.append("")
    return "\n".join(lines)


def main() -> int:
    args = parse_args()
    output_dir = repo_path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    groups = load_build_modules()
    matching_groups_by_va: dict[str, list[str]] = {}
    for group in groups:
        functions = group.get("functions")
        assert isinstance(functions, dict)
        for va, entry in functions.items():
            if isinstance(entry, dict) and entry.get("status") == "matching":
                matching_groups_by_va.setdefault(str(va).upper(), []).append(str(group["name"]))
    requested = set(args.group)
    if requested:
        known = {str(group["name"]) for group in groups}
        missing = sorted(requested - known)
        if missing:
            raise SystemExit(f"Unknown translation-unit groups: {', '.join(missing)}")
        groups = [group for group in groups if str(group["name"]) in requested]

    statuses = build_status_rows(include_source_preview=False)
    by_source: dict[Path, list[dict[str, str]]] = {}
    for status in statuses:
        source_path = str(status.get("source_path") or "")
        if (
            status.get("corpus_bucket") != "normal"
            or status.get("source_bucket") == "unresolved"
            or not source_path
        ):
            continue
        by_source.setdefault(repo_path(source_path).resolve(), []).append(status)

    policy_cache: dict[Path, list[str]] = {}
    targets_by_group: dict[str, list[dict[str, object]]] = {}
    for group in groups:
        wrapper = repo_path(str(group["source"]))
        targets: list[dict[str, object]] = []
        for source in _source_closure(wrapper):
            for status in by_source.get(source.resolve(), []):
                source_path = repo_path(str(status["source_path"])).resolve()
                if source_path not in policy_cache:
                    policy_cache[source_path] = _source_policy_issues(source_path)
                targets.append(
                    {
                        "status": status,
                        "policy_issues": policy_cache[source_path],
                    }
                )
        targets.sort(key=lambda target: str(target["status"]["va"]))
        targets_by_group[str(group["name"])] = targets

    original_symbols, _ = load_original_owner_symbols()
    pdb_owner_names = {
        str(va).upper(): str(entry.get("symbol_name") or "")
        for va, entry in load_pdb_function_source_map().items()
    }
    results: list[dict[str, object]] = []
    jobs = max(1, min(args.jobs, len(groups) or 1))
    with ThreadPoolExecutor(max_workers=jobs) as executor:
        futures = {
            executor.submit(
                compile_and_compare_group,
                group,
                targets_by_group[str(group["name"])],
                original_symbols,
                pdb_owner_names,
                matching_groups_by_va,
                output_dir,
            ): str(group["name"])
            for group in groups
        }
        completed = 0
        for future in as_completed(futures):
            results.append(future.result())
            completed += 1
            print(f"Completed groups: {completed}/{len(groups)}", flush=True)

    order = {str(group["name"]): index for index, group in enumerate(groups)}
    results.sort(key=lambda result: order[str(result["group"])])
    rows = [row for result in results for row in result["rows"]]
    category_counts = Counter(str(row["category"]) for row in rows)
    compile_errors = [
        {"group": result["group"], "error": result["compile_error"]}
        for result in results
        if result["compile_error"]
    ]
    report: dict[str, object] = {
        "schema": 1,
        "summary": {
            "group_count": len(groups),
            "compiled_group_count": len(groups) - len(compile_errors),
            "compile_error_count": len(compile_errors),
            "function_count": len(rows),
            "matching_count": sum(bool(row["matching_anywhere"]) for row in rows),
            "nonmatching_count": sum(not bool(row["matching_anywhere"]) for row in rows),
            "category_counts": dict(sorted(category_counts.items())),
        },
        "compile_errors": compile_errors,
        "groups": results,
        "rows": rows,
    }
    json_path = output_dir / "report.json"
    csv_path = output_dir / "report.csv"
    text_path = output_dir / "report.txt"
    queue_json_path = output_dir / "queue.json"
    queue_text_path = output_dir / "queue.txt"
    json_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")

    fields = [
        "group",
        "va",
        "name",
        "source_path",
        "source_bucket",
        "matching_in_group",
        "matching_anywhere",
        "matching_groups",
        "previous_result",
        "previous_diff_bytes",
        "grouped_result",
        "grouped_diff_bytes",
        "grouped_diff_percent",
        "owner_status",
        "relocation_target_mismatches",
        "boundary_escape_count",
        "symbol",
        "expected_symbol",
        "expected_owner_name",
        "category",
        "recommended_action",
        "reason",
        "error",
    ]
    with csv_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fields, extrasaction="ignore", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)
    text_path.write_text(text_report(report), encoding="utf-8")
    queue = build_queue(groups, rows)
    queue_json_path.write_text(json.dumps(queue, indent=2) + "\n", encoding="utf-8")
    queue_text_path.write_text(queue_text(queue) + "\n", encoding="utf-8")
    print(text_report(report) if args.print_full else console_summary(report))
    print(f"Wrote {json_path}")
    print(f"Wrote {csv_path}")
    print(f"Wrote {text_path}")
    print(f"Wrote {queue_json_path}")
    print(f"Wrote {queue_text_path}")
    return 1 if compile_errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
