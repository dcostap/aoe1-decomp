from __future__ import annotations

import copy
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from common import (  # noqa: E402
    build_module_for_va,
    compiler_artifact_slug,
    compiler_source_path,
    function_entry_for_va,
    function_record_by_va,
    load_build_modules,
    load_function_modules,
    matching_build_for_va,
    preferred_source_path,
    validate_build_module,
    validate_function_registry,
)
from validate_translation_units import (  # noqa: E402
    find_isolated_owner_overlaps,
    validate_translation_units,
)
import validate_translation_units as validation_module  # noqa: E402


class TranslationUnitTests(unittest.TestCase):
    def test_registry_contains_every_normal_function_once(self) -> None:
        modules = load_function_modules()
        entries = [
            (va, entry, module)
            for module in modules
            for va, entry in module["functions"].items()
        ]
        self.assertEqual(242, len(modules))
        self.assertEqual(5428, len(entries))
        self.assertEqual(5428, len({va for va, _, _ in entries}))
        self.assertEqual([], validate_function_registry())

    def test_build_modules_keep_every_known_symbol(self) -> None:
        modules = load_build_modules()
        entries = [
            entry
            for module in modules
            for entry in module["functions"].values()
        ]
        self.assertEqual(224, len(modules))
        self.assertEqual(5261, len(entries))
        self.assertTrue(all(entry.get("symbol") for entry in entries))
        self.assertEqual([], validate_translation_units(modules, require_complete=True))

    def test_header_owned_functions_are_explicit_unresolved_entries(self) -> None:
        header_modules = [
            module
            for module in load_function_modules()
            if str(module["source"]).startswith("include/")
        ]
        entries = [
            entry
            for module in header_modules
            for entry in module["functions"].values()
        ]
        self.assertEqual(17, len(header_modules))
        self.assertEqual(134, len(entries))
        self.assertTrue(all(entry["status"] == "unresolved" for entry in entries))
        self.assertTrue(all(module["build"] is None for module in header_modules))

    def test_point_uses_one_source_recipe_for_all_statuses(self) -> None:
        point = next(module for module in load_build_modules() if module["name"] == "point")
        functions = point["functions"]
        self.assertEqual(point["source"], "src/point.cpp")
        self.assertEqual(point["build"]["flags"], "default")
        self.assertEqual(functions["0047E480"]["status"], "matching")
        self.assertEqual(functions["0047E530"]["status"], "scratch")
        self.assertEqual(
            functions["0047E530"]["symbol"],
            "??HXYZ@@QBE?AV0@ABV0@@Z",
        )
        self.assertIsNotNone(matching_build_for_va(0x0047E480))
        self.assertIsNone(matching_build_for_va(0x0047E530))
        self.assertEqual(build_module_for_va(0x0047E530), point)

    def test_view_symbols_keep_original_incomplete_record_tags(self) -> None:
        view = next(module for module in load_build_modules() if module["name"] == "view")
        functions = view["functions"]
        self.assertEqual(
            functions["005359E0"]["symbol"],
            "?pick@RGE_View@@QAEEEEJJPAURGE_Pick_Info@@PAVRGE_Static_Object@@@Z",
        )
        self.assertEqual(
            functions["00538280"]["symbol"],
            "?Add_GDI_Clip_Mask@RGE_View@@IAEXPAUDClipInfo_Node@@PAVTSpan_List_Manager@@@Z",
        )
        self.assertEqual(
            functions["0053B000"]["symbol"],
            "?GetNode@DClipInfo_List@@QAEPAUDClipInfo_Node@@XZ",
        )

    def test_compiler_helpers_use_the_natural_source_module(self) -> None:
        for va in (0x005468C0, 0x005469C0, 0x00546E50, 0x005473B0):
            record = function_record_by_va(va)
            module = build_module_for_va(va)
            self.assertIsNotNone(module)
            assert module is not None
            validate_build_module(module)
            self.assertEqual(compiler_source_path(record), REPO_ROOT / "src" / "zone_map.cpp")
            self.assertEqual(compiler_artifact_slug(record), "tu_zone_map")
            self.assertEqual(preferred_source_path(record), REPO_ROOT / "src" / "zone_map.cpp")

    def test_function_entry_carries_module_context(self) -> None:
        entry = function_entry_for_va(0x0042FAF0)
        self.assertIsNotNone(entry)
        assert entry is not None
        self.assertEqual(entry["status"], "matching")
        self.assertEqual(entry["module"]["source"], "src/com_obj.cpp")

    def test_validation_rejects_duplicate_va(self) -> None:
        module = copy.deepcopy(load_build_modules()[0])
        duplicate = copy.deepcopy(module)
        duplicate["name"] = "duplicate"
        duplicate["source"] = "src/duplicate.cpp"
        issues = validate_translation_units([module, duplicate])
        self.assertIn("duplicate-va", {issue.code for issue in issues})

    def test_validation_rejects_missing_source(self) -> None:
        module = copy.deepcopy(load_build_modules()[0])
        module["source"] = "src/does_not_exist.cpp"
        issues = validate_translation_units([module])
        self.assertIn("missing-source", {issue.code for issue in issues})

    def test_validation_requires_tc_for_c_source(self) -> None:
        module = copy.deepcopy(load_build_modules()[0])
        with tempfile.TemporaryDirectory() as temp_dir:
            root = Path(temp_dir)
            source = root / "src" / "demo.c"
            flags = root / "config" / "flags" / "demo.rsp"
            source.parent.mkdir(parents=True)
            flags.parent.mkdir(parents=True)
            source.write_text("int demo(void) { return 0; }\n", encoding="utf-8")
            flags.write_text("/nologo /c /O2\n", encoding="utf-8")
            module["source"] = "src/demo.c"
            module["build"] = {"flags": "demo", "flags_path": "config/flags/demo.rsp"}
            issues = validate_translation_units([module], root=root)
        self.assertIn("c-language-mode", {issue.code for issue in issues})

    def test_validation_checks_matching_symbols_in_grouped_object(self) -> None:
        module = copy.deepcopy(
            next(item for item in load_build_modules() if item["name"] == "zone_map")
        )
        matching_va = next(
            va
            for va, entry in module["functions"].items()
            if entry["status"] == "matching"
        )
        with patch.object(
            validation_module,
            "_mapped_matching_symbols",
            return_value={matching_va: "?wrong@Other@@QAE@XZ"},
        ):
            issues = validate_translation_units(
                [module], object_dir=REPO_ROOT / "build" / "objects"
            )
        self.assertIn("pdb-symbol-mismatch", {issue.code for issue in issues})

    def test_validation_rejects_missing_grouped_object(self) -> None:
        module = copy.deepcopy(load_build_modules()[0])
        with tempfile.TemporaryDirectory() as temp_dir:
            issues = validate_translation_units([module], object_dir=Path(temp_dir))
        self.assertIn("missing-grouped-object", {issue.code for issue in issues})

    def test_isolated_source_overlap_is_reported(self) -> None:
        module = copy.deepcopy(load_build_modules()[0])
        with tempfile.TemporaryDirectory() as temp_dir:
            manifests = Path(temp_dir)
            path = manifests / "build_isolated.json"
            path.write_text(json.dumps({"source": module["source"]}), encoding="utf-8")
            issues = find_isolated_owner_overlaps(
                [module], manifests_dir=manifests, root=REPO_ROOT
            )
        self.assertIn("isolated-source-overlap", {issue.code for issue in issues})


if __name__ == "__main__":
    unittest.main()
