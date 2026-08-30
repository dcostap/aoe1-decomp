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


def _source_module(status: str = "unresolved") -> dict[str, object]:
    entry = {"status": status}
    payload: dict[str, object] = {
        "schema": 1,
        "pdb_source_path": ".\\Release\\tech.obj",
        "pdb_no_line_info": True,
        "pdb_module_stream_evidence": "inventory/pdb/module_streams/0027_tech.json",
        "header": "include/tech.h",
        "functions": {VA: entry},
    }
    if status != "unresolved":
        entry["symbol"] = SYMBOL
        payload["build"] = {"flags": "default"}
    return payload


def _normalized_module(status: str = "matching") -> dict[str, object]:
    payload = _source_module(status)
    build = payload.get("build")
    if isinstance(build, dict):
        build = {**build, "flags_path": "config/flags/default.rsp"}
    return {
        **payload,
        "name": "tech",
        "source": "src/tech.cpp",
        "build": build,
    }


@contextmanager
def _source_module_config(payload: dict[str, object]):
    with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp_dir:
        module_dir = Path(temp_dir)
        path = module_dir / "src" / "tech.cpp.json"
        path.parent.mkdir(parents=True)
        path.write_text(
            json.dumps(payload), encoding="utf-8"
        )
        old_dir = common.FUNCTIONS_CONFIG_DIR
        old_flags = common.FLAGS_DIR
        common.FUNCTIONS_CONFIG_DIR = module_dir
        common.FLAGS_DIR = module_dir / "flags"
        common.load_function_modules.cache_clear()
        common.function_entries_by_va.cache_clear()
        try:
            yield
        finally:
            common.FUNCTIONS_CONFIG_DIR = old_dir
            common.FLAGS_DIR = old_flags
            common.load_function_modules.cache_clear()
            common.function_entries_by_va.cache_clear()


class PdbNoLineInfoTests(unittest.TestCase):
    def test_tech_is_a_no_line_source_module(self) -> None:
        tech = common.function_module_for_name("tech")
        self.assertIsNotNone(tech)
        assert tech is not None
        self.assertTrue(tech["pdb_no_line_info"])
        self.assertEqual(tech["source"], "src/tech.cpp")
        self.assertEqual(len(tech["functions"]), 33)
        self.assertEqual([], common.validate_function_registry())

    def test_common_rejects_non_boolean_no_line_flag(self) -> None:
        payload = _source_module()
        payload["pdb_no_line_info"] = "true"
        with _source_module_config(payload):
            with self.assertRaisesRegex(ValueError, "must be Boolean"):
                common.load_function_modules()

    def test_common_accepts_empty_stream_metadata(self) -> None:
        with _source_module_config(_source_module()), patch.object(
            common,
            "load_pdb_function_source_map",
            return_value={VA: {"has_line_info": "0", "primary_source_path": ""}},
        ), patch.object(
            common, "load_functions", return_value=[{"va": VA, "name": "TRIBE_Tech"}]
        ):
            self.assertEqual([], common.validate_function_registry())

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
        ), patch.object(
            common, "load_functions", return_value=[{"va": VA, "name": "TRIBE_Tech"}]
        ):
            issues = common.validate_function_registry()
        self.assertTrue(any("PDB line/source data" in issue for issue in issues))

    def test_candidate_accepts_stream_owned_no_line_symbol(self) -> None:
        source_module = _normalized_module("matching")
        payload = {
            "module": ".\\Release\\tech.obj",
            "source": "src/tech.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {VA: "src/tech.cpp"},
            "observed": {},
            "generated": {},
            "symbols": {VA: SYMBOL},
        }
        entry = {"module": source_module, "status": "matching"}
        pdb_symbol = common.function_record_by_va(int(VA, 16))["name"]
        with patch.object(
            candidate_module, "function_entry_for_va", return_value=entry
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
        source_module = _normalized_module("matching")
        payload = {
            "module": ".\\Release\\tech.obj",
            "source": "src/tech.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {VA: "src/tech.cpp"},
            "observed": {},
            "generated": {},
            "symbols": {VA: SYMBOL},
        }
        entry = {"module": source_module, "status": "matching"}
        with patch.object(
            candidate_module, "function_entry_for_va", return_value=entry
        ), patch.object(
            candidate_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(candidate_module, "load_pdb_function_source_map", return_value={VA: {}}):
            issues = candidate_module.validate_proposal(payload)
        self.assertIn(f"{VA} has no PDB-qualified symbol ownership", issues)

    def test_candidate_observation_requires_stream_evidence(self) -> None:
        source_module = _normalized_module("unresolved")
        source_module["pdb_module_stream_evidence"] = ""
        payload = {
            "module": ".\\Release\\tech.obj",
            "source": "src/tech.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {},
            "observed": {VA: {"source": "src/tech.cpp", "status": "unresolved"}},
            "generated": {},
            "symbols": {VA: SYMBOL},
        }
        entry = {"module": source_module, "status": "scratch"}
        with patch.object(
            candidate_module, "function_entry_for_va", return_value=entry
        ), patch.object(
            candidate_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(candidate_module, "load_pdb_function_source_map", return_value={VA: {}}):
            issues = candidate_module.validate_proposal(payload)
        self.assertTrue(any("PDB module '' does not match" in issue for issue in issues))

    def test_group_rejects_config_symbol_without_pdb_owner(self) -> None:
        source_module = _normalized_module("matching")
        group = copy.deepcopy(source_module)
        with patch.object(
            tu_module,
            "preferred_source_path",
            return_value=REPO_ROOT / "src" / "tech.cpp",
        ), patch.object(tu_module, "load_pdb_function_source_map", return_value={VA: {}}):
            issues = tu_module.validate_translation_units([group])
        self.assertIn("missing-pdb-symbol", {issue.code for issue in issues})

    def test_group_accepts_stream_owned_no_line_symbol(self) -> None:
        source_module = _normalized_module("matching")
        group = copy.deepcopy(source_module)
        pdb_symbol = common.function_record_by_va(int(VA, 16))["name"]
        with patch.object(
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
