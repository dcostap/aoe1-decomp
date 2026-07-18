from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from source_listing import parse_listing, source_line_for_offset  # noqa: E402


class SourceListingTests(unittest.TestCase):
    def test_parses_line_changes_and_overlapping_locals(self) -> None:
        text = """\tTITLE\tsrc/scratch/demo.cpp
_first$12 = -8
_second$13 = -8
; 41 : first();
  0000a\te8 00 00 00 00\t call first
; 52 : second();
  00020\te8 00 00 00 00\t call second
"""
        metadata = parse_listing(text)
        self.assertEqual(metadata["source"], "src/scratch/demo.cpp")
        self.assertEqual(source_line_for_offset(metadata, 0x0A), 41)
        self.assertEqual(source_line_for_offset(metadata, 0x1F), 41)
        self.assertEqual(source_line_for_offset(metadata, 0x20), 52)
        self.assertEqual(
            metadata["stack_locals"],
            [{"name": "first", "offset": -8}, {"name": "second", "offset": -8}],
        )


if __name__ == "__main__":
    unittest.main()
