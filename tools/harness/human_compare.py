"""Compare human replay reports without treating timing drift as proof of a game-code defect."""
import argparse
import hashlib
import json
from pathlib import Path

from human_session import compare_inputs, inputs, session_contract


def compare_rows(left, right):
    changed = [i for i in range(max(len(left),len(right)))
               if i >= len(left) or i >= len(right) or left[i] != right[i]]
    first = changed[0] if changed else None
    return {'equal':not changed,'counts':[len(left),len(right)],'different_positions':len(changed),
            'first_difference':None if first is None else {
                'index':first,'left':left[first] if first < len(left) else None,
                'right':right[first] if first < len(right) else None}}


def video_grid(rows, fps):
    """Reproduce GameVideo's integer frame grid from its pre-encode RGB hashes."""
    result = []
    previous = None
    time = 0
    for index,row in enumerate(rows):
        if row['input_frame'] != index or type(row['time_ms']) is not int or row['time_ms'] < time:
            raise ValueError('Invalid video-frame ordering.')
        time = row['time_ms']
        if time > 300000 or (index == 0 and time != 0):
            raise ValueError('Invalid video time range.')
        digest = row['rgb_sha256']
        if not isinstance(digest,str) or len(digest) != 64 or any(c not in '0123456789abcdef' for c in digest):
            raise ValueError('Invalid recorded RGB hash.')
        while len(result)*1000 < time*fps:
            result.append(previous)
        previous = (row['width'],row['height'],digest)
    if previous is None:
        raise ValueError('Missing video frames.')
    result.append(previous)
    return result


def load_capture(path):
    report = json.loads(path.read_text())
    if report['errors'] or not report.get('shared_assets_unchanged') or not (report.get('status') or {}).get('human',{}).get('stopped'):
        raise ValueError(f'Incomplete capture: {path}')
    video = report.get('video') or {}
    if type(video.get('fps')) is not int or not 1 <= video['fps'] <= 120:
        raise ValueError('Missing or invalid video metadata.')
    movie = path.with_name('video.mp4')
    digest = hashlib.sha256()
    with movie.open('rb') as stream:
        for block in iter(lambda:stream.read(1024*1024),b''):
            digest.update(block)
    if digest.hexdigest() != video.get('sha256'):
        raise ValueError(f'Video hash changed: {movie}')
    rows = [json.loads(line) for line in path.with_name('video-frames.jsonl').read_text().splitlines()]
    if len(rows) != video['input_frame_count']:
        raise ValueError('Video-frame metadata is incomplete.')
    grid = video_grid(rows,video['fps'])
    if len(grid) != video['encoded_frame_count']:
        raise ValueError('Video frame grid differs from encoder metadata.')
    return {'path':str(path),'report':report,'grid':grid}


def rng_prefix(report):
    return [dict(row,file=row['file'].replace('/','\\').lower()) for row in report['status']['rngTrace']]


def compare_captures(left,right):
    a,b = left['report'],right['report']
    if session_contract(a) != session_contract(b):
        raise ValueError('Capture starting contracts differ.')
    scenarios = [r['fixture']['human'] for r in (a,b)]
    if any(s.get('mode') != 'replay' for s in scenarios) or any(
            scenarios[0][key] != scenarios[1][key] for key in ('duration_ms','events','contract')):
        raise ValueError('Replay scripts differ.')
    if a['video']['fps'] != b['video']['fps']:
        raise ValueError('Video sampling rates differ.')
    cameras = [[row for row in r['events'] if row.get('kind') == 'human-camera'] for r in (a,b)]
    prefix = [rng_prefix(r) for r in (a,b)]
    terminal = [r['status']['human'] for r in (a,b)]
    video = compare_rows(left['grid'],right['grid'])
    if video['first_difference']:
        video['first_difference']['video_time_ms'] = video['first_difference']['index']*1000/a['video']['fps']
    video['origin_time_ms'] = [r['video_origin_time_ms'] for r in (a,b)]
    video['scope'] = 'Recorded pre-encode RGB hashes at video times, not matched simulation boundaries. Raw frames were not retained.'
    full_rng = None
    if a.get('rng_recording') and b.get('rng_recording'):
        from replay import first_rng_difference
        difference = first_rng_difference(Path(left['path']),Path(right['path']))
        if difference and 'error' in difference:
            raise ValueError(difference['error'])
        if any(r['rng_recording']['records'] != r['status']['rngCount'] for r in (a,b)):
            raise ValueError('Full RNG record counts differ from terminal counters.')
        full_rng = {'equal':difference is None,'first_difference':difference}
    return {'left':left['path'],'right':right['path'],
            'inputs':compare_inputs(inputs(a),inputs(b)),
            'camera_values':compare_rows([r['camera'] for r in cameras[0]],[r['camera'] for r in cameras[1]]),
            'camera_receipts':compare_rows(cameras[0],cameras[1]),
            'terminal_boundaries':[{key:r[key] for key in ('turn','updates','time_ms')} for r in terminal],
            'terminal_world':compare_rows([terminal[0]['world']],[terminal[1]['world']]),
            'rng_prefix':compare_rows(*prefix),
            'rng_trace_complete':[full_rng is not None or len(p) == r['status']['rngCount'] for p,r in zip(prefix,(a,b))],
            'full_rng':full_rng,
            'observer_sha256':[r.get('observer_sha256') for r in (a,b)],
            'rng_total_counts':[r['status']['rngCount'] for r in (a,b)],
            'video_samples':video}


def load_batch(path, original):
    batch = json.loads(path.read_text())
    if not batch.get('complete') or batch.get('original_only') != original or len(batch.get('runs',[])) != 3:
        raise ValueError('Expected a complete three-run batch for the selected target.')
    captures = [load_capture(Path(row['capture'])) for row in batch['runs']]
    from prepare_runtime import ORIGINAL_SHA256
    hashes = {capture['report']['manifest']['selected_exe_sha256'] for capture in captures}
    if len(hashes) != 1 or ((ORIGINAL_SHA256 in hashes) != original):
        raise ValueError('Unexpected executable identities in replay batch.')
    return captures


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--original',type=Path,required=True,help='Original three-run batch report')
    parser.add_argument('--rebuilt',type=Path,required=True,help='Rebuilt three-run batch report')
    parser.add_argument('--output',type=Path,required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True,exist_ok=False)
    result = {'schema':1,'complete':False,
              'scope':'Inputs, camera values, terminal counters, RNG prefix, full RNG when available, and video hashes. Not full hidden-state equivalence. Observer neutrality requires a separate original comparison.'}
    try:
        original = load_batch(args.original,True)
        rebuilt = load_batch(args.rebuilt,False)
        result['original_repeat'] = [compare_captures(original[0],row) for row in original[1:]]
        result['rebuilt_repeat'] = [compare_captures(rebuilt[0],row) for row in rebuilt[1:]]
        result['cross_build'] = [compare_captures(original[0],row) for row in rebuilt]
        result['complete'] = True
    except (OSError,ValueError,KeyError) as error:
        result['error'] = str(error)
    (args.output/'report.json').write_text(json.dumps(result,indent=2)+'\n')
    print(f'Comparison: {args.output / "report.json"}')
    if not result['complete']:
        print(result['error'])
    return 0 if result['complete'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
