from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import status_core  # noqa: E402
import common  # noqa: E402


class VerifiedLogicStatusTests(unittest.TestCase):
    def test_preferred_source_path_finds_verified_logic(self) -> None:
        record = {"va": "00400000", "name": "demo"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "verified_logic" / "00400000_demo.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("int demo() { return 1; }\n", encoding="utf-8")
            with patch.object(common, "REPO_ROOT", root):
                selected = common.preferred_source_path(record)
        self.assertEqual(selected, source)

    def test_verified_logic_is_completed_and_links_ledger(self) -> None:
        record = {
            "va": "00400000",
            "name": "demo",
            "slug": "00400000_demo",
            "size_bytes": "32",
            "asm_lines": "8",
            "calling_convention": "__cdecl",
            "pdb_source_file": "demo.cpp",
            "pdb_source_path": "demo.cpp",
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "verified_logic" / "00400000_demo.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("int demo() { return 1; }\n", encoding="utf-8")
            ledger = root / "logic_reviews" / "00400000_demo.md"
            ledger.parent.mkdir(parents=True)
            ledger.write_text("# Review\n", encoding="utf-8")

            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core, "load_functions", return_value=[record]),
                patch.object(status_core, "load_toolchain_supplied_function_names", return_value=set()),
                patch.object(status_core, "load_toolchain_supplied_regions", return_value=[]),
                patch.object(status_core, "load_asm_special_function_names", return_value=set()),
                patch.object(status_core, "load_asm_special_regions", return_value=[]),
                patch.object(status_core, "load_parent_owned_fragments", return_value={}),
                patch.object(status_core, "classify_corpus_bucket", return_value=("normal", "")),
            ):
                rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                )

        self.assertEqual(rows[0]["source_bucket"], "verified_logic")
        self.assertEqual(rows[0]["is_remaining"], "no")
        self.assertEqual(Path(rows[0]["logic_review_path"]), Path("logic_reviews/00400000_demo.md"))
        self.assertEqual(rows[0]["has_logic_review"], "yes")

    def test_verified_logic_without_ledger_is_flagged(self) -> None:
        record = {
            "va": "00400000",
            "name": "demo",
            "slug": "00400000_demo",
            "size_bytes": "32",
            "asm_lines": "8",
            "calling_convention": "__cdecl",
            "pdb_source_file": "demo.cpp",
            "pdb_source_path": "demo.cpp",
        }
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "verified_logic" / "00400000_demo.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("int demo() { return 1; }\n", encoding="utf-8")
            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core, "load_functions", return_value=[record]),
                patch.object(status_core, "load_toolchain_supplied_function_names", return_value=set()),
                patch.object(status_core, "load_toolchain_supplied_regions", return_value=[]),
                patch.object(status_core, "load_asm_special_function_names", return_value=set()),
                patch.object(status_core, "load_asm_special_regions", return_value=[]),
                patch.object(status_core, "load_parent_owned_fragments", return_value={}),
                patch.object(status_core, "classify_corpus_bucket", return_value=("normal", "")),
            ):
                rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                )

        self.assertEqual(rows[0]["source_bucket"], "verified_logic")
        self.assertEqual(rows[0]["has_logic_review"], "no")
        self.assertEqual(rows[0]["has_blocker"], "yes")
        self.assertIn("no logic-review ledger", rows[0]["source_blocker"])


if __name__ == "__main__":
    unittest.main()
