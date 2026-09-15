"""Check the explicit timer-control experiment without launching games."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/harness'))
from human_session import (V1_TO_V3_UPGRADE, V2_TO_V3_UPGRADE, V2_TO_V4_UPGRADE, V2_POLICY, V2_TEMPLATE_SHA256,
                           V3_POLICY, V3_TEMPLATE_SHA256, execution_plan,
                           load_recording_with_sha256)


def session():
    recording, sha = load_recording_with_sha256(ROOT / 'config/harness/human-candidate-20260915.json')
    return {'schema':1, 'mode':'replay', **{k:recording[k] for k in ('contract','events','duration_ms')},
            'recording_sha256':sha, 'upgrade_rule':V1_TO_V3_UPGRADE}


def test_v3_has_a_distinct_control_identity():
    plan = execution_plan(session())
    assert plan['executed_policy'] == V3_POLICY
    assert plan['same_policy_replay'] is False
    assert plan['upgrade_rule'] == V1_TO_V3_UPGRADE
    assert plan['recording_sha256'] == '60c04e651b19d144cd033ffcc5ed2bdff1bfe75629b036f493d8db497e4b832e'


def test_v3_rejects_a_different_recording_policy():
    scenario = session()
    scenario['contract'].update(policy=V2_POLICY, script_sha256=V2_TEMPLATE_SHA256)
    with pytest.raises(ValueError, match='exact v1'):
        execution_plan(scenario)


def test_v3_template_hash():
    folder = ROOT / 'tools/harness'
    template = '\n'.join((folder / name).read_text() for name in ('menu.js','offline.js','human.js','human-v3.js'))
    assert hashlib.sha256(template.encode()).hexdigest() == V3_TEMPLATE_SHA256


def test_v2_inputs_have_their_own_v3_upgrade_identity():
    scenario = session()
    scenario['contract'].update(policy=V2_POLICY,script_sha256=V2_TEMPLATE_SHA256)
    scenario['upgrade_rule'] = V2_TO_V3_UPGRADE
    plan = execution_plan(scenario)
    assert plan['recorded_policy'] == V2_POLICY and plan['executed_policy'] == V3_POLICY
    assert plan['same_policy_replay'] is False


def test_controlled_cli_selects_v2_to_v4_upgrade(tmp_path,monkeypatch):
    import human_session
    recording = json.loads((ROOT/'config/harness/human-accepted-20260914.json').read_text())
    recording['policy'] = V2_POLICY
    recording['contract'].update(policy=V2_POLICY,script_sha256=V2_TEMPLATE_SHA256)
    source = tmp_path/'v2.json'
    source.write_text(json.dumps(recording))
    requests = []
    def run(output,scenario,visible):
        requests.append(scenario)
        output.append({'capture':str(tmp_path/'capture/report.json'),'returncode':0})
        return {'events':[{**row,'kind':'human-input'} for row in scenario['events']],
                'status':{'human':{'dropped':0}}}
    monkeypatch.setattr(human_session,'run_session',run)
    monkeypatch.setattr(sys,'argv',['human_session.py','--recording',str(source),'--controlled',
                                  '--runs','1','--output',str(tmp_path/'result')])
    assert human_session.main()==0
    assert requests[0]['upgrade_rule']==V2_TO_V4_UPGRADE


@pytest.mark.parametrize('target',['replay-original','replay-rebuilt'])
def test_game_command_forwards_controlled_mode(monkeypatch,target):
    import game
    calls=[]
    monkeypatch.setattr(sys,'argv',['game.py',target,'recording.json','--controlled','--runs','1'])
    monkeypatch.setattr(game.subprocess,'run',lambda command,**kwargs:
        (calls.append(command) or type('Result',(),{'returncode':0})()))
    assert game.main()==0
    assert '--controlled' in calls[0]
    assert calls[0][calls[0].index('--target')+1] == target.removeprefix('replay-')


def test_v3_timer_and_terminal_rules():
    code = r'''
const assert = require('assert'), fs = require('fs'), vm = require('vm');
const hooks = {}, stopped = [], invalidations = [];
const context = {isReplay:true, events:[{turn:44}], cfg:{human:{duration_ms:180000}},
    human:{turn:0,stopped:false,lastFrame:0,input:1}, gameThread:7, ticks:1000,
    gameWindow:1, NULL:0, waiting:[], hu:{getExportByName:n=>n}, target:n=>n,
    invalidate:(...args)=>{invalidations.push(args); return true;},
    humanStop:message=>stopped.push(message),
    Interceptor:{attach:(name,hook)=>hooks[name]=hook}};
vm.createContext(context);
vm.runInContext(fs.readFileSync(process.argv[1],'utf8'), context);
assert.strictEqual(context.human.terminal_turn,52);
assert.strictEqual(context.human.historical_duration_ms,180000);
function message(value) { return {value,add(){return {readU32:()=>this.value,writeU32:x=>this.value=x};}}; }
let timer=message(0x113);
hooks.DispatchMessageA.onEnter.call({threadId:7},[timer]);
assert.strictEqual(timer.value,0);
hooks.DispatchMessageW.onEnter.call({threadId:7},[timer]);
assert.strictEqual(context.human.native_timers_suppressed,1);
let wideTimer=message(0x113);
hooks.DispatchMessageW.onEnter.call({threadId:7},[wideTimer]);
assert.strictEqual(wideTimer.value,0);
assert.strictEqual(context.human.native_timers_suppressed,2);
let foreign=message(0x113), input=message(0x200);
hooks.DispatchMessageA.onEnter.call({threadId:8},[foreign]);
hooks.DispatchMessageA.onEnter.call({threadId:7},[input]);
assert.strictEqual(foreign.value,0x113); assert.strictEqual(input.value,0x200);
context.human.turn=51; context.humanAfterFrame(); assert.strictEqual(stopped.length,0);
context.human.turn=52; hooks.idle.onLeave.call({threadId:7});
assert.strictEqual(invalidations.length,1); assert.strictEqual(context.humanFrameDue(),true);
context.humanAfterFrame(); assert.strictEqual(stopped[0],null);
context.waiting.push({}); context.humanAfterFrame(); assert.match(stopped[1],/before all inputs/);
'''
    subprocess.run(['node','-e',code,str(ROOT / 'tools/harness/human-v3.js')], check=True, capture_output=True, text=True)
