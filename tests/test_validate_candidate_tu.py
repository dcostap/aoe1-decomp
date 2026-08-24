from __future__ import annotations

import json
import sys
import tempfile
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from validate_candidate_tu import (  # noqa: E402
    _newline_style,
    _render,
    _source_policy_issues,
    load_proposal,
)


class CandidateTranslationUnitTests(unittest.TestCase):
    def test_newline_style_detects_mixed_files(self) -> None:
        self.assertEqual(_newline_style(b"one\r\ntwo\r\n"), "CRLF")
        self.assertEqual(_newline_style(b"one\ntwo\n"), "LF")
        self.assertEqual(_newline_style(b"one\r\ntwo\n"), "mixed")

    def test_load_proposal_normalizes_sections(self) -> None:
        payload = {
            "schema": 1,
            "name": "demo",
            "module": "demo.cpp",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/matching/00401010_demo.cpp"},
            "observed": {
                "00401020": {
                    "source": "src/scratch/00401020_demo.cpp",
                    "status": "scratch",
                }
            },
            "generated": {"00401030": "??_GDemo@@UAEPAXI@Z"},
            "symbols": {"00401010": "?demo@Demo@@QAEXXZ"},
        }
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "proposal.json"
            path.write_text(json.dumps(payload), encoding="utf-8")
            result = load_proposal(path)

        self.assertEqual(result["owners"]["00401010"], "src/matching/00401010_demo.cpp")
        self.assertEqual(result["observed"]["00401020"]["status"], "scratch")
        self.assertEqual(result["generated"]["00401030"], "??_GDemo@@UAEPAXI@Z")

    def test_load_proposal_rejects_va_in_two_sections(self) -> None:
        payload = {
            "schema": 1,
            "name": "demo",
            "module": "demo.cpp",
            "source": "src/demo_tu.cpp",
            "flags": "config/flags/default.rsp",
            "owners": {"00401010": "src/matching/00401010_demo.cpp"},
            "observed": {"00401010": "src/scratch/00401010_demo.cpp"},
        }
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "proposal.json"
            path.write_text(json.dumps(payload), encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "more than one"):
                load_proposal(path)

    def test_render_has_one_compact_result_row(self) -> None:
        text = _render(
            [
                {
                    "va": "00401010",
                    "kind": "exact",
                    "status": "matching",
                    "result": "MATCH",
                    "diff_bytes": 0,
                    "owner_status": "match",
                    "relocation_target_mismatches": 0,
                    "boundary_escape_count": 0,
                }
            ]
        )
        self.assertIn("00401010", text)
        self.assertIn("MATCH", text)

    def test_source_policy_rejects_fake_virtual_slots(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temporary:
            root = Path(temporary)
            wrapper = root / "demo.cpp"
            context = root / "context.h"
            wrapper.write_text('#include "context.h"\n', encoding="utf-8")
            context.write_text(
                "class Demo { public: virtual void vf10(); void* vptr; };\n",
                encoding="utf-8",
            )

            issues = _source_policy_issues(wrapper)

        self.assertTrue(any("placeholder virtual slots" in issue for issue in issues))
        self.assertTrue(any("raw vtable fields" in issue for issue in issues))


if __name__ == "__main__":
    unittest.main()
