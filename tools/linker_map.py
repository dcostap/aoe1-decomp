"""Read VC linker-map symbols without discarding duplicate names or owners."""
from __future__ import annotations
import re
from collections import defaultdict


def parse_symbols(text: str) -> list[dict]:
    rows = []
    pattern = r'^\s+([0-9a-fA-F]{4}):([0-9a-fA-F]{8})\s+(\S+)\s+([0-9a-fA-F]{8})\s+(.*)$'
    for match in re.finditer(pattern, text, re.M):
        segment, offset, name, address, suffix = match.groups()
        words = suffix.split()
        function = bool(words and words[0] == 'f')
        if function:
            words.pop(0)
        if words and words[0] == 'i':
            words.pop(0)
        rows.append(dict(segment=int(segment, 16), offset=int(offset, 16),
                         symbol=name, address=int(address, 16), function=function,
                         owner=' '.join(words)))
    return rows


def unique_addresses(rows: list[dict]) -> dict[str, int]:
    values = defaultdict(set)
    for row in rows:
        values[row['symbol']].add(row['address'])
    return {name: next(iter(addresses)) for name, addresses in values.items() if len(addresses) == 1}


def parse_folding(text: str) -> list[dict]:
    """Read explicit VC5 /VERBOSE replacement records, not address aliases."""
    rows = []
    selected = None
    mode = None
    for line in text.splitlines():
        if line.strip() == 'Selected symbol:':
            selected, mode = None, 'selected'
            continue
        if line.strip() == 'Replaced symbol(s):':
            mode = 'replaced' if selected else None
            continue
        match = re.fullmatch(r'\s+".*" \((\S+)\) from (.+)', line)
        if match and mode == 'selected':
            selected = match.groups()
            mode = None
        elif match and mode == 'replaced':
            symbol, owner = match.groups()
            rows.append(dict(symbol=symbol, owner=owner,
                             selected_symbol=selected[0], selected_owner=selected[1]))
        elif line.strip():
            selected, mode = None, None
    return rows
