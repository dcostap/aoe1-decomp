from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from merge_translation_unit_reports import merge_reports  # noqa: E402


def audit_group(name: str, category: str, registered: bool) -> dict[str, object]:
    return {
        "group": name,
        "source": f"src/{name}.cpp",
        "flags": "config/flags/default.rsp",
        "compile_error": "",
        "rows": [
            {
                "group": name,
                "category": category,
                "registered_anywhere": registered,
            }
        ],
    }


class MergeTranslationUnitReportsTests(unittest.TestCase):
    def test_focused_report_replaces_one_group_and_keeps_order(self) -> None:
        base = {
            "schema": 1,
            "groups": [
                audit_group("first", "grouped_mismatch", False),
                audit_group("second", "grouped_mismatch", False),
            ],
        }
        update = {
            "schema": 1,
            "groups": [audit_group("second", "registered_owner_match", True)],
        }
        registered = [
            {"name": "first"},
            {"name": "second"},
        ]

        merged = merge_reports(base, [update], registered)

        self.assertEqual([group["group"] for group in merged["groups"]], ["first", "second"])
        self.assertEqual(merged["summary"]["registered_owner_count"], 1)
        self.assertEqual(
            merged["summary"]["category_counts"],
            {"grouped_mismatch": 1, "registered_owner_match": 1},
        )

    def test_later_focused_report_wins(self) -> None:
        base = {"schema": 1, "groups": [audit_group("demo", "old", False)]}
        first = {"schema": 1, "groups": [audit_group("demo", "first", False)]}
        second = {"schema": 1, "groups": [audit_group("demo", "second", True)]}

        merged = merge_reports(base, [first, second], [{"name": "demo"}])

        self.assertEqual(merged["rows"][0]["category"], "second")
        self.assertEqual(merged["summary"]["registered_owner_count"], 1)


if __name__ == "__main__":
    unittest.main()
