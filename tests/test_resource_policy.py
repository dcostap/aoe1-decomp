from __future__ import annotations

import re
import sys
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import audit_translation_unit_functions  # noqa: E402
import find_function_donors  # noqa: E402
import generate_toolchain_supplied_manifest  # noqa: E402
import query_abi  # noqa: E402
import query_project_status  # noqa: E402
import search_asm_donors  # noqa: E402
import target_session  # noqa: E402
import variant_lab  # noqa: E402


class ResourcePolicyTests(unittest.TestCase):
    def test_result_limits_default_to_unlimited(self) -> None:
        cases = (
            (query_project_status, ["query_project_status.py", "--va", "00400000"]),
            (find_function_donors, ["find_function_donors.py", "--va", "00400000"]),
            (query_abi, ["query_abi.py", "--va", "00400000"]),
            (search_asm_donors, ["search_asm_donors.py", "--va", "00400000"]),
        )
        for module, argv in cases:
            with self.subTest(module=module.__name__), patch.object(sys, "argv", argv):
                self.assertEqual(module.parse_args().limit, 0)
        with patch.object(sys, "argv", ["find_function_donors.py", "--va", "00400000"]):
            self.assertEqual(find_function_donors.parse_args().candidate_pool, 0)

    def test_parallel_tools_require_user_selected_jobs(self) -> None:
        with patch.object(sys, "argv", ["audit_translation_unit_functions.py"]):
            with self.assertRaises(SystemExit):
                audit_translation_unit_functions.parse_args()
        with patch.object(
            sys,
            "argv",
            ["audit_translation_unit_functions.py", "--jobs", "37"],
        ):
            self.assertEqual(audit_translation_unit_functions.parse_args().jobs, 37)

        defaults = variant_lab.parse_args(["--va", "00400000", "--template", "demo.cpp"])
        self.assertIsNone(defaults.jobs)
        self.assertEqual(defaults.max_variants, 0)
        self.assertEqual(defaults.compile_timeout, 0)

    def test_leases_require_user_selected_duration(self) -> None:
        with patch.object(
            sys,
            "argv",
            ["target_session.py", "start", "--va", "00400000", "--owner", "worker"],
        ):
            with self.assertRaises(SystemExit):
                target_session.parse_args()
        with patch.object(
            sys,
            "argv",
            [
                "target_session.py",
                "start",
                "--va",
                "00400000",
                "--owner",
                "worker",
                "--lease-hours",
                "19",
            ],
        ):
            self.assertEqual(target_session.parse_args().lease_hours, 19)

    def test_manifest_classification_thresholds_are_user_supplied(self) -> None:
        with patch.object(sys, "argv", ["generate_toolchain_supplied_manifest.py"]):
            with self.assertRaises(SystemExit):
                generate_toolchain_supplied_manifest.parse_args()
        with patch.object(
            sys,
            "argv",
            [
                "generate_toolchain_supplied_manifest.py",
                "--max-probable-region-span-bytes",
                "0x900",
                "--max-probable-anchor-distance-bytes",
                "0x500",
                "--max-probable-anchor-scan-functions",
                "13",
            ],
        ):
            args = generate_toolchain_supplied_manifest.parse_args()
        self.assertEqual(args.max_probable_region_span_bytes, 0x900)
        self.assertEqual(args.max_probable_anchor_distance_bytes, 0x500)
        self.assertEqual(args.max_probable_anchor_scan_functions, 13)

    def test_policy_docs_do_not_set_numeric_worker_limits(self) -> None:
        paths = [REPO_ROOT / "README.md", *(REPO_ROOT / "docs").glob("*.md")]
        forbidden = (
            re.compile(r"no more than\s+\d+", re.IGNORECASE),
            re.compile(r"\d+\s+concurrent\s+max", re.IGNORECASE),
            re.compile(r"recycle .* after (?:\d+|three|four)", re.IGNORECASE),
            re.compile(r"--jobs\s+\d+", re.IGNORECASE),
        )
        failures: list[str] = []
        for path in paths:
            text = path.read_text(encoding="utf-8", errors="replace")
            for pattern in forbidden:
                if pattern.search(text):
                    failures.append(f"{path.relative_to(REPO_ROOT)}: {pattern.pattern}")
        self.assertEqual(failures, [])

    def test_current_tools_do_not_read_retired_source_banks(self) -> None:
        paths = (
            REPO_ROOT / "tools" / "find_function_donors.py",
            REPO_ROOT / "tools" / "query_abi.py",
            REPO_ROOT / "tools" / "search_asm_donors.py",
            REPO_ROOT / "tools" / "variant_lab.py",
        )
        failures: list[str] = []
        for path in paths:
            text = path.read_text(encoding="utf-8", errors="replace")
            for bank in ("src/matching", "src/scratch", "src/accepted_drift", "src/verified_logic"):
                if bank in text or bank.replace("/", '" / "') in text:
                    failures.append(f"{path.name}: {bank}")
        self.assertEqual(failures, [])


if __name__ == "__main__":
    unittest.main()
