from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from diff_function import _stack_home_pairing  # noqa: E402


class StackHomePairingTests(unittest.TestCase):
    def test_pairs_only_exact_coordinates_with_compatible_roles_and_widths(self) -> None:
        original_memory = {
            "stack": [
                {
                    "entry_coordinate": 4,
                    "width": 4,
                    "access": "read",
                    "occurrence_count": 2,
                },
                {
                    "entry_coordinate": -12,
                    "width": 4,
                    "access": "write",
                    "occurrence_count": 1,
                },
                {
                    "entry_coordinate": -12,
                    "width": 4,
                    "access": "read",
                    "occurrence_count": 1,
                },
            ]
        }
        rebuilt_listing = {
            "stack_homes": [
                {
                    "name": "value",
                    "kind": "parameter",
                    "offset": 8,
                    "entry_coordinate": 4,
                    "widths": [4],
                },
                {
                    "name": "temporary",
                    "kind": "local",
                    "offset": -8,
                    "entry_coordinate": -12,
                    "widths": [4],
                },
            ]
        }

        result = _stack_home_pairing(original_memory, rebuilt_listing)

        self.assertEqual([row["status"] for row in result["rows"]], ["paired", "paired"])
        self.assertEqual(result["status_counts"]["paired"], 2)

    def test_excludes_single_write_outgoing_slot_and_reports_width_conflict(self) -> None:
        original_memory = {
            "stack": [
                {
                    "entry_coordinate": -8,
                    "width": 4,
                    "access": "write",
                    "occurrence_count": 1,
                },
                {
                    "entry_coordinate": -12,
                    "width": 4,
                    "access": "read_write",
                    "occurrence_count": 1,
                },
            ]
        }
        rebuilt_listing = {
            "stack_homes": [
                {
                    "name": "byte_value",
                    "kind": "local",
                    "offset": -8,
                    "entry_coordinate": -12,
                    "widths": [1],
                },
            ]
        }

        result = _stack_home_pairing(original_memory, rebuilt_listing)

        self.assertEqual(len(result["rows"]), 1)
        self.assertEqual(result["rows"][0]["entry_coordinate"], -12)
        self.assertEqual(result["rows"][0]["status"], "width_mismatch")
        self.assertEqual(result["rows"][0]["width_evidence"], "conflict")


if __name__ == "__main__":
    unittest.main()
