"""Validate replay descriptions and compare explicit typed observations."""
from ui_fixture import validate_steps

WIDTHS = {'u8':1, 'i16':2, 'u16':2, 'i32':4, 'u32':4, 'f32':4}


def validate_replay(scenario):
    validate_steps(scenario.get('steps'))
    replay = scenario['replay']
    if not isinstance(replay, dict):
        raise ValueError('Replay must be an object.')
    if scenario.get('ui') is not True or replay.get('schema') != 1:
        raise ValueError('Replay requires UI input delivery and schema 1.')
    if type(replay.get('updates')) is not int or not 1 <= replay['updates'] <= 1000:
        raise ValueError('Replay requires 1..1000 world update calls.')
    probes = replay.get('probes')
    if not isinstance(probes, list) or not 1 <= len(probes) <= 32:
        raise ValueError('Replay requires 1..32 probes.')
    names = set()
    for probe in probes:
        if not isinstance(probe, dict):
            raise ValueError('Each probe must be an object.')
        name = probe.get('name')
        if not isinstance(name, str) or not name.isidentifier() or name in names:
            raise ValueError('Probe names must be unique identifiers.')
        names.add(name)
        if not isinstance(probe.get('module'), str) or not probe['module'].isidentifier():
            raise ValueError('Invalid probe module.')
        if not isinstance(probe.get('va'), str) or len(probe['va']) != 8:
            raise ValueError('Probe requires an eight-digit original VA.')
        int(probe['va'], 16)
        if probe.get('phase') not in ('enter', 'leave', 'both'):
            raise ValueError('Invalid probe phase.')
        fields = probe.get('fields', {})
        arguments = probe.get('arguments', {})
        if not isinstance(arguments, dict):
            raise ValueError('Probe arguments must be an object.')
        if not isinstance(fields, dict) or len(fields) > 128:
            raise ValueError('Probe fields must be a bounded object.')
        for field, spec in list(fields.items()) + list(arguments.items()):
            if not isinstance(field, str) or len(field) > 100 or not isinstance(spec, list) or len(spec) != 2:
                raise ValueError('Invalid field description.')
            offset, kind = spec
            if type(offset) is not int or not 0 <= offset <= 65536 or kind not in WIDTHS:
                raise ValueError('Unsupported field offset or type.')
    if replay.get('update_probe') not in names:
        raise ValueError('The update probe must exist.')
    captures = replay.get('captures', [])
    if not isinstance(captures, list) or len(captures) > 32:
        raise ValueError('Replay supports at most 32 capture checkpoints.')
    capture_names, previous = set(), -1
    for checkpoint in captures:
        if not isinstance(checkpoint, dict):
            raise ValueError('Capture checkpoints must be objects.')
        name, boundary = checkpoint.get('name'), checkpoint.get('after_updates')
        if not isinstance(name, str) or not name.isidentifier() or len(name) > 80 or name in capture_names:
            raise ValueError('Capture names must be short, unique identifiers.')
        if type(boundary) is not int or not previous < boundary <= replay['updates']:
            raise ValueError('Capture boundaries must increase within the replay update limit.')
        capture_names.add(name)
        previous = boundary
    if captures and previous != replay['updates']:
        raise ValueError('The final capture must use the terminal update boundary.')
    for step in scenario['steps']:
        if not isinstance(step.get('before'), str) or not step['before']:
            raise ValueError('Each replay input requires a source panel.')
        value = step.get('after_updates', 0)
        if type(value) is not int or not 0 <= value < replay['updates']:
            raise ValueError('Input update boundary exceeds the replay limit.')


def observations(report):
    return [event for event in report['events'] if event.get('kind') == 'behavior-state']


def first_difference(left, right):
    a, b = observations(left), observations(right)
    for index in range(max(len(a), len(b))):
        if index >= len(a) or index >= len(b):
            return {'index':index, 'reason':'observation count differs', 'left_count':len(a), 'right_count':len(b)}
        x, y = a[index], b[index]
        for key in ('probe', 'phase', 'ordinal', 'input', 'updates', 'arguments', 'fields', 'rng_count', 'rng_sha256'):
            if x.get(key) != y.get(key):
                fields = []
                if key == 'fields':
                    fields = [{'field':name, 'left':x[key].get(name), 'right':y[key].get(name)}
                              for name in sorted(x[key].keys() | y[key].keys()) if x[key].get(name) != y[key].get(name)]
                return {'index':index, 'reason':key, 'fields':fields, 'left':x, 'right':y}
    return None
