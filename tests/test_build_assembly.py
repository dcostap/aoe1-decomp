import hashlib
import json
from contextlib import contextmanager
from pathlib import Path
import sys
from types import SimpleNamespace

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import build_assembly


def prepare(tmp_path, monkeypatch, returncode=0, emit=True):
    (tmp_path / 'config').mkdir()
    source = tmp_path / 'draw.asm'
    source.write_text('END\n')
    assembler = tmp_path / 'ml.exe'
    assembler.write_bytes(b'pinned test tool')
    digest = hashlib.sha256(assembler.read_bytes()).hexdigest()
    config = dict(path=str(assembler), sha256=digest, flags=['/nologo', '/c', '/coff'])
    config_path = tmp_path / 'config/assembly_toolchain.json'
    config_path.write_text(json.dumps(config))
    output = tmp_path / 'build/draw.obj'
    events = []

    @contextmanager
    def admission():
        events.append('enter')
        yield
        events.append('leave')

    def run(command, **kwargs):
        assert events[-1] == 'enter'
        assert command == [str(assembler), '/nologo', '/c', '/coff', '/Fo'+str(output), str(source)]
        assert kwargs['cwd'] == source.parent
        if emit:
            output.write_bytes(b'test object')
        return SimpleNamespace(returncode=returncode, stdout='assembler output', stderr='')

    monkeypatch.setattr(build_assembly, 'REPO_ROOT', tmp_path)
    monkeypatch.setattr(build_assembly, 'compiler_admission', admission)
    monkeypatch.setattr(build_assembly, 'subprocess', SimpleNamespace(run=run))
    return source, output, assembler, events


def test_pinned_assembly_build(tmp_path, monkeypatch):
    source, output, assembler, events = prepare(tmp_path, monkeypatch)
    result = build_assembly.assemble_source(source, output)
    assert result['compiled']
    assert result['source'] == 'draw.asm'
    assert result['source_sha256'] == hashlib.sha256(source.read_bytes()).hexdigest()
    assert result['assembler_sha256'] == hashlib.sha256(assembler.read_bytes()).hexdigest()
    assert events == ['enter', 'leave']


def test_changed_assembler_fails_before_admission(tmp_path, monkeypatch):
    source, output, assembler, events = prepare(tmp_path, monkeypatch)
    assembler.write_bytes(b'changed tool')
    with pytest.raises(ValueError, match='hash differs'):
        build_assembly.assemble_source(source, output)
    assert events == []
    assert not output.exists()


@pytest.mark.parametrize('returncode,emit', [(1, True), (0, False)])
def test_assembly_requires_success_and_object(tmp_path, monkeypatch, returncode, emit):
    source, output, _, _ = prepare(tmp_path, monkeypatch, returncode, emit)
    result = build_assembly.assemble_source(source, output)
    assert not result['compiled']
    assert result['returncode'] == returncode
    assert result['stdout'] == 'assembler output'
