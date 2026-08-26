from __future__ import annotations

import argparse
import json
from pathlib import Path

from coff import load_coff_object
from common import load_translation_units, repo_path
from original_fpo import DEFAULT_FPO_PATH, load_original_fpo_symbols
from translation_unit_prefixes import _select_symbol


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Compare grouped COFF owner symbols with original FPO symbols."
    )
    parser.add_argument("--objects-dir", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--fpo", default=str(DEFAULT_FPO_PATH))
    parser.add_argument(
        "--allow-unavailable", action="store_true",
        help="Do not fail when an owner has no FPO record.",
    )
    return parser.parse_args()


def audit_symbols(
    groups: list[dict[str, object]], object_dir: Path, fpo_path: Path
) -> dict[str, object]:
    original = load_original_fpo_symbols(fpo_path)
    rows: list[dict[str, str]] = []
    unavailable: list[dict[str, str]] = []
    for group in groups:
        name = str(group["name"])
        obj = load_coff_object(object_dir / f"{name}.obj")
        owners = group.get("owners")
        assert isinstance(owners, dict)
        for raw_va in owners:
            va = str(raw_va).upper()
            expected = original.get(va)
            if expected is None:
                unavailable.append({"group": name, "va": va})
                continue
            try:
                rebuilt = _select_symbol(obj, int(va, 16), group).name
                error = ""
            except Exception as exception:
                rebuilt = ""
                error = str(exception)
            if rebuilt != expected:
                row = {
                    "group": name,
                    "va": va,
                    "expected": expected,
                    "rebuilt": rebuilt,
                }
                if error:
                    row["error"] = error
                rows.append(row)
    owner_count = sum(len(group.get("owners") or {}) for group in groups)
    return {
        "group_count": len(groups),
        "owner_count": owner_count,
        "match_count": owner_count - len(rows) - len(unavailable),
        "mismatch_count": len(rows),
        "unavailable_count": len(unavailable),
        "mismatches": rows,
        "unavailable": unavailable,
    }


def main() -> int:
    args = parse_args()
    report = audit_symbols(
        load_translation_units(),
        repo_path(args.objects_dir),
        repo_path(args.fpo),
    )
    output = repo_path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: report[key] for key in (
        "group_count", "owner_count", "match_count", "mismatch_count",
        "unavailable_count",
    )}))
    print(f"Wrote {output}")
    unavailable_failure = bool(report["unavailable_count"]) and not args.allow_unavailable
    return 1 if report["mismatch_count"] or unavailable_failure else 0


if __name__ == "__main__":
    raise SystemExit(main())
