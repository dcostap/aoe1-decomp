from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

from common import (
    REPO_ROOT,
    classify_corpus_bucket,
    ensure_build_subdir,
    load_asm_special_function_names,
    load_asm_special_regions,
    load_functions,
    load_padding_only_functions,
    load_toolchain_supplied_function_names,
    load_toolchain_supplied_regions,
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Sweep claimed-finished functions and rerun validation.")
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument(
        "--matching-only",
        action="store_true",
        help="Validate exact claimed finished bank under src\\matching\\.",
    )
    mode.add_argument(
        "--accepted-drift",
        action="store_true",
        help="Validate accepted drift bank under src\\accepted_drift\\; mismatches are expected and reported.",
    )
    mode.add_argument(
        "--verified-logic",
        action="store_true",
        help="Validate verified-logic bank under src\\verified_logic\\; mismatches are expected and reported.",
    )
    return parser.parse_args()


def source_bank_sources(
    bank: str,
    records: list[dict[str, str]],
) -> tuple[list[Path], list[Path]]:
    source_dir = REPO_ROOT / "src" / bank
    if not source_dir.exists():
        return [], []

    records_by_va = {record["va"].upper(): record for record in records}
    records_by_slug = {record["slug"].upper(): record for record in records}
    candidates: dict[str, list[Path]] = {}
    orphan_sources: list[Path] = []
    for child in sorted(source_dir.iterdir()):
        if child.suffix.lower() not in {".c", ".cpp"}:
            continue
        stem_key = child.stem.upper()
        record = records_by_slug.get(stem_key)
        if record is None and len(stem_key) >= 8:
            record = records_by_va.get(stem_key[:8])
        if record is None:
            orphan_sources.append(child)
            continue
        candidates.setdefault(record["va"].upper(), []).append(child)

    selected: list[Path] = []
    for paths in candidates.values():
        canonical = [path for path in paths if path.stem.upper() == records_by_va[path.stem[:8].upper()]["slug"].upper()]
        choices = canonical or paths
        selected.append(next((path for path in choices if path.suffix.lower() == ".c"), choices[0]))
        orphan_sources.extend(path for path in paths if path not in selected)
    return sorted(selected), sorted(set(orphan_sources))


def inventory_by_slug() -> dict[str, dict[str, str]]:
    return {record["slug"].upper(): record for record in load_functions()}


def run_check(va: str) -> subprocess.CompletedProcess[str]:
    command = [sys.executable, str(REPO_ROOT / "tools" / "check_function.py"), "--va", va, "--no-history"]
    return subprocess.run(command, capture_output=True, text=True)


def main() -> None:
    args = parse_args()
    if args.matching_only:
        bank = "matching"
        mode_label = "matching-only"
    elif args.accepted_drift:
        bank = "accepted_drift"
        mode_label = "accepted-drift"
    else:
        bank = "verified_logic"
        mode_label = "verified-logic"
    nonexact_bank = not args.matching_only

    records = load_functions()
    slug_map = inventory_by_slug()
    toolchain_supplied_names = load_toolchain_supplied_function_names()
    toolchain_supplied_regions = load_toolchain_supplied_regions()
    asm_special_names = load_asm_special_function_names()
    asm_special_regions = load_asm_special_regions()
    padding_only_functions = load_padding_only_functions()
    sources, orphan_sources = source_bank_sources(bank, records)
    summary_dir = ensure_build_subdir("validator")
    summary_path = summary_dir / f"{mode_label}_summary.txt"

    if not sources:
        summary_path.write_text(f"Mode: {mode_label}\nFunctions scanned: 0\nResult: PASS (nothing claimed yet)\n", encoding="utf-8")
        print(f"Mode: {mode_label}")
        print("Functions scanned: 0")
        print("Result: PASS (nothing claimed yet)")
        return

    lines = [f"Mode: {mode_label}", f"Functions scanned: {len(sources)}", ""]
    if orphan_sources:
        lines.append(f"Non-canonical source files not scanned: {len(orphan_sources)}")
        lines.extend(f"ORPHAN  {path.relative_to(REPO_ROOT)}" for path in orphan_sources)
        lines.append("")
    passed = 0
    failed = 0
    missing_inventory = 0
    skipped_non_normal = 0

    for source in sources:
        slug = source.stem
        source_key = slug.upper()
        record = slug_map.get(source_key)
        if record is None:
            missing_inventory += 1
            failed += 1
            message = f"FAIL  <unknown-va>  {slug}  missing inventory record"
            print(message)
            lines.append(message)
            continue

        corpus_bucket, corpus_reason = classify_corpus_bucket(
            record,
            toolchain_supplied_names=toolchain_supplied_names,
            toolchain_supplied_regions=toolchain_supplied_regions,
            asm_special_names=asm_special_names,
            asm_special_regions=asm_special_regions,
            padding_only_functions=padding_only_functions,
        )
        if corpus_bucket != "normal":
            skipped_non_normal += 1
            extra = f" ({corpus_reason})" if corpus_reason else ""
            message = f"SKIP  {record['va']}  {slug}  non-normal corpus bucket={corpus_bucket}{extra}"
            print(message)
            lines.append(message)
            continue

        va = record["va"]
        result = run_check(va)
        if result.returncode == 0:
            if nonexact_bank:
                failed += 1
                message = f"FAIL  {va}  {slug}  {bank} is now exact; move to src\\matching"
                print(message)
                lines.append(message)
                continue
            passed += 1
            message = f"PASS  {va}  {slug}"
            print(message)
            lines.append(message)
            continue

        if nonexact_bank:
            passed += 1
            diff_report = REPO_ROOT / "build" / "diff" / f"{slug}.txt"
            message = f"PASS-NONEXACT  {va}  {slug}  see {diff_report.relative_to(REPO_ROOT)}"
            print(message)
            lines.append(message)
            continue

        failed += 1
        diff_report = REPO_ROOT / "build" / "diff" / f"{slug}.txt"
        message = f"FAIL  {va}  {slug}  see {diff_report.relative_to(REPO_ROOT)}"
        print(message)
        lines.append(message)
        if result.stdout.strip():
            lines.append("--- stdout ---")
            lines.extend(result.stdout.strip().splitlines()[-40:])
        if result.stderr.strip():
            lines.append("--- stderr ---")
            lines.extend(result.stderr.strip().splitlines()[-40:])
        lines.append("")

    lines.append(f"Passed: {passed}")
    lines.append(f"Failed: {failed}")
    lines.append(f"Missing inventory records: {missing_inventory}")
    lines.append(f"Skipped non-normal corpus entries: {skipped_non_normal}")
    overall_ok = failed == 0
    lines.append(f"Result: {'PASS' if overall_ok else 'FAIL'}")
    summary_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
    print(f"Missing inventory records: {missing_inventory}")
    print(f"Skipped non-normal corpus entries: {skipped_non_normal}")
    print(f"Result: {'PASS' if overall_ok else 'FAIL'}")
    print(f"Wrote {summary_path}")

    if not overall_ok:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
