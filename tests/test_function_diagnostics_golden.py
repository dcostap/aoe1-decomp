from __future__ import annotations

import json
import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from common import byte_diff_metrics  # noqa: E402
from function_diagnostics import (  # noqa: E402
    basic_blocks,
    block_alignment,
    call_alignment,
    call_fingerprint,
    decode_instruction_ranges,
    decode_instructions,
    instruction_alignment,
)


class FunctionDiagnosticsGoldenTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        fixture_path = REPO_ROOT / "tests" / "fixtures" / "function_diagnostics_golden.json"
        cls.fixtures = json.loads(fixture_path.read_text(encoding="utf-8"))

    def test_golden_diagnostic_pipeline(self) -> None:
        for fixture in self.fixtures:
            with self.subTest(fixture=fixture["name"]):
                start_va = int(fixture["start_va"], 16)
                original_bytes = bytes.fromhex(fixture["original_hex"])
                rebuilt_bytes = bytes.fromhex(fixture["rebuilt_hex"])
                if fixture.get("original_ranges"):
                    original_instructions = decode_instruction_ranges(
                        original_bytes, fixture["original_ranges"]
                    )
                else:
                    original_instructions = decode_instructions(original_bytes, start_va)
                rebuilt_instructions = decode_instructions(rebuilt_bytes, start_va)

                original_calls = call_fingerprint(original_instructions, original=True, names_by_va={})
                rebuilt_calls = call_fingerprint(rebuilt_instructions, original=False, names_by_va={})
                calls = call_alignment(original_calls, rebuilt_calls)
                blocks = block_alignment(
                    basic_blocks(original_instructions, original_calls),
                    basic_blocks(rebuilt_instructions, rebuilt_calls),
                )
                shape = instruction_alignment(original_instructions, rebuilt_instructions)
                byte_metrics = byte_diff_metrics(original_bytes, rebuilt_bytes)
                expected = fixture["expected"]

                self.assertEqual(byte_metrics["diff_bytes"], expected["positional_diff_bytes"])
                if "instruction_shape_percent" in expected:
                    self.assertAlmostEqual(
                        shape["similarity_percent"], expected["instruction_shape_percent"], places=6
                    )
                self.assertAlmostEqual(
                    calls["similarity_percent"], expected["call_similarity_percent"], places=6
                )
                self.assertEqual(calls["aligned_prefix_calls"], expected["call_prefix"])
                self.assertAlmostEqual(
                    blocks["matched_coverage_percent"], expected["block_coverage_percent"], places=6
                )
                first_index = calls["first_difference_row"]
                expected_status = expected["first_call_status"]
                if expected_status is None:
                    self.assertIsNone(first_index)
                else:
                    self.assertIsNotNone(first_index)
                    first = calls["rows"][int(first_index)]
                    self.assertEqual(first["status"], expected_status)
                    if "first_call_confidence" in expected:
                        self.assertEqual(first["confidence"], expected["first_call_confidence"])
                    left = first.get("original") or {}
                    right = first.get("rebuilt") or {}
                    self.assertEqual(left.get("target"), expected.get("original_call_target"))
                    self.assertEqual(right.get("target"), expected.get("rebuilt_call_target"))
                if "original_addresses" in expected:
                    self.assertEqual(
                        [instruction.address for instruction in original_instructions],
                        expected["original_addresses"],
                    )


if __name__ == "__main__":
    unittest.main()
