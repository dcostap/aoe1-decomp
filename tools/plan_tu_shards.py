#!/usr/bin/env python3
"""Partition pending TU orchestration work into balanced conflict-free shards."""

from __future__ import annotations

import argparse
import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any


ACTIVE_STATUSES = {"assigned", "main_agent_review", "ready"}


@dataclass(frozen=True)
class GroupWork:
    name: str
    status: str
    weight: float
    captain_tasks: int
    main_agent_tasks: int
    source: str
    packet: str
    captain_id: str
    completed_runs: tuple[str, ...]


def _list_count(packet: dict[str, Any], key: str) -> int:
    value = packet.get(key, [])
    return len(value) if isinstance(value, list) else 0


def calculate_weight(state: dict[str, Any], packet: dict[str, Any] | None) -> float:
    """Estimate review and repair effort from packet task classes."""
    captain_tasks = int(state.get("captain_task_count", 0))
    main_tasks = int(state.get("main_agent_task_count", 0))
    if packet is None:
        return 2.0 + captain_tasks + 2.0 * main_tasks

    weight = 2.0
    weight += 1.0 * _list_count(packet, "codegen_repairs")
    weight += 4.0 * _list_count(packet, "structural_repairs")
    weight += 4.0 * _list_count(packet, "ownership_investigations")
    weight += 1.5 * _list_count(packet, "promotion_candidates")
    weight += 2.0 * _list_count(packet, "promotion_policy_reviews")
    weight += 4.0 * _list_count(packet, "context_ownership_reviews")
    weight += 5.0 * _list_count(packet, "comparison_errors")
    weight += 4.0 * _list_count(packet, "noncanonical_contexts")

    if state.get("status") == "assigned":
        weight *= 0.9
    return round(max(weight, 2.0), 2)


def load_group_work(
    state_path: Path,
    packet_dir: Path,
    selected_groups: set[str] | None = None,
) -> dict[str, GroupWork]:
    state_doc = json.loads(state_path.read_text(encoding="utf-8"))
    groups = state_doc.get("groups", {})
    result: dict[str, GroupWork] = {}
    for name, item in groups.items():
        if selected_groups is not None and name not in selected_groups:
            continue
        status = item.get("status", "")
        if status not in ACTIVE_STATUSES:
            continue
        packet_path = packet_dir / f"{name}.json"
        packet = None
        if packet_path.exists():
            packet = json.loads(packet_path.read_text(encoding="utf-8"))
        source = packet.get("source", "") if packet else ""
        result[name] = GroupWork(
            name=name,
            status=status,
            weight=calculate_weight(item, packet),
            captain_tasks=int(item.get("captain_task_count", 0)),
            main_agent_tasks=int(item.get("main_agent_task_count", 0)),
            source=source,
            packet=str(packet_path).replace("\\", "/") if packet else "",
            captain_id=item.get("captain_id", ""),
            completed_runs=tuple(item.get("completed_runs", [])),
        )
    return result


def conflict_components(
    groups: dict[str, GroupWork], conflicts: dict[str, list[str]]
) -> list[list[str]]:
    remaining = set(groups)
    components: list[list[str]] = []
    while remaining:
        first = min(remaining)
        remaining.remove(first)
        stack = [first]
        component = []
        while stack:
            current = stack.pop()
            component.append(current)
            for other in conflicts.get(current, []):
                if other in remaining:
                    remaining.remove(other)
                    stack.append(other)
        components.append(sorted(component))
    return components


def partition_groups(
    groups: dict[str, GroupWork],
    conflicts: dict[str, list[str]],
    shard_count: int,
    max_groups_per_shard: int = 0,
) -> list[list[str]]:
    if shard_count < 1:
        raise ValueError("shard_count must be positive")
    components = conflict_components(groups, conflicts)
    components.sort(
        key=lambda component: (
            -sum(groups[name].weight for name in component),
            component,
        )
    )
    shards: list[list[str]] = [[] for _ in range(shard_count)]
    totals = [0.0] * shard_count
    for component in components:
        eligible = [
            index
            for index in range(shard_count)
            if not max_groups_per_shard
            or len(shards[index]) + len(component) <= max_groups_per_shard
        ]
        if not eligible:
            raise ValueError(
                f"Cannot fit conflict component of {len(component)} groups "
                f"within the {max_groups_per_shard}-group shard limit"
            )
        target = min(eligible, key=lambda i: (totals[i], len(shards[i]), i))
        shards[target].extend(component)
        totals[target] += sum(groups[name].weight for name in component)
    for shard in shards:
        shard.sort()
    return shards


def write_plan(
    output_dir: Path,
    groups: dict[str, GroupWork],
    shards: list[list[str]],
    base_commit: str,
    max_concurrent_workers: int = 10,
    lead_model: str = "openai-codex-secondary/gpt-5.6-sol",
    lead_thinking: str = "medium",
    worker_model: str = "openai-codex-secondary/gpt-5.6-luna",
    worker_thinking: str = "xhigh",
) -> None:
    output_dir.mkdir(parents=True, exist_ok=True)
    index = {
        "schema": 1,
        "base_commit": base_commit,
        "shard_count": len(shards),
        "group_count": len(groups),
        "total_weight": round(sum(group.weight for group in groups.values()), 2),
        "shards": [],
    }
    lines = ["TU shard plan", ""]
    for number, names in enumerate(shards, 1):
        shard_id = f"shard_{number:02d}"
        items = [groups[name] for name in names]
        document = {
            "schema": 1,
            "shard": shard_id,
            "base_commit": base_commit,
            "max_concurrent_workers": max_concurrent_workers,
            "lead_model": lead_model,
            "lead_thinking": lead_thinking,
            "worker_model": worker_model,
            "worker_thinking": worker_thinking,
            "weight": round(sum(item.weight for item in items), 2),
            "groups": [item.__dict__ for item in items],
        }
        path = output_dir / f"{shard_id}.json"
        path.write_text(json.dumps(document, indent=2) + "\n", encoding="utf-8")
        index["shards"].append(
            {
                "shard": shard_id,
                "weight": document["weight"],
                "group_count": len(items),
                "manifest": str(path).replace("\\", "/"),
            }
        )
        lines.append(f"{shard_id}: {len(items)} groups, weight {document['weight']:.2f}")

    (output_dir / "index.json").write_text(
        json.dumps(index, indent=2) + "\n", encoding="utf-8"
    )
    (output_dir / "summary.txt").write_text("\n".join(lines) + "\n", encoding="utf-8")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--state", type=Path, required=True)
    parser.add_argument("--dependencies", type=Path, required=True)
    parser.add_argument("--packet-dir", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--shards", type=int, default=5)
    parser.add_argument("--base-commit", default="")
    parser.add_argument(
        "--ready-wave-only",
        action="store_true",
        help="Partition only the conflict-free ready_wave from the state file.",
    )
    parser.add_argument("--max-groups-per-shard", type=int, default=0)
    parser.add_argument("--max-concurrent-workers", type=int, default=10)
    parser.add_argument(
        "--lead-model", default="openai-codex-secondary/gpt-5.6-sol"
    )
    parser.add_argument("--lead-thinking", default="medium")
    parser.add_argument(
        "--worker-model", default="openai-codex-secondary/gpt-5.6-luna"
    )
    parser.add_argument("--worker-thinking", default="xhigh")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    selected_groups = None
    if args.ready_wave_only:
        state_doc = json.loads(args.state.read_text(encoding="utf-8"))
        selected_groups = {str(name) for name in state_doc.get("ready_wave", [])}
    groups = load_group_work(args.state, args.packet_dir, selected_groups)
    dependencies = json.loads(args.dependencies.read_text(encoding="utf-8"))
    conflicts = dependencies.get("conflicts", {})
    shards = partition_groups(
        groups, conflicts, args.shards, args.max_groups_per_shard
    )
    write_plan(
        args.output_dir,
        groups,
        shards,
        args.base_commit,
        args.max_concurrent_workers,
        args.lead_model,
        args.lead_thinking,
        args.worker_model,
        args.worker_thinking,
    )
    print(f"Planned {len(groups)} groups across {len(shards)} shards.")
    for number, names in enumerate(shards, 1):
        weight = sum(groups[name].weight for name in names)
        print(f"shard_{number:02d}: {len(names)} groups, weight {weight:.2f}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
