"""Check the private registry copy used by captured runs.

These tests create and remove keys only inside the harness namespace.
"""
from __future__ import annotations

import sys
import winreg
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import registry_state


def row(name, value):
    return {'name': name, 'type': winreg.REG_DWORD, 'value': value}


def private_values(base, name):
    with winreg.OpenKey(winreg.HKEY_CURRENT_USER, base + '\\' + name, 0,
                        winreg.KEY_READ | winreg.KEY_WOW64_32KEY) as key:
        count = winreg.QueryInfoKey(key)[1]
        return {winreg.EnumValue(key, index)[0]: winreg.EnumValue(key, index)[1]
                for index in range(count)}


def test_supplied_values_become_the_private_copy():
    live = registry_state.live_values()
    supplied = {'user': [row('Music Volume', 9900)], 'machine': []}
    base, supplied_snapshot, machine = registry_state.create(supplied)
    try:
        assert private_values(base, 'user') == {'Music Volume': 9900}
        assert supplied_snapshot == supplied
        # The machine snapshot reports the machine, not the supplied copy.
        assert machine == live
    finally:
        registry_state.cleanup(base)
    with pytest.raises(FileNotFoundError):
        private_values(base, 'user')


def test_without_supplied_values_the_copy_mirrors_the_machine():
    live = registry_state.live_values()
    base, supplied, machine = registry_state.create()
    try:
        assert supplied == live == machine
        assert private_values(base, 'user') == {row['name']: row['value'] for row in live['user']}
    finally:
        registry_state.cleanup(base)


def test_live_values_round_trip_through_restore():
    before = registry_state.live_values()
    registry_state.restore(before)
    assert registry_state.live_values() == before
