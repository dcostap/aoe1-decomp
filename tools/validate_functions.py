from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

from common import REPO_ROOT, ensure_build_subdir, load_functions, load_toolchain_supplied_function_names


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Sweep claimed-finished functions and rerun exact-match validation.")
    parser.add_argument(
        "--matching-only",
        action="store_true",
        help="Validate the claimed finished bank under src\\matching\\.",
    )
    return parser.parse_args()


def matching_sources() -> list[Path]:
    matching_dir = REPO_ROOT / "src" / "matching"
    if not matching_dir.exists():
        return []
    return sorted(
        child
        for child in matching_dir.iterdir()
        if child.suffix.lower() in {".c", ".cpp"}
    )


def inventory_by_slug() -> dict[str, dict[str, str]]:
    return {record["slug"]: record for record in load_functions()}


def run_check(va: str) -> subprocess.CompletedProcess[str]:
    command = [sys.executable, str(REPO_ROOT / "tools" / "check_function.py"), "--va", va]
    return subprocess.run(command, capture_output=True, text=True)


def main() -> None:
    args = parse_args()
    if not args.matching_only:
        raise SystemExit("Use --matching-only")

    slug_map = inventory_by_slug()
    toolchain_supplied_names = load_toolchain_supplied_function_names()
    sources = matching_sources()
    summary_dir = ensure_build_subdir("validator")
    summary_path = summary_dir / "matching_only_summary.txt"

    if not sources:
        summary_path.write_text("Mode: matching-only\nFunctions scanned: 0\nResult: PASS (nothing claimed yet)\n", encoding="utf-8")
        print("Mode: matching-only")
        print("Functions scanned: 0")
        print("Result: PASS (nothing claimed yet)")
        return

    lines = ["Mode: matching-only", f"Functions scanned: {len(sources)}", ""]
    passed = 0
    failed = 0
    missing_inventory = 0
    skipped_toolchain = 0

    for source in sources:
        slug = source.stem
        record = slug_map.get(slug)
        if record is None:
            missing_inventory += 1
            failed += 1
            message = f"FAIL  <unknown-va>  {slug}  missing inventory record"
            print(message)
            lines.append(message)
            continue

        if record["name"] in toolchain_supplied_names:
            skipped_toolchain += 1
            message = f"SKIP  {record['va']}  {slug}  toolchain/lib-supplied manifest entry"
            print(message)
            lines.append(message)
            continue

        va = record["va"]
        result = run_check(va)
        if result.returncode == 0:
            passed += 1
            message = f"PASS  {va}  {slug}"
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
    lines.append(f"Skipped toolchain/lib-supplied: {skipped_toolchain}")
    overall_ok = failed == 0
    lines.append(f"Result: {'PASS' if overall_ok else 'FAIL'}")
    summary_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
    print(f"Missing inventory records: {missing_inventory}")
    print(f"Skipped toolchain/lib-supplied: {skipped_toolchain}")
    print(f"Result: {'PASS' if overall_ok else 'FAIL'}")
    print(f"Wrote {summary_path}")

    if not overall_ok:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
