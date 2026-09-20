"""Check recovered executable data against the pinned original image."""
import ast
import hashlib
import json
from pathlib import Path
import re
import struct

import pefile
import pytest

ROOT = Path(__file__).resolve().parents[1]


def source_string_literals():
    literals = set()
    for path in (ROOT / "src").iterdir():
        if path.suffix.lower() not in {".c", ".cpp"}:
            continue
        for token in re.findall(r'"(?:[^"\\\r\n]|\\.)*"', path.read_text(errors="replace")):
            try:
                literals.add(ast.literal_eval(token))
            except (SyntaxError, ValueError):
                pass
    return literals


@pytest.mark.parametrize("evidence_file", ["play_file_strings.json", "ui_strings.json"])
def test_string_initializers_match_original(evidence_file):
    evidence = json.loads((ROOT / "decomp_notes/executable_build_evidence" / evidence_file).read_text())
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == evidence["original_sha256"]
    image = pefile.PE(data=original)
    literals = source_string_literals()
    for name, address in evidence["strings"].items():
        offset = int(address, 16) - image.OPTIONAL_HEADER.ImageBase
        original = image.get_data(offset, 256).split(b"\0", 1)[0].decode("ascii")
        assert original in literals, name


def test_runtime_scalar_initializers_match_original():
    evidence = json.loads((ROOT / "decomp_notes/executable_build_evidence/runtime_scalar_data.json").read_text())
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    mapped = image.get_memory_mapped_image()
    source = (ROOT / evidence["source"]).read_text()
    for name, address in evidence["scalars"].items():
        pattern = r'\b(unsigned char|unsigned long|unsigned int|long|int)\s+' + re.escape(name) + r'\s*=\s*(-?(?:0x[0-9A-Fa-f]+|[0-9]+))\s*;'
        matches = re.findall(pattern, source)
        assert len(matches) == 1, name
        kind, literal = matches[0]
        value = int(literal, 0)
        width = 1 if kind == "unsigned char" else 4
        expected = value.to_bytes(width, "little", signed=value < 0)
        offset = int(address, 16) - image.OPTIONAL_HEADER.ImageBase
        assert mapped[offset:offset + width] == expected, name


def test_random_log_reset_uses_original_array_extent():
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    code = image.get_data(0x423010 - image.OPTIONAL_HEADER.ImageBase, 18)
    assert code[0] == 0xB8  # MOV EAX, first entry.
    assert code[5:8] == b"\xc6\x00\x00"  # Clear the first byte.
    assert code[8:11] == b"\x83\xc0\x64"  # Advance by 100 bytes.
    assert code[11] == 0x3D  # CMP EAX, array end.
    start = int.from_bytes(code[1:5], "little")
    end = int.from_bytes(code[12:16], "little")
    assert code[16:18] == b"\x7c\xf3"  # Repeat below the end.
    assert (start, end) == (0x5B2378, 0x62C498)
    assert end - start == 5000 * 100
    mapped = image.get_memory_mapped_image()
    base = image.OPTIONAL_HEADER.ImageBase
    assert mapped[start - base:end - base] == bytes(end - start)
    source = (ROOT / "src/basegame.cpp").read_text()
    reset = source.split("void __cdecl debug_random_reset() {", 1)[1].split("}", 1)[0]
    assert "index < 5000" in reset
    assert "debug_random_log[index][0] = 0;" in reset
    globals_source = (ROOT / "src/game_globals.cpp").read_text()
    assert "char debug_random_log[5000][100] = {0};" in globals_source


def test_game_destructor_uses_configuration_dialog():
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    assert image.get_data(0x4954C8 - image.OPTIONAL_HEADER.ImageBase, 5) == bytes.fromhex("68d8425800")
    source = (ROOT / "src/scr_game.cpp").read_text()
    body = re.search(r'TRIBE_Screen_Game::~TRIBE_Screen_Game\(\)\s*\{(.*?)^\}', source, re.S | re.M)[1]
    assert 'destroyPanel("Config Dialog")' in body
    assert "destroyPanel(s_Game_Screen)" not in body


@pytest.mark.parametrize("declaration,address,expected", [
    ("RGE_Pick_Obj_Info Picked_Objects[64] = {0};", 0x87D4A0, bytes(64 * 12)),
    ("int DiagionalDistance[256] = {0};", 0x74D040, bytes(256 * 4)),
    ("int player_dropped[9] = {0};", 0x86BCA8, bytes(9 * 4)),
    ("char panel_string_buffer[0x200] = {0};", 0x62E670, bytes(512)),
    ("unsigned char ObstructionValueShift[4] = {0, 2, 4, 6};", 0x584EF4, bytes([0, 2, 4, 6])),
    ("unsigned char ObstructionValueMask[4] = {0xFC, 0xF3, 0xCF, 0x3F};", 0x584EF0, bytes.fromhex("fcf3cf3f")),
])
def test_shared_arrays_match_original(declaration, address, expected):
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    offset = address - image.OPTIONAL_HEADER.ImageBase
    assert image.get_memory_mapped_image()[offset:offset + len(expected)] == expected
    section = image.get_section_by_rva(offset)
    assert section is not None
    assert section.Characteristics & 0x80000000  # Original writable storage.
    assert (ROOT / "src/game_globals.cpp").read_text().count(declaration) == 1


def test_runtime_table_initializers_match_original():
    evidence = json.loads((ROOT / "decomp_notes/executable_build_evidence/runtime_tables.json").read_text())
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == evidence["original_sha256"]
    image = pefile.PE(data=original)
    source = (ROOT / evidence["source"]).read_text()
    for name, table in evidence["tables"].items():
        pattern = r'\b' + re.escape(name) + r'\[(\d+)\]\s*=\s*\{(.*?)^\};'
        matches = re.findall(pattern, source, re.S | re.M)
        assert len(matches) == 1, name
        count, body = matches[0]
        assert int(count) == table["count"], name
        values = [int(value, 0) for value in re.findall(r'-?(?:0x[0-9A-Fa-f]+|\d+)', body)]
        row_format = "<" + table["format"]
        row_size = struct.calcsize(row_format)
        fields = len(struct.unpack(row_format, bytes(row_size)))
        assert len(values) == table["count"] * fields, name
        encoded = b"".join(struct.pack(row_format, *values[i:i + fields]) for i in range(0, len(values), fields))
        offset = int(table["address"], 16) - image.OPTIONAL_HEADER.ImageBase
        assert image.get_data(offset, len(encoded)) == encoded, name


def test_encrypt_table_uses_its_real_start():
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    code = image.get_data(0x520FEB - image.OPTIONAL_HEADER.ImageBase, 7)
    assert code[:3] == bytes.fromhex("8b0c8d")
    assert int.from_bytes(code[3:], "little") + 0x40 * 4 == 0x58B860
    assert "encrypt_table[static_cast<int>(c) - 0x40]" in (ROOT / "src/tribegam.cpp").read_text()


def test_compressed_file_state_uses_private_pointer_storage():
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    offset = 0x86B25C - image.OPTIONAL_HEADER.ImageBase
    assert image.get_memory_mapped_image()[offset:offset + 40] == bytes(40)
    source = (ROOT / "src/rge_fio.cpp").read_text()
    for name in ("compression_buffers", "buffers", "current", "file_buffers"):
        assert f"static unsigned char* {name};" in source
    assert "static long point;" in source
    assert "static int current_handle;" in source
    assert "DAT_0086b2" not in source
    assert "(int)calloc" not in source
