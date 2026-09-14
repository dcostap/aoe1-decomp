"""Give captured runs private copies of the game's two registry keys."""
from __future__ import annotations

import base64
import os
import re
import uuid

GAME_KEY = r'Software\Microsoft\Games\Age of Empires\1.00'


def create():
    import winreg
    identity = os.environ.get('AOE1_HARNESS_RUN_ID', uuid.uuid4().hex)
    if not re.fullmatch('[0-9a-f]{32}', identity):
        raise ValueError('Invalid private registry identity.')
    base = 'Software\\AoE1Harness\\' + identity
    snapshot = {}
    try:
        for name, hive in [('user', winreg.HKEY_CURRENT_USER), ('machine', winreg.HKEY_LOCAL_MACHINE)]:
            rows = []
            try:
                with winreg.OpenKey(hive, GAME_KEY, 0, winreg.KEY_READ | winreg.KEY_WOW64_32KEY) as key:
                    count = winreg.QueryInfoKey(key)[1]
                    rows = [winreg.EnumValue(key, index) for index in range(count)]
            except FileNotFoundError:
                pass
            with winreg.CreateKeyEx(winreg.HKEY_CURRENT_USER, base + '\\' + name, 0,
                                    winreg.KEY_WRITE | winreg.KEY_WOW64_32KEY) as key:
                for value_name, value, kind in rows:
                    winreg.SetValueEx(key, value_name, 0, kind, value)
            snapshot[name] = sorted([
                {'name': value_name, 'type': kind,
                 'value': base64.b64encode(value).decode() if isinstance(value, bytes) else value}
                for value_name, value, kind in rows], key=lambda row: row['name'])
    except Exception:
        cleanup(base)
        raise
    return base, snapshot


def cleanup(base):
    import winreg
    if not base.startswith('Software\\AoE1Harness\\') or len(base.split('\\')) != 3:
        raise ValueError('Refusing to delete a registry key outside the harness namespace.')
    for path in (base + '\\user', base + '\\machine', base):
        try:
            winreg.DeleteKeyEx(winreg.HKEY_CURRENT_USER, path, winreg.KEY_WOW64_32KEY)
        except FileNotFoundError:
            pass
