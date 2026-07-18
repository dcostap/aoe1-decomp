from __future__ import annotations

import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from function_history import (  # noqa: E402
    _dominates,
    _refresh_frontier,
    _resolve_run,
    _validate_label,
    history_prune_candidates,
    format_history_source_comparison,
    prune_history,
    structural_checkpoint_delta,
)


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


if __name__ == "__main__":
    unittest.main()
