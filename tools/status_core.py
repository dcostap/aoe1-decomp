from __future__ import annotations

import csv
import json
import re
import subprocess
from pathlib import Path
from typing import Iterable

from common import (
    REPO_ROOT,
    classify_corpus_bucket,
    load_asm_special_function_names,
    load_asm_special_regions,
    load_functions,
    load_padding_only_functions,
    load_parent_owned_fragments,
    load_toolchain_supplied_function_names,
    load_toolchain_supplied_regions,
)

HEADER_NOTE_RE = re.compile(r"^//\s*([A-Z_]+):\s*(.*)$")
COMMENT_TOKEN_RE = re.compile(
    r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\r\n]*|/\*.*?(?:\*/|\Z)',
    re.DOTALL,
)
SOURCE_BUCKETS = ["matching", "accepted_drift", "verified_logic", "scratch", "unclaimed", "conflict"]
CORPUS_BUCKETS = ["normal", "padding_only", "parent_owned_fragment", "toolchain_supplied", "asm_special", "asm_region"]
STATUS_FIELDNAMES = [
    "va",
    "name",
    "slug",
    "size_bytes",
    "asm_lines",
    "calling_convention",
    "pdb_source_file",
    "pdb_source_path",
    "source_bucket",
    "source_path",
    "logic_review_path",
    "has_logic_review",
    "corpus_bucket",
    "corpus_reason",
    "padding_only",
    "padding_only_reason",
    "toolchain_supplied",
    "toolchain_supplied_reason",
    "parent_owned_fragment",
    "parent_va",
    "parent_name",
    "parent_fragment_reason",
    "is_remaining",
    "remaining_size_rank",
    "remaining_asm_rank",
    "uses_custom_flags",
    "custom_flags_path",
    "source_status",
    "source_flags_note",
    "source_blocker",
    "source_note",
    "source_class",
    "source_risk",
    "source_why",
    "source_next",
    "source_preview",
    "source_comment_lines",
    "has_blocker",
    "diff_result",
    "diff_percent",
    "diff_bytes",
    "diff_spans",
    "positional_diff_percent",
    "positional_diff_bytes",
    "positional_diff_spans",
    "edit_diff_percent",
    "edit_diff_bytes",
    "edit_insert_bytes",
    "edit_delete_bytes",
    "edit_replace_bytes",
    "edit_equal_bytes",
    "likely_shifted_alignment",
    "first_mismatch_offset",
]


def default_header_notes() -> dict[str, str]:
    return {
        "STATUS": "",
        "FLAGS": "",
        "BLOCKER": "",
        "NOTE": "",
        "CLASS": "",
        "RISK": "",
        "WHY": "",
        "NEXT": "",
    }


def source_files(path: Path) -> dict[str, Path]:
    files: dict[str, Path] = {}
    if not path.exists():
        return files
    for child in sorted(path.iterdir()):
        if child.suffix.lower() not in {".c", ".cpp"}:
            continue
        # Function VAs are case-insensitive. Older source files contain lower-
        # case hex digits while inventory slugs use upper-case hex digits.
        files[child.stem.upper()] = child
    return files


def logic_review_files(path: Path) -> dict[str, Path]:
    """Return present and tracked ledgers, including sparse-checkout files."""
    files: dict[str, Path] = {}
    if path.exists():
        for child in sorted(path.iterdir()):
            if child.suffix.lower() == ".md" and child.name.lower() != "readme.md":
                files[child.stem.upper()] = child

    try:
        relative = path.relative_to(REPO_ROOT)
    except ValueError:
        return files
    result = subprocess.run(
        ["git", "-C", str(REPO_ROOT), "ls-files", "--", relative.as_posix()],
        capture_output=True,
        text=True,
        check=False,
    )
    if result.returncode != 0:
        return files
    for raw_line in result.stdout.splitlines():
        tracked = Path(raw_line.strip())
        if tracked.suffix.lower() != ".md" or tracked.name.lower() == "readme.md":
            continue
        files.setdefault(tracked.stem.upper(), REPO_ROOT / tracked)
    return files


def parse_header_notes(path: Path) -> dict[str, str]:
    if not path.exists():
        return default_header_notes()
    notes = default_header_notes()
    with path.open("r", encoding="utf-8", errors="replace") as handle:
        for line in handle:
            stripped = line.strip()
            if not stripped:
                continue
            if not stripped.startswith("//"):
                break
            match = HEADER_NOTE_RE.match(stripped)
            if match is None:
                continue
            key = match.group(1)
            value = match.group(2).strip()
            if key not in notes:
                continue
            if key == "NOTE" and notes[key]:
                notes[key] = notes[key] + " | " + value
            else:
                notes[key] = value
    return notes


def parse_header_notes_text(text: str) -> dict[str, str]:
    notes = default_header_notes()
    for line in text.splitlines():
        stripped = line.strip()
        if not stripped:
            continue
        if not stripped.startswith("//"):
            break
        match = HEADER_NOTE_RE.match(stripped)
        if match is None:
            continue
        key = match.group(1)
        value = match.group(2).strip()
        if key not in notes:
            continue
        if key == "NOTE" and notes[key]:
            notes[key] = notes[key] + " | " + value
        else:
            notes[key] = value
    return notes


def read_source_preview(path: Path | None, max_lines: int = 140, max_chars: int = 12000) -> str:
    if path is None or not path.exists():
        return ""

    text = path.read_text(encoding="utf-8", errors="replace")
    return read_source_preview_text(text, max_lines=max_lines, max_chars=max_chars)


def read_source_preview_text(text: str, max_lines: int = 140, max_chars: int = 12000) -> str:
    if len(text) > max_chars:
        text = text[:max_chars]
    lines = text.splitlines()
    if len(lines) > max_lines:
        lines = lines[:max_lines]
        lines.append("// ... truncated ...")
    return "\n".join(lines)


def count_comment_lines(path: Path | None) -> int:
    if path is None or not path.exists():
        return 0

    text = path.read_text(encoding="utf-8", errors="replace")
    return count_comment_lines_text(text)


def count_comment_lines_text(text: str) -> int:
    """Count physical source lines that contain C or C++ comments.

    The scanner ignores comment-looking text in ordinary character and string
    literals. It counts both line comments and every line covered by a block
    comment, including mixed code/comment lines.
    """
    comment_lines: set[int] = set()
    line = 0
    position = 0
    for match in COMMENT_TOKEN_RE.finditer(text):
        line += text.count("\n", position, match.start())
        token = match.group(0)
        if token.startswith("//"):
            comment_lines.add(line)
        elif token.startswith("/*"):
            last_line = line + token.count("\n") - int(token.endswith("\n"))
            comment_lines.update(range(line, last_line + 1))
        line += token.count("\n")
        position = match.end()
    return len(comment_lines)


def rank_map(records: list[dict[str, str]], field: str) -> dict[str, int]:
    ordered = sorted(records, key=lambda row: (-int(row[field]), row["va"]))
    return {row["va"]: index + 1 for index, row in enumerate(ordered)}


def to_int(value: str | int | None) -> int:
    if value in (None, ""):
        return 0
    return int(value)


def to_float(value: str | int | float | None) -> float:
    if value in (None, ""):
        return 0.0
    return float(value)


def packet_path_for_row(row: dict[str, str]) -> str:
    return str(Path("inventory") / "functions" / row["va"][:4] / f"{row['slug']}.txt")


def _source_path_for_row(row: dict[str, str]) -> Path | None:
    raw_paths = [value.strip() for value in row.get("source_path", "").split(" | ") if value.strip()]
    if not raw_paths:
        return None
    priorities = ("src/scratch/", "src/verified_logic/", "src/accepted_drift/", "src/matching/")
    normalized = [(value.replace("\\", "/"), value) for value in raw_paths]
    for prefix in priorities:
        for portable, original in normalized:
            if portable.startswith(prefix):
                return REPO_ROOT / original
    return REPO_ROOT / raw_paths[0]


def enrich_status_rows(
    rows: list[dict[str, str]],
    *,
    include_source_notes: bool = False,
    include_source_preview: bool = False,
    include_comment_lines: bool = False,
    include_diff_metrics: bool = False,
) -> list[dict[str, str]]:
    """Load optional file-backed fields for rows that survived filtering and limits."""
    for row in rows:
        source_path = _source_path_for_row(row)
        source_text: str | None = None
        if source_path is not None and (include_source_preview or include_comment_lines):
            source_text = source_path.read_text(encoding="utf-8", errors="replace")

        if include_source_notes:
            if source_path is None:
                notes = default_header_notes()
            elif source_text is not None:
                notes = parse_header_notes_text(source_text)
            else:
                notes = parse_header_notes(source_path)
            if row.get("source_bucket") == "verified_logic" and row.get("has_logic_review") != "yes":
                missing_ledger = "verified_logic source has no logic-review ledger"
                notes["BLOCKER"] = (
                    f"{notes['BLOCKER']} | {missing_ledger}" if notes["BLOCKER"] else missing_ledger
                )
            row.update(
                {
                    "source_status": notes["STATUS"],
                    "source_flags_note": notes["FLAGS"],
                    "source_blocker": notes["BLOCKER"],
                    "source_note": notes["NOTE"],
                    "source_class": notes["CLASS"],
                    "source_risk": notes["RISK"],
                    "source_why": notes["WHY"],
                    "source_next": notes["NEXT"],
                    "has_blocker": "yes" if notes["BLOCKER"] else "no",
                }
            )
        if include_source_preview:
            row["source_preview"] = read_source_preview_text(source_text or "")
        if include_comment_lines:
            row["source_comment_lines"] = str(count_comment_lines_text(source_text or ""))

        if include_diff_metrics:
            diff_metrics: dict[str, object] = {}
            diff_metrics_path = REPO_ROOT / "build" / "diff" / f"{row['slug']}.json"
            if diff_metrics_path.exists():
                try:
                    diff_metrics = json.loads(diff_metrics_path.read_text(encoding="utf-8"))
                except json.JSONDecodeError:
                    diff_metrics = {}
            elif row.get("source_bucket") == "matching":
                diff_metrics = {
                    "result": "MATCH",
                    "diff_percent": 0.0,
                    "diff_bytes": 0,
                    "diff_spans": 0,
                    "positional_diff_percent": 0.0,
                    "positional_diff_bytes": 0,
                    "positional_diff_spans": 0,
                    "edit_diff_percent": 0.0,
                    "edit_diff_bytes": 0,
                    "edit_insert_bytes": 0,
                    "edit_delete_bytes": 0,
                    "edit_replace_bytes": 0,
                    "edit_equal_bytes": int(row.get("size_bytes") or 0),
                    "likely_shifted_alignment": "no",
                    "first_mismatch_offset": "",
                }
            row.update(
                {
                    "diff_result": str(diff_metrics.get("result", "")),
                    "diff_percent": f"{float(diff_metrics.get('diff_percent', 0.0)):.4f}" if diff_metrics else "",
                    "diff_bytes": str(diff_metrics.get("diff_bytes", "")),
                    "diff_spans": str(diff_metrics.get("diff_spans", "")),
                    "positional_diff_percent": f"{float(diff_metrics.get('positional_diff_percent', diff_metrics.get('diff_percent', 0.0))):.4f}" if diff_metrics else "",
                    "positional_diff_bytes": str(diff_metrics.get("positional_diff_bytes", diff_metrics.get("diff_bytes", ""))),
                    "positional_diff_spans": str(diff_metrics.get("positional_diff_spans", diff_metrics.get("diff_spans", ""))),
                    "edit_diff_percent": f"{float(diff_metrics.get('edit_diff_percent', diff_metrics.get('diff_percent', 0.0))):.4f}" if diff_metrics else "",
                    "edit_diff_bytes": str(diff_metrics.get("edit_diff_bytes", diff_metrics.get("diff_bytes", ""))),
                    "edit_insert_bytes": str(diff_metrics.get("edit_insert_bytes", "")),
                    "edit_delete_bytes": str(diff_metrics.get("edit_delete_bytes", "")),
                    "edit_replace_bytes": str(diff_metrics.get("edit_replace_bytes", "")),
                    "edit_equal_bytes": str(diff_metrics.get("edit_equal_bytes", "")),
                    "likely_shifted_alignment": "yes" if diff_metrics.get("likely_shifted_alignment") else ("no" if diff_metrics else ""),
                    "first_mismatch_offset": str(diff_metrics.get("first_mismatch_offset", "")),
                }
            )
    return rows


def build_status_rows(
    *,
    include_source_preview: bool = True,
    include_source_notes: bool = True,
    include_diff_metrics: bool = True,
    include_comment_lines: bool = True,
    va: str | None = None,
    source_bucket_filter: str | None = None,
    corpus_bucket_filter: str | None = None,
    remaining_filter: bool | None = None,
    pdb_source_file: str | None = None,
    min_size: int | None = None,
    max_size: int | None = None,
    include_vas: set[str] | None = None,
    exclude_vas: set[str] | None = None,
) -> list[dict[str, str]]:
    """Build current project status rows from live repo state.

    This deliberately does not read project_full_status.csv. The CSV/HTML dashboard
    are generated human-facing artifacts and may be stale; callers that need fresh
    answers should use this function directly.

    When ``va`` is supplied, all records are still classified for corpus-wide
    remaining-rank parity, but source notes and diff metrics are read only for the
    selected function.
    """
    scratch_dir = REPO_ROOT / "src" / "scratch"
    matching_dir = REPO_ROOT / "src" / "matching"
    accepted_drift_dir = REPO_ROOT / "src" / "accepted_drift"
    verified_logic_dir = REPO_ROOT / "src" / "verified_logic"
    logic_reviews_dir = REPO_ROOT / "logic_reviews"
    flags_dir = REPO_ROOT / "config" / "flags"
    scratch_files = source_files(scratch_dir)
    matching_files = source_files(matching_dir)
    accepted_drift_files = source_files(accepted_drift_dir)
    verified_logic_files = source_files(verified_logic_dir)
    logic_review_ledgers = logic_review_files(logic_reviews_dir)
    custom_flag_files = {
        child.stem.upper(): child
        for child in flags_dir.iterdir()
        if child.suffix.lower() == ".rsp"
    } if flags_dir.exists() else {}

    records = load_functions()
    toolchain_supplied_names = load_toolchain_supplied_function_names()
    toolchain_supplied_regions = load_toolchain_supplied_regions()
    asm_special_names = load_asm_special_function_names()
    asm_special_regions = load_asm_special_regions()
    parent_owned_fragments = load_parent_owned_fragments()
    padding_only_functions = load_padding_only_functions()
    remaining_records: list[dict[str, str]] = []
    rows: list[dict[str, str]] = []
    va_norm = va.upper() if va else None
    pdb_norm = pdb_source_file.lower() if pdb_source_file else None
    include_vas_norm = {value.upper() for value in include_vas} if include_vas is not None else None
    exclude_vas_norm = {value.upper() for value in exclude_vas or set()}

    for record in records:
        slug = record["slug"]
        slug_key = slug.upper()
        scratch_path = scratch_files.get(slug_key)
        matching_path = matching_files.get(slug_key)
        accepted_drift_path = accepted_drift_files.get(slug_key)
        verified_logic_path = verified_logic_files.get(slug_key)
        present_paths = [
            path
            for path in (matching_path, accepted_drift_path, verified_logic_path, scratch_path)
            if path is not None
        ]

        corpus_bucket, corpus_reason = classify_corpus_bucket(
            record,
            toolchain_supplied_names=toolchain_supplied_names,
            toolchain_supplied_regions=toolchain_supplied_regions,
            asm_special_names=asm_special_names,
            asm_special_regions=asm_special_regions,
            parent_owned_fragments=parent_owned_fragments,
            padding_only_functions=padding_only_functions,
        )

        if len(present_paths) > 1:
            source_bucket = "conflict"
        elif matching_path:
            source_bucket = "matching"
        elif accepted_drift_path:
            source_bucket = "accepted_drift"
        elif verified_logic_path:
            source_bucket = "verified_logic"
        elif scratch_path:
            source_bucket = "scratch"
        else:
            source_bucket = "unclaimed"

        is_remaining = "yes" if corpus_bucket == "normal" and source_bucket not in {"matching", "accepted_drift", "verified_logic"} else "no"
        if is_remaining == "yes":
            remaining_records.append(record)
        record_va = record["va"].upper()
        if va_norm is not None and record_va != va_norm:
            continue
        if include_vas_norm is not None and record_va not in include_vas_norm:
            continue
        if record_va in exclude_vas_norm:
            continue
        if source_bucket_filter is not None and source_bucket != source_bucket_filter:
            continue
        if corpus_bucket_filter is not None and corpus_bucket != corpus_bucket_filter:
            continue
        if remaining_filter is not None and (is_remaining == "yes") != remaining_filter:
            continue
        if pdb_norm and pdb_norm not in record.get("pdb_source_file", "").lower() and pdb_norm not in record.get("pdb_source_path", "").lower():
            continue
        if min_size is not None and int(record.get("size_bytes") or 0) < min_size:
            continue
        if max_size is not None and int(record.get("size_bytes") or 0) > max_size:
            continue

        source_path = " | ".join(
            str(Path("src") / path.parent.name / path.name) for path in present_paths
        )
        custom_flags_path = custom_flag_files.get(slug_key)
        logic_review_path = logic_review_ledgers.get(slug_key)

        parent_fragment = parent_owned_fragments.get(int(record["va"], 16))
        parent_va_text = f"{parent_fragment[0]:08X}" if parent_fragment else ""
        parent_name_text = parent_fragment[1] if parent_fragment else ""
        parent_reason_text = parent_fragment[2] if parent_fragment else ""

        row = {
            "va": record["va"],
            "name": record["name"],
            "slug": slug,
            "size_bytes": record["size_bytes"],
            "asm_lines": record["asm_lines"],
            "calling_convention": record["calling_convention"],
            "pdb_source_file": record.get("pdb_source_file", ""),
            "pdb_source_path": record.get("pdb_source_path", ""),
            "source_bucket": source_bucket,
            "source_path": source_path,
            "logic_review_path": str(Path("logic_reviews") / logic_review_path.name) if logic_review_path is not None else "",
            "has_logic_review": "yes" if logic_review_path is not None else "no",
            "corpus_bucket": corpus_bucket,
            "corpus_reason": corpus_reason,
            "padding_only": "yes" if corpus_bucket == "padding_only" else "no",
            "padding_only_reason": corpus_reason if corpus_bucket == "padding_only" else "",
            "toolchain_supplied": "yes" if corpus_bucket == "toolchain_supplied" else "no",
            "toolchain_supplied_reason": corpus_reason if corpus_bucket == "toolchain_supplied" else "",
            "parent_owned_fragment": "yes" if corpus_bucket == "parent_owned_fragment" else "no",
            "parent_va": parent_va_text,
            "parent_name": parent_name_text,
            "parent_fragment_reason": parent_reason_text,
            "is_remaining": is_remaining,
            "remaining_size_rank": "",
            "remaining_asm_rank": "",
            "uses_custom_flags": "yes" if custom_flags_path is not None else "no",
            "custom_flags_path": str(Path("config") / "flags" / custom_flags_path.name) if custom_flags_path is not None else "",
            "source_status": "",
            "source_flags_note": "",
            "source_blocker": "",
            "source_note": "",
            "source_class": "",
            "source_risk": "",
            "source_why": "",
            "source_next": "",
            "source_preview": "",
            "source_comment_lines": "",
            "has_blocker": "no",
            "diff_result": "",
            "diff_percent": "",
            "diff_bytes": "",
            "diff_spans": "",
            "positional_diff_percent": "",
            "positional_diff_bytes": "",
            "positional_diff_spans": "",
            "edit_diff_percent": "",
            "edit_diff_bytes": "",
            "edit_insert_bytes": "",
            "edit_delete_bytes": "",
            "edit_replace_bytes": "",
            "edit_equal_bytes": "",
            "likely_shifted_alignment": "",
            "first_mismatch_offset": "",
        }
        rows.append(row)

    if include_source_notes or include_source_preview or include_comment_lines or include_diff_metrics:
        enrich_status_rows(
            rows,
            include_source_notes=include_source_notes,
            include_source_preview=include_source_preview,
            include_comment_lines=include_comment_lines,
            include_diff_metrics=include_diff_metrics,
        )

    size_ranks = rank_map(remaining_records, "size_bytes")
    asm_ranks = rank_map(remaining_records, "asm_lines")
    for row in rows:
        if row["is_remaining"] == "yes":
            row["remaining_size_rank"] = str(size_ranks[row["va"]])
            row["remaining_asm_rank"] = str(asm_ranks[row["va"]])

    return rows


def write_status_csv(rows: Iterable[dict[str, str]], output_path: Path) -> None:
    with output_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=STATUS_FIELDNAMES)
        writer.writeheader()
        writer.writerows(rows)


def status_counts(rows: Iterable[dict[str, str]]) -> dict[str, int]:
    rows_list = list(rows)
    counts: dict[str, int] = {}
    for bucket in SOURCE_BUCKETS:
        counts[bucket] = sum(1 for row in rows_list if row["source_bucket"] == bucket)
    for bucket in CORPUS_BUCKETS:
        counts[bucket] = sum(1 for row in rows_list if row["corpus_bucket"] == bucket)
    return counts


def _matches_query(row: dict[str, str], query: str) -> bool:
    tokens = query.lower().split()
    hay = " ".join(
        row.get(field, "")
        for field in (
            "va",
            "name",
            "slug",
            "calling_convention",
            "pdb_source_file",
            "pdb_source_path",
            "source_bucket",
            "source_path",
            "corpus_bucket",
            "source_status",
            "source_blocker",
            "source_note",
            "source_class",
            "source_risk",
            "source_why",
            "source_next",
        )
    ).lower()
    return all(token in hay for token in tokens)


def filter_status_rows(
    rows: Iterable[dict[str, str]],
    *,
    corpus_bucket: str | None = None,
    source_bucket: str | None = None,
    remaining: bool | None = None,
    no_blockers: bool = False,
    blockers_only: bool = False,
    pdb_source_file: str | None = None,
    query: str | None = None,
    min_size: int | None = None,
    max_size: int | None = None,
    va: str | None = None,
) -> list[dict[str, str]]:
    result: list[dict[str, str]] = []
    va_norm = va.upper() if va else None
    pdb_norm = pdb_source_file.lower() if pdb_source_file else None
    for row in rows:
        if corpus_bucket is not None and row["corpus_bucket"] != corpus_bucket:
            continue
        if source_bucket is not None and row["source_bucket"] != source_bucket:
            continue
        if remaining is not None and (row["is_remaining"] == "yes") != remaining:
            continue
        if no_blockers and row["has_blocker"] == "yes":
            continue
        if blockers_only and row["has_blocker"] != "yes":
            continue
        if pdb_norm and pdb_norm not in row.get("pdb_source_file", "").lower() and pdb_norm not in row.get("pdb_source_path", "").lower():
            continue
        if query and not _matches_query(row, query):
            continue
        if min_size is not None and to_int(row["size_bytes"]) < min_size:
            continue
        if max_size is not None and to_int(row["size_bytes"]) > max_size:
            continue
        if va_norm is not None and row["va"].upper() != va_norm:
            continue
        result.append(row)
    return result


def sort_status_rows(rows: Iterable[dict[str, str]], *, sort: str = "size", descending: bool = False) -> list[dict[str, str]]:
    integer_keys = {
        "size": "size_bytes",
        "bytes": "size_bytes",
        "asm": "asm_lines",
        "first-mismatch": "first_mismatch_offset",
        "first_mismatch": "first_mismatch_offset",
        "remaining-rank": "remaining_size_rank",
        "remaining_rank": "remaining_size_rank",
        "comment-lines": "source_comment_lines",
        "comment_lines": "source_comment_lines",
        "comments": "source_comment_lines",
    }
    float_keys = {
        "diff": "positional_diff_percent",
        "edit-diff": "edit_diff_percent",
        "edit_diff": "edit_diff_percent",
    }
    text_keys = {
        "va": "va",
        "name": "name",
        "source": "pdb_source_file",
        "bucket": "source_bucket",
    }
    sort_key = sort.lower()
    rows_list = list(rows)
    if sort_key in integer_keys:
        field = integer_keys[sort_key]
        tie_breaker = "size_bytes" if field == "source_comment_lines" else "va"
        rows_list.sort(
            key=lambda row: (
                to_int(row.get(field, "") or 0),
                to_int(row.get(tie_breaker, "") or 0) if tie_breaker == "size_bytes" else row["va"],
                row["va"],
            ),
            reverse=descending,
        )
    elif sort_key in float_keys:
        field = float_keys[sort_key]
        rows_list.sort(key=lambda row: (to_float(row.get(field, "") or 0.0), row["va"]), reverse=descending)
    elif sort_key in text_keys:
        field = text_keys[sort_key]
        rows_list.sort(key=lambda row: (row.get(field, "").lower(), row["va"]), reverse=descending)
    else:
        raise ValueError(f"unknown sort key: {sort}")
    return rows_list
