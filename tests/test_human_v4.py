"""Check the queued-paint control profile without starting games."""
import hashlib
from pathlib import Path
import subprocess
import sys
import pytest

sys.path.insert(0,str(Path(__file__).resolve().parents[1] / 'tools/harness'))
from human_session import (V1_POLICY,V2_POLICY,V4_POLICY,V1_TO_V3_UPGRADE,V1_TO_V4_UPGRADE,V2_TO_V4_UPGRADE,
                           V4_TEMPLATE_SHA256,ORIGINAL_SHA256,execution_plan,template_sha256,validate_session)

ROOT=Path(__file__).resolve().parents[1]


@pytest.mark.parametrize('policy,rule',[(V1_POLICY,V1_TO_V4_UPGRADE),(V2_POLICY,V2_TO_V4_UPGRADE)])
def test_v4_upgrade_requires_its_actual_source_policy(policy,rule):
    scenario={'schema':1,'mode':'replay','duration_ms':1000,'events':[],
              'recording_sha256':'1'*64,'upgrade_rule':rule,
              'contract':{'original_sha256':ORIGINAL_SHA256,'policy':policy,'script_sha256':template_sha256(policy)}}
    plan=execution_plan(scenario)
    assert plan['executed_policy']==V4_POLICY and plan['executed_script_sha256']==V4_TEMPLATE_SHA256
    assert plan['same_policy_replay'] is False and plan['recorded_policy']==policy
    scenario['upgrade_rule']=V2_TO_V4_UPGRADE if policy==V1_POLICY else V1_TO_V4_UPGRADE
    with pytest.raises(ValueError,match='requires the exact'):
        execution_plan(scenario)


def test_noise_cannot_enter_a_recording_contract():
    with pytest.raises(ValueError,match='replay-only'):
        validate_session({'schema':1,'mode':'record','duration_ms':1000,'message_noise':True})


def test_marked_noise_rejects_the_timer_only_v3_profile():
    scenario={'schema':1,'mode':'replay','duration_ms':1000,'events':[],
              'recording_sha256':'1'*64,'upgrade_rule':V1_TO_V3_UPGRADE,'message_noise':True,
              'contract':{'original_sha256':ORIGINAL_SHA256,'policy':V1_POLICY,'script_sha256':template_sha256(V1_POLICY)}}
    with pytest.raises(ValueError,match='require a v4'):
        execution_plan(scenario)


def test_v4_template_hash():
    template='\n'.join((ROOT/'tools/harness'/name).read_text() for name in
                      ('menu.js','offline.js','human.js','human-v3.js','human-v4.js'))
    assert hashlib.sha256(template.encode()).hexdigest()==V4_TEMPLATE_SHA256


def test_noise_template_hash():
    from human_repeatability import NOISE_SHA256
    assert hashlib.sha256((ROOT/'tools/harness/human_noise.js').read_text().encode()).hexdigest()==NOISE_SHA256


def test_queued_paints_are_acknowledged_and_idle_paints_do_not_recurse():
    code=r'''
const assert=require('assert'), fs=require('fs'), vm=require('vm');
const hooks={}, calls=[], errors=[];
const window={equals:other=>other===window};
const context={human:{stopped:false},gameThread:7,gameWindow:window,NULL:0,
    hu:{getExportByName:name=>name},target:name=>name,
    humanStop:error=>errors.push(error),
    Interceptor:{attach:(name,hook)=>hooks[name]=hook},
    ha:(module,name)=> name==='ValidateRect' ? (...args)=>{calls.push(['validate',...args]);return 1;} :
        (...args)=>{calls.push(['send',...args]); hooks.idle.onLeave.call({threadId:7}); return 0;}};
vm.createContext(context);
vm.runInContext(fs.readFileSync(process.argv[1],'utf8'),context);
function message(hwnd,value) {return {value,readPointer:()=>hwnd,
    add(){return {readU32:()=>this.value,writeU32:value=>this.value=value};}};}
for(const name of ['DispatchMessageA','DispatchMessageW']) {
    let paint=message(window,0xf); hooks[name].onEnter.call({threadId:7},[paint]);
    assert.strictEqual(paint.value,0);
}
assert.strictEqual(context.human.native_paints_suppressed,2);
assert.strictEqual(calls.filter(x=>x[0]==='validate').length,2);
let input=message(window,0x200), child=message({equals:()=>false},0xf), otherThread=message(window,0xf);
hooks.DispatchMessageA.onEnter.call({threadId:7},[input]);
hooks.DispatchMessageA.onEnter.call({threadId:7},[child]);
hooks.DispatchMessageA.onEnter.call({threadId:8},[otherThread]);
assert.strictEqual(input.value,0x200); assert.strictEqual(child.value,0xf); assert.strictEqual(otherThread.value,0xf);
hooks.idle.onLeave.call({threadId:7});
assert.strictEqual(calls.filter(x=>x[0]==='send').length,1);
hooks.idle.onLeave.call({threadId:8}); context.human.stopped=true; hooks.idle.onLeave.call({threadId:7});
assert.strictEqual(calls.filter(x=>x[0]==='send').length,1);
assert.strictEqual(hooks.wndproc,undefined); // Synchronous game paints are not intercepted.
assert.strictEqual(errors.length,0);
'''
    subprocess.run(['node','-e',code,str(ROOT/'tools/harness/human-v4.js')],check=True,capture_output=True,text=True)


def test_noise_is_explicit_bounded_to_the_session_and_reported():
    code=r'''
const assert=require('assert'), fs=require('fs'), vm=require('vm');
const posted=[], events=[], cleared=[], hooks={}; let tick, stopped=false;
const context={gameWindow:7,gameThread:8,hu:{getExportByName:name=>name},
    Interceptor:{attach:(name,hook)=>hooks[name]=hook},human:{stopped:false},post:(...args)=>{posted.push(args);return 1;},
    send:event=>events.push(event),humanStop:()=>stopped=true,
    setInterval:(fn,period)=>{assert.strictEqual(period,37);tick=fn;return 3;},
    clearInterval:id=>cleared.push(id)};
vm.createContext(context);
vm.runInContext(fs.readFileSync(process.argv[1],'utf8'),context);
tick(); context.gameWindow=null; tick(); context.gameWindow=7; context.human.stopped=true; tick();
assert.deepStrictEqual(posted,[[7,0x113,0x4e540001,0],[7,0xf,0x4e500001,0]]);
for(const marker of [0x4e540001,0x4e500001]) {
    const message={toString:()=>String(marker),readPointer:()=>({equals:()=>true}),
        add:offset=>({readU32:()=>offset===8?marker:0})};
    const call={threadId:8}; hooks.DispatchMessageA.onEnter.call(call,[message]); hooks.DispatchMessageA.onLeave.call(call);
}
context.humanStop(null);
assert.strictEqual(stopped,true); assert.deepStrictEqual(cleared,[3]);
assert.strictEqual(events[0].kind,'control-noise-ready');
assert.strictEqual(events[1].kind,'control-noise-summary'); assert.strictEqual(events[1].batches,1);
assert.strictEqual(events[1].suppressed_dispatches.timer,1); assert.strictEqual(events[1].suppressed_dispatches.paint,1);
'''
    subprocess.run(['node','-e',code,str(ROOT/'tools/harness/human_noise.js')],check=True,capture_output=True,text=True)
