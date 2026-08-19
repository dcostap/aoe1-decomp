from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from status_history import (  # noqa: E402
    CHILD_FIELDS,
    append_live_snapshot,
    upgrade_history_diff_metrics,
)


class StatusHistoryLiveSnapshotTests(unittest.TestCase):
    def test_live_snapshot_adds_current_diff_metrics_to_an_old_cache_schema(self) -> None:
        old_schema = list(CHILD_FIELDS[:-1])
        old_child = {field: None for field in old_schema}
        old_child.update({"va": "00400000", "name": "demo", "bucket": "scratch"})
        history = {
            "schema": old_schema,
            "base": {
                "groups": [{"name": "demo.cpp", "path": "demo.cpp", "children": [[old_child[field] for field in old_schema]]}],
                "summary": {},
            },
            "commits": [{"shortHash": "abc123"}],
            "deltas": [{"changes": []}],
            "sourcePreviews": [],
        }
        live_child = dict(old_child)
        live_child.update({
            "editDiffPercent": 12.5,
            "positionalDiffPercent": 25.0,
            "diffResult": "MISMATCH",
            "sourcePreview": "int demo();",
        })

        result = append_live_snapshot(
            history,
            [{"name": "demo.cpp", "path": "demo.cpp", "children": [live_child]}],
            {"remainingFunctions": 1},
            "2026-08-13T19:00:00",
        )

        self.assertIn("diffResult", result["schema"])
        self.assertIn("diffMeasuredCommit", result["schema"])
        self.assertTrue(result["commits"][-1]["workingTree"])
        self.assertEqual(result["commits"][-1]["summary"]["remainingFunctions"], 1)
        self.assertEqual(result["sourcePreviews"], ["int demo();"])

        row = list(result["base"]["groups"][0]["children"][0])
        change = result["deltas"][-1]["changes"][0]
        for index, value in change["patch"]:
            while len(row) <= index:
                row.append(None)
            row[index] = value
        decoded = dict(zip(result["schema"], row))
        self.assertEqual(decoded["editDiffPercent"], 12.5)
        self.assertEqual(decoded["positionalDiffPercent"], 25.0)
        self.assertEqual(decoded["diffResult"], "MISMATCH")

    def test_cache_upgrade_adds_diff_metrics_to_each_csv_commit(self) -> None:
        old_schema = list(CHILD_FIELDS[:-1])
        child = {field: None for field in old_schema}
        child.update({"va": "00400000", "bucket": "scratch"})
        history = {
            "schema": old_schema,
            "base": {"groups": [{"children": [[child[field] for field in old_schema]]}]},
            "commits": [
                {"hash": "one", "changedFiles": [{"path": "project_full_status.csv"}]},
                {"hash": "two", "changedFiles": [{"path": "project_full_status.csv"}]},
            ],
            "deltas": [{"changes": []}, {"changes": []}],
        }
        resume = {"previous_children": {"00400000": dict(child)}}
        csv_by_commit = {
            "one": "va,source_bucket,diff_result,edit_diff_percent,positional_diff_percent\n00400000,scratch,MISMATCH,20,40\n",
            "two": "va,source_bucket,diff_result,edit_diff_percent,positional_diff_percent\n00400000,scratch,MISMATCH,30,50\n",
        }

        upgrade_history_diff_metrics(history, resume, csv_by_commit.get)

        schema = history["schema"]
        row = list(history["base"]["groups"][0]["children"][0])
        base = dict(zip(schema, row))
        self.assertEqual(base["editDiffPercent"], 20.0)
        self.assertEqual(base["positionalDiffPercent"], 40.0)
        for index, value in history["deltas"][1]["changes"][0]["patch"]:
            row[index] = value
        latest = dict(zip(schema, row))
        self.assertEqual(latest["editDiffPercent"], 30.0)
        self.assertEqual(latest["positionalDiffPercent"], 50.0)
        self.assertEqual(latest["diffResult"], "MISMATCH")
        self.assertEqual(resume["previous_children"]["00400000"]["editDiffPercent"], 30.0)

    def test_cache_upgrade_carries_metrics_until_that_source_changes(self) -> None:
        schema = list(CHILD_FIELDS)

        def encoded(va: str, preview: int) -> list[object]:
            child = {field: None for field in schema}
            child.update({
                "va": va,
                "bucket": "scratch",
                "sourcePath": f"src/scratch/{va}.cpp",
                "sourcePreviewId": preview,
            })
            return [child[field] for field in schema]

        history = {
            "schema": schema,
            "base": {"groups": [{"children": [encoded("00400000", 1), encoded("00400010", 2)]}]},
            "commits": [
                {"hash": "one", "changedFiles": [{"path": "project_full_status.csv"}]},
                {"hash": "two", "changedFiles": [{"path": "src/scratch/00400000.cpp"}]},
            ],
            "deltas": [
                {"changes": []},
                {"changes": [{"va": "00400000", "patch": [[schema.index("sourcePreviewId"), 3]]}]},
            ],
        }
        csv_text = (
            "va,source_bucket,diff_result,edit_diff_percent,positional_diff_percent\n"
            "00400000,scratch,MISMATCH,20,40\n"
            "00400010,scratch,MISMATCH,30,50\n"
        )

        upgrade_history_diff_metrics(history, csv_loader=lambda commit: csv_text if commit == "one" else "")

        rows = {
            row[0]: list(row)
            for group in history["base"]["groups"]
            for row in group["children"]
        }
        for change in history["deltas"][1]["changes"]:
            row = rows[change["va"]]
            for index, value in change.get("patch", []):
                row[index] = value
        first = dict(zip(schema, rows["00400000"]))
        second = dict(zip(schema, rows["00400010"]))
        self.assertEqual(first["diffResult"], "")
        self.assertEqual(second["editDiffPercent"], 30.0)
        self.assertEqual(second["diffMeasuredCommit"], "one")


if __name__ == "__main__":
    unittest.main()
