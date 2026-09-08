"""Protect independent target identity, map evidence, and reference boundaries."""
import hashlib
import json
from pathlib import Path
import sys
from types import SimpleNamespace

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import reference_identity as identity
from function_diagnostics import compatible_relocation_masks
from linker_map import parse_symbols, unique_addresses
from reference_build import window, disassemble, verify_pair
from audit_header_emissions import selected_emission
import audit_linked_references as linked
import linked_inputs


def test_wrong_base_method_is_not_exact():
    # Actual original call in TRIBE_Building_Object::copy_obj.
    start, target = 0x004C9737, 0x00430810
    original = b'\xe8' + (target-start-5).to_bytes(4, 'little', signed=True)
    rebuilt = b'\xe8\0\0\0\0'
    bad = '?copy_obj@RGE_Action_Object@@UAEXPAVRGE_Master_Static_Object@@@Z'
    good = '?copy_obj@RGE_Combat_Object@@UAEXPAVRGE_Master_Static_Object@@@Z'
    a, b, result = compatible_relocation_masks(original, rebuilt,
        [dict(offset=1, width=4, symbol_name=bad)], start)
    assert a != b
    assert result['target_mismatches'][0]['identity']['expected_symbol'] == good
    a, b, result = compatible_relocation_masks(original, rebuilt,
        [dict(offset=1, width=4, symbol_name=good)], start)
    assert a == b
    assert not result['target_mismatches']


def test_unknown_identity_cannot_mask_call(monkeypatch):
    monkeypatch.setattr(identity, 'original_identities', lambda: {})
    a, b, result = compatible_relocation_masks(b'\xe8\x10\0\0\0', b'\xe8\0\0\0\0',
        [dict(offset=1, width=4, symbol_name='?copy_obj@Wrong@@QAEXXZ')], 0x1000)
    assert a != b
    assert result['target_unknowns']
    assert not result['target_mismatches']


def test_conflicting_original_symbols_remain_unknown(monkeypatch):
    monkeypatch.setattr(identity, 'original_identities', lambda: {
        0x1000: dict(symbol=None, symbols={'_f': ['FPO'], '_g': ['supplement']})})
    assert identity.check_direct_identity(0x1000, '_f')['result'] == 'unknown'


def test_direct_addend_cannot_hide_interior_target(monkeypatch):
    monkeypatch.setattr(identity, 'original_identities', lambda: {0x1015: dict(symbol='_f', symbols={'_f': ['test']})})
    _, _, result = compatible_relocation_masks(b'\xe8\x10\0\0\0', b'\xe8\1\0\0\0',
        [dict(offset=1, width=4, symbol_name='_f')], 0x1000)
    assert result['target_unknowns'][0]['identity']['addend'] == 1


def test_full_identity_keeps_signature_and_case():
    assert not identity.compare_identity('?f@A@@QAEHXZ', '?f@B@@QAEHXZ')
    assert not identity.compare_identity('?f@A@@QAEHXZ', '?f@A@@QAEHH@Z')
    assert not identity.compare_identity('_Foo', '_foo')
    assert identity.compare_identity('_f@4', '__imp__f@4')


def test_crt_aliases_are_target_scoped():
    assert identity.check_direct_identity(0x54CFE0, '_open')['result'] == 'pass'
    assert identity.check_direct_identity(0x54CFE0, '__open')['result'] == 'pass'
    assert identity.check_direct_identity(0x54CFE0, '_close')['result'] == 'fail'
    assert not identity.compare_identity('_open', '__open')
    assert identity.check_direct_identity(0x54B700, '__ftol')['result'] == 'pass'
    assert identity.check_direct_identity(0x54B9A0, '_strstr')['result'] == 'pass'


def test_reviewed_alias_cannot_erase_new_conflict(tmp_path, monkeypatch):
    monkeypatch.setattr(identity, 'CONFIG_DIR', tmp_path)
    monkeypatch.setattr(identity, 'load_original_owner_symbols', lambda: ({'00001000': '_other'}, {}))
    monkeypatch.setattr(identity, 'load_pdb_function_source_map', lambda: {})
    (tmp_path / 'reviewed_reference_identities.json').write_text(json.dumps(dict(
        inputs={}, evidence='test', targets={'00001000': dict(symbol='_f', aliases=['__f'])})))
    identity.original_identities.cache_clear()
    try:
        assert identity.check_direct_identity(0x1000, '_f')['result'] == 'unknown'
    finally:
        identity.original_identities.cache_clear()


def test_reviewed_identity_rejects_stale_input(tmp_path, monkeypatch):
    monkeypatch.setattr(identity, 'CONFIG_DIR', tmp_path)
    monkeypatch.setattr(identity, 'REPO_ROOT', tmp_path)
    monkeypatch.setattr(identity, 'load_original_owner_symbols', lambda: ({}, {}))
    monkeypatch.setattr(identity, 'load_pdb_function_source_map', lambda: {})
    (tmp_path / 'input').write_bytes(b'changed')
    (tmp_path / 'reviewed_reference_identities.json').write_text(json.dumps(dict(
        inputs={'input': '0' * 64}, evidence='test', targets={})))
    identity.original_identities.cache_clear()
    try:
        with pytest.raises(ValueError, match='input changed'):
            identity.original_identities()
    finally:
        identity.original_identities.cache_clear()


def test_data_relocation_remains_explicitly_unchecked():
    _, _, result = compatible_relocation_masks(bytes.fromhex('a100104000'), bytes.fromhex('a100000000'),
        [dict(offset=1, width=4, symbol_name='_data')], 0x400000)
    assert result['data_references'][0]['result'] == 'unknown'


def test_map_retains_duplicate_owners_and_addresses():
    rows = parse_symbols(' 0001:00000000 ?f@@YAXXZ 00401000 f a.obj\n'
                         ' 0001:00000010 ?f@@YAXXZ 00401010 f b.obj\n'
                         ' 0002:00000000 _data 00500000   data.obj\n')
    assert len(rows) == 3
    assert rows[0]['owner'] == 'a.obj'
    assert unique_addresses(rows) == {'_data': 0x500000}


def test_emission_selection_requires_unique_map_owner():
    candidates = [dict(object='build/a.obj'), dict(object='build/b.obj')]
    row = dict(symbol='_f', address=0x401000, owner='a.obj')
    assert selected_emission(candidates, [row], '_f')['emission'] == candidates[0]
    assert selected_emission(candidates, [row, dict(row, owner='b.obj')], '_f')['result'] == 'unknown'
    assert selected_emission(candidates, [dict(row, owner='library:a.obj')], '_f')['result'] == 'unknown'


def test_reference_window_uses_any_next_symbol_without_claiming_boundary():
    pe = SimpleNamespace(OPTIONAL_HEADER=SimpleNamespace(ImageBase=0x400000),
        sections=[SimpleNamespace(VirtualAddress=0x1000, Misc_VirtualSize=0x100, Characteristics=0x20000000)])
    row = dict(address=0x401000, segment=1)
    size, reason = window(pe, row, [row, dict(address=0x401020, segment=1, function=False)])
    assert size == 0x20
    assert 'not a proved' in reason


def test_reference_wrong_hash_fails_before_parsing(tmp_path):
    exe, map_path = tmp_path / 'a.exe', tmp_path / 'a.map'
    exe.write_bytes(b'bad')
    map_path.write_bytes(b'bad')
    with pytest.raises(ValueError, match='hash'):
        verify_pair(exe, map_path, dict(exe_sha256='wrong', map_sha256='wrong'))


def test_disassembly_names_calls_without_guessing_integer_addresses():
    pe = SimpleNamespace(OPTIONAL_HEADER=SimpleNamespace(ImageBase=0x400000),
                         get_data=lambda rva, size: bytes.fromhex('e80b000000b810004000c3'))
    result = disassemble(pe, 0x400000, 11, [dict(address=0x400010, symbol='_f')])
    assert result['calls'][0]['target_symbols'] == ['_f']
    assert 'absolute_references' not in result['instructions'][1]


def test_reference_names_only_proven_pointer_immediates():
    pe = SimpleNamespace(OPTIONAL_HEADER=SimpleNamespace(ImageBase=0x400000),
        DIRECTORY_ENTRY_BASERELOC=[SimpleNamespace(entries=[SimpleNamespace(rva=1, type=3)])],
        get_data=lambda rva, size: bytes.fromhex('b810004000c3'))
    row = disassemble(pe, 0x400000, 6, [dict(address=0x400010, symbol='_table')])['instructions'][0]
    assert row['address_constant']['symbols'] == ['_table']


def test_reviewed_initial_pointer_uses_owner_offset(monkeypatch):
    a = (0x1004).to_bytes(4, 'little') + b'\x03\0\0\0'
    b = (0x2004).to_bytes(4, 'little') + b'\x03\0\0\0'
    monkeypatch.setattr(linked, 'read_storage', lambda pe, va, size: a if pe == 'original' else b)
    entry = dict(symbol='_table', original_va='00300000', size=8, check_initial_bytes=True, pointer_offsets=[0])
    owners = [dict(original=0x1000, rebuilt=0x2000, size=8, name='_owner')]
    rows = linked.check_initial_storage('original', 'rebuilt', entry, 0x400000, {}, owners)
    assert all(r['result'] == 'pass' for r in rows)
    rows = linked.check_initial_storage('original', 'rebuilt', entry, 0x400000, {}, [])
    assert rows[1]['result'] == 'unknown'


def test_initial_pointer_and_plain_byte_failures_are_separate(monkeypatch):
    monkeypatch.setattr(linked, 'read_storage', lambda pe, va, size:
                        bytes(8) if pe == 'original' else b'\1\0\0\0\2\0\0\0')
    entry = dict(symbol='_table', original_va='00300000', size=8, check_initial_bytes=True, pointer_offsets=[0])
    rows = linked.check_initial_storage('original', 'rebuilt', entry, 0x400000, {}, [])
    assert [r['result'] for r in rows] == ['fail', 'fail']
    assert rows[0]['differing_offsets'] == [4]


def test_unreviewed_initial_storage_is_unknown():
    rows = linked.check_initial_storage(None, None, dict(symbol='_a'), 0, {}, [])
    assert rows[0]['result'] == 'unknown'


def test_wrong_vtable_target_fails_without_a_vacuous_plain_pass(monkeypatch):
    monkeypatch.setattr(linked, 'read_storage', lambda pe, va, size:
                        (0x1000 if pe == 'original' else 0x3000).to_bytes(4, 'little'))
    entry = dict(symbol='_vtable', original_va='00300000', size=4, check_initial_bytes=True, pointer_offsets=[0])
    rows = linked.check_initial_storage('original', 'rebuilt', entry, 0x400000, {0x1000: ('_f', 0x2000)}, [])
    assert len(rows) == 1
    assert rows[0]['result'] == 'fail'
    assert rows[0]['expected'] == '00002000'


def test_build_rejects_changed_artifacts(tmp_path, monkeypatch):
    monkeypatch.setattr(linked_inputs, 'REPO_ROOT', tmp_path)
    monkeypatch.setattr(linked_inputs, 'registry_digest', lambda: 'registry')
    (tmp_path / 'config').mkdir()
    (tmp_path / 'original.exe').write_bytes(b'original')
    spec = dict(original='original.exe', original_sha256=hashlib.sha256(b'original').hexdigest())
    (tmp_path / 'config/executable.json').write_text(json.dumps(spec))
    (tmp_path / 'empiresx.exe').write_bytes(b'exe')
    (tmp_path / 'empiresx.map').write_bytes(b'map')
    report = dict(linked=True, config=spec, registry_sha256='registry', artifact_sha256={
        name: linked_inputs.digest(tmp_path / name) for name in ('empiresx.exe', 'empiresx.map')})
    (tmp_path / 'report.json').write_text(json.dumps(report))
    assert linked_inputs.verify_build(tmp_path)['linked']
    (tmp_path / 'empiresx.map').write_bytes(b'stale')
    with pytest.raises(ValueError, match='artifact changed'):
        linked_inputs.verify_build(tmp_path)
