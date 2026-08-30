from __future__ import annotations

import argparse
import io
import sys
import tempfile
import unittest
from datetime import datetime, timedelta, timezone
from pathlib import Path
from contextlib import redirect_stdout
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import query_project_status  # noqa: E402
from query_project_status import (  # noqa: E402
    annotate_leases,
    annotate_triage,
    filter_leases,
    lease_prefilter_vas,
)


class QueryProjectStatusLeaseTests(unittest.TestCase):
    def test_targeted_lease_query_loads_all_sessions_for_translation_unit_scope(self) -> None:
        future = (datetime.now(timezone.utc) + timedelta(hours=1)).isoformat().replace("+00:00", "Z")
        sibling_session = {
            "va": "00002000",
            "owner": "AgentB",
            "state": "active",
            "lease_expires_at": future,
            "probes": [],
        }
        rows = [{"va": "00001000", "source_path": "src/module.cpp", "name": "target"}]

        with (
            patch.object(sys, "argv", ["query_project_status.py", "--va", "00001000", "--leases"]),
            patch.object(query_project_status, "load_target_sessions", return_value=[sibling_session]) as load_sessions,
            patch.object(query_project_status, "load_rows", return_value=rows),
            patch.object(
                query_project_status,
                "function_record_by_va",
                return_value={"va": "00002000", "name": "sibling"},
            ),
            patch.object(
                query_project_status,
                "compiler_source_path",
                return_value=query_project_status.REPO_ROOT / "src" / "module.cpp",
            ),
        ):
            with redirect_stdout(io.StringIO()) as output:
                query_project_status.main()

        load_sessions.assert_called_once_with()
        self.assertIn("AgentB", output.getvalue())

    def test_live_va_query_requests_the_status_core_fast_path(self) -> None:
        with patch.object(sys, "argv", ["query_project_status.py", "--va", "00400000"]):
            args = query_project_status.parse_args()
        with patch.object(query_project_status, "build_status_rows", return_value=[]) as build_rows:
            self.assertEqual(query_project_status.load_rows(args), [])
        call = build_rows.call_args.kwargs
        self.assertEqual(call["va"], "00400000")
        self.assertFalse(call["include_source_preview"])
        self.assertFalse(call["include_source_notes"])
        self.assertFalse(call["include_diff_metrics"])
        self.assertFalse(call["include_comment_lines"])

    def sessions(self) -> list[dict]:
        future = (datetime.now(timezone.utc) + timedelta(hours=1)).isoformat().replace("+00:00", "Z")
        return [
            {
                "va": "00001000",
                "owner": "AgentA",
                "state": "active",
                "lease_expires_at": future,
                "probe_start_index": 1,
                "events": [
                    {"kind": "start", "owner": "AgentA"},
                    {"kind": "takeover", "from_owner": "AgentOld", "to_owner": "AgentA"},
                ],
                "probes": [
                    {"claim_number": 1},
                    {
                        "claim_number": 2,
                        "number": 2,
                        "meaningful": True,
                        "at": "2026-08-02T10:00:00Z",
                        "metrics": {"diff_bytes": 8},
                        "metric_delta": {"diff_bytes": {"direction": "improved"}},
                    },
                    {"claim_number": 2},
                ],
                "last_metric_summary": {"diff_bytes": 9},
            },
            {
                "va": "00002000",
                "owner": "AgentB",
                "state": "paused",
                "lease_expires_at": future,
                "probes": [{}],
            },
        ]

    def test_annotation_only_treats_unexpired_active_session_as_leased(self) -> None:
        rows = annotate_leases(
            [{"va": "00001000"}, {"va": "00002000"}, {"va": "00003000"}],
            self.sessions(),
            include_work_history=True,
        )
        self.assertEqual(rows[0]["lease_owner"], "AgentA")
        self.assertEqual(rows[0]["lease_probes"], "2")
        self.assertEqual(rows[0]["lease_probe_total"], "3")
        self.assertEqual(rows[0]["lease_claim_total"], "2")
        self.assertEqual(rows[0]["work_best_current_diff"], "8/9")
        self.assertEqual(rows[0]["work_last_gain"], "#2@2026-08-02")
        self.assertEqual(rows[1]["lease_active"], "no")
        self.assertEqual(rows[2]["lease_state"], "")

    def test_annotation_accepts_compact_session_summaries(self) -> None:
        future = (datetime.now(timezone.utc) + timedelta(hours=1)).isoformat().replace("+00:00", "Z")
        summary = {
            "summary_version": 1,
            "va": "00001000",
            "owner": "AgentA",
            "state": "active",
            "lease_expires_at": future,
            "meaningful_probe_count": 2,
            "meaningful_probe_total": 7,
            "claim_count": 3,
            "best_diff_bytes": 8,
            "last_positional_improvement": {"number": 6, "at": "2026-08-02T10:00:00Z"},
            "last_metric_summary": {"diff_bytes": 9},
            "clean_baseline": True,
        }
        row = annotate_leases([{"va": "00001000"}], [summary], include_work_history=True)[0]
        self.assertEqual(row["lease_probes"], "2")
        self.assertEqual(row["lease_probe_total"], "7")
        self.assertEqual(row["lease_claim_total"], "3")
        self.assertEqual(row["work_best_current_diff"], "8/9")
        self.assertEqual(row["work_last_gain"], "#6@2026-08-02")

    def test_annotation_marks_every_function_in_the_leased_translation_unit(self) -> None:
        rows = [
            {"va": "00001000", "source_path": "src/module.cpp"},
            {"va": "00003000", "source_path": "src/module.cpp"},
        ]

        def record_for_va(va: int) -> dict[str, str]:
            return {"va": f"{va:08X}", "name": "demo"}

        with (
            patch.object(query_project_status, "function_record_by_va", side_effect=record_for_va),
            patch.object(
                query_project_status,
                "compiler_source_path",
                return_value=query_project_status.REPO_ROOT / "src" / "module.cpp",
            ),
        ):
            annotated = annotate_leases(rows, self.sessions())

        self.assertEqual(annotated[1]["lease_active"], "yes")
        self.assertEqual(annotated[1]["lease_owner"], "AgentA")
        self.assertEqual(annotated[1]["lease_target_va"], "00001000")

    def test_review_hold_reserves_every_function_without_an_expiry(self) -> None:
        rows = [
            {"va": "00001000", "source_path": "src/module.cpp"},
            {"va": "00003000", "source_path": "src/module.cpp"},
        ]
        review = {
            "va": "00001000",
            "owner": "AgentA",
            "state": "review",
            "lease_expires_at": "",
            "probes": [],
        }
        with (
            patch.object(
                query_project_status,
                "function_record_by_va",
                return_value={"va": "00001000", "name": "demo"},
            ),
            patch.object(
                query_project_status,
                "compiler_source_path",
                return_value=query_project_status.REPO_ROOT / "src" / "module.cpp",
            ),
        ):
            annotated = annotate_leases(rows, [review])
        self.assertTrue(all(row["lease_active"] == "yes" for row in annotated))
        self.assertTrue(all(row["lease_state"] == "review" for row in annotated))
        self.assertTrue(all(row["lease_expires_at"] == "" for row in annotated))

    def test_filters_support_unleased_active_and_owner(self) -> None:
        rows = annotate_leases([{"va": "00001000"}, {"va": "00002000"}, {"va": "00003000"}], self.sessions())
        self.assertNotIn("lease_claim_total", rows[0])
        self.assertNotIn("work_next", rows[0])
        self.assertEqual([row["va"] for row in filter_leases(rows, active_only=True)], ["00001000"])
        self.assertEqual([row["va"] for row in filter_leases(rows, owner="AgentA")], ["00001000"])
        self.assertEqual(
            [row["va"] for row in filter_leases(rows, unleased=True)],
            ["00002000", "00003000"],
        )

    def test_lease_prefilter_excludes_rows_before_source_loading(self) -> None:
        args = argparse.Namespace(
            active_leases=False,
            owner=None,
            unleased=True,
            max_lifetime_probes=2,
            max_claims=1,
        )
        include_vas, exclude_vas = lease_prefilter_vas(args, self.sessions())
        self.assertIsNone(include_vas)
        self.assertEqual(exclude_vas, {"00001000"})

    def test_compact_triage_extracts_packet_features_for_selected_rows(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            packet = root / "inventory" / "functions" / "0000" / "00001000_demo.txt"
            packet.parent.mkdir(parents=True)
            packet.write_text(
                """VA: 00001000
Name: demo
Slug: 00001000_demo
SizeBytes: 32
AsmLines: 6
CallingConvention: __thiscall
PdbSourceFile: demo.cpp
PdbSourcePath: demo.cpp
PdbLineSpan: 10-20
PdbLineRecordCount: 4

=== OriginalAsm ===
00001000  push ebp
00001001  push esi
00001002  sub esp,20h
00001005  call 00002000h
0000100A  call dword [eax+10h]
0000100D  ret

=== GhidraDecompilerExcerpt ===
void demo(void) {}
""",
                encoding="utf-8",
            )
            rows = [{"va": "00001000", "name": "demo", "packet_path": str(packet)}]
            functions = [{"va": "00001000", "name": "demo"}, {"va": "00002000", "name": "callee"}]
            with patch.object(query_project_status, "REPO_ROOT", root), patch.object(
                query_project_status, "load_functions", return_value=functions
            ):
                annotated = annotate_triage(rows)
        self.assertEqual(annotated[0]["triage_pdb_lines"], "10-20")
        self.assertEqual(annotated[0]["triage_frame"], "0x20")
        self.assertEqual(annotated[0]["triage_calls"], "1")
        self.assertEqual(annotated[0]["triage_vslots"], "1")
        self.assertEqual(annotated[0]["triage_saved"], "ebp,esi")
        self.assertEqual(annotated[0]["triage_decomp"], "yes")


if __name__ == "__main__":
    unittest.main()
