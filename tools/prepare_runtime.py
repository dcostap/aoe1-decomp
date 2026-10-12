"""Copy a complete game install into a separate runtime directory."""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_SOURCE = ROOT / "runtime"
SAVE_BUNDLE_ROOT = ROOT / "config/harness/save-bundles"
# Personal saves pinned in config/harness/savegames.json but kept out of git.
LOCAL_SAVES = ROOT / "local/harness/savegames"
ORIGINAL_SHA256 = "88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90"
COMPAT_LAYER = "DWM8And16BitMitigation"
# Large input-only formats. Profiles, saves, scenarios, EXEs, and DLLs stay private.
SHARED_EXTENSIONS = {".drs", ".wav", ".avi"}


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def resolve_save_bundle(bundle=None):
    """Return the save folder, manifest, and stable bundle identity."""
    if bundle is None:
        folder = ROOT / 'config/harness/savegames'
        return folder, json.loads((folder.with_suffix('.json')).read_text()), None
    candidate = Path(bundle)
    if not candidate.is_absolute():
        direct = (ROOT / candidate).resolve()
        named = (SAVE_BUNDLE_ROOT / candidate).resolve()
        candidate = direct if direct.exists() else named
    candidate = candidate.resolve()
    root = SAVE_BUNDLE_ROOT.resolve()
    if candidate.is_file() and candidate.name.lower() == 'manifest.json':
        folder = candidate.parent
    elif candidate.is_dir():
        folder = candidate
    else:
        raise ValueError(f'Save bundle does not exist: {bundle}')
    if not folder.is_relative_to(root):
        raise ValueError('Save bundles must stay under config/harness/save-bundles.')
    manifest_path = folder / 'manifest.json'
    if not manifest_path.is_file():
        raise ValueError(f'Save bundle is missing manifest.json: {folder}')
    return folder, json.loads(manifest_path.read_text()), folder.relative_to(root).as_posix()


def save_fixtures(bundle=None):
    """Verify one immutable repository save bundle before staging a runtime."""
    folder, manifest, _ = resolve_save_bundle(bundle)
    if manifest.get('schema') != 1 or not isinstance(manifest.get('files'), list):
        raise ValueError('Invalid save fixture manifest.')
    names = set()
    result = []
    for row in manifest['files']:
        name = row.get('name', '')
        if not isinstance(name, str) or not name or '/' in name or '\\' in name or ':' in name or \
                Path(name).suffix.lower() not in ('.gmx', '.gam') or name.lower() in names:
            raise ValueError('Invalid or duplicate save fixture name.')
        names.add(name.lower())
        if row.get('local') is True and bundle is None:
            # A local save is optional: without it the pool is smaller, and a
            # recording that needs it fails its save contract check.
            path = LOCAL_SAVES / name
            if not path.exists():
                continue
        else:
            path = folder / name
        if path.is_symlink() or path.stat().st_size != row.get('size') or digest(path) != row.get('sha256'):
            raise ValueError(f'Save fixture hash or size differs: {name}')
        result.append((path, row))
    if bundle is None and LOCAL_SAVES.is_dir():
        # Any other personal save joins the pool as it is now. A recording pins its
        # hash, so a later change to the file fails that recording's save check.
        for path in sorted(LOCAL_SAVES.iterdir()):
            if path.suffix.lower() not in ('.gmx', '.gam') or path.name.lower() in names or \
                    path.is_symlink() or not path.is_file():
                continue
            names.add(path.name.lower())
            result.append((path, dict(name=path.name, local=True, size=path.stat().st_size, sha256=digest(path))))
    return result


def select_save_fixtures(fixtures, save_filter):
    """Select the exact pinned subset required by one human recording."""
    if not isinstance(save_filter, dict) or not save_filter:
        raise ValueError('A save filter must contain at least one pinned fixture.')
    expected = {}
    for name, sha256 in save_filter.items():
        if not isinstance(name, str) or not name or '/' in name or '\\' in name or ':' in name:
            raise ValueError('Invalid save filter name.')
        key = name.lower()
        if key in expected or not isinstance(sha256, str):
            raise ValueError('Invalid or duplicate save filter entry.')
        expected[key] = sha256

    selected = []
    found = set()
    for path, row in fixtures:
        key = row['name'].lower()
        if key in expected:
            if row['sha256'] != expected[key]:
                raise ValueError(f'Save fixture hash differs from recording contract: {row["name"]}')
            selected.append((path, row))
            found.add(key)
    if found != set(expected):
        missing = ', '.join(sorted(set(expected) - found))
        raise ValueError(f'Save fixtures differ from the recording contract; missing {missing}. '
                         f'Personal saves belong in {LOCAL_SAVES}.')
    return selected


def verify_harness_saves(runtime, manifest):
    """Reject private saves and changed fixtures before starting the game."""
    if manifest.get('savegame_source') != 'repository-fixtures':
        raise ValueError('Saved-game input requires repository save fixtures.')
    fixtures = save_fixtures(manifest.get('savegame_bundle'))
    if manifest.get('savegame_filter') is not None:
        fixtures = select_save_fixtures(fixtures, manifest['savegame_filter'])
    expected = {row['name']: row['sha256'] for _, row in fixtures}
    folder = runtime / 'savegame'
    if {path.name for path in folder.iterdir()} != set(expected):
        raise ValueError('Runtime save set differs from repository fixtures.')
    for name, sha256 in expected.items():
        path = folder / name
        if not path.is_file() or path.is_symlink() or digest(path) != sha256:
            raise ValueError(f'Runtime save fixture differs: {name}')
    recorded = {row['path']: row['sha256'] for row in manifest['copied_files_before_exe_replacement']
                if row['path'].replace('\\', '/').lower().startswith('savegame/')}
    if recorded != {'savegame/' + name: sha256 for name, sha256 in expected.items()}:
        raise ValueError('Runtime save manifest differs from repository fixtures.')


def prepare(source: Path, exe: Path, output: Path, *, assets: str = "copy", harness_saves=False,
            save_bundle=None, save_filter=None) -> dict:
    if assets not in ("copy", "hardlink"):
        raise ValueError("Asset mode must be copy or hardlink.")
    source, exe, output = source.resolve(), exe.resolve(), output.resolve()
    runtime_root = (ROOT / "build/runtime").resolve()
    if not output.is_relative_to(runtime_root) or output == runtime_root:
        raise ValueError("Output must be a new directory under build/runtime.")
    if output.exists():
        raise ValueError("Output already exists. Use a new directory.")
    if output.is_relative_to(source) or source.is_relative_to(output):
        raise ValueError("Source and output must not contain each other.")
    # The selected EXE replaces the installed one, so a retail install works as is.
    installed = source / "empiresx.exe"
    installed_hash = digest(installed) if installed.is_file() else None
    if not exe.is_file():
        raise ValueError("Selected EXE does not exist.")
    for name in ("data", "data2", "avi", "sound", "EMPIRES.EXE", "language.dll", "languagex.dll"):
        if not (source / name).exists():
            raise ValueError(f"Missing installed runtime input: {name}")
    if save_filter is not None and (not harness_saves or save_bundle is not None):
        raise ValueError('A save filter requires default repository fixtures, not a save bundle.')
    fixtures = save_fixtures(save_bundle) if harness_saves else []
    if save_filter is not None:
        fixtures = select_save_fixtures(fixtures, save_filter)
    _, _, save_bundle_id = resolve_save_bundle(save_bundle) if harness_saves else (None, None, None)
    exe_hash = digest(exe)
    files = []

    def copy_verified(src, dst):
        src, dst = Path(src), Path(dst)
        expected = digest(src)
        method = "copy"
        if assets == "hardlink" and src.suffix.lower() in SHARED_EXTENSIONS:
            try:
                os.link(src, dst)
                method = "hardlink"
            except OSError:
                # Different volumes and filesystems can reject hard links.
                shutil.copy2(src, dst)
        else:
            shutil.copy2(src, dst)
        if digest(dst) != expected:
            raise ValueError(f"Copy verification failed: {src}")
        files.append({"path": src.relative_to(source).as_posix(), "sha256": expected,
                      "method": method, "size": src.stat().st_size})
        return str(dst)

    # Harness saves come only from the checked-in fixture set.
    def ignored(directory, names):
        if Path(directory) != source:
            return set()
        return {name for name in names if name == 'README.md' or
                (harness_saves and name.lower() == 'savegame')}

    shutil.copytree(source, output, copy_function=copy_verified,
                    ignore=ignored)
    if harness_saves:
        (output / 'savegame').mkdir()
        for src, row in fixtures:
            dst = output / 'savegame' / row['name']
            shutil.copy2(src, dst)
            if digest(dst) != row['sha256']:
                raise ValueError(f'Save fixture copy verification failed: {src}')
            files.append({'path': 'savegame/' + row['name'], 'sha256': row['sha256'],
                          'size': row['size'], 'method': 'copy'})
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
        "source_directory": str(source), "source_exe_sha256": installed_hash,
        "selected_exe": str(exe), "selected_exe_sha256": exe_hash,
        "output_directory": str(output), "compat_layer": COMPAT_LAYER,
        "copied_files_before_exe_replacement": sorted(files, key=lambda row: row["path"]),
        "launcher": "Launch.cmd", "game_arguments": [],
        "asset_mode": assets,
        "savegame_source": "repository-fixtures" if harness_saves else "local-runtime",
        "shared_bytes": sum(row["size"] for row in files if row["method"] == "hardlink"),
    }
    if harness_saves and save_bundle_id is not None:
        report['savegame_bundle'] = save_bundle_id
    if save_filter is not None:
        report['savegame_filter'] = dict(save_filter)
    (output / "runtime_manifest.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    return report


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--source", type=Path, default=DEFAULT_SOURCE,
        help=f"Complete local game install (default: {DEFAULT_SOURCE})",
    )
    parser.add_argument("--exe", required=True, type=Path, help="Original or rebuilt expansion EXE to test")
    parser.add_argument("--output", required=True, type=Path, help="New directory under build/runtime")
    parser.add_argument("--assets", choices=("copy", "hardlink"), default="copy",
                        help="Share input-only DRS/WAV/AVI files. Never edit linked assets in place.")
    args = parser.parse_args()
    try:
        report = prepare(args.source, args.exe, args.output, assets=args.assets)
    except (OSError, ValueError) as error:
        parser.exit(1, f"Runtime preparation failed: {error}\n")
    print(json.dumps({key: value for key, value in report.items()
                      if key != "copied_files_before_exe_replacement"}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
