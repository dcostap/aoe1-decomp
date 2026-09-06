"""Preserve original PE resources as a Win32 .res input for the linker."""

from __future__ import annotations

import struct
from pathlib import Path

import pefile


def align4(data: bytes) -> bytes:
    return data + b"\0" * (-len(data) % 4)


def resource_name(value: int | str) -> bytes:
    if isinstance(value, int):
        if not 0 <= value <= 0xFFFF:
            raise ValueError(f"Resource ID is outside the Win32 range: {value}")
        return struct.pack("<HH", 0xFFFF, value)
    return value.encode("utf-16-le") + b"\0\0"


def resource_record(kind: int | str, name: int | str, language: int, data: bytes) -> bytes:
    names = align4(resource_name(kind) + resource_name(name))
    # PE resources do not retain .res allocation flags. MOVEABLE | PURE is
    # conventional linker input metadata; payload, IDs, and languages stay exact.
    header_size = 8 + len(names) + 16
    header = struct.pack("<II", len(data), header_size) + names
    header += struct.pack("<IHHII", 0, 0x30, language, 0, 0)
    return header + align4(data)


def extract_resources(original: Path, destination: Path) -> list[dict]:
    records = []
    # A .res file starts with the null resource header.
    payload = bytearray(struct.pack("<IIHHHHIHHII", 0, 32, 0xFFFF, 0, 0xFFFF, 0,
                                    0, 0, 0, 0, 0))
    with pefile.PE(str(original)) as pe:
        root = getattr(pe, "DIRECTORY_ENTRY_RESOURCE", None)
        for type_entry in root.entries if root is not None else ():
            kind = str(type_entry.name) if type_entry.name is not None else type_entry.id
            for name_entry in type_entry.directory.entries:
                name = str(name_entry.name) if name_entry.name is not None else name_entry.id
                for language_entry in name_entry.directory.entries:
                    leaf = language_entry.data.struct
                    data = pe.get_data(leaf.OffsetToData, leaf.Size)
                    if len(data) != leaf.Size:
                        raise ValueError(f"Truncated resource: {kind}/{name}")
                    language = language_entry.id
                    payload.extend(resource_record(kind, name, language, data))
                    records.append(dict(type=kind, name=name, language=language, size=len(data)))
    destination.write_bytes(payload)
    return records
