from types import SimpleNamespace as NS
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from linked_data_pairs import pair_references, value_extent

BASE = 0x400000


def coff(path, text, data, relocs, symbols):
    """Write a two-section COFF object. relocs: [(offset, symbol_index, type)] in .text."""
    sections = [(b'.text\0\0\0', text, relocs, 0x60000020), (b'.data\0\0\0', data, [], 0xC0000040)]
    header_size = 20 + 40 * len(sections)
    raw = bytearray()
    table = bytearray()
    offset = header_size
    layout = []
    for name, body, rels, flags in sections:
        layout.append((name, len(body), offset, offset + len(body) if rels else 0, len(rels), flags))
        raw += body + b''.join(struct.pack('<IIH', o, s, t) for o, s, t in rels)
        offset += len(body) + 10 * len(rels)
    for name, size, pointer, reloc_pointer, count, flags in layout:
        table += struct.pack('<8sIIIIIIHHI', name, 0, 0, size, pointer, reloc_pointer, 0, count, 0, flags)
    symtab = b''.join(struct.pack('<8sIhHBB', n.ljust(8, b'\0'), v, sec, typ, cls, 0) for n, v, sec, typ, cls in symbols)
    head = struct.pack('<HHIIIHH', 0x14C, len(sections), 0, header_size + len(raw), len(symbols), 0, 0)
    path.write_bytes(head + table + raw + symtab + struct.pack('<I', 4))


def pe(text_rva, text, data_rva, data):
    def section(name, rva, body):
        return NS(Name=name, VirtualAddress=rva, Misc_VirtualSize=len(body), SizeOfRawData=len(body),
                  get_data=lambda body=body: body)
    return NS(OPTIONAL_HEADER=NS(ImageBase=BASE),
              sections=[section(b'.text', text_rva, text), section(b'.data', data_rva, data)])


def run(tmp_path, original_string, rebuilt_string=b'hi\0\0'):
    symbols = [(b'_f', 0, 1, 0x20, 2), (b'$SG1', 0, 2, 0, 3)]
    coff(tmp_path / 'a.obj', b'\x68\0\0\0\0\xc3', rebuilt_string, [(1, 1, 6)], symbols)
    rebuilt = pe(0x1000, b'\x68' + (BASE + 0x2000).to_bytes(4, 'little') + b'\xc3', 0x2000, rebuilt_string)
    original = pe(0x1000, b'\x68' + (BASE + 0x2010).to_bytes(4, 'little') + b'\xc3', 0x2000,
                  bytes(16) + original_string)
    rows = [dict(symbol='_f', address=BASE + 0x1000, owner='a.obj')]
    return pair_references(original, rebuilt, rows, {'a.obj': tmp_path / 'a.obj'},
                           [(BASE + 0x1000, '_f', 6)], {'_f': BASE + 0x1000})


def test_pairs_string_through_exact_function(tmp_path):
    result = run(tmp_path, b'hi\0\0')
    assert result['seeds'] == {'exact seed': 1}
    assert [(p['rebuilt'], p['original'], p['result']) for p in result['pairs']] == [('00402000', '00402010', 'consistent')]
    assert [(i['result'], i['size'], i['extent']) for i in result['items']] == [('equal', 3, 'character string')]


def test_reports_different_string_text(tmp_path):
    result = run(tmp_path, b'ho\0\0')
    assert result['items'][0]['result'] == 'different'
    assert result['items'][0]['first_differences'] == [1]


def test_function_differing_outside_relocations_is_not_a_seed(tmp_path):
    symbols = [(b'_f', 0, 1, 0x20, 2), (b'$SG1', 0, 2, 0, 3)]
    coff(tmp_path / 'a.obj', b'\x68\0\0\0\0\xc3', b'hi\0\0', [(1, 1, 6)], symbols)
    rebuilt = pe(0x1000, b'\x68' + (BASE + 0x2000).to_bytes(4, 'little') + b'\xc3', 0x2000, b'hi\0\0')
    original = pe(0x1000, b'\x68' + (BASE + 0x2000).to_bytes(4, 'little') + b'\xc2', 0x2000, b'hi\0\0')
    rows = [dict(symbol='_f', address=BASE + 0x1000, owner='a.obj')]
    result = pair_references(original, rebuilt, rows, {'a.obj': tmp_path / 'a.obj'}, [(BASE + 0x1000, '_f', 6)], {})
    assert result['seeds'] == {'original differs outside relocated fields': 1}
    assert result['pairs'] == [] and result['items'] == []


def test_value_extent_uses_names_and_strings_not_guesses():
    assert value_extent('__real@4@3fff8000000000000000', bytes(8), []) == (4, 'float constant name')
    assert value_extent('?g_scale@@3MA', bytes(8), []) == (4, 'scalar decoration')
    assert value_extent('?g_name@@3PADA', b'ab\0\0\0\0', []) == (3, 'character string')
    # A relocated field or non-text bytes keep the object extent.
    assert value_extent('$T1', b'ab\0\0\0\0', [0]) == (6, 'next symbol')
    assert value_extent('$T1', b'\x01\x02\0\0', []) == (4, 'next symbol')
