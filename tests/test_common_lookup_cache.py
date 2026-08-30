from __future__ import annotations

import sys
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import common  # noqa: E402


class CommonLookupCacheTests(unittest.TestCase):
    def tearDown(self) -> None:
        common.function_records_by_va.cache_clear()
        common.source_module_entries_by_va.cache_clear()
        common._validate_translation_unit_cached.cache_clear()

    def test_function_record_lookup_builds_inventory_index_once(self) -> None:
        records = [
            {"va": "00001000", "name": "one"},
            {"va": "00002000", "name": "two"},
        ]
        common.function_records_by_va.cache_clear()

        with patch.object(common, "load_functions", return_value=records) as load:
            self.assertEqual(common.function_record_by_va(0x1000)["name"], "one")
            self.assertEqual(common.function_record_by_va(0x2000)["name"], "two")

        load.assert_called_once_with()

    def test_source_module_lookup_builds_va_index_once(self) -> None:
        modules = [
            {
                "name": "demo",
                "source": "src/demo.cpp",
                "functions": {
                    "00001000": {"status": "scratch", "note_path": ""},
                    "00002000": {"status": "matching", "note_path": ""},
                },
            }
        ]
        common.source_module_entries_by_va.cache_clear()

        with patch.object(common, "load_source_modules", return_value=modules) as load:
            self.assertEqual(common.source_module_entry_for_va(0x1000)["status"], "scratch")
            self.assertEqual(common.source_module_entry_for_va("00002000")["status"], "matching")

        load.assert_called_once_with()

    def test_translation_unit_validation_runs_once_per_payload(self) -> None:
        group = {
            "name": "demo",
            "source": "src/demo.cpp",
            "flags": "",
            "owners": {"00001000": "src/demo.cpp"},
            "symbols": {},
            "module": "demo",
        }
        common._validate_translation_unit_cached.cache_clear()

        with patch.object(common, "_validate_translation_unit_uncached") as validate:
            common.validate_translation_unit(group)
            common.validate_translation_unit(group)

        validate.assert_called_once()


if __name__ == "__main__":
    unittest.main()
