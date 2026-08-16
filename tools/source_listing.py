from __future__ import annotations

import bisect
import re
from pathlib import Path


_SOURCE_LINE_RE = re.compile(r"^;\s*(\d+)\s*:")
_OFFSET_RE = re.compile(r"^\s{2}([0-9A-Fa-f]{5,8})\s+[0-9A-Fa-f]{2}")
_STACK_SYMBOL_RE = re.compile(r"^_([^\s$]+)\$(\d*)\s*=\s*(-?\d+)\s*$")
_STACK_WIDTH_RE = re.compile(
    r"\b(BYTE|WORD|DWORD|QWORD)\s+PTR\s+_([^\s$+\-\[\]]+)\$(\d*)",
    re.IGNORECASE,
)
_TITLE_RE = re.compile(r"^\s*TITLE\s+(.+?)\s*$")
_WIDTH_BYTES = {"byte": 1, "word": 2, "dword": 4, "qword": 8}


def parse_listing(text: str) -> dict[str, object]:
    current_line: int | None = None
    source_path = ""
    changes: list[dict[str, int]] = []
    locals_by_key: dict[tuple[str, int], dict[str, object]] = {}
    homes_by_key: dict[tuple[str, str, int], dict[str, object]] = {}
    last_recorded_line: int | None = None
    for raw_line in text.splitlines():
        if not source_path:
            title = _TITLE_RE.match(raw_line)
            if title:
                source_path = title.group(1).strip()
        source_match = _SOURCE_LINE_RE.match(raw_line)
        if source_match:
            current_line = int(source_match.group(1), 10)
            continue
        symbol_match = _STACK_SYMBOL_RE.match(raw_line)
        if symbol_match:
            name = symbol_match.group(1)
            suffix = symbol_match.group(2)
            offset = int(symbol_match.group(3), 10)
            kind = "parameter" if not suffix else "local"
            homes_by_key[(name, suffix, offset)] = {
                "name": name,
                "kind": kind,
                "offset": offset,
                # VC5 listing symbols use the canonical EBP frame. At function
                # entry, that coordinate is four bytes lower because of saved EBP.
                "entry_coordinate": offset - 4,
                "widths": [],
            }
            if kind == "local":
                locals_by_key[(name, offset)] = {"name": name, "offset": offset}
            continue
        offset_match = _OFFSET_RE.match(raw_line)
        if offset_match and current_line is not None:
            offset = int(offset_match.group(1), 16)
            if current_line != last_recorded_line:
                changes.append({"offset": offset, "line": current_line})
                last_recorded_line = current_line
    # Optimized block placement can make listing offsets decrease relative to
    # source order. Lookup needs address order, with the last marker at a given
    # offset winning.
    by_offset: dict[int, int] = {}
    for row in changes:
        by_offset[int(row["offset"])] = int(row["line"])
    ordered_changes = [
        {"offset": offset, "line": line}
        for offset, line in sorted(by_offset.items())
    ]
    observed_widths: dict[tuple[str, str], set[int]] = {}
    for width_name, name, suffix in _STACK_WIDTH_RE.findall(text):
        observed_widths.setdefault((name, suffix), set()).add(_WIDTH_BYTES[width_name.lower()])
    for (name, suffix, _), row in homes_by_key.items():
        row["widths"] = sorted(observed_widths.get((name, suffix), set()))
    return {
        "source": source_path,
        "line_changes": ordered_changes,
        "stack_locals": sorted(locals_by_key.values(), key=lambda row: (int(row["offset"]), str(row["name"]))),
        "stack_homes": sorted(
            homes_by_key.values(),
            key=lambda row: (int(row["entry_coordinate"]), str(row["kind"]), str(row["name"])),
        ),
    }


def parse_listing_file(path: Path) -> dict[str, object]:
    return parse_listing(path.read_text(encoding="utf-8", errors="replace"))


def source_line_for_offset(metadata: dict[str, object] | None, offset: int) -> int | None:
    if not metadata:
        return None
    rows = list(metadata.get("line_changes") or [])
    if not rows:
        return None
    offsets = [int(row["offset"]) for row in rows]
    index = bisect.bisect_right(offsets, offset) - 1
    return None if index < 0 else int(rows[index]["line"])
