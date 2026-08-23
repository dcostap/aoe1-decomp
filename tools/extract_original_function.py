from __future__ import annotations

import argparse
import json
from pathlib import Path

from iced_x86 import Decoder, DecoderOptions, Formatter, FormatterSyntax

from common import (
    ensure_build_subdir,
    format_hex,
    function_by_start,
    function_record_by_va,
    function_slug,
    load_binaries,
    load_layout,
    load_pe_image,
    owned_function_ranges,
    repo_path,
)


def decode_bytes(code_bytes: bytes, start_va: int) -> list[dict]:
    decoder = Decoder(32, code_bytes, ip=start_va, options=DecoderOptions.NONE)
    formatter = Formatter(FormatterSyntax.NASM)
    lines: list[dict] = []
    while decoder.can_decode:
        instruction = decoder.decode()
        offset = instruction.ip - start_va
        next_offset = instruction.next_ip - start_va
        instruction_bytes = code_bytes[offset:next_offset]
        lines.append(
            {
                "address": format_hex(instruction.ip),
                "bytes": instruction_bytes.hex(),
                "text": formatter.format(instruction),
            }
        )
    return lines


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Extract original function bytes and disassembly from the reference EXE.")
    parser.add_argument("--va", required=True, help="Function start VA in hex, for example 00449750.")
    parser.add_argument("--size", type=int, help="Override size in bytes. When omitted, use the inventory or Ghidra layout.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    binaries = load_binaries()
    exe = load_pe_image(repo_path(binaries["original_exe"]))
    layout = load_layout(repo_path(binaries["ghidra_layout"]))
    record = function_record_by_va(va)

    ranges: list[tuple[int, int]] = []
    included_fragments: list[int] = []
    layout_function: dict | None = None
    try:
        layout_function = function_by_start(layout, va)
    except KeyError:
        layout_function = None
    else:
        ranges, included_fragments = owned_function_ranges(layout, va)

    if not ranges:
        size = args.size or int(record["size_bytes"])
        ranges = [(va, va + size - 1)]

    out_dir = ensure_build_subdir("asm")
    slug = function_slug(record)
    bin_path = out_dir / f"orig_{slug}.bin"
    json_path = out_dir / f"orig_{slug}.json"
    asm_path = out_dir / f"orig_{slug}.txt"

    all_bytes = bytearray()
    all_lines: list[str] = []
    range_records: list[dict] = []
    for start, end in ranges:
        code_bytes = exe.read_va_range(start, end)
        all_bytes.extend(code_bytes)
        decoded = decode_bytes(code_bytes, start)
        range_records.append(
            {
                "start": format_hex(start),
                "end": format_hex(end),
                "size_bytes": len(code_bytes),
                "decoded": decoded,
            }
        )
        all_lines.append(f"{format_hex(start)}-{format_hex(end)}")
        for line in decoded:
            all_lines.append(f"  {line['address']}  {line['bytes']:<16}  {line['text']}")
        all_lines.append("")

    metadata = {
        "schema_version": 2,
        "va": format_hex(va),
        "name": record["name"],
        "record_size_bytes": int(record["size_bytes"]),
        "ranges": range_records,
        "binary": str(repo_path(binaries["original_exe"])),
        "layout_name": None if layout_function is None else layout_function.get("name"),
        "boundary_start": format_hex(ranges[0][0]) if ranges else None,
        "boundary_end": format_hex(ranges[-1][1]) if ranges else None,
        "parent_owned_fragments": [format_hex(fragment_va) for fragment_va in included_fragments],
        "combined_size_bytes": len(all_bytes),
    }

    bin_path.write_bytes(bytes(all_bytes))
    json_path.write_text(json.dumps(metadata, indent=2), encoding="utf-8")
    asm_path.write_text("\n".join(all_lines).rstrip() + "\n", encoding="utf-8")

    print(f"Wrote {bin_path}")
    print(f"Wrote {json_path}")
    print(f"Wrote {asm_path}")


if __name__ == "__main__":
    main()
