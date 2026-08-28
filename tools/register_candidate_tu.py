from __future__ import annotations

"""Register one validated candidate translation unit."""

import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
import os
import subprocess
import sys
from pathlib import Path

from audit_translation_unit_flags import audit_translation_units, load_original_needs
from common import (
    REPO_ROOT,
    TRANSLATION_UNITS_PATH,
    load_functions,
    load_pdb_function_source_map,
    load_source_modules,
    load_translation_units,
    slugify_name,
)
from validate_candidate_tu import _resolve, load_proposal, validate_proposal
from validate_translation_units import (
    _all_local_includes,
    _owner_include_positions,
    validate_translation_units,
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Register exact owners from one validated candidate translation unit."
    )
    parser.add_argument("--proposal", type=Path, required=True, help="Candidate proposal JSON.")
    parser.add_argument(
        "--name",
        help="Registered group name. The default is the proposal name.",
    )
    parser.add_argument(
        "--apply",
        action="store_true",
        help="Write config/translation_units.json. Without this option, show the plan only.",
    )
    parser.add_argument(
        "--jobs",
        type=int,
        default=4,
        help="Parallel registered owner checks after --apply. The default is 4.",
    )
    return parser.parse_args()


def candidate_group(payload: dict[str, object]) -> dict[str, object]:
    owners = payload["owners"]
    symbols = payload["symbols"]
    assert isinstance(owners, dict)
    assert isinstance(symbols, dict)
    group: dict[str, object] = {
        "name": str(payload["name"]),
        "source": str(payload["source"]).replace("\\", "/"),
        "flags": str(payload["flags"]).replace("\\", "/"),
        "owners": dict(owners),
    }
    owner_symbols = {va: symbol for va, symbol in symbols.items() if va in owners}
    if owner_symbols:
        group["symbols"] = owner_symbols

    source = str(group["source"]).casefold()
    source_modules = [
        module
        for module in load_source_modules()
        if str(module["source"]).replace("\\", "/").casefold() == source
    ]
    if len(source_modules) > 1:
        names = ", ".join(str(module["name"]) for module in source_modules)
        raise ValueError(f"Source {group['source']} belongs to multiple source modules: {names}")
    if source_modules:
        group["module"] = str(source_modules[0]["name"])
    return group


def merge_candidate_group(
    groups: list[dict[str, object]],
    candidate: dict[str, object],
    *,
    root: Path = REPO_ROOT,
) -> tuple[list[dict[str, object]], str]:
    result = [dict(group) for group in groups]
    candidate_name = str(candidate["name"])
    candidate_source = str(candidate["source"])
    candidate_owners = dict(candidate["owners"])
    candidate_symbols = dict(candidate.get("symbols") or {})

    same_name = [index for index, group in enumerate(result) if group.get("name") == candidate_name]
    if len(same_name) > 1:
        raise ValueError(f"More than one registered group is named {candidate_name}")

    owner_groups: dict[str, str] = {}
    source_groups: dict[str, str] = {}
    for group in result:
        name = str(group.get("name") or "")
        source_groups[str(group.get("source") or "").replace("\\", "/").casefold()] = name
        for va in (group.get("owners") or {}):
            owner_groups[str(va).upper()] = name

    for va in candidate_owners:
        other = owner_groups.get(str(va).upper())
        if other and other != candidate_name:
            raise ValueError(f"VA {va} is already owned by {other}")
    other_source = source_groups.get(candidate_source.casefold())
    if other_source and other_source != candidate_name:
        raise ValueError(f"Wrapper {candidate_source} is already registered as {other_source}")

    if not same_name:
        result.append(candidate)
        return result, "add"

    index = same_name[0]
    current = result[index]
    for key in ("source", "flags"):
        current_value = str(current.get(key) or "").replace("\\", "/")
        candidate_value = str(candidate.get(key) or "").replace("\\", "/")
        if current_value != candidate_value:
            raise ValueError(
                f"Registered group {candidate_name} uses {key} {current_value!r}, not {candidate_value!r}"
            )

    current_module = str(current.get("module") or "")
    candidate_module = str(candidate.get("module") or "")
    if current_module and candidate_module and current_module != candidate_module:
        raise ValueError(
            f"Registered group {candidate_name} uses module {current_module!r}, "
            f"not {candidate_module!r}"
        )

    owners = dict(current.get("owners") or {})
    owners.update(candidate_owners)
    merged_module = candidate_module or current_module
    if merged_module:
        owners = dict(sorted(owners.items(), key=lambda item: int(item[0], 16)))
    else:
        source_path = root / candidate_source
        local_includes = _all_local_includes(source_path)
        owner_positions: dict[str, int] = {}
        fallback_position = 1 << 30
        for owner_index, (va, owner) in enumerate(owners.items()):
            owner_path = root / str(owner).replace("\\", "/")
            positions = _owner_include_positions(source_path, owner_path)
            if not positions:
                positions = [
                    position
                    for position, included_path in local_includes
                    if included_path.name.casefold() == owner_path.name.casefold()
                ]
            owner_positions[va] = (
                positions[0] if len(positions) == 1 else fallback_position + owner_index
            )
        owners = dict(sorted(owners.items(), key=lambda item: owner_positions[item[0]]))
    symbols = dict(current.get("symbols") or {})
    symbols.update(candidate_symbols)
    merged = dict(current)
    if merged_module:
        merged["module"] = merged_module
    merged["owners"] = owners
    if symbols or "symbols" in current or candidate_symbols:
        merged["symbols"] = symbols
    result[index] = merged
    return result, "update"


def introduced_validation_issues(
    baseline: list[object], proposed: list[object]
) -> list[object]:
    """Return structural issues added by one candidate config change."""
    remaining = Counter(baseline)
    introduced: list[object] = []
    for issue in proposed:
        if remaining[issue] > 0:
            remaining[issue] -= 1
        else:
            introduced.append(issue)
    return introduced


def changed_owner_checks(
    groups: list[dict[str, object]], candidate: dict[str, object]
) -> dict[str, object]:
    """Return owners whose registered path or symbol will change."""
    current = next(
        (group for group in groups if group.get("name") == candidate.get("name")),
        None,
    )
    candidate_owners = dict(candidate.get("owners") or {})
    if current is None:
        return candidate_owners

    current_owners = dict(current.get("owners") or {})
    current_symbols = dict(current.get("symbols") or {})
    candidate_symbols = dict(candidate.get("symbols") or {})
    changed: dict[str, object] = {}
    for va, owner in candidate_owners.items():
        current_owner = str(current_owners.get(va) or "").replace("\\", "/")
        candidate_owner = str(owner).replace("\\", "/")
        owner_changed = current_owner != candidate_owner
        symbol_changed = (
            va in candidate_symbols
            and current_symbols.get(va) != candidate_symbols[va]
        )
        if owner_changed or symbol_changed:
            changed[va] = owner
    return changed


def validate_report(
    payload: dict[str, object], proposal_path: Path, report_path: Path
) -> dict[str, object]:
    report = json.loads(report_path.read_text(encoding="utf-8"))
    if not isinstance(report, dict):
        raise ValueError("Validation report root must be an object")
    if report.get("schema") != 1 or not report.get("proposal_valid"):
        raise ValueError("Validation report is not a successful candidate report")
    report_proposal = Path(str(report.get("proposal") or ""))
    if not report_proposal.is_absolute():
        report_proposal = REPO_ROOT / report_proposal
    if report_proposal.resolve() != proposal_path.resolve():
        raise ValueError("Validation report belongs to a different proposal")

    inputs = [proposal_path, _resolve(payload["source"]), _resolve(payload["flags"])]
    for section in ("owners", "observed"):
        entries = payload[section]
        assert isinstance(entries, dict)
        for entry in entries.values():
            value = entry["source"] if isinstance(entry, dict) else entry
            inputs.append(_resolve(value))
    report_time = report_path.stat().st_mtime_ns
    stale = [path for path in inputs if path.is_file() and path.stat().st_mtime_ns > report_time]
    if stale:
        names = ", ".join(str(path) for path in stale)
        raise ValueError(f"Validation report is older than its inputs: {names}")
    return report


def candidate_flag_errors(candidate: dict[str, object]) -> list[dict[str, object]]:
    # Fresh candidate validation already compiled every proposed exact owner
    # with the configured TU flags. Per-function response files describe old
    # isolated builds and cannot invalidate that grouped result.
    superseded_codes = {"stale_per_function_exception"}
    owners = candidate["owners"]
    assert isinstance(owners, dict)
    owner_vas = {str(va).upper() for va in owners}
    records = [row for row in load_functions() if row["va"].upper() in owner_vas]
    source_map = load_pdb_function_source_map()
    selected_source_map = {va: source_map[va] for va in owner_vas if va in source_map}
    report = audit_translation_units(
        groups=[candidate],
        records=records,
        source_map=selected_source_map,
        original_needs=load_original_needs(records),
    )
    scope = f"current:{candidate['name']}"
    return [
        issue
        for issue in report["issues"]
        if issue.get("scope") == scope
        and issue.get("severity") == "error"
        and issue.get("code") not in superseded_codes
    ]


def _write_config(groups: list[dict[str, object]]) -> None:
    payload = {"translation_units": groups}
    text = json.dumps(payload, indent=2) + "\n"
    temporary = TRANSLATION_UNITS_PATH.with_suffix(".json.tmp")
    with temporary.open("w", encoding="utf-8", newline="\n") as stream:
        stream.write(text)
    os.replace(temporary, TRANSLATION_UNITS_PATH)


def _restore_config(text: str) -> None:
    with TRANSLATION_UNITS_PATH.open("w", encoding="utf-8", newline="\n") as stream:
        stream.write(text)


def _registered_check(va: str) -> tuple[str, bool, str]:
    completed = subprocess.run(
        [
            sys.executable,
            str(REPO_ROOT / "tools" / "check_function.py"),
            "--va",
            va,
            "--detail",
            "concise",
        ],
        cwd=REPO_ROOT,
        text=True,
        capture_output=True,
        check=False,
    )
    output = completed.stdout + completed.stderr
    exact = (
        completed.returncode == 0
        and "Result: MATCH" in completed.stdout
        and "0.0000%" in completed.stdout
    )
    return va, exact, output


def run_registered_checks(
    owners: dict[str, object], jobs: int
) -> list[tuple[str, bool, str]]:
    vas = list(owners)
    with ThreadPoolExecutor(max_workers=max(1, jobs)) as executor:
        return list(executor.map(_registered_check, vas))


def main() -> int:
    args = parse_args()
    try:
        proposal_path = args.proposal.resolve()
        payload = load_proposal(proposal_path)
        issues = validate_proposal(payload)
        if issues:
            raise ValueError("; ".join(issues))
        output_dir = (
            REPO_ROOT / "build" / "candidate_tus" / slugify_name(str(payload["name"]))
        )
        completed = subprocess.run(
            [
                sys.executable,
                str(REPO_ROOT / "tools" / "validate_candidate_tu.py"),
                "--proposal",
                str(proposal_path),
                "--output-dir",
                str(output_dir),
            ],
            cwd=REPO_ROOT,
            text=True,
            capture_output=True,
            check=False,
        )
        if completed.stdout:
            print(completed.stdout, end="")
        if completed.stderr:
            print(completed.stderr, end="", file=sys.stderr)
        if completed.returncode != 0:
            raise ValueError("Fresh candidate validation failed")
        report_path = output_dir / "report.json"
        validate_report(payload, proposal_path, report_path)
        candidate = candidate_group(payload)
        if args.name:
            candidate["name"] = args.name
        registered_groups = load_translation_units()
        baseline_issues = validate_translation_units(registered_groups)
        owners_to_check = changed_owner_checks(registered_groups, candidate)
        groups, action = merge_candidate_group(registered_groups, candidate)
        flag_errors = candidate_flag_errors(candidate)
        if flag_errors:
            message = "; ".join(str(issue["message"]) for issue in flag_errors)
            raise ValueError(f"Candidate flags are not safe: {message}")
        target = next(group for group in groups if group.get("name") == candidate["name"])
        target_issues = validate_translation_units([target])
        if target_issues:
            message = "; ".join(str(issue) for issue in target_issues)
            raise ValueError(f"Candidate translation unit is invalid: {message}")
        proposed_issues = validate_translation_units(groups)
        introduced_issues = introduced_validation_issues(
            baseline_issues, proposed_issues
        )
        if introduced_issues:
            message = "; ".join(str(issue) for issue in introduced_issues)
            raise ValueError(f"Candidate config introduces invalid state: {message}")
    except (OSError, ValueError, KeyError, json.JSONDecodeError) as error:
        print(f"Cannot register candidate: {error}", file=sys.stderr)
        return 2

    owners = candidate["owners"]
    assert isinstance(owners, dict)
    print(f"Action: {action} translation unit {candidate['name']}")
    print(f"Source: {candidate['source']}")
    print(f"Exact owners: {len(owners)}")
    if baseline_issues:
        print(
            f"Existing unrelated config issues: {len(baseline_issues)} "
            "(candidate adds none)."
        )
    if not args.apply:
        print("Dry run. Use --apply to write config/translation_units.json.")
        return 0

    if args.jobs < 1:
        print("Cannot register candidate: --jobs must be at least 1", file=sys.stderr)
        return 2
    old_config = TRANSLATION_UNITS_PATH.read_text(encoding="utf-8")
    _write_config(groups)
    results = run_registered_checks(owners_to_check, args.jobs)
    failures = [result for result in results if not result[1]]
    if failures:
        _restore_config(old_config)
        for va, _, output in failures:
            print(f"Registered owner {va} failed after apply:", file=sys.stderr)
            print(output, file=sys.stderr)
        print("Restored config/translation_units.json.", file=sys.stderr)
        return 1
    print(
        f"Changed registered checks: {len(results)}/{len(results)} MATCH, 0.0000%."
    )
    print("Updated config/translation_units.json.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
