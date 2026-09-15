import copy
import hashlib
import io
import json
from pathlib import Path
import sys

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/harness'))
import human_session as human_session_module
from human_session import (validate_session, compare_inputs, execution_plan, load_recording,
                           load_recording_with_sha256, verify_starting_contract,
                           template_sha256, ORIGINAL_SHA256, POLICY, V1_POLICY, V2_POLICY,
                           V1_TEMPLATE_SHA256, V2_TEMPLATE_SHA256, V1_TO_V2_UPGRADE)


def event():
    return {'time_ms':100,'turn':3,'updates':0,'panel':'Main Menu','route':[],
            'message':0x201,'value':1,'parameter':100}


def session():
    return {'schema':1,'mode':'replay','duration_ms':1000,'events':[event()],
            'contract':{'original_sha256':ORIGINAL_SHA256,'policy':POLICY,
                        'script_sha256':template_sha256(POLICY)}}


def test_valid_record_and_replay():
    validate_session(session())
    validate_session({'schema':1,'mode':'record','duration_ms':1000})


def test_frozen_v1_and_current_v2_template_hashes():
    harness = ROOT/'tools/harness'
    legacy = (harness/'human-v1-template.js').read_bytes()
    current = '\n'.join((harness/name).read_text() for name in ('menu.js','offline.js','human.js')).encode()
    assert hashlib.sha256(legacy).hexdigest() == V1_TEMPLATE_SHA256
    assert hashlib.sha256(current).hexdigest() == V2_TEMPLATE_SHA256


def test_preserved_candidate_recording_and_explicit_upgrade_plan():
    path=ROOT/'config/harness/human-candidate-20260915.json'
    recording,source_sha256=load_recording_with_sha256(path)
    assert source_sha256 == '60c04e651b19d144cd033ffcc5ed2bdff1bfe75629b036f493d8db497e4b832e'
    assert recording['policy'] == V1_POLICY and len(recording['events']) == 1361
    data={'schema':1,'mode':'replay','duration_ms':recording['duration_ms'],'events':recording['events'],
          'contract':recording['contract'],'recording_sha256':source_sha256,
          'upgrade_rule':V1_TO_V2_UPGRADE}
    before=copy.deepcopy(data['contract']),copy.deepcopy(data['events'])
    plan=execution_plan(data)
    assert plan == {'recorded_policy':V1_POLICY,'recorded_script_sha256':V1_TEMPLATE_SHA256,
                    'executed_policy':V2_POLICY,'executed_script_sha256':V2_TEMPLATE_SHA256,
                    'upgrade_rule':V1_TO_V2_UPGRADE,'recording_sha256':data['recording_sha256'],
                    'same_policy_replay':False}
    assert (data['contract'],data['events']) == before


def test_upgrade_verifies_complete_recorded_starting_contract():
    path=ROOT/'config/harness/human-candidate-20260915.json'
    recording=load_recording(path)
    contract=recording['contract']
    session={'schema':1,'mode':'replay','duration_ms':recording['duration_ms'],'events':recording['events'],
             'contract':contract,'recording_sha256':hashlib.sha256(path.read_bytes()).hexdigest(),
             'upgrade_rule':V1_TO_V2_UPGRADE}
    report={'clock':contract['clock'],'registry_inputs':copy.deepcopy(contract['registry_inputs']),
            'arguments':copy.deepcopy(contract['arguments']),'frida_version':contract['frida_version'],
            'manifest':{'copied_files_before_exe_replacement':[
                {'path':name,'sha256':value} for name,value in contract['assets'].items()],
                **copy.deepcopy(contract['graphics'])}}
    assert verify_starting_contract(session,report)['same_policy_replay'] is False
    for field in ('clock','registry_inputs','arguments','frida_version'):
        changed=copy.deepcopy(report)
        changed[field]=None
        with pytest.raises(ValueError,match='starting contract differs'):
            verify_starting_contract(session,changed)
    changed=copy.deepcopy(report)
    changed['manifest']['copied_files_before_exe_replacement'][0]['sha256']='changed'
    with pytest.raises(ValueError,match='starting contract differs'):
        verify_starting_contract(session,changed)
    changed=copy.deepcopy(report)
    changed['manifest']['graphics_sha256']='changed'
    with pytest.raises(ValueError,match='starting contract differs'):
        verify_starting_contract(session,changed)


@pytest.mark.parametrize('change', ['policy','hash','upgrade','missing_recording_hash'])
def test_unknown_or_incomplete_upgrade_pair_fails(change):
    data=session()
    data['contract'].update(policy=V1_POLICY,script_sha256=V1_TEMPLATE_SHA256)
    data.update(upgrade_rule=V1_TO_V2_UPGRADE,recording_sha256='1'*64)
    if change == 'policy':
        data['contract'].update(policy='unknown',script_sha256=V1_TEMPLATE_SHA256)
    elif change == 'hash':
        data['contract']['script_sha256']='0'*64
    elif change == 'upgrade':
        data['upgrade_rule']='unknown'
    else:
        del data['recording_sha256']
    with pytest.raises(ValueError):
        validate_session(data)


@pytest.mark.parametrize('settings',[{'combat':True},{'observe':True,'combat':True,'rng_only':True},
                                    {'observe':True,'combat':1}])
def test_combat_requires_boolean_replay_observers_without_rng_only(settings):
    data=session();data.update(settings)
    with pytest.raises(ValueError,match='Combat diagnostics'):
        validate_session(data)


def test_combat_mode_does_not_change_recorded_inputs():
    data=session();before=copy.deepcopy(data['events'])
    data.update(observe=True,combat=True)
    validate_session(data)
    assert data['events']==before


def test_rebuilt_requires_explicit_replay_target():
    data=session(); data['target']='rebuilt'
    validate_session(data)
    data['mode']='record'; data['events']=[]
    with pytest.raises(ValueError): validate_session(data)
    data['mode']='replay'; data['target']='other'
    with pytest.raises(ValueError): validate_session(data)


@pytest.mark.parametrize('message',[0x103,0x107])
def test_dead_character_messages_are_preserved(message):
    data=session(); data['events'][0]['message']=message
    validate_session(data)
    assert compare_inputs(data['events'],copy.deepcopy(data['events']))['exact_boundaries']
    code=(ROOT/'tools/harness/human.js').read_text()
    assert 'message <= 0x107' in code
    assert '0x102,0x103,0x104,0x105,0x106,0x107' in code


@pytest.mark.parametrize('key,value', [('schema',True),('mode','rebuilt'),('duration_ms',True),
    ('duration_ms',190001),('duration_ms',0),('events',{}),('events',[None]),('smoke',True),('contract',None)])
def test_invalid_session(key,value):
    data=session(); data[key]=value
    with pytest.raises(ValueError): validate_session(data)


@pytest.mark.parametrize('key,value',[('time_ms',-1),('time_ms',1001),('message',0x20a),
    ('message',0x111),('parameter',-1),('value',True),('route','window'),
    ('route',[{'id':1,'index':0,'cls':''}])])
def test_invalid_event(key,value):
    data=session(); data['events'][0][key]=value
    with pytest.raises(ValueError): validate_session(data)


def test_events_must_be_ordered():
    data=session(); data['events'] += [dict(event(),time_ms=99)]
    with pytest.raises(ValueError): validate_session(data)


def test_child_route_and_equal_event_times():
    data=session(); data['events'] += [dict(event(),route=[{'id':3,'index':0,'cls':'EDIT'}])]
    validate_session(data)


def test_record_cannot_inject_script():
    data=session(); data['mode']='record'
    with pytest.raises(ValueError): validate_session(data)


def test_delivery_fidelity_is_not_message_equality():
    a=[event()]; b=copy.deepcopy(a); b[0]['time_ms']+=10; b[0]['updates']+=1
    result=compare_inputs(a,b)
    assert result['same_messages'] and not result['exact_boundaries']
    assert not result['same_game_boundaries']
    assert result['delivery_differences'][0]['time_delta_ms']==10
    assert compare_inputs(a,a)['exact_boundaries']


def test_clock_drift_remains_visible_with_equal_game_boundaries():
    result=compare_inputs([event()],[dict(event(),time_ms=120)])
    assert result['same_game_boundaries']
    assert not result['exact_boundaries']


def test_missing_or_changed_message_fails():
    a=[event()]
    assert not compare_inputs(a,[])['same_messages']
    assert not compare_inputs(a,[dict(event(),value=2)])['same_messages']


def test_missing_panel_fails_before_replay():
    data=session(); del data['events'][0]['panel']
    with pytest.raises(ValueError): validate_session(data)


@pytest.mark.parametrize('data',[None, [], {}, {'schema':1,'policy':POLICY},
    {'schema':1,'policy':POLICY,'contract':None,'duration_ms':10,'events':[]}])
def test_bad_recording_header(tmp_path,data):
    path=tmp_path/'recording.json'; path.write_text(json.dumps(data))
    with pytest.raises(ValueError): load_recording(path)


def test_recording_read_stays_bounded_if_file_grows(monkeypatch):
    requested=[]
    class Stream(io.BytesIO):
        def read(self,size=-1):
            requested.append(size)
            return super().read(size)
    class GrowingPath:
        def stat(self):
            return type('Stat',(),{'st_size':1})()
        def open(self,mode):
            assert mode == 'rb'
            return Stream(b'x'*9)
    monkeypatch.setattr(human_session_module,'MAX_RECORDING_BYTES',8)
    with pytest.raises(ValueError,match='size limit'):
        human_session_module.load_recording_with_sha256(GrowingPath())
    assert requested == [9]


def test_new_profile_keeps_existing_menu_guard():
    code=(ROOT/'tools/harness/ui.js').read_text()
    assert "if (cfg.replay && name === 'forbidStart') continue;" in code
    human=(ROOT/'tools/harness/human.js').read_text()
    assert "['forbidLoad','forbidScenario','forbidEditor']" in human
    assert 'TranslateMessage' in human


def test_wrapper_cursor_uses_logical_coordinates():
    code=(ROOT/'tools/harness/human.js').read_text()
    cursor=code.split("name === 'GetCursorPos' ? new NativeCallback(point => {",1)[1].split("}, 'int'",1)[0]
    assert 'point.writeS32(hx)' in cursor and 'point.add(4).writeS32(hy)' in cursor
    assert 'cts(' not in cursor
    assert 'return 1;' in cursor


def test_normal_close_requests_terminal_frame_before_destruction():
    code=(ROOT/'tools/harness/human.js').read_text()
    close=code.split("human.stop_reason = 'window-close';",1)[1].split('return;',1)[0]
    assert 'args[1] = ptr(0)' in close
    assert 'invalidate(gameWindow,NULL,0)' in close


def test_game_command_routes_explicit_scheduler_upgrade(monkeypatch):
    import game
    calls=[]
    monkeypatch.setattr(sys,'argv',['game.py','replay-original',
        str(ROOT/'config/harness/human-candidate-20260915.json'),'--runs','1','--upgrade-v1-to-v2'])
    monkeypatch.setattr(game.subprocess,'run',lambda command,**kwargs:
                        calls.append(command) or type('Result',(),{'returncode':0})())
    assert game.main() == 0
    assert '--upgrade-v1-to-v2' in calls[0]
