from __future__ import annotations

import argparse
import io
import json
from pathlib import Path
import sys
from types import SimpleNamespace
from unittest.mock import patch
import zipfile

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import behavior_recovery as br


SOURCE = b"int neighbour() { return 7; }\n// previous target note\nint sample(int x)\n{\n    return x + 1;\n}\n"
VA = "00400000"


@pytest.fixture
def repo(tmp_path):
    root = tmp_path / "main"
    root.mkdir()
    br.git(root, "init", "--template=", "--initial-branch=main")
    br.git(root, "config", "user.name", "Test")
    br.git(root, "config", "user.email", "test@local")
    br.git(root, "config", "commit.gpgsign", "false")
    binaries = dict(original_exe="orig/alias.exe", original_pdb="orig/alias.pdb",
                    ghidra_layout="orig/layout.json", ghidra_listing="orig/asm.txt",
                    type_dump="orig/types.h", ghidra_decomp_root="orig/decomp")
    module = dict(schema=1, pdb_source_path="sample.cpp", build={"flags": "default"},
                  functions={VA: {"status": "scratch", "symbol": "?sample@@YAHH@Z"}})
    files = {
        "src/sample.cpp": SOURCE,
        "include/sample.h": b"int sample(int);\n",
        "third_party/sdk/include/vendor.h": b"typedef int vendor_type;\n",
        "third_party/sdk/README.md": b"excluded vendor documentation\n",
        "config/functions/src/sample.cpp.json": br.json_bytes(module),
        "config/flags/default.rsp": b"/nologo /c /O2 /Oy\n",
        "config/toolchain.json": b"{}\n",
        "config/binaries.json": br.json_bytes(binaries),
        f"inventory/functions/0040/{VA}_sample.txt": b"Name: sample\nOriginalAsm: reference\n",
        "orig/alias.exe": b"original-executable",
        "orig/alias.pdb": b"original-pdb",
        br.ORIGINAL_ROOT + "empiresx.exe": b"original-executable",
        br.ORIGINAL_ROOT + "age1_x1.pdb": b"original-pdb",
        "orig/layout.json": b"{}\n",
        "orig/asm.txt": b"static instructions\n",
        "orig/types.h": b"struct Original {};\n",
        "orig/decomp/sample.c": b"original approximate C\n",
        "AGENTS.md": b"old workflow\n",
        "src/AGENTS.override.md": b"old nested workflow\n",
        ".pi/settings.json": b"{}\n",
        "decomp_notes/old.md": b"old evidence and target implementation\n",
        "logic_reviews/00400000.md": b"old review\n",
        "tools/variant_lab.py": b"old matching lab\n",
        "inventory/README.md": b"old instructions\n",
        ".gitignore": b"build/\n",
    }
    br.write_files(root, files)
    br.git(root, "add", "--all")
    br.git(root, "commit", "-m", "fixture")
    return root


def prepare(repo, tmp_path, **kwargs):
    values = dict(repo=repo, destination=tmp_path / "worker", base="HEAD", va=VA,
                  start_line=2, end_line=6, store=tmp_path / "store", wave_name="wave-test")
    values.update(kwargs)
    args = argparse.Namespace(**values)
    with patch.object(br, "preflight", return_value={"compiler_files": {}}):
        wave = br.prepare(args)
    return wave, args.destination


def deliver(workspace, source=SOURCE, **extra):
    br.write_files(workspace, {"src/sample.cpp": source, **extra})
    br.git(workspace, "add", "--all")
    br.git(workspace, "commit", "-m", "Deliver fixture", "-m", "Extended reasoning survives collection.\n\nCompile: passed.")
    br.write_files(workspace, {"build/manifests/build_sample.json": b'{"returncode": 0}\n'})


def collect(repo, wave, workspace, **kwargs):
    values = dict(repo=repo, wave=wave, workspace=workspace, attempt="attempt-01",
                  agent_id="test", model="test/fixture", thinking="off", incomplete=False)
    values.update(kwargs)
    return br.collect(argparse.Namespace(**values))


def test_prepare_blinds_before_git_and_preserves_other_source(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path)
    meta, files = br.load_input(wave)
    assert files["src/sample.cpp"] == b"int neighbour() { return 7; }\n#error BEHAVIOR_RECOVERY_UNIMPLEMENTED_00400000\n"
    assert files["include/sample.h"] == b"int sample(int);\n"
    assert files["third_party/sdk/include/vendor.h"] == b"typedef int vendor_type;\n"
    assert "third_party/sdk/README.md" not in files
    assert files["AGENTS.md"] == (br.ROOT / br.WORKER_ROLE).read_bytes()
    assert set(n.removeprefix("tools/") for n in files if n.startswith("tools/")) == set(br.TOOLS)
    for forbidden in ("decomp_notes/old.md", "logic_reviews/00400000.md", "tools/variant_lab.py",
                      "src/AGENTS.override.md", ".pi/settings.json", "inventory/README.md"):
        assert forbidden not in files
    assert b"previous target note" not in br.git(worker, "log", "--all", "-p", "--", "src/sample.cpp")
    assert br.git(worker, "rev-list", "--count", "HEAD").strip() == b"1"
    assert not br.git(worker, "remote").strip()
    assert not br.git(worker, "status", "--porcelain").strip()
    assert (repo / "src/sample.cpp").read_bytes() == SOURCE
    assert br.git(worker, "rev-parse", "HEAD").decode().strip() == meta["prepared_commit"]


def test_prepare_locates_unambiguous_definition_without_orchestrator_source_review(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path, start_line=None, end_line=None)
    assert b"BEHAVIOR_RECOVERY_UNIMPLEMENTED_00400000" in (worker / "src/sample.cpp").read_bytes()
    assert br.load_json(wave / "wave.json")["removal"]["start_line"] == 2


def test_source_comes_from_base_not_dirty_main(repo, tmp_path):
    (repo / "include/sample.h").write_bytes(b"uncommitted declaration\n")
    _, worker = prepare(repo, tmp_path)
    assert (worker / "include/sample.h").read_bytes() == b"int sample(int);\n"
    assert (repo / "include/sample.h").read_bytes() == b"uncommitted declaration\n"


def test_second_workspace_reproduces_baseline_without_history(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path)
    deliver(worker)
    destination = tmp_path / "second"
    br.workspace(argparse.Namespace(repo=repo, wave=wave, destination=destination))
    assert b"UNIMPLEMENTED" in (destination / "src/sample.cpp").read_bytes()
    assert not (destination / "report.md").exists()
    assert br.git(destination, "rev-list", "--count", "HEAD").strip() == b"1"


def test_collect_roundtrip_binary_deletion_message_and_history(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path)
    deliver(worker, SOURCE.replace(b"x + 1", b"x + 2"), **{"src/data.inc": b"\x00\xff\x01"})
    (worker / "include/sample.h").unlink()
    br.git(worker, "add", "--all")
    br.git(worker, "commit", "-m", "Remove fixture header")
    (worker / "build").mkdir(exist_ok=True)
    attempt = collect(repo, wave, worker)
    meta = br.load_json(attempt / "attempt.json")
    assert meta["state"] == "complete"
    assert b"Extended reasoning survives" in (attempt / "commits.patch").read_bytes()
    assert b"GIT binary patch" in (attempt / "changes.patch").read_bytes()
    assert (attempt / "evidence/build/manifests/build_sample.json").read_bytes() == b'{"returncode": 0}\n'
    restored = tmp_path / "restored"
    br.workspace(argparse.Namespace(repo=repo, wave=wave, destination=restored))
    br.git(restored, "apply", "--index", "--whitespace=nowarn", "-", data=(attempt / "changes.patch").read_bytes())
    assert br.git(restored, "write-tree").decode().strip() == meta["final_tree"]


def test_candidate_integration_patch_applies_to_main_base_without_source_swap(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path)
    deliver(worker, SOURCE.replace(b"x + 1", b"x + 2"))
    attempt = collect(repo, wave, worker)
    meta, _, patch = br.candidate_integration_patch(repo, attempt)
    assert meta["main_base"] == br.git(repo, "rev-parse", "HEAD").decode().strip()
    br.git(repo, "apply", "--check", "-", data=patch)
    br.git(repo, "apply", "-", data=patch)
    assert b"x + 2" in (repo / "src/sample.cpp").read_bytes()
    br.git(repo, "apply", "-R", "-", data=patch)


def test_collection_refuses_missing_delivery_dirty_and_overwrite(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path)
    with pytest.raises(ValueError, match="delivery commit"):
        collect(repo, wave, worker)
    (worker / "scratch.txt").write_bytes(b"not committed")
    with pytest.raises(ValueError, match="dirty"):
        collect(repo, wave, worker)
    deliver(worker)
    collect(repo, wave, worker)
    with pytest.raises(ValueError, match="already exists"):
        collect(repo, wave, worker)


def test_interrupted_collection_preserves_committed_dirty_and_untracked(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path)
    deliver(worker)
    (worker / "src/sample.cpp").write_bytes(SOURCE + b"// unfinished\n")
    (worker / "probe.txt").write_bytes(b"untracked input")
    attempt = collect(repo, wave, worker, incomplete=True)
    assert br.load_json(attempt / "attempt.json")["state"] == "incomplete"
    assert b"unfinished" in (attempt / "dirty.patch").read_bytes()
    with zipfile.ZipFile(attempt / "untracked.zip") as archive:
        assert archive.read("probe.txt") == b"untracked input"


def test_review_receives_all_payloads_and_perfect_result_builds_integration_patch(repo, tmp_path):
    wave, worker = prepare(repo, tmp_path)
    source = SOURCE.replace(b"x + 1", b"x + 2")
    registry = "config/functions/src/sample.cpp.json"
    module = br.load_json(worker / registry)
    module["functions"][VA]["symbol"] = "?sample@@YAHJ@Z"
    deliver(worker, source, **{"include/sample.h": b"int sample(int value);\n", registry: br.json_bytes(module)})
    attempt = collect(repo, wave, worker)
    before = br.git(repo, "status", "--porcelain")
    args = argparse.Namespace(repo=repo, attempt=[attempt], destination=tmp_path / "reviewer",
                              store=tmp_path / "store", wave_name="review-test")
    with patch.object(br, "preflight", return_value={"compiler_files": {}}):
        review_wave = br.review(args)
    reviewer = args.destination
    assert b"UNIMPLEMENTED" in (reviewer / "src/sample.cpp").read_bytes()
    assert (reviewer / "deliverables/delivery-01/source.patch").is_file()
    br.git(reviewer, "apply", "--index", "--whitespace=nowarn", "deliverables/delivery-01/source.patch")
    assert (reviewer / "src/sample.cpp").read_bytes() == source
    assert (reviewer / "include/sample.h").read_bytes() == b"int sample(int value);\n"
    br.git(reviewer, "commit", "-m", "Approve fixture", "-m",
           "Checked the supplied evidence. Compile passed.\n\nBehavior-Recovery-Choice: delivery-01\nBehavior-Recovery-Verdict: PERFECT")
    br.write_files(reviewer, {"build/manifests/build_sample.json": b'{"returncode": 0}\n'})
    assert br.load_json(review_wave / "wave.json")["mode"] == "review"
    reviewed = collect(repo, review_wave, reviewer)
    review_meta = br.load_json(reviewed / "attempt.json")
    assert review_meta["verdict"] == "PERFECT"
    assert review_meta["choice"] == "delivery-01"
    assert b"UNIMPLEMENTED" not in (reviewed / "integration.patch").read_bytes()
    assert br.git(repo, "status", "--porcelain") == before


def test_bad_archive_hash_stops_restore(repo, tmp_path):
    wave, _ = prepare(repo, tmp_path)
    with (wave / "input.zip").open("ab") as handle:
        handle.write(b"corrupt")
    with pytest.raises(ValueError, match="archive hash"):
        br.workspace(argparse.Namespace(repo=repo, wave=wave, destination=tmp_path / "second"))
    assert not (tmp_path / "second").exists()


@pytest.mark.parametrize("value", ["../outside", "/outside", "C:/outside", ".git/config", ".GIT/config", "a/../outside", "a//b"])
def test_unsafe_paths_are_rejected(value):
    with pytest.raises(ValueError):
        br.relative(value)


def test_archive_path_traversal_is_rejected(repo, tmp_path):
    wave, _ = prepare(repo, tmp_path)
    output = io.BytesIO()
    with zipfile.ZipFile(output, "w") as archive:
        archive.writestr("../escape", b"bad")
    data = output.getvalue()
    (wave / "input.zip").write_bytes(data)
    meta = br.load_json(wave / "wave.json")
    meta["input_sha256"] = br.sha(data)
    (wave / "wave.json").write_bytes(br.json_bytes(meta))
    with pytest.raises(ValueError, match="Unsafe"):
        br.load_input(wave)


def test_destinations_and_ancestor_context_are_checked(repo, tmp_path):
    with pytest.raises(ValueError, match="outside"):
        br.check_destination(repo, repo / "build/worker")
    existing = tmp_path / "existing"
    existing.mkdir()
    with pytest.raises(ValueError, match="already exists"):
        br.check_destination(repo, existing)
    parent = tmp_path / "parent"
    parent.mkdir()
    (parent / "AGENTS.md").write_text("parent instructions")
    with pytest.raises(ValueError, match="Ancestor context"):
        br.check_destination(repo, parent / "worker")


def test_constructor_and_crlf_blanking():
    data = b'// prior explanation\r\nExample::Example() : x(2)\r\n{\r\n  const char* s = "}"; /* { */\r\n}\r\n'
    result, _ = br.blank_function(data, 1, 5, VA, "Example")
    assert result == b"#error BEHAVIOR_RECOVERY_UNIMPLEMENTED_00400000\r\n"


@pytest.mark.parametrize("data,name", [
    (b"int other() { return 1; }\n", "sample"),
    (b"int sample_other() { return 1; }\n", "sample"),
    (b"if (sample()) {}\n", "sample"),
    (b"int sample() {\n", "sample"),
    (b"int sample() {} int other() {}\n", "sample"),
    (b"int global; int sample() {}\n", "sample"),
])
def test_ambiguous_or_incomplete_definition_is_rejected(data, name):
    with pytest.raises(ValueError):
        br.blank_function(data, 1, len(data.splitlines()), VA, name)


def test_wrong_original_alias_is_rejected(repo, tmp_path):
    (repo / "orig/alias.exe").write_bytes(b"different original")
    br.git(repo, "add", "orig/alias.exe")
    br.git(repo, "commit", "-m", "Bad fixture")
    with pytest.raises(ValueError, match="alias differs"):
        prepare(repo, tmp_path)


@pytest.mark.parametrize("blank,mode,returncode,output,expected", [
    (True, "reconstruct", 1, b"C1083: missing header", "must stop at its explicit marker"),
    (True, "reconstruct", 0, b"compiled", "must stop at its explicit marker"),
    (False, "review", 1, b"C1083: missing header", "does not compile"),
    (True, "review", 1, b"BEHAVIOR_RECOVERY_UNIMPLEMENTED_00400000", "does not compile"),
])
def test_preflight_rejects_wrong_compile_outcome(tmp_path, blank, mode, returncode, output, expected):
    body = b"#error BEHAVIOR_RECOVERY_UNIMPLEMENTED_00400000\n" if blank else SOURCE
    br.write_files(tmp_path, {"src/sample.cpp": body,
                              "assignment.json": br.json_bytes({"blank_target": mode == "reconstruct"})})
    fake = SimpleNamespace(returncode=returncode, stdout=output, stderr=b"")
    with patch.object(br, "run", return_value=fake), pytest.raises(ValueError, match=expected):
        br.preflight(tmp_path, {"va": VA, "source": "src/sample.cpp"})


@pytest.mark.parametrize("blank", [True, False])
def test_preflight_records_expected_failure_or_success(tmp_path, blank):
    compiler = tmp_path / "CL.EXE"
    compiler.write_bytes(b"fixture compiler; never executed")
    output = b"BEHAVIOR_RECOVERY_UNIMPLEMENTED_00400000" if blank else b"compiled"
    code = 1 if blank else 0
    build = {"build_inputs": {"compiler": {"path": str(compiler)}},
             "command": ["fixture"], "returncode": code, "stdout": output.decode(), "stderr": ""}
    br.write_files(tmp_path, {"src/sample.cpp": b"#error " + output if blank else SOURCE,
                              "assignment.json": br.json_bytes({"blank_target": blank}),
                              "build/manifests/build_sample.json": br.json_bytes(build)})
    with patch.object(br, "run", return_value=SimpleNamespace(returncode=code, stdout=output, stderr=b"")):
        result = br.preflight(tmp_path, {"va": VA, "source": "src/sample.cpp"})
    assert result["preflight"]["returncode"] == code
    assert result["compiler_files"][str(compiler)] == br.sha(compiler.read_bytes())
