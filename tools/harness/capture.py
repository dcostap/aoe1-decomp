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
from ui_fixture import normalize_resolution, resolution_from_registry, validate_steps


def hook_config(exe: Path, manifest: dict, ui=False, probes=()):
    image = exe.read_bytes()
    if hashlib.sha256(image).hexdigest() != manifest['selected_exe_sha256']:
        raise ValueError('Runtime EXE hash changed.')
    addresses = {'paint': 0x00443520, 'clock': 0x004231E0,
                 'rand': 0x004230A0, 'srand': 0x00423140,
                 'run': 0x0041CFD0, 'idle': 0x00529610,
                 'wndproc': 0x0041E7A0, 'panelSystem': 0x0062E870,
                 'alloc_new': 0x0054B6F0}
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
            'alloc_new': '??2@YAPAXI@Z',
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
                    if name in ('GetKeyState', 'GetAsyncKeyState', 'GetKeyboardState', 'GetCursorPos'):
                        if name in result['inputIAT']:
                            raise ValueError('Duplicate input import identity.')
                        result['inputIAT'][name] = first_thunk + index * 4
                index += 1
            descriptor += 20
        if len(result['inputIAT']) != 4 or len(set(result['inputIAT'].values())) != 4:
            raise ValueError('Expected four separate game input import slots.')
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


def savegame_outputs(runtime: Path, manifest: dict) -> dict:
    """Report changed game-save files without treating them as input fixtures."""
    baseline = {row['path'].replace('\\', '/'): row['sha256']
                for row in manifest.get('copied_files_before_exe_replacement', [])
                if row['path'].replace('\\', '/').lower().startswith('savegame/')}
    current = {}
    folder = runtime / 'savegame'
    if folder.is_dir():
        for path in sorted(folder.iterdir()):
            if path.is_file() and path.suffix.lower() in ('.gmx', '.gam'):
                relative = 'savegame/' + path.name
                current[relative] = {'path': relative, 'size': path.stat().st_size,
                                     'sha256': digest(path)}
    changed = [row for name, row in current.items() if baseline.get(name) != row['sha256']]
    removed = sorted(name for name in baseline if name not in current)
    return {'changed': changed, 'removed': removed}


# Harness files inside the runtime; everything else that changes was written by the game.
HARNESS_RUNTIME_FILES = ('human-worker.json', 'human-worker.log')


def runtime_snapshot(runtime: Path) -> dict:
    """Size and modification time of every runtime file, before the game starts."""
    rows = {}
    for path in runtime.rglob('*'):
        relative = path.relative_to(runtime).as_posix()
        if path.is_file() and not relative.startswith('capture/') and relative not in HARNESS_RUNTIME_FILES:
            stat = path.stat()
            rows[relative] = (stat.st_size, stat.st_mtime_ns)
    return rows


def written_files(runtime: Path, before: dict) -> dict:
    """Every file the game created, changed, or removed: saves, scenarios, and anything else."""
    after = runtime_snapshot(runtime)
    changed = [{'path': relative, 'size': after[relative][0], 'sha256': digest(runtime / relative)}
               for relative in sorted(after) if before.get(relative) != after[relative]]
    return {'changed': changed, 'removed': sorted(set(before) - set(after))}


def function_names(manifest):
    """Map an image VA to 'symbol+offset' for the original registry or a rebuilt map."""
    import bisect
    if manifest['selected_exe_sha256'] == ORIGINAL_SHA256:
        rows = {}
        for path in (TOOLS.parent / 'config/functions/src').glob('*.json'):
            for va, row in json.loads(path.read_text()).get('functions', {}).items():
                if isinstance(row, dict) and row.get('symbol'):
                    rows[int(va, 16)] = row['symbol']
    else:
        mapping = Path(manifest['selected_exe']).with_name('empiresx.map')
        rows = {row['address']: row['symbol'] for row in parse_symbols(mapping.read_text(errors='replace'))
                if row['function']}
    starts = sorted(rows)
    def name(va):
        index = bisect.bisect_right(starts, va) - 1
        return f'{rows[starts[index]]}+0x{va - starts[index]:x}' if index >= 0 else hex(va)
    return name


def capture(runtime: Path, seconds: float, fixture: Path | None = None, clock='real', visible=False,
            resolution=None):
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
    requested_resolution = resolution if resolution is not None else scenario.get('resolution')
    selected_resolution = normalize_resolution(requested_resolution) if requested_resolution is not None else None
    replay = scenario.get('replay')
    human = scenario.get('human')
    human_control = None
    if human:
        from human_session import (V1_POLICY, V5_POLICY, V6_POLICY, V8_POLICY, V9_POLICY,
                                   V10_POLICY, V11_POLICY, TRACE_FAST_POLICY,
                                   execution_plan, validate_session, control_template)
        validate_session(human)
        human_control = execution_plan(human)
        if human_control['executed_policy'] in (V5_POLICY, V6_POLICY, V8_POLICY, V9_POLICY,
                                                V10_POLICY, V11_POLICY, TRACE_FAST_POLICY):
            from prepare_runtime import verify_harness_saves
            verify_harness_saves(runtime, manifest)
        original_target = human.get('target','original') == 'original'
        if replay or ui or (manifest['selected_exe_sha256'] == ORIGINAL_SHA256) != original_target or clock != 'calls':
            raise ValueError('Human recording requires the selected executable and controlled-clock profile.')
        if selected_resolution is not None:
            contract_resolution = resolution_from_registry(human['contract']['registry_inputs'])
            if contract_resolution != selected_resolution:
                raise ValueError('Pinned human recordings do not support a resolution override.')
    if 'replay' in scenario:
        from behavior import validate_replay
        validate_replay(scenario)
    probes = replay['probes'] if replay else ([{'name':'human_world','module':'world','va':'00542ED0'},
        {'name':'human_camera','module':'player','va':'004704C0'}] if human else ())
    if human and human.get('call_probe'):
        probes = [*probes, *({'name':f'call{index}', 'module':row['module'], 'va':row['va']}
                             for index, row in enumerate(human['call_probe']['functions']))]
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
    if human:
        from human_session import startup_blocks
        # The current core installs only the blocks its profile refuses.
        config['blockedStartups'] = startup_blocks(human_control['executed_policy'])
    config['humanControl'] = human_control
    trace_fast = bool(human and human.get('trace_fast'))
    if trace_fast:
        config['traceNative'] = Path(__file__).with_name('trace_replay.c').read_text()
    supplied = ((human or {}).get('contract') or {}).get('registry_inputs')
    if human:
        if selected_resolution is None and supplied is not None:
            selected_resolution = resolution_from_registry(supplied)
    else:
        if supplied is None:
            supplied = scenario.get('registry_inputs')
        if supplied is None:
            supplied = registry_state.automated_values()
        if selected_resolution is None:
            selected_resolution = resolution_from_registry(supplied) or normalize_resolution()
        supplied = registry_state.with_screen_size(supplied, selected_resolution['width'])
        scenario['resolution'] = selected_resolution
    if ui and selected_resolution is not None:
        config['uiResolution'] = selected_resolution
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
    if human:
        template = control_template(human_control['executed_policy'])
    else:
        template = (Path(__file__).with_name('menu.js')).read_text()
        if ui:
            template += '\n' + Path(__file__).with_name('offline.js').read_text()
            template += '\n' + Path(__file__).with_name('ui.js').read_text()
        if replay:
            template += '\n' + Path(__file__).with_name('replay.js').read_text()
    template_sha256 = hashlib.sha256(template.encode()).hexdigest()
    if human and template_sha256 != human_control['executed_script_sha256']:
        raise ValueError('Selected human control template differs from its policy hash.')
    # The native fast engine implements its own replay and RNG observation.
    addons = human and not trace_fast
    observer = Path(__file__).with_name('human_observe.js').read_text() if observe and addons else ''
    message_observer = (Path(__file__).with_name('human_message_observe.js').read_text()
                        if observe and addons and human.get('rng_only') else '')
    noise = Path(__file__).with_name('human_noise.js').read_text() if addons and human.get('message_noise') else ''
    rng_seed_replay = (Path(__file__).with_name('human_rng_seed_replay.js').read_text()
                       if addons and human.get('replay_rng_seeds') else '')
    boundary_replay = (Path(__file__).with_name('human_boundary_replay.js').read_text()
                       if addons and human.get('replay_exact_boundaries') else '')
    update_replay = (Path(__file__).with_name('human_update_replay.js').read_text()
                     if addons and human.get('replay_update_trace') and not human.get('replay_clock_trace') else '')
    clock_replay = (Path(__file__).with_name('human_clock_replay.js').read_text()
                    if addons and human.get('replay_clock_trace') else '')
    message_replay = (Path(__file__).with_name('human_message_replay.js').read_text()
                      if addons and human.get('message_replay_path') else '')
    zone_probe = (Path(__file__).with_name('human_zone_probe.js').read_text()
                  if addons and human.get('zone_probe') else '')
    alloc_fill = (Path(__file__).with_name('human_alloc_fill.js').read_text()
                  if addons and human.get('alloc_fill') else '')
    video = None
    video_report = None
    video_origin = None
    video_finalized = False
    native_frames = []
    if human:
        from game_video import GameVideo
        video = GameVideo(output, fps=20)
        video.MAX_SECONDS = None
    events, frames, errors = [], [], []
    rng_digest, rng_records, rng_sites = hashlib.sha256(), 0, {}
    rng_file = (output / 'rng.bin').open('wb') if replay or observe else None
    message_records = 0
    message_windows = {0:{'role':'thread','route':None}, 1:{'role':'main','route':[]}}
    message_file = (output / 'messages.bin').open('wb') if message_observer else None
    lock = threading.Lock()
    stopped = threading.Event()
    finished = threading.Event()
    status = None
    device = frida.get_local_device()
    pid = None
    session = None
    arguments = ['NOSTARTUP', 'GAMECD', 'NOSOUND', 'NOMUSIC']
    started = time.monotonic()
    before_game = None
    timing = {}
    registry_base = None
    registry_snapshot = None
    registry_machine = None
    process_desktop = None
    game_job = None
    try:
        # Automated runs use a fixed profile. Pinned recordings supply their own contract.
        registry_base, registry_snapshot, registry_machine = registry_state.create(supplied)
        if human and human.get('contract'):
            from human_session import verify_starting_contract
            verify_starting_contract(human, {'clock':clock, 'registry_inputs':registry_snapshot,
                'arguments':arguments, 'frida_version':frida.__version__, 'manifest':manifest})
        config['registryBase'] = registry_base
        source = template.replace('__CONFIG__', json.dumps(config))
        if observer:
            source += '\n' + observer
        if message_observer:
            source += '\n' + message_observer
        if noise:
            source += '\n' + noise
        if rng_seed_replay:
            source += '\n' + rng_seed_replay
        if boundary_replay:
            source += '\n' + boundary_replay
        if update_replay:
            source += '\n' + update_replay
        if clock_replay:
            source += '\n' + clock_replay
        if message_replay:
            source += '\n' + message_replay
        if zone_probe:
            source += '\n' + zone_probe
        if alloc_fill:
            source += '\n' + alloc_fill
        (output / 'instrumentation.js').write_text(source)
        (output / 'capture-tool.py').write_bytes(Path(__file__).read_bytes())
        before_game = runtime_snapshot(runtime)
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
            nonlocal rng_records, message_records, video_origin
            with lock:
                if human and video_finalized:
                    return
                try:
                    if msg['type'] == 'send':
                        row = msg['payload']
                        if row.get('kind') == 'human-input-batch':
                            if 'first_input' not in timing and row['rows']:
                                timing['first_input'] = time.monotonic() - started
                            events.extend(row['rows'])
                            return
                        if row.get('kind') == 'state-dump':
                            events.extend({'kind':'state-object', 'updates':row['updates'], 'fields':fields}
                                          for fields in row['rows'])
                            return
                        if row.get('kind') == 'call-probe-batch':
                            events.extend(row['rows'])
                            return
                        if row.get('kind') == 'clock-log-batch':
                            events.extend({'kind':'clock-read', 'updates':u, 'line':line, 'file_hash':h}
                                          for u, line, h in row['rows'])
                            return
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
                        if row.get('kind') == 'message-pump-batch':
                            if row.get('record_size') != 80 or len(data) != row['records'] * 80:
                                raise ValueError('Invalid message-pump batch length.')
                            message_file.write(data)
                            message_records += row['records']
                            row['through_record'] = message_records
                        if row.get('kind') == 'message-window-site':
                            if row.get('id') in message_windows:
                                raise ValueError('Duplicate message window ID.')
                            message_windows[row['id']] = {'role':row['role'], 'route':row['route']}
                        if row.get('kind') == 'behavior-state':
                            row['rng_sha256'] = rng_digest.hexdigest()
                            row['rng_count'] = rng_records
                        events.append(row)
                        if row.get('kind') == 'human-input' and 'first_input' not in timing:
                            timing['first_input'] = time.monotonic() - started
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
        timing['script_loaded'] = time.monotonic() - started
        if message_replay or trace_fast:
            trace_path = Path(human['message_replay_path'])
            trace_data = trace_path.read_bytes()
            if trace_path.suffix == '.xz':
                import lzma
                trace_data = lzma.decompress(trace_data)
            expected_size = human['message_recording']['records'] * human['message_recording']['record_size']
            if len(trace_data) != expected_size or hashlib.sha256(trace_data).hexdigest() != human['message_recording']['sha256']:
                raise ValueError('Message replay sidecar differs from its metadata.')
            chunk_size = 1024 * 1024
            for offset in range(0, len(trace_data), chunk_size):
                chunk = trace_data[offset:offset+chunk_size]
                script.post({'type':'message-trace','offset':offset,
                             'done':offset+len(chunk)==len(trace_data)}, chunk)
        if not any(row.get('kind') == 'ready' for row in events):
            # load() completes script evaluation; let the message callback drain.
            for _ in range(100):
                if events or errors:
                    break
                time.sleep(.01)
        if errors or not any(row.get('kind') == 'ready' for row in events):
            raise ValueError(f'Instrumentation did not initialize: {errors}')
        if trace_fast:
            # Resume only after the whole pump trace sits in native memory.
            for _ in range(3000):
                if any(row.get('kind') == 'trace-ready' for row in events) or errors:
                    break
                time.sleep(.01)
            if errors or not any(row.get('kind') == 'trace-ready' for row in events):
                raise ValueError(f'Native trace replay did not load its message trace: {errors}')
            timing['trace_loaded'] = time.monotonic() - started
        device.resume(pid)
        timing['resumed'] = time.monotonic() - started
        finished.wait(seconds)
        timing['finished'] = time.monotonic() - started
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
                observed = [row for row in events if row.get('kind') in ('observer-update','observer-world','observer-object','observer-pick','observer-camera','observer-combat','observer-attack-update','observer-sprite','observer-villager')]
                if len(summaries) != 1 or summaries[0]['events'] != len(observed) or any(
                        row.get('sequence') != index+1 or not 0 <= row.get('rng_count',-1) <= rng_records
                        for index,row in enumerate(observed)):
                    errors.append({'error':'Human diagnostic event trace is incomplete.'})
                if message_observer:
                    message_summaries = [row for row in events if row.get('kind') == 'message-pump-summary']
                    if len(message_summaries) != 1 or message_summaries[0].get('records') != message_records:
                        errors.append({'error':'Message-pump trace is incomplete.'})
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
        if message_file:
            message_file.close()
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
        save_outputs = savegame_outputs(runtime, manifest)
        game_writes = written_files(runtime, before_game) if before_game is not None else None
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
            probe_rows = [row for row in events if row.get('kind') == 'call-probe']
            if probe_rows:
                name_of = function_names(manifest)
                for row in probe_rows:
                    row['stack_symbols'] = [name_of(int(address, 16) - int(row['base'], 16) + 0x400000)
                                            for address in row['stack']]
            report = {'schema': 1, 'runtime': str(runtime), 'manifest': manifest, 'hook': config,
                      'script_sha256': template_sha256, 'human_control':human_control,
                      'observer_sha256':hashlib.sha256(observer.encode()).hexdigest() if observer else None,
                      'noise_sha256':hashlib.sha256(noise.encode()).hexdigest() if noise else None,
                      'instrumentation_sha256':digest(output/'instrumentation.js') if (output/'instrumentation.js').exists() else None,
                      'registry_inputs': registry_snapshot, 'registry_machine': registry_machine,
                      'shared_assets_unchanged': not changed_assets,
                      'desktop': process_desktop,
                      'arguments': arguments, 'fixture': scenario, 'clock': clock, 'duration': time.monotonic()-started,
                      'timing': timing,
                      'frida_version': frida.__version__, 'status': status,
                      'frames': frames, 'events': events, 'errors': errors,
                      'save_outputs': save_outputs,
                      'written_files': game_writes,
                      'video': video_report,
                      'video_origin_time_ms': video_origin,
                      'rng_recording': ({'file':'rng.bin', 'records':rng_records, 'sites':rng_sites,
                                         'sha256':digest(output / 'rng.bin')} if replay or observe else None),
                      'message_recording': ({'file':'messages.bin', 'records':message_records,
                                             'format':'aoe-message-pump-v7-le', 'record_size':80,
                                             'windows':message_windows,
                                             'sha256':digest(output / 'messages.bin')}
                                            if message_observer else None),
                      'alloc_fill': bool(human and human.get('alloc_fill')),
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
    parser.add_argument('--resolution', help='Game resolution, for example 800x600')
    parser.add_argument('--visible', action='store_true', help='Explicitly permit the normal interactive desktop')
    args = parser.parse_args()
    if args.seconds <= 0:
        parser.error('Seconds must be greater than zero.')
    return capture(args.runtime, args.seconds, args.fixture, args.clock, args.visible, args.resolution)


if __name__ == '__main__':
    raise SystemExit(main())
