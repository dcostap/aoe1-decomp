import hashlib
import json
from pathlib import Path
import sys

import pytest

TOOLS = Path(__file__).resolve().parents[1] / "tools"
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "harness"))
import game
from capture import save_frame, hook_config, savegame_outputs
from compare import compare
import registry_state


def test_build_requires_matching_report_hash(tmp_path):
    exe = tmp_path / 'empiresx.exe'
    exe.write_bytes(b'new')
    report = {'linked': True, 'artifact_sha256': {'empiresx.exe': hashlib.sha256(b'new').hexdigest()}}
    (tmp_path / 'report.json').write_text(json.dumps(report))
    assert game.validate_build(exe) == exe
    exe.write_bytes(b'changed')
    with pytest.raises(ValueError, match='successful build report'):
        game.validate_build(exe)


def test_failed_build_rejected_even_with_correct_hash(tmp_path):
    exe = tmp_path / 'empiresx.exe'
    exe.write_bytes(b'new')
    report = {'linked': False, 'artifact_sha256': {'empiresx.exe': hashlib.sha256(b'new').hexdigest()}}
    (tmp_path / 'report.json').write_text(json.dumps(report))
    with pytest.raises(ValueError, match='successful build report'):
        game.validate_build(exe)


def test_parallel_runtime_names_are_unique():
    assert len({game.stamp() for _ in range(128)}) == 128


def test_automated_registry_profile_is_independent_of_live_settings():
    values = registry_state.automated_values()
    screen_size = next(row['value'] for row in values['user'] if row['name'] == 'Screen Size')
    assert screen_size == 640
    changed = registry_state.with_screen_size(values, 800)
    assert next(row['value'] for row in changed['user'] if row['name'] == 'Screen Size') == 800
    assert next(row['value'] for row in values['user'] if row['name'] == 'Screen Size') == 640


def test_capture_excludes_pitch_padding_but_keeps_raw_data(tmp_path):
    meta = {'width': 2, 'height': 2, 'pitch': 4, 'count': 1}
    palette = bytes(1024)
    payload = bytes([1, 2, 99, 99, 3, 4, 88, 88]) + palette
    row = save_frame(tmp_path, meta, payload)
    assert row['pixel_sha256'] == hashlib.sha256(bytes([1, 2, 3, 4])).hexdigest()
    assert (tmp_path / 'frame-0001.bin').read_bytes() == payload


def test_palette_changes_detected_even_when_indices_match(tmp_path):
    meta = {'width': 1, 'height': 1, 'pitch': 1, 'count': 1}
    first = save_frame(tmp_path, meta, b'\x00' + bytes(1024))
    second = save_frame(tmp_path, dict(meta, count=2), b'\x00\xff' + bytes(1023))
    assert first['pixel_sha256'] == second['pixel_sha256']
    assert first['palette_sha256'] != second['palette_sha256']
    assert first['rgb_sha256'] != second['rgb_sha256']


def test_invalid_frame_length_rejected(tmp_path):
    with pytest.raises(ValueError, match='payload size'):
        save_frame(tmp_path, {'width': 1, 'height': 1, 'pitch': 1, 'count': 1}, b'')


def test_save_outputs_report_changed_and_removed_files(tmp_path):
    runtime = tmp_path / 'runtime'
    folder = runtime / 'savegame'
    folder.mkdir(parents=True)
    changed = folder / 'checkpoint.gmx'
    changed.write_bytes(b'changed')
    (folder / 'new.gam').write_bytes(b'new')
    manifest = {'copied_files_before_exe_replacement': [
        {'path': 'savegame/checkpoint.gmx', 'sha256': hashlib.sha256(b'old').hexdigest()},
        {'path': 'savegame/removed.gmx', 'sha256': hashlib.sha256(b'gone').hexdigest()}]}
    result = savegame_outputs(runtime, manifest)
    assert {row['path'] for row in result['changed']} == {'savegame/checkpoint.gmx', 'savegame/new.gam'}
    assert result['removed'] == ['savegame/removed.gmx']


def test_override_breaks_link_without_changing_source(tmp_path, monkeypatch):
    import os
    monkeypatch.setattr(game, 'ROOT', tmp_path)
    runtime = tmp_path / 'build/runtime/test'
    runtime.mkdir(parents=True)
    (runtime / 'runtime_manifest.json').write_text('{}')
    source = tmp_path / 'original.drs'
    source.write_bytes(b'original')
    os.link(source, runtime / 'graphics.drs')
    replacement = tmp_path / 'replacement.drs'
    replacement.write_bytes(b'replacement')
    game.override_asset(runtime, Path('graphics.drs'), replacement)
    assert source.read_bytes() == b'original'
    assert (runtime / 'graphics.drs').read_bytes() == b'replacement'
    assert not source.samefile(runtime / 'graphics.drs')


def test_override_rejects_parent_escape(tmp_path, monkeypatch):
    monkeypatch.setattr(game, 'ROOT', tmp_path)
    with pytest.raises(ValueError, match='inside a prepared runtime'):
        game.override_asset(tmp_path / 'build/runtime/test', Path('../escape.drs'), tmp_path / 'input.drs')


def capture_report(directory, pixel=0, seed=1002):
    directory.mkdir()
    frame = save_frame(directory, {'width': 1, 'height': 1, 'pitch': 1, 'count': 1},
                       bytes([pixel]) + bytes(1024))
    report = {'frames': [frame], 'errors': [], 'manifest': {}, 'arguments': [],
              'fixture': {}, 'clock': 'calls', 'script_sha256': 'same', 'registry_inputs': {},
              'status': {'rngCount': 1, 'rngTrace': [{'seed': seed}]}}
    path = directory / 'report.json'
    path.write_text(json.dumps(report))
    return path


def test_equal_capture_passes(tmp_path):
    left = capture_report(tmp_path / 'a')
    right = capture_report(tmp_path / 'b')
    assert compare(left, right, tmp_path / 'diff') == 0


def test_changed_index_fails_even_with_identical_rgb(tmp_path):
    left = capture_report(tmp_path / 'a')
    right = capture_report(tmp_path / 'b', pixel=1)
    assert compare(left, right, tmp_path / 'diff') == 1
    report = json.loads((tmp_path / 'diff/report.json').read_text())
    assert report['different_indices'] == 1
    assert report['different_rgb_pixels'] == 0


def test_changed_seed_fails_even_with_identical_pixels(tmp_path):
    left = capture_report(tmp_path / 'a')
    right = capture_report(tmp_path / 'b', seed=1003)
    assert compare(left, right, tmp_path / 'diff') == 1


def test_different_fixture_rejected(tmp_path):
    left = capture_report(tmp_path / 'a')
    right = capture_report(tmp_path / 'b')
    report = json.loads(right.read_text())
    report['fixture'] = {'different': True}
    right.write_text(json.dumps(report))
    with pytest.raises(ValueError, match='fixtures differ'):
        compare(left, right, tmp_path / 'diff')


def test_hook_rejects_changed_exe_before_parsing(tmp_path):
    exe = tmp_path / 'empiresx.exe'
    exe.write_bytes(b'changed')
    with pytest.raises(ValueError, match='EXE hash changed'):
        hook_config(exe, {'selected_exe_sha256': 'wrong'})


def test_different_asset_override_rejected(tmp_path):
    left = capture_report(tmp_path / 'a')
    right = capture_report(tmp_path / 'b')
    report = json.loads(right.read_text())
    report['manifest']['overrides'] = {'data2/graphics.drs': {'sha256': 'changed'}}
    right.write_text(json.dumps(report))
    with pytest.raises(ValueError, match='Asset inputs differ'):
        compare(left, right, tmp_path / 'diff')


def test_worker_defaults_to_private_desktop(tmp_path, monkeypatch):
    calls = []
    class Result:
        returncode = 0
    monkeypatch.setattr(game.subprocess, 'run', lambda command, **kw: calls.append(command) or Result())
    assert game.run_worker(['python', 'capture.py'], tmp_path / 'worker.log', 60, False) == 0
    assert calls[0][1].endswith('hidden.py')
    assert calls[0][-2:] == ['python', 'capture.py']


def test_visible_worker_requires_opt_in(tmp_path, monkeypatch):
    calls = []
    class Result:
        returncode = 0
    monkeypatch.setattr(game.subprocess, 'run', lambda command, **kw: calls.append(command) or Result())
    game.run_worker(['python', 'capture.py'], tmp_path / 'worker.log', 60, True)
    assert calls == [['python', 'capture.py', '--visible']]


def test_capture_prepare_only_does_not_start_worker(tmp_path, monkeypatch):
    monkeypatch.setattr(game.sys, 'argv', ['game.py', 'capture', 'original', '--prepare-only'])
    monkeypatch.setattr(game, 'stage', lambda *args, **kwargs: tmp_path)
    def refuse(*args, **kwargs):
        pytest.fail('Prepare-only must not start a worker.')
    monkeypatch.setattr(game, 'run_worker', refuse)
    assert game.main() == 0
