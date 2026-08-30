from __future__ import annotations

import re
import subprocess
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
RETIRED_TEXT = (
    "config/source_modules/",
    "config/translation_units.json",
    "docs/main_agent_workflow.md",
    "audit_translation_unit_observed.py",
    "plan_translation_unit.py",
    "translation_unit_prefixes.py",
)
PATH_REFERENCE_RE = re.compile(r"(?:config/flags|tools)/[A-Za-z0-9_./-]+\.(?:rsp|py)")
RSP_REFERENCE_RE = re.compile(r"[A-Za-z0-9_./-]+\.rsp")
FUNCTION_STATUS_RE = re.compile(r"^.{0,20}(?:current )?status\s*:", re.IGNORECASE | re.MULTILINE)


def present_markdown_files() -> list[Path]:
    result = subprocess.run(
        [
            "git",
            "-C",
            str(REPO_ROOT),
            "ls-files",
            "--cached",
            "--others",
            "--exclude-standard",
            "*.md",
        ],
        check=True,
        capture_output=True,
        text=True,
    )
    paths = [REPO_ROOT / line for line in result.stdout.splitlines() if line]
    return [path for path in paths if path.is_file()]


class DocumentationTests(unittest.TestCase):
    def test_workflows_define_continuous_translation_unit_review(self) -> None:
        orchestrator = (REPO_ROOT / "docs" / "orchestrator_workflow.md").read_text(
            encoding="utf-8"
        )
        worker = (REPO_ROOT / "docs" / "agentic_matching_workflow.md").read_text(
            encoding="utf-8"
        )
        orchestrator = " ".join(orchestrator.split())
        worker = " ".join(worker.split())
        for required in (
            "one worker to one natural translation unit",
            "first unchecked item",
            "TODO verification item",
            "managed subagent list",
            "compiler_gate.py close",
            "compiler_gate.py open",
        ):
            self.assertIn(required, orchestrator)
        for required in (
            "one assigned natural translation unit",
            "scratch function bodies",
            "target_session.py start",
            "Send no intermediate progress reports",
            "Do not use a report tool",
        ):
            self.assertIn(required, worker)
        self.assertNotIn("wave", orchestrator.casefold())

    def test_markdown_has_no_assignment_lease_language(self) -> None:
        pattern = re.compile(r"\b(?:lease|leases|leased|unleased)\b", re.IGNORECASE)
        failures = [
            path.relative_to(REPO_ROOT).as_posix()
            for path in present_markdown_files()
            if pattern.search(path.read_text(encoding="utf-8", errors="replace"))
        ]
        self.assertEqual(failures, [])

    def test_orchestrator_is_the_only_orchestration_role_name(self) -> None:
        result = subprocess.run(
            [
                "git",
                "-C",
                str(REPO_ROOT),
                "grep",
                "-n",
                "-I",
                "-i",
                "-e",
                "main-agent",
                "-e",
                "main_agent",
                "-e",
                "main agent",
                "-e",
                "coordinator",
                "--",
                ".",
                ":!orig/**",
                ":!tests/test_documentation.py",
            ],
            capture_output=True,
            text=True,
        )
        self.assertIn(result.returncode, {0, 1})
        self.assertEqual(result.stdout, "")
        self.assertFalse((REPO_ROOT / "docs" / "main_agent_workflow.md").exists())
        self.assertTrue((REPO_ROOT / "docs" / "orchestrator_workflow.md").is_file())

    def test_markdown_uses_current_paths(self) -> None:
        failures: list[str] = []
        for path in present_markdown_files():
            text = path.read_text(encoding="utf-8", errors="replace")
            relative = path.relative_to(REPO_ROOT).as_posix()
            for retired in RETIRED_TEXT:
                if retired in text:
                    failures.append(f"{relative}: retired reference {retired}")
            for reference in PATH_REFERENCE_RE.findall(text):
                if not (REPO_ROOT / reference).is_file():
                    failures.append(f"{relative}: missing path {reference}")
            for reference in RSP_REFERENCE_RE.findall(text):
                full_path = REPO_ROOT / reference
                profile_path = REPO_ROOT / "config" / "flags" / reference
                if not full_path.is_file() and not profile_path.is_file():
                    failures.append(f"{relative}: missing response file {reference}")
        self.assertEqual(failures, [])

    def test_function_notes_do_not_store_status(self) -> None:
        failures: list[str] = []
        notes = REPO_ROOT / "decomp_notes" / "functions"
        for path in notes.glob("*/*.md"):
            text = path.read_text(encoding="utf-8", errors="replace")
            if FUNCTION_STATUS_RE.search(text):
                failures.append(path.relative_to(REPO_ROOT).as_posix())
        self.assertEqual(failures, [])

    def test_logic_review_paths_use_only_the_va(self) -> None:
        reviews = REPO_ROOT / "logic_reviews"
        invalid = [
            path.relative_to(REPO_ROOT).as_posix()
            for path in reviews.glob("*.md")
            if re.fullmatch(r"[0-9A-F]{8}\.md", path.name) is None
        ]
        self.assertEqual(invalid, [])

    def test_build_has_no_present_markdown(self) -> None:
        present = [
            path.relative_to(REPO_ROOT).as_posix()
            for path in present_markdown_files()
            if path.is_relative_to(REPO_ROOT / "build")
        ]
        self.assertEqual(present, [])

        result = subprocess.run(
            ["git", "-C", str(REPO_ROOT), "ls-files", "-v", "build/*.md"],
            check=True,
            capture_output=True,
            text=True,
        )
        sparse = [line for line in result.stdout.splitlines() if line.startswith("S ")]
        self.assertEqual(sparse, [])


if __name__ == "__main__":
    unittest.main()
