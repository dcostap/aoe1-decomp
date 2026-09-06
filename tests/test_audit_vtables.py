from types import SimpleNamespace
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audit_vtables import table_definitions


def test_table_slots_use_symbol_start_and_stop_at_next_owner():
    symbols = [
        SimpleNamespace(name='??_7Example@@6B@', section_number=1, value=4, storage_class=2),
        SimpleNamespace(name='next_constant', section_number=1, value=12, storage_class=2),
        SimpleNamespace(name='??_7Undefined@@6B@', section_number=0, value=0, storage_class=2),
    ]
    relocations = [SimpleNamespace(offset=i, symbol_name='slot' + str(i), reloc_type=6, width=4)
                   for i in (0, 4, 8, 12)]
    section = SimpleNamespace(data=b'\0' * 8 + b'\x04\0\0\0' + b'\0' * 4,
                              relocations=relocations)
    obj = SimpleNamespace(symbols=symbols, section_by_index=lambda _: section)
    assert list(table_definitions(obj)) == [
        ('??_7Example@@6B@', [(0, 'slot4', 0), (4, 'slot8', 4)])]


def test_table_slots_ignore_non_pointer_relocations():
    symbol = SimpleNamespace(name='??_7Example@@6B@', section_number=1, value=0, storage_class=2)
    relocation = SimpleNamespace(offset=0, symbol_name='relative', reloc_type=20, width=4)
    obj = SimpleNamespace(symbols=[symbol], section_by_index=lambda _: SimpleNamespace(
        data=b'\0' * 4, relocations=[relocation]))
    assert list(table_definitions(obj)) == [('??_7Example@@6B@', [])]
