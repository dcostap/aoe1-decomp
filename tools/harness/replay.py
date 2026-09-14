"""Compare repeated original and rebuilt replays, checking variation separately."""
import argparse
from bisect import bisect_right
import hashlib
import json
from pathlib import Path
import struct
import sys

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
from game import ROOT, stage
from capture import capture
from behavior import first_difference, observations, validate_replay
from linker_map import parse_symbols


def recording_contract(report):
    return {**{key:report[key] for key in ('clock', 'script_sha256', 'registry_inputs', 'arguments', 'frida_version')},
            'assets':{row['path']:row['sha256'] for row in report['manifest']['copied_files_before_exe_replacement']},
            'graphics':{key:report['manifest'][key] for key in ('graphics', 'graphics_sha256', 'graphics_config_sha256')}}


def symbolize_difference(comparison, left, right):
    difference = comparison.get('first_difference') or {}
    for side, report in (('left', left), ('right', right)):
        event = difference.get(side)
        if not isinstance(event, dict) or 'stack' not in event:
            continue
        mapping = Path(report['manifest']['selected_exe']).with_name('empiresx.map')
        # The pinned beta need not equal the asset folder's source EXE.
        from game import ORIGINAL_SHA256
        if report['manifest']['selected_exe_sha256'] == ORIGINAL_SHA256:
            symbols = {}
            for path in (ROOT / 'config/functions/src').glob('*.json'):
                registry = json.loads(path.read_text())
                for va, row in registry.get('functions', {}).items():
                    if isinstance(row, dict) and row.get('symbol'):
                        symbols[int(va, 16)] = row['symbol']
        elif mapping and mapping.exists():
            symbols = {row['address']:row['symbol'] for row in parse_symbols(mapping.read_text()) if row['function']}
        else:
            symbols = {}
        addresses = sorted(symbols)
        for frame in event['stack']:
            if (frame.get('module') or '').lower() != 'empiresx.exe':
                continue
            # Both verified PE images use preferred base 00400000. RVAs exclude ASLR movement.
            address = 0x400000 + frame['rva']
            index = bisect_right(addresses, address) - 1
            if index >= 0 and address - addresses[index] < 0x4000:
                frame['nearest_symbol'] = symbols[addresses[index]]
                frame['symbol_offset'] = address - addresses[index]
        event['stack_note'] = 'Frida unwind can be partial. Names identify nearest known starts, not validated frame ownership.'


def input_receipts(report):
    return [{key:event.get(key) for key in ('step', 'message', 'value', 'parameter', 'updates')}
            for event in report['events'] if event.get('kind') == 'ui-input-consumed']


def compare_reports(left, right):
    for key in ('fixture', 'clock', 'script_sha256', 'registry_inputs', 'arguments', 'frida_version'):
        if left[key] != right[key]:
            return {'passed':False, 'classification':'incompatible', 'reason':key}
    for key in ('graphics_sha256', 'graphics_config_sha256', 'graphics'):
        if left['manifest'].get(key) != right['manifest'].get(key):
            return {'passed':False, 'classification':'incompatible', 'reason':key}
    assets = [{row['path']:row['sha256'] for row in report['manifest'].get('copied_files_before_exe_replacement', [])}
              for report in (left, right)]
    if assets[0] != assets[1] or left['manifest'].get('overrides') != right['manifest'].get('overrides'):
        return {'passed':False, 'classification':'incompatible', 'reason':'assets'}
    for report in (left, right):
        if report['errors'] or not report['shared_assets_unchanged'] or not observations(report) or not any(
                event.get('kind') == 'replay-done' for event in report['events']):
            return {'passed':False, 'classification':'incomplete', 'errors':report['errors']}
    if input_receipts(left) != input_receipts(right):
        return {'passed':False, 'classification':'input-divergence',
                'left':input_receipts(left), 'right':input_receipts(right)}
    difference = first_difference(left, right)
    return {'passed':difference is None, 'classification':'observed-match' if difference is None else 'state-divergence',
            'first_difference':difference, 'observations':[len(observations(left)), len(observations(right))]}


def first_rng_difference(left_path, right_path):
    reports = [json.loads(path.read_text()) for path in (left_path, right_path)]
    if any(not report.get('rng_recording') for report in reports):
        return {'error':'Missing RNG recording'}
    paths = [path.parent / report['rng_recording']['file'] for path, report in zip((left_path, right_path), reports)]
    for path, report in zip(paths, reports):
        record = report['rng_recording']
        if path.stat().st_size != record['records'] * 8 or hashlib.sha256(path.read_bytes()).hexdigest() != record['sha256']:
            return {'error':'RNG recording hash or length differs'}
    if reports[0]['rng_recording'] == reports[1]['rng_recording']:
        return None
    with paths[0].open('rb') as left, paths[1].open('rb') as right:
        index = 0
        while True:
            pair = [left.read(8), right.read(8)]
            if pair == [b'', b'']:
                return None
            decoded = []
            for data, report in zip(pair, reports):
                if not data:
                    decoded.append(None)
                else:
                    site, value = struct.unpack('<II', data)
                    decoded.append({'site':report['rng_recording']['sites'][str(site)], 'value':value})
            if decoded[0] != decoded[1]:
                return {'index':index, 'left':decoded[0], 'right':decoded[1]}
            index += 1


def compare_pair(left_path, right_path, left, right):
    if left is None or right is None:
        return {'passed':False, 'classification':'incomplete'}
    result = compare_reports(left, right)
    try:
        rng = first_rng_difference(left_path, right_path)
    except (OSError, ValueError, KeyError, struct.error) as error:
        rng = {'error':str(error)}
    result['first_rng_difference'] = rng
    if rng is not None:
        if 'error' in rng:
            result['classification'] = 'invalid-rng-recording'
        elif result['passed']:
            result['classification'] = 'rng-divergence'
        result['passed'] = False
    return result


def repeat_group(paths, reports):
    comparisons = [compare_pair(paths[0], path, reports[0], report) for path, report in zip(paths, reports)]
    return {'runs':len(reports), 'passed':all(row['passed'] for row in comparisons), 'comparisons':comparisons}


def batch_classification(original, rebuilt, cross):
    failures = [row['classification'] for group in (original, rebuilt) for row in group['comparisons'] if not row['passed']]
    if any(value in ('incomplete', 'invalid-rng-recording', 'incompatible') for value in failures):
        return 'incomplete-or-incompatible'
    if not original['passed'] and not rebuilt['passed']:
        return 'both-not-repeatable'
    if not original['passed']:
        return 'original-not-repeatable'
    if not rebuilt['passed']:
        return 'rebuilt-not-repeatable'
    return cross['classification']


def run(fixture, output, seconds, runs=3):
    scenario = json.loads(fixture.read_text())
    recording = scenario if 'scenario' in scenario else None
    if recording:
        if recording.get('schema') != 1 or not isinstance(recording.get('delivery'), list):
            raise ValueError('Invalid input recording.')
        scenario = recording['scenario']
    validate_replay(scenario)
    output.mkdir(parents=True, exist_ok=False)
    frozen = output / 'scenario.json'
    frozen.write_text(json.dumps(scenario, indent=2) + '\n')
    paths, reports = [], []
    targets = ['original'] * runs + ['rebuilt'] * runs
    codes = []
    for target in targets:
        runtime = stage(target)
        try:
            code = capture(runtime, seconds, frozen, 'calls')
        except Exception as error:
            code = 1
            print(f'Capture failed: {error}', flush=True)
        path = runtime / 'capture/report.json'
        paths.append(path)
        codes.append(code)
        reports.append(json.loads(path.read_text()) if path.exists() else None)
        print(f'{target}: capture exit {code}', flush=True)
    result = {'schema':2, 'runs_per_executable':runs, 'targets':targets, 'capture_exit_codes':codes,
              'captures':[str(path) for path in paths], 'passed':False,
              'scope':'Configured fields and full debug RNG sequence at selected function boundaries; not all game state'}
    result['original_repeat'] = repeat_group(paths[:runs], reports[:runs])
    result['rebuilt_repeat'] = repeat_group(paths[runs:], reports[runs:])
    result['cross_build'] = compare_pair(paths[0], paths[runs], reports[0], reports[runs])
    result['classification'] = batch_classification(result['original_repeat'], result['rebuilt_repeat'], result['cross_build'])
    result['passed'] = all(result[key]['passed'] for key in ('original_repeat', 'rebuilt_repeat', 'cross_build')) and not any(codes)
    if any(codes):
        result['classification'] = 'incomplete'
    if recording:
        result['recording_matches'] = all(report is not None and input_receipts(report) == recording['delivery'] and
                                          recording_contract(report) == recording.get('contract') for report in reports)
        if not result['recording_matches']:
            result['passed'] = False
            result['classification'] = 'recording-contract-or-input-differs'
    if reports[0] is not None and reports[runs] is not None:
        symbolize_difference(result['cross_build'], reports[0], reports[runs])
    if reports[0] is not None:
        # Contains the script and actual input receipts, never original game-state outputs.
        (output / 'recording.json').write_text(json.dumps({
            'schema':1, 'scenario':scenario, 'delivery':input_receipts(reports[0]), 'contract':recording_contract(reports[0]),
            'source_report':str(paths[0])}, indent=2) + '\n')
    (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
    print(f"Replay result: {result['classification']}\nReport: {output / 'report.json'}", flush=True)
    return 0 if result['passed'] else 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fixture', type=Path, default=ROOT/'config/harness/replay-random-smoke.json')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--seconds', type=float, default=90)
    parser.add_argument('--runs', type=int, default=3, help='Runs per executable')
    args = parser.parse_args()
    if not 1 <= args.seconds <= 300:
        parser.error('Capture deadline must be 1..300 seconds.')
    if not 3 <= args.runs <= 30:
        parser.error('Use 3..30 runs per executable.')
    return run(args.fixture, args.output, args.seconds, args.runs)


if __name__ == '__main__':
    raise SystemExit(main())
