from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from generate_source_module_inventory import (  # noqa: E402
    build_source_module_inventory,
)
from common import load_translation_units  # noqa: E402


class SourceModuleInventoryTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.inventory = build_source_module_inventory()
        cls.modules = {module["name"]: module for module in cls.inventory["modules"]}

    def test_current_manifest_has_ordered_groups(self) -> None:
        configured = load_translation_units()
        self.assertEqual(self.inventory["translation_unit_count"], len(configured))
        self.assertEqual(
            self.inventory["owner_count"],
            sum(len(group["owners"]) for group in configured),
        )
        self.assertEqual(self.inventory["translation_unit_count"], len(self.modules))
        self.assertEqual(self.modules.keys(), {str(group["name"]) for group in configured})
        for module in self.modules.values():
            owners = module["owners"]
            self.assertEqual(
                [owner["va"] for owner in owners],
                sorted((owner["va"] for owner in owners), key=lambda va: int(va, 16)),
            )
            self.assertEqual([owner["address_order"] for owner in owners], list(range(1, len(owners) + 1)))

    def test_pdb_module_line_and_class_context_is_preserved(self) -> None:
        module = self.modules["com_obj_enter"]
        self.assertEqual(module["module_name"], "com_obj.cpp")
        self.assertEqual(module["module_name_source"], "pdb_source_file")
        self.assertEqual(
            [owner["source_line"] for owner in module["owners"]],
            [179, 532, 541, 569, 980, 1252, 1301, 1309, 1356],
        )
        self.assertEqual({owner["class_owner"] for owner in module["owners"]}, {"RGE_Combat_Object"})
        self.assertIn("pdb_source_module", module["context"]["flags"])
        self.assertIn("source_line_order", module["context"]["flags"])
        self.assertIn("class_ownership", module["context"]["flags"])
        self.assertIn("address_sequence", module["context"]["flags"])

    def test_bank_and_exact_status_are_per_owner(self) -> None:
        module = self.modules["zone_map"]
        owners = {owner["va"]: owner for owner in module["owners"]}
        self.assertTrue(all(owner["bank"] == "matching" for owner in owners.values()))
        for owner in owners.values():
            self.assertIn(owner["exact_status"], {"MATCH", "MISMATCH", "UNVALIDATED"})
            if owner["exact_status"] == "UNVALIDATED":
                self.assertFalse(owner["exact_anchor"])
            if owner["exact_anchor"]:
                self.assertEqual(owner["exact_status"], "MATCH")
        self.assertEqual(
            module["context"]["exact_anchor_count"],
            sum(owner["exact_anchor"] for owner in owners.values()),
        )
        self.assertEqual(module["exact_owner_count"], module["context"]["exact_anchor_count"])

    def test_exact_anchor_always_has_generated_diff_evidence(self) -> None:
        for module in self.modules.values():
            for owner in module["owners"]:
                if owner["exact_anchor"]:
                    self.assertTrue(owner["exact_evidence"].startswith("build/diff/"))
                    self.assertEqual(owner["exact_status"], "MATCH")


if __name__ == "__main__":
    unittest.main()
