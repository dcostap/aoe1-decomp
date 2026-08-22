from __future__ import annotations

import sys
import unittest
from pathlib import Path


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


if __name__ == "__main__":
    unittest.main()
