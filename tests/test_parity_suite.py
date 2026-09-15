import json
import copy
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import parity_suite as suite


def test_permanent_recording_is_the_unchanged_accepted_input():
    recording = suite.accepted_recording()
    assert len(recording['events']) == 324
    assert recording['automated_smoke'] is False
    assert recording['contract']['policy'] == 'human-idle20-clock1-paced-v1-message-driven-polling'
    assert recording['contract']['script_sha256'] == '6312fbd5ebb7d82dd91abe775e8c4c15c538743f276dba03ab61bbb8a1043db4'


def test_changed_recording_is_rejected(tmp_path):
    path = tmp_path / 'recording.json'
    path.write_bytes(suite.RECORDING.read_bytes() + b' ')
    with pytest.raises(ValueError, match='changed'):
        suite.accepted_recording(path)


def matching_comparison():
    row = {name: {'equal': True} for name in
           ('camera_values', 'camera_receipts', 'terminal_world', 'rng_prefix', 'full_rng', 'video_samples')}
    row.update(inputs={'same_messages': True, 'same_game_boundaries': True, 'exact_boundaries': True},
               terminal_boundaries=[{'updates': 331}, {'updates': 331}], rng_trace_complete=[True, True],
               rng_total_counts=[100, 100], observer_sha256=['same', 'same'])
    return row


@pytest.mark.parametrize('field', ['input_clock_boundaries', 'terminal_boundaries', 'full_rng', 'video_rgb', 'observer_identity'])
def test_no_timing_pixel_or_incomplete_rng_exceptions(field):
    row = matching_comparison()
    assert all(suite.comparison_checks(row).values())
    if field == 'input_clock_boundaries':
        row['inputs']['exact_boundaries'] = False
    elif field == 'terminal_boundaries':
        row['terminal_boundaries'][1]['updates'] = 330
    elif field == 'full_rng':
        row['full_rng'] = None
        row['rng_trace_complete'] = [False, False]
    elif field == 'video_rgb':
        row['video_samples']['equal'] = False
    else:
        row['observer_sha256'][1] = 'different'
    assert suite.comparison_checks(row)[field] is False


def test_standard_suite_runs_human_case_after_scripted_failure(tmp_path, monkeypatch):
    commands = []
    def runner(command, log, timeout, visible):
        commands.append(command)
        output = Path(command[command.index('--output') + 1])
        output.mkdir()
        (output / 'report.json').write_text(json.dumps({'passed': False}))
        assert timeout > 0 and visible is False
        return 1 if len(commands) == 1 else 0
    monkeypatch.setattr(suite, 'human_result', lambda *args: {'complete': True, 'passed': True})
    result = suite.run_legacy_suite(tmp_path / 'run', runner)
    assert len(commands) == 3
    for command, target in zip(commands[1:], ('original', 'rebuilt')):
        assert command[command.index('--target') + 1] == target
        assert command[command.index('--recording') + 1] == str(suite.RECORDING)
        assert '--observe' in command and '--rng-only' in command
        assert '--upgrade-v1-to-v2' not in command
        assert command[command.index('--runs') + 1] == '3'
    assert result['complete'] is True and result['passed'] is False


def test_missing_capture_cannot_pass(tmp_path):
    result = suite.human_result(tmp_path / 'missing', tmp_path / 'missing2', suite.accepted_recording())
    assert result['complete'] is False and result['passed'] is False


@pytest.mark.parametrize('change', [None, 'clock', 'recording', 'observer', 'upgrade'])
def test_human_case_checks_recording_fidelity_and_observer(monkeypatch, change):
    recording = suite.accepted_recording()
    session = {key: copy.deepcopy(recording[key]) for key in ('duration_ms', 'events', 'contract')}
    session.update(observe=True, rng_only=True, combat=False)
    control={'recorded_policy':recording['contract']['policy'],
             'recorded_script_sha256':recording['contract']['script_sha256'],
             'executed_policy':recording['contract']['policy'],
             'executed_script_sha256':recording['contract']['script_sha256'],
             'upgrade_rule':None,'recording_sha256':suite.RECORDING_SHA256,'same_policy_replay':True}
    capture = {'report': {'fixture': {'human': session},
                          'script_sha256':recording['contract']['script_sha256'],
                          'human_control':control,
                          'events': [dict(event, kind='human-input') for event in recording['events']]}}
    captures = [copy.deepcopy(capture) for _ in range(6)]
    if change == 'clock':
        captures[0]['report']['events'][0]['time_ms'] += 20
    elif change == 'recording':
        captures[0]['report']['fixture']['human']['duration_ms'] += 1
    elif change == 'observer':
        captures[0]['report']['fixture']['human']['rng_only'] = False
    elif change == 'upgrade':
        captures[0]['report']['human_control'].update(
            executed_policy='human-idle20-clock1-paced-v2-serialized-message-driven-polling',
            upgrade_rule='v1-to-v2-serialized-dispatch-20260915',same_policy_replay=False)
    monkeypatch.setattr(suite, 'load_batch', lambda path, original: captures[:3] if original else captures[3:])
    monkeypatch.setattr(suite, 'compare_captures', lambda *args: matching_comparison())
    result = suite.human_result(Path('original'), Path('rebuilt'), recording)
    assert result['passed'] is (change is None)
    if change == 'clock':
        assert result['complete'] is True
        assert result['recording_fidelity'][0]['delivery_differences'][0]['time_delta_ms'] == 20


def test_fixture_failure_starts_no_games(tmp_path, monkeypatch):
    def reject():
        raise ValueError('changed fixture')
    monkeypatch.setattr(suite, 'accepted_recording', reject)
    result = suite.run_legacy_suite(tmp_path / 'run', lambda *args: pytest.fail('Started a game'))
    assert result['passed'] is False and result['workers'] == []


def test_game_command_routes_to_standard_suite(monkeypatch):
    import game
    monkeypatch.setattr(sys, 'argv', ['game.py', 'test-parity'])
    calls = []
    def run(command, **kwargs):
        calls.append(command)
        return type('Result', (), {'returncode': 1})()
    monkeypatch.setattr(game.subprocess, 'run', run)
    assert game.main() == 1
    assert calls[0][1].endswith('parity_suite.py')
