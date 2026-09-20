import json
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import prepare_runtime
import save_bundle


def test_create_bundle_copies_original_save_outputs(tmp_path, monkeypatch):
    root = tmp_path / 'bundles'
    monkeypatch.setattr(save_bundle, 'SAVE_BUNDLE_ROOT', root)
    runtime = tmp_path / 'runtime'
    (runtime / 'savegame').mkdir(parents=True)
    (runtime / 'savegame/checkpoint.gmx').write_bytes(b'checkpoint')
    (runtime / 'savegame/ignore.txt').write_bytes(b'ignore')
    report = tmp_path / 'report.json'
    report.write_text(json.dumps({'runtime': str(runtime), 'errors': [],
        'status': {'human': {'stopped': True}}, 'manifest': {
            'selected_exe_sha256': prepare_runtime.ORIGINAL_SHA256}}))
    output = save_bundle.create_bundle(report, root / 'chain-01/checkpoint-01')
    assert (output / 'checkpoint.gmx').read_bytes() == b'checkpoint'
    manifest = json.loads((output / 'manifest.json').read_text())
    assert [row['name'] for row in manifest['files']] == ['checkpoint.gmx']


def test_create_bundle_rejects_rebuilt_capture(tmp_path, monkeypatch):
    monkeypatch.setattr(save_bundle, 'SAVE_BUNDLE_ROOT', tmp_path / 'bundles')
    report = tmp_path / 'report.json'
    report.write_text(json.dumps({'manifest': {'selected_exe_sha256': 'rebuilt'}}))
    with pytest.raises(ValueError, match='original capture'):
        save_bundle.create_bundle(report, tmp_path / 'bundles/checkpoint')
