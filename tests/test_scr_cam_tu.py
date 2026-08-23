from __future__ import annotations

import csv
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]


class ScrCamTranslationUnitTests(unittest.TestCase):
    def test_wrapper_follows_pdb_source_order(self) -> None:
        with (REPO_ROOT / "inventory" / "all_functions.csv").open(
            encoding="utf-8", newline=""
        ) as handle:
            owners = [
                row
                for row in csv.DictReader(handle)
                if row["pdb_source_file"].lower() == "scr_cam.cpp"
            ]
        owners.sort(key=lambda row: int(row["va"], 16))
        self.assertEqual(len(owners), 13)

        wrapper = (REPO_ROOT / "src" / "scr_cam_tu.cpp").read_text(encoding="utf-8")
        include_names = [
            line.split('"', 2)[1]
            for line in wrapper.splitlines()
            if line.startswith('#include "matching/')
            or line.startswith('#include "accepted_drift/')
        ]
        expected = []
        for row in owners:
            matches = list((REPO_ROOT / "src").glob(f"**/{row['va']}_*.cpp"))
            self.assertEqual(len(matches), 1)
            expected.append(str(matches[0].relative_to(REPO_ROOT / "src")).replace("\\", "/"))
        self.assertEqual(include_names, expected)

    def test_scr_cam_owners_use_one_context_header(self) -> None:
        for va in (
            "0048F5D0", "0048FA40", "0048FBC0", "0048FD20", "0048FE80",
            "0048FF00", "0048FF80", "00490120", "00490380", "00490400",
            "00490480", "00490520", "004905D0",
        ):
            matches = list((REPO_ROOT / "src").glob(f"**/{va}_*.cpp"))
            self.assertEqual(len(matches), 1)
            text = matches[0].read_text(encoding="utf-8")
            self.assertIn('#include "../../include/scr_cam_context.h"', text)

        header = (REPO_ROOT / "include" / "scr_cam_context.h").read_text(encoding="utf-8")
        for token in (
            "class TPanel",
            "class TEasy_Panel",
            "class TScreenPanel",
            "class TRIBE_Campaign_Editor_Screen",
            "class RGE_Campaign",
        ):
            self.assertIn(token, header)


if __name__ == "__main__":
    unittest.main()
