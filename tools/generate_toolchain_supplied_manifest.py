from __future__ import annotations

import argparse
import csv
import re
from collections import defaultdict
from pathlib import Path

import pefile

from common import (
    REPO_ROOT,
    classify_corpus_bucket,
    load_asm_special_function_names,
    load_asm_special_regions,
    load_binaries,
    load_functions,
    load_toolchain_supplied_regions,
    repo_path,
)


SAFE_EXACT_RUNTIME_NAMES = {
    "abort",
    "atof",
    "ctime",
    "fflush",
    "fwrite",
    "getenv",
    "gmtime",
    "localtime",
    "mbtowc",
    "isupper",
    "isspace",
    "memcpy",
    "memmove",
    "memset",
    "qsort",
    "raise",
    "realloc",
    "strtok",
    "time",
    "tolower",
    "toupper",
    "ungetc",
    "wctomb",
    "wcstombs",
    "writepad",
    "__CallSettingFrame@12",
    "__CxxRestoreUnhandledExceptionFilter",
    "__CxxSetUnhandledExceptionFilter",
    "__CxxUnhandledExceptionFilter",
    "__FillZeroMan",
    "__IncMan",
    "__IsZeroMan",
    "__NLG_Notify",
    "__NLG_Notify1",
    "__RoundMan",
    "__ShrMan",
    "__ZeroTail",
    "__ArrayUnwind",
    "__allshl",
    "__atodbl",
    "__atoflt",
    "__atoldbl",
    "__aulldiv",
    "__aullrem",
    "__callnewh",
    "__clearfp",
    "__control87",
    "__controlfp",
    "__except1",
    "__except2",
    "__except_handler3",
    "__fcloseall",
    "__fpreset",
    "__fptrap",
    "__fptostr",
    "__get_sbh_threshold",
    "__global_unwind2",
    "__heap_alloc",
    "__heap_init",
    "__heap_term",
    "__ioterm",
    "__input",
    "__ioinit",
    "__isindst",
    "__ld12cvt",
    "__ld12tod",
    "__ld12tof",
    "__ld12told",
    "__local_unwind2",
    "__mbbtype",
    "__openfile",
    "__output",
    "__seh_longjmp_unwind@4",
    "__set_sbh_threshold",
    "__setmode",
    "__sopen",
    "__statusfp",
    "__tzset",
    "___CxxFrameHandler",
    "___CxxLongjmpUnwind@4",
    "___FrameUnwindToState",
    "___InternalCxxFrameHandler",
    "___dtold",
    "___endstdio",
    "___initstdio",
    "___isascii",
    "___iscsym",
    "___iscsymf",
    "___toascii",
    "__fltout",
    "__CopyMan",
    "__tolower",
    "__toupper",
    "_CallCatchBlock2",
    "_CallMemberFunction0",
    "_CallMemberFunction1",
    "_CallMemberFunction2",
    "_DestructExceptionObject",
    "_UnwindNestedFrames",
    "_ValidateExecute",
    "_inconsistency",
    "_isalnum",
    "_iscntrl",
    "_isdigit",
    "_isgraph",
    "_islower",
    "_isprint",
    "_ispunct",
    "_isxdigit",
    "_query_new_handler",
    "_set_new_handler",
    "signal",
    "`eh_vector_constructor_iterator'",
    "`eh_vector_destructor_iterator'",
}

SAFE_RUNTIME_PREFIXES = (
    "___sbh_",
    "___crt",
    "___ld12",
    "___strgtold",
    "__cfto",
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate a high-confidence toolchain/lib-supplied manifest.")
    parser.add_argument(
        "--output",
        type=Path,
        default=REPO_ROOT / "config" / "toolchain_supplied_functions.txt",
        help="Manifest output path.",
    )
    parser.add_argument(
        "--report",
        type=Path,
        default=REPO_ROOT / "build" / "toolchain_supplied_candidates.tsv",
        help="Candidate report output path.",
    )
    parser.add_argument(
        "--hidden-label-report",
        type=Path,
        default=REPO_ROOT / "build" / "toolchain_hidden_label_safe_candidates.tsv",
        help="Safe hidden-label candidate report output path.",
    )
    parser.add_argument(
        "--hidden-label-unhandled-report",
        type=Path,
        default=REPO_ROOT / "build" / "toolchain_hidden_label_unhandled_candidates.tsv",
        help="Unhandled safe hidden-label candidate report output path.",
    )
    return parser.parse_args()


def normalize_import_name(name: str) -> str:
    normalized = name
    if normalized.startswith("_"):
        normalized = normalized[1:]
    normalized = re.sub(r"@\d+$", "", normalized)
    return normalized


def load_imported_symbol_names() -> set[str]:
    binaries = load_binaries()
    original_exe = repo_path(binaries["original_exe"])
    pe = pefile.PE(str(original_exe))
    names: set[str] = set()
    for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        for imported in entry.imports:
            if imported.name:
                names.add(imported.name.decode(errors="replace"))
    return names


def hidden_label_packet_path(record: dict[str, str]) -> Path:
    return REPO_ROOT / "inventory" / "functions" / record["va"][:4] / f"{record['slug']}.txt"


HIDDEN_LABEL_RE = re.compile(r"^\s+(_[A-Za-z0-9_@$?]+)\s*(?:XREF.*)?$")


def extract_hidden_labels(record: dict[str, str]) -> list[str]:
    path = hidden_label_packet_path(record)
    if not path.exists():
        return []

    labels: list[str] = []
    in_listing = False
    for raw_line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if raw_line.startswith("=== GhidraListingExcerpt ==="):
            in_listing = True
            continue
        if in_listing and raw_line.startswith("=== "):
            break
        if not in_listing:
            continue
        match = HIDDEN_LABEL_RE.match(raw_line)
        if match is None:
            continue
        label = match.group(1)
        if label.startswith("_ASM"):
            continue
        if label not in labels:
            labels.append(label)
    return labels


def runtime_name_matches(label: str, exact_name: str) -> bool:
    if label == exact_name:
        return True
    if label.lstrip("_") == exact_name.lstrip("_"):
        return True
    if normalize_import_name(label) == normalize_import_name(exact_name):
        return True
    return False


def label_matches_safe_runtime_name(label: str) -> bool:
    return any(runtime_name_matches(label, exact_name) for exact_name in SAFE_EXACT_RUNTIME_NAMES)


def label_matches_safe_runtime_prefix(label: str) -> bool:
    normalized_label = normalize_import_name(label)
    stripped_label = label.lstrip("_")
    for prefix in SAFE_RUNTIME_PREFIXES:
        if label.startswith(prefix):
            return True
        if stripped_label.startswith(prefix.lstrip("_")):
            return True
        if normalized_label.startswith(normalize_import_name(prefix)):
            return True
    return False


def label_matches_imported_symbol(label: str, imported_symbol_names: set[str]) -> bool:
    normalized_label = normalize_import_name(label)
    return normalized_label in imported_symbol_names


def collect_candidates() -> tuple[list[dict[str, str]], list[dict[str, str]], list[dict[str, str]], list[dict[str, str]]]:
    imported_symbol_names = load_imported_symbol_names()
    records = load_functions()

    manifest_candidates: dict[str, dict[str, str]] = {}
    report_rows: list[dict[str, str]] = []
    hidden_label_rows: list[dict[str, str]] = []

    for record in records:
        name = record["name"]
        reasons: list[str] = []

        if name.startswith("_") and normalize_import_name(name) in imported_symbol_names:
            reasons.append("dll-import-thunk")

        if name in SAFE_EXACT_RUNTIME_NAMES:
            reasons.append("runtime-exact-name")
        elif any(name.startswith(prefix) for prefix in SAFE_RUNTIME_PREFIXES):
            reasons.append("runtime-prefix")

        if reasons:
            reason = ",".join(reasons)
            report_rows.append(
                {
                    "va": record["va"],
                    "name": name,
                    "size_bytes": record["size_bytes"],
                    "calling_convention": record["calling_convention"],
                    "pdb_source_file": record.get("pdb_source_file", ""),
                    "reason": reason,
                }
            )

            manifest_candidates.setdefault(
                name,
                {
                    "name": name,
                    "reason": reason,
                },
            )

        if not (name.startswith("FUN_") or name.startswith("case")):
            continue

        for hidden_label in extract_hidden_labels(record):
            hidden_reasons: list[str] = []
            if label_matches_safe_runtime_name(hidden_label):
                hidden_reasons.append("hidden-runtime-exact-name")
            if label_matches_safe_runtime_prefix(hidden_label):
                hidden_reasons.append("hidden-runtime-prefix")
            if label_matches_imported_symbol(hidden_label, imported_symbol_names):
                hidden_reasons.append("hidden-dll-import-like")
            if not hidden_reasons:
                continue
            hidden_label_rows.append(
                {
                    "va": record["va"],
                    "inventory_name": name,
                    "hidden_label": hidden_label,
                    "size_bytes": record["size_bytes"],
                    "calling_convention": record["calling_convention"],
                    "pdb_source_file": record.get("pdb_source_file", ""),
                    "reason": ",".join(hidden_reasons),
                    "packet_path": str(hidden_label_packet_path(record).relative_to(REPO_ROOT)),
                }
            )

    manifest_rows = sorted(manifest_candidates.values(), key=lambda row: row["name"].lower())
    report_rows.sort(key=lambda row: (row["name"].lower(), row["va"]))
    hidden_label_rows.sort(key=lambda row: (row["hidden_label"].lower(), row["va"]))

    generated_toolchain_names = {row["name"] for row in manifest_rows}
    toolchain_regions = load_toolchain_supplied_regions()
    asm_special_names = load_asm_special_function_names()
    asm_special_regions = load_asm_special_regions()
    records_by_va = {record["va"]: record for record in records}

    hidden_label_unhandled_rows: list[dict[str, str]] = []
    for row in hidden_label_rows:
        record = records_by_va[row["va"]]
        bucket, _ = classify_corpus_bucket(
            record,
            toolchain_supplied_names=generated_toolchain_names,
            toolchain_supplied_regions=toolchain_regions,
            asm_special_names=asm_special_names,
            asm_special_regions=asm_special_regions,
        )
        if bucket == "normal":
            hidden_label_unhandled_rows.append(row)

    return manifest_rows, report_rows, hidden_label_rows, hidden_label_unhandled_rows


def write_manifest(path: Path, rows: list[dict[str, str]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)

    import_names = [row["name"] for row in rows if "dll-import-thunk" in row["reason"]]
    runtime_names = [row["name"] for row in rows if "dll-import-thunk" not in row["reason"]]

    lines = [
        "# High-confidence toolchain/lib-supplied functions.",
        "# These are excluded from the normal manual decomp/matching corpus.",
        "# One exact inventory function name per line.",
        "# Generated by tools/generate_toolchain_supplied_manifest.py.",
        "",
        "# DLL import thunks derived from the original EXE import table.",
    ]
    lines.extend(import_names)
    lines.extend(
        [
            "",
            "# Known VC5 CRT/runtime functions identified by conservative exact-name/prefix rules.",
        ]
    )
    lines.extend(runtime_names)
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_report(path: Path, rows: list[dict[str, str]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=["va", "name", "size_bytes", "calling_convention", "pdb_source_file", "reason"],
            delimiter="\t",
        )
        writer.writeheader()
        writer.writerows(rows)


def write_hidden_label_report(path: Path, rows: list[dict[str, str]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "va",
                "inventory_name",
                "hidden_label",
                "size_bytes",
                "calling_convention",
                "pdb_source_file",
                "reason",
                "packet_path",
            ],
            delimiter="\t",
        )
        writer.writeheader()
        writer.writerows(rows)


def main() -> None:
    args = parse_args()
    manifest_rows, report_rows, hidden_label_rows, hidden_label_unhandled_rows = collect_candidates()
    write_manifest(args.output, manifest_rows)
    write_report(args.report, report_rows)
    write_hidden_label_report(args.hidden_label_report, hidden_label_rows)
    write_hidden_label_report(args.hidden_label_unhandled_report, hidden_label_unhandled_rows)
    print(f"Wrote {args.output}")
    print(f"Wrote {args.report}")
    print(f"Wrote {args.hidden_label_report}")
    print(f"Wrote {args.hidden_label_unhandled_report}")
    reason_counts: dict[str, int] = defaultdict(int)
    for row in report_rows:
        for reason in row["reason"].split(","):
            reason_counts[reason] += 1
    for reason in sorted(reason_counts):
        print(f"{reason}: {reason_counts[reason]}")
    hidden_reason_counts: dict[str, int] = defaultdict(int)
    for row in hidden_label_rows:
        for reason in row["reason"].split(","):
            hidden_reason_counts[reason] += 1
    for reason in sorted(hidden_reason_counts):
        print(f"{reason}: {hidden_reason_counts[reason]}")
    print(f"Total manifest names: {len(manifest_rows)}")
    print(f"Total report rows: {len(report_rows)}")
    print(f"Total hidden-label safe candidates: {len(hidden_label_rows)}")
    print(f"Total hidden-label unhandled candidates: {len(hidden_label_unhandled_rows)}")


if __name__ == "__main__":
    main()
