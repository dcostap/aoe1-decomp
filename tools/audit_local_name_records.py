"""Compare local names in a VC5 debug object with original PDB records.

This pilot checks only exact functions with unique storage records and no
lexical blocks. It can compile a module or read existing objects. It does not
change source names.
"""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import subprocess

from coff import load_coff_object
from common import load_build_modules, load_pe_image, REPO_ROOT
from function_compare import compare_object_function, compile_source
from pdb_scoped_symbols import (
    apply_type_names, BPREL_RE, parse_scoped_symbols, parse_type_summaries,
    PROCEDURE_RE, RECORD_RE, REGISTER_RE, type_evidence,
)

PINNED = REPO_ROOT / "orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack"
SECTION_RE = re.compile(r"^\*{5} SECTION #([0-9A-F]+)$")


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def dump(cvdump: Path, option: str, path: Path, output: Path) -> str:
    result = subprocess.run([str(cvdump), option, str(path)], capture_output=True,
                            text=True, errors="replace")
    if result.returncode:
        raise RuntimeError(result.stdout + result.stderr)
    output.write_text(result.stdout, encoding="utf-8")
    return result.stdout


def parse_object_records(text: str, obj) -> dict[str, dict]:
    """Use COFF relocations, not display names, to identify each procedure."""
    procedures: dict[str, dict] = {}
    section = None
    current = None
    for raw in text.splitlines():
        line = raw.strip()
        heading = SECTION_RE.match(line)
        if heading:
            section = obj.section_by_index(int(heading[1], 16))
            current = None
            continue
        record = RECORD_RE.match(line)
        if not record or section is None:
            continue
        kind, body = record["kind"], record["body"] or ""
        if kind in {"S_GPROC32", "S_LPROC32"}:
            current = None
            procedure = PROCEDURE_RE.match(body)
            # S_GPROC32_ST stores its code offset at record offset + 32.
            location = int(record["record"], 16) + 32
            owners = [r.symbol_name for r in section.relocations
                      if r.offset == location and r.reloc_type == 0xB]
            if procedure is None or len(owners) != 1:
                continue
            owner = owners[0]
            if owner in procedures:
                raise ValueError(f"Multiple debug procedures for {owner}")
            current = {"name": procedure["name"], "stack_symbols": [],
                       "register_symbols": [], "has_blocks": False}
            procedures[owner] = current
        elif current is not None:
            if kind == "S_BLOCK32":
                current["has_blocks"] = True
            elif kind == "S_END":
                # Once a block appears, this pilot refuses the whole procedure.
                current = None
            elif kind == "S_BPREL32":
                match = BPREL_RE.match(body)
                if match:
                    offset = int(match["offset"], 16)
                    if offset & 0x80000000:
                        offset -= 0x100000000
                    current["stack_symbols"].append({
                        "kind": "stack", "name": match["name"], "offset": offset,
                        **type_evidence(match["type"]),
                    })
            elif kind == "S_REGISTER":
                match = REGISTER_RE.match(body)
                if match:
                    current["register_symbols"].append({
                        "kind": "register", "name": match["name"],
                        "register": match["register"], **type_evidence(match["type"]),
                    })
    return procedures


def mark_original_blocks(text: str, image, functions: dict) -> None:
    current = None
    for raw in text.splitlines():
        record = RECORD_RE.match(raw.strip())
        if not record:
            continue
        kind = record["kind"]
        if kind in {"S_GPROC32", "S_LPROC32"}:
            current = None
            procedure = PROCEDURE_RE.match(record["body"] or "")
            if procedure:
                section = image.sections[int(procedure["section"], 16) - 1]
                va = image.image_base + section.virtual_address + int(procedure["offset"], 16)
                current = functions.get(f"{va:08X}")
        elif current is not None:
            if kind == "S_BLOCK32":
                current["has_blocks"] = True
            elif kind == "S_END":
                current = None


def storage(row: dict) -> tuple:
    if row["kind"] == "stack":
        return "stack", row["offset"]
    return "register", row["register"].lower()


def symbols(procedure: dict) -> list[dict]:
    return procedure.get("stack_symbols", []) + procedure.get("register_symbols", [])


def compare_names(original: dict, rebuilt: dict) -> list[dict]:
    """Check only unique names at unique storage locations with resolved types."""
    old, new = symbols(original), symbols(rebuilt)
    old_names = Counter(r["name"] for r in old)
    new_names = Counter(r["name"] for r in new)
    old_slots = Counter(storage(r) for r in old)
    new_slots = Counter(storage(r) for r in new)
    rows = []
    for expected in old:
        place = storage(expected)
        candidates = [r for r in new if storage(r) == place]
        actual = candidates[0] if len(candidates) == 1 else None
        row = {"original": expected, "rebuilt_at_location": actual,
               "result": "unknown", "reason": ""}
        if original.get("has_blocks") or rebuilt.get("has_blocks"):
            row["reason"] = "lexical scopes need a separate comparison"
        elif old_names[expected["name"]] != 1 or old_slots[place] != 1 or new_slots[place] > 1:
            row["reason"] = "name or storage reuse makes the mapping uncertain"
        elif actual is None:
            row["reason"] = "no rebuilt variable at the original location"
        elif new_names[actual["name"]] != 1:
            row["reason"] = "rebuilt name appears more than once"
        elif not expected.get("type_name") or not actual.get("type_name"):
            row["reason"] = "type is not resolved"
        elif expected["type_name"] != actual["type_name"]:
            row["reason"] = "types differ; this pilot cannot prove a name-only error"
        elif expected["name"] != actual["name"]:
            if old_names[actual["name"]] == 1:
                row.update(result="conflict", reason="original name appears at another typed location",
                           name_relation="original_name_at_other_location")
            elif old_names[actual["name"]]:
                row["reason"] = "rebuilt spelling has more than one original record"
            else:
                row.update(result="different_spelling", reason="rebuilt spelling does not appear in the original procedure",
                           name_relation="different_spelling")
        else:
            row.update(result="confirmed", reason="name, type, and storage location agree")
        rows.append(row)
    return rows


def audit_function(va: str, entry: dict, module: dict, baseline, debug,
                   originals: dict, procedures: dict) -> dict:
    row = {"va": va, "symbol": entry.get("symbol", ""), "variables": []}
    if entry.get("status") != "matching":
        return {**row, "result": "not_checked", "reason": "function does not claim exactness"}
    normal = compare_object_function(baseline, int(va, 16), module)
    expanded = compare_object_function(debug, int(va, 16), module)
    row.update(baseline_comparison=normal, debug_comparison=expanded)
    if normal["result"] != "MATCH" or expanded["result"] != "MATCH":
        return {**row, "result": "not_checked", "reason": "both objects must match the original code"}
    original = originals.get(va)
    rebuilt = procedures.get(entry.get("symbol"))
    if original is None:
        return {**row, "result": "unknown", "reason": "original procedure records are missing"}
    if rebuilt is None:
        return {**row, "result": "unknown", "reason": "rebuilt procedure records are missing"}
    rows = compare_names(original, rebuilt)
    counts = Counter(r["result"] for r in rows)
    source_only = [r for r in symbols(rebuilt)
                   if not any(storage(r) == storage(o) for o in symbols(original))]
    outcome = (
        "conflict" if counts["conflict"] else
        "name_difference" if counts["different_spelling"] else
        "unknown" if counts["unknown"] or source_only or not rows else "confirmed"
    )
    row.update(result=outcome, variables=rows, counts=dict(counts),
               source_only_records=source_only)
    return row


def compile_pair(module: dict, out: Path, source_ref: str | None) -> tuple[Path, Path]:
    source = REPO_ROOT / module["source"]
    normal_flags = (REPO_ROOT / module["build"]["flags_path"]).read_text(encoding="utf-8")
    debug_source = source
    if source_ref:
        snapshot = subprocess.check_output(["git", "show", source_ref + ":" + module["source"]], cwd=REPO_ROOT)
        debug_source = out / ("source-snapshot" + source.suffix)
        debug_source.write_bytes(snapshot)
    manifests = []
    for label, input_source, extra in [("baseline", source, ""), ("debug", debug_source, " /Z7")]:
        rsp = out / (label + ".rsp")
        rsp.write_text(normal_flags.strip() + extra + "\n", encoding="utf-8")
        manifest = compile_source(input_source, out / (label + ".obj"), rsp, source.parent)
        manifest["source_sha256"] = digest(input_source)
        manifest["flags_sha256"] = digest(rsp)
        manifest["compiler_sha256"] = digest(Path(manifest["command"][0]))
        manifests.append(manifest)
    (out / "builds.json").write_text(json.dumps({"debug_source_ref": source_ref, "builds": manifests}, indent=2) + "\n",
                                    encoding="utf-8")
    return out / "baseline.obj", out / "debug.obj"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--group", required=True, help="Configured natural source module")
    parser.add_argument("--object", type=Path, help="Existing VC5 /Z7 object; otherwise compile the configured source")
    parser.add_argument("--baseline-object", type=Path, help="Existing normal object; required with --object")
    parser.add_argument("--debug-source-ref", help="Negative control: compile the debug source from this Git revision")
    parser.add_argument("--cvdump", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True, help="New report directory")
    args = parser.parse_args()
    if bool(args.object) != bool(args.baseline_object):
        parser.error("--object and --baseline-object must appear together")
    if args.object and args.debug_source_ref:
        parser.error("--debug-source-ref requires a fresh compilation")
    module = next((m for m in load_build_modules() if m["name"] == args.group), None)
    if module is None:
        parser.error("unknown group")
    out = args.output_dir.resolve()
    out.mkdir(parents=True, exist_ok=False)
    cvdump = args.cvdump.resolve()
    if args.object:
        object_path = args.object.resolve()
        baseline_path = args.baseline_object.resolve()
    else:
        baseline_path, object_path = compile_pair(module, out, args.debug_source_ref)
    obj = load_coff_object(object_path)
    baseline = load_coff_object(baseline_path)
    original_dump = dump(cvdump, "-s", PINNED / "age1_x1.pdb", out / "original-symbols.txt")
    original_types = dump(cvdump, "-t", PINNED / "age1_x1.pdb", out / "original-types.txt")
    rebuilt_dump = dump(cvdump, "-s", object_path, out / "rebuilt-symbols.txt")
    rebuilt_types = dump(cvdump, "-t", object_path, out / "rebuilt-types.txt")
    image = load_pe_image(PINNED / "empiresx.exe")
    original = parse_scoped_symbols(original_dump, image)
    apply_type_names(original, parse_type_summaries(original_types))
    mark_original_blocks(original_dump, image, original["functions"])
    procedures = parse_object_records(rebuilt_dump, obj)
    apply_type_names({"functions": procedures}, parse_type_summaries(rebuilt_types))
    rows = []
    for va, entry in module["functions"].items():
        try:
            rows.append(audit_function(va, entry, module, baseline, obj,
                                       original["functions"], procedures))
        except (KeyError, ValueError, RuntimeError, OSError) as error:
            rows.append({"va": va, "result": "unknown", "reason": str(error), "variables": []})
    function_counts = Counter(r["result"] for r in rows)
    variable_counts = Counter(v["result"] for r in rows for v in r["variables"])
    source_only_count = sum(len(r.get("source_only_records", [])) for r in rows)
    name_relations = Counter(v["name_relation"] for r in rows for v in r["variables"]
                             if v["result"] in {"conflict", "different_spelling"})
    report = {"schema": 1, "group": args.group, "function_counts": dict(function_counts),
              "variable_counts": dict(variable_counts), "functions": rows,
              "source_only_unknown_count": source_only_count,
              "name_relations": dict(name_relations),
              "inputs": {str(p): digest(p) for p in
                         [PINNED / "age1_x1.pdb", PINNED / "empiresx.exe", object_path, baseline_path, cvdump,
                          Path(__file__).resolve()]},
              "limits": ["Only configured matching functions are eligible.",
                         "Both compiled objects must pass the original function check.",
                         "This pilot refuses lexical blocks and reused names or storage.",
                         "Unresolved types and missing records remain unknown.",
                         "Extra rebuilt records have no confirmed original name.",
                         "A different spelling alone does not prove a wrong variable binding.",
                         "Only S_BPREL32 and S_REGISTER variable records are supported.",
                         "Type-name agreement does not prove complete type-layout equality.",
                         "This check does not prove complete variable lifetimes or game behavior."]}
    (out / "report.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    lines = [f"Local-name record pilot: {args.group}", f"Functions: {dict(function_counts)}",
             f"Original variable records: {dict(variable_counts)}",
             f"Name differences: {dict(name_relations)}",
             f"Extra rebuilt records without original names: {source_only_count}"]
    for row in rows:
        lines.append(f"{row['va']} {row['result']} {row.get('reason', '')}")
        for variable in row["variables"]:
            if variable["result"] != "confirmed":
                expected = variable["original"]
                actual = variable["rebuilt_at_location"]
                lines.append(f"  {expected['name']} {storage(expected)}: {variable['result']}; "
                             f"rebuilt={actual['name'] if actual else '(missing)'}; {variable['reason']}"
                             + (f"; {variable['name_relation']}" if variable.get("name_relation") else ""))
        for extra in row.get("source_only_records", []):
            lines.append(f"  {extra['name']} {storage(extra)}: unknown; no original record at this location")
    text = "\n".join(lines) + "\n"
    (out / "report.txt").write_text(text, encoding="utf-8")
    print(text, end="")
    print(f"Report: {out / 'report.json'}")
    return 1 if function_counts["conflict"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
