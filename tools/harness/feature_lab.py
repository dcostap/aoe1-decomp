"""Generate, inspect, and compare a native game feature map. Outputs stay under build/."""
from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import gzip
import hashlib
import itertools
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import threading

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
from game import ROOT, stage, stamp, run_worker
from capture import hook_config, save_frame
from prepare_runtime import digest, ORIGINAL_SHA256
import registry_state

PROFILE = 'feature-lab-idle20-clock1-paint-v1'
DEFAULT_FIXTURE = ROOT / 'config/harness/feature_lab'
FIXTURES = (('civilizations-1-8', DEFAULT_FIXTURE),
            ('civilizations-9-16', ROOT / 'config/harness/feature_lab_9_16'),
            ('chaos-battle', ROOT / 'config/harness/feature_lab_chaos'))
# One setup script owns the map-building calls. buildFeatureMap and issueFeatureOrders
# are the whole contract between a layout and the shared control scripts.
LAYOUTS = {'features': 'feature_lab_setup.js', 'chaos': 'feature_lab_chaos_setup.js'}
SCRIPT_NAMES = ('menu.js', 'offline.js', 'feature_lab.js',
                'feature_lab_control.js', 'feature_lab_observe.js')


def script_names(layout):
    if layout not in LAYOUTS:
        raise ValueError('Unknown feature-lab layout: ' + str(layout))
    return SCRIPT_NAMES[:3] + (LAYOUTS[layout],) + SCRIPT_NAMES[3:]
# Registry identities, not inferred addresses. hook_config verifies image entry bytes
# and resolves rebuilt symbols through the hash-checked linker map.
APIS = {
    'editor': ('tribegam', '00528DE0'), 'new_map': ('scr_sed', '004AD340'),
    'get_player': ('basegame', '00420330'), 'create': ('tplayer', '00512F60'),
    'save': ('world', '00543770'), 'load': ('tribegam', '00526170'),
    'camera': ('player', '004704C0'), 'relation': ('player', '00470BE0'),
    'visible': ('player', '00471BF0'), 'terrain': ('map', '00459A00'),
    'work': ('Command', '00435620'), 'move': ('Command', '00435810'),
    'world_update': ('world', '00542ED0'), 'editor_quit': ('scr_sed', '004AD6A0'),
    'map_visible': ('map', '00455890'), 'map_fog': ('map', '004558A0'),
    'modify_percent': ('stat_obj', '004C4E90'), 'attribute': ('tplayer', '00519570'),
    'train': ('tcommand', '0050A7F0'), 'research': ('tcommand', '0050A8D0'),
    'build': ('tcommand', '0050A9B0'), 'unload': ('tcommand', '0050B330'),
    'save_scenario': ('world', '00543A00'),
    'new_scenario': ('world', '00542BF0'),
    'technology': ('tech', '0050C5E5'),
    'draw_object': ('stat_obj', '004C1F30'),
    'repair': ('tcommand', '0050B290'),
    'cancel_build': ('tplayer', '00515180'),
    'elevation': ('map', '004595E0'),
    'redraw': ('scr_game', '004959A0'),
    'civilization_effect': ('teffects', '0050D550'),
    'placement': ('m_s_obj', '00453C40'),
}


def write_json(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')


def validate_fixture(folder):
    fixture = json.loads((folder / 'fixture.json').read_text())
    if not isinstance(fixture, dict) or type(fixture.get('schema')) is not int or \
            fixture.get('schema') != 2 or fixture.get('name') != 'feature_lab.gmx' or \
            fixture.get('original_sha256') != ORIGINAL_SHA256:
        raise ValueError('Invalid feature-lab fixture identity.')
    if fixture.get('layout', 'features') not in LAYOUTS:
        raise ValueError('Invalid feature-lab layout: ' + str(fixture.get('layout')))
    if not isinstance(fixture.get('metadata'), dict) or set(fixture['metadata']) != {'setup.json', 'catalog.json'}:
        raise ValueError('Invalid feature-lab metadata manifest.')
    path = folder / fixture['name']
    if path.is_symlink() or path.stat().st_size != fixture.get('size') or digest(path) != fixture.get('sha256'):
        raise ValueError('Feature-lab save hash or size differs.')
    for name in ('setup.json', 'catalog.json'):
        path = folder / name
        if path.is_symlink() or digest(path) != fixture.get('metadata', {}).get(name):
            raise ValueError('Feature-lab metadata differs: ' + name)
    return fixture


def stage_fixture(target, fixture_folder):
    fixture = validate_fixture(fixture_folder)  # Reject changed inputs before staging or starting a game.
    runtime = stage(target)
    destination = runtime / 'savegame' / fixture['name']
    if destination.exists():
        raise ValueError('Feature-lab save already exists in the new runtime.')
    shutil.copy2(fixture_folder / fixture['name'], destination)
    if digest(destination) != fixture['sha256']:
        raise ValueError('Feature-lab save copy differs.')
    path = runtime / 'runtime_manifest.json'
    manifest = json.loads(path.read_text())
    is_original = manifest.get('selected_exe_sha256') == ORIGINAL_SHA256
    if is_original != (target == 'original'):
        raise ValueError('The selected executable does not match the requested target.')
    manifest['savegame_source'] = 'feature-lab-fixture'
    manifest['feature_lab'] = fixture
    for name in ('setup.json', 'catalog.json'):
        shutil.copy2(fixture_folder / name, runtime / ('feature_lab_' + name))
    manifest['copied_files_before_exe_replacement'].append(dict(
        path='savegame/' + fixture['name'], sha256=fixture['sha256'], size=fixture['size'], method='copy'))
    write_json(path, manifest)
    return runtime


def worker(runtime, output, mode, turns, visible=False, civilization_offset=0, layout='features'):
    import frida
    from game_video import GameVideo
    if not visible and not os.environ.get('AOE1_HARNESS_DESKTOP'):
        raise ValueError('Use a private desktop worker, or explicitly request --visible.')
    manifest = json.loads((runtime / 'runtime_manifest.json').read_text())
    if mode == 'generate' and manifest['selected_exe_sha256'] != ORIGINAL_SHA256:
        raise ValueError('Generate reference saves with the original executable.')
    for name, key in [('ddraw.dll', 'graphics_sha256'), ('ddraw.ini', 'graphics_config_sha256')]:
        if digest(runtime / name) != manifest[key]:
            raise ValueError(f'Graphics input changed: {name}')
    if mode == 'replay':
        row = manifest['feature_lab']
        layout = row.get('layout', 'features')
        if digest(runtime / 'savegame' / row['name']) != row['sha256']:
            raise ValueError('Staged feature-lab save changed.')
        for name, sha256 in row['metadata'].items():
            if digest(runtime / ('feature_lab_' + name)) != sha256:
                raise ValueError('Staged feature-lab metadata changed: ' + name)
    needed = APIS if mode == 'generate' else {name: APIS[name] for name in ('load', 'get_player', 'camera', 'world_update', 'unload', 'draw_object', 'redraw', 'work')}
    probes = [dict(name=name, module=module, va=va) for name, (module, va) in needed.items()]
    cfg = hook_config(runtime / 'empiresx.exe', manifest, True, probes)
    cfg.update(clockMode='calls', actions=[], maxFrames=120, human={},
               generator={'seed': 24681357, 'size': 240, 'civilization_offset': civilization_offset},
               lab={'mode': mode, 'turns': turns, 'profile': PROFILE, 'layout': layout})
    if mode == 'replay':
        cfg['lab']['setup'] = json.loads((runtime / 'feature_lab_setup.json').read_text())
    folder = Path(__file__).parent
    template = '\n'.join((folder / name).read_text() for name in script_names(layout))
    key = pid = session = None
    registry = actual = None
    device = frida.get_local_device()
    done = threading.Event()
    events, errors, frames, states = [], [], [], []
    rng_sites, rng_records = {}, 0
    video_origin = None
    video_report = None
    lock = threading.Lock()
    finalizing = False
    from feature_lab_coverage import Coverage
    coverage = Coverage(cfg['lab']['setup']) if mode == 'replay' else None
    output.mkdir(parents=True, exist_ok=True)
    video = GameVideo(output)
    video.MAX_SECONDS = 900  # This separate profile can have long debug-clock traces.
    rng_file = (output / 'rng.bin').open('xb')
    state_file = gzip.open(output / 'states.jsonl.gz', 'xb')
    try:
        key, registry, _ = registry_state.create()
        cfg['registryBase'] = key
        source = template.replace('__CONFIG__', json.dumps(cfg))
        (output / 'instrumentation.js').write_text(source)
        (output / 'worker-source.py').write_bytes(Path(__file__).read_bytes())
        pid = device.spawn([str(runtime / 'empiresx.exe'), 'NOSTARTUP', 'GAMECD', 'NOSOUND', 'NOMUSIC'],
                           cwd=str(runtime), env=dict(os.environ, __COMPAT_LAYER=''))
        session = device.attach(pid)
        session.on('detached', lambda *args: done.set())
        desktop = session.create_script((folder / 'desktop.js').read_text())
        desktop.load()
        actual = desktop.exports_sync.desktop()
        if os.environ.get('AOE1_HARNESS_DESKTOP') and actual != os.environ['AOE1_HARNESS_DESKTOP']:
            raise ValueError('Game did not inherit its private desktop.')
        script = session.create_script(source)

        def message(msg, data):
            nonlocal video_origin, rng_records
            with lock:
                if finalizing:
                    return
                try:
                    if msg['type'] != 'send':
                        errors.append(msg)
                        done.set()
                        return
                    row = msg['payload']
                    kind = row.get('kind')
                    if kind == 'lab-state':
                        if coverage:
                            coverage.observe(row)
                        encoded = json.dumps(row, sort_keys=True, separators=(',', ':')).encode() + b'\n'
                        state_file.write(encoded)
                        row = {k: row[k] for k in ('kind', 'phase', 'turn', 'updates', 'ticks', 'calls', 'rng', 'clockSites', 'world')}
                        row['sha256'] = hashlib.sha256(encoded).hexdigest()
                        states.append(row)
                    if kind == 'frame':
                        if video_origin is None:
                            video_origin = row['time_ms']
                        video.add(dict(row, time_ms=row['time_ms'] - video_origin), bytes(data))
                        # Keep occasional lossless inspection images as well as every raw RGB hash.
                        if not frames or any(e.get('kind') == 'lab-tour' for e in events[-2:]) or mode == 'generate':
                            if len(frames) < 300 or mode != 'generate':
                                save_frame(output, row, bytes(data))
                        frames.append(row)
                    if kind == 'replay-rng-site':
                        if row['id'] in rng_sites:
                            raise ValueError('Duplicate RNG site ID.')
                        rng_sites[row['id']] = row['site']
                    if kind == 'replay-rng-batch':
                        if len(data) != row['records'] * 8:
                            raise ValueError('Invalid RNG batch size.')
                        rng_file.write(data)
                        rng_records += row['records']
                    events.append(row)
                    if kind in ('lab-progress', 'lab-done', 'lab-error'):
                        print(json.dumps({k: v for k, v in row.items() if k != 'status'}), flush=True)
                    if kind in ('lab-done', 'lab-error'):
                        if row.get('error'):
                            errors.append(row)
                        done.set()
                    if kind in ('capture-error', 'ui-error') or (
                        kind == 'exception' and row.get('code') != 0xe06d7363):
                        errors.append(row)
                        done.set()
                except Exception as error:
                    errors.append({'error': str(error)})
                    done.set()

        script.on('message', message)
        script.load()
        device.resume(pid)
        if not done.wait(240):
            errors.append({'error': 'Worker exceeded its wall-clock deadline.'})
    finally:
        if pid is not None:
            try:
                device.kill(pid)
            except frida.ProcessNotFoundError:
                pass
        if session is not None:
            try:
                session.detach()
            except frida.InvalidOperationError:
                pass
        if key:
            registry_state.cleanup(key)
        with lock:
            finalizing = True
            rng_file.close()
            state_file.close()
            try:
                video_report = video.close()
            except Exception as error:
                errors.append({'error': 'Video finalization failed: ' + str(error)})
        completed = [e for e in events if e.get('kind') == 'lab-done']
        status = completed[0]['status'] if len(completed) == 1 else None
        if not status:
            errors.append({'error': 'Worker did not reach its terminal boundary.'})
        else:
            if status['registryRedirects'] != 3 or status['mutexRedirects'] != 1:
                errors.append({'error': 'Runtime isolation checks failed.'})
            graphics = [m for m in status['modules'] if m['name'].lower() == 'ddraw.dll']
            if len(graphics) != 1 or Path(graphics[0]['path']).resolve() != runtime / 'ddraw.dll':
                errors.append({'error': 'Game did not load the pinned graphics DLL.'})
            if status['rngCount'] != rng_records:
                errors.append({'error': 'Full RNG trace is incomplete.'})
            if status['lab']['calls'] <= 0 or sum(status['lab']['clockSites']) != status['lab']['calls'] or \
                    status['ticks'] != 1000 + status['lab']['turn']*20 + status['lab']['calls']:
                errors.append({'error': 'Controlled clock or its call-site trace is incomplete.'})
            if not states or not any(e.get('kind') == 'lab-world' for e in events):
                errors.append({'error': 'World observations are incomplete.'})
            if mode == 'replay' and states[-1]['phase'] != 'terminal':
                errors.append({'error': 'Terminal state observation is missing.'})
            entries = [e for e in events if e.get('kind') == 'lab-world']
            leaves = [s for s in states if s['phase'] == 'leave']
            if len(entries) != len(leaves) or len(leaves) != status['lab']['updates']:
                errors.append({'error': 'World entry and exit counts differ.'})
            if mode == 'replay' and digest(runtime / 'savegame/feature_lab.gmx') != manifest['feature_lab']['sha256']:
                errors.append({'error': 'Replay changed its reference save.'})
        for row in manifest['copied_files_before_exe_replacement']:
            if row['method'] == 'hardlink' and digest(Path(manifest['source_directory']) / row['path']) != row['sha256']:
                errors.append({'error': 'Shared input changed.', 'path': row['path']})
        report = dict(schema=1, profile=PROFILE, mode=mode, turns=turns, runtime=str(runtime),
                      manifest=manifest, configuration=cfg, events=events, errors=errors, status=status,
                      frames=frames, states=states, video=video_report, registry_inputs=registry, desktop=actual,
                      video_frames_sha256=digest(output / 'video-frames.jsonl') if (output / 'video-frames.jsonl').exists() else None,
                      script_sha256=hashlib.sha256(template.encode()).hexdigest(), frida_version=frida.__version__,
                      rng_recording=dict(file='rng.bin', records=rng_records, sites=rng_sites, sha256=digest(output / 'rng.bin')),
                      state_recording=dict(file='states.jsonl.gz', samples=len(states), sha256=digest(output / 'states.jsonl.gz')),
                      passed=bool(status) and not errors,
                      scope='Defined world, object, action, and player fields; complete debug RNG and raw RGB samples. Not complete game state.')
        if coverage:
            report['coverage'] = coverage.result()
            drawn = next((e['objects'] for e in events if e.get('kind') == 'lab-draw-summary'), [])
            missing = [r['label'] for r in cfg['lab']['setup']['placed'] if r['label'].startswith('catalog-') and r['id'] not in drawn]
            report['coverage']['catalog']['not_drawn'] = missing
            report['coverage']['passed'] &= not missing
        write_json(output / 'report.json', report)
    if report['passed'] and mode == 'generate':
        source_save = runtime / 'savegame/feature_lab.gmx'
        shutil.copy2(source_save, output / source_save.name)
        setup = next(e for e in events if e.get('kind') == 'lab-setup')
        write_json(output / 'setup.json', setup)
        write_json(output / 'catalog.json', [e for e in events if e.get('kind') == 'lab-catalog'])
        write_json(output / 'fixture.json', dict(schema=2, name=source_save.name, layout=layout,
                   sha256=digest(source_save), size=source_save.stat().st_size,
                   original_sha256=ORIGINAL_SHA256, generator_sha256=report['script_sha256'],
                   generator=cfg['generator'], metadata={name:digest(output/name) for name in ('setup.json','catalog.json')}))
    return 0 if report['passed'] else 1


def first_difference(left, right):
    for index, (a, b) in enumerate(itertools.zip_longest(left, right)):
        if a != b:
            return {'index': index, 'left': a, 'right': b}
    return None


def validate_capture(report):
    if report.get('passed') is not True or report.get('errors') != [] or report.get('mode') != 'replay':
        raise ValueError('Incomplete replay.')
    status, states = report['status'], report['states']
    control = status['lab']
    if control['calls'] <= 0 or sum(control['clockSites']) != control['calls'] or \
            status['ticks'] != 1000 + control['turn'] * 20 + control['calls']:
        raise ValueError('Controlled clock trace is incomplete.')
    if not states or states[-1]['phase'] != 'terminal' or \
            control['turn'] - control['loadedTurn'] != report['turns']:
        raise ValueError('Terminal boundary is incomplete.')
    entries = sum(e.get('kind') == 'lab-world' for e in report['events'])
    leaves = sum(s['phase'] == 'leave' for s in states)
    if not entries or entries != leaves or leaves != control['updates'] or \
            len(states) != report['state_recording']['samples'] or \
            status['rngCount'] != report['rng_recording']['records']:
        raise ValueError('World or RNG observations are incomplete.')
    if not report.get('script_sha256') or not report.get('frida_version') or \
            report.get('profile') != PROFILE or not report.get('frames'):
        raise ValueError('Capture identity or frames are missing.')


def compare_pair(left_path, right_path):
    from replay import first_rng_difference
    a, b = [json.loads(path.read_text()) for path in (left_path, right_path)]
    for report in (a, b):
        validate_capture(report)
    for key in ('profile', 'mode', 'turns', 'script_sha256', 'registry_inputs', 'frida_version'):
        if a.get(key) != b.get(key):
            return {'passed': False, 'error': 'Incompatible ' + key}
    for key in ('feature_lab', 'graphics_sha256', 'graphics_config_sha256', 'copied_files_before_exe_replacement'):
        if a['manifest'].get(key) != b['manifest'].get(key):
            return {'passed': False, 'error': 'Incompatible runtime input: ' + key}
    state = first_difference(a['states'], b['states'])
    kinds = ('lab-world', 'lab-tour', 'lab-loaded', 'lab-command', 'lab-clock-site', 'lab-draw-summary')
    observations = first_difference([e for e in a['events'] if e.get('kind') in kinds],
                                   [e for e in b['events'] if e.get('kind') in kinds])
    rng = first_rng_difference(left_path, right_path)
    video_rows = []
    for path, report in ((left_path, a), (right_path, b)):
        state_file = path.parent / report['state_recording']['file']
        if digest(state_file) != report['state_recording']['sha256']:
            return {'passed': False, 'error': 'State recording changed'}
        video_file = path.parent / 'video-frames.jsonl'
        if digest(video_file) != report['video_frames_sha256']:
            raise ValueError('Video sample recording changed.')
        rows = [json.loads(line) for line in video_file.read_text().splitlines()]
        if len(rows) != report['video']['input_frame_count'] or len(rows) != len(report['frames']):
            raise ValueError('Video samples are incomplete.')
        video_rows.append(rows)
    images = first_difference(video_rows[0], video_rows[1])
    rgb = first_difference([row['rgb_sha256'] for row in video_rows[0]], [row['rgb_sha256'] for row in video_rows[1]])
    clocks = first_difference([a['status']['ticks'], a['status']['lab']], [b['status']['ticks'], b['status']['lab']])
    return dict(passed=not any((state, observations, rng, images, clocks)), state=state, observations=observations,
                rng=rng, images=images, rgb=rgb, clocks=clocks)


def run_one(output, mode, target='original', fixture=None, turns=800, civilization_offset=0, layout='features'):
    output.mkdir(parents=True, exist_ok=False)
    runtime = stage('original') if mode == 'generate' else stage_fixture(target, fixture)
    command = [str(ROOT / 'build/harness-env/Scripts/python.exe'), str(Path(__file__).resolve()), 'worker',
               '--runtime', str(runtime), '--output', str(output), '--mode', mode, '--turns', str(turns),
               '--civilization-offset', str(civilization_offset), '--layout', layout]
    return run_worker(command, output / 'worker.log', 270, False)


def test_all(output, runs=3, turns=800, jobs=None):
    for _, fixture in FIXTURES:
        validate_fixture(fixture)
    output.mkdir(parents=True, exist_ok=False)
    cases = {}
    if jobs is not None and jobs < 1:
        raise ValueError('The feature-lab worker count must be positive.')
    worker_count = min(len(FIXTURES), jobs if jobs is not None else len(FIXTURES))

    def one(name, fixture):
        destination = output / name
        command = [sys.executable, str(Path(__file__).resolve()), 'test',
                   '--fixture', str(fixture), '--output', str(destination), '--runs', str(runs),
                   '--turns', str(turns)]
        if jobs is not None:
            command += ['--jobs', str(jobs)]
        code = subprocess.run(command, cwd=ROOT).returncode
        try:
            result = json.loads((destination / 'report.json').read_text())
        except (OSError, ValueError) as error:
            result = dict(passed=False, error=str(error))
        return name, dict(returncode=code, report=str(destination / 'report.json'),
                          complete=result.get('complete') is True,
                          passed=code == 0 and result.get('passed') is True)

    with ThreadPoolExecutor(max_workers=worker_count) as executor:
        futures = [executor.submit(one, name, fixture) for name, fixture in FIXTURES]
        for future in as_completed(futures):
            name, row = future.result()
            cases[name] = row
    cases = {name: cases[name] for name, _ in FIXTURES}
    report = dict(schema=1, jobs=worker_count, cases=cases,
                  complete=all(row['complete'] for row in cases.values()),
                  passed=all(row['passed'] for row in cases.values()))
    write_json(output / 'report.json', report)
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='command', required=True)
    for name, help_text in [('generate', 'Generate a reference save with the original game.'),
                            ('replay', 'Load a feature save and record its camera tour.'),
                            ('test', 'Compare original and rebuilt repeats without tolerances.')]:
        p = sub.add_parser(name, help=help_text)
        p.add_argument('--output', type=Path, default=ROOT / 'build/feature-lab' / stamp())
        if name != 'generate':
            p.add_argument('--fixture', type=Path, default=DEFAULT_FIXTURE)
            p.add_argument('--turns', type=int, default=800)
        else:
            p.add_argument('--civilization-offset', type=int, choices=(0,8), default=0,
                           help='Use civilizations 1-8 or 9-16. The engine has eight player slots.')
            p.add_argument('--layout', choices=tuple(LAYOUTS), default='features',
                           help='feature map kind: feature lanes or a chaos battle')
        if name == 'replay':
            p.add_argument('--target', choices=('original', 'rebuilt'), default='original')
        if name == 'test':
            p.add_argument('--runs', type=int, choices=(2, 3), default=3)
            p.add_argument('--jobs', type=int, help='Maximum feature-lab captures to start at once; default is all captures')
    p = sub.add_parser('open', help='Stage a private game. Load feature_lab from its Load Game menu.')
    p.add_argument('--fixture', type=Path, default=DEFAULT_FIXTURE)
    p.add_argument('--target', choices=('original', 'rebuilt'), default='original')
    p.add_argument('--prepare-only', action='store_true')
    p = sub.add_parser('test-all', help='Compare both civilization sets. Keep later cases after a failure.')
    p.add_argument('--output', type=Path, default=ROOT / 'build/feature-lab' / stamp())
    p.add_argument('--runs', type=int, choices=(2,3), default=3)
    p.add_argument('--turns', type=int, default=800)
    p.add_argument('--jobs', type=int, help='Maximum feature-lab workers to start at once; default is all workers')
    p = sub.add_parser('worker', help='Internal private-desktop worker.')
    p.add_argument('--runtime', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--mode', choices=('generate', 'replay'), required=True)
    p.add_argument('--turns', type=int, default=800)
    p.add_argument('--civilization-offset', type=int, choices=(0,8), default=0)
    p.add_argument('--layout', choices=tuple(LAYOUTS), default='features')
    p.add_argument('--visible', action='store_true')
    args = parser.parse_args()
    if hasattr(args, 'turns') and not 100 <= args.turns <= 3000:
        parser.error('Use 100 through 3000 idle turns.')
    if args.command == 'worker':
        return worker(args.runtime.resolve(), args.output.resolve(), args.mode, args.turns, args.visible,
                      args.civilization_offset, args.layout)
    if args.command == 'open':
        runtime = stage_fixture(args.target, args.fixture.resolve())
        print('Select Single Player > Load Game > feature_lab.')
        if args.prepare_only:
            return 0
        # This path runs the game without instrumentation. Put the machine's settings back.
        before = registry_state.live_values()
        try:
            return subprocess.run([str(runtime / 'empiresx.exe'), 'NOSTARTUP', 'GAMECD'], cwd=runtime,
                                  env=dict(os.environ, __COMPAT_LAYER='')).returncode
        finally:
            registry_state.restore(before)
    output = args.output.resolve()
    if not output.is_relative_to((ROOT / 'build').resolve()):
        parser.error('Generated output must stay under build/.')
    if args.command == 'test-all':
        if args.jobs is not None and args.jobs < 1:
            parser.error('--jobs must be positive.')
        return 0 if test_all(output, args.runs, args.turns, args.jobs)['passed'] else 1
    if args.command == 'generate':
        return run_one(output, 'generate', civilization_offset=args.civilization_offset, layout=args.layout)
    fixture = args.fixture.resolve()
    validate_fixture(fixture)
    if args.command == 'replay':
        return run_one(output, 'replay', args.target, fixture, args.turns)
    output.mkdir(parents=True, exist_ok=False)
    captures, codes, targets = [], [], ['original'] * args.runs + ['rebuilt'] * args.runs
    if args.jobs is not None and args.jobs < 1:
        parser.error('--jobs must be positive.')
    worker_count = min(len(targets), args.jobs if args.jobs is not None else len(targets))
    completed = [None] * len(targets)

    def one(index, target):
        path = output / f'{index:02d}-{target}'
        try:
            code = run_one(path, 'replay', target, fixture, args.turns)
            error = None
        except Exception as failure:
            code, error = 1, str(failure)
        return index, path, code, error

    with ThreadPoolExecutor(max_workers=worker_count) as executor:
        futures = [executor.submit(one, index, target) for index, target in enumerate(targets)]
        for future in as_completed(futures):
            index, path, code, error = future.result()
            completed[index] = (path, code, error)
            print(f'{targets[index]} {index + 1}/{len(targets)}: worker exit {code}', flush=True)
    captures = [path / 'report.json' for path, _, _ in completed]
    codes = [code for _, code, _ in completed]
    pairs = []
    for left, right in itertools.combinations(range(len(captures)), 2):
        try:
            comparison = compare_pair(captures[left], captures[right])
        except (OSError, ValueError, KeyError) as error:
            comparison = {'passed': False, 'error': str(error)}
        pairs.append(dict(left=left, right=right, **comparison))
    result = dict(schema=1, jobs=worker_count, captures=[str(p) for p in captures], targets=targets, exit_codes=codes,
                  pairs=pairs, complete=not any(codes) and all('error' not in p for p in pairs),
                  comparison_passed=not any(codes) and all(p['passed'] for p in pairs))
    result['coverage'] = []
    for path in captures:
        try:
            result['coverage'].append(json.loads(path.read_text()).get('coverage', {}))
        except (OSError, ValueError) as error:
            result['coverage'].append(dict(passed=False, error=str(error)))
    result['coverage_passed'] = all(row.get('passed') is True for row in result['coverage'])
    result['passed'] = result['comparison_passed'] and result['coverage_passed']
    write_json(output / 'report.json', result)
    print(f"Feature-lab pairs: {sum(p['passed'] for p in pairs)}/{len(pairs)}")
    return 0 if result['passed'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
