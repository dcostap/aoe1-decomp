from __future__ import annotations

import re
from pathlib import Path

from common import REPO_ROOT


DEFAULT_FPO_PATH = REPO_ROOT / "build" / "004AB300_dumpbin_fpo.txt"


def load_original_fpo_symbols(path: Path | None = None) -> dict[str, str]:
    """Load original executable RVA owners from dumpbin /fpo output."""
    source = path or DEFAULT_FPO_PATH
    symbols: dict[str, str] = {}
    for line in source.read_text(encoding="utf-8", errors="ignore").splitlines():
        parts = line.split()
        if len(parts) < 10 or re.fullmatch(r"[0-9A-Fa-f]{8}", parts[0]) is None:
            continue
        va = 0x400000 + int(parts[0], 16)
        symbols[f"{va:08X}"] = parts[9]
    return symbols
