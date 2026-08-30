from __future__ import annotations

import copy
import json
import multiprocessing
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


def _concurrent_start_worker(root_path, record, records, result_queue) -> None:
    root = Path(root_path)
    records_by_va = {item["va"].upper(): item for item in records}

    def source_path(_record):
        return root / "src" / "shared_module.cpp"

    def record_by_va(va):
        return records_by_va[f"{int(va):08X}"]

    def unexpected_full_scan():
        raise AssertionError("current session index was not used")

    with (
        patch.object(target_session, "REPO_ROOT", root),
        patch.object(target_session, "compiler_source_path", source_path),
        patch.object(target_session, "function_record_by_va", record_by_va),
        patch.object(target_session, "_all_sessions", unexpected_full_scan),
    ):
        try:
            target_session.start_session(record, "AgentA", 2.0)
        except Exception as error:  # pragma: no cover - exercised in child process
            result_queue.put(("error", type(error).__name__, str(error)))
        else:
            result_queue.put(("ok", record["va"], ""))


class TargetSessionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.record = {
            "va": "00001000",
            "name": "demo",
            "size_bytes": "64",
            "calling_convention": "__thiscall",
            "pdb_source_file": "demo.cpp",
        }
        source_patcher = patch.object(
            target_session,
            "compiler_source_path",
            side_effect=lambda _record: target_session.REPO_ROOT / "src" / "demo.cpp",
        )
        source_patcher.start()
        self.addCleanup(source_patcher.stop)

    def test_active_json_list_uses_compact_index_and_filters_rows(self) -> None:
        rows = [
            {
                "summary_version": target_session.SESSION_INDEX_VERSION,
                "va": "00001000",
                "slug": "00001000_demo",
                "owner": "AgentA",
                "state": "active",
                "lease_expires_at": "2999-01-01T00:00:00Z",
                "updated_at": "2026-01-01T00:00:00Z",
            },
            {
                "summary_version": target_session.SESSION_INDEX_VERSION,
                "va": "00002000",
                "slug": "00002000_other",
                "owner": "AgentB",
                "state": "pause",
                "lease_expires_at": "",
                "updated_at": "2026-01-01T00:00:00Z",
            },
        ]
        args = SimpleNamespace(command="list", active=True, json=True)

        with (
            patch.object(target_session, "parse_args", return_value=args),
            patch.object(target_session, "load_target_sessions", return_value=rows) as load,
            patch.object(target_session, "_all_sessions", side_effect=AssertionError("full scan")),
            patch("builtins.print") as output,
        ):
            target_session.main()

        load.assert_called_once_with()
        payload = json.loads(output.call_args.args[0])
        self.assertEqual([row["va"] for row in payload], ["00001000"])
        self.assertNotIn("probes", payload[0])

    def test_active_lease_rejects_other_owner_then_allows_paused_takeover(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                first = target_session.start_session(self.record, "AgentA", 2.0)
                self.assertTrue(target_session._lease_active(first))
                with self.assertRaises(RuntimeError):
                    target_session.start_session(self.record, "AgentB", 2.0)
                target_session.change_state(self.record, "AgentA", "pause", "needs ABI facts")
                second = target_session.start_session(self.record, "AgentB", 2.0)
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
                target_session.start_session(self.record, "AgentA", 2.0)
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
                first = target_session.start_session(self.record, "AgentA", 2.0)
                second = target_session.start_session(self.record, "AgentA", 2.0)
        self.assertEqual(target_session.session_claim_count(first), 1)
        self.assertEqual(target_session.session_claim_count(second), 1)

    def test_active_same_owner_start_skips_metric_collection(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "current_metric_summary", return_value={}) as metrics,
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                metrics.reset_mock()
                session = target_session.start_session(self.record, "AgentA", 2.0)
        metrics.assert_not_called()
        self.assertTrue(session["_start_reused_active"])

    def test_preclaim_skips_metric_collection(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "current_metric_summary") as metrics,
            ):
                session = target_session.start_session(
                    self.record,
                    "AgentA",
                    2.0,
                    collect_metrics=False,
                )
        metrics.assert_not_called()
        self.assertEqual(session["last_metric_summary"], {})

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
                target_session.start_session(self.record, "AgentA", 2.0)
                with self.assertRaisesRegex(RuntimeError, "translation unit"):
                    target_session.start_session(other_record, "AgentB", 2.0)

    def test_start_uses_current_index_for_translation_unit_conflict(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                with patch.object(
                    target_session,
                    "_all_sessions",
                    side_effect=AssertionError("current session index was not used"),
                ):
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentB", 2.0)

    def test_semantically_stale_index_entry_preserves_translation_unit_conflict(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                index = target_session._read_session_index()
                self.assertIsNotNone(index)
                session_files_fingerprint = target_session._session_file_fingerprint()
                index["sessions"][self.record["va"]]["state"] = "pause"
                target_session._session_index_path().write_text(
                    json.dumps(index), encoding="utf-8"
                )
                self.assertEqual(
                    session_files_fingerprint,
                    target_session._session_file_fingerprint(),
                )
                with patch.object(
                    target_session, "_all_sessions", wraps=target_session._all_sessions
                ) as all_sessions:
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentB", 2.0)
        all_sessions.assert_called_once_with()

    def test_start_skips_invalid_session_payloads_during_conflict_scan(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        payloads = {
            "invalid-utf8": b"\xff\xfe",
            "null": b"null",
            "list": b"[]",
            "string": b'"session"',
        }
        for label, payload in payloads.items():
            with self.subTest(label=label), tempfile.TemporaryDirectory() as temporary:
                root = Path(temporary)
                shared_source = root / "src" / "module.cpp"
                with (
                    patch.object(target_session, "REPO_ROOT", root),
                    patch.object(target_session, "compiler_source_path", return_value=shared_source),
                    patch.object(target_session, "function_record_by_va", return_value=self.record),
                ):
                    target_session.start_session(self.record, "AgentA", 2.0)
                    invalid_path = target_session._sessions_root() / "00000001_bad.json"
                    invalid_path.write_bytes(payload)
                    with patch.object(
                        target_session, "_all_sessions", wraps=target_session._all_sessions
                    ) as all_sessions:
                        with self.assertRaisesRegex(RuntimeError, "translation unit"):
                            target_session.start_session(other_record, "AgentB", 2.0)
                all_sessions.assert_called_once_with()

    def test_matching_empty_index_falls_back_to_active_session_files(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                index = target_session._read_session_index()
                self.assertIsNotNone(index)
                index["sessions"] = {}
                target_session._session_index_path().write_text(
                    json.dumps(index), encoding="utf-8"
                )
                self.assertEqual(
                    index["session_files_fingerprint"],
                    target_session._session_file_fingerprint(),
                )
                with patch.object(
                    target_session, "_all_sessions", wraps=target_session._all_sessions
                ) as all_sessions:
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentB", 2.0)
        all_sessions.assert_called_once_with()

    def test_matching_index_with_missing_entry_falls_back_to_full_scan(self) -> None:
        second_record = {**self.record, "va": "00002000", "name": "second"}
        other_record = {**self.record, "va": "00003000", "name": "other"}
        records_by_va = {
            record["va"]: record for record in (self.record, second_record, other_record)
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)

            def source_path(record):
                return root / "src" / (
                    "first.cpp" if record["va"] == self.record["va"] else "second.cpp"
                )

            def record_by_va(va):
                return records_by_va[f"{int(va):08X}"]

            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", source_path),
                patch.object(target_session, "function_record_by_va", record_by_va),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                target_session.start_session(second_record, "AgentB", 2.0)
                index = target_session._read_session_index()
                self.assertIsNotNone(index)
                del index["sessions"][second_record["va"]]
                target_session._session_index_path().write_text(
                    json.dumps(index), encoding="utf-8"
                )
                self.assertEqual(
                    index["session_files_fingerprint"],
                    target_session._session_file_fingerprint(),
                )
                with patch.object(
                    target_session, "_all_sessions", wraps=target_session._all_sessions
                ) as all_sessions:
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentC", 2.0)
        all_sessions.assert_called_once_with()

    def test_matching_index_with_extra_entry_falls_back_to_full_scan(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                index = target_session._read_session_index()
                self.assertIsNotNone(index)
                index["sessions"]["00009999"] = {
                    "va": "00009999",
                    "slug": "00009999_missing",
                    "state": "active",
                }
                target_session._session_index_path().write_text(
                    json.dumps(index), encoding="utf-8"
                )
                self.assertEqual(
                    index["session_files_fingerprint"],
                    target_session._session_file_fingerprint(),
                )
                with patch.object(
                    target_session, "_all_sessions", wraps=target_session._all_sessions
                ) as all_sessions:
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentB", 2.0)
        all_sessions.assert_called_once_with()

    def test_matching_index_with_non_dict_entry_falls_back_to_full_scan(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        for invalid_entry in (None, ["invalid"]):
            with self.subTest(invalid_entry=invalid_entry), tempfile.TemporaryDirectory() as temporary:
                root = Path(temporary)
                shared_source = root / "src" / "module.cpp"
                with (
                    patch.object(target_session, "REPO_ROOT", root),
                    patch.object(target_session, "compiler_source_path", return_value=shared_source),
                    patch.object(target_session, "function_record_by_va", return_value=self.record),
                ):
                    target_session.start_session(self.record, "AgentA", 2.0)
                    index = target_session._read_session_index()
                    self.assertIsNotNone(index)
                    index["sessions"][self.record["va"]] = invalid_entry
                    target_session._session_index_path().write_text(
                        json.dumps(index), encoding="utf-8"
                    )
                    self.assertEqual(
                        index["session_files_fingerprint"],
                        target_session._session_file_fingerprint(),
                    )
                    with patch.object(
                        target_session, "_all_sessions", wraps=target_session._all_sessions
                    ) as all_sessions:
                        with self.assertRaisesRegex(RuntimeError, "translation unit"):
                            target_session.start_session(other_record, "AgentB", 2.0)
                all_sessions.assert_called_once_with()

    def test_start_falls_back_to_full_scan_for_stale_index(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        active_other = {
            "va": "00001000",
            "owner": "AgentA",
            "state": "active",
            "lease_expires_at": "2999-01-01T00:00:00Z",
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                index = target_session._read_session_index()
                self.assertIsNotNone(index)
                index["session_files_fingerprint"] = "stale"
                target_session._session_index_path().write_text(
                    json.dumps(index), encoding="utf-8"
                )
                with patch.object(
                    target_session, "_all_sessions", return_value=[active_other]
                ) as all_sessions:
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentB", 2.0)
        all_sessions.assert_called_once_with()

    def test_start_falls_back_to_full_scan_for_corrupt_index(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        active_other = {
            "va": "00001000",
            "owner": "AgentA",
            "state": "active",
            "lease_expires_at": "2999-01-01T00:00:00Z",
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                target_session._session_index_path().write_text("[]", encoding="utf-8")
                with patch.object(
                    target_session, "_all_sessions", return_value=[active_other]
                ) as all_sessions:
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentB", 2.0)
        all_sessions.assert_called_once_with()

    def test_start_falls_back_for_invalid_utf8_index(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            shared_source = root / "src" / "module.cpp"
            with (
                patch.object(target_session, "REPO_ROOT", root),
                patch.object(target_session, "compiler_source_path", return_value=shared_source),
                patch.object(target_session, "function_record_by_va", return_value=self.record),
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                target_session._session_index_path().write_bytes(b"\xff\xfe")
                with patch.object(
                    target_session, "_all_sessions", wraps=target_session._all_sessions
                ) as all_sessions:
                    with self.assertRaisesRegex(RuntimeError, "translation unit"):
                        target_session.start_session(other_record, "AgentB", 2.0)
        all_sessions.assert_called_once_with()

    def test_concurrent_starts_reject_duplicate_translation_unit_claims(self) -> None:
        other_record = {**self.record, "va": "00002000", "name": "other"}
        records = [self.record, other_record]
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                target_session._sessions_root().mkdir(parents=True)
                target_session._write_session_index(
                    {}, target_session._session_file_fingerprint()
                )
            context = multiprocessing.get_context("spawn")
            result_queue = context.Queue()
            processes = [
                context.Process(
                    target=_concurrent_start_worker,
                    args=(str(root), record, records, result_queue),
                )
                for record in records
            ]
            try:
                for process in processes:
                    process.start()
                for process in processes:
                    process.join(15)
                self.assertTrue(all(not process.is_alive() for process in processes))
                self.assertTrue(all(process.exitcode == 0 for process in processes))
                results = [result_queue.get(timeout=2) for _ in processes]
            finally:
                for process in processes:
                    if process.is_alive():
                        process.terminate()
                        process.join()
                result_queue.close()
            self.assertEqual(sum(result[0] == "ok" for result in results), 1)
            errors = [result for result in results if result[0] == "error"]
            self.assertEqual(len(errors), 1)
            self.assertEqual(errors[0][1], "RuntimeError")
            self.assertIn("translation unit", errors[0][2])
            with patch.object(target_session, "REPO_ROOT", root):
                index = target_session._read_session_index()
                self.assertIsNotNone(index)
                self.assertEqual(
                    index["session_files_fingerprint"],
                    target_session._session_file_fingerprint(),
                )
                self.assertEqual(len(index["sessions"]), 1)

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

    def test_broad_load_repairs_structural_and_semantic_index_staleness(self) -> None:
        mutations = {
            "null": lambda sessions, va: sessions.__setitem__(va, None),
            "missing": lambda sessions, va: sessions.pop(va),
            "extra": lambda sessions, va: sessions.__setitem__(
                "00009999",
                {
                    "va": "00009999",
                    "slug": "00009999_missing",
                    "owner": "AgentB",
                    "state": "pause",
                    "lease_expires_at": "",
                },
            ),
            "semantic-stale": lambda sessions, va: sessions[va].__setitem__("state", "pause"),
        }
        for label, mutate in mutations.items():
            with self.subTest(label=label), tempfile.TemporaryDirectory() as temporary:
                root = Path(temporary)
                with patch.object(target_session, "REPO_ROOT", root):
                    target_session.start_session(self.record, "AgentA", 2.0)
                    index = target_session._read_session_index()
                    self.assertIsNotNone(index)
                    mutate(index["sessions"], self.record["va"])
                    target_session._session_index_path().write_text(
                        json.dumps(index), encoding="utf-8"
                    )
                    rows = target_session.load_target_sessions()
                    repaired = target_session._read_session_index()
                    self.assertTrue(
                        target_session._session_index_is_current(
                            repaired, target_session._session_file_fingerprint()
                        )
                    )
                self.assertEqual([row["va"] for row in rows], [self.record["va"]])
                self.assertEqual(rows[0]["state"], "active")

    def test_broad_load_handles_invalid_session_payloads(self) -> None:
        payloads = {
            "invalid-utf8": b"\xff\xfe",
            "null": b"null",
            "list": b"[]",
            "string": b'"session"',
        }
        for label, payload in payloads.items():
            with self.subTest(label=label), tempfile.TemporaryDirectory() as temporary:
                root = Path(temporary)
                sessions = root / "build" / "target_sessions"
                sessions.mkdir(parents=True)
                (sessions / "00001000_demo.json").write_text(
                    json.dumps(
                        {
                            "va": "00001000",
                            "owner": "AgentA",
                            "state": "active",
                            "lease_expires_at": "2999-01-01T00:00:00Z",
                            "probes": [],
                        }
                    ),
                    encoding="utf-8",
                )
                (sessions / "00000001_bad.json").write_bytes(payload)
                with patch.object(target_session, "REPO_ROOT", root):
                    rows = target_session.load_target_sessions()
                by_va = {row["va"]: row for row in rows}
                self.assertEqual(by_va["00001000"]["state"], "active")
                self.assertEqual(by_va["00000001"]["state"], "invalid")

    def test_broad_load_reuses_index_after_corrupt_session_rebuild(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            sessions = root / "build" / "target_sessions"
            sessions.mkdir(parents=True)
            (sessions / "00001000_bad.json").write_bytes(b"\xff\xfe")
            with patch.object(target_session, "REPO_ROOT", root):
                first = target_session.load_target_sessions()
                index = target_session._read_session_index()
                self.assertTrue(
                    target_session._session_index_is_current(
                        index, target_session._session_file_fingerprint()
                    )
                )
                with patch.object(
                    target_session,
                    "_rebuild_session_index",
                    side_effect=AssertionError("rebuild repeated for unchanged corrupt file"),
                ):
                    second = target_session.load_target_sessions()
        self.assertEqual(second, first)

    def test_bounded_summary_load_handles_invalid_session_payloads(self) -> None:
        payloads = {
            "invalid-utf8": b"\xff\xfe",
            "null": b"null",
            "list": b"[]",
            "string": b'"session"',
        }
        for label, payload in payloads.items():
            with self.subTest(label=label), tempfile.TemporaryDirectory() as temporary:
                root = Path(temporary)
                sessions = root / "build" / "target_sessions"
                sessions.mkdir(parents=True)
                (sessions / "00001000_bad.json").write_bytes(payload)
                with patch.object(target_session, "REPO_ROOT", root):
                    rows = target_session.load_target_sessions({"00001000"})
                self.assertEqual(rows[0]["va"], "00001000")
                self.assertEqual(rows[0]["state"], "invalid")

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
                target_session.start_session(self.record, "AgentA", 2.0)
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

    def test_stage_classification_uses_objective_differences(self) -> None:
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
            "objective mismatch",
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
                target_session.start_session(self.record, "AgentA", 2.0)
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
                target_session.start_session(self.record, "AgentA", 2.0)
                with self.assertRaisesRegex(ValueError, "managed"):
                    target_session.run_checked_probe(
                        self.record, "AgentA", "layout", "note", "", ["--no-history"]
                    )

    def test_checked_probe_does_not_record_an_incomplete_checker_run(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root):
                target_session.start_session(self.record, "AgentA", 2.0)
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
                target_session.start_session(self.record, "AgentA", 2.0)
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
                target_session.start_session(self.record, "AgentA", 2.0)
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
                target_session.start_session(self.record, "AgentA", 2.0)
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
                target_session.start_session(self.record, "AgentA", 2.0)
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

    def test_pause_releases_the_lease_after_recorded_work(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session,
                "current_metric_summary",
                return_value={"result": "MISMATCH", "artifact_fresh": True},
            ):
                target_session.start_session(self.record, "AgentA", 2.0)
                target_session.record_probe(
                    self.record, "AgentA", "control-flow", "changed guard"
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
                target_session.start_session(self.record, "AgentA", 2.0)
                session = target_session.pin_clean_baseline(
                    self.record,
                    "AgentA",
                    "canonical fields and natural indexed loop",
                )
            baseline = session["clean_baseline"]
            self.assertEqual(baseline["checkpoint_id"], "checkpoint-clean")
            self.assertEqual(baseline["inputs"], snapshot)
            self.assertIn("natural indexed loop", baseline["note"])

    def test_release_releases_the_lease_after_recorded_work(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            with patch.object(target_session, "REPO_ROOT", root), patch.object(
                target_session,
                "current_metric_summary",
                return_value={"result": "MISMATCH", "artifact_fresh": True},
            ), patch.object(target_session, "current_input_snapshot", return_value={}):
                target_session.start_session(self.record, "AgentA", 2.0)
                target_session.record_probe(self.record, "AgentA", "baseline", "first")
                released = target_session.change_state(
                    self.record, "AgentA", "release", "stop"
                )
            self.assertEqual(released["state"], "release")


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
                                 "source_path": "src/demo.cpp",
                                 "summary": {"result": "MISMATCH", "diff_bytes": 10,
                                             "diff_percent": 15.6, "resync_similarity_percent": 80.0}},
                                {"id": "run-b", "timestamp": "2026-08-02T10:30:00Z",
                                 "labels": ["probe-002-abi"], "custom_flags": True,
                                 "source_path": "src/demo.cpp",
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
