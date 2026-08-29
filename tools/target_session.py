from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import subprocess
import sys
import time
from contextlib import contextmanager
from datetime import datetime, timedelta, timezone
from pathlib import Path

from build_cache import build_input_manifest, build_manifest_matches
from common import (
    REPO_ROOT,
    compiler_artifact_slug,
    compiler_source_path,
    compiler_translation_unit_for_va,
    function_recovery_note_relative_path,
    function_record_by_va,
    function_slug,
    load_pdb_function_source_map,
    load_toolchain,
    preferred_flags_rsp_path,
    preferred_source_path,
)
from function_diagnostics import owning_function_symbol_validation
from function_history import (
    _context_storage_path,
    checkpoint_info,
    current_build_context,
    record_checkpoint,
    restore_checkpoint,
)


SESSION_VERSION = 3
SESSION_INDEX_VERSION = 1
CLEAN_CHECKPOINT_LABEL = "clean-source"
OWNER_RE = re.compile(r"^[A-Za-z0-9][A-Za-z0-9_.-]{0,63}$")
PROBE_KINDS = (
    "baseline",
    "behavior",
    "abi",
    "layout",
    "control-flow",
    "liveness",
    "context",
    "flags",
    "variant",
    "restore",
    "validation",
    "other",
)
NON_MEANINGFUL_PROBE_KINDS = {"restore", "validation"}


def _utc_now() -> datetime:
    return datetime.now(timezone.utc)


def _iso(value: datetime) -> str:
    return value.replace(microsecond=0).isoformat().replace("+00:00", "Z")


def _parse_iso(value: str) -> datetime:
    return datetime.fromisoformat(value.replace("Z", "+00:00"))


def _sessions_root() -> Path:
    return REPO_ROOT / "build" / "target_sessions"


def _session_index_path() -> Path:
    return REPO_ROOT / "build" / "target_session_index.json"


def _session_path(record: dict[str, str]) -> Path:
    return _sessions_root() / f"{function_slug(record)}.json"


def _validate_owner(owner: str) -> str:
    value = owner.strip()
    if not OWNER_RE.fullmatch(value):
        raise ValueError("Owner must start with an alphanumeric and contain only A-Z, a-z, 0-9, _, ., or -")
    return value


@contextmanager
def _sessions_lock():
    root = _sessions_root()
    root.mkdir(parents=True, exist_ok=True)
    path = root / "sessions.lock"
    descriptor: int | None = None
    for _ in range(200):
        try:
            descriptor = os.open(path, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
            os.write(descriptor, str(os.getpid()).encode("ascii"))
            break
        except FileExistsError:
            try:
                if time.time() - path.stat().st_mtime > 300:
                    path.unlink()
                    continue
            except FileNotFoundError:
                continue
            time.sleep(0.05)
    if descriptor is None:
        raise TimeoutError(f"Timed out waiting for target-session lock: {path}")
    try:
        yield
    finally:
        os.close(descriptor)
        try:
            path.unlink()
        except FileNotFoundError:
            pass


def _load_session(record: dict[str, str]) -> dict | None:
    path = _session_path(record)
    if not path.exists():
        return None
    return json.loads(path.read_text(encoding="utf-8"))


def _session_file_fingerprint() -> str:
    """Return a cheap fingerprint of all session files without reading them."""
    root = _sessions_root()
    if not root.exists():
        return ""
    entries: list[tuple[str, int, int]] = []
    with os.scandir(root) as children:
        for child in children:
            if not child.is_file() or not child.name.lower().endswith(".json"):
                continue
            stat = child.stat()
            entries.append((child.name, stat.st_size, stat.st_mtime_ns))
    digest = hashlib.sha256()
    for name, size, modified in sorted(entries):
        digest.update(name.encode("utf-8", errors="surrogatepass"))
        digest.update(b"\0")
        digest.update(f"{size}:{modified}\n".encode("ascii"))
    return digest.hexdigest()


def target_session_summary(session: dict) -> dict:
    """Reduce one complete session to fields needed by project status queries."""
    probes = list(session.get("probes") or [])
    probe_diffs = [
        int((probe.get("metrics") or {}).get("diff_bytes"))
        for probe in probes
        if (probe.get("metrics") or {}).get("diff_bytes") is not None
    ]
    improvement = last_positional_improvement(session)
    return {
        "summary_version": SESSION_INDEX_VERSION,
        "va": str(session.get("va", "")).upper(),
        "name": str(session.get("name", "")),
        "slug": str(session.get("slug", "")),
        "owner": str(session.get("owner", "")),
        "state": str(session.get("state", "")),
        "claimed_at": str(session.get("claimed_at", "")),
        "updated_at": str(session.get("updated_at", "")),
        "lease_expires_at": str(session.get("lease_expires_at", "")),
        "meaningful_probe_budget": int(session.get("meaningful_probe_budget") or 0),
        "meaningful_probe_count": meaningful_probe_count(session),
        "meaningful_probe_total": meaningful_probe_count(session, current_claim_only=False),
        "claim_count": session_claim_count(session),
        "recorded_probe_count": len(probes),
        "best_diff_bytes": min(probe_diffs) if probe_diffs else None,
        "last_positional_improvement": (
            {"number": improvement.get("number"), "at": improvement.get("at")}
            if improvement
            else None
        ),
        "last_metric_summary": dict(session.get("last_metric_summary") or {}),
        "clean_baseline": bool(session.get("clean_baseline")),
    }


def _read_session_index() -> dict | None:
    path = _session_index_path()
    if not path.exists():
        return None
    try:
        payload = json.loads(path.read_text(encoding="utf-8"))
    except (json.JSONDecodeError, OSError):
        return None
    if payload.get("version") != SESSION_INDEX_VERSION or not isinstance(payload.get("sessions"), dict):
        return None
    return payload


def _write_session_index(sessions: dict[str, dict], fingerprint: str) -> None:
    path = _session_index_path()
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(".json.tmp")
    payload = {
        "version": SESSION_INDEX_VERSION,
        "session_files_fingerprint": fingerprint,
        "sessions": sessions,
    }
    temporary.write_text(
        json.dumps(payload, ensure_ascii=False, separators=(",", ":")) + "\n",
        encoding="utf-8",
    )
    temporary.replace(path)


def _rebuild_session_index() -> dict:
    summaries: dict[str, dict] = {}
    root = _sessions_root()
    if root.exists():
        for path in sorted(root.glob("*.json")):
            try:
                session = json.loads(path.read_text(encoding="utf-8"))
                summary = target_session_summary(session)
            except (json.JSONDecodeError, OSError, TypeError, ValueError):
                summary = {
                    "summary_version": SESSION_INDEX_VERSION,
                    "va": path.name.split("_", 1)[0].upper(),
                    "slug": path.stem,
                    "owner": "",
                    "state": "invalid",
                }
            va = str(summary.get("va", "")).upper()
            if va:
                summaries[va] = summary
    fingerprint = _session_file_fingerprint()
    _write_session_index(summaries, fingerprint)
    return {
        "version": SESSION_INDEX_VERSION,
        "session_files_fingerprint": fingerprint,
        "sessions": summaries,
    }


def _write_session(record: dict[str, str], payload: dict) -> None:
    payload["version"] = SESSION_VERSION
    prior_fingerprint = _session_file_fingerprint()
    index = _read_session_index()
    index_was_current = bool(
        index and index.get("session_files_fingerprint") == prior_fingerprint
    )
    path = _session_path(record)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(".json.tmp")
    temporary.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    temporary.replace(path)
    current_fingerprint = _session_file_fingerprint()
    if index_was_current and index is not None:
        sessions = dict(index["sessions"])
        sessions[str(payload.get("va") or record["va"]).upper()] = target_session_summary(payload)
        _write_session_index(sessions, current_fingerprint)
    else:
        _rebuild_session_index()


def _lease_active(session: dict, now: datetime | None = None) -> bool:
    if session.get("state") != "active":
        return False
    expiry = str(session.get("lease_expires_at") or "")
    if not expiry:
        return False
    try:
        return _parse_iso(expiry) > (now or _utc_now())
    except ValueError:
        return False


def _probe_is_meaningful(probe: dict) -> bool:
    if "meaningful" in probe:
        return bool(probe["meaningful"])
    return probe.get("kind") not in NON_MEANINGFUL_PROBE_KINDS


def meaningful_probe_count(session: dict, *, current_claim_only: bool = True) -> int:
    if session.get("summary_version") == SESSION_INDEX_VERSION:
        field = "meaningful_probe_count" if current_claim_only else "meaningful_probe_total"
        return int(session.get(field) or 0)
    probes = list(session.get("probes") or [])
    if current_claim_only:
        probes = probes[int(session.get("probe_start_index") or 0) :]
    return sum(_probe_is_meaningful(probe) for probe in probes)


def session_claim_count(session: dict) -> int:
    """Return lifetime claims without counting pause and probe events."""
    if session.get("summary_version") == SESSION_INDEX_VERSION:
        return int(session.get("claim_count") or 0)
    events = session.get("events") or []
    event_count = sum(event.get("kind") in {"start", "takeover"} for event in events)
    return max(event_count, 1 if session else 0)


def last_positional_improvement(session: dict) -> dict | None:
    """Return the latest meaningful probe that lowered positional diff bytes."""
    if session.get("summary_version") == SESSION_INDEX_VERSION:
        improvement = session.get("last_positional_improvement")
        return dict(improvement) if isinstance(improvement, dict) else None
    for probe in reversed(session.get("probes") or []):
        delta = (probe.get("metric_delta") or {}).get("diff_bytes") or {}
        if _probe_is_meaningful(probe) and delta.get("direction") == "improved":
            return probe
    return None


def _source_bucket(source: Path) -> str:
    if not source.exists():
        return "unclaimed"
    try:
        relative = source.relative_to(REPO_ROOT)
    except ValueError:
        return "external"
    if len(relative.parts) >= 2 and relative.parts[0] == "src":
        return relative.parts[1]
    return "other"


def _metrics_path(record: dict[str, str]) -> Path:
    return REPO_ROOT / "build" / "diff" / f"{function_slug(record)}.json"


def _artifact_freshness(record: dict[str, str]) -> tuple[bool, str]:
    slug = function_slug(record)
    build_slug = compiler_artifact_slug(record)
    source = compiler_source_path(record)
    if not source.exists():
        return False, "living source is missing"
    try:
        toolchain = load_toolchain()
        flags = preferred_flags_rsp_path(record, toolchain)
        fingerprint = str(build_input_manifest(source, flags, toolchain)["fingerprint"])
    except (FileNotFoundError, KeyError, OSError) as error:
        return False, f"cannot fingerprint current inputs: {error}"
    obj = REPO_ROOT / "build" / "obj" / f"{build_slug}.obj"
    manifest = REPO_ROOT / "build" / "manifests" / f"build_{build_slug}.json"
    rebuilt = REPO_ROOT / "build" / "asm" / f"rebuilt_{slug}.bin"
    metrics = _metrics_path(record)
    if not build_manifest_matches(manifest, fingerprint, obj):
        return False, "source/flags/compiler/include fingerprint differs from the recorded build"
    if not rebuilt.exists() or not metrics.exists():
        return False, "rebuilt or diff artifact is missing"
    if rebuilt.stat().st_mtime_ns < obj.stat().st_mtime_ns or metrics.stat().st_mtime_ns < rebuilt.stat().st_mtime_ns:
        return False, "extraction or diff artifact predates the current object"
    return True, "fingerprinted build and diff are current"


def current_metric_summary(record: dict[str, str]) -> dict[str, object]:
    path = _metrics_path(record)
    if not path.exists():
        return {}
    try:
        metrics = json.loads(path.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return {"error": f"invalid JSON in {path.relative_to(REPO_ROOT)}"}
    original_prologue = metrics.get("original_prologue") or {}
    rebuilt_prologue = metrics.get("rebuilt_prologue") or {}
    call_alignment = metrics.get("call_alignment") or {}
    call_sites = metrics.get("call_site_status_counts") or {}
    block_alignment = metrics.get("block_alignment") or {}
    rebuilt_extraction = metrics.get("rebuilt_extraction") or {}
    relocation_identity = [
        {
            "offset": row.get("offset"),
            "type": row.get("type"),
            "width": row.get("width"),
            "symbol_name": row.get("symbol_name"),
        }
        for row in rebuilt_extraction.get("relocations") or []
    ]
    relocation_identity_sha256 = hashlib.sha256(
        json.dumps(relocation_identity, sort_keys=True).encode("utf-8")
    ).hexdigest()
    owner_validation = dict(metrics.get("owning_symbol_validation") or {})
    rebuilt_symbol = str(
        ((rebuilt_extraction.get("symbol") or {}).get("name") if isinstance(rebuilt_extraction, dict) else "")
        or ""
    ).strip()
    pdb_row = load_pdb_function_source_map().get(record["va"].upper()) or {}
    pdb_symbol = str(pdb_row.get("symbol_name") or "").strip()
    if rebuilt_symbol and pdb_symbol:
        owner_validation = owning_function_symbol_validation(record["name"], rebuilt_symbol, pdb_symbol)
    elif rebuilt_symbol:
        owner_validation = {**owner_validation, "status": "unverified"}
    meaningful_size = rebuilt_extraction.get(
        "effective_size_bytes", rebuilt_extraction.get("meaningful_size_bytes")
    )
    original_size = metrics.get("original_size")
    rebuilt_path = REPO_ROOT / "build" / "asm" / f"rebuilt_{function_slug(record)}.bin"
    artifact_fresh, freshness_reason = _artifact_freshness(record)
    first_mismatch_text = str(metrics.get("first_mismatch_offset") or "")
    try:
        first_mismatch: int | None = int(first_mismatch_text, 10) if first_mismatch_text else None
    except ValueError:
        first_mismatch = None
    return {
        "result": metrics.get("result"),
        "workflow_stage": metrics.get("workflow_stage"),
        "diagnostic_class": (metrics.get("mismatch_classification") or {}).get("primary"),
        "diff_bytes": metrics.get("diff_bytes"),
        "diff_percent": metrics.get("diff_percent"),
        "first_mismatch_offset": first_mismatch,
        "shape_percent": (metrics.get("instruction_shape") or {}).get("similarity_percent"),
        "call_similarity_percent": call_alignment.get("similarity_percent"),
        "call_prefix": call_alignment.get("aligned_prefix_calls"),
        "call_site_status_counts": metrics.get("call_site_status_counts") or {},
        "call_equal_sites": int(call_sites.get("equal") or 0),
        "call_deleted_sites": int(call_sites.get("delete") or 0),
        "call_inserted_sites": int(call_sites.get("insert") or 0),
        "call_replaced_sites": int(call_sites.get("replace") or 0),
        "call_target_count_gap": sum(
            abs(int(row.get("delta", 0))) for row in metrics.get("call_target_count_deltas") or []
        ),
        "wrong_direct_targets": len(metrics.get("relocation_target_mismatches") or []),
        "original_frame": original_prologue.get("frame_size"),
        "rebuilt_frame": rebuilt_prologue.get("frame_size"),
        "original_size": original_size,
        "rebuilt_size": metrics.get("rebuilt_size"),
        "meaningful_rebuilt_size": meaningful_size,
        "meaningful_size_delta": (
            int(meaningful_size) - int(original_size)
            if meaningful_size is not None and original_size is not None
            else None
        ),
        "meaningful_size_gap": (
            abs(int(meaningful_size) - int(original_size))
            if meaningful_size is not None and original_size is not None
            else None
        ),
        "edit_diff_bytes": metrics.get("edit_diff_bytes"),
        "edit_diff_percent": metrics.get("edit_diff_percent"),
        "exact_block_coverage_percent": block_alignment.get("matched_coverage_percent"),
        "rebuilt_bin_sha256": _sha256(rebuilt_path) if rebuilt_path.exists() else "",
        "relocation_identity_sha256": relocation_identity_sha256,
        "build_input_fingerprint": metrics.get("build_input_fingerprint", ""),
        "owning_symbol_validation": owner_validation,
        "likely_shifted_alignment": bool(metrics.get("likely_shifted_alignment")),
        "artifact_fresh": artifact_fresh,
        "freshness_reason": freshness_reason,
    }


def _history_count(record: dict[str, str]) -> int:
    path = REPO_ROOT / "build" / "history" / function_slug(record) / "history.json"
    if not path.exists():
        return 0
    try:
        return len(json.loads(path.read_text(encoding="utf-8")).get("runs") or [])
    except json.JSONDecodeError:
        return 0


def classify_next_stage(metrics: dict[str, object]) -> str:
    if not metrics:
        return "No current check: establish behavior, call set, boundary, and frame before codegen tuning."
    if metrics.get("artifact_fresh") is False:
        return "Recorded check is stale: rebuild before interpreting metrics or spending another hypothesis."
    if metrics.get("result") == "MATCH":
        return "Exact candidate: audit source plausibility, review flags, and validate locally before promotion."
    stage = str(metrics.get("workflow_stage") or "").upper()
    if stage == "CALL TARGET INTEGRITY":
        return "Call-target integrity: fix the declaration or symbol binding without reshaping aligned code."
    if stage == "STRUCTURAL RECONSTRUCTION":
        deleted = int(metrics.get("call_deleted_sites") or 0)
        inserted = int(metrics.get("call_inserted_sites") or 0)
        replaced = int(metrics.get("call_replaced_sites") or 0)
        call_note = (
            f" Ordered call sites still differ (-{deleted}/+{inserted}, replacements={replaced})."
            if deleted or inserted or replaced
            else ""
        )
        return (
            "Structural reconstruction: follow the checker's first structural/call hunk and size/CFG evidence; "
            "do not tune register coloring yet." + call_note
        )
    if stage == "STACK/LOCAL TOPOLOGY":
        return "Stack/local topology: investigate parameter homes, address-taken locals, and declaration lifetimes."
    if stage == "BLOCK SHAPE AND LIVENESS":
        return "Block shape/liveness: work from the first paired hunk while preserving exact blocks."
    if stage == "EXACT CODEGEN":
        return (
            "Focused emitted-code work: keep the clean-source baseline authoritative while using a localized "
            "range or deliberate variant lab. Closer assembly does not by itself improve the source model."
        )
    if int(metrics.get("wrong_direct_targets") or 0) or int(metrics.get("call_target_count_gap") or 0):
        return "Behavior/ABI first: resolve missing, extra, or wrong direct calls before source-shape tuning."
    original_frame = metrics.get("original_frame")
    rebuilt_frame = metrics.get("rebuilt_frame")
    if original_frame is not None and rebuilt_frame is not None and original_frame != rebuilt_frame:
        return "Stack/local topology: investigate parameter homes, address-taken locals, and declaration lifetimes."
    shape = metrics.get("shape_percent")
    if shape is None or float(shape) < 75.0:
        return "Structural reconstruction: fix the first block/control-flow divergence; do not run broad variant sweeps."
    return (
        "Focused emitted-code work: preserve aligned regions and the clean-source baseline while using a "
        "localized range or deliberate variant lab."
    )


def _new_session(
    record: dict[str, str],
    owner: str,
    budget: int,
    lease_hours: float,
    prior: dict | None,
    metric_summary: dict[str, object] | None = None,
) -> dict:
    now = _utc_now()
    events = list((prior or {}).get("events") or [])
    probes = list((prior or {}).get("probes") or [])
    continuing_active_claim = bool(
        prior and prior.get("owner") == owner and _lease_active(prior, now)
    )
    if continuing_active_claim:
        pass
    elif prior and prior.get("owner") != owner:
        events.append(
            {
                "at": _iso(now),
                "kind": "takeover",
                "from_owner": prior.get("owner", ""),
                "to_owner": owner,
            }
        )
    else:
        events.append({"at": _iso(now), "kind": "start", "owner": owner})
    return {
        "version": SESSION_VERSION,
        "va": record["va"],
        "name": record["name"],
        "slug": function_slug(record),
        "owner": owner,
        "state": "active",
        "claimed_at": prior.get("claimed_at") if continuing_active_claim else _iso(now),
        "updated_at": _iso(now),
        "lease_expires_at": _iso(now + timedelta(hours=lease_hours)),
        "lease_hours": lease_hours,
        "meaningful_probe_budget": budget,
        "probe_start_index": int(prior.get("probe_start_index") or 0)
        if continuing_active_claim
        else len(probes),
        "probes": probes,
        "events": events,
        "last_metric_summary": metric_summary or {},
        "clean_baseline": dict((prior or {}).get("clean_baseline") or {}),
    }


def start_session(
    record: dict[str, str], owner: str, budget: int, lease_hours: float, force: bool = False
) -> dict:
    checked_owner = _validate_owner(owner)
    metric_summary = current_metric_summary(record)
    with _sessions_lock():
        prior = _load_session(record)
        if prior and _lease_active(prior) and prior.get("owner") != checked_owner and not force:
            raise RuntimeError(
                f"{record['va']} is actively leased by {prior.get('owner')} until {prior.get('lease_expires_at')}; "
                "coordinate with that owner or use --force for a deliberate takeover"
            )
        target_source = compiler_source_path(record).resolve()
        for other in _all_sessions():
            other_va = str(other.get("va") or "").upper()
            if other_va == record["va"].upper() or not _lease_active(other):
                continue
            try:
                other_record = function_record_by_va(int(other_va, 16))
                other_source = compiler_source_path(other_record).resolve()
            except (KeyError, TypeError, ValueError):
                continue
            if other_source == target_source:
                raise RuntimeError(
                    f"translation unit {target_source.relative_to(REPO_ROOT)} is actively leased "
                    f"through {other_va} by {other.get('owner')} until "
                    f"{other.get('lease_expires_at')}; pause or release that target first"
                )
        session = _new_session(
            record,
            checked_owner,
            budget,
            lease_hours,
            prior,
            metric_summary,
        )
        _write_session(record, session)
    return session


def _require_owner(session: dict | None, owner: str, record: dict[str, str]) -> dict:
    if session is None:
        raise RuntimeError(f"No target session exists for {record['va']}; run start first")
    checked_owner = _validate_owner(owner)
    if session.get("owner") != checked_owner:
        raise RuntimeError(f"{record['va']} is owned by {session.get('owner')}, not {checked_owner}")
    return session


def _require_active_owner(session: dict | None, owner: str, record: dict[str, str]) -> dict:
    checked = _require_owner(session, owner, record)
    if not _lease_active(checked):
        raise RuntimeError(f"{record['va']} session is not an active unexpired lease; run start first")
    return checked


def _sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def current_input_snapshot(record: dict[str, str]) -> dict[str, object]:
    source = compiler_source_path(record)
    toolchain: dict | None = None
    try:
        toolchain = load_toolchain()
        flags = preferred_flags_rsp_path(record, toolchain)
    except (FileNotFoundError, KeyError, OSError):
        flags = REPO_ROOT / "config" / "flags" / "default.rsp"
    snapshot: dict[str, object] = {
        "source_path": str(source.relative_to(REPO_ROOT)) if source.exists() else "",
        "source_sha256": _sha256(source) if source.exists() else "",
        "flags_path": str(flags.relative_to(REPO_ROOT)) if flags.exists() and flags.is_relative_to(REPO_ROOT) else str(flags),
        "flags_sha256": _sha256(flags) if flags.exists() else "",
    }
    try:
        if toolchain is None:
            raise ValueError("toolchain is unavailable")
        snapshot["build_input_fingerprint"] = str(
            build_input_manifest(source, flags, toolchain)["fingerprint"]
        )
    except (FileNotFoundError, KeyError, OSError, ValueError):
        # Keep the old compact input snapshot usable when the compiler context
        # is unavailable. A check cannot pass freshness until this is filled.
        snapshot["build_input_fingerprint"] = ""
    return snapshot


def _context_input_hashes(context: dict) -> dict[str, str]:
    return {
        str(item.get("path") or "").replace("\\", "/"): str(item.get("sha256") or "")
        for item in context.get("inputs") or []
        if str(item.get("path") or "")
    }


def _validate_grouped_checkpoint(
    record: dict[str, str],
    checkpoint: dict,
    current_context: dict | None,
    metrics: dict[str, object],
    inputs: dict[str, object],
    *,
    require_exact: bool,
) -> None:
    """Verify that a grouped checkpoint still names the exact compiler context."""
    if current_context is None:
        return
    saved_context = checkpoint.get("build_context")
    if not isinstance(saved_context, dict):
        raise RuntimeError(
            "grouped checkpoint has no compiler context; legacy checkpoints cannot support an exact claim"
        )
    current_fingerprint = str(current_context.get("fingerprint") or "")
    saved_fingerprint = str(saved_context.get("fingerprint") or "")
    snapshot_fingerprint = str(inputs.get("build_input_fingerprint") or "")
    if not current_fingerprint or snapshot_fingerprint != current_fingerprint:
        raise RuntimeError("current grouped build fingerprint is unavailable or stale")
    if saved_fingerprint != current_fingerprint:
        raise RuntimeError("grouped checkpoint build fingerprint differs from the current build")
    if require_exact and str(metrics.get("build_input_fingerprint") or "") != current_fingerprint:
        raise RuntimeError("grouped exact result has no matching current build fingerprint")

    fields = ("name", "source", "flags", "owners", "symbols")
    saved_unit = saved_context.get("translation_unit") or {}
    current_unit = current_context.get("translation_unit") or {}
    for field in fields:
        if saved_unit.get(field) != current_unit.get(field):
            raise RuntimeError(f"grouped checkpoint translation-unit {field} differs from the current mapping")
    if saved_context.get("pdb_symbol", "") != current_context.get("pdb_symbol", ""):
        raise RuntimeError("grouped checkpoint PDB-qualified owner differs from the current mapping")

    if _context_input_hashes(saved_context) != _context_input_hashes(current_context):
        raise RuntimeError("translation-unit source, owner, flags, or declaration inputs changed")

    artifact_path = checkpoint.get("artifact_path")
    context_root = REPO_ROOT / str(artifact_path or "") / "context"
    if not (context_root / "build_context.json").is_file():
        raise RuntimeError("grouped checkpoint compiler-context artifact is missing")
    for item in current_context.get("inputs") or []:
        display_path = str(item.get("path") or "")
        saved_path = context_root / _context_storage_path(display_path)
        if not saved_path.is_file():
            raise RuntimeError(f"grouped checkpoint input artifact is missing: {display_path}")

    if not require_exact:
        return
    if metrics.get("result") != "MATCH":
        raise RuntimeError("grouped exact release requires a current MATCH result")
    current_owner = metrics.get("owning_symbol_validation") or {}
    if not isinstance(current_owner, dict) or current_owner.get("status") != "match":
        raise RuntimeError("grouped exact release requires a matching PDB-qualified owner")
    saved_owner = saved_context.get("pdb_owner")
    if not isinstance(saved_owner, dict) or saved_owner != current_owner:
        raise RuntimeError("grouped checkpoint PDB-qualified owner result differs from the current result")


def current_output_snapshot(record: dict[str, str], metrics: dict[str, object]) -> dict[str, object]:
    rebuilt = REPO_ROOT / "build" / "asm" / f"rebuilt_{function_slug(record)}.bin"
    code_hash = _sha256(rebuilt) if rebuilt.exists() and metrics.get("artifact_fresh") is not False else ""
    identity_payload = {
        "code_sha256": code_hash,
        "meaningful_size": metrics.get("meaningful_rebuilt_size"),
        "relocation_identity_sha256": metrics.get("relocation_identity_sha256"),
        "calls": {
            "equal": metrics.get("call_equal_sites"),
            "delete": metrics.get("call_deleted_sites"),
            "insert": metrics.get("call_inserted_sites"),
            "replace": metrics.get("call_replaced_sites"),
            "wrong_direct_targets": metrics.get("wrong_direct_targets"),
        },
    }
    identity = (
        hashlib.sha256(json.dumps(identity_payload, sort_keys=True).encode("utf-8")).hexdigest()
        if code_hash
        else ""
    )
    return {
        "rebuilt_path": str(rebuilt.relative_to(REPO_ROOT)) if rebuilt.exists() else "",
        "rebuilt_sha256": code_hash,
        "emitted_identity_sha256": identity,
        "meaningful_size": metrics.get("meaningful_rebuilt_size"),
    }


def metric_delta(current: dict[str, object], prior: dict[str, object]) -> dict[str, object]:
    pairs = {
        "diff_bytes": False,
        "diff_percent": False,
        "shape_percent": True,
        "call_similarity_percent": True,
        "call_prefix": True,
        "call_target_count_gap": False,
        "call_deleted_sites": False,
        "call_inserted_sites": False,
        "call_replaced_sites": False,
        "wrong_direct_targets": False,
        "first_mismatch_offset": True,
        "meaningful_size_gap": False,
        "exact_block_coverage_percent": True,
        "edit_diff_percent": False,
        "rebuilt_frame": None,
    }
    result: dict[str, object] = {}
    for key, higher_is_better in pairs.items():
        left = current.get(key)
        right = prior.get(key)
        if not isinstance(left, (int, float)) or not isinstance(right, (int, float)):
            continue
        delta = left - right
        row: dict[str, object] = {"current": left, "prior": right, "delta": delta}
        if higher_is_better is not None:
            row["direction"] = (
                "same" if delta == 0 else "improved" if (delta > 0) == higher_is_better else "regressed"
            )
        result[key] = row
    return result


def record_probe(
    record: dict[str, str],
    owner: str,
    kind: str,
    note: str,
    checkpoint: str = "",
    *,
    evidence: dict[str, object] | None = None,
    detect_output_duplicate: bool = True,
) -> dict:
    metrics = current_metric_summary(record)
    outputs = current_output_snapshot(record, metrics)
    inputs = current_input_snapshot(record)
    with _sessions_lock():
        session = _require_active_owner(_load_session(record), owner, record)
        now = _utc_now()
        prior_metrics = {}
        if session.get("probes"):
            prior_metrics = dict(session["probes"][-1].get("metrics") or {})
        duplicate_of = None
        identity = outputs.get("emitted_identity_sha256")
        if identity and detect_output_duplicate:
            for earlier in reversed(session.get("probes") or []):
                if (earlier.get("outputs") or {}).get("emitted_identity_sha256") == identity:
                    duplicate_of = earlier.get("number")
                    break
        probe = {
            "number": len(session.get("probes") or []) + 1,
            "claim_number": len(session.get("probes") or [])
            - int(session.get("probe_start_index") or 0)
            + 1,
            "at": _iso(now),
            "kind": kind,
            "meaningful": kind not in NON_MEANINGFUL_PROBE_KINDS,
            "note": note.strip(),
            "checkpoint": checkpoint.strip(),
            "metrics": metrics,
            "metric_delta": metric_delta(metrics, prior_metrics),
            "inputs": inputs,
            "outputs": outputs,
            "same_emitted_code_as_probe": duplicate_of,
        }
        if evidence:
            probe["evidence"] = evidence
        session.setdefault("probes", []).append(probe)
        session.setdefault("events", []).append(
            {"at": _iso(now), "kind": "probe", "probe_number": probe["number"]}
        )
        session["updated_at"] = _iso(now)
        session["lease_expires_at"] = _iso(now + timedelta(hours=float(session.get("lease_hours") or 8)))
        session["last_metric_summary"] = metrics
        _write_session(record, session)
    return session


def clean_baseline_is_current(record: dict[str, str], session: dict) -> bool:
    baseline = session.get("clean_baseline") or {}
    return bool(baseline) and baseline.get("inputs") == current_input_snapshot(record)


def require_clean_baseline(record: dict[str, str], owner: str) -> dict:
    """Require an active owner and one explicitly audited clean-source checkpoint."""
    with _sessions_lock():
        session = _require_active_owner(_load_session(record), owner, record)
        baseline = dict(session.get("clean_baseline") or {})
    if not baseline:
        raise RuntimeError(
            "no clean-source baseline is pinned; compile the natural reconstruction with "
            "--kind baseline, or run target_session.py pin-clean after a current check"
        )
    checkpoint_id = str(baseline.get("checkpoint_id") or "")
    try:
        checkpoint_info(record, checkpoint_id)
    except (KeyError, OSError, json.JSONDecodeError) as error:
        raise RuntimeError(
            f"pinned clean-source checkpoint is unavailable ({checkpoint_id or 'missing id'})"
        ) from error
    return baseline


def pin_clean_baseline(record: dict[str, str], owner: str, note: str) -> dict:
    """Designate the current checked source as the canonical clean reconstruction."""
    checked_note = note.strip()
    if not checked_note:
        raise ValueError("clean-source note must describe canonical ownership and the plausible source family")
    with _sessions_lock():
        _require_active_owner(_load_session(record), owner, record)
    metrics = current_metric_summary(record)
    if metrics.get("artifact_fresh") is not True:
        reason = metrics.get("freshness_reason") or "checker artifacts are stale"
        raise RuntimeError(f"cannot pin clean source without a current completed check ({reason})")
    checkpoint = record_checkpoint(record, CLEAN_CHECKPOINT_LABEL)
    inputs = current_input_snapshot(record)
    current_context = current_build_context(record, metrics)
    _validate_grouped_checkpoint(
        record,
        checkpoint,
        current_context,
        metrics,
        inputs,
        require_exact=metrics.get("result") == "MATCH",
    )
    baseline = {
        "checkpoint_id": checkpoint.get("id"),
        "label": CLEAN_CHECKPOINT_LABEL,
        "pinned_at": _iso(_utc_now()),
        "owner": owner,
        "note": checked_note,
        "inputs": inputs,
        "metrics": metrics,
    }
    with _sessions_lock():
        session = _require_active_owner(_load_session(record), owner, record)
        session["clean_baseline"] = baseline
        session["updated_at"] = _iso(_utc_now())
        session.setdefault("events", []).append(
            {
                "at": baseline["pinned_at"],
                "kind": "pin-clean",
                "owner": owner,
                "checkpoint": checkpoint.get("id"),
                "note": checked_note,
            }
        )
        _write_session(record, session)
    return session


def restore_clean_baseline(record: dict[str, str], owner: str) -> dict:
    """Restore the pinned clean source into the one living compiler-facing file."""
    baseline = require_clean_baseline(record, owner)
    restored = restore_checkpoint(record, str(baseline["checkpoint_id"]))
    return record_probe(
        record,
        owner,
        "restore",
        f"restored pinned clean source {str(baseline['checkpoint_id'])[:18]}",
        str(baseline["checkpoint_id"]),
        evidence={
            "kind": "clean_restore",
            "restored_source_path": restored.get("restored_source_path"),
            "restore_backup": restored.get("restore_backup"),
        },
        detect_output_duplicate=False,
    )


def run_checked_probe(
    record: dict[str, str],
    owner: str,
    kind: str,
    note: str,
    checkpoint: str,
    checker_args: list[str],
) -> tuple[int, dict]:
    with _sessions_lock():
        session = _require_active_owner(_load_session(record), owner, record)
        next_number = len(session.get("probes") or []) + 1
        clean_baseline = dict(session.get("clean_baseline") or {})
    label = checkpoint.strip() or f"probe-{next_number:03d}-{kind}"
    forbidden = {
        "--va",
        "--checkpoint",
        "--compare-checkpoint",
        "--no-history",
        "--history",
        "--restore-checkpoint",
    }
    for argument in checker_args:
        option = argument.split("=", 1)[0]
        if option in forbidden:
            raise ValueError(f"checker argument {option} is managed by target_session check")
    command = [
        sys.executable,
        str(REPO_ROOT / "tools" / "check_function.py"),
        "--va",
        record["va"],
        "--checkpoint",
        label,
        *(
            ["--compare-checkpoint", CLEAN_CHECKPOINT_LABEL]
            if clean_baseline and kind != "baseline"
            else []
        ),
        *checker_args,
    ]
    result = subprocess.run(command, cwd=REPO_ROOT)
    if result.returncode not in {0, 1}:
        raise RuntimeError(f"check_function failed with exit code {result.returncode}; probe was not recorded")
    if checkpoint_info(record, label) is None:
        raise RuntimeError("check_function did not complete a checkpoint; probe was not recorded")
    session = record_probe(record, owner, kind, note, label)
    if kind == "baseline":
        session = pin_clean_baseline(record, owner, note)
    return result.returncode, session


def require_final_validation(record: dict[str, str], session: dict) -> None:
    """Reject a pause that would leave the durable source newer than its check."""
    probes = session.get("probes") or []
    claim_probes = probes[int(session.get("probe_start_index") or 0) :]
    if not claim_probes:
        # A target may be paused before its first compile for a documented hard
        # blocker. Once checks exist, the stronger finalization contract applies.
        return
    latest = claim_probes[-1]
    command = (
        f"python tools/target_session.py check --va {record['va']} --owner {session['owner']} "
        "--kind validation --note \"final validation after attempt-log update\" -- --detail concise"
    )
    if latest.get("kind") != "validation":
        raise RuntimeError(
            "cannot pause after recorded checks until the last check is --kind validation; "
            f"update the function journal first, then run: {command}"
        )
    current_inputs = current_input_snapshot(record)
    if latest.get("inputs") != current_inputs:
        raise RuntimeError(
            "cannot pause because source/flags/compiler/include inputs changed after the final validation; "
            f"run: {command}"
        )
    metrics = current_metric_summary(record)
    if metrics.get("artifact_fresh") is not True:
        reason = metrics.get("freshness_reason") or "checker artifacts are stale"
        raise RuntimeError(
            f"cannot pause because the final validation is not current ({reason}); run: {command}"
        )
    if metrics.get("result") != "MATCH":
        baseline = session.get("clean_baseline") or {}
        if not baseline:
            raise RuntimeError(
                "cannot pause an unresolved checked target without a pinned clean-source baseline; "
                "audit the current natural reconstruction and run target_session.py pin-clean"
            )
        if not clean_baseline_is_current(record, session):
            raise RuntimeError(
                "cannot pause while the living source differs from the pinned clean reconstruction. "
                "Run restore-clean, update the function journal, validate, then pin-clean; or, if the current "
                "source is now the defensible natural reconstruction, explicitly pin-clean it after validation"
            )


def change_state(record: dict[str, str], owner: str, state: str, reason: str) -> dict:
    with _sessions_lock():
        session = _require_owner(_load_session(record), owner, record)
    metrics = current_metric_summary(record)
    if state == "pause":
        require_final_validation(record, session)
    elif state == "release":
        claim_probes = list(session.get("probes") or [])[int(session.get("probe_start_index") or 0) :]
        if claim_probes and not (
            metrics.get("result") == "MATCH" and metrics.get("artifact_fresh") is True
        ):
            raise RuntimeError(
                "release is only for an exact current result or a claim with no recorded work; "
                "finalize unresolved work with validation, pin-clean, and pause"
            )
        if claim_probes and metrics.get("result") == "MATCH":
            current_context = current_build_context(record, metrics)
            if current_context is not None:
                latest_checkpoint = str(claim_probes[-1].get("checkpoint") or "")
                if not latest_checkpoint:
                    raise RuntimeError(
                        "grouped exact release requires the latest check checkpoint"
                    )
                try:
                    checkpoint = checkpoint_info(record, latest_checkpoint)
                except (KeyError, OSError, json.JSONDecodeError) as error:
                    raise RuntimeError(
                        f"grouped exact release checkpoint is unavailable ({latest_checkpoint})"
                    ) from error
                _validate_grouped_checkpoint(
                    record,
                    checkpoint,
                    current_context,
                    metrics,
                    current_input_snapshot(record),
                    require_exact=True,
                )
    with _sessions_lock():
        session = _require_owner(_load_session(record), owner, record)
        now = _utc_now()
        session["state"] = state
        session["updated_at"] = _iso(now)
        session["lease_expires_at"] = _iso(now)
        session["last_metric_summary"] = metrics
        session.setdefault("events", []).append(
            {"at": _iso(now), "kind": state, "owner": owner, "reason": reason.strip()}
        )
        _write_session(record, session)
    return session


def format_session(record: dict[str, str], session: dict | None) -> str:
    source = preferred_source_path(record)
    metrics = current_metric_summary(record)
    journal_relative = function_recovery_note_relative_path(record["va"], function_slug(record))
    journal_exists = (REPO_ROOT / journal_relative).is_file()
    lines = [
        f"Target: {record['va']} {record['name']} ({record['size_bytes']} bytes)",
        f"Source: {_source_bucket(source)} / {source.relative_to(REPO_ROOT) if source.exists() else '<none>'}",
        f"PDB donor: {record.get('pdb_source_file', '') or '<none>'}",
        f"Recovery journal: {journal_relative.as_posix() if journal_exists else '<missing>'}",
    ]
    if session is None:
        lines.append("Session: unclaimed")
    else:
        total_checks = len(session.get("probes") or [])
        probes = meaningful_probe_count(session)
        total_probes = meaningful_probe_count(session, current_claim_only=False)
        active = "active" if _lease_active(session) else session.get("state", "inactive")
        lines.extend(
            [
                f"Session: {active}; owner={session.get('owner')} lease={session.get('lease_expires_at')}",
                f"Meaningful probes this claim: {probes}; "
                f"target total={total_probes}; recorded checks={total_checks}",
            ]
        )
        baseline = session.get("clean_baseline") or {}
        if baseline:
            baseline_metrics = baseline.get("metrics") or {}
            baseline_state = "CURRENT" if clean_baseline_is_current(record, session) else "saved"
            lines.append(
                f"Clean source [{baseline_state}]: {str(baseline.get('checkpoint_id') or '')[:18]} "
                f"diff={baseline_metrics.get('diff_bytes')} "
                f"note={str(baseline.get('note') or '-')[:180]}"
            )
        else:
            lines.append("Clean source: <not pinned>")
        if session.get("probes"):
            last_probe = session["probes"][-1]
            delta = last_probe.get("metric_delta") or {}
            changed = []
            for key, row in delta.items():
                if row.get("delta"):
                    direction = {
                        "improved": "assembly-closer",
                        "regressed": "assembly-farther",
                    }.get(str(row.get("direction")), str(row.get("direction") or "changed"))
                    changed.append(f"{key}={row['delta']:+g}({direction})")
            lines.append(
                f"Last probe: #{last_probe.get('number')} {last_probe.get('kind')} "
                f"checkpoint={last_probe.get('checkpoint') or '-'}"
            )
            if changed:
                lines.append("Last emitted-code metric delta: " + ", ".join(changed[:8]))
            if last_probe.get("same_emitted_code_as_probe") is not None:
                lines.append(
                    "Codegen duplicate: emitted code is unchanged from probe "
                    f"#{last_probe['same_emitted_code_as_probe']}."
                )
            evidence = last_probe.get("evidence") or {}
            if evidence.get("kind") == "variant_lab":
                lines.append(
                    "Variant lab: "
                    f"{evidence.get('variants')} variants, "
                    f"{evidence.get('invariant_eligible')} invariant-eligible, "
                    f"{evidence.get('exact_matches')} exact; {evidence.get('run_dir')}"
                )
    if metrics:
        freshness = "current" if metrics.get("artifact_fresh") else "STALE"
        rebuilt_frame = metrics.get("rebuilt_frame")
        original_frame = metrics.get("original_frame")
        frame_text = (
            f"{('-' if rebuilt_frame is None else f'0x{int(rebuilt_frame):X}')}/"
            f"{('-' if original_frame is None else f'0x{int(original_frame):X}')}"
        )
        lines.append(
            f"Latest recorded check [{freshness}]: "
            f"{metrics.get('result')} diff={metrics.get('diff_bytes')} ({float(metrics.get('diff_percent') or 0):.4f}%) "
            f"shape={float(metrics.get('shape_percent') or 0):.2f}% frame={frame_text} "
            f"code_size={metrics.get('meaningful_rebuilt_size')}/{metrics.get('original_size')} "
            f"first={metrics.get('first_mismatch_offset')}"
        )
        lines.append(
            "Ordered calls: "
            f"aligned={float(metrics.get('call_similarity_percent') or 0):.2f}% "
            f"sites equal={metrics.get('call_equal_sites')} "
            f"-{metrics.get('call_deleted_sites')}/+{metrics.get('call_inserted_sites')} "
            f"replaced={metrics.get('call_replaced_sites')} "
            f"target-count-gap={metrics.get('call_target_count_gap')}"
        )
        lines.append(
            f"Structural coverage: exact-blocks={float(metrics.get('exact_block_coverage_percent') or 0):.2f}% "
            f"edit-diff={metrics.get('edit_diff_bytes')} "
            f"({float(metrics.get('edit_diff_percent') or 0):.2f}%)"
        )
        if metrics.get("workflow_stage"):
            lines.append(f"Checker stage: {metrics['workflow_stage']}")
        if metrics.get("diagnostic_class") and metrics.get("diagnostic_class") != "EXACT":
            lines.append(f"Diagnostic class (audit only): {metrics['diagnostic_class']}")
        if not metrics.get("artifact_fresh"):
            lines.append(f"Freshness: {metrics.get('freshness_reason')}")
    else:
        lines.append("Latest check: <none>")
    try:
        codegen_best = checkpoint_info(record, "@best-positional")
    except (KeyError, OSError, json.JSONDecodeError):
        codegen_best = {}
    if codegen_best:
        best_summary = codegen_best.get("summary") or {}
        lines.append(
            f"Codegen best (diagnostic): {str(codegen_best.get('id') or '')[:18]} "
            f"diff={best_summary.get('diff_bytes')} shape={float(best_summary.get('shape_percent') or 0):.2f}%"
        )
    lines.extend(
        [
            f"Recorded checker checkpoints: {_history_count(record)}",
            f"Recommendation: {classify_next_stage(metrics)}",
            "",
            "Useful commands:",
            f"  python tools/target_session.py history --va {record['va']}",
            f"  python tools/target_dossier.py --va {record['va']}",
            f"  python tools/query_abi.py --va {record['va']} --limit 40",
            f"  python tools/find_function_donors.py --va {record['va']} --limit 20",
            f"  python tools/check_function.py --va {record['va']} --detail concise",
            f"  python tools/check_function.py --va {record['va']} --call-map-unmatched --map-limit 40",
            f"  python tools/check_function.py --va {record['va']} --stack-map --no-build",
            f"  python tools/check_function.py --va {record['va']} --history",
        ]
    )
    return "\n".join(lines)


def session_status_payload(record: dict[str, str], session: dict | None) -> dict[str, object]:
    source = preferred_source_path(record)
    metrics = current_metric_summary(record)
    journal_relative = function_recovery_note_relative_path(record["va"], function_slug(record))
    try:
        codegen_best = checkpoint_info(record, "@best-positional")
    except (KeyError, OSError, json.JSONDecodeError):
        codegen_best = {}
    return {
        "target": {
            "va": record["va"],
            "name": record["name"],
            "size_bytes": int(record["size_bytes"]),
            "pdb_source_file": record.get("pdb_source_file", ""),
            "source_bucket": _source_bucket(source),
            "source_path": str(source.relative_to(REPO_ROOT)) if source.exists() else "",
            "recovery_journal_path": journal_relative.as_posix()
            if (REPO_ROOT / journal_relative).is_file()
            else "",
        },
        "session": session,
        "current_metrics": metrics,
        "clean_baseline": dict((session or {}).get("clean_baseline") or {}),
        "codegen_best": codegen_best,
        "checkpoint_count": _history_count(record),
        "recommendation": classify_next_stage(metrics),
    }


def _all_sessions() -> list[dict]:
    root = _sessions_root()
    if not root.exists():
        return []
    rows = []
    for path in sorted(root.glob("*.json")):
        try:
            rows.append(json.loads(path.read_text(encoding="utf-8")))
        except json.JSONDecodeError:
            rows.append({"slug": path.stem, "state": "invalid", "owner": "", "updated_at": ""})
    return rows


def load_target_sessions(vas: set[str] | None = None) -> list[dict]:
    """Return compact session summaries for status tooling.

    A bounded VA lookup reads only its session file. Broad lookups use an
    atomic summary index. The index repairs itself when any session file changes.
    """
    if vas is not None:
        rows: list[dict] = []
        root = _sessions_root()
        if not root.exists():
            return rows
        for va in sorted({value.upper() for value in vas}):
            matches = sorted(root.glob(f"{va}_*.json"))
            for path in matches:
                try:
                    rows.append(target_session_summary(json.loads(path.read_text(encoding="utf-8"))))
                except (json.JSONDecodeError, OSError, TypeError, ValueError):
                    rows.append(
                        {
                            "summary_version": SESSION_INDEX_VERSION,
                            "va": va,
                            "slug": path.stem,
                            "owner": "",
                            "state": "invalid",
                        }
                    )
        return rows

    fingerprint = _session_file_fingerprint()
    index = _read_session_index()
    if index is None or index.get("session_files_fingerprint") != fingerprint:
        with _sessions_lock():
            fingerprint = _session_file_fingerprint()
            index = _read_session_index()
            if index is None or index.get("session_files_fingerprint") != fingerprint:
                index = _rebuild_session_index()
    return [index["sessions"][va] for va in sorted(index["sessions"])]


def session_is_active(session: dict) -> bool:
    return _lease_active(session)


def format_session_list(rows: list[dict], active_only: bool = False) -> str:
    if active_only:
        rows = [row for row in rows if _lease_active(row)]
    if not rows:
        return "No target sessions."
    lines = ["VA       owner                state     probes clean  lease/update", "-" * 86]
    for row in rows:
        state = "active" if _lease_active(row) else str(row.get("state", ""))
        probes = meaningful_probe_count(row)
        when = row.get("lease_expires_at") if state == "active" else row.get("updated_at")
        lines.append(
            f"{row.get('va', ''):<8} {str(row.get('owner', '')):<20} {state:<9} "
            f"{probes:>6} {('yes' if row.get('clean_baseline') else 'no'):<6} {when or ''}"
        )
    return "\n".join(lines)


def _history_index(record: dict[str, str]) -> dict:
    """Load the checker checkpoint index for a target (mirrors _history_count)."""
    path = REPO_ROOT / "build" / "history" / function_slug(record) / "history.json"
    if not path.exists():
        return {"slug": function_slug(record), "labels": {}, "runs": []}
    try:
        payload = json.loads(path.read_text(encoding="utf-8"))
    except json.JSONDecodeError:
        return {"slug": function_slug(record), "labels": {}, "runs": []}
    payload.setdefault("labels", {})
    payload.setdefault("runs", [])
    return payload


def format_history(record: dict[str, str], session: dict | None, limit: int) -> str:
    """Human-readable per-target history: checker runs plus notebook probes, newest first."""
    index = _history_index(record)
    runs = list(index.get("runs") or [])
    probes = list((session or {}).get("probes") or [])
    lines = [
        f"Target: {record['va']} {record['name']} ({record['size_bytes']} bytes)",
    ]
    if session is None:
        lines.append("Session: unclaimed")
    else:
        state = "active" if _lease_active(session) else str(session.get("state", "inactive"))
        lines.append(
            f"Session: {state}; owner={session.get('owner')} "
            f"claimed={session.get('claimed_at')} updated={session.get('updated_at')}"
        )
        lines.append(
            f"Probes: {len(probes)} recorded; "
            f"{meaningful_probe_count(session)} meaningful this claim; "
            f"checker checkpoints: {len(runs)}"
        )
    lines.append("")
    lines.append("Checker runs (newest first):")
    if not runs:
        lines.append("  <none recorded>")
    else:
        lines.append("at (UTC)             result    diff      diff%     resync    flags  labels / source")
        shown = 0
        for run in reversed(runs):
            if limit > 0 and shown >= limit:
                break
            shown += 1
            summary = run.get("summary") or {}
            when = str(run.get("timestamp") or run.get("id") or "?")[:19].replace("T", " ")
            result = summary.get("result", "?")
            diff_b = summary.get("diff_bytes")
            diff_p = float(summary.get("diff_percent") or 0)
            resync = float(summary.get("resync_similarity_percent") or 0)
            flags = "custom" if run.get("custom_flags") else "-"
            labels = ",".join(run.get("labels") or []) or "-"
            source = str(run.get("source_path") or "?")
            lines.append(
                f"{when:<19} {str(result):<9} {str(diff_b):>8} {diff_p:>7.1f}% {resync:>7.1f}% "
                f"{flags:<6} {labels:<20} {source}"
            )
            context = run.get("build_context") or {}
            translation_unit = context.get("translation_unit") or {}
            if translation_unit:
                pdb_owner = context.get("pdb_owner") or {}
                lines.append(
                    f"    build context: TU={translation_unit.get('name') or '?'} "
                    f"fingerprint={str(context.get('fingerprint') or '')[:16]} "
                    f"owners={len(translation_unit.get('owners') or {})} "
                    f"symbols={len(translation_unit.get('symbols') or {})} "
                    f"pdb_owner={pdb_owner.get('status') or 'unverified'}"
                )
    lines.append("")
    lines.append("Notebook probes (newest first):")
    if not probes:
        lines.append("  <none recorded>")
    else:
        lines.append("#    kind           at (UTC)             checkpoint        note")
        shown = 0
        for probe in reversed(probes):
            if limit > 0 and shown >= limit:
                break
            shown += 1
            note = str(probe.get("note") or "").replace("\n", " ")[:90]
            lines.append(
                f"#{str(probe.get('number', '?')):<4} {str(probe.get('kind')):<15} "
                f"{str(probe.get('at'))[:19].replace('T', ' '):<19} {str(probe.get('checkpoint') or '-'):<17} {note}"
            )
    lines.append("")
    lines.append(
        f"Full data: python tools/target_session.py history --va {record['va']} --json "
        f"(or build/history/{function_slug(record)}/history.json)"
    )
    return "\n".join(lines)


def format_brief(record: dict[str, str], session: dict | None, note_limit: int) -> str:
    """Return a bounded worker handoff without raw checkpoint/session payloads."""
    status_lines = format_session(record, session).split("\n\nUseful commands:", 1)[0]
    lines = [status_lines]
    translation_unit = compiler_translation_unit_for_va(int(record["va"], 16))
    if translation_unit is not None:
        lines.extend(
            [
                f"Translation unit: {translation_unit['name']} / {translation_unit['source']}",
                f"Registered exact neighbors: {len(translation_unit.get('owners') or {})}",
            ]
        )
    if session is None:
        lines.extend(["", "Prior evidence: <no target session>"])
        return "\n".join(lines)

    probes = list(session.get("probes") or [])
    meaningful = [probe for probe in probes if _probe_is_meaningful(probe)]
    improvement = last_positional_improvement(session)
    identities = {
        str((probe.get("outputs") or {}).get("emitted_identity_sha256"))
        for probe in probes
        if (probe.get("outputs") or {}).get("emitted_identity_sha256")
    }
    best_diffs = [
        int((probe.get("metrics") or {}).get("diff_bytes"))
        for probe in probes
        if (probe.get("metrics") or {}).get("diff_bytes") is not None
    ]
    lines.extend(
        [
            "",
            "Cumulative work:",
            f"  claims={session_claim_count(session)} meaningful_probes={len(meaningful)} "
            f"recorded_checks={len(probes)} emitted_code_groups={len(identities)}",
            f"  best_positional_diff={min(best_diffs) if best_diffs else '-'} "
            f"last_positional_gain={('#' + str(improvement.get('number'))) if improvement else 'none recorded'}",
            "",
            f"Recent meaningful notes (newest first, max {note_limit}):",
        ]
    )
    if not meaningful:
        lines.append("  <none recorded>")
    else:
        selected = meaningful if note_limit == 0 else meaningful[-note_limit:]
        for probe in reversed(selected):
            metrics = probe.get("metrics") or {}
            duplicate = probe.get("same_emitted_code_as_probe")
            duplicate_text = f" duplicate=#{duplicate}" if duplicate is not None else ""
            note = " ".join(str(probe.get("note") or "").split())[:220]
            lines.append(
                f"  #{probe.get('number', '?')} claim_probe={probe.get('claim_number', '?')} "
                f"{probe.get('kind', '?')} diff={metrics.get('diff_bytes', '-')}{duplicate_text}: {note}"
            )
    lines.extend(
        [
            "",
            "Read the tracked function journal next. Search LESSONS.md only for narrow blocker terms.",
            "Do not load raw target-session JSON. Use bounded history only for a specific open question.",
        ]
    )
    return "\n".join(lines)


def history_payload(record: dict[str, str], session: dict | None, limit: int) -> dict[str, object]:
    """Structured per-target history (runs and probes, newest first)."""
    index = _history_index(record)
    runs = list(index.get("runs") or [])
    probes = list((session or {}).get("probes") or [])
    if limit > 0:
        runs = runs[-limit:]
        probes = probes[-limit:]
    return {
        "target": {
            "va": record["va"],
            "name": record["name"],
            "slug": function_slug(record),
            "size_bytes": int(record["size_bytes"]),
        },
        "session": session,
        "checkpoint_count": len(index.get("runs") or []),
        "runs": list(reversed(runs)),
        "probes": list(reversed(probes)),
    }


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=(
            "Advisory target leases, clean-source checkpoints, and meaningful-probe bookkeeping "
            "for parallel matching work.\n"
            "\n"
            "Conventions:\n"
            "  --va        target VA as hex, e.g. 00425A40\n"
            "  --owner     stable agent/session name (use your subagent id)\n"
            "  pause/release require --reason (--note is an alias for it)\n"
            "  status      takes --va only; --owner is NOT accepted\n"
            "  list        flags are --active and --json only (there is no --all flag)\n"
            "  brief       shows a bounded worker handoff with recent meaningful notes\n"
            "  history     shows a target's checker checkpoints and notebook probes\n"
            "\n"
            "Examples:\n"
            '  python tools/target_session.py start --va 00425A40 --owner sa-1234\n'
            '  python tools/target_session.py check --va 00425A40 --owner sa-1234 '
            '--kind abi --note "hypothesis note" -- --detail concise\n'
            '  python tools/target_session.py status --va 00425A40\n'
            '  python tools/target_session.py brief --va 00425A40\n'
            '  python tools/target_session.py history --va 00425A40\n'
            '  python tools/target_session.py release --va 00425A40 --owner sa-1234 '
            '--reason "exact match"\n'
            '  python tools/target_session.py list --active\n'
        ),
        epilog=(
            "Per-target attempt history also lives on disk under "
            "build/history/<va>_<slug>/runs/ and build/dossiers/<slug>.{txt,json}."
        ),
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    start = subparsers.add_parser(
        "start",
        help="Claim or resume one target lease and print a briefing. Requires --va and --owner.",
    )
    start.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    start.add_argument("--owner", required=True, help="Stable agent/session name (use your subagent id).")
    start.add_argument(
        "--budget",
        type=int,
        default=20,
        help=argparse.SUPPRESS,
    )
    start.add_argument("--lease-hours", type=float, default=8.0, help="Lease duration in hours (default 8.0).")
    start.add_argument("--force", action="store_true", help="Deliberately take over another active lease (use with care).")

    probe = subparsers.add_parser(
        "probe",
        help="Record one hypothesis probe on a target. Requires --va --owner --kind --note.",
    )
    probe.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    probe.add_argument("--owner", required=True, help="Stable agent/session name (use your subagent id).")
    probe.add_argument(
        "--kind", required=True, choices=PROBE_KINDS,
        help="Probe kind. One of: " + ", ".join(PROBE_KINDS) + ".",
    )
    probe.add_argument("--note", required=True, help="Free-form note describing the hypothesis (required).")
    probe.add_argument("--checkpoint", default="", help="Optional checker checkpoint label/id.")

    check = subparsers.add_parser(
        "check",
        help="Run check_function under the active lease, checkpoint it, and record a probe. "
        "Requires --va --owner --kind --note.",
    )
    check.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    check.add_argument("--owner", required=True, help="Stable agent/session name (use your subagent id).")
    check.add_argument(
        "--kind", required=True, choices=PROBE_KINDS,
        help="Probe kind. One of: " + ", ".join(PROBE_KINDS) + ".",
    )
    check.add_argument("--note", required=True, help="Free-form note describing the hypothesis (required).")
    check.add_argument("--checkpoint", default="", help="Optional label; defaults to probe-NNN-kind.")
    check.add_argument(
        "checker_args",
        nargs=argparse.REMAINDER,
        help="Everything after '--' is forwarded to check_function, e.g. -- --detail concise.",
    )

    pin_clean = subparsers.add_parser(
        "pin-clean",
        help="Pin the current checked source as the canonical clean reconstruction. "
        "Requires --va --owner --note.",
    )
    pin_clean.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    pin_clean.add_argument("--owner", required=True, help="Stable agent/session name (use your subagent id).")
    pin_clean.add_argument(
        "--note",
        required=True,
        help="Canonical ownership and plausible original-source family (required).",
    )

    restore_clean = subparsers.add_parser(
        "restore-clean",
        help="Restore the pinned clean reconstruction into the one living source file. "
        "Requires --va --owner.",
    )
    restore_clean.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    restore_clean.add_argument("--owner", required=True, help="Stable agent/session name (use your subagent id).")

    for command in ("pause", "release"):
        action = subparsers.add_parser(
            command,
            help=f"{command.title()} the lease while keeping its notebook. "
            "Requires --va --owner and --reason (or its alias --note).",
        )
        action.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
        action.add_argument("--owner", required=True, help="Stable agent/session name (use your subagent id).")
        reason = action.add_mutually_exclusive_group(required=True)
        reason.add_argument("--reason", dest="reason", help="Why the lease is being paused/released (REQUIRED).")
        reason.add_argument("--note", dest="reason", help="Alias for --reason (REQUIRED either way).")

    status = subparsers.add_parser(
        "status",
        help="Show one target's lease, metrics, and next stage. Takes --va only (no --owner).",
    )
    status.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    status.add_argument("--json", action="store_true", help="Emit JSON instead of the human summary.")

    brief = subparsers.add_parser(
        "brief",
        help="Show a bounded worker handoff. Takes --va only and never emits raw session JSON.",
    )
    brief.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    brief.add_argument(
        "--notes", type=int, default=20,
        help="Maximum recent meaningful notes (0 = all; default 20).",
    )

    history = subparsers.add_parser(
        "history",
        help="Show a target's checker checkpoint runs and notebook probes, newest first.",
    )
    history.add_argument("--va", required=True, help="Target VA as hex, e.g. 00425A40.")
    history.add_argument("--json", action="store_true", help="Emit JSON instead of the human tables.")
    history.add_argument(
        "--limit", type=int, default=15,
        help="Max rows per section, newest first (0 = all; default 15).",
    )

    listing = subparsers.add_parser(
        "list",
        help="List target sessions. Flags are --active and --json only (no --all, no --va).",
    )
    listing.add_argument("--active", action="store_true", help="Show only unexpired active leases.")
    listing.add_argument("--json", action="store_true", help="Emit JSON instead of the human table.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    if args.command == "list":
        rows = _all_sessions()
        print(json.dumps(rows, indent=2) if args.json else format_session_list(rows, args.active))
        return

    record = function_record_by_va(int(args.va, 16))
    try:
        if args.command == "start":
            if args.budget < 0:
                raise ValueError("--budget must be zero or positive")
            if args.lease_hours <= 0:
                raise ValueError("--lease-hours must be positive")
            session = start_session(record, args.owner, args.budget, args.lease_hours, args.force)
            print(format_brief(record, session, 20))
        elif args.command == "probe":
            session = record_probe(record, args.owner, args.kind, args.note, args.checkpoint)
            if args.kind == "baseline":
                session = pin_clean_baseline(record, args.owner, args.note)
            print(format_session(record, session))
        elif args.command == "check":
            checker_args = list(args.checker_args)
            if checker_args and checker_args[0] == "--":
                checker_args = checker_args[1:]
            _returncode, session = run_checked_probe(
                record,
                args.owner,
                args.kind,
                args.note,
                args.checkpoint,
                checker_args,
            )
            print(format_session(record, session))
        elif args.command == "pin-clean":
            session = pin_clean_baseline(record, args.owner, args.note)
            print(format_session(record, session))
        elif args.command == "restore-clean":
            session = restore_clean_baseline(record, args.owner)
            print(format_session(record, session))
        elif args.command in {"pause", "release"}:
            session = change_state(record, args.owner, args.command, args.reason)
            print(format_session(record, session))
        elif args.command == "status":
            session = _load_session(record)
            print(
                json.dumps(session_status_payload(record, session), indent=2)
                if args.json
                else format_session(record, session)
            )
        elif args.command == "brief":
            if args.notes < 0:
                raise ValueError("--notes must be zero or positive")
            print(format_brief(record, _load_session(record), args.notes))
        elif args.command == "history":
            if args.limit < 0:
                raise ValueError("--limit must be zero or positive")
            session = _load_session(record)
            print(
                json.dumps(history_payload(record, session, args.limit), indent=2)
                if args.json
                else format_history(record, session, args.limit)
            )
    except (RuntimeError, ValueError, FileNotFoundError, KeyError) as error:
        raise SystemExit(str(error)) from error


if __name__ == "__main__":
    main()
