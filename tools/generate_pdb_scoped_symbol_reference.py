from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
from pathlib import Path

from common import PDB_INVENTORY_DIR, load_binaries, load_pe_image, repo_path
from pdb_scoped_symbols import apply_type_names, parse_scoped_symbols, parse_type_summaries


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate a procedure-scoped PDB symbol index from cvdump -s."
    )
    parser.add_argument("--cvdump", type=Path, help="cvdump.exe path")
    parser.add_argument(
        "--input-dump",
        type=Path,
        help="Use an existing full cvdump -s text dump instead of running cvdump",
    )
    parser.add_argument(
        "--input-types",
        type=Path,
        help="Optional existing full cvdump -t text dump for complex type resolution",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=PDB_INVENTORY_DIR / "scoped_symbols.json",
        help="Output JSON path",
    )
    args = parser.parse_args()
    if bool(args.cvdump) == bool(args.input_dump):
        parser.error("select exactly one of --cvdump or --input-dump")
    if args.input_types and not args.input_dump:
        parser.error("--input-types requires --input-dump")
    return args


def _sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def main() -> int:
    args = parse_args()
    binaries = load_binaries()
    pdb_path = repo_path(str(binaries["original_pdb"]))
    image = load_pe_image(repo_path(str(binaries["original_exe"])))

    if args.input_dump:
        dump_path = args.input_dump.resolve()
        raw_dump = dump_path.read_text(encoding="utf-8", errors="replace")
        dump_source = str(dump_path)
        dump_sha256 = _sha256(dump_path)
        raw_types = (
            args.input_types.resolve().read_text(encoding="utf-8", errors="replace")
            if args.input_types
            else ""
        )
    else:
        cvdump = args.cvdump.resolve()
        if not cvdump.is_file():
            raise SystemExit(f"Missing cvdump: {cvdump}")
        result = subprocess.run(
            [str(cvdump), "-s", str(pdb_path)],
            capture_output=True,
            text=True,
            check=False,
        )
        if result.returncode != 0:
            raise SystemExit(result.stdout + result.stderr)
        raw_dump = result.stdout
        dump_source = "cvdump -s"
        dump_sha256 = hashlib.sha256(raw_dump.encode("utf-8")).hexdigest()
        type_result = subprocess.run(
            [str(cvdump), "-t", str(pdb_path)],
            capture_output=True,
            text=True,
            check=False,
        )
        if type_result.returncode != 0:
            raise SystemExit(type_result.stdout + type_result.stderr)
        raw_types = type_result.stdout

    payload = parse_scoped_symbols(raw_dump, image)
    type_summaries = parse_type_summaries(raw_types) if raw_types else {}
    apply_type_names(payload, type_summaries)
    payload.update(
        {
            "pdb_path": str(binaries["original_pdb"]).replace("\\", "/"),
            "pdb_sha256": _sha256(pdb_path),
            "dump_source": dump_source,
            "dump_sha256": dump_sha256,
            "type_record_count": len(type_summaries),
        }
    )
    output = args.output.resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    counts = payload["counts"]
    print(f"Wrote {output}")
    print(
        "Procedures: {procedures}; function statics: {function_statics}; "
        "stack symbols: {stack_symbols}; register symbols: {register_symbols}".format(**counts)
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
