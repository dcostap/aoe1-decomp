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
        common.function_entries_by_va.cache_clear()
        common._validate_build_module_cached.cache_clear()

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

    def test_function_registry_lookup_builds_va_index_once(self) -> None:
        modules = [
            {
                "name": "demo",
                "source": "src/demo.cpp",
                "functions": {
                    "00001000": {"status": "scratch"},
                    "00002000": {"status": "matching"},
                },
            }
        ]
        common.function_entries_by_va.cache_clear()

        with patch.object(common, "load_function_modules", return_value=modules) as load:
            self.assertEqual(common.function_entry_for_va(0x1000)["status"], "scratch")
            self.assertEqual(common.function_entry_for_va("00002000")["status"], "matching")

        load.assert_called_once_with()

    def test_build_module_validation_runs_once_per_payload(self) -> None:
        group = {
            "name": "demo",
            "source": "src/demo.cpp",
            "build": {"flags": "default", "flags_path": "config/flags/default.rsp"},
            "functions": {
                "00001000": {"status": "matching", "symbol": "?demo@@YAHXZ"}
            },
        }
        common._validate_build_module_cached.cache_clear()

        with patch.object(common, "_validate_build_module_uncached") as validate:
            common.validate_build_module(group)
            common.validate_build_module(group)

        validate.assert_called_once()


if __name__ == "__main__":
    unittest.main()
