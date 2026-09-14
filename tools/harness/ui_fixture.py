"""Validate bounded input scripts before starting a game process."""


def validate_steps(steps):
    if not isinstance(steps, list) or not 1 <= len(steps) <= 200:
        raise ValueError('UI fixtures require 1..200 steps.')
    names = set()
    for step in steps:
        if not isinstance(step, dict):
            raise ValueError('Each UI step must be an object.')
        name = step.get('name')
        if not isinstance(name, str) or not name or len(name) > 80 or name in names:
            raise ValueError('UI checkpoint names must be short, nonempty, and unique.')
        names.add(name)
        kind = step.get('type', 'snapshot')
        if kind not in ('snapshot', 'key', 'text', 'click', 'down', 'up', 'move'):
            raise ValueError('Unsupported UI input type.')
        if kind == 'key' and (type(step.get('key')) is not int or not 1 <= step['key'] <= 255):
            raise ValueError('UI key must be 1..255.')
        if kind == 'text' and (not isinstance(step.get('text'), str) or not 1 <= len(step['text']) <= 200 or
                               any(ord(c) != 8 and not 32 <= ord(c) <= 126 for c in step['text'])):
            raise ValueError('UI text supports bounded ASCII input and backspace.')
        if kind in ('click', 'down', 'up', 'move') and any(
                type(step.get(key)) is not int or not 0 <= step[key] < maximum
                for key, maximum in (('x', 640), ('y', 480))):
            raise ValueError('UI mouse coordinates must lie inside the 640 by 480 game client.')
        modifiers = step.get('modifiers', [])
        if not isinstance(modifiers, list) or any(type(key) is not int or key not in (16,17,18) for key in modifiers):
            raise ValueError('UI modifiers support Shift, Control, and Alt only.')
        checks = step.get('check', [])
        if not isinstance(checks, list) or any(not isinstance(check, dict) for check in checks):
            raise ValueError('Control assertions must be a list of objects.')
        for check in checks:
            if check.get('kind') not in ('panel', 'button', 'drop', 'list', 'text', 'edit', 'scroll'):
                raise ValueError('Unknown control assertion type.')
            if not isinstance(check.get('equals', {}), dict):
                raise ValueError('Control assertions require an equals object.')
