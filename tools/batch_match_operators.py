from __future__ import annotations

import csv
import glob
import re
import subprocess
import sys
from pathlib import Path

from common import function_slug, load_functions, repo_path

REPO_ROOT = Path(__file__).resolve().parent.parent
SCRATCH_DIR = REPO_ROOT / "src" / "scratch"
MATCHING_DIR = REPO_ROOT / "src" / "matching"
ACCEPTED_DRIFT_DIR = REPO_ROOT / "src" / "accepted_drift"
VERIFIED_LOGIC_DIR = REPO_ROOT / "src" / "verified_logic"

DIRECT_COMPARE_PATTERN = [
    re.compile(r"mov eax,\[esp\+4\]$"),
    re.compile(r"mov edx,\[esp\+8\]$"),
    re.compile(r"push esi$"),
    re.compile(r"mov ecx,\[eax\+([0-9A-Fa-f]+)(?:h)?\]$"),
    re.compile(r"mov esi,\[edx\+([0-9A-Fa-f]+)(?:h)?\]$"),
    re.compile(r"xor eax,eax$"),
    re.compile(r"cmp ecx,esi$"),
    re.compile(r"set([a-z]+) al$"),
    re.compile(r"pop esi$"),
    re.compile(r"ret$"),
]

WRAPPER_NE_PATTERN = [
    re.compile(r"mov eax,\[esp\+8\]$"),
    re.compile(r"mov ecx,\[esp\+4\]$"),
    re.compile(r"push eax$"),
    re.compile(r"push ecx$"),
    re.compile(r"call ([0-9A-Fa-f]+)h$"),
    re.compile(r"add esp,8$"),
    re.compile(r"neg eax$"),
    re.compile(r"sbb eax,eax$"),
    re.compile(r"inc eax$"),
    re.compile(r"ret$"),
]

SETCC_TO_OPERATOR = {
    "e": "==",
    "ne": "!=",
    "l": "<",
    "g": ">",
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


def read_packet_text(va: str) -> str | None:
    packet_path = packet_path_for_va(va)
    if packet_path is None:
        return None
    return packet_path.read_text(encoding="utf-8")


def parse_original_asm(packet_text: str) -> list[str]:
    if "=== OriginalAsm ===" not in packet_text:
        return []
    sec = packet_text.split("=== OriginalAsm ===", 1)[1]
    if "===" in sec:
        sec = sec.split("===", 1)[0]

    instrs: list[str] = []
    for line in sec.strip().splitlines():
        line = line.split(";", 1)[0].strip()
        if not line:
            continue
        if len(line) >= 17 and line[8] == "-":
            continue
        parts = line.split()
        if len(parts) < 3:
            continue
        try:
            bytes.fromhex(parts[1])
        except ValueError:
            continue
        instrs.append(" ".join(parts[2:]))
    return instrs


def extract_class_name(packet_text: str) -> str | None:
    if "=== GhidraListingExcerpt ===" not in packet_text:
        return None
    sec = packet_text.split("=== GhidraListingExcerpt ===", 1)[1]
    match = re.search(r"operator[=!<>]+\(class\s+(\w+)\s+const\s+&,class\s+\1\s+const\s+&\)", sec)
    if match:
        return match.group(1)
    match = re.search(r"operator[=!<>]+\((\w+) \* param_1,(\w+) \* param_2\)", sec)
    if match and match.group(1) == match.group(2):
        return match.group(1)
    return None


def make_struct(class_name: str, field_offset: int) -> str:
    if field_offset == 0:
        return (
            f"class {class_name} {{\n"
            "public:\n"
            "    int value;\n"
            "};\n"
        )
    return (
        f"class {class_name} {{\n"
        "public:\n"
        f"    char gap_00[0x{field_offset:X}];\n"
        "    int value;\n"
        "};\n"
    )


def generate_direct_compare_source(packet_text: str) -> str | None:
    instrs = parse_original_asm(packet_text)
    if len(instrs) != len(DIRECT_COMPARE_PATTERN):
        return None

    captures: list[re.Match[str]] = []
    for instr, pattern in zip(instrs, DIRECT_COMPARE_PATTERN):
        match = pattern.fullmatch(instr)
        if not match:
            return None
        captures.append(match)

    lhs_offset = int(captures[3].group(1), 16)
    rhs_offset = int(captures[4].group(1), 16)
    if lhs_offset != rhs_offset:
        return None

    condition = captures[7].group(1)
    op = SETCC_TO_OPERATOR.get(condition)
    if op is None:
        return None

    class_name = extract_class_name(packet_text)
    if class_name is None:
        return None

    return (
        f"{make_struct(class_name, lhs_offset)}\n"
        f"int __cdecl operator{op}({class_name} const& lhs, {class_name} const& rhs) {{\n"
        f"    return lhs.value {op} rhs.value;\n"
        "}\n"
    )


def generate_wrapper_ne_source(packet_text: str, target_record: dict[str, str]) -> str | None:
    instrs = parse_original_asm(packet_text)
    if len(instrs) != len(WRAPPER_NE_PATTERN):
        return None

    captures: list[re.Match[str]] = []
    for instr, pattern in zip(instrs, WRAPPER_NE_PATTERN):
        match = pattern.fullmatch(instr)
        if not match:
            return None
        captures.append(match)

    target_va = captures[4].group(1).upper().zfill(8)
    if target_va != target_record["va"].upper():
        return None
    if target_record["name"] != "operator==":
        return None

    class_name = extract_class_name(packet_text)
    if class_name is None:
        return None

    return (
        f"class {class_name};\n\n"
        f"int __cdecl operator==({class_name} const& lhs, {class_name} const& rhs);\n\n"
        f"int __cdecl operator!=({class_name} const& lhs, {class_name} const& rhs) {{\n"
        "    return !operator==(lhs, rhs);\n"
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
    all_functions = {row["va"].upper(): row for row in load_functions()}
    status_rows = load_status_rows()

    matched = 0
    failed = 0
    skipped = 0

    for row in status_rows:
        if row["is_remaining"] != "yes":
            continue
        if not row["name"].startswith("operator"):
            continue

        record = all_functions.get(row["va"].upper())
        if record is None:
            skipped += 1
            continue

        packet_text = read_packet_text(record["va"].upper())
        if packet_text is None:
            skipped += 1
            continue

        source = generate_direct_compare_source(packet_text)
        if source is None:
            call_match = re.search(r"call\s+([0-9A-Fa-f]+)h", "\n".join(parse_original_asm(packet_text)))
            if call_match:
                target_record = all_functions.get(call_match.group(1).upper().zfill(8))
                if target_record is not None:
                    source = generate_wrapper_ne_source(packet_text, target_record)

        if source is None:
            continue

        slug = function_slug(record)
        scratch_path = SCRATCH_DIR / f"{slug}.cpp"
        matching_path = MATCHING_DIR / f"{slug}.cpp"
        accepted_drift_path = ACCEPTED_DRIFT_DIR / f"{slug}.cpp"
        verified_logic_path = VERIFIED_LOGIC_DIR / f"{slug}.cpp"
        if accepted_drift_path.exists():
            print(f"[skip] {record['va']} already in accepted_drift")
            skipped += 1
            continue
        if verified_logic_path.exists():
            print(f"[skip] {record['va']} already in verified_logic")
            skipped += 1
            continue

        scratch_path.write_text(source, encoding="utf-8")
        print(f"\n[operator] {record['va']} {record['name']}")
        print(f"  wrote {scratch_path}")

        if check_function(record["va"]):
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
    print("OPERATOR BATCH RESULTS")
    print("============================================================")
    print(f"Matched: {matched}")
    print(f"Failed:  {failed}")
    print(f"Skipped: {skipped}")


if __name__ == "__main__":
    main()
