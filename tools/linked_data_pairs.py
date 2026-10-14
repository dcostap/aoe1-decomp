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

from bisect import bisect_right
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


def code_end(section, by_index, start):
    """Return where a function's code ends in its object section.

    The code ends at the next function symbol or at the first table that already decoded code addresses through
    a same-section label, whichever comes first. Table entries also address labels, but they lie past that point.
    """
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    later = [s.value for s in by_index.values() if s.section_number == section.index and s.symbol_type == 0x20
             and s.value > start]
    end = min(later, default=len(section.data))
    targets = {}
    for reloc in section.relocations:
        symbol = by_index.get(reloc.symbol_index)
        if reloc.reloc_type == DIR32 and start <= reloc.offset < end and symbol is not None \
                and symbol.section_number == section.index and symbol.storage_class in STATIC_CLASSES:
            inline = int.from_bytes(section.data[reloc.offset:reloc.offset + 4], 'little', signed=True)
            targets[reloc.offset] = symbol.value + inline
    tables = end
    for ins in Cs(CS_ARCH_X86, CS_MODE_32).disasm(section.data[start:end], start):
        if ins.address >= tables:
            break
        for field in range(ins.address, ins.address + ins.size):
            if start < targets.get(field, end) < tables:
                tables = targets[field]
    return tables


IMAGE_LOW, IMAGE_HIGH = 0x400000, 0x1000000  # displacements in this range address the image, not a structure


def instructions(data, va, identify):
    """Decode a byte range. Return (instructions, keys, generic keys, masks).

    identify(kind, value) names a branch target ('target') or a four-byte address operand ('memory') the same way
    in both images: ('function', original address), ('import', dll, name), or ('data', original address). A key
    carries that identity; a generic key does not.
    """
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32, CS_GRP_CALL, CS_GRP_JUMP
    from capstone.x86 import X86_OP_IMM, X86_OP_MEM
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    decoded, keys, generic, masks = [], [], [], []
    for ins in decoder.disasm(data, va):
        raw = bytearray(ins.bytes)
        masked = set()
        identity = None
        control = ins.group(CS_GRP_CALL) or ins.group(CS_GRP_JUMP)
        if control and ins.operands and ins.operands[0].type == X86_OP_IMM:
            masked.update(range(ins.imm_offset, ins.imm_offset + ins.imm_size))
            target = ins.operands[0].imm & 0xffffffff
            inside = va <= target < va + len(data)
            if not inside:
                identity = identify('target', target)
            key = (ins.mnemonic, 'inside' if inside else 'outside')
        else:
            found = []
            disp = int.from_bytes(ins.bytes[ins.disp_offset:ins.disp_offset + 4], 'little')
            if ins.disp_size == 4 and (IMAGE_LOW <= disp < IMAGE_HIGH or any(
                    op.type == X86_OP_MEM and op.mem.base == 0 for op in ins.operands)):
                # An absolute operand, or a table indexed from a base register, such as a byte selector.
                masked.update(range(ins.disp_offset, ins.disp_offset + 4))
                found.append(identify('memory', disp))
            if ins.imm_size == 4:
                masked.update(range(ins.imm_offset, ins.imm_offset + 4))
                found.append(identify('memory', int.from_bytes(ins.bytes[ins.imm_offset:ins.imm_offset + 4],
                                                               'little')))
            identity = None if not any(found) else found[0] if len(found) == 1 else tuple(found)
            for i in masked:
                raw[i] = 0
            key = bytes(raw)
        decoded.append(ins)
        generic.append(key)
        keys.append((key, identity))
        masks.append(masked)
    return decoded, keys, generic, masks


LONG_RUN = 8  # aligned instructions that pair operands even without an anchor


def align_function(original_code, original_at, rebuilt_code, rebuilt_at, fields, identify_original,
                   identify_rebuilt):
    """Map rebuilt instruction offsets to original addresses through an instruction alignment.

    fields: rebuilt offsets of relocated four-byte fields. Calls and import slots align only with the same
    callee. An aligned pair must have the same length and the same bytes outside those fields and outside branch
    targets, so a field is paired only inside an identical instruction. Short runs of common shapes, such as x87
    sequences, also match unrelated code after blocks move. So operands pair only in a run that has an anchor, an
    operand with a proved identity, or in a run of LONG_RUN instructions; table jumps always pair. Labels map
    through every aligned instruction and serve only as weaker evidence for table entries. Where the alignment
    replaces one instruction by one of the same shape and both callees are known but differ, the pair is reported.

    Returns (field map, label map, rebuilt instruction count, [(rebuilt offset, rebuilt identity, original
    identity)]). Each map is {rebuilt offset: (original address, size)}.
    """
    from difflib import SequenceMatcher
    a, a_keys, a_generic, _ = instructions(original_code, original_at, identify_original)
    b, b_keys, b_generic, b_masks = instructions(rebuilt_code, rebuilt_at, identify_rebuilt)
    mapping, labels, changed = {}, {}, []
    opcodes = SequenceMatcher(None, a_keys, b_keys, autojunk=False).get_opcodes()

    def anchored(n):
        tag, _, _, j1, j2 = opcodes[n]
        return tag == 'equal' and (j2 - j1 >= LONG_RUN or any(key[1] is not None for key in b_keys[j1:j2]))

    for n, (tag, i1, i2, j1, j2) in enumerate(opcodes):
        # Only a block between anchored equal blocks that differs in identities alone pairs its instructions by
        # position. Elsewhere the alignment may have drifted, such as after a register swap.
        flanked = all(anchored(m) for m in (n - 1, n + 1) if 0 <= m < len(opcodes)) and len(opcodes) > 1
        if tag == 'replace' and flanked and a_generic[i1:i2] == b_generic[j1:j2]:
            for x, y, ka, kb in zip(a[i1:i2], b[j1:j2], a_keys[i1:i2], b_keys[j1:j2]):
                if ka[0] == kb[0] and ka[1] is not None and kb[1] is not None \
                        and ka[1][0] in ('function', 'import') and kb[1][0] in ('function', 'import'):
                    changed.append((y.address - rebuilt_at, kb[1], ka[1]))
        if tag != 'equal':
            continue
        run_anchored = i2 - i1 >= LONG_RUN or any(key[1] is not None for key in b_keys[j1:j2])
        for k in range(i2 - i1):
            x, y = a[i1 + k], b[j1 + k]
            offset = y.address - rebuilt_at
            if x.size != y.size:
                continue
            ignored = set(b_masks[j1 + k]) if isinstance(b_generic[j1 + k], tuple) else set()
            for field in fields:
                if offset <= field < offset + y.size:
                    ignored.update(range(field - offset, field - offset + 4))
            if not all(x.bytes[p] == y.bytes[p] for p in range(y.size) if p not in ignored):
                continue
            labels[offset] = (x.address, y.size)
            table_jump = y.mnemonic == 'jmp' and not isinstance(b_generic[j1 + k], tuple)
            if run_anchored or table_jump:
                mapping[offset] = (x.address, y.size)
    return mapping, labels, len(b), changed


def pair_references(original_pe, rebuilt_pe, map_rows, object_paths, exact_functions, function_vas,
                    aligned_functions=()):
    """exact_functions: [(original_va, symbol, size)]; function_vas: symbol -> original VA (registry).

    aligned_functions: [(original_va, symbol, size, status)] of functions that are not exact. Their fields are
    paired only inside instructions that an alignment matches, and their rows carry seed 'aligned'.
    """
    original, rebuilt = Image(original_pe), Image(rebuilt_pe)
    objects = Objects(object_paths, map_rows)
    addresses = defaultdict(set)
    for row in map_rows:
        addresses[row['symbol']].add(row['address'])
    seeds = Counter()
    forward = defaultdict(set)   # rebuilt address -> original addresses
    reverse = defaultdict(set)   # original address -> rebuilt addresses
    info = {}                    # rebuilt address -> symbol, kind, definition
    sources = defaultdict(dict)  # rebuilt address -> original address -> first source
    seed_kinds = defaultdict(set)
    evidence = Counter()
    checks = []                  # field checks with an independent expectation
    queue, seen, tables = [], set(), set()

    class Range:
        """One compared byte range. Exact ranges map every offset; aligned ranges map matched instructions only."""

        def __init__(self, start, size, rebuilt_at, original_at, source, seed, mapping=None, labels=None):
            self.start, self.size, self.rebuilt_at, self.original_at = start, size, rebuilt_at, original_at
            self.source, self.seed, self.mapping, self.labels = source, seed, mapping, labels
            self.starts = sorted(mapping) if mapping is not None else None

        def label(self, offset):
            """Original address of a rebuilt section offset that starts an instruction or item byte."""
            if self.mapping is None:
                return self.original_at + offset - self.start
            return self.labels.get(offset - self.start, (None,))[0]

        def field(self, offset, weak=False):
            """Original address of a relocated field, or None when its instruction is not aligned.

            weak also uses the label map, for a field whose use is checked independently.
            """
            if self.mapping is None:
                return self.original_at + offset - self.start
            mapping = self.labels if weak else self.mapping
            starts = sorted(mapping) if weak else self.starts
            i = bisect_right(starts, offset - self.start) - 1
            if i < 0:
                return None
            address, size = mapping[starts[i]]
            inside = offset - self.start - starts[i]
            return address + inside if inside + 4 <= size else None

    def switch_table(obj_name, section, span, label, original_va):
        """Compare a table that the function addresses past its code.

        Entries that address labels of the same function must address the original instruction that the label
        maps to. In an exact function that is the same offset from the function start, so a changed case order
        fails even when the code bytes match.
        """
        _, by_index, starts, _ = objects.get(obj_name)
        later = [v for v in starts.get(section.index, []) if v > label]
        end = later[0] if later else len(section.data)
        rebuilt_table = rebuilt.read(span.rebuilt_at + label - span.start, end - label)
        original_table = original.read(original_va, end - label)
        row = dict(kind='switch_table', seed=span.seed, source=span.source, offset=label - span.start, symbol='',
                   size=end - label, original_target=f'{original_va:08X}')
        if rebuilt_table is None or original_table is None:
            return dict(row, result='unknown')
        entries = {r.offset - label for r in section.relocations
                   if label <= r.offset < end and r.reloc_type == DIR32}
        if span.mapping is not None and not entries:
            return None  # an aligned byte table is checked through the jump table that it selects from
        differing, unmapped = [], []
        compared = end - label
        if span.mapping is not None:
            # The original keeps its own code after its table, where the rebuilt object may have padding.
            compared = max(len(rebuilt_table.rstrip(bytes([0x90]))), max(entries, default=-4) + 4)
        for offset in range(0, compared):
            if any(e <= offset < e + 4 for e in entries):
                continue
            if rebuilt_table[offset] != original_table[offset]:
                differing.append(offset)
        disagreeing = []
        for entry in sorted(entries):
            target = int.from_bytes(rebuilt_table[entry:entry + 4], 'little') - span.rebuilt_at + span.start
            expected = span.label(target)
            if expected is None:
                unmapped.append(entry)
            elif int.from_bytes(original_table[entry:entry + 4], 'little') != expected:
                disagreeing.append(entry)
        if span.mapping is None:
            differing += disagreeing
            result = 'fail' if differing else 'unknown' if unmapped else 'pass'
            return dict(row, expected=rebuilt_table.hex(), actual=original_table.hex(),
                        differing=sorted(differing)[:8], unmapped_entries=len(unmapped), result=result)

        # Moved blocks can mislead the label map, so an aligned table is proved by its partition: case values that
        # share a target in one image must share a target in the other. A label disagreement alone stays unproved.
        # When a byte table selects the entry, the two images may number their entries differently, so each case
        # value goes through its own image's byte table first.
        rebuilt_cases, original_cases = list(range(len(entries))), list(range(len(entries)))
        selector = byte_selector(obj_name, section, span, end, len(entries))
        if selector is not None:
            rebuilt_cases, original_cases = selector
            differing = [d for d in differing if d < max(entries, default=-4) + 4]
        rebuilt_targets = [rebuilt_table[4 * i:4 * i + 4] for i in rebuilt_cases]
        original_targets = [original.read(original_va + 4 * i, 4) for i in original_cases]
        if partition(rebuilt_targets) != partition(original_targets):
            differing.append('partition')
        if selector is not None:
            row.update(case_values=len(rebuilt_cases))
            disagreeing = []
        result = ('fail' if differing else 'partition_pass' if disagreeing or unmapped else 'pass')
        return dict(row, expected=rebuilt_table.hex(), actual=original_table.hex(), differing=differing[:8],
                    unmapped_entries=len(unmapped), label_disagreements=len(disagreeing), result=result)

    def partition(targets):
        first = {}
        return [first.setdefault(target, i) for i, target in enumerate(targets)]

    def byte_selector(obj_name, section, span, label, entries):
        """Return the entry index per case value in both images, when a byte table at label selects the entry."""
        _, by_index, starts, _ = objects.get(obj_name)
        later = [v for v in starts.get(section.index, []) if v > label]
        end = later[0] if later else len(section.data)
        if any(label <= r.offset < end for r in section.relocations):
            return None
        for reloc in section.relocations:
            symbol = by_index.get(reloc.symbol_index)
            if reloc.reloc_type != DIR32 or not span.start <= reloc.offset < span.start + span.size \
                    or symbol is None or symbol.section_number != section.index:
                continue
            inline = int.from_bytes(section.data[reloc.offset:reloc.offset + 4], 'little', signed=True)
            if symbol.value + inline != label:
                continue
            # A wrong pairing here gives a wrong byte table, which the partition comparison reports.
            field = span.field(reloc.offset, weak=True)
            if field is None:
                return None
            # The rebuilt range may end in padding, such as 90 8b ff. A real index addresses an entry of the table.
            rebuilt_cases = []
            for index in section.data[label:end]:
                if index >= entries:
                    break
                rebuilt_cases.append(index)
            disp = original.dword(field)
            theirs = original.read(disp, len(rebuilt_cases))
            return (rebuilt_cases, list(theirs)) if theirs is not None else None
        return None

    def record(rebuilt_address, original_address, symbol, definition, kind, span):
        forward[rebuilt_address].add(original_address)
        reverse[original_address].add(rebuilt_address)
        evidence[rebuilt_address] += 1
        seed_kinds[rebuilt_address].add(span.seed)
        sources[rebuilt_address].setdefault(original_address, span.source)
        info.setdefault(rebuilt_address, dict(symbol=symbol, kind=kind, definition=definition, source=span.source))
        if kind == 'data' and definition and rebuilt_address not in seen:
            seen.add(rebuilt_address)
            queue.append((rebuilt_address, span.seed))

    def visit(obj_name, section, span):
        """Pair every relocated field of one compared byte range."""
        _, by_index, _, _ = objects.get(obj_name)
        start, size = span.start, span.size
        for reloc in section.relocations:
            if not start <= reloc.offset < start + size or reloc.reloc_type not in (DIR32, REL32):
                continue
            symbol = by_index.get(reloc.symbol_index)
            if symbol is None:
                continue
            po = span.field(reloc.offset)
            if po is None:
                seeds['unaligned field'] += 1
                continue
            inline = int.from_bytes(section.data[reloc.offset:reloc.offset + 4], 'little', signed=True) \
                if section.data else 0
            pr = span.rebuilt_at + reloc.offset - start
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
            row = dict(seed=span.seed, source=span.source, offset=reloc.offset - start, symbol=symbol.name,
                       original_target=f'{ao:08X}')
            if definition is not None and definition[0] == obj_name and target_section is section \
                    and symbol.storage_class in STATIC_CLASSES:
                # A label of the same function, such as a switch table.
                label = start + ar - span.rebuilt_at + (inline if reloc.reloc_type == DIR32 else 0)
                referenced = (o if reloc.reloc_type == DIR32 else po + 4 + o) & 0xffffffff
                if label >= start + size:
                    # Past the code. An aligned function's table has no expected place; its entries are checked.
                    expected = span.label(label) if span.mapping is None else referenced
                    if span.mapping is None:
                        checks.append(dict(row, kind='internal_label', expected=f'{expected:08X}',
                                           result='pass' if referenced == expected else 'fail'))
                    if referenced == expected and (obj_name, section.index, label) not in tables:
                        tables.add((obj_name, section.index, label))
                        table = switch_table(obj_name, section, span, label, referenced)
                        if table is not None:
                            checks.append(table)
                    continue
                expected = span.label(label)
                checks.append(dict(row, kind='internal_label',
                                   expected='' if expected is None else f'{expected:08X}',
                                   result='unknown' if expected is None else
                                   'pass' if referenced == expected else 'fail'))
                continue
            if symbol.name.startswith('__imp_'):
                expected = rebuilt.imports.get(ar)
                actual = original.imports.get(ao)
                checks.append(dict(row, kind='import', expected=' '.join(expected or ()),
                                   actual=' '.join(actual or ()),
                                   result='unknown' if expected is None or actual is None
                                   else 'pass' if expected == actual else 'fail'))
                continue
            if is_code or symbol.name in function_vas:
                if symbol.name in function_vas and addresses.get(symbol.name) and len(addresses[symbol.name]) == 1:
                    delta = ar - next(iter(addresses[symbol.name]))
                    expected = function_vas[symbol.name] + delta
                    checks.append(dict(row, kind='function', expected=f'{expected:08X}',
                                       result='pass' if ao == expected else 'fail'))
                record(ar, ao, symbol.name, definition, 'function', span)
                continue
            record(ar, ao, symbol.name, definition, 'data' if definition else 'external', span)

    def function_range(original_va, symbol, size):
        """Return (owner, section, start, rebuilt address) of a linked function, or a reason string."""
        owners = objects.owners.get(symbol, set())
        if len(owners) != 1 or len(addresses.get(symbol, ())) != 1:
            return 'symbol not uniquely linked'
        owner = next(iter(owners))
        loaded = objects.get(owner)
        if loaded is None:
            return 'defining object not in build'
        obj, _, _, sections = loaded
        defs = [s for s in obj.symbols if s.name == symbol and s.section_number > 0]
        if len(defs) != 1:
            return 'symbol not uniquely defined'
        return owner, sections[defs[0].section_number], defs[0].value, next(iter(addresses[symbol]))

    items = []

    def drain():
        while queue:
            ar, seed = queue.pop()
            origins = forward[ar]
            entry = info[ar]
            obj_name, section_number, value = entry['definition']
            _, _, starts, sections = objects.get(obj_name)
            section = sections[section_number]
            later = [v for v in starts.get(section_number, []) if v > value]
            row = dict(symbol=entry['symbol'], seed=seed, object=obj_name, section=section.name, rebuilt=f'{ar:08X}',
                       original=' '.join(f'{o:08X}' for o in sorted(origins)), references=evidence[ar])
            if len(origins) != 1:
                items.append(dict(row, result='conflict', reason='rebuilt item pairs with several original addresses'))
                continue
            ao = next(iter(origins))
            if not section.data or section.characteristics & SECTION_UNINITIALIZED:
                items.append(dict(row, result='zero_fill', reason='uninitialized storage; size not proved here'))
                continue
            end = later[0] if later else len(section.data)
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
            visit(obj_name, section, Range(value, size, ar, ao, f'item {entry["symbol"]}', seed))
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

    for original_va, symbol, size in exact_functions:
        found = function_range(original_va, symbol, size)
        if isinstance(found, str):
            seeds[found] += 1
            continue
        owner, section, start, rebuilt_at = found
        if start + size > len(section.data):
            seeds['inventory size exceeds object section'] += 1
            continue
        fields = [r.offset - start for r in section.relocations if start <= r.offset < start + size]
        body = section.data[start:start + size]
        if not masked_equal(body, rebuilt.read(rebuilt_at, size), fields):
            seeds['linked bytes differ from object'] += 1
            continue
        if not masked_equal(body, original.read(original_va, size), fields):
            seeds['original differs outside relocated fields'] += 1
            continue
        seeds['exact seed'] += 1
        visit(owner, section, Range(start, size, rebuilt_at, original_va, f'{original_va:08X} {symbol}', 'exact'))
    drain()

    # Operands align by identity: registry functions, imports, and the addresses that exact seeds proved.
    registry = {va: name for name, va in function_vas.items()}
    symbol_at = {}
    for row in map_rows:
        symbol_at.setdefault(row['address'], row['symbol'])
    proved = {r: next(iter(o)) for r, o in forward.items() if len(o) == 1}
    proved_original = set(proved.values())

    def identify_original(kind, value):
        if kind == 'memory' and value in original.imports:
            return ('import',) + original.imports[value]
        if value in registry:
            return ('function', value)
        return ('data', value) if value in proved_original else None

    def identify_rebuilt(kind, value):
        if kind == 'memory' and value in rebuilt.imports:
            return ('import',) + rebuilt.imports[value]
        if symbol_at.get(value) in function_vas:
            return ('function', function_vas[symbol_at[value]])
        return ('data', proved[value]) if value in proved else None

    def identity_text(identity):
        if identity[0] == 'import':
            return ' '.join(identity[1:])
        return f'{identity[1]:08X} {registry.get(identity[1], "")}'.rstrip()

    alignment = []
    for original_va, symbol, size, status in aligned_functions:
        found = function_range(original_va, symbol, size)
        if isinstance(found, str):
            seeds[found] += 1
            continue
        owner, section, start, rebuilt_at = found
        _, by_index, _, _ = objects.get(owner)
        end = code_end(section, by_index, start)
        fields = [r.offset - start for r in section.relocations if start <= r.offset < end]
        rebuilt_code, original_code = rebuilt.read(rebuilt_at, end - start), original.read(original_va, size)
        if rebuilt_code is None or original_code is None:
            seeds['code outside the image'] += 1
            continue
        if not masked_equal(section.data[start:end], rebuilt_code, fields):
            seeds['linked bytes differ from object'] += 1
            continue
        mapping, labels, total, changed = align_function(original_code, original_va, rebuilt_code, rebuilt_at,
                                                         fields, identify_original, identify_rebuilt)
        source = f'{original_va:08X} {symbol}'
        alignment.append(dict(source=source, status=status, rebuilt_instructions=total,
                              aligned_instructions=len(mapping), relocated_fields=len(fields)))
        for offset, theirs_expected, actual in changed:
            checks.append(dict(seed='aligned', source=source, offset=offset, symbol='', kind='callee',
                               expected=identity_text(theirs_expected), actual=identity_text(actual), result='fail'))
        seeds['aligned seed'] += 1
        visit(owner, section, Range(start, end - start, rebuilt_at, original_va, source, 'aligned', mapping,
                                       labels))
    drain()

    pairs = []
    for ar, origins in sorted(forward.items()):
        entry = info[ar]
        splits = sorted({r for o in origins for r in reverse[o]} - {ar})
        result = ('conflict' if len(origins) > 1 else 'split' if splits else 'consistent')
        pairs.append(dict(symbol=entry['symbol'], kind=entry['kind'],
                          seed='exact' if 'exact' in seed_kinds[ar] else 'aligned', rebuilt=f'{ar:08X}',
                          original=' '.join(f'{o:08X}' for o in sorted(origins)), references=evidence[ar],
                          shared_with=' '.join(f'{s:08X}' for s in splits), result=result,
                          first_source=entry['source'],
                          original_sources='' if len(origins) == 1 else '; '.join(
                              f'{o:08X} {s}' for o, s in sorted(sources[ar].items()))))
    return dict(seeds=dict(seeds), pairs=pairs, items=items, checks=checks, alignment=alignment)
