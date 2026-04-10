from __future__ import annotations

import argparse
import difflib
import json
from pathlib import Path

from coff import mask_relocations
from common import ensure_build_subdir, function_record_by_va, function_slug, repo_path


def first_mismatch_offset(left: bytes, right: bytes) -> int | None:
    limit = min(len(left), len(right))
    for index in range(limit):
        if left[index] != right[index]:
            return index
    if len(left) != len(right):
        return limit
    return None


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compare original and rebuilt function outputs.")
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    asm_dir = repo_path(Path("build") / "asm")
    diff_dir = ensure_build_subdir("diff")

    orig_bin = asm_dir / f"orig_{slug}.bin"
    rebuilt_bin = asm_dir / f"rebuilt_{slug}.bin"
    rebuilt_json = asm_dir / f"rebuilt_{slug}.json"
    orig_asm = asm_dir / f"orig_{slug}.txt"
    rebuilt_asm = asm_dir / f"rebuilt_{slug}.txt"
    report_path = diff_dir / f"{slug}.txt"

    if not orig_bin.exists():
        raise SystemExit(f"Missing original bytes: {orig_bin}")
    if not rebuilt_bin.exists():
        raise SystemExit(f"Missing rebuilt bytes: {rebuilt_bin}")
    if not rebuilt_json.exists():
        raise SystemExit(f"Missing rebuilt metadata: {rebuilt_json}")

    original_bytes = orig_bin.read_bytes()
    rebuilt_bytes = rebuilt_bin.read_bytes()
    rebuilt_meta = json.loads(rebuilt_json.read_text(encoding="utf-8"))
    masked_original = original_bytes
    masked_rebuilt = rebuilt_bytes

    relocation_count = 0
    if rebuilt_meta.get("relocations"):
        relocation_count = len(rebuilt_meta["relocations"])
        masked_original = bytearray(original_bytes)
        for reloc in rebuilt_meta["relocations"]:
            offset = int(reloc["offset"])
            width = int(reloc["width"])
            end = min(len(masked_original), offset + width)
            for index in range(offset, end):
                masked_original[index] = 0
        masked_original = bytes(masked_original)
        masked_rebuilt = mask_relocations(
            rebuilt_bytes,
            [],
        )
        masked_rebuilt = bytearray(masked_rebuilt)
        for reloc in rebuilt_meta["relocations"]:
            offset = int(reloc["offset"])
            width = int(reloc["width"])
            end = min(len(masked_rebuilt), offset + width)
            for index in range(offset, end):
                masked_rebuilt[index] = 0
        masked_rebuilt = bytes(masked_rebuilt)

    mismatch = first_mismatch_offset(masked_original, masked_rebuilt)
    lines: list[str] = []
    lines.append(f"Function: {record['name']} ({record['va']})")
    lines.append(f"Original bytes: {len(original_bytes)}")
    lines.append(f"Rebuilt bytes: {len(rebuilt_bytes)}")
    lines.append(f"Relocations masked: {relocation_count}")

    if mismatch is None:
        lines.append("Result: MATCH")
        report_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print("\n".join(lines))
        raise SystemExit(0)

    lines.append("Result: MISMATCH")
    lines.append(f"First mismatch offset: {mismatch}")
    window_start = max(0, mismatch - 8)
    window_end = min(max(len(masked_original), len(masked_rebuilt)), mismatch + 8)
    lines.append(f"Original window: {masked_original[window_start:window_end].hex()}")
    lines.append(f"Rebuilt  window: {masked_rebuilt[window_start:window_end].hex()}")

    if orig_asm.exists() and rebuilt_asm.exists():
        original_text = orig_asm.read_text(encoding="utf-8").splitlines()
        rebuilt_text = rebuilt_asm.read_text(encoding="utf-8").splitlines()
        lines.append("")
        lines.append("Asm diff:")
        diff_lines = difflib.unified_diff(original_text, rebuilt_text, fromfile=str(orig_asm.name), tofile=str(rebuilt_asm.name), lineterm="")
        lines.extend(list(diff_lines)[:200])

    report_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("\n".join(lines))
    raise SystemExit(1)


if __name__ == "__main__":
    main()
