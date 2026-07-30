from __future__ import annotations

import argparse
import json
from pathlib import Path

from iced_x86 import Decoder, DecoderOptions, FlowControl, Formatter, FormatterSyntax

from coff import find_function_symbol, function_symbol_section, load_coff_object
from common import ensure_build_subdir, format_hex, function_record_by_va, function_slug, repo_path


PADDING_BYTES = {0x90, 0xCC}


def decode_bytes(code_bytes: bytes, start_va: int, relocations=()) -> list[dict]:
    relocation_rows = list(relocations)
    decoder = Decoder(32, code_bytes, ip=start_va, options=DecoderOptions.NONE)
    formatter = Formatter(FormatterSyntax.NASM)
    lines: list[dict] = []
    while decoder.can_decode:
        instruction = decoder.decode()
        offset = instruction.ip - start_va
        next_offset = instruction.next_ip - start_va
        instruction_bytes = code_bytes[offset:next_offset]
        related = [
            {
                "offset": relocation.offset,
                "type": f"0x{relocation.reloc_type:04X}",
                "width": relocation.width,
                "symbol_name": relocation.symbol_name,
            }
            for relocation in relocation_rows
            if offset <= relocation.offset < next_offset
        ]
        lines.append(
            {
                "offset": offset,
                "address": format_hex(instruction.ip),
                "bytes": instruction_bytes.hex(),
                "text": formatter.format(instruction),
                "relocations": related,
            }
        )
    return lines


def meaningful_code_size(data: bytes) -> int:
    """Return the section span without ordinary compiler alignment padding."""
    end = len(data)
    while end > 0 and data[end - 1] in PADDING_BYTES:
        end -= 1
    return end


def _reachable_boundary_escapes(data: bytes, expected_size: int, meaningful_size: int) -> list[int]:
    decoder = Decoder(32, data[:meaningful_size], ip=0, options=DecoderOptions.NONE)
    instructions: dict[int, tuple[int, int, int]] = {}
    while decoder.can_decode:
        instruction = decoder.decode()
        instructions[instruction.ip] = (instruction.next_ip, instruction.flow_control, instruction.near_branch_target)

    pending = [0]
    visited: set[int] = set()
    escapes: list[int] = []
    while pending:
        offset = pending.pop()
        if offset in visited or offset not in instructions:
            continue
        visited.add(offset)
        next_offset, flow_control, target = instructions[offset]
        successors: list[int] = []
        if flow_control in (FlowControl.NEXT, FlowControl.CALL, FlowControl.INDIRECT_CALL):
            successors.append(next_offset)
        elif flow_control == FlowControl.CONDITIONAL_BRANCH:
            successors.extend((next_offset, target))
        elif flow_control == FlowControl.UNCONDITIONAL_BRANCH:
            successors.append(target)
        if offset < expected_size < next_offset:
            escapes.append(offset)
        for successor in successors:
            if successor >= expected_size:
                if successor < meaningful_size:
                    escapes.append(successor)
            elif successor >= 0:
                pending.append(successor)
    return sorted(set(escapes))


def extraction_extent(
    data: bytes,
    expected_size: int | None,
    indirect_targets: list[int] | None = None,
) -> dict[str, object]:
    """Choose the comparison span without hiding code beyond the boundary."""
    meaningful_size = meaningful_code_size(data)
    effective_size = meaningful_size
    boundary_escapes: list[int] = []
    if expected_size is not None and meaningful_size > expected_size:
        boundary_escapes = _reachable_boundary_escapes(data, expected_size, meaningful_size)
        boundary_escapes.extend(
            target
            for target in (indirect_targets or [])
            if expected_size <= target < meaningful_size
        )
        boundary_escapes = sorted(set(boundary_escapes))
    has_code_overflow = bool(boundary_escapes)
    if expected_size is not None and not has_code_overflow and len(data) >= expected_size:
        # Extra bytes may be jump tables, EH data, or section alignment. They are
        # not part of the function unless entry-reachable control flow crosses the
        # inventory boundary.
        effective_size = expected_size
    comparison_size = meaningful_size if expected_size is None or has_code_overflow else expected_size
    comparison_size = min(comparison_size, len(data))
    overflow_offsets: list[int] = []
    if expected_size is not None and len(data) > expected_size:
        overflow_offsets = [
            offset for offset in range(expected_size, len(data)) if data[offset] not in PADDING_BYTES
        ]
    return {
        "meaningful_size": meaningful_size,
        "effective_size": effective_size,
        "comparison_size": comparison_size,
        "overflow_offsets": overflow_offsets,
        "boundary_escape_offsets": boundary_escapes,
        "has_code_overflow": has_code_overflow,
    }


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Extract one function and relocations from a COFF object.")
    parser.add_argument("--va", help="Function VA in hex, used for naming and disassembly IP.")
    parser.add_argument("--obj", type=Path, help="Explicit object path. Defaults to build\\obj\\<slug>.obj.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    if not args.va and not args.obj:
        raise SystemExit("Provide --va or --obj")

    record = None
    va = 0
    if args.va:
        va = int(args.va, 16)
        record = function_record_by_va(va)

    if args.obj:
        obj_path = repo_path(args.obj)
        slug = obj_path.stem
    else:
        assert record is not None
        slug = function_slug(record)
        obj_path = repo_path(Path("build") / "obj" / f"{slug}.obj")

    obj = load_coff_object(obj_path)
    wanted_name = "" if record is None else record["name"].lower()
    symbol = find_function_symbol(obj, lambda candidate: wanted_name in candidate.name.lower())
    section = function_symbol_section(obj, symbol)

    expected_size = None if record is None else int(record["size_bytes"], 10)
    symbol_by_index = {candidate.index: candidate for candidate in obj.symbols}
    indirect_targets: list[int] = []
    for relocation in section.relocations:
        if expected_size is None or relocation.offset < expected_size:
            continue
        target_symbol = symbol_by_index.get(relocation.symbol_index)
        if target_symbol is None or target_symbol.section_number != symbol.section_number:
            continue
        indirect_targets.append(target_symbol.value - symbol.value)
    extent = extraction_extent(section.data, expected_size, indirect_targets)
    meaningful_size = int(extent["meaningful_size"])
    effective_size = int(extent["effective_size"])
    comparison_size = int(extent["comparison_size"])

    extracted_bytes = section.data[:comparison_size]
    overflow_nonpadding_offsets = list(extent["overflow_offsets"])
    boundary_escape_offsets = list(extent["boundary_escape_offsets"])

    selected_relocations = [relocation for relocation in section.relocations if relocation.offset < len(extracted_bytes)]
    out_dir = ensure_build_subdir("asm")
    bin_path = out_dir / f"rebuilt_{slug}.bin"
    full_bin_path = out_dir / f"rebuilt_{slug}.full.bin"
    json_path = out_dir / f"rebuilt_{slug}.json"
    asm_path = out_dir / f"rebuilt_{slug}.txt"

    metadata = {
        "object": str(obj_path),
        "symbol": {
            "name": symbol.name,
            "value": symbol.value,
            "section_number": symbol.section_number,
        },
        "section_name": section.name,
        "section_index": section.index,
        "section_size_bytes": len(section.data),
        "expected_size_bytes": expected_size,
        "meaningful_size_bytes": meaningful_size,
        "effective_size_bytes": effective_size,
        "comparison_size_bytes": len(extracted_bytes),
        "overflow_nonpadding_bytes": len(overflow_nonpadding_offsets) if boundary_escape_offsets else 0,
        "trailing_auxiliary_nonpadding_bytes": 0 if boundary_escape_offsets else len(overflow_nonpadding_offsets),
        "overflow_first_offset": None if not overflow_nonpadding_offsets else overflow_nonpadding_offsets[0],
        "boundary_escape_offsets": boundary_escape_offsets,
        "size_status": "code-overflow" if boundary_escape_offsets else "within-expected-span",
        "size_bytes": len(extracted_bytes),
        "relocations": [
            {
                "offset": relocation.offset,
                "type": f"0x{relocation.reloc_type:04X}",
                "width": relocation.width,
                "symbol_index": relocation.symbol_index,
                "symbol_name": relocation.symbol_name,
            }
            for relocation in selected_relocations
        ],
    }

    bin_path.write_bytes(extracted_bytes)
    full_bin_path.write_bytes(section.data)
    asm_lines = decode_bytes(extracted_bytes, va, selected_relocations)
    metadata["decoded"] = asm_lines
    json_path.write_text(json.dumps(metadata, indent=2), encoding="utf-8")
    rendered_lines = []
    for line in asm_lines:
        rendered = f"{line['address']}  {line['bytes']:<16}  {line['text']}"
        if line["relocations"]:
            descriptions = [
                f"COFF {row['type']} -> {row['symbol_name'] or '<unnamed>'}"
                for row in line["relocations"]
            ]
            rendered += "  ; " + "; ".join(descriptions)
        rendered_lines.append(rendered)
    asm_path.write_text(
        "\n".join(rendered_lines) + "\n",
        encoding="utf-8",
    )

    print(f"Extracted {symbol.name} from COFF section {section.index} ({section.name})")
    if expected_size is not None:
        delta = effective_size - expected_size
        print(
            f"Expected {expected_size} bytes; rebuilt effective code span {effective_size} "
            f"({delta:+d}); section span {len(section.data)}"
        )
    print(f"Wrote {bin_path}")
    print(f"Wrote {json_path}")
    print(f"Wrote {asm_path}")


if __name__ == "__main__":
    main()
