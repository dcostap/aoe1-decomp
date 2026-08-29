from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from pathlib import Path

from common import REPO_ROOT, compiler_source_path, function_record_by_va, load_functions
from status_core import (
    build_status_rows,
    enrich_status_rows,
    filter_status_rows,
    packet_path_for_row,
    sort_status_rows,
    status_counts,
)
from target_session import (
    classify_next_stage,
    last_positional_improvement,
    load_target_sessions,
    meaningful_probe_count,
    session_claim_count,
    session_is_active,
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=(
            "Query current function status from live repository state.\n"
            "\n"
            "Use this tool before target selection, assignment, or status reporting.\n"
            "Combine one corpus filter, one source-status filter, and optional sorting.\n"
            "Triage and work-history views are for a small result set, not a full dump.\n"
            "\n"
            "BLOCKER semantics:\n"
            "  A BLOCKER is a manual obstacle note in the living source's top comment header.\n"
            "  The tool does not infer ordinary matching obstacles or enforce the note.\n"
            "  A verified-logic source without its required ledger gets an integrity blocker.\n"
            "  A blocker is not a lease, source status, or corpus class.\n"
            "  Combine blocker filters with a source or remaining-work filter.\n"
            "\n"
            "Examples:\n"
            "  python tools/query_project_status.py --va 0047A3A0 --paths --notes --leases\n"
            "  python tools/query_project_status.py --unclaimed --normal --unleased --smallest --limit 12\n"
            "  python tools/query_project_status.py --scratch --normal --work-history --notes --limit 12\n"
            "  python tools/query_project_status.py --logic-review-in-progress --paths\n"
            "  python tools/query_project_status.py --summary --normal\n"
        ),
    )
    corpus = parser.add_mutually_exclusive_group()
    corpus.add_argument("--normal", action="store_true", help="Only normal corpus functions")
    corpus.add_argument("--corpus-bucket", choices=["normal", "padding_only", "compiler_generated", "parent_owned_fragment", "toolchain_supplied", "asm_special", "asm_region"], help="Only this corpus bucket")

    source = parser.add_mutually_exclusive_group()
    source.add_argument("--unclaimed", action="store_true", help="Only unclaimed functions")
    source.add_argument("--scratch", action="store_true", help="Only scratch functions")
    source.add_argument("--matching", action="store_true", help="Only matching functions")
    source.add_argument("--accepted-drift", action="store_true", help="Only accepted-drift functions")
    source.add_argument("--verified-logic", action="store_true", help="Only verified-logic functions")
    source.add_argument("--conflict", action="store_true", help="Only conflict functions")
    source.add_argument("--source-bucket", choices=["matching", "accepted_drift", "verified_logic", "scratch", "unclaimed", "conflict"], help="Only this source bucket")

    remaining = parser.add_mutually_exclusive_group()
    remaining.add_argument("--remaining", action="store_true", help="Only remaining normal functions (scratch/unclaimed/conflict)")
    remaining.add_argument("--done", action="store_true", help="Only non-remaining functions")

    logic_review = parser.add_mutually_exclusive_group()
    logic_review.add_argument("--logic-review", action="store_true", help="Only functions with a logic-review ledger")
    logic_review.add_argument(
        "--logic-review-in-progress",
        action="store_true",
        help="Only scratch functions that have entered logic review",
    )

    blockers = parser.add_mutually_exclusive_group()
    blockers.add_argument("--no-blockers", action="store_true", help="Exclude rows with a parsed top-header BLOCKER note")
    blockers.add_argument("--blockers", action="store_true", help="Only rows with a parsed top-header BLOCKER note")

    leases = parser.add_mutually_exclusive_group()
    leases.add_argument("--unleased", action="store_true", help="Only functions whose translation unit has no active lease")
    leases.add_argument("--active-leases", action="store_true", help="Only functions in an actively leased translation unit")
    parser.add_argument("--owner", help="Only active leases owned by this exact agent/session name")
    parser.add_argument("--leases", action="store_true", help="Include lease owner/state/probe columns in table output")
    parser.add_argument(
        "--work-history",
        action="store_true",
        help=(
            "Include local generated claims, probes, progress, and last worker. "
            "This data can reset with build cleanup; tracked recovery journals are durable."
        ),
    )
    parser.add_argument("--max-lifetime-probes", type=int, help="Maximum lifetime meaningful probes")
    parser.add_argument("--max-claims", type=int, help="Maximum lifetime target claims")

    parser.add_argument("--va", help="Show one VA, e.g. 0047A3A0")
    parser.add_argument("--source", help="Filter by PDB source file/path substring, e.g. Pnl_pic.cpp")
    parser.add_argument("--query", "-q", help="Whitespace-token search over VA/name/source/path/notes")
    parser.add_argument("--min-size", type=int, help="Minimum function size in bytes")
    parser.add_argument("--max-size", type=int, help="Maximum function size in bytes")

    sort = parser.add_mutually_exclusive_group()
    sort.add_argument("--smallest", action="store_true", help="Sort by size ascending")
    sort.add_argument("--largest", action="store_true", help="Sort by size descending")
    sort.add_argument(
        "--least-comments",
        action="store_true",
        help="Sort by source comment lines ascending, then function size",
    )
    parser.add_argument(
        "--sort",
        default="size",
        choices=["size", "bytes", "asm", "va", "name", "source", "bucket", "diff", "edit-diff", "first-mismatch", "remaining-rank", "comment-lines"],
        help="Sort key (default: size)",
    )
    parser.add_argument("--desc", action="store_true", help="Descending sort")
    parser.add_argument("--limit", type=int, default=30, help="Maximum rows to print (default: 30; 0 = all)")

    parser.add_argument("--paths", action="store_true", help="Include source and packet paths in table output")
    parser.add_argument("--notes", action="store_true", help="Include blocker/note/next columns in table output")
    parser.add_argument(
        "--triage",
        action="store_true",
        help=(
            "Add compact packet evidence (PDB span, frame, EH, calls, vslots, saved registers, decomp). "
            "Packet parsing happens only after sorting/--limit."
        ),
    )
    parser.add_argument("--json", action="store_true", help="Emit JSON rows")
    parser.add_argument("--csv", action="store_true", help="Emit CSV rows")
    parser.add_argument("--summary", action="store_true", help="Print bucket summary instead of rows")
    parser.add_argument(
        "--with-preview",
        action="store_true",
        help="Include source_preview while building live rows. Slower and usually unnecessary for CLI queries.",
    )
    return parser.parse_args()


def load_rows(
    args: argparse.Namespace,
    *,
    include_vas: set[str] | None = None,
    exclude_vas: set[str] | None = None,
) -> list[dict[str, str]]:
    sort_key, _descending = sort_from_args(args)
    return build_status_rows(
        include_source_preview=False,
        include_source_notes=bool(args.no_blockers or args.blockers or args.query),
        include_diff_metrics=sort_key in {"diff", "edit-diff", "first-mismatch"},
        include_comment_lines=sort_key == "comment-lines",
        va=args.va,
        source_bucket_filter=source_bucket_from_args(args),
        corpus_bucket_filter=corpus_bucket_from_args(args),
        remaining_filter=remaining_from_args(args),
        pdb_source_file=args.source,
        min_size=args.min_size,
        max_size=args.max_size,
        include_vas=include_vas,
        exclude_vas=exclude_vas,
    )


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
    if args.verified_logic:
        return "verified_logic"
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
    if args.least_comments:
        return "comment-lines", False
    return args.sort, args.desc


def limited(rows: list[dict[str, str]], limit: int) -> list[dict[str, str]]:
    if limit and limit > 0:
        return rows[:limit]
    return rows


def annotate_leases(
    rows: list[dict[str, str]],
    sessions: list[dict] | None = None,
    *,
    include_work_history: bool = False,
) -> list[dict[str, str]]:
    source_sessions = load_target_sessions() if sessions is None else sessions
    by_va = {str(session.get("va", "")).upper(): session for session in source_sessions}
    active_by_source: dict[Path, dict] = {}
    for session in source_sessions:
        if not session_is_active(session):
            continue
        try:
            record = function_record_by_va(int(str(session.get("va") or ""), 16))
            active_by_source[compiler_source_path(record).resolve()] = session
        except (KeyError, TypeError, ValueError):
            continue
    for row in rows:
        session = by_va.get(row.get("va", "").upper())
        lease_session = session if session and session_is_active(session) else None
        if lease_session is None and active_by_source:
            try:
                source_text = str(row.get("source_path") or "")
                source = Path(source_text)
                if not source.is_absolute():
                    source = REPO_ROOT / source
                lease_session = active_by_source.get(source.resolve())
            except (OSError, ValueError):
                lease_session = None
        active = lease_session is not None
        total_probes = meaningful_probe_count(session or {}, current_claim_only=False)
        row["lease_active"] = "yes" if active else "no"
        row["lease_owner"] = str((lease_session or {}).get("owner", "")) if active else ""
        row["lease_target_va"] = str((lease_session or {}).get("va", "")) if active else ""
        row["lease_state"] = "active" if active else str((session or {}).get("state", ""))
        row["lease_expires_at"] = str((lease_session or {}).get("lease_expires_at", "")) if active else ""
        row["lease_probes"] = str(meaningful_probe_count(session or {})) if session else ""
        row["lease_probe_total"] = str(total_probes) if session else ""
        row["clean_pinned"] = "yes" if session and session.get("clean_baseline") else ""
        if include_work_history:
            claim_count = session_claim_count(session or {})
            improvement = last_positional_improvement(session or {})
            if (session or {}).get("summary_version"):
                best_diff = (session or {}).get("best_diff_bytes")
            else:
                probe_diffs = [
                    int((probe.get("metrics") or {}).get("diff_bytes"))
                    for probe in (session or {}).get("probes") or []
                    if (probe.get("metrics") or {}).get("diff_bytes") is not None
                ]
                best_diff = min(probe_diffs) if probe_diffs else None
            current_metrics = (session or {}).get("last_metric_summary") or {}
            current_diff = current_metrics.get("diff_bytes")
            row["lease_claim_total"] = str(claim_count)
            row["work_best_current_diff"] = (
                f"{best_diff}/{current_diff if current_diff is not None else '-'}"
                if best_diff is not None else "-"
            )
            row["work_last_gain"] = (
                f"#{improvement.get('number')}@{str(improvement.get('at') or '')[:10]}"
                if improvement else "none"
            )
            row["work_last_worker"] = str((session or {}).get("owner", ""))
            recommendation = classify_next_stage(current_metrics)
            if total_probes >= 30 or claim_count >= 4:
                recommendation = "readiness/specialist audit; " + recommendation
            row["work_next"] = recommendation
    return rows


def filter_leases(
    rows: list[dict[str, str]], *, unleased: bool = False, active_only: bool = False, owner: str = ""
) -> list[dict[str, str]]:
    result = rows
    if unleased:
        result = [row for row in result if row.get("lease_active") != "yes"]
    if active_only:
        result = [row for row in result if row.get("lease_active") == "yes"]
    if owner:
        result = [
            row
            for row in result
            if row.get("lease_active") == "yes" and row.get("lease_owner") == owner
        ]
    return result


def lease_prefilter_vas(
    args: argparse.Namespace,
    sessions: list[dict],
) -> tuple[set[str] | None, set[str]]:
    """Return safe VA filters that can run before source files are read."""
    include_vas: set[str] | None = None
    exclude_vas: set[str] = set()

    if args.max_lifetime_probes is not None:
        exclude_vas.update(
            str(session.get("va", "")).upper()
            for session in sessions
            if meaningful_probe_count(session, current_claim_only=False) > args.max_lifetime_probes
        )
    if args.max_claims is not None:
        exclude_vas.update(
            str(session.get("va", "")).upper()
            for session in sessions
            if session_claim_count(session) > args.max_claims
        )
    return include_vas, exclude_vas


def annotate_triage(rows: list[dict[str, str]]) -> list[dict[str, str]]:
    """Attach bounded packet evidence to already-sorted/limited status rows."""
    if not rows:
        return rows
    from find_function_donors import packet_features

    names_by_va = {int(row["va"], 16): row["name"] for row in load_functions()}
    for row in rows:
        packet_text_path = Path(row.get("packet_path") or packet_path_for_row(row))
        if not packet_text_path.is_absolute():
            packet_text_path = REPO_ROOT / packet_text_path
        features = packet_features(packet_text_path, names_by_va)
        header = ""
        if packet_text_path.exists():
            with packet_text_path.open("r", encoding="utf-8", errors="replace") as handle:
                header = "".join(handle.readline() for _ in range(16))
                has_decomp = any(
                    line.rstrip() == "=== GhidraDecompilerExcerpt ===" for line in handle
                )
        else:
            has_decomp = False
        line_span = re.search(r"^PdbLineSpan:\s*(.+)$", header, re.MULTILINE)
        line_records = re.search(r"^PdbLineRecordCount:\s*(\d+)$", header, re.MULTILINE)
        frame_size = int(features.get("frame_size") or 0)
        row["triage_pdb_lines"] = line_span.group(1).strip() if line_span else ""
        row["triage_line_records"] = line_records.group(1) if line_records else ""
        row["triage_frame"] = f"0x{frame_size:X}" if frame_size else "-"
        row["triage_eh"] = "yes" if features.get("eh_frame") else "no"
        row["triage_calls"] = str(len(features.get("calls") or []))
        row["triage_vslots"] = str(len(features.get("vslots") or []))
        row["triage_saved"] = ",".join(features.get("saved_registers") or []) or "-"
        row["triage_decomp"] = "yes" if has_decomp else "no"
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
        f"verified_logic={counts['verified_logic']} "
        f"scratch={counts['scratch']} "
        f"unclaimed={counts['unclaimed']} "
        f"conflict={counts['conflict']}"
    )
    bucket_bytes = {
        bucket: sum(
            int(row.get("size_bytes") or 0)
            for row in rows
            if row.get("source_bucket") == bucket
        )
        for bucket in ("matching", "accepted_drift", "verified_logic", "scratch", "unclaimed", "conflict")
    }
    print(
        "source_bytes: "
        + " ".join(f"{bucket}={bucket_bytes[bucket]}" for bucket in bucket_bytes)
    )
    print(
        "corpus: "
        f"normal={counts['normal']} "
        f"padding_only={counts['padding_only']} "
        f"parent_owned_fragment={counts['parent_owned_fragment']} "
        f"toolchain_supplied={counts['toolchain_supplied']} "
        f"asm_special={counts['asm_special']} "
        f"asm_region={counts['asm_region']}"
    )
    active_leases = sum(row.get("lease_active") == "yes" for row in rows)
    print(f"leases: active={active_leases} unleased={len(rows) - active_leases}")
    logic_reviews = sum(row.get("has_logic_review") == "yes" for row in rows)
    logic_reviews_in_progress = sum(
        row.get("has_logic_review") == "yes" and row.get("source_bucket") == "scratch"
        for row in rows
    )
    print(f"logic_reviews: total={logic_reviews} in_progress={logic_reviews_in_progress}")


def emit_csv(rows: list[dict[str, str]]) -> None:
    if not rows:
        return
    writer = csv.DictWriter(sys.stdout, fieldnames=list(rows[0].keys()), extrasaction="ignore", lineterminator="\n")
    writer.writeheader()
    writer.writerows(rows)


def table_columns(args: argparse.Namespace) -> list[tuple[str, str, int]]:
    if args.triage:
        cols = [
            ("size", "size_bytes", 6),
            ("asm", "asm_lines", 5),
            ("VA", "va", 10),
            ("name", "name", 32),
            ("pdb_source", "pdb_source_file", 16),
            ("lines", "triage_pdb_lines", 11),
            ("frame", "triage_frame", 8),
            ("EH", "triage_eh", 4),
            ("calltg", "triage_calls", 6),
            ("vslots", "triage_vslots", 7),
            ("saved", "triage_saved", 16),
            ("decomp", "triage_decomp", 7),
        ]
    else:
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
            ("logic_review", "logic_review_path", 46),
            ("packet", "packet_path", 56),
        ])
    if args.notes:
        cols.extend([
            ("blocker", "source_blocker", 28),
            ("note", "source_note", 36),
            ("next", "source_next", 36),
        ])
    if args.leases or args.work_history or args.unleased or args.active_leases or args.owner:
        cols.extend([
            ("lease_owner", "lease_owner", 20),
            ("lease_va", "lease_target_va", 10),
            ("lease", "lease_state", 10),
            ("claim", "lease_probes", 7),
            ("total", "lease_probe_total", 7),
            ("clean", "clean_pinned", 6),
            ("expires", "lease_expires_at", 20),
        ])
    if args.work_history:
        cols.extend([
            ("claims", "lease_claim_total", 6),
            ("best/cur", "work_best_current_diff", 10),
            ("last_gain", "work_last_gain", 15),
            ("last_worker", "work_last_worker", 18),
        ])
        if not args.notes:
            cols.append(("blocker", "source_blocker", 28))
        cols.append(("next_workflow", "work_next", 42))
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
    if args.triage and (args.limit <= 0 or args.limit > 50):
        raise SystemExit("--triage requires a bounded --limit between 1 and 50")
    if args.max_lifetime_probes is not None and args.max_lifetime_probes < 0:
        raise SystemExit("--max-lifetime-probes must be zero or positive")
    if args.max_claims is not None and args.max_claims < 0:
        raise SystemExit("--max-claims must be zero or positive")
    include_work_history = (
        args.work_history
        or args.max_lifetime_probes is not None
        or args.max_claims is not None
    )
    needs_sessions = bool(
        args.summary
        or args.json
        or args.csv
        or args.leases
        or args.work_history
        or args.unleased
        or args.active_leases
        or args.owner
        or args.max_lifetime_probes is not None
        or args.max_claims is not None
    )
    sessions = load_target_sessions() if needs_sessions else []
    include_vas, exclude_vas = lease_prefilter_vas(args, sessions) if needs_sessions else (None, set())
    rows = load_rows(args, include_vas=include_vas, exclude_vas=exclude_vas)
    if needs_sessions:
        rows = annotate_leases(rows, sessions, include_work_history=include_work_history)
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
    if args.logic_review:
        rows = [row for row in rows if row.get("has_logic_review") == "yes"]
    elif args.logic_review_in_progress:
        rows = [
            row
            for row in rows
            if row.get("has_logic_review") == "yes" and row.get("source_bucket") == "scratch"
        ]
    rows = filter_leases(
        rows,
        unleased=args.unleased,
        active_only=args.active_leases,
        owner=args.owner or "",
    )
    if args.max_lifetime_probes is not None:
        rows = [
            row for row in rows
            if int(row.get("lease_probe_total") or 0) <= args.max_lifetime_probes
        ]
    if args.max_claims is not None:
        rows = [
            row for row in rows
            if int(row.get("lease_claim_total") or 0) <= args.max_claims
        ]

    if args.summary:
        print_summary(rows)
        return

    sort_key, descending = sort_from_args(args)
    rows = sort_status_rows(rows, sort=sort_key, descending=descending)
    total_before_limit = len(rows)
    rows = limited(rows, args.limit)
    enrich_status_rows(
        rows,
        include_source_notes=bool(args.notes or args.work_history or args.json or args.csv),
        include_source_preview=args.with_preview,
        include_comment_lines=bool(args.json or args.csv),
        include_diff_metrics=bool(args.json or args.csv),
    )
    if args.triage:
        rows = annotate_triage(rows)

    if args.json:
        print(json.dumps(rows, ensure_ascii=False, indent=2))
    elif args.csv:
        emit_csv(rows)
    else:
        emit_table(rows, args, total_before_limit)


if __name__ == "__main__":
    main()
