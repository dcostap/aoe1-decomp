from pathlib import Path
import sys

import pytest

sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools/harness'))
from human_compare import compare_rows, video_grid


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
    monkeypatch.setattr(human_compare,'session_contract',lambda report:{})
    captures=[]
    for name,value in [('left',7),('right',right_value)]:
        folder=tmp_path/name
        folder.mkdir()
        data=struct.pack('<II',0,value)
        (folder/'rng.bin').write_bytes(data)
        report={'fixture':{'human':{'mode':'replay','duration_ms':1000,'events':[],'contract':{}}},
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
    (tmp_path/'right/rng.bin').write_bytes(b'changed')
    with pytest.raises(ValueError,match='hash or length'):
        human_compare.compare_captures(*captures)
