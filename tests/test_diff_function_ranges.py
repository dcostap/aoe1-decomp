from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from diff_function import (  # noqa: E402
    _format_focus_range,
    _format_full_block_map,
    _format_full_call_map,
    _hard_discrepancies,
    _parse_focus_range,
    _relocated_call_pairs,
)
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

    def test_call_map_filters_target_and_limits_rows(self) -> None:
        def call(offset: int, target: str) -> dict:
            return {"offset": offset, "kind": "direct", "target": target, "display": target}

        alignment = {
            "rows": [
                {"status": "equal", "confidence": "high", "original": call(1, "type"), "rebuilt": call(1, "type")},
                {"status": "delete", "confidence": "high", "original": call(2, "setaction"), "rebuilt": None},
                {"status": "insert", "confidence": "medium", "original": None, "rebuilt": call(3, "setaction")},
            ]
        }
        text = "\n".join(
            _format_full_call_map(
                alignment,
                0x1000,
                unmatched_only=True,
                target_filter="setaction",
                limit=1,
            )
        )
        self.assertNotIn("direct type", text)
        self.assertIn("direct setaction", text)
        self.assertIn("1 more filtered call-map row", text)

    def test_call_map_exact_and_regex_filters(self) -> None:
        def call(offset: int, target: str) -> dict:
            return {"offset": offset, "kind": "direct", "target": target, "display": target}

        alignment = {
            "rows": [
                {"status": "equal", "confidence": "high", "original": call(1, "action"), "rebuilt": call(1, "action")},
                {"status": "equal", "confidence": "high", "original": call(2, "setaction"), "rebuilt": call(2, "setaction")},
            ]
        }
        exact = "\n".join(
            _format_full_call_map(alignment, 0x1000, target_filter="action", target_filter_mode="exact")
        )
        self.assertIn("direct action", exact)
        self.assertNotIn("direct setaction", exact)
        regex = "\n".join(
            _format_full_call_map(alignment, 0x1000, target_filter="^direct set", target_filter_mode="regex")
        )
        self.assertNotIn("direct action", regex)
        self.assertIn("direct setaction", regex)

    def test_relocated_call_pairs_require_identical_call_sequence(self) -> None:
        def call(offset: int, block: int, target: str) -> dict:
            return {"offset": offset, "block_offset": block, "kind": "direct", "target": target, "display": target}

        block_map = {
            "relocated_pairs": [
                {
                    "confidence": "high",
                    "exact": True,
                    "original": {"offset": 0x10},
                    "rebuilt": {"offset": 0x80},
                }
            ]
        }
        rows = _relocated_call_pairs(
            block_map,
            [call(0x12, 0x10, "a"), call(0x18, 0x10, "b")],
            [call(0x82, 0x80, "a"), call(0x88, 0x80, "b")],
        )
        self.assertEqual([(row["original"]["target"], row["rebuilt"]["target"]) for row in rows], [("a", "a"), ("b", "b")])
        self.assertEqual(rows[0]["block_offset_delta"], 0x70)

    def test_block_map_difference_filter_omits_equal_rows(self) -> None:
        block = {
            "index": 0,
            "offset": 0,
            "end_offset": 1,
            "instruction_count": 1,
            "calls": [],
            "successors": [],
        }
        alignment = {
            "rows": [
                {"status": "equal", "confidence": "high", "original": block, "rebuilt": block},
                {"status": "delete", "confidence": "high", "original": {**block, "index": 1, "offset": 1, "end_offset": 2}, "rebuilt": None},
            ]
        }
        text = "\n".join(_format_full_block_map(alignment, differences_only=True))
        self.assertNotIn("B000", text)
        self.assertIn("B001", text)

    def test_hard_discrepancy_prefers_aggregate_direction_over_local_gap(self) -> None:
        call = {"offset": 10, "kind": "direct", "target": "logcommonhistory"}
        alignment = {
            "rows": [
                {"status": "insert", "confidence": "high", "original": None, "rebuilt": call},
            ]
        }
        rows = _hard_discrepancies(
            alignment,
            [],
            [{"kind": "direct", "target": "logcommonhistory", "original": 2, "rebuilt": 1, "delta": -1}],
        )
        self.assertEqual(rows[0]["kind"], "aggregate-call-count")
        self.assertIn("missing 1 rebuilt", rows[0]["message"])
        self.assertFalse(any("extra rebuilt call" in row["message"] for row in rows))


if __name__ == "__main__":
    unittest.main()
