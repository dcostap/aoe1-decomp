from __future__ import annotations

import argparse
import csv
import json
import sys
from pathlib import Path

from status_core import (
    build_status_rows,
    filter_status_rows,
    packet_path_for_row,
    sort_status_rows,
    status_counts,
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Query current project function status from live repo state. "
            "Does not read project_full_status.csv unless --from-csv is explicitly supplied."
        )
    )
    corpus = parser.add_mutually_exclusive_group()
    corpus.add_argument("--normal", action="store_true", help="Only normal corpus functions")
    corpus.add_argument("--corpus-bucket", choices=["normal", "parent_owned_fragment", "toolchain_supplied", "asm_special", "asm_region"], help="Only this corpus bucket")

    source = parser.add_mutually_exclusive_group()
    source.add_argument("--unclaimed", action="store_true", help="Only unclaimed functions")
    source.add_argument("--scratch", action="store_true", help="Only scratch functions")
    source.add_argument("--matching", action="store_true", help="Only matching functions")
    source.add_argument("--accepted-drift", action="store_true", help="Only accepted-drift functions")
    source.add_argument("--conflict", action="store_true", help="Only conflict functions")
    source.add_argument("--source-bucket", choices=["matching", "accepted_drift", "scratch", "unclaimed", "conflict"], help="Only this source bucket")

    remaining = parser.add_mutually_exclusive_group()
    remaining.add_argument("--remaining", action="store_true", help="Only remaining normal functions (scratch/unclaimed/conflict)")
    remaining.add_argument("--done", action="store_true", help="Only non-remaining functions")

    blockers = parser.add_mutually_exclusive_group()
    blockers.add_argument("--no-blockers", action="store_true", help="Exclude functions with BLOCKER notes")
    blockers.add_argument("--blockers", action="store_true", help="Only functions with BLOCKER notes")

    parser.add_argument("--va", help="Show one VA, e.g. 0047A3A0")
    parser.add_argument("--source", help="Filter by PDB source file/path substring, e.g. Pnl_pic.cpp")
    parser.add_argument("--query", "-q", help="Whitespace-token search over VA/name/source/path/notes")
    parser.add_argument("--min-size", type=int, help="Minimum function size in bytes")
    parser.add_argument("--max-size", type=int, help="Maximum function size in bytes")

    sort = parser.add_mutually_exclusive_group()
    sort.add_argument("--smallest", action="store_true", help="Sort by size ascending")
    sort.add_argument("--largest", action="store_true", help="Sort by size descending")
    parser.add_argument(
        "--sort",
        default="size",
        choices=["size", "bytes", "asm", "va", "name", "source", "bucket", "diff", "edit-diff", "first-mismatch", "remaining-rank"],
        help="Sort key (default: size)",
    )
    parser.add_argument("--desc", action="store_true", help="Descending sort")
    parser.add_argument("--limit", type=int, default=30, help="Maximum rows to print (default: 30; 0 = all)")

    parser.add_argument("--paths", action="store_true", help="Include source and packet paths in table output")
    parser.add_argument("--notes", action="store_true", help="Include blocker/note/next columns in table output")
    parser.add_argument("--json", action="store_true", help="Emit JSON rows")
    parser.add_argument("--csv", action="store_true", help="Emit CSV rows")
    parser.add_argument("--summary", action="store_true", help="Print bucket summary instead of rows")
    parser.add_argument(
        "--from-csv",
        type=Path,
        help="Explicit stale/fast mode: read an existing generated status CSV instead of live repo state",
    )
    parser.add_argument(
        "--with-preview",
        action="store_true",
        help="Include source_preview while building live rows. Slower and usually unnecessary for CLI queries.",
    )
    return parser.parse_args()


def load_rows(args: argparse.Namespace) -> list[dict[str, str]]:
    if args.from_csv:
        with args.from_csv.open("r", encoding="utf-8", errors="replace", newline="") as handle:
            return list(csv.DictReader(handle))
    return build_status_rows(include_source_preview=args.with_preview)


def source_bucket_from_args(args: argparse.Namespace) -> str | None:
    if args.source_bucket:
        return args.source_bucket
    if args.unclaimed:
        return "unclaimed"
    if args.scratch:
        return "scratch"
    if args.matching:
        return "matching"
    if args.accepted_drift:
        return "accepted_drift"
    if args.conflict:
        return "conflict"
    return None


def corpus_bucket_from_args(args: argparse.Namespace) -> str | None:
    if args.corpus_bucket:
        return args.corpus_bucket
    if args.normal:
        return "normal"
    return None


def remaining_from_args(args: argparse.Namespace) -> bool | None:
    if args.remaining:
        return True
    if args.done:
        return False
    return None


def sort_from_args(args: argparse.Namespace) -> tuple[str, bool]:
    if args.smallest:
        return "size", False
    if args.largest:
        return "size", True
    return args.sort, args.desc


def limited(rows: list[dict[str, str]], limit: int) -> list[dict[str, str]]:
    if limit and limit > 0:
        return rows[:limit]
    return rows


def print_summary(rows: list[dict[str, str]]) -> None:
    counts = status_counts(rows)
    total_bytes = sum(int(row.get("size_bytes") or 0) for row in rows)
    remaining_bytes = sum(int(row.get("size_bytes") or 0) for row in rows if row.get("is_remaining") == "yes")
    print(f"rows={len(rows)} bytes={total_bytes} remaining_bytes={remaining_bytes}")
    print(
        "source: "
        f"matching={counts['matching']} "
        f"accepted_drift={counts['accepted_drift']} "
        f"scratch={counts['scratch']} "
        f"unclaimed={counts['unclaimed']} "
        f"conflict={counts['conflict']}"
    )
    print(
        "corpus: "
        f"normal={counts['normal']} "
        f"parent_owned_fragment={counts['parent_owned_fragment']} "
        f"toolchain_supplied={counts['toolchain_supplied']} "
        f"asm_special={counts['asm_special']} "
        f"asm_region={counts['asm_region']}"
    )


def emit_csv(rows: list[dict[str, str]]) -> None:
    if not rows:
        return
    writer = csv.DictWriter(sys.stdout, fieldnames=list(rows[0].keys()), extrasaction="ignore", lineterminator="\n")
    writer.writeheader()
    writer.writerows(rows)


def table_columns(args: argparse.Namespace) -> list[tuple[str, str, int]]:
    cols = [
        ("size", "size_bytes", 6),
        ("asm", "asm_lines", 5),
        ("VA", "va", 10),
        ("bucket", "source_bucket", 15),
        ("corpus", "corpus_bucket", 22),
        ("name", "name", 36),
        ("pdb_source", "pdb_source_file", 20),
    ]
    if args.paths:
        cols.extend([
            ("source_path", "source_path", 46),
            ("packet", "packet_path", 56),
        ])
    if args.notes:
        cols.extend([
            ("blocker", "source_blocker", 28),
            ("note", "source_note", 36),
            ("next", "source_next", 36),
        ])
    return cols


def clipped(value: str, width: int) -> str:
    text = str(value or "")
    if len(text) <= width:
        return text
    if width <= 1:
        return text[:width]
    return text[: width - 1] + "…"


def emit_table(rows: list[dict[str, str]], args: argparse.Namespace, total_before_limit: int) -> None:
    if args.paths:
        for row in rows:
            row.setdefault("packet_path", packet_path_for_row(row))
    cols = table_columns(args)
    header = " ".join(label.ljust(width) for label, _field, width in cols)
    print(header)
    print("-" * len(header))
    for row in rows:
        print(" ".join(clipped(row.get(field, ""), width).ljust(width) for _label, field, width in cols))
    if args.limit and total_before_limit > len(rows):
        print(f"... showing {len(rows)} of {total_before_limit} rows (use --limit 0 for all)")


def main() -> None:
    args = parse_args()
    rows = load_rows(args)
    rows = filter_status_rows(
        rows,
        corpus_bucket=corpus_bucket_from_args(args),
        source_bucket=source_bucket_from_args(args),
        remaining=remaining_from_args(args),
        no_blockers=args.no_blockers,
        blockers_only=args.blockers,
        pdb_source_file=args.source,
        query=args.query,
        min_size=args.min_size,
        max_size=args.max_size,
        va=args.va,
    )

    if args.summary:
        print_summary(rows)
        return

    sort_key, descending = sort_from_args(args)
    rows = sort_status_rows(rows, sort=sort_key, descending=descending)
    total_before_limit = len(rows)
    rows = limited(rows, args.limit)

    if args.json:
        print(json.dumps(rows, ensure_ascii=False, indent=2))
    elif args.csv:
        emit_csv(rows)
    else:
        emit_table(rows, args, total_before_limit)


if __name__ == "__main__":
    main()
