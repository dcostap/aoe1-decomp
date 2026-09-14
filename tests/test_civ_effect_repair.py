"""Check the civilization-effect argument against the original executable."""
import hashlib
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[1]


def test_new_game_uses_tribe_effect_not_graphics_culture():
    source=(ROOT/'src/tworld.cpp').read_text()
    body=source.split('unsigned char TRIBE_World::new_game(',1)[1].split(
        'unsigned char TRIBE_World::new_scenario(',1)[0]
    assert 'do_effect(static_cast<short>(this->players[i]->tribe_effect),' in body
    assert 'do_effect(this->players[i]->culture,' not in body
    assert 'do_effect(0xd2,' in body


def test_original_effect_call_reads_low_word_at_player_10c():
    data=(ROOT/'orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe').read_bytes()
    assert hashlib.sha256(data).hexdigest()=='88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90'
    pe=struct.unpack_from('<I',data,60)[0]
    count=struct.unpack_from('<H',data,pe+6)[0]
    table=pe+24+struct.unpack_from('<H',data,pe+20)[0]
    rva=0x52fd30-0x400000
    sections=[struct.unpack_from('<IIII',data,table+40*i+8) for i in range(count)]
    section=next(s for s in sections if s[1]<=rva<s[1]+min(s[0],s[2]))
    offset=section[3]+rva-section[1]
    assert data[offset:offset+11]==bytes.fromhex('66 8B 80 0C 01 00 00 50 FF 52 08')
