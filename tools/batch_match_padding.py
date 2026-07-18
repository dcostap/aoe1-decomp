from __future__ import annotations

import csv
import glob
import subprocess
import sys
from pathlib import Path

from common import function_slug, load_functions, repo_path

REPO_ROOT = Path(__file__).resolve().parent.parent
SCRATCH_DIR = REPO_ROOT / "src" / "scratch"
MATCHING_DIR = REPO_ROOT / "src" / "matching"
ACCEPTED_DRIFT_DIR = REPO_ROOT / "src" / "accepted_drift"

ALLOWED_INSTRUCTIONS = {
    "nop",
    "mov edi,edi",
    "mov eax,eax",
}


def load_status_rows() -> list[dict[str, str]]:
    with (REPO_ROOT / "project_full_status.csv").open("r", encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def packet_path_for_va(va: str) -> Path | None:
    prefix = va[:4]
    matches = glob.glob(str(REPO_ROOT / f"inventory/functions/{prefix}/{va}*"))
    if not matches:
        return None
    return Path(matches[0])


def parse_packet(packet_path: Path) -> tuple[list[str], list[int]]:
    text = packet_path.read_text(encoding="utf-8")
    if "=== OriginalAsm ===" not in text:
        return [], []
    sec = text.split("=== OriginalAsm ===", 1)[1]
    if "===" in sec:
        sec = sec.split("===", 1)[0]

    instrs: list[str] = []
    raw_bytes: list[int] = []
    for line in sec.strip().splitlines():
        line = line.split(";", 1)[0].strip()
        if not line:
            continue
        if len(line) >= 17 and line[8] == "-":
            continue
        parts = line.split()
        if len(parts) < 3:
            continue
        hex_blob = parts[1]
        try:
            raw_bytes.extend(bytes.fromhex(hex_blob))
        except ValueError:
            continue
        instrs.append(" ".join(parts[2:]))
    return instrs, raw_bytes


def is_padding_only(instrs: list[str]) -> bool:
    return bool(instrs) and all(instr in ALLOWED_INSTRUCTIONS for instr in instrs)


def make_source(instrs: list[str], raw_bytes: list[int]) -> str:
    emits = "\n".join(f"    __asm _emit 0x{byte:02X}" for byte in raw_bytes)
    asm_note = " ; ".join(instrs)
    return (
        "// PSEUDO-FUNCTION: padding-only exception.\n"
        f"// ORIGINAL ASM: {asm_note}\n"
        "__declspec(naked) void padding_pseudo_function(void) {\n"
        f"{emits}\n"
        "}\n"
    )


def check_function(va: str) -> bool:
    result = subprocess.run(
        [sys.executable, str(REPO_ROOT / "tools" / "check_function.py"), "--va", va, "--no-history"],
        capture_output=True,
        text=True,
    )
    sys.stdout.write(result.stdout)
    sys.stderr.write(result.stderr)
    return result.returncode == 0


def main() -> None:
    status_rows = load_status_rows()
    all_functions = {row["va"].upper(): row for row in load_functions()}

    matched = 0
    skipped = 0
    failed = 0

    for row in sorted(status_rows, key=lambda r: (int(r["size_bytes"]), r["va"])):
        if row["is_remaining"] != "yes":
            continue

        va = row["va"].upper()
        record = all_functions.get(va)
        if record is None:
            skipped += 1
            continue

        slug = function_slug(record)
        matching_path = MATCHING_DIR / f"{slug}.cpp"
        accepted_drift_path = ACCEPTED_DRIFT_DIR / f"{slug}.cpp"
        if accepted_drift_path.exists():
            print(f"[skip] {va} already in accepted_drift")
            skipped += 1
            continue
        if matching_path.exists():
            continue

        packet_path = packet_path_for_va(va)
        if packet_path is None:
            skipped += 1
            continue

        instrs, raw_bytes = parse_packet(packet_path)
        if not is_padding_only(instrs):
            continue

        scratch_path = SCRATCH_DIR / f"{slug}.cpp"
        source = make_source(instrs, raw_bytes)
        scratch_path.write_text(source, encoding="utf-8")

        print(f"\n[padding] {va} {row['name']} ({row['size_bytes']}B) :: {' ; '.join(instrs)}")
        if check_function(va):
            if matching_path.exists():
                scratch_path.unlink(missing_ok=True)
            else:
                scratch_path.rename(matching_path)
            print(f"  OK MATCH -> {matching_path}")
            matched += 1
        else:
            print(f"  XX MISMATCH -> kept in scratch: {scratch_path}")
            failed += 1

    print("\n============================================================")
    print("PADDING BATCH RESULTS")
    print("============================================================")
    print(f"Matched: {matched}")
    print(f"Failed:  {failed}")
    print(f"Skipped: {skipped}")


if __name__ == "__main__":
    main()
