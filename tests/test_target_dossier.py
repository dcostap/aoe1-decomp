from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from function_diagnostics import decode_instructions  # noqa: E402
import target_dossier  # noqa: E402
from target_dossier import (  # noqa: E402
    collect_memory_evidence,
    infer_memory_access,
    infer_memory_width,
    infer_class_name,
    parse_memory_expression,
    _ret_cleanup_bytes,
    build_evidence_bands,
)


class TargetDossierTests(unittest.TestCase):
    def test_absolute_address_joins_reviewed_shared_global_evidence(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "config").mkdir(parents=True)
            (root / "inventory" / "globals").mkdir(parents=True)
            (root / "inventory" / "globals" / "all_globals.csv").write_text(
                "va,primary_name\n", encoding="utf-8"
            )
            (root / "config" / "shared_abi_evidence.json").write_text(
                '{"version":1,"globals":[{'
                '"name":"known_global","storage_va":"00123456",'
                '"declaration":"extern int* known_global;",'
                '"header":"include/known.h","codegen_note":"Use the symbol."'
                '}]}',
                encoding="utf-8",
            )
            rows = [{"address": "00123456"}]
            with patch.object(target_dossier, "REPO_ROOT", root):
                target_dossier._annotate_globals(rows)
            self.assertEqual(rows[0]["global"]["primary_name"], "known_global")
            self.assertEqual(
                rows[0]["shared_global_evidence"]["declaration"],
                "extern int* known_global;",
            )

    def test_memory_expression_retains_fixed_offset_and_index_evidence(self) -> None:
        parsed = parse_memory_expression("esi+eax*4+504h")
        self.assertEqual(parsed["registers"], ["esi", "eax"])
        self.assertEqual(parsed["fixed_displacement"], 0x504)
        self.assertEqual(parsed["indexed_terms"], ["eax*4"])

    def test_width_ignores_address_register(self) -> None:
        self.assertEqual(infer_memory_width("mov al,[esi+51Ch]"), 1)
        self.assertEqual(infer_memory_width("mov [esi+4E4h],eax"), 4)
        self.assertEqual(infer_memory_width("fld qword [eax]"), 8)

    def test_fpu_and_indirect_call_memory_are_reads(self) -> None:
        self.assertEqual(infer_memory_access("fmul dword [esi+4FCh]", 16), "read")
        self.assertEqual(infer_memory_access("call dword [88A594h]", 11), "read")

    def test_this_alias_collection_groups_binary_observed_widths(self) -> None:
        # mov esi,ecx; mov al,[esi+51c]; mov [esi+4e4],eax
        instructions = decode_instructions(
            bytes.fromhex("8bf18a861c0500008986e4040000"), 0x005204A0
        )
        evidence = collect_memory_evidence(instructions, [])
        fields = {(row["offset"], row["width"], row["access"]) for row in evidence["this_fields"]}
        self.assertIn((0x51C, 1, "read"), fields)
        self.assertIn((0x4E4, 4, "write"), fields)

    def test_class_inference_ignores_qualified_calls_inside_function(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / "demo.cpp"
            source.write_text(
                "unsigned char Derived::check()\n"
                "{\n"
                "    return Base::check();\n"
                "}\n",
                encoding="utf-8",
            )
            self.assertEqual(infer_class_name(source), "Derived")

    def test_class_check_flags_fixed_access_past_generated_size(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            types = root / "inventory" / "types"
            types.mkdir(parents=True)
            (types / "all_types.csv").write_text(
                "name,kind,base,size_bytes,size_hex,field_count,gap_count,start_line,end_line\n"
                "Small,class,,16,0x10,0,0,1,1\n",
                encoding="utf-8",
            )
            with patch.object(target_dossier, "REPO_ROOT", root):
                result = target_dossier._class_check(
                    "Small", [{"offset": 0x10, "offset_hex": "0x10", "width": 4, "indexed": False}]
                )
            self.assertEqual(result["status"], "conflict")
            self.assertIn("cannot contain", result["warnings"][0])

    def test_stack_normalization_identifies_parameter_home_address_and_write(self) -> None:
        # sub esp,8; lea eax,[esp+0c] (entry +4); push ecx;
        # mov [esp+10],eax (still entry +4)
        instructions = decode_instructions(bytes.fromhex("83ec088d44240c5189442410"), 0x1000)
        evidence = collect_memory_evidence(instructions, [])
        homes = evidence["parameter_home_evidence"]
        self.assertEqual({row["access"] for row in homes}, {"address", "write"})
        self.assertTrue(all(row["entry_coordinate"] == 4 for row in homes))
        self.assertEqual(evidence["stack_normalization"]["coverage_percent"], 100.0)

    def test_stack_normalization_stops_after_unknown_indirect_cleanup(self) -> None:
        # sub esp,8; call eax; mov eax,[esp+0c]
        instructions = decode_instructions(bytes.fromhex("83ec08ffd08b44240c"), 0x1000)
        evidence = collect_memory_evidence(instructions, [])
        self.assertIsNone(evidence["stack"][0]["entry_coordinate"])

    def test_ret_cleanup_requires_one_consistent_return_size(self) -> None:
        self.assertEqual(_ret_cleanup_bytes(bytes.fromhex("c20800"), 0x1000), 8)
        self.assertEqual(_ret_cleanup_bytes(bytes.fromhex("c3"), 0x1000), 0)
        self.assertIsNone(_ret_cleanup_bytes(bytes.fromhex("c3c20400"), 0x1000))

    def test_pdb_evidence_bands_group_calls_fields_and_blocks_by_line_change(self) -> None:
        instructions = decode_instructions(bytes.fromhex("8bf18a4610e800000000c3"), 0x1000)
        changes = [
            {"address": "00001000", "source_file": "a.cpp", "source_path": "a.cpp", "line_number": "10"},
            {"address": "00001005", "source_file": "a.cpp", "source_path": "a.cpp", "line_number": "11"},
        ]
        memory = collect_memory_evidence(instructions, changes)
        calls = [{"offset": 5, "address": "00001005", "kind": "direct", "target": "helper", "display": "helper", "block_index": 0}]
        bands = build_evidence_bands(instructions, changes, calls, memory)
        self.assertEqual([band["source_line"] for band in bands], [10, 11])
        self.assertEqual(bands[0]["this_fields"][0]["offset_hex"], "0x10")
        self.assertEqual(bands[1]["calls"][0]["target"], "helper")


if __name__ == "__main__":
    unittest.main()
