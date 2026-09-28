"""Check the fast deterministic-trace suite without launching games."""
import hashlib
import json
import lzma
from pathlib import Path
import struct
import sys

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/harness'))
import trace_suite
import human_session as human
from human_session import ORIGINAL_SHA256, POLICY, TRACE_FAST_POLICY, template_sha256


def rng(*records):
    return b''.join(struct.pack('<II', site, value) for site, value in records)


def test_update_checkpoints_are_running_prefix_digests():
    data = rng((0, 5), (1, 6), (1, 7))
    rows = trace_suite.rng_checkpoints(data, [1, 1, 3])
    assert rows == [hashlib.sha256(data[:8]).hexdigest()[:16]] * 2 + [hashlib.sha256(data).hexdigest()[:16]]
    with pytest.raises(ValueError):
        trace_suite.rng_checkpoints(data, [4])


def oracle():
    return {'rng_records': 3, 'rng_sha256': 'a', 'updates': 2, 'inputs': 1, 'world': {'time': 1, 'objects': 2},
            'camera': None, 'update_rng': [[1, 'x'], [3, 'y']]}


def test_exact_run_passes_and_first_update_difference_is_reported():
    run = dict(oracle(), errors=[])
    assert trace_suite.compare(oracle(), run) == {
        'checks': dict.fromkeys(('completed', 'rng_records', 'rng_sha256', 'updates', 'inputs', 'world',
                                 'camera'), True), 'passed': True, 'first_update_difference': None}
    changed = dict(run, rng_sha256='b', update_rng=[[1, 'x'], [3, 'z']])
    result = trace_suite.compare(oracle(), changed)
    assert result['passed'] is False and result['first_update_difference'] == 2
    short = dict(run, update_rng=[[1, 'x']])
    assert trace_suite.compare(oracle(), short)['first_update_difference'] == 2
    assert trace_suite.compare(oracle(), dict(run, errors=['mismatch']))['passed'] is False


def test_first_rng_difference_names_record_site_and_update(tmp_path):
    left, right = tmp_path / 'left', tmp_path / 'right'
    left.mkdir(), right.mkdir()
    (left / 'rng.bin').write_bytes(rng((0, 1), (1, 2), (1, 3)))
    (right / 'rng.bin').write_bytes(rng((0, 1), (1, 2), (1, 4)))
    sites = {'1': {'kind': 'rand', 'file': 'x.cpp', 'line': 7}}
    found = trace_suite.first_rng_difference(left, right, sites, [[2, 'a'], [3, 'b']])
    assert found == {'record': 2, 'world_update': 2, 'original': {'site': sites['1'], 'value': 3},
                     'rebuilt': {'site': sites['1'], 'value': 4}}
    (right / 'rng.bin').write_bytes(rng((0, 1), (1, 2), (1, 3)))
    assert trace_suite.first_rng_difference(left, right, sites, []) is None


def test_pinned_trace_fixtures_are_checked(tmp_path, monkeypatch):
    folder = tmp_path / 'traces' / 'case'
    folder.mkdir(parents=True)
    (folder / 'recording.json.xz').write_bytes(b'r')
    (folder / 'messages.bin.xz').write_bytes(b'm')
    registry = tmp_path / 'traces.json'
    registry.write_text(json.dumps({'schema': 1, 'cases': {'case': {
        'recording_sha256': hashlib.sha256(b'r').hexdigest(),
        'messages_sha256': hashlib.sha256(b'm').hexdigest(), 'duration_ms': 1000}}}))
    monkeypatch.setattr(trace_suite, 'TRACE_DIR', tmp_path / 'traces')
    monkeypatch.setattr(trace_suite, 'REGISTRY', registry)
    assert set(trace_suite.check_fixtures()) == {'case'}
    (folder / 'messages.bin.xz').write_bytes(b'changed')
    with pytest.raises(ValueError, match='changed'):
        trace_suite.check_fixtures()
    with pytest.raises(ValueError, match='Unknown'):
        trace_suite.check_fixtures(['missing'])


def test_no_local_traces_is_a_visible_skip(tmp_path, monkeypatch):
    monkeypatch.setattr(trace_suite, 'REGISTRY', tmp_path / 'missing.json')
    monkeypatch.setattr(trace_suite.subprocess, 'run', lambda *args, **kwargs: pytest.fail('Started a game'))
    result = trace_suite.run_suite(tmp_path / 'run')
    assert result['complete'] is True and 'No traced recordings' in result['skipped']
    assert trace_suite.TRACE_DIR.is_relative_to(trace_suite.ROOT / 'local')


def test_changed_fixture_starts_no_games(tmp_path, monkeypatch):
    def reject(names=None):
        raise ValueError('The case trace file messages.bin.xz changed.')
    monkeypatch.setattr(trace_suite, 'check_fixtures', reject)
    monkeypatch.setattr(trace_suite.subprocess, 'run', lambda *args, **kwargs: pytest.fail('Started a game'))
    result = trace_suite.run_suite(tmp_path / 'run')
    assert result['passed'] is False and 'changed' in result['error']


def test_import_requires_a_deterministic_trace_recording(tmp_path):
    folder = tmp_path / 'human'
    folder.mkdir()
    (folder / 'recording.json').write_text(json.dumps({'automated_smoke': False, 'events': []}))
    with pytest.raises(ValueError, match='deterministic-trace'):
        trace_suite.import_trace(folder, 'case')


def test_registered_cases_load_as_fast_replays():
    for name in trace_suite.check_fixtures():
        recording, _ = human.load_recording_with_sha256(trace_suite.TRACE_DIR / name / 'recording.json.xz')
        oracle = recording['oracle']
        assert recording['message_recording']['format'] == 'aoe-message-pump-v7-le'
        assert recording['clock_trace'] and recording['alloc_fill'] is True
        assert len(oracle['update_rng']) == oracle['updates']
        # Stored bytes are what the registry pins; the trace sha covers raw records.
        raw = lzma.decompress((trace_suite.TRACE_DIR / name / 'messages.bin.xz').read_bytes())
        assert hashlib.sha256(raw).hexdigest() == recording['message_recording']['sha256']


def replay_session(**extra):
    return {'schema': 1, 'mode': 'replay', 'duration_ms': 1000, 'events': [],
            'contract': {'original_sha256': ORIGINAL_SHA256, 'policy': POLICY, 'script_sha256': template_sha256(POLICY),
                         'savegame_source': 'repository-fixtures'}, **extra}


def test_fast_replay_needs_recorded_streams_and_uses_the_native_engine():
    with pytest.raises(ValueError, match='message-pump trace'):
        human.validate_session(replay_session(trace_fast=True))
    with pytest.raises(ValueError, match='clock trace'):
        human.validate_session(replay_session(trace_fast=True, message_replay_path='m'))
    session = replay_session(trace_fast=True, message_replay_path='m', replay_clock_trace=[[1000, 1]], alloc_fill=True)
    plan = human.execution_plan(session)
    assert plan['executed_policy'] == TRACE_FAST_POLICY and plan['same_policy_replay'] is False
    assert plan['executed_script_sha256'] == hashlib.sha256(human.control_template(TRACE_FAST_POLICY).encode()).hexdigest()
    engine = (ROOT / 'tools/harness/trace_replay.js').read_text()
    assert 'Sleep' in engine and 'hs(0xffffffff)' in engine  # Only the terminal park sleeps.
    assert 'replay_clock' in (ROOT / 'tools/harness/trace_replay.c').read_text()
    with pytest.raises(ValueError, match='scheduler upgrades'):
        human.execution_plan(dict(session, recording_sha256='1' * 64, upgrade_rule=human.V8_TO_V9_UPGRADE))


def test_idle_throttle_is_a_traced_recording_option():
    record = {'schema': 1, 'mode': 'record', 'duration_ms': 1000, 'observe': True, 'rng_only': True}
    human.validate_session(dict(record, idle_throttle_ms=1))
    for bad in (dict(record, idle_throttle_ms=0), dict(record, idle_throttle_ms=1, rng_only=False, observe=False),
                dict(replay_session(), idle_throttle_ms=1)):
        with pytest.raises(ValueError, match='idle throttle'):
            human.validate_session(bad)


def test_game_commands_route_to_trace_suite(monkeypatch):
    import game
    calls = []
    monkeypatch.setattr(game.subprocess, 'run', lambda command, **kwargs: calls.append(command) or
                        type('Result', (), {'returncode': 0})())
    monkeypatch.setattr(sys, 'argv', ['game.py', 'test-traces', '--case', 'a', '--jobs', '4'])
    assert game.main() == 0
    assert calls[-1][1].endswith('trace_suite.py') and calls[-1][2:] == ['run', '--case', 'a', '--jobs', '4']
    monkeypatch.setattr(sys, 'argv', ['game.py', 'import-trace', 'build/runtime/x', '--name', 'b'])
    assert game.main() == 0
    assert calls[-1][2] == 'import' and calls[-1][-2:] == ['--name', 'b']
    monkeypatch.setattr(sys, 'argv', ['game.py', 'replay-rebuilt', 'r.json', '--runs', '1', '--fast'])
    assert game.main() == 0
    assert calls[-1][1].endswith('human_session.py') and '--fast' in calls[-1] and '--rng-only' in calls[-1]


def test_game_writes_are_every_changed_runtime_file(tmp_path):
    import capture
    (tmp_path / 'savegame').mkdir()
    (tmp_path / 'savegame/old.gmx').write_bytes(b'old')
    (tmp_path / 'gone.scn').write_bytes(b'gone')
    (tmp_path / 'capture').mkdir()
    before = capture.runtime_snapshot(tmp_path)
    (tmp_path / 'savegame/new.gmx').write_bytes(b'new save')
    (tmp_path / 'gone.scn').unlink()
    (tmp_path / 'capture/report.json').write_text('harness output')
    (tmp_path / 'human-worker.log').write_text('harness log')
    written = capture.written_files(tmp_path, before)
    assert written == {'changed': [{'path': 'savegame/new.gmx', 'size': 8, 'sha256': hashlib.sha256(b'new save').hexdigest()}],
                       'removed': ['gone.scn']}


def test_written_files_join_the_oracle_and_report_the_first_differing_byte():
    save = {'changed': [{'path': 'savegame/a.gmx', 'size': 4, 'sha256': 'x'}], 'removed': []}
    oracle = dict(oracle_with_files := dict(**{'rng_records': 3, 'rng_sha256': 'a', 'updates': 2, 'inputs': 1,
                  'world': {'time': 1, 'objects': 2}, 'camera': None, 'update_rng': []}), written_files=save)
    run = dict(oracle, errors=[])
    assert trace_suite.compare(oracle, run)['checks']['written_files'] is True
    changed = dict(run, written_files={'changed': [{'path': 'savegame/a.gmx', 'size': 4, 'sha256': 'y'}], 'removed': []})
    assert trace_suite.compare(oracle, changed)['passed'] is False
    assert trace_suite.compare(oracle, dict(run, written_files=None))['passed'] is False
    assert 'written_files' not in trace_suite.compare(oracle_with_files, run)['checks']
    assert trace_suite.first_byte_difference(b'abcd', b'abXd') == 2
    assert trace_suite.first_byte_difference(b'abcd', b'abcd') is None
    assert trace_suite.first_byte_difference(b'abcd', b'abcdef') == 4
    rows = trace_suite.file_differences(trace_suite.file_set(save), trace_suite.file_set(changed['written_files']),
                                        lambda path: b'abcd', lambda path: b'abZd')
    assert rows == [{'path': 'savegame/a.gmx', 'expected_sha256': 'x', 'actual_sha256': 'y',
                     'expected_size': 4, 'actual_size': 4, 'first_difference': 2}]
    missing = trace_suite.file_differences(trace_suite.file_set(save), {'changed': {}, 'removed': ['s.scn']},
                                           lambda path: b'abcd', lambda path: None)
    assert missing == [{'path': 'savegame/a.gmx', 'expected_sha256': 'x', 'actual_sha256': None},
                       {'path': 's.scn', 'removed_in': 'actual'}]


def test_recorded_outputs_are_stored_and_pinned(tmp_path, monkeypatch):
    monkeypatch.setattr(trace_suite, 'TRACE_DIR', tmp_path / 'traces')
    monkeypatch.setattr(trace_suite, 'REGISTRY', tmp_path / 'traces.json')
    runtime = tmp_path / 'runtime'
    (runtime / 'capture').mkdir(parents=True)
    (runtime / 'savegame').mkdir()
    (runtime / 'savegame/mine.gmx').write_bytes(b'my save')
    rng_bytes = rng((0, 1))
    (runtime / 'capture/rng.bin').write_bytes(rng_bytes)
    report = {'events': [], 'errors': [], 'status': {'human': {'updates': 0, 'input': 0}},
              'written_files': {'changed': [{'path': 'savegame/mine.gmx', 'size': 7,
                                             'sha256': hashlib.sha256(b'my save').hexdigest()}], 'removed': []}}
    (runtime / 'capture/report.json').write_text(json.dumps(report))
    human_dir = tmp_path / 'human'
    human_dir.mkdir()
    messages = b'\0' * 80
    (human_dir / 'messages.bin').write_bytes(messages)
    (human_dir / 'rng.bin').write_bytes(rng_bytes)
    (human_dir / 'recording.json').write_text(json.dumps({
        'automated_smoke': False, 'duration_ms': 1000, 'events': [], 'clock_trace': [[1, 1]], 'alloc_fill': True,
        'source_report': str(runtime / 'capture/report.json'),
        'message_recording': {'format': 'aoe-message-pump-v7-le', 'sha256': hashlib.sha256(messages).hexdigest()}}))
    row = trace_suite.import_trace(human_dir, 'mine')
    assert list(row['outputs']) == ['savegame/mine.gmx.xz']
    assert trace_suite.stored_output('mine', 'savegame/mine.gmx') == b'my save'
    assert set(trace_suite.check_fixtures()) == {'mine'}
    (tmp_path / 'traces/mine/outputs/savegame/mine.gmx.xz').write_bytes(lzma.compress(b'edited'))
    with pytest.raises(ValueError, match='outputs changed'):
        trace_suite.check_fixtures()


def test_record_command_records_traced_editor_session_and_imports_it(monkeypatch):
    import game
    calls = []

    def run(command, **kwargs):
        calls.append(command)
        if command[1].endswith('human_session.py'):
            output = Path(command[command.index('--output') + 1])
            output.mkdir(parents=True)
            (output / 'recording.json').write_text('{}')
        return type('Result', (), {'returncode': 0})()
    monkeypatch.setattr(game.subprocess, 'run', run)
    monkeypatch.setattr(sys, 'argv', ['game.py', 'record', '--name', 'my-game'])
    try:
        assert game.main() == 0
    finally:
        import shutil
        shutil.rmtree(Path(calls[0][calls[0].index('--output') + 1]), ignore_errors=True)
    assert {'--record', '--no-time-limit', '--editor', '--observe', '--rng-only'} <= set(calls[0])
    assert calls[1][1].endswith('trace_suite.py') and calls[1][2] == 'import' and calls[1][-2:] == ['--name', 'my-game']


def message_record(api, updates, inputs, rng_count):
    fields = [0] * 20
    fields[0], fields[16], fields[17], fields[19] = api, updates, inputs, rng_count
    return struct.pack('<20I', *fields)


def test_cut_keeps_the_prefix_through_an_update_and_derives_its_oracle(tmp_path, monkeypatch):
    traces, registry = tmp_path / 'traces', tmp_path / 'traces.json'
    monkeypatch.setattr(trace_suite, 'TRACE_DIR', traces)
    monkeypatch.setattr(trace_suite, 'REGISTRY', registry)
    peek, dispatch = 0x80000003, 6
    messages = b''.join([message_record(peek, 0, 0, 0), message_record(3, 0, 1, 0),
                         message_record(peek, 1, 1, 2), message_record(3, 1, 2, 2),
                         message_record(peek, 2, 2, 5), message_record(dispatch, 2, 2, 5)])
    capture = tmp_path / 'capture' / 'report.json'
    capture.parent.mkdir()
    capture.write_text(json.dumps({'events': [
        {'kind': 'human-camera', 'time_ms': 5, 'updates': 1, 'camera': {'x': 1}},
        # A move after the update's time but still at that update comes after the cut.
        {'kind': 'human-camera', 'time_ms': 12, 'updates': 1, 'camera': {'x': 2}}]}))
    recording = {'duration_ms': 100, 'events': [{'time_ms': 1}, {'time_ms': 2}, {'time_ms': 3}],
                 'source_report': str(capture),
                 'update_trace': [{'updates': 1, 'time_ms': 10, 'exit_time': 40},
                                  {'updates': 2, 'time_ms': 20, 'exit_time': 80}],
                 'message_recording': {'records': 6, 'sha256': hashlib.sha256(messages).hexdigest()},
                 'oracle': {'rng_records': 5, 'rng_sha256': 'full', 'rng_sites': {}, 'updates': 3,
                            'update_rng': [[2, 'a'], [5, 'b'], [5, 'c']], 'inputs': 3,
                            'world': {'time': 90, 'objects': 7}, 'camera': {'x': 3}, 'alloc': None}}
    folder = traces / 'full'
    folder.mkdir(parents=True)
    stored = lzma.compress(json.dumps(recording).encode())
    stored_messages = lzma.compress(messages)
    (folder / 'recording.json.xz').write_bytes(stored)
    (folder / 'messages.bin.xz').write_bytes(stored_messages)
    registry.write_text(json.dumps({'schema': 1, 'cases': {'full': {
        'recording_sha256': hashlib.sha256(stored).hexdigest(),
        'messages_sha256': hashlib.sha256(stored_messages).hexdigest(), 'duration_ms': 100}}}))
    row = trace_suite.cut_trace('full', 'part', 1)
    assert row['updates'] == 1 and row['inputs'] == 1 and row['rng_records'] == 2 and row['cut_from'] == 'full'
    assert set(trace_suite.check_fixtures()) == {'full', 'part'}
    cut = json.loads(lzma.decompress((traces / 'part/recording.json.xz').read_bytes()))
    kept = lzma.decompress((traces / 'part/messages.bin.xz').read_bytes())
    assert kept == messages[:2 * 80] and cut['message_recording']['records'] == 2
    assert cut['events'] == recording['events'][:1] and len(cut['update_trace']) == 1
    assert cut['oracle'] == {'rng_records': 2, 'rng_sites': {}, 'update_rng': [[2, 'a']], 'updates': 1,
                             'inputs': 1, 'world': {'time': 40}, 'alloc': None, 'camera': {'x': 1}}
    with pytest.raises(ValueError, match='Choose an update'):
        trace_suite.cut_trace('full', 'late', 3)


def test_a_cut_oracle_checks_only_what_it_knows():
    cut = {'rng_records': 3, 'updates': 2, 'inputs': 1, 'world': {'time': 1}, 'update_rng': [[1, 'x'], [3, 'y']]}
    run = dict(oracle(), errors=[], camera={'x': 9})
    result = trace_suite.compare(cut, run)
    assert result['passed'] is True and 'rng_sha256' not in result['checks'] and 'camera' not in result['checks']
    assert trace_suite.compare(cut, dict(run, world={'time': 2, 'objects': 2}))['checks']['world'] is False
