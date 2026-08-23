from __future__ import annotations

import csv
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
PADDING_ONLY = {"004AE05A", "004AEC95", "004AF2D2"}


class ScrSed2TranslationUnitTests(unittest.TestCase):
    def test_wrapper_follows_normal_pdb_source_order(self) -> None:
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

        wrapper = (REPO_ROOT / "src" / "scr_sed2_tu.cpp").read_text(
            encoding="utf-8"
        )
        include_names = [
            line.split('"', 2)[1]
            for line in wrapper.splitlines()
            if line.startswith('#include "matching/')
            or line.startswith('#include "accepted_drift/')
            or line.startswith('#include "scratch/')
        ]
        expected = []
        for row in owners:
            matches = list((REPO_ROOT / "src").glob(f"**/{row['va']}_*.cpp"))
            self.assertEqual(len(matches), 1)
            expected.append(
                str(matches[0].relative_to(REPO_ROOT / "src")).replace("\\", "/")
            )
        self.assertEqual(include_names, expected)

    def test_normal_owners_use_one_context_header(self) -> None:
        for va in (
            "004ADC80", "004ADD00", "004ADD50", "004ADD60", "004AE070",
            "004AE620", "004AE9D0", "004AECB0", "004AED50", "004AEE10",
            "004AF320", "004AF6C0", "004B1A50", "004B29E0", "004B2AA0",
            "004B2BC0", "004B2C50", "004B2DD0", "004B2E60",
        ):
            matches = list((REPO_ROOT / "src").glob(f"**/{va}_*.cpp"))
            self.assertEqual(len(matches), 1)
            text = matches[0].read_text(encoding="utf-8")
            self.assertIn('#include "../../include/scr_sed2_context.h"', text)

        header = (REPO_ROOT / "include" / "scr_sed2_context.h").read_text(
            encoding="utf-8"
        )
        for token in (
            "class TPanel",
            "class TEasy_Panel",
            "class TScreenPanel",
            "class T_Scenario",
            "class TRIBE_World",
            "class TRIBE_Screen_Sed",
            "TButtonPanel* Diplomacy_friend_box[8][3]",
            "unsigned long save_window_color",
        ):
            self.assertIn(token, header)


if __name__ == "__main__":
    unittest.main()
