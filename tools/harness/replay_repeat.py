"""Stress one executable's replay repeatability with serial private processes."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import json
from pathlib import Path
import sys
import time

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from game import ROOT, require_serial_jobs, run_worker, SERIAL_HARNESS_ERROR, stage
from behavior import validate_replay
from replay import compare_pair, input_receipts, recording_contract
from ui_fixture import normalize_resolution


def run(fixture, output, runs, jobs, seconds, target='original', resolution=None):
    document = json.loads(fixture.read_text())
    recording = document if isinstance(document, dict) and 'scenario' in document else None
    scenario = recording['scenario'] if recording else document
    if resolution is not None:
        scenario['resolution'] = normalize_resolution(resolution)
    validate_replay(scenario)
    output.mkdir(parents=True, exist_ok=False)
    frozen = output / 'scenario.json'
    frozen.write_text(json.dumps(scenario, indent=2) + '\n')
    require_serial_jobs(jobs)
    # Prepare first, so every serial launch uses its own runtime.
    runtimes = [stage(target, select=False) for _ in range(runs)]
    started = time.monotonic()

    def one(index):
        begin = time.monotonic() - started
        command = [str(ROOT/'build/harness-env/Scripts/python.exe'), str(ROOT/'tools/harness/capture.py'),
                   '--runtime', str(runtimes[index]), '--fixture', str(frozen.resolve()),
                   '--clock', 'calls', '--seconds', str(seconds)]
        try:
            code = run_worker(command, runtimes[index]/'hidden-worker.log', seconds + 30, False)
            error = None
        except Exception as failure:
            code, error = 1, str(failure)
        return {'index':index, 'exit_code':code, 'error':error, 'start_seconds':begin,
                'end_seconds':time.monotonic()-started,
                'report':str(runtimes[index]/'capture/report.json')}

    rows = []
    with ThreadPoolExecutor(max_workers=1) as executor:
        futures = [executor.submit(one, index) for index in range(runs)]
        for future in as_completed(futures):
            row = future.result()
            rows.append(row)
            print(f"{target} {row['index']+1}/{runs}: exit {row['exit_code']}", flush=True)
    rows.sort(key=lambda row:row['index'])
    reference_path = Path(rows[0]['report'])
    reference = json.loads(reference_path.read_text()) if reference_path.exists() else None
    for row in rows:
        path = Path(row['report'])
        current = json.loads(path.read_text()) if path.exists() else None
        if reference is None or current is None:
            row['comparison'] = {'passed':False, 'classification':'missing-capture'}
            continue
        comparison = compare_pair(reference_path, path, reference, current)
        if row['exit_code']:
            comparison['passed'] = False
        if recording and (recording.get('contract') != recording_contract(current) or
                          recording.get('delivery') != input_receipts(current)):
            comparison = {'passed':False, 'classification':'recording-contract-or-input-differs'}
        row['comparison'] = comparison
    result = {'schema':1, 'target':target, 'resolution':scenario.get('resolution'),
              'runs':runs, 'jobs':jobs, 'captures':rows,
              'passed':all(row['comparison']['passed'] for row in rows),
              'scope':'Repeatability of configured state, input delivery, full RNG sequence, and requested game-client captures'}
    (output/'report.json').write_text(json.dumps(result, indent=2) + '\n')
    print(f"{target} repeatability: {'PASS' if result['passed'] else 'FAIL'}\nReport: {output/'report.json'}", flush=True)
    return 0 if result['passed'] else 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--fixture', type=Path, default=ROOT/'config/harness/replay-random-smoke.json')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--runs', type=int, default=10)
    parser.add_argument('--jobs', type=int, default=1,
                        help='Must be 1; parallel repeat runs are disabled')
    parser.add_argument('--seconds', type=float, default=120)
    parser.add_argument('--target', choices=('original', 'rebuilt'), default='original')
    parser.add_argument('--resolution', help='Game resolution, for example 800x600')
    args = parser.parse_args()
    if args.jobs > 1:
        parser.error(SERIAL_HARNESS_ERROR)
    if not 2 <= args.runs <= 30 or not 1 <= args.jobs <= min(10, args.runs) or not 1 <= args.seconds <= 300:
        parser.error('Use 2..30 runs, 1..10 jobs no greater than runs, and 1..300 seconds.')
    return run(args.fixture, args.output, args.runs, args.jobs, args.seconds, args.target, args.resolution)


if __name__ == '__main__':
    raise SystemExit(main())
