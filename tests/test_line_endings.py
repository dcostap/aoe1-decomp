from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import check_line_endings  # noqa: E402


class LineEndingTests(unittest.TestCase):
    def test_mixed_endings_are_rejected(self) -> None:
        issue = check_line_endings.line_ending_issue(b"one\r\ntwo\n", "lf")
        self.assertEqual(issue, "mixed line endings")

    def test_repository_line_endings_follow_policy(self) -> None:
        self.assertEqual(check_line_endings.check_repository(REPO_ROOT), [])


if __name__ == "__main__":
    unittest.main()
