"""Bound COFF emissions through map owners, bytes, and explicit relocations.

An emission can include padding and local tables. Its end is not automatically
the end of executable instructions. Folded or unsupported owners stay unknown.
Unresolved address fields produce a bounded span, not full relocated-byte proof.
"""
from pathlib import Path

from coff import load_coff_object, function_symbol_section
from linked_inputs import digest
from linker_map import parse_symbols, unique_addresses, parse_folding


def owner_file(owner):
    return owner.replace('\\', '/').rsplit('/', 1)[-1].casefold()


def relocate_span(obj, symbol, address, symbols, anchors, image_base, *, allow_unresolved=False):
    section = function_symbol_section(obj, symbol)
    data = bytearray(section.data)
    by_index = {s.index: s for s in obj.symbols}
    references = []
    covered = set()
    for r in section.relocations:
        if r.width != 4 or r.reloc_type not in (6, 7, 0x14) or r.offset < 0 or r.offset+4 > len(data):
            raise ValueError('unsupported or out-of-range emission relocation')
        offsets = set(range(r.offset, r.offset+4))
        if covered & offsets:
            raise ValueError('overlapping emission relocations')
        covered |= offsets
        target = by_index.get(r.symbol_index)
        if target is None:
            raise ValueError('missing relocation symbol')
        if target.section_number == symbol.section_number:
            destination = address + target.value - symbol.value
        elif target.name in symbols and (target.section_number == 0 or target.storage_class == 2):
            destination = symbols[target.name]
        elif target.section_number > 0 and target.section_number in anchors:
            destination = anchors[target.section_number] + target.value
        else:
            if not allow_unresolved:
                raise ValueError('relocation target lacks a unique linked address: ' + target.name)
            references.append(dict(offset=r.offset, symbol=target.name, type=r.reloc_type,
                                   result='unknown', reason='no independent linked target address'))
            continue
        addend = int.from_bytes(data[r.offset:r.offset+4], 'little')
        value = destination + addend
        if r.reloc_type == 0x14:
            value -= address + r.offset + 4
        elif r.reloc_type == 7:
            value -= image_base
        data[r.offset:r.offset+4] = (value & 0xffffffff).to_bytes(4, 'little')
        references.append(dict(offset=r.offset, symbol=target.name, destination=destination, type=r.reloc_type, result='pass'))
    return bytes(data), references


class LinkedEmissions:
    def __init__(self, build, report, pe):
        self.pe = pe
        self.maps = parse_symbols((build / 'empiresx.map').read_text(errors='replace'))
        self.symbols = unique_addresses(self.maps)
        self.objects = {}
        self.hashes = {}
        for row in report['sources']:
            if not row.get('compiled'):
                continue
            path = build / Path(row['object']).name
            expected = report.get('artifact_sha256', {}).get(path.name)
            if not path.is_file() or not expected or digest(path) != expected:
                raise ValueError('Missing or changed object hash: ' + str(path))
            key = owner_file(path.name)
            if key in self.objects:
                raise ValueError('Duplicate object basename')
            self.objects[key] = load_coff_object(path)
            self.hashes[path.name] = expected
        self.folded = set()
        if report.get('artifact_sha256', {}).get('link.log'):
            if digest(build / 'link.log') != report['artifact_sha256']['link.log']:
                raise ValueError('Changed linker log')
            self.folded = {r['symbol'] for r in parse_folding((build / 'link.log').read_text(errors='replace'))}
        self.cache = {}
        self.anchor_cache = {}

    def verify(self, name):
        if name not in self.cache:
            try:
                self.cache[name] = self._verify(name)
            except (ValueError, KeyError) as error:
                self.cache[name] = dict(result='unknown', reason=str(error))
        return self.cache[name]

    def _verify(self, name):
        if name in self.folded:
            raise ValueError('folded emission requires separate ownership proof')
        matches = {(r['address'], owner_file(r['owner'])) for r in self.maps if r['symbol'] == name}
        if len(matches) != 1:
            raise ValueError('no unique linked owner')
        address, owner = next(iter(matches))
        obj = self.objects.get(owner)
        if obj is None:
            raise ValueError('owner is outside hash-checked compiled game objects')
        candidates = [s for s in obj.symbols if s.name == name and s.is_function and s.section_number > 0]
        if len(candidates) != 1:
            raise ValueError('no unique function in selected object')
        symbol = candidates[0]
        if owner not in self.anchor_cache:
            bases = {}
            addresses = unique_addresses([r for r in self.maps if owner_file(r['owner']) == owner])
            for s in obj.symbols:
                if s.section_number > 0 and s.name in addresses:
                    bases.setdefault(s.section_number, set()).add(addresses[s.name] - s.value)
            self.anchor_cache[owner] = {n: next(iter(values)) for n, values in bases.items() if len(values) == 1}
        data, references = relocate_span(obj, symbol, address, self.symbols, self.anchor_cache[owner],
                                        self.pe.OPTIONAL_HEADER.ImageBase, allow_unresolved=True)
        if not data:
            raise ValueError('empty emission')
        actual = self.pe.get_data(address - self.pe.OPTIONAL_HEADER.ImageBase, len(data))
        unresolved = [r for r in references if r['result'] == 'unknown']
        excluded = {i for r in unresolved for i in range(r['offset'], r['offset']+4)}
        if len(actual) != len(data) or any(a != b for i, (a, b) in enumerate(zip(actual, data)) if i not in excluded):
            raise ValueError('relocated emission differs from linked bytes')
        return dict(result='bounded_emitted_span' if unresolved else 'proved_emitted_span',
                    address=address, size=len(data), owner=owner,
                    section=symbol.section_number, offset=symbol.value, references=references,
                    unresolved_relocations=len(unresolved),
                    scope='COFF symbol to next function symbol or section end, including possible tables and padding')
