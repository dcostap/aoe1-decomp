from __future__ import annotations

import json
from pathlib import Path
import subprocess
import sys
import uuid

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from build_assembly import assemble_source
from common import load_toolchain, repo_path
from probe_compression_library import inf32_issues

ORIGINAL = ROOT / "orig/empiresx.exe"


def tools_installed() -> bool:
    assembler = Path(json.loads((ROOT / "config/assembly_toolchain.json").read_text())["path"])
    return assembler.is_file() and repo_path(load_toolchain()["compiler"]["cl"]).is_file()


pytestmark = [
    pytest.mark.skipif(not ORIGINAL.is_file(), reason="needs orig/empiresx.exe"),
    pytest.mark.skipif(not tools_installed(), reason="needs the pinned VC5 compiler and MASM"),
]


def test_inf32_source_assembles_to_original_bytes():
    obj = ROOT / "build/tests/compression_library" / uuid.uuid4().hex / "Inf32.obj"
    result = assemble_source(ROOT / "src/Inf32.asm", obj)
    assert result["compiled"], result["stdout"] + result["stderr"]
    assert inf32_issues(obj) == []


def test_deflate_source_matches_original_behavior():
    result = subprocess.run([sys.executable, str(ROOT / "tools/probe_compression_library.py"), "--quick",
                             "--output-dir", "build/tests/compression_library_probe"],
                            capture_output=True, text=True, timeout=1800)
    assert result.returncode == 0, result.stdout + result.stderr
    summary = json.loads(result.stdout)
    assert summary["passed"] and summary["differential"].endswith(" 0 mismatches")
