"""Record original play and replay it on fresh original or rebuilt processes, with game-window video."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import ctypes as C
from ctypes import wintypes as W
import hashlib
import json
from pathlib import Path
import sys

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
from game import ROOT, SERIAL_HARNESS_ERROR, require_serial_jobs, stage, stamp, run_worker
from prepare_runtime import ORIGINAL_SHA256

MESSAGES = {*range(0x100,0x108),*range(0x200,0x20b)}
V1_POLICY = 'human-idle20-clock1-paced-v1-message-driven-polling'
V2_POLICY = 'human-idle20-clock1-paced-v2-serialized-message-driven-polling'
V3_POLICY = 'human-idle20-clock1-paced-v3-no-native-timers'
V4_POLICY = 'human-idle20-clock1-paced-v4-controlled-paint'
V5_POLICY = 'human-idle20-clock1-paced-v5-save-fixtures'
V6_POLICY = 'human-idle20-clock1-paced-v6-controlled-save-fixtures'
# The editor profile records the scenario editor as well as the game screen.
V7_POLICY = 'human-idle20-clock1-paced-v7-editor-screens'
V8_POLICY = 'human-real-clock-v8-responsive-recording'
V9_POLICY = 'human-idle20-clock1-paced-v9-controlled-responsive-inputs'
V10_POLICY = 'human-real-clock-v10-responsive-editor-recording'
V11_POLICY = 'human-idle20-clock1-paced-v11-controlled-editor-inputs'
POLICY = V8_POLICY
V1_TEMPLATE_SHA256 = '6312fbd5ebb7d82dd91abe775e8c4c15c538743f276dba03ab61bbb8a1043db4'
V2_TEMPLATE_SHA256 = '1112a4ab54fef13f766d20da7fc1815b20f43aa844bbfdde23ce14eeabc862f4'
V1_TO_V2_UPGRADE = 'v1-to-v2-serialized-dispatch-20260915'
V3_TEMPLATE_SHA256 = 'd4dbe3e19381be0af88827d80bb783027960b2d37bb2b43b430db869c9c14000'
V1_TO_V3_UPGRADE = 'v1-to-v3-no-native-timers-turn-stop-20260915'
V2_TO_V3_UPGRADE = 'v2-to-v3-no-native-timers-turn-stop-20260915'
V4_TEMPLATE_SHA256 = '17752944a9ed945df3a3d0e34bea6f7ac7aabbdcde68a6ae8ad0c65797c5e99e'
V1_TO_V4_UPGRADE = 'v1-to-v4-controlled-paint-turn-stop-20260915'
V2_TO_V4_UPGRADE = 'v2-to-v4-controlled-paint-turn-stop-20260915'
V5_TEMPLATE_SHA256 = 'c4a88062d17a54ae852ec6acc709530691f021dc22eeefe9a3a608862768f5c3'
V6_TEMPLATE_SHA256 = 'f8a9fa538f78495bef80dd9579573e688d4ee7433ea18dbd5123c27357f67687'
V7_TEMPLATE_SHA256 = '9b3d3f53d79e54fd66161b33736bec203ec90622883463d2cadd201bb4bb9031'
V8_TEMPLATE_SHA256 = 'e4dde5def905c831fa5587791c11c64547dfc8bb67a7055fb6d7f495a872aa15'
V9_TEMPLATE_SHA256 = '2151d34e2a62a313cc1b82b4bf728a5a0d83004fe1ddd051186d5027693af26e'
V10_TEMPLATE_SHA256 = '0af89f39e1b293e82a1ad510f793a861aa2aa9418ac049629ffc6a8e65330f6d'
V11_TEMPLATE_SHA256 = '60bebfaa676cb1774296148287d9e391d0e41f62fce622da28a37b530df3fe61'
V5_TO_V6_UPGRADE = 'v5-to-v6-controlled-paint-save-fixtures'
V8_TO_V9_UPGRADE = 'v8-to-v9-controlled-paint-responsive-inputs'
V10_TO_V11_UPGRADE = 'v10-to-v11-controlled-paint-editor-inputs'
UPGRADES = {V1_TO_V2_UPGRADE:(V1_POLICY,V2_POLICY), V1_TO_V3_UPGRADE:(V1_POLICY,V3_POLICY),
            V2_TO_V3_UPGRADE:(V2_POLICY,V3_POLICY), V1_TO_V4_UPGRADE:(V1_POLICY,V4_POLICY),
            V2_TO_V4_UPGRADE:(V2_POLICY,V4_POLICY), V5_TO_V6_UPGRADE:(V5_POLICY,V6_POLICY),
            V8_TO_V9_UPGRADE:(V8_POLICY,V9_POLICY), V10_TO_V11_UPGRADE:(V10_POLICY,V11_POLICY)}
UNTIMED_RECORDING_MS = 24*60*60*1000


def template_sha256(policy):
    if policy == V1_POLICY:
        return V1_TEMPLATE_SHA256
    if policy == V2_POLICY:
        return V2_TEMPLATE_SHA256
    if policy == V3_POLICY:
        return V3_TEMPLATE_SHA256
    if policy == V4_POLICY:
        return V4_TEMPLATE_SHA256
    if policy == V5_POLICY:
        return V5_TEMPLATE_SHA256
    if policy == V6_POLICY:
        return V6_TEMPLATE_SHA256
    if policy == V7_POLICY:
        return V7_TEMPLATE_SHA256
    if policy == V8_POLICY:
        return V8_TEMPLATE_SHA256
    if policy == V9_POLICY:
        return V9_TEMPLATE_SHA256
    if policy == V10_POLICY:
        return V10_TEMPLATE_SHA256
    if policy == V11_POLICY:
        return V11_TEMPLATE_SHA256
    raise ValueError('Unknown human input policy.')


def startup_blocks(policy):
    """Startup paths a profile refuses. Only the current core reads this value."""
    template_sha256(policy)  # Reject unknown profiles.
    if policy in (V1_POLICY, V2_POLICY):
        return ['forbidLoad', 'forbidScenario', 'forbidEditor']
    if policy in (V7_POLICY, V10_POLICY, V11_POLICY):
        return []
    return ['forbidScenario', 'forbidEditor']


def control_template(policy):
    """Keep the pinned pre-save profiles unchanged."""
    folder = Path(__file__).parent
    template_sha256(policy)  # Reject unknown profiles.
    if policy == V1_POLICY:
        return (folder / 'human-v1-template.js').read_text()
    if policy in (V5_POLICY, V6_POLICY):
        core = 'human-v5-core.js'
    elif policy in (V8_POLICY, V9_POLICY):
        core = 'human-v8-core.js'
    elif policy == V7_POLICY:
        core = 'human.js'
    elif policy == V10_POLICY:
        core = 'human-v10-core.js'
    elif policy == V11_POLICY:
        core = 'human-v11-core.js'
    else:
        core = 'human-v2-core.js'
    names = ['menu.js', 'offline.js', core]
    if policy in (V3_POLICY, V4_POLICY, V6_POLICY):
        names.append('human-v3.js')
    if policy in (V4_POLICY, V6_POLICY):
        names.append('human-v4.js')
    if policy in (V8_POLICY, V9_POLICY):
        names.append('human-v8.js')
    if policy == V9_POLICY:
        names.extend(('human-v3.js', 'human-v4.js'))
    if policy in (V10_POLICY, V11_POLICY):
        names.append('human-v8.js')
    if policy == V11_POLICY:
        names.extend(('human-v3.js', 'human-v4.js'))
    if policy in (V7_POLICY, V10_POLICY, V11_POLICY):
        names.append('human-v7-editor.js')
    if policy == V11_POLICY:
        names.append('human-v11.js')
    return '\n'.join((folder / name).read_text() for name in names)


def integer(value, minimum, maximum):
    return type(value) is int and minimum <= value <= maximum


def validate_session(session):
    if not isinstance(session,dict) or type(session.get('schema')) is not int or session.get('schema') != 1 or session.get('mode') not in ('record', 'replay'):
        raise ValueError('Unsupported human recording schema or mode.')
    target = session.get('target','original')
    if target not in ('original','rebuilt') or (session['mode'] == 'record' and target != 'original'):
        raise ValueError('Record on the original. Replay only an explicitly selected supported target.')
    if type(session.get('observe',False)) is not bool or (session.get('observe') and session['mode'] != 'replay'):
        raise ValueError('Additional read-only observers require replay mode.')
    if type(session.get('rng_only',False)) is not bool or (session.get('rng_only') and not session.get('observe')):
        raise ValueError('RNG-only diagnostics require observers.')
    if type(session.get('combat',False)) is not bool or (session.get('combat') and
            (not session.get('observe') or session.get('rng_only'))):
        raise ValueError('Combat diagnostics require observers without RNG-only mode.')
    if not integer(session.get('duration_ms'), 1, UNTIMED_RECORDING_MS):
        raise ValueError('Recorded terminal boundary exceeds the session limit.')
    if type(session.get('no_time_limit',False)) is not bool or (session.get('no_time_limit') and session['mode'] != 'record'):
        raise ValueError('No-time-limit mode is available only while recording.')
    upgrade = session.get('upgrade_rule')
    if upgrade is not None and upgrade not in UPGRADES:
        raise ValueError('Unknown human replay upgrade rule.')
    if session['mode'] == 'record' and upgrade is not None:
        raise ValueError('A recording cannot use a replay upgrade rule.')
    if session['mode'] == 'replay':
        contract = session.get('contract')
        if not isinstance(contract,dict) or contract.get('original_sha256') != ORIGINAL_SHA256:
            raise ValueError('A replay requires its original starting contract.')
        policy = contract.get('policy')
        if policy not in (V1_POLICY,V2_POLICY,V5_POLICY,V7_POLICY,V8_POLICY,V10_POLICY) or contract.get('script_sha256') != template_sha256(policy):
            raise ValueError('Unknown human replay policy or control-script hash.')
        if policy in (V5_POLICY, V7_POLICY, V8_POLICY, V10_POLICY) and contract.get('savegame_source') != 'repository-fixtures':
            raise ValueError('Saved-game replay requires repository save fixtures.')
        if upgrade is not None:
            required_policy = UPGRADES[upgrade][0]
            if policy != required_policy:
                version = {V1_POLICY:'v1', V2_POLICY:'v2', V5_POLICY:'v5', V8_POLICY:'v8', V10_POLICY:'v10'}[required_policy]
                raise ValueError(f'The scheduler upgrade requires the exact {version} policy and script hash.')
        recording_sha = session.get('recording_sha256')
        if recording_sha is not None and (not isinstance(recording_sha,str) or len(recording_sha) != 64 or
                any(c not in '0123456789abcdef' for c in recording_sha)):
            raise ValueError('Invalid source recording SHA256.')
        if upgrade is not None and recording_sha is None:
            raise ValueError('The scheduler upgrade requires the unchanged recording SHA256.')
    events = session.get('events', [])
    event_policy = (session.get('contract') or {}).get('policy')
    if not isinstance(events, list):
        raise ValueError('Invalid input event count.')
    if session['mode'] == 'record' and events:
        raise ValueError('A human recording cannot contain replay inputs.')
    if type(session.get('smoke',False)) is not bool:
        raise ValueError('The smoke flag must be boolean.')
    if type(session.get('message_noise',False)) is not bool or (session['mode'] == 'record' and session.get('message_noise')):
        raise ValueError('Message noise is a boolean replay-only diagnostic.')
    if session['mode'] == 'replay' and session.get('smoke'):
        raise ValueError('Replay cannot add smoke inputs.')
    previous = 0
    previous_turn = 0
    for event in events:
        if not isinstance(event,dict):
            raise ValueError('Invalid input event.')
        if not integer(event.get('time_ms'), previous, session['duration_ms']):
            raise ValueError('Input times must increase and stay inside the recording.')
        previous = event['time_ms']
        if not integer(event.get('turn'),previous_turn,10000000):
            raise ValueError('Input idle boundaries must increase.')
        previous_turn = event['turn']
        if not integer(event.get('updates'),0,10000000) or 'panel' not in event or not isinstance(event.get('panel'),(str,type(None))):
            raise ValueError('Invalid input delivery boundary.')
        if not integer(event.get('message'), 0, 65535) or event['message'] not in MESSAGES:
            raise ValueError('Unsupported recorded input message.')
        if event['message'] == 0x20a and event_policy != V10_POLICY:
            raise ValueError('Mouse-wheel input requires the responsive editor profile.')
        if not all(integer(event.get(key), 0, 0xffffffff) for key in ('value', 'parameter')):
            raise ValueError('Invalid input message parameters.')
        route = event.get('route')
        if not isinstance(route, list) or len(route) > 8:
            raise ValueError('Invalid owned-window route.')
        for part in route:
            if not isinstance(part, dict) or not integer(part.get('id'), -0x80000000, 0x7fffffff) or \
                    not isinstance(part.get('cls'), str) or not 1 <= len(part['cls']) <= 255:
                raise ValueError('Invalid child-window identity.')
            if 'index' in part:
                valid_identity = integer(part.get('index'), 0, 0)
            else:
                valid_identity = integer(part.get('vis'), 0, 1)
            if not valid_identity:
                raise ValueError('Invalid child-window identity.')


def load_recording_with_sha256(path):
    with path.open('rb') as stream:
        data = stream.read()
    recording = json.loads(data)
    if not isinstance(recording,dict) or type(recording.get('schema')) is not int or recording.get('schema') != 1 or recording.get('policy') not in (V1_POLICY,V2_POLICY,V5_POLICY,V7_POLICY,V8_POLICY,V10_POLICY):
        raise ValueError('Unsupported original recording contract.')
    if not all(key in recording for key in ('duration_ms','events','contract')):
        raise ValueError('Recording is missing required fields.')
    if not isinstance(recording['contract'],dict) or recording['policy'] != recording['contract'].get('policy'):
        raise ValueError('Recording policy differs from its starting contract.')
    validate_session({'schema':1,'mode':'replay', **{key:recording[key] for key in ('duration_ms','events','contract')}})
    return recording, hashlib.sha256(data).hexdigest()


def load_recording(path):
    return load_recording_with_sha256(path)[0]


def execution_plan(session):
    validate_session(session)
    if session['mode'] == 'record':
        policy = V10_POLICY if session.get('editor') else V8_POLICY
        return {'recorded_policy':None, 'recorded_script_sha256':None,
                'executed_policy':policy, 'executed_script_sha256':template_sha256(policy),
                'upgrade_rule':None, 'recording_sha256':None, 'same_policy_replay':None}
    contract = session['contract']
    upgrade = session.get('upgrade_rule')
    executed_policy = UPGRADES[upgrade][1] if upgrade else contract['policy']
    if session.get('message_noise') and executed_policy != V4_POLICY:
        raise ValueError('Marked message-noise diagnostics require a v4 replay upgrade.')
    return {'recorded_policy':contract['policy'], 'recorded_script_sha256':contract['script_sha256'],
            'executed_policy':executed_policy, 'executed_script_sha256':template_sha256(executed_policy),
            'upgrade_rule':upgrade, 'recording_sha256':session.get('recording_sha256'),
            'same_policy_replay':upgrade is None}


def session_contract(report, policy=None):
    from replay import recording_contract
    if policy is None:
        policy = (report.get('human_control') or {}).get('executed_policy')
    if policy is None:
        policy = (((report.get('fixture') or {}).get('human') or {}).get('contract') or {}).get('policy', POLICY)
    contract = dict(recording_contract(report), policy=policy, original_sha256=ORIGINAL_SHA256)
    if report['manifest'].get('savegame_bundle') is not None:
        contract['save_bundle'] = report['manifest']['savegame_bundle']
    if policy in (V5_POLICY, V6_POLICY, V7_POLICY, V8_POLICY, V9_POLICY, V10_POLICY, V11_POLICY):
        if report['manifest'].get('savegame_source') != 'repository-fixtures':
            raise ValueError('Saved-game input requires repository save fixtures.')
        contract['savegame_source'] = 'repository-fixtures'
    return contract


def verify_starting_contract(session, report):
    from replay import gameplay_contract
    plan = execution_plan(session)
    actual = session_contract({**report, 'script_sha256':plan['recorded_script_sha256']},
                              policy=plan['recorded_policy'])
    if gameplay_contract(actual) != gameplay_contract(session['contract']):
        raise ValueError('Recording starting contract differs; refusing to launch replay.')
    return plan


def inputs(report):
    return [{key:row[key] for key in ('time_ms','turn','updates','panel','route','message','value','parameter')}
            for row in report['events'] if row.get('kind') == 'human-input']


def compare_inputs(expected, actual):
    fields = ('route','message','value','parameter')
    same = len(expected) == len(actual) and all(
        all(a[k] == b[k] for k in fields) for a, b in zip(expected, actual))
    differences = [{'index':i, 'time_delta_ms':b['time_ms']-a['time_ms'],
                    'turn':[a['turn'],b['turn']], 'updates':[a['updates'],b['updates']], 'panel':[a['panel'],b['panel']]}
                   for i, (a,b) in enumerate(zip(expected,actual))
                   if any(a[k] != b[k] for k in ('time_ms','turn','updates','panel'))]
    game_boundaries = same and all(all(a[k] == b[k] for k in ('turn','updates','panel')) for a,b in zip(expected,actual))
    return {'same_messages':same, 'same_game_boundaries':game_boundaries, 'exact_boundaries':same and not differences,
            'expected_count':len(expected), 'actual_count':len(actual), 'delivery_differences':differences}


class GameJob:
    """Own only the freshly spawned game, including visible recording sessions."""
    def __init__(self, pid):
        from hidden import JOB_LIMIT, bind
        kernel = C.WinDLL('kernel32', use_last_error=True)
        self.close_handle = bind(kernel,'CloseHandle',W.BOOL,[W.HANDLE])
        create = bind(kernel,'CreateJobObjectW',W.HANDLE,[C.c_void_p,W.LPCWSTR])
        configure = bind(kernel,'SetInformationJobObject',W.BOOL,[W.HANDLE,C.c_int,C.c_void_p,W.DWORD])
        assign = bind(kernel,'AssignProcessToJobObject',W.BOOL,[W.HANDLE,W.HANDLE])
        open_process = bind(kernel,'OpenProcess',W.HANDLE,[W.DWORD,W.BOOL,W.DWORD])
        self.handle = create(None,None)
        process = None
        try:
            limits = JOB_LIMIT(); limits.basic.flags = 0x2000
            if not self.handle or not configure(self.handle,9,C.byref(limits),C.sizeof(limits)):
                raise C.WinError(C.get_last_error())
            process = open_process(0x0101,False,pid)  # SET_QUOTA | TERMINATE
            if not process or not assign(self.handle,process):
                raise C.WinError(C.get_last_error())
        except Exception:
            self.close()
            raise
        finally:
            if process:
                self.close_handle(process)

    def close(self):
        if self.handle:
            self.close_handle(self.handle)
            self.handle = None


def run_session(output, session, visible):
    validate_session(session)
    plan = execution_plan(session)
    runtime = stage(session.get('target','original'), select=False,
                    save_bundle=session.get('save_bundle'))
    fixture = runtime / 'human-fixture.json'
    fixture.write_text(json.dumps({'name':'human-original-v1','human':session}, indent=2)+'\n')
    seconds = (UNTIMED_RECORDING_MS // 1000 if session.get('no_time_limit') else
               min(900, session['duration_ms']/1000*3+90) if plan['executed_policy'] == V11_POLICY else
               min(300, session['duration_ms']/1000*2+90))
    command = [str(ROOT/'build/harness-env/Scripts/python.exe'), str(TOOLS/'harness/capture.py'),
               '--runtime',str(runtime),'--fixture',str(fixture),'--clock','calls','--seconds',str(seconds)]
    if visible:
        from hidden import run
        code = run([*command,'--visible'],ROOT,runtime/'human-worker.log',seconds+60,visible=True)
    else:
        code = run_worker(command, runtime/'human-worker.log', seconds+60, False)
    path = runtime/'capture/report.json'
    if not path.exists():
        raise ValueError(f'No capture report. Inspect {runtime}.')
    report = json.loads(path.read_text())
    output.append({'capture':str(path), 'video':report.get('video'), 'returncode':code,
                   'human_control':report.get('human_control'),
                   'save_outputs':report.get('save_outputs', {'changed': [], 'removed': []})})
    if code or report['errors'] or not (report.get('status') or {}).get('human', {}).get('stopped'):
        raise ValueError(f'Session is incomplete. Inspect {path}.')
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    source = parser.add_mutually_exclusive_group(required=True)
    source.add_argument('--record', action='store_true')
    source.add_argument('--recording', type=Path)
    parser.add_argument('--seconds', type=int, default=60, help='Maximum recording duration')
    parser.add_argument('--no-time-limit', action='store_true',
                        help='Record until F10 or window close; the worker keeps a 24-hour safety deadline')
    parser.add_argument('--runs', type=int, default=3)
    parser.add_argument('--jobs', type=int, default=1,
                        help='Must be 1; parallel replay runs are disabled')
    parser.add_argument('--target',choices=('original','rebuilt'),default='original')
    parser.add_argument('--observe',action='store_true',help='Add full RNG and focused read-only diagnostics during replay')
    parser.add_argument('--rng-only',action='store_true',help='Keep only full RNG diagnostics; requires --observe')
    parser.add_argument('--combat',action='store_true',help='Use focused combat diagnostics instead of broad state hooks; requires --observe')
    parser.add_argument('--upgrade-v1-to-v2',action='store_true',
                        help='Diagnostic only: replay an exact v1 recording with the serialized v2 scheduler')
    parser.add_argument('--upgrade-v1-to-v3',action='store_true',
                        help='Experimental: suppress native timers and stop eight turns after the final input')
    parser.add_argument('--controlled',action='store_true',
                        help='Use controlled paint timing; preserve the recording save policy')
    parser.add_argument('--upgrade-v1-to-v4',action='store_true',help='Experiment with controlled queued paints as well as timers')
    parser.add_argument('--message-noise',action='store_true',help='Diagnostic: add queued timer/paint messages during controlled replay')
    parser.add_argument('--smoke', action='store_true', help='Private automated plumbing test, not human qualification')
    parser.add_argument('--editor', action='store_true',
                        help='Record or replay the scenario editor profile; the editor and scenarios may open')
    parser.add_argument('--save-bundle', type=Path,
                        help='Repository save bundle for a new recording')
    parser.add_argument('--cursor-check',action='store_true',help='Private stationary-cursor and normal-close check; requires smoke')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    if args.jobs is not None and args.jobs > 1:
        parser.error(SERIAL_HARNESS_ERROR)
    if args.no_time_limit and not args.record:
        parser.error('--no-time-limit requires --record')
    if args.message_noise and args.record:
        parser.error('--message-noise requires controlled replay')
    if ((args.controlled or args.upgrade_v1_to_v3 or args.upgrade_v1_to_v4) and args.record) or sum((args.controlled,args.upgrade_v1_to_v2,args.upgrade_v1_to_v3,args.upgrade_v1_to_v4)) > 1:
        parser.error('Select one replay upgrade; v3/v4 do not record new inputs yet.')
    if not 1 <= args.seconds <= 180 or not 1 <= args.runs <= 3 or (args.jobs is not None and not 1 <= args.jobs <= args.runs) or (args.smoke and not args.record) or (args.cursor_check and not args.smoke) or (args.record and (args.target != 'original' or args.observe or args.upgrade_v1_to_v2)) or (args.rng_only and not args.observe) or (args.combat and (not args.observe or args.rng_only)):
        parser.error('Use 1..180 seconds, 1..3 runs, and smoke only with record.')
    require_serial_jobs(args.jobs)
    output = args.output or ROOT/'build/runtime'/('human-'+stamp())
    output.mkdir(parents=True, exist_ok=False)
    result = {'schema':1,'original_only':args.target == 'original','target':args.target,
              'jobs':1,
              'runs':[], 'complete':False}
    try:
        if args.record:
            print('Recording starts at launch. Press F10 or close the game window to save. Do not resize or switch windows.', flush=True)
            session = {'schema':1,'mode':'record',
                       'duration_ms':UNTIMED_RECORDING_MS if args.no_time_limit else args.seconds*1000,
                       'no_time_limit':args.no_time_limit,'smoke':args.smoke,
                       'cursor_check':args.cursor_check,'editor':args.editor,
                       'save_bundle':str(args.save_bundle) if args.save_bundle else None}
            report = run_session(result['runs'],session,not args.smoke)
            if args.cursor_check:
                camera_changes = [row for row in report['events'] if row.get('kind') == 'human-camera' and row['updates'] > 0]
                result['stationary_cursor_check'] = {'camera_changes':camera_changes, 'updates':report['status']['human']['updates'],
                                                    'stop_reason':report['status']['human'].get('stop_reason')}
                if camera_changes or report['status']['human']['updates'] < 10 or report['status']['human'].get('stop_reason') != 'window-close':
                    raise ValueError('Stationary-cursor or normal-close check failed.')
            policy = V10_POLICY if args.editor else POLICY
            recording = {'schema':1,'policy':policy,'contract':session_contract(report, policy=policy),
                         'duration_ms':report['status']['human']['time_ms'], 'events':inputs(report),
                         'source_report':result['runs'][0]['capture'], 'automated_smoke':args.smoke}
            validate_session({'schema':1,'mode':'replay','duration_ms':recording['duration_ms'],
                              'contract':recording['contract'],'events':recording['events']})
            (output/'recording.json').write_text(json.dumps(recording,indent=2)+'\n')
            print(f'Recording: {output / "recording.json"}')
            print(f'Capture report: {result["runs"][0]["capture"]}')
        else:
            recording, recording_sha256 = load_recording_with_sha256(args.recording)
            upgrade_rule = V1_TO_V3_UPGRADE if args.upgrade_v1_to_v3 else (V1_TO_V2_UPGRADE if args.upgrade_v1_to_v2 else None)
            if args.controlled:
                upgrade_rule = {V1_POLICY:V1_TO_V4_UPGRADE, V2_POLICY:V2_TO_V4_UPGRADE,
                                V5_POLICY:V5_TO_V6_UPGRADE, V8_POLICY:V8_TO_V9_UPGRADE,
                                V10_POLICY:V10_TO_V11_UPGRADE}[recording['policy']]
            if args.upgrade_v1_to_v4:
                upgrade_rule = V1_TO_V4_UPGRADE
            session = {'schema':1,'mode':'replay','duration_ms':recording['duration_ms'],
                       'events':recording['events'],'contract':recording['contract'],'target':args.target,
                       'observe':args.observe,'rng_only':args.rng_only,'combat':args.combat,
                       'message_noise':args.message_noise,
                       'recording_sha256':recording_sha256,
                       'upgrade_rule':upgrade_rule,
                       'save_bundle':recording['contract'].get('save_bundle')}
            result['human_control'] = execution_plan(session)

            def one(index):
                rows = []
                try:
                    report = run_session(rows, session, False)
                    row = rows[0]
                    received = inputs(report)
                    row['recording_fidelity'] = compare_inputs(recording['events'], received)
                    row['dropped_unrequested_messages'] = report['status']['human']['dropped']
                    return index, row, received, None
                except (OSError, ValueError) as error:
                    return index, None, None, str(error)

            completed = [None] * args.runs
            received_runs = [None] * args.runs
            failures = []
            with ThreadPoolExecutor(max_workers=1) as executor:
                futures = [executor.submit(one, index) for index in range(args.runs)]
                for future in as_completed(futures):
                    index, row, received, error = future.result()
                    if row is not None:
                        completed[index] = row
                        received_runs[index] = received
                    if error is not None:
                        failures.append(error)
            result['runs'] = completed
            if failures:
                raise ValueError(failures[0])
            first = received_runs[0]
            for row, received in zip(result['runs'][1:], received_runs[1:]):
                row['input_repeatability'] = compare_inputs(first, received)
            result['scope'] = 'Input fidelity and repeatability only. Review videos; hidden-state equivalence is not checked.'
            result['input_sequence_preserved'] = all(row['recording_fidelity']['same_messages'] for row in result['runs'])
            result['input_repeatable'] = (all(row['input_repeatability']['exact_boundaries'] for row in result['runs'][1:]) if args.runs > 1 else None)
            result['game_boundaries_repeatable'] = (all(row['input_repeatability']['same_game_boundaries'] for row in result['runs'][1:]) if args.runs > 1 else None)
            print(f'Input sequence preserved: {result["input_sequence_preserved"]}')
            print(f'Game input boundaries repeated: {result["game_boundaries_repeatable"]}')
            print(f'Exact input-repeat boundaries: {result["input_repeatable"]}')
        result['complete'] = True
    except (OSError,ValueError) as error:
        result['error'] = str(error)
        print(f'Session failed: {error}',file=sys.stderr)
    finally:
        (output/'report.json').write_text(json.dumps(result,indent=2)+'\n')
        print(f'Report: {output / "report.json"}')
        for row in result['runs']:
            if row is not None:
                print(f'Video: {Path(row["capture"]).with_name("video.mp4")}')
    return 0 if result['complete'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
