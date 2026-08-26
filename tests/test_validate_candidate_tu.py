from __future__ import annotations

import json
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from validate_candidate_tu import (  # noqa: E402
    _compare_generated_entry,
    _compare_generated_destructor,
    _compiler_generated_destructor_symbols,
    _newline_style,
    _render,
    _source_policy_issues,
    load_proposal,
)


class CandidateTranslationUnitTests(unittest.TestCase):
    @staticmethod
    def _symbol(
        index: int,
        name: str,
        *,
        section_number: int,
        storage_class: int,
        auxiliary_count: int = 0,
        tag_index: int | None = None,
        characteristics: int | None = None,
        is_function: bool = True,
    ) -> SimpleNamespace:
        return SimpleNamespace(
            index=index,
            name=name,
            value=0,
            section_number=section_number,
            symbol_type=0x20 if is_function else 0,
            storage_class=storage_class,
            auxiliary_count=auxiliary_count,
            weak_external_tag_index=tag_index,
            weak_external_characteristics=characteristics,
            is_function=is_function,
        )

    @classmethod
    def _weak_destructor_object(cls, *, tag_name: str = "??_GRGE_Player@@UAEPAXI@Z", **weak) -> SimpleNamespace:
        auxiliary_count = weak.pop("auxiliary_count", 1)
        tag_index = weak.pop("tag_index", 9)
        characteristics = weak.pop("characteristics", 2)
        return SimpleNamespace(
            symbols=[
                cls._symbol(9, tag_name, section_number=0, storage_class=2),
                cls._symbol(
                    10,
                    "??_ERGE_Player@@UAEPAXI@Z",
                    section_number=0,
                    storage_class=105,
                    auxiliary_count=auxiliary_count,
                    tag_index=tag_index,
                    characteristics=characteristics,
                    **weak,
                ),
                cls._symbol(
                    27,
                    "??_GRGE_Player@@UAEPAXI@Z",
                    section_number=1,
                    storage_class=2,
                ),
            ]
        )

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

    def test_source_policy_rejects_token_pasted_virtual_slots(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temporary:
            source = Path(temporary) / "demo.cpp"
            source.write_text(
                "#define VPAD(n) virtual void vpad##n();\n",
                encoding="utf-8",
            )

            issues = _source_policy_issues(source)

        self.assertTrue(any("placeholder virtual slots" in issue for issue in issues))

    def test_generated_destructor_compares_defined_g_fallback(self) -> None:
        obj = self._weak_destructor_object()
        expected = "??_ERGE_Player@@UAEPAXI@Z"
        comparison = {
            "symbol": "??_GRGE_Player@@UAEPAXI@Z",
            "result": "MATCH",
        }
        with patch("validate_candidate_tu.compare_object_owner", return_value=comparison) as compare:
            result = _compare_generated_destructor(
                obj,
                0x0046E750,
                {"symbols": {"0046E750": expected}},
            )

        compare.assert_called_once()
        self.assertEqual(compare.call_args.kwargs["require_owner"], False)
        self.assertEqual(
            compare.call_args.args[2]["symbols"]["0046E750"],
            "??_GRGE_Player@@UAEPAXI@Z",
        )
        self.assertEqual(result["expected_symbol"], expected)
        self.assertEqual(result["fallback_symbol"], "??_GRGE_Player@@UAEPAXI@Z")

    def test_generated_destructor_rejects_missing_weak_symbol(self) -> None:
        obj = SimpleNamespace(
            symbols=[
                self._symbol(9, "??_GRGE_Player@@UAEPAXI@Z", section_number=0, storage_class=2),
                self._symbol(27, "??_GRGE_Player@@UAEPAXI@Z", section_number=1, storage_class=2),
            ]
        )
        with self.assertRaisesRegex(ValueError, "weak external"):
            _compiler_generated_destructor_symbols(
                obj,
                0x0046E750,
                "??_ERGE_Player@@UAEPAXI@Z",
            )

    def test_generated_destructor_rejects_different_class_fallback(self) -> None:
        obj = self._weak_destructor_object(tag_name="??_GOther_Player@@UAEPAXI@Z")
        with self.assertRaisesRegex(ValueError, "same-class"):
            _compiler_generated_destructor_symbols(
                obj,
                0x0046E750,
                "??_ERGE_Player@@UAEPAXI@Z",
            )

    def test_generated_destructor_rejects_missing_defined_fallback_body(self) -> None:
        obj = self._weak_destructor_object()
        obj.symbols.pop()
        with self.assertRaisesRegex(ValueError, "defined same-class fallback"):
            _compiler_generated_destructor_symbols(
                obj,
                0x0046E750,
                "??_ERGE_Player@@UAEPAXI@Z",
            )

    def test_generated_destructor_rejects_ordinary_weak_alias(self) -> None:
        obj = self._weak_destructor_object(characteristics=3)
        with self.assertRaisesRegex(ValueError, "VC5 fallback"):
            _compiler_generated_destructor_symbols(
                obj,
                0x0046E750,
                "??_ERGE_Player@@UAEPAXI@Z",
            )

    def test_generated_destructor_rejects_strong_synthetic_alias(self) -> None:
        obj = self._weak_destructor_object()
        obj.symbols[1] = self._symbol(
            10,
            "??_ERGE_Player@@UAEPAXI@Z",
            section_number=1,
            storage_class=2,
        )
        with self.assertRaisesRegex(ValueError, "WeakExternal"):
            _compiler_generated_destructor_symbols(
                obj,
                0x0046E750,
                "??_ERGE_Player@@UAEPAXI@Z",
            )

    def test_direct_generated_entry_keeps_old_comparison(self) -> None:
        expected = "?$E14@@YAXXZ"
        obj = SimpleNamespace(
            symbols=[
                self._symbol(
                    12,
                    expected,
                    section_number=1,
                    storage_class=2,
                )
            ]
        )
        comparison = {"symbol": expected, "result": "MATCH"}
        with patch("validate_candidate_tu.compare_object_owner", return_value=comparison) as compare:
            result = _compare_generated_entry(
                obj,
                0x004D6B20,
                {"symbols": {"004D6B20": expected}},
            )

        compare.assert_called_once()
        self.assertEqual(compare.call_args.kwargs["require_owner"], False)
        self.assertEqual(result, comparison)


if __name__ == "__main__":
    unittest.main()
