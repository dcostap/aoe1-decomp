"""Guard the font index and metrics layout against the original executable."""
import hashlib
import json
from pathlib import Path
import re

import pefile

ROOT = Path(__file__).resolve().parents[1]


def test_original_font_index_is_outside_metrics():
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    base = image.OPTIONAL_HEADER.ImageBase

    def code(va, expected):
        expected = bytes.fromhex(expected)
        assert image.get_data(va - base, len(expected)) == expected

    code(0x41F5C4, "89442414")  # Save the promoted loop index at S+0x14.
    code(0x41F681, "8d442418")  # Pass the metrics object at S+0x18.
    code(0x41F68D, "8b442414")  # Read the saved index, not tmHeight.
    code(0x41F697, "5553")  # Two pending SelectObject arguments lower ESP by 8.
    code(0x41F6A8, "8b4c2434")  # S+0x2C: metrics offset 0x14, average width.
    code(0x41F6B0, "8b542420")  # S+0x18: metrics offset zero, height.
    code(0x41F6B4, "8b4c2430")  # S+0x28: metrics offset 0x10, external leading.
    code(0x41F6B8, "03d1")  # Add height and external leading.


def test_source_uses_independent_index_and_complete_metrics():
    source = (ROOT / "src/basegame.cpp").read_text()
    body = re.search(r"int RGE_Base_Game::setup_fonts\(\)\s*\{(.*?)^\}", source, re.S | re.M)[1]
    assert "short i;" in body
    assert "TEXTMETRICA tm;" in body
    assert "GetTextMetricsA(dc, &tm);" in body
    assert "this->fonts[i].font = font;" in body
    assert "this->fonts[i].font_wid = tm.tmAveCharWidth;" in body
    assert "this->fonts[i].font_hgt = tm.tmHeight + tm.tmExternalLeading;" in body
    assert "font_index" not in body
    assert not re.search(r"tm\.tmHeight\s*=(?!=)", body)
