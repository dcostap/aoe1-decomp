from __future__ import annotations

import argparse
import hashlib
import json
import re
from collections import defaultdict, deque
from pathlib import Path
from typing import Iterable

from common import repo_path


STRUCTURAL_FIELDS = (
    "owner_status",
    "relocation_target_mismatches",
    "boundary_escape_count",
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Build persistent repair state and captain packets from one TU sweep."
    )
    parser.add_argument(
        "--report",
        default="build/audits/tu_orchestration/report.json",
        help="Observed-function sweep report.",
    )
    parser.add_argument(
        "--queue",
        default="",
        help="Sweep queue. Default: queue.json beside the report.",
    )
    parser.add_argument(
        "--baseline-report",
        default="",
        help="Optional prior sweep report for delta and regression checks.",
    )
    parser.add_argument(
        "--output-dir",
        default="build/audits/tu_orchestration",
        help="Directory for state, dependencies, packets, prompts, and deltas.",
    )
    parser.add_argument(
        "--state",
        default="",
        help="Prior state file. Default: state.json in the output directory.",
    )
    parser.add_argument(
        "--assign",
        action="append",
        default=[],
        metavar="GROUP=CAPTAIN_ID",
        help="Assign or preserve one captain for a TU.",
    )
    parser.add_argument(
        "--start",
        action="append",
        default=[],
        metavar="GROUP=RUN_ID",
        help="Record the exact active captain run for one TU.",
    )
    parser.add_argument(
        "--approve",
        action="append",
        default=[],
        metavar="GROUP=VA",
        help="Record one reviewed promotion candidate.",
    )
    parser.add_argument(
        "--accept-drift",
        action="append",
        default=[],
        metavar="GROUP=VA",
        help="Accept only the current reviewed result for one accepted-drift VA.",
    )
    parser.add_argument(
        "--block",
        action="append",
        default=[],
        metavar="GROUP=REASON",
        help="Block one TU on a main-agent shared repair.",
    )
    parser.add_argument(
        "--clear-block",
        action="append",
        default=[],
        metavar="GROUP",
        help="Clear all resolved shared blockers for one TU.",
    )
    parser.add_argument(
        "--finish",
        action="append",
        default=[],
        metavar="GROUP=RUN_ID",
        help="Record a returned captain run and require integration validation.",
    )
    parser.add_argument(
        "--validated",
        action="append",
        default=[],
        metavar="GROUP=RUN_ID,COMMIT",
        help="Validate one returned run and record its integration commit.",
    )
    parser.add_argument(
        "--limit",
        type=int,
        default=40,
        help="Maximum conflict-free TUs in the ready wave. Default: 40.",
    )
    parser.add_argument(
        "--fail-on-regression",
        action="store_true",
        help="Return failure when the delta contains a blocking regression.",
    )
    return parser.parse_args()


def load_json(path: Path) -> dict[str, object]:
    value = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(value, dict):
        raise ValueError(f"Expected a JSON object: {path}")
    return value


def validate_report(report: dict[str, object]) -> None:
    rows = report.get("rows")
    errors = report.get("compile_errors")
    if not isinstance(rows, list):
        raise ValueError("Report rows must be a list.")
    if not isinstance(errors, list):
        raise ValueError("Report compile_errors must be a list.")
    for index, row in enumerate(rows):
        if not isinstance(row, dict):
            raise ValueError(f"Report row {index} must be an object.")
        if not str(row.get("group") or "") or not str(row.get("va") or ""):
            raise ValueError(f"Report row {index} needs group and VA fields.")
    for index, error in enumerate(errors):
        if not isinstance(error, dict):
            raise ValueError(f"Compile error {index} must be an object.")


def validate_state(state: dict[str, object]) -> None:
    groups = state.get("groups", {})
    if not isinstance(groups, dict):
        raise ValueError("State groups must be an object.")
    for group, value in groups.items():
        if not isinstance(value, dict):
            raise ValueError(f"State for group {group} must be an object.")


def file_sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def display_path(path: Path) -> str:
    try:
        return path.relative_to(repo_path(".")).as_posix()
    except ValueError:
        return str(path)


def validate_report_transition(
    prior_fingerprint: str,
    report_fingerprint: str,
    baseline_fingerprint: str,
) -> None:
    if not prior_fingerprint or report_fingerprint == prior_fingerprint:
        return
    if not baseline_fingerprint:
        raise ValueError("The sweep changed, but no baseline report was supplied.")
    if baseline_fingerprint != prior_fingerprint:
        raise ValueError(
            "The baseline report does not match the report stored in state."
        )


def resolve_prior_fingerprint(
    prior_state: dict[str, object],
    baseline_display_path: str,
    baseline_fingerprint: str,
) -> str:
    fingerprint = str(prior_state.get("report_fingerprint") or "")
    if not prior_state or fingerprint:
        return fingerprint
    if not baseline_fingerprint:
        raise ValueError(
            "Legacy state has no report fingerprint. Supply its baseline report."
        )
    stored_report = str(prior_state.get("report") or "")
    if stored_report and baseline_display_path != stored_report:
        raise ValueError(
            "The baseline report path does not match the legacy state report."
        )
    return baseline_fingerprint


def parse_mapping(values: Iterable[str], label: str) -> dict[str, str]:
    result: dict[str, str] = {}
    for value in values:
        key, separator, item = value.partition("=")
        if not separator or not key.strip() or not item.strip():
            raise ValueError(f"Invalid {label}: {value}. Use GROUP=VALUE.")
        result[key.strip()] = item.strip()
    return result


def parse_pairs(values: Iterable[str], label: str) -> list[tuple[str, str]]:
    result = []
    for value in values:
        key, separator, item = value.partition("=")
        if not separator or not key.strip() or not item.strip():
            raise ValueError(f"Invalid {label}: {value}. Use GROUP=VALUE.")
        result.append((key.strip(), item.strip()))
    return result


def queue_packets(queue: dict[str, object]) -> list[dict[str, object]]:
    raw = queue.get("packets")
    if not isinstance(raw, list):
        raise ValueError("Queue packets must be a list.")
    packets: list[dict[str, object]] = []
    groups: set[str] = set()
    for index, packet in enumerate(raw):
        if not isinstance(packet, dict):
            raise ValueError(f"Queue packet {index} must be an object.")
        group = str(packet.get("group") or "").strip()
        if not group:
            raise ValueError(f"Queue packet {index} has no group name.")
        if re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_.-]*", group) is None:
            raise ValueError(f"Unsafe queue group name: {group}")
        if group in groups:
            raise ValueError(f"Duplicate queue group: {group}")
        editable = packet.get("captain_editable_files", [])
        if not isinstance(editable, list) or any(
            not isinstance(path, str) or not path for path in editable
        ):
            raise ValueError(
                f"captain_editable_files for {group} must be a list of paths."
            )
        groups.add(group)
        packets.append(packet)
    declared = integer(queue.get("group_count"))
    if declared is not None and declared != len(packets):
        raise ValueError(
            f"Queue group count is {declared}, but {len(packets)} packets exist."
        )
    return packets


def integer(value: object) -> int | None:
    try:
        return int(str(value))
    except (TypeError, ValueError):
        return None


def row_key(row: dict[str, object]) -> tuple[str, str]:
    return str(row["group"]), str(row["va"]).upper()


def report_group_names(report: dict[str, object]) -> set[str]:
    groups = report.get("groups")
    if isinstance(groups, list):
        names = {
            str(group.get("group"))
            for group in groups
            if isinstance(group, dict) and group.get("group")
        }
        if names:
            return names
    names = {
        str(row.get("group"))
        for row in report.get("rows") or []
        if isinstance(row, dict) and row.get("group")
    }
    names.update(
        str(error.get("group"))
        for error in report.get("compile_errors") or []
        if isinstance(error, dict) and error.get("group")
    )
    return names


def row_signature(row: dict[str, object]) -> dict[str, object]:
    return {
        "result": row.get("grouped_result"),
        "diff_bytes": row.get("grouped_diff_bytes"),
        "owner_status": row.get("owner_status"),
        "relocation_target_mismatches": row.get("relocation_target_mismatches"),
        "boundary_escape_count": row.get("boundary_escape_count"),
        "category": row.get("category"),
    }


def structural_value(row: dict[str, object], field: str) -> object:
    value = row.get(field)
    if field == "owner_status":
        return str(value or "")
    return integer(value) or 0


def approved_vas(state: dict[str, object]) -> set[str]:
    result: set[str] = set()
    groups = state.get("groups") or {}
    if not isinstance(groups, dict):
        return result
    for group_state in groups.values():
        if not isinstance(group_state, dict):
            continue
        for va in group_state.get("approved_promotions") or []:
            result.add(str(va).upper())
    return result


def reviewed_drift_signatures(
    state: dict[str, object],
) -> dict[tuple[str, str], dict[str, object]]:
    result: dict[tuple[str, str], dict[str, object]] = {}
    groups = state.get("groups") or {}
    if not isinstance(groups, dict):
        return result
    for group, group_state in groups.items():
        if not isinstance(group_state, dict):
            continue
        signatures = group_state.get("reviewed_drift_signatures") or {}
        if not isinstance(signatures, dict):
            raise ValueError(f"Invalid drift signatures for group: {group}")
        for va, signature in signatures.items():
            if not isinstance(signature, dict):
                raise ValueError(f"Invalid drift signature for {group} {va}")
            result[(str(group), str(va).upper())] = signature
    return result


def record_drift_acceptances(
    state: dict[str, object],
    acceptances: list[tuple[str, str]],
    report: dict[str, object],
) -> None:
    validate_state(state)
    rows = {
        row_key(row): row
        for row in report.get("rows") or []
        if isinstance(row, dict)
    }
    groups = state.setdefault("groups", {})
    assert isinstance(groups, dict)
    for group, va_value in acceptances:
        va = va_value.upper()
        row = rows.get((group, va))
        if row is None:
            raise ValueError(f"Accepted-drift row not found: {group} {va}")
        if str(row.get("source_bucket")) != "accepted_drift":
            raise ValueError(f"Row is not accepted drift: {group} {va}")
        group_state = groups.setdefault(group, {})
        if not isinstance(group_state, dict):
            raise ValueError(f"Invalid state for group: {group}")
        signatures = group_state.setdefault("reviewed_drift_signatures", {})
        if not isinstance(signatures, dict):
            raise ValueError(f"Invalid drift signatures for group: {group}")
        signatures[va] = row_signature(row)


def apply_state_changes(
    prior: dict[str, object],
    approvals: list[tuple[str, str]],
    clear_blocks: set[str],
    starts: list[tuple[str, str]],
    finishes: list[tuple[str, str]],
    validations: list[tuple[str, str]],
) -> dict[str, object]:
    validate_state(prior)
    groups = prior.setdefault("groups", {})
    if not isinstance(groups, dict):
        raise ValueError("State groups must be an object.")

    def group_state(group: str) -> dict[str, object]:
        value = groups.setdefault(group, {})
        if not isinstance(value, dict):
            raise ValueError(f"Invalid state for group: {group}")
        return value

    for group, va in approvals:
        state = group_state(group)
        approved = state.setdefault("approved_promotions", [])
        if not isinstance(approved, list):
            raise ValueError(f"Invalid approved promotions for group: {group}")
        normalized = va.upper()
        if normalized not in approved:
            approved.append(normalized)
            approved.sort()
    for group in clear_blocks:
        group_state(group)["shared_blockers"] = []
    for group, run_id in starts:
        state = group_state(group)
        active = str(state.get("active_run_id") or "")
        if active and active != run_id:
            raise ValueError(
                f"Group {group} already has active run {active}; cannot start {run_id}."
            )
        if state.get("pending_validation"):
            raise ValueError(f"Group {group} still requires integration validation.")
        state["active_run_id"] = run_id
    for group, run_id in finishes:
        state = group_state(group)
        active = str(state.get("active_run_id") or "")
        if active != run_id:
            raise ValueError(
                f"Cannot finish stale run {run_id} for {group}; active run is {active or 'none'}."
            )
        runs = state.setdefault("completed_runs", [])
        if not isinstance(runs, list):
            raise ValueError(f"Invalid completed runs for group: {group}")
        if run_id not in runs:
            runs.append(run_id)
        state["active_run_id"] = ""
        state["pending_validation"] = True
        state["pending_validation_run_id"] = run_id
    for group, value in validations:
        run_id, separator, commit = value.partition(",")
        if not separator or not run_id.strip() or not commit.strip():
            raise ValueError(
                f"Invalid validation for {group}: {value}. Use RUN_ID,COMMIT."
            )
        state = group_state(group)
        pending_run = str(state.get("pending_validation_run_id") or "")
        if not state.get("pending_validation") or pending_run != run_id:
            raise ValueError(
                f"Cannot validate stale run {run_id} for {group}; "
                f"pending run is {pending_run or 'none'}."
            )
        state["pending_validation"] = False
        state["pending_validation_run_id"] = ""
        state["last_commit"] = commit.strip()
    return prior


def compare_reports(
    before: dict[str, object] | None,
    after: dict[str, object],
    approved: set[str] | None = None,
    reviewed_drift: dict[tuple[str, str], dict[str, object]] | None = None,
) -> dict[str, object]:
    validate_report(after)
    if before is not None:
        validate_report(before)
    approved = approved or set()
    reviewed_drift = reviewed_drift or {}
    after_rows = after.get("rows") or []
    if not isinstance(after_rows, list):
        raise ValueError("Current report rows must be a list.")
    compile_errors = after.get("compile_errors") or []
    regressions: list[dict[str, object]] = []
    events: list[dict[str, object]] = []

    for error in compile_errors:
        if isinstance(error, dict):
            regressions.append(
                {
                    "kind": "compile_error",
                    "group": error.get("group", ""),
                    "va": "",
                    "reason": str(error.get("error") or "Wrapper compilation failed."),
                }
            )
    for row in after_rows:
        if isinstance(row, dict) and str(row.get("grouped_result")) == "ERROR":
            regressions.append(
                {
                    "kind": "comparison_error",
                    "group": str(row.get("group") or ""),
                    "va": str(row.get("va") or ""),
                    "reason": str(
                        row.get("error") or "Grouped function comparison failed."
                    ),
                }
            )

    if before is None:
        return {
            "schema": 1,
            "baseline_available": False,
            "event_count": 0,
            "regression_count": len(regressions),
            "gate": "FAIL" if regressions else "PASS",
            "events": [],
            "regressions": regressions,
        }

    before_rows = before.get("rows") or []
    if not isinstance(before_rows, list):
        raise ValueError("Baseline report rows must be a list.")
    old = {row_key(row): row for row in before_rows if isinstance(row, dict)}
    new = {row_key(row): row for row in after_rows if isinstance(row, dict)}
    current_groups = report_group_names(after)

    for key in sorted(set(old) | set(new)):
        prior = old.get(key)
        current = new.get(key)
        group, va = key
        if group not in current_groups:
            continue
        if prior is None:
            events.append({"kind": "new_row", "group": group, "va": va})
            continue
        if current is None:
            event = {"kind": "removed_row", "group": group, "va": va}
            events.append(event)
            if bool(prior.get("registered_in_group")):
                regressions.append(
                    {**event, "reason": "A registered owner disappeared from the sweep."}
                )
            continue

        prior_result = str(prior.get("grouped_result") or "")
        current_result = str(current.get("grouped_result") or "")
        prior_diff = integer(prior.get("grouped_diff_bytes"))
        current_diff = integer(current.get("grouped_diff_bytes"))
        if prior_result != current_result:
            kind = "new_exact" if current_result == "MATCH" else "lost_exact"
            events.append(
                {
                    "kind": kind,
                    "group": group,
                    "va": va,
                    "before": row_signature(prior),
                    "after": row_signature(current),
                }
            )
        elif prior_diff is not None and current_diff is not None and prior_diff != current_diff:
            events.append(
                {
                    "kind": "improved" if current_diff < prior_diff else "worsened",
                    "group": group,
                    "va": va,
                    "before_diff_bytes": prior_diff,
                    "after_diff_bytes": current_diff,
                }
            )

        if prior_result == "MATCH" and current_result != "MATCH":
            protected = bool(prior.get("registered_in_group")) or va in approved
            if protected:
                regressions.append(
                    {
                        "kind": "protected_exact_lost",
                        "group": group,
                        "va": va,
                        "reason": "A registered or approved exact result was lost.",
                    }
                )

        if str(prior.get("source_bucket")) == "accepted_drift":
            if row_signature(prior) != row_signature(current):
                accepted = reviewed_drift.get((group, va))
                if accepted != row_signature(current):
                    regressions.append(
                        {
                            "kind": "accepted_drift_changed",
                            "group": group,
                            "va": va,
                            "reason": "A reviewed accepted-drift result changed.",
                        }
                    )

        prior_owner = structural_value(prior, "owner_status")
        current_owner = structural_value(current, "owner_status")
        prior_relocations = structural_value(prior, "relocation_target_mismatches")
        current_relocations = structural_value(current, "relocation_target_mismatches")
        prior_boundaries = structural_value(prior, "boundary_escape_count")
        current_boundaries = structural_value(current, "boundary_escape_count")
        structural_reasons = []
        if prior_owner == "match" and current_owner != "match":
            structural_reasons.append("owner status regressed")
        if int(current_relocations) > int(prior_relocations):
            structural_reasons.append("relocation mismatches increased")
        if int(current_boundaries) > int(prior_boundaries):
            structural_reasons.append("boundary escapes increased")
        if structural_reasons:
            regressions.append(
                {
                    "kind": "structural_regression",
                    "group": group,
                    "va": va,
                    "reason": "; ".join(structural_reasons),
                }
            )

    return {
        "schema": 1,
        "baseline_available": True,
        "event_count": len(events),
        "regression_count": len(regressions),
        "gate": "FAIL" if regressions else "PASS",
        "events": events,
        "regressions": regressions,
    }


def conflict_components(conflicts: dict[str, set[str]]) -> list[list[str]]:
    remaining = set(conflicts)
    components: list[list[str]] = []
    while remaining:
        first = min(remaining)
        queue = deque([first])
        component: set[str] = set()
        while queue:
            group = queue.popleft()
            if group in component:
                continue
            component.add(group)
            queue.extend(sorted(conflicts.get(group, set()) - component))
        remaining -= component
        components.append(sorted(component))
    return components


def build_dependencies(queue: dict[str, object]) -> dict[str, object]:
    packets = queue_packets(queue)
    owners: dict[str, list[str]] = defaultdict(list)
    groups: list[str] = []
    for packet in packets:
        if not isinstance(packet, dict):
            continue
        group = str(packet["group"])
        groups.append(group)
        for source in packet.get("captain_editable_files") or []:
            owners[str(source)].append(group)

    conflicts: dict[str, set[str]] = {group: set() for group in groups}
    shared_files = []
    for source, source_groups in sorted(owners.items()):
        unique = sorted(set(source_groups))
        if len(unique) < 2:
            continue
        shared_files.append({"source_path": source, "groups": unique})
        for group in unique:
            conflicts[group].update(set(unique) - {group})

    return {
        "schema": 1,
        "groups": groups,
        "shared_editable_files": shared_files,
        "conflicts": {group: sorted(values) for group, values in sorted(conflicts.items())},
        "conflict_components": conflict_components(conflicts),
    }


def initial_status(
    packet: dict[str, object],
    group_state: dict[str, object],
    compile_error: bool = False,
) -> str:
    if compile_error:
        return "compile_error"
    if group_state.get("shared_blockers"):
        return "blocked_shared"
    if group_state.get("pending_validation"):
        return "pending_integration"
    if group_state.get("active_run_id"):
        return "active"
    captain_tasks = int(packet.get("captain_task_count") or 0)
    main_tasks = int(packet.get("main_agent_task_count") or 0)
    if captain_tasks:
        return "assigned" if group_state.get("captain_id") else "ready"
    if main_tasks:
        return "main_agent_review"
    if packet.get("accepted_drift_holds"):
        return "hold_only"
    return "complete"


def build_state(
    queue: dict[str, object],
    report_path: str,
    prior: dict[str, object] | None = None,
    assignments: dict[str, str] | None = None,
    blockers: dict[str, str] | None = None,
    compile_error_groups: set[str] | None = None,
) -> dict[str, object]:
    validate_state(prior or {})
    prior = prior or {}
    assignments = assignments or {}
    blockers = blockers or {}
    compile_error_groups = compile_error_groups or set()
    prior_groups = prior.get("groups") or {}
    if not isinstance(prior_groups, dict):
        prior_groups = {}
    packets = queue_packets(queue)

    state_groups: dict[str, dict[str, object]] = {
        str(group): dict(value) for group, value in prior_groups.items()
    }
    for packet in packets:
        if not isinstance(packet, dict):
            continue
        group = str(packet["group"])
        old = prior_groups.get(group) or {}
        if not isinstance(old, dict):
            old = {}
        state = {
            "status": "ready",
            "captain_id": str(old.get("captain_id") or ""),
            "active_run_id": str(old.get("active_run_id") or ""),
            "completed_runs": list(old.get("completed_runs") or []),
            "shared_blockers": list(old.get("shared_blockers") or []),
            "pending_validation": bool(old.get("pending_validation")),
            "pending_validation_run_id": str(
                old.get("pending_validation_run_id") or ""
            ),
            "approved_promotions": list(old.get("approved_promotions") or []),
            "reviewed_drift_signatures": dict(
                old.get("reviewed_drift_signatures") or {}
            ),
            "last_sweep": report_path,
            "last_commit": str(old.get("last_commit") or ""),
            "captain_task_count": int(packet.get("captain_task_count") or 0),
            "main_agent_task_count": int(packet.get("main_agent_task_count") or 0),
            "captain_editable_files": list(packet.get("captain_editable_files") or []),
        }
        if group in assignments:
            state["captain_id"] = assignments[group]
        if group in blockers:
            reason = blockers[group]
            if reason not in state["shared_blockers"]:
                state["shared_blockers"].append(reason)
        state["status"] = initial_status(
            packet, state, group in compile_error_groups
        )
        state_groups[group] = state

    return {
        "schema": 1,
        "report": report_path,
        "groups": state_groups,
    }


def packet_priority(packet: dict[str, object]) -> tuple[int, int, str]:
    structural = packet.get("structural_repairs") or []
    ownership = packet.get("ownership_investigations") or []
    codegen = packet.get("codegen_repairs") or []
    if any(
        isinstance(row, dict) and row.get("category") == "registered_owner_regression"
        for row in structural
    ):
        band = 0
    elif ownership:
        band = 1
    elif structural:
        band = 2
    else:
        band = 3
    differences = [
        integer(row.get("grouped_diff_bytes"))
        for row in codegen
        if isinstance(row, dict)
    ]
    known = [value for value in differences if value is not None]
    minimum = min(known) if known else 1_000_000
    return band, minimum, str(packet["group"])


def select_ready_wave(
    queue: dict[str, object],
    state: dict[str, object],
    dependencies: dict[str, object],
    limit: int,
) -> list[str]:
    if limit <= 0:
        return []
    packets = queue_packets(queue)
    state_groups = state.get("groups") or {}
    conflicts = dependencies.get("conflicts") or {}
    if not isinstance(state_groups, dict):
        raise ValueError("Invalid state groups.")
    if not isinstance(conflicts, dict):
        raise ValueError("Invalid dependency conflicts.")
    candidates = []
    occupied = {
        str(group)
        for group, group_state in state_groups.items()
        if isinstance(group_state, dict)
        and group_state.get("status") in {"active", "pending_integration"}
    }
    occupied_files = {
        str(source)
        for group in occupied
        for source in (
            state_groups.get(group, {}).get("captain_editable_files", [])
            if isinstance(state_groups.get(group), dict)
            else []
        )
    }
    for packet in packets:
        if not isinstance(packet, dict) or not int(packet.get("captain_task_count") or 0):
            continue
        group = str(packet["group"])
        group_state = state_groups.get(group) or {}
        if isinstance(group_state, dict) and group_state.get("status") in {"ready", "assigned"}:
            candidates.append(packet)
    selected: list[str] = []
    selected_set: set[str] = set()
    for packet in sorted(candidates, key=packet_priority):
        group = str(packet["group"])
        blocked_by = set(conflicts.get(group) or [])
        editable = {str(source) for source in packet.get("captain_editable_files") or []}
        if (selected_set | occupied) & blocked_by or editable & occupied_files:
            continue
        selected.append(group)
        selected_set.add(group)
        if len(selected) >= limit:
            break
    return selected


def captain_prompt(packet: dict[str, object], packet_path: str = "") -> str:
    group = str(packet["group"])
    if not packet_path:
        packet_path = f"build/audits/tu_orchestration/packets/{group}.json"
    lines = [
        f"You are the persistent repair captain for TU `{group}`.",
        "",
        f"Read the complete packet at `{packet_path}`.",
        "Read `LESSONS.md` and `docs/agentic_matching_workflow.md` completely.",
        "Use the authentic wrapper and flags from the packet.",
        "",
        "Scope rules:",
        "- Edit only files in `captain_editable_files`.",
        "- Do not edit shared headers, wrappers, config, tools, tests, or metrics.",
        "- Do not move files, commit, or launch subagents.",
        "- Do not edit accepted-drift holds.",
        "- Preserve unrelated worktree changes.",
        "",
        "Work order:",
        "1. Repair registered regressions and structural problems first.",
        "2. Then repair small codegen differences before large differences.",
        "3. Use fresh grouped validation after each stable cluster.",
        "4. Compare the complete TU result with the packet baseline.",
        "",
        "Source rules:",
        "- Recover natural VC5-era source.",
        "- Do not hide shared layout defects with raw local offsets.",
        "- Report a shared declaration defect to the main agent immediately.",
        "- Restore failed, opaque, or worsened experiments before return.",
        "",
        "Return one consolidated report with:",
        "- investigated, exact, improved, unresolved, and untouched VAs;",
        "- changed files;",
        "- bytes, owner, relocation, and boundary results;",
        "- exact-finish walkbacks;",
        "- shared-change requests;",
        "- validation commands and report paths.",
        "",
        "A clean partial result is valid. The same captain can continue later.",
    ]
    return "\n".join(lines) + "\n"


def delta_text(delta: dict[str, object]) -> str:
    lines = [
        "Translation-unit sweep delta",
        f"Baseline available: {delta['baseline_available']}",
        f"Events: {delta['event_count']}",
        f"Blocking regressions: {delta['regression_count']}",
        f"Gate: {delta['gate']}",
        "",
        "Regressions:",
    ]
    for item in delta["regressions"]:
        lines.append(
            f"  {item.get('group', '')} {item.get('va', '')} "
            f"{item['kind']}: {item['reason']}"
        )
    lines.extend(["", "Events:"])
    for item in delta["events"]:
        lines.append(
            f"  {item.get('group', '')} {item.get('va', '')} {item['kind']}"
        )
    return "\n".join(lines) + "\n"


def summary_text(
    queue: dict[str, object], state: dict[str, object], delta: dict[str, object]
) -> str:
    groups = state["groups"]
    counts: dict[str, int] = defaultdict(int)
    for group_state in groups.values():
        counts[str(group_state["status"])] += 1
    lines = [
        "Translation-unit orchestration state",
        f"Groups: {len(groups)}",
        f"Captain tasks: {queue.get('captain_task_count', 0)}",
        f"Main-agent tasks: {queue.get('main_agent_task_count', 0)}",
        f"Regression gate: {delta['gate']}",
        f"Ready wave: {len(state.get('ready_wave') or [])}",
        "",
        "States:",
    ]
    for status, count in sorted(counts.items()):
        lines.append(f"  {count:5}  {status}")
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    report_path = repo_path(args.report)
    queue_path = repo_path(args.queue) if args.queue else report_path.with_name("queue.json")
    output_dir = repo_path(args.output_dir)
    state_path = repo_path(args.state) if args.state else output_dir / "state.json"
    baseline_path = repo_path(args.baseline_report) if args.baseline_report else None

    report = load_json(report_path)
    queue = load_json(queue_path)
    prior_state = load_json(state_path) if state_path.is_file() else {}
    baseline = load_json(baseline_path) if baseline_path else None
    validate_report(report)
    validate_state(prior_state)
    if baseline is not None:
        validate_report(baseline)
    packets = queue_packets(queue)
    report_fingerprint = file_sha256(report_path)
    baseline_fingerprint = file_sha256(baseline_path) if baseline_path else ""
    prior_fingerprint = resolve_prior_fingerprint(
        prior_state,
        display_path(baseline_path) if baseline_path else "",
        baseline_fingerprint,
    )
    validate_report_transition(
        prior_fingerprint, report_fingerprint, baseline_fingerprint
    )
    assignments = parse_mapping(args.assign, "assignment")
    blockers = parse_mapping(args.block, "blocker")
    approvals = parse_pairs(args.approve, "approval")
    drift_acceptances = parse_pairs(args.accept_drift, "accepted drift")
    starts = parse_pairs(args.start, "started run")
    finishes = parse_pairs(args.finish, "finished run")
    validations = parse_pairs(args.validated, "validation")

    known_groups = {
        str(packet["group"]) for packet in packets
    }
    changed_groups = {
        group
        for group, _ in [
            *approvals,
            *drift_acceptances,
            *starts,
            *finishes,
            *validations,
        ]
    }
    unknown = sorted(
        (
            set(assignments)
            | set(blockers)
            | set(args.clear_block)
            | changed_groups
        )
        - known_groups
    )
    if unknown:
        raise SystemExit(f"Unknown groups: {', '.join(unknown)}")

    prior_state = apply_state_changes(
        prior_state,
        approvals,
        set(args.clear_block),
        starts,
        finishes,
        validations,
    )
    record_drift_acceptances(prior_state, drift_acceptances, report)
    delta = compare_reports(
        baseline,
        report,
        approved_vas(prior_state),
        reviewed_drift_signatures(prior_state),
    )
    dependencies = build_dependencies(queue)
    compile_error_groups = {
        str(error.get("group"))
        for error in report.get("compile_errors") or []
        if isinstance(error, dict)
    }
    state = build_state(
        queue,
        display_path(report_path),
        prior_state,
        assignments,
        blockers,
        compile_error_groups,
    )
    state["ready_wave"] = select_ready_wave(
        queue, state, dependencies, max(0, args.limit)
    )
    state["report_fingerprint"] = report_fingerprint

    packets_dir = output_dir / "packets"
    prompts_dir = output_dir / "prompts"
    deltas_dir = output_dir / "deltas"
    packets_dir.mkdir(parents=True, exist_ok=True)
    prompts_dir.mkdir(parents=True, exist_ok=True)
    deltas_dir.mkdir(parents=True, exist_ok=True)

    packet_count = 0
    for packet in packets:
        if not int(packet.get("captain_task_count") or 0):
            continue
        group = str(packet["group"])
        packet_path = packets_dir / f"{group}.json"
        prompt_path = prompts_dir / f"{group}.txt"
        packet_path.write_text(json.dumps(packet, indent=2) + "\n", encoding="utf-8")
        prompt_path.write_text(
            captain_prompt(packet, display_path(packet_path)), encoding="utf-8"
        )
        packet_count += 1

    delta_name = (
        f"{baseline_path.parent.name}-{baseline_path.stem}-{baseline_fingerprint[:8]}"
        f"-to-{report_path.parent.name}-{report_path.stem}-{report_fingerprint[:8]}"
        if baseline_path
        else f"initial-{report_path.stem}-{report_fingerprint[:8]}"
    )
    (deltas_dir / f"{delta_name}.json").write_text(
        json.dumps(delta, indent=2) + "\n", encoding="utf-8"
    )
    (deltas_dir / f"{delta_name}.txt").write_text(delta_text(delta), encoding="utf-8")
    (output_dir / "dependencies.json").write_text(
        json.dumps(dependencies, indent=2) + "\n", encoding="utf-8"
    )
    state_path.write_text(json.dumps(state, indent=2) + "\n", encoding="utf-8")
    summary = summary_text(queue, state, delta)
    (output_dir / "summary.txt").write_text(summary, encoding="utf-8")
    print(summary, end="")
    print(f"Wrote {state_path}")
    print(f"Wrote {output_dir / 'dependencies.json'}")
    print(f"Wrote {packet_count} captain packets and prompts")
    return 1 if args.fail_on_regression and delta["gate"] == "FAIL" else 0


if __name__ == "__main__":
    raise SystemExit(main())
