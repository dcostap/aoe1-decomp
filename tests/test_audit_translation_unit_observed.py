import sys
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from audit_translation_unit_observed import build_queue, classify  # noqa: E402


def status(bucket: str = "scratch") -> dict[str, str]:
    return {
        "source_bucket": bucket,
        "diff_result": "MISMATCH",
        "diff_bytes": "4",
    }


def comparison(
    result: str = "MISMATCH",
    difference: int = 4,
    owner: str = "match",
    relocations: int = 0,
    boundaries: int = 0,
) -> dict[str, object]:
    return {
        "result": result,
        "diff_bytes": difference,
        "owner_status": owner,
        "relocation_target_mismatches": relocations,
        "boundary_escape_count": boundaries,
    }


def test_exact_unregistered_function_enters_promotion_review() -> None:
    category, action, _ = classify(
        status(), comparison("MATCH", 0), False, False, []
    )
    assert category == "grouped_match_not_registered"
    assert action == "review_for_promotion"


def test_accepted_drift_mismatch_stays_closed() -> None:
    category, action, _ = classify(
        status("accepted_drift"), comparison(), False, False, []
    )
    assert category == "accepted_drift_observed"
    assert action == "hold_accepted_drift"


def test_zero_byte_owner_failure_becomes_ownership_task() -> None:
    category, action, _ = classify(
        status("matching"), comparison(difference=0, owner="unverified"), False, False, []
    )
    assert category == "ownership_problem"
    assert action == "investigate_ownership"


def test_relocation_failure_precedes_ordinary_codegen_work() -> None:
    category, action, _ = classify(
        status(), comparison(relocations=1), False, False, []
    )
    assert category == "relocation_problem"
    assert action == "repair_relocation_targets"


def test_boundary_failure_precedes_ordinary_codegen_work() -> None:
    category, action, _ = classify(
        status(), comparison(boundaries=1), False, False, []
    )
    assert category == "boundary_problem"
    assert action == "repair_boundary_or_classification"


def test_other_registered_context_is_not_duplicate_work() -> None:
    category, action, _ = classify(
        status("matching"), comparison(), False, True, []
    )
    assert category == "registered_elsewhere_context_mismatch"
    assert action == "review_context_ownership"


def test_queue_assigns_overlapping_va_to_largest_exact_context() -> None:
    groups = [
        {"name": "prefix", "source": "src/prefix.cpp", "owners": {}, "flags": ""},
        {"name": "complete", "source": "src/complete.cpp", "owners": {}, "flags": ""},
    ]
    base = {
        "va": "00401000",
        "name": "target",
        "source_path": "src/scratch/00401000_target.cpp",
        "source_bucket": "scratch",
        "registered_groups": [],
        "grouped_result": "MATCH",
        "grouped_diff_bytes": 0,
        "category": "grouped_match_not_registered",
        "recommended_action": "review_for_promotion",
        "difficulty_band": "0-1",
        "error": "",
    }
    rows = [
        {**base, "group": "prefix"},
        {**base, "group": "complete"},
        {
            **base,
            "group": "complete",
            "va": "00401010",
            "name": "anchor",
            "registered_groups": ["complete"],
            "registered_anywhere": True,
            "registered_in_group": True,
            "recommended_action": "none",
            "category": "registered_owner_match",
        },
    ]

    queue = build_queue(groups, rows)

    assignment = next(row for row in queue["assignments"] if row["va"] == "00401000")
    assert assignment["canonical_group"] == "complete"
    prefix = next(packet for packet in queue["packets"] if packet["group"] == "prefix")
    complete = next(packet for packet in queue["packets"] if packet["group"] == "complete")
    assert prefix["promotion_candidates"] == []
    assert [row["va"] for row in complete["promotion_candidates"]] == ["00401000"]


def test_queue_retains_exact_policy_review() -> None:
    groups = [
        {"name": "complete", "source": "src/complete.cpp", "owners": {}, "flags": ""}
    ]
    rows = [
        {
            "group": "complete",
            "va": "00401000",
            "name": "target",
            "source_path": "src/scratch/00401000_target.cpp",
            "source_bucket": "scratch",
            "registered_groups": [],
            "grouped_result": "MATCH",
            "grouped_diff_bytes": 0,
            "category": "grouped_match_policy_review",
            "recommended_action": "repair_policy_then_review_promotion",
            "difficulty_band": "0-1",
            "error": "",
        }
    ]

    queue = build_queue(groups, rows)
    complete = queue["packets"][0]

    assert [row["va"] for row in complete["promotion_policy_reviews"]] == [
        "00401000"
    ]
    assert complete["main_agent_task_count"] == 1
