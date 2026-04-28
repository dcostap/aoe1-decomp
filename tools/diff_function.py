from __future__ import annotations

import argparse
import difflib
import json
from pathlib import Path

from coff import mask_relocations
from common import byte_diff_metrics, ensure_build_subdir, function_record_by_va, function_slug, repo_path


def format_edit_hunks(metrics: dict, original: bytes, rebuilt: bytes, limit: int = 12) -> list[str]:
    lines: list[str] = []
    opcodes = metrics.get("edit_opcodes") or []
    for opcode in opcodes[:limit]:
        tag = str(opcode["tag"])
        i1 = int(opcode["i1"])
        i2 = int(opcode["i2"])
        j1 = int(opcode["j1"])
        j2 = int(opcode["j2"])
        left_size = i2 - i1
        right_size = j2 - j1
        line = f"  {tag:<7} orig+{i1:04X}..{i2:04X} ({left_size:4d})  rebuilt+{j1:04X}..{j2:04X} ({right_size:4d})"
        if tag != "equal":
            left_hex = original[i1:i2].hex()
            right_hex = rebuilt[j1:j2].hex()
            if left_hex:
                line += f"  orig={left_hex[:48]}"
            if right_hex:
                line += f"  rebuilt={right_hex[:48]}"
        lines.append(line)
    if len(opcodes) > limit:
        lines.append(f"  ... {len(opcodes) - limit} more edit hunks")
    return lines


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

    metrics = byte_diff_metrics(masked_original, masked_rebuilt)
    mismatch_text = str(metrics["first_mismatch_offset"])
    mismatch = int(mismatch_text) if mismatch_text else None
    metrics_path = diff_dir / f"{slug}.json"
    metrics_payload = {
        "va": record["va"],
        "name": record["name"],
        "slug": slug,
        "relocations_masked": relocation_count,
        **metrics,
    }
    metrics_path.write_text(json.dumps(metrics_payload, indent=2), encoding="utf-8")

    lines: list[str] = []
    lines.append(f"Function: {record['name']} ({record['va']})")
    lines.append(f"Original bytes: {len(original_bytes)}")
    lines.append(f"Rebuilt bytes: {len(rebuilt_bytes)}")
    lines.append(f"Compared bytes: {metrics['compare_size']}")
    lines.append(f"Positional diff bytes: {metrics['diff_bytes']}")
    lines.append(f"Positional diff percent: {float(metrics['diff_percent']):.4f}%")
    lines.append(f"Positional diff spans: {metrics['diff_spans']}")
    lines.append(f"Edit diff bytes: {metrics['edit_diff_bytes']}")
    lines.append(f"Edit diff percent: {float(metrics['edit_diff_percent']):.4f}%")
    lines.append(
        "Edit inserts/deletes/replaces: "
        f"{metrics['edit_insert_bytes']} / {metrics['edit_delete_bytes']} / {metrics['edit_replace_bytes']}"
    )
    lines.append(f"Edit equal bytes: {metrics['edit_equal_bytes']}")
    lines.append(f"Likely shifted alignment: {'yes' if metrics['likely_shifted_alignment'] else 'no'}")
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
    lines.append("")
    lines.append("Edit/resync hunks:")
    lines.extend(format_edit_hunks(metrics, masked_original, masked_rebuilt))

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
