import struct
import sys
import json
from pathlib import Path
from types import SimpleNamespace as NS

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audit_image_dependencies import check_code, compare_literal, readonly_bytes
from audit_linked_references import check_initial_storage
import pytest


class Image:
    OPTIONAL_HEADER = NS(ImageBase=0)

    def __init__(self, target, value, writable=False, code=None):
        self.code = code if code is not None else b'\xd9\x05' + struct.pack('<I', target) + b'\xc3'
        self.target = target
        self.value = value
        self.sections = [NS(VirtualAddress=0x100, Misc_VirtualSize=len(self.code),
                            SizeOfRawData=len(self.code), Characteristics=0x60000000),
                         NS(VirtualAddress=target, Misc_VirtualSize=len(value),
                            SizeOfRawData=len(value), Characteristics=0xC0000000 if writable else 0x40000000)]

    def get_data(self, rva, size):
        if 0x100 <= rva < 0x100 + len(self.code):
            return self.code[rva-0x100:rva-0x100+size]
        return self.value[rva-self.target:rva-self.target+size]


def literals(rows):
    return [r for r in rows if r['kind'] == 'memory_operand']


def test_wrong_literal_with_equal_instruction_shape():
    a, b = Image(0x200, struct.pack('<f', -0.5)), Image(0x300, struct.pack('<f', 0.5))
    rows = literals(check_code(a, b, 0x100, 0x100, 7, {}, []))
    assert rows[0]['result'] == 'fail'
    assert rows[0]['original_hex'] == '000000bf'
    assert rows[0]['rebuilt_hex'] == '0000003f'


def test_relocated_equal_literal_passes_value_check():
    a, b = Image(0x200, struct.pack('<f', -1)), Image(0x300, struct.pack('<f', -1))
    assert literals(check_code(a, b, 0x100, 0x100, 7, {}, []))[0]['result'] == 'pass'


def test_writable_operand_is_not_a_literal():
    a, b = Image(0x200, b'abcd', True), Image(0x300, b'abce', True)
    assert compare_literal(a, b, 0x200, 0x300, 4)['result'] == 'unknown'


def test_reviewed_version_initializer_bug():
    a = Image(0x200, struct.pack('<f', 7.23), True)
    b = Image(0x300, struct.pack('<f', 0), True)
    owner = dict(symbol='version', original_va='00000200', size=4,
                 check_initial_bytes=True, pointer_offsets=[])
    assert check_initial_storage(a, b, owner, 0x300, {}, [])[0]['result'] == 'fail'
    b.value = a.value
    assert check_initial_storage(a, b, owner, 0x300, {}, [])[0]['result'] == 'pass'


def test_base_relocation_content_is_not_literal():
    a = Image(0x200, b'abcd')
    a.DIRECTORY_ENTRY_BASERELOC = [NS(entries=[NS(type=3, rva=0x200)])]
    assert compare_literal(a, a, 0x200, 0x200, 4)['result'] == 'unknown'


def test_unaligned_fields_are_unknown():
    a = Image(0x200, b'abcd', code=b'\x8b\x40\x54\xc3')
    b = Image(0x200, b'abcd', code=b'\x8b\x40\x58\xc3')
    assert check_code(a, b, 0x100, 0x100, 4, {}, [])[0]['result'] == 'unknown'


def test_truncated_and_code_storage_rejected():
    a = Image(0x200, b'abcd')
    assert compare_literal(a, a, 0x200, 0x200, 8)['result'] == 'unknown'
    assert compare_literal(a, a, 0x100, 0x100, 4)['result'] == 'unknown'


def test_changed_direct_target_detected():
    def code(target):
        return b'\xe8' + struct.pack('<i', target - 0x105) + b'\xc3'
    a = Image(0x200, b'abcd', code=code(0x500))
    b = Image(0x300, b'abcd', code=code(0x700))
    checks = check_code(a, b, 0x100, 0x100, 6, {0x500: ('callee', 0x600)}, [])
    assert checks[0]['kind'] == 'reference_control'
    assert checks[0]['result'] == 'fail'


def test_untyped_load_is_not_assumed_to_be_numeric():
    a = Image(0x200, b'abcd', code=b'\xa1\x00\x02\x00\x00\xc3')
    b = Image(0x300, b'efgh', code=b'\xa1\x00\x03\x00\x00\xc3')
    row = literals(check_code(a, b, 0x100, 0x100, 6, {}, []))[0]
    assert row['result'] == 'unknown'
    assert row['reason'] == 'operand value type is not independently established'


@pytest.mark.parametrize('relative,expected_hash,expected_failures', [
    ('user/20260914T155318269945Z/20260914T155318520959Z',
     '95e46ebf03109684d589c24683974ac92607005756995f3835a04744f778b1a9', 9),
    ('human-civ-effect-repair/20260914T215953270395Z',
     '75ea997f420d64395b314f25d0b3b6bf75bb121c5dc962ee41f8f425bf58278b', 0),
])
def test_preserved_broken_and_repaired_images(relative, expected_hash, expected_failures):
    import pefile
    from common import REPO_ROOT, load_functions
    from linked_inputs import digest
    from linker_map import parse_symbols, unique_addresses
    from reference_identity import original_identities
    build = REPO_ROOT / 'build/executable' / relative
    if not (build / 'empiresx.exe').exists():
        pytest.skip('Optional preserved runtime build is unavailable')
    config = json.loads((REPO_ROOT / 'config/executable.json').read_text())
    original_path = REPO_ROOT / config['original']
    assert digest(original_path) == config['original_sha256']
    assert digest(build / 'empiresx.exe') == expected_hash
    report = json.loads((build / 'report.json').read_text())
    assert digest(build / 'empiresx.map') == report['artifact_sha256']['empiresx.map']
    original, rebuilt = pefile.PE(str(original_path)), pefile.PE(str(build / 'empiresx.exe'))
    symbols = unique_addresses(parse_symbols((build / 'empiresx.map').read_text()))
    identities = original_identities()
    selected = {'00438670': 2, '00438720': 2, '0045A6D0': 1, '0052EAC0': 4}
    failures = 0
    for item in load_functions():
        if item['va'] not in selected:
            continue
        va = int(item['va'], 16)
        address = symbols[identities[va]['symbol']]
        rows = literals(check_code(original, rebuilt, va, address, int(item['size_bytes']), {}, []))
        count = sum(r['result'] == 'fail' for r in rows)
        assert count == (selected[item['va']] if expected_failures else 0)
        if not expected_failures:
            assert sum(r['result'] == 'pass' for r in rows) >= selected[item['va']]
        failures += count
    assert failures == expected_failures
    if not expected_failures:
        table_failures = {'00450D00': 2, '004C2110': 3}
        for item in load_functions():
            if item['va'] not in table_failures:
                continue
            va = int(item['va'], 16)
            address = symbols[identities[va]['symbol']]
            rows = check_code(original, rebuilt, va, address, int(item['size_bytes']), {}, [])
            assert sum(r['kind'] == 'switch_table' and r['result'] == 'fail' for r in rows) == table_failures[item['va']]
