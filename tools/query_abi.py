from __future__ import annotations

import argparse
import csv
import json
import re
from pathlib import Path

from common import REPO_ROOT, function_slug, load_functions
from shared_abi_evidence import (
    load_shared_global_evidence,
    shared_global_matches,
    shared_globals_referenced_by_text,
)


SOURCE_SUFFIXES = {".c", ".cpp", ".h", ".hpp", ".inl"}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=(
            "Query ABI evidence and show its provenance.\n"
            "\n"
            "Reviewed shared evidence appears first. Generated metadata is reference evidence.\n"
            "Living exact source is strong codegen evidence, but one local stub does not prove\n"
            "canonical shared ABI. Nonexact source is excluded unless requested.\n"
            "\n"
            "Examples:\n"
            "  python tools/query_abi.py --va 004A9CC0\n"
            "  python tools/query_abi.py --symbol rge_read\n"
            "  python tools/query_abi.py --class TRIBE_Player\n"
            "  python tools/query_abi.py --global rge_base_game\n"
        ),
    )
    query = parser.add_mutually_exclusive_group(required=True)
    query.add_argument("--symbol", help="Search function/type/global names and exact source context.")
    query.add_argument("--class", dest="class_name", help="Query one generated class/type surface.")
    query.add_argument("--global", dest="global_name", help="Query a global by name, alias, or VA.")
    query.add_argument("--va", help="Query one function/global VA in hex.")
    parser.add_argument(
        "--include-nonexact",
        action="store_true",
        help="Include accepted_drift, verified_logic, and scratch source references after exact evidence.",
    )
    parser.add_argument("--limit", type=int, default=40, help="Maximum source evidence rows (default 40; 0 unlimited).")
    parser.add_argument("--json", action="store_true", help="Emit machine-readable JSON.")
    return parser.parse_args()


def _read_csv(path: Path) -> list[dict[str, str]]:
    if not path.exists():
        return []
    with path.open("r", encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def _normalized_va(value: str) -> str:
    cleaned = value.strip().upper()
    if cleaned.startswith("0X"):
        cleaned = cleaned[2:]
    return f"{int(cleaned, 16):08X}"


def _name_matches(candidate: str, query: str, *, exact: bool = False) -> bool:
    left = candidate.casefold()
    right = query.casefold()
    return left == right if exact else right in left


def function_matches(query: str, *, va_only: bool = False) -> list[dict[str, object]]:
    normalized_va = _normalized_va(query) if va_only else ""
    rows = []
    for record in load_functions():
        if va_only:
            if record["va"].upper() != normalized_va:
                continue
        elif not _name_matches(record.get("name", ""), query):
            continue
        rows.append(
            {
                "provenance": "inventory/all_functions.csv (PDB/Ghidra reference)",
                "confidence": "reference-metadata",
                "va": record["va"],
                "name": record["name"],
                "calling_convention": record.get("calling_convention", ""),
                "size_bytes": int(record.get("size_bytes") or 0),
                "pdb_source_file": record.get("pdb_source_file", ""),
                "pdb_source_path": record.get("pdb_source_path", ""),
                "packet": str(
                    Path("inventory")
                    / "functions"
                    / record["va"][:4]
                    / f"{record['slug']}.txt"
                ),
            }
        )
    return rows


def global_matches(query: str, *, va_only: bool = False) -> list[dict[str, object]]:
    normalized_va = _normalized_va(query) if va_only else ""
    rows = []
    for row in _read_csv(REPO_ROOT / "inventory" / "globals" / "all_globals.csv"):
        aliases = row.get("aliases", "")
        if va_only:
            if row.get("va", "").upper() != normalized_va:
                continue
        elif not any(
            _name_matches(candidate, query)
            for candidate in (row.get("primary_name", ""), aliases, row.get("hints", ""))
        ):
            continue
        rows.append(
            {
                "provenance": "inventory/globals/all_globals.csv (generated reference)",
                "confidence": "generated-reference",
                "va": row.get("va", ""),
                "primary_name": row.get("primary_name", ""),
                "aliases": aliases,
                "section": row.get("section_name", ""),
                "size_bytes": int(row.get("size_bytes") or 0),
                "hints": row.get("hints", ""),
                "emit_c_type": row.get("emit_c_type", ""),
                "emit_mode": row.get("emit_mode", ""),
                "byte_preview": row.get("byte_preview", ""),
                "packet": str(
                    Path("inventory") / "globals" / "dumps" / f"{row.get('va', '')}_{row.get('primary_name', '')}.txt"
                ),
            }
        )
    return rows


def _function_source_text(va: str) -> str:
    record = next((row for row in load_functions() if row["va"].upper() == va.upper()), None)
    if record is None:
        return ""
    slug = function_slug(record)
    for bucket in ("matching", "accepted_drift", "verified_logic", "scratch"):
        for suffix in (".c", ".cpp"):
            path = REPO_ROOT / "src" / bucket / f"{slug}{suffix}"
            if path.exists():
                return path.read_text(encoding="utf-8", errors="replace")
    return ""


def class_matches(
    query: str, *, exact: bool = False, methods_only_match: bool = False
) -> list[dict[str, object]]:
    type_rows = _read_csv(REPO_ROOT / "inventory" / "types" / "all_types.csv")
    interface_rows = _read_csv(REPO_ROOT / "inventory" / "classes" / "all_class_interfaces.csv")
    names = {
        row.get("name", "")
        for row in type_rows
        if _name_matches(row.get("name", ""), query, exact=exact)
    }
    names.update(
        row.get("class_name", "")
        for row in interface_rows
        if _name_matches(row.get("class_name", ""), query, exact=exact)
        or (
            not exact
            and any(
                _name_matches(candidate, query)
                for candidate in (row.get("method_name", ""), row.get("declaration", ""))
            )
        )
    )
    results = []
    for name in sorted(filter(None, names), key=str.casefold):
        type_row = next((row for row in type_rows if row.get("name", "").casefold() == name.casefold()), None)
        matching_interface_rows = [
            row
            for row in interface_rows
            if row.get("class_name", "").casefold() == name.casefold()
            and (
                not methods_only_match
                or any(
                    _name_matches(candidate, query)
                    for candidate in (row.get("method_name", ""), row.get("declaration", ""))
                )
            )
        ]
        methods = [
            {
                "kind": row.get("method_kind", ""),
                "name": row.get("method_name", ""),
                "declaration": row.get("declaration", ""),
                "slot_index": row.get("slot_index", ""),
                "slot_hex": row.get("slot_hex", ""),
                "confidence": row.get("method_confidence", ""),
                "evidence": row.get("method_evidence", ""),
            }
            for row in matching_interface_rows
        ]
        first_interface = next(
            (row for row in interface_rows if row.get("class_name", "").casefold() == name.casefold()),
            {},
        )
        results.append(
            {
                "provenance": "inventory/types + inventory/classes (generated reference)",
                "confidence": first_interface.get("class_confidence", "generated-reference"),
                "class_name": name,
                "kind": (type_row or {}).get("kind", ""),
                "base": (type_row or {}).get("base", ""),
                "size_bytes": int((type_row or {}).get("size_bytes") or 0),
                "size_hex": (type_row or {}).get("size_hex", ""),
                "field_count": int((type_row or {}).get("field_count") or 0),
                "donor_header": first_interface.get("donor_header", ""),
                "class_evidence": first_interface.get("class_evidence", ""),
                "type_dump": str(Path("inventory") / "types" / "dumps" / f"{name}.txt"),
                "class_dump": str(Path("inventory") / "classes" / "dumps" / f"{name}.txt"),
                "methods": methods,
            }
        )
    return results


def _source_paths(include_nonexact: bool) -> list[tuple[str, Path]]:
    buckets = [("matching", REPO_ROOT / "src" / "matching")]
    if include_nonexact:
        buckets.extend(
            [
                ("accepted_drift", REPO_ROOT / "src" / "accepted_drift"),
                ("verified_logic", REPO_ROOT / "src" / "verified_logic"),
                ("scratch", REPO_ROOT / "src" / "scratch"),
            ]
        )
    paths = []
    for bucket, root in buckets:
        if not root.exists():
            continue
        for path in sorted(root.iterdir()):
            if path.is_file() and path.suffix.lower() in SOURCE_SUFFIXES:
                paths.append((bucket, path))
    return paths


def _reference_kind(line: str, query: str) -> str:
    escaped = re.escape(query)
    if re.search(rf"\b(?:class|struct|enum)\s+{escaped}\b", line, re.IGNORECASE):
        return "type_declaration_context"
    if re.search(rf"\b{escaped}\s*::", line, re.IGNORECASE):
        return "qualified_definition_or_reference"
    call_match = re.search(rf"\b{escaped}\s*\(", line, re.IGNORECASE)
    if call_match:
        prefix = line[: call_match.start()].strip()
        declaration_prefix = bool(prefix) and not (
            prefix.endswith(("->", ".", "=", ","))
            or prefix.split(None, 1)[0] in {"return", "if", "while", "for", "switch", "case"}
            or "=" in prefix
        )
        if ";" in line and "{" not in line and declaration_prefix:
            return "declaration_candidate"
        if "{" in line:
            return "definition_candidate"
        return "call_or_multiline_signature"
    return "name_or_layout_context"


def source_evidence(query: str, include_nonexact: bool = False, limit: int = 40) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    needle = query.casefold()
    for bucket, path in _source_paths(include_nonexact):
        text = path.read_text(encoding="utf-8", errors="replace")
        if needle not in text.casefold():
            continue
        per_file = 0
        lines = text.splitlines()
        for index, line in enumerate(lines):
            if needle not in line.casefold():
                continue
            rows.append(
                {
                    "provenance": f"living {bucket} source",
                    "confidence": "exact-codegen-context" if bucket == "matching" else "nonexact-working-context",
                    "bucket": bucket,
                    "path": str(path.relative_to(REPO_ROOT)),
                    "line": index + 1,
                    "kind": _reference_kind(line, query),
                    "text": line.strip(),
                    "context_before": lines[index - 1].strip() if index else "",
                    "context_after": lines[index + 1].strip() if index + 1 < len(lines) else "",
                    "caveat": "An exact function proves this declaration/context can produce that function's bytes; it does not make every local stub canonical semantic ABI.",
                }
            )
            per_file += 1
            if per_file >= 3 or (limit and len(rows) >= limit):
                break
        if limit and len(rows) >= limit:
            break
    return rows


def _split_parameters(text: str) -> list[str]:
    if not text.strip() or text.strip() == "void":
        return []
    parts: list[str] = []
    start = 0
    depth = 0
    for index, char in enumerate(text):
        if char in "(<[":
            depth += 1
        elif char in ")>]":
            depth = max(0, depth - 1)
        elif char == "," and depth == 0:
            parts.append(text[start:index].strip())
            start = index + 1
    parts.append(text[start:].strip())
    return parts


def _parameter_type(parameter: str) -> str:
    value = parameter.split("=", 1)[0].strip()
    if value == "...":
        return value
    # Function pointers/references and unnamed array declarators need a real C++
    # parser. Preserve them verbatim instead of manufacturing false consensus.
    if "(*" in value or "(&" in value:
        return " ".join(value.split())
    match = re.match(r"^(.*?)(?:\s+|(?<=[*&]))([A-Za-z_]\w*)(\s*\[[^\]]*\])?$", value)
    if match:
        prefix, possible_name, array = match.groups()
        terminal_type_words = {
            "void", "bool", "char", "short", "int", "long", "float", "double",
            "signed", "unsigned", "wchar_t", "size_t", "uchar", "ushort", "uint", "ulong",
        }
        if possible_name not in terminal_type_words and prefix.strip():
            value = prefix.strip() + (array or "")
    value = re.sub(r"\s*([*&])\s*", r"\1", value)
    return " ".join(value.split())


def normalize_declaration(declaration: str, symbol: str) -> dict[str, object]:
    text = " ".join(declaration.strip().rstrip(";").split())
    escaped = re.escape(symbol)
    match = re.search(rf"(?:\b[A-Za-z_]\w*::)?\b{escaped}\s*\((.*)\)\s*(const)?$", text)
    if not match:
        return {"parsed": False, "canonical": f"raw:{text}", "raw": text}
    prefix = text[: match.start()].strip()
    linkage = "C" if re.search(r'\bextern\s+"C"', prefix) else "C++/default"
    convention_match = re.search(r"\b(__cdecl|__stdcall|__thiscall|__fastcall)\b", prefix)
    convention = convention_match.group(1) if convention_match else "default/unknown"
    form = (
        "virtual-member" if re.search(r"\bvirtual\b", prefix)
        else "static-or-free" if re.search(r"\bstatic\b", prefix)
        else "qualified-member" if "::" in text[: match.end()]
        else "free-or-unknown"
    )
    return_prefix = re.sub(r'\bextern\s+"C"\s*', "", prefix)
    return_prefix = re.sub(r"\b(?:extern|static|virtual|inline|__cdecl|__stdcall|__thiscall|__fastcall)\b", "", return_prefix)
    return_type = " ".join(return_prefix.split()) or "constructor/destructor-or-unknown"
    params = [_parameter_type(item) for item in _split_parameters(match.group(1))]
    is_const = bool(match.group(2))
    canonical = (
        f"linkage={linkage};cc={convention};form={form};return={return_type};"
        f"params=({','.join(params)});const={int(is_const)}"
    )
    return {
        "parsed": True,
        "canonical": canonical,
        "linkage": linkage,
        "calling_convention": convention,
        "form": form,
        "return_type": return_type,
        "parameter_types": params,
        "const_member": is_const,
        "raw": text,
    }


def declaration_candidates(
    evidence: list[dict[str, object]], symbol: str = ""
) -> list[dict[str, object]]:
    grouped: dict[str, dict[str, object]] = {}
    for row in evidence:
        if row.get("kind") != "declaration_candidate":
            continue
        declaration = " ".join(str(row.get("text") or "").split())
        candidate = grouped.setdefault(
            declaration,
            {
                "declaration": declaration,
                "exact_occurrences": 0,
                "nonexact_occurrences": 0,
                "locations": [],
                "confidence": "exact-codegen-context-candidate",
                "caveat": "Textual agreement is declaration evidence, not proof of canonical semantic ABI.",
            },
        )
        if symbol:
            candidate["normalized_abi"] = normalize_declaration(declaration, symbol)
        if row.get("bucket") == "matching":
            candidate["exact_occurrences"] = int(candidate["exact_occurrences"]) + 1
        else:
            candidate["nonexact_occurrences"] = int(candidate["nonexact_occurrences"]) + 1
        candidate["locations"].append(f"{row.get('path')}:{row.get('line')}")
    return sorted(
        grouped.values(),
        key=lambda row: (
            -int(row["exact_occurrences"]),
            -int(row["nonexact_occurrences"]),
            str(row["declaration"]).casefold(),
        ),
    )


def abi_consensus(candidates: list[dict[str, object]]) -> list[dict[str, object]]:
    grouped: dict[str, dict[str, object]] = {}
    for candidate in candidates:
        normalized = candidate.get("normalized_abi") or {}
        if not isinstance(normalized, dict):
            continue
        canonical = str(normalized.get("canonical") or "")
        if not canonical:
            continue
        row = grouped.setdefault(
            canonical,
            {
                "canonical": canonical,
                "normalized": normalized,
                "exact_occurrences": 0,
                "nonexact_occurrences": 0,
                "spellings": [],
                "locations": [],
            },
        )
        row["exact_occurrences"] = int(row["exact_occurrences"]) + int(candidate["exact_occurrences"])
        row["nonexact_occurrences"] = int(row["nonexact_occurrences"]) + int(candidate["nonexact_occurrences"])
        row["spellings"].append(candidate["declaration"])
        row["locations"].extend(candidate["locations"])
    return sorted(
        grouped.values(),
        key=lambda row: (-int(row["exact_occurrences"]), -int(row["nonexact_occurrences"]), row["canonical"]),
    )


def build_query(
    *,
    symbol: str = "",
    class_name: str = "",
    global_name: str = "",
    va: str = "",
    include_nonexact: bool = False,
    limit: int = 40,
) -> dict[str, object]:
    if limit < 0:
        raise ValueError("--limit must be zero or positive")
    reviewed_globals = load_shared_global_evidence(REPO_ROOT)
    if va:
        normalized = _normalized_va(va)
        functions = function_matches(normalized, va_only=True)
        globals_found = global_matches(normalized, va_only=True)
        if functions:
            shared_globals = shared_globals_referenced_by_text(
                reviewed_globals, _function_source_text(normalized)
            )
        else:
            shared_globals = shared_global_matches(reviewed_globals, normalized)
        evidence_query = (
            str(functions[0]["name"])
            if functions
            else str(globals_found[0]["primary_name"])
            if globals_found
            else ""
        )
        query_kind = "va"
        query_value = normalized
        classes = []
    elif class_name:
        functions = []
        globals_found = []
        shared_globals = []
        classes = class_matches(class_name, exact=True)
        evidence_query = class_name
        query_kind = "class"
        query_value = class_name
    elif global_name:
        functions = []
        globals_found = global_matches(global_name)
        shared_globals = shared_global_matches(reviewed_globals, global_name)
        classes = []
        evidence_query = global_name
        query_kind = "global"
        query_value = global_name
    else:
        functions = function_matches(symbol)
        globals_found = global_matches(symbol)
        shared_globals = shared_global_matches(reviewed_globals, symbol)
        classes = class_matches(symbol, methods_only_match=True)
        evidence_query = symbol
        query_kind = "symbol"
        query_value = symbol

    evidence = (
        source_evidence(evidence_query, include_nonexact=include_nonexact, limit=limit)
        if evidence_query
        else []
    )
    candidates = declaration_candidates(evidence, evidence_query)
    return {
        "version": 2,
        "query": {"kind": query_kind, "value": query_value},
        "policy": [
            "The original EXE is the behavior oracle; this command joins reference metadata and living-source provenance.",
            "Generated signatures/layouts are candidates, not canonical ABI by themselves.",
            "Exact-source context is strong codegen evidence but local stubs may still be intentionally narrow or codegen-active.",
            "Reviewed shared evidence is a verified starting point, not proof that every target needs the same source surface.",
            "No declaration is auto-promoted to shared headers by this tool.",
        ],
        "functions": functions,
        "globals": globals_found,
        "shared_globals": shared_globals,
        "classes": classes,
        "source_evidence": evidence,
        "declaration_candidates": candidates,
        "abi_consensus": abi_consensus(candidates),
    }


def format_query(payload: dict[str, object]) -> str:
    query = payload["query"]
    assert isinstance(query, dict)
    lines = [f"ABI evidence query: {query['kind']}={query['value']}", "", "Policy:"]
    for item in payload["policy"]:
        lines.append(f"  - {item}")

    functions = payload["functions"]
    assert isinstance(functions, list)
    lines.extend(["", f"Function metadata ({len(functions)}):"])
    if not functions:
        lines.append("  <none>")
    for row in functions:
        lines.append(
            f"  {row['va']} {row['name']} cc={row['calling_convention'] or '?'} "
            f"size={row['size_bytes']} donor={row['pdb_source_file'] or '<none>'}"
        )
        lines.append(f"    provenance: {row['provenance']}")

    globals_found = payload["globals"]
    assert isinstance(globals_found, list)
    lines.extend(["", f"Global metadata ({len(globals_found)}):"])
    if not globals_found:
        lines.append("  <none>")
    for row in globals_found:
        type_text = row["emit_c_type"] or "<no conservative emitted type>"
        lines.append(
            f"  {row['va']} {row['primary_name']} type={type_text} size={row['size_bytes']} "
            f"section={row['section']}"
        )
        if row["aliases"]:
            lines.append(f"    aliases: {row['aliases']}")
        lines.append(f"    provenance: {row['provenance']}")

    shared_globals = payload["shared_globals"]
    assert isinstance(shared_globals, list)
    lines.extend(["", f"Reviewed shared global evidence ({len(shared_globals)}):"])
    if not shared_globals:
        lines.append("  <none>")
    for row in shared_globals:
        lines.append(
            f"  {row['storage_va']} {row['name']}: {row['declaration']}"
        )
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
        lines.append(f"    provenance: {row['provenance']}")

    classes = payload["classes"]
    assert isinstance(classes, list)
    lines.extend(["", f"Class/type metadata ({len(classes)}):"])
    if not classes:
        lines.append("  <none>")
    for row in classes:
        lines.append(
            f"  {row['class_name']} kind={row['kind'] or '?'} base={row['base'] or '<none>'} "
            f"size={row['size_hex'] or '?'} confidence={row['confidence']}"
        )
        if row["donor_header"]:
            lines.append(f"    donor header: {row['donor_header']}")
        for method in row["methods"]:
            slot = f" slot={method['slot_hex']}" if method["slot_hex"] else ""
            lines.append(
                f"    {method['kind']}{slot}: {method['declaration']} "
                f"[{method['confidence'] or 'unknown'}]"
            )

    evidence = payload["source_evidence"]
    assert isinstance(evidence, list)
    declarations = payload["declaration_candidates"]
    assert isinstance(declarations, list)
    lines.extend(["", f"Declaration candidates ({len(declarations)} distinct spellings):"])
    if not declarations:
        lines.append("  <none>")
    for row in declarations:
        lines.append(
            f"  exact={row['exact_occurrences']} nonexact={row['nonexact_occurrences']} "
            f"{row['declaration']}"
        )
        locations = row["locations"]
        lines.append(f"    evidence: {', '.join(locations[:6])}")
    consensus = payload["abi_consensus"]
    assert isinstance(consensus, list)
    lines.extend(["", f"Normalized ABI candidates ({len(consensus)}):"])
    if not consensus:
        lines.append("  <none>")
    for row in consensus:
        lines.append(
            f"  exact={row['exact_occurrences']} nonexact={row['nonexact_occurrences']} {row['canonical']}"
        )
    lines.extend(["", f"Living source evidence ({len(evidence)}):"])
    if not evidence:
        lines.append("  <none or VA-only query>")
    for row in evidence:
        lines.append(
            f"  [{row['bucket']}] {row['path']}:{row['line']} {row['kind']}"
        )
        lines.append(f"    {row['text']}")
    return "\n".join(lines) + "\n"


def main() -> None:
    args = parse_args()
    try:
        payload = build_query(
            symbol=args.symbol or "",
            class_name=args.class_name or "",
            global_name=args.global_name or "",
            va=args.va or "",
            include_nonexact=args.include_nonexact,
            limit=args.limit,
        )
    except ValueError as error:
        raise SystemExit(str(error)) from error
    print(json.dumps(payload, indent=2) if args.json else format_query(payload), end="" if args.json else "")
    if args.json:
        print()


if __name__ == "__main__":
    main()
