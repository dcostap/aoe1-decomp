"""Prepare isolated behavior workspaces and preserve their complete results."""
from __future__ import annotations

import argparse
import hashlib
import io
import json
import os
from pathlib import Path, PurePosixPath
import re
import subprocess
import sys
import uuid
import zipfile
from datetime import datetime, timezone


ROOT = Path(__file__).resolve().parents[1]
WORKER_ROLE = "agent_roles/behavior_recovery_worker.md"
TOOLS = (
    "build_function.py", "build_cache.py", "common.py", "source_listing.py",
    "extract_original_function.py", "extract_obj_function.py", "coff.py",
    "original_fpo.py", "query_abi.py", "shared_abi_evidence.py", "pdb_scoped_symbols.py",
    "requirements.txt",
)
CONFIG_FILES = {
    "binaries.json", "toolchain.json", "parent_owned_fragments.txt",
    "padding_only_functions.txt", "compiler_generated_functions.txt",
    "asm_special_functions.txt", "asm_special_regions.txt",
    "toolchain_supplied_functions.txt", "toolchain_supplied_regions.txt",
    "original_owner_symbol_overrides.txt", "original_symbol_overrides.txt",
}
CONTEXT_FILES = {"agents.md", "agents.override.md", "claude.md"}
SOURCE_SUFFIXES = {".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp", ".hxx", ".inl", ".inc"}
ORIGINAL_ROOT = "orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/"
THINKING = ("off", "minimal", "low", "medium", "high", "xhigh", "max")
TOKEN = re.compile(rb'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\r\n]*|/\*.*?\*/', re.S)


def run(command, *, cwd, data=None, env=None, check=True):
    result = subprocess.run(command, cwd=cwd, input=data, capture_output=True, env=env)
    if check and result.returncode:
        raise ValueError(f"Command failed ({result.returncode}): {command}\n"
                         + result.stdout.decode("utf-8", "replace")
                         + result.stderr.decode("utf-8", "replace"))
    return result


def git(root, *args, data=None, env=None):
    return run(["git", "-c", "core.autocrlf=false", "-c", "core.hooksPath=", "-C", str(root), *args],
               cwd=root, data=data, env=env if env is not None else git_env()).stdout


def sha(data):
    return hashlib.sha256(data).hexdigest()


def json_bytes(value):
    return (json.dumps(value, indent=2, sort_keys=True) + "\n").encode()


def load_json(path):
    return json.loads(path.read_bytes())


def reference(root, path):
    path = path.resolve()
    return path.relative_to(root.resolve()).as_posix() if path.is_relative_to(root.resolve()) else str(path)


def safe_name(value):
    if not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_.-]*", value):
        raise ValueError(f"Invalid directory name: {value!r}")
    return value


def relative(value):
    value = str(value).replace("\\", "/")
    path = PurePosixPath(value)
    if not value or path.is_absolute() or ":" in value or any(p.casefold() in {"..", ".git"} for p in path.parts):
        raise ValueError(f"Unsafe relative path: {value!r}")
    if str(path) != value or value == ".":
        raise ValueError(f"Noncanonical relative path: {value!r}")
    return value


def inside(root, name):
    path = root / relative(name)
    if not path.resolve().is_relative_to(root.resolve()):
        raise ValueError(f"Path escapes its root: {name}")
    return path


def scratch(root):
    path = root / "build" / "behavior_recovery" / uuid.uuid4().hex
    path.mkdir(parents=True)
    return path


def git_env(index=None):
    env = os.environ.copy()
    for key in list(env):
        if key.startswith("GIT_"):
            del env[key]
    env.update(GIT_TERMINAL_PROMPT="0", GIT_CONFIG_NOSYSTEM="1")
    if index is not None:
        env["GIT_INDEX_FILE"] = str(index.resolve())
    return env


def read_tree(root, revision):
    rows = git(root, "ls-tree", "-rz", revision).split(b"\0")
    result = {}
    for row in rows:
        if row:
            meta, name = row.split(b"\t", 1)
            mode, kind, oid = meta.decode().split()
            result[relative(name.decode("utf-8"))] = (mode, kind, oid)
    return result


def archive_files(root, revision, paths):
    payload = git(root, "archive", "--format=zip", revision, "--", *paths)
    with zipfile.ZipFile(io.BytesIO(payload)) as archive:
        return {relative(item.filename): archive.read(item) for item in archive.infolist() if not item.is_dir()}


def write_files(root, files):
    for name, data in files.items():
        path = inside(root, name)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)


def input_zip(files):
    output = io.BytesIO()
    with zipfile.ZipFile(output, "w", compression=zipfile.ZIP_DEFLATED) as archive:
        for name, data in sorted(files.items()):
            info = zipfile.ZipInfo(relative(name))
            info.compress_type = zipfile.ZIP_DEFLATED
            info.external_attr = 0o100644 << 16
            archive.writestr(info, data)
    return output.getvalue()


def load_input(wave):
    meta = load_json(wave / "wave.json")
    payload = (wave / "input.zip").read_bytes()
    if sha(payload) != meta["input_sha256"]:
        raise ValueError("Prepared input archive hash does not match")
    with zipfile.ZipFile(io.BytesIO(payload)) as archive:
        files = {}
        seen = set()
        for item in archive.infolist():
            name = relative(item.filename)
            if name.casefold() in seen or ((item.external_attr >> 16) & 0o170000) == 0o120000:
                raise ValueError(f"Duplicate or symbolic-link archive entry: {name}")
            seen.add(name.casefold())
            files[name] = archive.read(item)
    if {name: sha(data) for name, data in files.items()} != meta["files"]:
        raise ValueError("Prepared input file hashes do not match")
    return meta, files


def check_destination(root, destination):
    destination = destination.resolve()
    if destination.is_relative_to(root.resolve()) or root.resolve().is_relative_to(destination):
        raise ValueError("Worker workspace must be outside the main repository tree")
    if destination.exists():
        raise ValueError(f"Destination already exists: {destination}")
    for parent in destination.parents:
        for name in ("AGENTS.md", "AGENTS.override.md", "CLAUDE.md"):
            if (parent / name).is_file():
                raise ValueError(f"Ancestor context file would also load: {parent / name}")


def init_workspace(destination, files, date):
    destination.mkdir(parents=True, exist_ok=False)
    write_files(destination, files)
    git(destination, "init", "--template=", "--initial-branch=attempt", env=git_env())
    git(destination, "config", "core.autocrlf", "false")
    git(destination, "config", "core.filemode", "false")
    git(destination, "config", "commit.gpgsign", "false")
    git(destination, "config", "user.name", "Behavior Recovery")
    git(destination, "config", "user.email", "behavior-recovery@local")
    git(destination, "add", "--all", env=git_env())
    env = git_env()
    env.update(GIT_AUTHOR_DATE=date, GIT_COMMITTER_DATE=date,
               GIT_AUTHOR_NAME="Behavior Recovery", GIT_COMMITTER_NAME="Behavior Recovery",
               GIT_AUTHOR_EMAIL="behavior-recovery@local", GIT_COMMITTER_EMAIL="behavior-recovery@local")
    git(destination, "commit", "--no-gpg-sign", "-m", "Prepared behavior recovery input", env=env)
    return git(destination, "rev-parse", "HEAD").decode().strip()


def blank_function(data, start, end, va, name):
    lines = data.splitlines(keepends=True)
    if start < 1 or end < start or end > len(lines):
        raise ValueError("Function line range is outside the source file")
    selected = b"".join(lines[start - 1:end])
    code = TOKEN.sub(b"", selected).strip()
    # A narrow guard, not a C++ parser. The orchestrator must review the range.
    if not code.endswith(b"}") or b"(" not in code or b"{" not in code:
        raise ValueError("Select a complete function definition, including its closing brace")
    prefix = code.split(b"{", 1)[0]
    if not re.search(rb"(?<![\w])" + re.escape(name.encode()) + rb"\s*\(", prefix):
        raise ValueError("Selected definition does not contain the inventory function name")
    if b";" in prefix or re.search(rb"\b(if|for|while|switch|catch|else|return|do)\b", prefix):
        raise ValueError("Function range includes another declaration before the definition")
    depth = 0
    groups = 0
    for byte in code:
        if byte == ord("{"):
            if depth == 0:
                groups += 1
            depth += 1
        elif byte == ord("}"):
            depth -= 1
            if depth < 0:
                raise ValueError("Function range has an unmatched closing brace")
    if depth or groups != 1:
        raise ValueError("Function range must contain exactly one complete outer brace group")
    newline = b"\r\n" if b"\r\n" in selected else b"\n"
    marker = b"#error BEHAVIOR_RECOVERY_UNIMPLEMENTED_" + va.encode() + newline
    return b"".join(lines[:start - 1]) + marker + b"".join(lines[end:]), sha(selected)


def export_input(root, base, va):
    tree = read_tree(root, base)
    binaries = json.loads(git(root, "show", f"{base}:config/binaries.json"))
    original_paths = {relative(binaries[key]) for key in (
        "original_exe", "original_pdb", "ghidra_layout", "ghidra_listing", "type_dump")}
    original_paths.update({ORIGINAL_ROOT + "empiresx.exe", ORIGINAL_ROOT + "age1_x1.pdb"})
    decomp = relative(binaries["ghidra_decomp_root"]) + "/"

    def allowed(name):
        p = PurePosixPath(name)
        if p.name.casefold() in CONTEXT_FILES or ".pi" in p.parts:
            return False
        if p.parts[0] in {"src", "include", "third_party"}:
            return p.suffix.lower() in SOURCE_SUFFIXES
        if name.startswith("inventory/"):
            return p.suffix.lower() in {".txt", ".json", ".csv", ".h"}
        if name.startswith(("config/functions/", "config/flags/")):
            return p.suffix.lower() in {".json", ".rsp"}
        if p.parent == PurePosixPath("config"):
            return p.name in CONFIG_FILES
        return name in original_paths or name.startswith(decomp)

    selected = {name for name in tree if allowed(name)}
    for name in selected:
        if tree[name][0] not in {"100644", "100755"}:
            raise ValueError(f"Cannot export non-regular input: {name}")
    # Archive only the selected original paths; never copy full game assets.
    paths = ["src", "include", "third_party", "inventory", "config", *sorted(original_paths), decomp.rstrip("/")]
    available = set(tree)
    paths = [p for p in paths if p in available or any(n.startswith(p + "/") for n in available)]
    files = {name: data for name, data in archive_files(root, base, paths).items() if name in selected}
    for name in original_paths:
        if name not in files:
            raise ValueError(f"Missing pinned original input: {name}")
    for alias, original in (("original_exe", "empiresx.exe"), ("original_pdb", "age1_x1.pdb")):
        if sha(files[relative(binaries[alias])]) != sha(files[ORIGINAL_ROOT + original]):
            raise ValueError(f"Original {alias} alias differs from the full-game evidence")
        binaries[alias] = ORIGINAL_ROOT + original
    files["config/binaries.json"] = json_bytes(binaries)
    target = target_from_files(files, va)
    for name in TOOLS:
        files[f"tools/{name}"] = (ROOT / "tools" / name).read_bytes()
    files["AGENTS.md"] = (ROOT / WORKER_ROLE).read_bytes()
    files[".gitignore"] = b"/build/\n__pycache__/\n*.pyc\n"
    files[".gitattributes"] = b"* -text\n"
    return files, target


def target_from_files(files, va):
    found = []
    for name, data in files.items():
        if name.startswith("config/functions/"):
            module = json.loads(data)
            if va in module.get("functions", {}):
                found.append((name, module))
    if len(found) != 1:
        raise ValueError(f"Target {va} must have exactly one registry owner")
    registry, module = found[0]
    entry = module["functions"][va]
    source = registry[len("config/functions/"):-len(".json")]
    emitter = entry.get("emission_source", source)
    build = json.loads(files[f"config/functions/{emitter}.json"]).get("build")
    if not entry.get("symbol") or not build:
        raise ValueError("Target has no configured compiler recipe")
    packet_names = [n for n in files if n.startswith(f"inventory/functions/{va[:4]}/{va}_")]
    if len(packet_names) != 1:
        raise ValueError("Target must have exactly one inventory packet")
    packet = files[packet_names[0]].decode("utf-8")
    name_match = re.search(r"^Name: (.+)$", packet, re.M)
    if not name_match:
        raise ValueError("Inventory packet has no function name")
    return dict(va=va, name=name_match[1].strip(), source=source, symbol=entry["symbol"],
                emission_source=emitter, packet=packet_names[0], flags=f"config/flags/{build['flags']}.rsp")


def preflight(workspace, target):
    for tool in ("build_function.py", "extract_original_function.py", "extract_obj_function.py", "query_abi.py"):
        run([sys.executable, f"tools/{tool}", "--help"], cwd=workspace)
    result = run([sys.executable, "tools/build_function.py", "--va", target["va"], "--force"],
                 cwd=workspace, check=False)
    marker = f"BEHAVIOR_RECOVERY_UNIMPLEMENTED_{target['va']}"
    source = (workspace / target["source"]).read_bytes()
    output = (result.stdout + result.stderr).decode("utf-8", "replace")
    if load_json(workspace / "assignment.json")["mode"] == "reconstruct":
        if marker.encode() not in source or not result.returncode or marker not in output:
            raise ValueError(f"Blank-target compile must stop at its explicit marker:\n{output}")
    elif result.returncode:
        raise ValueError(f"Review input does not compile:\n{output}")
    logs = list((workspace / "build/manifests").glob("build_*.json"))
    if len(logs) != 1:
        raise ValueError("Expected one fresh compiler-input manifest")
    build = load_json(logs[0])
    manifest = build["build_inputs"]
    manifest["preflight"] = {key: build[key] for key in ("command", "returncode", "stdout", "stderr")}
    compiler = Path(manifest["compiler"]["path"])
    pinned = {str(compiler): sha(compiler.read_bytes())}
    for name in ("C1.DLL", "C1XX.DLL", "C2.DLL", "MSPDB50.DLL"):
        path = compiler.parent / name
        if path.is_file():
            pinned[str(path)] = sha(path.read_bytes())
    manifest["compiler_files"] = pinned
    return manifest


def prepare(args):
    root, destination = args.repo.resolve(), args.destination.resolve()
    check_destination(root, destination)
    base = git(root, "rev-parse", f"{args.base}^{{commit}}").decode().strip()
    va = f"{int(args.va, 16):08X}"
    date = datetime.now(timezone.utc).replace(microsecond=0)
    wave_name = safe_name(args.wave_name or date.strftime("wave-%Y%m%d-%H%M%SZ"))
    wave = (args.store or root / "logic_matching") / va / wave_name
    if wave.exists():
        raise ValueError(f"Wave already exists: {wave}")
    files, target = export_input(root, base, va)
    parent = None
    if args.mode == "reconstruct":
        if args.start_line is None or args.end_line is None or args.candidate:
            raise ValueError("Reconstruction needs --start-line and --end-line, without --candidate")
        files[target["source"]], removed_hash = blank_function(
            files[target["source"]], args.start_line, args.end_line, va, target["name"])
        removal = dict(start_line=args.start_line, end_line=args.end_line, sha256=removed_hash)
    else:
        if not args.candidate or args.start_line is not None or args.end_line is not None:
            raise ValueError("Review needs --candidate, without a removal range")
        candidate = load_json(args.candidate / "candidate.json")
        patch = (args.candidate / "changes.patch").read_bytes()
        if candidate["main_base"] != base or candidate["va"] != va or sha(patch) != candidate["patch_sha256"]:
            raise ValueError("Candidate target, base, or patch hash does not match")
        stage = scratch(root)
        index = stage / "index"
        env = git_env(index)
        git(root, "read-tree", base, env=env)
        if patch:
            git(root, "apply", "--cached", "--whitespace=nowarn", "-", data=patch, env=env)
        changed = git(root, "diff", "--cached", "--no-renames", "--name-only", "-z", base, env=env).split(b"\0")
        candidate_tree = read_tree(root, git(root, "write-tree", env=env).decode().strip())
        for raw in filter(None, changed):
            name = relative(raw.decode())
            if name not in files and not name.startswith(("src/", "include/", "third_party/")):
                raise ValueError(f"Candidate changes a file outside the worker input: {name}")
            if name in candidate_tree and candidate_tree[name][0] not in {"100644", "100755"}:
                raise ValueError(f"Candidate contains a non-regular input: {name}")
            result = run(["git", "show", f":{name}"], cwd=root, env=env, check=False)
            if result.returncode:
                files.pop(name, None)
            else:
                files[name] = result.stdout
        target = target_from_files(files, va)
        parent = reference(root, args.candidate)
        removal = None
    assignment = dict(mode=args.mode, target=target,
                      compile_command=["python", "tools/build_function.py", "--va", va, "--force"],
                      report="report.md")
    files["assignment.json"] = json_bytes(assignment)
    commit = init_workspace(destination, files, date.isoformat())
    prerequisites = preflight(destination, target)
    payload = input_zip(files)
    meta = dict(schema=1, va=va, main_base=base, mode=args.mode, target=target,
                created=date.isoformat(), prepared_commit=commit,
                prepared_tree=git(destination, "rev-parse", "HEAD^{tree}").decode().strip(),
                parent_candidate=parent, removal=removal, input_sha256=sha(payload),
                files={n: sha(d) for n, d in files.items()}, prerequisites=prerequisites)
    wave.mkdir(parents=True, exist_ok=False)
    (wave / "input.zip").write_bytes(payload)
    (wave / "wave.json").write_bytes(json_bytes(meta))
    print(f"Wave: {wave}\nWorkspace: {destination}\nBaseline: {commit}")
    return wave


def workspace(args):
    check_destination(args.repo.resolve(), args.destination.resolve())
    meta, files = load_input(args.wave)
    commit = init_workspace(args.destination.resolve(), files, meta["created"])
    if commit != meta["prepared_commit"]:
        raise ValueError("Recreated baseline commit does not match")
    for name, expected in meta["prerequisites"].get("compiler_files", {}).items():
        if sha(Path(name).read_bytes()) != expected:
            raise ValueError(f"Pinned compiler file changed: {name}")
    print(f"Workspace: {args.destination}\nBaseline: {commit}")


def index_diff(root, base, replacements, modes=None):
    env = git_env(scratch(root) / "index")
    git(root, "read-tree", base, env=env)
    original_modes = {name: row[0] for name, row in read_tree(root, base).items()}
    for name, data in replacements.items():
        relative(name)
        if data is None:
            git(root, "update-index", "--force-remove", "--", name, env=env)
        else:
            oid = git(root, "hash-object", "-w", "--stdin", data=data, env=env).decode().strip()
            mode = (modes or {}).get(name, original_modes.get(name, "100644"))
            if mode not in {"100644", "100755"}:
                raise ValueError(f"Candidate contains a non-regular file: {name}")
            git(root, "update-index", "--add", "--cacheinfo", f"{mode},{oid},{name}", env=env)
    patch = git(root, "diff", "--cached", "--binary", "--full-index", "--no-ext-diff", "--no-renames", base, env=env)
    return patch, git(root, "write-tree", env=env).decode().strip()


def dirty_snapshot(root, head):
    patch = git(root, "diff", "--binary", "--full-index", "--no-ext-diff", "--no-renames", head)
    untracked = git(root, "ls-files", "--others", "--exclude-standard", "-z").split(b"\0")
    extra = {}
    for raw in filter(None, untracked):
        name = relative(raw.decode())
        path = inside(root, name)
        if path.is_symlink():
            raise ValueError(f"Cannot collect an untracked symbolic link: {name}")
        extra[name] = path.read_bytes()
    return patch, input_zip(extra)


def collect(args):
    meta, files = load_input(args.wave)
    root = args.workspace.resolve()
    if not (root / ".git").is_dir() or git(root, "rev-parse", "--show-toplevel").decode().strip().replace("\\", "/").casefold() != root.as_posix().casefold():
        raise ValueError("Expected the root of a fresh worker repository")
    base = meta["prepared_commit"]
    if git(root, "rev-parse", f"{base}^{{tree}}").decode().strip() != meta["prepared_tree"]:
        raise ValueError("Worker baseline does not match the wave")
    git(root, "merge-base", "--is-ancestor", base, "HEAD")
    if git(root, "rev-list", "--merges", f"{base}..HEAD").strip():
        raise ValueError("Worker history has merges; preserve it before manual collection")
    head = git(root, "rev-parse", "HEAD").decode().strip()
    dirty = git(root, "status", "--porcelain=v1", "--untracked-files=all").strip()
    if dirty and not args.incomplete:
        raise ValueError("Worker repository is dirty; commit delivery or use --incomplete")
    committed = git(root, "diff", "--binary", "--full-index", "--no-ext-diff", "--no-renames", base, head)
    stage = scratch(args.repo.resolve())
    env = git_env(stage / "index")
    git(root, "read-tree", base, env=env)
    if committed:
        git(root, "apply", "--cached", "--whitespace=nowarn", "-", data=committed, env=env)
    if git(root, "write-tree", env=env) != git(root, "rev-parse", f"{head}^{{tree}}"):
        raise ValueError("Saved patch does not reconstruct the delivered tree")
    tree = read_tree(root, head)
    for name, (mode, kind, oid) in tree.items():
        if mode not in {"100644", "100755"}:
            raise ValueError(f"Delivery contains a non-regular file: {name}")
    report = git(root, "show", f"{head}:report.md") if "report.md" in tree else b""
    if not report.strip() and not args.incomplete:
        raise ValueError("Completed delivery needs a committed report.md")
    series = git(root, "format-patch", "--stdout", "--binary", "--full-index", "--no-signature", f"{base}..{head}")
    output = args.wave / safe_name(args.attempt)
    if output.exists():
        raise ValueError(f"Attempt already exists: {output}")
    collected = {"changes.patch": committed, "commits.patch": series, "report.md": report}
    if args.incomplete and dirty:
        collected["dirty.patch"], collected["untracked.zip"] = dirty_snapshot(root, head)
    for name in args.evidence:
        path = inside(root, name)
        if not path.is_file():
            raise ValueError(f"Evidence file is missing: {path}")
        collected[f"evidence/{relative(name)}"] = path.read_bytes()
    if head != git(root, "rev-parse", "HEAD").decode().strip() or dirty != git(root, "status", "--porcelain=v1", "--untracked-files=all").strip():
        raise ValueError("Worker inputs changed during collection")
    if args.incomplete and dirty and dirty_snapshot(root, head) != (collected["dirty.patch"], collected["untracked.zip"]):
        raise ValueError("Uncommitted content changed during collection")
    for name in args.evidence:
        if inside(root, name).read_bytes() != collected[f"evidence/{relative(name)}"]:
            raise ValueError(f"Evidence changed during collection: {name}")
    attempt = dict(schema=1, agent_id=args.agent_id, model=args.model, thinking=args.thinking,
                   final_commit=head, final_tree=git(root, "rev-parse", f"{head}^{{tree}}").decode().strip(),
                   state="incomplete" if args.incomplete else "complete", dirty=bool(dirty),
                   files={name: sha(data) for name, data in collected.items()})
    collected["attempt.json"] = json_bytes(attempt)
    output.mkdir(parents=True, exist_ok=False)
    write_files(output, collected)
    print(f"Collected: {output}")
    return output


def candidate(args):
    wave = args.attempt.parent
    meta, files = load_input(wave)
    attempt = load_json(args.attempt / "attempt.json")
    if attempt["state"] != "complete":
        raise ValueError("An incomplete attempt cannot become an integration candidate")
    patch = (args.attempt / "changes.patch").read_bytes()
    if sha(patch) != attempt["files"]["changes.patch"]:
        raise ValueError("Attempt patch hash does not match")
    root = args.repo.resolve()
    stage = scratch(root) / "restore"
    init_workspace(stage, files, meta["created"])
    if patch:
        git(stage, "apply", "--index", "--whitespace=nowarn", "-", data=patch)
    stage_tree = git(stage, "write-tree").decode().strip()
    if stage_tree != attempt["final_tree"]:
        raise ValueError("Attempt does not reconstruct its recorded tree")
    paths = [relative(p) for p in args.path]
    for name in paths:
        if not name.startswith(("src/", "include/", "third_party/", "config/", "tools/")):
            raise ValueError(f"Select only reviewed compiler source or supporting inputs: {name}")
    replacements = {name: inside(stage, name).read_bytes() if inside(stage, name).is_file() else None for name in paths}
    result, tree = index_diff(root, meta["main_base"], replacements,
                             {name: row[0] for name, row in read_tree(stage, stage_tree).items()})
    destination = wave.parent / safe_name(args.name)
    if destination.exists():
        raise ValueError(f"Candidate already exists: {destination}")
    omitted = [name.decode() for name in filter(None, git(stage, "diff", "--cached", "--name-only", "-z", "HEAD").split(b"\0"))
               if name.decode().startswith(("src/", "include/", "third_party/", "config/", "tools/")) and name.decode() not in paths]
    parents = [args.attempt, *getattr(args, "parent", [])]
    selected = dict(schema=1, va=meta["va"], main_base=meta["main_base"],
                    parents=[reference(root, p) for p in parents], paths=paths, omitted_supporting_paths=omitted,
                    tree=tree, patch_sha256=sha(result))
    report = args.report.read_bytes()
    if not report.strip():
        raise ValueError("Candidate selection needs a report")
    destination.mkdir(parents=True, exist_ok=False)
    write_files(destination, {"candidate.json": json_bytes(selected), "changes.patch": result, "report.md": report})
    print(f"Candidate: {destination}")
    if omitted:
        print("Not selected; review dependencies: " + ", ".join(omitted))


def parser():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--repo", type=Path, default=ROOT, help="Main repository; source always comes from a committed base")
    sub = p.add_subparsers(dest="command", required=True)
    prep = sub.add_parser("prepare", help="Export one wave and its first fresh workspace")
    prep.add_argument("--va", required=True)
    prep.add_argument("--mode", choices=("reconstruct", "review"), required=True)
    prep.add_argument("--base", default="HEAD")
    prep.add_argument("--start-line", type=int, help="First line of the reviewed complete definition, including its comments")
    prep.add_argument("--end-line", type=int, help="Last line of the complete definition")
    prep.add_argument("--candidate", type=Path, help="Archived candidate directory for review")
    prep.add_argument("--destination", type=Path, required=True)
    prep.add_argument("--store", type=Path, help="Archive root; default: main/logic_matching (use build/ for tests)")
    prep.add_argument("--wave-name", help="Unique wave name; default: UTC date and time")
    prep.set_defaults(func=prepare)
    ws = sub.add_parser("workspace", help="Create another independent workspace from a saved wave")
    ws.add_argument("--wave", type=Path, required=True)
    ws.add_argument("--destination", type=Path, required=True)
    ws.set_defaults(func=workspace)
    col = sub.add_parser("collect", help="Preserve and verify a complete or interrupted worker result")
    col.add_argument("--wave", type=Path, required=True)
    col.add_argument("--workspace", type=Path, required=True)
    col.add_argument("--attempt", required=True, help="Unique directory name, for example attempt-01")
    col.add_argument("--agent-id", required=True)
    col.add_argument("--model", required=True, help="Exact provider/model ID used for this attempt")
    col.add_argument("--thinking", choices=THINKING, required=True)
    col.add_argument("--incomplete", action="store_true", help="Preserve interrupted work without claiming clean delivery")
    col.add_argument("--evidence", action="append", default=[], help="Workspace-relative validation file to preserve; repeat as needed")
    col.set_defaults(func=collect)
    cand = sub.add_parser("candidate", help="Export selected attempt files as a patch against the recorded main base")
    cand.add_argument("--attempt", type=Path, required=True)
    cand.add_argument("--name", required=True, help="Unique candidate directory name")
    cand.add_argument("--path", action="append", required=True, help="Reviewed supporting or target file; repeat for every required file")
    cand.add_argument("--report", type=Path, required=True, help="Selection report, including unresolved questions")
    cand.add_argument("--parent", type=Path, action="append", default=[], help="Additional contributing attempt or candidate; repeat as needed")
    cand.set_defaults(func=candidate)
    return p


def main():
    args = parser().parse_args()
    try:
        if args.command == "collect" and ("/" not in args.model or args.model.startswith("/") or args.model.endswith("/")):
            raise ValueError("Use the exact provider/model ID for the delivered attempt")
        args.func(args)
    except (ValueError, OSError, KeyError, zipfile.BadZipFile) as error:
        raise SystemExit(str(error)) from error


if __name__ == "__main__":
    main()
