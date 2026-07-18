from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from diff_function import _format_focus_range, _parse_focus_range  # noqa: E402
from function_diagnostics import basic_blocks, block_alignment, decode_instruction_ranges, decode_instructions  # noqa: E402


class DiffFunctionRangeTests(unittest.TestCase):
    def test_offset_and_real_va_ranges(self) -> None:
        instructions = decode_instructions(bytes.fromhex("90 90 C3"), 0x401000)
        self.assertEqual(
            _parse_focus_range("+0001-+0002", instructions, instructions, 0x401000),
            ("original", 1, 3),
        )
        self.assertEqual(
            _parse_focus_range("rebuilt:00401001-00401002", instructions, instructions, 0x401000),
            ("rebuilt", 1, 3),
        )

    def test_discontiguous_real_va_maps_to_combined_offset(self) -> None:
        original = decode_instruction_ranges(
            bytes.fromhex("90 C3 90 C3"),
            [
                {"start": "00401000", "size_bytes": 2},
                {"start": "00402000", "size_bytes": 2},
            ],
        )
        rebuilt = decode_instructions(bytes.fromhex("90 C3 90 C3"), 0x401000)
        self.assertEqual(
            _parse_focus_range("orig:00402000-00402001", original, rebuilt, 0x401000),
            ("original", 2, 4),
        )

    def test_focused_output_uses_aligned_block_partner(self) -> None:
        original = decode_instructions(bytes.fromhex("85 C0 74 01 90 C3"), 0x1000)
        rebuilt = decode_instructions(bytes.fromhex("83 F8 00 74 01 90 C3"), 0x1000)
        alignment = block_alignment(basic_blocks(original, []), basic_blocks(rebuilt, []))
        lines = _format_focus_range("+0000-+0003", 0x1000, original, rebuilt, alignment)
        text = "\n".join(lines)
        self.assertIn("Focused original range", text)
        self.assertIn("ORIGINAL", text)
        self.assertIn("REBUILT", text)
        self.assertIn("test eax,eax", text)
        self.assertIn("cmp eax,0", text)


if __name__ == "__main__":
    unittest.main()
