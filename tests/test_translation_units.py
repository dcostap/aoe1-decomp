from __future__ import annotations

import copy
import json
import os
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
    compiler_artifact_slug,
    compiler_source_path,
    compiler_translation_unit_for_va,
    function_record_by_va,
    load_translation_units,
    preferred_source_path,
    translation_unit_for_va,
    validate_translation_unit,
)
from validate_translation_units import (  # noqa: E402
    find_isolated_owner_overlaps,
    validate_translation_units,
)
import validate_translation_units as validation_module  # noqa: E402


class TranslationUnitTests(unittest.TestCase):
    def test_zone_map_owners_use_one_natural_source_module(self) -> None:
        expected_vas = (0x005468C0, 0x005469C0, 0x00546E50, 0x005473B0)
        paths = set()
        slugs = set()

        for va in expected_vas:
            record = function_record_by_va(va)
            group = compiler_translation_unit_for_va(va)
            self.assertIsNotNone(group)
            assert group is not None
            validate_translation_unit(group)
            paths.add(compiler_source_path(record))
            slugs.add(compiler_artifact_slug(record))

        self.assertEqual(paths, {REPO_ROOT / "src" / "zone_map.cpp"})
        self.assertEqual(slugs, {"tu_zone_map"})
        self.assertIsNone(translation_unit_for_va(0x005468C0))

    def test_com_obj_owners_use_natural_source_module_without_stale_group(self) -> None:
        expected_vas = (
            0x0042FC90,
            0x00430EC0,
            0x00431490,
            0x004315A0,
            0x004315B0,
        )
        paths = set()
        slugs = set()

        for va in expected_vas:
            record = function_record_by_va(va)
            self.assertIsNone(translation_unit_for_va(va))
            self.assertIsNone(compiler_translation_unit_for_va(va))
            paths.add(compiler_source_path(record))
            slugs.add(compiler_artifact_slug(record))

        self.assertEqual(paths, {REPO_ROOT / "src" / "com_obj.cpp"})
        self.assertEqual(
            slugs,
            {
                f"{va:08X}_{function_record_by_va(va)['name']}"
                for va in expected_vas
            },
        )

    def test_point_module_maps_multiple_exact_owners_to_one_normal_source(self) -> None:
        point = next(group for group in load_translation_units() if group["name"] == "point")
        owners = point["owners"]
        assert isinstance(owners, dict)

        self.assertEqual(set(owners.values()), {"src/point.cpp"})
        self.assertEqual(
            compiler_source_path(function_record_by_va(0x0047E480)),
            REPO_ROOT / "src" / "point.cpp",
        )
        self.assertEqual(
            compiler_source_path(function_record_by_va(0x0047E5D0)),
            REPO_ROOT / "src" / "point.cpp",
        )
        self.assertIsNone(translation_unit_for_va(0x0047E530))
        self.assertEqual(compiler_translation_unit_for_va(0x0047E530)["name"], "point")
        self.assertEqual(
            compiler_artifact_slug(function_record_by_va(0x0047E530)),
            "tu_point",
        )
        self.assertEqual([], validate_translation_units([point]))

    def test_each_group_has_unique_owner_vas(self) -> None:
        seen: set[str] = set()
        for group in load_translation_units():
            owners = group["owners"]
            self.assertIsInstance(owners, dict)
            assert isinstance(owners, dict)
            for va in owners:
                self.assertNotIn(va, seen)
                seen.add(va)

    def test_manifest_validation_rejects_noncanonical_grouped_objects(self) -> None:
        issues = validate_translation_units(
            load_translation_units(),
            manifests_dir=REPO_ROOT / "build" / "manifests",
            object_dir=REPO_ROOT / "build" / "obj",
        )
        mismatch_vas = {
            issue.message.split(" owner ", 1)[1].split(" ", 1)[0]
            for issue in issues
            if issue.code == "pdb-owner-mismatch"
        }
        configured_vas = {
            str(va).upper()
            for group in load_translation_units()
            for va in group["owners"]
        }
        self.assertTrue(mismatch_vas <= configured_vas)

        # Keep the PDB-owner rejection test independent from mutable build
        # output. The source module supplies the expected owner.
        group = copy.deepcopy(
            next(group for group in load_translation_units() if group["name"] == "zone_map")
        )
        with patch.object(
            validation_module,
            "_mapped_owner_symbols",
            return_value={
                "005473B0": (
                    "?get_zone_map@Other_Zone_Map_List"
                    "@@QAEPAVRGE_Zone_Map@@PAMJAAH@Z"
                ),
            },
        ):
            forced_issues = validate_translation_units(
                [group], object_dir=REPO_ROOT / "build" / "obj"
            )
        forced_mismatch_vas = {
            issue.message.split(" owner ", 1)[1].split(" ", 1)[0]
            for issue in forced_issues
            if issue.code == "pdb-owner-mismatch"
        }
        self.assertIn("005473B0", forced_mismatch_vas)

    def test_manifest_validation_rejects_duplicate_va(self) -> None:
        groups = load_translation_units()
        duplicate = copy.deepcopy(groups[1])
        duplicate["name"] = "duplicate_zone_map"
        groups_with_duplicate = [groups[1], duplicate]

        issues = validate_translation_units(groups_with_duplicate)

        self.assertIn("duplicate-va", {issue.code for issue in issues})

    def test_manifest_validation_rejects_missing_wrapper(self) -> None:
        group = copy.deepcopy(load_translation_units()[0])
        group["source"] = "src/does_not_exist_tu.cpp"

        issues = validate_translation_units([group])

        self.assertIn("missing-source", {issue.code for issue in issues})

    def test_manifest_validation_accepts_c_wrapper_with_tc(self) -> None:
        group = copy.deepcopy(load_translation_units()[0])

        with tempfile.TemporaryDirectory() as temp_dir:
            root = Path(temp_dir)
            wrapper = root / "src" / "demo_tu.c"
            flags = root / "config" / "flags" / "demo.rsp"
            wrapper.parent.mkdir(parents=True)
            flags.parent.mkdir(parents=True)
            wrapper.write_text("int demo(void) { return 0; }\n", encoding="utf-8")
            flags.write_text("/nologo /c /O2 /TC\n", encoding="utf-8")
            group["source"] = "src/demo_tu.c"
            group["flags"] = "config/flags/demo.rsp"

            issues = validate_translation_units([group], root=root)

        issue_codes = {issue.code for issue in issues}
        self.assertNotIn("wrapper-extension", issue_codes)
        self.assertNotIn("c-language-mode", issue_codes)

    def test_manifest_validation_requires_tc_for_c_wrapper(self) -> None:
        group = copy.deepcopy(load_translation_units()[0])

        with tempfile.TemporaryDirectory() as temp_dir:
            root = Path(temp_dir)
            wrapper = root / "src" / "demo_tu.c"
            flags = root / "config" / "flags" / "demo.rsp"
            wrapper.parent.mkdir(parents=True)
            flags.parent.mkdir(parents=True)
            wrapper.write_text("int demo(void) { return 0; }\n", encoding="utf-8")
            flags.write_text("/nologo /c /O2\n", encoding="utf-8")
            group["source"] = "src/demo_tu.c"
            group["flags"] = "config/flags/demo.rsp"

            issues = validate_translation_units([group], root=root)

        self.assertIn("c-language-mode", {issue.code for issue in issues})

    def test_manifest_validation_requires_owner_include_order_and_count(self) -> None:
        first_va = "00405D00"
        second_va = "00405D10"
        first_record = function_record_by_va(int(first_va, 16))
        second_record = function_record_by_va(int(second_va, 16))
        first_path = preferred_source_path(first_record)
        second_path = preferred_source_path(second_record)
        self.assertTrue(first_path.is_file())
        self.assertTrue(second_path.is_file())

        (REPO_ROOT / "build").mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp_dir:
            temp_root = Path(temp_dir)
            wrapper = temp_root / "legacy_tu.cpp"
            first_include = Path(os.path.relpath(first_path, wrapper.parent)).as_posix()
            second_include = Path(os.path.relpath(second_path, wrapper.parent)).as_posix()
            wrapper.write_text(
                f'#include "{first_include}"\n#include "{second_include}"\n',
                encoding="utf-8",
            )
            group = {
                "name": "legacy_order_test",
                "source": wrapper.relative_to(REPO_ROOT).as_posix(),
                "flags": "",
                "owners": {
                    first_va: first_path.relative_to(REPO_ROOT).as_posix(),
                    second_va: second_path.relative_to(REPO_ROOT).as_posix(),
                },
                "symbols": {},
                "module": "",
            }

            reversed_group = copy.deepcopy(group)
            owners = reversed_group["owners"]
            assert isinstance(owners, dict)
            reversed_group["owners"] = dict(reversed(list(owners.items())))
            issues = validate_translation_units([reversed_group])
            self.assertIn("owner-include-order", {issue.code for issue in issues})

            missing_owner = copy.deepcopy(group)
            missing_owners = missing_owner["owners"]
            assert isinstance(missing_owners, dict)
            missing_owners[first_va] = missing_owners[first_va] + ".missing"
            missing_issues = validate_translation_units([missing_owner])

        self.assertIn("owner-include-count", {issue.code for issue in missing_issues})

    def test_manifest_validation_requires_exact_symbols_for_duplicate_names(self) -> None:
        group = copy.deepcopy(
            next(group for group in load_translation_units() if group["name"] == "tscenaro")
        )
        group["symbols"] = {}

        issues = validate_translation_units([group])

        missing = [issue for issue in issues if issue.code == "missing-exact-symbol"]
        self.assertEqual(2, len(missing))

    def test_manifest_validation_checks_configured_symbols_in_grouped_object(self) -> None:
        object_path = REPO_ROOT / "build" / "obj" / "tu_tscenaro.obj"
        if not object_path.is_file():
            self.skipTest("grouped object is not available in this checkout")

        group = copy.deepcopy(
            next(group for group in load_translation_units() if group["name"] == "tscenaro")
        )
        symbols = group["symbols"]
        assert isinstance(symbols, dict)
        symbols["00468CB0"] = "?not_a_real_symbol@@YAXXZ"

        issues = validate_translation_units([group], object_dir=object_path.parent)

        self.assertIn("symbol-not-defined", {issue.code for issue in issues})

    def test_isolated_owner_overlap_is_reported(self) -> None:
        group = load_translation_units()[1]
        owners = group["owners"]
        assert isinstance(owners, dict)
        owner = next(iter(owners.values()))

        (REPO_ROOT / "build").mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp_dir:
            manifests_dir = Path(temp_dir)
            manifest = manifests_dir / "build_isolated_owner.json"
            manifest.write_text(
                json.dumps({"source": owner, "object": "build/obj/isolated.obj"}),
                encoding="utf-8",
            )
            issues = find_isolated_owner_overlaps(
                [group], manifests_dir=manifests_dir, root=REPO_ROOT
            )

        self.assertEqual(1, len(issues))
        self.assertEqual("isolated-owner-overlap", issues[0].code)


if __name__ == "__main__":
    unittest.main()
