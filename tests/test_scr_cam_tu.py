from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from common import compiler_source_path, function_record_by_va  # noqa: E402


class ScrCamSourceModuleTests(unittest.TestCase):
    VAS = (
        0x0048F5D0, 0x0048FA40, 0x0048FBC0, 0x0048FD20, 0x0048FE80,
        0x0048FF00, 0x0048FF80, 0x00490120, 0x00490380, 0x00490400,
        0x00490480, 0x00490520, 0x004905D0,
    )

    def test_module_owns_all_pdb_functions_in_order(self) -> None:
        source = REPO_ROOT / "src" / "scr_cam.cpp"
        text = source.read_text(encoding="utf-8")
        definitions = (
            "TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen",
            "TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen",
            "TRIBE_Campaign_Editor_Screen::fill_campaign_drop",
            "TRIBE_Campaign_Editor_Screen::fill_scenario_list",
            "TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list",
            "TRIBE_Campaign_Editor_Screen::check_lists",
            "TRIBE_Campaign_Editor_Screen::load_campaign",
            "TRIBE_Campaign_Editor_Screen::make_campaign",
            "TRIBE_Campaign_Editor_Screen::add_scenario",
            "TRIBE_Campaign_Editor_Screen::remove_scenario",
            "TRIBE_Campaign_Editor_Screen::move_scenario_up",
            "TRIBE_Campaign_Editor_Screen::move_scenario_down",
            "TRIBE_Campaign_Editor_Screen::action",
        )

        positions = [text.index(definition) for definition in definitions]
        self.assertEqual(positions, sorted(positions))
        self.assertEqual(
            {compiler_source_path(function_record_by_va(va)) for va in self.VAS},
            {source},
        )

    def test_module_uses_its_normal_header_without_fragments(self) -> None:
        source = (REPO_ROOT / "src" / "scr_cam.cpp").read_text(encoding="utf-8")
        header = (REPO_ROOT / "include" / "scr_cam.h").read_text(encoding="utf-8")
        shared_header = (REPO_ROOT / "include" / "Pnl_scr.h").read_text(
            encoding="utf-8"
        )
        panel_header = (REPO_ROOT / "include" / "panel_ez.h").read_text(
            encoding="utf-8"
        )
        base_panel_header = (REPO_ROOT / "include" / "panel.h").read_text(
            encoding="utf-8"
        )

        self.assertIn('#include "../include/scr_cam.h"', source)
        self.assertNotIn('#include "matching/', source)
        self.assertFalse((REPO_ROOT / "src" / "scr_cam_tu.cpp").exists())
        for va in self.VAS:
            self.assertEqual(list((REPO_ROOT / "src").glob(f"**/{va:08X}_*.cpp")), [])

        self.assertIn('#include "Pnl_scr.h"', header)
        self.assertIn("class TScreenPanel", shared_header)
        self.assertIn("class TPanel", base_panel_header)
        self.assertIn("class TEasy_Panel", panel_header)
        for token in ("class TPanel", "class TEasy_Panel"):
            self.assertNotIn(token, header)
        self.assertIn("class TRIBE_Campaign_Editor_Screen", header)
        self.assertIn("class RGE_Campaign;", header)


if __name__ == "__main__":
    unittest.main()
