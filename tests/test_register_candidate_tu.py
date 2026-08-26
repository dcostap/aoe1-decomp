from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from register_candidate_tu import (  # noqa: E402
    candidate_group,
    candidate_flag_errors,
    merge_candidate_group,
    run_registered_checks,
)


class RegisterCandidateTranslationUnitTests(unittest.TestCase):
    def test_candidate_group_keeps_only_owner_symbols(self) -> None:
        payload = {
            "name": "demo",
            "source": "src\\demo_tu.cpp",
            "flags": "config\\flags\\default.rsp",
            "owners": {"00401010": "src/matching/00401010_demo.cpp"},
            "observed": {"00401020": {"source": "src/scratch/00401020_other.cpp"}},
            "symbols": {
                "00401010": "?demo@@YAXXZ",
                "00401020": "?other@@YAXXZ",
            },
        }

        group = candidate_group(payload)

        self.assertEqual(group["source"], "src/demo_tu.cpp")
        self.assertEqual(group["symbols"], {"00401010": "?demo@@YAXXZ"})

    def test_merge_adds_one_new_group(self) -> None:
        candidate = {
            "name": "demo",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/matching/00401010_demo.cpp"},
        }

        groups, action = merge_candidate_group([], candidate)

        self.assertEqual(action, "add")
        self.assertEqual(groups, [candidate])

    def test_merge_updates_same_group_without_removing_owners(self) -> None:
        groups = [
            {
                "name": "demo",
                "source": "src/demo_tu.cpp",
                "flags": "config/flags/default.rsp",
                "owners": {"00401010": "src/matching/00401010_demo.cpp"},
            }
        ]
        candidate = {
            "name": "demo",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401020": "src/matching/00401020_other.cpp"},
        }

        merged, action = merge_candidate_group(groups, candidate)

        self.assertEqual(action, "update")
        self.assertEqual(list(merged[0]["owners"]), ["00401010", "00401020"])

    def test_merge_uses_wrapper_owner_order(self) -> None:
        groups = [
            {
                "name": "demo",
                "source": "src/demo_tu.cpp",
                "flags": "config/flags/default.rsp",
                "owners": {"00401020": "src/matching/00401020_late.cpp"},
            }
        ]
        candidate = {
            "name": "demo",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/matching/00401010_early.cpp"},
        }

        with tempfile.TemporaryDirectory() as temp_dir:
            root = Path(temp_dir)
            wrapper = root / "src" / "demo_tu.cpp"
            wrapper.parent.mkdir(parents=True)
            wrapper.write_text(
                '#include "scratch/00401010_early.cpp"\n'
                '#include "matching/00401020_late.cpp"\n',
                encoding="utf-8",
            )

            merged, action = merge_candidate_group(groups, candidate, root=root)

        self.assertEqual(action, "update")
        self.assertEqual(list(merged[0]["owners"]), ["00401010", "00401020"])

    def test_merge_rejects_an_owner_from_another_group(self) -> None:
        groups = [
            {
                "name": "first",
                "source": "src/first_tu.cpp",
                "flags": "config/flags/default.rsp",
                "owners": {"00401010": "src/matching/00401010_demo.cpp"},
            }
        ]
        candidate = {
            "name": "second",
            "source": "src/second_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/matching/00401010_demo.cpp"},
        }

        with self.assertRaisesRegex(ValueError, "already owned"):
            merge_candidate_group(groups, candidate)

    def test_candidate_flag_errors_returns_only_current_errors(self) -> None:
        candidate = {
            "name": "demo",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/matching/00401010_demo.cpp"},
        }
        report = {
            "issues": [
                {"scope": "current:demo", "severity": "warning", "message": "warning"},
                {"scope": "current:demo", "severity": "error", "message": "blocked"},
                {"scope": "proposed:demo.cpp", "severity": "error", "message": "proposal"},
            ]
        }
        from unittest.mock import patch

        with patch("register_candidate_tu.load_functions", return_value=[]), patch(
            "register_candidate_tu.load_pdb_function_source_map", return_value={}
        ), patch("register_candidate_tu.load_original_needs", return_value={}), patch(
            "register_candidate_tu.audit_translation_units", return_value=report
        ):
            issues = candidate_flag_errors(candidate)

        self.assertEqual([issue["message"] for issue in issues], ["blocked"])

    def test_registered_checks_keep_owner_order(self) -> None:
        from unittest.mock import patch

        with patch(
            "register_candidate_tu._registered_check",
            side_effect=lambda va: (va, True, "MATCH"),
        ):
            results = run_registered_checks(
                {"00401020": "second", "00401010": "first"},
                jobs=2,
            )

        self.assertEqual([result[0] for result in results], ["00401020", "00401010"])


if __name__ == "__main__":
    unittest.main()
