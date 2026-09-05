from __future__ import annotations

import sys
import unittest
import tempfile
from pathlib import Path
from unittest.mock import patch


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import check_line_endings  # noqa: E402


class LineEndingTests(unittest.TestCase):
    def test_mixed_endings_are_rejected(self) -> None:
        issue = check_line_endings.line_ending_issue(b"one\r\ntwo\n", "lf")
        self.assertEqual(issue, "mixed line endings")

    def test_repository_line_endings_follow_policy(self) -> None:
        self.assertEqual(check_line_endings.check_repository(REPO_ROOT), [])

    def test_binary_attribute_does_not_relax_source_policy(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as directory:
            root = Path(directory)
            archive, source = root / "archive", root / "source.cpp"
            archive.write_bytes(b"saved\r\nbytes\n")
            source.write_bytes(b"source\r\n")
            attributes = {"archive": {"text": "unset"}, "source.cpp": {"text": "auto", "eol": "lf"}}
            with patch.object(check_line_endings, "repository_paths", return_value=[archive, source]), patch.object(
                check_line_endings, "path_attributes", return_value=attributes
            ):
                self.assertEqual(check_line_endings.check_repository(root), ["source.cpp: expected LF line endings"])


if __name__ == "__main__":
    unittest.main()
