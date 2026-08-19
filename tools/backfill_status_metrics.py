from __future__ import annotations

import argparse
import csv
import gzip
import hashlib
import json
import re
import subprocess
from pathlib import Path

from common import REPO_ROOT
from status_history import BACKFILL_METRICS_PATH


SOURCE_RE = re.compile(
    r"^src/(scratch|matching|accepted_drift|verified_logic)/([0-9A-Fa-f]{8}_[^/]+)\.(?:c|cpp)$"
)
FIELDS = (
    "commit", "va", "source_bucket", "source_sha256", "flags_sha256", "evidence_run",
    "diff_result", "diff_percent", "diff_bytes", "diff_spans",
    "positional_diff_percent", "positional_diff_bytes", "positional_diff_spans",
    "edit_diff_percent", "edit_diff_bytes", "edit_insert_bytes", "edit_delete_bytes",
    "edit_replace_bytes", "edit_equal_bytes", "likely_shifted_alignment",
    "first_mismatch_offset",
)
METRIC_KEYS = FIELDS[6:]


def git_bytes(commit: str, path: str) -> bytes | None:
    try:
        return subprocess.check_output(
            ["git", "show", f"{commit}:{path}"],
            cwd=REPO_ROOT,
            stderr=subprocess.DEVNULL,
        )
    except subprocess.CalledProcessError:
        return None


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def changed_sources(commit: str) -> list[tuple[str, str]]:
    output = subprocess.check_output(
        ["git", "diff-tree", "--no-commit-id", "--name-status", "-r", "-M", commit],
        cwd=REPO_ROOT,
        text=True,
    )
    found: dict[str, str] = {}
    for line in output.splitlines():
        parts = line.split("\t")
        if len(parts) < 2:
            continue
        path = parts[-1].replace("\\", "/")
        match = SOURCE_RE.match(path)
        if match:
            found[match.group(2)] = path
    return sorted(found.items())


def checkpoint_metrics(slug: str, source_hash: str, flags_hash: str) -> tuple[dict[str, object], str] | None:
    history_path = REPO_ROOT / "build" / "history" / slug / "history.json"
    if not history_path.is_file():
        return None
    try:
        history = json.loads(history_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None
    candidates = [
        run for run in history.get("runs", [])
        if run.get("source_sha256") == source_hash and run.get("flags_sha256") == flags_hash
    ]
    for run in reversed(candidates):
        run_id = str(run.get("id", ""))
        diff_path = history_path.parent / "runs" / run_id / "artifacts" / "diff" / f"{slug}.json.gz"
        if not diff_path.is_file():
            continue
        try:
            with gzip.open(diff_path, "rt", encoding="utf-8") as handle:
                return json.load(handle), run_id
        except (OSError, json.JSONDecodeError):
            continue
    return None


def metric_row(
    commit: str,
    va: str,
    bucket: str,
    source_hash: str,
    flags_hash: str,
    metrics: dict[str, object],
    evidence_run: str,
) -> dict[str, object]:
    row: dict[str, object] = {
        "commit": commit,
        "va": va,
        "source_bucket": bucket,
        "source_sha256": source_hash,
        "flags_sha256": flags_hash,
        "evidence_run": evidence_run,
    }
    for field in METRIC_KEYS:
        key = field
        if field == "diff_result":
            key = "result"
        row[field] = metrics.get(key, "")
    shifted = metrics.get("likely_shifted_alignment", "")
    row["likely_shifted_alignment"] = "yes" if shifted is True else ("no" if shifted is False else shifted)
    return row


def exact_metrics(size: int) -> dict[str, object]:
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


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Recover commit-linked dashboard metrics from durable checker artifacts."
    )
    parser.add_argument("--start", default="eafbdf58", help="last commit with a complete metric snapshot")
    parser.add_argument("--ref", default="HEAD", help="last commit to inspect")
    parser.add_argument("--output", default=BACKFILL_METRICS_PATH, help="tracked history ledger path")
    parser.add_argument("--incremental", action="store_true", help="inspect only commits after the last automatic run")
    args = parser.parse_args()

    state_path = REPO_ROOT / "build" / "status" / "status_metrics_backfill_state.json"
    start = args.start
    if args.incremental and state_path.is_file():
        try:
            state = json.loads(state_path.read_text(encoding="utf-8"))
            candidate = str(state.get("processedCommit", ""))
            ancestry = subprocess.run(
                ["git", "merge-base", "--is-ancestor", candidate, args.ref],
                cwd=REPO_ROOT,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            ) if candidate else None
            if ancestry is not None and ancestry.returncode == 0:
                start = candidate
        except (OSError, json.JSONDecodeError):
            pass

    commits = subprocess.check_output(
        ["git", "rev-list", "--reverse", "--first-parent", f"{start}..{args.ref}"],
        cwd=REPO_ROOT,
        text=True,
    ).splitlines()
    inventory_text = git_bytes(args.ref, "inventory/all_functions.csv")
    if inventory_text is None:
        raise SystemExit("inventory/all_functions.csv is not available")
    inventory = {
        row["slug"]: int(row["size_bytes"])
        for row in csv.DictReader(inventory_text.decode("utf-8", errors="replace").splitlines())
    }

    output = REPO_ROOT / args.output
    existing: dict[tuple[str, str], dict[str, str]] = {}
    if output.is_file():
        with output.open("r", encoding="utf-8", newline="") as handle:
            existing = {
                (row.get("commit", ""), row.get("va", "")): row
                for row in csv.DictReader(handle)
            }

    recovered: list[dict[str, object]] = []
    missing: list[dict[str, str]] = []
    for commit in commits:
        for slug, source_path in changed_sources(commit):
            source = git_bytes(commit, source_path)
            if source is None:
                continue
            bucket = SOURCE_RE.match(source_path).group(1)  # type: ignore[union-attr]
            va = slug[:8].upper()
            source_hash = sha256(source)
            custom_flags = git_bytes(commit, f"config/flags/{slug}.rsp")
            flags = custom_flags or git_bytes(commit, "config/flags/default.rsp") or b""
            flags_hash = sha256(flags)
            if bucket == "matching":
                recovered.append(metric_row(
                    commit, va, bucket, source_hash, flags_hash,
                    exact_metrics(inventory.get(slug, 0)), "exact source promotion",
                ))
                continue
            checkpoint = checkpoint_metrics(slug, source_hash, flags_hash)
            if checkpoint is None:
                prior = existing.get((commit, va))
                if prior and prior.get("source_sha256") == source_hash and prior.get("flags_sha256") == flags_hash:
                    recovered.append(prior)
                    continue
                missing.append({
                    "commit": commit,
                    "va": va,
                    "source_bucket": bucket,
                    "source_path": source_path,
                    "source_sha256": source_hash,
                    "flags_sha256": flags_hash,
                })
                continue
            metrics, run_id = checkpoint
            recovered.append(metric_row(commit, va, bucket, source_hash, flags_hash, metrics, run_id))

    recovered_keys = {(str(row["commit"]), str(row["va"])) for row in recovered}
    recovered.extend(row for key, row in existing.items() if key not in recovered_keys)
    recovered.sort(key=lambda row: (str(row["commit"]), str(row["va"])))
    temporary = output.with_suffix(output.suffix + ".tmp")
    with temporary.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=FIELDS, lineterminator="\n")
        writer.writeheader()
        writer.writerows(recovered)
    temporary.replace(output)

    missing_path = REPO_ROOT / "build" / "status" / "missing_historical_metrics.csv"
    missing_path.parent.mkdir(parents=True, exist_ok=True)
    with missing_path.open("w", encoding="utf-8", newline="") as handle:
        fieldnames = tuple(missing[0]) if missing else (
            "commit", "va", "source_bucket", "source_path", "source_sha256", "flags_sha256"
        )
        writer = csv.DictWriter(handle, fieldnames=fieldnames, lineterminator="\n")
        writer.writeheader()
        writer.writerows(missing)

    processed_commit = subprocess.check_output(
        ["git", "rev-parse", args.ref], cwd=REPO_ROOT, text=True
    ).strip()
    state_path.parent.mkdir(parents=True, exist_ok=True)
    state_tmp = state_path.with_suffix(".json.tmp")
    state_tmp.write_text(
        json.dumps({"processedCommit": processed_commit}, separators=(",", ":")) + "\n",
        encoding="utf-8",
    )
    state_tmp.replace(state_path)

    print(f"Wrote {output} with {len(recovered)} recovered measurements")
    print(f"Wrote {missing_path} with {len(missing)} missing measurements")


if __name__ == "__main__":
    main()
