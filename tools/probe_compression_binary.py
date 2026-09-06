"""Compile and run the isolated compression binary dependency with VC5."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import zlib
from datetime import datetime, timezone
from compression_binary import build_compression_object
from build_cache import compiler_admission

ROOT = Path(__file__).resolve().parents[1]

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir', default='build/probes/compression')
    args = parser.parse_args()
    output_root = (ROOT / args.output_dir).resolve()
    if not output_root.is_relative_to((ROOT / 'build').resolve()):
        parser.error('Output must be under build/.')
    OUT = output_root / datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    OUT.mkdir(parents=True)
    build_compression_object(ROOT / 'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe',
                             ROOT / 'config/compression_binary.json', OUT / 'compression.obj')
    toolchain = json.loads((ROOT / 'config/toolchain.json').read_text())
    env = {k:v for k,v in os.environ.items() if k.upper() in ('SYSTEMROOT','WINDIR','TEMP','TMP','COMSPEC')}
    env['PATH'] = ';'.join(toolchain['environment']['path_prepend']) + ';' + str(Path(os.environ['SYSTEMROOT']) / 'System32')
    env['INCLUDE'] = ';'.join(toolchain['environment']['include'])
    env['LIB'] = ';'.join(toolchain['environment']['lib'])
    commands = []
    def run(args):
        with compiler_admission():
            p = subprocess.run([str(a) for a in args], cwd=OUT, env=env, capture_output=True, timeout=60)
        commands.append(dict(args=[str(a) for a in args], returncode=p.returncode, stdout=p.stdout.decode(errors='replace'), stderr=p.stderr.decode(errors='replace')))
        (OUT / 'compression_test_commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if p.returncode:
            raise RuntimeError(commands[-1])
    source = ROOT / 'tests/fixtures/compression_binary/compression_test.c'
    run([toolchain['compiler']['cl'], '@' + str(ROOT / 'config/flags/default.rsp'),
         '/Focompression_test.obj', source])
    runs = []
    for base in (0x400000, 0x10000000):
        exe = 'compression_test_%08x.exe' % base
        run([toolchain['compiler']['link'], '/nologo', '/subsystem:console', '/fixed:no', '/base:0x%x' % base,
             '/out:' + exe, 'compression_test.obj', 'compression.obj', 'kernel32.lib'])
        run([OUT / exe])
        fixtures = []
        for index in range(24):
            raw = (OUT / ('fixture_%02d.raw' % index)).read_bytes()
            packed = (OUT / ('fixture_%02d.deflate' % index)).read_bytes()
            assert zlib.decompress(packed, -15) == raw
            fixtures.append(dict(index=index, raw_size=len(raw), packed_size=len(packed), sha256=hashlib.sha256(packed).hexdigest()))
        game = ROOT / 'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/data2/empires.dat'
        expected = zlib.decompress(game.read_bytes(), -15)
        (OUT / 'game_expected.raw').write_bytes(expected)
        run([OUT / exe, game, OUT / 'game_expected.raw'])
        for level in (0, 1, 6, 9):
            encoder = zlib.compressobj(level, zlib.DEFLATED, -15)
            encoded = encoder.compress(expected) + encoder.flush()
            fixture = OUT / ('zlib_level%d.deflate' % level)
            fixture.write_bytes(encoded)
            run([OUT / exe, fixture, OUT / 'game_expected.raw'])
        runs.append(dict(image_base=base, fixtures=fixtures))
    assert runs[0]['fixtures'] == runs[1]['fixtures']
    result = dict(runs=runs, source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
                  original_decoder_roundtrip=True, independent_zlib_decode=True, output_identical_at_two_bases=True,
                  original_game_data_decoded_bytes=len(expected), independent_zlib_encoder_levels=[0,1,6,9])
    (OUT / 'compression_test_report.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(cases_per_image=24, images=2, original_decoder_roundtrip=True,
                         independent_zlib_decode=True, report=str(OUT / 'compression_test_report.json')),indent=2))

if __name__ == '__main__':
    main()
