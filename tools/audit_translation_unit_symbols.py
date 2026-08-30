from __future__ import annotations

import argparse
import json
from pathlib import Path

from coff import load_coff_object
from common import load_build_modules, repo_path
from extract_obj_function import select_exact_function_symbol
from original_fpo import (
    DEFAULT_FPO_PATH,
    DEFAULT_OWNER_OVERRIDES_PATH,
    load_original_owner_symbols,
)


def _select_symbol(obj, va: int, module: dict[str, object]):
    functions = module["functions"]
    assert isinstance(functions, dict)
    entry = functions[f"{va:08X}"]
    assert isinstance(entry, dict)
    return select_exact_function_symbol(obj, str(entry["symbol"]))


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Compare grouped COFF owner symbols with original FPO symbols."
    )
    parser.add_argument("--objects-dir", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--fpo", default=str(DEFAULT_FPO_PATH))
    parser.add_argument(
        "--owner-overrides", default=str(DEFAULT_OWNER_OVERRIDES_PATH)
    )
    parser.add_argument(
        "--allow-unavailable", action="store_true",
        help="Do not fail when an owner has no FPO record.",
    )
    return parser.parse_args()


def audit_symbols(
    groups: list[dict[str, object]], object_dir: Path, fpo_path: Path,
    owner_overrides_path: Path | None = None,
) -> dict[str, object]:
    original, original_linkages = load_original_owner_symbols(
        fpo_path, owner_overrides_path
    )
    rows: list[dict[str, str]] = []
    unavailable: list[dict[str, str]] = []
    for group in groups:
        name = str(group["name"])
        obj = load_coff_object(object_dir / f"{name}.obj")
        functions = group.get("functions")
        assert isinstance(functions, dict)
        for raw_va, entry in functions.items():
            if not isinstance(entry, dict) or entry.get("status") != "matching":
                continue
            va = str(raw_va).upper()
            expected = original.get(va)
            if expected is None:
                unavailable.append({"group": name, "va": va})
                continue
            try:
                rebuilt_symbol = _select_symbol(obj, int(va, 16), group)
                rebuilt = rebuilt_symbol.name
                if rebuilt_symbol.storage_class == 2:
                    rebuilt_linkage = "global"
                elif rebuilt_symbol.storage_class == 3:
                    rebuilt_linkage = "local"
                else:
                    rebuilt_linkage = f"coff:{rebuilt_symbol.storage_class}"
                error = ""
            except Exception as exception:
                rebuilt = ""
                rebuilt_linkage = ""
                error = str(exception)
            expected_linkage = original_linkages.get(va, "")
            if rebuilt != expected or (
                expected_linkage and rebuilt_linkage != expected_linkage
            ):
                row = {
                    "group": name,
                    "va": va,
                    "expected": expected,
                    "rebuilt": rebuilt,
                }
                if expected_linkage:
                    row["expected_linkage"] = expected_linkage
                    row["rebuilt_linkage"] = rebuilt_linkage
                if error:
                    row["error"] = error
                rows.append(row)
    owner_count = sum(
        1
        for group in groups
        for entry in (group.get("functions") or {}).values()
        if isinstance(entry, dict) and entry.get("status") == "matching"
    )
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
        load_build_modules(),
        repo_path(args.objects_dir),
        repo_path(args.fpo),
        repo_path(args.owner_overrides),
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
