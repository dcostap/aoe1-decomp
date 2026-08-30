from __future__ import annotations

import json
import multiprocessing
import queue
import subprocess
import sys
import tempfile
import unittest
from argparse import Namespace
from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import build_function  # noqa: E402
import check_function  # noqa: E402


def _grouped_owner_worker(
    root_text: str,
    owner: str,
    phase: object,
    control: object,
) -> None:
    """Run one build/extract owner with a controlled compiler replacement."""
    root = Path(root_text)
    import extract_obj_function

    source = root / "unit.cpp"
    response = root / "flags.rsp"
    directories = {
        name: root / name
        for name in ("obj", "manifests", "asm", "locks", "tmp")
    }
    for directory in directories.values():
        directory.mkdir(parents=True, exist_ok=True)

    record = {"va": owner, "name": f"owner_{owner}", "size_bytes": "10"}
    toolchain = {"compiler": {"cl": "fake-cl.exe"}}

    def ensure_build_subdir(name: str) -> Path:
        directories[name].mkdir(parents=True, exist_ok=True)
        return directories[name]

    def repo_path(value: str | Path) -> Path:
        path = Path(value)
        if len(path.parts) >= 3 and path.parts[0] == "build" and path.parts[1] in directories:
            return directories[path.parts[1]].joinpath(*path.parts[2:])
        return path if path.is_absolute() else root / path

    def fake_compiler(command: list[str], **_kwargs: object) -> subprocess.CompletedProcess[str]:
        object_path = Path(next(value[3:] for value in command if value.startswith("/Fo")))
        listing_path = Path(next(value[3:] for value in command if value.startswith("/Fa")))
        if owner == "B":
            phase.put(("compiler_started", owner))
            object_path.write_bytes(b"PARTIAL___")
            listing_path.write_text("partial\n", encoding="utf-8")
            if control.get(timeout=5) != "finish_compile":
                raise RuntimeError("grouped test did not release compiler")
        object_path.write_bytes(b"COMPLETE__")
        listing_path.write_text("complete\n", encoding="utf-8")
        return subprocess.CompletedProcess(command, 0, "", "")

    build_function.parse_args = lambda: Namespace(va=owner, force=True)
    build_function.function_record_by_va = lambda _va: record
    build_function.compiler_artifact_slug = lambda _record: "tu_group"
    build_function.compiler_source_path = lambda _record: source
    build_function.load_toolchain = lambda: toolchain
    build_function.preferred_flags_rsp_path = lambda _record, _toolchain: response
    build_function.repo_path = repo_path
    build_function.ensure_build_subdir = ensure_build_subdir
    build_function.build_input_manifest = lambda _source, _response, _toolchain: {
        "fingerprint": "grouped-fingerprint"
    }
    build_function.tool_env = lambda _toolchain: {}
    build_function.parse_listing_file = lambda _path: {"line_changes": []}
    build_function.subprocess.run = fake_compiler
    build_function.main()
    phase.put(("build_done", owner))
    if control.get(timeout=5) != "extract":
        raise RuntimeError("grouped test did not release extraction")

    def fake_object(path: Path) -> SimpleNamespace:
        section = SimpleNamespace(
            data=path.read_bytes(),
            relocations=[],
            index=1,
            name=".text",
        )
        symbol = SimpleNamespace(
            index=0,
            value=0,
            section_number=1,
            name=f"owner_{owner}",
            is_function=True,
        )
        return SimpleNamespace(sections=[section], symbols=[symbol])

    extract_obj_function.parse_args = lambda: Namespace(va=owner, obj=None)
    extract_obj_function.function_record_by_va = lambda _va: record
    extract_obj_function.compiler_artifact_slug = lambda _record: "tu_group"
    extract_obj_function.function_slug = lambda _record: f"owner_{owner}"
    extract_obj_function.repo_path = repo_path
    extract_obj_function.ensure_build_subdir = ensure_build_subdir
    extract_obj_function.matching_build_for_va = lambda _va: None
    extract_obj_function.load_coff_object = fake_object
    extract_obj_function.select_record_function_symbol = lambda obj, _name: obj.symbols[0]
    extract_obj_function.function_symbol_section = lambda obj, _symbol: obj.sections[0]
    extract_obj_function.decode_bytes = lambda _data, _va, _relocations: []
    extract_obj_function.main()
    output_path = directories["asm"] / f"rebuilt_owner_{owner}.bin"
    metadata_path = directories["asm"] / f"rebuilt_owner_{owner}.json"
    metadata = json.loads(metadata_path.read_text(encoding="utf-8"))
    phase.put(("extract_done", owner, output_path.read_bytes(), metadata["build_input_fingerprint"]))


class BuildFunctionTests(unittest.TestCase):
    def _run_build(
        self,
        root: Path,
        run_compiler: object,
        *,
        force: bool = False,
    ) -> None:
        source = root / "source.cpp"
        response = root / "flags.rsp"
        source.write_text("int demo() { return 1; }\n", encoding="utf-8")
        response.write_text("/O2\n", encoding="utf-8")
        directories = {
            name: root / name
            for name in ("obj", "manifests", "asm", "locks", "tmp")
        }

        def ensure_build_subdir(name: str) -> Path:
            directories[name].mkdir(parents=True, exist_ok=True)
            return directories[name]

        record = {"va": "00100000", "name": "demo"}
        toolchain = {"compiler": {"cl": "cl.exe"}}
        args = ["build_function.py", "--va", "00100000"]
        if force:
            args.append("--force")
        with patch.object(sys, "argv", args), patch.multiple(
            build_function,
            function_record_by_va=lambda _va: record,
            compiler_artifact_slug=lambda _record: "tu_group",
            compiler_source_path=lambda _record: source,
            load_toolchain=lambda: toolchain,
            preferred_flags_rsp_path=lambda _record, _toolchain: response,
            repo_path=lambda value: root / str(value),
            ensure_build_subdir=ensure_build_subdir,
            build_input_manifest=lambda _source, _response, _toolchain: {"fingerprint": "fresh"},
            tool_env=lambda _toolchain: {},
            parse_listing_file=lambda _path: {"line_changes": []},
        ), patch.object(build_function.subprocess, "run", side_effect=run_compiler):
            build_function.main()

    def test_failed_build_does_not_leave_a_current_cache(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp:
            root = Path(temp)
            calls: list[list[str]] = []

            def successful_compiler(command: list[str], **_kwargs: object) -> subprocess.CompletedProcess[str]:
                calls.append(command)
                object_path = Path(next(value[3:] for value in command if value.startswith("/Fo")))
                listing_path = Path(next(value[3:] for value in command if value.startswith("/Fa")))
                object_path.write_bytes(b"object")
                listing_path.write_text("listing\n", encoding="utf-8")
                return subprocess.CompletedProcess(command, 0, "", "")

            self._run_build(root, successful_compiler)
            object_path = root / "obj" / "tu_group.obj"
            listing_path = root / "asm" / "rebuilt_tu_group.cod"
            source_map_path = root / "asm" / "rebuilt_tu_group.lines.json"
            manifest_path = root / "manifests" / "build_tu_group.json"
            self.assertEqual(object_path.read_bytes(), b"object")
            self.assertTrue(listing_path.is_file())
            self.assertTrue(source_map_path.is_file())

            def failed_compiler(command: list[str], **_kwargs: object) -> subprocess.CompletedProcess[str]:
                calls.append(command)
                return subprocess.CompletedProcess(command, 1, "", "failed")

            with self.assertRaises(SystemExit) as error:
                self._run_build(root, failed_compiler, force=True)
            self.assertEqual(error.exception.code, 1)
            self.assertEqual(object_path.read_bytes(), b"object")
            self.assertFalse(listing_path.exists())
            self.assertFalse(source_map_path.exists())
            self.assertEqual(json.loads(manifest_path.read_text(encoding="utf-8"))["returncode"], 1)

            self._run_build(root, successful_compiler)
            self.assertEqual(len(calls), 3)
            self.assertTrue(source_map_path.is_file())

    def test_grouped_owner_build_and_extract_use_one_artifact_snapshot(self) -> None:
        context = multiprocessing.get_context("spawn")
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp:
            root = Path(temp)
            (root / "unit.cpp").write_text("int grouped() { return 1; }\n", encoding="utf-8")
            (root / "flags.rsp").write_text("/O2\n", encoding="utf-8")
            phase = context.Queue()
            first_control = context.Queue()
            second_control = context.Queue()
            first = context.Process(
                target=_grouped_owner_worker,
                args=(str(root), "A", phase, first_control),
            )
            second = context.Process(
                target=_grouped_owner_worker,
                args=(str(root), "B", phase, second_control),
            )
            first.start()
            second_started = False
            try:
                self.assertEqual(phase.get(timeout=5), ("build_done", "A"))
                second.start()
                second_started = True
                self.assertEqual(phase.get(timeout=5), ("compiler_started", "B"))
                first_control.put("extract")
                with self.assertRaises(queue.Empty):
                    phase.get(timeout=0.2)
                second_control.put("finish_compile")
                self.assertEqual(phase.get(timeout=5), ("build_done", "B"))
                second_control.put("extract")
                results = [phase.get(timeout=5), phase.get(timeout=5)]
            finally:
                first_control.put("extract")
                second_control.put("finish_compile")
                second_control.put("extract")
                first.join(timeout=5)
                if second_started:
                    second.join(timeout=5)
                if first.is_alive():
                    first.terminate()
                if second.is_alive():
                    second.terminate()
            self.assertEqual(first.exitcode, 0)
            self.assertEqual(second.exitcode, 0)
            self.assertEqual(
                sorted((row[0], row[1]) for row in results),
                [("extract_done", "A"), ("extract_done", "B")],
            )
            for row in results:
                self.assertEqual(row[2], b"COMPLETE__")
                self.assertEqual(row[3], "grouped-fingerprint")

    def test_checker_rejects_extraction_from_another_fingerprint(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp:
            root = Path(temp)
            build_root = root / "build"
            obj_path = build_root / "obj" / "tu_group.obj"
            source_map_path = build_root / "asm" / "rebuilt_tu_group.lines.json"
            extracted_bin = build_root / "asm" / "rebuilt_owner_A.bin"
            extracted_json = build_root / "asm" / "rebuilt_owner_A.json"
            extracted_txt = build_root / "asm" / "rebuilt_owner_A.txt"
            for path in (obj_path, source_map_path, extracted_bin, extracted_json, extracted_txt):
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text("artifact\n", encoding="utf-8")
            extracted_json.write_text(
                json.dumps({"build_input_fingerprint": "old-fingerprint"}),
                encoding="utf-8",
            )
            record = {"va": "00100000"}
            with patch.object(check_function, "REPO_ROOT", root), patch.object(
                check_function,
                "load_toolchain",
                return_value={},
            ), patch.object(
                check_function,
                "compiler_source_path",
                return_value=root / "source.cpp",
            ), patch.object(
                check_function,
                "preferred_flags_rsp_path",
                return_value=root / "flags.rsp",
            ), patch.object(
                check_function,
                "build_input_manifest",
                return_value={"fingerprint": "current-fingerprint"},
            ), patch.object(
                check_function,
                "compiler_artifact_slug",
                return_value="tu_group",
            ), patch.object(check_function, "build_manifest_matches", return_value=True):
                build_current, extraction_current, _ = check_function.rebuilt_cache_state(
                    record, "owner_A"
                )
            self.assertTrue(build_current)
            self.assertFalse(extraction_current)
            extracted_json.write_text(
                json.dumps({"build_input_fingerprint": "current-fingerprint"}),
                encoding="utf-8",
            )
            with patch.object(check_function, "REPO_ROOT", root), patch.object(
                check_function,
                "load_toolchain",
                return_value={},
            ), patch.object(
                check_function,
                "compiler_source_path",
                return_value=root / "source.cpp",
            ), patch.object(
                check_function,
                "preferred_flags_rsp_path",
                return_value=root / "flags.rsp",
            ), patch.object(
                check_function,
                "build_input_manifest",
                return_value={"fingerprint": "current-fingerprint"},
            ), patch.object(
                check_function,
                "compiler_artifact_slug",
                return_value="tu_group",
            ), patch.object(check_function, "build_manifest_matches", return_value=True):
                _, extraction_current, _ = check_function.rebuilt_cache_state(record, "owner_A")
            self.assertTrue(extraction_current)


if __name__ == "__main__":
    unittest.main()
