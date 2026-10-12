import hashlib
import json
from pathlib import Path
import struct
import sys
import uuid

import pefile
import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT/'tools'))
from preserved_binary import build_preserved_object
from coff import load_coff_object

MANIFEST = ROOT/'config/drawing_binary.json'
ORIGINAL = ROOT/'orig/empiresx.exe'
pytestmark = pytest.mark.skipif(
    not ORIGINAL.is_file() or not (ROOT / 'orig/age1_x1.pdb').is_file(),
    reason='needs orig/empiresx.exe and orig/age1_x1.pdb')


def output_dir():
    path=ROOT/'build/tests/drawing_binary'/uuid.uuid4().hex
    path.mkdir(parents=True)
    return path


def test_drawing_scope_and_active_owner():
    manifest=json.loads(MANIFEST.read_text())
    config=json.loads((ROOT/'config/executable.json').read_text())
    assert manifest['pdb_module']=='00C9 .\\Asm_draw.obj'
    assert [(s['original_va'],s['size']) for s in manifest['sections']]==[(0x563000,0xABE1),(0x88C000,0x90)]
    assert len(manifest['exports'])==9
    assert 'drawing_binary' not in config
    assert 'src/Asm_draw.asm' in config['assembly_sources']
    assert 'src/Drawarea_asm.asm' in config['assembly_sources']
    pdb=ORIGINAL.parent/'age1_x1.pdb'
    assert hashlib.sha256(pdb.read_bytes()).hexdigest()==manifest['pdb_sha256']


def test_drawing_roundtrip_and_exports():
    manifest=json.loads(MANIFEST.read_text())
    path=output_dir()/'drawing.obj'
    result=build_preserved_object(ORIGINAL,MANIFEST,path)
    assert result['relocations']==4223
    assert not result['source_recovered']
    obj=load_coff_object(path)
    assert not [s for s in obj.symbols if s.section_number==0]
    exports={s.name:s for s in obj.symbols if s.storage_class==2}
    assert set(exports)==set(manifest['exports'])
    pe=pefile.PE(str(ORIGINAL))
    image=pe.get_memory_mapped_image()
    for index,spec in enumerate(manifest['sections']):
        section=obj.sections[index]
        data=bytearray(section.data)
        for relocation in section.relocations:
            target=obj.symbols[relocation.symbol_index]
            assert relocation.reloc_type==6 and target.storage_class==3
            value=struct.unpack_from('<I',data,relocation.offset)[0]+manifest['sections'][target.section_number-1]['original_va']
            struct.pack_into('<I',data,relocation.offset,value)
        start=spec['original_va']-pe.OPTIONAL_HEADER.ImageBase
        assert data==image[start:start+spec['size']]
    for name,va in manifest['exports'].items():
        symbol=exports[name]
        assert symbol.is_function
        assert manifest['sections'][symbol.section_number-1]['original_va']+symbol.value==va


def test_drawing_rejects_changed_operand():
    directory=output_dir()
    manifest=json.loads(MANIFEST.read_text())
    manifest['sections'][0]['relocations'][0]['target_offset']+=1
    bad=directory/'manifest.json'
    bad.write_text(json.dumps(manifest))
    with pytest.raises(ValueError,match='address operand differs'):
        build_preserved_object(ORIGINAL,bad,directory/'drawing.obj')
    assert not (directory/'drawing.obj').exists()
