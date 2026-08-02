from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from coff import CoffRelocation, CoffSection, _merge_sections  # noqa: E402
from extract_obj_function import extraction_extent, meaningful_code_size  # noqa: E402
from function_diagnostics import (  # noqa: E402
    basic_blocks,
    block_alignment,
    call_alignment,
    call_count_deltas,
    call_fingerprint,
    call_target_counts,
    clean_symbol_name,
    compatible_relocation_masks,
    decode_instruction_ranges,
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
        self.assertEqual(
            clean_symbol_name("??_L@YGXPAXIHP6EX0@Z1@Z"),
            "eh_vector_constructor_iterator",
        )
        self.assertEqual(
            clean_symbol_name("`eh_vector_constructor_iterator'"),
            "eh_vector_constructor_iterator",
        )
        self.assertEqual(
            clean_symbol_name("??_M@YGXPAXIHP6EX0@Z@Z"),
            "eh_vector_destructor_iterator",
        )
        self.assertEqual(
            clean_symbol_name("?eh_vector_destructor_iterator@@YGXPAXHH0@Z"),
            "eh_vector_destructor_iterator",
        )

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

    def test_discontiguous_original_ranges_keep_real_addresses_and_combined_offsets(self) -> None:
        instructions = decode_instruction_ranges(
            bytes.fromhex("90 C3 90 C3"),
            [
                {"start": "00001000", "size_bytes": 2},
                {"start": "00002000", "size_bytes": 2},
            ],
        )
        self.assertEqual([row.address for row in instructions], [0x1000, 0x1001, 0x2000, 0x2001])
        self.assertEqual([row.offset for row in instructions], [0, 1, 2, 3])
        blocks = basic_blocks(instructions, [])
        self.assertEqual([row["offset"] for row in blocks], [0, 2])

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

    def test_loaded_vtable_slot_call_is_identified(self) -> None:
        # mov eax,[ecx]; mov edx,[eax+28h]; call edx; ret
        instructions = decode_instructions(bytes.fromhex("8B 01 8B 50 28 FF D2 C3"), 0x1000)
        calls = call_fingerprint(instructions, original=False)
        self.assertEqual([(row["kind"], row["target"]) for row in calls], [("virtual", "vslot+0x28")])
        self.assertEqual(calls[0]["block_offset"], 0)

    def test_stack_spilled_vtable_slot_tracks_push_adjustments(self) -> None:
        # mov eax,[ecx]; mov edx,[eax+10Ch]; mov [esp+14h],edx;
        # push four args; call dword [esp+24h]; ret
        instructions = decode_instructions(
            bytes.fromhex("8B 01 8B 90 0C 01 00 00 89 54 24 14 6A 01 6A 02 6A 03 6A 04 FF 54 24 24 C3"),
            0x1000,
        )
        calls = call_fingerprint(instructions, original=False)
        self.assertEqual([(row["kind"], row["target"]) for row in calls], [("virtual", "vslot+0x10C")])

    def test_unproven_esp_indirect_call_is_not_a_virtual_slot(self) -> None:
        instructions = decode_instructions(bytes.fromhex("FF 54 24 24 C3"), 0x1000)
        calls = call_fingerprint(instructions, original=False)
        self.assertEqual([(row["kind"], row["target"]) for row in calls], [("indirect", "indirect")])

    def test_call_alignment_marks_contextual_slot_replacement(self) -> None:
        original = [
            {"offset": 1, "kind": "direct", "target": "a", "display": "a", "setup": ["push 1"], "previous_targets": [], "next_targets": ["b"]},
            {"offset": 5, "kind": "direct", "target": "b", "display": "b", "setup": ["push 2"], "previous_targets": ["a"], "next_targets": ["vslot+0x28"]},
            {"offset": 9, "kind": "virtual", "target": "vslot+0x28", "display": "vslot+0x28", "setup": ["mov reg,[reg]"], "previous_targets": ["a", "b"], "next_targets": []},
        ]
        rebuilt = [
            {**original[0]},
            {**original[1], "next_targets": ["vslot+0x38"]},
            {**original[2], "target": "vslot+0x38", "display": "vslot+0x38"},
        ]
        alignment = call_alignment(original, rebuilt)
        self.assertEqual(alignment["aligned_prefix_calls"], 2)
        self.assertEqual(alignment["rows"][-1]["status"], "replace")
        self.assertIn(alignment["rows"][-1]["confidence"], {"medium", "high"})

    def test_call_alignment_marks_unique_gap_between_anchors_high_confidence(self) -> None:
        def call(offset: int, target: str) -> dict[str, object]:
            return {
                "offset": offset,
                "kind": "direct",
                "target": target,
                "display": target,
                "setup": [],
                "previous_targets": [],
                "next_targets": [],
            }

        alignment = call_alignment(
            [call(1, "a"), call(2, "missing"), call(3, "c")],
            [call(1, "a"), call(3, "c")],
        )
        gap = next(row for row in alignment["rows"] if row["status"] == "delete")
        self.assertEqual(gap["confidence"], "high")

    def test_basic_block_alignment_finds_exact_island_after_changed_entry(self) -> None:
        original_instructions = decode_instructions(bytes.fromhex("85 C0 74 01 90 C3"), 0x1000)
        rebuilt_instructions = decode_instructions(bytes.fromhex("83 F8 00 74 01 90 C3"), 0x1000)
        original_blocks = basic_blocks(original_instructions, [])
        rebuilt_blocks = basic_blocks(rebuilt_instructions, [])
        alignment = block_alignment(original_blocks, rebuilt_blocks)
        self.assertGreaterEqual(len(alignment["strong_islands"]), 1)
        self.assertIsNotNone(alignment["first_difference_row"])

    def test_block_alignment_reports_unique_relocated_exact_block(self) -> None:
        def block(index: int, offset: int, signature: str) -> dict[str, object]:
            return {
                "index": index,
                "offset": offset,
                "end_offset": offset + 1,
                "instruction_count": 1,
                "shapes": [signature],
                "signature": signature,
                "terminator": signature,
                "successors": [],
                "calls": [],
            }

        alignment = block_alignment(
            [block(0, 0, "a"), block(1, 1, "b"), block(2, 2, "c")],
            [block(0, 0, "a"), block(1, 1, "c"), block(2, 2, "b")],
        )
        self.assertTrue(alignment["relocated_pairs"])
        pair = alignment["relocated_pairs"][0]
        self.assertTrue(pair["exact"])
        self.assertEqual(pair["original"]["signature"], pair["rebuilt"]["signature"])

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
