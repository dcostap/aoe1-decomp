from __future__ import annotations

import csv
import json
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]


class ScrAchTranslationUnitTests(unittest.TestCase):
    def test_scr_ach_owners_follow_pdb_source_order(self) -> None:
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
        self.assertEqual(
            [row["va"].upper() for row in owners],
            [
                "0048D530",
                "0048E210",
                "0048E400",
                "0048F0B0",
                "0048F190",
                "0048F280",
                "0048F500",
                "0048F530",
            ],
        )

        source = (REPO_ROOT / "src" / "scr_ach.cpp").read_text(encoding="utf-8")
        self.assertNotIn('.cpp"', source)
        self.assertNotIn("SCR_ACH_TU_CONTEXT", source)
        self.assertNotIn("#if 0", source)
        self.assertIn('#include "../include/scr_ach.h"', source)

    def test_scr_ach_module_metadata_owns_all_functions(self) -> None:
        metadata = json.loads(
            (REPO_ROOT / "config" / "source_modules" / "scr_ach.json").read_text(
                encoding="utf-8"
            )
        )
        self.assertEqual(metadata["source"], "src/scr_ach.cpp")
        self.assertEqual(metadata["header"], "include/scr_ach.h")
        self.assertEqual(len(metadata["functions"]), 8)
        self.assertEqual(
            {entry["status"] for entry in metadata["functions"].values()},
            {"matching", "scratch"},
        )


if __name__ == "__main__":
    unittest.main()
