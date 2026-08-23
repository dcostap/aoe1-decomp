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
    compiler_artifact_slug,
    compiler_source_path,
    function_record_by_va,
    load_translation_units,
    translation_unit_for_va,
    validate_translation_unit,
)
from validate_translation_units import (  # noqa: E402
    find_isolated_owner_overlaps,
    validate_translation_units,
)
import validate_translation_units as validation_module  # noqa: E402


class TranslationUnitTests(unittest.TestCase):
    def test_zone_map_owners_use_one_grouped_object(self) -> None:
        expected_vas = (0x005468C0, 0x005469C0, 0x00546E50, 0x005473B0)
        paths = set()
        slugs = set()

        for va in expected_vas:
            record = function_record_by_va(va)
            group = translation_unit_for_va(va)
            self.assertIsNotNone(group)
            assert group is not None
            validate_translation_unit(group)
            paths.add(compiler_source_path(record))
            slugs.add(compiler_artifact_slug(record))

        self.assertEqual(paths, {REPO_ROOT / "src" / "rge_zone_map_tu.cpp"})
        self.assertEqual(slugs, {"tu_zone_map"})

    def test_com_obj_owners_use_one_grouped_object(self) -> None:
        expected_vas = (0x004304A0, 0x00431150)
        paths = set()
        slugs = set()

        for va in expected_vas:
            record = function_record_by_va(va)
            group = translation_unit_for_va(va)
            self.assertIsNotNone(group)
            assert group is not None
            validate_translation_unit(group)
            paths.add(compiler_source_path(record))
            slugs.add(compiler_artifact_slug(record))

        self.assertEqual(paths, {REPO_ROOT / "src" / "com_obj_enter_tu.cpp"})
        self.assertEqual(slugs, {"tu_com_obj_enter"})

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
        self.assertTrue(
            mismatch_vas <= {
                "004304A0",
                "004AD680",
                "004BFFE0",
                "004DAFF0",
                "004348F0",
                "00467A50",
            }
        )

        # Current grouped objects may all be canonical. Keep the PDB-owner
        # rejection test independent from mutable build output.
        object_path = REPO_ROOT / "build" / "obj" / "tu_com_obj_enter.obj"
        if not object_path.is_file():
            self.skipTest("grouped object is not available in this checkout")
        group = copy.deepcopy(load_translation_units()[0])
        with patch.object(
            validation_module,
            "_mapped_owner_symbols",
            return_value={
                "004304A0": "?reset_attack_timer@Other_Combat_Object@@QAEXXZ",
                "00431150": "?enter@Other_Combat_Object@@QAEHHH@Z",
            },
        ):
            forced_issues = validate_translation_units([group], object_dir=object_path.parent)
        forced_mismatch_vas = {
            issue.message.split(" owner ", 1)[1].split(" ", 1)[0]
            for issue in forced_issues
            if issue.code == "pdb-owner-mismatch"
        }
        self.assertIn("004304A0", forced_mismatch_vas)

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

    def test_manifest_validation_requires_owner_include_order_and_count(self) -> None:
        group = copy.deepcopy(load_translation_units()[1])
        owners = group["owners"]
        assert isinstance(owners, dict)
        group["owners"] = dict(reversed(list(owners.items())))

        issues = validate_translation_units([group])
        issue_codes = {issue.code for issue in issues}

        self.assertIn("owner-include-order", issue_codes)

        missing_owner = copy.deepcopy(load_translation_units()[1])
        missing_owners = missing_owner["owners"]
        assert isinstance(missing_owners, dict)
        first_va = next(iter(missing_owners))
        missing_owners[first_va] = missing_owners[first_va] + ".missing"
        missing_issues = validate_translation_units([missing_owner])

        self.assertIn("owner-include-count", {issue.code for issue in missing_issues})

    def test_manifest_validation_requires_exact_symbols_for_duplicate_names(self) -> None:
        group = copy.deepcopy(load_translation_units()[9])
        group["symbols"] = {}

        issues = validate_translation_units([group])

        missing = [issue for issue in issues if issue.code == "missing-exact-symbol"]
        self.assertEqual(2, len(missing))

    def test_manifest_validation_checks_configured_symbols_in_grouped_object(self) -> None:
        object_path = REPO_ROOT / "build" / "obj" / "tu_panel_create_button.obj"
        if not object_path.is_file():
            self.skipTest("grouped object is not available in this checkout")

        group = copy.deepcopy(load_translation_units()[9])
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
