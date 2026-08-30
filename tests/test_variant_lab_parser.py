from __future__ import annotations

import io
import subprocess
import sys
import tempfile
import unittest
from contextlib import redirect_stdout
from pathlib import Path
from unittest.mock import patch

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import variant_lab  # noqa: E402


class VariantLabParserTests(unittest.TestCase):
    def test_compile_jobs_default_to_one(self) -> None:
        args = variant_lab.parse_args(["--va", "00400000", "--template", "demo.cpp"])
        self.assertEqual(args.jobs, 1)
        self.assertEqual(args.max_variants, 1024)

        args = variant_lab.parse_args(
            ["--va", "00400000", "--template", "demo.cpp", "--jobs", "3"]
        )
        self.assertEqual(args.jobs, 3)

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

    def test_ambient_declarations_generate_deterministic_cumulative_samples(self) -> None:
        text = "before\n@ambient_declarations ambient samples=4 seed=demo\nafter\n"
        plan = variant_lab.parse_template(text)
        specs = variant_lab.make_specs(plan)

        self.assertEqual([axis.name for axis in plan.axes], ["ambient"])
        self.assertEqual(
            [variant_lab.label_text(spec, plan.axes) for spec in specs],
            [
                "src.ambient=n0000",
                "src.ambient=n0001",
                "src.ambient=n0002",
                "src.ambient=n0003",
            ],
        )
        baseline = variant_lab.expand_source(plan, specs[0])
        first = variant_lab.expand_source(plan, specs[1])
        third = variant_lab.expand_source(plan, specs[3])
        self.assertNotIn("struct codegen_ambient_ambient_", baseline)
        self.assertEqual(first.count("struct codegen_ambient_ambient_"), 1)
        self.assertEqual(third.count("struct codegen_ambient_ambient_"), 3)
        self.assertEqual(len(baseline.splitlines()), len(first.splitlines()))
        self.assertEqual(len(first.splitlines()), len(third.splitlines()))
        first_declaration = next(line for line in first.splitlines() if line.startswith("struct "))
        self.assertIn(first_declaration, third)

        repeated = variant_lab.parse_template(text)
        self.assertEqual(
            variant_lab.expand_source(repeated, variant_lab.make_specs(repeated)[3]),
            third,
        )

    def test_ambient_declarations_validate_arguments(self) -> None:
        with self.assertRaisesRegex(ValueError, "must be positive"):
            variant_lab.parse_template("@ambient_declarations ctx samples=0\n")
        with self.assertRaisesRegex(ValueError, "unknown.*argument"):
            variant_lab.parse_template("@ambient_declarations ctx samples=2 mode=random\n")

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

    def test_localized_splice_retains_markers_and_replaces_body(self) -> None:
        base = "before\n// REGION START\nold body\n// REGION END\nafter\n"
        fragment = "@choice body\n@case a\nnew a\n@case b\nnew b\n@endchoice\n"
        combined = variant_lab.splice_template(base, fragment, "REGION START", "REGION END")
        self.assertNotIn("old body", combined)
        self.assertIn("// REGION START\n@choice body", combined)
        self.assertIn("@endchoice\n// REGION END", combined)
        plan = variant_lab.parse_template(combined)
        self.assertEqual(len(variant_lab.make_specs(plan)), 2)

    def test_localized_splice_rejects_ambiguous_marker(self) -> None:
        with self.assertRaisesRegex(ValueError, "exactly one"):
            variant_lab.splice_template("// X\n// X\n// Y\n", "body\n", "X", "Y")

    def test_focus_range_accepts_offsets_and_real_vas(self) -> None:
        self.assertEqual(variant_lab.parse_focus_range("+0010-+001F", 0x401000, 0x100), (0x10, 0x20))
        self.assertEqual(variant_lab.parse_focus_range("00401010-0040101F", 0x401000, 0x100), (0x10, 0x20))
        with self.assertRaisesRegex(ValueError, "inside"):
            variant_lab.parse_focus_range("+00F0-+0100", 0x401000, 0x100)

    def test_invariant_evaluation_reports_size_frame_and_call_set(self) -> None:
        constraints = variant_lab.LabConstraints(
            require_size=True,
            require_frame=True,
            require_call_set=True,
            original_frame_size=8,
            original_call_counts={("direct", "a"): 1},
        )
        failures = variant_lab.evaluate_constraints(
            constraints=constraints,
            text_size=12,
            expected_size=10,
            frame_size=4,
            call_counts={("direct", "b"): 1},
        )
        self.assertEqual(len(failures), 3)
        self.assertIn("size", failures[0])

    def test_effective_extent_ignores_unreachable_context_tail(self) -> None:
        extent = variant_lab.variant_code_extent(b"\xC3\x55\x8B\xEC\xC3", 1)
        self.assertEqual(extent["meaningful_size"], 5)
        self.assertEqual(extent["effective_size"], 1)
        self.assertFalse(extent["has_code_overflow"])

    def test_effective_extent_keeps_entry_reachable_overflow(self) -> None:
        # jmp +0 crosses the two-byte inventory boundary and reaches the ret.
        extent = variant_lab.variant_code_extent(b"\xEB\x00\xC3", 2)
        self.assertEqual(extent["effective_size"], 3)
        self.assertTrue(extent["has_code_overflow"])

    def test_effective_extent_keeps_indirect_target_overflow(self) -> None:
        extent = variant_lab.variant_code_extent(
            b"\xC3\x55\x8B\xEC\xC3", 1, indirect_targets=[3]
        )
        self.assertEqual(extent["effective_size"], 5)
        self.assertTrue(extent["has_code_overflow"])

    def test_group_symbol_normalization_keeps_external_identity(self) -> None:
        self.assertEqual(variant_lab.normalize_relocation_symbol_for_group("$L395"), "$L#")
        self.assertEqual(
            variant_lab.normalize_relocation_symbol_for_group("_value$S351"),
            "_value$S#",
        )
        self.assertEqual(
            variant_lab.normalize_relocation_symbol_for_group("?external@@YAXXZ"),
            "?external@@YAXXZ",
        )

    def test_variant_preview_is_compact_unless_full_is_requested(self) -> None:
        plan = variant_lab.parse_template(
            "before\n@choice x\n@case a\nA\n@case b\nB\n@endchoice\nafter\n"
        )
        specs = variant_lab.make_specs(plan)
        compact = io.StringIO()
        with redirect_stdout(compact):
            variant_lab.print_variant_preview_with_mode(
                plan, specs, specs, full_source=False
            )
        compact_text = compact.getvalue()
        self.assertIn("src.x=a", compact_text)
        self.assertIn("source=", compact_text)
        self.assertNotIn("before\nA\nafter", compact_text)

        full = io.StringIO()
        with redirect_stdout(full):
            variant_lab.print_variant_preview_with_mode(
                plan, specs, specs[:1], full_source=True
            )
        self.assertIn("before\nA\nafter", full.getvalue())

    def test_compile_timeout_becomes_a_bounded_tool_error(self) -> None:
        plan = variant_lab.parse_template("void f() {}\n")
        spec = variant_lab.make_specs(plan)[0]
        with tempfile.TemporaryDirectory() as temporary, patch.object(
            variant_lab, "tool_env", return_value={}
        ), patch.object(
            variant_lab.subprocess,
            "run",
            side_effect=subprocess.TimeoutExpired(["cl"], 0.01),
        ):
            root = Path(temporary)
            result = variant_lab.build_variant(
                spec,
                plan,
                plan.axes,
                root,
                root / "work",
                Path("cl"),
                Path("default.rsp"),
                {},
                b"\xC3",
                1,
                0x401000,
                "00401000_f",
                variant_lab.LabConstraints(),
                0.01,
            )
        self.assertEqual(result.status, "tool_error")
        self.assertIn("compiler timeout", result.error_text)


if __name__ == "__main__":
    unittest.main()
