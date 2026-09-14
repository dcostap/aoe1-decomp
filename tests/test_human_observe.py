import json
from pathlib import Path
import shutil
import subprocess
import sys

import pytest

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/harness'))
from human_session import validate_session


def test_observers_cannot_change_recording_mode():
    with pytest.raises(ValueError):
        validate_session({'schema':1,'mode':'record','duration_ms':1000,'observe':True})


def test_observer_does_not_change_control_script_fingerprint():
    code=(ROOT/'tools/harness/capture.py').read_text()
    assert "source += '\\n' + observer" in code
    assert "'script_sha256': hashlib.sha256(template.encode()).hexdigest()" in code
    assert "'observer_sha256':hashlib.sha256(observer.encode()).hexdigest()" in code
    assert "status['rngCount'] != rng_records" in code


@pytest.mark.skipif(shutil.which('node') is None,reason='Node is required for the JavaScript observer unit test')
@pytest.mark.parametrize(('rng_only','combat','hook_count'),[(True,False,0),(False,False,5),(False,True,4)])
def test_rng_observer_preserves_control_and_flushes_complete_records(rng_only,combat,hook_count):
    program=r"""
const vm=require('vm'),fs=require('fs');
let calls=0,stops=0; const messages=[],hooks=[];
const ctx={cfg:{human:{rng_only:process.argv[2]==='true',combat:process.argv[3]==='true'}},rng:()=>calls++,humanStop:()=>stops++,human:{turn:1,updates:2,input:3},ticks:1010,
  humanAdvance:amount=>ctx.ticks+=amount,
  target:n=>n,Interceptor:{attach:n=>hooks.push(n)},send:(row,data)=>messages.push({row,bytes:data?Array.from(new Uint8Array(data)):null})};
vm.createContext(ctx); vm.runInContext(fs.readFileSync(process.argv[1],'utf8'),ctx);
ctx.rng({kind:'srand',file:'C:/A.cpp',line:1,seed:7});
for(let n=0;n<4100;n++)ctx.rng({kind:'rand',file:'C:/A.cpp',line:2,value:n});
if(!ctx.cfg.human.rng_only)for(let n=0;n<259;n++)ctx.observed('observer-world',{phase:'test'});
ctx.humanStop(null);
ctx.humanAdvance(1);ctx.humanAdvance(20);
console.log(JSON.stringify({calls,stops,messages,hooks,ticks:ctx.ticks}));
"""
    result=subprocess.run(['node','-e',program,str(ROOT/'tools/harness/human_observe.js'),json.dumps(rng_only),json.dumps(combat)],check=True,capture_output=True,text=True)
    data=json.loads(result.stdout)
    assert data['calls']==4101 and data['stops']==1
    assert len(data['hooks'])==hook_count and data['ticks']==1031
    batches=[row for row in data['messages'] if row['row']['kind']=='replay-rng-batch']
    assert sum(row['row']['records'] for row in batches)==4101
    assert all(len(row['bytes'])==row['row']['records']*8 for row in batches)
    assert data['messages'][-1]['row']['records']==4101
    event_batches=[row['row']['events'] for row in data['messages'] if row['row']['kind']=='observer-events']
    assert [len(batch) for batch in event_batches]==([] if rng_only else [128,128,3])
    event_rows=[row for batch in event_batches for row in batch]
    assert all(row['sequence']==index+1 and row['rng_count']==4101 for index,row in enumerate(event_rows))
    sites=[row['row']['site'] for row in data['messages'] if row['row']['kind']=='replay-rng-site']
    assert len(sites)==2 and all(row['file']=='c:\\a.cpp' for row in sites)


def test_minimap_source_adds_original_negative_subtrahend():
    source=(ROOT/'src/diam_map.cpp').read_text()
    assert 'set_view_loc((float)xs + 0.5f, (float)ys + 0.5f)' in source
    assert 'set_view_loc((float)out_1 + 0.5f, (float)out_2 + 0.5f)' in source


def test_map_point_source_uses_original_negative_one_subtrahend():
    source=(ROOT/'src/map.cpp').read_text()
    assert '(param_4 + 1.0f - param_3 - param_5)' in source


@pytest.mark.parametrize(('address','expected'),[(0x56F608,-0.5),(0x5706EC,-1.0)])
def test_repaired_constants_against_pinned_original_data(address,expected):
    import hashlib
    import struct
    data=(ROOT/'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe').read_bytes()
    assert hashlib.sha256(data).hexdigest()=='88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90'
    pe=struct.unpack_from('<I',data,60)[0]
    count=struct.unpack_from('<H',data,pe+6)[0]
    table=pe+24+struct.unpack_from('<H',data,pe+20)[0]
    rva=address-0x400000
    sections=[struct.unpack_from('<IIII',data,table+40*i+8) for i in range(count)]
    section=next(s for s in sections if s[1]<=rva<s[1]+min(s[0],s[2]))
    assert struct.unpack_from('<f',data,section[3]+rva-section[1])[0]==expected
