"""Check linked references against shared function and reviewed storage owners.

This is not a function equivalence or boundary checker. Unaligned code is unknown.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL, CS_GRP_JUMP
from capstone.x86 import X86_OP_IMM, X86_OP_MEM

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / 'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe'


def read_map(path):
    symbols = {}
    for line in path.read_text(errors='replace').splitlines():
        m = re.match(r'\s+\w{4}:\w{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+', line)
        if m:
            symbols.setdefault(m[1], set()).add(int(m[2], 16))
    return {name: next(iter(values)) for name, values in symbols.items() if len(values) == 1}


def decode(pe, va, size):
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    code = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, size)
    if not hasattr(pe, '_audit_relocations'):
        pe._audit_relocations = {pe.OPTIONAL_HEADER.ImageBase + item.rva
                                for block in getattr(pe, 'DIRECTORY_ENTRY_BASERELOC', [])
                                for item in block.entries if item.type == 3}
    relocations = pe._audit_relocations
    instructions = list(decoder.disasm(code, va))
    if sum(i.size for i in instructions) != size:
        return None
    signature, refs = bytearray(code), []
    for ins in instructions:
        offset = ins.address - va
        control = (ins.group(CS_GRP_CALL) or ins.group(CS_GRP_JUMP))
        if control and ins.operands and ins.operands[0].type == X86_OP_IMM:
            target = ins.operands[0].imm & 0xffffffff
            if not va <= target < va + size:
                refs.append((offset + ins.imm_offset, 'control', target))
                signature[offset + ins.imm_offset:offset + ins.imm_offset + ins.imm_size] = bytes(ins.imm_size)
        for field, width in ((ins.disp_offset, ins.disp_size), (ins.imm_offset, ins.imm_size)):
            absolute_memory = field == ins.disp_offset and any(
                op.type == X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0
                and op.mem.segment == 0 for op in ins.operands)
            if width == 4 and (absolute_memory or ins.address + field in relocations):
                position = offset + field
                target = int.from_bytes(code[position:position + 4], 'little')
                refs.append((position, 'address', target))
                signature[position:position + 4] = bytes(4)
    return bytes(signature), refs


def classify(target, actual, owners):
    candidates = [o for o in owners if o['original'] <= target < o['original'] + o['size']]
    if len(candidates) != 1:
        return 'unknown', None
    owner = candidates[0]
    expected = owner['rebuilt'] + target - owner['original']
    return ('pass' if actual == expected else 'fail'), dict(
        owner=owner['name'], expected=f'{expected:08X}')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--owners', type=Path, default=ROOT / 'config/linked_reference_owners.json')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if not args.output.resolve().is_relative_to(ROOT / 'build'):
        parser.error('Output must be under build/')
    original = pefile.PE(str(ORIGINAL))
    exe = args.build / 'empiresx.exe'
    rebuilt = pefile.PE(str(exe))
    symbols = read_map(args.build / 'empiresx.map')
    functions, rows = {}, []
    for path in (ROOT / 'config/functions').rglob('*.json'):
        for va, entry in json.loads(path.read_text()).get('functions', {}).items():
            if entry.get('symbol') in symbols:
                functions[int(va, 16)] = (entry['symbol'], symbols[entry['symbol']])
            else:
                rows.append(dict(function=va, symbol=entry.get('symbol'), result='unknown',
                                 reason='function symbol absent or ambiguous'))
    owners = []
    for entry in json.loads(args.owners.read_text())['owners']:
        if entry['symbol'] not in symbols:
            rows.append(dict(result='unknown', reason='storage symbol absent or ambiguous', owner=entry['symbol']))
            continue
        owners.append(dict(original=int(entry['original_va'], 16), rebuilt=symbols[entry['symbol']],
                           size=entry['size'], name=entry['symbol']))
    sizes = {}
    for path in (ROOT / 'inventory/functions').rglob('*.txt'):
        with path.open(errors='replace') as stream:
            header = ''.join(next(stream, '') for _ in range(8))
        match = re.search(r'^VA: ([0-9A-F]+).*?^SizeBytes: (\d+)', header, re.M | re.S)
        if match:
            sizes[int(match[1], 16)] = int(match[2])
    for va, (name, address) in sorted(functions.items()):
        row = dict(function=f'{va:08X}', symbol=name)
        size = sizes.get(va)
        if not size:
            rows.append(dict(row, result='unknown', reason='no original size'))
            continue
        a, b = decode(original, va, size), decode(rebuilt, address, size)
        if a is None or b is None or a[0] != b[0] or [(x, k) for x, k, _ in a[1]] != [(x, k) for x, k, _ in b[1]]:
            rows.append(dict(row, result='unknown', reason='code window does not align'))
            continue
        if not a[1]:
            rows.append(dict(row, result='unknown', reason='no supported references'))
        for (offset, kind, target), (_, _, actual) in zip(a[1], b[1]):
            if target in functions:
                expected = functions[target][1]
                result = 'pass' if expected == actual else 'fail'
                detail = dict(owner=functions[target][0], expected=f'{expected:08X}')
            else:
                result, detail = classify(target, actual, owners)
            rows.append(dict(row, offset=offset, kind=kind, original_target=f'{target:08X}',
                             rebuilt_target=f'{actual:08X}', result=result, **(detail or {'reason': 'no unique reviewed owner'})))
    report = dict(schema=1, scope='Aligned original-size code windows; direct control references, absolute memory operands and PE HIGHLOW address fields. Not whole-function equivalence, full coverage, or boundary proof.',
                  functions_examined=len(functions),
                  linked_map_sha256=hashlib.sha256((args.build / 'empiresx.map').read_bytes()).hexdigest(),
                  function_map_sha256=hashlib.sha256(json.dumps(functions, sort_keys=True).encode()).hexdigest(),
                  original_sha256=hashlib.sha256(ORIGINAL.read_bytes()).hexdigest(),
                  rebuilt_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(),
                  owners_sha256=hashlib.sha256(args.owners.read_bytes()).hexdigest(),
                  counts=dict(Counter(r['result'] for r in rows)), rows=rows)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['counts']))
    for row in rows:
        if row['result'] == 'fail':
            print(json.dumps(row))
    return int(any(r['result'] == 'fail' for r in rows))


if __name__ == '__main__':
    raise SystemExit(main())
