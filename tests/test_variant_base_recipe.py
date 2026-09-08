"""A lab must use the same baseline flags as the authoritative checker."""
import hashlib
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from common import function_record_by_va, load_toolchain, REPO_ROOT
from variant_lab import freeze_base_recipe


def test_tech_lab_uses_unoptimized_recipe(tmp_path):
    result = freeze_base_recipe(function_record_by_va(0x0050C730), load_toolchain(), tmp_path)
    assert result.read_bytes() == (REPO_ROOT / 'config/flags/unoptimized.rsp').read_bytes()
    manifest = json.loads((tmp_path / 'base_recipe.json').read_text())
    assert manifest['sha256'] == hashlib.sha256(result.read_bytes()).hexdigest()
    assert Path(manifest['source']).name == 'unoptimized.rsp'


def test_header_lab_uses_emitter_exception_profile(tmp_path):
    result = freeze_base_recipe(function_record_by_va(0x00405D40), load_toolchain(), tmp_path)
    assert result.read_bytes() == (REPO_ROOT / 'config/flags/gx.rsp').read_bytes()


def test_lab_profile_copy_does_not_follow_later_edits(tmp_path, monkeypatch):
    import variant_lab
    source = tmp_path / 'source.rsp'
    source.write_bytes(b'/Od\n')
    monkeypatch.setattr(variant_lab, 'preferred_flags_rsp_path', lambda record, toolchain: source)
    result = freeze_base_recipe({}, {}, tmp_path)
    source.write_bytes(b'/O2\n')
    assert result.read_bytes() == b'/Od\n'
