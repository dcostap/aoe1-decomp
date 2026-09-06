from __future__ import annotations

import hashlib
import json
from pathlib import Path
import struct
import sys
import uuid

import pefile
import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
from coff import load_coff_object
from compression_binary import build_compression_object

MANIFEST = ROOT / 'config/compression_binary.json'
ORIGINAL = ROOT / 'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe'


def output_dir():
    path = ROOT / 'build/tests/compression_binary' / uuid.uuid4().hex
    path.mkdir(parents=True)
    return path


def test_preserved_compression_object_roundtrip():
    manifest = json.loads(MANIFEST.read_text())
    obj_path = output_dir() / 'compression.obj'
    result = build_compression_object(ORIGINAL, MANIFEST, obj_path)
    assert result['source_recovered'] is False
    assert result['relocations'] == 565
    assert result['object_sha256'] == manifest['object_sha256']
    obj = load_coff_object(obj_path)
    assert not [s for s in obj.symbols if s.section_number == 0]
    exports = {s.name: s for s in obj.symbols if s.storage_class == 2}
    assert set(exports) == set(manifest['exports'])
    pe = pefile.PE(str(ORIGINAL))
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    for index, spec in enumerate(manifest['sections']):
        section = obj.sections[index]
        restored = bytearray(section.data or bytes(spec['size']))
        for relocation in section.relocations:
            assert relocation.reloc_type == 6
            target = obj.symbols[relocation.symbol_index]
            assert target.storage_class == 3
            target_va = manifest['sections'][target.section_number - 1]['original_va']
            value = struct.unpack_from('<I', restored, relocation.offset)[0] + target_va
            struct.pack_into('<I', restored, relocation.offset, value)
        va = spec['original_va']
        assert restored == image[va-base:va-base+spec['size']]
    for name, address in manifest['exports'].items():
        symbol = exports[name]
        assert symbol.is_function
        assert manifest['sections'][symbol.section_number-1]['original_va'] + symbol.value == address


def test_preservation_scope_is_only_compression():
    manifest = json.loads(MANIFEST.read_text())
    assert {r['module'] for r in manifest['pdb_contributions']} == {0xF6, 0xF7}
    assert [(s['original_va'], s['size']) for s in manifest['sections']] == [
        (0x5479A0, 0x37E6), (0x58EF30, 0xC18), (0x886C60, 0x134C), (0x88D000, 0xAD90)]
    assert hashlib.sha256((ROOT / 'orig/age1_x1.pdb').read_bytes()).hexdigest() == manifest['pdb_sha256']
    assert set(manifest['exports']) == {'_deflate_data', '_deflate_init', '_deflate_deinit',
                                       '_deflate_buf_size', '_Inf32BufSize', '_Inf32Decode'}


def test_rejects_wrong_original():
    directory = output_dir()
    bad = directory / 'wrong.exe'
    bad.write_bytes(b'wrong input')
    with pytest.raises(ValueError, match='original hash differs'):
        build_compression_object(bad, MANIFEST, directory / 'output.obj')
    assert not (directory / 'output.obj').exists()


def test_rejects_invalid_relocation():
    directory = output_dir()
    manifest = json.loads(MANIFEST.read_text())
    manifest['sections'][0]['relocations'][0]['offset'] = -1
    bad = directory / 'manifest.json'
    bad.write_text(json.dumps(manifest))
    with pytest.raises(ValueError, match='relocation outside section'):
        build_compression_object(ORIGINAL, bad, directory / 'output.obj')
    assert not (directory / 'output.obj').exists()
