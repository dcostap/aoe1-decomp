"""Build a relocatable COFF object for an explicitly approved binary dependency.

The reviewed manifest supplies ownership, payload hashes, and relocation fields.
This tool does not select ranges or discover relocations.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import struct

import pefile


def build_preserved_object(original: Path, manifest_path: Path, output: Path) -> dict:
    manifest_bytes = manifest_path.read_bytes()
    manifest = json.loads(manifest_bytes)
    raw = original.read_bytes()
    if hashlib.sha256(raw).hexdigest() != manifest['original_sha256']:
        raise ValueError('Preserved dependency: original hash differs.')
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    specs = manifest['sections']
    sections = []
    relocation_count = 0
    for spec in specs:
        va, size = spec['original_va'], spec['size']
        original_data = image[va-base:va-base+size]
        if len(original_data) != size or hashlib.sha256(original_data).hexdigest() != spec['original_sha256']:
            raise ValueError('Preserved dependency: section payload differs.')
        data = bytearray(original_data)
        relocs = []
        used = set()
        for relocation in spec['relocations']:
            offset = relocation['offset']
            target = relocation['target_section']
            addend = relocation['target_offset']
            if not 0 <= offset <= size - 4 or not 0 <= target < len(specs):
                raise ValueError('Preserved dependency: relocation outside section.')
            if not 0 <= addend < specs[target]['size'] or any(i in used for i in range(offset, offset+4)):
                raise ValueError('Preserved dependency: invalid or overlapping relocation.')
            used.update(range(offset, offset+4))
            expected = specs[target]['original_va'] + addend
            if struct.unpack_from('<I', data, offset)[0] != expected:
                raise ValueError('Preserved dependency: original address operand differs.')
            struct.pack_into('<I', data, offset, addend)
            relocs.append((offset, target, 6))  # IMAGE_REL_I386_DIR32
        restored = bytearray(data)
        for offset, target, _ in relocs:
            value = struct.unpack_from('<I', restored, offset)[0] + specs[target]['original_va']
            struct.pack_into('<I', restored, offset, value)
        if restored != original_data:
            raise ValueError('Preserved dependency: original-address round trip failed.')
        flags = spec['characteristics']
        if flags & 0x80 and any(data):
            raise ValueError('Preserved dependency: nonzero uninitialized data.')
        sections.append((spec['name'].encode('ascii'), data, relocs, flags))
        relocation_count += len(relocs)
    symbols = [(('$cmp%d' % i), 0, i+1, 0, 3) for i in range(len(sections))]
    for name, address in manifest['exports'].items():
        owners = [i for i,s in enumerate(specs) if s['original_va'] <= address < s['original_va'] + s['size']]
        if len(owners) != 1 or not specs[owners[0]]['characteristics'] & 0x20:
            raise ValueError('Preserved dependency: export has no unique code owner.')
        index = owners[0]
        symbols.append((name, address-specs[index]['original_va'], index+1, 0x20, 2))
    payload = bytearray(20 + 40 * len(sections))
    headers = []
    for name, data, relocs, flags in sections:
        raw_offset = 0 if flags & 0x80 else len(payload)
        if raw_offset:
            payload.extend(data)
        reloc_offset = len(payload) if relocs else 0
        for relocation in relocs:
            payload.extend(struct.pack('<IIH', *relocation))
        headers.append(struct.pack('<8sIIIIIIHHI', name, 0, 0, len(data), raw_offset, reloc_offset, 0, len(relocs), 0, flags))
    symbol_offset = len(payload)
    strings = bytearray(4)
    for name, value, section, kind, storage in symbols:
        encoded = name.encode('ascii')
        if len(encoded) > 8:
            symbol_name = struct.pack('<II', 0, len(strings))
            strings.extend(encoded + b'\0')
        else:
            symbol_name = encoded.ljust(8, b'\0')
        payload.extend(struct.pack('<8sIhHBB', symbol_name, value, section, kind, storage, 0))
    struct.pack_into('<I', strings, 0, len(strings))
    payload.extend(strings)
    struct.pack_into('<HHIIIHH', payload, 0, 0x14c, len(sections), 0, symbol_offset, len(symbols), 0, 0)
    payload[20:20+40*len(sections)] = b''.join(headers)
    digest = hashlib.sha256(payload).hexdigest()
    if digest != manifest['object_sha256'] or relocation_count != manifest['absolute_relocations']:
        raise ValueError('Preserved dependency: object differs from the validated probe.')
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(payload)
    return dict(object=str(output), object_sha256=digest, manifest=str(manifest_path),
                manifest_sha256=hashlib.sha256(manifest_bytes).hexdigest(),
                original_sha256=manifest['original_sha256'], relocations=relocation_count,
                exports=list(manifest['exports']), source_recovered=False)
