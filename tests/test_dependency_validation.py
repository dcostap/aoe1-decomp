"""Checks for local literals, linked emissions, and guarded dispatch tables."""
import struct
import sys
from pathlib import Path
from types import SimpleNamespace as NS

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from coff import CoffObject, CoffSection, CoffSymbol, CoffRelocation
from object_dependencies import compare_object_dependencies
from linked_emissions import LinkedEmissions, relocate_span
from audit_image_dependencies import check_code


def symbol(index, name, section, value=0, function=False):
    return CoffSymbol(index, name, value, section, 0x20 if function else 0, 2, 0)


class Image:
    OPTIONAL_HEADER = NS(ImageBase=0)

    def __init__(self, code, value, code_va=0x100, value_va=0x200):
        self.parts = [(code_va, code), (value_va, value)]
        self.sections = [NS(VirtualAddress=va, Misc_VirtualSize=len(data), SizeOfRawData=len(data),
                            Characteristics=0x60000000 if n == 0 else 0x40000000)
                         for n, (va, data) in enumerate(self.parts)]

    def get_data(self, rva, size):
        for va, data in self.parts:
            if va <= rva and rva+size <= va+len(data):
                return data[rva-va:rva-va+size]
        return b''


def literal_object(value):
    body = b'\xd9\x05\0\0\0\0\xc3'
    fn = symbol(0, 'fn', 1, function=True)
    obj = CoffObject([CoffSection('.text', body, [CoffRelocation(2, 1, 6, 4, 'literal')], 1, 0x60000000),
                      CoffSection('.rdata', struct.pack('<f', value), [], 2, 0x40000000)],
                     [fn, symbol(1, 'literal', 2)])
    return obj, fn, body


def test_local_constant_gate_reads_complete_object():
    obj, fn, body = literal_object(0.5)
    original = b'\xd9\x05\x00\x02\x00\x00\xc3'
    pe = Image(original, struct.pack('<f', -0.5))
    result = compare_object_dependencies(obj, fn, original, body, 0x100, True, pe)
    assert result['counts'] == {'fail': 1}
    obj, fn, body = literal_object(-0.5)
    assert compare_object_dependencies(obj, fn, original, body, 0x100, True, pe)['result'] == 'pass'
    assert compare_object_dependencies(obj, fn, original, b'bad', 0x100, True, pe)['result'] == 'unknown'


def test_local_external_and_unaligned_are_unknown():
    obj, fn, body = literal_object(0.5)
    external = CoffObject(obj.sections, [fn, symbol(1, 'literal', 0)])
    original = b'\xd9\x05\x00\x02\x00\x00\xc3'
    result = compare_object_dependencies(external, fn, original, body, 0x100, True)
    assert result['result'] == 'unknown'
    assert compare_object_dependencies(obj, fn, original, body, 0x100, False)['result'] == 'unknown'


def test_coff_relocation_checks_addend_and_same_section_label():
    fn = symbol(0, 'fn', 1, function=True)
    obj = CoffObject([CoffSection('.text', b'\0'*8, [CoffRelocation(0, 1, 0x14, 4),
                                                    CoffRelocation(4, 2, 6, 4)], 1)],
                     [fn, symbol(1, 'callee', 0), symbol(2, '$case', 1, 7)])
    raw, refs = relocate_span(obj, fn, 0x100, {'callee': 0x200}, {}, 0)
    assert int.from_bytes(raw[:4], 'little') == 0xFC
    assert int.from_bytes(raw[4:], 'little') == 0x107
    with pytest.raises(ValueError, match='unique linked address'):
        relocate_span(obj, fn, 0x100, {}, {}, 0)


def test_linked_emission_requires_actual_positional_equality():
    obj, fn, body = literal_object(0.5)
    linked = b'\xd9\x05\x00\x02\x00\x00\xc3'
    index = LinkedEmissions.__new__(LinkedEmissions)
    index.pe = Image(linked, struct.pack('<f', 0.5))
    index.maps = [dict(symbol='fn', address=0x100, owner='owner.obj'),
                  dict(symbol='literal', address=0x200, owner='owner.obj')]
    index.symbols = {'fn': 0x100, 'literal': 0x200}
    index.objects = {'owner.obj': obj}
    index.folded, index.cache, index.anchor_cache = set(), {}, {}
    assert index.verify('fn')['size'] == 7
    index.symbols, index.maps, index.cache, index.anchor_cache = {'fn': 0x100}, index.maps[:1], {}, {}
    assert index.verify('fn')['result'] == 'bounded_emitted_span'
    assert index.verify('fn')['unresolved_relocations'] == 1
    index.pe = Image(b'\xcc' + linked[1:], struct.pack('<f', 0.5))
    index.cache = {}
    assert index.verify('fn')['result'] == 'unknown'
    index.folded, index.cache = {'fn'}, {}
    assert 'folded' in index.verify('fn')['reason']


def test_guarded_switch_checks_every_target():
    # cmp eax,1; ja default; jmp [eax*4+table]; ret; ret
    def code(table):
        return b'\x83\xf8\x01\x77\x07\xff\x24\x85' + struct.pack('<I', table) + b'\xc3\xc3'
    a = Image(code(0x200), struct.pack('<II', 0x10c, 0x10d))
    b = Image(code(0x400), struct.pack('<II', 0x30c, 0x30d), 0x300, 0x400)
    rows = check_code(a, b, 0x100, 0x300, 14, {}, [])
    assert [r['result'] for r in rows if r['kind'] == 'switch_table'] == ['pass', 'pass']
    b = Image(code(0x400), struct.pack('<II', 0x30d, 0x30d), 0x300, 0x400)
    rows = check_code(a, b, 0x100, 0x300, 14, {}, [])
    assert [r['result'] for r in rows if r['kind'] == 'switch_table'] == ['fail', 'pass']


def test_previously_reviewed_strings_have_proved_original_bytes(monkeypatch):
    import reviewed_storage
    from object_dependencies import original_image
    pe = original_image()
    entries = reviewed_storage.load_reviewed_storage(pe)
    assert len(entries) == 81
    assert len({e['symbol'] for e in entries}) == len(entries)
    monkeypatch.setattr(reviewed_storage, 'read_storage', lambda *args: b'bad')
    with pytest.raises(ValueError, match='extent differs'):
        reviewed_storage.load_reviewed_storage(pe)
