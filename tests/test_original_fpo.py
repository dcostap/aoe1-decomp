import sys
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from original_fpo import (  # noqa: E402
    load_original_fpo_symbols,
    load_original_owner_symbol_overrides,
    load_original_owner_symbols,
)


def test_load_original_fpo_symbols_maps_rva_to_va(tmp_path: Path) -> None:
    report = tmp_path / "fpo.txt"
    report.write_text(
        " 00001000       289       16     2        0   N   N    fpo        8  "
        "??0RGE_Action_Attack@@QAE@XZ (public)\n"
        "not an FPO row\n",
        encoding="utf-8",
    )

    assert load_original_fpo_symbols(report) == {
        "00401000": "??0RGE_Action_Attack@@QAE@XZ"
    }


def test_load_original_owner_symbol_overrides(tmp_path: Path) -> None:
    report = tmp_path / "owners.txt"
    report.write_text(
        "# PDB S_LPROC32 supplement\n"
        "00475930 ?pnl_sub_wnd_proc@@YGJPAXIIJ@Z local\n",
        encoding="utf-8",
    )

    assert load_original_owner_symbol_overrides(report) == {
        "00475930": ("?pnl_sub_wnd_proc@@YGJPAXIIJ@Z", "local")
    }


def test_load_original_owner_symbols_rejects_fpo_overlap(tmp_path: Path) -> None:
    fpo = tmp_path / "fpo.txt"
    fpo.write_text(
        " 00001000 289 16 2 0 N N fpo 8 original_symbol (public)\n",
        encoding="utf-8",
    )
    owners = tmp_path / "owners.txt"
    owners.write_text("00401000 original_symbol global\n", encoding="utf-8")

    try:
        load_original_owner_symbols(fpo, owners)
    except ValueError as error:
        assert "overlaps FPO owner 00401000" in str(error)
    else:
        raise AssertionError("Expected an overlap error")
