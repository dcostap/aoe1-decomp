from __future__ import annotations

import struct
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class CoffRelocation:
    offset: int
    symbol_index: int
    reloc_type: int
    width: int


@dataclass(frozen=True)
class CoffSection:
    name: str
    data: bytes
    relocations: list[CoffRelocation]


def _decode_name(raw_name: bytes) -> str:
    return raw_name.split(b"\x00", 1)[0].decode("ascii", errors="replace")


def relocation_width(reloc_type: int) -> int:
    width_map = {
        0x0006: 4,  # IMAGE_REL_I386_DIR32
        0x0007: 4,  # IMAGE_REL_I386_DIR32NB
        0x000A: 2,  # IMAGE_REL_I386_SECTION
        0x000B: 4,  # IMAGE_REL_I386_SECREL
        0x0014: 4,  # IMAGE_REL_I386_REL32
    }
    return width_map.get(reloc_type, 4)


def _load_all_sections(path: Path) -> dict[str, CoffSection]:
    """Load all COFF sections from a COFF object file, returning a dict by name."""
    data = path.read_bytes()
    if len(data) < 20:
        raise ValueError(f"{path} is too small to be a COFF object")

    machine, number_of_sections, _, pointer_to_symbol_table, _, optional_header_size, _ = struct.unpack_from(
        "<HHIIIHH", data, 0
    )
    if machine != 0x14C:
        raise ValueError(f"Unsupported COFF machine 0x{machine:04X}")
    if optional_header_size != 0:
        raise ValueError(f"Unexpected optional header size {optional_header_size} in COFF object")

    section_table_offset = 20
    sections: dict[str, CoffSection] = {}
    for index in range(number_of_sections):
        offset = section_table_offset + index * 40
        raw_name = struct.unpack_from("8s", data, offset)[0]
        name = _decode_name(raw_name)

        (
            _,
            _,
            size_of_raw_data,
            pointer_to_raw_data,
            pointer_to_relocations,
            _,
            number_of_relocations,
            _,
        ) = struct.unpack_from("<IIIIIIII", data, offset + 8)

        if size_of_raw_data and pointer_to_raw_data:
            section_bytes = data[pointer_to_raw_data : pointer_to_raw_data + size_of_raw_data]
        else:
            section_bytes = b""

        relocations: list[CoffRelocation] = []
        for reloc_index in range(number_of_relocations):
            reloc_offset = pointer_to_relocations + reloc_index * 10
            virtual_address, symbol_index, reloc_type = struct.unpack_from("<IIH", data, reloc_offset)
            relocations.append(
                CoffRelocation(
                    offset=virtual_address,
                    symbol_index=symbol_index,
                    reloc_type=reloc_type,
                    width=relocation_width(reloc_type),
                )
            )

        if name in sections:
            # Name collision — append relocations to existing section
            existing = sections[name]
            sections[name] = CoffSection(
                name=name,
                data=existing.data + section_bytes,
                relocations=existing.relocations + relocations,
            )
        else:
            sections[name] = CoffSection(name=name, data=section_bytes, relocations=relocations)

    return sections


def load_coff_section(path: Path, section_name: str = ".text") -> CoffSection:
    """Load a COFF section by name.


    Priority when looking for .text code fallback:
    1. .xtra (used by VC5 for pragma alloc_text stubs, contains actual code)
    2. .text (standard code section)
    3. Any other non-metadata, non-empty section

    This handles two VC5 pragma alloc_text edge cases:
    (a) .text section is absent → fall through to .xtra
    (b) .text section is present but empty → prefer .xtra over empty .text
    """
    sections = _load_all_sections(path)
    if section_name in sections:
        return sections[section_name]

    # Fallback order: .xtra (pragma stubs) > .text (standard) > other non-metadata
    skip = {".drectve", ".debug$F", ".debug$T", ".debug$S"}
    # Try .xtra first (VC5 pragma stub code section)
    if ".xtra" in sections and sections[".xtra"].data:
        return sections[".xtra"]
    # Then .text (may be present but empty for pragma stubs)
    if ".text" in sections and sections[".text"].data:
        return sections[".text"]
    # Last resort: first non-metadata section with data
    for name, sec in sections.items():
        if name not in skip and sec.data:
            return sec
    available = list(sections.keys())
    raise KeyError(f"Section {section_name!r} not found in {path}; available sections: {available}")


def mask_relocations(data: bytes, relocations: list[CoffRelocation]) -> bytes:
    mutable = bytearray(data)
    for reloc in relocations:
        end = min(len(mutable), reloc.offset + reloc.width)
        for index in range(reloc.offset, end):
            mutable[index] = 0
    return bytes(mutable)
