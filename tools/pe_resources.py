"""Compile the resource script and read PE resources for comparison."""

from __future__ import annotations

import hashlib
import struct
import subprocess
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


RT_ICON = 3
RT_GROUP_ICON = 14


def extract_icon(executable: Path, group_name: str, destination: Path, expected_sha256: str) -> dict:
    """Write one group icon from an installed game EXE as an .ico file."""
    with pefile.PE(str(executable)) as pe:
        entries = {}
        root = getattr(pe, "DIRECTORY_ENTRY_RESOURCE", None)
        for type_entry in root.entries if root is not None else ():
            for name_entry in type_entry.directory.entries:
                name = str(name_entry.name) if name_entry.name is not None else name_entry.id
                leaf = name_entry.directory.entries[0].data.struct
                entries[type_entry.id, name] = pe.get_data(leaf.OffsetToData, leaf.Size)
    group = entries.get((RT_GROUP_ICON, group_name))
    if group is None:
        raise ValueError(f"{executable} has no {group_name} icon group.")
    count = struct.unpack_from("<HHH", group)[2]
    images = []
    for index in range(count):
        fields = struct.unpack_from("<BBBBHHIH", group, 6 + 14 * index)
        images.append((fields[:7], entries[RT_ICON, fields[7]]))
    payload = bytearray(struct.pack("<HHH", 0, 1, count))
    offset = 6 + 16 * count
    for fields, data in images:
        payload.extend(struct.pack("<BBBBHHII", *fields, offset))
        offset += len(data)
    for _, data in images:
        payload.extend(data)
    digest = hashlib.sha256(payload).hexdigest()
    if digest != expected_sha256:
        raise ValueError(f"{group_name} icon from {executable} differs from the pinned icon.")
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_bytes(payload)
    return dict(source=str(executable), icon=str(destination), sha256=digest)


def compile_resources(rc: Path, script: Path, include_dir: Path, destination: Path,
                      env: dict[str, str]) -> dict:
    command = [str(rc), "/r", "/i", str(include_dir), "/fo", str(destination), str(script)]
    result = subprocess.run(command, cwd=script.parent, capture_output=True, text=True, env=env)
    return dict(script=str(script), command=command, returncode=result.returncode,
                stdout=result.stdout, stderr=result.stderr,
                compiled=result.returncode == 0 and destination.is_file())
