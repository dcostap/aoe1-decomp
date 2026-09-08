"""Check natural header emissions and unresolved functions in verified build objects. Never emit wrappers or change the registry."""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path

from common import REPO_ROOT
from coff import load_coff_object
from function_compare import compare_object_function
from linker_map import parse_symbols, parse_folding
import pefile
from reference_identity import original_identities, validation_fingerprint
from linked_inputs import verify_build


def index_emissions(sources: list[dict]) -> tuple[dict, dict]:
    objects, emissions = {}, defaultdict(list)
    for row in sources:
        if not row.get('compiled'):
            continue
        path = Path(row['object'])
        obj = load_coff_object(path)
        objects[str(path)] = obj
        digest = hashlib.sha256(path.read_bytes()).hexdigest()
        for symbol in obj.symbols:
            if symbol.section_number > 0 and symbol.is_function:
                emissions[symbol.name].append(dict(source=row['source'], object=str(path),
                    object_sha256=digest, flags=row['flags'],
                    input_fingerprint=(row.get('inputs') or {}).get('fingerprint'),
                    section=symbol.section_number, offset=symbol.value))
    return objects, emissions


def selected_emission(candidates: list[dict], map_rows: list[dict], symbol: str,
                      *, folding: list[dict] = (), emissions: dict | None = None) -> dict:
    linked = [r for r in map_rows if r['symbol'] == symbol]
    identities = {(r['address'], r['owner']) for r in linked}
    if len(identities) != 1:
        return dict(result='unknown', reason='linked symbol absent or ambiguous', map_rows=linked)
    address, owner = next(iter(identities))
    replacements = [row for row in folding if row['symbol'] == symbol]
    if replacements:
        chain, seen = [], set()
        current, current_owner = symbol, None
        while True:
            edges = {tuple(row[key] for key in ('symbol', 'owner', 'selected_symbol', 'selected_owner'))
                     for row in folding if row['symbol'] == current}
            if not edges:
                break
            if len(edges) != 1 or current in seen:
                return dict(result='unknown', reason='ambiguous or cyclic folding evidence')
            edge = next(iter(edges))
            if current_owner is not None and current_owner != edge[1]:
                return dict(result='unknown', reason='folding chain changes object identity')
            seen.add(current)
            chain.append(dict(zip(('symbol', 'owner', 'selected_symbol', 'selected_owner'), edge)))
            current, current_owner = edge[2:]
        root_maps = {(r['address'], r['owner']) for r in map_rows if r['symbol'] == current}
        if root_maps != {(address, owner)} or current_owner != owner:
            return dict(result='unknown', reason='folding record disagrees with linked map', chain=chain)
        def owned(rows, object_name):
            return [r for r in rows if Path(r['object']).name.casefold() == object_name.casefold()]
        original = owned(candidates, chain[0]['owner'])
        physical = owned((emissions or {}).get(current, []), owner)
        if len(original) != 1 or len(physical) != 1:
            return dict(result='unknown', reason='folding record lacks a unique actual object emission', chain=chain)
        return dict(result='selected', selection_kind='folded', address=f'{address:08X}', owner=owner,
                    emission=original[0], physical_emission=physical[0], physical_symbol=current, chain=chain)
    # VC maps name the input object. Do not select by bytes or source proximity.
    matches = [r for r in candidates if Path(r['object']).name.casefold() == owner.replace('\\', '/').rsplit('/', 1)[-1].casefold()]
    if len(matches) != 1:
        return dict(result='unknown', reason='map owner does not select one build object', map_rows=linked)
    return dict(result='selected', address=f'{address:08X}', owner=owner, emission=matches[0])


def verified_folding(build_dir: Path, build: dict) -> list[dict]:
    expected = build.get('artifact_sha256', {}).get('link.log')
    if not expected:
        return []
    data = (build_dir / 'link.log').read_bytes()
    if hashlib.sha256(data).hexdigest() != expected:
        raise ValueError('Build artifact changed: link.log')
    return parse_folding(data.decode('utf-8'))


def verify_folded_bytes(selection: dict, objects: dict, pe, size: int) -> bool:
    """Limit folded proof to complete, relocation-free function bytes."""
    bodies = []
    for key in ('emission', 'physical_emission'):
        candidate = selection[key]
        section = objects[candidate['object']].section_by_index(candidate['section'])
        offset = candidate['offset']
        if section.relocations or offset + size > len(section.data):
            return False
        bodies.append(section.data[offset:offset + size])
    linked = pe.get_data(int(selection['address'], 16) - pe.OPTIONAL_HEADER.ImageBase, size)
    return len(linked) == size and bodies[0] == bodies[1] == linked


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True, help='Build directory with report, map, and compiled objects')
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if not args.output.resolve().is_relative_to(REPO_ROOT / 'build'):
        parser.error('Output must be under build/')
    build_path = args.build / 'report.json'
    build = verify_build(args.build, objects=True)
    map_path = args.build / 'empiresx.map'
    maps = parse_symbols(map_path.read_text(errors='replace'))
    folding = verified_folding(args.build, build)
    pe = pefile.PE(str(args.build / 'empiresx.exe'))
    objects, emissions = index_emissions(build['sources'])
    rows = []
    for path in sorted((REPO_ROOT / 'config/functions').rglob('*.json')):
        source = path.relative_to(REPO_ROOT / 'config/functions').as_posix().removesuffix('.json')
        for va, entry in json.loads(path.read_text())['functions'].items():
            if entry['status'] != 'unresolved' and not source.endswith(('.h', '.hpp')):
                continue
            identity = original_identities().get(int(va, 16))
            row = dict(va=va, source=source, identity=identity, emissions=[])
            if not identity or not identity['symbol']:
                row.update(result='unknown', reason='original linkage identity missing or conflicting')
            else:
                symbol = identity['symbol']
                for candidate in emissions.get(symbol, []):
                    item = dict(candidate)
                    try:
                        item['comparison'] = compare_object_function(
                            objects[candidate['object']], int(va, 16),
                            {'functions': {va: {'symbol': symbol}}}, symbol)
                    except (KeyError, ValueError, OSError, RuntimeError) as error:
                        item['error'] = str(error)
                    row['emissions'].append(item)
                row['linked_selection'] = selected_emission(emissions.get(symbol, []), maps, symbol,
                                                            folding=folding, emissions=emissions)
                selection = row['linked_selection']
                if selection.get('selection_kind') == 'folded':
                    comparisons = [e.get('comparison', {}) for e in row['emissions']]
                    sizes = {c.get('original_size') for c in comparisons}
                    if (len(sizes) != 1 or None in sizes or
                            not verify_folded_bytes(selection, objects, pe, next(iter(sizes)))):
                        selection.update(result='unknown', reason='folded linked bytes not proved')
                results = [e.get('comparison', {}).get('result', 'ERROR') for e in row['emissions']]
                if not results:
                    row.update(result='unknown', reason='symbol not emitted in supplied objects')
                elif row['linked_selection']['result'] != 'selected':
                    row.update(result='unknown', reason='linked emission not proved')
                elif all(r == 'MATCH' for r in results):
                    row.update(result='all_emissions_match')
                else:
                    row.update(result='emission_differences')
            rows.append(row)
    report = dict(schema=1, scope='Real build emission and original symbol evidence. No registry promotion, linked storage proof, or initial-data proof.',
                  validation_fingerprint=validation_fingerprint(),
                  build_report_sha256=hashlib.sha256(build_path.read_bytes()).hexdigest(),
                  map_sha256=hashlib.sha256(map_path.read_bytes()).hexdigest(),
                  folding_log_sha256=build.get('artifact_sha256', {}).get('link.log'),
                  counts=dict(Counter(r['result'] for r in rows)), rows=rows)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['counts']))
    print(f'Report: {args.output}')
    return int(any('error' in e for r in rows for e in r['emissions']))


if __name__ == '__main__':
    raise SystemExit(main())
