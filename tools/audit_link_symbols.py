"""Find possible declaration conflicts in a failed executable link."""

from __future__ import annotations

import argparse
import csv
import json
import re
import struct
from collections import defaultdict
from pathlib import Path

from coff import load_coff_object
import pefile
from common import REPO_ROOT, load_pdb_function_source_map, repo_path


def decorated_name(diagnostic: str) -> str:
    match = re.search(r"\((\?[^ ]+)\)$", diagnostic)
    return match[1] if match else diagnostic


def symbol_key(name: str) -> str:
    # This is a search key, not ABI evidence and never a link alias.
    if name.startswith("?"):
        return name.split("@@", 1)[0].lstrip("?").lower()
    return re.sub(r"@\d+$", "", name.lstrip("_")).lower()


def main() -> int:
    parser = argparse.ArgumentParser(description="Find possible declaration conflicts in a failed executable link.")
    parser.add_argument("--report", required=True, type=Path, help="build_executable.py report.json")
    args = parser.parse_args()
    report_path = args.report.resolve()
    if not report_path.is_relative_to((REPO_ROOT / "build").resolve()):
        parser.error("Report must be under build/.")
    report = json.loads(report_path.read_text(encoding="utf-8"))
    pdb = load_pdb_function_source_map()
    pdb_names = defaultdict(list)
    for va, entry in pdb.items():
        pdb_names[entry.get("symbol_name", "")].append(va)
    definitions = defaultdict(set)
    for source in report["sources"]:
        if not source["compiled"]:
            continue
        for symbol in load_coff_object(Path(source["object"])).symbols:
            if symbol.storage_class == 2 and symbol.section_number > 0:
                definitions[symbol_key(symbol.name)].add((symbol.name, source["source"]))
    rows = []
    original = pefile.PE(str(repo_path(report["config"]["original"])))
    for diagnostic, callers in report["link"]["unresolved"].items():
        symbol = decorated_name(diagnostic)
        candidates = sorted(definitions[symbol_key(symbol)])
        original_va = ""
        forward_target = ""
        if symbol.startswith("??1"):
            class_name = symbol[3:].split("@@", 1)[0]
            addresses = pdb_names[f"{class_name}::~{class_name}"]
            if len(addresses) == 1:
                original_va = addresses[0]
                va = int(original_va, 16)
                data = original.get_data(va - original.OPTIONAL_HEADER.ImageBase, 5)
                if len(data) == 5 and data[0] == 0xE9:
                    target = va + 5 + struct.unpack("<i", data[1:])[0]
                    forward_target = f"{target:08X} {pdb.get(f'{target:08X}', {}).get('symbol_name', '')}"
        rows.append(dict(symbol=symbol, diagnostic=diagnostic,
                         callers="; ".join(callers),
                         candidates="; ".join(f"{s} [{p}]" for s, p in candidates),
                         original_va=original_va, original_forward_target=forward_target,
                         classification="possible_declaration_conflict" if candidates else "no_object_definition"))
    original.close()
    output = report_path.with_name("unresolved.csv")
    with output.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, ["symbol", "classification", "callers", "candidates",
                                        "original_va", "original_forward_target", "diagnostic"])
        writer.writeheader()
        writer.writerows(rows)
    print(f"Unresolved symbols: {len(rows)}")
    print(f"Possible declaration conflicts: {sum(bool(r['candidates']) for r in rows)}")
    print(f"Report: {output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
