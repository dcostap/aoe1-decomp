from pathlib import Path
import json
import sys

import pytest

sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools/harness'))
from human_compare import compare_rows, video_grid
from human_session import (execution_plan, ORIGINAL_SHA256, V1_POLICY, V2_POLICY,
                           V1_TEMPLATE_SHA256, V2_TEMPLATE_SHA256, V1_TO_V2_UPGRADE)


def frame(index,time,character):
    return {'input_frame':index,'time_ms':time,'width':640,'height':480,'rgb_sha256':character*64}


def test_differences_are_positional_and_include_missing_tail():
    result=compare_rows([1,2,3],[2,1])
    assert not result['equal'] and result['different_positions']==3
    assert result['first_difference']=={'index':0,'left':1,'right':2}
    assert compare_rows([],[])['equal']


def test_video_grid_repeats_previous_frame_across_gaps():
    result=video_grid([frame(0,0,'a'),frame(1,125,'b')],20)
    assert [r[2] for r in result]==['a'*64]*3+['b'*64]


def test_equal_timestamp_replaces_unencoded_frame():
    result=video_grid([frame(0,0,'a'),frame(1,0,'b'),frame(2,50,'c')],20)
    assert [r[2] for r in result]==['b'*64,'c'*64]


@pytest.mark.parametrize('rows',[[],[frame(0,1,'a')],[frame(1,0,'a')],
    [frame(0,0,'a'),frame(1,-1,'b')],[frame(0,0,'z')]])
def test_bad_video_metadata_fails(rows):
    with pytest.raises(ValueError): video_grid(rows,20)


@pytest.mark.parametrize('right_value',[7,8])
def test_full_rng_comparison_is_not_limited_to_status_prefix(tmp_path,monkeypatch,right_value):
    import hashlib
    import json
    import struct
    import human_compare
    monkeypatch.setattr(human_compare,'session_contract',lambda report:{'assets':{}})
    captures=[]
    for name,value in [('left',7),('right',right_value)]:
        folder=tmp_path/name
        folder.mkdir()
        data=struct.pack('<II',0,value)
        (folder/'rng.bin').write_bytes(data)
        scenario={'mode':'replay','schema':1,'duration_ms':1000,'events':[],
                  'contract':{'original_sha256':ORIGINAL_SHA256,'policy':V2_POLICY,
                              'script_sha256':V2_TEMPLATE_SHA256}}
        report={'fixture':{'human':scenario},'script_sha256':V2_TEMPLATE_SHA256,
                'human_control':execution_plan(scenario),
                'video':{'fps':20},'video_origin_time_ms':0,'events':[],
                'status':{'rngTrace':[],'rngCount':1,'human':{'turn':0,'updates':0,'time_ms':0,'world':{}}},
                'rng_recording':{'file':'rng.bin','records':1,'sha256':hashlib.sha256(data).hexdigest(),
                                 'sites':{'0':{'kind':'rand','file':'x','line':2}}}}
        path=folder/'report.json'
        path.write_text(json.dumps(report))
        captures.append({'path':str(path),'report':report,'grid':[]})
    result=human_compare.compare_captures(*captures)
    assert result['rng_prefix']['equal']
    assert result['rng_trace_complete']==[True,True]
    assert result['full_rng']['equal']==(right_value==7)
    assert result['control_identity']['classification']=='same-policy'
    (tmp_path/'right/rng.bin').write_bytes(b'changed')
    with pytest.raises(ValueError,match='hash or length'):
        human_compare.compare_captures(*captures)


def test_explicit_upgrade_identity_is_visible_and_strict(monkeypatch):
    import human_compare
    monkeypatch.setattr(human_compare,'session_contract',lambda report:{'assets':{}})
    scenario={'mode':'replay','schema':1,'duration_ms':1000,'events':[],
              'contract':{'original_sha256':ORIGINAL_SHA256,'policy':V1_POLICY,
                          'script_sha256':V1_TEMPLATE_SHA256},
              'recording_sha256':'1'*64,'upgrade_rule':V1_TO_V2_UPGRADE}
    def capture():
        report={'fixture':{'human':scenario},'script_sha256':V2_TEMPLATE_SHA256,
                'human_control':execution_plan(scenario),'video':{'fps':20},'video_origin_time_ms':0,
                'events':[],'status':{'rngTrace':[],'rngCount':0,
                'human':{'turn':0,'updates':0,'time_ms':0,'world':{}}}}
        return {'path':'capture','report':report,'grid':[]}
    left,right=capture(),capture()
    result=human_compare.compare_captures(left,right)
    assert result['control_identity']['same_policy_replay'] is False
    assert result['control_identity']['classification']=='explicit-v1-to-v2-upgrade'
    right['report']['human_control']['upgrade_rule']='unknown'
    with pytest.raises(ValueError,match='control identity'):
        human_compare.compare_captures(left,right)


def test_save_output_hashes_are_compared(monkeypatch):
    import human_compare
    monkeypatch.setattr(human_compare,'session_contract',lambda report:{'assets':{}})
    scenario={'mode':'replay','schema':1,'duration_ms':1000,'events':[],
              'contract':{'original_sha256':ORIGINAL_SHA256,'policy':V2_POLICY,
                          'script_sha256':V2_TEMPLATE_SHA256}}
    report={'fixture':{'human':scenario},'script_sha256':V2_TEMPLATE_SHA256,
            'human_control':execution_plan(scenario),'video':{'fps':20},
            'video_origin_time_ms':0,'events':[],
            'status':{'rngTrace':[],'rngCount':0,
                      'human':{'turn':0,'updates':0,'time_ms':0,'world':{}}},
            'save_outputs':{'changed':[{'path':'savegame/checkpoint.gmx','size':3,'sha256':'a'*64}],
                            'removed':[]}}
    left={'path':'left','report':report,'grid':[]}
    right={'path':'right','report':json.loads(json.dumps(report)),'grid':[]}
    assert human_compare.compare_captures(left,right)['save_outputs']['equal']
    right['report']['save_outputs']['changed'][0]['sha256']='b'*64
    assert not human_compare.compare_captures(left,right)['save_outputs']['equal']


@pytest.mark.parametrize('classification', ['same-policy','explicit-v1-to-v2-upgrade',
                                         'explicit-v1-to-v3-upgrade','explicit-v2-to-v3-upgrade',
                                         'explicit-v1-to-v4-upgrade','explicit-v2-to-v4-upgrade'])
def test_aggregate_comparison_keeps_its_actual_profile(tmp_path,monkeypatch,classification):
    import json
    import sys
    import human_compare
    monkeypatch.setattr(human_compare,'load_batch',lambda *args:[{}, {}, {}])
    monkeypatch.setattr(human_compare,'compare_captures',lambda *args:{'control_identity':{
        'same_policy_replay':classification=='same-policy','classification':classification}})
    output=tmp_path/'comparison'
    monkeypatch.setattr(sys,'argv',['human_compare.py','--original','a','--rebuilt','b','--output',str(output)])
    assert human_compare.main()==0
    assert json.loads((output/'report.json').read_text())['classification']==classification+'-comparison'
