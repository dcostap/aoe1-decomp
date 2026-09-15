import hashlib
import json
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import prepare_runtime


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
