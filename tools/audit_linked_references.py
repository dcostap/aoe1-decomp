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
from linked_inputs import verify_build
from linker_map import parse_symbols, unique_addresses
from reference_identity import original_identities
from audit_global_initializers import read_storage
from common import load_functions

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / 'orig/empiresx.exe'


def read_map(path):
    return unique_addresses(parse_symbols(path.read_text(errors='replace')))


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
                op.type == X86_OP_MEM and op.mem.base == 0
                and (op.mem.index == 0 or (ins.mnemonic == 'jmp' and op.mem.scale == 4))
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


def check_initial_storage(original, rebuilt, entry, address, functions, owners):
    """Compare reviewed plain bytes and explicit pointer fields separately."""
    row = dict(kind='initial_storage', owner=entry['symbol'])
    if not entry.get('check_initial_bytes'):
        return [dict(row, result='unknown', reason='initial layout not reviewed')]
    size = entry['size']
    offsets = entry.get('pointer_offsets', [])
    if len(set(offsets)) != len(offsets) or any(not isinstance(o, int) or o < 0 or o + 4 > size for o in offsets):
        raise ValueError('Invalid reviewed pointer offsets')
    if any(abs(a-b) < 4 for i, a in enumerate(offsets) for b in offsets[i+1:]):
        raise ValueError('Overlapping pointer fields')
    try:
        a = read_storage(original, int(entry['original_va'], 16), size)
        b = read_storage(rebuilt, address, size)
    except ValueError as error:
        return [dict(row, result='unknown', reason=str(error))]
    excluded = {i for offset in offsets for i in range(offset, offset+4)}
    differences = [i for i in range(size) if i not in excluded and a[i] != b[i]]
    rows = [dict(row, result='fail' if differences else 'pass',
                 plain_bytes_checked=size-len(excluded), differing_offsets=differences)] if size > len(excluded) else []
    for offset in offsets:
        target = int.from_bytes(a[offset:offset+4], 'little')
        actual = int.from_bytes(b[offset:offset+4], 'little')
        detail = {}
        if target == 0:
            result = 'pass' if actual == 0 else 'fail'
            detail['expected'] = '00000000'
        elif target in functions:
            name, expected = functions[target]
            result = 'pass' if actual == expected else 'fail'
            detail.update(expected=f'{expected:08X}', target_owner=name)
        else:
            result, resolved = classify(target, actual, owners)
            if resolved:
                detail.update(expected=resolved['expected'], target_owner=resolved['owner'])
            else:
                detail['reason'] = 'pointer target has no unique reviewed owner'
        rows.append(dict(row, kind='initial_pointer', offset=offset, result=result,
                         original_target=f'{target:08X}', rebuilt_target=f'{actual:08X}', **detail))
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    parser.add_argument('--owners', type=Path, default=ROOT / 'config/linked_reference_owners.json')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if not args.output.resolve().is_relative_to(ROOT / 'build'):
        parser.error('Output must be under build/')
    build = verify_build(args.build)
    original = pefile.PE(str(ORIGINAL))
    exe = args.build / 'empiresx.exe'
    rebuilt = pefile.PE(str(exe))
    symbols = read_map(args.build / 'empiresx.map')
    functions, rows = {}, []
    # Target identity must not depend on the caller or its relocated bytes.
    # Original symbols also cover header functions absent from build recipes.
    for va, evidence in original_identities().items():
        name = evidence['symbol']
        if name in symbols:
            functions[va] = (name, symbols[name])
    for path in (ROOT / 'config/functions').rglob('*.json'):
        for va, entry in json.loads(path.read_text()).get('functions', {}).items():
            if int(va, 16) in functions:
                continue
            elif entry.get('symbol') in symbols:
                rows.append(dict(function=va, symbol=entry['symbol'], result='unknown',
                                 reason='registry symbol lacks unique original linkage evidence'))
            else:
                rows.append(dict(function=va, symbol=entry.get('symbol'), result='unknown',
                                 reason='function symbol absent or ambiguous'))
    owners = []
    owner_entries = json.loads(args.owners.read_text())['owners']
    for entry in owner_entries:
        if not entry.get('evidence') or not isinstance(entry.get('size'), int) or entry['size'] <= 0:
            raise ValueError('Storage owners require evidence and a positive byte size')
        if entry['symbol'] not in symbols:
            rows.append(dict(result='unknown', reason='storage symbol absent or ambiguous', owner=entry['symbol']))
            continue
        owners.append(dict(original=int(entry['original_va'], 16), rebuilt=symbols[entry['symbol']],
                           size=entry['size'], name=entry['symbol']))
    for entry in owner_entries:
        if entry['symbol'] in symbols:
            rows.extend(check_initial_storage(original, rebuilt, entry, symbols[entry['symbol']], functions, owners))
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
    unknown_targets = Counter(r['original_target'] for r in rows if r['result'] == 'unknown' and 'original_target' in r)
    inventory_names = {r['va'].upper(): r['name'] for r in load_functions()}
    report = dict(schema=2, scope='Aligned original-size code windows and explicitly reviewed initial storage. Direct control references, absolute memory operands and PE HIGHLOW fields. Not whole-function equivalence, full coverage, or boundary proof.',
                  functions_examined=len(functions),
                  build_report_sha256=hashlib.sha256((args.build / 'report.json').read_bytes()).hexdigest(),
                  linked_map_sha256=hashlib.sha256((args.build / 'empiresx.map').read_bytes()).hexdigest(),
                  function_map_sha256=hashlib.sha256(json.dumps(functions, sort_keys=True).encode()).hexdigest(),
                  original_sha256=hashlib.sha256(ORIGINAL.read_bytes()).hexdigest(),
                  rebuilt_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(),
                  owners_sha256=hashlib.sha256(args.owners.read_bytes()).hexdigest(),
                  counts=dict(Counter(r['result'] for r in rows)),
                  unknown_reasons=dict(Counter(r.get('reason', 'unspecified') for r in rows if r['result'] == 'unknown')),
                  unknown_targets=[dict(original_target=va, references=count,
                                        inventory_name_hint=inventory_names.get(va),
                                        functions=sorted({r.get('function', '') for r in rows if r.get('original_target') == va}))
                                   for va, count in unknown_targets.most_common()], rows=rows)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['counts']))
    for row in rows:
        if row['result'] == 'fail':
            print(json.dumps(row))
    return int(any(r['result'] == 'fail' for r in rows))


if __name__ == '__main__':
    raise SystemExit(main())
