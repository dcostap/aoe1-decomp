"""Guard wrapping cursor and temporary-buffer boundaries."""
import hashlib
import json
from pathlib import Path
import re

import pefile

ROOT = Path(__file__).resolve().parents[1]


def test_original_wrap_uses_lookahead_and_complete_buffer():
    config = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / config["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == config["original_sha256"]
    image = pefile.PE(data=original)
    base = image.OPTIONAL_HEADER.ImageBase

    def code(va, expected):
        expected = bytes.fromhex(expected)
        assert image.get_data(va - base, len(expected)) == expected

    # The first result supplies a byte length, not a new EDI cursor.
    code(0x47C815, "e866250d002bc683c404")
    # Only the second result replaces EDI. EBX counts one character.
    code(0x47C848, "e833250d0083c40443")
    code(0x47C854, "8bf8")
    # Both clear and copy use S+0x80. The copy address follows one push.
    code(0x47C95C, "8dbc2480000000f3ab")
    code(0x47C968, "578d842484000000")
    assert 0x84 - 4 == 0x80


def test_wrap_source_preserves_cursor_and_buffer_boundaries():
    source = (ROOT / "src/Pnl_txt.cpp").read_text()
    body = re.search(
        r"int TTextPanel::word_wrap_append\([^)]*\)\s*\{(.*?)^\}",
        source, re.S | re.M,
    )[1]
    fitting = body.split("while (chars < (short)text_len) {", 1)[1]
    fitting = fitting.split("while (chars > 1)", 1)[0]
    assert fitting.count("next_char = _mbsinc(next_char);") == 1
    assert fitting.index("len = _mbsinc(next_char)") < fitting.index("if (text_size.cx > max_wid)")
    assert fitting.index("if (text_size.cx > max_wid)") < fitting.index("next_char = _mbsinc(next_char);")
    assert "unsigned char temp_text[256];" in body
    assert "memset(temp_text, 0, 256);" in body
    assert "_mbsncpy(temp_text," in body
    assert "append_line((char*)temp_text, 0);" in body
    assert not re.search(r"temp_text\s*\+", body)
