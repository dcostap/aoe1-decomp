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
    direct_call_symbols_match,
    compatible_relocation_masks,
    decode_instruction_ranges,
    decode_instructions,
    instruction_alignment,
    iteration_delta,
    owning_function_symbol_validation,
)
from mismatch_classifier import classify_mismatch  # noqa: E402


class CoffAndDiagnosticTests(unittest.TestCase):
    def _classify(
        self,
        original_hex: str,
        rebuilt_hex: str,
        *,
        call_map: dict[str, object] | None = None,
        call_target_deltas: list[dict[str, object]] | None = None,
        target_mismatches: list[dict[str, object]] | None = None,
        cfg_issues: list[dict[str, object]] | None = None,
        owner_symbol_mismatch: dict[str, object] | None = None,
    ) -> dict[str, object]:
        original_bytes = bytes.fromhex(original_hex)
        rebuilt_bytes = bytes.fromhex(rebuilt_hex)
        original = decode_instructions(original_bytes, 0x1000)
        rebuilt = decode_instructions(rebuilt_bytes, 0x1000)
        return classify_mismatch(
            original,
            rebuilt,
            original_bytes,
            rebuilt_bytes,
            shape=instruction_alignment(original, rebuilt),
            call_map=call_map or {"rows": []},
            call_target_deltas=call_target_deltas or [],
            target_mismatches=target_mismatches or [],
            cfg_issues=cfg_issues or [],
            owner_symbol_mismatch=owner_symbol_mismatch,
        )

    def test_mismatch_classifier_reports_consistent_register_recolor(self) -> None:
        result = self._classify(
            "8B 01 03 41 04 50 C3",  # mov/add/push through eax
            "8B 11 03 51 04 52 C3",  # same forms through edx
        )
        self.assertEqual(result["primary"], "CONSISTENT_REGISTER_RECOLOR")
        self.assertEqual(result["register_map"], {"EAX": "EDX"})
        self.assertFalse(result["establishes_equivalence"])

    def test_mismatch_classifier_rejects_conflicting_register_map(self) -> None:
        result = self._classify(
            "8B C1 03 C2 C3",  # eax is the destination twice
            "8B D1 03 C3 C3",  # rebuilt destinations disagree
        )
        self.assertEqual(result["primary"], "REGISTER_MAP_CONFLICT")
        self.assertTrue(result["register_map_conflicts"])

    def test_mismatch_classifier_reports_compare_reversal_without_equivalence(self) -> None:
        result = self._classify(
            "39 D8 7C 01 90 C3",  # cmp eax,ebx; jl
            "39 C3 7F 01 90 C3",  # cmp ebx,eax; jg
        )
        self.assertEqual(result["primary"], "COMPARE_OPERAND_OR_BRANCH_FORM")
        self.assertTrue(result["compare_events"][0]["compatible_jump_reversal"])
        self.assertFalse(result["establishes_equivalence"])

    def test_mismatch_classifier_flags_test_swap_with_changed_branch(self) -> None:
        result = self._classify(
            "85 D8 7F 01 90 C3",  # test eax,ebx; jg
            "85 C3 7C 01 90 C3",  # test ebx,eax; jl (not equivalent)
        )
        self.assertEqual(result["primary"], "TEST_OPERAND_WITH_BRANCH_CHANGE")
        self.assertTrue(result["test_events"][0]["branch_changed"])

    def test_mismatch_classifier_reports_test_operand_order_with_same_branch(self) -> None:
        result = self._classify(
            "85 D8 74 01 90 C3",  # test eax,ebx; je
            "85 C3 74 01 90 C3",  # test ebx,eax; je
        )
        self.assertEqual(result["primary"], "TEST_OPERAND_ORDER")
        self.assertFalse(result["test_events"][0]["branch_changed"])

    def test_mismatch_classifier_does_not_recolor_stack_pointer(self) -> None:
        result = self._classify(
            "8B C4 C3",  # mov eax,esp
            "8B C1 C3",  # mov eax,ecx
        )
        self.assertEqual(result["primary"], "REGISTER_MAP_CONFLICT")
        self.assertIn("stack-pointer", result["register_map_conflicts"][0])

    def test_mismatch_classifier_reports_x87_operand_order(self) -> None:
        result = self._classify(
            "D9 45 FC D8 4D F8 C3",  # fld [ebp-4]; fmul [ebp-8]
            "D9 45 F8 D8 4D FC C3",  # fld [ebp-8]; fmul [ebp-4]
        )
        self.assertEqual(result["primary"], "X87_OPERATION_ORDER")
        self.assertEqual(len(result["x87_events"]), 1)

    def test_mismatch_classifier_prioritizes_call_surface(self) -> None:
        result = self._classify(
            "90 C3",
            "91 C3",
            call_map={"rows": [{"status": "replace"}]},
        )
        self.assertEqual(result["primary"], "CALL_SURFACE_DIFFERENCE")

    def test_mismatch_classifier_exact_result_has_no_mismatch_labels(self) -> None:
        result = self._classify("8B C1 C3", "8B C1 C3")
        self.assertEqual(result["primary"], "EXACT")
        self.assertEqual(result["labels"], [])

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

    def test_direct_call_decorated_overloads_keep_full_identity(self) -> None:
        string_overload = "??6ostream@@QAEAAV0@PBD@Z"
        self.assertTrue(direct_call_symbols_match(string_overload, string_overload))
        self.assertTrue(direct_call_symbols_match(string_overload, "__imp_" + string_overload))
        self.assertFalse(
            direct_call_symbols_match(string_overload, "??6ostream@@QAEAAV0@N@Z")
        )
        self.assertFalse(direct_call_symbols_match("operator<<", string_overload))
        self.assertTrue(direct_call_symbols_match("~RGE_Action", "??1RGE_Action@@UAE@XZ"))
        self.assertFalse(direct_call_symbols_match("~RGE_Action", "??0RGE_Action@@QAE@XZ"))

    def test_vc5_stack_probe_export_aliases_match(self) -> None:
        self.assertTrue(direct_call_symbols_match("__alloca_probe", "__chkstk"))
        self.assertTrue(direct_call_symbols_match("__chkstk", "__alloca_probe"))
        self.assertFalse(direct_call_symbols_match("__alloca_probe", "__ftol"))

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

    def test_tail_jump_relocation_requires_the_original_target(self) -> None:
        original = bytes.fromhex("E9 BB 54 00 00")  # 00402030 -> 004074F0 ~RGE_Action
        rebuilt = bytes.fromhex("E9 00 00 00 00")
        left, right, info = compatible_relocation_masks(
            original,
            rebuilt,
            [{"offset": 1, "width": 4, "symbol_name": "?parent_destroy@RGE_Action@@QAEXXZ"}],
            0x00402030,
        )
        self.assertNotEqual(left, right)
        self.assertEqual(info["compatible"], 0)
        self.assertEqual(info["target_mismatches"][0]["kind"], "tail-jump")

        left, right, info = compatible_relocation_masks(
            original,
            rebuilt,
            [{"offset": 1, "width": 4, "symbol_name": "??1RGE_Action@@UAE@XZ"}],
            0x00402030,
        )
        self.assertEqual(left, right)
        self.assertEqual(info["compatible"], 1)
        self.assertEqual(info["target_mismatches"], [])

    def test_original_operator_override_preserves_overload_identity(self) -> None:
        original = (b"\x90" * 29) + bytes.fromhex("E8 8E ED FF FF")
        rebuilt = (b"\x90" * 29) + bytes.fromhex("E8 00 00 00 00")
        left, right, info = compatible_relocation_masks(
            original,
            rebuilt,
            [
                {
                    "offset": 30,
                    "width": 4,
                    "symbol_name": "??8@YAHABVConstructionItem@@0@Z",
                }
            ],
            0x0040BBB0,
        )
        self.assertEqual(left, right)
        self.assertEqual(info["compatible"], 1)
        self.assertEqual(info["target_mismatches"], [])

    def test_owning_symbol_validation_rejects_a_different_method(self) -> None:
        valid = owning_function_symbol_validation(
            "~RGE_Action_Bird", "??1RGE_Action_Bird@@UAE@XZ"
        )
        invalid = owning_function_symbol_validation(
            "~RGE_Action_Bird", "?destroy@RGE_Action_Bird@@QAEXXZ"
        )
        wrong_kind = owning_function_symbol_validation(
            "~RGE_Action_Bird", "??0RGE_Action_Bird@@QAE@XZ"
        )
        wrong_reverse_kind = owning_function_symbol_validation(
            "RGE_Action_Bird", "??1RGE_Action_Bird@@UAE@XZ"
        )
        ambiguous = owning_function_symbol_validation(
            "`vector_deleting_destructor'", "??_GRGE_Action_Bird@@UAEPAXI@Z"
        )
        self.assertEqual(valid["status"], "match")
        self.assertEqual(invalid["status"], "mismatch")
        self.assertEqual(wrong_kind["status"], "mismatch")
        self.assertEqual(wrong_reverse_kind["status"], "mismatch")
        self.assertEqual(ambiguous["status"], "unverified")

    def test_owning_symbol_validation_rejects_wrong_pdb_class(self) -> None:
        valid = owning_function_symbol_validation(
            "reset_attack_timer",
            "?reset_attack_timer@RGE_Combat_Object@@QAEXXZ",
            "RGE_Combat_Object::reset_attack_timer",
        )
        wrong_class = owning_function_symbol_validation(
            "reset_attack_timer",
            "?reset_attack_timer@SomeClass@@QAEXXZ",
            "RGE_Combat_Object::reset_attack_timer",
        )
        free_function = owning_function_symbol_validation(
            "importantUnit",
            "?importantUnit@@YGHH@Z",
            "TribeInformationAIModule::importantUnit",
        )
        self.assertEqual(valid["status"], "match")
        self.assertEqual(wrong_class["status"], "mismatch")
        self.assertEqual(free_function["status"], "mismatch")

    def test_owning_symbol_validation_accepts_pdb_stdcall_name(self) -> None:
        valid = owning_function_symbol_validation(
            "_WinMain@16", "_WinMain@16", "WinMain"
        )
        wrong_pdb_name = owning_function_symbol_validation(
            "_WinMain@16", "_WinMain@16", "OtherMain"
        )
        self.assertEqual(valid["status"], "match")
        self.assertEqual(wrong_pdb_name["status"], "mismatch")

    def test_owning_symbol_validation_accepts_vc5_operators(self) -> None:
        member = owning_function_symbol_validation(
            "operator+=",
            "??YResourceItem@@QAEAAV0@ABV0@@Z",
            "ResourceItem::operator+=",
        )
        free_equal = owning_function_symbol_validation(
            "operator==",
            "??8@YAHABVResourceItem@@0@Z",
            "operator==",
        )
        wrong_owner = owning_function_symbol_validation(
            "operator+=",
            "??YOtherItem@@QAEAAV0@ABV0@@Z",
            "ResourceItem::operator+=",
        )
        self.assertEqual(member["status"], "match")
        self.assertEqual(free_equal["status"], "match")
        self.assertEqual(wrong_owner["status"], "mismatch")

    def test_mismatch_classifier_reports_owner_symbol_difference(self) -> None:
        result = self._classify(
            "E9 00 00 00 00",
            "E9 00 00 00 00",
            owner_symbol_mismatch={
                "expected": "~RGE_Action_Bird",
                "rebuilt": "?destroy@RGE_Action_Bird@@QAEXXZ",
            },
        )
        self.assertEqual(result["primary"], "FUNCTION_SYMBOL_DIFFERENCE")

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
