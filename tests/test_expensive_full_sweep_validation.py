from __future__ import annotations

import subprocess
import sys
import threading
import time
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from expensive_full_sweep_validation import interleaved_indices, run_checks  # noqa: E402


class ExpensiveFullSweepValidationTests(unittest.TestCase):
    def test_parallel_checks_preserve_input_order_and_results(self) -> None:
        active = 0
        maximum_active = 0
        lock = threading.Lock()

        def checker(va: str) -> subprocess.CompletedProcess[str]:
            nonlocal active, maximum_active
            with lock:
                active += 1
                maximum_active = max(maximum_active, active)
            time.sleep(0.02)
            with lock:
                active -= 1
            return subprocess.CompletedProcess(["check", va], int(va[-1], 16) % 2, va, "")

        vas = ["00400000", "00400001", "00400002", "00400003"]
        serial = run_checks(vas, 1, checker=checker)
        parallel = run_checks(vas, 4, checker=checker)

        self.assertEqual(
            [(result.returncode, result.stdout) for result in serial],
            [(result.returncode, result.stdout) for result in parallel],
        )
        self.assertGreater(maximum_active, 1)

    def test_jobs_must_be_positive(self) -> None:
        with self.assertRaisesRegex(ValueError, "at least 1"):
            run_checks(["00400000"], 0)

    def test_parallel_checks_interleave_artifacts_but_restore_result_order(self) -> None:
        self.assertEqual(
            [0, 2, 4, 1, 3],
            interleaved_indices(["A", "A", "B", "B", "C"]),
        )

        def checker(va: str) -> subprocess.CompletedProcess[str]:
            return subprocess.CompletedProcess(["check", va], 0, va, "")

        vas = ["A1", "A2", "B1", "B2", "C1"]
        results = run_checks(
            vas,
            2,
            checker=checker,
            schedule_keys=["A", "A", "B", "B", "C"],
        )
        self.assertEqual(vas, [result.stdout for result in results])

    def test_schedule_key_count_must_match(self) -> None:
        with self.assertRaisesRegex(ValueError, "match the VA count"):
            run_checks(["00400000"], 2, schedule_keys=[])


if __name__ == "__main__":
    unittest.main()
