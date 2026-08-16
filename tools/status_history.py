from __future__ import annotations

import csv
import io
import re
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Callable

from common import REPO_ROOT, classify_corpus_bucket
from status_core import count_comment_lines_text


HEADER_NOTE_RE = re.compile(r"^//\s*([A-Z_]+):\s*(.*)$")
SOURCE_DIRS = ("matching", "accepted_drift", "verified_logic", "scratch")
NOTE_KEYS = ("STATUS", "FLAGS", "BLOCKER", "NOTE", "CLASS", "RISK", "WHY", "NEXT")
# The browser stores changed function records as compact value arrays. Keeping
# this schema in the generated artifact makes additions full records and later
# commits true field-level patches instead of repeating JSON property names.
CHILD_FIELDS = (
    "va", "name", "slug", "sizeBytes", "asmLines", "callingConvention", "bucket",
    "sourcePath", "logicReviewPath", "sourceStatus", "sourceFlagsNote", "sourceBlocker",
    "sourceNote", "sourceClass", "sourceRisk", "sourceWhy", "sourceNext", "sourcePreviewId",
    "sourceCommentLines", "diffPercent", "diffBytes", "diffSpans", "positionalDiffPercent",
    "positionalDiffBytes", "positionalDiffSpans", "editDiffPercent", "editDiffBytes",
    "editInsertBytes", "editDeleteBytes", "editReplaceBytes", "editEqualBytes",
    "likelyShiftedAlignment", "firstMismatchOffset", "usesCustomFlags", "customFlagsPath",
    "isRemaining", "remainingSizeRank", "remainingAsmRank", "hasBlocker", "groupName", "groupPath",
    "diffResult",
)
DIFF_CHILD_FIELDS = (
    "diffPercent", "diffBytes", "diffSpans", "positionalDiffPercent",
    "positionalDiffBytes", "positionalDiffSpans", "editDiffPercent",
    "editDiffBytes", "editInsertBytes", "editDeleteBytes", "editReplaceBytes",
    "editEqualBytes", "likelyShiftedAlignment", "firstMismatchOffset", "diffResult",
)


def _default_notes() -> dict[str, str]:
    return {key: "" for key in NOTE_KEYS}


def _parse_notes(text: str) -> dict[str, str]:
    notes = _default_notes()
    for line in text.splitlines():
        stripped = line.strip()
        if not stripped:
            continue
        if not stripped.startswith("//"):
            break
        match = HEADER_NOTE_RE.match(stripped)
        if match is None or match.group(1) not in notes:
            continue
        key, value = match.group(1), match.group(2).strip()
        if key == "NOTE" and notes[key]:
            notes[key] += " | " + value
        else:
            notes[key] = value
    return notes


def _source_preview(text: str, max_lines: int = 140, max_chars: int = 12000) -> str:
    if len(text) > max_chars:
        text = text[:max_chars]
    lines = text.splitlines()
    if len(lines) > max_lines:
        lines = lines[:max_lines]
        lines.append("// ... truncated ...")
    return "\n".join(lines)


def _comment_lines(text: str) -> int:
    return count_comment_lines_text(text)


def _manifest_names(text: str) -> set[str]:
    return {line.strip() for line in text.splitlines() if line.strip() and not line.strip().startswith("#")}


def _manifest_regions(text: str) -> list[tuple[int, int, str]]:
    regions: list[tuple[int, int, str]] = []
    for raw in text.splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 1)
        start_text, end_text = parts[0].split("-", 1)
        regions.append((int(start_text, 16), int(end_text, 16), parts[1].strip() if len(parts) > 1 else ""))
    return regions


def _manifest_fragments(text: str) -> dict[int, tuple[int, str, str]]:
    fragments: dict[int, tuple[int, str, str]] = {}
    for raw in text.splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 3)
        if len(parts) < 2:
            continue
        fragment = int(parts[0], 16)
        parent = int(parts[1], 16)
        fragments[fragment] = (parent, parts[2] if len(parts) >= 3 else "", parts[3] if len(parts) >= 4 else "")
    return fragments


def _manifest_va_reasons(text: str) -> dict[int, str]:
    entries: dict[int, str] = {}
    for raw in text.splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split(None, 1)
        entries[int(parts[0], 16)] = parts[1].strip() if len(parts) > 1 else ""
    return entries


def _zero_diff(record: dict[str, str]) -> dict[str, object]:
    size = int(record.get("size_bytes") or 0)
    return {
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
        "edit_equal_bytes": size,
        "likely_shifted_alignment": False,
        "first_mismatch_offset": "",
    }


def _to_int(value: object) -> int:
    return int(value) if value not in (None, "") else 0


def _to_float(value: object) -> float:
    return float(value) if value not in (None, "") else 0.0


def _csv_diff_values(row: dict[str, str]) -> dict[str, object]:
    result = row.get("diff_result", "")
    return {
        "diffPercent": _to_float(row.get("diff_percent")),
        "diffBytes": _to_int(row.get("diff_bytes")),
        "diffSpans": _to_int(row.get("diff_spans")),
        "positionalDiffPercent": _to_float(row.get("positional_diff_percent") or row.get("diff_percent")),
        "positionalDiffBytes": _to_int(row.get("positional_diff_bytes") or row.get("diff_bytes")),
        "positionalDiffSpans": _to_int(row.get("positional_diff_spans") or row.get("diff_spans")),
        "editDiffPercent": _to_float(row.get("edit_diff_percent") or row.get("diff_percent")),
        "editDiffBytes": _to_int(row.get("edit_diff_bytes") or row.get("diff_bytes")),
        "editInsertBytes": _to_int(row.get("edit_insert_bytes")),
        "editDeleteBytes": _to_int(row.get("edit_delete_bytes")),
        "editReplaceBytes": _to_int(row.get("edit_replace_bytes")),
        "editEqualBytes": _to_int(row.get("edit_equal_bytes")),
        "likelyShiftedAlignment": row.get("likely_shifted_alignment", "") == "yes",
        "firstMismatchOffset": row.get("first_mismatch_offset", ""),
        "diffResult": result,
    }


def _unknown_diff_values(bucket: str) -> dict[str, object]:
    values = {field: 0 for field in DIFF_CHILD_FIELDS}
    values["likelyShiftedAlignment"] = False
    values["firstMismatchOffset"] = ""
    values["diffResult"] = "MATCH" if bucket == "matching" else ""
    return values


@dataclass
class GitSnapshot:
    commit: str
    tree: dict[str, str]
    blob_cache: dict[str, bytes]

    @classmethod
    def load(cls, commit: str, blob_cache: dict[str, bytes]) -> "GitSnapshot":
        raw = subprocess.check_output(
            ["git", "ls-tree", "-r", "-z", commit], cwd=REPO_ROOT, text=False
        )
        tree: dict[str, str] = {}
        for record in raw.split(b"\0"):
            if not record:
                continue
            header, path_bytes = record.split(b"\t", 1)
            _mode, _kind, oid = header.split()
            tree[path_bytes.decode("utf-8", errors="surrogateescape")] = oid.decode("ascii")
        return cls(commit=commit, tree=tree, blob_cache=blob_cache)

    def read_bytes(self, path: str) -> bytes | None:
        oid = self.tree.get(path)
        if oid is None:
            return None
        cached = self.blob_cache.get(oid)
        if cached is not None:
            return cached
        reader = self.blob_cache.get("__batch__")
        if reader is not None:
            data = reader.read(oid)
            if data is None:
                # Batch streaming failed even after retries; fall back to a
                # one-off read, which is reliable for a single object.
                data = subprocess.check_output(
                    ["git", "cat-file", "blob", oid],
                    cwd=REPO_ROOT,
                    stderr=subprocess.DEVNULL,
                    text=False,
                )
        else:
            data = subprocess.check_output(
                ["git", "cat-file", "blob", oid],
                cwd=REPO_ROOT,
                stderr=subprocess.DEVNULL,
                text=False,
            )
        self.blob_cache[oid] = data
        return data

    def read_text(self, path: str) -> str:
        data = self.read_bytes(path)
        return "" if data is None else data.decode("utf-8", errors="replace")

    def direct_source_files(self, bucket: str) -> dict[str, str]:
        """Map lowercase stem -> git tree path.

        The repo contains files whose tracked path casing differs from the casing
        on disk (Windows checkout), while the inventory slug always uses the
        uppercase VA. Comparing lowercase stems keeps historical classification
        consistent with the live on-disk scan.
        """
        prefix = f"src/{bucket}/"
        result: dict[str, str] = {}
        for path in sorted(self.tree):
            if not path.startswith(prefix) or "/" in path[len(prefix):]:
                continue
            suffix = Path(path).suffix.lower()
            if suffix in {".c", ".cpp"}:
                result[Path(path).stem.lower()] = path
        return result


def build_historical_rows(snapshot: GitSnapshot) -> list[dict[str, str]]:
    inventory = snapshot.read_text("inventory/all_functions.csv")
    if not inventory:
        return []
    records = list(csv.DictReader(io.StringIO(inventory)))
    source_files = {bucket: snapshot.direct_source_files(bucket) for bucket in SOURCE_DIRS}
    names = {
        "toolchain": _manifest_names(snapshot.read_text("config/toolchain_supplied_functions.txt")),
        "asm": _manifest_names(snapshot.read_text("config/asm_special_functions.txt")),
    }
    regions = {
        "toolchain": _manifest_regions(snapshot.read_text("config/toolchain_supplied_regions.txt")),
        "asm": _manifest_regions(snapshot.read_text("config/asm_special_regions.txt")),
    }
    fragments = _manifest_fragments(snapshot.read_text("config/parent_owned_fragments.txt"))
    padding_only = _manifest_va_reasons(snapshot.read_text("config/padding_only_functions.txt"))
    status_csv_text = snapshot.read_text("project_full_status.csv")
    status_csv_rows = {
        row.get("va", "").upper(): row
        for row in csv.DictReader(io.StringIO(status_csv_text))
    } if status_csv_text else {}
    rows: list[dict[str, str]] = []
    remaining: list[dict[str, str]] = []

    for record in records:
        slug = record["slug"]
        paths = {bucket: source_files[bucket].get(slug.lower()) for bucket in SOURCE_DIRS}
        present = [paths[bucket] for bucket in ("matching", "accepted_drift", "verified_logic", "scratch") if paths[bucket]]
        if len(present) > 1:
            source_bucket = "conflict"
            source_path = " | ".join(present)
            note_path = paths["scratch"] or paths["verified_logic"] or paths["accepted_drift"] or paths["matching"]
        else:
            source_bucket = next((bucket for bucket in ("matching", "accepted_drift", "verified_logic", "scratch") if paths[bucket]), "unclaimed")
            source_path = paths[source_bucket] if source_bucket != "unclaimed" else ""
            note_path = paths["scratch"] or paths["verified_logic"] or paths["accepted_drift"] or paths["matching"]

        corpus_bucket, corpus_reason = classify_corpus_bucket(
            record,
            toolchain_supplied_names=names["toolchain"],
            toolchain_supplied_regions=regions["toolchain"],
            asm_special_names=names["asm"],
            asm_special_regions=regions["asm"],
            parent_owned_fragments=fragments,
            padding_only_functions=padding_only,
        )
        is_remaining = "yes" if corpus_bucket == "normal" and source_bucket not in {"matching", "accepted_drift", "verified_logic"} else "no"
        if is_remaining == "yes":
            remaining.append(record)

        source_text = snapshot.read_text(note_path) if note_path else ""
        notes = _parse_notes(source_text)
        logic_review_path = f"logic_reviews/{slug}.md"
        has_logic_review = snapshot.read_bytes(logic_review_path) is not None
        if source_bucket == "verified_logic" and not has_logic_review:
            missing = "verified_logic source has no logic-review ledger"
            notes["BLOCKER"] = f"{notes['BLOCKER']} | {missing}" if notes["BLOCKER"] else missing
        custom_flags_path = f"config/flags/{slug}.rsp"
        has_flags = snapshot.read_bytes(custom_flags_path) is not None
        parent = fragments.get(int(record["va"], 16))
        status_csv_row = status_csv_rows.get(record["va"].upper())
        if status_csv_row and status_csv_row.get("source_bucket") == source_bucket:
            diff = {
                "result": status_csv_row.get("diff_result", ""),
                "diff_percent": _to_float(status_csv_row.get("diff_percent")),
                "diff_bytes": _to_int(status_csv_row.get("diff_bytes")),
                "diff_spans": _to_int(status_csv_row.get("diff_spans")),
                "positional_diff_percent": _to_float(status_csv_row.get("positional_diff_percent") or status_csv_row.get("diff_percent")),
                "positional_diff_bytes": _to_int(status_csv_row.get("positional_diff_bytes") or status_csv_row.get("diff_bytes")),
                "positional_diff_spans": _to_int(status_csv_row.get("positional_diff_spans") or status_csv_row.get("diff_spans")),
                "edit_diff_percent": _to_float(status_csv_row.get("edit_diff_percent") or status_csv_row.get("diff_percent")),
                "edit_diff_bytes": _to_int(status_csv_row.get("edit_diff_bytes") or status_csv_row.get("diff_bytes")),
                "edit_insert_bytes": _to_int(status_csv_row.get("edit_insert_bytes")),
                "edit_delete_bytes": _to_int(status_csv_row.get("edit_delete_bytes")),
                "edit_replace_bytes": _to_int(status_csv_row.get("edit_replace_bytes")),
                "edit_equal_bytes": _to_int(status_csv_row.get("edit_equal_bytes")),
                "likely_shifted_alignment": status_csv_row.get("likely_shifted_alignment", "") == "yes",
                "first_mismatch_offset": status_csv_row.get("first_mismatch_offset", ""),
            }
        else:
            diff = _zero_diff(record) if source_bucket == "matching" else {}
        rows.append({
            "va": record["va"], "name": record["name"], "slug": slug,
            "size_bytes": record["size_bytes"], "asm_lines": record["asm_lines"],
            "calling_convention": record["calling_convention"],
            "pdb_source_file": record.get("pdb_source_file", ""),
            "pdb_source_path": record.get("pdb_source_path", ""),
            "source_bucket": source_bucket, "source_path": source_path,
            "logic_review_path": logic_review_path if has_logic_review else "",
            "has_logic_review": "yes" if has_logic_review else "no",
            "corpus_bucket": corpus_bucket, "corpus_reason": corpus_reason,
            "padding_only": "yes" if corpus_bucket == "padding_only" else "no",
            "padding_only_reason": corpus_reason if corpus_bucket == "padding_only" else "",
            "toolchain_supplied": "yes" if corpus_bucket == "toolchain_supplied" else "no",
            "toolchain_supplied_reason": corpus_reason if corpus_bucket == "toolchain_supplied" else "",
            "parent_owned_fragment": "yes" if corpus_bucket == "parent_owned_fragment" else "no",
            "parent_va": f"{parent[0]:08X}" if parent else "",
            "parent_name": parent[1] if parent else "",
            "parent_fragment_reason": parent[2] if parent else "",
            "is_remaining": is_remaining, "remaining_size_rank": "", "remaining_asm_rank": "",
            "uses_custom_flags": "yes" if has_flags else "no", "custom_flags_path": custom_flags_path if has_flags else "",
            "source_status": notes["STATUS"], "source_flags_note": notes["FLAGS"],
            "source_blocker": notes["BLOCKER"], "source_note": notes["NOTE"],
            "source_class": notes["CLASS"], "source_risk": notes["RISK"],
            "source_why": notes["WHY"], "source_next": notes["NEXT"],
            "source_preview": _source_preview(source_text), "source_comment_lines": str(_comment_lines(source_text)),
            "has_blocker": "yes" if notes["BLOCKER"] else "no",
            "diff_result": str(diff.get("result", "")),
            "diff_percent": f"{float(diff.get('diff_percent', 0.0)):.4f}" if diff else "",
            "diff_bytes": str(diff.get("diff_bytes", "")), "diff_spans": str(diff.get("diff_spans", "")),
            "positional_diff_percent": f"{float(diff.get('positional_diff_percent', 0.0)):.4f}" if diff else "",
            "positional_diff_bytes": str(diff.get("positional_diff_bytes", "")),
            "positional_diff_spans": str(diff.get("positional_diff_spans", "")),
            "edit_diff_percent": f"{float(diff.get('edit_diff_percent', 0.0)):.4f}" if diff else "",
            "edit_diff_bytes": str(diff.get("edit_diff_bytes", "")), "edit_insert_bytes": str(diff.get("edit_insert_bytes", "")),
            "edit_delete_bytes": str(diff.get("edit_delete_bytes", "")), "edit_replace_bytes": str(diff.get("edit_replace_bytes", "")),
            "edit_equal_bytes": str(diff.get("edit_equal_bytes", "")),
            "likely_shifted_alignment": "yes" if diff.get("likely_shifted_alignment") else ("no" if diff else ""),
            "first_mismatch_offset": str(diff.get("first_mismatch_offset", "")),
        })

    size_ranks = {row["va"]: index + 1 for index, row in enumerate(sorted(remaining, key=lambda row: (-int(row["size_bytes"]), row["va"]))) }
    asm_ranks = {row["va"]: index + 1 for index, row in enumerate(sorted(remaining, key=lambda row: (-int(row["asm_lines"]), row["va"]))) }
    for row in rows:
        if row["is_remaining"] == "yes":
            row["remaining_size_rank"] = str(size_ranks[row["va"]])
            row["remaining_asm_rank"] = str(asm_ranks[row["va"]])
    return rows


def _commit_metadata(commit: str) -> dict[str, object]:
    raw = subprocess.check_output(
        ["git", "show", "-s", "--format=%H%x00%h%x00%aI%x00%cI%x00%an%x00%ae%x00%P%x00%s", commit],
        cwd=REPO_ROOT,
        text=False,
    ).decode("utf-8", errors="replace").rstrip("\0\n")
    fields = raw.split("\0")
    full, short, author_date, commit_date, author, email, parents, subject = (fields + [""] * 8)[:8]
    return {
        "hash": full, "shortHash": short, "authorDate": author_date, "commitDate": commit_date,
        "author": author, "email": email, "parents": parents.split() if parents else [], "subject": subject,
    }


def _changed_paths(previous: dict[str, str], current: dict[str, str]) -> list[dict[str, str]]:
    changes: list[dict[str, str]] = []
    for path in sorted(set(previous) | set(current)):
        if previous.get(path) == current.get(path):
            continue
        changes.append({"status": "A" if path not in previous else ("D" if path not in current else "M"), "path": path})
    return changes


def _history_groups(rows: list[dict[str, str]], group_builder: Callable[[list[dict[str, str]]], list[dict[str, object]]]) -> list[dict[str, object]]:
    return group_builder(rows)


RELEVANT_PATHS = (
    "inventory/all_functions.csv",
    "config/toolchain_supplied_functions.txt",
    "config/toolchain_supplied_regions.txt",
    "config/asm_special_functions.txt",
    "config/asm_special_regions.txt",
    "config/parent_owned_fragments.txt",
    "config/padding_only_functions.txt",
    "project_full_status.csv",
)


class BatchBlobReader:
    """Persistent `git cat-file --batch` reader for fetching many blobs with one subprocess.

    Git-for-Windows can intermittently fail to stream a large packed blob to a pipe
    ("unable to stream ... to stdout"), so every read is verified and retried with a
    freshly spawned batch process before the caller falls back to a one-off command.
    """

    def __init__(self) -> None:
        self.proc = None
        self._spawn()

    def _spawn(self) -> None:
        self.proc = subprocess.Popen(
            ["git", "cat-file", "--batch"],
            cwd=REPO_ROOT,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            bufsize=0,
        )

    def _respawn(self) -> None:
        self._shutdown()
        self._spawn()

    def _shutdown(self) -> None:
        proc = self.proc
        if proc is not None:
            try:
                if proc.stdin is not None:
                    proc.stdin.close()
                if proc.stdout is not None:
                    proc.stdout.close()
                proc.wait(timeout=5)
            except Exception:
                proc.kill()
                try:
                    proc.wait(timeout=5)
                except Exception:
                    pass
        self.proc = None

    def read(self, oid: str) -> bytes | None:
        """Return blob bytes, or None when the object could not be streamed."""
        for _attempt in range(3):
            proc = self.proc
            if proc is None or proc.stdin is None or proc.stdout is None:
                self._spawn()
                continue
            try:
                proc.stdin.write(oid.encode("ascii") + b"\n")
                proc.stdin.flush()
                header = proc.stdout.readline()
                parts = header.split()
                if len(parts) == 3 and parts[1] != b"missing":
                    size = int(parts[2])
                    data = proc.stdout.read(size)
                    proc.stdout.read(1)  # trailing newline
                    if len(data) == size:
                        return data
            except Exception:
                pass
            self._respawn()
        return None

    def close(self) -> None:
        self._shutdown()


def _relevant_change(changed_files: list[dict[str, str]]) -> bool:
    return any(
        item["path"] in RELEVANT_PATHS
        or item["path"].startswith(("src/matching/", "src/accepted_drift/", "src/verified_logic/", "src/scratch/"))
        or item["path"].startswith("logic_reviews/")
        or item["path"].startswith("config/flags/")
        for item in changed_files
    )


def _empty_resume_state() -> dict[str, object]:
    return {
        "processed": 0,
        "previous_tree": {},
        "previous_children": {},
        "previous_rows": [],
        "previous_groups": [],
        "previous_summary": {},
        "previews": [],
        "preview_ids": {},
        "prefix_commits": [],
        "prefix_deltas": [],
        "base": None,
    }


def build_history(
    commits: list[str],
    group_builder: Callable[[list[dict[str, str]]], list[dict[str, object]]],
    summary_builder: Callable[[list[dict[str, str]]], dict[str, object]],
    resume: dict[str, object] | None = None,
    prefix_history: dict[str, object] | None = None,
) -> tuple[dict[str, object], dict[str, object]]:
    """Build the commit timeline payload, returning it plus a small resume state.

    ``resume`` (plus the previously generated ``prefix_history`` payload) may come
    from a previous call whose processed commit prefix equals ``commits[:processed]``.
    When the repository has only advanced (new commits appended), the cached prefix
    is reused and only the new commits are extracted, so regeneration after a few
    new commits is nearly instant.
    """
    if resume is not None and prefix_history is not None:
        state = {
            "processed": int(resume["processed"]),
            "previous_tree": resume.get("previous_tree", {}),
            "previous_children": resume.get("previous_children", {}),
            "previous_rows": [],
            "previous_groups": [],
            "previous_summary": resume.get("previous_summary", {}),
            "previews": prefix_history.get("sourcePreviews", []),
            "preview_ids": {},
            "prefix_commits": prefix_history.get("commits", []),
            "prefix_deltas": prefix_history.get("deltas", []),
            "base": prefix_history.get("base"),
        }
    else:
        state = _empty_resume_state()
    # Preview ids are assigned in order of first appearance, so they can be
    # reconstructed from the preview list alone (keeps the cache small).
    if not state["preview_ids"]:
        state["preview_ids"] = {preview: index for index, preview in enumerate(state["previews"])}
    blob_cache: dict[str, bytes] = {}
    batch_reader = BatchBlobReader()
    blob_cache["__batch__"] = batch_reader
    try:
        return _build_history_inner(commits, group_builder, summary_builder, state, blob_cache)
    finally:
        batch_reader.close()


def append_live_snapshot(
    history: dict[str, object],
    groups: list[dict[str, object]],
    summary: dict[str, object],
    generated_at: str,
) -> dict[str, object]:
    """Append current live rows without storing them in the commit cache."""
    schema = list(history.get("schema") or [])
    for field in CHILD_FIELDS:
        if field not in schema:
            schema.append(field)
    history["schema"] = schema

    previews: list[str] = list(history.get("sourcePreviews") or [])
    preview_ids = {preview: index for index, preview in enumerate(previews)}

    current_rows: dict[str, list[object]] = {}
    for group in groups:
        for raw_child in group.get("children", []):  # type: ignore[union-attr]
            child = dict(raw_child)  # type: ignore[arg-type]
            child["groupName"] = group.get("name", "")
            child["groupPath"] = group.get("path", "")
            preview = str(child.pop("sourcePreview", ""))
            if preview:
                if preview not in preview_ids:
                    preview_ids[preview] = len(previews)
                    previews.append(preview)
                child["sourcePreviewId"] = preview_ids[preview]
            row = [child.get(field) for field in schema]
            current_rows[str(child.get("va", ""))] = row

    previous_rows: dict[str, list[object]] = {}
    for group in (history.get("base") or {}).get("groups", []):  # type: ignore[union-attr]
        for child in group.get("children", []):
            previous_rows[str(child[0])] = list(child)
    for delta in history.get("deltas", []):  # type: ignore[union-attr]
        for change in delta.get("changes", []):
            va = str(change.get("va", ""))
            if "patch" in change:
                row = previous_rows.get(va)
                if row is None:
                    continue
                for field_index, value in change["patch"]:
                    while len(row) <= field_index:
                        row.append(None)
                    row[field_index] = value
            elif change.get("value") is None:
                previous_rows.pop(va, None)
            else:
                previous_rows[va] = list(change["value"])

    changes: list[dict[str, object]] = []
    for va in sorted(set(previous_rows) | set(current_rows)):
        old = previous_rows.get(va)
        current = current_rows.get(va)
        if current is None:
            changes.append({"va": va, "value": None})
        elif old is None:
            changes.append({"va": va, "value": current})
        else:
            patch = [
                [index, value]
                for index, value in enumerate(current)
                if (old[index] if index < len(old) else None) != value
            ]
            if patch:
                changes.append({"va": va, "patch": patch})

    commits = history.setdefault("commits", [])
    commits.append({  # type: ignore[union-attr]
        "hash": "WORKTREE",
        "shortHash": "working tree",
        "authorDate": generated_at,
        "commitDate": generated_at,
        "author": "",
        "email": "",
        "parents": [],
        "subject": "Current live project status",
        "index": len(commits),  # type: ignore[arg-type]
        "changedFiles": [],
        "summary": summary,
        "workingTree": True,
    })
    history.setdefault("deltas", []).append({"changes": changes})  # type: ignore[union-attr]
    history["sourcePreviews"] = previews
    return history


def upgrade_history_diff_metrics(
    history: dict[str, object],
    resume: dict[str, object] | None = None,
    csv_loader: Callable[[str], str] | None = None,
) -> None:
    """Add committed dashboard diff metrics to a version-6 history cache."""
    schema: list[str] = list(history.get("schema") or [])
    for field in CHILD_FIELDS:
        if field not in schema:
            schema.append(field)
    history["schema"] = schema
    field_indexes = {field: schema.index(field) for field in DIFF_CHILD_FIELDS}
    bucket_index = schema.index("bucket")

    rows: dict[str, list[object]] = {}
    base = history.get("base") or {}
    for group in base.get("groups", []):  # type: ignore[union-attr]
        for child in group.get("children", []):
            while len(child) < len(schema):
                child.append(None)
            rows[str(child[0])] = child

    def set_values(va: str, values: dict[str, object], delta: dict[str, object] | None) -> None:
        row = rows.get(va)
        if row is None:
            return
        if delta is not None:
            row = row.copy()
            rows[va] = row
        changed = {
            field_indexes[field]: value
            for field, value in values.items()
            if row[field_indexes[field]] != value
        }
        if not changed:
            return
        for index, value in changed.items():
            row[index] = value
        if delta is None:
            return

        changes = delta.setdefault("changes", [])
        existing = next((change for change in changes if change.get("va") == va), None)
        if existing is None:
            changes.append({"va": va, "patch": [[index, changed[index]] for index in sorted(changed)]})
        elif existing.get("value") is not None:
            value_row = existing["value"]
            while len(value_row) < len(schema):
                value_row.append(None)
            for index, value in changed.items():
                value_row[index] = value
        elif "patch" in existing:
            patch = {int(index): value for index, value in existing["patch"]}
            patch.update(changed)
            existing["patch"] = [[index, patch[index]] for index in sorted(patch)]

    for va, row in rows.items():
        set_values(va, _unknown_diff_values(str(row[bucket_index] or "")), None)

    batch_reader = None
    if csv_loader is None:
        batch_reader = BatchBlobReader()

        def csv_loader(commit: str) -> str:
            try:
                oid = subprocess.check_output(
                    ["git", "rev-parse", f"{commit}:project_full_status.csv"],
                    cwd=REPO_ROOT,
                    stderr=subprocess.DEVNULL,
                    text=True,
                ).strip()
            except subprocess.CalledProcessError:
                return ""
            data = batch_reader.read(oid)
            if data is None:
                try:
                    data = subprocess.check_output(
                        ["git", "cat-file", "blob", oid],
                        cwd=REPO_ROOT,
                        stderr=subprocess.DEVNULL,
                    )
                except subprocess.CalledProcessError:
                    return ""
            return "" if data is None else data.decode("utf-8", errors="replace")

    commits = history.get("commits", [])
    deltas = history.get("deltas", [])
    try:
        for commit_index, commit in enumerate(commits):
            delta = deltas[commit_index]
            if commit_index:
                prior_buckets: dict[str, object] = {}
                for change in list(delta.get("changes", [])):
                    va = str(change.get("va", ""))
                    old_row = rows.get(va)
                    prior_buckets[va] = old_row[bucket_index] if old_row else None
                    if "patch" in change:
                        if old_row is None:
                            continue
                        new_row = old_row.copy()
                        for index, value in change["patch"]:
                            while len(new_row) <= index:
                                new_row.append(None)
                            new_row[index] = value
                        while len(new_row) < len(schema):
                            new_row.append(None)
                        rows[va] = new_row
                    elif change.get("value") is None:
                        rows.pop(va, None)
                    else:
                        new_row = list(change["value"])
                        while len(new_row) < len(schema):
                            new_row.append(None)
                        rows[va] = new_row
                for va, prior_bucket in prior_buckets.items():
                    row = rows.get(va)
                    if row is not None and row[bucket_index] != prior_bucket:
                        set_values(va, _unknown_diff_values(str(row[bucket_index] or "")), delta)

            changed_files = commit.get("changedFiles", [])
            if not any(item.get("path") == "project_full_status.csv" for item in changed_files):
                continue
            text = csv_loader(str(commit.get("hash", "")))
            if not text:
                continue
            for csv_row in csv.DictReader(io.StringIO(text)):
                va = csv_row.get("va", "").upper()
                row = rows.get(va)
                if row is None or csv_row.get("source_bucket") != row[bucket_index]:
                    continue
                set_values(va, _csv_diff_values(csv_row), None if commit_index == 0 else delta)
    finally:
        if batch_reader is not None:
            batch_reader.close()

    if resume is not None:
        previous_children = resume.get("previous_children") or {}
        for va, child in previous_children.items():
            row = rows.get(str(va))
            if row is None:
                continue
            for field in DIFF_CHILD_FIELDS:
                child[field] = row[field_indexes[field]]


def _build_history_inner(
    commits: list[str],
    group_builder: Callable[[list[dict[str, str]]], list[dict[str, object]]],
    summary_builder: Callable[[list[dict[str, str]]], dict[str, object]],
    state: dict[str, object],
    blob_cache: dict[str, bytes],
) -> tuple[dict[str, object], dict[str, object]]:
    commits_out: list[dict[str, object]] = list(state["prefix_commits"])  # type: ignore[arg-type]
    deltas_out: list[dict[str, object]] = list(state["prefix_deltas"])  # type: ignore[arg-type]
    base: dict[str, object] | None = state["base"]  # type: ignore[assignment]
    previews: list[str] = state["previews"]  # type: ignore[assignment]
    preview_ids: dict[str, int] = state["preview_ids"]  # type: ignore[assignment]

    def compact_child(child: dict[str, object]) -> list[object]:
        return [child.get(field) for field in CHILD_FIELDS]

    def encode_groups(groups: list[dict[str, object]]) -> tuple[list[dict[str, object]], dict[str, dict[str, object]]]:
        encoded: list[dict[str, object]] = []
        all_children: dict[str, dict[str, object]] = {}
        for group in groups:
            children: list[dict[str, object]] = []
            for child in group["children"]:  # type: ignore[index]
                item = dict(child)  # type: ignore[arg-type]
                item["groupName"] = group["name"]
                item["groupPath"] = group.get("path", "")
                preview = str(item.pop("sourcePreview", ""))
                if preview:
                    if preview not in preview_ids:
                        preview_ids[preview] = len(previews)
                        previews.append(preview)
                    item["sourcePreviewId"] = preview_ids[preview]
                all_children[str(item["va"])] = item
                children.append(item)
            encoded.append({"name": group["name"], "path": group.get("path", ""), "children": children})
        return encoded, all_children

    start = int(state["processed"])
    for index in range(start, len(commits)):
        commit = commits[index]
        snapshot = GitSnapshot.load(commit, blob_cache)
        changed_files = _changed_paths(state["previous_tree"], snapshot.tree)  # type: ignore[arg-type]
        relevant_change = _relevant_change(changed_files)
        if index and not relevant_change and state["previous_rows"]:
            rows = state["previous_rows"]  # type: ignore[assignment]
            encoded_groups = state["previous_groups"]  # type: ignore[assignment]
            children = state["previous_children"]  # type: ignore[assignment]
        else:
            rows = build_historical_rows(snapshot)
            encoded_groups, children = encode_groups(_history_groups(rows, group_builder))
        changes = []
        previous_children = state["previous_children"]  # type: ignore[assignment]
        for va in sorted(set(previous_children) | set(children)):
            if previous_children.get(va) != children.get(va):
                current = children.get(va)
                if current is None:
                    changes.append({"va": va, "value": None})
                elif va not in previous_children:
                    changes.append({"va": va, "value": compact_child(current)})
                else:
                    old = previous_children[va]
                    patch = [
                        [field_index, current.get(field)]
                        for field_index, field in enumerate(CHILD_FIELDS)
                        if old.get(field) != current.get(field)
                    ]
                    changes.append({"va": va, "patch": patch})
        metadata = _commit_metadata(commit)
        metadata["index"] = index
        metadata["changedFiles"] = changed_files
        metadata["summary"] = state["previous_summary"] if index and not relevant_change else summary_builder(rows)
        commits_out.append(metadata)
        deltas_out.append({"changes": changes})
        if base is None:
            base = {
                "groups": [
                    {
                        "name": group["name"],
                        "path": group.get("path", ""),
                        "children": [compact_child(child) for child in group["children"]],  # type: ignore[index]
                    }
                    for group in encoded_groups
                ],
                "summary": metadata["summary"],
            }
        state["previous_children"] = children
        state["previous_rows"] = rows
        state["previous_groups"] = encoded_groups
        state["previous_summary"] = metadata["summary"]
        state["previous_tree"] = snapshot.tree

    state["processed"] = len(commits)
    payload = {
        "commits": commits_out,
        "schema": list(CHILD_FIELDS),
        "base": base if base is not None else {"groups": [], "summary": {}},
        "deltas": deltas_out,
        "sourcePreviews": previews,
    }
    # Keep the persistent resume state small: the bulky derived fields (rows,
    # groups, preview ids, prefix copies) are rebuilt or recovered from the
    # payload when a later run resumes from this point.
    resume_out = {
        "processed": len(commits),
        "previous_tree": state["previous_tree"],
        "previous_children": state["previous_children"],
        "previous_summary": state["previous_summary"],
    }
    return payload, resume_out
