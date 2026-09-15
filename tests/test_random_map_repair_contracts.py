"""Source regression checks. Independent gameplay replay checks behavior."""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]


def test_prior_land_scan_starts_at_first_land_not_current_output():
    source = (ROOT / 'src/rmm_dbct.cpp').read_text()
    function = source.split('void RGE_RMM_Database_Controller::calc_land_start(', 1)[1].split(
        'void RGE_RMM_Database_Controller::add_land_module(', 1)[0]
    # Original 00483781 retains land[start].y in a fixed stack home.
    # 00483825 resets each scan from that home; 004838FE advances only output.
    assert re.search(r'prior\s*=\s*&this->land_info\.land\[land_index\]\.y\s*;', function)
    assert not re.search(r'prior\s*=\s*land_ptr\s*;', function)


def test_building_clearance_search_uses_original_three_tile_bounds():
    source = (ROOT / 'src/tworld.cpp').read_text()
    function = source.split('void TRIBE_World::check_destructables(', 1)[1].split(
        'void TRIBE_World::scenario_make_player(', 1)[0]
    # Original 0057755C holds 00004040 (+3.0); 00577560 holds 000040C0 (-3.0).
    for axis, coordinate in (('x', 'col'), ('y', 'row')):
        assert f'{axis}_min = static_cast<short>({coordinate} - 3.0f)' in function
        assert f'{axis}_max = static_cast<short>({coordinate} + 3.0f)' in function
