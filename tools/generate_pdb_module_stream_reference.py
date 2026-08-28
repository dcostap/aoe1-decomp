"""Export one original PDB module symbol stream as reviewed inventory evidence."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
from pathlib import Path

from common import PDB_INVENTORY_DIR, load_binaries, parse_hex, repo_path


MODULE_HEADER = re.compile(r'^\*\* Module: "(?P<path>.+)"$', re.MULTILINE)
PROCEDURE = re.compile(
    r"^\([0-9A-F]+\) S_GPROC32: \[(?P<section>[0-9A-F]{4}):"
    r"(?P<offset>[0-9A-F]{8})\], Cb: [0-9A-F]+, Type: .+, (?P<name>.+)$",
    re.MULTILINE,
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Export one original PDB module symbol stream with cvdump."
    )
    parser.add_argument("--cvdump", type=Path, required=True, help="cvdump.exe path")
    parser.add_argument(
        "--module-index",
        required=True,
        help="PDB module index in decimal or hexadecimal, for example 0x27",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=PDB_INVENTORY_DIR / "module_streams",
        help="Output directory for the raw dump and JSON evidence",
    )
    return parser.parse_args()


def _sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def _run(cvdump: Path, *args: str) -> str:
    result = subprocess.run(
        [str(cvdump), *args], capture_output=True, text=True, check=False
    )
    if result.returncode != 0:
        raise RuntimeError(result.stdout + result.stderr)
    return result.stdout


def _procedures(raw_dump: str, image_base: int) -> list[dict[str, str]]:
    procedures: list[dict[str, str]] = []
    for match in PROCEDURE.finditer(raw_dump):
        section = match.group("section")
        offset = match.group("offset")
        va = ""
        if section == "0001":
            va = f"{image_base + int(offset, 16):08X}"
        procedures.append(
            {
                "va": va,
                "section": section,
                "offset": offset,
                "name": match.group("name").strip(),
            }
        )
    return procedures


def main() -> int:
    args = parse_args()
    module_index = int(args.module_index, 0)
    if module_index < 1:
        raise SystemExit("module index must be positive")
    cvdump = args.cvdump.resolve()
    if not cvdump.is_file():
        raise SystemExit(f"Missing cvdump: {cvdump}")

    binaries = load_binaries()
    pdb_path = repo_path(str(binaries["original_pdb"]))
    image_base = parse_hex(str(binaries["image_base"]))
    if image_base is None:
        raise SystemExit("config/binaries.json has invalid image_base")
    module_selector = f"{module_index:03d}"
    raw_dump = _run(cvdump, "-s", f"-M{module_selector}", str(pdb_path))
    header = MODULE_HEADER.search(raw_dump)
    if header is None:
        raise SystemExit(f"cvdump did not return module {module_index:04X}")

    output_dir = args.output_dir.resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    stem = f"{module_index:04X}_{Path(header.group('path')).stem.lower()}"
    raw_path = output_dir / f"{stem}.txt"
    json_path = output_dir / f"{stem}.json"
    raw_path.write_text(raw_dump.rstrip() + "\n", encoding="utf-8", newline="\n")

    evidence = {
        "schema": 1,
        "pdb_path": str(binaries["original_pdb"]).replace("\\", "/"),
        "pdb_sha256": _sha256(pdb_path),
        "module_index": f"{module_index:04X}",
        "module_selector_decimal": module_selector,
        "object_path": header.group("path"),
        "raw_dump": raw_path.relative_to(repo_path(".")).as_posix(),
        "raw_dump_sha256": _sha256(raw_path),
        "procedure_count": len(_procedures(raw_dump, image_base)),
        "procedures": _procedures(raw_dump, image_base),
    }
    json_path.write_text(json.dumps(evidence, indent=2) + "\n", encoding="utf-8")
    print(f"Wrote {raw_path}")
    print(f"Wrote {json_path}")
    print(f"Procedures: {evidence['procedure_count']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
