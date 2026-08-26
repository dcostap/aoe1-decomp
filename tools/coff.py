from __future__ import annotations

import struct
from dataclasses import dataclass
from pathlib import Path
from typing import Callable


@dataclass(frozen=True)
class CoffRelocation:
    offset: int
    symbol_index: int
    reloc_type: int
    width: int
    symbol_name: str = ""


@dataclass(frozen=True)
class CoffSection:
    name: str
    data: bytes
    relocations: list[CoffRelocation]
    index: int = 0
    characteristics: int = 0


@dataclass(frozen=True)
class CoffSymbol:
    index: int
    name: str
    value: int
    section_number: int
    symbol_type: int
    storage_class: int
    auxiliary_count: int
    # A weak external stores the symbol-table index of its fallback in its
    # auxiliary record.  Keep this metadata so validators can distinguish a
    # compiler weak external from an ordinary alias.
    weak_external_tag_index: int | None = None
    weak_external_characteristics: int | None = None

    @property
    def is_function(self) -> bool:
        # IMAGE_SYM_DTYPE_FUNCTION occupies the first derived-type field.
        return bool(self.symbol_type & 0x20)


@dataclass(frozen=True)
class CoffObject:
    sections: list[CoffSection]
    symbols: list[CoffSymbol]

    def section_by_index(self, section_number: int) -> CoffSection:
        for section in self.sections:
            if section.index == section_number:
                return section
        raise KeyError(f"COFF section {section_number} not found")


def _decode_short_name(raw_name: bytes) -> str:
    return raw_name.split(b"\x00", 1)[0].decode("ascii", errors="replace")


def _read_c_string(data: bytes, offset: int) -> str:
    if offset < 0 or offset >= len(data):
        return ""
    end = data.find(b"\x00", offset)
    if end < 0:
        end = len(data)
    return data[offset:end].decode("ascii", errors="replace")


def _decode_symbol_name(raw_name: bytes, data: bytes, string_table_offset: int) -> str:
    zeroes, string_offset = struct.unpack("<II", raw_name)
    if zeroes == 0 and string_offset:
        return _read_c_string(data, string_table_offset + string_offset)
    return _decode_short_name(raw_name)


def _decode_section_name(raw_name: bytes, data: bytes, string_table_offset: int) -> str:
    short = raw_name.rstrip(b"\x00")
    if short.startswith(b"/"):
        try:
            string_offset = int(short[1:].decode("ascii"))
        except ValueError:
            pass
        else:
            return _read_c_string(data, string_table_offset + string_offset)
    return _decode_short_name(raw_name)


def relocation_width(reloc_type: int) -> int:
    width_map = {
        0x0006: 4,  # IMAGE_REL_I386_DIR32
        0x0007: 4,  # IMAGE_REL_I386_DIR32NB
        0x000A: 2,  # IMAGE_REL_I386_SECTION
        0x000B: 4,  # IMAGE_REL_I386_SECREL
        0x0014: 4,  # IMAGE_REL_I386_REL32
    }
    return width_map.get(reloc_type, 4)


def load_coff_object(path: Path) -> CoffObject:
    """Parse COFF sections, symbols, and section-relative relocations.

    Section identity is deliberately preserved. VC5 commonly emits several
    same-named COMDAT ``.text`` sections; flattening those sections before
    resolving symbols loses the reliable way to select the target body.
    """
    data = path.read_bytes()
    if len(data) < 20:
        raise ValueError(f"{path} is too small to be a COFF object")

    machine, section_count, _, symbol_table_offset, symbol_count, optional_size, _ = struct.unpack_from(
        "<HHIIIHH", data, 0
    )
    if machine != 0x14C:
        raise ValueError(f"Unsupported COFF machine 0x{machine:04X}")
    if optional_size != 0:
        raise ValueError(f"Unexpected optional header size {optional_size} in COFF object")

    string_table_offset = symbol_table_offset + symbol_count * 18
    symbols: list[CoffSymbol] = []
    symbol_names: dict[int, str] = {}
    raw_index = 0
    while raw_index < symbol_count:
        offset = symbol_table_offset + raw_index * 18
        if offset + 18 > len(data):
            raise ValueError(f"Truncated COFF symbol table in {path}")
        raw_name, value, section_number, symbol_type, storage_class, auxiliary_count = struct.unpack_from(
            "<8sIhHBB", data, offset
        )
        name = _decode_symbol_name(raw_name, data, string_table_offset)
        weak_external_tag_index = None
        weak_external_characteristics = None
        if storage_class == 105 and auxiliary_count:
            aux_offset = offset + 18
            if aux_offset + 8 <= len(data):
                (
                    weak_external_tag_index,
                    weak_external_characteristics,
                ) = struct.unpack_from("<II", data, aux_offset)
        symbol = CoffSymbol(
            index=raw_index,
            name=name,
            value=value,
            section_number=section_number,
            symbol_type=symbol_type,
            storage_class=storage_class,
            auxiliary_count=auxiliary_count,
            weak_external_tag_index=weak_external_tag_index,
            weak_external_characteristics=weak_external_characteristics,
        )
        symbols.append(symbol)
        symbol_names[raw_index] = name
        raw_index += 1 + auxiliary_count

    section_table_offset = 20 + optional_size
    sections: list[CoffSection] = []
    for zero_based_index in range(section_count):
        offset = section_table_offset + zero_based_index * 40
        raw_name = struct.unpack_from("8s", data, offset)[0]
        name = _decode_section_name(raw_name, data, string_table_offset)
        (
            _,
            _,
            raw_size,
            raw_pointer,
            relocation_pointer,
            _,
            relocation_count,
            _,
            characteristics,
        ) = struct.unpack_from("<IIIIIIHHI", data, offset + 8)

        section_bytes = data[raw_pointer : raw_pointer + raw_size] if raw_size and raw_pointer else b""
        relocations: list[CoffRelocation] = []
        for relocation_index in range(relocation_count):
            relocation_offset = relocation_pointer + relocation_index * 10
            virtual_address, symbol_index, reloc_type = struct.unpack_from("<IIH", data, relocation_offset)
            relocations.append(
                CoffRelocation(
                    offset=virtual_address,
                    symbol_index=symbol_index,
                    reloc_type=reloc_type,
                    width=relocation_width(reloc_type),
                    symbol_name=symbol_names.get(symbol_index, ""),
                )
            )

        sections.append(
            CoffSection(
                name=name,
                data=section_bytes,
                relocations=relocations,
                index=zero_based_index + 1,
                characteristics=characteristics,
            )
        )

    return CoffObject(sections=sections, symbols=symbols)


def _merge_sections(sections: list[CoffSection], name: str) -> CoffSection:
    """Compatibility merge for old callers, rebasing later relocations."""
    data = bytearray()
    relocations: list[CoffRelocation] = []
    characteristics = 0
    for section in sections:
        base = len(data)
        data.extend(section.data)
        characteristics |= section.characteristics
        relocations.extend(
            CoffRelocation(
                offset=base + relocation.offset,
                symbol_index=relocation.symbol_index,
                reloc_type=relocation.reloc_type,
                width=relocation.width,
                symbol_name=relocation.symbol_name,
            )
            for relocation in section.relocations
        )
    return CoffSection(name=name, data=bytes(data), relocations=relocations, characteristics=characteristics)


def load_coff_section(path: Path, section_name: str = ".text") -> CoffSection:
    """Load a section by name while retaining the historical fallback behavior."""
    obj = load_coff_object(path)
    exact = [section for section in obj.sections if section.name == section_name]
    if exact and any(section.data for section in exact):
        return _merge_sections(exact, section_name)

    skip = {".drectve", ".debug$F", ".debug$T", ".debug$S"}
    for preferred in (".xtra", ".text"):
        candidates = [section for section in obj.sections if section.name == preferred and section.data]
        if candidates:
            return _merge_sections(candidates, preferred)
    for section in obj.sections:
        if section.name not in skip and section.data:
            return section
    raise KeyError(f"Section {section_name!r} not found in {path}; available: {[s.name for s in obj.sections]}")


def find_function_symbol(
    obj: CoffObject,
    predicate: Callable[[CoffSymbol], bool] | None = None,
) -> CoffSymbol:
    candidates = [symbol for symbol in obj.symbols if symbol.section_number > 0 and symbol.is_function]
    if predicate is not None:
        preferred = [symbol for symbol in candidates if predicate(symbol)]
        if preferred:
            candidates = preferred
    if not candidates:
        raise KeyError("No defined COFF function symbol found")
    candidates.sort(key=lambda symbol: (symbol.value != 0, symbol.section_number, symbol.value, symbol.index))
    return candidates[0]


def function_symbol_section(obj: CoffObject, symbol: CoffSymbol) -> CoffSection:
    """Return only the selected symbol's section span with relative relocations."""
    section = obj.section_by_index(symbol.section_number)
    end = len(section.data)
    for other in obj.symbols:
        if other.section_number == symbol.section_number and other.is_function and other.value > symbol.value:
            end = min(end, other.value)
    start = symbol.value
    relocations = [
        CoffRelocation(
            offset=relocation.offset - start,
            symbol_index=relocation.symbol_index,
            reloc_type=relocation.reloc_type,
            width=relocation.width,
            symbol_name=relocation.symbol_name,
        )
        for relocation in section.relocations
        if start <= relocation.offset < end
    ]
    return CoffSection(
        name=section.name,
        data=section.data[start:end],
        relocations=relocations,
        index=section.index,
        characteristics=section.characteristics,
    )


def mask_relocations(data: bytes, relocations: list[CoffRelocation]) -> bytes:
    mutable = bytearray(data)
    for relocation in relocations:
        end = min(len(mutable), relocation.offset + relocation.width)
        for index in range(relocation.offset, end):
            mutable[index] = 0
    return bytes(mutable)
