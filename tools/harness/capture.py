"""Capture menu surfaces at verified Paint entries. This is not full game replay."""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import struct
import sys
import threading
import time

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
from linker_map import parse_symbols, unique_addresses
from prepare_runtime import ORIGINAL_SHA256, digest
import registry_state
from ui_fixture import validate_steps


def hook_config(exe: Path, manifest: dict, ui=False, probes=()):
    image = exe.read_bytes()
    if hashlib.sha256(image).hexdigest() != manifest['selected_exe_sha256']:
        raise ValueError('Runtime EXE hash changed.')
    addresses = {'paint': 0x00443520, 'clock': 0x004231E0,
                 'rand': 0x004230A0, 'srand': 0x00423140,
                 'run': 0x0041CFD0, 'idle': 0x00529610,
                 'wndproc': 0x0041E7A0, 'panelSystem': 0x0062E870}
    ui_symbols = {}
    if ui:
        # Reviewed registry identities; the original executable remains the behavior oracle.
        for module, names in {
            'tribegam': {'start_game': 'forbidStart', 'load_game': 'forbidLoad',
                         'start_scenario': 'forbidScenario', 'start_scenario_editor': 'forbidEditor'},
            'Pnl_drop': {'draw': 'dropDraw'}, 'pnl_btn': {'draw': 'buttonDraw'},
            'Pnl_lst': {'draw': 'listDraw'}, 'Pnl_txt': {'draw': 'textDraw'},
            'Pnl_edit': {'draw': 'editDraw'},
            'Pnl_scbr': {'draw': 'scrollDraw'},
        }.items():
            registry = json.loads((TOOLS.parent / f'config/functions/src/{module}.cpp.json').read_text())
            entries = registry.get('functions', registry)
            for name, key in names.items():
                matches = [(va, row['symbol']) for va, row in entries.items()
                           if isinstance(row, dict) and row.get('symbol', '').startswith('?' + name + '@')]
                if len(matches) != 1:
                    raise ValueError(f'Ambiguous UI identity: {module}:{name}')
                va, symbol = matches[0]
                addresses[key], ui_symbols[key] = int(va, 16), symbol
    for probe in probes:
        registry = json.loads((TOOLS.parent / f"config/functions/src/{probe['module']}.cpp.json").read_text())
        symbol = registry['functions'][probe['va']]['symbol']
        key = 'probe_' + probe['name']
        addresses[key], ui_symbols[key] = int(probe['va'], 16), symbol
    if manifest['selected_exe_sha256'] != ORIGINAL_SHA256:
        selected = Path(manifest['selected_exe'])
        report = json.loads(selected.with_name('report.json').read_text())
        mapping = selected.with_name('empiresx.map')
        if report.get('artifact_sha256', {}).get('empiresx.exe') != digest(exe) or \
                report.get('artifact_sha256', {}).get('empiresx.map') != digest(mapping):
            raise ValueError('Rebuilt EXE or map differs from the build report.')
        symbols = unique_addresses(parse_symbols(mapping.read_text(errors='replace')))
        for key, symbol in {
            'paint': '?Paint@TDrawSystem@@QAEXPAUtagRECT@@@Z',
            'clock': '?debug_timeGetTime@@YAKPADH@Z',
            'rand': '?debug_rand@@YAHPADH@Z',
            'srand': '?debug_srand@@YAXPADHI@Z',
            'run': '?run@RGE_Base_Game@@UAEHXZ',
            'idle': '?handle_idle@TRIBE_Game@@UAEHXZ',
            'wndproc': '?rge_base_game_wnd_proc@@YGJPAXIIJ@Z',
            'panelSystem': '?panel_system@@3VTPanelSystem@@A',
        }.items():
            addresses[key] = symbols[symbol]
        for key, symbol in ui_symbols.items():
            addresses[key] = symbols[symbol]
    pe = struct.unpack_from('<I', image, 0x3c)[0]
    count, optional_size = struct.unpack_from('<H', image, pe + 6)[0], struct.unpack_from('<H', image, pe + 20)[0]
    image_base = struct.unpack_from('<I', image, pe + 24 + 28)[0]
    result = {}
    def file_offset(rva):
        for index in range(count):
            section = pe + 24 + optional_size + index * 40
            _, start, size, offset = struct.unpack_from('<IIII', image, section + 8)
            if start <= rva < start + size:
                return offset + rva - start
        raise ValueError('PE RVA does not map to file data.')
    if ui:
        # Frida 17.8 reports the same slot for distinct imports in this image.
        # Resolve each actual IAT slot from the hash-checked PE import descriptors instead.
        result['inputIAT'] = {}
        descriptor = file_offset(struct.unpack_from('<I', image, pe + 24 + 104)[0])
        while any(image[descriptor:descriptor+20]):
            original_thunk, _, _, _, first_thunk = struct.unpack_from('<IIIII', image, descriptor)
            table = file_offset(original_thunk or first_thunk)
            index = 0
            while True:
                thunk = struct.unpack_from('<I', image, table + index * 4)[0]
                if not thunk:
                    break
                if not thunk & 0x80000000:
                    start = file_offset(thunk) + 2
                    name = image[start:image.index(b'\0', start)].decode('ascii')
                    if name in ('GetKeyState', 'GetAsyncKeyState', 'GetCursorPos'):
                        if name in result['inputIAT']:
                            raise ValueError('Duplicate input import identity.')
                        result['inputIAT'][name] = first_thunk + index * 4
                index += 1
            descriptor += 20
        if len(result['inputIAT']) != 3 or len(set(result['inputIAT'].values())) != 3:
            raise ValueError('Expected three separate game input import slots.')
    for key, address in addresses.items():
        rva = address - image_base
        if key == 'panelSystem':
            result[key] = {'rva': rva}
            continue
        for index in range(count):
            section = pe + 24 + optional_size + index * 40
            _, section_rva, size, offset = struct.unpack_from('<IIII', image, section + 8)
            if section_rva <= rva and rva + 16 <= section_rva + size:
                start = offset + rva - section_rva
                result[key] = {'rva': rva, 'bytes': list(image[start:start + 16])}
                break
        else:
            raise ValueError(f'{key} address does not map to file bytes.')
    return result


def save_frame(output: Path, meta: dict, data: bytes):
    from PIL import Image
    width, height, pitch = meta['width'], meta['height'], meta['pitch']
    if len(data) != pitch * height + 1024:
        raise ValueError('Frame payload size differs from its descriptor.')
    pixels = b''.join(data[y*pitch:y*pitch+width] for y in range(height))
    palette = data[pitch*height:]
    rgb = bytes(channel for i in range(256) for channel in palette[i*4:i*4+3])
    image = Image.frombytes('P', (width, height), pixels)
    image.putpalette(rgb)
    name = f"frame-{meta['count']:04d}"
    image.save(output / (name + '.png'))
    (output / (name + '.bin')).write_bytes(data)
    return dict(meta, pixel_sha256=hashlib.sha256(pixels).hexdigest(),
                palette_sha256=hashlib.sha256(palette).hexdigest(),
                rgb_sha256=hashlib.sha256(image.convert('RGB').tobytes()).hexdigest(), file=name+'.png')


def capture(runtime: Path, seconds: float, fixture: Path | None = None, clock='real', visible=False):
    runtime = runtime.resolve()
    if not visible and not os.environ.get('AOE1_HARNESS_DESKTOP'):
        raise ValueError('Use game.cmd capture for a private desktop, or explicitly supply --visible.')
    import frida
    manifest = json.loads((runtime / 'runtime_manifest.json').read_text())
    if manifest.get('graphics') != 'cnc-ddraw':
        raise ValueError('This initial capture requires the pinned memory-backed graphics wrapper.')
    for filename, key in [('ddraw.dll', 'graphics_sha256'), ('ddraw.ini', 'graphics_config_sha256')]:
        if digest(runtime / filename) != manifest[key]:
            raise ValueError(f'{filename} differs from the runtime manifest.')
    scenario = json.loads(fixture.read_text()) if fixture else {
        'name': 'main-menu', 'expected_panel': 'Main Menu', 'actions': []}
    ui = scenario.get('ui', False)
    if ui:
        validate_steps(scenario.get('steps'))
    replay = scenario.get('replay')
    human = scenario.get('human')
    human_control = None
    if human:
        from human_session import V1_POLICY, execution_plan, validate_session
        validate_session(human)
        human_control = execution_plan(human)
        original_target = human.get('target','original') == 'original'
        if replay or ui or (manifest['selected_exe_sha256'] == ORIGINAL_SHA256) != original_target or clock != 'calls':
            raise ValueError('Human recording requires the selected executable and controlled-clock profile.')
    if 'replay' in scenario:
        from behavior import validate_replay
        validate_replay(scenario)
    probes = replay['probes'] if replay else ([{'name':'human_world','module':'world','va':'00542ED0'},
        {'name':'human_camera','module':'player','va':'004704C0'}] if human else ())
    observe = bool(human and human.get('observe'))
    if observe and human.get('combat'):
        probes += [{'name':'observer_attack','module':'com_obj','va':'00430230'},
                   {'name':'observer_attack_update','module':'act_atak','va':'00401780'},
                   {'name':'observer_sprite_add','module':'asp_list','va':'0041A910'},
                   {'name':'observer_actor_update','module':'act_obj','va':'00406A70'}]
    elif observe and not human.get('rng_only'):
        probes += [{'name':'observer_add','module':'world','va':'00545E00'},
                   {'name':'observer_remove','module':'world','va':'00545FD0'},
                   {'name':'observer_pick','module':'diam_map','va':'00438530'}]
    config = hook_config(runtime / 'empiresx.exe', manifest, ui or bool(human), probes)
    config['replay'] = replay
    config['human'] = human
    config['humanControl'] = human_control
    config['actions'] = scenario.get('actions', [])
    config['uiSteps'] = scenario.get('steps', [])
    config['maxFrames'] = 40 if replay else (480 if ui else 120)
    config['clockMode'] = clock
    for action in config['actions']:
        if not 1 <= action['after_paint'] <= 120 or not 1 <= action['key'] <= 255:
            raise ValueError('Fixture action is outside the supported range.')
    output = runtime / 'capture'
    output.mkdir(exist_ok=False)
    legacy_template = None
    if human and human_control['recorded_policy'] == V1_POLICY:
        legacy_template = Path(__file__).with_name('human-v1-template.js').read_text()
        if hashlib.sha256(legacy_template.encode()).hexdigest() != human_control['recorded_script_sha256']:
            raise ValueError('Frozen v1 human control template changed.')
    if human and human_control['executed_policy'] == V1_POLICY:
        template = legacy_template
    else:
        template = (Path(__file__).with_name('menu.js')).read_text()
        if ui:
            template += '\n' + Path(__file__).with_name('offline.js').read_text()
            template += '\n' + Path(__file__).with_name('ui.js').read_text()
        if replay:
            template += '\n' + Path(__file__).with_name('replay.js').read_text()
        if human:
            template += '\n' + Path(__file__).with_name('offline.js').read_text()
            template += '\n' + Path(__file__).with_name('human.js').read_text()
    template_sha256 = hashlib.sha256(template.encode()).hexdigest()
    if human and template_sha256 != human_control['executed_script_sha256']:
        raise ValueError('Selected human control template differs from its policy hash.')
    observer = Path(__file__).with_name('human_observe.js').read_text() if observe else ''
    video = None
    video_report = None
    video_origin = None
    video_finalized = False
    native_frames = []
    if human:
        from game_video import GameVideo
        video = GameVideo(output, fps=20)
    events, frames, errors = [], [], []
    rng_digest, rng_records, rng_sites = hashlib.sha256(), 0, {}
    rng_file = (output / 'rng.bin').open('wb') if replay or observe else None
    lock = threading.Lock()
    stopped = threading.Event()
    finished = threading.Event()
    status = None
    device = frida.get_local_device()
    pid = None
    session = None
    arguments = ['NOSTARTUP', 'GAMECD', 'NOSOUND', 'NOMUSIC']
    started = time.monotonic()
    registry_base = None
    registry_snapshot = None
    process_desktop = None
    game_job = None
    try:
        registry_base, registry_snapshot = registry_state.create()
        if human and human.get('contract'):
            from human_session import verify_starting_contract
            verify_starting_contract(human, {'clock':clock, 'registry_inputs':registry_snapshot,
                'arguments':arguments, 'frida_version':frida.__version__, 'manifest':manifest})
        config['registryBase'] = registry_base
        source = template.replace('__CONFIG__', json.dumps(config))
        if observer:
            source += '\n' + observer
        (output / 'instrumentation.js').write_text(source)
        (output / 'capture-tool.py').write_bytes(Path(__file__).read_bytes())
        pid = device.spawn([str(runtime / 'empiresx.exe'), *arguments], cwd=str(runtime),
                           env=dict(os.environ, __COMPAT_LAYER=''))
        if human:
            from human_session import GameJob
            game_job = GameJob(pid)
        session = device.attach(pid)
        session.on('detached', lambda *args: (stopped.set(), finished.set()))
        desktop_probe = session.create_script(Path(__file__).with_name('desktop.js').read_text())
        desktop_probe.load()
        process_desktop = desktop_probe.exports_sync.desktop()
        expected_desktop = os.environ.get('AOE1_HARNESS_DESKTOP')
        if expected_desktop and process_desktop != expected_desktop:
            raise ValueError('Game did not inherit the private desktop. Refusing to resume it.')
        script = session.create_script(source)
        def message(msg, data):
            nonlocal rng_records, video_origin
            with lock:
                if human and video_finalized:
                    return
                try:
                    if msg['type'] == 'send':
                        row = msg['payload']
                        if row.get('kind') == 'observer-events':
                            batch = row['events']
                            if not isinstance(batch,list) or not 1 <= len(batch) <= 128:
                                raise ValueError('Invalid diagnostic event batch.')
                            events.extend(batch)
                            return
                        if row.get('kind') == 'replay-rng-site':
                            if row['id'] in rng_sites:
                                raise ValueError('Duplicate RNG site ID.')
                            rng_sites[row['id']] = row['site']
                            encoded = json.dumps(row['site'], sort_keys=True, separators=(',', ':')).encode()
                            rng_digest.update(b'S' + struct.pack('<I', len(encoded)) + encoded)
                        if row.get('kind') == 'replay-rng-batch':
                            if len(data) != row['records'] * 8:
                                raise ValueError('Invalid RNG batch length.')
                            rng_file.write(data)
                            # Hash complete records. Batch boundaries do not affect the digest.
                            for index in range(0, len(data), 8):
                                rng_digest.update(b'R' + data[index:index+8])
                            rng_records += row['records']
                            row['through_record'] = rng_records
                        if row.get('kind') == 'behavior-state':
                            row['rng_sha256'] = rng_digest.hexdigest()
                            row['rng_count'] = rng_records
                        events.append(row)
                        if row.get('kind') == 'human-native-frame':
                            native_frames.append({'rect':row['rect'], 'bgrx':bytes(data)})
                        if row.get('kind') == 'human-done':
                            if row.get('error'):
                                errors.append(row)
                            finished.set()
                        if row.get('kind') == 'ui-native-frame':
                            from PIL import Image
                            name = f"native-{row['step']:03d}-{len(events):04d}.png"
                            image = Image.frombytes('RGB', (row['rect'][2], row['rect'][3]), data, 'raw', 'BGRX')
                            image.save(output / name)
                            row['file'] = name
                            row['rgb_sha256'] = hashlib.sha256(image.tobytes()).hexdigest()
                        if row.get('kind') in ('ui-done', 'replay-done', 'replay-error'):
                            finished.set()
                        if row.get('kind') == 'replay-error':
                            errors.append(row)
                        if row.get('kind') in ('ui-error', 'forbidden-gameplay'):
                            errors.append(row)
                            finished.set()
                        if row.get('kind') == 'frame':
                            if human:
                                if video_origin is None:
                                    video_origin = row['time_ms']
                                video.add(dict(row, time_ms=row['time_ms']-video_origin, overlays=list(native_frames)), data)
                                native_frames.clear()
                                frames.append(row)
                            else:
                                frames.append(save_frame(output, row, data))
                        elif row.get('kind') == 'capture-error':
                            errors.append(row)
                            if human:
                                finished.set()
                        elif row.get('kind') == 'exception':
                            # Log first-chance MSVC exceptions without treating a caught throw as a crash.
                            # The handler returns false; Windows still handles or terminates the process.
                            if row.get('type') != 'system' or row.get('code') != 0xe06d7363:
                                errors.append(row)
                    else:
                        errors.append(msg)
                        if human:
                            finished.set()
                except Exception as error:
                    errors.append({'error': str(error)})
                    if human:
                        finished.set()
        script.on('message', message)
        script.load()
        if not any(row.get('kind') == 'ready' for row in events):
            # load() completes script evaluation; let the message callback drain.
            for _ in range(100):
                if events or errors:
                    break
                time.sleep(.01)
        if errors or not any(row.get('kind') == 'ready' for row in events):
            raise ValueError(f'Instrumentation did not initialize: {errors}')
        device.resume(pid)
        finished.wait(seconds)
        terminal = next((row for row in events if row.get('kind') in ('replay-done', 'replay-error', 'human-done')), None)
        if terminal:
            status = terminal['status']  # The terminal boundary parks the game thread until cleanup.
        elif any(row.get('kind') == 'forbidden-gameplay' for row in events):
            pass  # The blocked game thread cannot advance. Kill it without requesting RPC state.
        elif human:
            errors.append({'error':'Human session stopped before its terminal Paint boundary.'})
        elif not stopped.is_set():
            status = script.exports_sync.status()
            if status['registryRedirects'] != 3:
                errors.append({'error': 'Expected three private game registry handles.'})
            if status['mutexRedirects'] != 1:
                errors.append({'error': 'Expected one private game instance mutex.'})
            loaded_graphics = [row for row in status['modules'] if row['name'].lower() == 'ddraw.dll']
            if len(loaded_graphics) != 1 or Path(loaded_graphics[0]['path']).resolve() != (runtime / 'ddraw.dll'):
                errors.append({'error': 'The pinned runtime graphics DLL was not loaded.'})
            if not replay and status['count'] > config['maxFrames']:
                errors.append({'error': 'Frame limit reached; final capture would be incomplete.'})
            if status['posted'] != len(config['actions']):
                errors.append({'error': 'Not all fixture inputs reached their Paint boundary.'})
            if scenario.get('expected_panel') and status['panel'] != scenario['expected_panel']:
                errors.append({'error': 'Expected menu was not reached.', 'actual': status['panel']})
            expected = [(message, action['key']) for action in config['actions'] for message in (0x100, 0x101)]
            consumed = [(row['message'], row['key']) for row in events if row.get('kind') == 'input-consumed']
            if consumed != expected:
                if not ui:
                    errors.append({'error': 'Consumed keys differ from the fixture.', 'consumed': consumed})
            if ui and not replay and not status.get('ui', {}).get('done'):
                errors.append({'error': 'UI steps did not complete.', 'ui': status.get('ui')})
        else:
            errors.append({'error': 'Game exited before the capture deadline.'})
        if replay and not any(row.get('kind') == 'replay-done' for row in events):
            errors.append({'error': 'Replay did not reach its terminal boundary.'})
        if replay and status:
            expected_captures = replay.get('captures', [])
            captured = status.get('ui', {}).get('checkpoints', [])
            if [row.get('name') for row in captured] != [row['name'] for row in expected_captures]:
                errors.append({'error': 'Replay capture checkpoints are incomplete.'})
            if status['registryRedirects'] != 3 or status['mutexRedirects'] != 1:
                errors.append({'error': 'Replay isolation checks failed.'})
            graphics = [m for m in status['modules'] if m['name'].lower() == 'ddraw.dll']
            if len(graphics) != 1 or Path(graphics[0]['path']).resolve() != runtime / 'ddraw.dll':
                errors.append({'error': 'Replay did not load its pinned graphics DLL.'})
            if status['rngCount'] != rng_records:
                errors.append({'error': 'Replay RNG trace is incomplete.'})
        if human and status:
            if status['registryRedirects'] != 3 or status['mutexRedirects'] != 1:
                errors.append({'error':'Human session isolation checks failed.'})
            graphics = [m for m in status['modules'] if m['name'].lower() == 'ddraw.dll']
            if len(graphics) != 1 or Path(graphics[0]['path']).resolve() != runtime / 'ddraw.dll':
                errors.append({'error':'Human session did not load its pinned graphics DLL.'})
            if observe:
                summaries = [row for row in events if row.get('kind') == 'observer-summary']
                if len(summaries) != 1 or summaries[0]['records'] != rng_records or status['rngCount'] != rng_records:
                    errors.append({'error':'Full human RNG trace is incomplete.'})
                observed = [row for row in events if row.get('kind') in ('observer-world','observer-object','observer-pick','observer-camera','observer-combat','observer-attack-update','observer-sprite','observer-villager')]
                if len(summaries) != 1 or summaries[0]['events'] != len(observed) or any(
                        row.get('sequence') != index+1 or not 0 <= row.get('rng_count',-1) <= rng_records
                        for index,row in enumerate(observed)):
                    errors.append({'error':'Human diagnostic event trace is incomplete.'})
    finally:
        if game_job:
            game_job.close()
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
        if registry_base is not None:
            registry_state.cleanup(registry_base)
        if rng_file:
            rng_file.close()
        if video:
            with lock:
                video_finalized = True
                try:
                    video_report = video.close()
                except Exception as error:
                    errors.append({'error':'Video finalization failed: ' + str(error)})
        changed_assets = [row['path'] for row in manifest['copied_files_before_exe_replacement']
                          if row['method'] == 'hardlink' and
                          digest(Path(manifest['source_directory']) / row['path']) != row['sha256']]
        if changed_assets:
            errors.append({'error': 'Shared source assets changed.', 'paths': changed_assets})
        with lock:
            if ui and status:
                from PIL import Image
                for index, checkpoint in enumerate(status['ui']['checkpoints']):
                    frame = next((f for f in frames if f['count'] == checkpoint['frame']), None)
                    if frame is None:
                        errors.append({'error': 'Checkpoint has no captured surface.', 'checkpoint': checkpoint['name']})
                        continue
                    image = Image.open(output / frame['file']).convert('RGB')
                    for native in (e for e in events if e.get('kind') == 'ui-native-frame' and e['step'] == index):
                        with Image.open(output / native['file']) as child:
                            image.paste(child, tuple(native['rect'][:2]))
                    name = f'checkpoint-{index:03d}.png'
                    image.save(output / name)
                    checkpoint['composite'] = name
                    checkpoint['rgb_sha256'] = hashlib.sha256(image.tobytes()).hexdigest()
            report = {'schema': 1, 'runtime': str(runtime), 'manifest': manifest, 'hook': config,
                      'script_sha256': template_sha256, 'human_control':human_control,
                      'observer_sha256':hashlib.sha256(observer.encode()).hexdigest() if observer else None,
                      'instrumentation_sha256':digest(output/'instrumentation.js') if (output/'instrumentation.js').exists() else None,
                      'registry_inputs': registry_snapshot, 'shared_assets_unchanged': not changed_assets,
                      'desktop': process_desktop,
                      'arguments': arguments, 'fixture': scenario, 'clock': clock, 'duration': time.monotonic()-started,
                      'frida_version': frida.__version__, 'status': status,
                      'frames': frames, 'events': events, 'errors': errors,
                      'video': video_report,
                      'video_origin_time_ms': video_origin,
                      'rng_recording': ({'file':'rng.bin', 'records':rng_records, 'sites':rng_sites,
                                         'sha256':digest(output / 'rng.bin')} if replay or observe else None),
                      'scope': ('Selected typed state at function boundaries; not full process determinism' if replay else
                                'Menu surface and RNG observations; not full process determinism')}
            (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print(f'Capture: {output}\nFrames: {len(frames)}; errors: {len(errors)}')
    return 0 if frames and not errors else 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--runtime', required=True, type=Path)
    parser.add_argument('--seconds', type=float, default=8)
    parser.add_argument('--fixture', type=Path, help='Menu key events scheduled after Paint calls')
    parser.add_argument('--clock', choices=('real', 'calls'), default='real',
                        help='calls: experimental debug-clock replacement; one millisecond per call')
    parser.add_argument('--visible', action='store_true', help='Explicitly permit the normal interactive desktop')
    args = parser.parse_args()
    if not 0 < args.seconds <= 300:
        parser.error('Seconds must be greater than zero and at most 300.')
    return capture(args.runtime, args.seconds, args.fixture, args.clock, args.visible)


if __name__ == '__main__':
    raise SystemExit(main())
