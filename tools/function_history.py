from __future__ import annotations

import gzip
import hashlib
import json
import os
import re
import shutil
import time
import difflib
from collections import Counter
from contextlib import contextmanager
from datetime import datetime, timezone
from pathlib import Path
from typing import Iterable

from common import REPO_ROOT, function_slug, preferred_source_path


_HISTORY_VERSION = 1
_LABEL_RE = re.compile(r"^[A-Za-z0-9][A-Za-z0-9_.-]{0,63}$")


def _sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def _history_root(slug: str) -> Path:
    return REPO_ROOT / "build" / "history" / slug


def _index_path(slug: str) -> Path:
    return _history_root(slug) / "history.json"


def _load_index(slug: str) -> dict:
    path = _index_path(slug)
    if not path.exists():
        return {"version": _HISTORY_VERSION, "slug": slug, "labels": {}, "runs": []}
    payload = json.loads(path.read_text(encoding="utf-8"))
    payload.setdefault("version", _HISTORY_VERSION)
    payload.setdefault("slug", slug)
    payload.setdefault("labels", {})
    payload.setdefault("runs", [])
    return payload


def _write_index(slug: str, payload: dict) -> None:
    root = _history_root(slug)
    root.mkdir(parents=True, exist_ok=True)
    target = _index_path(slug)
    temporary = target.with_suffix(".json.tmp")
    temporary.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    temporary.replace(target)


@contextmanager
def _history_lock(slug: str):
    """Serialize same-function history updates across parallel agents."""
    root = _history_root(slug)
    root.mkdir(parents=True, exist_ok=True)
    lock_path = root / "history.lock"
    descriptor: int | None = None
    for _ in range(200):
        try:
            descriptor = os.open(lock_path, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
            os.write(descriptor, str(os.getpid()).encode("ascii"))
            break
        except FileExistsError:
            try:
                if time.time() - lock_path.stat().st_mtime > 300:
                    lock_path.unlink()
                    continue
            except FileNotFoundError:
                continue
            time.sleep(0.05)
    if descriptor is None:
        raise TimeoutError(f"Timed out waiting for history lock: {lock_path}")
    try:
        yield
    finally:
        os.close(descriptor)
        try:
            lock_path.unlink()
        except FileNotFoundError:
            pass


def _validate_label(label: str) -> str:
    value = label.strip()
    if not _LABEL_RE.fullmatch(value):
        raise ValueError("Checkpoint labels must start with an alphanumeric and contain only A-Z, a-z, 0-9, _, ., or -")
    return value


def _metric_objectives(metrics: dict) -> dict[str, float | int]:
    call_rows = list((metrics.get("call_alignment") or {}).get("rows") or [])
    hard_call_ops = sum(row.get("status") != "equal" for row in call_rows)
    call_gap = sum(abs(int(row.get("delta", 0))) for row in metrics.get("call_target_count_deltas") or [])
    original_flow = metrics.get("original_control_flow") or {}
    rebuilt_flow = metrics.get("rebuilt_control_flow") or {}
    cfg_gap = sum(
        abs(int(original_flow.get(key, 0)) - int(rebuilt_flow.get(key, 0)))
        for key in ("conditional_branches", "unconditional_branches", "returns")
    )
    extraction = metrics.get("rebuilt_extraction") or {}
    expected_size = extraction.get("expected_size_bytes")
    effective_size = extraction.get("effective_size_bytes", extraction.get("meaningful_size_bytes"))
    size_gap = 0 if expected_size is None or effective_size is None else abs(int(effective_size) - int(expected_size))
    shape = metrics.get("instruction_shape") or {}
    return {
        "exact_gate": 0 if metrics.get("result") == "MATCH" else 1,
        "wrong_direct_targets": len(metrics.get("relocation_target_mismatches") or []),
        "hard_call_operations": hard_call_ops,
        "call_count_gap": call_gap,
        "size_gap": size_gap,
        "cfg_gap": cfg_gap,
        "shape_gap": 100.0 - float(shape.get("similarity_percent", 0.0)),
        "positional_diff_bytes": int(metrics.get("diff_bytes", 0)),
    }


def _metric_summary(metrics: dict) -> dict[str, object]:
    call_map = metrics.get("call_alignment") or {}
    block_map = metrics.get("block_alignment") or {}
    extraction = metrics.get("rebuilt_extraction") or {}
    return {
        "result": metrics.get("result"),
        "diff_bytes": metrics.get("diff_bytes"),
        "diff_percent": metrics.get("diff_percent"),
        "resync_similarity_percent": metrics.get("resync_similarity_percent"),
        "shape_percent": (metrics.get("instruction_shape") or {}).get("similarity_percent"),
        "call_similarity_percent": call_map.get("similarity_percent"),
        "call_prefix": call_map.get("aligned_prefix_calls"),
        "block_coverage_percent": block_map.get("matched_coverage_percent"),
        "size_delta": None
        if extraction.get("expected_size_bytes") is None
        else int(extraction.get("effective_size_bytes", extraction.get("meaningful_size_bytes", 0)))
        - int(extraction["expected_size_bytes"]),
    }


def _dominates(left: dict, right: dict) -> bool:
    keys = (
        "exact_gate",
        "wrong_direct_targets",
        "hard_call_operations",
        "call_count_gap",
        "size_gap",
        "cfg_gap",
        "shape_gap",
        "positional_diff_bytes",
    )
    return all(float(left[key]) <= float(right[key]) for key in keys) and any(
        float(left[key]) < float(right[key]) for key in keys
    )


def _refresh_frontier(index: dict) -> None:
    runs = list(index.get("runs") or [])
    for run in runs:
        objectives = run.get("objectives") or {}
        run["pareto"] = bool(objectives) and not any(
            other is not run
            and other.get("objectives")
            and _dominates(other["objectives"], objectives)
            for other in runs
        )


def _artifact_candidates(slug: str, source_path: Path, custom_flags: Path) -> Iterable[tuple[Path, Path]]:
    yield source_path, Path("source") / source_path.name
    effective_flags = custom_flags if custom_flags.exists() else REPO_ROOT / "config" / "flags" / "default.rsp"
    if effective_flags.exists():
        yield effective_flags, Path("flags") / "effective.rsp"
    if custom_flags.exists():
        yield custom_flags, Path("flags") / custom_flags.name
    candidates = [
        REPO_ROOT / "build" / "obj" / f"{slug}.obj",
        REPO_ROOT / "build" / "asm" / f"rebuilt_{slug}.bin",
        REPO_ROOT / "build" / "asm" / f"rebuilt_{slug}.full.bin",
        REPO_ROOT / "build" / "asm" / f"rebuilt_{slug}.json",
        REPO_ROOT / "build" / "asm" / f"rebuilt_{slug}.txt",
        REPO_ROOT / "build" / "asm" / f"rebuilt_{slug}.lines.json",
        REPO_ROOT / "build" / "diff" / f"{slug}.json",
        REPO_ROOT / "build" / "diff" / f"{slug}.txt",
        REPO_ROOT / "build" / "manifests" / f"build_{slug}.json",
    ]
    for path in candidates:
        if path.exists():
            yield path, Path("artifacts") / path.relative_to(REPO_ROOT / "build")


def _copy_checkpoint_artifact(source: Path, run_dir: Path, relative: Path) -> None:
    target = run_dir / relative
    target.parent.mkdir(parents=True, exist_ok=True)
    if relative.parts and relative.parts[0] == "artifacts" and source.suffix.lower() in {".json", ".txt"}:
        compressed = target.with_suffix(target.suffix + ".gz")
        with source.open("rb") as source_handle, gzip.open(compressed, "wb", compresslevel=6) as target_handle:
            shutil.copyfileobj(source_handle, target_handle)
        if target.exists():
            target.unlink()
    else:
        shutil.copy2(source, target)


def _record_checkpoint_unlocked(record: dict[str, str], label: str | None = None) -> dict:
    """Persist the current source, generated artifacts, metrics, and Pareto state.

    Identical source/flags/rebuilt-byte runs are deduplicated.  Labels may be
    moved to an existing run without creating another artifact copy.
    """
    slug = function_slug(record)
    source_path = preferred_source_path(record)
    if not source_path.exists():
        raise FileNotFoundError(f"Missing source for history checkpoint: {source_path}")
    metrics_path = REPO_ROOT / "build" / "diff" / f"{slug}.json"
    rebuilt_path = REPO_ROOT / "build" / "asm" / f"rebuilt_{slug}.bin"
    if not metrics_path.exists() or not rebuilt_path.exists():
        raise FileNotFoundError("A completed check_function run is required before recording history")

    metrics = json.loads(metrics_path.read_text(encoding="utf-8"))
    custom_flags = REPO_ROOT / "config" / "flags" / f"{slug}.rsp"
    effective_flags = custom_flags if custom_flags.exists() else REPO_ROOT / "config" / "flags" / "default.rsp"
    source_sha = _sha256(source_path)
    flags_sha = _sha256(effective_flags)
    rebuilt_sha = _sha256(rebuilt_path)
    key = f"{source_sha}:{flags_sha}:{rebuilt_sha}"
    index = _load_index(slug)
    existing = next((run for run in index["runs"] if run.get("content_key") == key), None)
    if existing is not None:
        existing["summary"] = _metric_summary(metrics)
        existing["objectives"] = _metric_objectives(metrics)
        existing_run_dir = REPO_ROOT / str(existing["artifact_path"])
        for source, relative in _artifact_candidates(slug, source_path, custom_flags):
            _copy_checkpoint_artifact(source, existing_run_dir, relative)
        if label:
            checked_label = _validate_label(label)
            for run in index["runs"]:
                if run is not existing and checked_label in (run.get("labels") or []):
                    run["labels"].remove(checked_label)
            index["labels"][checked_label] = existing["id"]
            existing.setdefault("labels", [])
            if checked_label not in existing["labels"]:
                existing["labels"].append(checked_label)
        _refresh_frontier(index)
        _write_index(slug, index)
        return existing

    now = datetime.now(timezone.utc)
    timestamp = now.strftime("%Y-%m-%dT%H:%M:%SZ")
    run_id = now.strftime("%Y%m%dT%H%M%S.%fZ") + "-" + source_sha[:10]
    run_dir = _history_root(slug) / "runs" / run_id
    for source, relative in _artifact_candidates(slug, source_path, custom_flags):
        _copy_checkpoint_artifact(source, run_dir, relative)

    run = {
        "id": run_id,
        "timestamp": timestamp,
        "content_key": key,
        "source_path": str(source_path.relative_to(REPO_ROOT)),
        "source_sha256": source_sha,
        "custom_flags": custom_flags.exists(),
        "flags_sha256": flags_sha,
        "rebuilt_sha256": rebuilt_sha,
        "artifact_path": str(run_dir.relative_to(REPO_ROOT)),
        "labels": [],
        "summary": _metric_summary(metrics),
        "objectives": _metric_objectives(metrics),
    }
    if label:
        checked_label = _validate_label(label)
        for prior in index["runs"]:
            if checked_label in (prior.get("labels") or []):
                prior["labels"].remove(checked_label)
        index["labels"][checked_label] = run_id
        run["labels"].append(checked_label)
    index["runs"].append(run)
    _refresh_frontier(index)
    _write_index(slug, index)
    return run


def record_checkpoint(record: dict[str, str], label: str | None = None) -> dict:
    slug = function_slug(record)
    with _history_lock(slug):
        return _record_checkpoint_unlocked(record, label)


def _resolve_run(index: dict, selector: str) -> dict:
    runs = list(index.get("runs") or [])
    automatic_selectors = {
        "@latest": lambda row: (str(row.get("timestamp", "")),),
        "@best-call-prefix": lambda row: (
            int((row.get("summary") or {}).get("call_prefix") or 0),
            -int((row.get("summary") or {}).get("diff_bytes") or 0),
        ),
        "@best-shape": lambda row: (
            float((row.get("summary") or {}).get("shape_percent") or 0),
            -int((row.get("summary") or {}).get("diff_bytes") or 0),
        ),
        "@best-blocks": lambda row: (
            float((row.get("summary") or {}).get("block_coverage_percent") or 0),
            -int((row.get("summary") or {}).get("diff_bytes") or 0),
        ),
        "@best-positional": lambda row: (
            -int((row.get("summary") or {}).get("diff_bytes") or 0),
            float((row.get("summary") or {}).get("shape_percent") or 0),
        ),
        "@closest-size": lambda row: (
            -abs(int((row.get("summary") or {}).get("size_delta") or 0)),
            -int((row.get("summary") or {}).get("diff_bytes") or 0),
        ),
    }
    if selector in automatic_selectors:
        if not runs:
            raise KeyError(f"No checkpoints are available for selector {selector}")
        return max(runs, key=automatic_selectors[selector])
    run_id = index.get("labels", {}).get(selector, selector)
    exact = next((run for run in runs if run.get("id") == run_id), None)
    if exact is not None:
        return exact
    matches = [run for run in runs if str(run.get("id", "")).startswith(run_id)]
    if len(matches) == 1:
        return matches[0]
    if not matches:
        raise KeyError(f"Unknown checkpoint label/id: {selector}")
    raise KeyError(f"Ambiguous checkpoint id prefix: {selector}")


def _load_run_metrics(record: dict[str, str], run: dict) -> dict:
    slug = function_slug(record)
    root = REPO_ROOT / str(run["artifact_path"]) / "artifacts" / "diff"
    plain = root / f"{slug}.json"
    compressed = plain.with_suffix(".json.gz")
    if compressed.exists():
        with gzip.open(compressed, "rt", encoding="utf-8") as handle:
            return json.load(handle)
    if plain.exists():
        return json.loads(plain.read_text(encoding="utf-8"))
    raise FileNotFoundError(f"Checkpoint metrics artifact is missing under {root}")


def _call_issue_key(row: dict) -> tuple[str, str, str, str, str]:
    left = row.get("original") or {}
    right = row.get("rebuilt") or {}
    return (
        str(row.get("status") or ""),
        str(left.get("kind") or "-"),
        str(left.get("target") or "-"),
        str(right.get("kind") or "-"),
        str(right.get("target") or "-"),
    )


def _call_issue_text(key: tuple[str, str, str, str, str]) -> str:
    status, left_kind, left_target, right_kind, right_target = key
    return f"{status}: {left_kind} {left_target} -> {right_kind} {right_target}"


def structural_checkpoint_delta(current_metrics: dict, baseline_metrics: dict) -> dict[str, object]:
    """Return call-issue and exact-block changes between two checker reports."""
    current_call_rows = list((current_metrics.get("call_alignment") or {}).get("rows") or [])
    baseline_call_rows = list((baseline_metrics.get("call_alignment") or {}).get("rows") or [])
    current_issues = Counter(
        _call_issue_key(row) for row in current_call_rows if row.get("status") != "equal"
    )
    baseline_issues = Counter(
        _call_issue_key(row) for row in baseline_call_rows if row.get("status") != "equal"
    )
    new_issues = current_issues - baseline_issues
    resolved_issues = baseline_issues - current_issues
    persistent_issues = current_issues & baseline_issues

    def exact_original_offsets(metrics: dict) -> set[int]:
        return {
            int(row["original"]["offset"])
            for row in (metrics.get("block_alignment") or {}).get("rows") or []
            if row.get("status") == "equal" and row.get("original") is not None
        }

    current_exact = exact_original_offsets(current_metrics)
    baseline_exact = exact_original_offsets(baseline_metrics)

    def first_block(metrics: dict) -> dict[str, int | None]:
        block_map = metrics.get("block_alignment") or {}
        index = block_map.get("first_difference_row")
        rows = list(block_map.get("rows") or [])
        if index is None or int(index) >= len(rows):
            return {"original": None, "rebuilt": None}
        row = rows[int(index)]
        return {
            "original": None if row.get("original") is None else int(row["original"]["offset"]),
            "rebuilt": None if row.get("rebuilt") is None else int(row["rebuilt"]["offset"]),
        }

    return {
        "new_call_issues": [{"issue": _call_issue_text(key), "count": count} for key, count in new_issues.items()],
        "resolved_call_issues": [
            {"issue": _call_issue_text(key), "count": count} for key, count in resolved_issues.items()
        ],
        "persistent_call_issues": [
            {"issue": _call_issue_text(key), "count": count} for key, count in persistent_issues.items()
        ],
        "new_exact_original_blocks": sorted(current_exact - baseline_exact),
        "lost_exact_original_blocks": sorted(baseline_exact - current_exact),
        "current_first_block_difference": first_block(current_metrics),
        "baseline_first_block_difference": first_block(baseline_metrics),
    }


def _restore_checkpoint_unlocked(record: dict[str, str], selector: str) -> dict:
    """Restore source and custom-flag state, first backing up current files."""
    slug = function_slug(record)
    index = _load_index(slug)
    run = _resolve_run(index, selector)
    run_dir = REPO_ROOT / str(run["artifact_path"])
    source_relative = Path(str(run["source_path"]))
    recorded_source = REPO_ROOT / source_relative
    current_source = preferred_source_path(record)
    # Preserve the current corpus owner (scratch/matching/accepted_drift/verified_logic) if the
    # file has moved since the checkpoint. Restoring an old path as a second file
    # would create two compiler-facing owners for one VA.
    source_target = current_source if current_source.exists() else recorded_source
    source_snapshot = run_dir / "source" / recorded_source.name
    if not source_snapshot.exists():
        raise FileNotFoundError(f"Checkpoint source artifact is missing: {source_snapshot}")

    backup_root = _history_root(slug) / "restore-backups" / datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S.%fZ")
    if current_source.exists():
        backup = backup_root / "source" / current_source.name
        backup.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(current_source, backup)
    custom_flags = REPO_ROOT / "config" / "flags" / f"{slug}.rsp"
    if custom_flags.exists():
        backup = backup_root / "flags" / custom_flags.name
        backup.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(custom_flags, backup)

    source_target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source_snapshot, source_target)
    saved_flags = run_dir / "flags" / custom_flags.name
    if bool(run.get("custom_flags")):
        if not saved_flags.exists():
            raise FileNotFoundError(f"Checkpoint flags artifact is missing: {saved_flags}")
        custom_flags.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(saved_flags, custom_flags)
    elif custom_flags.exists():
        custom_flags.unlink()
    return {
        **run,
        "restored_source_path": str(source_target.relative_to(REPO_ROOT)),
        "restore_backup": str(backup_root.relative_to(REPO_ROOT)),
    }


def restore_checkpoint(record: dict[str, str], selector: str) -> dict:
    slug = function_slug(record)
    with _history_lock(slug):
        return _restore_checkpoint_unlocked(record, selector)


def history_prune_candidates(index: dict, keep_recent: int = 20) -> list[dict]:
    """Select old dominated, unlabeled runs while preserving useful baselines."""
    runs = list(index.get("runs") or [])
    protected_ids = {str(value) for value in (index.get("labels") or {}).values()}
    protected_ids.update(str(run.get("id")) for run in runs if run.get("labels"))
    protected_ids.update(str(run.get("id")) for run in runs if run.get("pareto"))
    if keep_recent > 0:
        protected_ids.update(str(run.get("id")) for run in runs[-keep_recent:])
    return [run for run in runs if str(run.get("id")) not in protected_ids]


def _tree_size(path: Path) -> int:
    if not path.exists():
        return 0
    if path.is_file():
        return path.stat().st_size
    return sum(item.stat().st_size for item in path.rglob("*") if item.is_file())


def prune_history(record: dict[str, str], keep_recent: int = 20, apply: bool = False) -> list[str]:
    slug = function_slug(record)
    with _history_lock(slug):
        index = _load_index(slug)
        candidates = history_prune_candidates(index, max(keep_recent, 0))
        total_bytes = sum(_tree_size(REPO_ROOT / str(run["artifact_path"])) for run in candidates)
        mode = "APPLY" if apply else "DRY RUN"
        lines = [
            f"History prune {mode} for {slug}: {len(candidates)} candidate(s), "
            f"{total_bytes / (1024 * 1024):.2f} MiB"
        ]
        for run in candidates[:30]:
            summary = run.get("summary") or {}
            lines.append(
                f"  {str(run.get('id', ''))[:24]} diff={int(summary.get('diff_bytes') or 0)} "
                f"shape={float(summary.get('shape_percent') or 0):.1f}"
            )
        if len(candidates) > 30:
            lines.append(f"  ... {len(candidates) - 30} more")
        if not apply:
            lines.append("Nothing deleted. Re-run with --apply-prune to remove these dominated, unlabeled runs.")
            return lines

        candidate_ids = {str(run["id"]) for run in candidates}
        history_root = _history_root(slug).resolve()
        for run in candidates:
            artifact_path = (REPO_ROOT / str(run["artifact_path"])).resolve()
            if not artifact_path.is_relative_to(history_root):
                raise ValueError(f"Refusing to prune artifact outside function history: {artifact_path}")
            if artifact_path.exists():
                shutil.rmtree(artifact_path)
        index["runs"] = [run for run in index.get("runs", []) if str(run.get("id")) not in candidate_ids]
        index["labels"] = {
            label: run_id
            for label, run_id in (index.get("labels") or {}).items()
            if str(run_id) not in candidate_ids
        }
        _refresh_frontier(index)
        _write_index(slug, index)
        lines.append(f"Deleted {len(candidates)} checkpoint(s); reclaimed approximately {total_bytes / (1024 * 1024):.2f} MiB.")
        return lines


def format_history(record: dict[str, str], limit: int = 20) -> list[str]:
    slug = function_slug(record)
    index = _load_index(slug)
    runs = list(index.get("runs") or [])
    if not runs:
        return [f"No persistent history for {slug}."]
    label_by_id: dict[str, list[str]] = {}
    for label, run_id in (index.get("labels") or {}).items():
        label_by_id.setdefault(str(run_id), []).append(str(label))
    lines = [f"History for {slug}: {len(runs)} checkpoint(s)", "P  timestamp             id prefix          diff      shape  calls  blocks size  labels"]
    for run in reversed(runs[-limit:]):
        summary = run.get("summary") or {}
        labels = ",".join(sorted(label_by_id.get(str(run["id"]), []))) or "-"
        lines.append(
            f"{'*' if run.get('pareto') else ' '}  {str(run.get('timestamp', '')):<20} "
            f"{str(run.get('id', ''))[:18]:<18} "
            f"{int(summary.get('diff_bytes') or 0):7d} "
            f"{float(summary.get('shape_percent') or 0):6.1f} "
            f"{float(summary.get('call_similarity_percent') or 0):6.1f} "
            f"{float(summary.get('block_coverage_percent') or 0):6.1f} "
            f"{int(summary.get('size_delta') or 0):+5d}  {labels}"
        )
    lines.append("* = current Pareto frontier (no recorded checkpoint is better on every tracked structural objective)")
    lines.append("Selectors: @latest, @best-call-prefix, @best-shape, @best-blocks, @best-positional, @closest-size")
    return lines


def format_checkpoint_comparison(
    record: dict[str, str], current: dict, selector: str, current_name: str = "current"
) -> list[str]:
    """Compare one just-recorded run with any label or run-id prefix."""
    index = _load_index(function_slug(record))
    baseline = _resolve_run(index, selector)
    current_summary = current.get("summary") or {}
    baseline_summary = baseline.get("summary") or {}
    rows = [
        ("positional diff bytes", "diff_bytes", False),
        ("shape similarity", "shape_percent", True),
        ("call similarity", "call_similarity_percent", True),
        ("aligned call prefix", "call_prefix", True),
        ("exact-block coverage", "block_coverage_percent", True),
        ("size delta", "size_delta", None),
        ("resync similarity", "resync_similarity_percent", True),
    ]
    lines = [
        f"Checkpoint comparison: {current_name} {str(current.get('id', ''))[:18]} vs "
        f"{selector} ({str(baseline.get('id', ''))[:18]})"
    ]
    for label, key, higher_is_better in rows:
        current_value = float(current_summary.get(key) or 0)
        baseline_value = float(baseline_summary.get(key) or 0)
        delta = current_value - baseline_value
        if key in {"diff_bytes", "call_prefix", "size_delta"}:
            value_text = f"{int(current_value)} vs {int(baseline_value)} ({int(delta):+d})"
        else:
            value_text = f"{current_value:.2f} vs {baseline_value:.2f} ({delta:+.2f})"
        if higher_is_better is None:
            verdict = "closer" if abs(current_value) < abs(baseline_value) else ("farther" if abs(current_value) > abs(baseline_value) else "same")
        elif delta == 0:
            verdict = "same"
        elif (delta > 0) == higher_is_better:
            verdict = "better"
        else:
            verdict = "worse"
        lines.append(f"  {label:<23} {value_text:<28} {verdict}")
    try:
        structural = structural_checkpoint_delta(
            _load_run_metrics(record, current),
            _load_run_metrics(record, baseline),
        )
        lines.append("Structural delta:")
        for label, key in (
            ("new call issue", "new_call_issues"),
            ("resolved call issue", "resolved_call_issues"),
        ):
            rows_for_key = list(structural[key])
            if not rows_for_key:
                lines.append(f"  {label}s: none")
                continue
            for row in rows_for_key[:8]:
                suffix = "" if int(row["count"]) == 1 else f" x{int(row['count'])}"
                lines.append(f"  {label}: {row['issue']}{suffix}")
            if len(rows_for_key) > 8:
                lines.append(f"  ... {len(rows_for_key) - 8} more {label}s")
        new_blocks = list(structural["new_exact_original_blocks"])
        lost_blocks = list(structural["lost_exact_original_blocks"])
        lines.append(
            "  newly exact original blocks: "
            + (", ".join(f"+{int(value):04X}" for value in new_blocks[:12]) or "none")
        )
        lines.append(
            "  lost exact original blocks:  "
            + (", ".join(f"+{int(value):04X}" for value in lost_blocks[:12]) or "none")
        )
        current_first = structural["current_first_block_difference"]
        baseline_first = structural["baseline_first_block_difference"]
        def offset_text(value: object) -> str:
            return "none" if value is None else f"+{int(value):04X}"
        lines.append(
            "  first block divergence: "
            f"{current_name} orig={offset_text(current_first['original'])} rebuilt={offset_text(current_first['rebuilt'])} | "
            f"{selector} orig={offset_text(baseline_first['original'])} rebuilt={offset_text(baseline_first['rebuilt'])}"
        )
    except FileNotFoundError as exc:
        lines.append(f"Structural delta unavailable: {exc}")
    return lines


def format_history_comparison(record: dict[str, str], left_selector: str, right_selector: str) -> list[str]:
    index = _load_index(function_slug(record))
    left = _resolve_run(index, left_selector)
    return format_checkpoint_comparison(record, left, right_selector, current_name=left_selector)


def _run_source_path(record: dict[str, str], run: dict) -> Path:
    slug = function_slug(record)
    history_root = _history_root(slug).resolve()
    run_root = (REPO_ROOT / str(run["artifact_path"])).resolve()
    if not run_root.is_relative_to(history_root):
        raise ValueError(f"Checkpoint artifact is outside function history: {run_root}")
    source_root = run_root / "source"
    preferred = source_root / preferred_source_path(record).name
    if preferred.is_file():
        return preferred
    candidates = sorted(path for path in source_root.iterdir() if path.is_file()) if source_root.is_dir() else []
    if len(candidates) != 1:
        raise FileNotFoundError(f"Could not identify checkpoint source under {source_root}")
    return candidates[0]


def format_history_source_comparison(
    record: dict[str, str],
    left_selector: str,
    right_selector: str,
    *,
    limit: int = 500,
) -> list[str]:
    """Return a bounded unified source diff between two persistent checkpoints."""
    index = _load_index(function_slug(record))
    left = _resolve_run(index, left_selector)
    right = _resolve_run(index, right_selector)
    left_path = _run_source_path(record, left)
    right_path = _run_source_path(record, right)
    left_lines = left_path.read_text(encoding="utf-8").splitlines()
    right_lines = right_path.read_text(encoding="utf-8").splitlines()
    diff = list(
        difflib.unified_diff(
            left_lines,
            right_lines,
            fromfile=f"{left_selector}:{str(left.get('id', ''))[:18]}/{left_path.name}",
            tofile=f"{right_selector}:{str(right.get('id', ''))[:18]}/{right_path.name}",
            lineterm="",
        )
    )
    header = [
        f"Checkpoint source comparison: {left_selector} ({str(left.get('id', ''))[:18]}) vs "
        f"{right_selector} ({str(right.get('id', ''))[:18]})"
    ]
    if not diff:
        return header + ["  (sources are identical)"]
    if limit > 0 and len(diff) > limit:
        omitted = len(diff) - limit
        diff = diff[:limit] + [f"... {omitted} more unified-diff line(s); raise --history-diff-limit to show them"]
    return header + diff
