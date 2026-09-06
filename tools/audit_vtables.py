"""Report unresolved virtual slots and conflicting COFF vtable definitions.

Exact function relocations locate original tables. They do not prove table
bounds or class layouts. Each reported repair still needs binary review.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
from collections import Counter, defaultdict
from pathlib import Path

import pefile

from audit_link_symbols import decorated_name
from coff import function_symbol_section, load_coff_object
from common import REPO_ROOT, load_build_modules, load_pdb_function_source_map, repo_path
from extract_obj_function import select_exact_function_symbol


def table_definitions(obj):
    """Return vtable relocation slots, without assuming original table bounds."""
    for symbol in obj.symbols:
        if not symbol.name.startswith('??_7') or symbol.section_number <= 0:
            continue
        section = obj.section_by_index(symbol.section_number)
        following = [s.value for s in obj.symbols
                     if s.section_number == symbol.section_number
                     and s.storage_class == 2 and s.value > symbol.value]
        end = min(following, default=len(section.data))
        slots = [(r.offset - symbol.value, r.symbol_name,
                  struct.unpack_from('<I', section.data, r.offset)[0]) for r in section.relocations
                 if symbol.value <= r.offset < end and r.reloc_type == 6 and r.width == 4]
        yield symbol.name, slots


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build-report', required=True)
    parser.add_argument('--function-audit', required=True)
    parser.add_argument('--output', required=True)
    args = parser.parse_args()
    output = repo_path(args.output).resolve()
    if not output.is_relative_to((REPO_ROOT / 'build').resolve()):
        parser.error('Output must be under build/.')
    build_path, audit_path = repo_path(args.build_report), repo_path(args.function_audit)
    build = json.loads(build_path.read_text())
    audit = json.loads(audit_path.read_text())
    original = repo_path(build['config']['original'])
    if hashlib.sha256(original.read_bytes()).hexdigest() != build['original_sha256']:
        raise ValueError('Original EXE differs from the recorded build input.')
    pe = pefile.PE(str(original))
    image_base = pe.OPTIONAL_HEADER.ImageBase
    sources = {row['source'].casefold(): row for row in build['sources'] if row['compiled']}
    missing = {decorated_name(name) for name in build['link']['unresolved']}
    pdb = load_pdb_function_source_map()
    registry = {va: entry.get('symbol', '') for module in load_build_modules()
                for va, entry in module['functions'].items()}
    addresses = defaultdict(set)
    anchors = defaultdict(list)
    skipped = []
    for group in audit['groups']:
        source = sources.get(group['source'].casefold())
        if (not source or group.get('compile_error')
                or source['inputs']['fingerprint'] != group['input_fingerprint']):
            skipped.append(group['group'])
            continue
        obj = load_coff_object(audit_path.parent / 'objects' / (group['group'] + '.obj'))
        for row in group['rows']:
            if (row['grouped_result'] != 'MATCH' or row['owner_status'] != 'match'
                    or row['relocation_target_mismatches'] or row['boundary_escape_count']):
                continue
            symbol = select_exact_function_symbol(obj, row['symbol'])
            section = function_symbol_section(obj, symbol)
            for relocation in section.relocations:
                if ((not relocation.symbol_name.startswith('??_7') and relocation.symbol_name not in missing)
                        or relocation.reloc_type != 6 or relocation.width != 4):
                    continue
                offset = int(row['va'], 16) - image_base + relocation.offset
                addend = struct.unpack_from('<I', section.data, relocation.offset)[0]
                address = (struct.unpack('<I', pe.get_data(offset, 4))[0] - addend) & 0xffffffff
                addresses[relocation.symbol_name].add(address)
                anchors[relocation.symbol_name].append(dict(group=group['group'], va=row['va'],
                                                             offset=relocation.offset))
    definitions = defaultdict(list)
    reference_counts = Counter()
    for source in sources.values():
        obj = load_coff_object(Path(source['object']))
        reference_counts.update(r.symbol_name for section in obj.sections for r in section.relocations)
        for name, slots in table_definitions(obj):
            definitions[name].append(dict(source=source['source'], slots=slots))
    conflicts = []
    rows = []
    for name, entries in sorted(definitions.items()):
        variants = defaultdict(list)
        for entry in entries:
            variants[tuple(entry['slots'])].append(entry['source'])
        if len(variants) > 1:
            conflicts.append(dict(symbol=name, variants=[dict(sources=s, slots=k)
                                                         for k, s in variants.items()]))
        if len(addresses[name]) != 1:
            continue
        address = next(iter(addresses[name]))
        for slots, owners in variants.items():
            for offset, target, addend in slots:
                if target not in missing or offset % 4:
                    continue
                original_va = struct.unpack('<I', pe.get_data(address - image_base + offset, 4))[0]
                va = f'{original_va:08X}'
                rows.append(dict(table=name, table_va=f'{address:08X}', slot_offset=offset,
                                 unresolved=target, target_addend=addend, sources=owners, original_target_va=va,
                                 original_target_name=pdb.get(va, {}).get('symbol_name', ''),
                                 original_target_symbol=registry.get(va, ''), anchors=anchors[name]))
    data = []
    for name, values in sorted(addresses.items()):
        if name not in missing or len(values) != 1:
            continue
        address = next(iter(values))
        section = pe.get_section_by_rva(address - image_base)
        available = section.SizeOfRawData - (address - image_base - section.VirtualAddress) if section else 0
        raw = pe.get_data(address - image_base, min(160, available)) if available > 0 else b''
        text = raw.split(b'\0', 1)[0]
        data.append(dict(symbol=name, original_va=f'{address:08X}', raw_prefix=raw[:16].hex(),
                         total_references=reference_counts[name], exact_references=len(anchors[name]),
                         section=section.Name.rstrip(b'\0').decode('ascii') if section else None,
                         has_nul=b'\0' in raw,
                         ascii_prefix=text.decode('ascii') if raw and all(32 <= c < 127 or c in (9, 10, 13) for c in text) else None,
                         anchors=anchors[name]))
    report = dict(schema=1, build_report=str(build_path), function_audit=str(audit_path),
                  skipped_groups=skipped, table_conflicts=conflicts, unresolved_slots=rows,
                  unresolved_data_references=data,
                  table_addresses={n: f'{next(iter(a)):08X}' for n, a in addresses.items() if n.startswith('??_7') and len(a) == 1},
                  address_conflicts={n: sorted(a) for n, a in addresses.items() if len(a) > 1},
                  summary=dict(defined_tables=len(definitions), located_tables=sum(n.startswith('??_7') and len(a) == 1 for n, a in addresses.items()),
                               conflicting_tables=len(conflicts), unresolved_slots=len(rows)))
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['summary'], indent=2))
    print(f'Report: {output}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
