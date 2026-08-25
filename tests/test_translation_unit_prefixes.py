from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
TOOLS_DIR = REPO_ROOT / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from translation_unit_prefixes import (  # noqa: E402
    PdbOwner,
    _default_prefixes,
    compare_object_owner,
    render_filtered_wrapper,
    validate_authentic_prefix,
)


def owner(va: int, lines: tuple[int, int], *, module: str = "C:\\src\\fractal.cpp") -> PdbOwner:
    return PdbOwner(
        va=va,
        symbol_name="PointMaker::method",
        source_path=module,
        source_file="fractal.cpp",
        line_start=lines[0],
        line_end=lines[1],
        class_owner="PointMaker",
    )


class TranslationUnitPrefixTests(unittest.TestCase):
    def test_real_fractal_group_finds_authentic_prefix(self) -> None:
        from common import load_pdb_function_source_map, translation_unit_for_va

        source_map = load_pdb_function_source_map()
        group = translation_unit_for_va(0x0044B270)
        self.assertIsNotNone(group)
        assert group is not None
        target_row = source_map["0044B270"]
        target = owner(
            0x0044B270,
            (int(target_row["line_start"]), int(target_row["line_end"])),
            module=target_row["primary_source_path"],
        )
        prefixes = _default_prefixes(target, group, source_map)
        self.assertEqual(
            [item.va for item in prefixes],
            [0x0044AC50, 0x0044AC80, 0x0044B210],
        )

    def test_prefix_owner_comparison_requires_pdb_qualified_class(self) -> None:
        from coff import load_coff_object
        from common import translation_unit_for_va

        object_path = REPO_ROOT / "build" / "obj" / "tu_com_obj_enter.obj"
        if not object_path.is_file():
            self.skipTest("grouped object is not available in this checkout")
        group = translation_unit_for_va(0x004304A0)
        self.assertIsNotNone(group)
        assert group is not None
        obj = load_coff_object(object_path)

        # Use a deliberately wrong qualified owner. The grouped object now
        # carries the canonical RGE_Combat_Object symbol, so the test must
        # exercise the PDB-owner rejection instead of relying on stale bytes.
        wrong_pdb_symbol = "Other_Combat_Object::reset_attack_timer"
        result = compare_object_owner(obj, 0x004304A0, group, wrong_pdb_symbol)

        self.assertEqual("MISMATCH", result["result"])
        self.assertEqual("mismatch", result["owner_symbol"]["status"])

    def test_rejects_reversed_source_order(self) -> None:
        target = owner(0x0044B2B0, (194, 206))
        first = owner(0x0044B210, (176, 182))
        second = owner(0x0044B270, (185, 191))
        paths = {
            first.va: REPO_ROOT / "src" / "matching" / "first.cpp",
            second.va: REPO_ROOT / "src" / "matching" / "second.cpp",
        }
        with self.assertRaisesRegex(ValueError, "overlap or reverse"):
            validate_authentic_prefix(target, [second, first], paths)

    def test_rejects_a_different_pdb_module(self) -> None:
        target = owner(0x0044B2B0, (194, 206))
        prefix = owner(0x0044B210, (176, 182), module="C:\\src\\dummy.cpp")
        paths = {prefix.va: REPO_ROOT / "src" / "matching" / "first.cpp"}
        with self.assertRaisesRegex(ValueError, "different PDB source modules"):
            validate_authentic_prefix(target, [prefix], paths)

    def test_accepts_different_class_owner_in_same_source_module(self) -> None:
        target = owner(0x0044B2B0, (194, 206))
        prefix = PdbOwner(
            va=0x0044B210,
            symbol_name="OtherClass::method",
            source_path=target.source_path,
            source_file=target.source_file,
            line_start=176,
            line_end=182,
            class_owner="OtherClass",
        )
        paths = {prefix.va: REPO_ROOT / "src" / "matching" / "first.cpp"}
        self.assertEqual([], validate_authentic_prefix(target, [prefix], paths))

    def test_reports_address_order_conflict_without_rejecting_source_order(self) -> None:
        target = owner(0x0044B210, (194, 206))
        prefix = owner(0x0044B2B0, (176, 182))
        paths = {prefix.va: REPO_ROOT / "src" / "matching" / "first.cpp"}
        conflicts = validate_authentic_prefix(target, [prefix], paths)
        self.assertEqual(1, len(conflicts))
        self.assertEqual("0044B2B0", conflicts[0]["earlier_source_va"])

    def test_rejects_a_nonmatching_anchor_owner(self) -> None:
        target = owner(0x0044B2B0, (194, 206))
        prefix = owner(0x0044B210, (176, 182))
        paths = {prefix.va: REPO_ROOT / "build" / "dummy.cpp"}
        with self.assertRaisesRegex(ValueError, "not an exact anchor"):
            validate_authentic_prefix(target, [prefix], paths)

    def test_filtered_wrapper_has_one_owner_for_each_selected_va(self) -> None:
        include_lines = {
            0x10: '#include "matching/10.cpp"',
            0x20: '#include "matching/20.cpp"',
            0x30: '#include "matching/30.cpp"',
        }
        source = "\n".join(
            [
                '#include "../include/context.h"',
                include_lines[0x10],
                include_lines[0x20],
                include_lines[0x30],
                "",
            ]
        )
        rendered = render_filtered_wrapper(source, include_lines, [0x10, 0x30])
        self.assertEqual(rendered.count(include_lines[0x10]), 1)
        self.assertNotIn(include_lines[0x20], rendered)
        self.assertEqual(rendered.count(include_lines[0x30]), 1)

    def test_filtered_wrapper_preserves_authentic_context_between_owners(self) -> None:
        include_lines = {
            0x10: '#include "matching/10.cpp"',
            0x20: '#include "matching/20.cpp"',
        }
        context = '#include "../include/context.h"'
        source = "\n".join([include_lines[0x10], context, include_lines[0x20], ""])

        rendered = render_filtered_wrapper(source, include_lines, [0x10, 0x20])

        self.assertIn(context, rendered)
        self.assertEqual(rendered.count(include_lines[0x10]), 1)
        self.assertEqual(rendered.count(include_lines[0x20]), 1)

    def test_filtered_wrapper_rejects_duplicate_owner(self) -> None:
        include_lines = {0x10: '#include "matching/10.cpp"'}
        with self.assertRaisesRegex(ValueError, "one owner twice"):
            render_filtered_wrapper(include_lines[0x10] + "\n", include_lines, [0x10, 0x10])

    def test_filtered_wrapper_rejects_synthetic_code(self) -> None:
        include_lines = {0x10: '#include "matching/10.cpp"'}
        source = include_lines[0x10] + "\nstatic void dummy() {}\n"
        with self.assertRaisesRegex(ValueError, "synthetic context"):
            render_filtered_wrapper(source, include_lines, [0x10])


if __name__ == "__main__":
    unittest.main()
