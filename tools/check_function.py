from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

from common import REPO_ROOT, function_record_by_va, function_slug


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Build, compare, and diagnose one function.")
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    parser.add_argument("--verbose", action="store_true", help="Show subprocess chatter and the longer diff report.")
    parser.add_argument("--refresh-original", action="store_true", help="Re-extract immutable original bytes.")
    return parser.parse_args()


def run_step(script_name: str, va: str, *, verbose: bool = False, extra: list[str] | None = None) -> None:
    command = [sys.executable, str(REPO_ROOT / "tools" / script_name), "--va", va]
    if extra:
        command.extend(extra)
    result = subprocess.run(command, capture_output=True, text=True)
    if verbose or result.returncode != 0:
        sys.stdout.write(result.stdout)
        sys.stderr.write(result.stderr)
    elif script_name == "build_function.py":
        # Compiler warnings remain important even in concise mode.
        warning_lines = [
            line
            for line in (result.stdout + result.stderr).splitlines()
            if "warning" in line.lower() or "error" in line.lower()
        ]
        if warning_lines:
            print("\n".join(warning_lines))
    if result.returncode != 0:
        raise SystemExit(result.returncode)


def snapshot_previous(slug: str) -> None:
    asm_dir = REPO_ROOT / "build" / "asm"
    diff_dir = REPO_ROOT / "build" / "diff"
    history_dir = REPO_ROOT / "build" / "history" / slug
    candidates = {
        asm_dir / f"rebuilt_{slug}.bin": history_dir / "previous.bin",
        asm_dir / f"rebuilt_{slug}.json": history_dir / "previous.extract.json",
        diff_dir / f"{slug}.json": history_dir / "previous.diff.json",
    }
    existing = [(source, target) for source, target in candidates.items() if source.exists()]
    if not existing:
        return
    history_dir.mkdir(parents=True, exist_ok=True)
    for source, target in existing:
        shutil.copy2(source, target)


def original_artifacts_exist(slug: str) -> bool:
    asm_dir = REPO_ROOT / "build" / "asm"
    return all((asm_dir / f"orig_{slug}.{suffix}").exists() for suffix in ("bin", "json", "txt"))


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)

    snapshot_previous(slug)
    if args.refresh_original or not original_artifacts_exist(slug):
        run_step("extract_original_function.py", args.va, verbose=args.verbose)
    elif args.verbose:
        print(f"Using cached original artifacts for {slug}")

    run_step("build_function.py", args.va, verbose=args.verbose)
    run_step("extract_obj_function.py", args.va, verbose=args.verbose)
    diff_extra = ["--verbose"] if args.verbose else None
    run_step("diff_function.py", args.va, verbose=True, extra=diff_extra)


if __name__ == "__main__":
    main()
