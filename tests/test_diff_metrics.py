from __future__ import annotations

import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from common import byte_diff_metrics  # noqa: E402


class DiffMetricsTests(unittest.TestCase):
    def test_exact_match_zeroes_both_metrics(self) -> None:
        metrics = byte_diff_metrics(bytes.fromhex("AA BB CC"), bytes.fromhex("AA BB CC"))
        self.assertEqual(metrics["result"], "MATCH")
        self.assertEqual(metrics["diff_bytes"], 0)
        self.assertEqual(metrics["edit_diff_bytes"], 0)
        self.assertFalse(metrics["likely_shifted_alignment"])

    def test_single_replace(self) -> None:
        metrics = byte_diff_metrics(bytes.fromhex("AA BB CC"), bytes.fromhex("AA 90 CC"))
        self.assertEqual(metrics["result"], "MISMATCH")
        self.assertEqual(metrics["diff_bytes"], 1)
        self.assertEqual(metrics["edit_diff_bytes"], 1)
        self.assertEqual(metrics["edit_replace_bytes"], 1)
        self.assertFalse(metrics["likely_shifted_alignment"])

    def test_single_insert_resynchronizes(self) -> None:
        metrics = byte_diff_metrics(bytes.fromhex("AA BB CC DD EE"), bytes.fromhex("AA 90 BB CC DD EE"))
        self.assertEqual(metrics["result"], "MISMATCH")
        self.assertEqual(metrics["diff_bytes"], 5)
        self.assertEqual(metrics["edit_diff_bytes"], 1)
        self.assertEqual(metrics["edit_insert_bytes"], 1)
        self.assertTrue(metrics["likely_shifted_alignment"])

    def test_single_delete_resynchronizes(self) -> None:
        metrics = byte_diff_metrics(bytes.fromhex("AA 90 BB CC DD EE"), bytes.fromhex("AA BB CC DD EE"))
        self.assertEqual(metrics["result"], "MISMATCH")
        self.assertEqual(metrics["diff_bytes"], 5)
        self.assertEqual(metrics["edit_diff_bytes"], 1)
        self.assertEqual(metrics["edit_delete_bytes"], 1)
        self.assertTrue(metrics["likely_shifted_alignment"])


if __name__ == "__main__":
    unittest.main()
