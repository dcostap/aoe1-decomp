"""Check that repeatability requires complete evidence and exact agreement."""
import copy
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import human_repeatability as repeatability


def capture():
    world = {'kind':'observer-world','time':0,'delta':0,'old_time':0,'speed':1,
             'registrations':1,'rng_count':1,'turn':1,'time_ms':20,'clock_counts':{'calls':0,'idle':1}}
    return {'report':{'observer_sha256':'observer','fixture':{'human':{
        'events':[], 'observe':True,'combat':True}},
        'status':{'count':1,'human':{'input':0,'posted':0,'dropped':0,'updates':1}},
        'events':[{**world,'phase':'enter','updates':0}, {**world,'phase':'leave','updates':1}]}}


def comparison():
    return {'full_rng':{'equal':True}, 'inputs':{'exact_boundaries':True,'same_messages':True},
            'camera_values':{'equal':True}, 'camera_receipts':{'equal':True},
            'terminal_boundaries':[{},{}], 'terminal_world':{'equal':True}, 'video_samples':{'equal':True}}


def test_exact_complete_observations_pass(monkeypatch):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    assert repeatability.compare(capture(),capture())['passed']


@pytest.mark.parametrize('change', ['missing_world','missing_exit','missing_field','bad_phase','bad_counter','dropped','posted'])
def test_incomplete_evidence_fails_even_if_both_reports_agree(monkeypatch, change):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    a = capture()
    report = a['report']
    if change == 'missing_world': report['events'] = []
    elif change == 'missing_exit': report['events'].pop()
    elif change == 'missing_field': del report['events'][0]['delta']
    elif change == 'bad_phase': report['events'][0]['phase'] = 'leave'
    elif change == 'bad_counter': report['events'][1]['updates'] = 0
    elif change == 'dropped': report['status']['human']['dropped'] = 1
    elif change == 'posted': report['status']['human']['posted'] = 1
    assert not repeatability.compare(a,copy.deepcopy(a))['passed']


@pytest.mark.parametrize('field', ['full_rng','video_samples','camera_values','camera_receipts','terminal_world','inputs'])
def test_a_difference_cannot_pass(monkeypatch,field):
    result = comparison()
    if field == 'inputs': result[field]['exact_boundaries'] = False
    else: result[field]['equal'] = False
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:result)
    assert not repeatability.compare(capture(),capture())['passed']


def test_equal_rng_cannot_hide_a_state_difference(monkeypatch):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    a,b = capture(),capture()
    b['report']['events'][1]['delta'] = 13
    assert not repeatability.compare(a,b)['passed']


def test_rng_prefix_is_not_complete_rng_evidence(monkeypatch):
    result = comparison()
    result['full_rng'] = None
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:result)
    assert not repeatability.compare(capture(),capture())['passed']


def test_observer_mode_changes_are_not_repeatability(monkeypatch):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    a,b = capture(),capture()
    b['report']['fixture']['human']['combat'] = False
    with pytest.raises(ValueError,match='same observer mode'):
        repeatability.compare(a,b)


def test_identically_late_inputs_still_fail(monkeypatch):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    a=capture()
    event={'message':512,'value':0,'parameter':0,'route':[],'panel':'Game Screen',
           'turn':1,'updates':0,'time_ms':20}
    a['report']['fixture']['human']['events']=[event]
    a['report']['events'].append({**event,'kind':'human-input','turn':2})
    a['report']['status']['human'].update(input=1,posted=1)
    assert not repeatability.compare(a,copy.deepcopy(a))['passed']


def perturbed_capture():
    a=capture()
    a['report']['fixture']['human']['message_noise']=True
    a['report']['noise_sha256']=repeatability.NOISE_SHA256
    a['report']['events'] += [
        {'kind':'control-noise-ready','version':2,'period_ms':37,'messages':[0x113,0xf]},
        {'kind':'control-noise-summary','version':2,'period_ms':37,'batches':10,'suppressed_dispatches':{'timer':9,'paint':9}}]
    return a


def test_noise_resistance_needs_explicit_mode(monkeypatch):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    with pytest.raises(ValueError,match='perturbation'):
        repeatability.compare(capture(),perturbed_capture())
    result=repeatability.compare(capture(),perturbed_capture(),noise_resistance=True)
    assert result['passed'] and result['comparison_mode']=='noise-resistance'


def test_noise_resistance_does_not_relax_output_checks(monkeypatch):
    result=comparison()
    result['video_samples']['equal']=False
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:result)
    assert not repeatability.compare(capture(),perturbed_capture(),noise_resistance=True)['passed']


def test_requested_noise_needs_positive_stimulus_evidence(monkeypatch):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    a=perturbed_capture()
    a['report']['events'][-1]['batches']=0
    assert not repeatability.compare(a,copy.deepcopy(a))['passed']


@pytest.mark.parametrize('defect',['hash','timer','paint'])
def test_noise_needs_known_code_and_both_dispatch_receipts(monkeypatch,defect):
    monkeypatch.setattr(repeatability,'compare_captures',lambda a,b:comparison())
    a=perturbed_capture()
    if defect=='hash': a['report']['noise_sha256']='b'*64
    else: a['report']['events'][-1]['suppressed_dispatches'][defect]=0
    assert not repeatability.compare(a,copy.deepcopy(a))['passed']


def test_all_noisy_is_not_a_quiet_noisy_comparison(monkeypatch,tmp_path):
    a=perturbed_capture()
    a['path']='capture'
    monkeypatch.setattr(repeatability,'load_capture',lambda path:a)
    monkeypatch.chdir(tmp_path)
    monkeypatch.setattr(sys,'argv',['human_repeatability.py','a','b','--noise-resistance','--output','build/report.json'])
    assert repeatability.main()==1
