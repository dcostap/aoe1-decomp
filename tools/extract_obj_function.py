from __future__ import annotations

import argparse
import json
from pathlib import Path

from iced_x86 import Decoder, DecoderOptions, Formatter, FormatterSyntax

from coff import load_coff_section
from common import ensure_build_subdir, format_hex, function_record_by_va, function_slug, repo_path


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
    parser = argparse.ArgumentParser(description="Extract .text bytes and relocations from a COFF object.")
    parser.add_argument("--va", help="Function VA in hex, used for naming and disassembly IP.")
    parser.add_argument("--obj", type=Path, help="Explicit object path. Defaults to build\\obj\\<slug>.obj when --va is used.")
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

    section = load_coff_section(obj_path, ".text")
    extracted_bytes = section.data
    if record is not None:
        expected_size = int(record["size_bytes"], 10)
        if expected_size <= 0:
            raise SystemExit(f"Invalid size_bytes for {record['va']}: {record['size_bytes']}")
        if expected_size > len(section.data):
            raise SystemExit(
                f"Configured function size {expected_size} exceeds .text section size {len(section.data)} for {obj_path}"
            )
        extracted_bytes = section.data[:expected_size]

    out_dir = ensure_build_subdir("asm")
    bin_path = out_dir / f"rebuilt_{slug}.bin"
    json_path = out_dir / f"rebuilt_{slug}.json"
    asm_path = out_dir / f"rebuilt_{slug}.txt"

    metadata = {
        "object": str(obj_path),
        "section_name": section.name,
        "section_size_bytes": len(section.data),
        "size_bytes": len(extracted_bytes),
        "relocations": [
            {
                "offset": reloc.offset,
                "type": f"0x{reloc.reloc_type:04X}",
                "width": reloc.width,
                "symbol_index": reloc.symbol_index,
            }
            for reloc in section.relocations
            if reloc.offset < len(extracted_bytes)
        ],
    }

    bin_path.write_bytes(extracted_bytes)
    json_path.write_text(json.dumps(metadata, indent=2), encoding="utf-8")
    asm_lines = decode_bytes(extracted_bytes, va)
    asm_path.write_text(
        "\n".join(f"{line['address']}  {line['bytes']:<16}  {line['text']}" for line in asm_lines) + "\n",
        encoding="utf-8",
    )

    print(f"Wrote {bin_path}")
    print(f"Wrote {json_path}")
    print(f"Wrote {asm_path}")


if __name__ == "__main__":
    main()
