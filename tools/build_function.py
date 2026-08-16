from __future__ import annotations

import argparse
import json
import subprocess
import sys

from build_cache import build_input_manifest, build_manifest_matches
from common import (
    ensure_build_subdir,
    function_record_by_va,
    function_slug,
    load_toolchain,
    preferred_flags_rsp_path,
    preferred_source_path,
    repo_path,
    tool_env,
)
from source_listing import parse_listing_file


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compile one source file into a COFF object with the pinned toolchain.")
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    parser.add_argument("--force", action="store_true", help="Compile even when the input fingerprint is cached.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    source_path = preferred_source_path(record)
    if not source_path.exists():
        raise SystemExit(f"Missing source file: {source_path}")

    toolchain = load_toolchain()
    cl_path = repo_path(toolchain["compiler"]["cl"])
    rsp_path = preferred_flags_rsp_path(record, toolchain)

    obj_dir = ensure_build_subdir("obj")
    manifest_dir = ensure_build_subdir("manifests")
    asm_dir = ensure_build_subdir("asm")
    obj_path = obj_dir / f"{slug}.obj"
    log_path = manifest_dir / f"build_{slug}.json"
    listing_path = asm_dir / f"rebuilt_{slug}.cod"
    source_map_path = asm_dir / f"rebuilt_{slug}.lines.json"
    input_manifest = build_input_manifest(source_path, rsp_path, toolchain)
    fingerprint = str(input_manifest["fingerprint"])

    if not args.force and build_manifest_matches(log_path, fingerprint, obj_path) and source_map_path.is_file():
        print(f"Build cache hit: {slug} ({fingerprint[:12]})")
        return

    command = [
        str(cl_path),
        f"@{rsp_path}",
        "/FAsc",
        f"/Fa{listing_path}",
        f"/Fo{obj_path}",
        str(source_path),
    ]
    for stale in (listing_path, source_map_path):
        if stale.exists():
            stale.unlink()
    env = tool_env(toolchain)
    result = subprocess.run(command, capture_output=True, text=True, env=env)

    manifest = {
        "command": command,
        "source": str(source_path),
        "object": str(obj_path),
        "response_file": str(rsp_path),
        "listing": str(listing_path),
        "source_map": str(source_map_path),
        "input_fingerprint": fingerprint,
        "build_inputs": input_manifest,
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

    if listing_path.exists():
        listing_metadata = parse_listing_file(listing_path)
        listing_metadata.update(
            {
                "schema": 2,
                "listing": str(listing_path),
                "input_fingerprint": fingerprint,
            }
        )
        source_map_path.write_text(json.dumps(listing_metadata, indent=2), encoding="utf-8")

    print(f"Wrote {obj_path}")
    if source_map_path.exists():
        print(f"Wrote {source_map_path}")


if __name__ == "__main__":
    main()
