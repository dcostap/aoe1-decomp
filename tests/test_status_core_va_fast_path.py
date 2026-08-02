from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import status_core  # noqa: E402


class StatusCoreVaFastPathTests(unittest.TestCase):
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

        self.assertEqual(target_rows, [row for row in full_rows if row["va"] == "00400000"])
        self.assertEqual(target_rows[0]["remaining_size_rank"], "2")
        self.assertEqual(target_rows[0]["remaining_asm_rank"], "2")
        self.assertEqual(missing_rows, [])


if __name__ == "__main__":
    unittest.main()
