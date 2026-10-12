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


class AcceptedLogicStatusTests(unittest.TestCase):
    status = "accepted_logic"

    def test_preferred_source_path_finds_accepted_logic(self) -> None:
        record = {"va": "00400000", "name": "demo"}
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "src" / "demo.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("int demo() { return 1; }\n", encoding="utf-8")
            entry = {
                "module": {"name": "demo", "source": "src/demo.cpp"},
                "status": self.status,
            }
            with patch.object(common, "REPO_ROOT", root), patch.object(
                common, "function_entry_for_va", return_value=entry
            ):
                selected = common.preferred_source_path(record)
        self.assertEqual(selected, source)

    def test_accepted_logic_is_completed_and_links_review(self) -> None:
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
            source = root / "src" / "demo.cpp"
            source.parent.mkdir(parents=True)
            source.write_text("int demo() { return 1; }\n", encoding="utf-8")
            entry_record = {
                "module": {"name": "demo", "source": "src/demo.cpp"},
                "status": self.status,
            }
            review = root / "logic_matching" / "00400000" / "review-test" / "attempt-01"
            review.mkdir(parents=True)
            (review / "attempt.json").write_text(
                '{"state":"complete","mode":"review","verdict":"PERFECT"}\n', encoding="utf-8")
            (review / "commits.patch").write_text("review commit\n", encoding="utf-8")
            entry_record["behavior_review"] = "logic_matching/00400000/review-test/attempt-01"
            expected_review = Path(entry_record["behavior_review"])

            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core, "load_functions", return_value=[record]),
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
                    return_value=entry_record,
                ),
            ):
                rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                )

        self.assertEqual(rows[0]["source_bucket"], self.status)
        self.assertEqual(rows[0]["is_remaining"], "no")
        self.assertEqual(Path(rows[0]["logic_review_path"]), expected_review)
        self.assertEqual(rows[0]["has_logic_review"], "yes")

    def test_accepted_logic_without_review_is_flagged(self) -> None:
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
            source = root / "src" / "demo.cpp"
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
                patch.object(status_core, "load_padding_only_functions", return_value={}),
                patch.object(status_core, "classify_corpus_bucket", return_value=("normal", "")),
                patch.object(
                    status_core,
                    "function_entry_for_va",
                    return_value={
                        "module": {"name": "demo", "source": "src/demo.cpp"},
                        "status": self.status,
                    },
                ),
            ):
                rows = status_core.build_status_rows(
                    include_source_preview=False,
                    include_diff_metrics=False,
                )

        self.assertEqual(rows[0]["source_bucket"], self.status)
        self.assertEqual(rows[0]["has_logic_review"], "no")
        self.assertEqual(rows[0]["has_blocker"], "yes")
        self.assertIn("no valid review record", rows[0]["source_blocker"])

    def test_registry_accepts_status(self) -> None:
        self.assertIn(self.status, common._FUNCTION_STATUSES)

    def test_dual_behavior_review_requires_two_valid_records(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            reviews = []
            for name in ("review-a", "review-b"):
                review = root / "logic_matching" / "00400000" / name / "attempt-01"
                review.mkdir(parents=True)
                (review / "attempt.json").write_text(
                    '{"state":"complete","mode":"review","verdict":"PERFECT"}\n',
                    encoding="utf-8",
                )
                (review / "commits.patch").write_text("review commit\n", encoding="utf-8")
                reviews.append(review.relative_to(root).as_posix())

            with patch.object(status_core, "REPO_ROOT", root):
                paths = status_core.behavior_review_paths(
                    {"behavior_review": reviews}, "00400000"
                )

        self.assertEqual(len(paths), 2)

    def test_registry_loader_preserves_behavior_review(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            registry = root / "config" / "functions" / "src" / "demo.cpp.json"
            registry.parent.mkdir(parents=True)
            registry.write_text(
                """{
  "schema": 1,
  "pdb_source_path": "demo.cpp",
  "build": {"flags": "default"},
  "functions": {
    "00400000": {
      "status": "accepted_logic",
      "symbol": "?demo@@YAHXZ",
      "behavior_review": ["logic_matching/00400000/review-a/attempt-01", "logic_matching/00400000/review-b/attempt-01"]
    }
  }
}\n""",
                encoding="utf-8",
            )
            common.load_function_modules.cache_clear()
            try:
                with (
                    patch.object(common, "REPO_ROOT", root),
                    patch.object(common, "FUNCTIONS_CONFIG_DIR", root / "config" / "functions"),
                    patch.object(common, "FLAGS_DIR", root / "config" / "flags"),
                ):
                    modules = common.load_function_modules()
            finally:
                common.load_function_modules.cache_clear()

        self.assertEqual(
            modules[0]["functions"]["00400000"]["behavior_review"],
            [
                "logic_matching/00400000/review-a/attempt-01",
                "logic_matching/00400000/review-b/attempt-01",
            ],
        )

    def test_behavior_review_reads_tracked_sparse_files(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            review = root / "logic_matching" / "00400000" / "review-a" / "attempt-01"
            metadata = '{"state":"complete","mode":"review","verdict":"PERFECT"}\n'

            def tracked_text(path: Path) -> str:
                if path.name == "attempt.json":
                    return metadata
                if path.name == "commits.patch":
                    return "review commit\n"
                raise OSError(path)

            with (
                patch.object(status_core, "REPO_ROOT", root),
                patch.object(status_core, "_repo_text", side_effect=tracked_text),
            ):
                paths = status_core.behavior_review_paths(
                    {
                        "behavior_review":
                            "logic_matching/00400000/review-a/attempt-01"
                    },
                    "00400000",
                )

        self.assertEqual(paths, [review])


if __name__ == "__main__":
    unittest.main()
