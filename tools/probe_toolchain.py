from __future__ import annotations

import hashlib
import json
import shutil
import subprocess
import tempfile
from pathlib import Path

from common import ensure_build_subdir, load_toolchain, repo_path, tool_env


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def compile_once(cl_path: Path, rsp_path: Path, source: Path, output: Path, env: dict[str, str]) -> dict:
    command = [
        str(cl_path),
        f"@{rsp_path}",
        f"/Fo{output}",
        str(source),
    ]
    result = subprocess.run(command, capture_output=True, text=True, env=env)
    return {
        "command": command,
        "returncode": result.returncode,
        "stdout": result.stdout,
        "stderr": result.stderr,
        "exists": output.exists(),
        "sha256": sha256(output) if output.exists() else None,
    }


def main() -> None:
    toolchain = load_toolchain()
    cl_path = repo_path(toolchain["compiler"]["cl"])
    rsp_path = repo_path(toolchain["compiler"]["default_rsp"])
    manifest_dir = ensure_build_subdir("manifests")
    manifest_path = manifest_dir / "toolchain_probe.json"

    temp_dir = Path(tempfile.mkdtemp(prefix="aoe1_attempt3_probe_"))
    try:
        source = temp_dir / "probe_add.c"
        source.write_text("int probe_add(int a, int b) { return a + b; }\n", encoding="ascii")
        obj_a = temp_dir / "probe_a.obj"
        obj_b = temp_dir / "probe_b.obj"
        env = tool_env(toolchain)

        first = compile_once(cl_path, rsp_path, source, obj_a, env)
        second = compile_once(cl_path, rsp_path, source, obj_b, env)
        deterministic = bool(first["exists"] and second["exists"] and first["sha256"] == second["sha256"])

        manifest = {
            "source": str(source),
            "first": first,
            "second": second,
            "deterministic": deterministic,
        }
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")

        print(f"Wrote {manifest_path}")
        print(json.dumps(manifest, indent=2))

        if not deterministic:
            raise SystemExit(1)
    finally:
        shutil.rmtree(temp_dir, ignore_errors=True)


if __name__ == "__main__":
    main()
