import json
from pathlib import Path

from tools.plan_tu_shards import (
    GroupWork,
    calculate_weight,
    conflict_components,
    partition_groups,
)


def group(name: str, weight: float) -> GroupWork:
    return GroupWork(name, "ready", weight, 1, 0, "", "", "", ())


def test_weight_prioritizes_structural_work() -> None:
    state = {"status": "ready", "captain_task_count": 2, "main_agent_task_count": 0}
    simple = {"codegen_repairs": [{}, {}]}
    structural = {"structural_repairs": [{}, {}]}
    assert calculate_weight(state, structural) > calculate_weight(state, simple)


def test_conflicting_groups_stay_in_one_component() -> None:
    groups = {name: group(name, 1.0) for name in ("a", "b", "c")}
    conflicts = {"a": ["b"], "b": ["a"], "c": []}
    assert sorted(conflict_components(groups, conflicts)) == [["a", "b"], ["c"]]


def test_partition_is_deterministic_and_keeps_conflicts_together() -> None:
    groups = {
        "a": group("a", 8.0),
        "b": group("b", 4.0),
        "c": group("c", 3.0),
        "d": group("d", 2.0),
    }
    conflicts = {"a": [], "b": ["c"], "c": ["b"], "d": []}
    first = partition_groups(groups, conflicts, 2)
    second = partition_groups(groups, conflicts, 2)
    assert first == second
    assert any("b" in shard and "c" in shard for shard in first)
    assert sorted(name for shard in first for name in shard) == sorted(groups)
