from __future__ import annotations

import copy
import json
import sys
import tempfile
import unittest
from contextlib import contextmanager
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

import common  # noqa: E402
import validate_candidate_tu as candidate_module  # noqa: E402
import validate_translation_units as tu_module  # noqa: E402


VA = "0050B840"
SYMBOL = "??0TRIBE_Tech@@QAE@HPAVTRIBE_World@@@Z"


def _source_module(status: str = "scratch") -> dict[str, object]:
    return {
        "schema": 1,
        "name": "tech_test",
        "pdb_source_path": ".\\Release\\tech.obj",
        "pdb_no_line_info": True,
        "pdb_module_stream_evidence": "inventory/pdb/module_streams/0027_tech.json",
        "source": "src/tech.cpp",
        "header": "include/tech.h",
        "functions": {VA: {"status": status}},
    }


@contextmanager
def _source_module_config(payload: dict[str, object]):
    with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp_dir:
        module_dir = Path(temp_dir)
        module_dir.joinpath("tech_test.json").write_text(
            json.dumps(payload), encoding="utf-8"
        )
        old_dir = common.SOURCE_MODULES_DIR
        common.SOURCE_MODULES_DIR = module_dir
        common.load_source_modules.cache_clear()
        try:
            yield
        finally:
            common.SOURCE_MODULES_DIR = old_dir
            common.load_source_modules.cache_clear()


class PdbNoLineInfoTests(unittest.TestCase):
    def test_tech_is_a_no_line_source_module(self) -> None:
        tech = common.source_module_for_name("tech")
        self.assertIsNotNone(tech)
        assert tech is not None
        self.assertTrue(tech["pdb_no_line_info"])
        self.assertEqual(tech["source"], "src/tech.cpp")
        self.assertEqual(len(tech["functions"]), 33)
        self.assertEqual([], common.validate_source_modules())

    def test_common_rejects_non_boolean_no_line_flag(self) -> None:
        payload = _source_module()
        payload["pdb_no_line_info"] = "true"
        with _source_module_config(payload):
            with self.assertRaisesRegex(ValueError, "must be Boolean"):
                common.load_source_modules()

    def test_common_accepts_empty_stream_metadata(self) -> None:
        with _source_module_config(_source_module()), patch.object(
            common,
            "load_pdb_function_source_map",
            return_value={VA: {"has_line_info": "0", "primary_source_path": ""}},
        ):
            self.assertEqual([], common.validate_source_modules())

    def test_common_rejects_line_or_source_data(self) -> None:
        with _source_module_config(_source_module()), patch.object(
            common,
            "load_pdb_function_source_map",
            return_value={
                VA: {
                    "has_line_info": "1",
                    "primary_source_path": "C:\\msdev\\work\\tech.cpp",
                }
            },
        ):
            issues = common.validate_source_modules()
        self.assertTrue(any("PDB line/source data" in issue for issue in issues))

    def test_candidate_accepts_stream_owned_no_line_symbol(self) -> None:
        source_module = _source_module("matching")
        payload = {
            "module": ".\\Release\\tech.obj",
            "source": "src/tech.cpp",
            "flags": "config/flags/tech.rsp",
            "owners": {VA: "src/tech.cpp"},
            "observed": {},
            "generated": {},
            "symbols": {VA: SYMBOL},
        }
        entry = {"module": source_module, "status": "matching", "note_path": ""}
        pdb_symbol = common.function_record_by_va(int(VA, 16))["name"]
        with patch.object(
            candidate_module, "source_module_entry_for_va", return_value=entry
        ), patch.object(
            candidate_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(
            candidate_module,
            "load_pdb_function_source_map",
            return_value={VA: {"symbol_name": pdb_symbol}},
        ), patch.object(
            candidate_module,
            "pdb_module_stream_procedure_for_va",
            return_value={"va": VA, "name": pdb_symbol},
        ):
            self.assertEqual([], candidate_module.validate_proposal(payload))

    def test_candidate_rejects_config_symbol_without_pdb_owner(self) -> None:
        source_module = _source_module("matching")
        payload = {
            "module": ".\\Release\\tech.obj",
            "source": "src/tech.cpp",
            "flags": "config/flags/tech.rsp",
            "owners": {VA: "src/tech.cpp"},
            "observed": {},
            "generated": {},
            "symbols": {VA: SYMBOL},
        }
        entry = {"module": source_module, "status": "matching", "note_path": ""}
        with patch.object(
            candidate_module, "source_module_entry_for_va", return_value=entry
        ), patch.object(
            candidate_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(candidate_module, "load_pdb_function_source_map", return_value={VA: {}}):
            issues = candidate_module.validate_proposal(payload)
        self.assertIn(f"{VA} has no PDB-qualified symbol ownership", issues)

    def test_candidate_observation_requires_stream_evidence(self) -> None:
        source_module = _source_module()
        source_module["pdb_module_stream_evidence"] = ""
        payload = {
            "module": ".\\Release\\tech.obj",
            "source": "src/tech.cpp",
            "flags": "config/flags/tech.rsp",
            "owners": {},
            "observed": {VA: {"source": "src/tech.cpp", "status": "observed"}},
            "generated": {},
            "symbols": {VA: SYMBOL},
        }
        entry = {"module": source_module, "status": "scratch", "note_path": ""}
        with patch.object(
            candidate_module, "source_module_entry_for_va", return_value=entry
        ), patch.object(
            candidate_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(candidate_module, "load_pdb_function_source_map", return_value={VA: {}}):
            issues = candidate_module.validate_proposal(payload)
        self.assertTrue(any("PDB module '' does not match" in issue for issue in issues))

    def test_group_rejects_config_symbol_without_pdb_owner(self) -> None:
        source_module = _source_module("matching")
        group = {
            "name": "tech_test",
            "source": "src/tech.cpp",
            "module": "tech_test",
            "flags": "config/flags/tech.rsp",
            "functions": {VA: SYMBOL},
            "owners": {VA: "src/tech.cpp"},
            "symbols": {VA: SYMBOL},
        }
        with patch.object(
            tu_module, "source_module_for_name", return_value=copy.deepcopy(source_module)
        ), patch.object(
            tu_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(tu_module, "load_pdb_function_source_map", return_value={VA: {}}):
            issues = tu_module.validate_translation_units([group])
        self.assertIn("missing-pdb-symbol", {issue.code for issue in issues})

    def test_group_accepts_stream_owned_no_line_symbol(self) -> None:
        source_module = _source_module("matching")
        group = {
            "name": "tech_test",
            "source": "src/tech.cpp",
            "module": "tech_test",
            "flags": "config/flags/tech.rsp",
            "functions": {VA: SYMBOL},
            "owners": {VA: "src/tech.cpp"},
            "symbols": {VA: SYMBOL},
        }
        pdb_symbol = common.function_record_by_va(int(VA, 16))["name"]
        with patch.object(
            tu_module, "source_module_for_name", return_value=copy.deepcopy(source_module)
        ), patch.object(
            tu_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(
            tu_module,
            "load_pdb_function_source_map",
            return_value={VA: {"symbol_name": pdb_symbol}},
        ), patch.object(
            tu_module,
            "pdb_module_stream_procedure_for_va",
            return_value={"va": VA, "name": pdb_symbol},
        ):
            self.assertEqual([], tu_module.validate_translation_units([group]))


if __name__ == "__main__":
    unittest.main()
