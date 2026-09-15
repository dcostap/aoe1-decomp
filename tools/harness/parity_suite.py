"""Run the standard gameplay parity suite, including the accepted human recording."""
import argparse
import hashlib
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from game import ROOT, run_worker, stamp
from human_session import load_recording, compare_inputs, inputs
from human_compare import load_batch, compare_captures

RECORDING = ROOT / 'config/harness/human-accepted-20260914.json'
RECORDING_SHA256 = 'a320c5d68b8b6f2e49d5d9963e60bc3455c177deac2909d5795ab19e02510e4d'
SCOPE = ('Exact observed comparisons, including clock differences. No pixel masks or timing tolerances. '
         'Full RNG capture uses the read-only observer. Observer neutrality and full hidden-state equivalence remain unproved.')


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


def run_suite(output, runner=run_worker):
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
        for name, command, timeout in commands:
            row = {'name': name, 'command': command, 'returncode': None}
            result['workers'].append(row)
            try:
                row['returncode'] = runner(command, output / (name + '.log'), timeout, False)
            except OSError as error:
                row['error'] = str(error)
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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path)
    parser.add_argument('--check-fixtures', action='store_true', help='Check the permanent recording without running games')
    args = parser.parse_args()
    if args.check_fixtures:
        accepted_recording()
        print(f'Accepted human fixture: 324 messages; SHA256 {RECORDING_SHA256}')
        return 0
    output = args.output or ROOT / 'build/runtime' / ('parity-' + stamp())
    result = run_suite(output)
    print(f'Gameplay parity: {"PASS" if result["passed"] else "FAIL"}')
    print(f'Report: {output / "report.json"}')
    return 0 if result['passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
