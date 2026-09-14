"""Record original play and replay it on fresh original or rebuilt processes, with game-window video."""
import argparse
import ctypes as C
from ctypes import wintypes as W
import json
from pathlib import Path
import sys

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
from game import ROOT, stage, stamp, run_worker
from prepare_runtime import ORIGINAL_SHA256

MESSAGES = {*range(0x100,0x108),*range(0x200,0x20a)}
POLICY = 'human-idle20-clock1-paced-v1-message-driven-polling'


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
    if not integer(session.get('duration_ms'), 1, 190000):
        raise ValueError('Recorded terminal boundary exceeds 190 seconds.')
    if session['mode'] == 'replay' and (not isinstance(session.get('contract'),dict) or session['contract'].get('original_sha256') != ORIGINAL_SHA256 or session['contract'].get('policy') != POLICY):
        raise ValueError('A replay requires its original starting contract.')
    events = session.get('events', [])
    if not isinstance(events, list) or len(events) > 100000:
        raise ValueError('Invalid input event count.')
    if session['mode'] == 'record' and events:
        raise ValueError('A human recording cannot contain replay inputs.')
    if type(session.get('smoke',False)) is not bool:
        raise ValueError('The smoke flag must be boolean.')
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
        if not all(integer(event.get(key), 0, 0xffffffff) for key in ('value', 'parameter')):
            raise ValueError('Invalid input message parameters.')
        route = event.get('route')
        if not isinstance(route, list) or len(route) > 8:
            raise ValueError('Invalid owned-window route.')
        for part in route:
            if not isinstance(part, dict) or not integer(part.get('id'), -0x80000000, 0x7fffffff) or not integer(part.get('index'), 0, 0) or not isinstance(part.get('cls'), str) or not 1 <= len(part['cls']) <= 255:
                raise ValueError('Invalid child-window identity.')


def load_recording(path):
    if path.stat().st_size > 32*1024*1024:
        raise ValueError('Recording exceeds the size limit.')
    recording = json.loads(path.read_text())
    if not isinstance(recording,dict) or type(recording.get('schema')) is not int or recording.get('schema') != 1 or recording.get('policy') != POLICY:
        raise ValueError('Unsupported original recording contract.')
    if not all(key in recording for key in ('duration_ms','events','contract')):
        raise ValueError('Recording is missing required fields.')
    validate_session({'schema':1,'mode':'replay', **{key:recording[key] for key in ('duration_ms','events','contract')}})
    return recording


def session_contract(report):
    from replay import recording_contract
    return dict(recording_contract(report), policy=POLICY, original_sha256=ORIGINAL_SHA256)


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
    runtime = stage(session.get('target','original'))
    fixture = runtime / 'human-fixture.json'
    fixture.write_text(json.dumps({'name':'human-original-v1','human':session}, indent=2)+'\n')
    seconds = min(300, session['duration_ms']/1000*2+90)
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
    output.append({'capture':str(path), 'video':report.get('video'), 'returncode':code})
    if code or report['errors'] or not (report.get('status') or {}).get('human', {}).get('stopped'):
        raise ValueError(f'Session is incomplete. Inspect {path}.')
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    source = parser.add_mutually_exclusive_group(required=True)
    source.add_argument('--record', action='store_true')
    source.add_argument('--recording', type=Path)
    parser.add_argument('--seconds', type=int, default=60, help='Maximum controlled recording duration')
    parser.add_argument('--runs', type=int, default=3)
    parser.add_argument('--target',choices=('original','rebuilt'),default='original')
    parser.add_argument('--observe',action='store_true',help='Add full RNG and focused read-only diagnostics during replay')
    parser.add_argument('--rng-only',action='store_true',help='Keep only full RNG diagnostics; requires --observe')
    parser.add_argument('--smoke', action='store_true', help='Private automated plumbing test, not human qualification')
    parser.add_argument('--cursor-check',action='store_true',help='Private stationary-cursor and normal-close check; requires smoke')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    if not 1 <= args.seconds <= 180 or not 1 <= args.runs <= 3 or (args.smoke and not args.record) or (args.cursor_check and not args.smoke) or (args.record and (args.target != 'original' or args.observe)) or (args.rng_only and not args.observe):
        parser.error('Use 1..180 seconds, 1..3 runs, and smoke only with record.')
    output = args.output or ROOT/'build/runtime'/('human-'+stamp())
    output.mkdir(parents=True, exist_ok=False)
    result = {'schema':1,'original_only':args.target == 'original','target':args.target,'runs':[], 'complete':False}
    try:
        if args.record:
            print('Recording starts at launch. Press F10 or close the game window to save. Do not resize or switch windows.', flush=True)
            session = {'schema':1,'mode':'record','duration_ms':args.seconds*1000,'smoke':args.smoke,'cursor_check':args.cursor_check}
            report = run_session(result['runs'],session,not args.smoke)
            if args.cursor_check:
                camera_changes = [row for row in report['events'] if row.get('kind') == 'human-camera' and row['updates'] > 0]
                result['stationary_cursor_check'] = {'camera_changes':camera_changes, 'updates':report['status']['human']['updates'],
                                                    'stop_reason':report['status']['human'].get('stop_reason')}
                if camera_changes or report['status']['human']['updates'] < 10 or report['status']['human'].get('stop_reason') != 'window-close':
                    raise ValueError('Stationary-cursor or normal-close check failed.')
            recording = {'schema':1,'policy':POLICY,'contract':session_contract(report),
                         'duration_ms':report['status']['human']['time_ms'], 'events':inputs(report),
                         'source_report':result['runs'][0]['capture'], 'automated_smoke':args.smoke}
            validate_session({'schema':1,'mode':'replay','duration_ms':recording['duration_ms'],
                              'contract':recording['contract'],'events':recording['events']})
            (output/'recording.json').write_text(json.dumps(recording,indent=2)+'\n')
            print(f'Recording: {output / "recording.json"}')
        else:
            recording = load_recording(args.recording)
            session = {'schema':1,'mode':'replay','duration_ms':recording['duration_ms'],
                       'events':recording['events'],'contract':recording['contract'],'target':args.target,
                       'observe':args.observe,'rng_only':args.rng_only}
            first = None
            for _ in range(args.runs):
                report = run_session(result['runs'],session,False)
                received = inputs(report)
                result['runs'][-1]['recording_fidelity'] = compare_inputs(recording['events'],received)
                result['runs'][-1]['dropped_unrequested_messages'] = report['status']['human']['dropped']
                if first is None:
                    first = received
                else:
                    result['runs'][-1]['input_repeatability'] = compare_inputs(first,received)
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
            print(f'Video: {Path(row["capture"]).with_name("video.mp4")}')
    return 0 if result['complete'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
