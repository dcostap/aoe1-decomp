from __future__ import annotations

import json
import re
from pathlib import Path

from common import REPO_ROOT


def _normalized_va(value: str) -> str:
    cleaned = value.strip().upper()
    if cleaned.startswith("0X"):
        cleaned = cleaned[2:]
    return f"{int(cleaned, 16):08X}"


def load_shared_global_evidence(root: Path | None = None) -> list[dict[str, object]]:
    repo_root = root or REPO_ROOT
    path = repo_root / "config" / "shared_abi_evidence.json"
    if not path.exists():
        return []
    payload = json.loads(path.read_text(encoding="utf-8"))
    rows = payload.get("globals") or []
    if not isinstance(rows, list):
        raise ValueError("config/shared_abi_evidence.json: globals must be a list")
    result: list[dict[str, object]] = []
    for row in rows:
        if not isinstance(row, dict):
            raise ValueError("config/shared_abi_evidence.json: each global must be an object")
        name = str(row.get("name") or "").strip()
        storage_va = str(row.get("storage_va") or "").strip()
        declaration = str(row.get("declaration") or "").strip()
        header = str(row.get("header") or "").strip()
        if not all((name, storage_va, declaration, header)):
            raise ValueError(
                "config/shared_abi_evidence.json: each global needs name, storage_va, declaration, and header"
            )
        result.append(
            {
                **row,
                "name": name,
                "storage_va": _normalized_va(storage_va),
                "declaration": declaration,
                "header": header,
                "provenance": "config/shared_abi_evidence.json (reviewed shared evidence)",
                "confidence": "reviewed-shared-evidence",
            }
        )
    return result


def shared_global_matches(
    rows: list[dict[str, object]], query: str
) -> list[dict[str, object]]:
    needle = query.casefold().strip()
    try:
        query_va = _normalized_va(query)
    except ValueError:
        query_va = ""
    result = []
    for row in rows:
        names = [str(row.get("name") or "")]
        aliases = row.get("aliases") or []
        if isinstance(aliases, list):
            names.extend(str(alias) for alias in aliases)
        if query_va == row.get("storage_va") or any(
            needle and needle in name.casefold() for name in names
        ):
            result.append(row)
    return result


def shared_globals_referenced_by_text(
    rows: list[dict[str, object]], text: str
) -> list[dict[str, object]]:
    result = []
    for row in rows:
        names = [str(row.get("name") or "")]
        aliases = row.get("aliases") or []
        if isinstance(aliases, list):
            names.extend(str(alias) for alias in aliases)
        name_match = any(
            name and re.search(rf"\b{re.escape(name)}\b", text, re.IGNORECASE)
            for name in names
        )
        storage_va = str(row.get("storage_va") or "")
        address_match = bool(
            storage_va
            and re.search(rf"(?:0x)?0*{re.escape(storage_va.lstrip('0'))}\b", text, re.IGNORECASE)
        )
        if name_match or address_match:
            result.append({**row, "matched_by": "name" if name_match else "storage-address"})
    return result


def shared_globals_by_address(
    rows: list[dict[str, object]],
) -> dict[str, dict[str, object]]:
    return {str(row["storage_va"]).upper(): row for row in rows}
