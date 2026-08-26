from __future__ import annotations

import re
from pathlib import Path

from common import REPO_ROOT


DEFAULT_FPO_PATH = REPO_ROOT / "build" / "004AB300_dumpbin_fpo.txt"
DEFAULT_OWNER_OVERRIDES_PATH = (
    REPO_ROOT / "config" / "original_owner_symbol_overrides.txt"
)


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


def load_original_owner_symbol_overrides(
    path: Path | None = None,
) -> dict[str, tuple[str, str]]:
    """Load reviewed PDB procedure symbols missing from the FPO table."""
    source = path or DEFAULT_OWNER_OVERRIDES_PATH
    overrides: dict[str, tuple[str, str]] = {}
    if not source.is_file():
        return overrides
    for line_number, line in enumerate(
        source.read_text(encoding="utf-8", errors="strict").splitlines(), 1
    ):
        text = line.strip()
        if not text or text.startswith("#"):
            continue
        parts = text.split()
        if len(parts) != 3 or re.fullmatch(r"[0-9A-Fa-f]{8}", parts[0]) is None:
            raise ValueError(f"Invalid owner symbol override at {source}:{line_number}")
        va = parts[0].upper()
        linkage = parts[2].lower()
        if linkage not in {"global", "local"}:
            raise ValueError(f"Invalid owner linkage at {source}:{line_number}")
        if va in overrides:
            raise ValueError(f"Duplicate owner symbol override for {va}")
        overrides[va] = (parts[1], linkage)
    return overrides


def load_original_owner_symbols(
    fpo_path: Path | None = None,
    overrides_path: Path | None = None,
) -> tuple[dict[str, str], dict[str, str]]:
    """Load the FPO oracle plus reviewed PDB procedure supplements."""
    symbols = load_original_fpo_symbols(fpo_path)
    linkages: dict[str, str] = {}
    for va, (symbol, linkage) in load_original_owner_symbol_overrides(
        overrides_path
    ).items():
        if va in symbols:
            raise ValueError(f"Owner symbol override overlaps FPO owner {va}")
        symbols[va] = symbol
        linkages[va] = linkage
    return symbols, linkages
