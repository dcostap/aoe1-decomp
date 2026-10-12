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
from probe_drawing_engine import drawing_engine_issues

ORIGINAL = ROOT / "orig/empiresx.exe"


def tools_installed() -> bool:
    assembler = Path(json.loads((ROOT / "config/assembly_toolchain.json").read_text())["path"])
    return assembler.is_file() and repo_path(load_toolchain()["compiler"]["cl"]).is_file()


pytestmark = [
    pytest.mark.skipif(not ORIGINAL.is_file(), reason="needs orig/empiresx.exe"),
    pytest.mark.skipif(not tools_installed(), reason="needs the pinned VC5 compiler and MASM"),
]


def test_drawing_source_assembles_to_original_sections():
    obj = ROOT / "build/tests/drawing_engine" / uuid.uuid4().hex / "Asm_draw.obj"
    result = assemble_source(ROOT / "src/Asm_draw.asm", obj)
    assert result["compiled"], result["stdout"] + result["stderr"]
    assert drawing_engine_issues(obj) == []


def test_drawing_source_runs_native_fixtures():
    result = subprocess.run([sys.executable, str(ROOT / "tools/probe_drawing_engine.py"),
                             "--output-dir", "build/tests/drawing_engine_probe"],
                            capture_output=True, text=True, timeout=1800)
    assert result.returncode == 0, result.stdout + result.stderr
    summary = json.loads(result.stdout)
    assert summary["issues"] == [] and summary["native_tests_passed"]
