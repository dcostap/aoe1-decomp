from types import SimpleNamespace as NS
from pathlib import Path
import struct
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from linked_data_pairs import LONG_RUN, align_function, pair_references, value_extent

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


def switch_run(tmp_path, original_entries):
    """A function of 9 bytes whose jump table lies after its registry size."""
    body = b'\xff\x24\x85\0\0\0\0\xc3\xc3'
    symbols = [(b'_f', 0, 1, 0x20, 2), (b'$Ltab', 9, 1, 0, 6), (b'$La', 7, 1, 0, 6), (b'$Lb', 8, 1, 0, 6)]
    coff(tmp_path / 'a.obj', body + bytes(8), b'\0\0\0\0', [(3, 1, 6), (9, 2, 6), (13, 3, 6)], symbols)

    def text(entries):
        code = b'\xff\x24\x85' + (BASE + 0x1009).to_bytes(4, 'little') + b'\xc3\xc3'
        return code + b''.join((BASE + 0x1000 + e).to_bytes(4, 'little') for e in entries)
    rebuilt = pe(0x1000, text([7, 8]), 0x2000, b'\0\0\0\0')
    original = pe(0x1000, text(original_entries), 0x2000, b'\0\0\0\0')
    rows = [dict(symbol='_f', address=BASE + 0x1000, owner='a.obj')]
    result = pair_references(original, rebuilt, rows, {'a.obj': tmp_path / 'a.obj'},
                             [(BASE + 0x1000, '_f', 9)], {'_f': BASE + 0x1000})
    return [(c['kind'], c['result']) for c in result['checks']]


def test_switch_table_after_function_is_compared(tmp_path):
    assert switch_run(tmp_path, [7, 8]) == [('internal_label', 'pass'), ('switch_table', 'pass')]


def test_switch_table_with_swapped_cases_fails(tmp_path):
    # The code bytes match, but the original sends each case to the other block.
    assert switch_run(tmp_path, [8, 7]) == [('internal_label', 'pass'), ('switch_table', 'fail')]


def aligned_switch_run(tmp_path, original_entries):
    """The switch function of switch_run, compared as a non-exact function."""
    body = b'\xff\x24\x85\0\0\0\0\xc3\xc3'
    symbols = [(b'_f', 0, 1, 0x20, 2), (b'$Ltab', 9, 1, 0, 6), (b'$La', 7, 1, 0, 6), (b'$Lb', 8, 1, 0, 6)]
    coff(tmp_path / 'a.obj', body + bytes(8), b'\0\0\0\0', [(3, 1, 6), (9, 2, 6), (13, 3, 6)], symbols)

    def text(entries):
        code = b'\xff\x24\x85' + (BASE + 0x1009).to_bytes(4, 'little') + b'\xc3\xc3'
        return code + b''.join((BASE + 0x1000 + e).to_bytes(4, 'little') for e in entries)
    rebuilt = pe(0x1000, text([7, 8]), 0x2000, b'\0\0\0\0')
    original = pe(0x1000, text(original_entries), 0x2000, b'\0\0\0\0')
    rows = [dict(symbol='_f', address=BASE + 0x1000, owner='a.obj')]
    result = pair_references(original, rebuilt, rows, {'a.obj': tmp_path / 'a.obj'}, [],
                             {'_f': BASE + 0x1000}, [(BASE + 0x1000, '_f', 9, 'accepted_drift')])
    return [(c['seed'], c['kind'], c['result']) for c in result['checks']]


def test_aligned_switch_table_passes_with_same_targets(tmp_path):
    assert aligned_switch_run(tmp_path, [7, 8]) == [('aligned', 'switch_table', 'pass')]


def test_aligned_switch_table_with_other_labels_but_same_partition(tmp_path):
    # Blocks of a non-exact function may move, so differing labels alone are not a failure.
    assert aligned_switch_run(tmp_path, [8, 7]) == [('aligned', 'switch_table', 'partition_pass')]


def test_aligned_switch_table_with_merged_cases_fails(tmp_path):
    # Both original cases share one block; the rebuilt cases do not.
    assert aligned_switch_run(tmp_path, [7, 7]) == [('aligned', 'switch_table', 'fail')]


def pushes(count, address):
    return b''.join(b'\x68' + (address + 4 * i).to_bytes(4, 'little') for i in range(count)) + b'\xc3'


def test_alignment_pairs_fields_in_long_runs_after_an_insertion():
    original = pushes(LONG_RUN, BASE + 0x2010)
    rebuilt = b'\x90' + pushes(LONG_RUN, BASE + 0x2000)
    fields = [2 + 5 * i for i in range(LONG_RUN)]
    none = lambda kind, value: None
    mapping, labels, count, changed = align_function(original, BASE + 0x1000, rebuilt, BASE + 0x1000, fields,
                                                     none, none)
    assert count == LONG_RUN + 2 and changed == []
    assert mapping[1] == (BASE + 0x1000, 5) and mapping[1 + 5 * (LONG_RUN - 1)] == (BASE + 0x1000 + 5 * 7, 5)
    assert 0 not in labels


def test_alignment_needs_an_anchor_for_short_runs():
    original, rebuilt = pushes(2, BASE + 0x2010), b'\x90' + pushes(2, BASE + 0x2000)
    none = lambda kind, value: None
    mapping, labels, _, _ = align_function(original, BASE + 0x1000, rebuilt, BASE + 0x1000, [2, 7], none, none)
    assert mapping == {} and labels[1] == (BASE + 0x1000, 5)

    def identify(kind, value):
        return ('data', value & ~0xff | 0x10) if kind == 'memory' else None
    mapping, _, _, _ = align_function(original, BASE + 0x1000, rebuilt, BASE + 0x1000, [2, 7], identify, identify)
    assert mapping[1] == (BASE + 0x1000, 5)


def calls(at, targets):
    return b''.join(b'\xe8' + ((t - (at + 5 * i + 5)) & 0xffffffff).to_bytes(4, 'little')
                    for i, t in enumerate(targets)) + b'\xc3'


def test_alignment_reports_a_changed_callee_between_anchors():
    at = BASE + 0x1000
    identify = lambda kind, value: ('function', value) if kind == 'target' else None
    original = calls(at, [0x500000, 0x510000, 0x520000])
    rebuilt = calls(at, [0x500000, 0x530000, 0x520000])
    _, _, _, changed = align_function(original, at, rebuilt, at, [], identify, identify)
    assert changed == [(5, ('function', 0x530000), ('function', 0x510000))]


def test_value_extent_uses_names_and_strings_not_guesses():
    assert value_extent('__real@4@3fff8000000000000000', bytes(8), []) == (4, 'float constant name')
    assert value_extent('?g_scale@@3MA', bytes(8), []) == (4, 'scalar decoration')
    assert value_extent('?g_name@@3PADA', b'ab\0\0\0\0', []) == (3, 'character string')
    # A relocated field or non-text bytes keep the object extent.
    assert value_extent('$T1', b'ab\0\0\0\0', [0]) == (6, 'next symbol')
    assert value_extent('$T1', b'\x01\x02\0\0', []) == (4, 'next symbol')
