from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import common  # noqa: E402


class PaddingOnlyCorpusTests(unittest.TestCase):
    def test_load_padding_only_functions_reads_va_and_reason(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            manifest = Path(temporary) / "padding_only_functions.txt"
            manifest.write_text(
                "# comment\n00401746 reviewed_padding_only\n",
                encoding="utf-8",
            )
            common.load_padding_only_functions.cache_clear()
            with patch.object(common, "PADDING_ONLY_FUNCTIONS_PATH", manifest):
                entries = common.load_padding_only_functions()
            common.load_padding_only_functions.cache_clear()

        self.assertEqual(entries, {0x00401746: "reviewed_padding_only"})

    def test_classify_padding_only_by_va(self) -> None:
        bucket, reason = common.classify_corpus_bucket(
            {"va": "00401746", "name": "FUN_00401746"},
            toolchain_supplied_names=set(),
            toolchain_supplied_regions=[],
            asm_special_names=set(),
            asm_special_regions=[],
            parent_owned_fragments={},
            padding_only_functions={0x00401746: "reviewed_padding_only"},
        )

        self.assertEqual((bucket, reason), ("padding_only", "reviewed_padding_only"))


if __name__ == "__main__":
    unittest.main()
