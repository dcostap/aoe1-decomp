from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

from common import REPO_ROOT


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the full extract/build/diff loop for one function.")
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    return parser.parse_args()


def run_step(script_name: str, va: str) -> None:
    command = [sys.executable, str(REPO_ROOT / "tools" / script_name), "--va", va]
    result = subprocess.run(command)
    if result.returncode != 0:
        raise SystemExit(result.returncode)


def main() -> None:
    args = parse_args()
    run_step("extract_original_function.py", args.va)
    run_step("build_function.py", args.va)
    run_step("extract_obj_function.py", args.va)
    run_step("diff_function.py", args.va)
    print("MATCHING")


if __name__ == "__main__":
    main()
