"""Compare complete PE files and independently mapped code and storage windows.

Raw coverage is complete. Semantic coverage is partial and never inferred from
byte similarity. Original-size code windows do not prove rebuilt boundaries.
"""
from __future__ import annotations

import argparse
from collections import Counter
import csv
import json
from pathlib import Path

import pefile
from audit_linked_references import check_initial_storage, classify, decode
from audit_global_initializers import read_storage
from common import REPO_ROOT, load_functions
from linked_inputs import digest, verify_build
from linker_map import parse_symbols, unique_addresses
from reference_identity import original_identities


def difference_ranges(a, b):
    """Partition both file lengths by positional equality, including unmatched tails."""
    start, previous = 0, None
    for i in range(max(len(a), len(b))):
        state = ('rebuilt_only' if i >= len(a) else 'original_only' if i >= len(b)
                 else 'equal' if a[i] == b[i] else 'different')
        if previous is not None and state != previous:
            yield dict(offset=start, size=i-start, result=previous)
            start = i
        previous = state
    if previous is not None:
        yield dict(offset=start, size=max(len(a), len(b))-start, result=previous)


def regions(pe, length):
    rows = [(0, min(length, pe.OPTIONAL_HEADER.SizeOfHeaders), 'PE headers')]
    for s in pe.sections:
        start = s.PointerToRawData
        end = min(length, start + s.SizeOfRawData)
        if s.SizeOfRawData and start < end:
            rows.append((start, end, s.Name.rstrip(b'\0').decode('ascii', 'replace')))
    return rows


def region_at(offset, rows, length):
    if offset >= length:
        return 'absent'
    names = [name for start, end, name in rows if start <= offset < end]
    return names[0] if len(names) == 1 else 'unknown' if not names else 'overlapping regions'


def raw_ranges(a, b, original, rebuilt):
    left, right = regions(original, len(a)), regions(rebuilt, len(b))
    boundaries = sorted({n for rows in (left, right) for start, end, _ in rows for n in (start, end)})
    for row in difference_ranges(a, b):
        start, end = row['offset'], row['offset'] + row['size']
        cuts = [start] + [n for n in boundaries if start < n < end] + [end]
        for lo, hi in zip(cuts, cuts[1:]):
            yield dict(offset=lo, size=hi-lo, result=row['result'],
                       original_region=region_at(lo, left, len(a)),
                       rebuilt_region=region_at(lo, right, len(b)),
                       original_hex_preview=a[lo:min(hi, lo+16)].hex(),
                       rebuilt_hex_preview=b[lo:min(hi, lo+16)].hex(),
                       interpretation='positional only; semantic ownership unknown')


def structure(pe):
    optional = pe.OPTIONAL_HEADER
    fields = ['ImageBase', 'AddressOfEntryPoint', 'SizeOfImage', 'SizeOfHeaders',
              'SectionAlignment', 'FileAlignment', 'Subsystem', 'CheckSum',
              'SizeOfStackReserve', 'SizeOfStackCommit', 'DllCharacteristics']
    result = {key: getattr(optional, key) for key in fields}
    result.update(timestamp=pe.FILE_HEADER.TimeDateStamp,
                  machine=pe.FILE_HEADER.Machine, characteristics=pe.FILE_HEADER.Characteristics)
    result['directories'] = [dict(name=d.name, rva=d.VirtualAddress, size=d.Size)
                             for d in optional.DATA_DIRECTORY]
    result['sections'] = [dict(name=s.Name.rstrip(b'\0').decode('ascii', 'replace'),
                              rva=s.VirtualAddress, virtual_size=s.Misc_VirtualSize,
                              file_offset=s.PointerToRawData, raw_size=s.SizeOfRawData,
                              characteristics=s.Characteristics) for s in pe.sections]
    result['imports'] = sorted((entry.dll.decode('ascii', 'replace').lower(),
                               item.name.decode('ascii', 'replace') if item.name else f'ordinal:{item.ordinal}')
                              for entry in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []) for item in entry.imports)
    result['exports'] = [dict(name=e.name.decode('ascii', 'replace') if e.name else None,
                              ordinal=e.ordinal, rva=e.address,
                              forwarder=e.forwarder.decode('ascii', 'replace') if e.forwarder else None)
                         for e in getattr(getattr(pe, 'DIRECTORY_ENTRY_EXPORT', None), 'symbols', [])]
    result['resources'] = []
    def visit(directory, path):
        for entry in directory.entries:
            key = str(entry.name) if entry.name is not None else entry.id
            if hasattr(entry, 'directory'):
                visit(entry.directory, path + [key])
            elif hasattr(entry, 'data'):
                import hashlib
                data = entry.data.struct
                payload = pe.get_data(data.OffsetToData, data.Size)
                if len(payload) != data.Size:
                    raise ValueError('Truncated resource')
                result['resources'].append(dict(path=path + [key], size=data.Size,
                                                codepage=data.CodePage,
                                                sha256=hashlib.sha256(payload).hexdigest()))
    if hasattr(pe, 'DIRECTORY_ENTRY_RESOURCE'):
        visit(pe.DIRECTORY_ENTRY_RESOURCE, [])
    return result


def compare_code_references(original, rebuilt, va, address, size, functions, owners):
    """Resolve fields only when the complete decoded windows align."""
    a, b = decode(original, va, size), decode(rebuilt, address, size)
    if a is None or b is None or a[0] != b[0] or [(o, k) for o, k, _ in a[1]] != [(o, k) for o, k, _ in b[1]]:
        return dict(normalized_result='unknown', references=[],
                    normalization_reason='instruction windows do not align')
    references = []
    for (offset, kind, target), (_, _, actual) in zip(a[1], b[1]):
        detail = {}
        if target in functions:
            symbol, expected = functions[target]
            result = 'pass' if actual == expected else 'fail'
            detail = dict(owner=symbol, expected=f'{expected:08X}')
        else:
            result, resolved = classify(target, actual, owners)
            detail = resolved or dict(reason='no unique reviewed target owner')
        references.append(dict(offset=offset, kind=kind, original_target=f'{target:08X}',
                               rebuilt_target=f'{actual:08X}', result=result, **detail))
    state = ('changed_target' if any(r['result'] == 'fail' for r in references) else
             'unknown' if any(r['result'] == 'unknown' for r in references) else 'equal_supported_window')
    return dict(normalized_result=state, references=references,
                normalization_reason='supported fields only; boundaries and unrecognized address operands remain unproved')


def semantic_windows(original, rebuilt, symbols, entries):
    identities = original_identities()
    functions = {va: (e['symbol'], symbols[e['symbol']]) for va, e in identities.items()
                 if e['symbol'] in symbols}
    owners = []
    for entry in entries:
        if not entry.get('evidence') or not isinstance(entry.get('size'), int) or entry['size'] <= 0:
            raise ValueError('Storage owner needs evidence and a positive size')
        if entry['symbol'] in symbols:
            owners.append(dict(original=int(entry['original_va'], 16), rebuilt=symbols[entry['symbol']],
                               size=entry['size'], name=entry['symbol']))
    data = []
    for entry in entries:
        if entry['symbol'] not in symbols:
            data.append(dict(owner=entry['symbol'], result='unknown', reason='missing or ambiguous linked symbol'))
        else:
            checks = check_initial_storage(original, rebuilt, entry, symbols[entry['symbol']], functions, owners)
            data.extend(dict(r, original_va=entry['original_va'],
                             rebuilt_va=f"{symbols[entry['symbol']]:08X}", size=entry['size']) for r in checks)
    code = []
    for item in load_functions():
        va = int(item['va'], 16)
        row = dict(original_va=item['va'], name=item['name'], size=int(item['size_bytes']))
        if va not in functions:
            code.append(dict(row, result='unknown', reason='no independent symbol pair'))
            continue
        name, address = functions[va]
        row.update(symbol=name, rebuilt_va=f'{address:08X}')
        try:
            a = read_storage(original, va, row['size'])
            b = read_storage(rebuilt, address, row['size'])
            diffs = [r for r in difference_ranges(a, b) if r['result'] != 'equal']
            row.update(result='equal_window' if a == b else 'different_window',
                       differing_bytes=sum(r['size'] for r in diffs), differences=diffs,
                       reason='original-size window only; rebuilt boundary and address fields not proved')
            row.update(compare_code_references(original, rebuilt, va, address, row['size'], functions, owners))
        except ValueError as error:
            row.update(result='unknown', reason=str(error))
        code.append(row)
    return code, data


def write_csv(path, rows):
    fields = list(dict.fromkeys(key for row in rows for key in row))
    with path.open('w', newline='', encoding='utf-8') as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        for row in rows:
            writer.writerow({k: json.dumps(v) if isinstance(v, (list, dict)) else v for k, v in row.items()})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', required=True, type=Path, help='Hash-recorded executable build directory')
    parser.add_argument('--output', required=True, type=Path, help='New report directory under build/')
    parser.add_argument('--structural-only', action='store_true',
                        help='Compare historical images without current registry or semantic claims')
    args = parser.parse_args()
    output = args.output.resolve()
    if not output.is_relative_to(REPO_ROOT / 'build') or output.exists():
        parser.error('Output must be a new directory under build/')
    build = args.build.resolve()
    report = json.loads((build / 'report.json').read_text())
    config = json.loads((REPO_ROOT / 'config/executable.json').read_text())
    original_path = REPO_ROOT / config['original']
    rebuilt_path = build / 'empiresx.exe'
    if not report.get('linked') or digest(rebuilt_path) != report.get('artifact_sha256', {}).get('empiresx.exe'):
        raise ValueError('Rebuilt EXE lacks a successful hash-checked build')
    if digest(original_path) != config['original_sha256']:
        raise ValueError('Original EXE hash differs')
    if not args.structural_only:
        verify_build(build)
    original, rebuilt = pefile.PE(str(original_path)), pefile.PE(str(rebuilt_path))
    a, b = original_path.read_bytes(), rebuilt_path.read_bytes()
    ranges = list(raw_ranges(a, b, original, rebuilt))
    structures = [structure(pe) for pe in (original, rebuilt)]
    code, data = [], []
    owners_path = REPO_ROOT / 'config/linked_reference_owners.json'
    if not args.structural_only:
        symbols = unique_addresses(parse_symbols((build / 'empiresx.map').read_text(errors='replace')))
        code, data = semantic_windows(original, rebuilt, symbols, json.loads(owners_path.read_text())['owners'])
    counts = Counter()
    for row in ranges:
        counts[row['result']] += row['size']
    summary = dict(schema=1, original=str(original_path), rebuilt=str(rebuilt_path),
                   original_sha256=digest(original_path), rebuilt_sha256=digest(rebuilt_path),
                   tool_sha256=digest(Path(__file__)),
                   build_report_sha256=digest(build / 'report.json'), structural_only=args.structural_only,
                   original_size=len(a), rebuilt_size=len(b), positional_bytes=dict(counts),
                   structure_equal_fields={k: structures[0][k] == structures[1][k] for k in structures[0]},
                   function_windows=dict(Counter(r['result'] for r in code)),
                   normalized_windows=dict(Counter(r.get('normalized_result', 'unknown') for r in code)),
                   reviewed_storage=dict(Counter(r['result'] for r in data)),
                   scope='Complete positional file coverage. Partial reviewed storage checks. Code windows are not function equivalence.',
                   limits=['No complete semantic byte ownership.', 'No inferred jump tables, padding, or constants.',
                           'Code normalization covers only aligned supported reference fields, not rebuilt boundary proof.',
                           'Raw file coverage excludes virtual zero-fill. Storage checks can include virtual zero-fill.'])
    if not args.structural_only:
        summary.update(map_sha256=digest(build / 'empiresx.map'), owners_sha256=digest(owners_path),
                       registry_sha256=report['registry_sha256'],
                       function_inventory_sha256=digest(REPO_ROOT / 'inventory/all_functions.csv'))
    output.mkdir(parents=True)
    for filename, value in [('summary.json', summary), ('structure.json', dict(original=structures[0], rebuilt=structures[1]))]:
        (output / filename).write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')
    write_csv(output / 'ranges.csv', ranges)
    write_csv(output / 'functions.csv', code)
    write_csv(output / 'data.csv', data)
    # Raw ranges have structural labels, not proved semantic owners.
    write_csv(output / 'unknown_ranges.csv', [r for r in ranges if r['result'] != 'equal'])
    (output / 'report.md').write_text(
        '# Linked image comparison\n\n' + summary['scope'] + '\n\n'
        + f"Original: {len(a):,} bytes. Rebuilt: {len(b):,} bytes.\n\n"
        + '\n'.join(f'- {key}: {value:,} bytes' for key, value in counts.items())
        + '\n\n## Comparisons\n\n'
        + f"Resource payloads equal: {summary['structure_equal_fields']['resources']}.\n\n"
        + f"Function windows: {json.dumps(summary['function_windows'])}.\n\n"
        + f"Supported normalized windows: {json.dumps(summary['normalized_windows'])}.\n\n"
        + f"Reviewed storage checks: {json.dumps(summary['reviewed_storage'])}.\n"
        + '\n## Limits\n\n' + '\n'.join('- ' + text for text in summary['limits']) + '\n', encoding='utf-8')
    print(json.dumps(summary, indent=2))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
