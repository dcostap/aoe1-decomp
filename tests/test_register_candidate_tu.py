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
    affected_owner_checks,
    changed_owner_checks,
    introduced_validation_issues,
    merge_candidate_group,
    run_registered_checks,
)
from validate_translation_units import ValidationIssue  # noqa: E402


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

    def test_candidate_group_detects_direct_source_module(self) -> None:
        payload = {
            "name": "demo_candidate",
            "source": "src\\demo.cpp",
            "flags": "config\\flags\\default.rsp",
            "owners": {"00401010": "src/demo.cpp"},
            "observed": {},
            "symbols": {},
        }
        modules = [{"name": "demo", "source": "src/demo.cpp"}]
        from unittest.mock import patch

        with patch("register_candidate_tu.load_source_modules", return_value=modules):
            group = candidate_group(payload)

        self.assertEqual(group["module"], "demo")

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

    def test_merge_direct_module_uses_va_order_and_keeps_module(self) -> None:
        groups = [
            {
                "name": "demo",
                "source": "src/demo.cpp",
                "module": "demo",
                "flags": "config/flags/default.rsp",
                "owners": {"00401020": "src/demo.cpp"},
            }
        ]
        candidate = {
            "name": "demo",
            "source": "src/demo.cpp",
            "module": "demo",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/demo.cpp"},
        }

        merged, action = merge_candidate_group(groups, candidate)

        self.assertEqual(action, "update")
        self.assertEqual(merged[0]["module"], "demo")
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

    def test_changed_owner_checks_ignores_unchanged_owners(self) -> None:
        groups = [
            {
                "name": "demo",
                "source": "src/demo_tu.cpp",
                "flags": "config/flags/default.rsp",
                "owners": {
                    "00401010": "src/matching/00401010_demo.cpp",
                    "00401020": "src/matching/00401020_old.cpp",
                },
                "symbols": {"00401010": "?demo@@YAXXZ"},
            }
        ]
        candidate = {
            "name": "demo",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {
                "00401010": "src\\matching\\00401010_demo.cpp",
                "00401020": "src/matching/00401020_new.cpp",
                "00401030": "src/matching/00401030_added.cpp",
            },
            "symbols": {"00401010": "?demo@@YAXXZ"},
        }

        changed = changed_owner_checks(groups, candidate)

        self.assertEqual(list(changed), ["00401020", "00401030"])

    def test_changed_owner_checks_includes_new_symbol(self) -> None:
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
            "owners": {"00401010": "src/matching/00401010_demo.cpp"},
            "symbols": {"00401010": "?demo@@YAXXZ"},
        }

        self.assertEqual(
            changed_owner_checks(groups, candidate),
            {"00401010": "src/matching/00401010_demo.cpp"},
        )

    def test_affected_owner_checks_keeps_existing_group_owners(self) -> None:
        groups = [
            {
                "name": "demo",
                "source": "src/demo_tu.cpp",
                "flags": "config/flags/default.rsp",
                "owners": {
                    "00401010": "src/matching/00401010_demo.cpp",
                    "00401020": "src/matching/00401020_old.cpp",
                },
            }
        ]
        candidate = {
            "name": "demo",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401030": "src/matching/00401030_added.cpp"},
        }
        merged, _ = merge_candidate_group(groups, candidate)

        self.assertEqual(
            affected_owner_checks(groups, candidate, merged),
            {
                "00401010": "src/matching/00401010_demo.cpp",
                "00401020": "src/matching/00401020_old.cpp",
                "00401030": "src/matching/00401030_added.cpp",
            },
        )

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

    def test_candidate_flag_errors_ignores_superseded_isolated_flags(self) -> None:
        candidate = {
            "name": "demo",
            "source": "src/demo.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/demo.cpp"},
        }
        report = {
            "issues": [
                {
                    "code": "stale_per_function_exception",
                    "scope": "current:demo",
                    "severity": "error",
                    "message": "old isolated flags",
                }
            ]
        }
        from unittest.mock import patch

        with patch("register_candidate_tu.load_functions", return_value=[]), patch(
            "register_candidate_tu.load_pdb_function_source_map", return_value={}
        ), patch("register_candidate_tu.load_original_needs", return_value={}), patch(
            "register_candidate_tu.audit_translation_units", return_value=report
        ):
            issues = candidate_flag_errors(candidate)

        self.assertEqual(issues, [])

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

    def test_introduced_validation_issues_ignores_existing_debt(self) -> None:
        existing = ValidationIssue("old", "unrelated")
        added = ValidationIssue("new", "candidate")

        self.assertEqual(
            introduced_validation_issues([existing], [existing, added]),
            [added],
        )

    def test_introduced_validation_issues_tracks_duplicate_counts(self) -> None:
        existing = ValidationIssue("old", "repeated")

        self.assertEqual(
            introduced_validation_issues([existing], [existing, existing]),
            [existing],
        )


if __name__ == "__main__":
    unittest.main()
