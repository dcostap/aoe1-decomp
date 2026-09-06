"""Test modern MASM objects with VC5 LINK and the original color operation."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
from datetime import datetime, timezone

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
from coff import load_coff_object
from build_cache import compiler_admission
import pefile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir', default='build/probes/masm')
    args = parser.parse_args()
    output_root = (ROOT / args.output_dir).resolve()
    if not output_root.is_relative_to((ROOT / 'build').resolve()):
        parser.error('Output must be under build/.')
    out = output_root / datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    out.mkdir(parents=True)
    assembler = json.loads((ROOT / 'config/assembly_toolchain.json').read_text())
    ml = Path(assembler['path'])
    if hashlib.sha256(ml.read_bytes()).hexdigest() != assembler['sha256']:
        raise ValueError('Assembler hash differs from the pinned tool.')
    env = {k: v for k, v in os.environ.items() if k.upper() in ('SYSTEMROOT', 'WINDIR', 'TEMP', 'TMP', 'COMSPEC')}
    toolchain = json.loads((ROOT / 'config/toolchain.json').read_text())
    vc = Path(toolchain['compiler']['link']).parent.parent
    env['PATH'] = ';'.join(toolchain['environment']['path_prepend']) + ';' + str(Path(os.environ['SYSTEMROOT']) / 'System32')
    env['INCLUDE'] = ';'.join(toolchain['environment']['include'])
    env['LIB'] = ';'.join(toolchain['environment']['lib'])
    results = []
    def run(args, environment=None):
        with compiler_admission():
            p = subprocess.run([str(x) for x in args], cwd=out, env=environment, capture_output=True, timeout=60)
        results.append({'args': [str(x) for x in args], 'returncode': p.returncode,
                        'stdout': p.stdout.decode(errors='replace'), 'stderr': p.stderr.decode(errors='replace')})
        if p.returncode:
            (out / 'failed_commands.json').write_text(json.dumps(results, indent=2) + '\n')
            raise RuntimeError(results[-1])
    source = ROOT / 'tests/fixtures/masm/probe.asm'
    run([ml] + assembler['flags'] + ['/Foprobe.obj', source])
    obj = load_coff_object(out / 'probe.obj')
    symbol = next(s for s in obj.symbols if s.name == '_ASMSet_Color_Xform')
    section = obj.section_by_index(symbol.section_number)
    code = bytearray(section.data[symbol.value:symbol.value + 23])
    relocs = [r for r in section.relocations if symbol.value <= r.offset < symbol.value + 23]
    assert len(relocs) == 1 and relocs[0].reloc_type == 6
    assert relocs[0].symbol_name == '_probe_color'
    struct.pack_into('<I', code, relocs[0].offset - symbol.value, 0x88C040)
    original_path = ROOT / 'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe'
    original = original_path.read_bytes()
    assert hashlib.sha256(original).hexdigest() == '88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90'
    pe = pefile.PE(data=original)
    expected = pe.get_data(0x56C760 - pe.OPTIONAL_HEADER.ImageBase, 23)
    comparison = {'expected': expected.hex(), 'actual': code.hex(), 'equal': bytes(code) == expected}
    caller = ROOT / 'tests/fixtures/masm/caller.cpp'
    run([toolchain['compiler']['cl'], '@' + str(ROOT / 'config/flags/default.rsp'), '/Focaller.obj', caller], env)
    # Preserve comparison failures too; instruction encoding can differ between assemblers.
    for base in (0x400000, 0x10000000):
        exe = out / ('probe_%08x.exe' % base)
        run([vc / 'Bin/LINK.EXE', '/nologo', '/machine:ix86', '/subsystem:console',
             '/entry:probe_start', '/nodefaultlib', '/fixed:no', '/base:0x%x' % base,
             '/out:' + str(exe), out / 'probe.obj', vc / 'Lib/KERNEL32.LIB'], env)
        run([exe])
        cpp_exe = out / ('probe_cpp_%08x.exe' % base)
        run([toolchain['compiler']['link'], '/nologo', '/subsystem:console', '/fixed:no', '/base:0x%x' % base,
             '/out:' + str(cpp_exe), out / 'caller.obj', out / 'probe.obj', 'kernel32.lib'], env)
        run([cpp_exe])
    report = {'assembler': str(ml), 'assembler_sha256': hashlib.sha256(ml.read_bytes()).hexdigest(),
              'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
              'caller_sha256': hashlib.sha256(caller.read_bytes()).hexdigest(),
              'mmx_and_x87_test': True, 'vc5_thiscall_test': True,
              'comparison': comparison, 'test_inputs_per_image': 65536, 'commands': results}
    (out / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({'instruction_bytes_equal': comparison['equal'], 'linked_and_ran_images': 4,
                      'mmx_and_x87_test': True, 'vc5_thiscall_test': True, 'report': str(out / 'report.json')}, indent=2))

if __name__ == '__main__':
    main()
