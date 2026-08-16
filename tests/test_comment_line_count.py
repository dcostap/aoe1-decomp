from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from status_core import count_comment_lines_text, sort_status_rows  # noqa: E402


class CommentLineCountTests(unittest.TestCase):
    def test_counts_line_and_block_comments(self) -> None:
        source = """// header
int a; /* inline block */
/* first block line
 * second block line
 */ int b;
const char* url = \"https://example.test//not-a-comment\";
char slash = '/'; // trailing
"""
        self.assertEqual(count_comment_lines_text(source), 6)

    def test_ignores_comment_markers_in_literals(self) -> None:
        source = """const char* line = \"// text\";
const char* block = \"/* text */\";
char quote = '\\'';
"""
        self.assertEqual(count_comment_lines_text(source), 0)

    def test_handles_escapes_and_unterminated_block_comments(self) -> None:
        source = '''const char* quoted = "escaped \\\" // text";
char slash = '\\'';
/* open block
 * still open
'''
        self.assertEqual(count_comment_lines_text(source), 2)

    def test_comment_sort_uses_size_as_the_tie_breaker(self) -> None:
        rows = [
            {"va": "00400020", "source_comment_lines": "2", "size_bytes": "16"},
            {"va": "00400030", "source_comment_lines": "0", "size_bytes": "64"},
            {"va": "00400010", "source_comment_lines": "0", "size_bytes": "32"},
        ]
        self.assertEqual(
            [row["va"] for row in sort_status_rows(rows, sort="comment-lines")],
            ["00400010", "00400030", "00400020"],
        )


if __name__ == "__main__":
    unittest.main()
