"""Run the game UI main menu tests against fresh original and rebuilt processes."""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import fnmatch
import hashlib
import json
from pathlib import Path
import re
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import game
from capture import capture
from compare import compare
from ui_fixture import normalize_resolution, validate_steps

SUITE = game.ROOT / 'config/harness/game-ui-main-menu.json'


def load_suite(path=SUITE, patterns=()):
    suite = json.loads(path.read_text())
    ids = [case['id'] for case in suite['cases']]
    if len(ids) != len(set(ids)) or any(not re.fullmatch('[a-z0-9-]+', name) for name in ids):
        raise ValueError('Suite IDs must be unique, safe directory names.')
    cases = [case for case in suite['cases'] if not patterns or
             any(fnmatch.fnmatchcase(case['id'], pattern) for pattern in patterns)]
    if not cases:
        raise ValueError('No capture test matched the selection.')
    for case in cases:
        steps = suite['routes'][case['route']] + case['steps']
        validate_steps(steps)
        names = [step['name'] for step in steps]
        if not names or len(names) != len(set(names)):
            raise ValueError('Checkpoint names must be nonempty and unique within each test.')
    return suite, cases


def compare_checkpoints(left, right, output):
    a, b = (json.loads(path.read_text()) for path in (left, right))
    ca, cb = a['status']['ui']['checkpoints'], b['status']['ui']['checkpoints']
    if [c['name'] for c in ca] != [c['name'] for c in cb] or not ca:
        raise ValueError('Checkpoint sequences differ or are empty.')
    output.mkdir(parents=True, exist_ok=False)
    results = []
    for index, (x, y) in enumerate(zip(ca, cb)):
        folder = output / f'{index:03d}'
        code = compare(left, right, folder, x['frame'], y['frame'], compare_rng=False)
        state_match = x['panel'] == y['panel'] and x['controls'] == y['controls']
        rng_match = (x['rngCount'] == len(x['rngTrace']) and y['rngCount'] == len(y['rngTrace']) and
                     x['rngTrace'] == y['rngTrace'])
        from PIL import Image, ImageChops
        with Image.open(left.parent / x['composite']) as ax, Image.open(right.parent / y['composite']) as bx:
            ax, bx = ax.convert('RGB'), bx.convert('RGB')
            if ax.size != bx.size:
                raise ValueError('Checkpoint image dimensions differ.')
            if any(hashlib.sha256(image.tobytes()).hexdigest() != checkpoint['rgb_sha256']
                   for image, checkpoint in ((ax, x), (bx, y))):
                raise ValueError('Checkpoint image hash does not match its report.')
            delta = ImageChops.difference(ax, bx)
            composite_match = delta.getbbox() is None
            delta.save(folder / 'composite-difference.png')
            pair = Image.new('RGB', (ax.width * 2, ax.height))
            pair.paste(ax, (0,0)); pair.paste(bx, (ax.width,0))
            pair.save(folder / 'composite-side-by-side.png')
        results.append({'name': x['name'], 'pixels_passed': code == 0,
                        'controls_passed': state_match, 'rng_passed': rng_match,
                        'composite_passed': composite_match, 'evidence': str(folder)})
        (folder / 'controls.json').write_text(json.dumps({'left': x, 'right': y,
                                                          'match': state_match}, indent=2) + '\n')
    result = {'passed': all(r['pixels_passed'] and r['controls_passed'] and r['composite_passed'] and r['rng_passed'] for r in results),
              'checkpoints': results}
    (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


def run_case(case, definition, folder, original_runs=2, visible=False, resolution=None):
    """Run one UI case in one worker-owned desktop."""
    fixture = folder / 'fixture.json'
    fixture.write_text(json.dumps({'name': case['id'], 'ui': True,
        'resolution': normalize_resolution(resolution),
        'steps': definition['routes'][case['route']] + case['steps']}, indent=2) + '\n')
    row = {'id': case['id'], 'captures': [], 'comparisons': [], 'passed': False}
    print(f"UI test: {case['id']}", flush=True)
    try:
        for target in ['original'] * original_runs + ['rebuilt']:
            runtime = game.stage(target, select=False)
            code = capture(runtime, case.get('seconds', 20), fixture, 'calls', visible)
            missing = [name for name in case.get('files_exist', []) if not (runtime / name).is_file()]
            row['captures'].append({'target': target, 'report': str(runtime / 'capture/report.json'),
                                    'returncode': code if not missing else 1, 'missing_files': missing})
        if case.get('expect_blocked'):
            row['kind'] = 'safety guard'
            row['passed'] = all(guard_passed(Path(c['report']), case['expect_blocked'])
                                for c in row['captures'])
        elif row['captures'][0]['returncode'] == 0:
            reference = Path(row['captures'][0]['report'])
            for index, other in enumerate(row['captures'][1:]):
                if other['returncode'] != 0:
                    continue
                comparison = folder / f'comparison-{index:02d}'
                compared = compare_checkpoints(reference, Path(other['report']), comparison)
                row['comparisons'].append({'target': other['target'], 'report': str(comparison / 'report.json'),
                                           'passed': compared['passed']})
            row['passed'] = (all(c['returncode'] == 0 for c in row['captures']) and
                             all(c['passed'] for c in row['comparisons']))
    except Exception as error:
        row['error'] = str(error)
    print(f"UI result: {case['id']}: {'PASS' if row['passed'] else 'FAIL'}", flush=True)
    return row


def run_case_file(case_file, output, original_runs=2, visible=False):
    """Internal entry point for one nested UI worker."""
    payload = json.loads(case_file.read_text())
    row = run_case(payload['case'], payload['definition'], output, original_runs, visible,
                   payload.get('resolution'))
    (output / 'case-report.json').write_text(json.dumps(row, indent=2) + '\n')
    return 0 if row['passed'] else 1


def run(output, patterns=(), original_runs=2, visible=False, jobs=None, resolution=None):
    definition, cases = load_suite(patterns=patterns)
    selected_resolution = normalize_resolution(
        resolution if resolution is not None else definition.get('resolution'))
    if jobs is not None and jobs < 1:
        raise ValueError('The UI worker count must be positive.')
    game.require_serial_jobs(jobs)
    output.mkdir(parents=True, exist_ok=False)
    (output / 'suite.json').write_text(json.dumps(definition, indent=2) + '\n')
    result = {'group': definition['name'], 'resolution': selected_resolution,
              'scope': 'Named menu checkpoints: pixels, palette, RNG, and selected control state',
              'original_runs': original_runs, 'jobs': 1,
              'cases': [None] * len(cases), 'passed': False}
    report = output / 'report.json'
    # Runtime harnesses stay serial until the parallel drift is understood.
    worker_count = 1

    def one(index, case):
        folder = output / case['id']
        folder.mkdir()
        case_file = folder / 'case.json'
        case_file.write_text(json.dumps({'case': case, 'definition': definition,
                                         'resolution': selected_resolution}, indent=2) + '\n')
        if visible:
            return index, run_case(case, definition, folder, original_runs, True,
                                  selected_resolution)
        python = str(game.ROOT / 'build/harness-env/Scripts/python.exe')
        command = [python, str(Path(__file__).resolve()),
                   '--case-file', str(case_file), '--output', str(folder),
                   '--original-runs', str(original_runs)]
        timeout = (case.get('seconds', 20) + 20) * (original_runs + 1) + 60
        try:
            code = game.run_worker(command, output / (case['id'] + '.hidden-worker.log'),
                                   timeout, False)
            case_report = folder / 'case-report.json'
            row = json.loads(case_report.read_text()) if case_report.exists() else {
                'id': case['id'], 'captures': [], 'comparisons': [], 'passed': False,
                'error': f'Case worker returned {code} without a case report.'}
            if code != 0 and row.get('passed'):
                row['passed'] = False
                row['error'] = f'Case worker returned {code}.'
            return index, row
        except Exception as error:
            return index, {'id': case['id'], 'captures': [], 'comparisons': [],
                           'passed': False, 'error': str(error)}

    try:
        with ThreadPoolExecutor(max_workers=worker_count) as executor:
            futures = [executor.submit(one, index, case) for index, case in enumerate(cases)]
            for future in as_completed(futures):
                index, row = future.result()
                result['cases'][index] = row
                report.write_text(json.dumps(result, indent=2) + '\n')
                print(f"UI result: {row['id']}: {'PASS' if row['passed'] else 'FAIL'}", flush=True)
        result['passed'] = all(row['passed'] for row in result['cases'])
        return 0 if result['passed'] else 1
    finally:
        report.write_text(json.dumps(result, indent=2) + '\n')
        print(f'UI suite report: {report}', flush=True)


def guard_passed(path, expected):
    report = json.loads(path.read_text())
    return (len(report['errors']) == 1 and report['errors'][0].get('kind') == 'forbidden-gameplay' and
            report['errors'][0].get('boundary') == expected and
            any(e.get('kind') == 'forbidden-gameplay' and e.get('boundary') == expected
                for e in report['events']))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--jobs', type=int, default=1,
                        help='Must be 1; parallel UI cases are disabled')
    parser.add_argument('--case-file', type=Path, help=argparse.SUPPRESS)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--case', action='append', default=[])
    parser.add_argument('--original-runs', type=int, choices=(1, 2, 3), default=2)
    parser.add_argument('--resolution', help='Game resolution, for example 800x600')
    parser.add_argument('--visible', action='store_true')
    args = parser.parse_args()
    if args.jobs is not None and args.jobs < 1:
        parser.error('--jobs must be positive.')
    if args.jobs is not None and args.jobs > 1:
        parser.error(game.SERIAL_HARNESS_ERROR)
    if args.case_file:
        return run_case_file(args.case_file, args.output, args.original_runs, args.visible)
    return run(args.output, args.case, args.original_runs, args.visible, args.jobs, args.resolution)


if __name__ == '__main__':
    raise SystemExit(main())
