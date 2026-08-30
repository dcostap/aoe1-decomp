import json
import sys
import tempfile
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from audit_matching_owners import (  # noqa: E402
    audit_status,
    build_report,
    collect_function_audit_rows,
    owner_mismatch_kind,
)
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
                "repair_reason": "repair class/free-function owner",
                "pdb_qualified_owner": "Owner::work",
                "rebuilt_decorated_symbol": "?work@Other@@...",
                "source": "src/00400020_work.cpp",
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
                "repair_reason": "",
                "pdb_qualified_owner": "Owner::work",
                "rebuilt_decorated_symbol": "?work@Owner@@...",
                "source": "src/00400010_work.cpp",
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

    def test_complete_grouped_report_supplies_fast_owner_evidence(self) -> None:
        report = {
            "summary": {
                "group_count": 1,
                "compiled_group_count": 1,
                "compile_error_count": 0,
            },
            "rows": [
                {
                    "group": "sample",
                    "va": "00400010",
                    "name": "work",
                    "source_path": "src/sample.cpp",
                    "source_bucket": "matching",
                    "matching_groups": ["sample"],
                    "grouped_result": "MATCH",
                    "owner_status": "match",
                    "symbol": "?work@Owner@@QAEXXZ",
                    "expected_symbol": "?work@Owner@@QAEXXZ",
                    "expected_owner_name": "work",
                    "category": "matching_result",
                }
            ],
        }
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary) / "function_audit.json"
            path.write_text(json.dumps(report), encoding="utf-8")
            rows = collect_function_audit_rows(path)
        self.assertEqual(rows[0]["status"], "MATCH")
        self.assertEqual(rows[0]["metadata_state"], "grouped")


if __name__ == "__main__":
    unittest.main()
