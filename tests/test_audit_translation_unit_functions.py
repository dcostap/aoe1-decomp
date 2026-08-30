import sys
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from audit_translation_unit_functions import build_queue, classify  # noqa: E402


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


def test_exact_nonmatching_function_enters_promotion_review() -> None:
    category, action, _ = classify(
        status(), comparison("MATCH", 0), False, False, []
    )
    assert category == "grouped_match_needs_review"
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


def test_missing_normal_symbol_becomes_structural_captain_work() -> None:
    category, action, _ = classify(
        status(), comparison("NOT_EMITTED", 0, owner="error"), False, False, []
    )
    assert category == "missing_grouped_symbol"
    assert action == "repair_missing_symbol"


def test_missing_accepted_drift_symbol_stays_closed() -> None:
    category, action, _ = classify(
        status("accepted_drift"),
        comparison("NOT_EMITTED", 0, owner="error"),
        False,
        False,
        [],
    )
    assert category == "accepted_drift_not_emitted"
    assert action == "hold_accepted_drift"


def test_other_matching_context_is_not_duplicate_work() -> None:
    category, action, _ = classify(
        status("matching"), comparison(), False, True, []
    )
    assert category == "matching_elsewhere_mismatch"
    assert action == "review_context_ownership"


def test_queue_assigns_overlapping_va_to_largest_exact_context() -> None:
    groups = [
        {"name": "prefix", "source": "src/prefix.cpp", "build": {"flags_path": "config/flags/default.rsp"}},
        {"name": "complete", "source": "src/complete.cpp", "build": {"flags_path": "config/flags/default.rsp"}},
    ]
    base = {
        "va": "00401000",
        "name": "target",
        "source_path": "src/00401000_target.cpp",
        "source_bucket": "scratch",
        "matching_groups": [],
        "grouped_result": "MATCH",
        "grouped_diff_bytes": 0,
        "category": "grouped_match_needs_review",
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
            "matching_groups": ["complete"],
            "matching_anywhere": True,
            "matching_in_group": True,
            "recommended_action": "none",
            "category": "matching_result",
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
        {"name": "complete", "source": "src/complete.cpp", "build": {"flags_path": "config/flags/default.rsp"}}
    ]
    rows = [
        {
            "group": "complete",
            "va": "00401000",
            "name": "target",
            "source_path": "src/00401000_target.cpp",
            "source_bucket": "scratch",
            "matching_groups": [],
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
