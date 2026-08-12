from __future__ import annotations

import argparse
import sys
import tempfile
import unittest
from datetime import datetime, timedelta, timezone
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import query_project_status  # noqa: E402
from query_project_status import annotate_leases, annotate_triage, filter_leases  # noqa: E402


class QueryProjectStatusLeaseTests(unittest.TestCase):
    def test_live_va_query_requests_the_status_core_fast_path(self) -> None:
        args = argparse.Namespace(from_csv=None, with_preview=False, va="00400000")
        with patch.object(query_project_status, "build_status_rows", return_value=[]) as build_rows:
            self.assertEqual(query_project_status.load_rows(args), [])
        build_rows.assert_called_once_with(include_source_preview=False, va="00400000")

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
