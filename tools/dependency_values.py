"""Read stored numeric operands without treating pointer fixups as constants."""

FLOAT_READS = {'fld', 'fadd', 'fsub', 'fsubr', 'fmul', 'fdiv', 'fdivr', 'fcom', 'fcomp'}


def readonly_bytes(pe, address, size):
    rva = address - pe.OPTIONAL_HEADER.ImageBase
    matches = [s for s in pe.sections if s.VirtualAddress <= rva
               and rva + size <= s.VirtualAddress + min(s.Misc_VirtualSize, s.SizeOfRawData)]
    if len(matches) != 1 or matches[0].Characteristics & 0xA0000020:
        raise ValueError('operand is not in one read-only non-code stored range')
    for block in getattr(pe, 'DIRECTORY_ENTRY_BASERELOC', []):
        for entry in block.entries:
            if entry.type and entry.rva < rva + size and entry.rva + 4 > rva:
                raise ValueError('operand overlaps a base relocation; pointer content needs ownership evidence')
    raw = pe.get_data(rva, size)
    if len(raw) != size:
        raise ValueError('truncated operand storage')
    return raw
