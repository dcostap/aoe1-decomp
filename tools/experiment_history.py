"""Durable experiment branches over the existing compiler-input manifest.

States are immutable. Results and findings are separate immutable records.
Scores never remove states. Reproduction only creates a new Git worktree.
"""
from __future__ import annotations

import argparse
import difflib
import hashlib
import json
import os
import re
import subprocess
import sys
import uuid
from datetime import datetime, timezone
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_STORE = ROOT / "workflow" / "decomp_notes" / "experiments"


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def encode(value: dict) -> bytes:
    return (json.dumps(value, sort_keys=True, indent=2) + "\n").encode()


def save_immutable(path: Path, data: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        if path.read_bytes() != data:
            raise ValueError(f"Corrupt immutable file: {path}")
        return
    pending = path.with_name(path.name + "." + uuid.uuid4().hex + ".pending")
    with pending.open("xb") as file:
        file.write(data)
        file.flush()
        os.fsync(file.fileno())
    os.replace(pending, path)


def git(workspace: Path, *args: str) -> str:
    return subprocess.check_output(["git", "-C", str(workspace), *args], text=True).strip()


def relative_path(value: str) -> str:
    path = PurePosixPath(value.replace("\\", "/"))
    if path.is_absolute() or not path.parts or any(
        p.casefold() in ("..", ".git") or ":" in p or p.endswith((".", " ")) for p in path.parts
    ):
        raise ValueError(f"Unsafe repository path: {value}")
    return str(path)


def workspace_context(workspace: Path, va: str) -> dict:
    script = (
        "import sys,json; sys.path.insert(0,'tools'); "
        "from common import function_record_by_va; "
        "from function_history import current_build_context; "
        "print(json.dumps(current_build_context(function_record_by_va(int(sys.argv[1],16)))))"
    )
    return json.loads(subprocess.check_output([sys.executable, "-c", script, va], cwd=workspace, text=True))


def is_primary_workspace(workspace: Path) -> bool:
    """Identify the primary checkout, not the checkout containing this script."""
    git_dir = Path(git(workspace, "rev-parse", "--absolute-git-dir")).resolve()
    common_dir = (workspace / git(workspace, "rev-parse", "--git-common-dir")).resolve()
    return git_dir == common_dir


def owner_output_index(obj_path: Path, context: dict) -> dict:
    from coff import load_coff_object, function_symbol_section
    obj = load_coff_object(obj_path)
    owners = {}
    for va, name in context["translation_unit"]["functions"].items():
        symbols = [s for s in obj.symbols if s.name == name and s.section_number > 0]
        if len(symbols) != 1:
            owners[va] = {"symbol": name, "error": "Owner is missing or ambiguous"}
            continue
        section = function_symbol_section(obj, symbols[0])
        relocations = [(r.offset, r.reloc_type, r.symbol_name) for r in section.relocations]
        owners[va] = {"symbol": name, "code_sha256": digest(section.data),
                      "relocations_sha256": digest(encode({"relocations": relocations}))}
    return {"object_sha256": digest(obj_path.read_bytes()), "owners": owners}


class Store:
    def __init__(self, root: Path):
        self.root = root.resolve()

    def blob(self, data: bytes) -> str:
        key = digest(data)
        path = self.root / "objects" / key[:2] / key
        save_immutable(path, data)
        return key

    def read_blob(self, key: str) -> bytes:
        if not re.fullmatch(r"[0-9a-f]{64}", key):
            raise ValueError("Invalid object ID")
        data = (self.root / "objects" / key[:2] / key).read_bytes()
        if digest(data) != key:
            raise ValueError(f"Corrupt object: {key}")
        return data

    def save(self, kind: str, record: dict) -> str:
        data = encode(record)
        key = digest(data)
        path = self.root / kind / f"{key}.json"
        save_immutable(path, data)
        return key

    def records(self, kind: str) -> list[tuple[str, dict]]:
        rows = []
        for path in sorted((self.root / kind).glob("*.json")):
            data = path.read_bytes()
            if digest(data) != path.stem:
                raise ValueError(f"Corrupt record: {path}")
            rows.append((path.stem, json.loads(data)))
        return rows

    def state(self, selector: str) -> tuple[str, dict]:
        rows = [(key, row) for key, row in self.records("states") if key.startswith(selector) or row["name"] == selector]
        if len(rows) != 1:
            raise ValueError(f"Expected one state for {selector!r}; found {len(rows)}")
        return rows[0]

    def capture(self, workspace: Path, va: str, name: str, hypothesis: str,
                parents: list[str], provenance: str) -> str:
        if not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_.-]*", name):
            raise ValueError("Use a simple alphanumeric state name")
        address = int(va, 16)
        if not 0 <= address <= 0xffffffff:
            raise ValueError("VA must fit in 32 bits")
        va = f"{address:08X}"
        if any(row["name"] == name for _, row in self.records("states")):
            raise ValueError("State name already exists")
        deleted = git(workspace, "diff", "HEAD", "--name-only", "--diff-filter=D", "--", "src", "include", "tools", "config")
        if deleted:
            raise ValueError("This pilot cannot freeze deleted build files: " + deleted)
        parent_ids = [self.state(p)[0] for p in parents]
        context = workspace_context(workspace, va)
        if not context:
            raise ValueError("Pilot requires a configured natural translation unit")
        local, external = {}, {}
        for entry in context["inputs"]:
            path = Path(entry["path"])
            if path.is_absolute():
                if digest(path.read_bytes()) != entry["sha256"]:
                    raise ValueError(f"Input changed during capture: {path}")
                external[str(path)] = entry["sha256"]
            else:
                rel = relative_path(entry["path"])
                data = (workspace / rel).read_bytes()
                if digest(data) != entry["sha256"]:
                    raise ValueError(f"Input changed during capture: {rel}")
                local[rel] = self.blob(data)
        # Registry is a compiler/extraction input, not only bookkeeping.
        registry = "config/functions/" + relative_path(context["source"]) + ".json"
        local[registry] = self.blob((workspace / registry).read_bytes())
        # The Git base pins checker code; include changed and new local tools/config.
        dirty = git(workspace, "diff", "HEAD", "--name-only", "--", "tools", "config")
        new = git(workspace, "ls-files", "--others", "--exclude-standard", "--", "tools", "config")
        for dirty_name in set(dirty.splitlines() + new.splitlines()):
            rel = relative_path(dirty_name)
            if not (workspace / rel).is_file():
                raise ValueError(f"Pilot cannot capture deleted tool/config input: {rel}")
            local[rel] = self.blob((workspace / rel).read_bytes())
        config = json.loads((workspace / "config/toolchain.json").read_text())
        for value in config["compiler"].values():
            path = Path(value)
            if path.is_absolute() and path.is_file():
                external[str(path)] = digest(path.read_bytes())
        compiler_dir = Path(config["compiler"]["cl"]).parent
        for filename in ("C1.DLL", "C1XX.DLL", "C2.DLL"):
            path = compiler_dir / filename
            if path.is_file():
                external[str(path)] = digest(path.read_bytes())
        state = {
            "schema": 1, "name": name, "va": va.upper(), "parents": parent_ids,
            "hypothesis": hypothesis, "provenance": provenance,
            "base_commit": git(workspace, "rev-parse", "HEAD"),
            "context": context, "files": local, "external": external,
        }
        self.verify(state, workspace)
        return self.save("states", state)

    def verify(self, state: dict, workspace: Path) -> None:
        if git(workspace, "rev-parse", "HEAD") != state["base_commit"]:
            raise ValueError("Workspace base differs from recorded base")
        for rel, key in state["files"].items():
            data = self.read_blob(key)
            if (workspace / relative_path(rel)).read_bytes() != data:
                raise ValueError(f"Workspace input differs: {rel}")
        for name, expected in state["external"].items():
            if digest(Path(name).read_bytes()) != expected:
                raise ValueError(f"External prerequisite differs: {name}")
        if "context" in state:
            actual = workspace_context(workspace, state["va"])
            if actual["fingerprint"] != state["context"]["fingerprint"]:
                raise ValueError("Compiler context differs from the frozen state")

    def reproduce(self, selector: str, destination: Path) -> Path:
        _, state = self.state(selector)
        destination = destination.resolve()
        if destination.exists():
            raise ValueError("Destination exists; reproduction never overwrites a workspace")
        # Validate every object and prerequisite before creating a worktree.
        for rel, key in state["files"].items():
            relative_path(rel)
            self.read_blob(key)
        for name, expected in state["external"].items():
            if digest(Path(name).read_bytes()) != expected:
                raise ValueError(f"External prerequisite differs: {name}")
        subprocess.run(["git", "-C", str(ROOT), "worktree", "add", "--detach", str(destination), state["base_commit"]], check=True)
        for rel, key in state["files"].items():
            path = destination / relative_path(rel)
            if not path.resolve().is_relative_to(destination) or path.is_symlink() or any(p.is_symlink() for p in path.parents):
                raise ValueError(f"Refusing symlink destination: {rel}")
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(self.read_blob(key))
        self.verify(state, destination)
        return destination

    def switch(self, expected: str, target: str, workspace: Path) -> None:
        _, before = self.state(expected)
        _, after = self.state(target)
        if is_primary_workspace(workspace):
            raise ValueError("Switch only operates in an isolated workspace")
        self.verify(before, workspace)
        if before["base_commit"] != after["base_commit"] or set(before["files"]) != set(after["files"]):
            raise ValueError("Different base or file set; use reproduce in a new workspace")
        if git(workspace, "diff", "--cached", "--name-only"):
            raise ValueError("Workspace has staged changes")
        changed = set(git(workspace, "diff", "HEAD", "--name-only").splitlines())
        untracked = set(git(workspace, "ls-files", "--others", "--exclude-standard").splitlines())
        if (changed | untracked) - set(before["files"]):
            raise ValueError("Workspace has unrelated changes")
        for name, expected_hash in after["external"].items():
            if digest(Path(name).read_bytes()) != expected_hash:
                raise ValueError(f"External prerequisite differs: {name}")
        replacements = [(workspace / relative_path(rel), self.read_blob(key))
                        for rel, key in after["files"].items() if key != before["files"][rel]]
        for path, _ in replacements:
            if not path.resolve().is_relative_to(workspace.resolve()) or path.is_symlink() or any(p.is_symlink() for p in path.parents):
                raise ValueError(f"Refusing symlink destination: {path}")
        for path, data in replacements:
            path.write_bytes(data)
        self.verify(after, workspace)

    def event(self, selector: str, kind: str, note: str, artifacts: list[Path], **extra) -> str:
        key, _ = self.state(selector)
        return self.save("events", {
            "schema": 1, "state": key, "kind": kind, "note": note,
            "at": datetime.now(timezone.utc).isoformat(), "id": uuid.uuid4().hex,
            "artifacts": {str(p): self.blob(p.read_bytes()) for p in artifacts}, **extra,
        })

    def inspect(self, selector: str) -> dict:
        key, state = self.state(selector)
        events = []
        for event_id, event in self.records("events"):
            if event["state"] == key:
                view = {name: value for name, value in event.items() if name != "id"}
                view.update(event_id=event_id, record_uuid=event.get("id"))
                events.append(view)
        return {"state_id": key, "state": state, "events": events}

    def event_summary(self, event: dict) -> dict:
        summary = dict(event.get("summary", {}))
        if event["kind"] == "run":
            for name, key in event["artifacts"].items():
                if name.endswith("closure/report.json") or name.endswith("closure\\report.json"):
                    report = json.loads(self.read_blob(key))
                    summary["exact_regressions"] = [
                        row["va"] for group in report["groups"] for row in group["rows"]
                        if row["source_bucket"] == "matching" and row["grouped_result"] != "MATCH"
                    ]
        return summary

    def run(self, selector: str, workspace: Path, closure: bool, jobs: int | None) -> str:
        state_id, state = self.state(selector)
        if closure and jobs is None:
            raise ValueError("Closure checks require --jobs")
        if jobs is not None and jobs < 1:
            raise ValueError("--jobs must be positive")
        # The base commit pins checker code. No check runs in the shared workspace.
        if is_primary_workspace(workspace):
            raise ValueError("Run experiments in an isolated workspace")
        self.verify(state, workspace)
        output = workspace / "build" / "experiment_runs" / uuid.uuid4().hex
        output.mkdir(parents=True)
        command = [sys.executable, "tools/check_function.py", "--va", state["va"], "--rebuild", "--detail", "concise"]
        run = subprocess.run(command, cwd=workspace, capture_output=True, text=True)
        log = output / "check.txt"
        log.write_text(run.stdout + run.stderr, encoding="utf-8")
        # Take metrics only from this run, not from an old cache after a build failure.
        artifacts = [log]
        summary = {"exit_code": run.returncode, "result": "BUILD_OR_CHECK_FAILED"}
        result_lines = re.findall(r"^Result: (MATCH|MISMATCH)\s*$", run.stdout, re.MULTILINE)
        if run.returncode in (0, 1) and result_lines:
            candidates = list((workspace / "build/diff").glob(state["va"] + "_*.json"))
            if len(candidates) != 1:
                raise ValueError("Expected one target metric file")
            metrics = json.loads(candidates[0].read_text())
            if metrics.get("build_input_fingerprint") != state["context"]["fingerprint"]:
                raise ValueError("Checker input fingerprint differs from the frozen state")
            if metrics["result"] != result_lines[-1] or (metrics["result"] == "MATCH") != (run.returncode == 0):
                raise ValueError("Checker exit code, output, and metrics disagree")
            artifacts.append(candidates[0])
            summary.update(result=metrics["result"], diff_bytes=metrics["diff_bytes"])
            binary = next((workspace / "build/asm").glob("rebuilt_" + state["va"] + "_*.bin"))
            # Exclude the optional full-section artifact from output identity.
            binary = binary.with_name(binary.name.replace(".full.bin", ".bin"))
            artifacts.append(binary)
            summary["output_sha256"] = digest(binary.read_bytes())
        if closure and summary["result"] != "BUILD_OR_CHECK_FAILED":
            group = state["context"]["translation_unit"]["name"]
            audit = subprocess.run([sys.executable, "tools/audit_translation_unit_functions.py", "--group", group,
                                    "--jobs", str(jobs), "--output-dir", str(output / "closure")],
                                   cwd=workspace, capture_output=True, text=True)
            audit_log = output / "closure.txt"
            audit_log.write_text(audit.stdout + audit.stderr, encoding="utf-8")
            artifacts.append(audit_log)
            summary["closure_exit_code"] = audit.returncode
            if (output / "closure/report.json").exists():
                artifacts.append(output / "closure/report.json")
            obj_path = output / "closure/objects" / (group + ".obj")
            if audit.returncode == 0 and obj_path.exists():
                owners = output / "owners.json"
                owners.write_bytes(encode(owner_output_index(obj_path, state["context"])))
                artifacts.extend([owners, obj_path])
        try:
            self.verify(state, workspace)
        except (ValueError, OSError) as error:
            summary["result"] = "INVALIDATED_INPUTS"
            summary["input_error"] = str(error)
            return self.event(selector, "run", "Inputs changed during the check; result is not authoritative", artifacts, summary=summary)
        if summary["result"] == "MATCH":
            candidate = ROOT / "workflow/decomp_notes/candidates" / state["va"][:4] / (
                state["va"] + "_experiment_" + state_id[:12] + "_exact_candidate.patch")
            if not candidate.exists():
                self.export_patch(selector, workspace, candidate)
            artifacts.append(candidate)
        return self.event(selector, "run", "Fresh check of recorded inputs", artifacts, summary=summary)

    def show(self, va: str | None) -> str:
        events = self.records("events")
        rows = {key: row for key, row in self.records("states")}
        ordered = []
        def visit(key):
            if key not in ordered:
                for parent in rows[key]["parents"]:
                    visit(parent)
                ordered.append(key)
        for key in sorted(rows, key=lambda k: rows[k]["name"]):
            visit(key)
        lines = []
        for key in ordered:
            row = rows[key]
            if va and row["va"] != va.upper():
                continue
            parent_names = [rows[p]["name"] for p in row["parents"]]
            lines.append(f"{row['name']} [{key[:12]}] <- {', '.join(parent_names) or '(root)'}")
            lines.append(f"  hypothesis: {row['hypothesis']}")
            for _, event in sorted(events, key=lambda item: item[1]["at"]):
                if event["state"] == key:
                    lines.append(f"  {event['kind']}: {event['note']} {json.dumps(self.event_summary(event))}")
        return "\n".join(lines)

    def compare(self, left: str, right: str) -> str:
        aid, a = self.state(left)
        bid, b = self.state(right)
        lines = [f"{a['name']} -> {b['name']}"]
        events = sorted(self.records("events"), key=lambda item: item[1]["at"])
        for key, state in ((aid, a), (bid, b)):
            runs = [e for _, e in events if e["state"] == key and e["kind"] == "run"]
            lines.append(f"{state['name']} result: {json.dumps(self.event_summary(runs[-1])) if runs else 'not tested'}")
        indexes = []
        for key in (aid, bid):
            matches = [blob for _, e in events if e["state"] == key
                       for name, blob in e["artifacts"].items() if name.endswith("owners.json")]
            indexes.append(json.loads(self.read_blob(matches[-1]))["owners"] if matches else None)
        if all(index is not None for index in indexes):
            changed = [va for va in sorted(set(indexes[0]) | set(indexes[1]))
                       if indexes[0].get(va) != indexes[1].get(va)]
            lines.append("Changed compiled owners (bytes or relocation names): " + (", ".join(changed) or "none"))
        else:
            lines.append("Complete compiled-owner comparison not recorded; equal scores do not prove equal output.")
        for path in sorted(set(a["files"]) | set(b["files"])):
            ka, kb = a["files"].get(path), b["files"].get(path)
            if ka == kb:
                continue
            old = self.read_blob(ka).decode("utf-8", errors="replace").splitlines(True) if ka else []
            new = self.read_blob(kb).decode("utf-8", errors="replace").splitlines(True) if kb else []
            lines.extend(line.rstrip("\n") for line in difflib.unified_diff(old, new, "old/" + path, "new/" + path))
        if a["external"] != b["external"]:
            lines.append("External prerequisites differ")
        if a["base_commit"] != b["base_commit"]:
            lines.append(f"Base commits differ: {a['base_commit']} -> {b['base_commit']}")
        return "\n".join(lines)

    def export_patch(self, selector: str, workspace: Path, output: Path) -> None:
        key, state = self.state(selector)
        self.verify(state, workspace)
        patch = subprocess.check_output(["git", "-C", str(workspace), "diff", "--binary",
                                         "--no-ext-diff", "HEAD", "--", *state["files"]])
        output.parent.mkdir(parents=True, exist_ok=True)
        with output.open("xb") as file:
            file.write(f"# Experiment {key}\n# Base {state['base_commit']}\n".encode() + patch)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--store", type=Path, default=DEFAULT_STORE)
    subs = parser.add_subparsers(dest="command", required=True)
    record = subs.add_parser("record", help="Freeze inputs before a check")
    record.add_argument("--workspace", type=Path, default=ROOT)
    record.add_argument("--va", required=True)
    record.add_argument("--name", required=True)
    record.add_argument("--hypothesis", required=True)
    record.add_argument("--parent", action="append", default=[])
    record.add_argument("--provenance", required=True)
    show = subs.add_parser("show", help="Show states, parents, findings, and results")
    show.add_argument("--va")
    inspect = subs.add_parser("inspect", help="Show complete metadata and artifact hashes")
    inspect.add_argument("state")
    export = subs.add_parser("export-patch", help="Export a verified state as a candidate patch")
    export.add_argument("state")
    export.add_argument("--workspace", type=Path, required=True)
    export.add_argument("--output", type=Path, required=True)
    compare = subs.add_parser("compare")
    compare.add_argument("left")
    compare.add_argument("right")
    reproduce = subs.add_parser("reproduce", help="Create a new isolated worktree")
    reproduce.add_argument("state")
    reproduce.add_argument("--destination", type=Path, required=True)
    switch = subs.add_parser("switch", help="Switch a verified isolated workspace between saved states")
    switch.add_argument("--from-state", required=True)
    switch.add_argument("--to-state", required=True)
    switch.add_argument("--workspace", type=Path, required=True)
    run = subs.add_parser("run", help="Check a recorded state without editing it")
    run.add_argument("state")
    run.add_argument("--workspace", type=Path, required=True)
    run.add_argument("--closure", action="store_true")
    run.add_argument("--jobs", type=int)
    note = subs.add_parser("note", help="Append a finding; never replace history")
    note.add_argument("state")
    note.add_argument("--kind", choices=["finding", "integration-objection", "open-question", "reported"], required=True)
    note.add_argument("--text", required=True)
    note.add_argument("--artifact", type=Path, action="append", default=[])
    args = parser.parse_args()
    store = Store(args.store)
    if args.command == "record":
        print(store.capture(args.workspace.resolve(), args.va, args.name, args.hypothesis, args.parent, args.provenance))
    elif args.command == "show":
        print(store.show(args.va))
    elif args.command == "inspect":
        print(json.dumps(store.inspect(args.state), indent=2))
    elif args.command == "compare":
        print(store.compare(args.left, args.right))
    elif args.command == "export-patch":
        store.export_patch(args.state, args.workspace.resolve(), args.output)
        print(args.output)
    elif args.command == "reproduce":
        print(store.reproduce(args.state, args.destination))
    elif args.command == "switch":
        store.switch(args.from_state, args.to_state, args.workspace.resolve())
        print(f"Switched to {args.to_state}; rerun validation before using old results")
    elif args.command == "run":
        event_id = store.run(args.state, args.workspace.resolve(), args.closure, args.jobs)
        event = next(e for key, e in store.records("events") if key == event_id)
        print(event_id)
        print(json.dumps(store.event_summary(event), sort_keys=True))
    elif args.command == "note":
        print(store.event(args.state, args.kind, args.text, args.artifact))


if __name__ == "__main__":
    try:
        main()
    except (ValueError, FileNotFoundError, subprocess.CalledProcessError) as error:
        raise SystemExit(f"Experiment refused: {error}") from error
