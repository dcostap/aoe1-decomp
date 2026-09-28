"""Generate a chaos-start save with the original game.

The game starts a normal random-map game through its own setup screen, with eight
players and the chosen map. At the first world update the engine places extra
villagers and a large random army near every town centre, sets resources and the
population limit, and saves with the normal save function. The save goes to
local/harness/savegames/, so `game.cmd record` offers it under Load Game.
"""
from __future__ import annotations

import argparse
import json
import os
from pathlib import Path
import random
import shutil
import sys
import threading

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
from game import ROOT, run_worker, stage, stamp
from capture import hook_config, save_frame
from prepare_runtime import LOCAL_SAVES, ORIGINAL_SHA256, digest
import registry_state

MAP_TYPES = {'small-islands': 0, 'large-islands': 1, 'coastal': 2, 'inland': 3, 'highland': 4,
             'continental': 5, 'mediterranean': 6, 'hill-country': 7, 'narrows': 8}
MAP_SIZES = {'tiny': 0, 'small': 1, 'medium': 2, 'large': 3, 'huge': 4, 'gigantic': 5}
AGES = {'stone': 2, 'tool': 3, 'bronze': 4, 'iron': 5}
DIFFICULTIES = {'hardest': 0, 'hard': 1, 'moderate': 2, 'easy': 3, 'easiest': 4}
# Registry identities; hook_config checks each original entry's bytes.
APIS = {
    'number_players': ('basegame', '004227E0'), 'difficulty': ('basegame', '00422870'),
    'player_team': ('basegame', '00422880'), 'get_player': ('basegame', '00420330'),
    'map_size': ('tribegam', '00529200'), 'map_type': ('tribegam', '005292B0'),
    'resource_level': ('tribegam', '00529500'), 'starting_age': ('tribegam', '00529510'),
    'civilization': ('tribegam', '00529350'), 'player_color': ('tribegam', '005293B0'),
    'save_game': ('tribegam', '00524640'), 'humanity': ('com_hand', '0042CC30'),
    'start_setup': ('scr_mps', '004A2060'), 'set_attribute': ('player', '004700B0'),
    'placement': ('m_s_obj', '00453C40'), 'create': ('tplayer', '00512F60'),
    'world_update': ('world', '00542ED0'), 'load_game': ('tribegam', '00526170'),
    'camera': ('player', '004704C0'), 'set_relation': ('player', '00470BE0'),
    'relation': ('player', '00470BD0'), 'set_allied_victory': ('player', '00470BB0'),
    'allied_victory': ('player', '00470BC0'), 'set_changeable': ('aidipmod', '0040C4A0'),
    'changeable': ('aidipmod', '0040C460'), 'redraw': ('scr_game', '004959A0'),
}
COMM_VA = 0x0062C4C0  # TCommunications_Handler* comm; read by TribeMPSetupScreen::startGame.


def worker(runtime, output, settings, visible):
    import frida
    if not visible and not os.environ.get('AOE1_HARNESS_DESKTOP'):
        raise ValueError('Use a private desktop worker, or explicitly request --visible.')
    manifest = json.loads((runtime / 'runtime_manifest.json').read_text())
    if manifest['selected_exe_sha256'] != ORIGINAL_SHA256:
        raise ValueError('Chaos starts are generated with the original executable.')
    probes = [dict(name=name, module=module, va=va) for name, (module, va) in APIS.items()]
    cfg = hook_config(runtime / 'empiresx.exe', manifest, False, probes)
    # Enter twice: Main Menu > Single Player > Random Map setup screen.
    cfg.update(clockMode='calls', actions=[{'after_paint': 8, 'key': 13}, {'after_paint': 14, 'key': 13}],
               maxFrames=0, human=None, chaos=dict(settings, comm_rva=COMM_VA - 0x400000))
    folder = Path(__file__).parent
    source = '\n'.join((folder / name).read_text() for name in ('menu.js', 'offline.js', 'chaos_start.js'))
    done = threading.Event()
    events, errors = [], []
    device = frida.get_local_device()
    key = pid = session = None
    try:
        key, _, _ = registry_state.create(registry_state.automated_values())
        cfg['registryBase'] = key
        source = source.replace('__CONFIG__', json.dumps(cfg))
        pid = device.spawn([str(runtime / 'empiresx.exe'), 'NOSTARTUP', 'GAMECD', 'NOSOUND', 'NOMUSIC'],
                           cwd=str(runtime), env=dict(os.environ, __COMPAT_LAYER=''))
        session = device.attach(pid)
        session.on('detached', lambda *args: done.set())
        script = session.create_script(source)

        def message(msg, data):
            if msg['type'] != 'send':
                errors.append(msg)
                done.set()
                return
            row = msg['payload']
            kind = row.get('kind')
            if kind == 'frame' and data:
                save_frame(output, row, bytes(data))
            if kind in ('chaos-progress', 'chaos-done', 'chaos-error'):
                events.append(row)
                shown = {k: v for k, v in row.items() if k != 'kinds'}
                print(json.dumps(shown), flush=True)
            if kind in ('chaos-done', 'chaos-error', 'capture-error') or (
                    kind == 'exception' and row.get('code') != 0xe06d7363):
                if kind != 'chaos-done':
                    errors.append(row)
                done.set()

        script.on('message', message)
        script.load()
        device.resume(pid)
        if not done.wait(settings['timeout']):
            errors.append({'error': 'Generation exceeded its wall-clock deadline.'})
    finally:
        if pid is not None:
            try:
                device.kill(pid)
            except frida.ProcessNotFoundError:
                pass
        if key:
            registry_state.cleanup(key)
    finished = [e for e in events if e['kind'] == 'chaos-done']
    if finished and settings['diplomacy'] == 'ffa':
        # Every pair must still be enemies after the computers' initial-diplomacy time.
        rows = finished[0]['summary']['diplomacy_after_load']
        if any(row['allied_victory'] or any(value != 3 for q, value in enumerate(row['relations'], 1)
                                             if q != row['player']) or
               any(value for q, value in enumerate(row['changeable'], 1) if q != row['player'] and value is not None)
               for row in rows):
            errors.append({'error': 'Free-for-all diplomacy did not hold after reload', 'diplomacy': rows})
    save = runtime / 'savegame' / settings['save_name']
    report = dict(schema=1, settings=settings, runtime=str(runtime), errors=errors,
                  summary=finished[0]['summary'] if finished else None,
                  passed=bool(finished) and not errors and save.exists())
    if report['passed']:
        shutil.copy2(save, output / save.name)
        report['save'] = dict(name=save.name, size=save.stat().st_size, sha256=digest(save))
    (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    return 0 if report['passed'] else 1


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--name', help='Save name without extension; default chaos-<seed>')
    parser.add_argument('--seed', type=int, help='Civilizations, army mix, and formation placement; default random')
    parser.add_argument('--map-type', choices=tuple(MAP_TYPES), default='continental')
    parser.add_argument('--map-size', choices=tuple(MAP_SIZES), default='gigantic')
    parser.add_argument('--age', choices=tuple(AGES), default='stone')
    parser.add_argument('--difficulty', choices=tuple(DIFFICULTIES), default='hardest')
    parser.add_argument('--diplomacy', choices=('ffa', 'standard'), default='ffa',
                        help='ffa: every player is an enemy of every other from the start, so the computers never '
                             'ally against you (default). standard: the normal random-map diplomacy')
    parser.add_argument('--check-seconds', type=float, default=15,
                        help='Game time after reloading at which the free-for-all check reads diplomacy (default 15)')
    parser.add_argument('--units', type=int, default=200, help='Army size per player (default 200)')
    parser.add_argument('--villagers', type=int, default=20, help='Villagers per player (default 20)')
    parser.add_argument('--resources', type=int, default=20000, help='Food, wood, stone, and gold per player')
    parser.add_argument('--pop-limit', type=int, default=200, help='Population limit per player (default 200)')
    parser.add_argument('--distance', type=float, default=10,
                        help='Tiles from the town centre to the army block centre, plus up to 4 more')
    parser.add_argument('--spacing', type=float, default=1.0, help='Tiles between formation cells')
    parser.add_argument('--output', type=Path, help='Report folder under build/')
    parser.add_argument('--visible', action='store_true', help='Show the game on the interactive desktop')
    parser.add_argument('--worker', action='store_true', help=argparse.SUPPRESS)
    parser.add_argument('--runtime', type=Path, help=argparse.SUPPRESS)
    parser.add_argument('--settings', type=Path, help=argparse.SUPPRESS)
    args = parser.parse_args()
    if args.worker:
        settings = json.loads(args.settings.read_text())
        return worker(args.runtime.resolve(), args.output.resolve(), settings, args.visible)
    if not 1 <= args.units <= 2000 or not 0 <= args.villagers <= 500:
        parser.error('Use 1-2000 units and 0-500 villagers per player.')
    if not 25 <= args.pop_limit <= 200 or args.resources < 0 or args.spacing < 0.5:
        parser.error('Use a population limit of 25-200, non-negative resources, and spacing of at least 0.5.')
    seed = args.seed if args.seed is not None else random.randrange(1, 1 << 31)
    name = args.name or f'chaos-{seed}'
    if not name.replace('-', '').replace('_', '').isalnum():
        parser.error('Use letters, digits, dashes, and underscores in --name.')
    destination = LOCAL_SAVES / (name + '.gmx')
    if destination.exists():
        parser.error(f'{destination} already exists; choose another --name.')
    output = (args.output or ROOT / 'build/chaos-start' / f'{name}-{stamp()}').resolve()
    if not output.is_relative_to((ROOT / 'build').resolve()):
        parser.error('Generated output must stay under build/.')
    output.mkdir(parents=True, exist_ok=False)
    settings = dict(seed=seed, save_name=name + '.gmx', map_type=MAP_TYPES[args.map_type],
                    map_size=MAP_SIZES[args.map_size], resource_level=3, starting_age=AGES[args.age],
                    difficulty=DIFFICULTIES[args.difficulty], civilizations=16, units=args.units,
                    villagers=args.villagers, resources=args.resources, pop_limit=args.pop_limit,
                    distance=args.distance, spacing=args.spacing, settle_updates=5, view_updates=40, timeout=600,
                    diplomacy=args.diplomacy, diplomacy_check_ms=int(args.check_seconds * 1000),
                    options=dict(map_type=args.map_type, map_size=args.map_size, age=args.age,
                                 difficulty=args.difficulty, diplomacy=args.diplomacy))
    (output / 'settings.json').write_text(json.dumps(settings, indent=2) + '\n')
    runtime = stage('original', select=False)
    command = [str(ROOT / 'build/harness-env/Scripts/python.exe'), str(Path(__file__).resolve()), '--worker',
               '--runtime', str(runtime), '--output', str(output), '--settings', str(output / 'settings.json')]
    code = run_worker(command, output / 'worker.log', settings['timeout'] + 60, args.visible)
    report_path = output / 'report.json'
    report = json.loads(report_path.read_text()) if report_path.exists() else {'passed': False}
    if code != 0 or not report.get('passed'):
        print(f'Generation failed. Details: {output}')
        return code or 1
    LOCAL_SAVES.mkdir(parents=True, exist_ok=True)
    shutil.copy2(output / settings['save_name'], destination)
    summary = report['summary']
    for row in summary['players']:
        print(f"player {row['player']}: civilization {row['civilization']}, "
              f"{row['villagers']} villagers, {row['army']} army units in {row['blocks']} block(s)")
    print(f"Objects: {summary['objects_before']} generated, {summary['objects_after']} after placement, "
          f"{summary['objects_loaded']} after reloading the save; map {summary['map_size']}x{summary['map_size']}")
    if settings['diplomacy'] == 'ffa':
        print(f"Diplomacy: all 8 players are mutual enemies, checked after reload at world time "
              f"{summary['diplomacy_checked_at_ms'] / 1000:.1f} s")
    print(f'Screenshots of player 1 after reloading: {output}')
    print(f'Saved {destination}')
    print(f'Play and record it: game.cmd record, then Single Player > Saved Game > {name}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
