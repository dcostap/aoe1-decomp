"""Compare linked initial storage with the original EXE; never change game source."""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import re
import subprocess

import pefile
from linked_inputs import verify_build

ROOT = Path(__file__).resolve().parents[1]
ORIGINAL = ROOT / 'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe'
PRIMITIVES = {'T_RCHAR': 1, 'T_CHAR': 1, 'T_UCHAR': 1, 'T_SHORT': 2,
              'T_USHORT': 2, 'T_LONG': 4, 'T_ULONG': 4, 'T_INT4': 4,
              'T_UINT4': 4, 'T_REAL32': 4, 'T_REAL64': 8, 'T_QUAD': 8,
              'T_UQUAD': 8, 'T_BOOL08': 1}


def read_storage(pe, va, size):
    rva = va - pe.OPTIONAL_HEADER.ImageBase
    for section in pe.sections:
        offset = rva - section.VirtualAddress
        extent = max(section.Misc_VirtualSize, section.SizeOfRawData)
        if 0 <= offset and offset + size <= extent:
            stored = max(0, min(size, section.SizeOfRawData - offset))
            raw = pe.get_data(rva, stored) if stored else b''
            if len(raw) != stored:
                raise ValueError('Truncated stored data')
            return raw + bytes(size - stored)
    raise ValueError('Range outside one PE section')


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--build', required=True, type=Path, help='Build directory containing EXE and linker map')
    p.add_argument('--cvdump', required=True, type=Path)
    p.add_argument('--output', required=True, type=Path, help='JSON report under build/')
    args = p.parse_args()
    if not args.output.resolve().is_relative_to(ROOT / 'build'):
        p.error('Output must be under build/')
    verify_build(args.build)
    original = pefile.PE(str(ORIGINAL))
    exe = args.build / 'empiresx.exe'
    rebuilt = pefile.PE(str(exe))
    def dump(flag):
        return subprocess.check_output([str(args.cvdump), flag, str(ROOT / 'orig/age1_x1.pdb')]).decode('utf-8', 'replace')
    globals_text, types_text = dump('-g'), dump('-t')
    records = {}
    for m in re.finditer(r'^0x([0-9A-Fa-f]+) : (.*?)(?=^0x|\Z)', types_text, re.M | re.S):
        records[int(m[1], 16)] = m[2]
    def classify(display, depth=0):
        if depth > 10:
            return 0, 'unknown'
        token = display.strip().split('(')[0]
        if token in PRIMITIVES:
            return PRIMITIVES[token], 'plain'
        if token.startswith('T_32P'):
            return 4, 'pointer'
        if not token.startswith('0x'):
            return 0, 'unknown'
        record = records.get(int(token, 16), '')
        if 'LF_POINTER' in record.split('\n')[0]:
            return 4, 'pointer'
        size = re.search(r'(?:\bSize|\blength) = (?:\(LF_\w+\) )?(\d+)', record)
        if 'LF_ARRAY' in record.split('\n')[0] and size:
            element = re.search(r'Element type = ([^\r\n,]+)', record)
            kind = classify(element[1], depth + 1)[1] if element else 'unknown'
            return int(size[1]), kind
        return int(size[1]) if size else 0, 'constructed_or_unknown'
    linked = defaultdict(list)
    for line in (args.build / 'empiresx.map').read_text(errors='replace').splitlines():
        m = re.match(r'\s+[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+(.*)', line)
        if not m or m[3].startswith('f '):
            continue
        symbol = m[1]
        name = re.match(r'^\?([^@]+)@@3', symbol)
        name = name[1] if name else symbol.removeprefix('_')
        linked[name].append((int(m[2], 16), symbol, m[3].strip()))
    relocations = []
    for pe in (original, rebuilt):
        relocations.append({pe.OPTIONAL_HEADER.ImageBase + e.rva
                            for block in getattr(pe, 'DIRECTORY_ENTRY_BASERELOC', [])
                            for e in block.entries if e.type})
    rows = []
    pattern = r'^S_GDATA32: \[([0-9A-F]+):([0-9A-F]+)\], Type:\s+(.+?), (.+)$'
    for m in re.finditer(pattern, globals_text, re.M):
        section, offset, display, name = m.groups()
        name = name.strip()
        if not 1 <= int(section, 16) <= len(original.sections):
            rows.append(dict(name=name, type=display.strip(), result='invalid_original_section'))
            continue
        va = original.OPTIONAL_HEADER.ImageBase + original.sections[int(section, 16)-1].VirtualAddress + int(offset, 16)
        size, kind = classify(display)
        row = dict(name=name, original_va=f'{va:08X}', type=display.strip(), size=size, kind=kind)
        candidates = linked.get(name, [])
        if len(candidates) != 1:
            row['result'] = 'unmapped' if not candidates else 'ambiguous'
        elif not size or kind != 'plain':
            row['result'] = 'needs_type_or_startup_review'
        else:
            target, symbol, owner = candidates[0]
            row.update(rebuilt_va=f'{target:08X}', symbol=symbol, owner=owner)
            if any(va <= r < va + size for r in relocations[0]) or any(target <= r < target + size for r in relocations[1]):
                row['result'] = 'needs_pointer_review'
            else:
                try:
                    a, b = read_storage(original, va, size), read_storage(rebuilt, target, size)
                    row.update(result='equal_initial_bytes' if a == b else 'different_initial_bytes',
                               original_hex=a[:64].hex(), rebuilt_hex=b[:64].hex(),
                               differing_bytes=sum(x != y for x, y in zip(a, b)),
                               differences=[dict(offset=i, original=x, rebuilt=y)
                                            for i, (x, y) in enumerate(zip(a, b)) if x != y][:64])
                except ValueError as error:
                    row.update(result='invalid_range', error=str(error))
        rows.append(row)
    report = dict(schema=1, original=str(ORIGINAL), rebuilt=str(exe),
                  original_sha256=hashlib.sha256(ORIGINAL.read_bytes()).hexdigest(),
                  rebuilt_sha256=hashlib.sha256(exe.read_bytes()).hexdigest(),
                  scope='PDB S_GDATA32 names; plain scalar and primitive-array initial storage only. Sizes come from original PDB; rebuilt layout needs review. No startup execution proof.',
                  counts=dict(Counter(r['result'] for r in rows)), rows=rows)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['counts'], indent=2))
    for row in rows:
        if row['result'] == 'different_initial_bytes':
            print(row['name'], row['original_va'], row['original_hex'], '->', row['rebuilt_hex'])
    return 1 if report['counts'].get('different_initial_bytes') else 0


if __name__ == '__main__':
    raise SystemExit(main())
