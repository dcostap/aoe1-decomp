from __future__ import annotations

import difflib
import re
from dataclasses import dataclass
from functools import lru_cache
from typing import Iterable

from iced_x86 import Decoder, DecoderOptions, FlowControl, Formatter, FormatterSyntax

from common import load_functions, load_pdb_function_line_changes


_REGISTER_RE = re.compile(
    r"\b(?:e?[abcd]x|e?[sd]i|e?[sb]p|[abcd][lh]|[cdefgs]s|st[0-7]|xmm\d+)\b",
    re.IGNORECASE,
)
_VIRTUAL_SLOT_RE = re.compile(r"call\s+dword\s+\[[^\]]*?\+([0-9a-f]+)h\]", re.IGNORECASE)


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


def clean_symbol_name(name: str) -> str:
    value = name.strip()
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


@lru_cache(maxsize=1)
def _function_names_by_va() -> dict[int, str]:
    return {int(record["va"], 16): record["name"] for record in load_functions()}


@lru_cache(maxsize=1)
def _pdb_line_changes() -> dict[str, list[dict[str, str]]]:
    return load_pdb_function_line_changes()


def original_call_target(instruction: DecodedInstruction, names_by_va: dict[int, str]) -> str:
    if instruction.flow_control != FlowControl.CALL:
        return ""
    return names_by_va.get(instruction.target, f"{instruction.target:08X}")


def call_fingerprint(
    instructions: list[DecodedInstruction],
    original: bool,
    names_by_va: dict[int, str] | None = None,
) -> list[dict[str, object]]:
    names = names_by_va or _function_names_by_va()
    calls: list[dict[str, object]] = []
    for instruction in instructions:
        if instruction.flow_control == FlowControl.CALL:
            target = original_call_target(instruction, names) if original else instruction.relocation_symbol
            calls.append(
                {
                    "offset": instruction.offset,
                    "kind": "direct",
                    "target": clean_symbol_name(target) if target else "unresolved",
                    "display": clean_symbol_name(target) if target else "unresolved",
                }
            )
        elif instruction.flow_control == FlowControl.INDIRECT_CALL:
            slot_match = _VIRTUAL_SLOT_RE.search(instruction.text)
            if slot_match:
                slot = int(slot_match.group(1), 16)
                target = f"vslot+0x{slot:X}"
                kind = "virtual"
            else:
                target = "indirect"
                kind = "indirect"
            calls.append({"offset": instruction.offset, "kind": kind, "target": target, "display": target})
    return calls


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
            right_text = f"+{right_item.offset:04X} {right_item.text}"
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
) -> tuple[bytes, bytes, dict[str, object]]:
    """Mask only relocations whose containing instruction still aligns.

    Applying rebuilt relocation offsets indiscriminately to a structurally
    different original creates artificial equal bytes. Known direct-call target
    mismatches are deliberately left unmasked and therefore fail exactness.
    """
    original_instructions = decode_instructions(original_bytes, start_va)
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
            original_clean = clean_symbol_name(original_target)
            rebuilt_clean = clean_symbol_name(rebuilt_target)
            if original_target and not original_target.startswith(tuple("0123456789")) and rebuilt_clean and original_clean != rebuilt_clean:
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
