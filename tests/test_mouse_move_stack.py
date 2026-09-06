"""Guard the original mouse-handler stack object boundaries."""
import hashlib
import json
from pathlib import Path
import re

import pefile

ROOT = Path(__file__).resolve().parents[1]


def test_original_mouse_point_fits_below_return_address():
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    base = image.OPTIONAL_HEADER.ImageBase

    def code(va, expected):
        expected = bytes.fromhex(expected)
        assert image.get_data(va - base, len(expected)) == expected

    code(0x421110, "83ec1856")  # Reserve 24 bytes, then save ESI.
    code(0x42112C, "57")  # Save EDI on the ready path.
    code(0x421164, "8d442408")  # Last flag output at S+8.
    code(0x421172, "8d44241c")  # First flag output at S+0x14, after two pushes.
    code(0x42117B, "8d4c2424")  # Complete POINT at S+0x18, after three pushes.
    frame_size, saved_register_bytes = 0x18, 8
    point_offset, point_size = 0x24 - 12, 8
    return_offset = frame_size + saved_register_bytes
    assert point_offset + point_size == return_offset
    # The old 20-byte frame placed the second POINT write on the return address.
    assert point_offset + 4 == 0x14 + saved_register_bytes


def test_mouse_handler_passes_complete_point_and_all_flags():
    source = (ROOT / "src/basegame.cpp").read_text()
    body = re.search(r"int RGE_Base_Game::handle_mouse_move\([^)]*\)\s*\{(.*?)^\}", source, re.S | re.M)[1]
    assert "tagPOINT point;" in body
    assert "int shift_key;" in body
    assert "get_mouse_info(p3, p4, point, left_btn, right_btn, ctrl_key, shift_key);" in body
    assert "action_mouse_move(point.x, point.y, left_btn, right_btn, ctrl_key, shift_key);" in body
    assert "reinterpret_cast" not in body
    assert "&point.y" not in body
