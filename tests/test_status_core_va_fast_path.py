from __future__ import annotations

import sys
import subprocess
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import status_core  # noqa: E402


class StatusCoreVaFastPathTests(unittest.TestCase):
    def test_migrated_module_uses_manifest_state_and_deterministic_notes(self) -> None:
        rows = status_core.build_status_rows(
            include_source_preview=False,
            include_source_notes=True,
            include_diff_metrics=False,
            include_comment_lines=False,
            va="0047E530",
        )

        self.assertEqual(len(rows), 1)
        row = rows[0]
        self.assertEqual(row["source_bucket"], "scratch")
        self.assertEqual(row["source_path"], "src/point.cpp")
        self.assertEqual(
            row["function_note_path"],
            "decomp_notes/functions/0047/0047E530.md",
        )
        self.assertEqual(row["module_note_path"], "")
        self.assertIn("Notes:", row["source_note"])

    def test_logic_review_lookup_includes_sparse_tracked_files(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            ledgers = root / "logic_reviews"
            git_result = subprocess.CompletedProcess(
                args=[],
                returncode=0,
                stdout="logic_reviews/0040CDF0.md\n",
                stderr="",
            )
            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core.subprocess, "run", return_value=git_result),
            ):
                files = status_core.logic_review_files(ledgers)

        self.assertEqual(
            files["0040CDF0"],
            root / "logic_reviews" / "0040CDF0.md",
        )

    def test_header_owned_function_is_unresolved(self) -> None:
        rows = status_core.build_status_rows(
            include_source_preview=False,
            include_diff_metrics=False,
            va="0041A480",
        )
        self.assertEqual(rows[0]["source_bucket"], "unresolved")
        self.assertEqual(rows[0]["source_path"], "include/stat_obj.h")
        self.assertEqual(rows[0]["is_remaining"], "yes")

    def test_va_build_matches_the_same_row_from_a_full_build(self) -> None:
        records = [
            {
                "va": "00400000",
                "name": "target",
                "slug": "00400000_target",
                "size_bytes": "32",
                "asm_lines": "8",
                "calling_convention": "__cdecl",
                "pdb_source_file": "demo.cpp",
                "pdb_source_path": "demo.cpp",
            },
            {
                "va": "00400020",
                "name": "other",
                "slug": "00400020_other",
                "size_bytes": "64",
                "asm_lines": "16",
                "calling_convention": "__cdecl",
                "pdb_source_file": "demo.cpp",
                "pdb_source_path": "demo.cpp",
            },
        ]
        records_by_va = {int(record["va"], 16): record for record in records}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "demo.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("// NOTE: target note\nint target() { return 1; }\n", encoding="utf-8")
            module = {"name": "demo", "source": "src/demo.cpp"}
            entries = {
                "00400000": {"module": module, "status": "scratch"},
            }

            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core, "load_functions", return_value=records),
                patch.object(
                    status_core,
                    "function_record_by_va",
                    side_effect=records_by_va.__getitem__,
                ),
                patch.object(status_core, "load_toolchain_supplied_function_names", return_value=set()),
                patch.object(status_core, "load_toolchain_supplied_regions", return_value=[]),
                patch.object(status_core, "load_asm_special_function_names", return_value=set()),
                patch.object(status_core, "load_asm_special_regions", return_value=[]),
                patch.object(status_core, "load_parent_owned_fragments", return_value={}),
                patch.object(status_core, "load_padding_only_functions", return_value={}),
                patch.object(status_core, "classify_corpus_bucket", return_value=("normal", "")),
                patch.object(
                    status_core,
                    "function_entry_for_va",
                    side_effect=lambda va: entries.get(str(va).upper()),
                ),
            ):
                full_rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                )
                target_rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                    va="00400000",
                )
                missing_rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                    va="FFFFFFFF",
                )
                filtered_rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                    source_bucket_filter="scratch",
                    corpus_bucket_filter="normal",
                    min_size=16,
                    max_size=48,
                )
                base_rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_source_notes=False,
                    include_diff_metrics=False,
                    include_comment_lines=False,
                    va="00400000",
                )
                enriched_rows = status_core.enrich_status_rows(
                    base_rows,
                    include_source_notes=True,
                    include_source_preview=False,
                    include_comment_lines=True,
                    include_diff_metrics=False,
                )

        expected_target = dict(next(row for row in full_rows if row["va"] == "00400000"))
        expected_target["remaining_size_rank"] = ""
        expected_target["remaining_asm_rank"] = ""
        self.assertEqual(target_rows, [expected_target])
        self.assertEqual(target_rows[0]["remaining_size_rank"], "")
        self.assertEqual(target_rows[0]["remaining_asm_rank"], "")
        self.assertEqual(missing_rows, [])
        self.assertEqual(enriched_rows, [expected_target])
        self.assertEqual(
            filtered_rows,
            status_core.filter_status_rows(
                full_rows,
                source_bucket="scratch",
                corpus_bucket="normal",
                min_size=16,
                max_size=48,
            ),
        )


if __name__ == "__main__":
    unittest.main()
