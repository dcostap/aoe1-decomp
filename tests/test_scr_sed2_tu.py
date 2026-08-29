from __future__ import annotations

import csv
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
PADDING_ONLY = {"004AE05A", "004AEC95", "004AF2D2"}


class ScrSed2TranslationUnitTests(unittest.TestCase):
    def test_module_follows_normal_pdb_source_order(self) -> None:
        with (REPO_ROOT / "inventory" / "all_functions.csv").open(
            encoding="utf-8", newline=""
        ) as handle:
            owners = [
                row
                for row in csv.DictReader(handle)
                if row["pdb_source_file"].lower() == "scr_sed2.cpp"
                and row["va"] not in PADDING_ONLY
            ]
        owners.sort(key=lambda row: int(row["va"], 16))
        self.assertEqual(len(owners), 19)

        module = (REPO_ROOT / "src" / "scr_sed2.cpp").read_text(
            encoding="utf-8"
        )
        positions = []
        for row in owners:
            positions.append(module.index(f"TRIBE_Screen_Sed::{row['name']}"))
        self.assertEqual(positions, sorted(positions))

    def test_normal_owners_use_one_module_header(self) -> None:
        module = (REPO_ROOT / "src" / "scr_sed2.cpp").read_text(
            encoding="utf-8"
        )
        self.assertIn('#include "../include/scr_sed2.h"', module)
        for name in (
            "SaveDisabledItemsInScenario", "LoadDisabledItemsFromScenario",
            "save_info_in_scenario", "save_multi_victory_cond_in_scenario",
            "save_victory_cond_in_scenario", "load_victory_cond_from_scenario",
            "load_multi_victory_cond_from_scenario", "save_diplomacy_in_scenario",
            "load_diplomacy_from_scenario", "activate_victory_proper_fields",
            "init_module_variables", "create_all_buttons_etc", "position_panels",
            "activate_victory_panel", "MakeFileList",
            "Set_player_advance_civilization_text", "SavePlayerActiveStatus",
            "create_check_box", "create_radio_button",
        ):
            self.assertIn(f"TRIBE_Screen_Sed::{name}", module)

        header = (REPO_ROOT / "include" / "scr_sed2.h").read_text(
            encoding="utf-8"
        )
        self.assertIn('#include "scr_sed.h"', header)
        self.assertNotIn("class TPanel", header)
        self.assertNotIn("class T_Scenario", header)
        self.assertNotIn("class TRIBE_World", header)
        self.assertNotIn("class TRIBE_Screen_Sed", header)

        for provider in (
            "pnl_msg.h", "pnl_btn.h", "pnl_edit.h", "pnl_drop.h",
            "pnl_lst.h", "tscenaro.h", "tworld.h", "vw_dimap.h",
            "vw_main.h", "spnl_obj.h",
        ):
            self.assertIn(f'#include "../include/{provider}"', module)


if __name__ == "__main__":
    unittest.main()
