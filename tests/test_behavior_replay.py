import copy
import hashlib
import json
from pathlib import Path
import sys
import struct

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/harness'))
from behavior import first_difference, validate_replay
from replay import batch_classification, compare_reports, first_rng_difference


def scenario():
    return json.loads((ROOT / 'config/harness/replay-random-smoke.json').read_text())


def report():
    state = {'kind':'behavior-state', 'probe':'world_new', 'phase':'leave', 'ordinal':1,
             'input':3, 'updates':0, 'fields':{'objects':{'value':5, 'bytes':[5,0,0,0]}},
             'receiver':'0x1000', 'stack':[], 'rng_count':20, 'rng_sha256':'same'}
    return {'fixture':scenario(), 'clock':'calls', 'script_sha256':'same', 'registry_inputs':{},
            'arguments':[], 'frida_version':'test', 'manifest':{}, 'shared_assets_unchanged':True,
            'errors':[], 'events':[state, {'kind':'replay-done'}]}


def test_default_replay_is_valid_and_contains_camera_input():
    value = scenario()
    validate_replay(value)
    assert any(step.get('after_updates', 0) > 0 for step in value['steps'])


@pytest.mark.parametrize('change', [
    lambda x:x.update(replay=None),
    lambda x:x.update(replay={}),
    lambda x:x.update(ui=False),
    lambda x:x['replay'].update(updates=0),
    lambda x:x['replay'].update(updates=True),
    lambda x:x['replay'].update(update_probe='missing'),
    lambda x:x['replay']['probes'][0].update(module='../world'),
    lambda x:x['replay']['probes'][0].update(phase='middle'),
    lambda x:x['replay']['probes'][0].update(fields={'field':[0,'pointer']}),
    lambda x:x['replay']['probes'][0].update(fields={'field':[-1,'u32']}),
    lambda x:x['replay']['probes'][0].update(fields={'field':3}),
    lambda x:x['steps'][0].update(before=None),
    lambda x:x['steps'][0].update(after_updates=100000),
])
def test_replay_rejects_invalid_descriptions(change):
    value = scenario()
    change(value)
    with pytest.raises(ValueError):
        validate_replay(value)


def test_addresses_are_diagnostics_not_object_identity():
    a, b = report(), report()
    b['events'][0]['receiver'] = '0x2000'
    b['events'][0]['stack'] = [{'address':'0x345'}]
    assert compare_reports(a, b)['passed']


def test_changed_field_reports_both_values_and_stack():
    a, b = report(), report()
    b['events'][0]['fields']['objects'] = {'value':8, 'bytes':[8,0,0,0]}
    value = compare_reports(a, b)
    assert value['classification'] == 'state-divergence'
    assert value['first_difference']['fields'][0]['field'] == 'objects'
    assert 'stack' in value['first_difference']['right']


def test_equal_display_values_do_not_hide_raw_byte_differences():
    a, b = report(), report()
    b['events'][0]['fields']['objects']['bytes'][-1] = 128
    assert first_difference(a, b)['reason'] == 'fields'


@pytest.mark.parametrize('field', ['clock', 'script_sha256', 'registry_inputs', 'frida_version'])
def test_incompatible_capture_contracts_fail(field):
    a, b = report(), report()
    b[field] = 'different'
    assert compare_reports(a, b)['classification'] == 'incompatible'


def test_empty_and_failed_captures_cannot_pass():
    a, b = report(), report()
    b['events'] = []
    assert not compare_reports(a, b)['passed']
    b = report()
    b['errors'] = [{'error':'timeout'}]
    assert not compare_reports(a, b)['passed']


def test_rng_prefix_change_is_not_hidden_by_equal_fields():
    a, b = report(), report()
    b['events'][0]['rng_sha256'] = 'different'
    assert first_difference(a, b)['reason'] == 'rng_sha256'


def test_missing_observation_is_a_difference():
    a, b = report(), report()
    b['events'].insert(0, copy.deepcopy(b['events'][0]))
    assert first_difference(a, b)['reason'] == 'observation count differs'


def rng_report(directory, values, filename='world.cpp'):
    directory.mkdir()
    data = b''.join(struct.pack('<II', 0, value) for value in values)
    (directory/'rng.bin').write_bytes(data)
    path = directory/'report.json'
    path.write_text(json.dumps({'rng_recording':{
        'file':'rng.bin', 'records':len(values), 'sha256':hashlib.sha256(data).hexdigest(),
        'sites':{'0':{'kind':'rand', 'file':filename, 'line':42}}}}))
    return path


def test_rng_binary_reports_first_changed_value(tmp_path):
    a = rng_report(tmp_path/'a', [1,2,3])
    b = rng_report(tmp_path/'b', [1,9,3])
    difference = first_rng_difference(a, b)
    assert difference['index'] == 1
    assert difference['left']['value'] == 2
    assert difference['right']['value'] == 9


def test_rng_binary_equal_values_do_not_hide_site_changes(tmp_path):
    a = rng_report(tmp_path/'a', [1,2,3])
    b = rng_report(tmp_path/'b', [1,2,3], 'other.cpp')
    assert first_rng_difference(a, b)['index'] == 0


def test_rng_binary_detects_truncation_and_tampering(tmp_path):
    a = rng_report(tmp_path/'a', [1,2,3])
    b = rng_report(tmp_path/'b', [1,2])
    assert first_rng_difference(a, b)['index'] == 2
    (b.parent/'rng.bin').write_bytes(b'bad')
    assert 'error' in first_rng_difference(a, b)


def test_rng_binary_equal_sequences_pass(tmp_path):
    a = rng_report(tmp_path/'a', [1,2,3])
    b = rng_report(tmp_path/'b', [1,2,3])
    assert first_rng_difference(a, b) is None


def test_asset_differences_reject_comparison():
    a, b = report(), report()
    b['manifest']['copied_files_before_exe_replacement'] = [{'path':'data.dat', 'sha256':'changed'}]
    assert compare_reports(a, b)['reason'] == 'assets'


def test_unused_save_files_do_not_reject_new_game_comparison():
    from replay import gameplay_assets
    a, b = report(), report()
    b['manifest']['copied_files_before_exe_replacement'] = [
        {'path':'savegame/imported.gmx', 'sha256':'different'},
        {'path':'SAVEGAME\\old.gam', 'sha256':'different'}]
    assert compare_reports(a, b) == compare_reports(a, a)
    assert gameplay_assets({'savegame/rules.dat':'keep', 'data/test.gmx':'keep'}) == {
        'savegame/rules.dat':'keep', 'data/test.gmx':'keep'}


def test_input_update_timing_is_compared():
    a, b = report(), report()
    message = {'kind':'ui-input-consumed', 'step':1, 'message':512, 'value':0, 'parameter':5, 'updates':15}
    a['events'].append(message)
    b['events'].append(dict(message, updates=16))
    assert compare_reports(a, b)['classification'] == 'input-divergence'


@pytest.mark.parametrize('original,rebuilt,expected', [
    (True, True, 'state-divergence'),
    (False, True, 'original-not-repeatable'),
    (True, False, 'rebuilt-not-repeatable'),
    (False, False, 'both-not-repeatable'),
])
def test_each_executable_gets_its_own_variation_result(original, rebuilt, expected):
    def group(passed):
        return {'passed':passed, 'comparisons':[{'passed':passed, 'classification':'state-divergence'}]}
    assert batch_classification(group(original), group(rebuilt), {'classification':'state-divergence'}) == expected


def test_incomplete_run_is_not_called_game_variation():
    a = {'passed':False, 'comparisons':[{'passed':False, 'classification':'incomplete'}]}
    b = {'passed':True, 'comparisons':[{'passed':True, 'classification':'observed-match'}]}
    assert batch_classification(a, b, {'classification':'state-divergence'}) == 'incomplete-or-incompatible'
