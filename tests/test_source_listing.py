from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from source_listing import parse_listing, source_line_for_offset  # noqa: E402


class SourceListingTests(unittest.TestCase):
    def test_parses_line_changes_and_overlapping_locals(self) -> None:
        text = """\tTITLE\tsrc/demo.cpp
_first$12 = -8
_second$13 = -8
_parameter$ = 8
; 41 : first();
  0000a\t8b 45 f8\t mov eax, DWORD PTR _first$12[ebp]
; 52 : second();
  00020\t8a 4d f8\t mov cl, BYTE PTR _second$13[ebp]
  00023\t8b 55 08\t mov edx, DWORD PTR _parameter$[ebp]
"""
        metadata = parse_listing(text)
        self.assertEqual(metadata["source"], "src/demo.cpp")
        self.assertEqual(source_line_for_offset(metadata, 0x0A), 41)
        self.assertEqual(source_line_for_offset(metadata, 0x1F), 41)
        self.assertEqual(source_line_for_offset(metadata, 0x20), 52)
        self.assertEqual(
            metadata["stack_locals"],
            [{"name": "first", "offset": -8}, {"name": "second", "offset": -8}],
        )
        self.assertEqual(
            metadata["stack_homes"],
            [
                {
                    "name": "first", "kind": "local", "offset": -8,
                    "entry_coordinate": -12, "widths": [4],
                },
                {
                    "name": "second", "kind": "local", "offset": -8,
                    "entry_coordinate": -12, "widths": [1],
                },
                {
                    "name": "parameter", "kind": "parameter", "offset": 8,
                    "entry_coordinate": 4, "widths": [4],
                },
            ],
        )


if __name__ == "__main__":
    unittest.main()
