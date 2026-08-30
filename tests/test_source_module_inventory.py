from __future__ import annotations

import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from generate_source_module_inventory import (  # noqa: E402
    build_source_module_inventory,
    _diff_freshness,
    _strict_build_fingerprint,
)
import generate_source_module_inventory as inventory_module  # noqa: E402
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
            self.inventory["function_count"],
            sum(len(group["functions"]) for group in configured),
        )
        self.assertEqual(
            self.inventory["exact_validation_count"],
            sum(len(group["owners"]) for group in configured),
        )
        self.assertEqual(self.inventory["translation_unit_count"], len(self.modules))
        self.assertEqual(self.modules.keys(), {str(group["name"]) for group in configured})
        for module in self.modules.values():
            owners = module["functions"]
            self.assertEqual(
                [owner["va"] for owner in owners],
                sorted((owner["va"] for owner in owners), key=lambda va: int(va, 16)),
            )
            self.assertEqual([owner["address_order"] for owner in owners], list(range(1, len(owners) + 1)))

    def test_point_module_keeps_per_function_state_outside_source_paths(self) -> None:
        point = self.modules["point"]
        owners = {owner["va"]: owner for owner in point["functions"]}

        self.assertEqual(point["translation_unit_source"], "src/point.cpp")
        self.assertEqual(point["function_count"], 8)
        self.assertEqual(point["exact_validation_count"], 6)
        self.assertEqual(
            {owner["owner_path"] for owner in owners.values()},
            {"src/point.cpp"},
        )
        self.assertEqual(
            {va: owner["bank"] for va, owner in owners.items()},
            {
                "0047E480": "matching",
                "0047E490": "matching",
                "0047E4B0": "matching",
                "0047E4E0": "matching",
                "0047E510": "matching",
                "0047E530": "scratch",
                "0047E580": "matching",
                "0047E5D0": "scratch",
            },
        )
        self.assertEqual(
            owners["0047E530"]["function_note_path"],
            "decomp_notes/functions/0047/0047E530.md",
        )
        self.assertEqual(owners["0047E530"]["module_note_path"], "")

    def test_pdb_module_line_and_class_context_is_preserved(self) -> None:
        module = self.modules["scr_info"]
        self.assertEqual(module["module_name"], "scr_info.cpp")
        self.assertEqual(module["module_name_source"], "pdb_source_file")
        self.assertEqual(
            [owner["source_line"] for owner in module["functions"]],
            [32, 58, 65, 91, 101, 110, 118],
        )
        self.assertEqual(
            {owner["class_owner"] for owner in module["functions"]},
            {"TRIBE_Screen_Info"},
        )
        self.assertIn("pdb_source_module", module["context"]["flags"])
        self.assertIn("source_line_order", module["context"]["flags"])
        self.assertIn("class_ownership", module["context"]["flags"])
        self.assertIn("address_sequence", module["context"]["flags"])

    def test_bank_and_exact_status_are_per_owner(self) -> None:
        module = self.modules["zone_map"]
        owners = {owner["va"]: owner for owner in module["functions"]}
        self.assertEqual(
            {va: owner["bank"] for va, owner in owners.items()},
            {
                "00546720": "matching",
                "00546770": "matching",
                "005467B0": "accepted_drift",
                "005468C0": "scratch",
                "005469C0": "matching",
                "00546A00": "matching",
                "00546A90": "accepted_drift",
                "00546BB0": "matching",
                "00546E50": "matching",
                "00546EB0": "matching",
                "00546ED0": "matching",
                "00546F00": "matching",
                "00547000": "matching",
                "00547080": "matching",
                "00547180": "matching",
                "00547240": "matching",
                "00547260": "matching",
                "00547270": "matching",
                "005472B0": "matching",
                "005473B0": "matching",
                "005474B0": "matching",
                "005474D0": "matching",
            },
        )
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
        self.assertEqual(module["exact_result_count"], module["context"]["exact_anchor_count"])

    def test_exact_anchor_always_has_generated_diff_evidence(self) -> None:
        for module in self.modules.values():
            for owner in module["functions"]:
                if owner["exact_anchor"]:
                    self.assertTrue(owner["exact_evidence"].startswith("build/diff/"))
                    self.assertEqual(owner["exact_status"], "MATCH")

    def test_strict_diff_freshness_rejects_stale_build_fingerprint(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temporary:
            root = Path(temporary)
            source = root / "module.cpp"
            diff = root / "module.diff.json"
            source.write_text("void module() {}\n", encoding="utf-8")
            diff.write_text(
                json.dumps(
                    {
                        "rebuilt_source_map": {"source": str(source)},
                        "build_input_fingerprint": "old",
                    }
                ),
                encoding="utf-8",
            )

            fresh, reason = _diff_freshness(
                diff,
                expected_source=source,
                input_paths=[source],
                expected_build_fingerprint="current",
            )

        self.assertFalse(fresh)
        self.assertEqual(reason, "stale-build-inputs")

    def test_strict_fingerprint_requires_grouped_object_and_manifest(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temporary:
            root = Path(temporary)
            with patch.object(
                inventory_module, "BUILD_DIR", root
            ), patch.object(
                inventory_module,
                "_current_build_fingerprint",
                return_value="current",
            ):
                fingerprint = _strict_build_fingerprint(
                    "demo", root / "demo.cpp", root / "demo.rsp"
                )

        self.assertEqual(fingerprint, "")


if __name__ == "__main__":
    unittest.main()
