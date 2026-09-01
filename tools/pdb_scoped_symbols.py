from __future__ import annotations

import json
import re
from pathlib import Path

from common import PDB_INVENTORY_DIR, PeImage


SCOPED_SYMBOLS_PATH = PDB_INVENTORY_DIR / "scoped_symbols.json"

MODULE_HEADER_RE = re.compile(r'^\*\* Module: "(?P<path>.+)"$')
RECORD_RE = re.compile(
    r"^\((?P<record>[0-9A-F]+)\)\s+(?P<kind>S_[A-Z0-9_]+)(?::\s*(?P<body>.*))?$"
)
PROCEDURE_RE = re.compile(
    r"^\[(?P<section>[0-9A-F]{4}):(?P<offset>[0-9A-F]{8})\],\s*"
    r"Cb:\s*(?P<size>[0-9A-F]+),\s*Type:\s*(?P<type>.+?),\s*(?P<name>.+)$"
)
PROCEDURE_END_RE = re.compile(r"\bEnd:\s*(?P<end>[0-9A-F]{8})\b")
DATA_RE = re.compile(
    r"^\[(?P<section>[0-9A-F]{4}):(?P<offset>[0-9A-F]{8})\],\s*"
    r"Type:\s*(?P<type>.+?),\s*(?P<name>.+)$"
)
BPREL_RE = re.compile(
    r"^\[(?P<offset>[0-9A-F]{8})\],\s*Type:\s*(?P<type>.+?),\s*(?P<name>.+)$"
)
REGISTER_RE = re.compile(
    r"^(?P<register>[^,]+),\s*Type:\s*(?P<type>.+?),\s*(?P<name>.+)$"
)
TYPE_INDEX_RE = re.compile(r"(?:\((?P<primitive>[0-9A-F]{4})\)|0x(?P<complex>[0-9A-F]+))\s*$")
TYPE_RECORD_RE = re.compile(
    r"^0x(?P<index>[0-9A-Fa-f]+)\s*:\s*Length\s*=.*?\b(?P<leaf>LF_[A-Z0-9_]+)\s*$"
)

TYPE_NAMES = {
    "T_VOID": "void",
    "T_RCHAR": "char",
    "T_UCHAR": "unsigned char",
    "T_SHORT": "short",
    "T_USHORT": "unsigned short",
    "T_LONG": "long",
    "T_ULONG": "unsigned long",
    "T_INT4": "int",
    "T_UINT4": "unsigned int",
    "T_REAL32": "float",
    "T_REAL64": "double",
    "T_32PVOID": "void*",
    "T_32PRCHAR": "char*",
    "T_32PUCHAR": "unsigned char*",
    "T_32PSHORT": "short*",
    "T_32PUSHORT": "unsigned short*",
    "T_32PLONG": "long*",
    "T_32PULONG": "unsigned long*",
    "T_32PINT4": "int*",
    "T_32PUINT4": "unsigned int*",
    "T_32PREAL32": "float*",
    "T_32PREAL64": "double*",
}


def _section_offset_va(image: PeImage, section: str, offset: str) -> str:
    section_index = int(section, 16) - 1
    if section_index < 0 or section_index >= len(image.sections):
        return ""
    pe_section = image.sections[section_index]
    return f"{image.image_base + pe_section.virtual_address + int(offset, 16):08X}"


def _signed_32(value: str) -> int:
    number = int(value, 16)
    return number - 0x100000000 if number & 0x80000000 else number


def type_evidence(display: str) -> dict[str, str]:
    value = " ".join(display.split())
    token = value.split("(", 1)[0].strip()
    match = TYPE_INDEX_RE.search(value)
    return {
        "type_display": value,
        "type_index": (match.group("primitive") or match.group("complex")) if match else "",
        "type_name": TYPE_NAMES.get(token, ""),
    }


def parse_type_summaries(raw_types: str) -> dict[str, dict[str, str]]:
    entries: dict[str, dict[str, str]] = {}
    current_index = ""
    current_lines: list[str] = []
    current_leaf = ""

    def finish() -> None:
        if not current_index:
            return
        text = "\n".join(current_lines)
        row = {
            "leaf": current_leaf,
            "name": "",
            "element_type": "",
            "form": "",
            "qualifier": "",
        }
        name_match = re.search(
            r"(?:class|structure|union|enum) name\s*=\s*([^,\r\n]+)", text, re.IGNORECASE
        )
        if name_match:
            row["name"] = name_match.group(1).strip()
        element_match = re.search(
            r"(?:(?:Element|Modified) type\s*[:=]|modifies type)\s*"
            r"(0x[0-9A-Fa-f]+|T_[A-Z0-9_]+\([0-9A-Fa-f]+\))",
            text,
        )
        if element_match:
            row["element_type"] = element_match.group(1)
        if "L-value Reference" in text:
            row["form"] = "reference"
        elif "Pointer" in text:
            row["form"] = "pointer"
        if re.search(r"\bconst,\s+modifies type\b", text):
            row["qualifier"] = "const"
        elif re.search(r"\bvolatile,\s+modifies type\b", text):
            row["qualifier"] = "volatile"
        entries[current_index] = row

    for raw_line in raw_types.splitlines():
        line = raw_line.strip()
        match = TYPE_RECORD_RE.match(line)
        if match:
            finish()
            current_index = match.group("index").upper()
            current_leaf = match.group("leaf")
            current_lines = []
        elif current_index:
            current_lines.append(line)
    finish()
    return entries


def resolve_type_name(
    type_display: str,
    summaries: dict[str, dict[str, str]],
    seen: set[str] | None = None,
) -> str:
    direct = type_evidence(type_display)
    if direct["type_name"]:
        return direct["type_name"]
    index = direct["type_index"].upper()
    if not index or index not in summaries:
        return ""
    seen = set() if seen is None else set(seen)
    if index in seen:
        return ""
    seen.add(index)
    row = summaries[index]
    if row.get("name"):
        return row["name"]
    element = row.get("element_type") or ""
    resolved = resolve_type_name(element, summaries, seen) if element else ""
    if not resolved:
        return ""
    if row.get("form") == "pointer":
        return resolved + "*"
    if row.get("form") == "reference":
        return resolved + "&"
    if row.get("qualifier"):
        return row["qualifier"] + " " + resolved
    return resolved


def apply_type_names(
    payload: dict[str, object], summaries: dict[str, dict[str, str]]
) -> None:
    functions = payload.get("functions") or {}
    if not isinstance(functions, dict):
        return
    for function in functions.values():
        if not isinstance(function, dict):
            continue
        function["type_name"] = resolve_type_name(
            str(function.get("type_display") or ""), summaries
        )
        for key in ("function_statics", "stack_symbols", "register_symbols"):
            for symbol in function.get(key) or []:
                if not symbol.get("type_name"):
                    symbol["type_name"] = resolve_type_name(
                        str(symbol.get("type_display") or ""), summaries
                    )
    owners = payload.get("function_static_address_owners") or {}
    if isinstance(owners, dict):
        for rows in owners.values():
            for owner in rows:
                function = functions.get(owner.get("function_va")) or {}
                symbol = next(
                    (
                        row
                        for row in function.get("function_statics") or []
                        if row.get("name") == owner.get("name")
                    ),
                    None,
                )
                if symbol:
                    owner["type_name"] = symbol.get("type_name") or ""


def parse_scoped_symbols(raw_dump: str, image: PeImage) -> dict[str, object]:
    lines = raw_dump.splitlines()
    functions: dict[str, dict[str, object]] = {}
    address_owners: dict[str, list[dict[str, str]]] = {}
    module_path = ""
    current: dict[str, object] | None = None
    current_end = ""

    counts = {
        "procedures": 0,
        "function_statics": 0,
        "stack_symbols": 0,
        "register_symbols": 0,
    }

    for index, raw_line in enumerate(lines):
        line = raw_line.strip()
        module_match = MODULE_HEADER_RE.match(line)
        if module_match:
            module_path = module_match.group("path")
            current = None
            current_end = ""
            continue

        record_match = RECORD_RE.match(line)
        if not record_match:
            continue
        record = record_match.group("record")
        kind = record_match.group("kind")
        body = record_match.group("body") or ""

        if kind in {"S_GPROC32", "S_LPROC32"}:
            procedure_match = PROCEDURE_RE.match(body)
            if procedure_match is None:
                current = None
                current_end = ""
                continue
            end_record = ""
            for following in lines[index + 1 : index + 4]:
                end_match = PROCEDURE_END_RE.search(following)
                if end_match:
                    end_record = end_match.group("end")
                    break
            va = _section_offset_va(
                image, procedure_match.group("section"), procedure_match.group("offset")
            )
            if not va:
                current = None
                current_end = ""
                continue
            current = {
                "va": va,
                "name": procedure_match.group("name").strip(),
                "module_object_path": module_path,
                "section": procedure_match.group("section"),
                "offset": procedure_match.group("offset"),
                "size_bytes": int(procedure_match.group("size"), 16),
                **type_evidence(procedure_match.group("type")),
                "function_statics": [],
                "stack_symbols": [],
                "register_symbols": [],
            }
            functions[va] = current
            current_end = f"{int(end_record, 16):X}" if end_record else ""
            counts["procedures"] += 1
            continue

        if current is None:
            continue
        if kind == "S_END" and f"{int(record, 16):X}" == current_end:
            current = None
            current_end = ""
            continue

        if kind == "S_LDATA32":
            symbol_match = DATA_RE.match(body)
            if symbol_match is None:
                continue
            address = _section_offset_va(
                image, symbol_match.group("section"), symbol_match.group("offset")
            )
            symbol = {
                "kind": "function_static",
                "name": symbol_match.group("name").strip(),
                "section": symbol_match.group("section"),
                "offset": symbol_match.group("offset"),
                "address": address,
                **type_evidence(symbol_match.group("type")),
            }
            current["function_statics"].append(symbol)  # type: ignore[index]
            if address:
                address_owners.setdefault(address, []).append(
                    {
                        "function_va": str(current["va"]),
                        "function_name": str(current["name"]),
                        "name": str(symbol["name"]),
                        "type_display": str(symbol["type_display"]),
                        "type_name": str(symbol["type_name"]),
                    }
                )
            counts["function_statics"] += 1
            continue

        if kind == "S_BPREL32":
            symbol_match = BPREL_RE.match(body)
            if symbol_match is None:
                continue
            offset = _signed_32(symbol_match.group("offset"))
            current["stack_symbols"].append(  # type: ignore[index]
                {
                    "kind": "stack",
                    "name": symbol_match.group("name").strip(),
                    "offset": offset,
                    "offset_hex": f"{offset:+#x}",
                    **type_evidence(symbol_match.group("type")),
                }
            )
            counts["stack_symbols"] += 1
            continue

        if kind == "S_REGISTER":
            symbol_match = REGISTER_RE.match(body)
            if symbol_match is None:
                continue
            current["register_symbols"].append(  # type: ignore[index]
                {
                    "kind": "register",
                    "name": symbol_match.group("name").strip(),
                    "register": symbol_match.group("register").strip(),
                    **type_evidence(symbol_match.group("type")),
                }
            )
            counts["register_symbols"] += 1

    functions_with_symbols = sum(
        bool(row["function_statics"] or row["stack_symbols"] or row["register_symbols"])
        for row in functions.values()
    )
    return {
        "schema": 1,
        "counts": {**counts, "functions_with_symbols": functions_with_symbols},
        "functions": functions,
        "function_static_address_owners": address_owners,
    }


def load_scoped_symbols(path: Path = SCOPED_SYMBOLS_PATH) -> dict[str, object]:
    if not path.exists():
        return {"schema": 1, "counts": {}, "functions": {}, "function_static_address_owners": {}}
    return json.loads(path.read_text(encoding="utf-8"))


def scoped_symbols_for_va(va: str, path: Path = SCOPED_SYMBOLS_PATH) -> dict[str, object] | None:
    payload = load_scoped_symbols(path)
    functions = payload.get("functions") or {}
    return functions.get(va.upper()) if isinstance(functions, dict) else None
