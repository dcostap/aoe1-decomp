from __future__ import annotations

import sys
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from plan_translation_unit import build_packet, rank_modules  # noqa: E402


def row(va: str, bank: str, size: int, *, corpus: str = "normal") -> dict[str, str]:
    return {
        "va": va,
        "name": f"function_{va}",
        "size_bytes": str(size),
        "source_bucket": bank,
        "source_path": f"src/{bank}/{va}_function.cpp" if bank != "unclaimed" else "",
        "corpus_bucket": corpus,
        "corpus_reason": "generated" if corpus == "compiler_generated" else "",
        "pdb_source_path": "C:\\src\\demo.cpp" if corpus == "normal" else "",
        "pdb_source_file": "demo.cpp" if corpus == "normal" else "",
        "diff_result": "MATCH" if bank == "matching" else "MISMATCH",
        "positional_diff_bytes": "0" if bank == "matching" else "4",
        "custom_flags_path": "",
        "source_blocker": "",
    }


class TranslationUnitPlannerTests(unittest.TestCase):
    def test_packet_uses_pdb_line_order_and_nearby_generated_entries(self) -> None:
        rows = [
            row("00401020", "scratch", 20),
            row("00401010", "matching", 10),
            row("00401018", "unclaimed", 6, corpus="compiler_generated"),
        ]
        pdb = {
            "00401010": {
                "primary_source_path": "C:\\src\\demo.cpp",
                "primary_source_file": "demo.cpp",
                "line_start": "10",
                "line_end": "12",
                "symbol_name": "Demo::first",
            },
            "00401020": {
                "primary_source_path": "C:\\src\\demo.cpp",
                "primary_source_file": "demo.cpp",
                "line_start": "20",
                "line_end": "24",
                "symbol_name": "Demo::second",
            },
        }
        with patch(
            "plan_translation_unit._registered_owner_map",
            return_value={"00401010": "demo_prefix"},
        ):
            packet = build_packet("demo.cpp", rows, pdb)

        self.assertEqual([owner["va"] for owner in packet["owners"]], ["00401010", "00401020"])
        self.assertEqual(packet["summary"]["registered_exact"], 1)
        self.assertEqual(packet["nearby_compiler_generated"][0]["va"], "00401018")

    def test_ranking_rewards_matching_and_penalizes_scratch(self) -> None:
        rows = [
            row("00401010", "matching", 10),
            row("00401020", "matching", 10),
            {**row("00402010", "scratch", 10), "pdb_source_path": "C:\\src\\hard.cpp", "pdb_source_file": "hard.cpp"},
        ]
        pdb = {
            "00401010": {"primary_source_path": "C:\\src\\demo.cpp"},
            "00401020": {"primary_source_path": "C:\\src\\demo.cpp"},
            "00402010": {"primary_source_path": "C:\\src\\hard.cpp"},
        }
        with patch("plan_translation_unit._registered_owner_map", return_value={}):
            ranking = rank_modules(rows, pdb, 10)

        self.assertEqual(ranking[0]["module"], "demo.cpp")
        self.assertGreater(ranking[0]["readiness_score"], ranking[1]["readiness_score"])


if __name__ == "__main__":
    unittest.main()
