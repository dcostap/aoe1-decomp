from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

from common import byte_diff_metrics, ensure_build_subdir, function_record_by_va, function_slug, repo_path
from function_diagnostics import (
    basic_blocks,
    block_alignment,
    call_alignment,
    call_count_deltas,
    call_fingerprint,
    call_target_counts,
    compatible_relocation_masks,
    control_flow_summary,
    decode_instructions,
    decode_instruction_ranges,
    instruction_alignment,
    iteration_delta,
    owning_function_symbol_validation,
    paired_instruction_context,
    pdb_line_for_address,
    prologue_summary,
)
from mismatch_classifier import classify_mismatch
from source_listing import parse_listing_file, source_line_for_offset
from target_dossier import collect_memory_evidence, direct_call_cleanups


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
    parser.add_argument(
        "--no-iteration",
        action="store_true",
        help="Suppress previous-build delta reporting for cached diagnostic-only queries.",
    )
    parser.add_argument(
        "--detail",
        choices=("auto", "concise", "full"),
        default="auto",
        help="Console detail level. Auto uses concise output for giant functions.",
    )
    parser.add_argument("--call-map", action="store_true", help="Print the full context-aware call-site alignment.")
    parser.add_argument(
        "--call-map-unmatched",
        action="store_true",
        help="Print only non-equal call-map rows (implies --call-map).",
    )
    call_filter = parser.add_mutually_exclusive_group()
    call_filter.add_argument(
        "--call-map-target",
        metavar="TEXT",
        help="Print call-map rows whose target/display contains TEXT (implies --call-map).",
    )
    call_filter.add_argument(
        "--call-map-target-exact",
        metavar="TARGET",
        help="Print call-map rows whose normalized target exactly equals TARGET (implies --call-map).",
    )
    call_filter.add_argument(
        "--call-map-target-regex",
        metavar="REGEX",
        help="Print call-map rows whose kind/target/display matches REGEX, ignoring case (implies --call-map).",
    )
    parser.add_argument("--block-map", action="store_true", help="Print the full basic-block alignment.")
    parser.add_argument(
        "--stack-map",
        action="store_true",
        help="Pair durable original and rebuilt stack homes at exact entry-relative coordinates.",
    )
    parser.add_argument(
        "--block-map-differences",
        action="store_true",
        help="Print only non-equal basic-block rows (implies --block-map).",
    )
    parser.add_argument(
        "--map-limit",
        type=int,
        metavar="N",
        help="Limit rows printed by call/block maps after filtering (0 means unlimited).",
    )
    parser.add_argument(
        "--range",
        dest="focus_range",
        metavar="[orig:|rebuilt:]START-END",
        help="Print focused aligned blocks/disassembly for a combined offset or real VA range.",
    )
    return parser.parse_args()


def _call_text(row: dict | None, function_va: int, original: bool) -> str:
    if row is None:
        return ""
    line = (
        pdb_line_for_address(function_va, function_va + int(row["offset"]))
        if original
        else row.get("source_line")
    )
    line_text = "" if line is None else f" L{line}"
    block = row.get("block_offset")
    block_text = "" if block is None else f" B+{int(block):04X}"
    cleanup = int(row.get("caller_cleanup_bytes", 0))
    cleanup_text = "" if cleanup == 0 else f" cleanup={cleanup}"
    return f"+{int(row['offset']):04X}{line_text}{block_text} {row['kind']} {row['display']}{cleanup_text}"


def _format_call_context(
    alignment: dict,
    start_row: int,
    function_va: int,
    radius: int = 3,
) -> list[str]:
    rows = list(alignment.get("rows") or [])
    lines: list[str] = []
    for aligned_index in range(max(0, start_row - radius), min(len(rows), start_row + radius + 1)):
        aligned = rows[aligned_index]
        left_text = _call_text(aligned.get("original"), function_va, True)
        right_text = _call_text(aligned.get("rebuilt"), function_va, False)
        marker = " " if aligned["status"] == "equal" else "!"
        confidence = str(aligned.get("confidence", ""))[:1].upper()
        lines.append(f" {marker}{confidence} {left_text:<58} | {right_text}")
    return lines


def _format_full_call_map(
    alignment: dict,
    function_va: int,
    *,
    unmatched_only: bool = False,
    target_filter: str | None = None,
    target_filter_mode: str = "contains",
    limit: int | None = None,
) -> list[str]:
    rows = list(enumerate(alignment.get("rows") or []))
    if unmatched_only:
        rows = [(index, row) for index, row in rows if row.get("status") != "equal"]
    if target_filter:
        query = target_filter.lower()
        pattern = None
        if target_filter_mode == "regex":
            try:
                pattern = re.compile(target_filter, re.IGNORECASE)
            except re.error as exc:
                raise ValueError(f"Invalid --call-map-target-regex: {exc}") from exc

        def matches(row: dict) -> bool:
            for call in (row.get("original"), row.get("rebuilt")):
                if not call:
                    continue
                if target_filter_mode == "exact":
                    if query in {str(call.get("target", "")).lower(), str(call.get("display", "")).lower()}:
                        return True
                else:
                    searchable = f"{call.get('kind', '')} {call.get('target', '')} {call.get('display', '')}"
                    if (pattern.search(searchable) if pattern is not None else query in searchable.lower()):
                        return True
            return False

        rows = [(index, row) for index, row in rows if matches(row)]
    total = len(rows)
    if limit is not None and limit > 0:
        rows = rows[:limit]
    filters: list[str] = []
    if unmatched_only:
        filters.append("non-equal only")
    if target_filter:
        description = {
            "contains": "target contains",
            "exact": "target equals",
            "regex": "target matches regex",
        }.get(target_filter_mode, "target contains")
        filters.append(f"{description} {target_filter!r}")
    suffix = "" if not filters else f"; {', '.join(filters)}"
    lines = [f"Call-site alignment (diagnostic; H/M/L is confidence{suffix}):"]
    for index, row in rows:
        left_text = _call_text(row.get("original"), function_va, True)
        right_text = _call_text(row.get("rebuilt"), function_va, False)
        confidence = str(row.get("confidence", "low"))[:1].upper()
        marker = {"equal": "=", "replace": "~", "delete": "-", "insert": "+"}.get(str(row.get("status")), "?")
        lines.append(f"  {index:04d} {marker}{confidence} {left_text:<62} | {right_text}")
        if row.get("status") != "equal" and row.get("original") and row.get("rebuilt"):
            left_setup = " ; ".join(row["original"].get("setup") or [])
            right_setup = " ; ".join(row["rebuilt"].get("setup") or [])
            lines.append(f"         setup orig: {left_setup}")
            lines.append(f"         setup rebu: {right_setup}")
    if len(rows) < total:
        lines.append(f"  ... {total - len(rows)} more filtered call-map row(s); raise --map-limit to show them")
    if total == 0:
        lines.append("  (no call-map rows matched the filters)")
    return lines


def _format_block(row: dict | None) -> str:
    if row is None:
        return ""
    calls = ",".join(row.get("calls") or []) or "-"
    successors = ",".join(f"+{int(value):04X}" for value in row.get("successors") or []) or "-"
    source_line = row.get("source_line")
    line_text = "" if source_line is None else f" L{int(source_line)}"
    return (
        f"B{int(row['index']):03d} +{int(row['offset']):04X}..+{int(row['end_offset']):04X}{line_text} "
        f"n={int(row['instruction_count'])} calls=[{calls}] succ=[{successors}]"
    )


def _format_block_context(alignment: dict, radius: int = 2) -> list[str]:
    rows = list(alignment.get("rows") or [])
    first = alignment.get("first_difference_row")
    if first is None:
        return []
    lines: list[str] = []
    for index in range(max(0, int(first) - radius), min(len(rows), int(first) + radius + 1)):
        row = rows[index]
        marker = " " if row["status"] == "equal" else "!"
        confidence = str(row.get("confidence", ""))[:1].upper()
        lines.append(f" {marker}{confidence} {_format_block(row.get('original')):<80} | {_format_block(row.get('rebuilt'))}")
    return lines


def _format_full_block_map(
    alignment: dict,
    *,
    differences_only: bool = False,
    limit: int | None = None,
) -> list[str]:
    rows = list(enumerate(alignment.get("rows") or []))
    if differences_only:
        rows = [(index, row) for index, row in rows if row.get("status") != "equal"]
    total = len(rows)
    if limit is not None and limit > 0:
        rows = rows[:limit]
    suffix = "; non-equal only" if differences_only else ""
    lines = [f"Basic-block alignment (diagnostic; exact/fuzzy/gap{suffix}):"]
    for index, row in rows:
        marker = {"equal": "=", "fuzzy": "~", "delete": "-", "insert": "+"}.get(str(row.get("status")), "?")
        confidence = str(row.get("confidence", "low"))[:1].upper()
        lines.append(f"  {index:04d} {marker}{confidence} {_format_block(row.get('original')):<82} | {_format_block(row.get('rebuilt'))}")
    if len(rows) < total:
        lines.append(f"  ... {total - len(rows)} more filtered block-map row(s); raise --map-limit to show them")
    if total == 0:
        lines.append("  (no block-map rows matched the filters)")
    return lines


def _focus_endpoint(text: str, instructions: list, function_va: int) -> int:
    value_text = text.strip()
    explicit_offset = value_text.startswith("+")
    if explicit_offset:
        value_text = value_text[1:]
    value = int(value_text, 16)
    if explicit_offset or value < function_va:
        return value
    for instruction in instructions:
        if instruction.address <= value < instruction.address + len(instruction.data):
            return instruction.offset + (value - instruction.address)
    # Rebuilt code is contiguous; this fallback is also useful for an endpoint
    # exactly at the end of an original range.
    return value - function_va


def _parse_focus_range(spec: str, original_instructions: list, rebuilt_instructions: list, function_va: int) -> tuple[str, int, int]:
    value = spec.strip()
    side = "original"
    if ":" in value:
        prefix, value = value.split(":", 1)
        normalized = prefix.strip().lower()
        if normalized in {"orig", "original"}:
            side = "original"
        elif normalized in {"rebuilt", "rebuild", "new"}:
            side = "rebuilt"
        else:
            raise ValueError(f"Unknown range side {prefix!r}; use orig: or rebuilt:")
    separator = ".." if ".." in value else ("-" if "-" in value else "")
    if separator:
        start_text, end_text = value.split(separator, 1)
    else:
        start_text = end_text = value
    instructions = original_instructions if side == "original" else rebuilt_instructions
    start = _focus_endpoint(start_text, instructions, function_va)
    end = _focus_endpoint(end_text, instructions, function_va) + 1
    if start < 0 or end <= start:
        raise ValueError(f"Invalid focused range: {spec}")
    return side, start, end


def _focused_instruction_lines(
    instructions: list,
    start: int,
    end: int,
    function_va: int,
    original: bool,
    rebuilt_line_lookup=None,
) -> list[str]:
    lines: list[str] = []
    for instruction in instructions:
        if instruction.end <= start or instruction.offset >= end:
            continue
        line = (
            pdb_line_for_address(function_va, instruction.address)
            if original
            else (None if rebuilt_line_lookup is None else rebuilt_line_lookup(instruction.offset))
        )
        line_text = "" if line is None else f" L{line}"
        lines.append(f"      +{instruction.offset:04X}{line_text} {instruction.data.hex():<16} {instruction.text}")
    return lines


def _format_focus_range(
    spec: str,
    function_va: int,
    original_instructions: list,
    rebuilt_instructions: list,
    alignment: dict,
    rebuilt_line_lookup=None,
) -> list[str]:
    side, start, end = _parse_focus_range(spec, original_instructions, rebuilt_instructions, function_va)
    selected: list[dict] = []
    for row in alignment.get("rows") or []:
        block = row.get("original" if side == "original" else "rebuilt")
        if block is not None and int(block["end_offset"]) > start and int(block["offset"]) < end:
            selected.append(row)
    lines = [f"Focused {side} range +{start:04X}..+{end - 1:04X} ({spec}):"]
    if not selected:
        lines.append("  No aligned basic block overlaps the range; showing same-offset instructions.")
        lines.append("  ORIGINAL")
        lines.extend(_focused_instruction_lines(original_instructions, start, end, function_va, True) or ["      (none)"])
        lines.append("  REBUILT")
        lines.extend(
            _focused_instruction_lines(
                rebuilt_instructions, start, end, function_va, False, rebuilt_line_lookup
            )
            or ["      (none)"]
        )
        return lines
    if len(selected) > 80:
        selected = selected[:80]
        lines.append("  Range overlaps more than 80 aligned rows; output truncated. Narrow --range for full detail.")
    for row in selected:
        marker = {"equal": "=", "fuzzy": "~", "delete": "-", "insert": "+"}.get(str(row.get("status")), "?")
        confidence = str(row.get("confidence", "low"))[:1].upper()
        lines.append(f"  {marker}{confidence} {_format_block(row.get('original'))} | {_format_block(row.get('rebuilt'))}")
        original_block = row.get("original")
        if original_block is not None:
            lines.append("    ORIGINAL")
            lines.extend(
                _focused_instruction_lines(
                    original_instructions,
                    int(original_block["offset"]),
                    int(original_block["end_offset"]),
                    function_va,
                    True,
                )
            )
        rebuilt_block = row.get("rebuilt")
        if rebuilt_block is not None:
            lines.append("    REBUILT")
            lines.extend(
                _focused_instruction_lines(
                    rebuilt_instructions,
                    int(rebuilt_block["offset"]),
                    int(rebuilt_block["end_offset"]),
                    function_va,
                    False,
                    rebuilt_line_lookup,
                )
            )
    return lines


def _format_call_count_deltas(rows: list[dict], limit: int = 14) -> list[str]:
    lines: list[str] = []
    for row in rows[:limit]:
        label = f"{row['kind']} {row['target']}"
        lines.append(
            f"  {int(row['delta']):+4d}  {int(row['rebuilt']):3d}/{int(row['original']):3d}  {label}"
        )
    if len(rows) > limit:
        lines.append(f"  ... {len(rows) - limit} more target-count difference(s)")
    return lines


def _format_iteration_call_deltas(rows: list[dict], limit: int = 10) -> list[str]:
    lines: list[str] = []
    for row in rows[:limit]:
        label = f"{row['kind']} {row['target']}"
        lines.append(
            f"  {int(row['delta']):+4d}  now {int(row['rebuilt']):3d}, previous {int(row['original']):3d}  {label}"
        )
    if len(rows) > limit:
        lines.append(f"  ... {len(rows) - limit} more changed call target(s)")
    return lines


def _stack_home_pairing(
    original_memory: dict[str, object], rebuilt_listing: dict[str, object]
) -> dict[str, object]:
    original_by_coordinate: dict[int, dict[str, object]] = {}
    for source in original_memory.get("stack") or []:
        coordinate = source.get("entry_coordinate")
        if coordinate is None or int(coordinate) == 0:
            continue
        value = int(coordinate)
        row = original_by_coordinate.setdefault(
            value,
            {"entry_coordinate": value, "widths": set(), "accesses": set(), "occurrence_count": 0},
        )
        if source.get("width") is not None:
            row["widths"].add(int(source["width"]))
        row["accesses"].add(str(source.get("access") or "unknown"))
        row["occurrence_count"] = int(row["occurrence_count"]) + int(source.get("occurrence_count") or 0)

    # A negative coordinate is a home candidate only when the original takes
    # its address or both reads and writes it. This excludes most outgoing args.
    original_candidates: dict[int, dict[str, object]] = {}
    for coordinate, row in original_by_coordinate.items():
        accesses = set(row["accesses"])
        reads = bool(accesses & {"read", "read_write"})
        writes = bool(accesses & {"write", "read_write"})
        if coordinate > 0 or "address" in accesses or (reads and writes):
            original_candidates[coordinate] = {
                **row,
                "widths": sorted(row["widths"]),
                "accesses": sorted(accesses),
                "region": "parameter" if coordinate > 0 else "local",
            }

    rebuilt_by_coordinate: dict[int, list[dict[str, object]]] = {}
    for source in rebuilt_listing.get("stack_homes") or []:
        rebuilt_by_coordinate.setdefault(int(source["entry_coordinate"]), []).append(dict(source))

    rows: list[dict[str, object]] = []
    for coordinate in sorted(set(original_candidates) | set(rebuilt_by_coordinate)):
        original = original_candidates.get(coordinate)
        rebuilt = sorted(
            rebuilt_by_coordinate.get(coordinate, []),
            key=lambda row: (str(row.get("kind")), str(row.get("name"))),
        )
        expected_kind = None if original is None else str(original["region"])
        kind_compatible = original is not None and bool(
            any(str(home.get("kind")) == expected_kind for home in rebuilt)
        )
        original_widths = set() if original is None else set(original["widths"])
        rebuilt_widths = {
            int(width)
            for home in rebuilt
            for width in home.get("widths") or []
        }
        width_compatible = not original_widths or not rebuilt_widths or bool(original_widths & rebuilt_widths)
        if original is None:
            status = "rebuilt_only"
        elif not rebuilt:
            status = "original_only"
        elif not kind_compatible:
            status = "role_mismatch"
        elif not width_compatible:
            status = "width_mismatch"
        else:
            status = "paired"
        rows.append(
            {
                "entry_coordinate": coordinate,
                "status": status,
                "original": original,
                "rebuilt": rebuilt,
                "width_evidence": (
                    "unknown"
                    if not original_widths or not rebuilt_widths
                    else "compatible" if width_compatible else "conflict"
                ),
            }
        )
    return {
        "coordinate_system": "entry ESP: return address=0, first stack argument=+4",
        "method": "exact entry coordinate, compatible role, and compatible observed width",
        "rows": rows,
        "status_counts": {
            status: sum(row["status"] == status for row in rows)
            for status in ("paired", "original_only", "rebuilt_only", "role_mismatch", "width_mismatch")
        },
    }


def _format_stack_map(pairing: dict[str, object]) -> list[str]:
    rows = list(pairing.get("rows") or [])
    if not rows:
        return [
            "Stack-home pairing (entry ESP; exact coordinates only):",
            "  (no durable original homes or listing-derived rebuilt symbols)",
        ]
    lines = [
        "Stack-home pairing (entry ESP; exact coordinates and compatible observed widths only):"
    ]
    for row in rows:
        coordinate = int(row["entry_coordinate"])
        original = row.get("original") or {}
        rebuilt = list(row.get("rebuilt") or [])
        if original:
            widths = "/".join(str(width) for width in original.get("widths") or []) or "?"
            accesses = "/".join(str(access) for access in original.get("accesses") or [])
            left = (
                f"original {original.get('region')} {accesses} width={widths} "
                f"uses={original.get('occurrence_count')}"
            )
        else:
            left = "no original home candidate"
        if rebuilt:
            names = []
            for home in rebuilt:
                widths = "/".join(str(width) for width in home.get("widths") or []) or "?"
                names.append(f"{home.get('kind')} {home.get('name')} width={widths}")
            right = ", ".join(names)
        else:
            right = "no rebuilt symbol"
        lines.append(f"  {coordinate:+5d}: {left}  <->  {right}  [{row['status']}]")
    return lines


def _relocated_call_pairs(
    block_map: dict,
    original_calls: list[dict[str, object]],
    rebuilt_calls: list[dict[str, object]],
) -> list[dict[str, object]]:
    """Pair calls inside conservative order-independent block matches.

    This does not alter ordered call-alignment metrics. It records when an
    apparent delete/insert is already explained by a uniquely paired moved block.
    """
    original_by_block: dict[int, list[dict[str, object]]] = {}
    rebuilt_by_block: dict[int, list[dict[str, object]]] = {}
    for call in original_calls:
        original_by_block.setdefault(int(call.get("block_offset", -1)), []).append(call)
    for call in rebuilt_calls:
        rebuilt_by_block.setdefault(int(call.get("block_offset", -1)), []).append(call)
    rows: list[dict[str, object]] = []
    for pair_index, pair in enumerate(block_map.get("relocated_pairs") or []):
        left_block = pair.get("original") or {}
        right_block = pair.get("rebuilt") or {}
        left_calls = original_by_block.get(int(left_block.get("offset", -1)), [])
        right_calls = rebuilt_by_block.get(int(right_block.get("offset", -1)), [])
        left_keys = [(str(call.get("kind")), str(call.get("target"))) for call in left_calls]
        right_keys = [(str(call.get("kind")), str(call.get("target"))) for call in right_calls]
        if not left_calls or left_keys != right_keys:
            continue
        for call_index, (left, right) in enumerate(zip(left_calls, right_calls)):
            rows.append(
                {
                    "pair_index": pair_index,
                    "call_index": call_index,
                    "confidence": pair.get("confidence", "low"),
                    "exact_block": bool(pair.get("exact")),
                    "original": left,
                    "rebuilt": right,
                    "block_offset_delta": int(right_block["offset"]) - int(left_block["offset"]),
                }
            )
    return rows


def _format_relocated_call_pairs(rows: list[dict[str, object]], function_va: int, limit: int = 16) -> list[str]:
    lines = ["Calls explained by order-independent relocated blocks (not added to ordered alignment):"]
    for row in rows[:limit]:
        lines.append(
            f"  [{str(row['confidence']).upper():6}] "
            f"{_call_text(row['original'], function_va, True):<58} -> "
            f"{_call_text(row['rebuilt'], function_va, False)} "
            f"(block delta {int(row['block_offset_delta']):+d})"
        )
    if len(rows) > limit:
        lines.append(f"  ... {len(rows) - limit} more relocated call site(s)")
    return lines


def _cfg_alignment_issues(alignment: dict, limit: int = 12) -> list[dict[str, object]]:
    issues: list[dict[str, object]] = []
    for index, row in enumerate(alignment.get("rows") or []):
        left = row.get("original")
        right = row.get("rebuilt")
        if left is not None and right is not None:
            terminator_changed = left.get("terminator") != right.get("terminator")
            successor_changed = len(left.get("successors") or []) != len(right.get("successors") or [])
            if not (terminator_changed or successor_changed):
                continue
            issues.append(
                {
                    "row": index,
                    "kind": "paired-edge-shape",
                    "original": _compact_block(left),
                    "rebuilt": _compact_block(right),
                    "terminator_changed": terminator_changed,
                    "successor_count_changed": successor_changed,
                }
            )
        else:
            block = left or right
            if block is None or not str(block.get("terminator", "")).startswith(("j", "ret")):
                continue
            issues.append(
                {
                    "row": index,
                    "kind": "missing-original-block" if left is None else "missing-rebuilt-block",
                    "original": _compact_block(left),
                    "rebuilt": _compact_block(right),
                }
            )
        if len(issues) >= limit:
            break
    return issues


def _format_cfg_issues(rows: list[dict[str, object]]) -> list[str]:
    lines: list[str] = []
    for row in rows:
        lines.append(
            f"  row {int(row['row']):04d} {row['kind']}: "
            f"{_format_block(row.get('original'))} | {_format_block(row.get('rebuilt'))}"
        )
    return lines


def _workflow_guidance(
    size_meta: dict,
    shape: dict,
    original_prologue: dict,
    rebuilt_prologue: dict,
    call_difference: tuple[int, int] | None,
    call_target_deltas: list[dict],
    relocation_validation: dict,
    owner_symbol_validation: dict,
    metrics: dict,
) -> list[str]:
    overflow = int(size_meta.get("overflow_nonpadding_bytes") or 0)
    expected_size = size_meta.get("expected_size_bytes")
    effective_size = size_meta.get("effective_size_bytes", size_meta.get("meaningful_size_bytes"))
    size_delta = 0 if expected_size is None or effective_size is None else int(effective_size) - int(expected_size)
    shape_percent = float(shape["similarity_percent"])
    frame_differs = original_prologue.get("frame_size") != rebuilt_prologue.get("frame_size")
    known_wrong_transfers = len(relocation_validation.get("target_mismatches") or [])
    wrong_owner = owner_symbol_validation.get("status") == "mismatch"

    lines: list[str] = []
    if int(metrics["diff_bytes"]) == 0 and not known_wrong_transfers and not wrong_owner and not size_delta:
        return [
            "Workflow stage: COMPLETE",
            "Source gate: exact emitted code still requires a plausibility and policy audit before promotion.",
        ]
    if wrong_owner and shape_percent >= 95.0 and not size_delta:
        return [
            "Workflow stage: FUNCTION SYMBOL IDENTITY",
            "Why: emitted instructions align, but the rebuilt owner names a different function.",
            "Next: define the assigned function with its real C/C++ owner and method kind.",
        ]
    if known_wrong_transfers and shape_percent >= 95.0 and not size_delta:
        return [
            "Workflow stage: CONTROL TARGET INTEGRITY",
            f"Why: instruction structure is aligned, but {known_wrong_transfers} direct control transfer(s) name the wrong external symbol.",
            "Next: fix the member/helper declaration or symbol binding; do not reshape the surrounding control flow.",
        ]
    if size_delta or shape_percent < 75.0 or call_difference is not None or known_wrong_transfers or wrong_owner:
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
        if call_target_deltas:
            reasons.append(f"{len(call_target_deltas)} call target count(s) differ")
        if known_wrong_transfers:
            reasons.append(f"{known_wrong_transfers} known direct-control target mismatch(es)")
        if wrong_owner:
            reasons.append("rebuilt owner symbol names a different function")
        lines.append("Why: " + "; ".join(reasons) + ".")
        if call_target_deltas:
            lines.append(
                "Next: resolve behavior-backed call-count gaps and the first ordered structural/call hunk; "
                "do not tune register coloring yet."
            )
        else:
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
        lines.append(
            "Next: keep the clean-source reconstruction authoritative; use the first localized hunk for "
            "diagnostic source-shape probes or a focused variant lab. Assembly-closer is not source-better."
        )
    return lines


def _format_frame(value: object) -> str:
    return "none" if value is None else f"0x{int(value):X}"


def _compact_block(block: dict | None) -> dict | None:
    if block is None:
        return None
    return {key: value for key, value in block.items() if key not in {"shapes", "signature"}}


def _compact_block_alignment(alignment: dict) -> dict:
    compact = {
        **{key: value for key, value in alignment.items() if key not in {"rows", "relocated_pairs"}},
        "rows": [
            {
                **{key: value for key, value in row.items() if key not in {"original", "rebuilt"}},
                "original": _compact_block(row.get("original")),
                "rebuilt": _compact_block(row.get("rebuilt")),
            }
            for row in alignment.get("rows") or []
        ],
    }
    compact["relocated_pairs"] = [
        {
            **{key: value for key, value in row.items() if key not in {"original", "rebuilt"}},
            "original": _compact_block(row.get("original")),
            "rebuilt": _compact_block(row.get("rebuilt")),
        }
        for row in alignment.get("relocated_pairs") or []
    ]
    return compact


def _hard_discrepancies(
    call_map: dict,
    target_mismatches: list[dict],
    call_target_deltas: list[dict],
    block_map: dict | None = None,
) -> list[dict]:
    rows: list[dict] = []
    delta_by_target = {
        (str(row["kind"]), str(row["target"])): int(row["delta"])
        for row in call_target_deltas
    }
    relocated_original_blocks = {
        int(row["original"]["offset"])
        for row in (block_map or {}).get("relocated_pairs") or []
        if row.get("original") is not None
    }
    relocated_rebuilt_blocks = {
        int(row["rebuilt"]["offset"])
        for row in (block_map or {}).get("relocated_pairs") or []
        if row.get("rebuilt") is not None
    }
    for mismatch in target_mismatches:
        rows.append(
            {
                "priority": 1,
                "kind": "direct-target",
                "confidence": "high",
                "message": f"+{int(mismatch['offset']):04X}: original {mismatch['original']} -> rebuilt {mismatch['rebuilt']}",
            }
        )
    for delta in call_target_deltas:
        count = abs(int(delta["delta"]))
        direction = "missing" if int(delta["delta"]) < 0 else "extra"
        rows.append(
            {
                "priority": 2,
                "magnitude": count,
                "kind": "aggregate-call-count",
                "confidence": "high",
                "message": (
                    f"{direction} {count} rebuilt call(s): {delta['kind']} {delta['target']} "
                    f"(rebuilt/original {int(delta['rebuilt'])}/{int(delta['original'])})"
                ),
            }
        )
    for aligned in call_map.get("rows") or []:
        left = aligned.get("original") or {}
        right = aligned.get("rebuilt") or {}
        if (
            aligned.get("status") in {"equal", "replace"}
            and left
            and right
            and int(left.get("caller_cleanup_bytes", 0)) != int(right.get("caller_cleanup_bytes", 0))
        ):
            rows.append(
                {
                    "priority": 4,
                    "kind": "stack-cleanup-mismatch",
                    "confidence": aligned.get("confidence", "low"),
                    "message": (
                        f"original +{int(left['offset']):04X} cleanup {int(left.get('caller_cleanup_bytes', 0))} -> "
                        f"rebuilt +{int(right['offset']):04X} cleanup {int(right.get('caller_cleanup_bytes', 0))}"
                    ),
                }
            )
        if aligned.get("status") in {"delete", "insert"} and aligned.get("confidence") != "low":
            call = left or right
            aggregate_delta = delta_by_target.get((str(call.get("kind")), str(call.get("target"))), 0)
            # A local aligner gap can point in the opposite direction from the
            # global multiset (typically after VC5 tail merging).  Do not call it
            # "extra" when the rebuild is globally missing that target, or vice
            # versa; the aggregate discrepancy above is the safer headline.
            if aligned["status"] == "insert" and aggregate_delta <= 0:
                continue
            if aligned["status"] == "delete" and aggregate_delta >= 0:
                continue
            side = "missing rebuilt call" if aligned["status"] == "delete" else "extra rebuilt call"
            rows.append(
                {
                    "priority": 3,
                    "kind": "missing-or-extra-call",
                    "confidence": aligned.get("confidence", "low"),
                    "message": f"{side}: {call.get('kind')} {call.get('target')} near +{int(call['offset']):04X}",
                }
            )
        if aligned.get("status") != "replace":
            continue
        if (
            int(left.get("block_offset", -1)) in relocated_original_blocks
            or int(right.get("block_offset", -1)) in relocated_rebuilt_blocks
        ):
            continue
        if left.get("kind") == "virtual" and right.get("kind") == "virtual":
            rows.append(
                {
                    "priority": 3,
                    "kind": "virtual-slot-replacement",
                    "confidence": aligned.get("confidence", "low"),
                    "message": (
                        f"original +{int(left['offset']):04X} {left['target']} -> "
                        f"rebuilt +{int(right['offset']):04X} {right['target']}"
                    ),
                }
            )
        elif aligned.get("confidence") != "low":
            rows.append(
                {
                    "priority": 3,
                    "kind": "call-target-replacement",
                    "confidence": aligned.get("confidence", "low"),
                    "message": (
                        f"original +{int(left['offset']):04X} {left.get('target')} -> "
                        f"rebuilt +{int(right['offset']):04X} {right.get('target')}"
                    ),
                }
            )
    rows.sort(
        key=lambda row: (
            int(row["priority"]),
            -int(row.get("magnitude", 0)),
            0 if row["confidence"] == "high" else 1,
            row["message"],
        )
    )
    return rows


def _top_changed_ranges(delta: dict, limit: int = 3) -> tuple[list[dict], list[dict]]:
    ranges = list(delta.get("ranges") or [])
    improved = sorted(
        (row for row in ranges if int(row["improved"]) > int(row["regressed"])),
        key=lambda row: (-(int(row["improved"]) - int(row["regressed"])), -int(row["changed"])),
    )[:limit]
    regressed = sorted(
        (row for row in ranges if int(row["regressed"]) > int(row["improved"])),
        key=lambda row: (-(int(row["regressed"]) - int(row["improved"])), -int(row["changed"])),
    )[:limit]
    return improved, regressed


def _format_changed_ranges(label: str, rows: list[dict]) -> str:
    values = ", ".join(
        f"+{int(row['start']):04X}..+{int(row['end']):04X} (+{int(row['improved'])}/-{int(row['regressed'])})"
        for row in rows
    )
    return f"{label}: {values or 'none'}"


def main() -> None:
    args = parse_args()
    if args.map_limit is not None and args.map_limit < 0:
        raise SystemExit("--map-limit must be zero or positive")
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)
    asm_dir = repo_path(Path("build") / "asm")
    diff_dir = ensure_build_subdir("diff")
    history_dir = repo_path(Path("build") / "history" / slug)

    orig_bin = asm_dir / f"orig_{slug}.bin"
    orig_json = asm_dir / f"orig_{slug}.json"
    rebuilt_bin = asm_dir / f"rebuilt_{slug}.bin"
    rebuilt_json = asm_dir / f"rebuilt_{slug}.json"
    rebuilt_lines_json = asm_dir / f"rebuilt_{slug}.lines.json"
    report_path = diff_dir / f"{slug}.txt"

    if not orig_bin.exists():
        raise SystemExit(f"Missing original bytes: {orig_bin}")
    if not orig_json.exists():
        raise SystemExit(f"Missing original metadata: {orig_json}")
    if not rebuilt_bin.exists():
        raise SystemExit(f"Missing rebuilt bytes: {rebuilt_bin}")
    if not rebuilt_json.exists():
        raise SystemExit(f"Missing rebuilt metadata: {rebuilt_json}")

    original_bytes = orig_bin.read_bytes()
    original_meta = json.loads(orig_json.read_text(encoding="utf-8"))
    rebuilt_bytes = rebuilt_bin.read_bytes()
    rebuilt_meta = json.loads(rebuilt_json.read_text(encoding="utf-8"))
    rebuilt_lines = (
        json.loads(rebuilt_lines_json.read_text(encoding="utf-8"))
        if rebuilt_lines_json.exists()
        else {}
    )
    owner_symbol_validation = owning_function_symbol_validation(
        record["name"], str((rebuilt_meta.get("symbol") or {}).get("name") or "")
    )
    owner_symbol_mismatch = (
        owner_symbol_validation if owner_symbol_validation["status"] == "mismatch" else None
    )
    if int(rebuilt_lines.get("schema") or 0) < 2:
        listing_path = asm_dir / f"rebuilt_{slug}.cod"
        if listing_path.exists():
            rebuilt_lines = {
                **rebuilt_lines,
                **parse_listing_file(listing_path),
                "schema": 2,
                "listing": str(listing_path),
            }
    rebuilt_line_lookup = lambda offset: source_line_for_offset(rebuilt_lines, offset)
    relocations = list(rebuilt_meta.get("relocations") or [])

    masked_original, masked_rebuilt, relocation_validation = compatible_relocation_masks(
        original_bytes, rebuilt_bytes, relocations, va, original_meta.get("ranges") or []
    )
    metrics = byte_diff_metrics(masked_original, masked_rebuilt)
    mismatch_text = str(metrics["first_mismatch_offset"])
    mismatch = int(mismatch_text) if mismatch_text else None

    original_instructions = decode_instruction_ranges(original_bytes, original_meta.get("ranges") or [])
    rebuilt_instructions = decode_instructions(rebuilt_bytes, va, relocations)
    original_memory = collect_memory_evidence(
        original_instructions,
        [],
        direct_call_cleanups(original_instructions),
    )
    stack_home_pairing = _stack_home_pairing(original_memory, rebuilt_lines)
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
    for call in rebuilt_calls:
        line = source_line_for_offset(rebuilt_lines, int(call["offset"]))
        if line is not None:
            call["source_line"] = line
            call["source_file"] = rebuilt_lines.get("source", "")
    call_map = call_alignment(original_calls, rebuilt_calls)
    call_site_status_counts = {
        status: sum(row.get("status") == status for row in call_map.get("rows") or [])
        for status in ("equal", "replace", "delete", "insert")
    }
    call_difference_row = call_map.get("first_difference_row")
    original_call_counts = call_target_counts(original_calls)
    rebuilt_call_counts = call_target_counts(rebuilt_calls)
    call_target_deltas = call_count_deltas(original_call_counts, rebuilt_call_counts)
    original_blocks = basic_blocks(original_instructions, original_calls)
    rebuilt_blocks = basic_blocks(rebuilt_instructions, rebuilt_calls)
    for block in original_blocks:
        line = pdb_line_for_address(va, va + int(block["offset"]))
        if line is not None:
            block["source_line"] = line
    for block in rebuilt_blocks:
        line = source_line_for_offset(rebuilt_lines, int(block["offset"]))
        if line is not None:
            block["source_line"] = line
    block_map = block_alignment(original_blocks, rebuilt_blocks)
    relocated_call_pairs = _relocated_call_pairs(block_map, original_calls, rebuilt_calls)
    cfg_issues = _cfg_alignment_issues(block_map)
    hard_discrepancies = _hard_discrepancies(
        call_map, actionable_target_mismatches, call_target_deltas, block_map
    )
    exact = (
        mismatch is None
        and not relocation_validation["target_mismatches"]
        and owner_symbol_mismatch is None
    )
    mismatch_classification = classify_mismatch(
        original_instructions,
        rebuilt_instructions,
        masked_original,
        masked_rebuilt,
        shape=shape,
        call_map=call_map,
        call_target_deltas=call_target_deltas,
        target_mismatches=relocation_validation["target_mismatches"],
        cfg_issues=cfg_issues,
        owner_symbol_mismatch=owner_symbol_mismatch,
    )

    previous_bin = history_dir / "previous.bin"
    previous_diff = history_dir / "previous.diff.json"
    delta = None
    iteration_call_deltas: list[dict] = []
    if previous_bin.exists() and not args.no_iteration:
        delta = iteration_delta(original_bytes, previous_bin.read_bytes(), rebuilt_bytes)
    if previous_diff.exists() and not args.no_iteration:
        previous_payload = json.loads(previous_diff.read_text(encoding="utf-8"))
        previous_counts = list(previous_payload.get("rebuilt_call_counts") or [])
        if previous_counts:
            iteration_call_deltas = call_count_deltas(previous_counts, rebuilt_call_counts)

    guidance = _workflow_guidance(
        rebuilt_meta,
        shape,
        original_prologue,
        rebuilt_prologue,
        None if call_difference_row is None else (0, 0),
        call_target_deltas,
        guidance_relocation_validation,
        owner_symbol_validation,
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
        "owning_symbol_validation": owner_symbol_validation,
        "rebuilt_extraction": rebuilt_meta,
        "rebuilt_source_map": {
            "source": rebuilt_lines.get("source", ""),
            "line_changes": rebuilt_lines.get("line_changes", []),
            "stack_locals": rebuilt_lines.get("stack_locals", []),
            "stack_homes": rebuilt_lines.get("stack_homes", []),
        },
        "stack_home_pairing": stack_home_pairing,
        "instruction_shape": {key: value for key, value in shape.items() if key not in {"opcodes", "first_change"}},
        "original_prologue": original_prologue,
        "rebuilt_prologue": rebuilt_prologue,
        "original_control_flow": original_flow,
        "rebuilt_control_flow": rebuilt_flow,
        "original_call_counts": original_call_counts,
        "rebuilt_call_counts": rebuilt_call_counts,
        "call_target_count_deltas": call_target_deltas,
        "call_alignment": call_map,
        "call_site_status_counts": call_site_status_counts,
        "relocated_call_pairs": relocated_call_pairs,
        "block_alignment": _compact_block_alignment(block_map),
        "cfg_alignment_issues": cfg_issues,
        "hard_discrepancies": hard_discrepancies,
        "mismatch_classification": mismatch_classification,
        "iteration_call_target_deltas": iteration_call_deltas,
        "iteration_delta": delta,
        "workflow_stage": guidance[0].split(":", 1)[-1].strip() if guidance else "",
        "workflow_guidance": guidance[1:],
        **metrics,
        "result": "MATCH" if exact else "MISMATCH",
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
        f"shape similarity {float(shape['similarity_percent']):.2f}%; longest aligned run {shape['longest_equal_run']}; "
        f"exact-block coverage {float(block_map['matched_coverage_percent']):.2f}%",
        f"Calls: original {len(original_calls)}, rebuilt {len(rebuilt_calls)}; "
        f"aligned {float(call_map['similarity_percent']):.2f}% (prefix {call_map['aligned_prefix_calls']}); "
        f"site gaps -{call_site_status_counts['delete']}/+{call_site_status_counts['insert']} "
        f"repl {call_site_status_counts['replace']}; target-count differences {len(call_target_deltas)}; "
        f"relocated call sites {len(relocated_call_pairs)}; "
        f"relocations safely masked {relocation_validation['compatible']}/{len(relocations)}",
        "Owner symbol: "
        f"{owner_symbol_validation['status']} "
        f"(target {owner_symbol_validation['expected'] or '<unknown>'}; "
        f"rebuilt {owner_symbol_validation['rebuilt'] or '<unknown>'})",
        "CFG signals (orig/rebuilt): "
        f"cond {original_flow['conditional_branches']}/{rebuilt_flow['conditional_branches']}, "
        f"jumps {original_flow['unconditional_branches']}/{rebuilt_flow['unconditional_branches']}, "
        f"returns {original_flow['returns']}/{rebuilt_flow['returns']}",
        f"Strict positional diff: {metrics['diff_bytes']} bytes ({float(metrics['diff_percent']):.4f}%), "
        f"{metrics['diff_spans']} span(s)",
        f"Edit/resync diagnostic: raw cost {metrics['edit_diff_bytes']}, "
        f"bounded cost {float(metrics['edit_cost_percent_total']):.2f}%, "
        f"similarity {float(metrics['resync_similarity_percent']):.2f}% ({metrics['edit_equal_bytes']} equal bytes)",
    ]
    if not exact:
        summary.append(
            "Diagnostic class (audit only): "
            f"{mismatch_classification['primary']} [{str(mismatch_classification['confidence']).upper()}]; "
            "does not establish equivalence"
        )
    if delta is not None:
        summary.append(
            "Emitted-code movement this iteration: "
            f"changed {delta['changed_bytes']} byte(s) in {delta['changed_spans']} span(s), "
            f"assembly-closer {delta['strict_improvements']}, assembly-farther {delta['strict_regressions']}, "
            f"neutral {delta['neutral_changes']}, size {delta['size_delta']:+d}"
        )
        improved_ranges, regressed_ranges = _top_changed_ranges(delta)
        summary.append(_format_changed_ranges("Top assembly-closer ranges", improved_ranges))
        summary.append(_format_changed_ranges("Top assembly-farther ranges", regressed_ranges))

    summary.append(f"Result: {'MATCH' if exact else 'MISMATCH'}")
    if mismatch is not None:
        summary.append(f"First strict mismatch: +{mismatch:04X} (VA {va + mismatch:08X})")

    detail: list[str] = []
    if not exact:
        detail.append("")
        detail.append("Mismatch pattern evidence (audit only; exactness and status are unchanged):")
        for label in list(mismatch_classification.get("labels") or [])[:6]:
            detail.append(f"  [{str(label['confidence']).upper():6}] {label['id']}")
            for evidence in list(label.get("evidence") or [])[:4]:
                detail.append(f"           - {evidence}")
    if hard_discrepancies:
        detail.append("")
        detail.append("Prioritized call-surface discrepancies (diagnostic confidence shown):")
        for row in hard_discrepancies[:8]:
            detail.append(f"  [{str(row['confidence']).upper():6}] {row['kind']}: {row['message']}")
    if iteration_call_deltas:
        detail.append("")
        detail.append("Call-target changes made by this iteration (current - previous):")
        detail.extend(_format_iteration_call_deltas(iteration_call_deltas))
    if call_target_deltas:
        detail.append("")
        detail.append("Call target count differences (rebuilt/original; aggregate diagnostic only):")
        detail.extend(_format_call_count_deltas(call_target_deltas))
    if block_map.get("strong_islands"):
        detail.append("")
        detail.append("Strongest exact basic-block islands:")
        for island in block_map["strong_islands"][:5]:
            detail.append(
                f"  {int(island['instructions']):4d} insn / {int(island['blocks']):3d} block(s): "
                f"orig +{int(island['original_start']):04X}..+{int(island['original_end']):04X} | "
                f"rebuilt +{int(island['rebuilt_start']):04X}..+{int(island['rebuilt_end']):04X}"
            )
    if block_map.get("relocated_pairs"):
        detail.append("")
        detail.append("Order-insensitive relocated cold-block candidates:")
        for pair in block_map["relocated_pairs"][:8]:
            detail.append(
                f"  [{str(pair['confidence']).upper():6}] {int(pair['instruction_count']):3d} insn: "
                f"orig +{int(pair['original']['offset']):04X} -> rebuilt +{int(pair['rebuilt']['offset']):04X} "
                f"(delta {int(pair['offset_delta']):+d})"
            )
    if relocated_call_pairs:
        detail.append("")
        detail.extend(_format_relocated_call_pairs(relocated_call_pairs, va))
    if cfg_issues:
        detail.append("")
        detail.append("Attributed CFG edge/terminator differences:")
        detail.extend(_format_cfg_issues(cfg_issues[:8]))
    if block_map.get("first_difference_row") is not None:
        detail.append("")
        detail.append("First context-aware basic-block divergence:")
        detail.extend(_format_block_context(block_map))
    if shape.get("first_change"):
        detail.append("")
        detail.append("First paired instruction-shape hunk (! differs):")
        detail.extend(
            paired_instruction_context(
                original_instructions,
                rebuilt_instructions,
                shape,
                va,
                rebuilt_line_for_offset=rebuilt_line_lookup,
            )
        )
    if call_difference_row is not None:
        detail.append("")
        detail.append("First context-aware call-site divergence (H/M/L confidence):")
        detail.extend(_format_call_context(call_map, int(call_difference_row), va))
    if actionable_target_mismatches:
        detail.append("")
        detail.append("Known direct-control target mismatches (not masked):")
        for row in actionable_target_mismatches[:12]:
            detail.append(
                f"  +{int(row['offset']):04X} {row.get('kind', 'call')}: "
                f"original {row['original']} | rebuilt {row['rebuilt']}"
            )
    if owner_symbol_mismatch:
        detail.append("")
        detail.append("Owning function symbol mismatch:")
        detail.append(
            f"  target {owner_symbol_mismatch['expected']} | rebuilt {owner_symbol_mismatch['rebuilt']}"
        )
    raw_detail: list[str] = []
    if mismatch is not None:
        raw_detail.append("")
        raw_detail.append("First raw-byte edit/resync hunks (secondary diagnostic):")
        raw_detail.extend(format_edit_hunks(metrics, masked_original, masked_rebuilt))

    map_detail: list[str] = []
    call_target_filter = args.call_map_target or args.call_map_target_exact or args.call_map_target_regex
    call_target_filter_mode = (
        "exact" if args.call_map_target_exact else ("regex" if args.call_map_target_regex else "contains")
    )
    if args.call_map or args.call_map_unmatched or call_target_filter:
        map_detail.append("")
        try:
            map_detail.extend(
                _format_full_call_map(
                    call_map,
                    va,
                    unmatched_only=args.call_map_unmatched,
                    target_filter=call_target_filter,
                    target_filter_mode=call_target_filter_mode,
                    limit=args.map_limit,
                )
            )
        except ValueError as exc:
            raise SystemExit(str(exc)) from exc
        if relocated_call_pairs and args.call_map_unmatched:
            map_detail.append("")
            map_detail.extend(_format_relocated_call_pairs(relocated_call_pairs, va))
    if args.block_map or args.block_map_differences:
        map_detail.append("")
        map_detail.extend(
            _format_full_block_map(
                block_map,
                differences_only=args.block_map_differences,
                limit=args.map_limit,
            )
        )
    if args.stack_map:
        map_detail.append("")
        map_detail.extend(_format_stack_map(stack_home_pairing))
    if args.focus_range:
        map_detail.append("")
        try:
            map_detail.extend(
                _format_focus_range(
                    args.focus_range,
                    va,
                    original_instructions,
                    rebuilt_instructions,
                    block_map,
                    rebuilt_line_lookup,
                )
            )
        except ValueError as exc:
            raise SystemExit(str(exc)) from exc

    report_lines = summary + [""] + guidance + detail + raw_detail + map_detail
    report_path.write_text("\n".join(report_lines) + "\n", encoding="utf-8")

    if args.verbose or args.detail == "full":
        console_detail = detail + raw_detail
    elif args.detail == "concise" or (args.detail == "auto" and expected_size >= 2000):
        # Giant-function mode: keep hard discrepancies and only the first local
        # block/instruction/call contexts. Aggregate tables and raw byte hunks
        # remain in the report and JSON.
        console_detail = []
        if hard_discrepancies:
            console_detail += ["", "Top hard discrepancy:"]
            row = hard_discrepancies[0]
            console_detail.append(f"  [{str(row['confidence']).upper()}] {row['kind']}: {row['message']}")
        if call_target_deltas:
            console_detail += ["", "Call target count differences (delta, rebuilt/original):"]
            console_detail += _format_call_count_deltas(call_target_deltas, limit=10)
        if block_map.get("first_difference_row") is not None:
            console_detail += ["", "First basic-block divergence:"] + _format_block_context(block_map, radius=1)
        if cfg_issues and not call_target_deltas:
            console_detail += ["", "First attributed CFG difference:"] + _format_cfg_issues(cfg_issues[:1])
        if shape.get("first_change"):
            console_detail += ["", "First instruction-shape hunk:"] + paired_instruction_context(
                original_instructions,
                rebuilt_instructions,
                shape,
                va,
                radius=2,
                rebuilt_line_for_offset=rebuilt_line_lookup,
            )
        if call_difference_row is not None:
            console_detail += ["", "First call-site divergence:"] + _format_call_context(
                call_map, int(call_difference_row), va, radius=2
            )
    else:
        console_detail = detail

    console_lines = summary + [""] + guidance
    if not exact:
        console_lines += console_detail
    console_lines += map_detail
    print("\n".join(console_lines))
    raise SystemExit(0 if exact else 1)


if __name__ == "__main__":
    main()
