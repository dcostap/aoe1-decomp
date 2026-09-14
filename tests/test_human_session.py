import copy
import json
from pathlib import Path
import sys

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/harness'))
from human_session import validate_session, compare_inputs, load_recording, ORIGINAL_SHA256, POLICY


def event():
    return {'time_ms':100,'turn':3,'updates':0,'panel':'Main Menu','route':[],
            'message':0x201,'value':1,'parameter':100}


def session():
    return {'schema':1,'mode':'replay','duration_ms':1000,'events':[event()],
            'contract':{'original_sha256':ORIGINAL_SHA256,'policy':POLICY}}


def test_valid_record_and_replay():
    validate_session(session())
    validate_session({'schema':1,'mode':'record','duration_ms':1000})


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
