"""Verify linked audit inputs against the build's recorded output hashes."""
from __future__ import annotations
import hashlib
import json
from pathlib import Path
from common import REPO_ROOT


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def registry_digest() -> str:
    rows = [(p.relative_to(REPO_ROOT).as_posix(), digest(p))
            for p in sorted((REPO_ROOT / 'config/functions').rglob('*.json'))]
    return hashlib.sha256(json.dumps(rows).encode()).hexdigest()


def verify_build(build: Path, *, objects: bool = False) -> dict:
    report = json.loads((build / 'report.json').read_text())
    if not report.get('linked'):
        raise ValueError('The build did not complete its link')
    hashes = report.get('artifact_sha256', {})
    required = ['empiresx.exe', 'empiresx.map']
    if objects:
        required += [Path(r['object']).name for r in report['sources'] if r.get('compiled')]
    for name in required:
        if name not in hashes:
            raise ValueError(f'Build has no recorded hash for {name}; make a fresh build')
        if digest(build / name) != hashes[name]:
            raise ValueError(f'Build artifact changed: {name}')
    if report.get('registry_sha256') != registry_digest():
        raise ValueError('Function registry differs from the build snapshot')
    if objects:
        checked = {}
        for source in report['sources']:
            for item in source.get('inputs', {}).get('inputs', []):
                path = REPO_ROOT / item['path']
                if path not in checked:
                    checked[path] = digest(path)
                if checked[path] != item['sha256']:
                    raise ValueError(f'Source input differs from the build: {path}')
    original = REPO_ROOT / report['config']['original']
    pinned = json.loads((REPO_ROOT / 'config/executable.json').read_text())
    if digest(original) != pinned['original_sha256']:
        raise ValueError('Original EXE differs from the pinned oracle')
    return report
