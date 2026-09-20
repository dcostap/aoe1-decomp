"""Run scripted smoke, human-input cases, and native feature maps on both executables."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from game import ROOT, run_worker, stamp
from human_session import load_recording, compare_inputs, inputs
from human_compare import load_batch, compare_captures
from human_session import (V1_TO_V4_UPGRADE, V5_POLICY, V5_TO_V6_UPGRADE,
                           V7_POLICY, V7_TEMPLATE_SHA256, V10_POLICY,
                           V10_TEMPLATE_SHA256, V10_TO_V11_UPGRADE, execution_plan)
from human_repeatability import compare as compare_repeatability
from prepare_runtime import save_fixtures
import itertools

RECORDING = ROOT / 'config/harness/human-accepted-20260914.json'
RECORDING_SHA256 = 'a320c5d68b8b6f2e49d5d9963e60bc3455c177deac2909d5795ab19e02510e4d'
SCOPE = ('Exact observed comparisons, including clock differences. No pixel masks or timing tolerances. '
         'Changed save files are compared by exact size and SHA-256. Full RNG capture uses the read-only observer. '
         'Observer neutrality and full hidden-state equivalence remain unproved.')
CONTROLLED_SCOPE = ('Each human case uses the same controlled profile on both executables: v4 for v1 inputs, v6 for v5 saved-game inputs. '
    'Unchanged recordings supply messages, routes, and turn/panel schedules, not expected controlled clocks or world-update counts. '
    'Historical recording fidelity stays visible. All cross-run clock, state, RNG, RGB, and changed-save checks remain exact. '
    'This does not reproduce the missing v1 timer history or prove complete hidden-state equivalence.')
CONTROLLED_CASES = (
    ('accepted', RECORDING, RECORDING_SHA256, 324),
    ('candidate', ROOT / 'config/harness/human-candidate-20260915.json',
     '60c04e651b19d144cd033ffcc5ed2bdff1bfe75629b036f493d8db497e4b832e', 1361),
    ('late-game-match', ROOT / 'config/harness/human-late-game-match.json',
     '07f2a4900af0f0c769224f1c9d5c9f561fce7d2aff16cdfdcaf300797f0fb5a6', 559),
)
EDITOR_RECORDING = ROOT / 'config/harness/human-editor-20260916.json'
EDITOR_RECORDING_SHA256 = '4cac2eb68eb4ef6202eecbf3dacf23fb7c4bc9c48d08fc34618f8976779ed953'
EDITOR_EVENT_COUNT = 3729
RESPONSIVE_EDITOR_RECORDING = ROOT / 'config/harness/human-editor-responsive-20260920.json'
RESPONSIVE_EDITOR_SHA256 = '28a14bf69b902fe0c575dcaa4559f147fd9443e6a1ee3f332d3348de211173d5'
RESPONSIVE_EDITOR_EVENT_COUNT = 91284


def run_commands(commands, output, runner, jobs=None):
    """Run independent suite workers together and keep report order stable."""
    if not commands:
        return []
    if jobs is not None and jobs < 1:
        raise ValueError('The suite worker count must be positive.')
    worker_count = min(len(commands), jobs if jobs is not None else len(commands))

    def one(index, name, command, timeout):
        row = {'name': name, 'command': command, 'returncode': None}
        try:
            row['returncode'] = runner(command, output / (name + '.log'), timeout, False)
        except Exception as error:
            row['error'] = str(error)
        return index, row

    rows = [None] * len(commands)
    with ThreadPoolExecutor(max_workers=worker_count) as executor:
        futures = [executor.submit(one, index, name, command, timeout)
                   for index, (name, command, timeout) in enumerate(commands)]
        for future in as_completed(futures):
            index, row = future.result()
            rows[index] = row
            print(f"Harness worker: {row['name']}: exit {row['returncode']}", flush=True)
    return rows


def accepted_recording(path=RECORDING):
    if hashlib.sha256(path.read_bytes()).hexdigest() != RECORDING_SHA256:
        raise ValueError('The accepted human recording changed.')
    recording = load_recording(path)
    if recording.get('automated_smoke') is not False or len(recording['events']) != 324:
        raise ValueError('Expected the accepted 324-message human recording.')
    return recording


def comparison_checks(row):
    return {
        'input_messages': row['inputs']['same_messages'],
        'game_input_boundaries': row['inputs']['same_game_boundaries'],
        'input_clock_boundaries': row['inputs']['exact_boundaries'],
        'camera_values': row['camera_values']['equal'],
        'camera_receipts': row['camera_receipts']['equal'],
        'terminal_boundaries': row['terminal_boundaries'][0] == row['terminal_boundaries'][1],
        'terminal_world': row['terminal_world']['equal'],
        'rng_prefix': row['rng_prefix']['equal'],
        'full_rng': all(row['rng_trace_complete']) and (row['full_rng'] or {}).get('equal') is True,
        'rng_counts': row['rng_total_counts'][0] == row['rng_total_counts'][1],
        'video_rgb': row['video_samples']['equal'],
        'save_outputs': row['save_outputs']['equal'],
        'observer_identity': bool(row['observer_sha256'][0]) and row['observer_sha256'][0] == row['observer_sha256'][1],
    }


def human_result(original_path, rebuilt_path, recording):
    result = {'complete': False, 'passed': False, 'scope': SCOPE}
    try:
        original = load_batch(original_path, True)
        rebuilt = load_batch(rebuilt_path, False)
        result['recording_fidelity'] = []
        for capture in original + rebuilt:
            report = capture['report']
            session = report['fixture']['human']
            if session.get('observe') is not True or session.get('rng_only') is not True or session.get('combat'):
                raise ValueError('The standard human case requires the full RNG-only observer.')
            control = report.get('human_control')
            if (not isinstance(control,dict) or control.get('same_policy_replay') is not True or
                    control.get('upgrade_rule') is not None or
                    control.get('recorded_policy') != recording['contract']['policy'] or
                    control.get('executed_policy') != recording['contract']['policy'] or
                    control.get('recorded_script_sha256') != recording['contract']['script_sha256'] or
                    control.get('executed_script_sha256') != recording['contract']['script_sha256'] or
                    control.get('recording_sha256') != RECORDING_SHA256 or
                    report.get('script_sha256') != recording['contract']['script_sha256']):
                raise ValueError('The standard human case requires an exact same-policy control script.')
            if any(session[key] != recording[key] for key in ('duration_ms', 'events', 'contract')):
                raise ValueError('Capture does not use the accepted recording.')
            result['recording_fidelity'].append(compare_inputs(recording['events'], inputs(report)))
        for name, left, others in (
                ('original_repeat', original[0], original[1:]),
                ('rebuilt_repeat', rebuilt[0], rebuilt[1:]),
                ('cross_build', original[0], rebuilt)):
            result[name] = []
            for right in others:
                row = compare_captures(left, right)
                row['checks'] = comparison_checks(row)
                row['passed'] = all(value is True for value in row['checks'].values())
                result[name].append(row)
        result['complete'] = True
        result['passed'] = (all(row['exact_boundaries'] for row in result['recording_fidelity']) and
                            all(row['passed'] for name in ('original_repeat', 'rebuilt_repeat', 'cross_build')
                                for row in result[name]))
        result['classification'] = 'observed-match' if result['passed'] else 'observed-differences'
    except (OSError, ValueError, KeyError, TypeError, IndexError) as error:
        result.update(classification='incomplete', error=str(error))
    return result


def run_legacy_suite(output, runner=run_worker, jobs=None):
    output.mkdir(parents=True, exist_ok=False)
    result = {'schema': 1, 'complete': False, 'passed': False, 'scope': SCOPE,
              'recording': str(RECORDING), 'recording_sha256': RECORDING_SHA256, 'workers': []}
    try:
        recording = accepted_recording()
        python = str(ROOT / 'build/harness-env/Scripts/python.exe')
        scripted = output / 'scripted'
        original = output / 'human-original'
        rebuilt = output / 'human-rebuilt'
        commands = [('scripted', [python, str(ROOT / 'tools/harness/replay.py'),
                     '--fixture', str(ROOT / 'config/harness/replay-random-smoke.json'),
                     '--runs', '3', '--seconds', '90', '--output', str(scripted)], 780)]
        deadline = 3 * (min(300, recording['duration_ms'] / 1000 * 2 + 90) + 60) + 90
        for target, destination in (('original', original), ('rebuilt', rebuilt)):
            commands.append(('human-' + target, [python, str(ROOT / 'tools/harness/human_session.py'),
                             '--recording', str(RECORDING), '--target', target, '--runs', '3',
                             '--observe', '--rng-only', '--output', str(destination)], deadline))
        # Run both cases even when the scripted case finds differences.
        result['jobs'] = min(len(commands), jobs if jobs is not None else len(commands))
        result['workers'] = run_commands(commands, output, runner, jobs)
        try:
            result['scripted'] = json.loads((scripted / 'report.json').read_text())
        except (OSError, ValueError) as error:
            result['scripted'] = {'passed': False, 'error': str(error)}
        result['human'] = human_result(original / 'report.json', rebuilt / 'report.json', recording)
        result['complete'] = ('error' not in result['scripted'] and result['human']['complete'] and
                              all(row['returncode'] is not None for row in result['workers']))
        result['passed'] = (result['complete'] and result['scripted'].get('passed') is True and
                            result['human']['passed'] and all(row['returncode'] == 0 for row in result['workers']))
    except (OSError, ValueError) as error:
        result['error'] = str(error)
    (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


def controlled_recordings():
    recordings = {}
    for name, path, sha, count in CONTROLLED_CASES:
        if hashlib.sha256(path.read_bytes()).hexdigest() != sha:
            raise ValueError(f'The {name} input recording changed.')
        recording = load_recording(path)
        if recording.get('automated_smoke') is not False or len(recording['events']) != count:
            raise ValueError(f'Invalid {name} input recording.')
        if recording['policy'] == V5_POLICY:
            recorded_saves = {key:value for key,value in recording['contract']['assets'].items()
                              if key.replace('\\', '/').lower().startswith('savegame/')}
            current_saves = {'savegame/' + row['name']:row['sha256'] for _,row in save_fixtures()}
            if recorded_saves != current_saves:
                raise ValueError(f'The {name} save fixtures differ from its recording contract.')
        recordings[name] = recording
    return recordings


def editor_recording():
    if hashlib.sha256(EDITOR_RECORDING.read_bytes()).hexdigest() != EDITOR_RECORDING_SHA256:
        raise ValueError('The editor input recording changed.')
    recording = load_recording(EDITOR_RECORDING)
    if recording.get('automated_smoke') is not False or recording.get('policy') != V7_POLICY or \
            recording.get('contract', {}).get('script_sha256') != V7_TEMPLATE_SHA256 or \
            len(recording.get('events', [])) != EDITOR_EVENT_COUNT:
        raise ValueError('Invalid editor input recording.')
    return recording


def responsive_editor_recording():
    if hashlib.sha256(RESPONSIVE_EDITOR_RECORDING.read_bytes()).hexdigest() != RESPONSIVE_EDITOR_SHA256:
        raise ValueError('The responsive editor input recording changed.')
    recording = load_recording(RESPONSIVE_EDITOR_RECORDING)
    if recording.get('automated_smoke') is not False or recording.get('policy') != V10_POLICY or \
            recording.get('contract', {}).get('script_sha256') != V10_TEMPLATE_SHA256 or \
            len(recording.get('events', [])) != RESPONSIVE_EDITOR_EVENT_COUNT:
        raise ValueError('Invalid responsive editor input recording.')
    return recording


def editor_comparison_checks(row):
    return {
        'input_messages': row['inputs']['same_messages'],
        'game_input_boundaries': row['inputs']['same_game_boundaries'],
        'camera_values': row['camera_values']['equal'],
        'camera_receipts': row['camera_receipts']['equal'],
        'video_rgb': row['video_samples']['equal'],
        'save_outputs': row['save_outputs']['equal'],
    }


def editor_result(original_path, rebuilt_path, recording, recording_sha):
    result = {'complete': False, 'passed': False,
              'scope': 'Delivered inputs, camera values and receipts, exact pre-encode RGB hashes, and changed-save hashes. No world or RNG observers.',
              'recording_sha256': recording_sha, 'recording_fidelity': []}
    try:
        captures = load_batch(original_path, True) + load_batch(rebuilt_path, False)
        expected_control = execution_plan({'schema': 1, 'mode': 'replay',
            **{key: recording[key] for key in ('duration_ms', 'events', 'contract')},
            'recording_sha256': recording_sha, 'upgrade_rule': None})
        for capture in captures:
            report = capture['report']
            session = report['fixture']['human']
            control = report.get('human_control') or {}
            if (session.get('observe') or session.get('rng_only') or session.get('combat') or
                    session.get('message_noise') or report.get('observer_sha256') is not None or
                    report.get('rng_recording') is not None):
                raise ValueError('The editor case forbids world and RNG observers.')
            if (control != expected_control or report.get('script_sha256') != V7_TEMPLATE_SHA256 or
                    any(session[key] != recording[key] for key in ('duration_ms', 'events', 'contract'))):
                raise ValueError('Capture does not use the pinned editor recording and profile.')
            result['recording_fidelity'].append(compare_inputs(recording['events'], inputs(report)))
        result['pairs'] = []
        for name, left, others in (
                ('original_repeat', captures[0], captures[1:3]),
                ('rebuilt_repeat', captures[3], captures[4:6]),
                ('cross_build', captures[0], captures[3:6])):
            result[name] = []
            for right in others:
                row = compare_captures(left, right)
                row['checks'] = editor_comparison_checks(row)
                row['passed'] = all(value is True for value in row['checks'].values())
                result[name].append(row)
                result['pairs'].append(row)
        result['complete'] = True
        result['passed'] = (all(row['same_messages'] and row['same_game_boundaries']
                                for row in result['recording_fidelity']) and
                            all(row['passed'] for row in result['pairs']))
        result['classification'] = 'visual-match' if result['passed'] else 'visual-differences'
    except (OSError, ValueError, KeyError, TypeError, IndexError) as error:
        result['error'] = str(error)
    return result


def responsive_editor_result(original_path, rebuilt_path, recording, recording_sha):
    result = {'complete':False, 'passed':False,
              'scope':'Controlled delivered inputs, clocks, camera receipts, RNG prefix and count, RGB hashes, and changed-save hashes. No world observer or complete RNG trace.',
              'recording_sha256':recording_sha, 'recording_fidelity':[]}
    try:
        expected_control = execution_plan({'schema':1, 'mode':'replay',
            **{key:recording[key] for key in ('duration_ms','events','contract')},
            'recording_sha256':recording_sha, 'upgrade_rule':V10_TO_V11_UPGRADE})
        captures = load_batch(original_path, True) + load_batch(rebuilt_path, False)
        for capture in captures:
            report = capture['report']
            session = report['fixture']['human']
            if (session.get('observe') or session.get('rng_only') or session.get('combat') or
                    session.get('message_noise') or report.get('observer_sha256') is not None or
                    report.get('rng_recording') is not None or report.get('human_control') != expected_control or
                    report.get('script_sha256') != expected_control['executed_script_sha256'] or
                    any(session[key] != recording[key] for key in ('duration_ms','events','contract'))):
                raise ValueError('Capture does not use the controlled responsive editor case.')
            result['recording_fidelity'].append(compare_inputs(recording['events'],inputs(report)))
        result['pairs'] = []
        for left,right in itertools.combinations(captures,2):
            row = compare_captures(left,right)
            checks = {
                'input_messages':row['inputs']['same_messages'],
                'input_boundaries':row['inputs']['exact_boundaries'],
                'camera_values':row['camera_values']['equal'],
                'camera_receipts':row['camera_receipts']['equal'],
                'terminal_boundaries':row['terminal_boundaries'][0] == row['terminal_boundaries'][1],
                'rng_prefix':row['rng_prefix']['equal'],
                'rng_counts':row['rng_total_counts'][0] == row['rng_total_counts'][1],
                'video_rgb':row['video_samples']['equal'],
                'save_outputs':row['save_outputs']['equal'],
            }
            row['checks'] = checks
            row['passed'] = all(value is True for value in checks.values())
            result['pairs'].append(row)
        result['complete'] = True
        result['passed'] = (all(row['same_messages'] for row in result['recording_fidelity']) and
                            all(row['passed'] for row in result['pairs']))
        result['classification'] = 'controlled-visual-match' if result['passed'] else 'controlled-visual-differences'
    except (OSError,ValueError,KeyError,TypeError,IndexError) as error:
        result['error'] = str(error)
    return result


def feature_fixtures():
    from feature_lab import FIXTURES, validate_fixture
    return {name: validate_fixture(path) for name, path in FIXTURES}


def controlled_result(original_path, rebuilt_path, recording, recording_sha):
    result = {'complete':False, 'passed':False, 'scope':CONTROLLED_SCOPE,
              'recording_sha256':recording_sha, 'recording_fidelity':[]}
    try:
        expected_control = execution_plan({'schema':1, 'mode':'replay',
            **{key:recording[key] for key in ('duration_ms','events','contract')},
            'recording_sha256':recording_sha,
            'upgrade_rule':V5_TO_V6_UPGRADE if recording['policy'] == V5_POLICY else V1_TO_V4_UPGRADE})
        captures = load_batch(original_path, True) + load_batch(rebuilt_path, False)
        for capture in captures:
            report = capture['report']
            session = report['fixture']['human']
            control = report.get('human_control') or {}
            if (session.get('observe') is not True or session.get('combat') is not True or session.get('rng_only') or session.get('message_noise') or
                    control.get('same_policy_replay') is not False or
                    any(control.get(key) != value for key,value in expected_control.items()) or
                    report.get('script_sha256') != expected_control['executed_script_sha256']):
                raise ValueError('The controlled case requires its pinned profile and world/RNG observers.')
            if any(session[key] != recording[key] for key in ('duration_ms','events','contract')):
                raise ValueError('Capture does not use the pinned input recording.')
            result['recording_fidelity'].append(compare_inputs(recording['events'], inputs(report)))
        result['pairs'] = [compare_repeatability(a,b) for a,b in itertools.combinations(captures,2)]
        result['complete'] = True
        result['passed'] = (all(row['same_messages'] for row in result['recording_fidelity']) and
                            all(row['passed'] for row in result['pairs']))
    except (OSError,ValueError,KeyError,TypeError,IndexError) as error:
        result['error'] = str(error)
    return result


def run_suite(output, runner=run_worker, include_editor=False, jobs=None):
    output.mkdir(parents=True, exist_ok=False)
    result = {'schema':2, 'complete':False, 'passed':False, 'scope':CONTROLLED_SCOPE, 'workers':[], 'human':{}}
    try:
        recordings = controlled_recordings()
        editor = editor_recording() if include_editor else None
        responsive_editor = responsive_editor_recording()
        feature_fixtures()
        python = str(ROOT / 'build/harness-env/Scripts/python.exe')
        scripted = output / 'scripted'
        commands = [('scripted', [python, str(ROOT / 'tools/harness/replay.py'),
            '--fixture', str(ROOT / 'config/harness/replay-random-smoke.json'),
            '--runs','3','--seconds','90','--output',str(scripted)], 780)]
        for name, path, sha, count in CONTROLLED_CASES:
            for target in ('original','rebuilt'):
                label = name + '-' + target
                commands.append((label, [python, str(ROOT / 'tools/harness/human_session.py'),
                    '--recording',str(path),'--target',target,'--runs','3','--observe','--combat',
                    '--controlled','--output',str(output / label)], 1170))
        for target in ('original','rebuilt'):
            label = 'responsive-editor-' + target
            commands.append((label, [python,str(ROOT / 'tools/harness/human_session.py'),
                '--recording',str(RESPONSIVE_EDITOR_RECORDING),'--target',target,'--runs','3',
                '--controlled','--output',str(output / label)], 1170))
        if include_editor:
            for target in ('original', 'rebuilt'):
                label = 'editor-' + target
                commands.append((label, [python, str(ROOT / 'tools/harness/human_session.py'),
                    '--recording', str(EDITOR_RECORDING), '--target', target, '--runs', '3',
                    '--output', str(output / label)], 1170))
        # Bound nested feature captures so private desktops do not starve each other.
        commands.append(('native-features', [python, str(ROOT / 'tools/harness/feature_lab.py'),
            'test-all', '--runs', '3', '--jobs', '3', '--output', str(output / 'native-features')], 3600))
        result['jobs'] = min(len(commands), jobs if jobs is not None else len(commands))
        result['workers'] = run_commands(commands, output, runner, jobs)
        try:
            result['scripted'] = json.loads((scripted / 'report.json').read_text())
        except (OSError,ValueError) as error:
            result['scripted'] = {'passed':False,'error':str(error)}
        for name, path, sha, count in CONTROLLED_CASES:
            result['human'][name] = controlled_result(output / (name + '-original/report.json'),
                output / (name + '-rebuilt/report.json'), recordings[name], sha)
        result['responsive_editor'] = responsive_editor_result(
            output / 'responsive-editor-original/report.json',
            output / 'responsive-editor-rebuilt/report.json',responsive_editor,RESPONSIVE_EDITOR_SHA256)
        if include_editor:
            result['editor'] = editor_result(output / 'editor-original/report.json',
                output / 'editor-rebuilt/report.json', editor, EDITOR_RECORDING_SHA256)
        try:
            result['features'] = json.loads((output / 'native-features/report.json').read_text())
        except (OSError,ValueError) as error:
            result['features'] = {'complete':False, 'passed':False, 'error':str(error)}
        result['complete'] = ('error' not in result['scripted'] and all(case['complete'] for case in result['human'].values()) and
                              result['responsive_editor']['complete'] and
                              (not include_editor or result['editor']['complete']) and
                              result['features'].get('complete') is True and
                              all(row['returncode'] is not None for row in result['workers']))
        result['passed'] = (result['complete'] and result['scripted'].get('passed') is True and
                            all(case['passed'] for case in result['human'].values()) and
                            result['responsive_editor']['passed'] and
                            (not include_editor or result['editor']['passed']) and
                            result['features'].get('passed') is True and
                            all(row['returncode'] == 0 for row in result['workers']))
    except (OSError,ValueError) as error:
        result['error'] = str(error)
    (output / 'report.json').write_text(json.dumps(result,indent=2)+'\n')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path)
    parser.add_argument('--check-fixtures', action='store_true', help='Check all permanent recordings and required saves without running games')
    parser.add_argument('--legacy', action='store_true', help='Run the old same-policy v1 suite instead of controlled cases')
    parser.add_argument('--editor', action='store_true', help='Also run the V7 editor input, camera, and RGB case')
    parser.add_argument('--jobs', type=int, help='Maximum independent workers to run at once; default is all workers')
    args = parser.parse_args()
    if args.jobs is not None and args.jobs < 1:
        parser.error('--jobs must be positive.')
    if args.check_fixtures:
        accepted_recording() if args.legacy else controlled_recordings()
        if not args.legacy:
            feature_fixtures()
            editor_recording()
            responsive_editor_recording()
        print('Pinned input fixtures checked; no games started.')
        return 0
    output = args.output or ROOT / 'build/runtime' / ('parity-' + stamp())
    result = (run_legacy_suite if args.legacy else run_suite)(
        output, include_editor=args.editor, jobs=args.jobs) if not args.legacy else run_legacy_suite(output, jobs=args.jobs)
    print(f'Gameplay parity: {"PASS" if result["passed"] else "FAIL"}')
    print(f'Report: {output / "report.json"}')
    return 0 if result['passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
