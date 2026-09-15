"""Check exact repeatability of human captures, including per-update observations."""
import argparse
import itertools
import json
from pathlib import Path

from human_compare import compare_captures, compare_rows, load_capture
from human_session import V1_TO_V3_UPGRADE, V2_TO_V3_UPGRADE, V1_TO_V4_UPGRADE, V2_TO_V4_UPGRADE, compare_inputs, inputs

STATE_KINDS = ('observer-world','observer-object','observer-pick','observer-camera',
               'observer-combat','observer-attack-update','observer-sprite','observer-villager')
NOISE_SHA256 = 'ed8657ee437720d2fbe04a5fde0bb89fb187bd9bf70a42a95968e84a1c403454'


def evidence_errors(report):
    errors = []
    human = report['status']['human']
    if not isinstance(report['status'].get('count'),int) or report['status']['count'] <= 0:
        errors.append('Valid-surface paint-count evidence is missing.')
    fidelity = compare_inputs(report['fixture']['human']['events'], inputs(report))
    if not fidelity['same_messages'] or human['input'] != fidelity['expected_count'] or human['posted'] != human['input'] or human['dropped']:
        errors.append('Input delivery is incomplete or includes dropped messages.')
    if any(a['turn'] != b['turn'] or a['panel'] != b['panel']
           for a,b in zip(report['fixture']['human']['events'],inputs(report))):
        errors.append('The recorded input turn/panel schedule was not followed.')
    session = report['fixture']['human']
    if bool(session.get('message_noise')) != bool(report.get('noise_sha256')):
        errors.append('Queue-noise instrumentation differs from its request.')
    if session.get('message_noise'):
        ready = [row for row in report['events'] if row.get('kind') == 'control-noise-ready']
        summaries = [row for row in report['events'] if row.get('kind') == 'control-noise-summary']
        if (report.get('noise_sha256') != NOISE_SHA256 or len(ready) != 1 or len(summaries) != 1 or
                ready[0].get('version') != 2 or summaries[0].get('version') != 2 or
                ready[0].get('messages') != [0x113,0xf] or ready[0].get('period_ms') != 37 or
                summaries[0].get('period_ms') != 37 or summaries[0].get('batches',0) <= 0 or
                any(summaries[0].get('suppressed_dispatches',{}).get(kind,0) <= 0 for kind in ('timer','paint'))):
            errors.append('Requested queue-noise evidence is incomplete.')
    if session.get('upgrade_rule') in (V1_TO_V3_UPGRADE,V2_TO_V3_UPGRADE,V1_TO_V4_UPGRADE,V2_TO_V4_UPGRADE):
        terminal_turn = (session['events'][-1]['turn'] if session['events'] else 0) + 8
        profile = 'v4-controlled-paint' if session['upgrade_rule'] in (V1_TO_V4_UPGRADE,V2_TO_V4_UPGRADE) else 'v3-no-native-timers'
        if (human.get('terminal_turn') != terminal_turn or human.get('turn') != terminal_turn or
                human.get('historical_duration_ms') != session['duration_ms'] or
                human.get('control_profile') != profile):
            errors.append('The declared controlled terminal rule was not followed.')
    world = [row for row in report['events'] if row.get('kind') == 'observer-world']
    required = {'time','delta','old_time','speed','registrations','rng_count','turn','time_ms','clock_counts'}
    if (human['updates'] <= 0 or len(world) != human['updates'] * 2 or
            any(row.get('phase') != ('enter' if i % 2 == 0 else 'leave') or
                row.get('updates') != (i + 1) // 2 or not required.issubset(row) or
                not isinstance(row.get('clock_counts'),dict) or not {'calls','idle'}.issubset(row['clock_counts'])
                for i, row in enumerate(world))):
        errors.append('World entry/exit observations are incomplete.')
    return errors


def compare(left, right, *, noise_resistance=False):
    result = compare_captures(left, right)
    reports = [capture['report'] for capture in (left, right)]
    modes = [{key: report['fixture']['human'].get(key, False)
              for key in ('observe','rng_only','combat','message_noise')} for report in reports]
    observer_keys = ('observe','rng_only','combat')
    same_noise = (modes[0]['message_noise'] == modes[1]['message_noise'] and
                  reports[0].get('noise_sha256') == reports[1].get('noise_sha256'))
    if (any(modes[0][key] != modes[1][key] for key in observer_keys) or
            reports[0].get('observer_sha256') != reports[1].get('observer_sha256') or
            (not same_noise and (not noise_resistance or all(mode['message_noise'] for mode in modes)))):
        raise ValueError('Repeatability requires the same observer mode, perturbation, and scripts.')
    result['comparison_mode'] = 'noise-resistance' if noise_resistance else 'observed-repeatability'
    result['observer_modes'] = modes
    result['noise_sha256'] = [report.get('noise_sha256') for report in reports]
    result['paint_counts'] = [report['status'].get('count') for report in reports]
    result['paint_count_scope'] = 'Paint entries with a usable 8-bit source surface; not every paint request.'
    state = {}
    for kind in STATE_KINDS:
        rows = [[row for row in report['events'] if row.get('kind') == kind] for report in reports]
        state[kind] = compare_rows(*rows)
    result['state_observations'] = state
    result['evidence_errors'] = [evidence_errors(report) for report in reports]
    result['required_evidence_present'] = (result['full_rng'] is not None and
        not any(result['evidence_errors']))
    result['passed'] = bool(result['required_evidence_present'] and result['full_rng']['equal'] and
        result['inputs']['exact_boundaries'] and result['inputs']['same_messages'] and
        result['camera_values']['equal'] and result['camera_receipts']['equal'] and
        result['terminal_boundaries'][0] == result['terminal_boundaries'][1] and
        result['terminal_world']['equal'] and result['video_samples']['equal'] and
        result['paint_counts'][0] == result['paint_counts'][1] and
        all(row['equal'] for row in state.values()))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('captures', type=Path, nargs='+', help='At least two complete capture report paths')
    parser.add_argument('--output', required=True, type=Path, help='New report path under build/')
    parser.add_argument('--noise-resistance',action='store_true',help='Explicitly compare quiet and perturbed captures; keep every output check exact')
    args = parser.parse_args()
    if len(args.captures) < 2:
        parser.error('Supply at least two captures.')
    if args.output.exists() or not args.output.resolve().is_relative_to(Path('build').resolve()):
        parser.error('Use a new report path under build/.')
    result = {'schema':1, 'complete':False, 'passed':False, 'pairs':[],
              'scope':'Exact observed repeatability only. Missing world/RNG evidence fails. No state alignment or image tolerance.'}
    try:
        captures = [load_capture(path) for path in args.captures]
        if args.noise_resistance and {bool(capture['report']['fixture']['human'].get('message_noise')) for capture in captures} != {False,True}:
            raise ValueError('Noise-resistance checks need both quiet and perturbed captures.')
        result['executables'] = [{'capture':capture['path'],
            'sha256':capture['report']['manifest']['selected_exe_sha256']} for capture in captures]
        result['pairs'] = [compare(left,right,noise_resistance=args.noise_resistance) for left,right in itertools.combinations(captures,2)]
        result['complete'] = True
        result['passed'] = all(pair['passed'] for pair in result['pairs'])
    except (OSError,ValueError,KeyError) as error:
        result['error'] = str(error)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    print('Repeatability passed:', result['passed'])
    print('Report:',args.output)
    return 0 if result['passed'] else 1

if __name__ == '__main__':
    raise SystemExit(main())
