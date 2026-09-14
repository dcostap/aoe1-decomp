"""Check numeric storage referenced by a complete compiled function object."""
from functools import lru_cache
from collections import Counter
import json

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_AC_READ
from capstone.x86 import X86_OP_MEM
from coff import function_symbol_section
from common import REPO_ROOT
from linked_inputs import digest
from dependency_values import FLOAT_READS, readonly_bytes


@lru_cache(maxsize=1)
def original_image():
    config = json.loads((REPO_ROOT / 'config/executable.json').read_text())
    path = REPO_ROOT / config['original']
    if digest(path) != config['original_sha256']:
        raise ValueError('Original EXE hash differs')
    return pefile.PE(str(path))


def summary(rows):
    counts = dict(Counter(r['result'] for r in rows))
    return dict(result='fail' if counts.get('fail') else 'unknown' if counts.get('unknown') else 'pass',
                counts=counts, rows=rows,
                scope='Object-local numeric operands only. External globals, tables, and linked storage remain unproved.')


def compare_object_dependencies(obj, symbol, original, rebuilt, va, aligned, pe=None):
    if not aligned:
        return summary([dict(result='unknown', reason='instruction windows do not align')])
    section = function_symbol_section(obj, symbol)
    if section.data[:len(rebuilt)] != rebuilt:
        return summary([dict(result='unknown', reason='extracted bytes differ from complete object')])
    symbols = {s.index: s for s in obj.symbols}
    relocations = {}
    for r in section.relocations:
        relocations.setdefault(r.offset, []).append(r)
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    instructions = list(decoder.disasm(original, va))
    if sum(i.size for i in instructions) != len(original):
        return summary([dict(result='unknown', reason='original instructions do not decode completely')])
    rows = []
    for ins in instructions:
        if ins.mnemonic not in FLOAT_READS:
            continue
        for op in ins.operands:
            if op.type != X86_OP_MEM or not op.access & CS_AC_READ:
                continue
            if op.mem.base or op.mem.index or op.mem.segment:
                continue
            offset = ins.address - va + ins.disp_offset
            row = dict(offset=ins.address-va, kind='numeric_operand', size=op.size,
                       original_target=f'{op.mem.disp & 0xffffffff:08X}')
            matches = relocations.get(offset, [])
            if len(matches) != 1 or matches[0].reloc_type != 6 or matches[0].width != 4:
                rows.append(dict(row, result='unknown', reason='no unique DIR32 operand relocation'))
                continue
            relocation = matches[0]
            target = symbols.get(relocation.symbol_index)
            if target is None or target.section_number <= 0:
                rows.append(dict(row, symbol=relocation.symbol_name, result='unknown', reason='external storage needs linked audit'))
                continue
            storage = obj.section_by_index(target.section_number)
            start = target.value + int.from_bytes(rebuilt[offset:offset+4], 'little')
            end = start + op.size
            row.update(symbol=target.name, object_section=storage.index, object_offset=start)
            if storage.characteristics & 0xA0000020 or not 0 <= start < end <= len(storage.data):
                rows.append(dict(row, result='unknown', reason='not a complete read-only numeric range'))
                continue
            if any(r.offset < end and r.offset + r.width > start for r in storage.relocations):
                rows.append(dict(row, result='unknown', reason='numeric storage contains relocations'))
                continue
            try:
                old = readonly_bytes(pe or original_image(), op.mem.disp & 0xffffffff, op.size)
            except ValueError as error:
                rows.append(dict(row, result='unknown', reason=str(error)))
                continue
            new = storage.data[start:end]
            rows.append(dict(row, result='pass' if old == new else 'fail', original_hex=old.hex(),
                             rebuilt_hex=new.hex(), reason='numeric bytes agree' if old == new else 'numeric bytes differ'))
    # No observed literal is not proof of every external dependency.
    return summary(rows or [dict(result='unknown', reason='no supported object-local numeric operands')])
