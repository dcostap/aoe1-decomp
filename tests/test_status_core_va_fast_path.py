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
    def test_logic_review_lookup_includes_sparse_tracked_files(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            ledgers = root / "logic_reviews"
            git_result = subprocess.CompletedProcess(
                args=[],
                returncode=0,
                stdout="logic_reviews/0040CDF0_MainDecisionAIModule.md\n",
                stderr="",
            )
            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core.subprocess, "run", return_value=git_result),
            ):
                files = status_core.logic_review_files(ledgers)

        self.assertEqual(
            files["0040CDF0_MAINDECISIONAIMODULE"],
            root / "logic_reviews" / "0040CDF0_MainDecisionAIModule.md",
        )

    def test_source_file_lookup_normalizes_hex_case(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            source = directory / "0040a000_target.cpp"
            source.write_text("int target() { return 1; }\n", encoding="utf-8")

            files = status_core.source_files(directory)

        self.assertEqual(files["0040A000_TARGET"], source)

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
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "scratch" / "00400000_target.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("// NOTE: target note\nint target() { return 1; }\n", encoding="utf-8")

            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core, "load_functions", return_value=records),
                patch.object(status_core, "load_toolchain_supplied_function_names", return_value=set()),
                patch.object(status_core, "load_toolchain_supplied_regions", return_value=[]),
                patch.object(status_core, "load_asm_special_function_names", return_value=set()),
                patch.object(status_core, "load_asm_special_regions", return_value=[]),
                patch.object(status_core, "load_parent_owned_fragments", return_value={}),
                patch.object(status_core, "load_padding_only_functions", return_value={}),
                patch.object(status_core, "classify_corpus_bucket", return_value=("normal", "")),
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

        self.assertEqual(target_rows, [row for row in full_rows if row["va"] == "00400000"])
        self.assertEqual(target_rows[0]["remaining_size_rank"], "2")
        self.assertEqual(target_rows[0]["remaining_asm_rank"], "2")
        self.assertEqual(missing_rows, [])
        self.assertEqual(enriched_rows, [row for row in full_rows if row["va"] == "00400000"])
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
