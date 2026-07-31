from __future__ import annotations

import json
import sys
import tempfile
import unittest
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


if __name__ == "__main__":
    unittest.main()
