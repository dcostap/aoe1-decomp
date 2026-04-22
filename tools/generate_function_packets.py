from __future__ import annotations

import argparse
import re
from pathlib import Path

from iced_x86 import Decoder, DecoderOptions, Formatter, FormatterSyntax

from common import (
    ensure_dir,
    format_hex,
    function_by_start,
    function_record_by_va,
    function_slug,
    load_binaries,
    load_functions,
    load_layout,
    load_pdb_function_line_changes,
    load_pdb_function_source_map,
    load_pe_image,
    parse_hex,
    repo_path,
)


ADDRESS_LINE_RE = re.compile(r"^\s*([0-9A-Fa-f]{8})\b")
DECOMP_OFFSET_RE = re.compile(r"^\s*// Offset: 0x([0-9A-Fa-f]{8})\s*$")


def decode_bytes(code_bytes: bytes, start_va: int) -> list[dict[str, str]]:
    decoder = Decoder(32, code_bytes, ip=start_va, options=DecoderOptions.NONE)
    formatter = Formatter(FormatterSyntax.NASM)
    lines: list[dict[str, str]] = []
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


def layout_ranges(entry: dict, fallback_va: int, fallback_size: int) -> list[tuple[int, int]]:
    ranges: list[tuple[int, int]] = []
    for body_range in entry.get("body_ranges", []):
        start = parse_hex(body_range.get("start"))
        end = parse_hex(body_range.get("end"))
        if start is None or end is None or end < start:
            continue
        ranges.append((start, end))
    if ranges:
        return ranges
    return [(fallback_va, fallback_va + fallback_size - 1)]


def build_listing_index(lines: list[str]) -> dict[str, int]:
    index: dict[str, int] = {}
    for line_index, line in enumerate(lines):
        match = ADDRESS_LINE_RE.match(line)
        if not match:
            continue
        address = match.group(1).upper()
        index.setdefault(address, line_index)
    return index


def build_decomp_index(decomp_root: Path) -> dict[str, tuple[str, list[str]]]:
    index: dict[str, tuple[str, list[str]]] = {}
    if not decomp_root.exists():
        return index

    for decomp_path in sorted(decomp_root.rglob("*.decomp")):
        lines = decomp_path.read_text(encoding="utf-8", errors="replace").splitlines()
        offsets: list[tuple[int, str]] = []
        for line_index, line in enumerate(lines):
            match = DECOMP_OFFSET_RE.match(line)
            if not match:
                continue
            offsets.append((line_index, match.group(1).upper()))

        for offset_index, (line_index, va) in enumerate(offsets):
            next_line_index = offsets[offset_index + 1][0] if offset_index + 1 < len(offsets) else len(lines)
            snippet = lines[line_index:next_line_index]
            index.setdefault(va, (str(decomp_path.relative_to(decomp_root)), snippet))
    return index


def listing_excerpt(lines: list[str], listing_index: dict[str, int], decoded_blocks: list[list[dict[str, str]]]) -> list[str]:
    first_address: str | None = None
    last_address: str | None = None
    for block in decoded_blocks:
        if not block:
            continue
        if first_address is None:
            first_address = block[0]["address"]
        last_address = block[-1]["address"]

    if first_address is None or last_address is None:
        return ["<no decoded instructions>"]

    start_line = listing_index.get(first_address)
    end_line = listing_index.get(last_address)
    if start_line is None or end_line is None:
        return [f"<listing excerpt unavailable for {first_address}-{last_address}>"]

    excerpt_start = max(0, start_line - 12)
    excerpt_end = min(len(lines), end_line + 13)
    for probe in range(end_line + 1, excerpt_end):
        if "****************************************************************" in lines[probe]:
            excerpt_end = probe
            break
    return lines[excerpt_start:excerpt_end]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate committed per-function raw packets for agents.")
    parser.add_argument("--va", help="Generate a packet for one function VA in hex. When omitted, generate all packets.")
    return parser.parse_args()


def pdb_line_span(summary: dict[str, str] | None) -> str:
    if not summary:
        return "<none>"
    start = summary.get("line_start", "").strip()
    end = summary.get("line_end", "").strip()
    if not start or not end:
        return "<none>"
    return f"{start}-{end}"


def pdb_line_comment_index(line_changes: list[dict[str, str]]) -> dict[str, str]:
    comments: dict[str, str] = {}
    for change in line_changes:
        address = (change.get("address") or "").strip().upper()
        line_number = (change.get("line_number") or "").strip()
        if not address or not line_number:
            continue
        source_file = (change.get("source_file") or "").strip()
        source_path = (change.get("source_path") or "").strip()
        if not source_file and source_path:
            source_file = Path(source_path).name
        comments[address] = f"{source_file or '<unknown>'}: {line_number}"
    return comments


def main() -> None:
    args = parse_args()
    binaries = load_binaries()
    exe = load_pe_image(repo_path(binaries["original_exe"]))
    layout = load_layout(repo_path(binaries["ghidra_layout"]))
    pdb_source_map = load_pdb_function_source_map()
    pdb_line_changes = load_pdb_function_line_changes()
    listing_lines = repo_path(binaries["ghidra_listing"]).read_text(encoding="utf-8", errors="replace").splitlines()
    listing_index = build_listing_index(listing_lines)
    decomp_root = repo_path(binaries["ghidra_decomp_root"])
    decomp_index = build_decomp_index(decomp_root)

    if args.va:
        records = [function_record_by_va(int(args.va, 16))]
    else:
        records = load_functions()

    function_dir = repo_path("inventory") / "functions"
    ensure_dir(function_dir)

    written = 0
    for record in records:
        va = int(record["va"], 16)
        slug = function_slug(record)
        try:
            layout_entry = function_by_start(layout, va)
        except KeyError:
            layout_entry = {"body_ranges": []}

        ranges = layout_ranges(layout_entry, va, int(record["size_bytes"]))
        decoded_blocks: list[list[dict[str, str]]] = []
        for range_start, range_end in ranges:
            code_bytes = exe.read_va_range(range_start, range_end)
            decoded_blocks.append(decode_bytes(code_bytes, range_start))

        shard_dir = function_dir / record["va"][:4]
        ensure_dir(shard_dir)
        packet_path = shard_dir / f"{slug}.txt"
        source_summary = pdb_source_map.get(record["va"].upper())
        line_changes = pdb_line_changes.get(record["va"].upper(), [])
        line_comment_index = pdb_line_comment_index(line_changes)

        packet_lines: list[str] = []
        packet_lines.append(f"VA: {record['va']}")
        packet_lines.append(f"Name: {record['name']}")
        packet_lines.append(f"Slug: {slug}")
        packet_lines.append(f"SizeBytes: {record['size_bytes']}")
        packet_lines.append(f"AsmLines: {record.get('asm_lines', '')}")
        packet_lines.append(f"CallingConvention: {record.get('calling_convention', 'unknown')}")
        packet_lines.append(
            f"PdbSourceFile: {(source_summary or {}).get('primary_source_file', '') or '<none>'}"
        )
        packet_lines.append(
            f"PdbSourcePath: {(source_summary or {}).get('primary_source_path', '') or '<none>'}"
        )
        packet_lines.append(f"PdbLineSpan: {pdb_line_span(source_summary)}")
        packet_lines.append(f"PdbLineRecordCount: {(source_summary or {}).get('line_record_count', '0')}")
        packet_lines.append(f"BodyRangeCount: {len(ranges)}")
        packet_lines.append("")
        packet_lines.append("=== PdbSource ===")
        if source_summary is None:
            packet_lines.append("<pdb source unavailable>")
        else:
            packet_lines.append(
                f"PrimarySource: {source_summary.get('primary_source_path', '') or '<none>'}"
            )
            packet_lines.append(
                f"DirectSource: {source_summary.get('direct_source_path', '') or '<none>'}"
            )
            packet_lines.append(f"LineSpan: {pdb_line_span(source_summary)}")
            packet_lines.append(f"LineRecords: {source_summary.get('line_record_count', '0')}")
            packet_lines.append(f"LineChanges: {source_summary.get('line_change_count', '0')}")
            packet_lines.append(f"UniqueLineFiles: {source_summary.get('unique_file_count', '0')}")
            packet_lines.append("LineChangeMap:")
            if not line_changes:
                packet_lines.append("  <none>")
            else:
                for change in line_changes:
                    packet_lines.append(
                        f"  {change['address']} -> {change['source_file']}:{change['line_number']}"
                    )
        packet_lines.append("")
        packet_lines.append("=== BodyRanges ===")
        for range_start, range_end in ranges:
            packet_lines.append(f"{format_hex(range_start)}-{format_hex(range_end)}")
        packet_lines.append("")
        packet_lines.append("=== OriginalAsm ===")
        for block_index, decoded in enumerate(decoded_blocks):
            range_start, range_end = ranges[block_index]
            packet_lines.append(f"{format_hex(range_start)}-{format_hex(range_end)}")
            for line in decoded:
                asm_line = f"  {line['address']}  {line['bytes']:<16}  {line['text']}"
                comment = line_comment_index.get(line["address"].upper())
                if comment:
                    packet_lines.append(f"{asm_line:<64} ; {comment}")
                else:
                    packet_lines.append(asm_line)
            packet_lines.append("")
        packet_lines.append("=== GhidraListingExcerpt ===")
        packet_lines.extend(listing_excerpt(listing_lines, listing_index, decoded_blocks))
        packet_lines.append("")
        packet_lines.append("=== GhidraDecompilerExcerpt ===")
        decomp_entry = decomp_index.get(record["va"].upper())
        if decomp_entry is None:
            packet_lines.append("<decompiler excerpt unavailable>")
        else:
            decomp_rel_path, decomp_lines = decomp_entry
            packet_lines.append(f"Source: {decomp_rel_path}")
            packet_lines.extend(decomp_lines)
        packet_lines.append("")

        packet_path.write_text("\n".join(packet_lines), encoding="utf-8")
        written += 1

    if args.va:
        print(f"Wrote 1 packet to {packet_path}")
    else:
        print(f"Wrote {written} packets under {function_dir}")


if __name__ == "__main__":
    main()
