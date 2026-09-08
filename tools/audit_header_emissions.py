"""Check unresolved functions in real build objects. Never emit wrappers or change the registry."""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path

from common import REPO_ROOT
from coff import load_coff_object
from function_compare import compare_object_function
from linker_map import parse_symbols
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


def selected_emission(candidates: list[dict], map_rows: list[dict], symbol: str) -> dict:
    linked = [r for r in map_rows if r['symbol'] == symbol]
    identities = {(r['address'], r['owner']) for r in linked}
    if len(identities) != 1:
        return dict(result='unknown', reason='linked symbol absent or ambiguous', map_rows=linked)
    address, owner = next(iter(identities))
    # VC maps name the input object. Do not select by bytes or source proximity.
    matches = [r for r in candidates if Path(r['object']).name.casefold() == owner.replace('\\', '/').rsplit('/', 1)[-1].casefold()]
    if len(matches) != 1:
        return dict(result='unknown', reason='map owner does not select one build object', map_rows=linked)
    return dict(result='selected', address=f'{address:08X}', owner=owner, emission=matches[0])


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
                row['linked_selection'] = selected_emission(emissions.get(symbol, []), maps, symbol)
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
                  counts=dict(Counter(r['result'] for r in rows)), rows=rows)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report['counts']))
    print(f'Report: {args.output}')
    return int(any('error' in e for r in rows for e in r['emissions']))


if __name__ == '__main__':
    raise SystemExit(main())
