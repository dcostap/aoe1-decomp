from __future__ import annotations

import json
import multiprocessing
import queue
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import function_history  # noqa: E402
from function_history import (  # noqa: E402
    _dominates,
    _refresh_frontier,
    _resolve_run,
    _validate_label,
    history_prune_candidates,
    format_history_source_comparison,
    prune_history,
    record_checkpoint,
    restore_checkpoint,
    structural_checkpoint_delta,
)


def _hold_history_lock(root: str, slug: str, ready: object, entered: object, release: object) -> None:
    import function_history

    function_history.REPO_ROOT = Path(root)
    ready.put(True)
    with function_history._history_lock(slug):
        entered.put(True)
        release.get(timeout=30)


class FunctionHistoryTests(unittest.TestCase):
    def objective(self, **overrides: int | float) -> dict[str, int | float]:
        value: dict[str, int | float] = {
            "exact_gate": 1,
            "wrong_direct_targets": 0,
            "hard_call_operations": 5,
            "call_count_gap": 3,
            "size_gap": 10,
            "cfg_gap": 2,
            "shape_gap": 20.0,
            "positional_diff_bytes": 100,
        }
        value.update(overrides)
        return value

    def test_dominance_requires_no_regression_on_any_objective(self) -> None:
        better = self.objective(hard_call_operations=4, size_gap=8)
        worse = self.objective()
        tradeoff = self.objective(hard_call_operations=3, size_gap=20)
        self.assertTrue(_dominates(better, worse))
        self.assertFalse(_dominates(tradeoff, worse))
        self.assertFalse(_dominates(worse, tradeoff))

    def test_frontier_keeps_tradeoffs_and_removes_dominated_run(self) -> None:
        index = {
            "runs": [
                {"id": "a", "objectives": self.objective(hard_call_operations=4, size_gap=8)},
                {"id": "b", "objectives": self.objective()},
                {"id": "c", "objectives": self.objective(hard_call_operations=3, size_gap=20)},
            ]
        }
        _refresh_frontier(index)
        self.assertEqual({row["id"] for row in index["runs"] if row["pareto"]}, {"a", "c"})

    def test_checkpoint_label_validation(self) -> None:
        self.assertEqual(_validate_label("best-call_prefix.2"), "best-call_prefix.2")
        with self.assertRaises(ValueError):
            _validate_label("bad label")
        with self.assertRaises(ValueError):
            _validate_label("../escape")

    def test_history_lock_closes_descriptor_when_handle_setup_fails(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            with (
                patch.object(function_history, "REPO_ROOT", Path(temporary)),
                patch.object(function_history.os, "open", return_value=123),
                patch.object(function_history.os, "fdopen", side_effect=RuntimeError("setup failed")),
                patch.object(function_history.os, "close") as close,
            ):
                with self.assertRaisesRegex(RuntimeError, "setup failed"):
                    with function_history._history_lock("demo"):
                        pass
            close.assert_called_once_with(123)

    def test_history_lock_serializes_processes(self) -> None:
        context = multiprocessing.get_context("spawn")
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            slug = "demo"
            first_ready = context.Queue()
            first_entered = context.Queue()
            first_release = context.Queue()
            second_ready = context.Queue()
            second_entered = context.Queue()
            second_release = context.Queue()
            first = context.Process(
                target=_hold_history_lock,
                args=(str(root), slug, first_ready, first_entered, first_release),
            )
            second = context.Process(
                target=_hold_history_lock,
                args=(str(root), slug, second_ready, second_entered, second_release),
            )
            first.start()
            second_started = False
            try:
                self.assertTrue(first_ready.get(timeout=5))
                self.assertTrue(first_entered.get(timeout=5))
                second.start()
                second_started = True
                self.assertTrue(second_ready.get(timeout=5))
                with self.assertRaises(queue.Empty):
                    second_entered.get(timeout=0.2)
                first_release.put(True)
                self.assertTrue(second_entered.get(timeout=5))
                second_release.put(True)
            finally:
                if first.is_alive():
                    first_release.put(True)
                if second_started and second.is_alive():
                    second_release.put(True)
                first.join(timeout=5)
                second.join(timeout=5)
                if first.is_alive():
                    first.terminate()
                if second.is_alive():
                    second.terminate()
            self.assertEqual(first.exitcode, 0)
            self.assertEqual(second.exitcode, 0)
            self.assertTrue((root / "build" / "history" / slug / "history.lock").is_file())

    def test_history_lock_is_released_when_process_exits(self) -> None:
        context = multiprocessing.get_context("spawn")
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            slug = "demo"
            abandoned_ready = context.Queue()
            abandoned_entered = context.Queue()
            abandoned_release = context.Queue()
            successor_ready = context.Queue()
            successor_entered = context.Queue()
            successor_release = context.Queue()
            abandoned = context.Process(
                target=_hold_history_lock,
                args=(str(root), slug, abandoned_ready, abandoned_entered, abandoned_release),
            )
            successor = context.Process(
                target=_hold_history_lock,
                args=(str(root), slug, successor_ready, successor_entered, successor_release),
            )
            abandoned.start()
            try:
                self.assertTrue(abandoned_ready.get(timeout=5))
                self.assertTrue(abandoned_entered.get(timeout=5))
                abandoned.terminate()
                abandoned.join(timeout=5)
                self.assertFalse(abandoned.is_alive())

                successor.start()
                self.assertTrue(successor_ready.get(timeout=5))
                self.assertTrue(successor_entered.get(timeout=5))
                successor_release.put(True)
                successor.join(timeout=5)
            finally:
                if abandoned.is_alive():
                    abandoned.terminate()
                if successor.is_alive():
                    successor_release.put(True)
                abandoned.join(timeout=5)
                successor.join(timeout=5)
                if successor.is_alive():
                    successor.terminate()
            self.assertEqual(successor.exitcode, 0)

    def test_automatic_best_selectors_use_structural_metric_then_diff_tiebreak(self) -> None:
        index = {
            "runs": [
                {"id": "a", "timestamp": "1", "summary": {"call_prefix": 10, "diff_bytes": 50, "shape_percent": 80}},
                {"id": "b", "timestamp": "2", "summary": {"call_prefix": 12, "diff_bytes": 90, "shape_percent": 70}},
                {"id": "c", "timestamp": "3", "summary": {"call_prefix": 12, "diff_bytes": 60, "shape_percent": 75}},
            ],
            "labels": {},
        }
        self.assertEqual(_resolve_run(index, "@best-call-prefix")["id"], "c")
        self.assertEqual(_resolve_run(index, "@best-shape")["id"], "a")
        self.assertEqual(_resolve_run(index, "@latest")["id"], "c")

    def test_prune_candidates_preserve_labels_pareto_and_recent(self) -> None:
        index = {
            "labels": {"keep-me": "labeled"},
            "runs": [
                {"id": "old-dominated", "pareto": False, "labels": []},
                {"id": "labeled", "pareto": False, "labels": ["keep-me"]},
                {"id": "frontier", "pareto": True, "labels": []},
                {"id": "recent", "pareto": False, "labels": []},
            ],
        }
        self.assertEqual(
            [row["id"] for row in history_prune_candidates(index, keep_recent=1)],
            ["old-dominated"],
        )

    def test_structural_checkpoint_delta_reports_call_and_block_changes(self) -> None:
        def issue(status: str, left: str | None, right: str | None) -> dict:
            return {
                "status": status,
                "original": None if left is None else {"kind": "direct", "target": left},
                "rebuilt": None if right is None else {"kind": "direct", "target": right},
            }

        baseline = {
            "call_alignment": {"rows": [issue("delete", "missing", None)]},
            "block_alignment": {
                "first_difference_row": 1,
                "rows": [
                    {"status": "equal", "original": {"offset": 0}, "rebuilt": {"offset": 0}},
                    {"status": "fuzzy", "original": {"offset": 10}, "rebuilt": {"offset": 12}},
                ],
            },
        }
        current = {
            "call_alignment": {"rows": [issue("insert", None, "extra")]},
            "block_alignment": {
                "first_difference_row": 0,
                "rows": [
                    {"status": "fuzzy", "original": {"offset": 0}, "rebuilt": {"offset": 0}},
                    {"status": "equal", "original": {"offset": 10}, "rebuilt": {"offset": 10}},
                ],
            },
        }
        delta = structural_checkpoint_delta(current, baseline)
        self.assertEqual(delta["new_call_issues"][0]["issue"], "insert: - - -> direct extra")
        self.assertEqual(delta["resolved_call_issues"][0]["issue"], "delete: direct missing -> - -")
        self.assertEqual(delta["new_exact_original_blocks"], [10])
        self.assertEqual(delta["lost_exact_original_blocks"], [0])

    def test_prune_history_apply_deletes_only_planned_artifact(self) -> None:
        record = {"va": "00001000", "name": "demo"}
        slug = "00001000_demo"
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            history_root = root / "build" / "history" / slug
            old_dir = history_root / "runs" / "old"
            kept_dir = history_root / "runs" / "kept"
            old_dir.mkdir(parents=True)
            kept_dir.mkdir(parents=True)
            (old_dir / "artifact.bin").write_bytes(b"old")
            (kept_dir / "artifact.bin").write_bytes(b"kept")
            index = {
                "version": 1,
                "slug": slug,
                "labels": {"keep": "kept"},
                "runs": [
                    {
                        "id": "old",
                        "pareto": False,
                        "labels": [],
                        "artifact_path": str(old_dir.relative_to(root)),
                        "summary": {},
                        "objectives": {},
                    },
                    {
                        "id": "kept",
                        "pareto": False,
                        "labels": ["keep"],
                        "artifact_path": str(kept_dir.relative_to(root)),
                        "summary": {},
                        "objectives": {},
                    },
                ],
            }
            (history_root / "history.json").write_text(json.dumps(index), encoding="utf-8")
            with patch("function_history.REPO_ROOT", root):
                lines = prune_history(record, keep_recent=0, apply=True)
            self.assertFalse(old_dir.exists())
            self.assertTrue(kept_dir.exists())
            self.assertTrue(any("Deleted 1 checkpoint" in line for line in lines))

    def test_history_source_comparison_returns_bounded_unified_diff(self) -> None:
        record = {"va": "00001000", "name": "demo"}
        slug = "00001000_demo"
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            history_root = root / "build" / "history" / slug
            for run_id, source in (("left-run", "one\ntwo\n"), ("right-run", "one\nchanged\nthree\n")):
                source_dir = history_root / "runs" / run_id / "source"
                source_dir.mkdir(parents=True)
                (source_dir / f"{slug}.cpp").write_text(source, encoding="utf-8")
            index = {
                "version": 1,
                "slug": slug,
                "labels": {"left": "left-run", "right": "right-run"},
                "runs": [
                    {"id": "left-run", "artifact_path": str((history_root / "runs" / "left-run").relative_to(root))},
                    {"id": "right-run", "artifact_path": str((history_root / "runs" / "right-run").relative_to(root))},
                ],
            }
            (history_root / "history.json").write_text(json.dumps(index), encoding="utf-8")
            with patch("function_history.REPO_ROOT", root):
                lines = format_history_source_comparison(record, "left", "right", limit=5)
            text = "\n".join(lines)
            self.assertIn("Checkpoint source comparison", text)
            self.assertIn("-two", text)
            self.assertTrue(any("more unified-diff line" in line for line in lines))

    def test_grouped_checkpoint_saves_complete_translation_unit_context(self) -> None:
        record = {"va": "00001000", "name": "demo", "size_bytes": "4"}
        group = {
            "name": "demo_unit",
            "source": "src/demo_unit_tu.cpp",
            "flags": "config/flags/demo.rsp",
            "owners": {
                "00001000": "src/matching/00001000_demo.cpp",
                "00001010": "src/matching/00001010_other.cpp",
            },
            "symbols": {"00001010": "?other@@YAHXZ"},
        }
        manifest = {
            "schema": 2,
            "fingerprint": "complete-build-fingerprint",
            "source": group["source"],
            "response_file": group["flags"],
            "compiler": {"path": "cl.exe", "size": 1, "mtime_ns": 2},
            "translation_unit": group,
            "inputs": [
                {"path": "config/flags/demo.rsp", "sha256": "flags"},
                {"path": "include/declaration_context.h", "sha256": "declarations"},
                {"path": "src/demo_unit_tu.cpp", "sha256": "wrapper"},
                {"path": "src/matching/00001000_demo.cpp", "sha256": "owner"},
                {"path": "src/matching/00001010_other.cpp", "sha256": "other-owner"},
            ],
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            for relative, content in (
                ("config/flags/demo.rsp", "/O2\n"),
                ("config/translation_units.json", "mapping\n"),
                ("include/declaration_context.h", "int declaration;\n"),
                ("src/demo_unit_tu.cpp", '#include "owner.cpp"\n'),
                ("src/matching/00001000_demo.cpp", "int demo;\n"),
                ("src/matching/00001010_other.cpp", "int other;\n"),
            ):
                path = root / relative
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(content, encoding="utf-8")
            slug = "00001000_demo"
            (root / "build" / "diff").mkdir(parents=True)
            (root / "build" / "asm").mkdir(parents=True)
            (root / "build" / "diff" / f"{slug}.json").write_text(
                json.dumps(
                    {
                        "result": "MISMATCH",
                        "diff_bytes": 1,
                        "owning_symbol_validation": {
                            "status": "match",
                            "expected_owner": "Demo",
                        },
                    }
                ),
                encoding="utf-8",
            )
            (root / "build" / "asm" / f"rebuilt_{slug}.bin").write_bytes(b"\x90")
            with patch("function_history.REPO_ROOT", root), patch(
                "function_history.translation_unit_for_va", return_value=group
            ), patch(
                "function_history.compiler_source_path", return_value=root / "src/demo_unit_tu.cpp"
            ), patch(
                "function_history.preferred_source_path", return_value=root / "src/matching/00001000_demo.cpp"
            ), patch(
                "function_history.preferred_flags_rsp_path", return_value=root / "config/flags/demo.rsp"
            ), patch(
                "function_history.compiler_artifact_slug", return_value="tu_demo_unit"
            ), patch(
                "function_history.load_toolchain",
                return_value={"compiler": {"default_rsp": "config/flags/default.rsp"}},
            ), patch("function_history.build_input_manifest", return_value=manifest), patch(
                "function_history.load_build_manifest", return_value=None
            ):
                run = record_checkpoint(record, "grouped")
                (root / "src/demo_unit_tu.cpp").write_text("changed wrapper\n", encoding="utf-8")
                (root / "src/matching/00001000_demo.cpp").write_text("changed target\n", encoding="utf-8")
                (root / "src/matching/00001010_other.cpp").write_text("changed owner\n", encoding="utf-8")
                (root / "config/flags/demo.rsp").write_text("/Od\n", encoding="utf-8")
                restore_checkpoint(record, "grouped")

            self.assertEqual(run["build_context"]["fingerprint"], "complete-build-fingerprint")
            self.assertEqual(run["build_context"]["translation_unit"]["owners"]["00001010"], group["owners"]["00001010"])
            self.assertEqual(run["build_context"]["translation_unit"]["symbols"]["00001010"], "?other@@YAHXZ")
            self.assertEqual(run["build_context"]["pdb_owner"]["status"], "match")
            context_root = root / run["artifact_path"] / "context"
            self.assertTrue((context_root / "files/src/demo_unit_tu.cpp").is_file())
            self.assertTrue((context_root / "files/src/matching/00001010_other.cpp").is_file())
            self.assertTrue((context_root / "files/include/declaration_context.h").is_file())
            self.assertTrue((context_root / "build_context.json").is_file())
            self.assertEqual((root / "src/demo_unit_tu.cpp").read_text(encoding="utf-8"), '#include "owner.cpp"\n')
            self.assertEqual((root / "src/matching/00001010_other.cpp").read_text(encoding="utf-8"), "int other;\n")
            self.assertEqual((root / "config/flags/demo.rsp").read_text(encoding="utf-8"), "/O2\n")


if __name__ == "__main__":
    unittest.main()
