from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import subprocess
import sys
from datetime import datetime
from pathlib import Path

from common import REPO_ROOT
from status_core import build_status_rows, count_comment_lines, status_counts, write_status_csv
from status_history import (
    COMPACT_METRICS_PATH,
    append_live_snapshot,
    build_history,
    upgrade_history_diff_metrics,
)


HEADER_NOTE_RE = re.compile(r"^//\s*([A-Z_]+):\s*(.*)$")
BUCKET_ORDER = ["matching", "accepted_drift", "verified_logic", "scratch", "unclaimed", "conflict"]
COMPLETED_PROGRESS_BUCKETS = {"matching", "accepted_drift", "verified_logic"}
CORPUS_ORDER = ["normal", "padding_only", "compiler_generated", "parent_owned_fragment", "toolchain_supplied", "asm_special", "asm_region"]
BUCKET_COLORS = {
    "matching": "#22c55e",
    "accepted_drift": "#f59e0b",
    "verified_logic": "#06b6d4",
    "scratch": "#8b5cf6",
    "unclaimed": "#475569",
    "conflict": "#ef4444",
}


HTML_TEMPLATE_PATH = REPO_ROOT / "tools" / "status_dashboard_template.html"
HISTORY_CACHE_VERSION = 12
DATA_MARKER = "__DASHBOARD_DATA__"
DASHBOARD_DIR = REPO_ROOT / "build" / "status"


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
        files[child.stem] = child
    return files


def parse_header_notes(path: Path) -> dict[str, str]:
    notes = default_header_notes()
    if not path.exists():
        return notes

    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    for line in lines:
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
    if len(text) > max_chars:
        text = text[:max_chars]
    lines = text.splitlines()
    if len(lines) > max_lines:
        lines = lines[:max_lines]
        lines.append("// ... truncated ...")
    return "\n".join(lines)


def rank_map(records: list[dict[str, str]], field: str) -> dict[str, int]:
    ordered = sorted(records, key=lambda row: (-int(row[field]), row["va"]))
    return {row["va"]: index + 1 for index, row in enumerate(ordered)}


def to_int(value: str | int | None) -> int:
    if value in (None, ""):
        return 0
    return int(value)


def _live_build_context_fingerprint() -> str:
    paths = [path for path in (REPO_ROOT / "include").rglob("*") if path.is_file()]
    paths.extend(
        path for path in (
            REPO_ROOT / "src" / "game_globals.cpp",
            REPO_ROOT / "config" / "toolchain.json",
            REPO_ROOT / "config" / "flags" / "default.rsp",
        )
        if path.is_file()
    )
    digest = hashlib.sha256()
    for path in sorted(paths, key=lambda item: item.as_posix().lower()):
        relative = path.relative_to(REPO_ROOT).as_posix()
        digest.update(relative.encode("utf-8"))
        digest.update(b"\0")
        digest.update(path.read_bytes())
        digest.update(b"\0")
    return digest.hexdigest()


def add_live_source_fingerprints(rows: list[dict[str, str]]) -> None:
    context = _live_build_context_fingerprint()
    for row in rows:
        digest = hashlib.sha256()
        digest.update(b"context\0")
        digest.update(context.encode("ascii"))
        digest.update(b"\0")
        for raw_path in (row.get("source_path", ""), row.get("custom_flags_path", "")):
            for path_text in raw_path.split(" | "):
                if not path_text:
                    continue
                normalized = path_text.replace("\\", "/")
                path = REPO_ROOT / normalized
                digest.update(normalized.encode("utf-8"))
                digest.update(b"\0")
                digest.update(path.read_bytes() if path.is_file() else b"missing")
                digest.update(b"\0")
        row["source_fingerprint"] = digest.hexdigest()
        row["diff_measured_commit"] = "WORKTREE" if row.get("diff_result") else ""


def write_compact_metrics(rows: list[dict[str, str]]) -> Path:
    fields = [
        "va", "source_bucket", "source_fingerprint", "diff_result", "diff_percent",
        "diff_bytes", "diff_spans", "positional_diff_percent", "positional_diff_bytes",
        "positional_diff_spans", "edit_diff_percent", "edit_diff_bytes",
        "edit_insert_bytes", "edit_delete_bytes", "edit_replace_bytes",
        "edit_equal_bytes", "likely_shifted_alignment", "first_mismatch_offset",
    ]
    output = REPO_ROOT / COMPACT_METRICS_PATH
    temporary = output.with_suffix(".csv.tmp")
    with temporary.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields, lineterminator="\n")
        writer.writeheader()
        for row in rows:
            if row.get("corpus_bucket") != "normal" or row.get("source_bucket") == "matching":
                continue
            writer.writerow({field: row.get(field, "") for field in fields})
    temporary.replace(output)
    return output


def packet_path_for_row(row: dict[str, str]) -> str:
    return str(Path("inventory") / "functions" / row["va"][:4] / f"{row['slug']}.txt")


def build_group_list(normal_rows: list[dict[str, str]]) -> list[dict[str, object]]:
    groups: dict[str, dict[str, object]] = {}
    for row in normal_rows:
        source_file = row["pdb_source_file"] or "(no pdb source file)"
        source_path = row["pdb_source_path"] or ""
        size_bytes = to_int(row["size_bytes"])
        asm_lines = to_int(row["asm_lines"])
        bucket = row["source_bucket"]

        group = groups.setdefault(
            source_file,
            {
                "name": source_file,
                "path": source_path,
                "valueBytes": 0,
                "valueAsmLines": 0,
                "functionCount": 0,
                "completedCount": 0,
                "remainingCount": 0,
                "remainingBytes": 0,
                "completedBytes": 0,
                "blockerCount": 0,
                "customFlagsCount": 0,
                "bucketCounts": {name: 0 for name in BUCKET_ORDER},
                "bucketBytes": {name: 0 for name in BUCKET_ORDER},
                "children": [],
            },
        )

        child = {
            "va": row["va"],
            "name": row["name"],
            "slug": row["slug"],
            "sizeBytes": size_bytes,
            "asmLines": asm_lines,
            "callingConvention": row["calling_convention"],
            "bucket": bucket,
            "sourcePath": row["source_path"],
            "logicReviewPath": row.get("logic_review_path", ""),
            "sourceStatus": row["source_status"],
            "sourceFlagsNote": row["source_flags_note"],
            "sourceNote": row["source_note"],
            "sourceBlocker": row["source_blocker"],
            "sourceClass": row["source_class"],
            "sourceRisk": row["source_risk"],
            "sourceWhy": row["source_why"],
            "sourceNext": row["source_next"],
            "sourcePreview": row["source_preview"],
            "sourceCommentLines": to_int(row["source_comment_lines"]),
            "diffPercent": float(row.get("diff_percent") or 0.0),
            "diffBytes": to_int(row.get("diff_bytes")),
            "diffSpans": to_int(row.get("diff_spans")),
            "positionalDiffPercent": float(row.get("positional_diff_percent") or row.get("diff_percent") or 0.0),
            "positionalDiffBytes": to_int(row.get("positional_diff_bytes") or row.get("diff_bytes")),
            "positionalDiffSpans": to_int(row.get("positional_diff_spans") or row.get("diff_spans")),
            "editDiffPercent": float(row.get("edit_diff_percent") or row.get("diff_percent") or 0.0),
            "editDiffBytes": to_int(row.get("edit_diff_bytes") or row.get("diff_bytes")),
            "editInsertBytes": to_int(row.get("edit_insert_bytes")),
            "editDeleteBytes": to_int(row.get("edit_delete_bytes")),
            "editReplaceBytes": to_int(row.get("edit_replace_bytes")),
            "editEqualBytes": to_int(row.get("edit_equal_bytes")),
            "likelyShiftedAlignment": row.get("likely_shifted_alignment", "") == "yes",
            "firstMismatchOffset": row.get("first_mismatch_offset", ""),
            "diffResult": row.get("diff_result", ""),
            "sourceFingerprint": row.get("source_fingerprint", ""),
            "diffMeasuredCommit": row.get("diff_measured_commit", ""),
            "usesCustomFlags": row["uses_custom_flags"] == "yes",
            "customFlagsPath": row["custom_flags_path"],
            "isRemaining": row["is_remaining"] == "yes",
            "remainingSizeRank": to_int(row["remaining_size_rank"]),
            "remainingAsmRank": to_int(row["remaining_asm_rank"]),
            "hasBlocker": row["has_blocker"] == "yes",
        }
        group["children"].append(child)
        group["functionCount"] = int(group["functionCount"]) + 1
        group["valueBytes"] = int(group["valueBytes"]) + size_bytes
        group["valueAsmLines"] = int(group["valueAsmLines"]) + asm_lines
        group["bucketCounts"][bucket] = int(group["bucketCounts"][bucket]) + 1
        group["bucketBytes"][bucket] = int(group["bucketBytes"][bucket]) + size_bytes

        if bucket in COMPLETED_PROGRESS_BUCKETS:
            group["completedCount"] = int(group["completedCount"]) + 1
            group["completedBytes"] = int(group["completedBytes"]) + size_bytes
        if row["is_remaining"] == "yes":
            group["remainingCount"] = int(group["remainingCount"]) + 1
            group["remainingBytes"] = int(group["remainingBytes"]) + size_bytes
        if row["has_blocker"] == "yes":
            group["blockerCount"] = int(group["blockerCount"]) + 1
        if row["uses_custom_flags"] == "yes":
            group["customFlagsCount"] = int(group["customFlagsCount"]) + 1

    group_list = sorted(groups.values(), key=lambda item: (-int(item["valueBytes"]), str(item["name"]).lower()))
    for group in group_list:
        group["children"] = sorted(
            group["children"],
            key=lambda item: (-int(item["sizeBytes"]), -int(item["asmLines"]), str(item["va"])),
        )
        function_count = int(group["functionCount"])
        value_bytes = int(group["valueBytes"])
        completed_count = int(group["completedCount"])
        completed_bytes = int(group["completedBytes"])
        group["progressFunctions"] = 0.0 if function_count == 0 else round((completed_count / function_count) * 100.0, 2)
        group["progressBytes"] = 0.0 if value_bytes == 0 else round((completed_bytes / value_bytes) * 100.0, 2)
        group["dominantBucket"] = max(BUCKET_ORDER, key=lambda name: (int(group["bucketCounts"][name]), int(group["bucketBytes"][name])))
    return group_list


def dashboard_payload(rows: list[dict[str, str]], generated_at: str | None = None) -> dict[str, object]:
    normal_rows = [row for row in rows if row["corpus_bucket"] == "normal"]
    excluded_rows = [row for row in rows if row["corpus_bucket"] != "normal"]

    total_functions = len(normal_rows)
    total_bytes = sum(to_int(row["size_bytes"]) for row in normal_rows)
    completed_functions = sum(1 for row in normal_rows if row["source_bucket"] in COMPLETED_PROGRESS_BUCKETS)
    completed_bytes = sum(to_int(row["size_bytes"]) for row in normal_rows if row["source_bucket"] in COMPLETED_PROGRESS_BUCKETS)
    remaining_functions = sum(1 for row in normal_rows if row["is_remaining"] == "yes")
    remaining_bytes = sum(to_int(row["size_bytes"]) for row in normal_rows if row["is_remaining"] == "yes")
    logic_review_functions = sum(1 for row in normal_rows if row.get("has_logic_review") == "yes")
    logic_review_in_progress = sum(
        1
        for row in normal_rows
        if row.get("has_logic_review") == "yes" and row["source_bucket"] == "scratch"
    )

    bucket_counts = {bucket: sum(1 for row in normal_rows if row["source_bucket"] == bucket) for bucket in BUCKET_ORDER}
    bucket_bytes = {bucket: sum(to_int(row["size_bytes"]) for row in normal_rows if row["source_bucket"] == bucket) for bucket in BUCKET_ORDER}
    corpus_counts = {bucket: sum(1 for row in rows if row["corpus_bucket"] == bucket) for bucket in CORPUS_ORDER}

    progress_functions = 0.0 if total_functions == 0 else (completed_functions / total_functions) * 100.0
    progress_bytes = 0.0 if total_bytes == 0 else (completed_bytes / total_bytes) * 100.0

    summary = {
        "totalFunctions": total_functions,
        "completedFunctions": completed_functions,
        "remainingFunctions": remaining_functions,
        "totalBytes": total_bytes,
        "completedBytes": completed_bytes,
        "remainingBytes": remaining_bytes,
        "logicReviewFunctions": logic_review_functions,
        "logicReviewInProgress": logic_review_in_progress,
        "progressFunctions": round(progress_functions, 2),
        "progressBytes": round(progress_bytes, 2),
        "bucketCounts": bucket_counts,
        "bucketBytes": bucket_bytes,
        "bucketOrder": BUCKET_ORDER,
        "bucketColors": BUCKET_COLORS,
        "corpusCounts": corpus_counts,
        "corpusOrder": CORPUS_ORDER,
        "excludedFunctions": len(excluded_rows),
        "excludedBytes": sum(to_int(row["size_bytes"]) for row in excluded_rows),
    }

    return {
        "generatedAt": generated_at or datetime.now().isoformat(timespec="seconds"),
        "summary": summary,
        "groups": build_group_list(normal_rows),
    }


def _load_embedded_history(html_path: Path) -> dict[str, object] | None:
    """Read the previous timeline without rebuilding Git history.

    ``--no-history`` is used for quick refreshes. It must not erase a timeline
    that a previous full refresh already wrote to the dashboard.
    """
    try:
        html_text = html_path.read_text(encoding="utf-8")
    except (OSError, MemoryError):
        return None

    marker = "const DATA = "
    marker_start = html_text.find(marker)
    if marker_start < 0:
        return None

    try:
        data, _ = json.JSONDecoder().raw_decode(html_text[marker_start + len(marker):])
    except (json.JSONDecodeError, MemoryError, TypeError):
        return None
    if not isinstance(data, dict):
        return None
    history = data.get("history")
    return history if isinstance(history, dict) else None


def _remove_live_snapshots(history: dict[str, object]) -> None:
    """Remove working-tree snapshots before replacing the current one."""
    commits = history.get("commits")
    deltas = history.get("deltas")
    if not isinstance(commits, list) or not isinstance(deltas, list):
        raise ValueError("dashboard history has no valid commit/delta arrays")
    if len(commits) != len(deltas):
        raise ValueError("dashboard history commit/delta lengths do not match")

    while commits and isinstance(commits[-1], dict) and commits[-1].get("workingTree"):
        commits.pop()
        deltas.pop()


def write_html_dashboard(
    rows: list[dict[str, str]],
    *,
    history_ref: str = "HEAD",
    include_history: bool = True,
) -> Path:
    DASHBOARD_DIR.mkdir(parents=True, exist_ok=True)
    html_path = DASHBOARD_DIR / "project_full_status.html"
    payload = dashboard_payload(rows)

    if include_history:
        commits = subprocess.check_output(
            ["git", "rev-list", "--reverse", "--first-parent", history_ref],
            cwd=REPO_ROOT,
            text=True,
        ).splitlines()
        history_cache_path = REPO_ROOT / "build" / "status_history_cache.json"
        cache_key = {"version": HISTORY_CACHE_VERSION, "ref": history_ref, "commits": commits}
        history = None
        resume = None
        prefix_history = None
        migrated_cache = False
        if history_cache_path.exists():
            try:
                cached = json.loads(history_cache_path.read_text(encoding="utf-8"))
                if cached.get("key") == cache_key:
                    history = cached.get("history")
                else:
                    # Reuse the cached prefix when the repo only advanced: the new
                    # commit list is a strict extension of the cached one.
                    cached_key = cached.get("key") or {}
                    cached_commits = cached_key.get("commits") or []
                    cache_is_prefix = (
                        cached_key.get("ref") == history_ref
                        and len(cached_commits) <= len(commits)
                        and commits[: len(cached_commits)] == cached_commits
                    )
                    if cached_key.get("version") in {6, 7, 10, 11} and cache_is_prefix:
                        candidate_history = cached.get("history")
                        candidate = cached.get("resume")
                        if (
                            isinstance(candidate_history, dict)
                            and isinstance(candidate, dict)
                            and candidate.get("processed") == len(cached_commits)
                        ):
                            if len(cached_commits) == len(commits):
                                history = candidate_history
                                resume = candidate
                            else:
                                resume = candidate
                                prefix_history = candidate_history
                    elif (
                        cached_key.get("version") == HISTORY_CACHE_VERSION
                        and len(cached_commits) < len(commits)
                        and cache_is_prefix
                    ):
                        candidate = cached.get("resume")
                        if isinstance(candidate, dict) and candidate.get("processed") == len(cached_commits):
                            resume = candidate
                            prefix_history = cached.get("history")
            except (OSError, json.JSONDecodeError):
                history = None
                resume = None
                prefix_history = None
        if history is None:
            history, resume = build_history(
                commits,
                lambda historical_rows: build_group_list(
                    [row for row in historical_rows if row["corpus_bucket"] == "normal"]
                ),
                lambda historical_rows: dashboard_payload(historical_rows)["summary"],
                resume=resume,
                prefix_history=prefix_history,
            )
            migrated_cache = True
        upgrade_history_diff_metrics(history, resume)
        migrated_cache = True
        if migrated_cache:
            history_cache_path.parent.mkdir(parents=True, exist_ok=True)
            cache_text = json.dumps(
                {"key": cache_key, "history": history, "resume": resume},
                ensure_ascii=False,
                separators=(",", ":"),
            )
            cache_tmp_path = history_cache_path.with_suffix(".json.tmp")
            cache_tmp_path.write_text(cache_text, encoding="utf-8")
            cache_tmp_path.replace(history_cache_path)
        payload["history"] = append_live_snapshot(
            history,
            build_group_list([row for row in rows if row["corpus_bucket"] == "normal"]),
            payload["summary"],
            str(payload["generatedAt"]),
        )
        # The history owns the full snapshots. Keeping another copy of the current
        # treemap here would defeat the point of storing only changes between commits.
        payload.pop("groups", None)
    else:
        # A quick refresh still writes the main dashboard. Reuse its last timeline
        # instead of replacing it with a historyless payload. The next full refresh
        # will recover any commits added since this quick refresh from the cache.
        previous_history = _load_embedded_history(html_path)
        if previous_history is not None:
            try:
                _remove_live_snapshots(previous_history)
                payload["history"] = append_live_snapshot(
                    previous_history,
                    build_group_list([row for row in rows if row["corpus_bucket"] == "normal"]),
                    payload["summary"],
                    str(payload["generatedAt"]),
                )
                payload.pop("groups", None)
            except (KeyError, MemoryError, TypeError, ValueError):
                # Keep the current-only dashboard if an old or damaged dashboard
                # cannot supply a reusable history payload.
                pass

    html_template = HTML_TEMPLATE_PATH.read_text(encoding="utf-8")
    marker_count = html_template.count(DATA_MARKER)
    if marker_count != 1:
        raise RuntimeError(f"dashboard template must contain exactly one {DATA_MARKER} marker (found {marker_count})")
    html_text = html_template.replace(
        DATA_MARKER,
        json.dumps(payload, ensure_ascii=False, separators=(",", ":")),
    )
    # A complete dashboard is tens of megabytes. Replace it atomically so an
    # interrupted refresh cannot leave the dashboard half-written.
    html_tmp_path = html_path.with_suffix(".html.tmp")
    html_tmp_path.write_text(html_text, encoding="utf-8")
    html_tmp_path.replace(html_path)
    return html_path


def main() -> None:
    parser = argparse.ArgumentParser(description="Generate the current status dashboard and its commit timeline.")
    parser.add_argument(
        "--no-history",
        action="store_true",
        help="write a quick refresh without rebuilding history; preserve an existing timeline",
    )
    parser.add_argument("--history-ref", default="HEAD", help="commit/ref whose first-parent history becomes the timeline (default: HEAD)")
    args = parser.parse_args()

    rows = build_status_rows()
    DASHBOARD_DIR.mkdir(parents=True, exist_ok=True)
    output_path = DASHBOARD_DIR / "project_full_status.csv"
    csv_tmp_path = output_path.with_suffix(".csv.tmp")
    write_status_csv(rows, csv_tmp_path)
    csv_tmp_path.replace(output_path)
    add_live_source_fingerprints(rows)
    metrics_output = write_compact_metrics(rows)
    if not args.no_history:
        subprocess.run(
            [
                sys.executable,
                str(REPO_ROOT / "tools" / "backfill_status_metrics.py"),
                "--incremental",
                "--ref",
                args.history_ref,
            ],
            cwd=REPO_ROOT,
            check=True,
        )
    html_output_path = write_html_dashboard(rows, history_ref=args.history_ref, include_history=not args.no_history)
    counts = status_counts(rows)

    print(f"Wrote {output_path}")
    print(f"Wrote {metrics_output}")
    print(f"Wrote {html_output_path}")
    print(
        "Counts: "
        f"matching={counts['matching']} "
        f"accepted_drift={counts['accepted_drift']} "
        f"verified_logic={counts['verified_logic']} "
        f"scratch={counts['scratch']} "
        f"unclaimed={counts['unclaimed']} "
        f"conflict={counts['conflict']} "
        f"normal={counts['normal']} "
        f"padding_only={counts['padding_only']} "
        f"compiler_generated={counts['compiler_generated']} "
        f"parent_owned_fragment={counts['parent_owned_fragment']} "
        f"toolchain_supplied={counts['toolchain_supplied']} "
        f"asm_special={counts['asm_special']} "
        f"asm_region={counts['asm_region']}"
    )


if __name__ == "__main__":
    main()
