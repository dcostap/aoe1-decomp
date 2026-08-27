from __future__ import annotations

import csv
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]


class ScrAchTranslationUnitTests(unittest.TestCase):
    def test_wrapper_follows_normal_pdb_source_order(self) -> None:
        with (REPO_ROOT / "inventory" / "all_functions.csv").open(
            encoding="utf-8", newline=""
        ) as handle:
            owners = [
                row
                for row in csv.DictReader(handle)
                if row["pdb_source_file"].lower() == "scr_ach.cpp"
                and row["name"] not in {"FUN_0048e1c6", "FUN_0048f085"}
            ]
        owners.sort(key=lambda row: int(row["va"], 16))
        self.assertEqual(len(owners), 8)

        wrapper = (REPO_ROOT / "src" / "scr_ach_tu.cpp").read_text(encoding="utf-8")
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
            expected.append(str(matches[0].relative_to(REPO_ROOT / "src")).replace("\\", "/"))
        self.assertEqual(include_names, expected)

    def test_registered_scr_ach_owners_use_one_context_header(self) -> None:
        for va in (
            "0048E210", "0048F0B0", "0048F190",
            "0048F280", "0048F500", "0048F530",
        ):
            matches = list((REPO_ROOT / "src").glob(f"**/{va}_*.cpp"))
            self.assertEqual(len(matches), 1)
            text = matches[0].read_text(encoding="utf-8")
            self.assertIn('#include "../../include/scr_ach_context.h"', text)

        header = (REPO_ROOT / "include" / "scr_ach_context.h").read_text(encoding="utf-8")
        for token in (
            "class TPanel",
            "class TEasy_Panel",
            "class TScreenPanel",
            "class TribeAchievementsScreen",
            "class RGE_Game_World",
        ):
            self.assertIn(token, header)


if __name__ == "__main__":
    unittest.main()
