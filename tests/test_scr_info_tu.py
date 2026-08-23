from __future__ import annotations

import csv
import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))


class ScrInfoTranslationUnitTests(unittest.TestCase):
    def test_wrapper_follows_pdb_source_order_for_seven_normal_owners(self) -> None:
        with (REPO_ROOT / "inventory" / "all_functions.csv").open(
            encoding="utf-8", newline=""
        ) as handle:
            owners = [
                row
                for row in csv.DictReader(handle)
                if row["pdb_source_file"].lower() == "scr_info.cpp"
            ]
        owners.sort(key=lambda row: int(row["va"], 16))
        self.assertEqual(len(owners), 7)

        wrapper = (REPO_ROOT / "src" / "scr_info_tu.cpp").read_text(encoding="utf-8")
        include_names = [
            line.split('"', 2)[1]
            for line in wrapper.splitlines()
            if line.startswith('#include "matching/')
        ]
        expected = []
        for row in owners:
            matches = list((REPO_ROOT / "src" / "matching").glob(f"{row['va']}_*.cpp"))
            self.assertEqual(len(matches), 1)
            expected.append(f"matching/{matches[0].name}")
        self.assertEqual(include_names, expected)

    def test_all_scr_info_owners_use_one_context_header(self) -> None:
        for va in ("0049D550", "0049D600", "0049D610", "0049D690", "0049D6B0", "0049D6C0", "0049D6E0"):
            matches = list((REPO_ROOT / "src" / "matching").glob(f"{va}_*.cpp"))
            self.assertEqual(len(matches), 1)
            text = matches[0].read_text(encoding="utf-8")
            self.assertIn('#include "../../include/scr_info_context.h"', text)

        header = (REPO_ROOT / "include" / "scr_info_context.h").read_text(encoding="utf-8")
        for token in ("class TEasy_Panel", "class TScreenPanel", "class TRIBE_Screen_Info", "virtual long action"):
            self.assertIn(token, header)


if __name__ == "__main__":
    unittest.main()
