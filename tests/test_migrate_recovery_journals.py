from __future__ import annotations

import importlib.util
import sys
import unittest
from pathlib import Path


TOOLS_DIR = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

SPEC = importlib.util.spec_from_file_location(
    "migrate_recovery_journals", TOOLS_DIR / "migrate_recovery_journals.py"
)
assert SPEC is not None and SPEC.loader is not None
migration = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = migration
SPEC.loader.exec_module(migration)


class RecoveryJournalMigrationTests(unittest.TestCase):
    def test_parse_removed_comment_blocks_keeps_only_comment_runs(self) -> None:
        patch = """diff --git a/src/sample.cpp b/src/sample.cpp
--- a/src/sample.cpp
+++ b/src/sample.cpp
@@ -10,5 +10,1 @@
-// Attempt: changed the loop.
-// Result: 4 differing bytes.
-
-int value = 1;
-// unrelated after code
+int value = 1;
"""
        blocks = migration.parse_removed_comment_blocks(patch, "deadbeef")
        self.assertEqual(len(blocks), 2)
        self.assertEqual(blocks[0].old_start, 10)
        self.assertIn("4 differing bytes", blocks[0].text)
        self.assertEqual(blocks[1].old_start, 14)

    def test_function_definition_parser_handles_qualified_overloads(self) -> None:
        source = """
class Thing {};
int Thing::work(int value)
{
    if (value) { return 1; }
    return 0;
}

float Thing::work(float value) const {
    return value;
}

static int helper(int value) {
    return value + 1;
}
"""
        definitions = migration.parse_function_definitions(source)
        self.assertEqual([name for name, _line in definitions], ["work", "work", "helper"])

    def test_render_journal_is_idempotent(self) -> None:
        row = {
            "va": "00400000",
            "name": "sample",
            "slug": "00400000_sample",
            "source_bucket": "scratch",
            "source_path": "src/sample.cpp",
            "pdb_source_path": "C:\\sample.cpp",
            "pdb_source_file": "sample.cpp",
            "recovery_note_path": "",
            "logic_review_path": "",
        }
        block = migration.RemovedBlock(
            commit="deadbeef",
            path="src/sample.cpp",
            old_start=20,
            old_end=21,
            lines=("// Attempt: changed the loop.", "// Result: mismatch."),
        )
        assignment = migration.BlockAssignment(
            va="00400000",
            confidence="strong",
            reason="test mapping",
            block=block,
        )
        first = migration.render_journal(row, [assignment])
        second = migration.render_journal(row, [assignment], first)
        self.assertEqual(first, second)
        self.assertEqual(first.count(f"recovered:{block.stable_id}"), 2)

    def test_attempt_score_rejects_plain_file_labels(self) -> None:
        plain = migration.RemovedBlock(
            commit="deadbeef",
            path="src/sample.cpp",
            old_start=1,
            old_end=1,
            lines=("// C:\\sample.cpp",),
        )
        useful = migration.RemovedBlock(
            commit="deadbeef",
            path="src/sample.cpp",
            old_start=2,
            old_end=2,
            lines=("// Probe changed the frame and reduced mismatch bytes.",),
        )
        self.assertEqual(plain.attempt_score, 0)
        self.assertGreater(useful.attempt_score, 0)

    def test_recovered_text_removes_trailing_whitespace(self) -> None:
        block = migration.RemovedBlock(
            commit="deadbeef",
            path="src/sample.cpp",
            old_start=1,
            old_end=2,
            lines=("// Attempt: changed the loop. ", "// Result: mismatch.\t"),
        )
        self.assertEqual(
            block.text,
            "// Attempt: changed the loop.\n// Result: mismatch.",
        )

    def test_declared_owner_va_beats_nearby_function_mapping(self) -> None:
        block = migration.RemovedBlock(
            commit="deadbeef",
            path="src/module.cpp",
            old_start=10,
            old_end=11,
            lines=(
                "// PDB source owner: 00401230_target.cpp",
                "// 00401230 Owner::target",
            ),
        )
        self.assertEqual(migration.declared_owner_vas(block), {"00401230"})


if __name__ == "__main__":
    unittest.main()
