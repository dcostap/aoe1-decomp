import sys
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from audit_matching_owners import audit_status, build_report, owner_mismatch_kind  # noqa: E402
from function_diagnostics import owning_function_symbol_validation  # noqa: E402


class MatchingOwnerAuditTests(unittest.TestCase):
    def test_owner_mismatch_blocks_exact_status(self) -> None:
        self.assertEqual(
            audit_status(
                metadata_state="fresh",
                diff_state="fresh",
                owner_status="mismatch",
                pdb_owner="Owner::work",
                checker_status="MATCH",
            ),
            "OWNER_MISMATCH",
        )

    def test_stale_owner_mismatch_is_not_a_match(self) -> None:
        self.assertEqual(
            audit_status(
                metadata_state="stale",
                diff_state="stale",
                owner_status="mismatch",
                pdb_owner="Owner::work",
                checker_status="MATCH",
            ),
            "OWNER_MISMATCH_STALE",
        )

    def test_missing_pdb_owner_blocks_exact_status(self) -> None:
        self.assertEqual(
            audit_status(
                metadata_state="fresh",
                diff_state="fresh",
                owner_status="match",
                pdb_owner="",
                checker_status="MATCH",
            ),
            "PDB_OWNER_MISSING",
        )

    def test_mismatch_kind_prioritizes_free_function_owner(self) -> None:
        self.assertEqual(
            owner_mismatch_kind(
                {"expected_owner": "Owner", "rebuilt_owner": ""}
            ),
            "free_function_owner",
        )
        self.assertEqual(
            owner_mismatch_kind(
                {"expected_owner": "Owner", "rebuilt_owner": "Other"}
            ),
            "class_owner",
        )

    def test_pdb_class_and_rebuilt_free_function_are_a_free_owner_mismatch(self) -> None:
        validation = owning_function_symbol_validation(
            "importantUnit",
            "?importantUnit@@YGHH@Z",
            "TribeInformationAIModule::importantUnit",
        )
        self.assertEqual(validation["status"], "mismatch")
        self.assertEqual(owner_mismatch_kind(validation), "free_function_owner")

    def test_vc5_template_owner_matches_pdb_spelling(self) -> None:
        validation = owning_function_symbol_validation(
            "remove",
            "?remove@?$ManagedArray@H@@QAEHH@Z",
            "ManagedArray<int>::remove",
        )
        self.assertEqual(validation["status"], "match")

    def test_report_is_sorted_and_counts_verified_exact_claims(self) -> None:
        rows = [
            {
                "va": "00400020",
                "status": "OWNER_MISMATCH",
                "owner_status": "mismatch",
                "owner_mismatch_kind": "class_owner",
                "repair_priority": 0,
                "repair_reason": "repair class/free-function owner first",
                "pdb_qualified_owner": "Owner::work",
                "rebuilt_decorated_symbol": "?work@Other@@...",
                "source": "src/matching/00400020_work.cpp",
                "grouped_tu": "",
                "name": "work",
                "bank": "matching",
                "corpus_bucket": "normal",
                "owner_expected_name": "work",
                "owner_expected_class": "Owner",
                "owner_rebuilt_class": "Other",
                "metadata_state": "fresh",
                "checker_status": "MATCH",
                "diff_state": "fresh",
                "metadata_path": "",
                "diff_path": "",
                "manifest_path": "",
                "object_path": "",
                "pdb_qualified_owner": "Owner::work",
            },
            {
                "va": "00400010",
                "status": "MATCH",
                "owner_status": "match",
                "owner_mismatch_kind": "",
                "repair_priority": 99,
                "repair_reason": "",
                "pdb_qualified_owner": "Owner::work",
                "rebuilt_decorated_symbol": "?work@Owner@@...",
                "source": "src/matching/00400010_work.cpp",
                "grouped_tu": "",
                "name": "work",
                "bank": "matching",
                "corpus_bucket": "normal",
                "owner_expected_name": "work",
                "owner_expected_class": "Owner",
                "owner_rebuilt_class": "Owner",
                "metadata_state": "fresh",
                "checker_status": "MATCH",
                "diff_state": "fresh",
                "metadata_path": "",
                "diff_path": "",
                "manifest_path": "",
                "object_path": "",
            },
        ]
        report = build_report(rows)
        self.assertEqual([row["va"] for row in report["rows"]], ["00400010", "00400020"])
        self.assertEqual(report["summary"]["exact_claim_count"], 1)
        self.assertEqual(report["summary"]["class_or_free_owner_mismatch_count"], 1)


if __name__ == "__main__":
    unittest.main()
