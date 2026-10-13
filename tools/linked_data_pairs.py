"""Pair linked references through exact functions and compare the paired items.

An exact function has the same bytes as the original apart from its relocated
fields. Its rebuilt object names the target of each field. The rebuilt field
value minus the object addend gives the target address in the rebuilt image.
The original field at the same offset gives the target address in the original.

Each pair is evidence, not an assumption. A rebuilt item that pairs with two
original addresses is a conflict. An original item that pairs with two rebuilt
items is a split. Paired data items are compared byte for byte, and their own
relocated fields are paired in turn, so tables and virtual tables check their
pointers through the same evidence. Item extents come from the defining object
symbol table, not from byte patterns.
"""
from __future__ import annotations

from collections import Counter, defaultdict
from pathlib import Path

from coff import load_coff_object

DIR32, REL32 = 0x0006, 0x0014
SECTION_CODE, SECTION_UNINITIALIZED = 0x20, 0x80
STATIC_CLASSES = {3, 6}


class Image:
    """Read virtual addresses from a PE file, including zero-filled tails."""

    def __init__(self, pe):
        self.ranges = []
        base = pe.OPTIONAL_HEADER.ImageBase
        for section in pe.sections:
            start = base + section.VirtualAddress
            size = max(section.Misc_VirtualSize, section.SizeOfRawData)
            raw = section.get_data()[:size]
            self.ranges.append((start, start + size, raw + bytes(size - len(raw)),
                                section.Name.rstrip(b'\0').decode('ascii', 'replace')))
        self.imports = {}
        for entry in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
            dll = entry.dll.decode('ascii', 'replace').lower()
            for item in entry.imports:
                name = item.name.decode('ascii', 'replace') if item.name else f'ordinal:{item.ordinal}'
                self.imports[item.address] = (dll, name)

    def read(self, va, size):
        for start, end, data, _ in self.ranges:
            if start <= va and va + size <= end:
                return data[va - start:va - start + size]
        return None

    def dword(self, va):
        data = self.read(va, 4)
        return None if data is None else int.from_bytes(data, 'little')

    def section(self, va):
        for start, end, _, name in self.ranges:
            if start <= va < end:
                return name
        return None


class Objects:
    """Load build objects lazily and find symbol definitions."""

    def __init__(self, paths: dict[str, Path], map_rows: list[dict]):
        self.paths = paths
        self.loaded = {}
        self.owners = defaultdict(set)
        for row in map_rows:
            self.owners[row['symbol']].add(row['owner'].lower())

    def get(self, name):
        if name not in self.paths:
            return None
        if name not in self.loaded:
            obj = load_coff_object(self.paths[name])
            by_index = {s.index: s for s in obj.symbols}
            by_section = defaultdict(list)
            for symbol in obj.symbols:
                if symbol.section_number > 0:
                    by_section[symbol.section_number].append(symbol.value)
            sections = {s.index: s for s in obj.sections}
            self.loaded[name] = (obj, by_index, {k: sorted(set(v)) for k, v in by_section.items()}, sections)
        return self.loaded[name]

    def definition(self, symbol, current):
        """Return (object, section, value) for a relocation symbol, or None."""
        if symbol.section_number > 0:
            return current, symbol.section_number, symbol.value
        owners = self.owners.get(symbol.name, set())
        if len(owners) != 1:
            return None
        owner = next(iter(owners))
        loaded = self.get(owner)
        if loaded is None:
            return None
        matches = [s for s in loaded[0].symbols if s.name == symbol.name and s.section_number > 0
                   and s.storage_class not in STATIC_CLASSES]
        if len(matches) != 1:
            return None
        return owner, matches[0].section_number, matches[0].value


# Decorated scalar data: ?name@@3<type><storage>. Pointer codes are omitted
# because VC5 decorates arrays as pointers.
SCALAR_SIZES = {'C': 1, 'D': 1, 'E': 1, 'F': 2, 'G': 2, 'H': 4, 'I': 4, 'J': 4, 'K': 4, 'M': 4, 'N': 8}


def value_extent(symbol, body, fields):
    """Return the compared size and its basis for one object data item."""
    if symbol.startswith('__real@4@'):
        return 4, 'float constant name'
    if symbol.startswith('__real@8@'):
        return 8, 'double constant name'
    marker = symbol.find('@@3')
    if symbol.startswith('?') and marker > 0 and symbol[marker + 3:marker + 4] in SCALAR_SIZES \
            and symbol[marker + 4:] in ('A', 'B'):
        return min(len(body), SCALAR_SIZES[symbol[marker + 3]]), 'scalar decoration'
    end = body.find(b'\0')
    if not fields and end > 0 and all(32 <= c < 127 or c in (9, 10, 13) for c in body[:end]) \
            and not body[end:].strip(b'\0'):
        return end + 1, 'character string'
    return len(body), 'next symbol'


def masked_equal(a, b, fields):
    if a is None or b is None or len(a) != len(b):
        return False
    a, b = bytearray(a), bytearray(b)
    for offset in fields:
        a[offset:offset + 4] = b[offset:offset + 4] = bytes(4)
    return a == b


def pair_references(original_pe, rebuilt_pe, map_rows, object_paths, exact_functions, function_vas):
    """exact_functions: [(original_va, symbol, size)]; function_vas: symbol -> original VA (registry)."""
    original, rebuilt = Image(original_pe), Image(rebuilt_pe)
    objects = Objects(object_paths, map_rows)
    addresses = defaultdict(set)
    for row in map_rows:
        addresses[row['symbol']].add(row['address'])
    seeds = Counter()
    forward = defaultdict(set)   # rebuilt address -> original addresses
    reverse = defaultdict(set)   # original address -> rebuilt addresses
    info = {}                    # rebuilt address -> symbol, kind, definition
    evidence = Counter()
    checks = []                  # field checks with an independent expectation
    queue, seen = [], set()

    def record(rebuilt_address, original_address, symbol, definition, kind, source):
        forward[rebuilt_address].add(original_address)
        reverse[original_address].add(rebuilt_address)
        evidence[rebuilt_address] += 1
        info.setdefault(rebuilt_address, dict(symbol=symbol, kind=kind, definition=definition, source=source))
        if kind == 'data' and definition and rebuilt_address not in seen:
            seen.add(rebuilt_address)
            queue.append(rebuilt_address)

    def visit(obj_name, section, start, size, rebuilt_at, original_at, source):
        """Pair every relocated field of one exact byte range."""
        _, by_index, _, _ = objects.get(obj_name)
        for reloc in section.relocations:
            if not start <= reloc.offset < start + size or reloc.reloc_type not in (DIR32, REL32):
                continue
            symbol = by_index.get(reloc.symbol_index)
            if symbol is None:
                continue
            inline = int.from_bytes(section.data[reloc.offset:reloc.offset + 4], 'little', signed=True) \
                if section.data else 0
            pr, po = rebuilt_at + reloc.offset - start, original_at + reloc.offset - start
            r, o = rebuilt.dword(pr), original.dword(po)
            if r is None or o is None:
                continue
            if reloc.reloc_type == DIR32:
                ar, ao = (r - inline) & 0xffffffff, (o - inline) & 0xffffffff
            else:
                ar, ao = (pr + 4 + r - inline) & 0xffffffff, (po + 4 + o - inline) & 0xffffffff
            definition = objects.definition(symbol, obj_name)
            target_section = None
            if definition is not None:
                target_section = objects.get(definition[0])[3].get(definition[1])
            is_code = bool(target_section and target_section.characteristics & SECTION_CODE)
            if definition is not None and definition[0] == obj_name and target_section is section \
                    and symbol.storage_class in STATIC_CLASSES:
                # A label inside the same exact range, such as a switch table.
                expected = original_at + (ar - rebuilt_at)
                checks.append(dict(kind='internal_label', source=source, offset=reloc.offset - start,
                                   symbol=symbol.name, original_target=f'{ao:08X}', expected=f'{expected:08X}',
                                   result='pass' if ao == expected else 'fail'))
                continue
            if symbol.name.startswith('__imp_'):
                expected = rebuilt.imports.get(ar)
                actual = original.imports.get(ao)
                checks.append(dict(kind='import', source=source, offset=reloc.offset - start, symbol=symbol.name,
                                   original_target=f'{ao:08X}', expected=' '.join(expected or ()),
                                   actual=' '.join(actual or ()),
                                   result='unknown' if expected is None or actual is None
                                   else 'pass' if expected == actual else 'fail'))
                continue
            if is_code or symbol.name in function_vas:
                if symbol.name in function_vas and addresses.get(symbol.name) and len(addresses[symbol.name]) == 1:
                    delta = ar - next(iter(addresses[symbol.name]))
                    expected = function_vas[symbol.name] + delta
                    checks.append(dict(kind='function', source=source, offset=reloc.offset - start,
                                       symbol=symbol.name, original_target=f'{ao:08X}', expected=f'{expected:08X}',
                                       result='pass' if ao == expected else 'fail'))
                record(ar, ao, symbol.name, definition, 'function', source)
                continue
            record(ar, ao, symbol.name, definition, 'data' if definition else 'external', source)

    for original_va, symbol, size in exact_functions:
        owners = objects.owners.get(symbol, set())
        if len(owners) != 1 or len(addresses.get(symbol, ())) != 1:
            seeds['symbol not uniquely linked'] += 1
            continue
        owner = next(iter(owners))
        loaded = objects.get(owner)
        if loaded is None:
            seeds['defining object not in build'] += 1
            continue
        obj, _, _, sections = loaded
        defs = [s for s in obj.symbols if s.name == symbol and s.section_number > 0]
        if len(defs) != 1:
            seeds['symbol not uniquely defined'] += 1
            continue
        section = sections[defs[0].section_number]
        start = defs[0].value
        if start + size > len(section.data):
            seeds['inventory size exceeds object section'] += 1
            continue
        rebuilt_at = next(iter(addresses[symbol]))
        fields = [r.offset - start for r in section.relocations if start <= r.offset < start + size]
        body = section.data[start:start + size]
        if not masked_equal(body, rebuilt.read(rebuilt_at, size), fields):
            seeds['linked bytes differ from object'] += 1
            continue
        if not masked_equal(body, original.read(original_va, size), fields):
            seeds['original differs outside relocated fields'] += 1
            continue
        seeds['exact seed'] += 1
        visit(owner, section, start, size, rebuilt_at, original_va, f'{original_va:08X} {symbol}')

    items = []
    while queue:
        ar = queue.pop()
        origins = forward[ar]
        entry = info[ar]
        obj_name, section_number, value = entry['definition']
        _, _, starts, sections = objects.get(obj_name)
        section = sections[section_number]
        later = [v for v in starts.get(section_number, []) if v > value]
        row = dict(symbol=entry['symbol'], object=obj_name, section=section.name, rebuilt=f'{ar:08X}',
                   original=' '.join(f'{o:08X}' for o in sorted(origins)), references=evidence[ar])
        if len(origins) != 1:
            items.append(dict(row, result='conflict', reason='rebuilt item pairs with several original addresses'))
            continue
        ao = next(iter(origins))
        if not section.data or section.characteristics & SECTION_UNINITIALIZED:
            items.append(dict(row, result='zero_fill', reason='uninitialized storage; size not proved here'))
            continue
        end = later[0] if later else len(section.data)
        size = end - value
        fields = [r.offset - value for r in section.relocations if value <= r.offset < end]
        body = section.data[value:end]
        size, basis = value_extent(entry['symbol'], body, fields)
        body = body[:size]
        row.update(size=size, extent=basis)
        if not masked_equal(body, rebuilt.read(ar, size), fields):
            items.append(dict(row, result='unknown', reason='linked bytes differ from the defining object'))
            continue
        theirs = original.read(ao, size)
        if theirs is None:
            items.append(dict(row, result='unknown', reason='original range outside one section'))
            continue
        differing = [i for i in range(size) if not any(f <= i < f + 4 for f in fields) and body[i] != theirs[i]]
        visit(obj_name, section, value, size, ar, ao, f'item {entry["symbol"]}')
        padding = len(body) - len(body.rstrip(b'\0'))
        if not differing:
            result = 'equal'
        elif basis == 'next symbol' and padding and min(differing) >= len(body) - padding:
            # The value may end before our zero tail; the original keeps other data there.
            result = 'tail_unproved'
        else:
            result = 'different'
        row.update(pointer_fields=len(fields), differing_bytes=len(differing),
                   first_differences=differing[:8], rebuilt_preview=body[:24].hex(),
                   original_preview=theirs[:24].hex())
        items.append(dict(row, result=result))

    pairs = []
    for ar, origins in sorted(forward.items()):
        entry = info[ar]
        splits = sorted({r for o in origins for r in reverse[o]} - {ar})
        result = ('conflict' if len(origins) > 1 else 'split' if splits else 'consistent')
        pairs.append(dict(symbol=entry['symbol'], kind=entry['kind'], rebuilt=f'{ar:08X}',
                          original=' '.join(f'{o:08X}' for o in sorted(origins)), references=evidence[ar],
                          shared_with=' '.join(f'{s:08X}' for s in splits), result=result,
                          first_source=entry['source']))
    return dict(seeds=dict(seeds), pairs=pairs, items=items, checks=checks)
