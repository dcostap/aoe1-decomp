from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import variant_lab  # noqa: E402


class VariantLabParserTests(unittest.TestCase):
    def test_nested_choice_only_activates_inner_axis_for_selected_parent(self) -> None:
        text = """A
@choice outer
@case a
a0
@choice inner
@case x
x0
@case y
y0
@endchoice
@case b
b0
@endchoice
Z
"""
        plan = variant_lab.parse_template(text)
        specs = variant_lab.make_specs(plan)
        self.assertEqual([axis.name for axis in plan.axes], ["outer", "inner"])
        self.assertEqual(len(specs), 3)
        self.assertEqual(
            [variant_lab.label_text(spec, plan.axes) for spec in specs],
            ["src.outer=a;src.inner=x", "src.outer=a;src.inner=y", "src.outer=b"],
        )
        self.assertEqual(variant_lab.expand_source(plan, specs[2]), "A\nb0\nZ\n")

    def test_reused_axis_stays_linked_inside_nested_choice(self) -> None:
        text = """@choice a
@case x
X1
@case y
Y1
@endchoice
@choice b
@case on
@choice a
@case x
X2
@endchoice
@case off
OFF
@endchoice
"""
        plan = variant_lab.parse_template(text)
        specs = variant_lab.make_specs(plan)
        rendered = [variant_lab.expand_source(plan, spec) for spec in specs]
        self.assertIn("X1\nX2\n", rendered)
        self.assertIn("Y1\n", rendered)  # a=y plus b=on; nested a omits y and emits nothing.
        self.assertEqual(len(specs), 4)

    def test_nested_flag_choice_is_inactive_outside_selected_source_case(self) -> None:
        text = """@choice outer
@case a
A
@flagchoice f
@case none
@case debug
/Zd
@endflagchoice
@case b
B
@endchoice
"""
        plan = variant_lab.parse_template(text)
        specs = variant_lab.make_specs(plan)
        self.assertEqual(len(specs), 3)
        b_spec = specs[2]
        self.assertEqual(variant_lab.label_text(b_spec, plan.axes), "src.outer=b")
        flags = variant_lab.expand_flags(plan, b_spec, variant_lab.preview_fmt_values())
        self.assertEqual(flags, "")

    def test_duplicate_case_label_is_rejected(self) -> None:
        text = """@choice x
@case a
1
@case a
2
@endchoice
"""
        with self.assertRaisesRegex(ValueError, "duplicate @case label"):
            variant_lab.parse_template(text)

    def test_template_expansion_inside_case_is_parseable(self) -> None:
        text = """@choice outer
@case with_template
@template vc5_dummy_member_surface axis=member_ctx class=Path prefix=ctx
@case without_template
@endchoice
"""
        expanded, records = variant_lab.expand_variant_templates(text)
        self.assertEqual([record["name"] for record in records], ["vc5_dummy_member_surface"])
        plan = variant_lab.parse_template(expanded)
        specs = variant_lab.make_specs(plan)
        self.assertEqual(len(specs), 16)  # 15 dummy-surface cases plus one outer-only branch.


if __name__ == "__main__":
    unittest.main()
