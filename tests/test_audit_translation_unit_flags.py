from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import audit_translation_unit_flags as flag_audit  # noqa: E402
from audit_translation_unit_flags import (  # noqa: E402
    audit_translation_units,
    flag_settings,
    load_original_needs,
    tokenize_response_flags,
)


class TranslationUnitFlagAuditTests(unittest.TestCase):
    def test_original_eh_probe_does_not_treat_saved_ebp_as_an_ebp_frame(self) -> None:
        from common import function_record_by_va

        needs = load_original_needs([function_record_by_va(0x00431150)])
        self.assertTrue(needs["00431150"]["eh"])
        self.assertFalse(needs["00431150"]["frame_pointer"])

    def test_response_tokens_ignore_comments_and_last_switch_wins(self) -> None:
        tokens = tokenize_response_flags(
            "/nologo /c /O2 // baseline\n/GX\n/Oy- // keep EBP\n"
        )
        self.assertEqual(tokens, ("/nologo", "/c", "/O2", "/GX", "/Oy-"))
        settings = flag_settings(tokens, input_language="cpp")
        self.assertEqual(settings["optimization"], "o2")
        self.assertEqual(settings["frame"], "keep")
        self.assertEqual(settings["eh"], "enabled")
        self.assertEqual(settings["language"], "cpp")
        self.assertEqual(flag_settings(("/GX", "/GX-"))["eh"], "disabled")

    def test_current_registry_has_no_blocking_flag_issue(self) -> None:
        report = audit_translation_units(original_needs={})
        self.assertEqual(report["summary"]["module_count"], 224)
        self.assertEqual(report["summary"]["blocking_issue_count"], 0)

    def test_audit_checks_language_eh_and_frame_against_original(self) -> None:
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            flags = root / "config" / "flags" / "default.rsp"
            source = root / "src" / "legacy.c"
            flags.parent.mkdir(parents=True)
            source.parent.mkdir(parents=True)
            flags.write_text("/nologo /c /O2 /Oy /TP\n", encoding="utf-8")
            source.write_text("int legacy(void) { return 0; }\n", encoding="utf-8")
            record = {
                "va": "00100020",
                "name": "legacy",
                "slug": "00100020_legacy",
                "size_bytes": "16",
                "pdb_source_file": "legacy.c",
                "pdb_source_path": "C:\\src\\legacy.c",
                "calling_convention": "__cdecl",
            }
            source_map = {
                "00100020": {
                    "va": "00100020",
                    "symbol_name": "legacy",
                    "primary_source_path": "C:\\src\\legacy.c",
                    "primary_source_file": "legacy.c",
                    "line_start": "10",
                    "line_end": "20",
                }
            }
            module = {
                "name": "legacy",
                "source": "src/legacy.c",
                "build": {
                    "flags": "default",
                    "flags_path": "config/flags/default.rsp",
                },
                "functions": {
                    "00100020": {
                        "status": "scratch",
                        "symbol": "_legacy",
                    }
                },
            }
            with patch.object(flag_audit, "preferred_source_path", return_value=source):
                report = audit_translation_units(
                    groups=[module],
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
