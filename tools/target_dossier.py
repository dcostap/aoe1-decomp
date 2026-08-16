from __future__ import annotations

import argparse
import csv
import json
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

from iced_x86 import FlowControl

from common import (
    REPO_ROOT,
    function_record_by_va,
    function_slug,
    load_binaries,
    load_functions,
    load_pe_image,
    load_pdb_function_line_changes,
    preferred_source_path,
    repo_path,
)
from function_diagnostics import basic_blocks, call_fingerprint, decode_instruction_ranges
from shared_abi_evidence import load_shared_global_evidence, shared_globals_by_address


MEMORY_RE = re.compile(r"\[([^\]]+)\]")
REGISTER_RE = re.compile(r"^(?:e(?:ax|bx|cx|dx|si|di|bp|sp))$", re.IGNORECASE)
QUALIFIED_DEFINITION_RE = re.compile(
    r"^[ \t]*(?:(?:[A-Za-z_][\w:<>&*~]*[ \t]+)+)?"
    r"([A-Za-z_]\w*)::(?:~?[A-Za-z_]\w*|operator\s*[^\s(]+)\s*"
    r"\([^;{}]*\)(?:\s*const)?\s*\{",
    re.MULTILINE,
)
HEX_TOKEN_RE = re.compile(r"^[0-9a-f]+h$", re.IGNORECASE)
DECIMAL_TOKEN_RE = re.compile(r"^[0-9]+$")

REGISTER_WIDTHS = {
    "al": 1,
    "ah": 1,
    "bl": 1,
    "bh": 1,
    "cl": 1,
    "ch": 1,
    "dl": 1,
    "dh": 1,
    "ax": 2,
    "bx": 2,
    "cx": 2,
    "dx": 2,
    "si": 2,
    "di": 2,
    "bp": 2,
    "sp": 2,
    "eax": 4,
    "ebx": 4,
    "ecx": 4,
    "edx": 4,
    "esi": 4,
    "edi": 4,
    "ebp": 4,
    "esp": 4,
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate a binary-evidence dossier for one matching target."
    )
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 005204A0.")
    parser.add_argument(
        "--class-name",
        help="Override the class inferred from the living source for size-conflict checks.",
    )
    parser.add_argument(
        "--refresh-original",
        action="store_true",
        help="Regenerate the cached original extraction before building the dossier.",
    )
    parser.add_argument(
        "--json-only",
        action="store_true",
        help="Write both artifacts but print only the JSON path.",
    )
    return parser.parse_args()


def _parse_number(token: str) -> int | None:
    value = token.strip().lower()
    if HEX_TOKEN_RE.fullmatch(value):
        return int(value[:-1], 16)
    if value.startswith("0x"):
        try:
            return int(value, 16)
        except ValueError:
            return None
    if DECIMAL_TOKEN_RE.fullmatch(value):
        return int(value, 10)
    return None


def parse_memory_expression(expression: str) -> dict[str, object]:
    """Return registers and the fixed displacement from a NASM memory expression.

    Scaled/index terms are retained as evidence but are not interpreted as a fixed
    object extent. This parser is deliberately conservative; it is not a symbolic
    execution engine.
    """
    normalized = expression.lower().replace(" ", "")
    terms = re.findall(r"[+-]?[^+-]+", normalized)
    registers: list[str] = []
    indexed_terms: list[str] = []
    displacement = 0
    for raw_term in terms:
        sign = -1 if raw_term.startswith("-") else 1
        term = raw_term.lstrip("+-")
        if REGISTER_RE.fullmatch(term):
            registers.append(term)
            continue
        if "*" in term:
            indexed_terms.append(("-" if sign < 0 else "") + term)
            register = term.split("*", 1)[0]
            if REGISTER_RE.fullmatch(register):
                registers.append(register)
            continue
        number = _parse_number(term)
        if number is not None:
            displacement += sign * number
        else:
            indexed_terms.append(("-" if sign < 0 else "") + term)
    return {
        "expression": expression,
        "registers": registers,
        "fixed_displacement": displacement,
        "indexed_terms": indexed_terms,
    }


def infer_memory_width(text: str) -> int | None:
    lowered = text.lower()
    for label, width in (("qword", 8), ("dword", 4), ("word", 2), ("byte", 1)):
        if re.search(rf"\b{label}\b", lowered):
            return width
    # Address registers describe the location, not the access width. Remove
    # memory expressions before using the remaining data register as a hint.
    without_addresses = MEMORY_RE.sub("[mem]", lowered)
    widths = [
        REGISTER_WIDTHS[token]
        for token in re.findall(r"\b[a-z][a-z0-9]*\b", without_addresses)
        if token in REGISTER_WIDTHS
    ]
    return max(widths) if widths else None


def infer_memory_access(text: str, memory_start: int) -> str:
    lowered = text.lower().strip()
    mnemonic = lowered.split(None, 1)[0] if lowered else ""
    if mnemonic == "lea":
        return "address"
    if mnemonic in {
        "cmp",
        "test",
        "push",
        "call",
        "fld",
        "fild",
        "fcomp",
        "fcom",
        "fcompp",
        "fadd",
        "fsub",
        "fsubr",
        "fmul",
        "fdiv",
        "fdivr",
    }:
        return "read"
    if mnemonic in {"fst", "fstp", "fist", "fistp", "seta", "setae", "setb", "setbe", "sete", "setne", "setg", "setge", "setl", "setle", "pop"}:
        return "write"
    first_comma = lowered.find(",")
    memory_is_first = first_comma < 0 or memory_start < first_comma
    if not memory_is_first:
        return "read"
    if mnemonic in {"add", "sub", "adc", "sbb", "and", "or", "xor", "inc", "dec", "neg", "not", "shl", "shr", "sar", "rol", "ror", "xadd", "xchg"}:
        return "read_write"
    return "write"


def _source_line_for_address(
    address: int, line_changes: list[dict[str, str]]
) -> dict[str, object] | None:
    best: dict[str, str] | None = None
    best_address = -1
    for row in line_changes:
        try:
            row_address = int(row.get("address", "0"), 16)
        except ValueError:
            continue
        if row_address <= address and row_address >= best_address:
            best = row
            best_address = row_address
    if best is None:
        return None
    return {
        "file": best.get("source_file", ""),
        "line": int(best.get("line_number") or 0),
        "line_address": f"{best_address:08X}",
    }


def _operand_parts(text: str) -> tuple[str, str]:
    body = text.split(None, 1)[1].strip() if " " in text else ""
    if "," not in body:
        return body, ""
    return tuple(part.strip().lower() for part in body.split(",", 1))  # type: ignore[return-value]


def _update_this_aliases(text: str, aliases: dict[str, int]) -> None:
    lowered = text.lower().strip()
    mnemonic = lowered.split(None, 1)[0] if lowered else ""
    left, right = _operand_parts(lowered)
    destination = left if REGISTER_RE.fullmatch(left) else ""
    if not destination:
        return

    if mnemonic == "mov" and REGISTER_RE.fullmatch(right):
        if right in aliases:
            aliases[destination] = aliases[right]
        else:
            aliases.pop(destination, None)
        return
    if mnemonic == "lea":
        match = MEMORY_RE.fullmatch(right)
        if match:
            parsed = parse_memory_expression(match.group(1))
            registers = list(parsed["registers"])
            indexed = list(parsed["indexed_terms"])
            alias_bases = [register for register in registers if register in aliases]
            if len(alias_bases) == 1 and not indexed and len(registers) == 1:
                base = alias_bases[0]
                aliases[destination] = aliases[base] + int(parsed["fixed_displacement"])
                return
        aliases.pop(destination, None)
        return
    if mnemonic in {"add", "sub"} and destination in aliases:
        immediate = _parse_number(right)
        if immediate is not None:
            aliases[destination] += immediate if mnemonic == "add" else -immediate
            return
    if mnemonic not in {"cmp", "test"}:
        aliases.pop(destination, None)


def _update_stack_coordinates(
    instruction,
    esp_coordinate: int | None,
    ebp_coordinate: int | None,
    callee_cleanups: dict[int, int | None],
) -> tuple[int | None, int | None]:
    text = instruction.text.lower().strip()
    mnemonic = text.split(None, 1)[0] if text else ""
    left, right = _operand_parts(text)

    if mnemonic == "push" and esp_coordinate is not None:
        esp_coordinate -= 4
    elif mnemonic == "pop" and esp_coordinate is not None:
        esp_coordinate += 4
    elif mnemonic == "pushad" and esp_coordinate is not None:
        esp_coordinate -= 32
    elif mnemonic == "popad" and esp_coordinate is not None:
        esp_coordinate += 32
    elif mnemonic in {"add", "sub"} and left == "esp":
        amount = _parse_number(right)
        if amount is None or esp_coordinate is None:
            esp_coordinate = None
        else:
            esp_coordinate += amount if mnemonic == "add" else -amount
    elif mnemonic == "lea" and left == "esp":
        match = MEMORY_RE.fullmatch(right)
        if match and esp_coordinate is not None:
            parsed = parse_memory_expression(match.group(1))
            if parsed["registers"] == ["esp"] and not parsed["indexed_terms"]:
                esp_coordinate += int(parsed["fixed_displacement"])
            else:
                esp_coordinate = None
        else:
            esp_coordinate = None
    elif mnemonic == "mov" and left == "ebp" and right == "esp":
        ebp_coordinate = esp_coordinate
    elif mnemonic == "mov" and left == "esp" and right == "ebp":
        esp_coordinate = ebp_coordinate
    elif mnemonic == "leave":
        esp_coordinate = None if ebp_coordinate is None else ebp_coordinate + 4
        ebp_coordinate = None

    if instruction.flow_control == FlowControl.CALL:
        cleanup = callee_cleanups.get(instruction.target)
        if cleanup is None:
            esp_coordinate = None
        elif esp_coordinate is not None:
            esp_coordinate += cleanup
    elif instruction.flow_control == FlowControl.INDIRECT_CALL:
        # Without a proven prototype/target, caller-vs-callee cleanup cannot be
        # recovered reliably from the call instruction alone.
        esp_coordinate = None
    return esp_coordinate, ebp_coordinate


def collect_memory_evidence(
    instructions,
    line_changes: list[dict[str, str]],
    callee_cleanups: dict[int, int | None] | None = None,
) -> dict[str, object]:
    aliases: dict[str, int] = {"ecx": 0}
    fields: dict[tuple[int, int | None, str, bool], list[dict[str, object]]] = defaultdict(list)
    stack: dict[tuple[str, int, int | None, int | None, str], list[dict[str, object]]] = defaultdict(list)
    absolutes: dict[tuple[int, int | None, str], list[dict[str, object]]] = defaultdict(list)
    cleanups = callee_cleanups or {}
    esp_coordinate: int | None = 0
    ebp_coordinate: int | None = None
    normalized_stack_occurrences = 0
    total_stack_occurrences = 0

    for instruction in instructions:
        text = instruction.text.lower()
        for match in MEMORY_RE.finditer(text):
            parsed = parse_memory_expression(match.group(1))
            registers = list(parsed["registers"])
            displacement = int(parsed["fixed_displacement"])
            width = infer_memory_width(text)
            access = infer_memory_access(text, match.start())
            occurrence = {
                "address": f"{instruction.address:08X}",
                "offset": instruction.offset,
                "instruction": instruction.text,
                "source": _source_line_for_address(instruction.address, line_changes),
            }

            alias_bases = [register for register in registers if register in aliases]
            if alias_bases:
                base = alias_bases[0]
                field_offset = aliases[base] + displacement
                indexed = bool(parsed["indexed_terms"] or len(registers) > 1)
                fields[(field_offset, width, access, indexed)].append(
                    {**occurrence, "base_alias": base, "expression": match.group(1)}
                )
                continue

            stack_bases = [register for register in registers if register in {"esp", "ebp"}]
            if stack_bases:
                base = stack_bases[0]
                base_coordinate = esp_coordinate if base == "esp" else ebp_coordinate
                entry_coordinate = None if base_coordinate is None else base_coordinate + displacement
                total_stack_occurrences += 1
                if entry_coordinate is not None:
                    normalized_stack_occurrences += 1
                stack[(base, displacement, entry_coordinate, width, access)].append(
                    {
                        **occurrence,
                        "expression": match.group(1),
                        "entry_coordinate": entry_coordinate,
                    }
                )
                continue

            if not registers and not parsed["indexed_terms"]:
                absolutes[(displacement, width, access)].append(occurrence)

        _update_this_aliases(text, aliases)
        if instruction.flow_control in (FlowControl.CALL, FlowControl.INDIRECT_CALL):
            for register in ("eax", "ecx", "edx"):
                aliases.pop(register, None)
        esp_coordinate, ebp_coordinate = _update_stack_coordinates(
            instruction, esp_coordinate, ebp_coordinate, cleanups
        )

    def field_rows() -> list[dict[str, object]]:
        result = []
        for (offset, width, access, indexed), occurrences in sorted(
            fields.items(), key=lambda item: (item[0][0], str(item[0][1]), item[0][2])
        ):
            result.append(
                {
                    "offset": offset,
                    "offset_hex": f"0x{offset:X}",
                    "width": width,
                    "access": access,
                    "indexed": indexed,
                    "occurrence_count": len(occurrences),
                    "occurrences": occurrences,
                    "confidence": "candidate-this-alias",
                }
            )
        return result

    def stack_rows() -> list[dict[str, object]]:
        result = []
        for (base, displacement, entry_coordinate, width, access), occurrences in sorted(
            stack.items(),
            key=lambda item: (
                item[0][2] is None,
                item[0][2] if item[0][2] is not None else 0,
                item[0][0],
                item[0][1],
                str(item[0][3]),
                item[0][4],
            ),
        ):
            if entry_coordinate is None:
                region = "unknown"
            elif entry_coordinate == 0:
                region = "return_address"
            elif entry_coordinate > 0:
                region = "incoming_parameter_area"
            else:
                region = "local_saved_or_outgoing_area"
            result.append(
                {
                    "base": base,
                    "displacement": displacement,
                    "displacement_hex": f"{displacement:+#x}",
                    "entry_coordinate": entry_coordinate,
                    "entry_coordinate_hex": None
                    if entry_coordinate is None
                    else f"{entry_coordinate:+#x}",
                    "entry_region": region,
                    "parameter_slot_index": (
                        (entry_coordinate - 4) // 4
                        if entry_coordinate is not None
                        and entry_coordinate >= 4
                        and (entry_coordinate - 4) % 4 == 0
                        else None
                    ),
                    "width": width,
                    "access": access,
                    "occurrence_count": len(occurrences),
                    "occurrences": occurrences,
                    "warning": None
                    if entry_coordinate is not None
                    else "entry-relative coordinate became unknown after an unresolved stack cleanup/rebase",
                }
            )
        return result

    def absolute_rows() -> list[dict[str, object]]:
        result = []
        for (address, width, access), occurrences in sorted(absolutes.items()):
            result.append(
                {
                    "address": f"{address:08X}",
                    "width": width,
                    "access": access,
                    "occurrence_count": len(occurrences),
                    "occurrences": occurrences,
                }
            )
        return result

    stack_result = stack_rows()
    parameter_homes = [
        row
        for row in stack_result
        if row["entry_region"] == "incoming_parameter_area"
        and row["access"] in {"write", "read_write", "address"}
    ]
    return {
        "this_fields": field_rows(),
        "stack": stack_result,
        "parameter_home_evidence": parameter_homes,
        "stack_normalization": {
            "normalized_occurrences": normalized_stack_occurrences,
            "total_occurrences": total_stack_occurrences,
            "coverage_percent": 0.0
            if total_stack_occurrences == 0
            else normalized_stack_occurrences / total_stack_occurrences * 100.0,
            "coordinate_system": "entry ESP: return address=0, first stack argument=+4, locals/saves/outgoing args are negative",
            "limit": "normalization stops after an unresolved indirect/direct callee cleanup until a frame-pointer restore re-establishes a coordinate",
        },
        "absolute_memory": absolute_rows(),
    }


def _load_csv_index(path: Path, key: str) -> dict[str, dict[str, str]]:
    if not path.exists():
        return {}
    with path.open("r", encoding="utf-8", newline="") as handle:
        return {row[key].upper(): row for row in csv.DictReader(handle)}


def infer_class_name(source_path: Path) -> str:
    if not source_path.exists():
        return ""
    text = source_path.read_text(encoding="utf-8", errors="replace")
    matches = QUALIFIED_DEFINITION_RE.findall(text)
    return matches[-1] if matches else ""


def _class_check(class_name: str, fields: list[dict[str, object]]) -> dict[str, object]:
    if not class_name:
        return {"class_name": "", "status": "not-checked", "warnings": []}
    index = _load_csv_index(REPO_ROOT / "inventory" / "types" / "all_types.csv", "name")
    row = index.get(class_name.upper())
    if row is None:
        return {
            "class_name": class_name,
            "status": "type-not-found",
            "warnings": [f"No generated type row for {class_name}; no size conclusion is possible."],
        }
    size = int(row.get("size_bytes") or 0)
    warnings: list[str] = []
    impossible = []
    for field in fields:
        if field.get("indexed") or field.get("width") is None:
            continue
        end = int(field["offset"]) + int(field["width"])
        if int(field["offset"]) >= 0 and end > size:
            impossible.append(field)
    if impossible:
        offsets = ", ".join(str(field["offset_hex"]) for field in impossible[:8])
        warnings.append(
            f"Candidate {class_name} size 0x{size:X} cannot contain observed fixed access(es) at {offsets}."
        )
    return {
        "class_name": class_name,
        "status": "conflict" if warnings else "no-fixed-offset-conflict",
        "generated_kind": row.get("kind", ""),
        "generated_base": row.get("base", ""),
        "generated_size": size,
        "generated_size_hex": f"0x{size:X}",
        "warnings": warnings,
        "caveat": "Generated type metadata is reference evidence, not a behavior oracle or proof of the true inheritance surface.",
    }


def _annotate_globals(rows: list[dict[str, object]]) -> None:
    globals_index = _load_csv_index(REPO_ROOT / "inventory" / "globals" / "all_globals.csv", "va")
    reviewed_index = shared_globals_by_address(load_shared_global_evidence(REPO_ROOT))
    for row in rows:
        candidate = globals_index.get(str(row["address"]).upper())
        reviewed = reviewed_index.get(str(row["address"]).upper())
        if candidate:
            row["global"] = {
                "primary_name": candidate.get("primary_name", ""),
                "aliases": candidate.get("aliases", ""),
                "section": candidate.get("section_name", ""),
                "hints": candidate.get("hints", ""),
                "emit_c_type": candidate.get("emit_c_type", ""),
            }
        if reviewed:
            row["global"] = {
                **(row.get("global") or {}),
                "primary_name": reviewed["name"],
                "emit_c_type": reviewed["declaration"],
                "provenance": reviewed["provenance"],
            }
            row["shared_global_evidence"] = reviewed


def _call_rows(instructions, line_changes: list[dict[str, str]]) -> list[dict[str, object]]:
    rows = call_fingerprint(instructions, original=True)
    by_offset = {instruction.offset: instruction for instruction in instructions}
    for row in rows:
        instruction = by_offset.get(int(row["offset"]))
        if instruction is not None:
            row["address"] = f"{instruction.address:08X}"
            row["instruction"] = instruction.text
            row["source"] = _source_line_for_address(instruction.address, line_changes)
    return rows


def build_evidence_bands(
    instructions,
    line_changes: list[dict[str, str]],
    calls: list[dict[str, object]],
    memory: dict[str, object],
) -> list[dict[str, object]]:
    changes = []
    for row in line_changes:
        try:
            changes.append((int(row.get("address", "0"), 16), row))
        except ValueError:
            continue
    changes.sort(key=lambda item: item[0])
    if not changes:
        return []
    instruction_by_offset = {instruction.offset: instruction for instruction in instructions}
    blocks = basic_blocks(instructions, calls)
    max_end = max((instruction.address + len(instruction.data) for instruction in instructions), default=changes[-1][0])

    field_occurrences = []
    for field in memory.get("this_fields", []):
        for occurrence in field.get("occurrences", []):
            field_occurrences.append((int(occurrence["address"], 16), field, occurrence))
    stack_occurrences = []
    for stack in memory.get("stack", []):
        for occurrence in stack.get("occurrences", []):
            stack_occurrences.append((int(occurrence["address"], 16), stack, occurrence))
    absolute_occurrences = []
    for absolute in memory.get("absolute_memory", []):
        for occurrence in absolute.get("occurrences", []):
            absolute_occurrences.append((int(occurrence["address"], 16), absolute, occurrence))

    result = []
    for index, (start, row) in enumerate(changes):
        end = changes[index + 1][0] if index + 1 < len(changes) else max_end
        band_calls = [call for call in calls if start <= int(str(call.get("address") or "0"), 16) < end]
        band_fields = [item for item in field_occurrences if start <= item[0] < end]
        band_stack = [item for item in stack_occurrences if start <= item[0] < end]
        band_absolutes = [item for item in absolute_occurrences if start <= item[0] < end]
        band_blocks = []
        for block in blocks:
            instruction = instruction_by_offset.get(int(block["offset"]))
            if instruction is not None and start <= instruction.address < end:
                band_blocks.append(
                    {
                        "offset": block["offset"],
                        "end_offset": block["end_offset"],
                        "instruction_count": block["instruction_count"],
                        "calls": block.get("calls", []),
                        "successors": block.get("successors", []),
                    }
                )
        if not (band_calls or band_fields or band_stack or band_absolutes or band_blocks):
            continue
        result.append(
            {
                "band_index": index,
                "start_address": f"{start:08X}",
                "end_address_exclusive": f"{end:08X}",
                "source_file": row.get("source_file", ""),
                "source_path": row.get("source_path", ""),
                "source_line": int(row.get("line_number") or 0),
                "calls": [
                    {
                        "address": call.get("address"),
                        "kind": call.get("kind"),
                        "target": call.get("display"),
                    }
                    for call in band_calls
                ],
                "this_fields": [
                    {
                        "address": occurrence["address"],
                        "offset_hex": field["offset_hex"],
                        "width": field["width"],
                        "access": field["access"],
                    }
                    for _address, field, occurrence in band_fields
                ],
                "stack": [
                    {
                        "address": occurrence["address"],
                        "entry_coordinate_hex": stack.get("entry_coordinate_hex"),
                        "entry_region": stack.get("entry_region"),
                        "access": stack.get("access"),
                        "width": stack.get("width"),
                    }
                    for _address, stack, occurrence in band_stack
                ],
                "absolute_memory": [
                    {
                        "address": absolute["address"],
                        "access": absolute["access"],
                        "global": (absolute.get("global") or {}).get("primary_name", ""),
                    }
                    for _address, absolute, _occurrence in band_absolutes
                ],
                "blocks": band_blocks,
            }
        )
    return result


def _ret_cleanup_bytes(code: bytes, start_va: int) -> int | None:
    values: set[int] = set()
    for instruction in decode_instruction_ranges(
        code, [{"start": f"{start_va:08X}", "size_bytes": len(code)}]
    ):
        lowered = instruction.text.lower()
        if lowered == "ret":
            values.add(0)
        elif lowered.startswith("ret "):
            value = _parse_number(lowered.split(None, 1)[1])
            if value is not None:
                values.add(value)
    return next(iter(values)) if len(values) == 1 else None


def direct_call_cleanups(instructions) -> dict[int, int | None]:
    """Resolve callee-pop bytes for known direct targets from original bodies."""
    targets = {
        instruction.target
        for instruction in instructions
        if instruction.flow_control == FlowControl.CALL
    }
    if not targets:
        return {}
    records = {int(row["va"], 16): row for row in load_functions()}
    binaries = load_binaries()
    exe = load_pe_image(repo_path(binaries["original_exe"]))
    result: dict[int, int | None] = {}
    for target in targets:
        record = records.get(target)
        if record is None:
            result[target] = None
            continue
        size = int(record.get("size_bytes") or 0)
        if size <= 0:
            result[target] = None
            continue
        try:
            code = exe.read_va_range(target, target + size - 1)
        except ValueError:
            result[target] = None
            continue
        result[target] = _ret_cleanup_bytes(code, target)
    return result


def _ensure_original(record: dict[str, str], refresh: bool) -> tuple[Path, Path]:
    slug = function_slug(record)
    asm_dir = REPO_ROOT / "build" / "asm"
    binary = asm_dir / f"orig_{slug}.bin"
    metadata = asm_dir / f"orig_{slug}.json"
    if refresh or not binary.exists() or not metadata.exists():
        result = subprocess.run(
            [sys.executable, str(REPO_ROOT / "tools" / "extract_original_function.py"), "--va", record["va"]],
            text=True,
            capture_output=True,
        )
        if result.returncode != 0:
            sys.stdout.write(result.stdout)
            sys.stderr.write(result.stderr)
            raise SystemExit(result.returncode)
    return binary, metadata


def build_dossier(record: dict[str, str], *, class_name: str = "", refresh: bool = False) -> dict[str, object]:
    binary_path, metadata_path = _ensure_original(record, refresh)
    code = binary_path.read_bytes()
    metadata = json.loads(metadata_path.read_text(encoding="utf-8"))
    instructions = decode_instruction_ranges(code, metadata.get("ranges") or [])
    line_changes = load_pdb_function_line_changes().get(record["va"].upper(), [])
    callee_cleanups = direct_call_cleanups(instructions)
    memory = collect_memory_evidence(instructions, line_changes, callee_cleanups)
    _annotate_globals(memory["absolute_memory"])
    shared_globals = []
    seen_shared_globals: set[str] = set()
    for row in memory["absolute_memory"]:
        shared = row.get("shared_global_evidence")
        if not isinstance(shared, dict):
            continue
        name = str(shared.get("name") or "")
        if name and name not in seen_shared_globals:
            seen_shared_globals.add(name)
            shared_globals.append(shared)
    source_path = preferred_source_path(record)
    inferred_class = class_name or infer_class_name(source_path)
    calls = _call_rows(instructions, line_changes)
    evidence_bands = build_evidence_bands(instructions, line_changes, calls, memory)
    return {
        "version": 2,
        "target": {
            "va": record["va"],
            "name": record["name"],
            "slug": function_slug(record),
            "size_bytes": int(record["size_bytes"]),
            "calling_convention": record.get("calling_convention", ""),
            "pdb_source_file": record.get("pdb_source_file", ""),
            "pdb_source_path": record.get("pdb_source_path", ""),
            "living_source": str(source_path.relative_to(REPO_ROOT)) if source_path.exists() else "",
        },
        "scope_and_caveats": [
            "Assembly accesses and call sites are binary evidence; names and inferred class identity are reference hypotheses.",
            "This-relative accesses use conservative register-alias tracking and must be checked against the original assembly before changing a layout.",
            "Stack rows use raw ESP/EBP displacements at each instruction and do not normalize transient pushes.",
            "The dossier does not infer true C++ inheritance, local lifetimes, source expressions, or compiler causation.",
            "Entry-relative stack coordinates are emitted only while stack adjustments and direct callee cleanup remain provable.",
        ],
        "pdb_line_changes": line_changes,
        "calls": calls,
        "pdb_evidence_bands": evidence_bands,
        "direct_call_cleanup_bytes": {
            f"{address:08X}": cleanup for address, cleanup in sorted(callee_cleanups.items())
        },
        "shared_global_evidence": shared_globals,
        **memory,
        "class_layout_check": _class_check(inferred_class, memory["this_fields"]),
    }


def _source_label(source: object) -> str:
    if not isinstance(source, dict) or not source.get("line"):
        return ""
    return f" {source.get('file', '')}:{source['line']}"


def format_dossier(dossier: dict[str, object]) -> str:
    target = dossier["target"]
    assert isinstance(target, dict)
    lines = [
        f"Target evidence dossier: {target['va']} {target['name']}",
        f"Size/calling convention: {target['size_bytes']} bytes / {target['calling_convention']}",
        f"PDB donor: {target['pdb_source_file'] or '<none>'}",
        f"Living source: {target['living_source'] or '<none>'}",
        "",
        "Evidence policy:",
    ]
    for caveat in dossier["scope_and_caveats"]:
        lines.append(f"  - {caveat}")

    calls = dossier["calls"]
    assert isinstance(calls, list)
    lines.extend(["", f"Calls ({len(calls)}):"])
    for index, row in enumerate(calls, 1):
        lines.append(
            f"  {index:02d} {row.get('address', '')} {row.get('kind', ''):<8} "
            f"{row.get('display', '')} pushes~{row.get('nearby_push_count', 0)} "
            f"cleanup={row.get('caller_cleanup_bytes', 0)}{_source_label(row.get('source'))}"
        )

    fields = dossier["this_fields"]
    assert isinstance(fields, list)
    lines.extend(["", f"Candidate this-relative accesses ({len(fields)} grouped facts):"])
    for row in fields:
        width = "?" if row["width"] is None else str(row["width"])
        indexed = " indexed" if row["indexed"] else ""
        example = row["occurrences"][0]
        lines.append(
            f"  {row['offset_hex']:>8} width={width:<2} {row['access']:<10}{indexed:<8} "
            f"x{row['occurrence_count']:<3} {example['address']} {example['instruction']}"
        )

    bands = dossier["pdb_evidence_bands"]
    assert isinstance(bands, list)
    lines.extend(["", f"PDB evidence bands ({len(bands)} nonempty line-change bands):"])
    for band in bands:
        call_names = ",".join(str(call["target"]) for call in band["calls"]) or "-"
        field_names = ",".join(dict.fromkeys(str(field["offset_hex"]) for field in band["this_fields"])) or "-"
        param_homes = sum(item.get("entry_region") == "incoming_parameter_area" for item in band["stack"])
        lines.append(
            f"  {band['start_address']}-{band['end_address_exclusive']} "
            f"{band['source_file']}:{band['source_line']} blocks={len(band['blocks'])} "
            f"calls=[{call_names}] fields=[{field_names}] parameter-home-refs={param_homes}"
        )

    layout = dossier["class_layout_check"]
    assert isinstance(layout, dict)
    lines.extend(["", "Generated class-size consistency check:"])
    if layout.get("class_name"):
        lines.append(
            f"  {layout['class_name']}: {layout['status']}"
            + (f" size={layout.get('generated_size_hex')}" if layout.get("generated_size_hex") else "")
        )
    else:
        lines.append("  No class inferred. Use --class-name when a candidate layout should be checked.")
    for warning in layout.get("warnings", []):
        lines.append(f"  WARNING: {warning}")

    absolutes = dossier["absolute_memory"]
    assert isinstance(absolutes, list)
    lines.extend(["", f"Absolute memory references ({len(absolutes)}):"])
    for row in absolutes:
        global_info = row.get("global") or {}
        name = global_info.get("primary_name", "") if isinstance(global_info, dict) else ""
        lines.append(
            f"  {row['address']} width={row['width'] or '?'} {row['access']:<10} "
            f"x{row['occurrence_count']:<3} {name}"
        )

    shared_globals = dossier["shared_global_evidence"]
    assert isinstance(shared_globals, list)
    lines.extend(["", f"Reviewed shared global evidence ({len(shared_globals)}):"])
    if not shared_globals:
        lines.append("  <none>")
    for row in shared_globals:
        lines.append(f"  {row['storage_va']} {row['name']}: {row['declaration']}")
        lines.append(f"    header: {row['header']}")
        if row.get("definition"):
            lines.append(f"    definition: {row['definition']}")
        if row.get("codegen_note"):
            lines.append(f"    codegen: {row['codegen_note']}")
        for evidence_row in row.get("evidence") or []:
            if isinstance(evidence_row, dict):
                lines.append(
                    f"    evidence {evidence_row.get('va', '?')}: "
                    f"{evidence_row.get('observation', '')}"
                )

    stack = dossier["stack"]
    assert isinstance(stack, list)
    normalization = dossier["stack_normalization"]
    assert isinstance(normalization, dict)
    lines.extend(
        [
            "",
            f"Stack accesses ({len(stack)} grouped facts; entry-normalized coverage "
            f"{float(normalization['coverage_percent']):.1f}%):",
        ]
    )
    for row in stack:
        example = row["occurrences"][0]
        coordinate = row.get("entry_coordinate_hex") or "unknown"
        lines.append(
            f"  [{row['base']}{row['displacement_hex']}] width={row['width'] or '?'} "
            f"entry={coordinate:<8} {row['access']:<10} x{row['occurrence_count']:<3} "
            f"{example['address']} {example['instruction']}"
        )
    parameter_homes = dossier["parameter_home_evidence"]
    assert isinstance(parameter_homes, list)
    lines.extend(["", f"Incoming parameter-home write/address evidence ({len(parameter_homes)}):"])
    if not parameter_homes:
        lines.append("  <none proven while stack coordinate was known>")
    for row in parameter_homes:
        example = row["occurrences"][0]
        slot = row.get("parameter_slot_index")
        slot_text = "unaligned" if slot is None else f"arg[{slot}]"
        lines.append(
            f"  entry={row['entry_coordinate_hex']} {slot_text:<10} width={row['width'] or '?'} "
            f"{row['access']:<10} {example['address']} {example['instruction']}"
        )
    lines.extend(
        [
            "",
            "Next checks:",
            f"  python tools/query_abi.py --va {target['va']} --limit 40",
            f"  python tools/find_function_donors.py --va {target['va']} --limit 20",
            f"  python tools/check_function.py --va {target['va']} --call-map-unmatched --map-limit 40",
            f"  python tools/check_function.py --va {target['va']} --stack-map --no-build",
            f"  python tools/check_function.py --va {target['va']} --block-map-differences --map-limit 40",
        ]
    )
    return "\n".join(lines) + "\n"


def main() -> None:
    args = parse_args()
    record = function_record_by_va(int(args.va, 16))
    dossier = build_dossier(record, class_name=args.class_name or "", refresh=args.refresh_original)
    output_dir = REPO_ROOT / "build" / "dossiers"
    output_dir.mkdir(parents=True, exist_ok=True)
    slug = function_slug(record)
    json_path = output_dir / f"{slug}.json"
    text_path = output_dir / f"{slug}.txt"
    json_path.write_text(json.dumps(dossier, indent=2) + "\n", encoding="utf-8")
    rendered = format_dossier(dossier)
    text_path.write_text(rendered, encoding="utf-8")
    if args.json_only:
        print(json_path)
    else:
        print(rendered, end="")
        print(f"Wrote {text_path.relative_to(REPO_ROOT)}")
        print(f"Wrote {json_path.relative_to(REPO_ROOT)}")


if __name__ == "__main__":
    main()
