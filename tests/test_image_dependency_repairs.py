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
from capstone.x86 import X86_OP_IMM

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audit_image_dependencies import check_code
from common import REPO_ROOT
from linked_inputs import digest
from linker_map import parse_symbols, unique_addresses
from reference_identity import original_identities

ORIGINAL_HASH = '88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90'
# Original instruction offsets, read widths, and stored bytes.
LITERALS = {
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
        assert row['size'] == width
        assert row['original_hex'] == row['rebuilt_hex'] == value
        assert row['result'] == 'pass'


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
