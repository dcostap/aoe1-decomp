"""Small source-data regressions; runtime comparisons remain the behavior check."""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]


def test_setup_format_covers_all_original_output_arguments():
    source = (ROOT/'src/Panel_ez.cpp').read_text()
    call = re.search(r'sscanf\(\(char\*\)info_data,\s*((?:"[^"]*"\s*)+),\s*(.*?)\) != -1',
                     source, re.S)
    assert call is not None
    conversions = re.findall(r'%[sd]', call[1])
    arguments = [value.strip() for value in call[2].split(',')]
    # Original format at 00584D5C has 65 conversions, including the final state color.
    assert len(conversions) == len(arguments) == 65
    assert arguments[-4:] == ['temp_label', '&s2r', '&s2g', '&s2b']


def test_list_key_labels_match_original_switch_data():
    source = (ROOT/'src/pnl_lst.cpp').read_text()
    function = source.split('long TListPanel::key_down_action(', 1)[1].split(
        'long TListPanel::char_action(', 1)[0]
    labels = {int(key, 16): int(action) for key, action in re.findall(
        r'case\s+(0x[0-9A-Fa-f]+):\s*this->scroll_cur_line\((\d+),\s*0,\s*1\)', function)}
    # Original selector 00478828 and pointer table 00478808; not covered by local code equality.
    assert labels == {0x28:2, 0x26:3, 0x22:4, 0x21:5, 0x24:6, 0x23:7}


def test_game_screen_label_buttons_use_text_drawing():
    source = (ROOT/'src/scr_game.cpp').read_text()
    # Original constructor passes 3 at 00494678, 0049472E, and 0049479C.
    # The loop configures three buttons; the two later calls configure S and ?.
    assert source.count('setDrawType(TButtonPanel::DrawText)') == 3
    assert 'setDrawType(TButtonPanel::DrawPicture)' not in source
