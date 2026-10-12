from __future__ import annotations

import struct
import sys
from pathlib import Path
from unittest.mock import patch

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import build_executable
from pe_resources import resource_name, resource_record
from audit_link_symbols import decorated_name, symbol_key


def test_link_diagnostics_groups_missing_symbols():
    text = ('one.obj : error LNK2001: unresolved external symbol _missing\n'
            'two.obj : error LNK2001: unresolved external symbol _missing\n'
            'out.exe : fatal error LNK1120: 1 unresolved externals\n'
            'LINK : warning LNK4098: library conflict\n')
    result = build_executable.link_diagnostics(text)
    assert result["unresolved"] == {"_missing": ["one.obj", "two.obj"]}
    assert len(result["errors"]) == 3
    assert len(result["warnings"]) == 1


def test_resource_record_alignment():
    result = resource_record(3, "AppIcon", 1033, b"abc")
    size, header = struct.unpack_from("<II", result)
    assert size == 3
    assert header % 4 == 0
    assert result[header:] == b"abc\0"
    assert len(result) % 4 == 0
    assert struct.unpack_from("<H", result, header - 10)[0] == 1033


def test_resource_numeric_name():
    assert resource_name(3) == b"\xff\xff\x03\x00"
    with pytest.raises(ValueError):
        resource_name(65536)


def test_plan_uses_registry_profiles_and_accepts_windows_case(tmp_path):
    (tmp_path / "src").mkdir()
    (tmp_path / "src/pnl_msg.cpp").touch()
    modules = [{"source": "src/Pnl_msg.cpp", "build": {"flags_path": "config/flags/gx.rsp"}}]
    with patch.object(build_executable, "REPO_ROOT", tmp_path):
        plan = build_executable.source_plan({"additional_sources": {}}, modules)
    assert plan[0]["flags"] == "config/flags/gx.rsp"


def test_plan_rejects_missing_source_route(tmp_path):
    (tmp_path / "src").mkdir()
    (tmp_path / "src/missing.cpp").touch()
    with patch.object(build_executable, "REPO_ROOT", tmp_path):
        with pytest.raises(ValueError, match="without build routes"):
            build_executable.source_plan({"additional_sources": {}}, [])


def test_plan_rejects_duplicate_routes(tmp_path):
    modules = [{"source": "src/One.cpp", "build": {"flags_path": "config/flags/gx.rsp"}}]
    with patch.object(build_executable, "REPO_ROOT", tmp_path):
        with pytest.raises(ValueError, match="Duplicate"):
            build_executable.source_plan({"additional_sources": {"src/one.cpp": "default"}}, modules)


def test_link_search_does_not_confuse_class_members():
    assert decorated_name('"int __cdecl read(int)" (?read@@YAHH@Z)') == '?read@@YAHH@Z'
    assert symbol_key('_rge_read') == symbol_key('?rge_read@@YAXHPAXH@Z')
    assert symbol_key('?read@One@@QAEHXZ') != symbol_key('?read@Two@@QAEHXZ')


def test_resource_roundtrip_with_pinned_linker():
    import subprocess
    import uuid
    from common import load_toolchain, repo_path, tool_env
    from pe_resources import extract_resources

    toolchain = load_toolchain()
    linker = repo_path(toolchain["compiler"]["link"])
    if not linker.is_file():
        pytest.skip("Pinned VC5 linker is not installed")
    if not repo_path("orig/empiresx.exe").is_file():
        pytest.skip("needs orig/empiresx.exe")
    tmp_path = repo_path("build/tests/resource_roundtrip") / uuid.uuid4().hex
    tmp_path.mkdir(parents=True)
    original = repo_path("orig/empiresx.exe")
    source_res = tmp_path / "original.res"
    linked_res = tmp_path / "roundtrip.res"
    dll = tmp_path / "resources.dll"
    original_rows = extract_resources(original, source_res)
    result = subprocess.run([str(linker), "/NOLOGO", "/DLL", "/NOENTRY", "/MACHINE:IX86",
                             f"/OUT:{dll}", str(source_res)], capture_output=True, text=True,
                            cwd=tmp_path, env=tool_env(toolchain))
    assert result.returncode == 0, result.stdout + result.stderr
    assert extract_resources(dll, linked_res) == original_rows
    assert linked_res.read_bytes() == source_res.read_bytes()


def test_resource_script_matches_original_resources():
    import json
    import subprocess
    import uuid
    from common import load_toolchain, repo_path, tool_env
    from pe_resources import compile_resources, extract_icon, extract_resources

    toolchain = load_toolchain()
    linker = repo_path(toolchain["compiler"]["link"])
    rc = repo_path(toolchain["compiler"]["rc"])
    if not linker.is_file() or not rc.is_file():
        pytest.skip("Pinned VC5 linker or resource compiler is not installed")
    config = json.loads(repo_path("config/executable.json").read_text())
    icon_sources = [repo_path(icon["source"]) for icon in config["icons"]]
    if not repo_path("orig/empiresx.exe").is_file() or not all(p.is_file() for p in icon_sources):
        pytest.skip("needs orig/empiresx.exe and the retail install in runtime/")
    tmp_path = repo_path("build/tests/resource_script") / uuid.uuid4().hex
    assets = tmp_path / "assets"
    for icon in config["icons"]:
        extract_icon(repo_path(icon["source"]), icon["group"], assets / icon["file"], icon["sha256"])
    resource = tmp_path / "empiresx.res"
    row = compile_resources(rc, repo_path(config["resource_script"]), assets, resource, tool_env(toolchain))
    assert row["compiled"], row["stdout"] + row["stderr"]
    dll = tmp_path / "resources.dll"
    result = subprocess.run([str(linker), "/NOLOGO", "/DLL", "/NOENTRY", "/MACHINE:IX86",
                             f"/OUT:{dll}", str(resource)], capture_output=True, text=True,
                            cwd=tmp_path, env=tool_env(toolchain))
    assert result.returncode == 0, result.stdout + result.stderr
    original_res = tmp_path / "original.res"
    linked_res = tmp_path / "linked.res"
    assert extract_resources(dll, linked_res) == extract_resources(repo_path("orig/empiresx.exe"), original_res)
    assert linked_res.read_bytes() == original_res.read_bytes()


def test_obstruction_tables_compile_as_writable_data():
    import hashlib
    import json
    import uuid
    import pefile
    from coff import load_coff_object
    from common import load_toolchain, repo_path
    from function_compare import compile_source

    toolchain = load_toolchain()
    if not repo_path(toolchain["compiler"]["cl"]).is_file():
        pytest.skip("Pinned VC5 compiler is not installed")
    if not repo_path("orig/empiresx.exe").is_file():
        pytest.skip("needs orig/empiresx.exe")
    output = repo_path("build/tests/obstruction_storage") / uuid.uuid4().hex / "game_globals.obj"
    output.parent.mkdir(parents=True)
    source = repo_path("src/game_globals.cpp")
    compile_source(source, output, repo_path("config/flags/default.rsp"), source.parent)
    obj = load_coff_object(output)
    config = json.loads(repo_path("config/executable.json").read_text())
    original = repo_path(config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    pe = pefile.PE(data=original)

    for name, address, expected in (
        ("ObstructionValueShift", 0x584EF4, bytes([0, 2, 4, 6])),
        ("ObstructionValueMask", 0x584EF0, bytes.fromhex("fcf3cf3f")),
    ):
        symbols = [s for s in obj.symbols
                   if s.name == "?" + name + "@@3PAEA" and s.section_number > 0]
        assert len(symbols) == 1, name
        symbol = symbols[0]
        section = obj.section_by_index(symbol.section_number)
        assert section.data[symbol.value:symbol.value + 4] == expected, name
        assert section.characteristics & 0x80000000, name
        assert section.characteristics & 0x40000000, name
        rva = address - pe.OPTIONAL_HEADER.ImageBase
        assert pe.get_data(rva, 4) == expected, name
        original_section = pe.get_section_by_rva(rva)
        assert original_section is not None
        assert original_section.Characteristics & 0x80000000, name
