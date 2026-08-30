from __future__ import annotations

import argparse
import csv
from pathlib import Path

from iced_x86 import Decoder, DecoderOptions

from common import (
    ensure_dir,
    format_hex,
    load_binaries,
    load_layout,
    load_pe_image,
    load_pdb_function_source_map,
    parse_hex,
    repo_path,
    slugify_name,
)


def decode_instruction_count(code_bytes: bytes, start_va: int) -> int:
    decoder = Decoder(32, code_bytes, ip=start_va, options=DecoderOptions.NONE)
    count = 0
    while decoder.can_decode:
        decoder.decode()
        count += 1
    return count


def function_ranges(entry: dict) -> list[tuple[int, int]]:
    ranges: list[tuple[int, int]] = []
    for body_range in entry.get("body_ranges", []):
        start = parse_hex(body_range.get("start"))
        end = parse_hex(body_range.get("end"))
        if start is None or end is None or end < start:
            continue
        ranges.append((start, end))
    if ranges:
        return ranges

    start = parse_hex(entry.get("start"))
    end = parse_hex(entry.get("end"))
    if start is None or end is None or end < start:
        return []
    return [(start, end)]


def main() -> None:
    argparse.ArgumentParser(
        description="Generate the master function inventory from the original executable."
    ).parse_args()

    binaries = load_binaries()
    exe = load_pe_image(repo_path(binaries["original_exe"]))
    layout = load_layout(repo_path(binaries["ghidra_layout"]))
    pdb_source_map = load_pdb_function_source_map()

    inventory_dir = repo_path("inventory")
    ensure_dir(inventory_dir)
    inventory_path = inventory_dir / "all_functions.csv"

    rows: list[dict[str, str | int]] = []
    for entry in layout.get("functions", []):
        start = parse_hex(entry.get("start"))
        name = (entry.get("name") or "").strip()
        if start is None or not name:
            continue

        ranges = function_ranges(entry)
        if not ranges:
            continue

        size_bytes = 0
        asm_lines = 0
        for range_start, range_end in ranges:
            code_bytes = exe.read_va_range(range_start, range_end)
            size_bytes += len(code_bytes)
            asm_lines += decode_instruction_count(code_bytes, range_start)

        rows.append(
            {
                "va": format_hex(start),
                "name": name,
                "slug": f"{format_hex(start)}_{slugify_name(name)}",
                "size_bytes": size_bytes,
                "asm_lines": asm_lines,
                "calling_convention": entry.get("calling_convention") or "unknown",
                "body_range_count": len(ranges),
                "pdb_source_file": pdb_source_map.get(format_hex(start), {}).get("primary_source_file", ""),
                "pdb_source_path": pdb_source_map.get(format_hex(start), {}).get("primary_source_path", ""),
                "pdb_line_start": pdb_source_map.get(format_hex(start), {}).get("line_start", ""),
                "pdb_line_end": pdb_source_map.get(format_hex(start), {}).get("line_end", ""),
                "pdb_line_record_count": pdb_source_map.get(format_hex(start), {}).get("line_record_count", "0"),
                "pdb_line_change_count": pdb_source_map.get(format_hex(start), {}).get("line_change_count", "0"),
                "pdb_unique_file_count": pdb_source_map.get(format_hex(start), {}).get("unique_file_count", "0"),
                "pdb_has_line_info": pdb_source_map.get(format_hex(start), {}).get("has_line_info", "0"),
                "pdb_has_direct_source": pdb_source_map.get(format_hex(start), {}).get("has_direct_source", "0"),
            }
        )

    rows.sort(key=lambda row: row["va"])

    with inventory_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "va",
                "name",
                "slug",
                "size_bytes",
                "asm_lines",
                "calling_convention",
                "body_range_count",
                "pdb_source_file",
                "pdb_source_path",
                "pdb_line_start",
                "pdb_line_end",
                "pdb_line_record_count",
                "pdb_line_change_count",
                "pdb_unique_file_count",
                "pdb_has_line_info",
                "pdb_has_direct_source",
            ],
        )
        writer.writeheader()
        writer.writerows(rows)

    print(f"Wrote {inventory_path}")
    print(f"Functions: {len(rows)}")


if __name__ == "__main__":
    main()
