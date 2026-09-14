"""Build, prepare, and run the original or rebuilt game with one asset source."""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import urllib.request
import zipfile

from prepare_runtime import DEFAULT_SOURCE, ORIGINAL_SHA256, digest, prepare

ROOT = Path(__file__).resolve().parents[1]
STATE = ROOT / "build/game"
ORIGINAL = ROOT / "orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe"
DEFAULT_ARGUMENTS = ["NOSTARTUP", "GAMECD"]


def stamp():
    return datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S%fZ")


def save_selection(path, value):
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(mode='w', encoding='utf-8', dir=path.parent,
                                         delete=False) as file:
            temporary = Path(file.name)
            json.dump(value, file, indent=2)
            file.write('\n')
        os.replace(temporary, path)
    finally:
        if temporary:
            temporary.unlink(missing_ok=True)


def dependencies():
    return json.loads((ROOT / "config/harness/dependencies.json").read_text())["cnc_ddraw"]


def wrapper_path():
    return ROOT / "build/deps" / ("cnc-ddraw-v" + dependencies()["version"]) / "ddraw.dll"


def setup():
    dep = dependencies()
    dll = wrapper_path()
    dll.parent.mkdir(parents=True, exist_ok=True)
    if not dll.exists() or digest(dll) != dep["dll_sha256"]:
        archive = dll.parent / "cnc-ddraw.zip"
        with urllib.request.urlopen(dep["url"], timeout=60) as response:
            payload = response.read()
        if hashlib.sha256(payload).hexdigest() != dep["archive_sha256"]:
            raise ValueError("Graphics download hash differs from the pinned archive.")
        archive.write_bytes(payload)
        with zipfile.ZipFile(archive) as package:
            dll.write_bytes(package.read("ddraw.dll"))
        if digest(dll) != dep["dll_sha256"]:
            raise ValueError("Graphics DLL hash differs from the pinned DLL.")
    env = ROOT / "build/harness-env"
    python = env / "Scripts/python.exe"
    if not python.exists():
        subprocess.run([sys.executable, "-m", "venv", str(env)], check=True)
    subprocess.run([str(python), "-m", "pip", "install", "-r",
                    str(ROOT / "tools/harness/requirements.txt")], check=True)
    print("Harness dependencies ready.")


def run_worker(command, log, timeout, visible):
    if visible:
        command = [*command, '--visible']
    else:
        command = [str(ROOT / 'build/harness-env/Scripts/python.exe'),
                   str(ROOT / 'tools/harness/hidden.py'), '--log', str(log),
                   '--timeout', str(timeout), '--', *command]
    return subprocess.run(command, cwd=ROOT).returncode


def validate_build(exe: Path):
    exe = exe.resolve()
    report = json.loads(exe.with_name("report.json").read_text())
    if not report.get("linked") or report.get("artifact_sha256", {}).get(exe.name) != digest(exe):
        raise ValueError("EXE does not match a successful build report.")
    return exe


def override_asset(runtime: Path, relative: Path, source: Path):
    runtime = runtime.resolve()
    destination = (runtime / relative).resolve()
    if not runtime.is_relative_to((ROOT / 'build/runtime').resolve()) or \
            relative.is_absolute() or not destination.is_relative_to(runtime):
        raise ValueError('Override destination must stay inside a prepared runtime.')
    if destination.suffix.lower() not in ('.drs', '.wav', '.avi', '.dat', '.ai', '.per', '.scn'):
        raise ValueError('Only game assets can be overridden. Select EXEs through --exe.')
    manifest_path = runtime / 'runtime_manifest.json'
    manifest = json.loads(manifest_path.read_text())
    destination.parent.mkdir(parents=True, exist_ok=True)
    temporary = None
    try:
        with tempfile.NamedTemporaryFile(dir=destination.parent, delete=False) as file:
            temporary = Path(file.name)
        shutil.copyfile(source, temporary)
        expected = digest(source)
        if digest(temporary) != expected:
            raise ValueError('Override copy verification failed.')
        os.replace(temporary, destination)  # Replace the link, never write through it.
    finally:
        if temporary is not None:
            temporary.unlink(missing_ok=True)
    manifest.setdefault('overrides', {})[relative.as_posix()] = {
        'source': str(source.resolve()), 'sha256': expected}
    manifest_path.write_text(json.dumps(manifest, indent=2) + '\n')
    print(f'Private override: {destination}')


def build():
    output = ROOT / "build/executable/user" / stamp()
    subprocess.run([sys.executable, str(ROOT / "tools/build_executable.py"),
                    "--output-dir", str(output)], cwd=ROOT, check=True)
    reports = list(output.glob("*/report.json"))
    if len(reports) != 1:
        raise ValueError("Expected one new build report.")
    return validate_build(reports[0].with_name("empiresx.exe"))


def stage(target: str, exe: Path | None = None, *, graphics="cnc-ddraw", assets="hardlink"):
    if target == "original":
        exe = ORIGINAL
        if digest(exe) != ORIGINAL_SHA256:
            raise ValueError("Original EXE hash differs from the pinned beta.")
    else:
        if exe is None:
            pointer = STATE / "rebuilt.json"
            if not pointer.exists():
                raise ValueError("No selected rebuilt EXE. Run game.cmd build, or supply --exe.")
            exe = Path(json.loads(pointer.read_text())["exe"])
        exe = validate_build(exe)
    if graphics == "cnc-ddraw":
        if not wrapper_path().exists() or digest(wrapper_path()) != dependencies()["dll_sha256"]:
            raise ValueError("Pinned graphics DLL is missing. Run game.cmd setup.")
    output = ROOT / "build/runtime" / f"{target}-{stamp()}"
    report = prepare(DEFAULT_SOURCE, exe, output, assets=assets)
    if graphics == "cnc-ddraw":
        shutil.copy2(wrapper_path(), output / "ddraw.dll")
        shutil.copy2(ROOT / "config/harness/ddraw.ini", output / "ddraw.ini")
        report["compat_layer"] = ""
        report["graphics_sha256"] = digest(output / "ddraw.dll")
        report["graphics_config_sha256"] = digest(output / "ddraw.ini")
    report["graphics"] = graphics
    report["game_arguments"] = DEFAULT_ARGUMENTS
    # This launcher changes only its own environment and working directory.
    (output / "Launch.cmd").write_bytes((
        '@echo off\r\nsetlocal\r\n'
        f'set "__COMPAT_LAYER={report["compat_layer"]}"\r\n'
        'pushd "%~dp0"\r\n"empiresx.exe" NOSTARTUP GAMECD %*\r\n'
        'set "code=%errorlevel%"\r\npopd\r\nexit /b %code%\r\n'
    ).encode("ascii"))
    (output / "runtime_manifest.json").write_text(json.dumps(report, indent=2) + "\n")
    STATE.mkdir(parents=True, exist_ok=True)
    save_selection(STATE / f"{target}.json", {"exe": str(exe), "runtime": str(output)})
    print(f"Runtime: {output}", flush=True)
    print(f"Shared assets: {report['shared_bytes'] / 1048576:.1f} MiB", flush=True)
    print(f"Launch: {output / 'Launch.cmd'}", flush=True)
    return output


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    subs = parser.add_subparsers(dest="command", required=True)
    subs.add_parser("setup", help="Install pinned graphics and isolated instrumentation dependencies")
    p = subs.add_parser('test-captures', help='Run the game UI main menu tests on private desktops')
    p.add_argument('--list', action='store_true')
    p.add_argument('--case', action='append', default=[], help='Test ID or wildcard; may be repeated')
    p.add_argument('--original-runs', type=int, choices=(1, 2, 3), default=2)
    p = subs.add_parser('override', help='Replace an asset without writing through its shared hard link')
    p.add_argument('runtime', type=Path)
    p.add_argument('relative', type=Path)
    p.add_argument('source', type=Path)
    p = subs.add_parser("compare", help="Compare the final surfaces in two capture reports")
    p.add_argument("left", type=Path)
    p.add_argument("right", type=Path)
    p.add_argument("--output", type=Path, required=True)
    p = subs.add_parser('repeat', help='Repeat a menu fixture and compare with its first run')
    p.add_argument('target', choices=('original', 'rebuilt'))
    p.add_argument('--count', type=int, default=20)
    p.add_argument('--seconds', type=float, default=4)
    p.add_argument('--fixture', type=Path)
    p.add_argument('--clock', choices=('real', 'calls'), default='calls')
    p.add_argument('--visible', action='store_true', help='Show game windows on the interactive desktop')
    for name in ("build", "original", "rebuilt", "capture"):
        p = subs.add_parser(name)
        if name == "capture":
            p.add_argument("target", choices=("original", "rebuilt"))
            p.add_argument("--seconds", type=float, default=8)
            p.add_argument("--fixture", type=Path)
            p.add_argument("--clock", choices=("real", "calls"), default="real")
            p.add_argument('--visible', action='store_true', help='Show the game on the interactive desktop')
        if name in ("rebuilt", "capture"):
            p.add_argument("--exe", type=Path)
        p.add_argument("--graphics", choices=("cnc-ddraw", "native"), default="cnc-ddraw")
        p.add_argument("--assets", choices=("hardlink", "copy"), default="hardlink")
        p.add_argument("--prepare-only", action="store_true")
    args = parser.parse_args()
    try:
        if args.command == 'test-captures':
            sys.path.insert(0, str(ROOT / 'tools/harness'))
            from suite import load_suite
            suite, cases = load_suite(patterns=args.case)
            if args.list:
                print(suite['name'])
                for case in cases:
                    print(f"  {case['id']}: {case['description']}")
                return 0
            output = ROOT / 'build/runtime' / ('ui-main-menu-' + stamp())
            command = [str(ROOT / 'build/harness-env/Scripts/python.exe'),
                       str(ROOT / 'tools/harness/suite.py'), '--output', str(output),
                       '--original-runs', str(args.original_runs)]
            for pattern in args.case:
                command += ['--case', pattern]
            code = run_worker(command, output.with_suffix('.log'),
                              sum((c.get('seconds', 20) + 20) * (args.original_runs + 1) for c in cases) + 60, False)
            report = output / 'report.json'
            if report.exists():
                result = json.loads(report.read_text())
                for row in result['cases']:
                    print(f"{'PASS' if row['passed'] else 'FAIL'} {row['id']}")
            print(f'UI suite report: {report}')
            return code
        if args.command == "setup":
            setup()
            return 0
        if args.command == 'override':
            override_asset(args.runtime, args.relative, args.source)
            return 0
        if args.command == "compare":
            python = ROOT / "build/harness-env/Scripts/python.exe"
            return subprocess.run([str(python), str(ROOT / "tools/harness/compare.py"),
                                   str(args.left), str(args.right), "--output", str(args.output)]).returncode
        if args.command == 'repeat':
            command = [str(ROOT / 'build/harness-env/Scripts/python.exe'),
                       str(ROOT / 'tools/harness/repeat.py'), args.target,
                       '--count', str(args.count), '--seconds', str(args.seconds), '--clock', args.clock]
            if args.fixture:
                command += ['--fixture', str(args.fixture.resolve())]
            log = ROOT / 'build/runtime' / ('hidden-repeat-' + stamp() + '.log')
            return run_worker(command, log, (args.seconds + 15) * args.count + 30, args.visible)
        target = args.target if args.command == "capture" else ("original" if args.command == "original" else "rebuilt")
        exe = build() if args.command == "build" else getattr(args, "exe", None)
        output = stage(target, exe, graphics=args.graphics, assets=args.assets)
        if args.command == "capture":
            if args.prepare_only:
                return 0
            python = ROOT / "build/harness-env/Scripts/python.exe"
            command = [str(python), str(ROOT / "tools/harness/capture.py"),
                       "--runtime", str(output), "--seconds", str(args.seconds), "--clock", args.clock]
            if args.fixture:
                command += ["--fixture", str(args.fixture.resolve())]
            return run_worker(command, output / 'hidden-worker.log', args.seconds + 30, args.visible)
        if args.command != "build" and not args.prepare_only:
            env = dict(os.environ, __COMPAT_LAYER="" if args.graphics == "cnc-ddraw" else "DWM8And16BitMitigation")
            process = subprocess.Popen([str(output / "empiresx.exe"), *DEFAULT_ARGUMENTS], cwd=output, env=env)
            print(f"Started PID {process.pid}.")
        return 0
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        print(f"Game command failed: {error}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
