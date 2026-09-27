"""Import deterministic-trace recordings and replay them fast on both executables.

A traced recording holds every game-clock value and message-pump result the
original returned while a person played. Replay feeds those values back, so the
game never observes wall time. Replay speed and CPU load cannot change its
state, and independent replays can run in parallel.

The recording session is the oracle. Each case replays once on the original and
once on the rebuilt executable. Both must reproduce the recorded RNG trace,
world counters, camera, and input count. The two replays must also consume the
same trace prefix and write the same saves.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import lzma
import os
from pathlib import Path
import subprocess
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from game import ROOT, stamp

# Traces are personal gameplay data: kept locally, never committed.
LOCAL_HARNESS = ROOT / 'local/harness'
TRACE_DIR = LOCAL_HARNESS / 'traces'
REGISTRY = LOCAL_HARNESS / 'traces.json'
PYTHON = ROOT / 'build/harness-env/Scripts/python.exe'
RNG_RECORD = 8
SCOPE = ('Fast deterministic-trace replay against the recorded session. Exact RNG trace, per-update RNG '
         'checkpoints, world time and object count, camera, input count, trace consumption, and every file the game wrote (saves, scenarios, ...). '
         'Heap allocations are zero-filled on both executables. No video; rerun without --fast for frames.')


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def rng_checkpoints(data, counts):
    """Return the running RNG-trace digest after each world update."""
    digest, done, result = hashlib.sha256(), 0, []
    for count in counts:
        if count < done or count * RNG_RECORD > len(data):
            raise ValueError('Update RNG counts are outside the RNG trace.')
        digest.update(data[done * RNG_RECORD:count * RNG_RECORD])
        done = count
        result.append(digest.hexdigest()[:16])
    return result


def observed(report, capture_dir):
    """Summarize one recording or replay capture for exact comparison."""
    status = report.get('status') or {}
    human = status.get('human') or {}
    rng_path = capture_dir / 'rng.bin'
    rng = rng_path.read_bytes() if rng_path.exists() else b''
    update_rows = [row for row in report.get('events', []) if row.get('kind') == 'observer-update']
    updates = [row['rng_count'] for row in update_rows]
    alloc = [row for row in report.get('events', []) if row.get('kind') == 'alloc-fill-status']
    errors = [row.get('error') or row.get('kind') for row in report.get('errors', [])]
    return {
        'rng_records': len(rng) // RNG_RECORD,
        'rng_sha256': sha256(rng),
        'rng_sites': (report.get('rng_recording') or {}).get('sites'),
        'update_rng': [[count, digest] for count, digest in zip(updates, rng_checkpoints(rng, updates))],
        # Object-state digests exist only in native replays; they compare executables, not the oracle.
        'update_state': [row.get('state_hash') for row in update_rows],
        'updates': human.get('updates'),
        'inputs': human.get('input'),
        'world': human.get('world'),
        'camera': human.get('camera'),
        'alloc': {'blocks': alloc[-1]['blocks'], 'bytes': alloc[-1]['bytes']} if alloc else None,
        'message_records': (status.get('message_replay') or {}).get('records'),
        'clock_calls': (status.get('clock_replay') or {}).get('calls'),
        'save_outputs': report.get('save_outputs'),
        'written_files': report.get('written_files'),
        'errors': errors,
    }


def oracle_from(summary):
    oracle = {key: summary[key] for key in
              ('rng_records', 'rng_sha256', 'rng_sites', 'update_rng', 'updates', 'inputs', 'world', 'camera', 'alloc')}
    # Captures before write tracking have no file oracle; their replays still compare the two executables.
    if summary.get('written_files') is not None:
        oracle['written_files'] = summary['written_files']
    return oracle


def file_set(written):
    """Comparable form of a written-files report: path to content hash, plus removed paths."""
    if written is None:
        return None
    return {'changed': {row['path']: row['sha256'] for row in written['changed']}, 'removed': sorted(written['removed'])}


def first_byte_difference(expected, actual):
    """Offset of the first differing byte, or the shorter length when one file is a prefix."""
    limit = min(len(expected), len(actual))
    step = 1 << 16
    for start in range(0, limit, step):
        end = min(start + step, limit)
        if expected[start:end] != actual[start:end]:
            return next(i for i in range(start, end) if expected[i] != actual[i])
    return None if len(expected) == len(actual) else limit


def file_differences(expected, actual, expected_bytes, actual_bytes):
    """Describe each written file whose presence or content differs, with the first differing byte."""
    rows = []
    for path in sorted(set(expected['changed']) | set(actual['changed'])):
        if expected['changed'].get(path) == actual['changed'].get(path):
            continue
        row = {'path': path, 'expected_sha256': expected['changed'].get(path),
               'actual_sha256': actual['changed'].get(path)}
        left, right = expected_bytes(path), actual_bytes(path)
        if left is not None and right is not None:
            row.update(expected_size=len(left), actual_size=len(right), first_difference=first_byte_difference(left, right))
        rows.append(row)
    for path in sorted(set(expected['removed']) ^ set(actual['removed'])):
        rows.append({'path': path, 'removed_in': 'expected' if path in expected['removed'] else 'actual'})
    return rows


def stored_output(name, path):
    stored = TRACE_DIR / name / 'outputs' / (path + '.xz')
    return lzma.decompress(stored.read_bytes()) if stored.exists() else None


def runtime_file(capture_dir, path):
    target = Path(capture_dir).parent / path
    return target.read_bytes() if target.is_file() else None


def load_registry():
    return json.loads(REGISTRY.read_text()) if REGISTRY.exists() else {'schema': 1, 'cases': {}}


def import_trace(human_dir, name):
    if not name.replace('-', '').replace('_', '').isalnum():
        raise ValueError('Use letters, digits, dashes, and underscores in the case name.')
    recording = json.loads((human_dir / 'recording.json').read_text())
    meta = recording.get('message_recording') or {}
    if (recording.get('automated_smoke') is not False or meta.get('format') != 'aoe-message-pump-v7-le' or
            not recording.get('clock_trace') or recording.get('alloc_fill') is not True):
        raise ValueError('Import needs a human recording made with record-original --deterministic-trace.')
    capture = Path(recording['source_report'])
    report = json.loads(capture.read_text())
    if report.get('errors'):
        raise ValueError('The recording capture has errors.')
    messages = (human_dir / 'messages.bin').read_bytes()
    if sha256(messages) != meta['sha256']:
        raise ValueError('messages.bin differs from its recording metadata.')
    recording['oracle'] = oracle_from(observed(report, capture.parent))
    if recording['oracle']['rng_sha256'] != sha256((human_dir / 'rng.bin').read_bytes()):
        raise ValueError('The recording RNG trace differs from its capture.')
    output = TRACE_DIR / name
    output.mkdir(parents=True, exist_ok=False)
    for row in (recording['oracle'].get('written_files') or {'changed': []})['changed']:
        data = runtime_file(capture.parent, row['path'])
        if data is None or sha256(data) != row['sha256']:
            raise ValueError(f"The recorded game output {row['path']} changed after the session.")
        target = output / 'outputs' / (row['path'] + '.xz')
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(lzma.compress(data, preset=6))
    stored = lzma.compress(json.dumps(recording, separators=(',', ':')).encode(), preset=6)
    (output / 'recording.json.xz').write_bytes(stored)
    stored_messages = lzma.compress(messages, preset=6)
    (output / 'messages.bin.xz').write_bytes(stored_messages)
    registry = load_registry()
    registry['cases'][name] = {
        'recording_sha256': sha256(stored), 'messages_sha256': sha256(stored_messages),
        'duration_ms': recording['duration_ms'], 'inputs': len(recording['events']),
        'updates': recording['oracle']['updates'], 'rng_records': recording['oracle']['rng_records'],
        'outputs': {path.relative_to(output / 'outputs').as_posix(): sha256(path.read_bytes())
                    for path in sorted((output / 'outputs').rglob('*.xz'))},
    }
    REGISTRY.write_text(json.dumps(registry, indent=2, sort_keys=True) + '\n', newline='\n')
    return registry['cases'][name]


def check_fixtures(names=None):
    registry = load_registry()
    cases = registry['cases']
    selected = names or sorted(cases)
    for name in selected:
        if name not in cases:
            raise ValueError(f'Unknown trace case: {name}')
        folder = TRACE_DIR / name
        for file, key in (('recording.json.xz', 'recording_sha256'), ('messages.bin.xz', 'messages_sha256')):
            if sha256((folder / file).read_bytes()) != cases[name][key]:
                raise ValueError(f'The {name} trace file {file} changed.')
        stored = {path.relative_to(folder / 'outputs').as_posix(): sha256(path.read_bytes())
                  for path in sorted((folder / 'outputs').rglob('*.xz'))}
        if stored != cases[name].get('outputs', {}):
            raise ValueError(f'The {name} recorded game outputs changed.')
    return {name: cases[name] for name in selected}


def first_rng_difference(left_dir, right_dir, sites, updates):
    """Locate the first differing RNG record between two replay captures."""
    left, right = (Path(left_dir) / 'rng.bin').read_bytes(), (Path(right_dir) / 'rng.bin').read_bytes()
    limit = min(len(left), len(right)) // RNG_RECORD
    for index in range(limit):
        a, b = left[index * 8:index * 8 + 8], right[index * 8:index * 8 + 8]
        if a != b:
            break
    else:
        if len(left) == len(right):
            return None
        index = limit

    def record(data):
        if index * 8 + 8 > len(data):
            return None
        site = int.from_bytes(data[index * 8:index * 8 + 4], 'little')
        return {'site': (sites or {}).get(str(site), site), 'value': int.from_bytes(data[index * 8 + 4:index * 8 + 8], 'little')}
    update = next((number for number, (count, _) in enumerate(updates, 1) if count > index), None)
    return {'record': index, 'world_update': update, 'original': record(left), 'rebuilt': record(right)}


def compare(oracle, run):
    checks = {'completed': not run['errors']}
    for key in ('rng_records', 'rng_sha256', 'updates', 'inputs', 'world', 'camera'):
        checks[key] = run[key] == oracle[key]
    if 'written_files' in oracle:
        checks['written_files'] = file_set(run.get('written_files')) == file_set(oracle['written_files'])
    first = next((number for number, (want, got) in enumerate(zip(oracle['update_rng'], run['update_rng']), 1)
                  if want != got), None)
    if first is None and len(run['update_rng']) != len(oracle['update_rng']):
        first = min(len(run['update_rng']), len(oracle['update_rng'])) + 1
    return {'checks': checks, 'passed': all(checks.values()), 'first_update_difference': first}


def replay_command(recording, target, output):
    return [str(PYTHON), str(ROOT / 'tools/harness/human_session.py'), '--recording', str(recording),
            '--target', target, '--runs', '1', '--fast', '--observe', '--rng-only', '--output', str(output)]


def run_suite(output, names=None, jobs=None):
    output.mkdir(parents=True, exist_ok=False)
    result = {'schema': 1, 'scope': SCOPE, 'complete': False, 'passed': False, 'cases': {}}
    try:
        cases = check_fixtures(names)
        if not cases:
            result.update(complete=True, skipped=f'No traced recordings in {REGISTRY}.')
            (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
            return result
        work = [(name, target) for name in cases for target in ('original', 'rebuilt')]
        jobs = jobs or max(1, min(len(work), (os.cpu_count() or 2) // 2))
        result['jobs'] = jobs

        def one(name, target):
            folder = output / f'{name}-{target}'
            seconds = cases[name]['duration_ms'] / 1000 * 3 + 240
            with (output / f'{name}-{target}.log').open('w') as log:
                try:
                    code = subprocess.run(replay_command(TRACE_DIR / name / 'recording.json.xz', target, folder),
                                          cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, timeout=seconds).returncode
                except subprocess.TimeoutExpired:
                    code = None
            return name, target, code, folder

        runs = {}
        with ThreadPoolExecutor(max_workers=jobs) as executor:
            futures = [executor.submit(one, name, target) for name, target in work]
            for future in as_completed(futures):
                name, target, code, folder = future.result()
                runs[(name, target)] = (code, folder)
                print(f'Trace replay {name} {target}: exit {code}', flush=True)
        for name in cases:
            recording = json.loads(lzma.decompress((TRACE_DIR / name / 'recording.json.xz').read_bytes()))
            oracle = recording['oracle']
            case = {'runs': {}}
            dirs, states = {}, {}
            for target in ('original', 'rebuilt'):
                code, folder = runs[(name, target)]
                try:
                    session = json.loads((folder / 'report.json').read_text())
                    capture = Path(session['runs'][0]['capture']) if session.get('runs') and session['runs'][0] else None
                    if capture is None:
                        raise ValueError(session.get('error') or 'Replay produced no capture.')
                    summary = observed(json.loads(capture.read_text()), capture.parent)
                    dirs[target] = capture.parent
                except (OSError, ValueError, KeyError, TypeError) as error:
                    summary = {'errors': [str(error)], 'update_rng': []}
                    for key in ('rng_records', 'rng_sha256', 'updates', 'inputs', 'world', 'camera'):
                        summary[key] = None
                row = compare(oracle, summary)
                states[target] = summary.get('update_state') or []
                row.update(returncode=code, errors=summary['errors'], capture=str(dirs.get(target, folder)),
                           alloc=summary.get('alloc'),
                           trace_consumed={'message_records': summary.get('message_records'),
                                           'clock_calls': summary.get('clock_calls')},
                           save_outputs=summary.get('save_outputs'), written_files=summary.get('written_files'))
                if row['checks'].get('written_files') is False and target in dirs:
                    row['written_file_differences'] = file_differences(
                        file_set(oracle['written_files']), file_set(summary.get('written_files')),
                        lambda path: stored_output(name, path),
                        lambda path, capture_dir=dirs[target]: runtime_file(capture_dir, path))
                row['passed'] = row['passed'] and code == 0
                case['runs'][target] = row
            original, rebuilt = case['runs']['original'], case['runs']['rebuilt']
            case['cross'] = {
                'same_trace_consumed': original['trace_consumed'] == rebuilt['trace_consumed'],
                'same_save_outputs': original['save_outputs'] == rebuilt['save_outputs'],
                'same_written_files': file_set(original['written_files']) == file_set(rebuilt['written_files']),
                # Reported, not gated: library allocations can differ without game-visible state.
                'same_allocations': original['alloc'] == rebuilt['alloc'],
            }
            # First completed update whose object-state digest differs between executables.
            case['first_state_difference'] = next(
                (number for number, (a, b) in enumerate(zip(states['original'], states['rebuilt']), 1) if a != b),
                None if len(states['original']) == len(states['rebuilt']) else
                min(len(states['original']), len(states['rebuilt'])) + 1)
            if len(dirs) == 2 and not rebuilt['checks'].get('rng_sha256', False):
                case['first_rng_difference'] = first_rng_difference(
                    dirs['original'], dirs['rebuilt'], oracle.get('rng_sites'), oracle['update_rng'])
            if not case['cross']['same_written_files'] and len(dirs) == 2 and                     original['written_files'] is not None and rebuilt['written_files'] is not None:
                case['written_file_differences'] = file_differences(
                    file_set(original['written_files']), file_set(rebuilt['written_files']),
                    lambda path: runtime_file(dirs['original'], path), lambda path: runtime_file(dirs['rebuilt'], path))
            case['passed'] = (original['passed'] and rebuilt['passed'] and case['cross']['same_trace_consumed'] and
                              case['cross']['same_save_outputs'] and case['cross']['same_written_files'])
            result['cases'][name] = case
        result['complete'] = True
        result['passed'] = all(case['passed'] for case in result['cases'].values())
    except (OSError, ValueError) as error:
        result['error'] = str(error)
    (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    subs = parser.add_subparsers(dest='command', required=True)
    p = subs.add_parser('import', help='Add a deterministic-trace human recording as a permanent case')
    p.add_argument('recording_dir', type=Path, help='build/runtime/human-* folder holding recording.json')
    p.add_argument('--name', required=True)
    p = subs.add_parser('check', help='Check pinned trace fixtures without starting games')
    p.add_argument('--case', action='append')
    p = subs.add_parser('run', help='Replay traced cases on both executables and compare with the recordings')
    p.add_argument('--case', action='append', help='Run only this case; repeatable')
    p.add_argument('--jobs', type=int, help='Parallel game processes; default half the logical CPUs')
    p.add_argument('--output', type=Path)
    args = parser.parse_args()
    if args.command == 'import':
        row = import_trace(args.recording_dir.resolve(), args.name)
        print(f'Imported {args.name}: {json.dumps(row)}')
        return 0
    if args.command == 'check':
        cases = check_fixtures(args.case)
        print(f'Trace fixtures checked: {len(cases)}; no games started.')
        return 0
    if args.jobs is not None and args.jobs < 1:
        parser.error('--jobs must be positive.')
    output = args.output or ROOT / 'build/runtime' / ('traces-' + stamp())
    result = run_suite(output, args.case, args.jobs)
    for name, case in result['cases'].items():
        line = 'PASS' if case['passed'] else 'FAIL'
        detail = {'first_state_difference': case.get('first_state_difference'),
                  'first_rng_difference': case.get('first_rng_difference') or {
                      target: run['first_update_difference'] for target, run in case['runs'].items()
                      if run['first_update_difference']}}
        files = {target: run['written_file_differences'] for target, run in case['runs'].items()
                 if run.get('written_file_differences')}
        if case.get('written_file_differences'):
            files['original_vs_rebuilt'] = case['written_file_differences']
        if files:
            detail['written_files'] = files
        print(f'{name}: {line}' + (f' {json.dumps(detail)}' if not case['passed'] else ''))
    if result.get('error'):
        print(f"Error: {result['error']}")
    if result.get('skipped'):
        print(f"Trace parity: SKIPPED ({result['skipped']})")
        print(f'Report: {output / "report.json"}')
        return 0
    print(f'Trace parity: {"PASS" if result["passed"] else "FAIL"}')
    print(f'Report: {output / "report.json"}')
    return 0 if result['passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
