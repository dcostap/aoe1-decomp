from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import query_abi  # noqa: E402
from shared_abi_evidence import load_shared_global_evidence  # noqa: E402


class QueryAbiTests(unittest.TestCase):
    def test_reviewed_global_declaration_matches_shared_header(self) -> None:
        rows = load_shared_global_evidence(REPO_ROOT)
        row = next(item for item in rows if item["name"] == "rge_base_game")
        header = REPO_ROOT / str(row["header"])
        self.assertIn(str(row["declaration"]), header.read_text(encoding="utf-8"))

    def test_va_query_reports_reviewed_global_used_by_target_source(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "config").mkdir(parents=True)
            (root / "src" / "scratch").mkdir(parents=True)
            (root / "config" / "shared_abi_evidence.json").write_text(
                '{"version":1,"globals":[{'
                '"name":"known_global","storage_va":"00123456",'
                '"declaration":"extern int* known_global;",'
                '"header":"include/known.h","codegen_note":"Use the symbol.",'
                '"evidence":[{"va":"00001000","observation":"Reduced the difference."}]'
                '}]}',
                encoding="utf-8",
            )
            (root / "src" / "scratch" / "00001000_demo.cpp").write_text(
                "void demo() { if (known_global) return; }\n", encoding="utf-8"
            )
            record = {
                "va": "00001000",
                "name": "demo",
                "calling_convention": "__cdecl",
                "size_bytes": "4",
                "pdb_source_file": "demo.cpp",
                "pdb_source_path": "demo.cpp",
                "slug": "00001000_demo",
            }
            with (
                patch.object(query_abi, "REPO_ROOT", root),
                patch.object(query_abi, "load_functions", return_value=[record]),
            ):
                payload = query_abi.build_query(va="00001000")
            self.assertEqual(payload["shared_globals"][0]["name"], "known_global")
            self.assertEqual(payload["shared_globals"][0]["matched_by"], "name")

    def test_reference_kind_separates_declaration_from_call(self) -> None:
        self.assertEqual(
            query_abi._reference_kind("void rge_read(int file, void* out, int size);", "rge_read"),
            "declaration_candidate",
        )
        self.assertEqual(
            query_abi._reference_kind("rge_read(file, &value, 4);", "rge_read"),
            "call_or_multiline_signature",
        )
        self.assertEqual(
            query_abi._reference_kind("this->rge_read(file);", "rge_read"),
            "call_or_multiline_signature",
        )

    def test_source_evidence_defaults_to_exact_bucket(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            matching = root / "src" / "matching"
            scratch = root / "src" / "scratch"
            matching.mkdir(parents=True)
            scratch.mkdir(parents=True)
            (matching / "00001000_exact.cpp").write_text("void helper(int);\n", encoding="utf-8")
            (scratch / "00002000_work.cpp").write_text("void helper(short);\n", encoding="utf-8")
            with patch.object(query_abi, "REPO_ROOT", root):
                exact = query_abi.source_evidence("helper")
                all_rows = query_abi.source_evidence("helper", include_nonexact=True)
            self.assertEqual([row["bucket"] for row in exact], ["matching"])
            self.assertEqual({row["bucket"] for row in all_rows}, {"matching", "scratch"})

    def test_symbol_class_lookup_can_find_method_without_dumping_unrelated_methods(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            types = root / "inventory" / "types"
            classes = root / "inventory" / "classes"
            types.mkdir(parents=True)
            classes.mkdir(parents=True)
            (types / "all_types.csv").write_text(
                "name,kind,base,size_bytes,size_hex,field_count,gap_count,start_line,end_line\n"
                "Player,class,Base,32,0x20,2,0,1,2\n",
                encoding="utf-8",
            )
            (classes / "all_class_interfaces.csv").write_text(
                "class_name,donor_header,class_confidence,class_evidence,method_kind,method_name,declaration,slot_index,slot_hex,method_confidence,method_evidence\n"
                "Player,p.h,high,donor,virtual,relation,virtual int relation(int),1,0X4,high,slot\n"
                "Player,p.h,high,donor,virtual,other,virtual void other(),2,0X8,high,slot\n",
                encoding="utf-8",
            )
            with patch.object(query_abi, "REPO_ROOT", root):
                rows = query_abi.class_matches("relation", methods_only_match=True)
            self.assertEqual(rows[0]["class_name"], "Player")
            self.assertEqual([method["name"] for method in rows[0]["methods"]], ["relation"])

    def test_declaration_candidates_count_exact_and_nonexact_provenance(self) -> None:
        rows = [
            {"kind": "declaration_candidate", "text": "void f(int);", "bucket": "matching", "path": "a", "line": 1},
            {"kind": "declaration_candidate", "text": "void  f(int);", "bucket": "matching", "path": "b", "line": 2},
            {"kind": "declaration_candidate", "text": "int f(short);", "bucket": "scratch", "path": "c", "line": 3},
            {"kind": "call_or_multiline_signature", "text": "f(1);", "bucket": "matching", "path": "d", "line": 4},
        ]
        candidates = query_abi.declaration_candidates(rows, "f")
        self.assertEqual(candidates[0]["declaration"], "void f(int);")
        self.assertEqual(candidates[0]["exact_occurrences"], 2)
        self.assertEqual(candidates[1]["nonexact_occurrences"], 1)

    def test_normalized_abi_ignores_parameter_names_but_preserves_linkage_and_convention(self) -> None:
        left = query_abi.normalize_declaration(
            'extern "C" void __cdecl rge_read(int handle, void* buffer, int size);', "rge_read"
        )
        right = query_abi.normalize_declaration(
            'extern "C" void __cdecl rge_read(int param_1, void * param_2, int param_3);', "rge_read"
        )
        cpp = query_abi.normalize_declaration(
            'void __cdecl rge_read(int handle, void* buffer, int size);', "rge_read"
        )
        self.assertEqual(left["canonical"], right["canonical"])
        self.assertNotEqual(left["canonical"], cpp["canonical"])
        self.assertEqual(left["parameter_types"], ["int", "void*", "int"])


if __name__ == "__main__":
    unittest.main()
