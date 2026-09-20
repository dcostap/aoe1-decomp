"""Create a checked-in save bundle from an original human capture."""
from __future__ import annotations

import json
from pathlib import Path
import shutil

from prepare_runtime import ORIGINAL_SHA256, digest, SAVE_BUNDLE_ROOT


def create_bundle(report_path: Path, output: Path) -> Path:
    report_path = report_path.resolve()
    report = json.loads(report_path.read_text())
    if report.get('manifest', {}).get('selected_exe_sha256') != ORIGINAL_SHA256:
        raise ValueError('Only an original capture can create a save bundle.')
    if report.get('errors') or not report.get('status', {}).get('human', {}).get('stopped'):
        raise ValueError('Capture is incomplete; cannot create a save bundle.')
    runtime = Path(report['runtime']).resolve()
    source = runtime / 'savegame'
    if not source.is_dir():
        raise ValueError(f'Capture has no savegame directory: {source}')
    output = output.resolve()
    root = SAVE_BUNDLE_ROOT.resolve()
    if not output.is_relative_to(root) or output == root:
        raise ValueError('Save bundle output must stay under config/harness/save-bundles.')
    if output.exists():
        raise ValueError(f'Save bundle output already exists: {output}')
    files = []
    output.mkdir(parents=True)
    try:
        for source_file in sorted(source.iterdir()):
            if not source_file.is_file() or source_file.suffix.lower() not in ('.gmx', '.gam'):
                continue
            destination = output / source_file.name
            shutil.copy2(source_file, destination)
            row = {'name': source_file.name, 'size': destination.stat().st_size,
                   'sha256': digest(destination)}
            if digest(source_file) != row['sha256']:
                raise ValueError(f'Save bundle copy verification failed: {source_file}')
            files.append(row)
        if not files:
            raise ValueError('Capture has no .gmx or .gam save files.')
        manifest = {'schema': 1, 'files': files}
        (output / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    except Exception:
        shutil.rmtree(output, ignore_errors=True)
        raise
    return output


def main() -> int:
    import argparse
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('report', type=Path, help='Original capture report.json')
    parser.add_argument('output', type=Path, help='New directory under config/harness/save-bundles')
    args = parser.parse_args()
    try:
        output = create_bundle(args.report, args.output)
    except (OSError, ValueError, KeyError, TypeError, json.JSONDecodeError) as error:
        parser.error(str(error))
    print(f'Save bundle: {output}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
