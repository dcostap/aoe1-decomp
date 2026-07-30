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
    function_record_by_va,
    function_slug,
    load_toolchain,
    preferred_flags_rsp_path,
    preferred_source_path,
)


SESSION_VERSION = 2
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
    "other",
)


def _utc_now() -> datetime:
    return datetime.now(timezone.utc)


def _iso(value: datetime) -> str:
    return value.replace(microsecond=0).isoformat().replace("+00:00", "Z")


def _parse_iso(value: str) -> datetime:
    return datetime.fromisoformat(value.replace("Z", "+00:00"))


def _sessions_root() -> Path:
    return REPO_ROOT / "build" / "target_sessions"


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


def _write_session(record: dict[str, str], payload: dict) -> None:
    path = _session_path(record)
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix(".json.tmp")
    temporary.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    temporary.replace(path)


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
    return probe.get("kind") != "restore"


def meaningful_probe_count(session: dict, *, current_claim_only: bool = True) -> int:
    probes = list(session.get("probes") or [])
    if current_claim_only:
        probes = probes[int(session.get("probe_start_index") or 0) :]
    return sum(_probe_is_meaningful(probe) for probe in probes)


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
    source = preferred_source_path(record)
    if not source.exists():
        return False, "living source is missing"
    try:
        toolchain = load_toolchain()
        flags = preferred_flags_rsp_path(record, toolchain)
        fingerprint = str(build_input_manifest(source, flags, toolchain)["fingerprint"])
    except (FileNotFoundError, KeyError, OSError) as error:
        return False, f"cannot fingerprint current inputs: {error}"
    obj = REPO_ROOT / "build" / "obj" / f"{slug}.obj"
    manifest = REPO_ROOT / "build" / "manifests" / f"build_{slug}.json"
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
        return "Exact candidate: review source/flags and validate locally before promotion."
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
        return "Focused codegen: preserve aligned regions and use a localized range or deliberate variant lab."
    if int(metrics.get("wrong_direct_targets") or 0) or int(metrics.get("call_target_count_gap") or 0):
        return "Behavior/ABI first: resolve missing, extra, or wrong direct calls before source-shape tuning."
    original_frame = metrics.get("original_frame")
    rebuilt_frame = metrics.get("rebuilt_frame")
    if original_frame is not None and rebuilt_frame is not None and original_frame != rebuilt_frame:
        return "Stack/local topology: investigate parameter homes, address-taken locals, and declaration lifetimes."
    shape = metrics.get("shape_percent")
    if shape is None or float(shape) < 75.0:
        return "Structural reconstruction: fix the first block/control-flow divergence; do not run broad variant sweeps."
    return "Focused codegen: preserve aligned regions and use a localized range or deliberate variant lab."


def _new_session(
    record: dict[str, str], owner: str, budget: int, lease_hours: float, prior: dict | None
) -> dict:
    now = _utc_now()
    events = list((prior or {}).get("events") or [])
    probes = list((prior or {}).get("probes") or [])
    continuing_active_claim = bool(
        prior and prior.get("owner") == owner and _lease_active(prior, now)
    )
    if prior and prior.get("owner") != owner:
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
        "last_metric_summary": current_metric_summary(record),
    }


def start_session(
    record: dict[str, str], owner: str, budget: int, lease_hours: float, force: bool = False
) -> dict:
    checked_owner = _validate_owner(owner)
    with _sessions_lock():
        prior = _load_session(record)
        if prior and _lease_active(prior) and prior.get("owner") != checked_owner and not force:
            raise RuntimeError(
                f"{record['va']} is actively leased by {prior.get('owner')} until {prior.get('lease_expires_at')}; "
                "coordinate with that owner or use --force for a deliberate takeover"
            )
        session = _new_session(record, checked_owner, budget, lease_hours, prior)
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
    source = preferred_source_path(record)
    try:
        toolchain = load_toolchain()
        flags = preferred_flags_rsp_path(record, toolchain)
    except (FileNotFoundError, KeyError, OSError):
        flags = REPO_ROOT / "config" / "flags" / "default.rsp"
    return {
        "source_path": str(source.relative_to(REPO_ROOT)) if source.exists() else "",
        "source_sha256": _sha256(source) if source.exists() else "",
        "flags_path": str(flags.relative_to(REPO_ROOT)) if flags.exists() and flags.is_relative_to(REPO_ROOT) else str(flags),
        "flags_sha256": _sha256(flags) if flags.exists() else "",
    }


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


def record_probe(record: dict[str, str], owner: str, kind: str, note: str, checkpoint: str = "") -> dict:
    with _sessions_lock():
        session = _require_active_owner(_load_session(record), owner, record)
        now = _utc_now()
        metrics = current_metric_summary(record)
        prior_metrics = {}
        if session.get("probes"):
            prior_metrics = dict(session["probes"][-1].get("metrics") or {})
        outputs = current_output_snapshot(record, metrics)
        duplicate_of = None
        identity = outputs.get("emitted_identity_sha256")
        if identity:
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
            "meaningful": kind != "restore",
            "note": note.strip(),
            "checkpoint": checkpoint.strip(),
            "metrics": metrics,
            "metric_delta": metric_delta(metrics, prior_metrics),
            "inputs": current_input_snapshot(record),
            "outputs": outputs,
            "same_emitted_code_as_probe": duplicate_of,
        }
        session.setdefault("probes", []).append(probe)
        session.setdefault("events", []).append(
            {"at": _iso(now), "kind": "probe", "probe_number": probe["number"]}
        )
        session["updated_at"] = _iso(now)
        session["lease_expires_at"] = _iso(now + timedelta(hours=float(session.get("lease_hours") or 8)))
        session["last_metric_summary"] = metrics
        _write_session(record, session)
    return session


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
        used = meaningful_probe_count(session)
        budget = int(session.get("meaningful_probe_budget") or 0)
        next_number = len(session.get("probes") or []) + 1
    if budget and used >= budget:
        print(
            f"WARNING: meaningful probe budget is exhausted ({used}/{budget}); "
            "continue only if this is a deliberate new lead.",
            file=sys.stderr,
        )
    label = checkpoint.strip() or f"probe-{next_number:03d}-{kind}"
    forbidden = {"--va", "--checkpoint", "--no-history", "--history", "--restore-checkpoint"}
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
        *checker_args,
    ]
    result = subprocess.run(command, cwd=REPO_ROOT)
    if result.returncode not in {0, 1}:
        raise RuntimeError(f"check_function failed with exit code {result.returncode}; probe was not recorded")
    session = record_probe(record, owner, kind, note, label)
    return result.returncode, session


def change_state(record: dict[str, str], owner: str, state: str, reason: str) -> dict:
    with _sessions_lock():
        session = _require_owner(_load_session(record), owner, record)
        now = _utc_now()
        session["state"] = state
        session["updated_at"] = _iso(now)
        session["lease_expires_at"] = _iso(now)
        session["last_metric_summary"] = current_metric_summary(record)
        session.setdefault("events", []).append(
            {"at": _iso(now), "kind": state, "owner": owner, "reason": reason.strip()}
        )
        _write_session(record, session)
    return session


def format_session(record: dict[str, str], session: dict | None) -> str:
    source = preferred_source_path(record)
    metrics = current_metric_summary(record)
    lines = [
        f"Target: {record['va']} {record['name']} ({record['size_bytes']} bytes)",
        f"Source: {_source_bucket(source)} / {source.relative_to(REPO_ROOT) if source.exists() else '<none>'}",
        f"PDB donor: {record.get('pdb_source_file', '') or '<none>'}",
    ]
    if session is None:
        lines.append("Session: unclaimed")
    else:
        total_checks = len(session.get("probes") or [])
        probes = meaningful_probe_count(session)
        total_probes = meaningful_probe_count(session, current_claim_only=False)
        budget = int(session.get("meaningful_probe_budget") or 0)
        remaining = max(0, budget - probes) if budget else "unbounded"
        active = "active" if _lease_active(session) else session.get("state", "inactive")
        lines.extend(
            [
                f"Session: {active}; owner={session.get('owner')} lease={session.get('lease_expires_at')}",
                f"Meaningful probes this claim: {probes}/{budget or 'unbounded'}; "
                f"remaining={remaining}; target total={total_probes}; recorded checks={total_checks}",
            ]
        )
        if session.get("probes"):
            last_probe = session["probes"][-1]
            delta = last_probe.get("metric_delta") or {}
            changed = []
            for key, row in delta.items():
                if row.get("delta"):
                    changed.append(f"{key}={row['delta']:+g}({row.get('direction', 'changed')})")
            lines.append(
                f"Last probe: #{last_probe.get('number')} {last_probe.get('kind')} "
                f"checkpoint={last_probe.get('checkpoint') or '-'}"
            )
            if changed:
                lines.append("Last metric delta: " + ", ".join(changed[:8]))
            if last_probe.get("same_emitted_code_as_probe") is not None:
                lines.append(
                    "Codegen duplicate: emitted code is unchanged from probe "
                    f"#{last_probe['same_emitted_code_as_probe']}."
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
        if not metrics.get("artifact_fresh"):
            lines.append(f"Freshness: {metrics.get('freshness_reason')}")
    else:
        lines.append("Latest check: <none>")
    lines.extend(
        [
            f"Recorded checker checkpoints: {_history_count(record)}",
            f"Recommendation: {classify_next_stage(metrics)}",
            "",
            "Useful commands:",
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
    return {
        "target": {
            "va": record["va"],
            "name": record["name"],
            "size_bytes": int(record["size_bytes"]),
            "pdb_source_file": record.get("pdb_source_file", ""),
            "source_bucket": _source_bucket(source),
            "source_path": str(source.relative_to(REPO_ROOT)) if source.exists() else "",
        },
        "session": session,
        "current_metrics": metrics,
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


def load_target_sessions() -> list[dict]:
    """Return local shared-tree target session rows for status tooling."""
    return _all_sessions()


def session_is_active(session: dict) -> bool:
    return _lease_active(session)


def format_session_list(rows: list[dict], active_only: bool = False) -> str:
    if active_only:
        rows = [row for row in rows if _lease_active(row)]
    if not rows:
        return "No target sessions."
    lines = ["VA       owner                state     probes  lease/update", "-" * 78]
    for row in rows:
        state = "active" if _lease_active(row) else str(row.get("state", ""))
        probes = meaningful_probe_count(row)
        budget = row.get("meaningful_probe_budget") or "-"
        when = row.get("lease_expires_at") if state == "active" else row.get("updated_at")
        lines.append(
            f"{row.get('va', ''):<8} {str(row.get('owner', '')):<20} {state:<9} "
            f"{probes:>3}/{str(budget):<3} {when or ''}"
        )
    return "\n".join(lines)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Advisory target leases and meaningful-probe bookkeeping for parallel matching work."
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    start = subparsers.add_parser("start", help="Claim or resume one target and print a diagnostic briefing.")
    start.add_argument("--va", required=True)
    start.add_argument("--owner", required=True, help="Stable agent/session name.")
    start.add_argument("--budget", type=int, default=10, help="Meaningful hypothesis budget (default 10).")
    start.add_argument("--lease-hours", type=float, default=8.0)
    start.add_argument("--force", action="store_true", help="Deliberately take over another active lease.")

    probe = subparsers.add_parser("probe", help="Record one interpreted hypothesis after a checker run.")
    probe.add_argument("--va", required=True)
    probe.add_argument("--owner", required=True)
    probe.add_argument("--kind", required=True, choices=PROBE_KINDS)
    probe.add_argument("--note", required=True)
    probe.add_argument("--checkpoint", default="", help="Optional checker checkpoint label/id.")

    check = subparsers.add_parser(
        "check", help="Run check_function under the active lease, checkpoint it, and record one probe."
    )
    check.add_argument("--va", required=True)
    check.add_argument("--owner", required=True)
    check.add_argument("--kind", required=True, choices=PROBE_KINDS)
    check.add_argument("--note", required=True)
    check.add_argument("--checkpoint", default="", help="Optional label; defaults to probe-NNN-kind.")
    check.add_argument(
        "checker_args",
        nargs=argparse.REMAINDER,
        help="Additional check_function arguments after --, for example -- --detail concise.",
    )

    for command in ("pause", "release"):
        action = subparsers.add_parser(command, help=f"{command.title()} the lease while retaining its notebook.")
        action.add_argument("--va", required=True)
        action.add_argument("--owner", required=True)
        reason = action.add_mutually_exclusive_group(required=True)
        reason.add_argument("--reason", dest="reason")
        reason.add_argument("--note", dest="reason", help="Alias for --reason.")

    status = subparsers.add_parser("status", help="Show one target's lease, metrics, and recommended next stage.")
    status.add_argument("--va", required=True)
    status.add_argument("--json", action="store_true")

    listing = subparsers.add_parser("list", help="List target sessions in this shared working tree.")
    listing.add_argument("--active", action="store_true", help="Show only unexpired active leases.")
    listing.add_argument("--json", action="store_true")
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
            print(format_session(record, session))
        elif args.command == "probe":
            session = record_probe(record, args.owner, args.kind, args.note, args.checkpoint)
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
    except (RuntimeError, ValueError) as error:
        raise SystemExit(str(error)) from error


if __name__ == "__main__":
    main()
