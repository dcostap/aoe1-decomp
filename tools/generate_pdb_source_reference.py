from __future__ import annotations

import argparse
import csv
import subprocess
from pathlib import Path

from common import ensure_build_subdir, ensure_dir, load_binaries, load_layout, parse_hex, repo_path, PDB_INVENTORY_DIR


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate PDB-backed source filename and line-number reference dumps.")
    parser.add_argument("--force-rebuild-helper", action="store_true", help="Rebuild the DIA helper even if it looks up to date.")
    return parser.parse_args()


def find_vs_installation() -> Path:
    vswhere = Path(r"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe")
    if not vswhere.exists():
        raise SystemExit(f"Missing vswhere.exe: {vswhere}")
    result = subprocess.run(
        [
            str(vswhere),
            "-latest",
            "-products",
            "*",
            "-requires",
            "Microsoft.VisualStudio.Component.VC.Tools.x86.x64",
            "-property",
            "installationPath",
        ],
        capture_output=True,
        text=True,
        check=True,
    )
    install = result.stdout.strip()
    if not install:
        raise SystemExit("Could not locate a Visual Studio installation for the DIA helper build.")
    return Path(install)


def build_helper(helper_source: Path, helper_exe: Path, force_rebuild: bool) -> Path:
    install = find_vs_installation()
    dia_include = install / "DIA SDK" / "include"
    dia_lib = install / "DIA SDK" / "lib" / "amd64"
    vsdevcmd = install / "Common7" / "Tools" / "VsDevCmd.bat"
    if not dia_include.joinpath("dia2.h").exists():
        raise SystemExit(f"Missing DIA SDK include under {dia_include}")
    if not dia_lib.joinpath("diaguids.lib").exists():
        raise SystemExit(f"Missing DIA SDK lib under {dia_lib}")
    if not vsdevcmd.exists():
        raise SystemExit(f"Missing VsDevCmd.bat: {vsdevcmd}")

    helper_obj_dir = ensure_build_subdir("tools") / "obj"
    ensure_dir(helper_obj_dir)
    helper_obj = helper_obj_dir / "pdb_function_source_export.obj"
    if (
        not force_rebuild
        and helper_exe.exists()
        and helper_exe.stat().st_mtime >= helper_source.stat().st_mtime
    ):
        return install

    helper_script = helper_exe.parent / "build_pdb_function_source_export.cmd"
    helper_script.write_text(
        "@echo off\r\n"
        f'call "{vsdevcmd}" -arch=amd64 -host_arch=amd64 >nul\r\n'
        "if errorlevel 1 exit /b 1\r\n"
        f'cl /nologo /EHsc /std:c++17 /I "{dia_include}" /Fo"{helper_obj}" /Fe"{helper_exe}" "{helper_source}" /link /LIBPATH:"{dia_lib}" diaguids.lib ole32.lib oleaut32.lib advapi32.lib\r\n',
        encoding="utf-8",
    )
    result = subprocess.run(
        ["cmd.exe", "/d", "/c", str(helper_script)],
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        raise SystemExit(
            "Failed to build PDB source exporter helper.\n"
            f"stdout:\n{result.stdout}\n"
            f"stderr:\n{result.stderr}"
        )
    return install


def write_rva_list(layout: dict, path: Path) -> int:
    count = 0
    with path.open("w", encoding="utf-8", newline="\n") as handle:
        for entry in layout.get("functions", []):
            start = parse_hex(entry.get("start"))
            name = (entry.get("name") or "").strip()
            if start is None or not name:
                continue
            handle.write(f"{start:08X}\n")
            count += 1
    return count


def load_csv_count(path: Path) -> int:
    with path.open("r", encoding="utf-8", newline="") as handle:
        return max(sum(1 for _ in handle) - 1, 0)


def main() -> None:
    args = parse_args()
    binaries = load_binaries()
    helper_source = repo_path("tools\\pdb_function_source_export.cpp")
    helper_dir = ensure_build_subdir("tools")
    helper_exe = helper_dir / "pdb_function_source_export.exe"
    install = build_helper(helper_source, helper_exe, args.force_rebuild_helper)
    msdia_dll = install / "Common7" / "IDE" / "msdia140.dll"
    if not msdia_dll.exists():
        raise SystemExit(f"Missing msdia140.dll: {msdia_dll}")

    ensure_dir(PDB_INVENTORY_DIR)
    summary_csv = PDB_INVENTORY_DIR / "function_source_map.csv"
    changes_csv = PDB_INVENTORY_DIR / "function_line_changes.csv"
    rva_list = helper_dir / "pdb_function_rvas.txt"

    layout = load_layout(repo_path(binaries["ghidra_layout"]))
    function_count = write_rva_list(layout, rva_list)
    pdb_path = repo_path(binaries["original_pdb"])

    result = subprocess.run(
        [
            str(helper_exe),
            str(msdia_dll),
            str(pdb_path),
            binaries["image_base"],
            str(rva_list),
            str(summary_csv),
            str(changes_csv),
        ],
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        raise SystemExit(
            "Failed to export PDB source map.\n"
            f"stdout:\n{result.stdout}\n"
            f"stderr:\n{result.stderr}"
        )

    print(f"Wrote {summary_csv}")
    print(f"Rows: {load_csv_count(summary_csv)}")
    print(f"Wrote {changes_csv}")
    print(f"Rows: {load_csv_count(changes_csv)}")
    print(f"Functions requested: {function_count}")


if __name__ == "__main__":
    main()
