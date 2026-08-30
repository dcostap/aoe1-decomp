from __future__ import annotations

import json
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]


class ScrInfoTranslationUnitTests(unittest.TestCase):
    VAS = (
        0x0049D550,
        0x0049D600,
        0x0049D610,
        0x0049D690,
        0x0049D6B0,
        0x0049D6C0,
        0x0049D6E0,
    )

    def test_module_follows_pdb_source_order(self) -> None:
        source = (REPO_ROOT / "src" / "scr_info.cpp").read_text(encoding="utf-8")
        definitions = (
            "TRIBE_Screen_Info::TRIBE_Screen_Info",
            "TRIBE_Screen_Info::~TRIBE_Screen_Info",
            "TRIBE_Screen_Info::handle_idle",
            "TRIBE_Screen_Info::key_down_action",
            "TRIBE_Screen_Info::mouse_left_down_action",
            "TRIBE_Screen_Info::action",
            "TRIBE_Screen_Info::close_screen",
        )
        positions = [source.index(definition) for definition in definitions]
        self.assertEqual(positions, sorted(positions))

    def test_module_has_direct_ownership_without_fragments(self) -> None:
        source = (REPO_ROOT / "src" / "scr_info.cpp").read_text(encoding="utf-8")

        self.assertIn('#include "../include/scr_info.h"', source)
        self.assertNotIn('#include "matching/', source)
        self.assertNotIn("scr_info_context", source)
        self.assertNotIn("#if", source)
        self.assertFalse((REPO_ROOT / "src" / "scr_info_tu.cpp").exists())
        self.assertFalse((REPO_ROOT / "include" / "scr_info_context.h").exists())
        for va in self.VAS:
            self.assertEqual(
                list((REPO_ROOT / "src").glob(f"**/{va:08X}_*.cpp")), []
            )

    def test_registry_contains_all_functions(self) -> None:
        metadata = json.loads(
            (REPO_ROOT / "config" / "functions" / "src" / "scr_info.cpp.json").read_text(
                encoding="utf-8"
            )
        )
        self.assertEqual(metadata["header"], "include/scr_info.h")
        self.assertEqual(tuple(int(va, 16) for va in metadata["functions"]), self.VAS)
        self.assertEqual(
            {entry["status"] for entry in metadata["functions"].values()},
            {"matching"},
        )


if __name__ == "__main__":
    unittest.main()
