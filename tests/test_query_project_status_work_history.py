from __future__ import annotations

import argparse
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import query_project_status  # noqa: E402
from query_project_status import (  # noqa: E402
    annotate_triage,
    annotate_work_history,
    history_prefilter_vas,
)


class QueryProjectStatusWorkHistoryTests(unittest.TestCase):
    def sessions(self) -> list[dict]:
        return [
            {
                "va": "00001000",
                "owner": "AgentA",
                "work_period_start_index": 1,
                "events": [
                    {"kind": "start", "owner": "AgentOld"},
                    {"kind": "takeover", "from_owner": "AgentOld", "to_owner": "AgentA"},
                ],
                "probes": [
                    {"work_period_probe_number": 1},
                    {
                        "work_period_probe_number": 2,
                        "number": 2,
                        "meaningful": True,
                        "at": "2026-08-02T10:00:00Z",
                        "metrics": {"diff_bytes": 8},
                        "metric_delta": {"diff_bytes": {"direction": "improved"}},
                    },
                    {"work_period_probe_number": 2},
                ],
                "last_metric_summary": {"diff_bytes": 9},
                "clean_baseline": {"checkpoint_id": "clean"},
            },
            {
                "va": "00002000",
                "owner": "AgentB",
                "probes": [{}],
            },
        ]

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

    def test_work_history_uses_only_the_matching_target_notebook(self) -> None:
        rows = annotate_work_history(
            [{"va": "00001000"}, {"va": "00002000"}, {"va": "00003000"}],
            self.sessions(),
            include_work_history=True,
        )
        self.assertEqual(rows[0]["work_probes"], "2")
        self.assertEqual(rows[0]["work_probe_total"], "3")
        self.assertEqual(rows[0]["work_period_total"], "2")
        self.assertEqual(rows[0]["work_best_current_diff"], "8/9")
        self.assertEqual(rows[0]["work_last_gain"], "#2@2026-08-02")
        self.assertEqual(rows[0]["work_last_worker"], "AgentA")
        self.assertEqual(rows[0]["work_clean_pinned"], "yes")
        self.assertEqual(rows[1]["work_last_worker"], "AgentB")
        self.assertEqual(rows[2]["work_probes"], "")

    def test_annotation_accepts_compact_notebook_summaries(self) -> None:
        summary = {
            "summary_version": 2,
            "va": "00001000",
            "owner": "AgentA",
            "meaningful_probe_count": 2,
            "meaningful_probe_total": 7,
            "work_period_count": 3,
            "best_diff_bytes": 8,
            "last_positional_improvement": {
                "number": 6,
                "at": "2026-08-02T10:00:00Z",
            },
            "last_metric_summary": {"diff_bytes": 9},
            "clean_baseline": True,
        }
        row = annotate_work_history(
            [{"va": "00001000"}], [summary], include_work_history=True
        )[0]
        self.assertEqual(row["work_probes"], "2")
        self.assertEqual(row["work_probe_total"], "7")
        self.assertEqual(row["work_period_total"], "3")
        self.assertEqual(row["work_best_current_diff"], "8/9")
        self.assertEqual(row["work_last_gain"], "#6@2026-08-02")

    def test_history_prefilter_excludes_rows_before_source_loading(self) -> None:
        args = argparse.Namespace(max_lifetime_probes=2, max_work_periods=1)
        include_vas, exclude_vas = history_prefilter_vas(args, self.sessions())
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
            functions = [
                {"va": "00001000", "name": "demo"},
                {"va": "00002000", "name": "callee"},
            ]
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
