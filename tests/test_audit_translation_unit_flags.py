from __future__ import annotations

import tempfile
import unittest
from pathlib import Path

import sys

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from audit_translation_unit_flags import (  # noqa: E402
    audit_translation_units,
    flag_settings,
    load_original_needs,
    tokenize_response_flags,
)


def _record(va: str, slug: str, name: str, owner: str) -> dict[str, str]:
    return {
        "va": va,
        "name": name,
        "slug": slug,
        "size_bytes": "16",
        "pdb_source_file": "demo.cpp",
        "pdb_source_path": "C:\\src\\demo.cpp",
        "calling_convention": "__cdecl",
    }


def _source_row(va: str, file_name: str = "demo.cpp") -> dict[str, str]:
    return {
        "va": va,
        "symbol_name": f"Demo::{file_name.split('.')[0]}",
        "primary_source_path": f"C:\\src\\{file_name}",
        "primary_source_file": file_name,
        "line_start": "10",
        "line_end": "20",
    }


class TranslationUnitFlagAuditTests(unittest.TestCase):
    def test_original_eh_probe_does_not_treat_saved_ebp_as_an_ebp_frame(self) -> None:
        from common import function_record_by_va

        needs = load_original_needs([function_record_by_va(0x00431150)])
        self.assertTrue(needs["00431150"]["eh"])
        self.assertFalse(needs["00431150"]["frame_pointer"])

    def test_response_tokens_ignore_comments_and_last_switch_wins(self) -> None:
        tokens = tokenize_response_flags(
            '/nologo /c /O2 // baseline\n/GX\n/Oy- // keep EBP\n'
        )
        self.assertEqual(tokens, ("/nologo", "/c", "/O2", "/GX", "/Oy-"))
        settings = flag_settings(tokens, input_language="cpp")
        self.assertEqual(settings["optimization"], "o2")
        self.assertEqual(settings["frame"], "keep")
        self.assertEqual(settings["eh"], "enabled")
        self.assertEqual(settings["language"], "cpp")
        self.assertEqual(flag_settings(("/GX", "/GX-"))["eh"], "disabled")

    def test_audit_reports_stale_owner_overlay_and_proposed_module_conflict(self) -> None:
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            flags = root / "config" / "flags"
            flags.mkdir(parents=True)
            (flags / "default.rsp").write_text("/nologo /c /O2 /Oy\n", encoding="utf-8")
            (flags / "00100000_alpha.rsp").write_text("/nologo /c /O2 /Oy /GX\n", encoding="utf-8")
            (flags / "00100010_beta.rsp").write_text("/nologo /c /O2 /Oy\n", encoding="utf-8")
            wrapper = root / "src" / "demo_tu.cpp"
            owner_a = root / "src" / "00100000_alpha.cpp"
            owner_b = root / "src" / "00100010_beta.cpp"
            wrapper.parent.mkdir(parents=True)
            wrapper.write_text("", encoding="utf-8")
            owner_a.write_text("", encoding="utf-8")
            owner_b.write_text("", encoding="utf-8")

            records = [
                _record("00100000", "00100000_alpha", "alpha", str(owner_a)),
                _record("00100010", "00100010_beta", "beta", str(owner_b)),
            ]
            source_map = {
                "00100000": _source_row("00100000"),
                "00100010": _source_row("00100010"),
            }
            groups = [
                {
                    "name": "demo",
                    "source": "src/demo_tu.cpp",
                    "flags": "config/flags/default.rsp",
                    "owners": {
                        "00100000": "src/00100000_alpha.cpp",
                        "00100010": "src/00100010_beta.cpp",
                    },
                }
            ]
            needs = {
                "00100000": {"eh": False, "frame_pointer": False, "frame_size": None, "evidence": {}},
                "00100010": {"eh": False, "frame_pointer": False, "frame_size": None, "evidence": {}},
            }

            report = audit_translation_units(
                groups=groups,
                records=records,
                source_map=source_map,
                original_needs=needs,
                root=root,
            )

        codes = {issue["code"] for issue in report["issues"]}
        self.assertIn("stale_per_function_exception", codes)
        self.assertIn("incompatible_custom_overlay", codes)
        self.assertEqual(report["summary"]["current_translation_unit_count"], 1)
        self.assertEqual(report["summary"]["proposed_module_count"], 1)

    def test_audit_checks_language_eh_and_frame_against_original(self) -> None:
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            flags = root / "config" / "flags"
            flags.mkdir(parents=True)
            (flags / "default.rsp").write_text("/nologo /c /O2 /Oy /TP\n", encoding="utf-8")
            wrapper = root / "src" / "legacy_tu.cpp"
            owner = root / "src" / "00100020_legacy.c"
            wrapper.parent.mkdir(parents=True)
            wrapper.write_text("", encoding="utf-8")
            owner.write_text("", encoding="utf-8")
            record = _record("00100020", "00100020_legacy", "legacy", str(owner))
            record["pdb_source_file"] = "legacy.c"
            source_map = {"00100020": _source_row("00100020", "legacy.c")}
            group = {
                "name": "legacy",
                "source": "src/legacy_tu.cpp",
                "flags": "config/flags/default.rsp",
                "owners": {"00100020": "src/00100020_legacy.c"},
            }
            report = audit_translation_units(
                groups=[group],
                records=[record],
                source_map=source_map,
                original_needs={
                    "00100020": {
                        "eh": True,
                        "frame_pointer": True,
                        "frame_size": 16,
                        "evidence": {"source": "test"},
                    }
                },
                root=root,
            )

        codes = {issue["code"] for issue in report["issues"]}
        self.assertIn("language_mismatch", codes)
        self.assertIn("eh_flag_missing", codes)
        self.assertIn("frame_flag_conflict", codes)


if __name__ == "__main__":
    unittest.main()
