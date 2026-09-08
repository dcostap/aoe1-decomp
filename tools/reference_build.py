"""Index a pinned older build and inspect named counterparts. Older code is reference evidence, not the target oracle."""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import re

import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL, CS_GRP_JUMP
from capstone.x86 import X86_OP_IMM, X86_OP_MEM

from common import REPO_ROOT, function_record_by_va, function_entry_for_va
from linker_map import parse_symbols
from reference_identity import original_identities
from function_diagnostics import clean_symbol_name


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def verify_pair(exe: Path, map_path: Path, spec: dict) -> tuple[object, str]:
    for key, path in [('exe', exe), ('map', map_path)]:
        if sha(path) != spec[key + '_sha256']:
            raise ValueError(f'{key} hash differs from the pinned reference')
    pe = pefile.PE(str(exe))
    text = map_path.read_text(errors='replace')
    stamp = re.search(r'Timestamp is ([0-9a-fA-F]+)', text)
    base = re.search(r'Preferred load address is ([0-9a-fA-F]+)', text)
    if not stamp or int(stamp[1], 16) != pe.FILE_HEADER.TimeDateStamp:
        raise ValueError('Reference map and PE timestamps differ')
    if not base or int(base[1], 16) != pe.OPTIONAL_HEADER.ImageBase:
        raise ValueError('Reference map and PE bases differ')
    return pe, text


def window(pe, row: dict, symbols: list[dict]) -> tuple[int, str]:
    """Next symbol bounds inspection only. It does not prove a function end."""
    va = row['address']
    for section in pe.sections:
        start = pe.OPTIONAL_HEADER.ImageBase + section.VirtualAddress
        end = start + section.Misc_VirtualSize
        if start <= va < end and section.Characteristics & 0x20000000:
            following = [r['address'] for r in symbols
                         if r['segment'] == row['segment'] and va < r['address'] <= end]
            bound = min(following) if following else end
            return bound - va, 'next symbol or executable section end; not a proved function boundary'
    raise ValueError('Selected reference symbol is not in executable storage')


def disassemble(pe, va: int, size: int, symbols: list[dict]) -> dict:
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    names = defaultdict(list)
    for row in symbols:
        names[row['address']].append(row['symbol'])
    relocated_fields = {pe.OPTIONAL_HEADER.ImageBase + item.rva
                        for block in getattr(pe, 'DIRECTORY_ENTRY_BASERELOC', [])
                        for item in block.entries if item.type == 3}
    code = pe.get_data(va - pe.OPTIONAL_HEADER.ImageBase, size)
    rows, calls, fields = [], [], Counter()
    for ins in decoder.disasm(code, va):
        row = dict(address=f'{ins.address:08X}', offset=ins.address-va,
                   bytes=ins.bytes.hex(), instruction=f'{ins.mnemonic} {ins.op_str}'.strip())
        if (ins.group(CS_GRP_CALL) or ins.group(CS_GRP_JUMP)) and ins.operands and ins.operands[0].type == X86_OP_IMM:
            target = ins.operands[0].imm & 0xffffffff
            row.update(target=f'{target:08X}', target_symbols=names.get(target, []))
            if ins.group(CS_GRP_CALL):
                calls.append(row)
        references = []
        for op in ins.operands:
            if op.type == X86_OP_MEM:
                mem = op.mem
                if mem.base or mem.index:
                    key = (ins.reg_name(mem.base), ins.reg_name(mem.index), mem.scale, mem.disp, op.size)
                    fields[key] += 1
                    if not mem.base and names.get(mem.disp & 0xffffffff):
                        references.append(dict(address=f'{mem.disp & 0xffffffff:08X}',
                                               symbols=names[mem.disp & 0xffffffff], indexed=True))
                else:
                    references.append(dict(address=f'{mem.disp & 0xffffffff:08X}',
                                           symbols=names.get(mem.disp & 0xffffffff, [])))
        if references:
            row['absolute_references'] = references
        if ins.imm_size == 4 and ins.address + ins.imm_offset in relocated_fields:
            value = int.from_bytes(ins.bytes[ins.imm_offset:ins.imm_offset+4], 'little')
            row['address_constant'] = dict(address=f'{value:08X}', symbols=names.get(value, []),
                                           evidence='PE HIGHLOW relocation')
        rows.append(row)
    return dict(instructions=rows, calls=calls,
                decoded_bytes=sum(len(bytes.fromhex(r['bytes'])) for r in rows),
                requested_bytes=size,
                memory_operands=[dict(base=k[0], index=k[1], scale=k[2], displacement=k[3], width=k[4], count=n)
                                 for k, n in fields.items()])


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='command', required=True)
    index = sub.add_parser('index', help='Verify and index the original reference files')
    index.add_argument('--root', type=Path, required=True, help='Older-build download root')
    index.add_argument('--build-id', default='january-1997')
    index.add_argument('--manifest', type=Path, default=REPO_ROOT / 'config/reference_builds.json')
    index.add_argument('--output', type=Path, required=True)
    query = sub.add_parser('query', help='Inspect one counterpart or search names')
    query.add_argument('--index', type=Path, required=True)
    choice = query.add_mutually_exclusive_group(required=True)
    choice.add_argument('--va', help='Current target VA; registry-only identities remain search hypotheses')
    choice.add_argument('--symbol', help='Exact decorated name')
    choice.add_argument('--query', help='Case-insensitive symbol or object-owner substring')
    query.add_argument('--owner', help='Exact map object owner; use it to resolve duplicate names')
    query.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if not args.output.resolve().is_relative_to(REPO_ROOT / 'build'):
        parser.error('Output must be under build/')
    if args.output.suffix.lower() != '.json':
        parser.error('Output must use a .json suffix; the text report uses .txt')
    if args.command == 'query' and args.output.resolve() == args.index.resolve():
        parser.error('Query output must not replace its index')
    if args.command == 'index':
        spec = json.loads(args.manifest.read_text())['builds'][args.build_id]
        exe, map_path = tuple((args.root / spec[k]).resolve() for k in ('exe', 'map'))
        pe, text = verify_pair(exe, map_path, spec)
        report = dict(schema=1, build_id=args.build_id, spec=spec, exe=str(exe), map=str(map_path),
                      manifest=str(args.manifest.resolve()), manifest_sha256=sha(args.manifest), symbols=parse_symbols(text))
        known = {e['symbol'] for e in original_identities().values() if e['symbol']}
        report['summary'] = dict(symbol_rows=len(report['symbols']),
                                shared_original_symbols=len(known & {r['symbol'] for r in report['symbols']}))
    else:
        data = json.loads(args.index.read_text())
        manifest = Path(data['manifest'])
        if sha(manifest) != data['manifest_sha256']:
            raise ValueError('Reference manifest changed; rebuild the index')
        spec = json.loads(manifest.read_text())['builds'][data['build_id']]
        if spec != data['spec']:
            raise ValueError('Cached reference specification differs from the manifest')
        pe, text = verify_pair(Path(data['exe']), Path(data['map']), spec)
        # Parse the pinned map again. An edited cache must not invent symbols.
        symbols = parse_symbols(text)
        symbol, target, search = args.symbol, None, args.query
        if args.va:
            va = int(args.va, 16)
            evidence = original_identities().get(va)
            if not evidence or not evidence['symbol']:
                entry = function_entry_for_va(va) or {}
                if not entry.get('symbol'):
                    search = function_record_by_va(va)['name']
                    evidence = dict(symbol=None, basis='inventory display-name search hypothesis; not original identity proof')
                else:
                    evidence = dict(symbol=entry['symbol'], basis='current registry search hypothesis; not original identity proof')
            symbol = evidence['symbol']
            target = dict(va=f'{va:08X}', identity=evidence)
        matches = [r for r in symbols if (r['symbol'] == symbol if symbol else
                   search.casefold() in (r['symbol'] + ' ' + r['owner']).casefold())]
        if args.owner:
            matches = [r for r in matches if r['owner'].casefold() == args.owner.casefold()]
        report = dict(schema=1, build_id=data['build_id'], index_sha256=sha(args.index),
                      reference_hashes={k: data['spec'][k] for k in ('exe_sha256', 'map_sha256')},
                      scope='Reference evidence only. Shared names do not prove shared behavior, layouts, or boundaries.',
                      target=target, candidates=matches)
        if symbol and not matches:
            report['signature_candidates'] = [dict(r, reason='same short name only; owner or signature can differ')
                for r in symbols if r['function'] and clean_symbol_name(r['symbol']) == clean_symbol_name(symbol)]
        unique = {(r['address'], r['symbol']) for r in matches if r['function']}
        if symbol and len(unique) == 1:
            row = next(r for r in matches if r['function'])
            size, boundary = window(pe, row, symbols)
            report['reference'] = dict(symbol=row, boundary=boundary,
                                       **disassemble(pe, row['address'], size, symbols))
        if target:
            spec = json.loads((REPO_ROOT / 'config/executable.json').read_text())
            original = REPO_ROOT / spec['original']
            if sha(original) != spec['original_sha256']:
                raise ValueError('Target EXE hash differs from the oracle')
            record = function_record_by_va(int(target['va'], 16))
            target_symbols = [dict(address=va, symbol=e['symbol']) for va, e in original_identities().items() if e['symbol']]
            report['target_code'] = disassemble(pefile.PE(str(original)), int(target['va'], 16),
                                                int(record['size_bytes']), target_symbols)
            report['target_sha256'] = sha(original)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    lines = [report.get('scope', 'Hash-checked reference index'), json.dumps(report.get('summary', {}))]
    for row in report.get('candidates', []):
        lines.append(f"{row['address']:08X} {row['symbol']} {row['owner']}")
    for row in report.get('signature_candidates', []):
        lines.append(f"HYPOTHESIS {row['address']:08X} {row['symbol']} {row['owner']}")
    for key in ('reference', 'target_code'):
        if key in report:
            lines.extend(['', key + ':'])
            for row in report[key]['instructions']:
                names = list(row.get('target_symbols', []))
                names.extend(row.get('address_constant', {}).get('symbols', []))
                for reference in row.get('absolute_references', []):
                    names.extend(reference['symbols'])
                labels = ', '.join(dict.fromkeys(names))
                lines.append(f"{row['address']} {row['instruction']}" + (f' ; {labels}' if labels else ''))
    args.output.with_suffix('.txt').write_text('\n'.join(lines) + '\n')
    print(f'Report: {args.output}')
    print(json.dumps(report.get('summary', {'candidates': len(report.get('candidates', []))})))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
