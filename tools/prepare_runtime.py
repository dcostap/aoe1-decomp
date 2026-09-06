"""Copy a complete installed beta into a separate runtime directory."""
from __future__ import annotations

import argparse
import hashlib
import json
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_SOURCE = ROOT / "runtime"
ORIGINAL_SHA256 = "88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90"
COMPAT_LAYER = "DWM8And16BitMitigation"


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def prepare(source: Path, exe: Path, output: Path) -> dict:
    source, exe, output = source.resolve(), exe.resolve(), output.resolve()
    runtime_root = (ROOT / "build/runtime").resolve()
    if not output.is_relative_to(runtime_root) or output == runtime_root:
        raise ValueError("Output must be a new directory under build/runtime.")
    if output.exists():
        raise ValueError("Output already exists. Use a new directory.")
    if output.is_relative_to(source) or source.is_relative_to(output):
        raise ValueError("Source and output must not contain each other.")
    original = source / "empiresx.exe"
    if digest(original) != ORIGINAL_SHA256:
        raise ValueError("Installed expansion EXE does not match the repository beta.")
    if not exe.is_file():
        raise ValueError("Selected EXE does not exist.")
    for name in ("data", "data2", "avi", "sound", "EMPIRES.EXE", "language.dll", "languagex.dll"):
        if not (source / name).exists():
            raise ValueError(f"Missing installed runtime input: {name}")
    exe_hash = digest(exe)
    files = []

    def copy_verified(src, dst):
        src, dst = Path(src), Path(dst)
        expected = digest(src)
        shutil.copy2(src, dst)
        if digest(dst) != expected:
            raise ValueError(f"Copy verification failed: {src}")
        files.append({"path": src.relative_to(source).as_posix(), "sha256": expected})
        return str(dst)

    shutil.copytree(source, output, copy_function=copy_verified)
    shutil.copy2(exe, output / "empiresx.exe")
    if digest(output / "empiresx.exe") != exe_hash:
        raise ValueError("Selected EXE copy verification failed.")
    # The environment setting applies only to this launcher and its child process.
    launcher = (
        '@echo off\r\nsetlocal\r\n'
        f'set "__COMPAT_LAYER={COMPAT_LAYER}"\r\n'
        'pushd "%~dp0"\r\n"empiresx.exe" %*\r\npopd\r\nendlocal\r\n'
    )
    (output / "Launch.cmd").write_bytes(launcher.encode("ascii"))
    report = {
        "source_directory": str(source), "source_exe_sha256": ORIGINAL_SHA256,
        "selected_exe": str(exe), "selected_exe_sha256": exe_hash,
        "output_directory": str(output), "compat_layer": COMPAT_LAYER,
        "copied_files_before_exe_replacement": sorted(files, key=lambda row: row["path"]),
        "launcher": "Launch.cmd", "game_arguments": [],
    }
    (output / "runtime_manifest.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    return report


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--source", type=Path, default=DEFAULT_SOURCE,
        help=f"Complete local beta runtime (default: {DEFAULT_SOURCE})",
    )
    parser.add_argument("--exe", required=True, type=Path, help="Original or rebuilt expansion EXE to test")
    parser.add_argument("--output", required=True, type=Path, help="New directory under build/runtime")
    args = parser.parse_args()
    try:
        report = prepare(args.source, args.exe, args.output)
    except (OSError, ValueError) as error:
        parser.exit(1, f"Runtime preparation failed: {error}\n")
    print(json.dumps({key: value for key, value in report.items()
                      if key != "copied_files_before_exe_replacement"}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
