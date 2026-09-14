from types import SimpleNamespace as NS
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from diff_linked_image import difference_ranges, raw_ranges, region_at
import diff_linked_image as diff


def image():
    return NS(OPTIONAL_HEADER=NS(SizeOfHeaders=2), sections=[
        NS(PointerToRawData=2, SizeOfRawData=3, Name=b'.text\0\0\0')])


def test_positional_partition_and_tails():
    assert list(difference_ranges(b'abcd', b'aXc')) == [
        dict(offset=0, size=1, result='equal'),
        dict(offset=1, size=1, result='different'),
        dict(offset=2, size=1, result='equal'),
        dict(offset=3, size=1, result='original_only')]
    assert list(difference_ranges(b'', b'')) == []
    assert list(difference_ranges(b'', b'x')) == [dict(offset=0, size=1, result='rebuilt_only')]


def test_regions_split_equal_runs_and_cover_overlay():
    rows = list(raw_ranges(b'abcdef', b'abcdef', image(), image()))
    assert [(r['offset'], r['size'], r['original_region']) for r in rows] == [
        (0, 2, 'PE headers'), (2, 3, '.text'), (5, 1, 'unknown')]
    assert sum(r['size'] for r in rows) == 6


def test_overlap_is_not_assigned_an_owner():
    assert region_at(2, [(0, 4, 'one'), (2, 5, 'two')], 5) == 'overlapping regions'
    assert region_at(5, [(0, 4, 'one')], 5) == 'absent'


def test_code_reference_requires_identity(monkeypatch):
    def decode(pe, va, size):
        return b'code', [(1, 'control', pe)]
    monkeypatch.setattr(diff, 'decode', decode)
    functions = {100: ('function', 200)}
    result = diff.compare_code_references(100, 200, 0, 0, 4, functions, [])
    assert result['normalized_result'] == 'equal_supported_window'
    assert result['references'][0]['owner'] == 'function'
    assert diff.compare_code_references(100, 201, 0, 0, 4, functions, [])['normalized_result'] == 'changed_target'
    # Equal numeric addresses are not independent identity evidence.
    assert diff.compare_code_references(300, 300, 0, 0, 4, functions, [])['normalized_result'] == 'unknown'


def test_storage_reference_preserves_member_offset(monkeypatch):
    monkeypatch.setattr(diff, 'decode', lambda pe, va, size: (b'code', [(1, 'address', pe)]))
    owners = [dict(original=100, rebuilt=200, size=8, name='table')]
    assert diff.compare_code_references(104, 204, 0, 0, 4, {}, owners)['normalized_result'] == 'equal_supported_window'
    assert diff.compare_code_references(104, 200, 0, 0, 4, {}, owners)['normalized_result'] == 'changed_target'
    assert diff.compare_code_references(104, 204, 0, 0, 4, {}, owners * 2)['normalized_result'] == 'unknown'


def test_unaligned_code_is_unknown(monkeypatch):
    monkeypatch.setattr(diff, 'decode', lambda pe, va, size: (pe, []))
    assert diff.compare_code_references(b'a', b'b', 0, 0, 1, {}, [])['normalized_result'] == 'unknown'


def test_range_partition_all_small_lengths():
    for a in (b'', b'x', b'xyz', b'\0\0\0'):
        for b in (b'', b'x', b'yxz', b'\0\0\0\0'):
            rows = list(raw_ranges(a, b, image(), image()))
            cursor = 0
            for row in rows:
                assert row['offset'] == cursor
                assert row['size'] > 0
                cursor += row['size']
            assert cursor == max(len(a), len(b))
