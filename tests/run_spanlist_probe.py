"""Compile the natural span-list source and test valid interval additions with VC5."""
from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from common import load_toolchain, tool_env


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output-dir", type=Path, default=ROOT / "build/spanlist_probe")
    args = parser.parse_args()
    output = args.output_dir.resolve()
    output.mkdir(parents=True, exist_ok=True)
    config = load_toolchain()
    exe = output / "spanlist_probe.exe"
    build = subprocess.run([
        config["compiler"]["cl"], "/nologo", "/O2", "/Gy",
        str(ROOT / "src/spanlist.cpp"), str(ROOT / "tests/spanlist_probe.cpp"),
        f"/Fe{exe}", "/link", "/OPT:REF", "kernel32.lib",
    ], cwd=output, env=tool_env(config), capture_output=True, text=True)
    (output / "compile.txt").write_text(build.stdout + build.stderr)
    if build.returncode:
        print(build.stdout + build.stderr)
        return build.returncode
    run = subprocess.run([str(exe)], cwd=output, capture_output=True, text=True)
    (output / "result.txt").write_text(run.stdout + run.stderr)
    (output / "inputs.json").write_text(json.dumps({
        "source_sha256": hashlib.sha256((ROOT / "src/spanlist.cpp").read_bytes()).hexdigest(),
        "probe_sha256": hashlib.sha256((ROOT / "tests/spanlist_probe.cpp").read_bytes()).hexdigest(),
        "compiler": config["compiler"]["cl"],
        "returncode": run.returncode,
    }, indent=2) + "\n")
    print(run.stdout + run.stderr, end="")
    return run.returncode


if __name__ == "__main__":
    raise SystemExit(main())
