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
        for role in ("matching_worker", "matching_reviewer", "orchestrator", "root_orchestrator"):
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
            "Read each state's input diff before accepting its behavior or source findings",
        ):
            self.assertIn(required, workflow)

    def test_reviewer_variation_is_opt_in_and_discoverable(self):
        self.assertIn("agent_roles", self.text("AGENTS.md"))
        for path in (
            "README.md", "docs/project_reference.md",
            "docs/experiments.md", "agent_roles/matching_worker.md",
            "agent_roles/orchestrator.md", "agent_roles/root_orchestrator.md",
        ):
            text = self.text(path)
            self.assertIn("existing matching workflow remains the default", text, path)
            self.assertIn("Workflow: matching with reviewers", text, path)
            self.assertIn("docs/matching_with_reviewers.md", text, path)

    def test_reviewer_variation_routes_without_duplicate_review(self):
        text = self.text("docs/matching_with_reviewers.md")
        for required in (
            "exact provider/model IDs and thinking levels",
            "Count active reviewers in the agreed capacity",
            "Only one matching worker or reviewer may operate in that slot at a time",
            "The worker selects useful recovery questions",
            "subagent_send",
            "APPROVE", "NEEDS_CORRECTION", "BLOCKED",
            "does not require the orchestrator to repeat instruction-by-instruction analysis",
            "A merge conflict or changed input can invalidate review approval",
        ):
            self.assertIn(required, text)

    def test_reviewer_has_independent_bounded_authority(self):
        text = self.text("agent_roles/matching_reviewer.md")
        for required in (
            "Use a fresh session for the first review",
            "Do not edit game source, headers, flags, registry entries, or test implementations",
            "Do not stage or commit",
            "Read actual frozen input diffs",
            "complete independent semantic proof",
            "experiment_history.py note --artifact",
            "Approval applies only to the identified inputs and scope",
        ):
            self.assertIn(required, text)


if __name__ == "__main__":
    unittest.main()
