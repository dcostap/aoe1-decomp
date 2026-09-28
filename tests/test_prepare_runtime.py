import hashlib
import json
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import prepare_runtime


def local_saves_present():
    return all((prepare_runtime.LOCAL_SAVES / name).exists() or
               (prepare_runtime.ROOT / 'config/harness/savegames' / name).exists()
               for name in ('late_game_match_2.gmx', 'new_game_15mins_in.gmx'))


@pytest.fixture
def inputs(tmp_path, monkeypatch):
    monkeypatch.setattr(prepare_runtime, "ROOT", tmp_path)
    source = tmp_path / "installation"
    source.mkdir()
    for name in ("data", "data2", "avi", "sound"):
        (source / name).mkdir()
        (source / name / "asset.bin").write_bytes(name.encode())
    for name in ("empiresx.exe", "EMPIRES.EXE", "language.dll", "languagex.dll"):
        (source / name).write_bytes(name.encode())
    monkeypatch.setattr(prepare_runtime, "ORIGINAL_SHA256", prepare_runtime.digest(source / "empiresx.exe"))
    exe = tmp_path / "rebuilt.exe"
    exe.write_bytes(b"rebuilt")
    return source, exe, tmp_path / "build/runtime/game"


def test_complete_copy_and_launcher(inputs):
    source, exe, output = inputs
    report = prepare_runtime.prepare(source, exe, output)
    assert (source / "empiresx.exe").read_bytes() == b"empiresx.exe"
    assert (output / "empiresx.exe").read_bytes() == b"rebuilt"
    assert (output / "avi/asset.bin").read_bytes() == b"avi"
    assert len(report["copied_files_before_exe_replacement"]) == 8
    assert report["selected_exe_sha256"] == hashlib.sha256(b"rebuilt").hexdigest()
    assert json.loads((output / "runtime_manifest.json").read_text()) == report
    launcher = (output / "Launch.cmd").read_text()
    assert "setlocal" in launcher
    assert '__COMPAT_LAYER=DWM8And16BitMitigation' in launcher
    assert 'pushd "%~dp0"' in launcher
    assert '"empiresx.exe" %*' in launcher
    assert "WINDOW" not in launcher


def test_repository_readme_is_not_a_game_input(inputs):
    source, exe, output = inputs
    (source / "README.md").write_text("Repository setup instructions.")
    (source / "Readme.doc").write_bytes(b"Installed game documentation")
    (source / "data/README.md").write_bytes(b"Nested installation input")
    report = prepare_runtime.prepare(source, exe, output)
    paths = {row["path"] for row in report["copied_files_before_exe_replacement"]}
    assert "README.md" not in paths
    assert not (output / "README.md").exists()
    assert (source / "README.md").is_file()
    assert "Readme.doc" in paths and "data/README.md" in paths
    assert (output / "Readme.doc").read_bytes() == b"Installed game documentation"
    assert (output / "data/README.md").read_bytes() == b"Nested installation input"


def test_reject_existing_output(inputs):
    source, exe, output = inputs
    output.mkdir(parents=True)
    with pytest.raises(ValueError, match="already exists"):
        prepare_runtime.prepare(source, exe, output)


def test_reject_output_outside_runtime(inputs):
    source, exe, output = inputs
    with pytest.raises(ValueError, match="under build/runtime"):
        prepare_runtime.prepare(source, exe, source)


def test_reject_wrong_installed_exe(inputs):
    source, exe, output = inputs
    (source / "empiresx.exe").write_bytes(b"different")
    with pytest.raises(ValueError, match="does not match"):
        prepare_runtime.prepare(source, exe, output)
    assert not output.exists()


def test_default_source_is_root_runtime():
    assert prepare_runtime.DEFAULT_SOURCE == prepare_runtime.ROOT / "runtime"


def test_hardlinks_only_share_large_input_formats(inputs):
    source, exe, output = inputs
    (source / "data/graphics.drs").write_bytes(b"graphics")
    (source / "data/aoe.ply").write_bytes(b"profile")
    report = prepare_runtime.prepare(source, exe, output, assets="hardlink")
    assert (source / "data/graphics.drs").samefile(output / "data/graphics.drs")
    assert not (source / "data/aoe.ply").samefile(output / "data/aoe.ply")
    assert not (source / "empiresx.exe").samefile(output / "empiresx.exe")
    assert report["shared_bytes"] == len(b"graphics")
    # Replacing an asset must remove the link first, never overwrite its content.
    (output / "data/graphics.drs").unlink()
    (output / "data/graphics.drs").write_bytes(b"override")
    assert (source / "data/graphics.drs").read_bytes() == b"graphics"


def test_hardlink_failure_falls_back_to_copy(inputs, monkeypatch):
    source, exe, output = inputs
    (source / "data/graphics.drs").write_bytes(b"graphics")
    def fail(*args):
        raise OSError("Different filesystem")
    monkeypatch.setattr(prepare_runtime.os, "link", fail)
    report = prepare_runtime.prepare(source, exe, output, assets="hardlink")
    assert report["shared_bytes"] == 0
    assert (output / "data/graphics.drs").read_bytes() == b"graphics"


def test_unknown_asset_mode_rejected(inputs):
    with pytest.raises(ValueError, match="Asset mode"):
        prepare_runtime.prepare(*inputs, assets="overlay")


@pytest.fixture
def harness_inputs(inputs, tmp_path, monkeypatch):
    source, exe, output = inputs
    # Personal saves on this machine are not part of these tests.
    monkeypatch.setattr(prepare_runtime, 'LOCAL_SAVES', tmp_path / 'no-local-saves')
    folder = prepare_runtime.ROOT / 'config/harness/savegames'
    folder.mkdir(parents=True)
    fixture = folder / 'late_game_match.gmx'
    fixture.write_bytes(b'fixture')
    folder.with_suffix('.json').write_text(json.dumps({'schema':1, 'files':[
        {'name':fixture.name, 'size':fixture.stat().st_size, 'sha256':prepare_runtime.digest(fixture)}]}))
    (source / 'SaveGame/nested').mkdir(parents=True)
    (source / 'SaveGame/personal.gmx').write_bytes(b'personal')
    (source / 'SaveGame/nested/private.gam').write_bytes(b'private')
    return source, exe, output, fixture


def test_local_saves_are_optional_pool_members(harness_inputs, tmp_path, monkeypatch):
    source, exe, output, fixture = harness_inputs
    local = tmp_path / 'local-saves'
    local.mkdir()
    monkeypatch.setattr(prepare_runtime, 'LOCAL_SAVES', local)
    (local / 'personal.gmx').write_bytes(b'personal')
    manifest = json.loads(fixture.parent.with_suffix('.json').read_text())
    manifest['files'].append({'name':'personal.gmx', 'local':True, 'size':8,
                              'sha256':prepare_runtime.digest(local / 'personal.gmx')})
    fixture.parent.with_suffix('.json').write_text(json.dumps(manifest))
    rows = prepare_runtime.save_fixtures()
    assert [path for path, _ in rows] == [fixture, local / 'personal.gmx']
    (local / 'personal.gmx').unlink()
    assert [path for path, _ in prepare_runtime.save_fixtures()] == [fixture]
    with pytest.raises(ValueError, match='missing personal.gmx'):
        prepare_runtime.select_save_fixtures(prepare_runtime.save_fixtures(), {'personal.gmx':'x'})


def test_unlisted_local_saves_join_the_pool_with_their_current_hash(harness_inputs, tmp_path, monkeypatch):
    source, exe, output, fixture = harness_inputs
    local = tmp_path / 'local-saves'
    local.mkdir()
    monkeypatch.setattr(prepare_runtime, 'LOCAL_SAVES', local)
    (local / 'chaos-1.gmx').write_bytes(b'chaos')
    (local / 'notes.txt').write_text('not a save')
    rows = prepare_runtime.save_fixtures()
    assert [path for path, _ in rows] == [fixture, local / 'chaos-1.gmx']
    assert rows[1][1] == {'name':'chaos-1.gmx', 'local':True, 'size':5,
                          'sha256':prepare_runtime.digest(local / 'chaos-1.gmx')}
    selected = prepare_runtime.select_save_fixtures(rows, {'chaos-1.gmx':rows[1][1]['sha256']})
    assert [path for path, _ in selected] == [local / 'chaos-1.gmx']
    # A recording pins the hash it saw; a changed file no longer satisfies it.
    (local / 'chaos-1.gmx').write_bytes(b'changed')
    with pytest.raises(ValueError, match='hash differs'):
        prepare_runtime.select_save_fixtures(prepare_runtime.save_fixtures(),
                                             {'chaos-1.gmx':rows[1][1]['sha256']})


def test_harness_uses_only_private_copies_of_repository_saves(harness_inputs):
    source, exe, output, fixture = harness_inputs
    report = prepare_runtime.prepare(source, exe, output, assets='hardlink', harness_saves=True)
    save = output / 'savegame' / fixture.name
    assert list((output / 'savegame').iterdir()) == [save]
    assert save.read_bytes() == fixture.read_bytes()
    assert not save.samefile(fixture)
    assert (source / 'SaveGame/personal.gmx').read_bytes() == b'personal'
    prepare_runtime.verify_harness_saves(output, report)
    save.write_bytes(b'changed during play')
    assert fixture.read_bytes() == b'fixture'
    with pytest.raises(ValueError, match='Runtime save fixture differs'):
        prepare_runtime.verify_harness_saves(output, report)
    fresh = output.with_name('fresh')
    fresh_report = prepare_runtime.prepare(source, exe, fresh, harness_saves=True)
    prepare_runtime.verify_harness_saves(fresh, fresh_report)


def test_plain_game_keeps_local_saves(harness_inputs):
    source, exe, output, fixture = harness_inputs
    report = prepare_runtime.prepare(source, exe, output)
    assert report['savegame_source'] == 'local-runtime'
    assert (output / 'SaveGame/personal.gmx').read_bytes() == b'personal'
    assert not (output / 'SaveGame' / fixture.name).exists()


def test_changed_fixture_fails_before_staging(harness_inputs):
    source, exe, output, fixture = harness_inputs
    fixture.write_bytes(b'changed')
    with pytest.raises(ValueError, match='Save fixture hash or size differs'):
        prepare_runtime.prepare(source, exe, output, harness_saves=True)
    assert not output.exists()


def test_extra_runtime_save_is_rejected(harness_inputs):
    source, exe, output, fixture = harness_inputs
    report = prepare_runtime.prepare(source, exe, output, harness_saves=True)
    (output / 'savegame/extra.gmx').write_bytes(b'personal')
    with pytest.raises(ValueError, match='Runtime save set differs'):
        prepare_runtime.verify_harness_saves(output, report)


@pytest.mark.parametrize('name', ['../escape.gmx', 'C:escape.gmx', 'nested/private.gmx', 'bad.txt'])
def test_save_fixture_paths_are_bounded(harness_inputs, name):
    source, exe, output, fixture = harness_inputs
    fixture.parent.with_suffix('.json').write_text(json.dumps({'schema':1, 'files':[{'name':name}]}))
    with pytest.raises(ValueError, match='save fixture name'):
        prepare_runtime.prepare(source, exe, output, harness_saves=True)


@pytest.mark.skipif(not local_saves_present(), reason='Personal save fixtures are not in local/harness/savegames.')
def test_repository_save_fixture_identity():
    # Other personal saves can follow the pinned rows; they are not part of this identity.
    fixtures = prepare_runtime.save_fixtures()[:3]
    assert [row['name'] for _, row in fixtures] == [
        'late_game_match.gmx', 'late_game_match_2.gmx', 'new_game_15mins_in.gmx']
    assert fixtures[0][1]['sha256'] == 'fccd0ca0ccd98a6658a1eeb3b306c89afee3af9caf58ab518ee04eae434687f4'
    assert fixtures[1][1]['sha256'] == '169165e6afa68fc55e18f892f68b55817d62f2489ffec6a7ff128ccccb79d34f'
    assert fixtures[2][1]['sha256'] == 'b54559781b0889bfea867070326e666ab6543cd317bf93c855c3c7aa1a676547'


def test_recording_save_filter_stages_only_its_pinned_subset(harness_inputs):
    source, exe, output, fixture = harness_inputs
    extra = fixture.parent / 'another.gmx'
    extra.write_bytes(b'other fixture')
    manifest_path = fixture.parent.with_suffix('.json')
    manifest = json.loads(manifest_path.read_text())
    manifest['files'].append({'name':extra.name, 'size':extra.stat().st_size,
                              'sha256':prepare_runtime.digest(extra)})
    manifest_path.write_text(json.dumps(manifest))

    selected = {fixture.name: prepare_runtime.digest(fixture)}
    report = prepare_runtime.prepare(source, exe, output, harness_saves=True,
                                     save_filter=selected)
    assert [path.name for path in (output / 'savegame').iterdir()] == [fixture.name]
    assert report['savegame_filter'] == selected
    prepare_runtime.verify_harness_saves(output, report)

    (output / 'savegame/another.gmx').write_bytes(b'unpinned')
    with pytest.raises(ValueError, match='Runtime save set differs'):
        prepare_runtime.verify_harness_saves(output, report)


def test_named_save_bundle_is_staged_and_pinned(harness_inputs, monkeypatch, tmp_path):
    source, exe, output, _ = harness_inputs
    bundle_root = tmp_path / 'bundles'
    bundle = bundle_root / 'chain-01/checkpoint-01'
    bundle.mkdir(parents=True)
    save = bundle / 'checkpoint.gmx'
    save.write_bytes(b'checkpoint')
    (bundle / 'manifest.json').write_text(json.dumps({'schema': 1, 'files': [
        {'name': save.name, 'size': save.stat().st_size, 'sha256': prepare_runtime.digest(save)}]}))
    monkeypatch.setattr(prepare_runtime, 'SAVE_BUNDLE_ROOT', bundle_root)
    report = prepare_runtime.prepare(source, exe, output, harness_saves=True, save_bundle=bundle)
    assert report['savegame_bundle'] == 'chain-01/checkpoint-01'
    assert (output / 'savegame/checkpoint.gmx').read_bytes() == b'checkpoint'
    prepare_runtime.verify_harness_saves(output, report)
