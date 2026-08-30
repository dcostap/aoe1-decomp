from __future__ import annotations

import re
from collections import Counter

from function_diagnostics import DecodedInstruction, instruction_shape

_GENERAL_REGISTER_RE = re.compile(
    r"\b(?:eax|ebx|ecx|edx|esi|edi|ebp|esp|ax|bx|cx|dx|si|di|bp|sp|ah|al|bh|bl|ch|cl|dh|dl)\b",
    re.IGNORECASE,
)
_REGISTER_WIDTHS = {
    **{register: 32 for register in ("eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp")},
    **{register: 16 for register in ("ax", "bx", "cx", "dx", "si", "di", "bp", "sp")},
    **{register: 8 for register in ("ah", "al", "bh", "bl", "ch", "cl", "dh", "dl")},
}
_REGISTER_FAMILIES = {
    "eax": "a", "ax": "a", "ah": "a", "al": "a",
    "ebx": "b", "bx": "b", "bh": "b", "bl": "b",
    "ecx": "c", "cx": "c", "ch": "c", "cl": "c",
    "edx": "d", "dx": "d", "dh": "d", "dl": "d",
    "esi": "si", "si": "si", "edi": "di", "di": "di",
    "ebp": "bp", "bp": "bp", "esp": "sp", "sp": "sp",
}
_REGISTER_FAMILY_DWORD = {
    "a": "eax", "b": "ebx", "c": "ecx", "d": "edx",
    "si": "esi", "di": "edi", "bp": "ebp", "sp": "esp",
}
_COMPARE_JUMP_REVERSALS = {
    ("ja", "jb"), ("jae", "jbe"), ("jb", "ja"), ("jbe", "jae"),
    ("jg", "jl"), ("jge", "jle"), ("jl", "jg"), ("jle", "jge"),
    ("je", "je"), ("jne", "jne"),
}
_PRIMARY_PRIORITY = (
    "FUNCTION_SYMBOL_DIFFERENCE",
    "CONTROL_TRANSFER_TARGET_DIFFERENCE",
    "CALL_SURFACE_DIFFERENCE",
    "TEST_OPERAND_WITH_BRANCH_CHANGE",
    "COMPARE_OPERAND_OR_BRANCH_FORM",
    "TEST_OPERAND_ORDER",
    "CONSISTENT_REGISTER_RECOLOR",
    "REGISTER_MAP_CONFLICT",
    "X87_OPERATION_ORDER",
    "WIDTH_OR_SIGNEDNESS",
    "CONTROL_FLOW_DIFFERENCE",
    "COPY_OR_FILL_LOWERING",
    "ADDRESS_OR_ARITHMETIC_LOWERING",
    "INSTRUCTION_SCHEDULING_OR_BLOCK_ORDER",
    "STRUCTURAL_INSTRUCTION_DIFFERENCE",
    "INSTRUCTION_SELECTION_OR_EXPRESSION_SHAPE",
    "PARTIAL_REGISTER_RECOLOR",
    "INSTRUCTION_ENCODING",
)


def _instruction_parts(text: str) -> tuple[str, list[str]]:
    mnemonic, separator, operand_text = text.lower().strip().partition(" ")
    return mnemonic, [] if not separator else [operand.strip() for operand in operand_text.split(",")]


def _general_registers(text: str) -> list[str]:
    return [match.group(0).lower() for match in _GENERAL_REGISTER_RE.finditer(text)]


def _register_skeleton(text: str) -> str:
    return _GENERAL_REGISTER_RE.sub(
        lambda match: f"<r{_REGISTER_WIDTHS[match.group(0).lower()]}>",
        text.lower(),
    )


def _register_map(
    pairs: list[tuple[DecodedInstruction, DecodedInstruction]],
) -> tuple[dict[str, str], list[str]]:
    forward: dict[str, str] = {}
    reverse: dict[str, str] = {}
    conflicts: list[str] = []
    for original, rebuilt in pairs:
        left_registers = _general_registers(original.text)
        right_registers = _general_registers(rebuilt.text)
        if len(left_registers) != len(right_registers):
            conflicts.append(f"+{original.offset:04X}: register operand counts differ")
            continue
        for left, right in zip(left_registers, right_registers):
            if _REGISTER_WIDTHS[left] != _REGISTER_WIDTHS[right]:
                conflicts.append(f"+{original.offset:04X}: {left} and {right} have different widths")
                continue
            left_family = _REGISTER_FAMILIES[left]
            right_family = _REGISTER_FAMILIES[right]
            if "sp" in {left_family, right_family} and left_family != right_family:
                conflicts.append(f"+{original.offset:04X}: stack-pointer family maps to a general register")
                continue
            previous_right = forward.get(left_family)
            previous_left = reverse.get(right_family)
            if previous_right not in {None, right_family}:
                conflicts.append(
                    f"+{original.offset:04X}: {_REGISTER_FAMILY_DWORD[left_family]} maps to both "
                    f"{_REGISTER_FAMILY_DWORD[previous_right]} and {_REGISTER_FAMILY_DWORD[right_family]}"
                )
                continue
            if previous_left not in {None, left_family}:
                conflicts.append(
                    f"+{original.offset:04X}: {_REGISTER_FAMILY_DWORD[right_family]} receives both "
                    f"{_REGISTER_FAMILY_DWORD[previous_left]} and {_REGISTER_FAMILY_DWORD[left_family]}"
                )
                continue
            forward[left_family] = right_family
            reverse[right_family] = left_family
    display = {
        _REGISTER_FAMILY_DWORD[left].upper(): _REGISTER_FAMILY_DWORD[right].upper()
        for left, right in sorted(forward.items())
        if left != right
    }
    return display, list(dict.fromkeys(conflicts))


def _operand_swap_events(
    original: list[DecodedInstruction], rebuilt: list[DecodedInstruction]
) -> tuple[list[dict[str, object]], list[dict[str, object]]]:
    compare_events: list[dict[str, object]] = []
    test_events: list[dict[str, object]] = []
    for index in range(min(len(original), len(rebuilt)) - 1):
        left_mnemonic, left_operands = _instruction_parts(original[index].text)
        right_mnemonic, right_operands = _instruction_parts(rebuilt[index].text)
        if left_mnemonic != right_mnemonic or left_mnemonic not in {"cmp", "test"}:
            continue
        if (
            len(left_operands) != 2
            or left_operands == right_operands
            or right_operands != list(reversed(left_operands))
        ):
            continue
        left_jump = original[index + 1].mnemonic
        right_jump = rebuilt[index + 1].mnemonic
        row = {
            "offset": original[index].offset,
            "original": original[index].text,
            "rebuilt": rebuilt[index].text,
            "original_jump": left_jump,
            "rebuilt_jump": right_jump,
        }
        if left_mnemonic == "cmp":
            row["compatible_jump_reversal"] = (left_jump, right_jump) in _COMPARE_JUMP_REVERSALS
            compare_events.append(row)
        else:
            row["branch_changed"] = left_jump != right_jump
            test_events.append(row)
    return compare_events, test_events


def _x87_swap_events(
    original: list[DecodedInstruction], rebuilt: list[DecodedInstruction]
) -> list[dict[str, object]]:
    events: list[dict[str, object]] = []
    for index in range(min(len(original), len(rebuilt)) - 1):
        left_a, left_a_ops = _instruction_parts(original[index].text)
        left_b, left_b_ops = _instruction_parts(original[index + 1].text)
        right_a, right_a_ops = _instruction_parts(rebuilt[index].text)
        right_b, right_b_ops = _instruction_parts(rebuilt[index + 1].text)
        if (
            left_a == right_a == "fld"
            and left_b == right_b
            and left_b in {"fadd", "fmul"}
            and len(left_a_ops) == len(left_b_ops) == len(right_a_ops) == len(right_b_ops) == 1
            and left_a_ops[0] == right_b_ops[0]
            and left_b_ops[0] == right_a_ops[0]
        ):
            events.append(
                {
                    "offset": original[index].offset,
                    "operation": left_b,
                    "original": [original[index].text, original[index + 1].text],
                    "rebuilt": [rebuilt[index].text, rebuilt[index + 1].text],
                }
            )
    return events


def classify_mismatch(
    original: list[DecodedInstruction],
    rebuilt: list[DecodedInstruction],
    masked_original: bytes,
    masked_rebuilt: bytes,
    *,
    shape: dict[str, object],
    call_map: dict[str, object],
    call_target_deltas: list[dict[str, object]],
    target_mismatches: list[dict[str, object]],
    cfg_issues: list[dict[str, object]],
    owner_symbol_mismatch: dict[str, object] | None = None,
) -> dict[str, object]:
    """Describe mismatch patterns without asserting equivalence or changing status."""
    strict_offsets = {
        offset
        for offset in range(max(len(masked_original), len(masked_rebuilt)))
        if (masked_original[offset] if offset < len(masked_original) else None)
        != (masked_rebuilt[offset] if offset < len(masked_rebuilt) else None)
    }
    if not strict_offsets and not target_mismatches and not owner_symbol_mismatch:
        return {
            "audit_only": True,
            "establishes_equivalence": False,
            "primary": "EXACT",
            "confidence": "high",
            "labels": [],
            "strict_changed_bytes": 0,
            "register_map": {},
            "register_map_conflicts": [],
        }

    labels: list[dict[str, object]] = []

    def add(
        label_id: str,
        confidence: str,
        evidence: list[str],
        offsets: list[int] | None = None,
    ) -> None:
        if any(row["id"] == label_id for row in labels):
            return
        row: dict[str, object] = {"id": label_id, "confidence": confidence, "evidence": evidence}
        if offsets:
            row["offsets"] = sorted(set(offsets))
        labels.append(row)

    if owner_symbol_mismatch:
        add(
            "FUNCTION_SYMBOL_DIFFERENCE",
            "high",
            [
                f"target name {owner_symbol_mismatch.get('expected')}",
                f"rebuilt owner {owner_symbol_mismatch.get('rebuilt')}",
            ],
        )

    jump_target_mismatches = [
        row for row in target_mismatches if row.get("kind") == "tail-jump"
    ]
    call_target_mismatches = [
        row for row in target_mismatches if row.get("kind") != "tail-jump"
    ]
    if jump_target_mismatches:
        add(
            "CONTROL_TRANSFER_TARGET_DIFFERENCE",
            "high",
            [f"{len(jump_target_mismatches)} direct tail-jump symbol mismatch(es)"],
            [int(row["offset"]) for row in jump_target_mismatches],
        )

    changed_call_rows = [row for row in call_map.get("rows") or [] if row.get("status") != "equal"]
    if call_target_mismatches or call_target_deltas or changed_call_rows:
        evidence = []
        if call_target_mismatches:
            evidence.append(f"{len(call_target_mismatches)} known direct-call symbol mismatch(es)")
        if call_target_deltas:
            evidence.append(f"{len(call_target_deltas)} aggregate call-target count difference(s)")
        if changed_call_rows:
            evidence.append(f"{len(changed_call_rows)} ordered call-site alignment difference(s)")
        add("CALL_SURFACE_DIFFERENCE", "high", evidence)

    compare_events, test_events = _operand_swap_events(original, rebuilt)
    if compare_events:
        compatible = sum(bool(row["compatible_jump_reversal"]) for row in compare_events)
        add(
            "COMPARE_OPERAND_OR_BRANCH_FORM",
            "medium",
            [
                f"{len(compare_events)} CMP operand-swap pattern(s)",
                f"{compatible} use the expected reversed branch mnemonic",
            ],
            [int(row["offset"]) for row in compare_events],
        )
    changed_test_events = [row for row in test_events if row["branch_changed"]]
    stable_test_events = [row for row in test_events if not row["branch_changed"]]
    if changed_test_events:
        add(
            "TEST_OPERAND_WITH_BRANCH_CHANGE",
            "high",
            [
                f"{len(changed_test_events)} TEST operand swap(s) also change the branch",
                "TEST operand order preserves flags; a changed branch is a separate control-flow difference",
            ],
            [int(row["offset"]) for row in changed_test_events],
        )
    if stable_test_events:
        add(
            "TEST_OPERAND_ORDER",
            "medium",
            [f"{len(stable_test_events)} TEST operand swap(s) keep the branch mnemonic"],
            [int(row["offset"]) for row in stable_test_events],
        )

    register_pairs: list[tuple[DecodedInstruction, DecodedInstruction]] = []
    encoding_offsets: list[int] = []
    uncovered_offsets = set(strict_offsets)
    if len(original) == len(rebuilt):
        for left, right in zip(original, rebuilt):
            if left.offset != right.offset or len(left.data) != len(right.data):
                continue
            changed_here = set(range(left.offset, left.end)) & strict_offsets
            if not changed_here:
                continue
            if left.text.lower() == right.text.lower():
                encoding_offsets.append(left.offset)
                uncovered_offsets.difference_update(changed_here)
            elif (
                _register_skeleton(left.text) == _register_skeleton(right.text)
                and _general_registers(left.text)
                and _general_registers(right.text)
            ):
                register_pairs.append((left, right))
                uncovered_offsets.difference_update(changed_here)

    register_map, register_conflicts = _register_map(register_pairs)
    register_only = bool(register_pairs and register_map and not register_conflicts and not uncovered_offsets)
    if register_only:
        add(
            "CONSISTENT_REGISTER_RECOLOR",
            "high",
            [
                f"all {len(strict_offsets)} strict changed byte(s) stay within aligned register/encoding forms",
                f"changed-region register map: {', '.join(f'{left}->{right}' for left, right in register_map.items())}",
            ],
            [left.offset for left, _ in register_pairs],
        )
    elif register_conflicts:
        add("REGISTER_MAP_CONFLICT", "high", register_conflicts, [left.offset for left, _ in register_pairs])
    elif register_pairs:
        add(
            "PARTIAL_REGISTER_RECOLOR",
            "medium",
            [
                f"{len(register_pairs)} aligned instruction(s) differ only by general registers",
                f"{len(uncovered_offsets)} strict changed byte(s) require another explanation",
            ],
            [left.offset for left, _ in register_pairs],
        )
    if encoding_offsets:
        add(
            "INSTRUCTION_ENCODING",
            "medium",
            [f"{len(encoding_offsets)} aligned instruction(s) have identical formatted text but different bytes"],
            encoding_offsets,
        )

    x87_events = _x87_swap_events(original, rebuilt)
    if x87_events:
        add(
            "X87_OPERATION_ORDER",
            "medium",
            [f"{len(x87_events)} FLD/FADD-or-FMUL operand-order pattern(s)"],
            [int(row["offset"]) for row in x87_events],
        )

    original_mnemonics = Counter(item.mnemonic for item in original)
    rebuilt_mnemonics = Counter(item.mnemonic for item in rebuilt)
    mnemonic_delta = original_mnemonics != rebuilt_mnemonics
    width_mnemonics = {"movsx", "movzx", "cbw", "cwde", "cwd", "cdq"}
    if any(original_mnemonics[name] != rebuilt_mnemonics[name] for name in width_mnemonics):
        add("WIDTH_OR_SIGNEDNESS", "medium", ["MOVSX/MOVZX or sign-extension instruction counts differ"])

    original_text = "\n".join(item.text.lower() for item in original)
    rebuilt_text = "\n".join(item.text.lower() for item in rebuilt)
    if any(token in original_text or token in rebuilt_text for token in ("rep movs", "rep stos")) and mnemonic_delta:
        add("COPY_OR_FILL_LOWERING", "medium", ["REP copy/fill instructions occur with a changed mnemonic multiset"])

    address_mnemonics = {"lea", "add", "sub", "imul", "shl", "shr", "sar"}
    if any(original_mnemonics[name] != rebuilt_mnemonics[name] for name in address_mnemonics):
        add(
            "ADDRESS_OR_ARITHMETIC_LOWERING",
            "medium",
            ["LEA/add/subtract/multiply/shift instruction counts differ"],
        )

    original_shapes = [instruction_shape(item) for item in original]
    rebuilt_shapes = [instruction_shape(item) for item in rebuilt]
    if (
        len(original_shapes) == len(rebuilt_shapes)
        and original_shapes != rebuilt_shapes
        and Counter(original_shapes) == Counter(rebuilt_shapes)
    ):
        add(
            "INSTRUCTION_SCHEDULING_OR_BLOCK_ORDER",
            "medium",
            ["instruction-shape multisets match, but their sequence differs"],
        )

    if cfg_issues:
        add("CONTROL_FLOW_DIFFERENCE", "high", [f"{len(cfg_issues)} attributed CFG edge or terminator difference(s)"])
    if len(original) != len(rebuilt):
        add(
            "STRUCTURAL_INSTRUCTION_DIFFERENCE",
            "high",
            [f"instruction counts differ: original {len(original)}, rebuilt {len(rebuilt)}"],
        )
    elif mnemonic_delta:
        changed_mnemonics = sorted(
            name
            for name in set(original_mnemonics) | set(rebuilt_mnemonics)
            if original_mnemonics[name] != rebuilt_mnemonics[name]
        )
        add(
            "INSTRUCTION_SELECTION_OR_EXPRESSION_SHAPE",
            "medium",
            [f"changed mnemonic counts: {', '.join(changed_mnemonics)}"],
        )

    by_id = {str(row["id"]): row for row in labels}
    primary_row = next((by_id[label_id] for label_id in _PRIMARY_PRIORITY if label_id in by_id), None)
    if primary_row is None:
        primary_row = {
            "id": "INCONCLUSIVE",
            "confidence": "low",
            "evidence": ["the changed instructions do not fit a supported diagnostic pattern"],
        }
        labels.append(primary_row)
    return {
        "audit_only": True,
        "establishes_equivalence": False,
        "primary": primary_row["id"],
        "confidence": primary_row["confidence"],
        "labels": labels,
        "strict_changed_bytes": len(strict_offsets),
        "register_map": register_map,
        "register_map_conflicts": register_conflicts,
        "uncovered_strict_byte_count": len(uncovered_offsets),
        "compare_events": compare_events,
        "test_events": test_events,
        "x87_events": x87_events,
        "instruction_shape_percent": float(shape["similarity_percent"]),
    }
