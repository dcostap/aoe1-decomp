"""Check the standard controlled-input recipe without launching games."""
import copy
import json
from pathlib import Path
import sys

sys.path.insert(0,str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import parity_suite as suite
from human_session import V1_TO_V4_UPGRADE, execution_plan


def test_both_permanent_recordings_are_pinned():
    records = suite.controlled_recordings()
    assert [len(records[name]['events']) for name in ('accepted','candidate')] == [324,1361]


def test_controlled_suite_runs_all_cases_after_script_failure(tmp_path,monkeypatch):
    calls = []
    def runner(command,log,timeout,visible):
        calls.append(command)
        output = Path(command[command.index('--output')+1])
        output.mkdir()
        (output/'report.json').write_text(json.dumps({'complete':True,'passed':False}))
        return 1 if len(calls)==1 else 0
    monkeypatch.setattr(suite,'controlled_result',lambda *args:{'complete':True,'passed':True})
    result = suite.run_suite(tmp_path/'suite',runner)
    assert result['complete'] and not result['passed']
    assert len(calls)==8
    assert set(result['human']) == {'accepted','candidate','late-game-match'}
    for command in calls[1:7]:
        assert '--observe' in command and '--combat' in command and '--controlled' in command
        assert '--rng-only' not in command and '--upgrade-v1-to-v4' not in command
        assert command[command.index('--runs')+1] == '3'
    assert calls[7][1].endswith('feature_lab.py') and calls[7][2] == 'test-all'


def mock_captures(recording):
    scenario = {'schema':1,'mode':'replay',**{k:copy.deepcopy(recording[k]) for k in ('duration_ms','events','contract')},
        'observe':True,'combat':True,'upgrade_rule':V1_TO_V4_UPGRADE,
        'recording_sha256':suite.RECORDING_SHA256}
    control = execution_plan(scenario)
    events = [{**row,'kind':'human-input','time_ms':row['time_ms']+20,'updates':row['updates']+1} for row in recording['events']]
    return [{'report':{'fixture':{'human':copy.deepcopy(scenario)},'events':copy.deepcopy(events),
                       'script_sha256':control['executed_script_sha256'],
                       'human_control':copy.deepcopy(control)}} for _ in range(3)]


def test_old_clock_and_update_fidelity_stays_visible_but_is_not_the_new_profile_oracle(monkeypatch):
    recording = suite.accepted_recording()
    monkeypatch.setattr(suite,'load_batch',lambda *args:mock_captures(recording))
    monkeypatch.setattr(suite,'compare_repeatability',lambda *args:{'passed':True})
    result = suite.controlled_result(Path('a'),Path('b'),recording,suite.RECORDING_SHA256)
    assert result['passed'] and len(result['pairs'])==15
    assert all(not row['exact_boundaries'] for row in result['recording_fidelity'])
    assert all(not row['same_game_boundaries'] for row in result['recording_fidelity'])


def test_new_cross_run_clock_failure_still_fails(monkeypatch):
    recording = suite.accepted_recording()
    monkeypatch.setattr(suite,'load_batch',lambda *args:mock_captures(recording))
    monkeypatch.setattr(suite,'compare_repeatability',lambda *args:{'passed':False})
    assert not suite.controlled_result(Path('a'),Path('b'),recording,suite.RECORDING_SHA256)['passed']


def test_controlled_case_rejects_missing_explicit_upgrade(monkeypatch):
    recording = suite.accepted_recording()
    captures = mock_captures(recording)
    captures[0]['report']['human_control']['upgrade_rule'] = None
    monkeypatch.setattr(suite,'load_batch',lambda *args:captures)
    result = suite.controlled_result(Path('a'),Path('b'),recording,suite.RECORDING_SHA256)
    assert not result['passed'] and not result['complete']
