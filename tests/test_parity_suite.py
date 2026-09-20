import json
import copy
from pathlib import Path
import sys
import threading
import time

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import parity_suite as suite


def test_independent_suite_workers_run_in_parallel(tmp_path):
    commands = [(f'worker-{index}', [f'worker-{index}'], 10) for index in range(3)]
    barrier = threading.Barrier(3)
    lock = threading.Lock()
    active = 0
    peak = 0

    def runner(command, log, timeout, visible):
        nonlocal active, peak
        with lock:
            active += 1
            peak = max(peak, active)
        barrier.wait(timeout=2)
        time.sleep(0.03)
        with lock:
            active -= 1
        return 0

    rows = suite.run_commands(commands, tmp_path, runner, jobs=3)
    assert peak == 3
    assert [row['name'] for row in rows] == ['worker-0', 'worker-1', 'worker-2']
    assert all(row['returncode'] == 0 for row in rows)


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


def test_default_fixtures_include_the_pinned_saved_game():
    recordings = suite.controlled_recordings()
    assert set(recordings) == {'accepted', 'candidate', 'late-game-match'}
    recording = recordings['late-game-match']
    assert len(recording['events']) == 559
    assert recording['policy'] == suite.V5_POLICY
    assert recording['contract']['assets']['savegame/late_game_match.gmx'] == (
        'fccd0ca0ccd98a6658a1eeb3b306c89afee3af9caf58ab518ee04eae434687f4')


def test_editor_fixture_is_pinned_and_observer_free():
    recording = suite.editor_recording()
    assert len(recording['events']) == 3729
    assert recording['policy'] == suite.V7_POLICY
    assert recording['contract']['script_sha256'] == suite.V7_TEMPLATE_SHA256
    assert recording['automated_smoke'] is False


def test_responsive_editor_fixture_is_pinned():
    recording = suite.responsive_editor_recording()
    assert len(recording['events']) == 91284
    assert recording['policy'] == suite.V10_POLICY
    assert recording['contract']['script_sha256'] == suite.V10_TEMPLATE_SHA256
    assert recording['automated_smoke'] is False


def test_editor_comparison_checks_only_its_declared_outputs():
    row = matching_comparison()
    checks = suite.editor_comparison_checks(row)
    assert set(checks) == {'input_messages', 'game_input_boundaries', 'camera_values',
                           'camera_receipts', 'video_rgb'}
    assert all(checks.values())
    row['terminal_world']['equal'] = False
    row['rng_prefix']['equal'] = False
    row['observer_sha256'] = [None, None]
    assert all(suite.editor_comparison_checks(row).values())


@pytest.mark.parametrize('failure', [None, 'scripted', 'late-game-match-original', 'late-game-match-rebuilt', 'native-features'])
def test_default_suite_runs_every_case_and_keeps_failures(tmp_path, monkeypatch, failure):
    commands = []
    def runner(command, log, timeout, visible):
        commands.append(command)
        output = Path(command[command.index('--output') + 1])
        output.mkdir()
        passed = output.name != failure
        (output / 'report.json').write_text(json.dumps({'complete': True, 'passed': passed}))
        assert timeout > 0 and visible is False
        return 0 if passed else 1
    monkeypatch.setattr(suite, 'controlled_result', lambda *args: {'complete': True, 'passed': True})
    monkeypatch.setattr(suite, 'responsive_editor_result', lambda *args: {'complete': True, 'passed': True})
    result = suite.run_suite(tmp_path / 'run', runner)
    assert len(commands) == 10
    assert set(result['human']) == {'accepted', 'candidate', 'late-game-match'}
    expected = [(path, target) for _,path,_,_ in suite.CONTROLLED_CASES for target in ('original', 'rebuilt')]
    for command, (path, target) in zip(commands[1:7], expected):
        assert command[command.index('--recording') + 1] == str(path)
        assert command[command.index('--target') + 1] == target
        assert command[command.index('--runs') + 1] == '3'
        assert all(flag in command for flag in ('--controlled', '--observe', '--combat'))
        assert '--upgrade-v1-to-v4' not in command and '--rng-only' not in command
    for command,target in zip(commands[7:9],('original','rebuilt')):
        assert command[command.index('--recording') + 1] == str(suite.RESPONSIVE_EDITOR_RECORDING)
        assert command[command.index('--target') + 1] == target
        assert command[command.index('--runs') + 1] == '3'
        assert '--controlled' in command and '--observe' not in command
    assert commands[-1][1].endswith('feature_lab.py') and commands[-1][2] == 'test-all'
    assert commands[-1][commands[-1].index('--runs') + 1] == '3'
    assert commands[-1][commands[-1].index('--jobs') + 1] == '3'
    assert result['complete'] is True
    assert result['passed'] is (failure is None)


def test_editor_option_adds_two_unobserved_workers(tmp_path, monkeypatch):
    commands = []
    def runner(command, log, timeout, visible):
        commands.append(command)
        output = Path(command[command.index('--output') + 1])
        output.mkdir()
        (output / 'report.json').write_text(json.dumps({'complete': True, 'passed': True}))
        return 0
    monkeypatch.setattr(suite, 'controlled_result', lambda *args: {'complete': True, 'passed': True})
    monkeypatch.setattr(suite, 'responsive_editor_result', lambda *args: {'complete': True, 'passed': True})
    monkeypatch.setattr(suite, 'editor_result', lambda *args: {'complete': True, 'passed': True})
    result = suite.run_suite(tmp_path / 'run', runner, include_editor=True)
    assert len(commands) == 12
    assert [command[command.index('--output') + 1] for command in commands[-3:-1]] == [
        str(tmp_path / 'run/editor-original'), str(tmp_path / 'run/editor-rebuilt')]
    assert all('--observe' not in command and '--combat' not in command
               for command in commands[-3:-1])
    assert result['complete'] is True and result['passed'] is True


def test_native_fixture_failure_starts_no_suite_games(tmp_path, monkeypatch):
    def reject():
        raise ValueError('Changed native save fixture')
    monkeypatch.setattr(suite, 'feature_fixtures', reject)
    result = suite.run_suite(tmp_path / 'run', lambda *args: pytest.fail('Started a game'))
    assert result['passed'] is False and result['workers'] == []


def test_all_native_fixtures_are_permanent():
    fixtures = suite.feature_fixtures()
    assert set(fixtures) == {'civilizations-1-8', 'civilizations-9-16', 'chaos-battle'}
    assert {row['generator']['civilization_offset'] for row in fixtures.values()} == {0, 8}
    assert fixtures['chaos-battle']['layout'] == 'chaos'


def test_changed_saved_recording_starts_no_games(tmp_path, monkeypatch):
    name, original, sha, count = suite.CONTROLLED_CASES[-1]
    changed = tmp_path / 'changed.json'
    changed.write_bytes(original.read_bytes() + b' ')
    monkeypatch.setattr(suite, 'CONTROLLED_CASES', ((name, changed, sha, count),))
    result = suite.run_suite(tmp_path / 'run', lambda *args: pytest.fail('Started a game'))
    assert result['passed'] is False and result['workers'] == []
    assert 'recording changed' in result['error']


def test_changed_save_set_starts_no_games(tmp_path, monkeypatch):
    monkeypatch.setattr(suite, 'save_fixtures', lambda: [])
    result = suite.run_suite(tmp_path / 'run', lambda *args: pytest.fail('Started a game'))
    assert result['passed'] is False and result['workers'] == []
    assert 'save fixtures differ' in result['error']


@pytest.mark.parametrize('case', ['accepted', 'late-game-match'])
@pytest.mark.parametrize('change', [None, 'profile', 'upgrade', 'same_policy', 'recording', 'script', 'observer', 'save', 'pair'])
def test_controlled_case_requires_its_profile_and_all_pairs(monkeypatch, case, change):
    import human_session as human
    name, path, sha, count = next(row for row in suite.CONTROLLED_CASES if row[0] == case)
    recording = suite.controlled_recordings()[name]
    session = {key: copy.deepcopy(recording[key]) for key in ('duration_ms', 'events', 'contract')}
    session.update(schema=1, mode='replay', observe=True, combat=True, recording_sha256=sha,
                   upgrade_rule=human.V5_TO_V6_UPGRADE if case == 'late-game-match' else human.V1_TO_V4_UPGRADE)
    control = human.execution_plan(session)
    assert control['executed_policy'] == (human.V6_POLICY if case == 'late-game-match' else human.V4_POLICY)
    capture = {'report': {'fixture': {'human': session}, 'human_control': control,
        'script_sha256': control['executed_script_sha256'],
        'events': [dict(event, kind='human-input') for event in recording['events']]}}
    captures = [copy.deepcopy(capture) for _ in range(6)]
    report = captures[0]['report']
    if change == 'profile':
        report['human_control']['executed_policy'] = 'wrong-profile'
    elif change == 'upgrade':
        report['human_control']['upgrade_rule'] = None
    elif change == 'same_policy':
        report['human_control']['same_policy_replay'] = 0
    elif change == 'recording':
        report['human_control']['recording_sha256'] = '0' * 64
    elif change == 'script':
        report['script_sha256'] = '0' * 64
    elif change == 'observer':
        report['fixture']['human']['combat'] = False
    elif change == 'save':
        report['fixture']['human']['contract']['assets']['savegame/late_game_match.gmx'] = 'changed'
    pairs = []
    def compare(left, right):
        pairs.append((left, right))
        return {'passed': not (change == 'pair' and len(pairs) == 15)}
    monkeypatch.setattr(suite, 'load_batch', lambda path, original: captures[:3] if original else captures[3:])
    monkeypatch.setattr(suite, 'compare_repeatability', compare)
    result = suite.controlled_result(Path('original'), Path('rebuilt'), recording, sha)
    assert result['passed'] is (change is None)
    assert len(pairs) == (15 if change in (None, 'pair') else 0)
