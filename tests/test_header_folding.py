"""Require explicit linker replacement records and actual object emissions."""
import sys
from pathlib import Path
from types import SimpleNamespace

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from linker_map import parse_folding
from audit_header_emissions import selected_emission, verified_folding, verify_folded_bytes


LOG = '''
    Selected symbol:
        "int Root::zero(void)" (?zero@Root@@QAEHXZ) from root.obj
    Replaced symbol(s):
        "int Child::zero(void)" (?zero@Child@@QAEHXZ) from child.obj
    Discarded "unused" (?unused@@YAXXZ) from unused.obj
'''
ROOT = '?zero@Root@@QAEHXZ'
CHILD = '?zero@Child@@QAEHXZ'


def fixture():
    child = dict(object='build/child.obj', section=1, offset=0)
    root = dict(object='build/root.obj', section=1, offset=0)
    maps = [dict(symbol=symbol, address=0x401000, owner='root.obj') for symbol in (ROOT, CHILD)]
    return [child], maps, {ROOT: [root]}, parse_folding(LOG)


def test_parse_only_explicit_replacements():
    assert parse_folding(LOG) == [dict(symbol=CHILD, owner='child.obj',
                                      selected_symbol=ROOT, selected_owner='root.obj')]
    assert parse_folding(LOG.split('Selected symbol:')[0] + '    Replaced symbol(s):\n        "x" (?x) from x.obj') == []


def test_select_original_emitter_and_keep_physical_owner_separate():
    candidates, maps, emissions, folding = fixture()
    result = selected_emission(candidates, maps, CHILD, emissions=emissions, folding=folding)
    assert result['result'] == 'selected'
    assert result['emission']['object'] == 'build/child.obj'
    assert result['physical_emission']['object'] == 'build/root.obj'
    assert result['physical_symbol'] == ROOT


def test_shared_address_without_log_is_not_proof():
    candidates, maps, emissions, _ = fixture()
    assert selected_emission(candidates, maps, CHILD, emissions=emissions)['result'] == 'unknown'


@pytest.mark.parametrize('damage', ['missing_object', 'wrong_address', 'cycle', 'conflict'])
def test_incomplete_or_conflicting_fold_is_unknown(damage):
    candidates, maps, emissions, folding = fixture()
    if damage == 'missing_object':
        emissions = {}
    elif damage == 'wrong_address':
        maps[0]['address'] += 16
    elif damage == 'cycle':
        folding.append(dict(symbol=ROOT, owner='root.obj', selected_symbol=CHILD, selected_owner='child.obj'))
    else:
        folding.append(dict(folding[0], selected_owner='other.obj'))
    assert selected_emission(candidates, maps, CHILD, emissions=emissions, folding=folding)['result'] == 'unknown'


def test_unrecorded_log_is_not_used_and_changed_log_fails(tmp_path):
    (tmp_path / 'link.log').write_text(LOG)
    assert verified_folding(tmp_path, {}) == []
    with pytest.raises(ValueError, match='link.log'):
        verified_folding(tmp_path, dict(artifact_sha256={'link.log': '0' * 64}))


def test_folded_bytes_require_both_objects_and_linked_image():
    candidates, maps, emissions, folding = fixture()
    selection = selected_emission(candidates, maps, CHILD, emissions=emissions, folding=folding)
    sections = {name: SimpleNamespace(data=b'\x33\xc0\xc3', relocations=[]) for name in ('child', 'root')}
    objects = {'build/' + name + '.obj': SimpleNamespace(section_by_index=lambda index, s=section: s)
               for name, section in sections.items()}
    pe = SimpleNamespace(OPTIONAL_HEADER=SimpleNamespace(ImageBase=0x400000), get_data=lambda address, size: b'\x33\xc0\xc3')
    assert verify_folded_bytes(selection, objects, pe, 3)
    sections['root'].data = b'\x33\xc0\xcb'
    assert not verify_folded_bytes(selection, objects, pe, 3)
    sections['root'].data = b'\x33\xc0\xc3'
    sections['child'].relocations = [object()]
    assert not verify_folded_bytes(selection, objects, pe, 3)
