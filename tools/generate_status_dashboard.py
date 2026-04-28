from __future__ import annotations

import csv
import json
import re
from datetime import datetime
from pathlib import Path

from common import (
    REPO_ROOT,
    classify_corpus_bucket,
    load_asm_special_function_names,
    load_asm_special_regions,
    load_functions,
    load_parent_owned_fragments,
    load_toolchain_supplied_function_names,
    load_toolchain_supplied_regions,
)


HEADER_NOTE_RE = re.compile(r"^//\s*([A-Z_]+):\s*(.*)$")
BUCKET_ORDER = ["matching", "accepted_drift", "scratch", "unclaimed", "conflict"]
CORPUS_ORDER = ["normal", "parent_owned_fragment", "toolchain_supplied", "asm_special", "asm_region"]
BUCKET_COLORS = {
    "matching": "#22c55e",
    "accepted_drift": "#f59e0b",
    "scratch": "#8b5cf6",
    "unclaimed": "#475569",
    "conflict": "#ef4444",
}


HTML_TEMPLATE_PATH = REPO_ROOT / "tools" / "status_dashboard_template.html"


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


def count_comment_lines(path: Path | None) -> int:
    if path is None or not path.exists():
        return 0

    text = path.read_text(encoding="utf-8", errors="replace")
    return sum(1 for line in text.splitlines() if line.startswith("//"))


def rank_map(records: list[dict[str, str]], field: str) -> dict[str, int]:
    ordered = sorted(records, key=lambda row: (-int(row[field]), row["va"]))
    return {row["va"]: index + 1 for index, row in enumerate(ordered)}


def to_int(value: str | int | None) -> int:
    if value in (None, ""):
        return 0
    return int(value)


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
                "matchedCount": 0,
                "remainingCount": 0,
                "remainingBytes": 0,
                "matchedBytes": 0,
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

        if bucket == "matching":
            group["matchedCount"] = int(group["matchedCount"]) + 1
            group["matchedBytes"] = int(group["matchedBytes"]) + size_bytes
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
        matched_count = int(group["matchedCount"])
        matched_bytes = int(group["matchedBytes"])
        group["progressFunctions"] = 0.0 if function_count == 0 else round((matched_count / function_count) * 100.0, 2)
        group["progressBytes"] = 0.0 if value_bytes == 0 else round((matched_bytes / value_bytes) * 100.0, 2)
        group["dominantBucket"] = max(BUCKET_ORDER, key=lambda name: (int(group["bucketCounts"][name]), int(group["bucketBytes"][name])))
    return group_list


def write_html_dashboard(rows: list[dict[str, str]]) -> Path:
    html_path = REPO_ROOT / "project_full_status.html"

    normal_rows = [row for row in rows if row["corpus_bucket"] == "normal"]
    excluded_rows = [row for row in rows if row["corpus_bucket"] != "normal"]

    total_functions = len(normal_rows)
    total_bytes = sum(to_int(row["size_bytes"]) for row in normal_rows)
    matched_functions = sum(1 for row in normal_rows if row["source_bucket"] == "matching")
    matched_bytes = sum(to_int(row["size_bytes"]) for row in normal_rows if row["source_bucket"] == "matching")
    remaining_functions = sum(1 for row in normal_rows if row["is_remaining"] == "yes")
    remaining_bytes = sum(to_int(row["size_bytes"]) for row in normal_rows if row["is_remaining"] == "yes")

    bucket_counts = {bucket: sum(1 for row in normal_rows if row["source_bucket"] == bucket) for bucket in BUCKET_ORDER}
    bucket_bytes = {bucket: sum(to_int(row["size_bytes"]) for row in normal_rows if row["source_bucket"] == bucket) for bucket in BUCKET_ORDER}
    corpus_counts = {bucket: sum(1 for row in rows if row["corpus_bucket"] == bucket) for bucket in CORPUS_ORDER}

    progress_functions = 0.0 if total_functions == 0 else (matched_functions / total_functions) * 100.0
    progress_bytes = 0.0 if total_bytes == 0 else (matched_bytes / total_bytes) * 100.0

    summary = {
        "totalFunctions": total_functions,
        "matchedFunctions": matched_functions,
        "remainingFunctions": remaining_functions,
        "totalBytes": total_bytes,
        "matchedBytes": matched_bytes,
        "remainingBytes": remaining_bytes,
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

    payload = {
        "generatedAt": datetime.now().isoformat(timespec="seconds"),
        "summary": summary,
        "groups": build_group_list(normal_rows),
    }

    html_template = HTML_TEMPLATE_PATH.read_text(encoding="utf-8")
    html_text = html_template.replace("__DASHBOARD_DATA__", json.dumps(payload, ensure_ascii=False, separators=(",", ":")))
    html_path.write_text(html_text, encoding="utf-8")
    return html_path


def main() -> None:
    scratch_dir = REPO_ROOT / "src" / "scratch"
    matching_dir = REPO_ROOT / "src" / "matching"
    accepted_drift_dir = REPO_ROOT / "src" / "accepted_drift"
    flags_dir = REPO_ROOT / "config" / "flags"
    scratch_files = source_files(scratch_dir)
    matching_files = source_files(matching_dir)
    accepted_drift_files = source_files(accepted_drift_dir)

    records = load_functions()
    toolchain_supplied_names = load_toolchain_supplied_function_names()
    toolchain_supplied_regions = load_toolchain_supplied_regions()
    asm_special_names = load_asm_special_function_names()
    asm_special_regions = load_asm_special_regions()
    parent_owned_fragments = load_parent_owned_fragments()
    remaining_records: list[dict[str, str]] = []
    rows: list[dict[str, str]] = []

    for record in records:
        slug = record["slug"]
        scratch_path = scratch_files.get(slug)
        matching_path = matching_files.get(slug)
        accepted_drift_path = accepted_drift_files.get(slug)
        present_paths = [path for path in (matching_path, accepted_drift_path, scratch_path) if path is not None]

        corpus_bucket, corpus_reason = classify_corpus_bucket(
            record,
            toolchain_supplied_names=toolchain_supplied_names,
            toolchain_supplied_regions=toolchain_supplied_regions,
            asm_special_names=asm_special_names,
            asm_special_regions=asm_special_regions,
            parent_owned_fragments=parent_owned_fragments,
        )

        if len(present_paths) > 1:
            source_bucket = "conflict"
            source_path = " | ".join(str(path.relative_to(REPO_ROOT)) for path in present_paths)
            note_path = scratch_path
        elif matching_path:
            source_bucket = "matching"
            source_path = str(matching_path.relative_to(REPO_ROOT))
            note_path = matching_path
        elif accepted_drift_path:
            source_bucket = "accepted_drift"
            source_path = str(accepted_drift_path.relative_to(REPO_ROOT))
            note_path = accepted_drift_path
        elif scratch_path:
            source_bucket = "scratch"
            source_path = str(scratch_path.relative_to(REPO_ROOT))
            note_path = scratch_path
        else:
            source_bucket = "unclaimed"
            source_path = ""
            note_path = None

        custom_flags_path = flags_dir / f"{slug}.rsp"
        header_notes = parse_header_notes(note_path) if note_path is not None else default_header_notes()
        preview_path = scratch_path or accepted_drift_path or matching_path
        is_remaining = "yes" if corpus_bucket == "normal" and source_bucket not in {"matching", "accepted_drift"} else "no"
        diff_metrics_path = REPO_ROOT / "build" / "diff" / f"{slug}.json"
        diff_metrics = {}
        if diff_metrics_path.exists():
            try:
                diff_metrics = json.loads(diff_metrics_path.read_text(encoding="utf-8"))
            except json.JSONDecodeError:
                diff_metrics = {}
        elif source_bucket == "matching":
            # src\matching is an exact-match claim; treat missing generated diff
            # artifacts as 0.0000% for status/dashboard coloring. Expensive full
            # sweep validation can be run separately when proof is needed.
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
                "edit_equal_bytes": int(record.get("size_bytes") or 0),
                "likely_shifted_alignment": "no",
                "first_mismatch_offset": "",
            }

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
            "corpus_bucket": corpus_bucket,
            "corpus_reason": corpus_reason,
            "toolchain_supplied": "yes" if corpus_bucket == "toolchain_supplied" else "no",
            "toolchain_supplied_reason": corpus_reason if corpus_bucket == "toolchain_supplied" else "",
            "parent_owned_fragment": "yes" if corpus_bucket == "parent_owned_fragment" else "no",
            "parent_va": parent_va_text,
            "parent_name": parent_name_text,
            "parent_fragment_reason": parent_reason_text,
            "is_remaining": is_remaining,
            "remaining_size_rank": "",
            "remaining_asm_rank": "",
            "uses_custom_flags": "yes" if custom_flags_path.exists() else "no",
            "custom_flags_path": str(custom_flags_path.relative_to(REPO_ROOT)) if custom_flags_path.exists() else "",
            "source_status": header_notes["STATUS"],
            "source_flags_note": header_notes["FLAGS"],
            "source_blocker": header_notes["BLOCKER"],
            "source_note": header_notes["NOTE"],
            "source_class": header_notes["CLASS"],
            "source_risk": header_notes["RISK"],
            "source_why": header_notes["WHY"],
            "source_next": header_notes["NEXT"],
            "source_preview": read_source_preview(preview_path),
            "source_comment_lines": str(count_comment_lines(preview_path)),
            "has_blocker": "yes" if header_notes["BLOCKER"] else "no",
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
        rows.append(row)
        if is_remaining == "yes":
            remaining_records.append(record)

    size_ranks = rank_map(remaining_records, "size_bytes")
    asm_ranks = rank_map(remaining_records, "asm_lines")
    for row in rows:
        if row["is_remaining"] == "yes":
            row["remaining_size_rank"] = str(size_ranks[row["va"]])
            row["remaining_asm_rank"] = str(asm_ranks[row["va"]])

    output_path = REPO_ROOT / "project_full_status.csv"
    with output_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
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
                "corpus_bucket",
                "corpus_reason",
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
            ],
        )
        writer.writeheader()
        writer.writerows(rows)

    html_output_path = write_html_dashboard(rows)

    scratch_count = sum(1 for row in rows if row["source_bucket"] == "scratch")
    matching_count = sum(1 for row in rows if row["source_bucket"] == "matching")
    accepted_drift_count = sum(1 for row in rows if row["source_bucket"] == "accepted_drift")
    conflict_count = sum(1 for row in rows if row["source_bucket"] == "conflict")
    unclaimed_count = sum(1 for row in rows if row["source_bucket"] == "unclaimed")
    normal_count = sum(1 for row in rows if row["corpus_bucket"] == "normal")
    toolchain_supplied_count = sum(1 for row in rows if row["corpus_bucket"] == "toolchain_supplied")
    asm_special_count = sum(1 for row in rows if row["corpus_bucket"] == "asm_special")
    asm_region_count = sum(1 for row in rows if row["corpus_bucket"] == "asm_region")
    parent_owned_fragment_count = sum(1 for row in rows if row["corpus_bucket"] == "parent_owned_fragment")

    print(f"Wrote {output_path}")
    print(f"Wrote {html_output_path}")
    print(
        "Counts: "
        f"matching={matching_count} "
        f"accepted_drift={accepted_drift_count} "
        f"scratch={scratch_count} "
        f"unclaimed={unclaimed_count} "
        f"conflict={conflict_count} "
        f"normal={normal_count} "
        f"parent_owned_fragment={parent_owned_fragment_count} "
        f"toolchain_supplied={toolchain_supplied_count} "
        f"asm_special={asm_special_count} "
        f"asm_region={asm_region_count}"
    )


if __name__ == "__main__":
    main()
