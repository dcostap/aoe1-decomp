from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import common  # noqa: E402


class CompilerGeneratedCorpusTests(unittest.TestCase):
    def test_load_compiler_generated_functions_reads_va_and_reason(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            manifest = Path(temporary) / "compiler_generated_functions.txt"
            manifest.write_text(
                "# comment\n00401150 compiler_generated_deleting_destructor\n",
                encoding="utf-8",
            )
            common.load_compiler_generated_functions.cache_clear()
            with patch.object(common, "COMPILER_GENERATED_FUNCTIONS_PATH", manifest):
                entries = common.load_compiler_generated_functions()
            common.load_compiler_generated_functions.cache_clear()

        self.assertEqual(
            entries,
            {0x00401150: "compiler_generated_deleting_destructor"},
        )

    def test_classify_compiler_generated_by_va(self) -> None:
        bucket, reason = common.classify_corpus_bucket(
            {"va": "00401150", "name": "`vector_deleting_destructor'"},
            toolchain_supplied_names=set(),
            toolchain_supplied_regions=[],
            asm_special_names=set(),
            asm_special_regions=[],
            parent_owned_fragments={},
            padding_only_functions={},
            compiler_generated_functions={
                0x00401150: "compiler_generated_deleting_destructor"
            },
        )

        self.assertEqual(
            (bucket, reason),
            ("compiler_generated", "compiler_generated_deleting_destructor"),
        )


if __name__ == "__main__":
    unittest.main()
