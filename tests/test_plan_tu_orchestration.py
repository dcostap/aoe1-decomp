import sys
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from plan_tu_orchestration import (  # noqa: E402
    apply_state_changes,
    build_dependencies,
    build_state,
    captain_prompt,
    compare_reports,
    select_ready_wave,
)


def row(
    group: str = "alpha",
    va: str = "00401000",
    result: str = "MISMATCH",
    difference: int = 4,
    bucket: str = "scratch",
    registered: bool = False,
    owner: str = "match",
    relocations: int = 0,
    boundaries: int = 0,
) -> dict[str, object]:
    return {
        "group": group,
        "va": va,
        "grouped_result": result,
        "grouped_diff_bytes": difference,
        "source_bucket": bucket,
        "registered_in_group": registered,
        "owner_status": owner,
        "relocation_target_mismatches": relocations,
        "boundary_escape_count": boundaries,
        "category": "grouped_mismatch",
    }


def report(*rows: dict[str, object]) -> dict[str, object]:
    return {"rows": list(rows), "compile_errors": []}


def packet(
    group: str,
    files: list[str],
    captain_tasks: int = 1,
    main_tasks: int = 0,
) -> dict[str, object]:
    return {
        "group": group,
        "source": f"src/{group}.cpp",
        "flags": "config/flags/default.rsp",
        "captain_editable_files": files,
        "captain_task_count": captain_tasks,
        "main_agent_task_count": main_tasks,
        "accepted_drift_holds": [],
    }


def test_delta_reports_new_exact_without_blocking_it() -> None:
    delta = compare_reports(
        report(row()),
        report(row(result="MATCH", difference=0)),
    )

    assert delta["gate"] == "PASS"
    assert [event["kind"] for event in delta["events"]] == ["new_exact"]


def test_registered_exact_loss_blocks_integration() -> None:
    delta = compare_reports(
        report(row(result="MATCH", difference=0, registered=True)),
        report(row(result="MISMATCH", difference=1, registered=True)),
    )

    assert delta["gate"] == "FAIL"
    assert any(item["kind"] == "protected_exact_lost" for item in delta["regressions"])


def test_approved_promotion_loss_blocks_integration() -> None:
    delta = compare_reports(
        report(row(result="MATCH", difference=0)),
        report(row(result="MISMATCH", difference=1)),
        {"00401000"},
    )

    assert delta["gate"] == "FAIL"
    assert any(item["kind"] == "protected_exact_lost" for item in delta["regressions"])


def test_accepted_drift_change_blocks_integration() -> None:
    delta = compare_reports(
        report(row(bucket="accepted_drift", difference=4)),
        report(row(bucket="accepted_drift", difference=3)),
    )

    assert delta["gate"] == "FAIL"
    assert any(item["kind"] == "accepted_drift_changed" for item in delta["regressions"])


def test_new_boundary_escape_blocks_integration() -> None:
    delta = compare_reports(
        report(row(boundaries=0)),
        report(row(boundaries=1)),
    )

    assert delta["gate"] == "FAIL"
    assert any(item["kind"] == "structural_regression" for item in delta["regressions"])


def test_dependencies_find_shared_editable_files() -> None:
    queue = {
        "packets": [
            packet("alpha", ["src/shared.cpp", "src/alpha.cpp"]),
            packet("beta", ["src/shared.cpp"]),
            packet("gamma", ["src/gamma.cpp"]),
        ]
    }

    dependencies = build_dependencies(queue)

    assert dependencies["shared_editable_files"] == [
        {"source_path": "src/shared.cpp", "groups": ["alpha", "beta"]}
    ]
    assert dependencies["conflicts"]["alpha"] == ["beta"]
    assert dependencies["conflicts"]["gamma"] == []


def test_state_preserves_captain_and_blocks_shared_repair() -> None:
    queue = {"packets": [packet("alpha", ["src/alpha.cpp"])]}
    prior = {
        "groups": {
            "alpha": {
                "captain_id": "sa-old",
                "completed_runs": ["run-1"],
                "approved_promotions": ["00401000"],
            }
        }
    }

    state = build_state(
        queue,
        "build/audits/tu_orchestration/report.json",
        prior,
        blockers={"alpha": "canonical layout review"},
    )
    alpha = state["groups"]["alpha"]

    assert alpha["captain_id"] == "sa-old"
    assert alpha["completed_runs"] == ["run-1"]
    assert alpha["approved_promotions"] == ["00401000"]
    assert alpha["status"] == "blocked_shared"


def test_state_assigns_ready_tu_without_activating_it() -> None:
    queue = {"packets": [packet("alpha", ["src/alpha.cpp"])]}

    state = build_state(
        queue,
        "build/audits/tu_orchestration/report.json",
        assignments={"alpha": "sa-new"},
    )

    assert state["groups"]["alpha"]["captain_id"] == "sa-new"
    assert state["groups"]["alpha"]["status"] == "assigned"


def test_compile_error_precedes_ready_state() -> None:
    queue = {"packets": [packet("alpha", ["src/alpha.cpp"])]}

    state = build_state(
        queue,
        "build/audits/tu_orchestration/report.json",
        compile_error_groups={"alpha"},
    )

    assert state["groups"]["alpha"]["status"] == "compile_error"


def test_prompt_forbids_local_raw_offset_workaround() -> None:
    text = captain_prompt(packet("alpha", ["src/alpha.cpp"]))

    assert "persistent repair captain" in text
    assert "Do not hide shared layout defects with raw local offsets." in text
    assert "A clean partial result is valid." in text


def test_state_changes_preserve_approval_and_finished_run() -> None:
    prior = {"groups": {"alpha": {"active_run_id": "run-1"}}}

    changed = apply_state_changes(
        prior,
        [("alpha", "00401000")],
        set(),
        [("alpha", "run-1")],
        [],
    )
    alpha = changed["groups"]["alpha"]

    assert alpha["approved_promotions"] == ["00401000"]
    assert alpha["completed_runs"] == ["run-1"]
    assert alpha["active_run_id"] == ""
    assert alpha["pending_validation"] is True


def test_ready_wave_uses_priority_and_avoids_conflicts() -> None:
    alpha = packet("alpha", ["src/shared.cpp"])
    alpha["structural_repairs"] = [{"category": "boundary_problem"}]
    alpha["ownership_investigations"] = []
    alpha["codegen_repairs"] = []
    beta = packet("beta", ["src/shared.cpp"])
    beta["structural_repairs"] = []
    beta["ownership_investigations"] = []
    beta["codegen_repairs"] = [{"grouped_diff_bytes": 1}]
    gamma = packet("gamma", ["src/gamma.cpp"])
    gamma["structural_repairs"] = []
    gamma["ownership_investigations"] = []
    gamma["codegen_repairs"] = [{"grouped_diff_bytes": 2}]
    queue = {"packets": [alpha, beta, gamma]}
    state = {
        "groups": {
            group: {"status": "ready"} for group in ("alpha", "beta", "gamma")
        }
    }
    dependencies = build_dependencies(queue)

    wave = select_ready_wave(queue, state, dependencies, 40)

    assert wave == ["alpha", "gamma"]


def test_ready_wave_respects_active_conflict_lock() -> None:
    alpha = packet("alpha", ["src/shared.cpp"])
    beta = packet("beta", ["src/shared.cpp"])
    for item in (alpha, beta):
        item["structural_repairs"] = []
        item["ownership_investigations"] = []
        item["codegen_repairs"] = [{"grouped_diff_bytes": 1}]
    queue = {"packets": [alpha, beta]}
    state = {
        "groups": {
            "alpha": {"status": "active"},
            "beta": {"status": "ready"},
        }
    }
    dependencies = build_dependencies(queue)

    assert select_ready_wave(queue, state, dependencies, 40) == []
