"""Original symbol evidence. Never infer target identity from a rebuilt call."""
from __future__ import annotations

from collections import defaultdict
from functools import lru_cache
import hashlib
import json

from common import CONFIG_DIR, REPO_ROOT, load_pdb_function_source_map
from original_fpo import load_original_owner_symbols


@lru_cache(maxsize=1)
def original_identities() -> dict[int, dict]:
    candidates = defaultdict(lambda: defaultdict(list))
    owners, _ = load_original_owner_symbols()
    for va, symbol in owners.items():
        candidates[int(va, 16)][symbol].append('original FPO or reviewed owner supplement')
    for va, row in load_pdb_function_source_map().items():
        symbol = str(row.get('symbol_name') or '').strip()
        # This export also calls qualified display names "symbol_name".
        # A display name is not a linkage identity.
        if symbol.startswith('?'):
            candidates[int(va, 16)][symbol].append('PDB procedure')
    path = CONFIG_DIR / 'original_symbol_overrides.txt'
    for line in path.read_text().splitlines() if path.exists() else []:
        if not line.strip() or line.lstrip().startswith('#'):
            continue
        va, symbol = line.split(None, 1)
        candidates[int(va, 16)][symbol.strip()].append('reviewed target supplement')
    result = {va: {'symbols': dict(symbols),
                 'symbol': next(iter(symbols)) if len(symbols) == 1 else None}
            for va, symbols in candidates.items()}
    path = CONFIG_DIR / 'reviewed_reference_identities.json'
    if path.exists():
        reviewed = json.loads(path.read_text())
        for name, expected_hash in reviewed['inputs'].items():
            if hashlib.sha256((REPO_ROOT / name).read_bytes()).hexdigest() != expected_hash:
                raise ValueError(f'Reviewed identity input changed: {name}')
        for address, row in reviewed['targets'].items():
            va = int(address, 16)
            allowed = {row['symbol'], *row['aliases']}
            prior = result.get(va, {'symbols': {}})
            # A reviewed alias cannot erase a newly discovered conflicting owner.
            if set(prior['symbols']) - allowed:
                prior['symbol'] = None
                result[va] = prior
                continue
            result[va] = dict(symbol=row['symbol'], aliases=row['aliases'],
                              symbols={s: [reviewed['evidence']] for s in sorted(allowed)})
    return result


def compare_identity(expected: str, actual: str) -> bool:
    """Keep class, overload, calling convention, and argument decoration intact."""
    expected = expected.removeprefix('__imp_')
    actual = actual.removeprefix('__imp_')
    return expected == actual


def check_direct_identity(target: int, actual: str) -> dict:
    evidence = original_identities().get(target)
    if not evidence or not evidence['symbol']:
        return {'result': 'unknown', 'reason': 'missing or conflicting original symbol',
                'evidence': evidence}
    expected = evidence['symbol']
    valid = any(compare_identity(symbol, actual) for symbol in [expected, *evidence.get('aliases', [])])
    return {'result': 'pass' if valid else 'fail',
            'expected_symbol': expected, 'evidence': evidence}


@lru_cache(maxsize=1)
def validation_fingerprint() -> str:
    """Invalidate old code-check reports when checks or original evidence change."""
    names = ['tools/reference_identity.py', 'tools/function_diagnostics.py',
             'tools/function_compare.py', 'tools/extract_obj_function.py',
             'tools/extract_original_function.py', 'tools/common.py', 'tools/coff.py',
             'tools/original_fpo.py', 'inventory/original_executable_fpo.txt',
             'inventory/pdb/function_source_map.csv', 'inventory/all_functions.csv',
             'config/original_owner_symbol_overrides.txt', 'config/original_symbol_overrides.txt',
             'config/parent_owned_fragments.txt', 'config/binaries.json',
             'config/reviewed_reference_identities.json']
    rows = [(name, hashlib.sha256((REPO_ROOT / name).read_bytes()).hexdigest()
             if (REPO_ROOT / name).is_file() else None) for name in names]
    return hashlib.sha256(json.dumps(rows).encode()).hexdigest()
