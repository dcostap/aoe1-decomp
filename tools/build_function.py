from __future__ import annotations

import argparse
import json
import subprocess
import sys
from pathlib import Path

from common import ensure_build_subdir, function_record_by_va, function_slug, load_toolchain, repo_path, tool_env


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compile one source file into a COFF object with the pinned toolchain.")
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    source_path = repo_path(record["source_path"])
    if not source_path.exists():
        raise SystemExit(f"Missing source file: {source_path}")

    toolchain = load_toolchain()
    cl_path = repo_path(toolchain["compiler"]["cl"])
    flags_override = (record.get("flags_override") or "").strip()
    rsp_path = repo_path(flags_override or toolchain["compiler"]["default_rsp"])

    obj_dir = ensure_build_subdir("obj")
    manifest_dir = ensure_build_subdir("manifests")
    obj_path = obj_dir / f"{slug}.obj"
    log_path = manifest_dir / f"build_{slug}.json"

    command = [
        str(cl_path),
        f"@{rsp_path}",
        f"/Fo{obj_path}",
        str(source_path),
    ]
    env = tool_env(toolchain)
    result = subprocess.run(command, capture_output=True, text=True, env=env)

    manifest = {
        "command": command,
        "source": str(source_path),
        "object": str(obj_path),
        "returncode": result.returncode,
        "stdout": result.stdout,
        "stderr": result.stderr,
    }
    log_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")

    sys.stdout.write(result.stdout)
    sys.stderr.write(result.stderr)
    print(f"Wrote {log_path}")

    if result.returncode != 0:
        raise SystemExit(result.returncode)
    if not obj_path.exists():
        raise SystemExit("Compiler exited successfully but produced no object file")

    print(f"Wrote {obj_path}")


if __name__ == "__main__":
    main()
