"""Audit linked code references, read-only operand bytes, and reviewed initial storage.

This static check does not execute the game. Unaligned code and unsupported
operands remain unknown. Windows must fit a hash-checked, symbol-owned COFF span.
"""
from __future__ import annotations

import argparse
from collections import Counter
import json
from pathlib import Path
import struct

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_AC_READ
from capstone.x86 import X86_OP_MEM, X86_OP_REG, X86_OP_IMM

from audit_global_initializers import read_storage
from audit_linked_references import check_initial_storage, decode
from common import REPO_ROOT, load_functions
from diff_linked_image import compare_code_references, write_csv
from linked_inputs import digest
from linker_map import parse_symbols, unique_addresses
from reference_identity import original_identities, validation_fingerprint
from linked_emissions import LinkedEmissions
from reviewed_storage import load_reviewed_storage, STRING_EVIDENCE

from dependency_values import FLOAT_READS, readonly_bytes


def compare_literal(original, rebuilt, target, actual, size):
    try:
        a = readonly_bytes(original, target, size)
        b = readonly_bytes(rebuilt, actual, size)
    except ValueError as error:
        return dict(result='unknown', reason=str(error))
    return dict(result='pass' if a == b else 'fail', original_hex=a.hex(), rebuilt_hex=b.hex(),
                reason='read-only operand bytes agree' if a == b else 'read-only operand bytes differ')


def check_switch_tables(original, rebuilt, left, right, va, address, size, functions):
    rows = []
    instruction_starts = {ins.address for ins in left}
    for i, ins in enumerate(left):
        if ins.mnemonic != 'jmp' or len(ins.operands) != 1 or ins.operands[0].type != X86_OP_MEM:
            continue
        mem = ins.operands[0].mem
        if mem.base or mem.segment or not mem.index or mem.scale != 4:
            continue
        row = dict(kind='switch_table', offset=ins.address-va)
        if i < 2:
            rows.append(dict(row, result='unknown', reason='no supported switch bound'))
            continue
        cmp, guard = left[i-2:i]
        if (cmp.mnemonic != 'cmp' or guard.mnemonic != 'ja' or len(cmp.operands) != 2
                or cmp.operands[0].type != X86_OP_REG or cmp.operands[0].reg != mem.index
                or cmp.operands[1].type != X86_OP_IMM or not 0 <= cmp.operands[1].imm < 4096
                or len(guard.operands) != 1 or guard.operands[0].type != X86_OP_IMM
                or cmp.address <= guard.operands[0].imm < ins.address + ins.size):
            rows.append(dict(row, result='unknown', reason='no adjacent unsigned guard for indexed switch'))
            continue
        count = cmp.operands[1].imm + 1
        target, actual = mem.disp & 0xffffffff, right[i].operands[0].mem.disp & 0xffffffff
        try:
            a = read_storage(original, target, count*4)
            b = read_storage(rebuilt, actual, count*4)
        except ValueError as error:
            rows.append(dict(row, result='unknown', reason=str(error)))
            continue
        for n in range(count):
            old, new = int.from_bytes(a[n*4:n*4+4], 'little'), int.from_bytes(b[n*4:n*4+4], 'little')
            expected = address + old - va if old in instruction_starts else functions.get(old, (None, None))[1]
            result = 'unknown' if expected is None else 'pass' if expected == new else 'fail'
            rows.append(dict(row, index=n, result=result, original_table=f'{target:08X}',
                             rebuilt_table=f'{actual:08X}', original_target=f'{old:08X}',
                             rebuilt_target=f'{new:08X}', expected=None if expected is None else f'{expected:08X}',
                             reason='guarded table slice; targets use aligned code offsets or independent functions'))
    return rows


def aligned_prefix_length(left, right):
    """Length in bytes of the leading region where both windows have the same instruction shapes."""
    length = 0
    for one, other in zip(left, right):
        if one.address - left[0].address != other.address - right[0].address:
            break
        if (one.size, one.mnemonic, [(op.type, op.size) for op in one.operands]) != \
                (other.size, other.mnemonic, [(op.type, op.size) for op in other.operands]):
            break
        length = one.address - left[0].address + one.size
    return length


def check_selector_tables(original, rebuilt, left, right, va, address, size, functions):
    """Compare switches that reach their handlers through a byte selector table.

    This is the sparse form: an unsigned bound check protects a byte table, and the byte
    from that table indexes the pointer table. Comparing the pointer table alone is not
    enough, because the semantics live in the pairing of the two tables.
    A handler is comparable only when its offset lies inside the region where both
    windows have equal instruction shapes. Outside that region the layout differs, so
    an offset difference proves nothing and the entry stays unknown.
    """
    prefix = aligned_prefix_length(left, right)
    rows = []
    for i, ins in enumerate(left):
        if ins.mnemonic != 'jmp' or len(ins.operands) != 1 or ins.operands[0].type != X86_OP_MEM:
            continue
        mem = ins.operands[0].mem
        if mem.base or mem.segment or not mem.index or mem.scale != 4:
            continue
        row = dict(kind='selector_table', offset=ins.address - va)
        selector = bound = selector_index = None
        for j in range(max(0, i - 8), i):
            earlier = left[j]
            if earlier.mnemonic != 'cmp' or len(earlier.operands) != 2 or \
                    earlier.operands[0].type != X86_OP_REG or earlier.operands[1].type != X86_OP_IMM \
                    or not 0 <= earlier.operands[1].imm < 4096:
                continue
            if j + 1 >= i or left[j + 1].mnemonic != 'ja':
                continue
            # The guarded register must be the base of the byte load that indexes the pointer table.
            for k in range(j + 2, i):
                candidate = left[k]
                if candidate.mnemonic == 'mov' and len(candidate.operands) == 2 and \
                        candidate.operands[0].type == X86_OP_REG and candidate.operands[1].type == X86_OP_MEM \
                        and candidate.operands[1].size == 1 and candidate.operands[1].mem.disp >= 0x1000 \
                        and candidate.operands[1].mem.base == earlier.operands[0].reg:
                    selector, selector_index = candidate.operands[1].mem.disp, k
                    bound = earlier.operands[1].imm + 1
        if selector is None or selector_index is None or bound is None:
            rows.append(dict(row, result='unknown', reason='no selector byte table with an unsigned bound'))
            continue
        if selector_index is None or selector_index >= len(right):
            rows.append(dict(row, result='unknown', reason='no matching selector load in the rebuilt window'))
            continue
        mirror = right[selector_index]
        if len(mirror.operands) != 2 or mirror.operands[0].type != X86_OP_REG or \
                mirror.operands[1].type != X86_OP_MEM or mirror.operands[1].size != 1:
            rows.append(dict(row, result='unknown', reason='rebuilt selector load has another shape'))
            continue
        if len(right[i].operands) != 1 or right[i].operands[0].type != X86_OP_MEM:
            rows.append(dict(row, result='unknown', reason='rebuilt indexed jump has another shape'))
            continue
        actual = right[selector_index].operands[1].mem.disp
        table, rebuilt_table = mem.disp & 0xffffffff, right[i].operands[0].mem.disp & 0xffffffff
        try:
            old_bytes = read_storage(original, selector, bound)
            new_bytes = read_storage(rebuilt, actual, bound)
            old_pointers = read_storage(original, table, (max(old_bytes) + 1 if old_bytes else 0) * 4)
            new_pointers = read_storage(rebuilt, rebuilt_table, (max(new_bytes) + 1 if new_bytes else 0) * 4)
        except ValueError as error:
            rows.append(dict(row, result='unknown', reason=str(error)))
            continue
        for n in range(bound):
            old_index, new_index = old_bytes[n], new_bytes[n]
            old = int.from_bytes(old_pointers[old_index * 4:old_index * 4 + 4], 'little')
            new = int.from_bytes(new_pointers[new_index * 4:new_index * 4 + 4], 'little')
            expected = address + old - va if va <= old < va + size else functions.get(old, (None, None))[1]
            comparable = va <= old < va + prefix and address <= new < address + prefix
            result = 'unknown' if expected is None or not comparable or expected != new else 'pass'
            reason = ('handler outside the equal-shape region' if not comparable else
                      'handler layout differs; semantic identity is not established' if expected != new else
                      'unsigned bound and byte selector table; handler offsets agree per state' if old_index == new_index else
                      'selector byte differs but resolves to the same handler')
            rows.append(dict(row, index=n, result=result, original_table=f'{table:08X}',
                             rebuilt_table=f'{rebuilt_table:08X}', original_target=f'{old:08X}',
                             rebuilt_target=f'{new:08X}', expected=None if expected is None else f'{expected:08X}',
                             original_selector=f'{old_index:02X}', rebuilt_selector=f'{new_index:02X}',
                             reason=reason))
    return rows


def check_code(original, rebuilt, va, address, size, functions, owners):
    a, b = decode(original, va, size), decode(rebuilt, address, size)
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    left = list(decoder.disasm(read_storage(original, va, size), va))
    right = list(decoder.disasm(read_storage(rebuilt, address, size), address))
    if a is None or b is None or a[0] != b[0] or [(o, k) for o, k, _ in a[1]] != [(o, k) for o, k, _ in b[1]]:
        # A span that also holds emitted tables cannot decode to an exact instruction sum.
        # The dispatch tables stay the most behaviour-dense data in that span, so compare them.
        return [dict(kind='code_window', result='unknown', reason='instruction windows do not align')] \
            + check_selector_tables(original, rebuilt, left, right, va, address, size, functions)
    rows = []
    references = compare_code_references(original, rebuilt, va, address, size, functions, owners)
    for ref in references['references']:
        rows.append(dict(ref, kind='reference_' + ref['kind']))
    rows.extend(check_switch_tables(original, rebuilt, left, right, va, address, size, functions))
    rows.extend(check_selector_tables(original, rebuilt, left, right, va, address, size, functions))
    for old, new in zip(left, right):
        for index, op in enumerate(old.operands):
            if op.type != X86_OP_MEM:
                continue
            other = new.operands[index]
            row = dict(kind='memory_operand', offset=old.address-va, instruction=old.mnemonic,
                       operand=index, size=op.size)
            if old.mnemonic == 'lea' or not op.access & CS_AC_READ:
                rows.append(dict(row, result='unknown', reason='address calculation or non-read operand'))
                continue
            if op.mem.base or op.mem.index or op.mem.segment or op.size <= 0:
                rows.append(dict(row, result='unknown', reason='runtime-dependent memory address'))
                continue
            target, actual = op.mem.disp & 0xffffffff, other.mem.disp & 0xffffffff
            if old.mnemonic not in FLOAT_READS:
                rows.append(dict(row, result='unknown', reason='operand value type is not independently established'))
                continue
            check = compare_literal(original, rebuilt, target, actual, op.size)
            if op.size in (4, 8) and 'original_hex' in check:
                fmt = '<f' if op.size == 4 else '<d'
                for side in ('original', 'rebuilt'):
                    check[side + '_value'] = repr(struct.unpack(fmt, bytes.fromhex(check[side + '_hex']))[0])
            rows.append(dict(row, original_target=f'{target:08X}', rebuilt_target=f'{actual:08X}',
                             **check))
    return rows or [dict(kind='code_window', result='unknown', reason='no supported dependencies in window')]


def audit(original, rebuilt, symbols, entries, emissions=None):
    functions = {va: (e['symbol'], symbols[e['symbol']]) for va, e in original_identities().items()
                 if e['symbol'] and e['symbol'] in symbols}
    owners = []
    for e in entries:
        if not e.get('evidence') or not isinstance(e.get('size'), int) or e['size'] <= 0:
            raise ValueError('Reviewed owner needs evidence and a positive size')
        if e['symbol'] in symbols:
            owners.append(dict(original=int(e['original_va'], 16), rebuilt=symbols[e['symbol']],
                               size=e['size'], name=e['symbol']))
    rows = []
    for item in load_functions():
        va, size = int(item['va'], 16), int(item['size_bytes'])
        context = dict(function=item['va'], name=item['name'])
        if va not in functions:
            rows.append(dict(context, kind='code_window', result='unknown', reason='no independent symbol pair'))
            continue
        name, address = functions[va]
        context.update(symbol=name, rebuilt_va=f'{address:08X}')
        if emissions is not None:
            proof = emissions.verify(name)
            context.update(emission_result=proof['result'], emitted_size=proof.get('size'),
                           emission_reason=proof.get('reason'),
                           unresolved_emission_relocations=proof.get('unresolved_relocations'))
            if proof['result'] not in ('proved_emitted_span', 'bounded_emitted_span') or size > proof['size']:
                rows.append(dict(context, kind='code_window', result='unknown',
                                 reason='code window lacks a verified containing emission'))
                continue
        try:
            checks = check_code(original, rebuilt, va, address, size, functions, owners)
        except ValueError as error:
            checks = [dict(kind='code_window', result='unknown', reason=str(error))]
        rows.extend(dict(context, **check) for check in checks)
    for e in entries:
        if e['symbol'] not in symbols:
            rows.append(dict(kind='initial_storage', owner=e['symbol'], result='unknown', reason='no unique linked owner'))
        else:
            checks = check_initial_storage(original, rebuilt, e, symbols[e['symbol']], functions, owners)
            rows.extend(dict(check, original_va=e['original_va'], rebuilt_va=f"{symbols[e['symbol']]:08X}") for check in checks)
    reviewed = {e['symbol'] for e in entries}
    for name in sorted(symbols):
        if name.startswith('??_7') and name not in reviewed:
            rows.append(dict(kind='vtable', owner=name, rebuilt_va=f'{symbols[name]:08X}', result='unknown',
                             reason='virtual table has no reviewed original bounds and pointer layout'))
    return rows


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--build', required=True, type=Path, help='Successful build with recorded EXE and map hashes')
    p.add_argument('--output', required=True, type=Path, help='New directory under build/')
    args = p.parse_args()
    output, build = args.output.resolve(), args.build.resolve()
    if not output.is_relative_to(REPO_ROOT / 'build') or output.exists():
        p.error('Output must be a new directory under build/')
    report = json.loads((build / 'report.json').read_text())
    if not report.get('linked'):
        raise ValueError('Build did not link')
    for name in ('empiresx.exe', 'empiresx.map'):
        if digest(build / name) != report.get('artifact_sha256', {}).get(name):
            raise ValueError(f'Missing or changed build artifact hash: {name}')
    config = json.loads((REPO_ROOT / 'config/executable.json').read_text())
    original_path = REPO_ROOT / config['original']
    if digest(original_path) != config['original_sha256']:
        raise ValueError('Original EXE hash differs')
    # Historical builds are intentional. No current registry or source recipe selects symbols.
    symbols = unique_addresses(parse_symbols((build / 'empiresx.map').read_text(errors='replace')))
    owner_path = REPO_ROOT / 'config/linked_reference_owners.json'
    original, rebuilt = pefile.PE(str(original_path)), pefile.PE(str(build / 'empiresx.exe'))
    entries = load_reviewed_storage(original)
    emissions = LinkedEmissions(build, report, rebuilt)
    rows = audit(original, rebuilt, symbols, entries, emissions)
    summary = dict(schema=1, build=str(build), original_sha256=digest(original_path),
                   rebuilt_sha256=digest(build / 'empiresx.exe'), map_sha256=digest(build / 'empiresx.map'),
                   build_report_sha256=digest(build / 'report.json'), owners_sha256=digest(owner_path),
                   strings_evidence_sha256=digest(STRING_EVIDENCE),
                   identity_fingerprint=validation_fingerprint(),
                   tool_sha256=digest(Path(__file__)),
                   checker_sha256={name: digest(REPO_ROOT / 'tools' / name) for name in (
                       'audit_image_dependencies.py', 'audit_linked_references.py', 'audit_global_initializers.py',
                       'linked_emissions.py', 'reviewed_storage.py', 'dependency_values.py', 'diff_linked_image.py')},
                   object_hashes=emissions.hashes,
                   emitted_spans=dict(Counter(r['result'] for r in emissions.cache.values())),
                   counts=dict(Counter(r['result'] for r in rows)),
                   by_kind={kind: dict(Counter(r['result'] for r in rows if r['kind'] == kind))
                            for kind in sorted({r['kind'] for r in rows})},
                   reviewed_storage_owner_count=len(entries),
                   failure_kinds=dict(Counter(r['kind'] for r in rows if r['result'] == 'fail')),
                   failing_functions=sorted({r['function'] for r in rows if r['result'] == 'fail' and 'function' in r}),
                   unknown_reasons=dict(Counter(r.get('reason', 'unproved reference identity') for r in rows if r['result'] == 'unknown')),
                   functions_considered=len(load_functions()),
                   scope='Static dependency checks, not whole-function equivalence or complete image ownership.',
                   limits=['Windows must fit a verified COFF emission; exact logical code ends can remain unknown.',
                           'Unaligned code, runtime field addresses, and inferred jump tables remain unknown.',
                           'Dispatch tables are compared only when the indexed jump and its guard resolve in both images.',
                           'Automatic literal checks cover x87 floating operands only; other types need review.',
                           'Read-only operand equality is value evidence, not storage identity or runtime immutability.',
                           'Reviewed globals compare startup bytes, not later runtime values.'])
    output.mkdir(parents=True)
    (output / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    (output / 'emissions.json').write_text(json.dumps(emissions.cache, indent=2) + '\n')
    write_csv(output / 'checks.csv', rows)
    write_csv(output / 'failures.csv', [r for r in rows if r['result'] == 'fail'])
    write_csv(output / 'tables.csv', [r for r in rows if r['kind'] in ('switch_table', 'selector_table', 'vtable')
                                     or r.get('owner', '').startswith('??_7')])
    (output / 'report.md').write_text('# Static dependency audit\n\n' + summary['scope'] + '\n\n'
                                     + '\n'.join(f'- {k}: {v}' for k, v in summary['counts'].items())
                                     + '\n\nSee `failures.csv` for actionable differences.\n\n'
                                     + '\n'.join('- ' + s for s in summary['limits']) + '\n')
    print(json.dumps({k: v for k, v in summary.items() if k != 'object_hashes'}, indent=2))
    return int(summary['counts'].get('fail', 0) > 0)


if __name__ == '__main__':
    raise SystemExit(main())
