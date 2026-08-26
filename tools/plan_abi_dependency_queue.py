from __future__ import annotations

import argparse
import json
from collections import defaultdict, deque
from pathlib import Path

from audit_translation_unit_symbols import audit_symbols
from common import REPO_ROOT, load_translation_units, repo_path
from original_fpo import DEFAULT_FPO_PATH
from validate_candidate_tu import _source_closure, _source_policy_issues


READ_ONLY_SHARED_HEADERS = {
    "include/game_globals.h",
    "include/game_types.h",
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Plan conflict-free ABI and source-policy repair tasks."
    )
    parser.add_argument("--objects-dir", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--fpo", default=str(DEFAULT_FPO_PATH))
    return parser.parse_args()


def relative(path: Path) -> str:
    return path.resolve().relative_to(REPO_ROOT.resolve()).as_posix()


def main() -> int:
    args = parse_args()
    groups = load_translation_units()
    symbol_report = audit_symbols(
        groups, repo_path(args.objects_dir), repo_path(args.fpo)
    )
    mismatch_by_group: dict[str, list[dict[str, str]]] = defaultdict(list)
    for row in symbol_report["mismatches"]:
        mismatch_by_group[row["group"]].append(row)

    tasks: dict[str, dict[str, object]] = {}
    for group in groups:
        name = str(group["name"])
        wrapper = repo_path(str(group["source"]))
        policy = _source_policy_issues(wrapper)
        mismatches = mismatch_by_group.get(name, [])
        if not mismatches and not policy:
            continue
        closure = _source_closure(wrapper)
        files = sorted(
            relative(path) for path in closure
            if path.is_file() and relative(path).split("/", 1)[0] in {"include", "src"}
        )
        headers = sorted(
            path for path in files
            if path.endswith(".h") and path not in READ_ONLY_SHARED_HEADERS
        )
        exclusive_files = sorted(
            path for path in files if path not in READ_ONLY_SHARED_HEADERS
        )
        tasks[name] = {
            "group": name,
            "wrapper": group["source"],
            "flags": group["flags"],
            "mismatches": mismatches,
            "mismatch_count": len(mismatches),
            "policy_issues": policy,
            "policy_issue_count": len(policy),
            "closure_files": files,
            "exclusive_files": exclusive_files,
            "exclusive_headers": headers,
            "read_only_headers": sorted(
                path for path in files if path in READ_ONLY_SHARED_HEADERS
            ),
        }

    file_users: dict[str, list[str]] = defaultdict(list)
    for name, task in tasks.items():
        for path in task["exclusive_files"]:
            file_users[path].append(name)
    shared = {key: sorted(value) for key, value in file_users.items() if len(value) > 1}

    adjacency = {name: set() for name in tasks}
    for users in shared.values():
        for index, left in enumerate(users):
            for right in users[index + 1:]:
                adjacency[left].add(right)
                adjacency[right].add(left)

    components: list[list[str]] = []
    remaining = set(tasks)
    while remaining:
        start = min(remaining)
        remaining.remove(start)
        pending = deque([start])
        component: list[str] = []
        while pending:
            current = pending.popleft()
            component.append(current)
            for neighbor in sorted(adjacency[current]):
                if neighbor in remaining:
                    remaining.remove(neighbor)
                    pending.append(neighbor)
        components.append(sorted(component))
    components.sort(
        key=lambda names: (
            -sum(tasks[name]["mismatch_count"] + tasks[name]["policy_issue_count"] for name in names),
            names,
        )
    )

    queue: list[dict[str, object]] = []
    for index, names in enumerate(components, 1):
        queue.append({
            "task_id": f"abi-{index:03d}",
            "groups": names,
            "mismatch_count": sum(tasks[name]["mismatch_count"] for name in names),
            "policy_issue_count": sum(tasks[name]["policy_issue_count"] for name in names),
            "exclusive_files": sorted({
                path for name in names for path in tasks[name]["exclusive_files"]
            }),
            "status": "ready",
        })
        for name in names:
            tasks[name]["task_id"] = f"abi-{index:03d}"

    report = {
        "owner_count": symbol_report["owner_count"],
        "symbol_mismatch_count": symbol_report["mismatch_count"],
        "unavailable_symbol_count": symbol_report["unavailable_count"],
        "group_task_count": len(tasks),
        "queue_task_count": len(queue),
        "maximum_concurrency": 40,
        "read_only_shared_headers": sorted(READ_ONLY_SHARED_HEADERS),
        "queue": queue,
        "groups": [tasks[name] for name in sorted(tasks)],
        "shared_files": shared,
        "unavailable": symbol_report["unavailable"],
    }
    output = repo_path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: report[key] for key in (
        "owner_count", "symbol_mismatch_count", "unavailable_symbol_count",
        "group_task_count", "queue_task_count", "maximum_concurrency",
    )}))
    print(f"Wrote {output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
