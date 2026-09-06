"""Build standalone assembly with the pinned MASM tool."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import subprocess

from build_cache import compiler_admission
from common import REPO_ROOT


def assemble_source(source: Path, output: Path) -> dict:
    config_path = REPO_ROOT / 'config/assembly_toolchain.json'
    config = json.loads(config_path.read_text())
    assembler = Path(config['path'])
    digest = hashlib.sha256(assembler.read_bytes()).hexdigest()
    if digest != config['sha256']:
        raise ValueError('Assembler hash differs from the pinned tool.')
    output.parent.mkdir(parents=True, exist_ok=True)
    command = [str(assembler), *config['flags'], '/Fo' + str(output), str(source)]
    with compiler_admission():
        result = subprocess.run(command, cwd=source.parent, capture_output=True, text=True)
    return dict(source=source.relative_to(REPO_ROOT).as_posix(), object=str(output),
                source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
                assembler_sha256=digest, command=command, returncode=result.returncode,
                stdout=result.stdout, stderr=result.stderr,
                compiled=result.returncode == 0 and output.is_file())
