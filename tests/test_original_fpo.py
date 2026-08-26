import sys
from pathlib import Path

TOOLS_DIR = Path(__file__).resolve().parents[1] / "tools"
if str(TOOLS_DIR) not in sys.path:
    sys.path.insert(0, str(TOOLS_DIR))

from original_fpo import load_original_fpo_symbols  # noqa: E402


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
