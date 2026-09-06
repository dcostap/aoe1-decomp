"""Check recovered drawing assembly bytes, private state, and native calls."""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import struct
import subprocess
from types import SimpleNamespace

import pefile
from build_assembly import assemble_source
from build_cache import compiler_admission
from coff import load_coff_object
from common import REPO_ROOT, function_entries_by_va, load_toolchain, tool_env


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir', default='build/probes/asm_draw')
    parser.add_argument('--manifest', default='config/asm_draw.json')
    parser.add_argument('--fixture', choices=('manifest', 'setup', 'copy', 'pattern'), default='manifest')
    args = parser.parse_args()
    root = (REPO_ROOT / args.output_dir).resolve()
    if not root.is_relative_to((REPO_ROOT / 'build').resolve()):
        parser.error('Output must be under build/.')
    output = root / datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    output.mkdir(parents=True)
    manifest_path = REPO_ROOT / args.manifest
    manifest = json.loads(manifest_path.read_text())
    executable = json.loads((REPO_ROOT / 'config/executable.json').read_text())
    raw = (REPO_ROOT / executable['original']).read_bytes()
    assert hashlib.sha256(raw).hexdigest() == executable['original_sha256']
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    obj_path = output / 'drawing.obj'
    build = assemble_source(REPO_ROOT / manifest['source'], obj_path)
    assert build['compiled'], build
    obj = load_coff_object(obj_path)
    symbols = {s.name: s for s in obj.symbols}
    by_index = {s.index: s for s in obj.symbols}
    # MASM omits unused local labels. Locate their data from a retained label.
    # The complete initializer and relocation comparison still checks every byte.
    for name, data in manifest['data'].items():
        if name not in symbols and 'object_anchor' in data:
            anchor = data['object_anchor']
            origin = symbols[anchor['symbol']]
            value = origin.value+anchor['offset']
            assert value >= 0
            symbols[name] = SimpleNamespace(name=name, value=value, section_number=origin.section_number)
    bodies = {**manifest['functions'], **manifest.get('codelets', {})}
    objects = {**manifest['data'], **bodies}
    external = manifest.get('external_functions', {})
    registry = function_entries_by_va()
    for name, va in external.items():
        assert registry['%08X' % va]['symbol'] == name, name
    addresses = {name: item['va'] for name, item in objects.items()}
    addresses.update(manifest.get('labels', {}))
    addresses.update(external)

    def normalize(symbol, size, va):
        section = obj.section_by_index(symbol.section_number)
        actual = bytearray(section.data[symbol.value:symbol.value+size])
        for relocation in section.relocations:
            if not symbol.value <= relocation.offset < symbol.value+size:
                continue
            target = by_index[relocation.symbol_index]
            assert target.name in addresses, target.name
            offset = relocation.offset-symbol.value
            addend = struct.unpack_from('<i', actual, offset)[0]
            if target.name in objects:
                assert 0 <= addend < objects[target.name]['size']
            else:
                assert addend == 0
            value = addresses[target.name]+addend
            if relocation.reloc_type == 20:
                assert target.name in bodies or target.name in external
                value -= va+offset+4
            else:
                assert relocation.reloc_type == 6
            struct.pack_into('<I', actual, offset, value & 0xffffffff)
        return actual

    rows = []
    for name, data in manifest['data'].items():
        symbol = symbols[name]
        actual = normalize(symbol, data['size'], data['va'])
        expected = image[data['va']-base:data['va']-base+data['size']]
        assert actual == expected, name
    for name, function in bodies.items():
        symbol = symbols[name]
        section = obj.section_by_index(symbol.section_number)
        ends = [s.value for s in obj.symbols if s.section_number == symbol.section_number and
                s.name in objects and s.value > symbol.value]
        end = min(ends) if ends else len(section.data)
        actual = normalize(symbol, end-symbol.value, function['va'])
        expected = image[function['va']-base:function['va']-base+function['size']]
        equal = actual == expected
        rows.append(dict(symbol=name, original_va=function['va'], expected_size=len(expected),
                         actual_size=len(actual), bytes_equal=equal))
        assert equal, rows[-1]
    toolchain = load_toolchain()
    commands = []
    def run(command):
        with compiler_admission():
            result = subprocess.run([str(x) for x in command], cwd=output, env=tool_env(toolchain),
                                    capture_output=True, text=True, timeout=60)
        commands.append(dict(command=[str(x) for x in command], returncode=result.returncode,
                             stdout=result.stdout, stderr=result.stderr))
        (output / 'commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        assert result.returncode == 0, commands[-1]
    source = REPO_ROOT / manifest.get('test_source', 'tests/fixtures/masm/drawing_setup.cpp')
    input_sets = manifest.get('input_sets_per_image',65536)
    defines = []
    test_objects = []
    test_assemblies = []
    if args.fixture == 'setup':
        source = REPO_ROOT / 'tests/fixtures/masm/drawing_setup.cpp'
        input_sets = 65536
    elif args.fixture in ('copy', 'pattern'):
        source = REPO_ROOT / ('tests/fixtures/masm/drawing_%s.cpp' % args.fixture)
        input_sets = 8212 if args.fixture == 'copy' else 16416
        table_define, table_name = ('TEST_COPY_FROM_HLINE', 'plain_copy_table') if args.fixture == 'copy' else (
            'TEST_PATTERN_FROM_HLINE', 'pattern_fill_table')
        for define, target_name, base_name in (
            (table_define, table_name, '_ASMDraw_HLine'),
            ('TEST_RESUME_FROM_COLOR', 'draw_resume', 'color_xform'),
        ):
            target, origin = symbols[target_name], symbols[base_name]
            assert target.section_number == origin.section_number
            section = obj.section_by_index(target.section_number)
            assert not section.characteristics & 0x1000, 'Test offsets require a contiguous, non-COMDAT section.'
            defines.append('/D%s=%d' % (define, target.value-origin.value))
        adapter = output / 'invoke_codelet.obj'
        adapter_build = assemble_source(REPO_ROOT / 'tests/fixtures/masm/invoke_codelet.asm', adapter)
        assert adapter_build['compiled'], adapter_build
        test_assemblies.append(adapter_build)
        test_objects.append(adapter)
    run([toolchain['compiler']['cl'], '@' + str(REPO_ROOT / 'config/flags/default.rsp'),
         *defines, '/Focaller.obj', source])
    for address in (0x400000, 0x10000000):
        exe = output / ('drawing_%08x.exe' % address)
        run([toolchain['compiler']['link'], '/nologo', '/subsystem:console', '/fixed:no',
             '/base:0x%x' % address, '/out:' + str(exe), 'caller.obj', obj_path, *test_objects, 'kernel32.lib'])
        run([exe])
    functions = [row for row in rows if row['symbol'] in manifest['functions']]
    codelets = [row for row in rows if row['symbol'] not in manifest['functions']]
    report = dict(build=build, functions=functions, codelets=codelets, private_data_initializers_equal=True,
                  input_sets_per_image=input_sets, image_bases=[0x400000,0x10000000], test_assemblies=test_assemblies,
                  manifest_sha256=hashlib.sha256(manifest_path.read_bytes()).hexdigest(),
                  test_source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(), commands=commands)
    (output / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(dict(functions=len(functions), codelets=len(codelets), instruction_bytes_equal=True, native_tests=True,
                         report=str(output / 'report.json')), indent=2))


if __name__ == '__main__':
    main()
