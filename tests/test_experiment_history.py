from __future__ import annotations

import json
import sys
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
from experiment_history import Store, digest, relative_path, is_primary_workspace


class ExperimentHistoryTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.store = Store(self.root / "store")

    def state(self, name="root", text=b"source", parents=None):
        return self.store.save("states", {
            "schema": 1, "name": name, "va": "004BB910", "hypothesis": name,
            "parents": parents or [], "base_commit": "base", "external": {},
            "files": {"src/Shape.cpp": self.store.blob(text)},
        })

    def test_same_content_deduplicates_without_losing_distinct_states(self):
        a = self.state("first")
        b = self.state("different hypothesis", parents=[a])
        self.assertNotEqual(a, b)
        self.assertEqual(self.store.state(a)[1]["files"], self.store.state(b)[1]["files"])
        self.assertEqual(len(self.store.records("states")), 2)

    def test_worse_result_never_hides_or_removes_state(self):
        a = self.state("wrong")
        b = self.state("correct", b"correct source", [a])
        self.store.event(a, "run", "wrong rows", [], summary={"diff_bytes": 1209})
        self.store.event(b, "run", "correct rows", [], summary={"diff_bytes": 1248})
        view = self.store.show("004BB910")
        self.assertIn("wrong", view)
        self.assertIn("correct", view)
        self.assertIn("1248", view)
        self.assertEqual(len(self.store.records("states")), 2)

    def test_equal_output_does_not_merge_different_source(self):
        a = self.state("cast")
        b = self.state("natural", b"natural", [a])
        for key in (a, b):
            self.store.event(key, "run", "same output", [], summary={"diff_bytes": 2})
        self.assertEqual(len(self.store.records("states")), 2)
        self.assertIn("+natural", self.store.compare(a, b))

    def test_findings_are_append_only_and_separate_from_results(self):
        key = self.state()
        self.store.event(key, "integration-objection", "unsupported cast", [])
        self.store.event(key, "open-question", "remove the cast", [])
        self.assertEqual(len(self.store.records("events")), 2)
        self.assertEqual(len(self.store.records("states")), 1)

    def test_failed_build_can_be_recorded_without_metrics(self):
        key = self.state()
        self.store.event(key, "run", "compile failed", [], summary={"result": "BUILD_OR_CHECK_FAILED"})
        self.assertIn("BUILD_OR_CHECK_FAILED", self.store.show(None))

    def test_object_tampering_is_detected(self):
        key = self.store.blob(b"source")
        (self.store.root / "objects" / key[:2] / key).write_bytes(b"changed")
        with self.assertRaisesRegex(ValueError, "Corrupt object"):
            self.store.read_blob(key)

    def test_record_tampering_is_detected(self):
        key = self.state()
        path = self.store.root / "states" / f"{key}.json"
        path.write_text("{}")
        with self.assertRaisesRegex(ValueError, "Corrupt record"):
            self.store.state(key)

    def test_reproduce_refuses_existing_destination_before_git(self):
        key = self.state()
        with patch("experiment_history.subprocess.run") as run:
            with self.assertRaisesRegex(ValueError, "Destination exists"):
                self.store.reproduce(key, self.root)
            run.assert_not_called()

    def test_paths_cannot_escape_repository(self):
        for path in ("../src/x.cpp", "C:/x", "/x", ".git/config", ".GIT", ".git./config", "src/../../x"):
            with self.subTest(path=path), self.assertRaises(ValueError):
                relative_path(path)

    def test_verify_checks_full_input_set_not_only_source(self):
        key = self.state()
        state = self.store.state(key)[1]
        state["files"]["include/Shape.h"] = self.store.blob(b"header")
        (self.root / "src").mkdir()
        (self.root / "src/Shape.cpp").write_bytes(b"source")
        (self.root / "include").mkdir()
        (self.root / "include/Shape.h").write_bytes(b"wrong header")
        with patch("experiment_history.git", return_value="base"):
            with self.assertRaisesRegex(ValueError, "include/Shape.h"):
                self.store.verify(state, self.root)

    def test_missing_build_cache_does_not_affect_saved_inputs(self):
        key = self.state()
        state = self.store.state(key)[1]
        self.assertFalse((self.root / "build").exists())
        self.assertEqual(self.store.read_blob(state["files"]["src/Shape.cpp"]), b"source")

    def test_snapshot_keeps_line_endings(self):
        a = self.store.blob(b"a\nb\n")
        b = self.store.blob(b"a\r\nb\r\n")
        self.assertNotEqual(a, b)
        self.assertEqual(self.store.read_blob(b), b"a\r\nb\r\n")

    def test_git_does_not_normalize_content_addressed_bytes(self):
        root = Path(__file__).resolve().parents[1]
        data = b"source\r\nwith CRLF\r\n"
        raw = subprocess.check_output(["git", "hash-object", "--stdin"], input=data, cwd=root)
        for directory in ("objects/ab", "states", "events"):
            filtered = subprocess.check_output([
                "git", "hash-object", "--path=workflow/decomp_notes/experiments/" + directory + "/sample.json", "--stdin"
            ], input=data, cwd=root)
            self.assertEqual(raw, filtered)

    def test_successful_audit_exit_does_not_hide_exact_regression(self):
        report = {"groups": [{"rows": [
            {"va": "004BAAF0", "source_bucket": "matching", "grouped_result": "MISMATCH"},
            {"va": "004B98E0", "source_bucket": "nonmatching", "grouped_result": "MATCH"},
        ]}]}
        key = self.store.blob(json.dumps(report).encode())
        event = {"kind": "run", "summary": {"closure_exit_code": 0},
                 "artifacts": {"build/closure/report.json": key}}
        self.assertEqual(self.store.event_summary(event)["exact_regressions"], ["004BAAF0"])

    def test_switch_refuses_unrelated_changes(self):
        a = self.state("before")
        b = self.state("after", b"new", [a])
        with patch.object(self.store, "verify"), patch("experiment_history.is_primary_workspace", return_value=False), patch("experiment_history.git", side_effect=["", "other.cpp", ""]):
            with self.assertRaisesRegex(ValueError, "unrelated changes"):
                self.store.switch(a, b, self.root)

    def test_switch_restores_exact_bytes_for_saved_untracked_input(self):
        a = self.state("before")
        b = self.state("after", b"new\r\n", [a])
        (self.root / "src").mkdir()
        (self.root / "src/Shape.cpp").write_bytes(b"source")
        with patch.object(self.store, "verify"), patch("experiment_history.is_primary_workspace", return_value=False), patch("experiment_history.git", side_effect=["", "", "src/Shape.cpp"]):
            self.store.switch(a, b, self.root)
        self.assertEqual((self.root / "src/Shape.cpp").read_bytes(), b"new\r\n")

    def test_verify_detects_changed_include_resolution(self):
        key = self.state()
        state = self.store.state(key)[1]
        state["context"] = {"fingerprint": "old"}
        (self.root / "src").mkdir()
        (self.root / "src/Shape.cpp").write_bytes(b"source")
        with patch("experiment_history.git", return_value="base"), patch(
            "experiment_history.workspace_context", return_value={"fingerprint": "changed"}
        ):
            with self.assertRaisesRegex(ValueError, "Compiler context differs"):
                self.store.verify(state, self.root)

    def test_capture_keeps_name_and_new_tool_inputs(self):
        files = {"src/Shape.cpp": b"source", "config/functions/src/Shape.cpp.json": b"{}",
                 "tools/changed.py": b"changed", "tools/new.py": b"new", "cl.exe": b"compiler"}
        files["config/toolchain.json"] = json.dumps({"compiler": {"cl": str(self.root / "cl.exe")}}).encode()
        for name, data in files.items():
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(data)
        context = {"source": "src/Shape.cpp", "fingerprint": "test", "inputs": [{"path": "src/Shape.cpp", "sha256": digest(b"source")}]}
        with patch("experiment_history.workspace_context", return_value=context), patch(
            "experiment_history.git", side_effect=["", "tools/changed.py", "tools/new.py", "base", "base"]
        ):
            key = self.store.capture(self.root, "0x004bb910", "named-state", "hypothesis", [], "test")
        state = self.store.state(key)[1]
        self.assertEqual(state["name"], "named-state")
        self.assertEqual(state["va"], "004BB910")
        self.assertEqual(self.store.read_blob(state["files"]["tools/new.py"]), b"new")

    def test_capture_refuses_unsupported_deleted_inputs(self):
        with patch("experiment_history.git", return_value="include/Shape.h"):
            with self.assertRaisesRegex(ValueError, "deleted build files"):
                self.store.capture(self.root, "004BB910", "deleted", "hypothesis", [], "test")

    def test_primary_checkout_detection_uses_git_metadata(self):
        common = self.root / ".git"
        with patch("experiment_history.git", side_effect=[str(common), ".git"]):
            self.assertTrue(is_primary_workspace(self.root))
        linked = common / "worktrees" / "worker"
        with patch("experiment_history.git", side_effect=[str(linked), str(common)]):
            self.assertFalse(is_primary_workspace(self.root / "worker"))

    def test_run_refuses_primary_checkout_before_validation(self):
        key = self.state()
        with patch("experiment_history.is_primary_workspace", return_value=True):
            with self.assertRaisesRegex(ValueError, "isolated workspace"):
                self.store.run(key, self.root, False, None)

    def test_inspect_distinguishes_event_hash_from_internal_uuid(self):
        state_id = self.state()
        event_id = self.store.event(state_id, "finding", "evidence", [])
        view = self.store.inspect(state_id)
        self.assertEqual(view["state_id"], state_id)
        event = view["events"][0]
        self.assertEqual(event["event_id"], event_id)
        self.assertNotEqual(event["record_uuid"], event_id)
        self.assertNotIn("id", event)


if __name__ == "__main__":
    unittest.main()
