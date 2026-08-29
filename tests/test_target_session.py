from __future__ import annotations

import copy
import json
import sys
import tempfile
import unittest
from contextlib import contextmanager
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import target_session  # noqa: E402


class TargetSessionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.record = {
            "va": "00001000",
            "name": "demo",
            "size_bytes": "64",
            "calling_convention": "__thiscall",
            "pdb_source_file": "demo.cpp",
        }

    def test_active_lease_rejects_other_owner_then_allows_paused_takeover(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                first = target_session.start_session(self.record, "AgentA", 4, 2.0)
                self.assertTrue(target_session._lease_active(first))
                with self.assertRaises(RuntimeError):
                    target_session.start_session(self.record, "AgentB", 4, 2.0)
                target_session.change_state(self.record, "AgentA", "pause", "needs ABI facts")
                second = target_session.start_session(self.record, "AgentB", 6, 2.0)
                self.assertEqual(second["owner"], "AgentB")
                self.assertEqual(second["probe_start_index"], len(second["probes"]))
                self.assertTrue(any(event["kind"] == "takeover" for event in second["events"]))

    def test_metric_and_snapshot_work_stays_outside_the_global_lock(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            lock_depth = 0

            @contextmanager
            def checked_lock():
                nonlocal lock_depth
                lock_depth += 1
                try:
                    yield
                finally:
                    lock_depth -= 1

            def require_unlocked(*_args, **_kwargs):
                self.assertEqual(lock_depth, 0)
                return {}

            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "_sessions_lock", checked_lock),
                patch.object(target_session, "current_metric_summary", require_unlocked),
                patch.object(target_session, "current_output_snapshot", require_unlocked),
                patch.object(target_session, "current_input_snapshot", require_unlocked),
            ):
                target_session.start_session(self.record, "AgentA", 4, 2.0)
                target_session.record_probe(
                    self.record,
                    "AgentA",
                    "abi",
                    "checked outside lock",
                )

    def test_active_same_owner_start_renews_without_adding_a_claim(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                first = target_session.start_session(self.record, "AgentA", 4, 2.0)
                second = target_session.start_session(self.record, "AgentA", 4, 2.0)
        self.assertEqual(target_session.session_claim_count(first), 1)
        self.assertEqual(target_session.session_claim_count(second), 1)

    def test_active_translation_unit_rejects_another_target(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 4, 2.0)
                with self.assertRaisesRegex(RuntimeError, "translation unit"):
                    target_session.start_session(other_record, "AgentB", 4, 2.0)

    def test_compact_summary_preserves_status_aggregates(self) -> None:
        session = {
            "va": "00001000",
            "owner": "AgentB",
            "state": "pause",
            "probe_start_index": 1,
            "events": [{"kind": "start"}, {"kind": "takeover"}],
            "probes": [
                {"number": 1, "kind": "baseline", "meaningful": True, "metrics": {"diff_bytes": 12}},
                {
                    "number": 2,
                    "kind": "liveness",
                    "meaningful": True,
                    "at": "2026-08-02T10:00:00Z",
                    "metrics": {"diff_bytes": 8},
                    "metric_delta": {"diff_bytes": {"direction": "improved"}},
                },
                {"number": 3, "kind": "validation", "meaningful": False, "metrics": {"diff_bytes": 9}},
            ],
            "last_metric_summary": {"diff_bytes": 9},
            "clean_baseline": {"checkpoint_id": "clean"},
        }
        summary = target_session.target_session_summary(session)
        self.assertNotIn("probes", summary)
        self.assertEqual(target_session.meaningful_probe_count(summary), 1)
        self.assertEqual(target_session.meaningful_probe_count(summary, current_claim_only=False), 2)
        self.assertEqual(target_session.session_claim_count(summary), 2)
        self.assertEqual(summary["best_diff_bytes"], 8)
        self.assertEqual(target_session.last_positional_improvement(summary)["number"], 2)

    def test_bounded_summary_load_reads_only_requested_session(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            sessions = root / "build" / "target_sessions"
            sessions.mkdir(parents=True)
            for va in ("00001000", "00002000"):
                (sessions / f"{va}_demo.json").write_text(
                    json.dumps({"va": va, "owner": va, "state": "pause", "probes": []}),
                    encoding="utf-8",
                )
            with patch.object(target_session, "REPO_ROOT", root):
                rows = target_session.load_target_sessions({"00001000"})
                index_exists = target_session._session_index_path().exists()
        self.assertEqual([row["va"] for row in rows], ["00001000"])
        self.assertFalse(index_exists)

    def test_broad_summary_index_repairs_after_external_session_change(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            sessions = root / "build" / "target_sessions"
            sessions.mkdir(parents=True)
            path = sessions / "00001000_demo.json"
            path.write_text(
                json.dumps({"va": "00001000", "owner": "AgentA", "state": "pause", "probes": []}),
                encoding="utf-8",
            )
            with patch.object(target_session, "REPO_ROOT", root):
                first = target_session.load_target_sessions()
                path.write_text(
                    json.dumps(
                        {
                            "va": "00001000",
                            "owner": "AgentA",
                            "state": "pause",
                            "probes": [{"kind": "baseline", "meaningful": True}],
                        }
                    ),
                    encoding="utf-8",
                )
                second = target_session.load_target_sessions()
        self.assertEqual(first[0]["meaningful_probe_total"], 0)
        self.assertEqual(second[0]["meaningful_probe_total"], 1)

    def test_probe_snapshots_current_metrics_and_counts_meaningful_attempts(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            slug = "00001000_demo"
            diff_dir = root / "build" / "diff"
            diff_dir.mkdir(parents=True)
            (diff_dir / f"{slug}.json").write_text(
                json.dumps(
                    {
                        "result": "MISMATCH",
                        "diff_bytes": 10,
                        "diff_percent": 15.625,
                        "first_mismatch_offset": "4",
                        "instruction_shape": {"similarity_percent": 90.0},
                        "call_alignment": {"similarity_percent": 100.0, "aligned_prefix_calls": 3},
                        "call_site_status_counts": {"equal": 3, "delete": 1, "insert": 1, "replace": 0},
                        "call_target_count_deltas": [],
                        "block_alignment": {"matched_coverage_percent": 75.0},
                        "rebuilt_extraction": {
                            "effective_size_bytes": 61,
                            "relocations": [{"offset": 4, "type": "0x0014", "width": 4, "symbol_name": "_demo"}],
                        },
                        "original_size": 64,
                        "edit_diff_bytes": 6,
                        "edit_diff_percent": 9.375,
                        "original_prologue": {"frame_size": 8},
                        "rebuilt_prologue": {"frame_size": 8},
                    }
                ),
                encoding="utf-8",
            )
            with patch.object(target_session, "REPO_ROOT", root):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                session = target_session.record_probe(
                    self.record, "AgentA", "control-flow", "inverted the final guard", "guard-v1"
                )
                self.assertEqual(len(session["probes"]), 1)
                self.assertEqual(session["probes"][0]["metrics"]["diff_bytes"], 10)
                self.assertEqual(session["probes"][0]["checkpoint"], "guard-v1")
                self.assertEqual(session["probes"][0]["metrics"]["meaningful_rebuilt_size"], 61)
                self.assertEqual(session["probes"][0]["metrics"]["call_deleted_sites"], 1)
                self.assertEqual(session["probes"][0]["metrics"]["exact_block_coverage_percent"], 75.0)

    def test_input_snapshot_records_complete_grouped_build_fingerprint(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "demo_unit_tu.cpp"
            flags = root / "config" / "flags" / "demo.rsp"
            source.parent.mkdir(parents=True)
            flags.parent.mkdir(parents=True)
            source.write_text("int demo;\n", encoding="utf-8")
            flags.write_text("/O2\n", encoding="utf-8")
            expected_flags_hash = target_session._sha256(flags)
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session, "compiler_source_path", return_value=source
            ), patch.object(
                target_session, "preferred_flags_rsp_path", return_value=flags
            ), patch.object(
                target_session, "load_toolchain",
                return_value={"compiler": {"default_rsp": "config/flags/default.rsp"}},
            ), patch.object(
                target_session,
                "build_input_manifest",
                return_value={"fingerprint": "complete-build-fingerprint"},
            ):
                snapshot = target_session.current_input_snapshot(self.record)

        self.assertEqual(str(snapshot["source_path"]).replace("\\", "/"), "src/demo_unit_tu.cpp")
        self.assertEqual(snapshot["flags_sha256"], expected_flags_hash)
        self.assertEqual(snapshot["build_input_fingerprint"], "complete-build-fingerprint")

    def test_stage_classification_prioritizes_calls_then_frame_then_shape(self) -> None:
        self.assertIn(
            "stale",
            target_session.classify_next_stage({"artifact_fresh": False, "call_target_count_gap": 1}),
        )
        self.assertIn("Behavior/ABI", target_session.classify_next_stage({"call_target_count_gap": 1}))
        self.assertIn(
            "Stack/local",
            target_session.classify_next_stage(
                {"call_target_count_gap": 0, "wrong_direct_targets": 0, "original_frame": 8, "rebuilt_frame": 12}
            ),
        )
        self.assertIn(
            "Structural",
            target_session.classify_next_stage(
                {"call_target_count_gap": 0, "wrong_direct_targets": 0, "shape_percent": 50}
            ),
        )
        self.assertIn(
            "Structural reconstruction",
            target_session.classify_next_stage(
                {
                    "workflow_stage": "STRUCTURAL RECONSTRUCTION",
                    "shape_percent": 90,
                    "call_target_count_gap": 0,
                    "call_deleted_sites": 2,
                    "call_inserted_sites": 2,
                }
            ),
        )
        self.assertNotIn(
            "Focused codegen",
            target_session.classify_next_stage(
                {"workflow_stage": "STRUCTURAL RECONSTRUCTION", "shape_percent": 90}
            ),
        )

    def test_metric_delta_labels_lower_diff_and_higher_shape_as_improvements(self) -> None:
        delta = target_session.metric_delta(
            {"diff_bytes": 8, "shape_percent": 90.0},
            {"diff_bytes": 10, "shape_percent": 80.0},
        )
        self.assertEqual(delta["diff_bytes"]["direction"], "improved")
        self.assertEqual(delta["shape_percent"]["direction"], "improved")

    def test_checked_probe_runs_checker_and_records_checkpoint(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                with patch.object(
                    target_session.subprocess, "run", return_value=SimpleNamespace(returncode=1)
                ) as run, patch.object(
                    target_session, "checkpoint_info", return_value={"id": "probe"}
                ), patch.object(
                    target_session, "record_probe", return_value={"owner": "AgentA"}
                ) as record:
                    code, session = target_session.run_checked_probe(
                        self.record,
                        "AgentA",
                        "layout",
                        "changed local order",
                        "",
                        ["--detail", "concise"],
                    )
            self.assertEqual(code, 1)
            self.assertEqual(session["owner"], "AgentA")
            command = run.call_args.args[0]
            self.assertIn("probe-001-layout", command)
            record.assert_called_once()

    def test_checked_probe_rejects_managed_checker_arguments(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                with self.assertRaisesRegex(ValueError, "managed"):
                    target_session.run_checked_probe(
                        self.record, "AgentA", "layout", "note", "", ["--no-history"]
                    )

    def test_checked_probe_does_not_record_an_incomplete_checker_run(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                with (
                    patch.object(
                        target_session.subprocess,
                        "run",
                        return_value=SimpleNamespace(returncode=1),
                    ),
                    patch.object(target_session, "checkpoint_info", return_value=None),
                    patch.object(target_session, "record_probe") as record,
                ):
                    with self.assertRaisesRegex(RuntimeError, "did not complete"):
                        target_session.run_checked_probe(
                            self.record, "AgentA", "layout", "note", "", []
                        )
            record.assert_not_called()

    def test_checked_baseline_automatically_pins_clean_source(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            recorded = {"owner": "AgentA", "probes": [{"number": 1}]}
            pinned = {"owner": "AgentA", "clean_baseline": {"checkpoint_id": "clean"}}
            with patch.object(target_session, "REPO_ROOT", root):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                with patch.object(
                    target_session.subprocess, "run", return_value=SimpleNamespace(returncode=1)
                ), patch.object(
                    target_session, "checkpoint_info", return_value={"id": "probe"}
                ), patch.object(
                    target_session, "record_probe", return_value=recorded
                ), patch.object(
                    target_session, "pin_clean_baseline", return_value=pinned
                ) as pin:
                    _code, session = target_session.run_checked_probe(
                        self.record,
                        "AgentA",
                        "baseline",
                        "canonical fields and natural loop",
                        "",
                        [],
                    )
            self.assertEqual(session, pinned)
            pin.assert_called_once_with(
                self.record,
                "AgentA",
                "canonical fields and natural loop",
            )

    def test_checked_probe_compares_against_pinned_clean_source(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                session = target_session._load_session(self.record)
                session["clean_baseline"] = {"checkpoint_id": "clean-id"}
                target_session._write_session(self.record, session)
                with patch.object(
                    target_session.subprocess, "run", return_value=SimpleNamespace(returncode=1)
                ) as run, patch.object(
                    target_session, "checkpoint_info", return_value={"id": "probe"}
                ), patch.object(
                    target_session,
                    "record_probe",
                    return_value={"owner": "AgentA"},
                ):
                    target_session.run_checked_probe(
                        self.record,
                        "AgentA",
                        "liveness",
                        "localized experiment",
                        "",
                        [],
                    )
            command = run.call_args.args[0]
            compare_index = command.index("--compare-checkpoint")
            self.assertEqual(command[compare_index + 1], target_session.CLEAN_CHECKPOINT_LABEL)

    def test_duplicate_emitted_code_is_linked_to_earlier_probe(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            rebuilt = root / "build" / "asm" / "rebuilt_00001000_demo.bin"
            rebuilt.parent.mkdir(parents=True)
            rebuilt.write_bytes(b"\xC3")
            metrics = {
                "result": "MISMATCH",
                "meaningful_rebuilt_size": 1,
                "relocation_identity_sha256": "none",
            }
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session, "current_metric_summary", return_value=metrics
            ) as metric_summary, patch.object(target_session, "current_input_snapshot", return_value={}):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                first = target_session.record_probe(self.record, "AgentA", "baseline", "first")
                second = target_session.record_probe(self.record, "AgentA", "liveness", "same code")
                metric_summary.return_value = {
                    **metrics,
                    "relocation_identity_sha256": "different-call-symbol",
                }
                third = target_session.record_probe(self.record, "AgentA", "abi", "same bytes, new symbol")
            self.assertIsNone(first["probes"][0]["same_emitted_code_as_probe"])
            self.assertEqual(second["probes"][1]["same_emitted_code_as_probe"], 1)
            self.assertIsNone(third["probes"][2]["same_emitted_code_as_probe"])

    def test_pause_note_is_alias_for_reason_and_baseline_is_valid(self) -> None:
        self.assertIn("baseline", target_session.PROBE_KINDS)
        self.assertIn("validation", target_session.PROBE_KINDS)
        argv = [
            "target_session.py",
            "pause",
            "--va",
            "00001000",
            "--owner",
            "AgentA",
            "--note",
            "bounded stop",
        ]
        with patch.object(sys, "argv", argv):
            args = target_session.parse_args()
        self.assertEqual(args.reason, "bounded stop")

    def test_restore_and_validation_checks_do_not_consume_meaningful_budget(self) -> None:
        session = {
            "probe_start_index": 1,
            "probes": [
                {"kind": "baseline", "meaningful": True},
                {"kind": "control-flow", "meaningful": True},
                {"kind": "restore", "meaningful": False},
                {"kind": "validation", "meaningful": False},
            ],
        }
        self.assertEqual(target_session.meaningful_probe_count(session), 1)
        self.assertEqual(
            target_session.meaningful_probe_count(session, current_claim_only=False),
            2,
        )

    def test_variant_evidence_can_be_recorded_without_baseline_duplicate_notice(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            rebuilt = root / "build" / "asm" / "rebuilt_00001000_demo.bin"
            rebuilt.parent.mkdir(parents=True)
            rebuilt.write_bytes(b"\xC3")
            metrics = {
                "result": "MISMATCH",
                "meaningful_rebuilt_size": 1,
                "relocation_identity_sha256": "none",
            }
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session, "current_metric_summary", return_value=metrics
            ), patch.object(target_session, "current_input_snapshot", return_value={}):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                target_session.record_probe(self.record, "AgentA", "baseline", "first")
                session = target_session.record_probe(
                    self.record,
                    "AgentA",
                    "variant",
                    "four-case copy lab",
                    evidence={"kind": "variant_lab", "variants": 4},
                    detect_output_duplicate=False,
                )
            probe = session["probes"][-1]
            self.assertTrue(probe["meaningful"])
            self.assertEqual(probe["evidence"]["variants"], 4)
            self.assertIsNone(probe["same_emitted_code_as_probe"])

    def test_pause_requires_a_current_final_validation_after_checks_exist(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            fresh_metrics = {"result": "MISMATCH", "artifact_fresh": True}
            snapshot = {"source_sha256": "current"}
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session, "current_metric_summary", return_value=fresh_metrics
            ), patch.object(
                target_session, "current_input_snapshot", return_value=snapshot
            ):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                seeded = target_session._load_session(self.record)
                seeded["clean_baseline"] = {"inputs": snapshot, "checkpoint_id": "clean-1"}
                target_session._write_session(self.record, seeded)
                target_session.record_probe(
                    self.record, "AgentA", "control-flow", "changed guard"
                )
                with self.assertRaisesRegex(RuntimeError, "--kind validation"):
                    target_session.change_state(
                        self.record, "AgentA", "pause", "bounded stop"
                    )
                target_session.record_probe(
                    self.record, "AgentA", "validation", "final current check"
                )
                paused = target_session.change_state(
                    self.record, "AgentA", "pause", "bounded stop"
                )
            self.assertEqual(paused["state"], "pause")

    def test_pin_clean_records_existing_checkpoint_and_current_inputs(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            snapshot = {"source_sha256": "clean", "flags_sha256": "flags"}
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session,
                "current_metric_summary",
                return_value={"result": "MISMATCH", "artifact_fresh": True, "diff_bytes": 12},
            ), patch.object(
                target_session, "current_input_snapshot", return_value=snapshot
            ), patch.object(
                target_session,
                "record_checkpoint",
                return_value={"id": "checkpoint-clean"},
            ):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                session = target_session.pin_clean_baseline(
                    self.record,
                    "AgentA",
                    "canonical fields and natural indexed loop",
                )
            baseline = session["clean_baseline"]
            self.assertEqual(baseline["checkpoint_id"], "checkpoint-clean")
            self.assertEqual(baseline["inputs"], snapshot)
            self.assertIn("natural indexed loop", baseline["note"])

    def test_grouped_exact_release_rejects_changed_sibling_context(self) -> None:
        current_context = {
            "fingerprint": "current-build",
            "translation_unit": {
                "name": "demo_unit",
                "source": "src/demo_unit_tu.cpp",
                "flags": "config/flags/demo.rsp",
                "owners": {
                    "00001000": "src/matching/00001000_demo.cpp",
                    "00001010": "src/matching/00001010_other.cpp",
                },
                "symbols": {"00001010": "?other@@YAHXZ"},
            },
            "inputs": [
                {"path": "src/demo_unit_tu.cpp", "sha256": "wrapper"},
                {"path": "src/matching/00001000_demo.cpp", "sha256": "target"},
                {"path": "src/matching/00001010_other.cpp", "sha256": "other"},
                {"path": "config/flags/demo.rsp", "sha256": "flags"},
            ],
        }
        stale_checkpoint = {"build_context": copy.deepcopy(current_context)}
        stale_checkpoint["build_context"]["translation_unit"]["owners"]["00001010"] = (
            "src/matching/00001010_old.cpp"
        )
        metrics = {
            "result": "MATCH",
            "artifact_fresh": True,
            "build_input_fingerprint": "current-build",
            "owning_symbol_validation": {"status": "match", "expected_owner": "Demo"},
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session, "current_metric_summary", return_value=metrics
            ), patch.object(
                target_session, "current_input_snapshot", return_value={"build_input_fingerprint": "current-build"}
            ), patch.object(
                target_session, "current_build_context", return_value=current_context
            ), patch.object(
                target_session, "checkpoint_info", return_value=stale_checkpoint
            ):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                session = target_session._load_session(self.record)
                session["probes"] = [{"number": 1, "checkpoint": "exact-check"}]
                target_session._write_session(self.record, session)
                with self.assertRaisesRegex(RuntimeError, "translation-unit owners"):
                    target_session.change_state(self.record, "AgentA", "release", "exact result")

    def test_pause_rejects_unresolved_source_without_clean_baseline(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            snapshot = {"source_sha256": "validated"}
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session,
                "current_metric_summary",
                return_value={"result": "MISMATCH", "artifact_fresh": True},
            ), patch.object(
                target_session, "current_input_snapshot", return_value=snapshot
            ):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                target_session.record_probe(
                    self.record, "AgentA", "validation", "final current check"
                )
                with self.assertRaisesRegex(RuntimeError, "clean-source baseline"):
                    target_session.change_state(
                        self.record, "AgentA", "pause", "bounded stop"
                    )

    def test_release_cannot_bypass_unresolved_pause_contract(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session,
                "current_metric_summary",
                return_value={"result": "MISMATCH", "artifact_fresh": True},
            ), patch.object(target_session, "current_input_snapshot", return_value={}):
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                target_session.record_probe(self.record, "AgentA", "baseline", "first")
                with self.assertRaisesRegex(RuntimeError, "pin-clean, and pause"):
                    target_session.change_state(
                        self.record, "AgentA", "release", "stop"
                    )

    def test_pause_rejects_changes_after_final_validation(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            snapshot = {"source_sha256": "validated"}
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session,
                "current_metric_summary",
                return_value={"result": "MISMATCH", "artifact_fresh": True},
            ), patch.object(
                target_session, "current_input_snapshot", return_value=snapshot
            ) as inputs:
                target_session.start_session(self.record, "AgentA", 2, 2.0)
                target_session.record_probe(
                    self.record, "AgentA", "validation", "final current check"
                )
                inputs.return_value = {"source_sha256": "changed-comments"}
                with self.assertRaisesRegex(RuntimeError, "changed after"):
                    target_session.change_state(
                        self.record, "AgentA", "pause", "bounded stop"
                    )


    def test_history_lists_checker_runs_and_notebook_probes_newest_first(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            slug = "00001000_demo"
            session_dir = root / "build" / "target_sessions"
            history_dir = root / "build" / "history" / slug
            session_dir.mkdir(parents=True)
            history_dir.mkdir(parents=True)
            with patch.object(target_session, "REPO_ROOT", root):
                target_session._write_session(
                    self.record,
                    {
                        "va": "00001000",
                        "name": "demo",
                        "slug": slug,
                        "owner": "AgentA",
                        "state": "pause",
                        "claimed_at": "2026-08-02T10:00:00Z",
                        "updated_at": "2026-08-02T11:00:00Z",
                        "lease_expires_at": "2026-08-02T12:00:00Z",
                        "lease_hours": 2.0,
                        "meaningful_probe_budget": 4,
                        "probe_start_index": 0,
                        "probes": [
                            {"number": 1, "kind": "baseline", "at": "2026-08-02T10:01:00Z",
                             "checkpoint": "probe-001-baseline", "note": "first probe"},
                            {"number": 2, "kind": "abi", "at": "2026-08-02T10:30:00Z",
                             "checkpoint": "probe-002-abi", "note": "second probe"},
                        ],
                    },
                )
                (history_dir / "history.json").write_text(
                    json.dumps(
                        {
                            "version": 1,
                            "slug": slug,
                            "labels": {"probe-001-baseline": "run-a", "probe-002-abi": "run-b"},
                            "runs": [
                                {"id": "run-a", "timestamp": "2026-08-02T10:01:00Z",
                                 "labels": ["probe-001-baseline"], "custom_flags": False,
                                 "source_path": "src/scratch/demo.cpp",
                                 "summary": {"result": "MISMATCH", "diff_bytes": 10,
                                             "diff_percent": 15.6, "resync_similarity_percent": 80.0}},
                                {"id": "run-b", "timestamp": "2026-08-02T10:30:00Z",
                                 "labels": ["probe-002-abi"], "custom_flags": True,
                                 "source_path": "src/scratch/demo.cpp",
                                 "summary": {"result": "MATCH", "diff_bytes": 0,
                                             "diff_percent": 0.0, "resync_similarity_percent": 100.0}},
                            ],
                        }
                    ),
                    encoding="utf-8",
                )
                session = target_session._load_session(self.record)
                text = target_session.format_history(self.record, session, limit=15)
                self.assertLess(text.index("10:30:00"), text.index("10:01:00"))
                self.assertIn("MATCH", text)
                self.assertIn("probe-002-abi", text)
                self.assertIn("second probe", text)
                payload = target_session.history_payload(self.record, session, limit=1)
                self.assertEqual(len(payload["runs"]), 1)
                self.assertEqual(payload["runs"][0]["id"], "run-b")
                self.assertEqual(len(payload["probes"]), 1)
                self.assertEqual(payload["probes"][0]["number"], 2)
                self.assertEqual(payload["checkpoint_count"], 2)

    def test_brief_bounds_notes_and_reports_lifetime_work(self) -> None:
        session = {
            "owner": "AgentB",
            "state": "pause",
            "probe_start_index": 2,
            "events": [
                {"kind": "start", "owner": "AgentA"},
                {"kind": "takeover", "owner": "AgentB"},
            ],
            "probes": [
                {
                    "number": 1,
                    "claim_number": 1,
                    "kind": "baseline",
                    "meaningful": True,
                    "note": "old note",
                    "metrics": {"diff_bytes": 12},
                    "outputs": {"emitted_identity_sha256": "a"},
                },
                {
                    "number": 2,
                    "claim_number": 1,
                    "kind": "liveness",
                    "meaningful": True,
                    "note": "useful gain",
                    "metrics": {"diff_bytes": 8},
                    "metric_delta": {"diff_bytes": {"direction": "improved"}},
                    "outputs": {"emitted_identity_sha256": "b"},
                },
                {
                    "number": 3,
                    "claim_number": 2,
                    "kind": "validation",
                    "meaningful": False,
                    "note": "final check",
                    "metrics": {"diff_bytes": 8},
                },
            ],
        }
        with patch.object(target_session, "current_metric_summary", return_value={}), patch.object(
            target_session, "preferred_source_path", return_value=Path("missing.cpp")
        ), patch.object(target_session, "checkpoint_info", side_effect=KeyError("none")):
            text = target_session.format_brief(self.record, session, note_limit=1)
        self.assertIn("claims=2 meaningful_probes=2", text)
        self.assertIn("best_positional_diff=8", text)
        self.assertIn("last_positional_gain=#2", text)
        self.assertIn("useful gain", text)
        self.assertNotIn("old note", text)
        self.assertNotIn("final check", text)


if __name__ == "__main__":
    unittest.main()
