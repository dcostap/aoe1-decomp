"""Test the approved drawing binary with VC5 at two image bases."""
from __future__ import annotations
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess

from build_cache import compiler_admission
from common import REPO_ROOT, load_toolchain, tool_env
from preserved_binary import build_preserved_object


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir', default='build/probes/drawing_binary')
    args = parser.parse_args()
    root = (REPO_ROOT/args.output_dir).resolve()
    if not root.is_relative_to((REPO_ROOT/'build').resolve()):
        parser.error('Output must be under build/.')
    output = root/datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')
    output.mkdir(parents=True)
    executable = json.loads((REPO_ROOT/'config/executable.json').read_text())
    obj = output/'drawing.obj'
    dependency = build_preserved_object(REPO_ROOT/executable['original'], REPO_ROOT/'config/drawing_binary.json', obj)
    toolchain = load_toolchain()
    commands, fixtures = [], []

    def run(command):
        with compiler_admission():
            result = subprocess.run([str(x) for x in command], cwd=output, env=tool_env(toolchain),
                                    capture_output=True, text=True, timeout=60)
        row = dict(command=[str(x) for x in command], returncode=result.returncode,
                   stdout=result.stdout, stderr=result.stderr)
        commands.append(row)
        (output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if result.returncode:
            raise RuntimeError(row)

    for index, name in enumerate(('drawing_setup','drawing_hline','drawing_sprite')):
        source = REPO_ROOT/('tests/fixtures/masm/'+name+'.cpp')
        fixtures.append(dict(source=str(source),sha256=hashlib.sha256(source.read_bytes()).hexdigest()))
        run([toolchain['compiler']['cl'],'@'+str(REPO_ROOT/'config/flags/default.rsp'),'/Focaller.obj',source])
        for base in (0x400000,0x10000000):
            exe = output/('native_%d_%08x.exe'%(index,base))
            run([toolchain['compiler']['link'],'/nologo','/subsystem:console','/fixed:no',
                 '/base:0x%x'%base,'/out:'+str(exe),'caller.obj',obj,'kernel32.lib'])
            run([exe])
    report = dict(dependency=dependency,fixtures=fixtures,commands=commands,
                  image_bases=[0x400000,0x10000000],native_tests_passed=True)
    (output/'report.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(native_tests_passed=True,report=str(output/'report.json')),indent=2))


if __name__=='__main__':
    main()
