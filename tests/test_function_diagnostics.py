from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from coff import CoffRelocation, CoffSection, _merge_sections  # noqa: E402
from extract_obj_function import extraction_extent, meaningful_code_size  # noqa: E402
from function_diagnostics import (  # noqa: E402
    call_count_deltas,
    call_target_counts,
    clean_symbol_name,
    compatible_relocation_masks,
    decode_instructions,
    instruction_alignment,
    iteration_delta,
)


class CoffAndDiagnosticTests(unittest.TestCase):
    def test_duplicate_section_relocations_are_rebased(self) -> None:
        first = CoffSection(".text", b"AAAA", [CoffRelocation(1, 2, 0x14, 4)])
        second = CoffSection(".text", b"BBBBBB", [CoffRelocation(2, 3, 0x14, 4)])
        merged = _merge_sections([first, second], ".text")
        self.assertEqual(merged.data, b"AAAABBBBBB")
        self.assertEqual([row.offset for row in merged.relocations], [1, 6])

    def test_meaningful_size_ignores_only_trailing_compiler_padding(self) -> None:
        self.assertEqual(meaningful_code_size(bytes.fromhex("C3 90 90")), 1)
        self.assertEqual(meaningful_code_size(bytes.fromhex("90 C3 CC")), 2)
        self.assertEqual(meaningful_code_size(bytes.fromhex("C3 00")), 2)

    def test_extraction_extent_keeps_overflow_code_but_not_alignment_nops(self) -> None:
        padded = extraction_extent(bytes.fromhex("C3 90 90 90"), 1)
        self.assertEqual(padded["comparison_size"], 1)
        self.assertEqual(padded["overflow_offsets"], [])

        auxiliary = extraction_extent(bytes.fromhex("C3 90 90 90 55 C3 90 90"), 4)
        self.assertEqual(auxiliary["comparison_size"], 4)
        self.assertFalse(auxiliary["has_code_overflow"])

        oversized = extraction_extent(bytes.fromhex("53 5B 90 90 55 C3 90 90"), 4)
        self.assertEqual(oversized["comparison_size"], 6)
        self.assertEqual(oversized["overflow_offsets"], [4, 5])
        self.assertTrue(oversized["has_code_overflow"])

        table_target = extraction_extent(bytes.fromhex("FF 20 C3 90 55 C3 90 90"), 4, [4])
        self.assertTrue(table_target["has_code_overflow"])
        self.assertIn(4, table_target["boundary_escape_offsets"])

    def test_vc5_decorated_special_names_are_normalized(self) -> None:
        self.assertEqual(clean_symbol_name("??2@YAPAXI@Z"), "operator_new")
        self.assertEqual(clean_symbol_name("??0RGE_Action_List@@QAE@XZ"), "rge_action_list")
        self.assertEqual(clean_symbol_name("~RGE_Action_List"), "rge_action_list")
        self.assertEqual(clean_symbol_name("?type@TacticalAIGroup@@QAEHXZ"), "type")

    def test_relocation_is_not_masked_across_different_instruction_shapes(self) -> None:
        original = bytes.fromhex("B8 11 22 33 44 C3")  # mov eax,imm32
        rebuilt = bytes.fromhex("68 00 00 00 00 C3")   # push imm32
        left, right, info = compatible_relocation_masks(
            original,
            rebuilt,
            [{"offset": 1, "width": 4, "symbol_name": "_value"}],
            0x1000,
        )
        self.assertEqual(left, original)
        self.assertEqual(right, rebuilt)
        self.assertEqual(info["compatible"], 0)
        self.assertEqual(info["incompatible"], 1)

    def test_instruction_alignment_resynchronizes_at_instruction_level(self) -> None:
        original = decode_instructions(bytes.fromhex("53 8B D8 5B C3"), 0x1000)
        rebuilt = decode_instructions(bytes.fromhex("90 53 8B D8 5B C3"), 0x1000)
        alignment = instruction_alignment(original, rebuilt)
        self.assertEqual(alignment["equal_instructions"], 4)
        self.assertEqual(alignment["similarity_percent"], 80.0)

    def test_call_count_deltas_prioritize_largest_target_gaps(self) -> None:
        original = call_target_counts(
            [
                {"kind": "direct", "target": "setaction"},
                {"kind": "direct", "target": "setaction"},
                {"kind": "direct", "target": "object"},
                {"kind": "virtual", "target": "vslot+0x198"},
            ]
        )
        rebuilt = call_target_counts(
            [
                {"kind": "direct", "target": "object"},
                {"kind": "direct", "target": "object"},
                {"kind": "direct", "target": "isenemy"},
                {"kind": "virtual", "target": "vslot+0x198"},
            ]
        )
        deltas = call_count_deltas(original, rebuilt)
        self.assertEqual(
            [(row["target"], row["delta"]) for row in deltas],
            [("setaction", -2), ("isenemy", 1), ("object", 1)],
        )

    def test_iteration_delta_reports_direction(self) -> None:
        result = iteration_delta(
            bytes.fromhex("AA BB CC DD"),
            bytes.fromhex("00 BB CC 00"),
            bytes.fromhex("AA 00 CC 11"),
        )
        self.assertEqual(result["changed_bytes"], 3)
        self.assertEqual(result["strict_improvements"], 1)
        self.assertEqual(result["strict_regressions"], 1)
        self.assertEqual(result["neutral_changes"], 1)
        self.assertEqual([(row["start"], row["end"]) for row in result["ranges"]], [(0, 2), (3, 4)])


if __name__ == "__main__":
    unittest.main()
