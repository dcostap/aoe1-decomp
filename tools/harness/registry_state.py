"""Give captured runs private copies of the game's two registry keys."""
from __future__ import annotations

import base64
import os
import re
import uuid

GAME_KEY = r'Software\Microsoft\Games\Age of Empires\1.00'
HIVES = (('user', 'HKEY_CURRENT_USER'), ('machine', 'HKEY_LOCAL_MACHINE'))


def _hives():
    import winreg
    return (('user', winreg.HKEY_CURRENT_USER), ('machine', winreg.HKEY_LOCAL_MACHINE))


def _normalize(rows):
    return sorted([{'name': value_name, 'type': kind,
                    'value': base64.b64encode(value).decode() if isinstance(value, bytes) else value}
                   for value_name, value, kind in rows], key=lambda row: row['name'])


def _decode(row):
    value = row['value']
    return base64.b64decode(value) if isinstance(value, str) and row['type'] == 3 else value


def _read(hive):
    import winreg
    rows = []
    try:
        with winreg.OpenKey(hive, GAME_KEY, 0, winreg.KEY_READ | winreg.KEY_WOW64_32KEY) as key:
            count = winreg.QueryInfoKey(key)[1]
            rows = [winreg.EnumValue(key, index) for index in range(count)]
    except FileNotFoundError:
        pass
    return rows


def live_values():
    """Return the machine's game-key values, normalized for comparison and restore."""
    return {name: _normalize(_read(hive)) for name, hive in _hives()}


def restore(values):
    """Put the given normalized values back into the machine's game key."""
    import winreg
    for name, hive in _hives():
        wanted = {row['name']: row for row in values.get(name, [])}
        try:
            with winreg.CreateKeyEx(hive, GAME_KEY, 0,
                                    winreg.KEY_READ | winreg.KEY_WRITE | winreg.KEY_WOW64_32KEY) as key:
                present = [winreg.EnumValue(key, index)[0] for index in range(winreg.QueryInfoKey(key)[1])]
                for value_name in present:
                    if value_name not in wanted:
                        winreg.DeleteValue(key, value_name)
                for row in wanted.values():
                    winreg.SetValueEx(key, row['name'], 0, row['type'], _decode(row))
        except OSError:
            continue


def create(values=None):
    """Create private copies of the game's registry keys for one run.

    Supplied values become the private copies, so the game reads exactly those settings
    whatever the machine holds. Without them the copies mirror the machine. The live
    snapshot always returns too, so a report can show the machine state.
    """
    import winreg
    identity = os.environ.get('AOE1_HARNESS_RUN_ID', uuid.uuid4().hex)
    if not re.fullmatch('[0-9a-f]{32}', identity):
        raise ValueError('Invalid private registry identity.')
    base = 'Software\\AoE1Harness\\' + identity
    machine = {}
    try:
        for name, hive in _hives():
            machine[name] = _normalize(_read(hive))
        supplied = {name: list(values[name]) for name in machine} if values else machine
        for name in machine:
            with winreg.CreateKeyEx(winreg.HKEY_CURRENT_USER, base + '\\' + name, 0,
                                    winreg.KEY_WRITE | winreg.KEY_WOW64_32KEY) as key:
                for row in supplied.get(name, []):
                    winreg.SetValueEx(key, row['name'], 0, row['type'], _decode(row))
    except Exception:
        cleanup(base)
        raise
    return base, supplied, machine


def cleanup(base):
    import winreg
    if not base.startswith('Software\\AoE1Harness\\') or len(base.split('\\')) != 3:
        raise ValueError('Refusing to delete a registry key outside the harness namespace.')
    for path in (base + '\\user', base + '\\machine', base):
        try:
            winreg.DeleteKeyEx(winreg.HKEY_CURRENT_USER, path, winreg.KEY_WOW64_32KEY)
        except FileNotFoundError:
            pass
