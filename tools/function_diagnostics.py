from __future__ import annotations

import difflib
import re
from collections import Counter
from dataclasses import dataclass, replace
from functools import lru_cache
from typing import Callable, Iterable

from iced_x86 import Decoder, DecoderOptions, FlowControl, Formatter, FormatterSyntax

from common import CONFIG_DIR, load_functions, load_pdb_function_line_changes


_REGISTER_RE = re.compile(
    r"\b(?:e?[abcd]x|e?[sd]i|e?[sb]p|[abcd][lh]|[cdefgs]s|st[0-7]|xmm\d+)\b",
    re.IGNORECASE,
)
_VIRTUAL_SLOT_RE = re.compile(
    r"call\s+dword\s+\[(e(?:ax|bx|cx|dx|si|di|bp))\+([0-9a-f]+)h\]$",
    re.IGNORECASE,
)
_CALL_REGISTER_RE = re.compile(r"call\s+(e(?:ax|bx|cx|dx|si|di|bp))$", re.IGNORECASE)
_CALL_STACK_RE = re.compile(r"call\s+dword\s+\[esp(?:\+([0-9a-f]+)h?)?\]$", re.IGNORECASE)
_MOV_RE = re.compile(r"mov\s+(e(?:ax|bx|cx|dx|si|di|bp)),(.+)$", re.IGNORECASE)
_MOV_STACK_STORE_RE = re.compile(
    r"mov\s+(?:dword\s+)?\[esp(?:\+([0-9a-f]+)h?)?\],(e(?:ax|bx|cx|dx|si|di|bp))$",
    re.IGNORECASE,
)
_MEMORY_RE = re.compile(r"(?:dword\s+)?\[(e(?:ax|bx|cx|dx|si|di|bp|sp))(?:(\+|-)([0-9a-f]+)h?)?\]$", re.IGNORECASE)
_REGISTER_RE_FULL = re.compile(r"e(?:ax|bx|cx|dx|si|di|bp)$", re.IGNORECASE)
_STACK_ADJUST_RE = re.compile(r"(add|sub)\s+esp,([0-9a-f]+)h?$", re.IGNORECASE)


@dataclass(frozen=True)
class DecodedInstruction:
    offset: int
    end: int
    address: int
    text: str
    mnemonic: str
    flow_control: int
    target: int
    data: bytes
    relocation_symbol: str = ""


def decode_instructions(code: bytes, start_va: int, relocations: Iterable[dict] = ()) -> list[DecodedInstruction]:
    relocation_rows = list(relocations)
    decoder = Decoder(32, code, ip=start_va, options=DecoderOptions.NONE)
    formatter = Formatter(FormatterSyntax.NASM)
    result: list[DecodedInstruction] = []
    while decoder.can_decode:
        instruction = decoder.decode()
        offset = instruction.ip - start_va
        end = instruction.next_ip - start_va
        if end <= offset:
            break
        text = formatter.format(instruction)
        relocation_symbol = ""
        for relocation in relocation_rows:
            relocation_offset = int(relocation["offset"])
            if offset <= relocation_offset < end:
                relocation_symbol = str(relocation.get("symbol_name") or "")
                break
        result.append(
            DecodedInstruction(
                offset=offset,
                end=end,
                address=instruction.ip,
                text=text,
                mnemonic=text.split(None, 1)[0].lower() if text else "",
                flow_control=instruction.flow_control,
                target=instruction.near_branch_target,
                data=code[offset:end],
                relocation_symbol=relocation_symbol,
            )
        )
    return result


def decode_instruction_ranges(
    code: bytes,
    ranges: Iterable[dict[str, object]],
) -> list[DecodedInstruction]:
    """Decode concatenated original bytes at their real discontiguous VAs."""
    result: list[DecodedInstruction] = []
    combined_offset = 0
    for row in ranges:
        start_text = str(row.get("start") or "0")
        start = int(start_text, 16)
        size = int(row.get("size_bytes") or 0)
        chunk = code[combined_offset:combined_offset + size]
        for instruction in decode_instructions(chunk, start):
            result.append(
                replace(
                    instruction,
                    offset=combined_offset + instruction.offset,
                    end=combined_offset + instruction.end,
                )
            )
        combined_offset += size
    if combined_offset != len(code):
        raise ValueError(
            f"Original range metadata covers {combined_offset} byte(s), but the binary has {len(code)}"
        )
    return result


def clean_symbol_name(name: str) -> str:
    value = name.strip()
    lowered = value.lower()
    if value.startswith("??_L@") or "eh_vector_constructor_iterator" in lowered:
        return "eh_vector_constructor_iterator"
    if value.startswith("??_M@") or "eh_vector_destructor_iterator" in lowered:
        return "eh_vector_destructor_iterator"
    if value.startswith("__imp_"):
        value = value[6:]
    if value.startswith("??2@") or value.startswith("??_U@"):
        return "operator_new"
    if value.startswith("??3@") or value.startswith("??_V@"):
        return "operator_delete"
    if value.startswith("??0") or value.startswith("??1"):
        return value[3:].split("@", 1)[0].lower()
    if value.startswith("??_G") or value.startswith("??_E"):
        return value[4:].split("@", 1)[0].lower()
    if value.startswith("?"):
        value = value[1:].split("@", 1)[0]
    else:
        value = value.lstrip("_")
        value = value.split("@", 1)[0]
    return value.lstrip("~").lower()


def direct_call_symbols_match(original: str, rebuilt: str) -> bool:
    """Compare direct-call symbols without collapsing known overload identity.

    Most original inventory names are undecorated, so they still require the
    historical normalized comparison.  When both sides have decorated C++
    names, however, compare the complete symbols: reducing at the first ``@``
    would make distinct overloads indistinguishable.
    """
    original_value = original.strip()
    rebuilt_value = rebuilt.strip()
    if original_value.startswith("__imp_"):
        original_value = original_value[6:]
    if rebuilt_value.startswith("__imp_"):
        rebuilt_value = rebuilt_value[6:]
    # VC5 LIBC.LIB chkstk.obj exports both names at offset zero for the same
    # 0x2F-byte helper body. The compiler can select either relocation name.
    stack_probe_aliases = {"__alloca_probe", "__chkstk"}
    if {original_value, rebuilt_value} == stack_probe_aliases:
        return True
    if original_value.startswith("?") and rebuilt_value.startswith("?"):
        return original_value == rebuilt_value
    return clean_symbol_name(original_value) == clean_symbol_name(rebuilt_value)


@lru_cache(maxsize=1)
def _function_names_by_va() -> dict[int, str]:
    return {int(record["va"], 16): record["name"] for record in load_functions()}


@lru_cache(maxsize=1)
def _original_symbol_overrides() -> dict[int, str]:
    """Load overload-specific original symbols lost by the inventory export."""
    path = CONFIG_DIR / "original_symbol_overrides.txt"
    if not path.exists():
        return {}
    result: dict[int, str] = {}
    for line_number, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        line = raw_line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 1)
        if len(parts) != 2:
            raise ValueError(f"{path}:{line_number}: expected '<VA> <decorated-symbol>'")
        va_text, symbol = parts
        result[int(va_text, 16)] = symbol.strip()
    return result


@lru_cache(maxsize=1)
def _pdb_line_changes() -> dict[str, list[dict[str, str]]]:
    return load_pdb_function_line_changes()


def original_call_target(instruction: DecodedInstruction, names_by_va: dict[int, str]) -> str:
    if instruction.flow_control != FlowControl.CALL:
        return ""
    override = _original_symbol_overrides().get(instruction.target)
    if override:
        return override
    return names_by_va.get(instruction.target, f"{instruction.target:08X}")


def _block_instruction_ranges(instructions: list[DecodedInstruction]) -> list[tuple[int, int]]:
    """Return half-open instruction-index ranges for ordinary basic blocks."""
    if not instructions:
        return []
    address_to_index = {item.address: index for index, item in enumerate(instructions)}
    leaders = {0}
    terminators = {
        FlowControl.CONDITIONAL_BRANCH,
        FlowControl.UNCONDITIONAL_BRANCH,
        FlowControl.RETURN,
    }
    for index, instruction in enumerate(instructions):
        if index and instruction.address != instructions[index - 1].address + len(instructions[index - 1].data):
            leaders.add(index)
        if instruction.flow_control in (FlowControl.CONDITIONAL_BRANCH, FlowControl.UNCONDITIONAL_BRANCH):
            target_index = address_to_index.get(instruction.target)
            if target_index is not None:
                leaders.add(target_index)
        if instruction.flow_control in terminators and index + 1 < len(instructions):
            leaders.add(index + 1)
    ordered = sorted(leaders)
    return [
        (start, ordered[pos + 1] if pos + 1 < len(ordered) else len(instructions))
        for pos, start in enumerate(ordered)
    ]


def _loaded_virtual_slots(instructions: list[DecodedInstruction]) -> dict[int, int]:
    """Recognize VC5's loaded virtual slots through registers and stack spills.

    This is intentionally conservative.  It only propagates a slot loaded from a
    register that was itself loaded from ``[object]`` in the same basic block.  A
    slot spilled to ``[esp+N]`` is keyed by its stack coordinate, accounting for
    intervening pushes, so the later ``call [esp+M]`` is not misreported as vslot M.
    """
    result: dict[int, int] = {}
    for start, end in _block_instruction_ranges(instructions):
        vtable_registers: set[str] = set()
        slot_registers: dict[str, int] = {}
        stack_slots: dict[int, int] = {}
        stack_delta = 0
        for instruction in instructions[start:end]:
            text = instruction.text.lower().strip()
            call_match = _CALL_REGISTER_RE.fullmatch(text)
            if call_match:
                register = call_match.group(1)
                if register in slot_registers:
                    result[instruction.offset] = slot_registers[register]
            stack_call_match = _CALL_STACK_RE.fullmatch(text)
            if stack_call_match:
                displacement = int(stack_call_match.group(1) or "0", 16)
                coordinate = stack_delta + displacement
                if coordinate in stack_slots:
                    result[instruction.offset] = stack_slots[coordinate]

            stack_store_match = _MOV_STACK_STORE_RE.fullmatch(text)
            if stack_store_match:
                displacement = int(stack_store_match.group(1) or "0", 16)
                register = stack_store_match.group(2)
                coordinate = stack_delta + displacement
                if register in slot_registers:
                    stack_slots[coordinate] = slot_registers[register]
                else:
                    stack_slots.pop(coordinate, None)

            mov_match = _MOV_RE.fullmatch(text)
            if mov_match:
                destination = mov_match.group(1)
                source = mov_match.group(2).strip()
                vtable_registers.discard(destination)
                slot_registers.pop(destination, None)
                memory_match = _MEMORY_RE.fullmatch(source)
                if memory_match:
                    base = memory_match.group(1)
                    sign = memory_match.group(2)
                    displacement_text = memory_match.group(3)
                    displacement = 0 if displacement_text is None else int(displacement_text, 16)
                    if sign == "-":
                        displacement = -displacement
                    if displacement == 0 and base != "esp":
                        vtable_registers.add(destination)
                    elif base in vtable_registers and displacement >= 0:
                        slot_registers[destination] = displacement
                elif _REGISTER_RE_FULL.fullmatch(source):
                    if source in vtable_registers:
                        vtable_registers.add(destination)
                    if source in slot_registers:
                        slot_registers[destination] = slot_registers[source]
            elif text.startswith(("pop ", "lea ", "xor ", "add ", "sub ", "and ", "or ")):
                parts = text.split(None, 1)
                destination = parts[1].split(",", 1)[0].strip() if len(parts) == 2 else ""
                if _REGISTER_RE_FULL.fullmatch(destination):
                    vtable_registers.discard(destination)
                    slot_registers.pop(destination, None)

            if instruction.flow_control in (FlowControl.CALL, FlowControl.INDIRECT_CALL):
                # Caller-saved values do not survive a call.  Callee-saved vtable
                # bases remain useful for later loaded-slot calls.
                for register in ("eax", "ecx", "edx"):
                    vtable_registers.discard(register)
                    slot_registers.pop(register, None)
                stack_slots.clear()

            if text.startswith("push "):
                stack_delta -= 4
            elif text.startswith("pop "):
                stack_delta += 4
            else:
                adjust_match = _STACK_ADJUST_RE.fullmatch(text)
                if adjust_match:
                    amount = int(adjust_match.group(2), 16)
                    stack_delta += amount if adjust_match.group(1) == "add" else -amount
                elif text.startswith(("lea esp,", "mov esp,")):
                    # Unknown stack rebasing invalidates coordinates accumulated
                    # earlier in the block.
                    stack_slots.clear()
                    stack_delta = 0
    return result


def call_fingerprint(
    instructions: list[DecodedInstruction],
    original: bool,
    names_by_va: dict[int, str] | None = None,
) -> list[dict[str, object]]:
    names = names_by_va or _function_names_by_va()
    loaded_slots = _loaded_virtual_slots(instructions)
    address_to_offset = {item.address: item.offset for item in instructions}
    block_ranges = _block_instruction_ranges(instructions)
    block_for_instruction: dict[int, tuple[int, int, int]] = {}
    for block_index, (start, end) in enumerate(block_ranges):
        for instruction_index in range(start, end):
            block_for_instruction[instruction_index] = (block_index, start, end)
    calls: list[dict[str, object]] = []
    for instruction_index, instruction in enumerate(instructions):
        block_index, block_start, block_end = block_for_instruction.get(
            instruction_index, (0, 0, len(instructions))
        )
        if instruction.flow_control == FlowControl.CALL:
            if not original and instruction.relocation_symbol:
                target = instruction.relocation_symbol
            elif instruction.target in address_to_offset:
                target = f"internal+0x{address_to_offset[instruction.target]:X}"
            else:
                target = original_call_target(instruction, names) if original else instruction.relocation_symbol
            calls.append(
                {
                    "offset": instruction.offset,
                    "kind": "direct",
                    "target": clean_symbol_name(target) if target else "unresolved",
                    "display": clean_symbol_name(target) if target else "unresolved",
                    "instruction_index": instruction_index,
                    "block_index": block_index,
                    "block_offset": instructions[block_start].offset,
                }
            )
        elif instruction.flow_control == FlowControl.INDIRECT_CALL:
            slot_match = _VIRTUAL_SLOT_RE.search(instruction.text)
            if slot_match:
                slot = int(slot_match.group(2), 16)
                target = f"vslot+0x{slot:X}"
                kind = "virtual"
            elif instruction.offset in loaded_slots:
                slot = loaded_slots[instruction.offset]
                target = f"vslot+0x{slot:X}"
                kind = "virtual"
            else:
                target = "indirect"
                kind = "indirect"
            calls.append(
                {
                    "offset": instruction.offset,
                    "kind": kind,
                    "target": target,
                    "display": target,
                    "instruction_index": instruction_index,
                    "block_index": block_index,
                    "block_offset": instructions[block_start].offset,
                }
            )
        if calls and int(calls[-1].get("instruction_index", -1)) == instruction_index:
            setup_start = max(block_start, instruction_index - 4)
            calls[-1]["setup"] = [instruction_shape(item) for item in instructions[setup_start:instruction_index]]
            calls[-1]["block_end_offset"] = instructions[block_end - 1].end
            post_end = min(block_end, instruction_index + 3)
            calls[-1]["post"] = [
                instruction_shape(item) for item in instructions[instruction_index + 1:post_end]
            ]
            cleanup = 0
            if instruction_index + 1 < block_end:
                cleanup_match = re.fullmatch(
                    r"add esp,([0-9a-f]+)h?", instructions[instruction_index + 1].text.lower()
                )
                if cleanup_match:
                    cleanup = int(cleanup_match.group(1), 16)
            calls[-1]["caller_cleanup_bytes"] = cleanup
            push_count = 0
            scan = instruction_index - 1
            while scan >= block_start and instruction_index - scan <= 12:
                previous = instructions[scan]
                if previous.flow_control in (
                    FlowControl.CALL,
                    FlowControl.INDIRECT_CALL,
                    FlowControl.CONDITIONAL_BRANCH,
                    FlowControl.UNCONDITIONAL_BRANCH,
                    FlowControl.RETURN,
                ):
                    break
                if previous.mnemonic == "push":
                    push_count += 1
                scan -= 1
            calls[-1]["nearby_push_count"] = push_count
    for index, row in enumerate(calls):
        row["previous_targets"] = [
            str(item["target"]) for item in calls[max(0, index - 2):index]
        ]
        row["next_targets"] = [
            str(item["target"]) for item in calls[index + 1:index + 3]
        ]
    return calls


def basic_blocks(
    instructions: list[DecodedInstruction], calls: list[dict[str, object]] | None = None
) -> list[dict[str, object]]:
    """Build JSON-friendly basic-block records with normalized signatures."""
    if not instructions:
        return []
    call_rows = calls or []
    calls_by_block: dict[int, list[dict[str, object]]] = {}
    for call in call_rows:
        calls_by_block.setdefault(int(call.get("block_index", -1)), []).append(call)
    address_to_offset = {item.address: item.offset for item in instructions}
    ranges = _block_instruction_ranges(instructions)
    blocks: list[dict[str, object]] = []
    for block_index, (start, end) in enumerate(ranges):
        body = instructions[start:end]
        last = body[-1]
        successors: list[int] = []
        if last.flow_control == FlowControl.CONDITIONAL_BRANCH:
            if last.target in address_to_offset:
                successors.append(address_to_offset[last.target])
            if end < len(instructions) and last.address + len(last.data) == instructions[end].address:
                successors.append(instructions[end].offset)
        elif last.flow_control == FlowControl.UNCONDITIONAL_BRANCH:
            if last.target in address_to_offset:
                successors.append(address_to_offset[last.target])
        elif (
            last.flow_control != FlowControl.RETURN
            and end < len(instructions)
            and last.address + len(last.data) == instructions[end].address
        ):
            successors.append(instructions[end].offset)
        block_calls = calls_by_block.get(block_index, [])
        shapes = [instruction_shape(item) for item in body]
        blocks.append(
            {
                "index": block_index,
                "offset": body[0].offset,
                "end_offset": body[-1].end,
                "instruction_start": start,
                "instruction_end": end,
                "instruction_count": len(body),
                "shapes": shapes,
                "signature": "\n".join(shapes),
                "terminator": shapes[-1],
                "successors": successors,
                "calls": [f"{row['kind']}:{row['target']}" for row in block_calls],
            }
        )
    return blocks


def _setup_similarity(left: dict[str, object], right: dict[str, object]) -> float:
    a = list(left.get("setup") or [])
    b = list(right.get("setup") or [])
    if not a and not b:
        return 1.0
    return difflib.SequenceMatcher(a=a, b=b, autojunk=False).ratio()


def call_alignment(original: list[dict[str, object]], rebuilt: list[dict[str, object]]) -> dict[str, object]:
    """Weighted, context-aware call-site alignment.

    Repeated calls are deliberately low confidence unless neighboring calls and
    setup shapes agree.  The result is diagnostic and never affects exactness.
    """
    left_counts = Counter((str(row["kind"]), str(row["target"])) for row in original)
    right_counts = Counter((str(row["kind"]), str(row["target"])) for row in rebuilt)
    n, m = len(original), len(rebuilt)
    gap = -7.0
    scores = [[0.0] * (m + 1) for _ in range(n + 1)]
    trace = [[""] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        scores[i][0] = i * gap
        trace[i][0] = "D"
    for j in range(1, m + 1):
        scores[0][j] = j * gap
        trace[0][j] = "I"

    def pair_score(left: dict[str, object], right: dict[str, object]) -> float:
        left_key = (str(left["kind"]), str(left["target"]))
        right_key = (str(right["kind"]), str(right["target"]))
        setup = _setup_similarity(left, right)
        if left_key == right_key:
            frequency = max(left_counts[left_key], right_counts[right_key])
            uniqueness = 5.0 / max(frequency, 1)
            neighbors = 0.0
            if left.get("previous_targets") == right.get("previous_targets"):
                neighbors += 1.5
            if left.get("next_targets") == right.get("next_targets"):
                neighbors += 1.5
            return 12.0 + uniqueness + neighbors + setup * 2.0
        if left["kind"] == right["kind"]:
            return -2.0 + setup * 3.0
        return -6.0 + setup

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            diagonal = scores[i - 1][j - 1] + pair_score(original[i - 1], rebuilt[j - 1])
            delete = scores[i - 1][j] + gap
            insert = scores[i][j - 1] + gap
            best = max(diagonal, delete, insert)
            # Prefer an exact diagonal on ties, otherwise prefer a gap over a
            # speculative replacement.
            exact = (original[i - 1]["kind"], original[i - 1]["target"]) == (
                rebuilt[j - 1]["kind"], rebuilt[j - 1]["target"]
            )
            if diagonal == best and (exact or (diagonal > delete and diagonal > insert)):
                trace[i][j] = "M"
            elif delete == best:
                trace[i][j] = "D"
            else:
                trace[i][j] = "I"
            scores[i][j] = best

    rows: list[dict[str, object]] = []
    i, j = n, m
    while i or j:
        operation = trace[i][j]
        if operation == "M":
            left = original[i - 1]
            right = rebuilt[j - 1]
            exact = (left["kind"], left["target"]) == (right["kind"], right["target"])
            setup = _setup_similarity(left, right)
            frequency = max(
                left_counts[(str(left["kind"]), str(left["target"]))],
                right_counts[(str(right["kind"]), str(right["target"]))],
            )
            if exact and (frequency == 1 or setup >= 0.75):
                confidence = "high"
            elif exact:
                confidence = "medium"
            elif left["kind"] == right["kind"] and setup >= 0.5:
                confidence = "medium"
            else:
                confidence = "low"
            rows.append(
                {
                    "status": "equal" if exact else "replace",
                    "confidence": confidence,
                    "original_index": i - 1,
                    "rebuilt_index": j - 1,
                    "original": left,
                    "rebuilt": right,
                    "setup_similarity": setup,
                }
            )
            i -= 1
            j -= 1
        elif operation == "D" or j == 0:
            rows.append(
                {
                    "status": "delete",
                    "confidence": "low",
                    "original_index": i - 1,
                    "rebuilt_index": None,
                    "original": original[i - 1],
                    "rebuilt": None,
                }
            )
            i -= 1
        else:
            rows.append(
                {
                    "status": "insert",
                    "confidence": "low",
                    "original_index": None,
                    "rebuilt_index": j - 1,
                    "original": None,
                    "rebuilt": rebuilt[j - 1],
                }
            )
            j -= 1
    rows.reverse()
    for index, row in enumerate(rows):
        if row["status"] not in {"delete", "insert"}:
            continue
        call = row.get("original") or row.get("rebuilt") or {}
        key = (str(call.get("kind")), str(call.get("target")))
        frequency = left_counts[key] if row["status"] == "delete" else right_counts[key]
        anchors = sum(
            1
            for neighbor in (index - 1, index + 1)
            if 0 <= neighbor < len(rows) and rows[neighbor]["status"] == "equal"
        )
        if frequency == 1 and anchors == 2:
            row["confidence"] = "high"
        elif frequency <= 2 and anchors >= 1:
            row["confidence"] = "medium"
    exact_count = sum(row["status"] == "equal" for row in rows)
    prefix = 0
    for row in rows:
        if row["status"] != "equal":
            break
        prefix += 1
    first_difference = next((index for index, row in enumerate(rows) if row["status"] != "equal"), None)
    return {
        "rows": rows,
        "exact_calls": exact_count,
        "similarity_percent": exact_count * 100.0 / max(n, m, 1),
        "aligned_prefix_calls": prefix,
        "first_difference_row": first_difference,
    }


def block_alignment(original: list[dict[str, object]], rebuilt: list[dict[str, object]]) -> dict[str, object]:
    """Align basic blocks using normalized instructions, calls, and terminators."""
    n, m = len(original), len(rebuilt)
    gap = -9.0
    scores = [[0.0] * (m + 1) for _ in range(n + 1)]
    trace = [[""] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        scores[i][0] = i * gap
        trace[i][0] = "D"
    for j in range(1, m + 1):
        scores[0][j] = j * gap
        trace[0][j] = "I"

    def pair_score(left: dict[str, object], right: dict[str, object]) -> float:
        if left["signature"] == right["signature"]:
            return 30.0 + min(int(left["instruction_count"]), 20) / 2.0
        ratio = difflib.SequenceMatcher(
            a=list(left["shapes"]), b=list(right["shapes"]), autojunk=False
        ).ratio()
        calls = 6.0 if left["calls"] and left["calls"] == right["calls"] else 0.0
        terminator = 2.0 if left["terminator"] == right["terminator"] else 0.0
        successor_shape = 1.0 if len(left["successors"]) == len(right["successors"]) else 0.0
        return ratio * 14.0 + calls + terminator + successor_shape - 5.0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            diagonal = scores[i - 1][j - 1] + pair_score(original[i - 1], rebuilt[j - 1])
            delete = scores[i - 1][j] + gap
            insert = scores[i][j - 1] + gap
            best = max(diagonal, delete, insert)
            if diagonal == best and diagonal > delete and diagonal > insert:
                trace[i][j] = "M"
            elif delete == best:
                trace[i][j] = "D"
            else:
                trace[i][j] = "I"
            scores[i][j] = best

    rows: list[dict[str, object]] = []
    i, j = n, m
    while i or j:
        operation = trace[i][j]
        if operation == "M":
            left, right = original[i - 1], rebuilt[j - 1]
            exact = left["signature"] == right["signature"]
            ratio = difflib.SequenceMatcher(
                a=list(left["shapes"]), b=list(right["shapes"]), autojunk=False
            ).ratio()
            rows.append(
                {
                    "status": "equal" if exact else "fuzzy",
                    "confidence": "high" if exact else ("medium" if ratio >= 0.65 else "low"),
                    "original": left,
                    "rebuilt": right,
                    "shape_similarity": ratio,
                }
            )
            i -= 1
            j -= 1
        elif operation == "D" or j == 0:
            rows.append({"status": "delete", "confidence": "low", "original": original[i - 1], "rebuilt": None})
            i -= 1
        else:
            rows.append({"status": "insert", "confidence": "low", "original": None, "rebuilt": rebuilt[j - 1]})
            j -= 1
    rows.reverse()

    exact_instructions = sum(
        int(row["original"]["instruction_count"])
        for row in rows
        if row["status"] == "equal" and row["original"] is not None
    )
    islands: list[dict[str, object]] = []
    current: list[dict[str, object]] = []
    for row in rows + [{"status": "end"}]:
        if row["status"] == "equal":
            current.append(row)
            continue
        if current:
            islands.append(
                {
                    "blocks": len(current),
                    "instructions": sum(int(item["original"]["instruction_count"]) for item in current),
                    "original_start": current[0]["original"]["offset"],
                    "original_end": current[-1]["original"]["end_offset"],
                    "rebuilt_start": current[0]["rebuilt"]["offset"],
                    "rebuilt_end": current[-1]["rebuilt"]["end_offset"],
                }
            )
            current = []
    islands.sort(key=lambda row: (-int(row["instructions"]), int(row["original_start"])))
    deleted = [row["original"] for row in rows if row["status"] == "delete" and row.get("original")]
    inserted = [row["rebuilt"] for row in rows if row["status"] == "insert" and row.get("rebuilt")]
    inserted_by_signature: dict[str, list[dict[str, object]]] = {}
    for block in inserted:
        inserted_by_signature.setdefault(str(block["signature"]), []).append(block)
    relocated_pairs: list[dict[str, object]] = []
    consumed_rebuilt: set[int] = set()
    # Exact signatures are safe, order-insensitive evidence. Restrict to unique
    # candidates so repeated tiny epilogues do not manufacture correspondences.
    deleted_counts = Counter(str(block["signature"]) for block in deleted)
    for left in deleted:
        signature = str(left["signature"])
        candidates = inserted_by_signature.get(signature, [])
        if deleted_counts[signature] != 1 or len(candidates) != 1:
            continue
        right = candidates[0]
        consumed_rebuilt.add(int(right["index"]))
        relocated_pairs.append(
            {
                "confidence": "high",
                "exact": True,
                "instruction_count": int(left["instruction_count"]),
                "original": left,
                "rebuilt": right,
                "offset_delta": int(right["offset"]) - int(left["offset"]),
            }
        )
    # Calls provide a useful conservative fallback for larger non-exact cold
    # blocks. Require a distinctive non-empty call sequence and strong shape.
    for left in deleted:
        if any(pair["original"] is left for pair in relocated_pairs) or not left.get("calls"):
            continue
        candidates: list[tuple[float, dict[str, object]]] = []
        for right in inserted:
            if int(right["index"]) in consumed_rebuilt or left.get("calls") != right.get("calls"):
                continue
            ratio = difflib.SequenceMatcher(
                a=list(left["shapes"]), b=list(right["shapes"]), autojunk=False
            ).ratio()
            if ratio >= 0.78:
                candidates.append((ratio, right))
        candidates.sort(key=lambda item: -item[0])
        if len(candidates) != 1:
            continue
        ratio, right = candidates[0]
        consumed_rebuilt.add(int(right["index"]))
        relocated_pairs.append(
            {
                "confidence": "medium",
                "exact": False,
                "shape_similarity": ratio,
                "instruction_count": int(left["instruction_count"]),
                "original": left,
                "rebuilt": right,
                "offset_delta": int(right["offset"]) - int(left["offset"]),
            }
        )
    relocated_pairs.sort(key=lambda row: (-int(row["instruction_count"]), int(row["original"]["offset"])))
    first_difference = next((index for index, row in enumerate(rows) if row["status"] != "equal"), None)
    return {
        "rows": rows,
        "exact_instructions": exact_instructions,
        "matched_coverage_percent": exact_instructions * 100.0 / max(
            sum(int(row["instruction_count"]) for row in original), 1
        ),
        "first_difference_row": first_difference,
        "strong_islands": islands[:8],
        "relocated_pairs": relocated_pairs[:32],
    }


def call_target_counts(calls: list[dict[str, object]]) -> list[dict[str, object]]:
    """Return stable per-kind/target counts for reports and run-to-run comparison."""
    counts = Counter((str(row["kind"]), str(row["target"])) for row in calls)
    return [
        {"kind": kind, "target": target, "count": count}
        for (kind, target), count in sorted(counts.items())
    ]


def call_count_deltas(
    original_counts: list[dict[str, object]],
    rebuilt_counts: list[dict[str, object]],
) -> list[dict[str, object]]:
    """Compare call multisets without claiming that their sequence is aligned."""
    original = {
        (str(row["kind"]), str(row["target"])): int(row["count"])
        for row in original_counts
    }
    rebuilt = {
        (str(row["kind"]), str(row["target"])): int(row["count"])
        for row in rebuilt_counts
    }
    rows: list[dict[str, object]] = []
    for kind, target in sorted(set(original) | set(rebuilt)):
        left = original.get((kind, target), 0)
        right = rebuilt.get((kind, target), 0)
        if left == right:
            continue
        rows.append(
            {
                "kind": kind,
                "target": target,
                "original": left,
                "rebuilt": right,
                "delta": right - left,
            }
        )
    rows.sort(
        key=lambda row: (
            -abs(int(row["delta"])),
            0 if int(row["original"]) == 0 or int(row["rebuilt"]) == 0 else 1,
            str(row["kind"]),
            str(row["target"]),
        )
    )
    return rows


def instruction_shape(instruction: DecodedInstruction) -> str:
    if instruction.flow_control in (FlowControl.CONDITIONAL_BRANCH, FlowControl.UNCONDITIONAL_BRANCH):
        direction = "back" if instruction.target < instruction.address else "forward"
        return f"{instruction.mnemonic} <{direction}-branch>"
    if instruction.flow_control == FlowControl.CALL:
        return "call <direct>"
    if instruction.flow_control == FlowControl.INDIRECT_CALL:
        slot = _VIRTUAL_SLOT_RE.search(instruction.text)
        return f"call <vslot:{slot.group(1).lower()}>" if slot else "call <indirect>"
    text = instruction.text.lower()
    if instruction.relocation_symbol and instruction.relocation_symbol != "__except_list":
        text = re.sub(r"(?<![0-9a-f])0(?![0-9a-f])", "<address>", text)
    # Executable addresses and object relocations are the same structural
    # operand even though one is resolved and the other is zero-filled.
    text = re.sub(r"(?<![+\-])\b[0-9a-f]{5,}h\b", "<address>", text)
    return _REGISTER_RE.sub("reg", text)


def instruction_alignment(
    original: list[DecodedInstruction], rebuilt: list[DecodedInstruction]
) -> dict[str, object]:
    left = [instruction_shape(item) for item in original]
    right = [instruction_shape(item) for item in rebuilt]
    matcher = difflib.SequenceMatcher(a=left, b=right, autojunk=False)
    opcodes = matcher.get_opcodes()
    equal = sum(i2 - i1 for tag, i1, i2, _, _ in opcodes if tag == "equal")
    denominator = max(len(left), len(right), 1)
    first_change = next((opcode for opcode in opcodes if opcode[0] != "equal"), None)
    longest_equal = max((i2 - i1 for tag, i1, i2, _, _ in opcodes if tag == "equal"), default=0)
    return {
        "original_instructions": len(left),
        "rebuilt_instructions": len(right),
        "equal_instructions": equal,
        "similarity_percent": equal * 100.0 / denominator,
        "longest_equal_run": longest_equal,
        "opcodes": opcodes,
        "first_change": first_change,
    }


def pdb_line_for_address(function_va: int, address: int) -> int | None:
    records = _pdb_line_changes().get(f"{function_va:08X}", [])
    line: int | None = None
    for record in records:
        record_address = int(record["address"], 16)
        if record_address > address:
            break
        line_text = record.get("line_number") or record.get("line")
        if line_text:
            line = int(line_text, 10)
    return line


def paired_instruction_context(
    original: list[DecodedInstruction],
    rebuilt: list[DecodedInstruction],
    alignment: dict[str, object],
    function_va: int,
    radius: int = 4,
    rebuilt_line_for_offset: Callable[[int], int | None] | None = None,
) -> list[str]:
    first = alignment.get("first_change")
    if not first:
        return []
    _, i1, i2, j1, j2 = first
    left_start = max(0, i1 - radius)
    right_start = max(0, j1 - radius)
    rows = max((i2 - left_start), (j2 - right_start), radius * 2 + 1)
    rows = min(rows, 14)
    lines: list[str] = []
    for row in range(rows):
        left_index = left_start + row
        right_index = right_start + row
        left_item = original[left_index] if left_index < len(original) else None
        right_item = rebuilt[right_index] if right_index < len(rebuilt) else None
        left_text = ""
        right_text = ""
        if left_item is not None:
            line = pdb_line_for_address(function_va, left_item.address)
            line_text = "" if line is None else f" L{line}"
            left_text = f"+{left_item.offset:04X}{line_text} {left_item.text}"
        if right_item is not None:
            rebuilt_line = None if rebuilt_line_for_offset is None else rebuilt_line_for_offset(right_item.offset)
            line_text = "" if rebuilt_line is None else f" L{rebuilt_line}"
            right_text = f"+{right_item.offset:04X}{line_text} {right_item.text}"
        marker = " " if left_item and right_item and instruction_shape(left_item) == instruction_shape(right_item) else "!"
        lines.append(f" {marker} {left_text:<49} | {right_text}")
    return lines


def prologue_summary(instructions: list[DecodedInstruction]) -> dict[str, object]:
    frame_size: int | None = None
    saved: list[str] = []
    for instruction in instructions[:16]:
        text = instruction.text.lower()
        match = re.fullmatch(r"sub esp,([0-9a-f]+)h?", text)
        if match and frame_size is None:
            frame_size = int(match.group(1), 16)
        push_match = re.fullmatch(r"push (ebx|ebp|esi|edi)", text)
        if push_match:
            saved.append(push_match.group(1))
        if instruction.flow_control in (
            FlowControl.CALL,
            FlowControl.INDIRECT_CALL,
            FlowControl.CONDITIONAL_BRANCH,
            FlowControl.UNCONDITIONAL_BRANCH,
            FlowControl.RETURN,
        ):
            break
    return {"frame_size": frame_size, "saved_registers": saved}


def control_flow_summary(instructions: list[DecodedInstruction]) -> dict[str, int]:
    return {
        "conditional_branches": sum(item.flow_control == FlowControl.CONDITIONAL_BRANCH for item in instructions),
        "unconditional_branches": sum(item.flow_control == FlowControl.UNCONDITIONAL_BRANCH for item in instructions),
        "direct_calls": sum(item.flow_control == FlowControl.CALL for item in instructions),
        "indirect_calls": sum(item.flow_control == FlowControl.INDIRECT_CALL for item in instructions),
        "returns": sum(item.flow_control == FlowControl.RETURN for item in instructions),
    }


def compatible_relocation_masks(
    original_bytes: bytes,
    rebuilt_bytes: bytes,
    rebuilt_relocations: list[dict],
    start_va: int,
    original_ranges: Iterable[dict[str, object]] | None = None,
) -> tuple[bytes, bytes, dict[str, object]]:
    """Mask only relocations whose containing instruction still aligns.

    Applying rebuilt relocation offsets indiscriminately to a structurally
    different original creates artificial equal bytes. Known direct-call target
    mismatches are deliberately left unmasked and therefore fail exactness.
    """
    original_instructions = (
        decode_instruction_ranges(original_bytes, original_ranges)
        if original_ranges is not None
        else decode_instructions(original_bytes, start_va)
    )
    rebuilt_instructions = decode_instructions(rebuilt_bytes, start_va, rebuilt_relocations)
    original_by_offset = {item.offset: item for item in original_instructions}
    names = _function_names_by_va()
    masked_original = bytearray(original_bytes)
    masked_rebuilt = bytearray(rebuilt_bytes)
    compatible = 0
    incompatible = 0
    target_mismatches: list[dict[str, object]] = []

    for relocation in rebuilt_relocations:
        offset = int(relocation["offset"])
        width = int(relocation["width"])
        rebuilt_instruction = next((item for item in rebuilt_instructions if item.offset <= offset < item.end), None)
        if rebuilt_instruction is None:
            incompatible += 1
            continue
        original_instruction = original_by_offset.get(rebuilt_instruction.offset)
        if (
            original_instruction is None
            or original_instruction.mnemonic != rebuilt_instruction.mnemonic
            or len(original_instruction.data) != len(rebuilt_instruction.data)
            or offset + width > original_instruction.end
            or offset + width > rebuilt_instruction.end
        ):
            incompatible += 1
            continue

        if rebuilt_instruction.flow_control == FlowControl.CALL:
            original_target = original_call_target(original_instruction, names)
            rebuilt_target = str(relocation.get("symbol_name") or "")
            rebuilt_clean = clean_symbol_name(rebuilt_target)
            if (
                original_target
                and not original_target.startswith(tuple("0123456789"))
                and rebuilt_clean
                and not direct_call_symbols_match(original_target, rebuilt_target)
            ):
                target_mismatches.append(
                    {
                        "offset": rebuilt_instruction.offset,
                        "original": original_target,
                        "rebuilt": rebuilt_target,
                    }
                )
                incompatible += 1
                continue

        for index in range(offset, min(offset + width, len(masked_original), len(masked_rebuilt))):
            masked_original[index] = 0
            masked_rebuilt[index] = 0
        compatible += 1

    return bytes(masked_original), bytes(masked_rebuilt), {
        "compatible": compatible,
        "incompatible": incompatible,
        "target_mismatches": target_mismatches,
    }


def iteration_delta(original: bytes, previous: bytes, current: bytes) -> dict[str, object]:
    size = max(len(previous), len(current))
    changed = improved = regressed = neutral = spans = 0
    in_span = False
    range_start = 0
    ranges: list[dict[str, int]] = []
    range_improved = range_regressed = range_neutral = 0
    for offset in range(size):
        old = previous[offset] if offset < len(previous) else None
        new = current[offset] if offset < len(current) else None
        target = original[offset] if offset < len(original) else None
        if old == new:
            if in_span:
                ranges.append(
                    {
                        "start": range_start,
                        "end": offset,
                        "changed": offset - range_start,
                        "improved": range_improved,
                        "regressed": range_regressed,
                        "neutral": range_neutral,
                    }
                )
            in_span = False
            continue
        changed += 1
        if not in_span:
            spans += 1
            in_span = True
            range_start = offset
            range_improved = range_regressed = range_neutral = 0
        old_match = old == target
        new_match = new == target
        if new_match and not old_match:
            improved += 1
            range_improved += 1
        elif old_match and not new_match:
            regressed += 1
            range_regressed += 1
        else:
            neutral += 1
            range_neutral += 1
    if in_span:
        ranges.append(
            {
                "start": range_start,
                "end": size,
                "changed": size - range_start,
                "improved": range_improved,
                "regressed": range_regressed,
                "neutral": range_neutral,
            }
        )
    return {
        "changed_bytes": changed,
        "changed_spans": spans,
        "strict_improvements": improved,
        "strict_regressions": regressed,
        "neutral_changes": neutral,
        "size_delta": len(current) - len(previous),
        "ranges": ranges,
    }
