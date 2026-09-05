from pathlib import Path
import unittest


ROOT = Path(__file__).resolve().parents[1]


class ExperimentWorkflowTests(unittest.TestCase):
    def text(self, path):
        return (ROOT / path).read_text(encoding="utf-8")

    def test_worker_workflow_is_universal_and_records_before_build(self):
        worker = self.text("agent_roles/matching_worker.md")
        self.assertIn("Every matching assignment must follow `docs/experiments.md`", worker)
        self.assertNotIn("For branch-based assignments", worker)
        self.assertIn("Record each distinct tested input state before compilation", worker)
        self.assertIn("Every handoff must include the four-part report", worker)

    def test_all_review_levels_require_four_part_report(self):
        for role in ("matching_worker", "orchestrator", "root_orchestrator"):
            text = self.text(f"agent_roles/{role}.md")
            for heading in ("Behavior", "Source", "Bytes", "Integration"):
                self.assertIn(heading, text, role)
            self.assertIn("docs/experiments.md", text, role)

    def test_review_separates_integration_from_preservation(self):
        workflow = self.text("docs/experiments.md")
        for required in (
            "Review Behavior and Source before Bytes",
            "Record separate decisions for source integration and experiment preservation",
            "Use this report even when no source change remains",
            "Verify their hashes, parent references, and reachable base commits",
            "Do not bypass a capture refusal",
        ):
            self.assertIn(required, workflow)


if __name__ == "__main__":
    unittest.main()
