from __future__ import annotations

import argparse
import difflib
import json
from pathlib import Path

from common import byte_diff_metrics, ensure_build_subdir, function_record_by_va, function_slug, repo_path
from function_diagnostics import (
    call_fingerprint,
    compatible_relocation_masks,
    control_flow_summary,
    decode_instructions,
    instruction_alignment,
    iteration_delta,
    paired_instruction_context,
    prologue_summary,
)


def format_edit_hunks(metrics: dict, original: bytes, rebuilt: bytes, limit: int = 8) -> list[str]:
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
                line += f"  orig={left_hex[:32]}"
            if right_hex:
                line += f"  rebuilt={right_hex[:32]}"
        lines.append(line)
    if len(opcodes) > limit:
        lines.append(f"  ... {len(opcodes) - limit} more raw-byte hunks (diagnostic only)")
    return lines


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compare original and rebuilt function outputs.")
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    parser.add_argument("--verbose", action="store_true", help="Print the longer diagnostic report to the console.")
    return parser.parse_args()


def _first_call_difference(original_calls: list[dict], rebuilt_calls: list[dict]) -> tuple[int, int] | None:
    left = [(row["kind"], row["target"]) for row in original_calls]
    right = [(row["kind"], row["target"]) for row in rebuilt_calls]
    matcher = difflib.SequenceMatcher(a=left, b=right, autojunk=False)
    for tag, i1, _, j1, _ in matcher.get_opcodes():
        if tag != "equal":
            return i1, j1
    return None


def _format_call_context(original_calls: list[dict], rebuilt_calls: list[dict], start: tuple[int, int], radius: int = 3) -> list[str]:
    i1, j1 = start
    lines: list[str] = []
    for row in range(-radius, radius + 1):
        oi = i1 + row
        ri = j1 + row
        left = original_calls[oi] if 0 <= oi < len(original_calls) else None
        right = rebuilt_calls[ri] if 0 <= ri < len(rebuilt_calls) else None
        left_text = "" if left is None else f"+{int(left['offset']):04X} {left['kind']} {left['display']}"
        right_text = "" if right is None else f"+{int(right['offset']):04X} {right['kind']} {right['display']}"
        marker = " " if left and right and (left["kind"], left["target"]) == (right["kind"], right["target"]) else "!"
        lines.append(f" {marker} {left_text:<48} | {right_text}")
    return lines


def _workflow_guidance(
    size_meta: dict,
    shape: dict,
    original_prologue: dict,
    rebuilt_prologue: dict,
    call_difference: tuple[int, int] | None,
    relocation_validation: dict,
    metrics: dict,
) -> list[str]:
    overflow = int(size_meta.get("overflow_nonpadding_bytes") or 0)
    expected_size = size_meta.get("expected_size_bytes")
    effective_size = size_meta.get("effective_size_bytes", size_meta.get("meaningful_size_bytes"))
    size_delta = 0 if expected_size is None or effective_size is None else int(effective_size) - int(expected_size)
    shape_percent = float(shape["similarity_percent"])
    frame_differs = original_prologue.get("frame_size") != rebuilt_prologue.get("frame_size")
    known_wrong_calls = len(relocation_validation.get("target_mismatches") or [])

    lines: list[str] = []
    if int(metrics["diff_bytes"]) == 0 and not known_wrong_calls and not size_delta:
        return ["Workflow stage: COMPLETE"]
    if known_wrong_calls and shape_percent >= 95.0 and not size_delta:
        return [
            "Workflow stage: CALL TARGET INTEGRITY",
            f"Why: instruction structure is aligned, but {known_wrong_calls} direct call(s) name the wrong external symbol.",
            "Next: fix the member/helper declaration or symbol binding; do not reshape the surrounding control flow.",
        ]
    if size_delta or shape_percent < 75.0 or call_difference is not None or known_wrong_calls:
        lines.append("Workflow stage: STRUCTURAL RECONSTRUCTION")
        reasons: list[str] = []
        if overflow:
            reasons.append(f"rebuilt has {overflow} non-padding byte(s) after the original boundary")
        elif size_delta:
            reasons.append(f"rebuilt effective code size differs by {size_delta:+d} byte(s)")
        if shape_percent < 75.0:
            reasons.append(f"instruction-shape similarity is only {shape_percent:.1f}%")
        if call_difference is not None:
            reasons.append("call/virtual-slot sequence is not aligned")
        if known_wrong_calls:
            reasons.append(f"{known_wrong_calls} known direct-call target mismatch(es)")
        lines.append("Why: " + "; ".join(reasons) + ".")
        lines.append("Next: fix the first paired structural/call hunk and size/CFG parity; do not tune register coloring yet.")
        if frame_differs:
            lines.append("Frame note: frame sizes differ, but stabilize real shared local lifetimes before padding the frame.")
    elif frame_differs:
        lines.append("Workflow stage: STACK/LOCAL TOPOLOGY")
        lines.append("Why: calls and instruction structure are close, but the frame size differs.")
        lines.append("Next: compare address-taken/overlapping locals and their scopes; avoid synthetic frame padding.")
    elif shape_percent < 95.0:
        lines.append("Workflow stage: BLOCK SHAPE AND LIVENESS")
        lines.append("Next: work from the first paired instruction hunk; keep already aligned regions stable.")
    elif int(metrics["diff_bytes"]) > 0:
        lines.append("Workflow stage: EXACT CODEGEN")
        lines.append("Next: use the first localized hunk for source-shape/register/branch probes or a focused variant lab.")
    return lines


def _format_frame(value: object) -> str:
    return "none" if value is None else f"0x{int(value):X}"


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    asm_dir = repo_path(Path("build") / "asm")
    diff_dir = ensure_build_subdir("diff")
    history_dir = repo_path(Path("build") / "history" / slug)

    orig_bin = asm_dir / f"orig_{slug}.bin"
    rebuilt_bin = asm_dir / f"rebuilt_{slug}.bin"
    rebuilt_json = asm_dir / f"rebuilt_{slug}.json"
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
    relocations = list(rebuilt_meta.get("relocations") or [])

    masked_original, masked_rebuilt, relocation_validation = compatible_relocation_masks(
        original_bytes, rebuilt_bytes, relocations, va
    )
    metrics = byte_diff_metrics(masked_original, masked_rebuilt)
    mismatch_text = str(metrics["first_mismatch_offset"])
    mismatch = int(mismatch_text) if mismatch_text else None

    original_instructions = decode_instructions(original_bytes, va)
    rebuilt_instructions = decode_instructions(rebuilt_bytes, va, relocations)
    shape = instruction_alignment(original_instructions, rebuilt_instructions)
    actionable_target_mismatches = (
        relocation_validation["target_mismatches"]
        if float(shape["similarity_percent"]) >= 85.0
        else []
    )
    guidance_relocation_validation = {
        **relocation_validation,
        "target_mismatches": actionable_target_mismatches,
    }
    original_prologue = prologue_summary(original_instructions)
    rebuilt_prologue = prologue_summary(rebuilt_instructions)
    original_flow = control_flow_summary(original_instructions)
    rebuilt_flow = control_flow_summary(rebuilt_instructions)
    original_calls = call_fingerprint(original_instructions, original=True)
    rebuilt_calls = call_fingerprint(rebuilt_instructions, original=False)
    call_difference = _first_call_difference(original_calls, rebuilt_calls)

    previous_bin = history_dir / "previous.bin"
    delta = None
    if previous_bin.exists():
        delta = iteration_delta(original_bytes, previous_bin.read_bytes(), rebuilt_bytes)

    guidance = _workflow_guidance(
        rebuilt_meta,
        shape,
        original_prologue,
        rebuilt_prologue,
        call_difference,
        guidance_relocation_validation,
        metrics,
    )

    metrics_path = diff_dir / f"{slug}.json"
    metrics_payload = {
        "va": record["va"],
        "name": record["name"],
        "slug": slug,
        "relocations_masked": relocation_validation["compatible"],
        "relocations_total": len(relocations),
        "relocations_compatible_masked": relocation_validation["compatible"],
        "relocations_incompatible_unmasked": relocation_validation["incompatible"],
        "relocation_target_mismatch_candidates": relocation_validation["target_mismatches"],
        "relocation_target_mismatches": actionable_target_mismatches,
        "rebuilt_extraction": rebuilt_meta,
        "instruction_shape": {key: value for key, value in shape.items() if key not in {"opcodes", "first_change"}},
        "original_prologue": original_prologue,
        "rebuilt_prologue": rebuilt_prologue,
        "original_control_flow": original_flow,
        "rebuilt_control_flow": rebuilt_flow,
        "iteration_delta": delta,
        "workflow_stage": guidance[0].split(":", 1)[-1].strip() if guidance else "",
        "workflow_guidance": guidance[1:],
        **metrics,
    }
    metrics_path.write_text(json.dumps(metrics_payload, indent=2), encoding="utf-8")

    meaningful_size = int(
        rebuilt_meta.get("effective_size_bytes", rebuilt_meta.get("meaningful_size_bytes", len(rebuilt_bytes)))
    )
    expected_size = len(original_bytes)
    size_delta = meaningful_size - expected_size
    summary: list[str] = [
        f"Function: {record['name']} ({record['va']})",
        f"Size: original {expected_size}, rebuilt code {meaningful_size} ({size_delta:+d}), compared {len(rebuilt_bytes)}",
        f"Frame: original {_format_frame(original_prologue.get('frame_size'))}, "
        f"rebuilt {_format_frame(rebuilt_prologue.get('frame_size'))}; "
        f"saved regs {original_prologue.get('saved_registers')} / {rebuilt_prologue.get('saved_registers')}",
        f"Instructions: original {shape['original_instructions']}, rebuilt {shape['rebuilt_instructions']}; "
        f"shape similarity {float(shape['similarity_percent']):.2f}%; longest aligned run {shape['longest_equal_run']}",
        f"Calls: original {len(original_calls)}, rebuilt {len(rebuilt_calls)}; "
        f"relocations safely masked {relocation_validation['compatible']}/{len(relocations)}",
        "CFG signals (orig/rebuilt): "
        f"cond {original_flow['conditional_branches']}/{rebuilt_flow['conditional_branches']}, "
        f"jumps {original_flow['unconditional_branches']}/{rebuilt_flow['unconditional_branches']}, "
        f"returns {original_flow['returns']}/{rebuilt_flow['returns']}",
        f"Strict positional diff: {metrics['diff_bytes']} bytes ({float(metrics['diff_percent']):.4f}%), "
        f"{metrics['diff_spans']} span(s)",
        f"Raw edit/resync diagnostic: {metrics['edit_diff_bytes']} ({float(metrics['edit_diff_percent']):.4f}%), "
        f"equal {metrics['edit_equal_bytes']}",
    ]
    if delta is not None:
        summary.append(
            "This iteration: "
            f"changed {delta['changed_bytes']} byte(s) in {delta['changed_spans']} span(s), "
            f"strictly improved {delta['strict_improvements']}, regressed {delta['strict_regressions']}, "
            f"neutral {delta['neutral_changes']}, size {delta['size_delta']:+d}"
        )
        changed_ranges = list(delta.get("ranges") or [])
        if changed_ranges:
            range_text = ", ".join(
                f"+{int(row['start']):04X}..+{int(row['end']):04X}"
                f" (better {row['improved']}, worse {row['regressed']}, neutral {row['neutral']})"
                for row in changed_ranges[:6]
            )
            if len(changed_ranges) > 6:
                range_text += f", ... {len(changed_ranges) - 6} more"
            summary.append("Changed output ranges: " + range_text)

    exact = mismatch is None and not relocation_validation["target_mismatches"]
    summary.append(f"Result: {'MATCH' if exact else 'MISMATCH'}")
    if mismatch is not None:
        summary.append(f"First strict mismatch: +{mismatch:04X} (VA {va + mismatch:08X})")

    detail: list[str] = []
    if shape.get("first_change"):
        detail.append("")
        detail.append("First paired instruction-shape hunk (! differs):")
        detail.extend(paired_instruction_context(original_instructions, rebuilt_instructions, shape, va))
    if call_difference is not None:
        detail.append("")
        detail.append("First call/virtual-slot sequence divergence:")
        detail.extend(_format_call_context(original_calls, rebuilt_calls, call_difference))
    if actionable_target_mismatches:
        detail.append("")
        detail.append("Known direct-call target mismatches (not masked):")
        for row in actionable_target_mismatches[:12]:
            detail.append(f"  +{int(row['offset']):04X}: original {row['original']} | rebuilt {row['rebuilt']}")
    if mismatch is not None:
        detail.append("")
        detail.append("First raw-byte edit/resync hunks (secondary diagnostic):")
        detail.extend(format_edit_hunks(metrics, masked_original, masked_rebuilt))

    report_lines = summary + [""] + guidance + detail
    report_path.write_text("\n".join(report_lines) + "\n", encoding="utf-8")

    console_lines = summary + [""] + guidance
    if args.verbose or not exact:
        console_lines += detail
    print("\n".join(console_lines))
    raise SystemExit(0 if exact else 1)


if __name__ == "__main__":
    main()
