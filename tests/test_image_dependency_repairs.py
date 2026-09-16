"""Static regressions for recovered constants and switch case meanings.

Set AOE_DEPENDENCY_BUILD to a fresh build directory to check its linked data.
These checks do not execute either game or prove complete runtime behavior.
"""
import json
import os
from pathlib import Path
import struct
import sys

import pefile
import pytest
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
from capstone.x86 import X86_OP_IMM, X86_OP_MEM

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audit_image_dependencies import check_code
from common import REPO_ROOT
from linked_inputs import digest
from linker_map import parse_symbols, unique_addresses
from reference_identity import original_identities

ORIGINAL_HASH = '88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90'
# Original instruction offsets, read widths, and stored bytes.
LITERALS = {
    0x42FC90: (9, {0: (4, '0000803f')}),
    0x460EB0: (143, {11: (8, 'f1d4c853fb211940'), 50: (4, 'db0fc9c0'),
                     73: (8, 'f1d4c853fb211940'), 86: (4, 'db0fc940'),
                     92: (8, 'f1d4c853fb211940')}),
    0x51F310: (455, {431: (4, 'abaaaa3d')}),
    0x545E00: (457, {54: (4, 'cdcc8c3f'), 292: (4, 'cdcc8c3f')}),
}


def raw(pe, address, size):
    value = pe.get_data(address - pe.OPTIONAL_HEADER.ImageBase, size)
    assert len(value) == size
    return value


@pytest.fixture(scope='module')
def original():
    config = json.loads((REPO_ROOT / 'config/executable.json').read_text())
    path = REPO_ROOT / config['original']
    assert digest(path) == ORIGINAL_HASH
    return pefile.PE(str(path))


@pytest.fixture(scope='module', params=['original', 'rebuilt'])
def image(request, original):
    identities = original_identities()
    if request.param == 'original':
        return original, lambda va: va
    selected = os.environ.get('AOE_DEPENDENCY_BUILD')
    if not selected:
        pytest.skip('Set AOE_DEPENDENCY_BUILD to check a fresh linked build')
    build = Path(selected)
    report = json.loads((build / 'report.json').read_text())
    assert report['linked']
    for name in ('empiresx.exe', 'empiresx.map'):
        assert digest(build / name) == report['artifact_sha256'][name]
    symbols = unique_addresses(parse_symbols((build / 'empiresx.map').read_text()))
    return pefile.PE(str(build / 'empiresx.exe')), lambda va: symbols[identities[va]['symbol']]


def direct_target(pe, address):
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    ins = next(decoder.disasm(raw(pe, address, 5), address))
    assert ins.mnemonic == 'call' and ins.operands[0].type == X86_OP_IMM
    return ins.operands[0].imm


@pytest.mark.parametrize('va', LITERALS)
def test_exact_numeric_operands(image, original, va):
    pe, address = image
    size, expected = LITERALS[va]
    rows = check_code(original, pe, va, address(va), size, {}, [])
    reads = {row['offset']: row for row in rows
             if row['kind'] == 'memory_operand' and row.get('offset') in expected}
    assert set(reads) == set(expected), 'A lost aligned window is not a passing repair'
    for offset, (width, value) in expected.items():
        row = reads[offset]
        assert row['result'] == 'pass', row
        assert row['size'] == width
        assert row['original_hex'] == row['rebuilt_hex'] == value


def test_modify_percent_case_meanings(image):
    pe, address = image
    start = address(0x450D00)
    # The source attribute is one unsigned byte. Table index = attribute - 6.
    assert raw(pe, start + 9, 11).hex() == '25ff00000083c0fa83f80c'
    assert raw(pe, start + 20, 2) == b'\x0f\x87'
    fallback = start + 26 + struct.unpack('<i', raw(pe, start + 22, 4))[0]
    assert fallback == start + 0xD9
    assert raw(pe, start + 26, 3).hex() == 'ff2485'
    table = struct.unpack('<I', raw(pe, start + 29, 4))[0]
    targets = struct.unpack('<13I', raw(pe, table, 52))
    expected = {6: 0x21, 8: 0xE6, 9: 0xE6, 10: 0x35, 11: 0x49,
                12: 0x6C, 15: 0x80, 16: 0xA2, 18: 0xC5}
    for attribute in range(256):
        index = (attribute - 6) & 0xFFFFFFFF
        target = fallback if index > 12 else targets[index]
        assert target == start + expected.get(attribute, 0xD9)
    # Cases 8 and 9 return without inherited effects or object reads.
    assert raw(pe, start + 0xE6, 4).hex() == '5ec20800'
    assert direct_target(pe, start + 0xE1) == address(0x44F850)


def test_draw_front_frame_case_meanings(image):
    pe, address = image
    start = address(0x4C2110)
    # The game-mode-one path stays separate and calls cube-front.
    assert raw(pe, start + 5, 9).hex() == '83b8b4010000017517'
    assert direct_target(pe, start + 0x1D) == address(0x4C31E0)
    # The other path reads an unsigned byte and rejects values above three.
    assert raw(pe, start + 0x25, 12).hex() == '33d28a50508bc283f8037749'
    assert raw(pe, start + 0x31, 3).hex() == 'ff2485'
    table = struct.unpack('<I', raw(pe, start + 0x34, 4))[0]
    targets = struct.unpack('<4I', raw(pe, table, 16))
    assert targets == tuple(start + n for n in (0x38, 0x4F, 0x66, 0x66))
    assert raw(pe, start + 0x49, 3).hex() == 'ff5020'  # virtual draw_frame
    assert direct_target(pe, targets[1] + 15) == address(0x4C31E0)
    for target in targets[2:]:
        assert direct_target(pe, target + 15) == address(0x4C2B50)
    assert raw(pe, start + 0x7A, 3).hex() == 'c20c00'  # default: return


def test_conversion_action_state_dispatch(image):
    pe, address = image
    start = address(0x4CE070)
    # The unsigned state selects one of seven handlers through a byte table.
    assert raw(pe, start + 0xD7, 11).hex() == '33c08a460c4883f80c0f87'
    fallback = start + 0xE6 + struct.unpack('<i', raw(pe, start + 0xE2, 4))[0]
    assert fallback == start + 0x382
    assert raw(pe, start + 0xE6, 4).hex() == '33c98a88'
    selector = struct.unpack('<I', raw(pe, start + 0xEA, 4))[0]
    indices = raw(pe, selector, 13)
    assert raw(pe, start + 0xEE, 3).hex() == 'ff248d'
    table = struct.unpack('<I', raw(pe, start + 0xF1, 4))[0]
    targets = struct.unpack('<7I', raw(pe, table, 28))
    expected = {1: 0x34B, 4: 0x124, 6: 0x17C, 7: 0x1BD,
                11: 0xF5, 13: 0x353}
    for state in range(256):
        index = (state - 1) & 0xFFFFFFFF
        target = fallback if index > 12 else targets[indices[index]]
        assert target == start + expected.get(state, 0x382), f'state {state}'
    # Original tables 004CE428 and 004CE43C assign different move results.
    for jump, offsets in [(0x10C, (0x1C4, 0x1C4, 0x113, 0x142, 0x1C4)),
                          (0x13B, (0x16B, 0x16B, 0x15A, 0x142, 0x142))]:
        assert raw(pe, start + jump, 3).hex() == 'ff2485'
        table = struct.unpack('<I', raw(pe, start + jump + 3, 4))[0]
        assert struct.unpack('<5I', raw(pe, table, 20)) == tuple(start + n for n in offsets)
    # Successful state-4 movement must select turning, not idle.
    assert raw(pe, start + 0x16B, 4).hex() == '8b066a06'
    assert raw(pe, start + 0x1C4, 4).hex() == '8b166a03'


def test_transport_action_state_dispatch(image):
    pe, address = image
    start = address(0x406F90)
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    head = list(decoder.disasm(raw(pe, start, 48), start))
    # The byte at offset 0x0C selects one of six handlers through two tables.
    byte_loads = [ins.operands[1].mem.disp for ins in head if ins.mnemonic == 'mov'
                  and len(ins.operands) == 2 and ins.operands[1].type == X86_OP_MEM
                  and ins.operands[0].size == 1]
    jump = next(ins for ins in head if ins.mnemonic == 'jmp'
                and ins.operands[0].type == X86_OP_MEM)
    table = jump.operands[0].mem.disp
    assert byte_loads[0] == 0xC
    selector = next(disp for disp in byte_loads[1:] if disp != table)
    assert raw(pe, selector, 13).hex() == '00050501050205050505030504'
    targets = struct.unpack('<6I', raw(pe, table, 24))
    offsets = {state: targets[index] - start
               for state, index in ((n, raw(pe, selector + n - 1, 1)[0]) for n in range(1, 14))}
    # States 4 and 0x0B run the same sub-action, but they end in different states.
    assert offsets == {1: 360, 2: 409, 3: 409, 4: 72, 5: 409, 6: 110,
                       7: 409, 8: 409, 9: 409, 10: 409, 11: 34, 12: 409, 13: 365}
    for state, destination in ((4, 6), (0x0B, 2)):
        handler = []
        for ins in decoder.disasm(raw(pe, start + offsets[state], 40), start + offsets[state]):
            handler.append(ins)
            if ins.mnemonic == 'ret':
                break
        pushed = [ins.operands[0].imm for ins in handler if ins.mnemonic == 'push']
        assert pushed == [destination], f'state {state}'
        assert handler[-1].mnemonic == 'ret'


def test_selector_table_dispatch_is_compared(image, original):
    pe, address = image
    rows = check_code(original, pe, 0x406F90, address(0x406F90), 464, {}, [])
    tables = [row for row in rows if row['kind'] == 'selector_table']
    assert len(tables) == 13, rows[:3]
    assert all(row['result'] == 'pass' for row in tables), \
        [row for row in tables if row['result'] != 'pass']


def test_artifact_notify_dispatch_keeps_the_default_body(image, original):
    # The original switch covers event types 0x1F4..0x2BB. Only 28 of the 200
    # values return at once. The other 167 fall through to the default body,
    # which clears the target, stops the object, and notifies the commander.
    pe, address = image
    rows = check_code(original, pe, 0x507A30, address(0x507A30), 848, {}, [])
    tables = [row for row in rows if row['kind'] == 'selector_table']
    assert len(tables) == 200, len(tables)
    assert all(row['result'] == 'pass' for row in tables), \
        [row for row in tables if row['result'] != 'pass'][:3]
    default = [row for row in tables if row['original_target'] == '00507D2C']
    direct = [row for row in tables if row['original_target'] == '00507D74']
    assert len(default) == 167 and len(direct) == 28
    assert len({row['rebuilt_target'] for row in default}) == 1
    assert len({row['rebuilt_target'] for row in direct}) == 1
    assert set(row['rebuilt_target'] for row in default) != \
        set(row['rebuilt_target'] for row in direct)


@pytest.mark.parametrize('va,count', [(0x438670, 2), (0x438720, 2),
                                     (0x45A6D0, 1), (0x52EAC0, 4)])
def test_historical_numeric_repairs_remain_supported(image, original, va, count):
    from common import load_functions
    size = int(next(row['size_bytes'] for row in load_functions() if int(row['va'], 16) == va))
    pe, address = image
    rows = check_code(original, pe, va, address(va), size, {}, [])
    reads = [row for row in rows if row['kind'] == 'memory_operand']
    assert not any(row['result'] == 'fail' for row in reads)
    assert sum(row['result'] == 'pass' for row in reads) >= count
