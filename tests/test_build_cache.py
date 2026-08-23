from __future__ import annotations

import multiprocessing
import queue
import sys
import tempfile
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import build_cache  # noqa: E402


def _hold_build_lock(path: str, entered: object, release: object) -> None:
    with build_cache.build_artifact_lock(Path(path)):
        entered.put(True)
        release.get(timeout=5)


class BuildCacheTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        (REPO_ROOT / "build").mkdir(parents=True, exist_ok=True)

    def test_source_dependencies_follow_repo_local_includes(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp:
            root = Path(temp)
            header = root / "local.h"
            source = root / "unit.cpp"
            header.write_text("#define VALUE 1\n", encoding="utf-8")
            source.write_text('#include "local.h"\nint x = VALUE;\n', encoding="utf-8")
            dependencies = build_cache.source_dependencies(source)
            self.assertEqual(set(dependencies), {source.resolve(), header.resolve()})

    def test_manifest_fingerprint_changes_with_header(self) -> None:
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp:
            root = Path(temp)
            header = root / "local.h"
            source = root / "unit.cpp"
            rsp = root / "flags.rsp"
            header.write_text("#define VALUE 1\n", encoding="utf-8")
            source.write_text('#include "local.h"\nint x = VALUE;\n', encoding="utf-8")
            rsp.write_text("/O2\n", encoding="utf-8")
            toolchain = {"compiler": {"cl": str(Path(sys.executable))}}
            first = build_cache.build_input_manifest(source, rsp, toolchain)
            header.write_text("#define VALUE 2\n", encoding="utf-8")
            second = build_cache.build_input_manifest(source, rsp, toolchain)
            self.assertNotEqual(first["fingerprint"], second["fingerprint"])

    def test_artifact_lock_serializes_processes(self) -> None:
        context = multiprocessing.get_context("spawn")
        with tempfile.TemporaryDirectory(dir=REPO_ROOT / "build") as temp:
            lock_path = Path(temp) / "tu_group.lock"
            first_entered = context.Queue()
            first_release = context.Queue()
            second_entered = context.Queue()
            second_release = context.Queue()
            first = context.Process(
                target=_hold_build_lock,
                args=(str(lock_path), first_entered, first_release),
            )
            second = context.Process(
                target=_hold_build_lock,
                args=(str(lock_path), second_entered, second_release),
            )
            first.start()
            second_started = False
            try:
                self.assertTrue(first_entered.get(timeout=5))
                second.start()
                second_started = True
                with self.assertRaises(queue.Empty):
                    second_entered.get(timeout=0.2)
                first_release.put(True)
                self.assertTrue(second_entered.get(timeout=5))
                second_release.put(True)
            finally:
                if first.is_alive():
                    first_release.put(True)
                if second_started and second.is_alive():
                    second_release.put(True)
                first.join(timeout=5)
                second.join(timeout=5)
                if first.is_alive():
                    first.terminate()
                if second.is_alive():
                    second.terminate()
            self.assertEqual(first.exitcode, 0)
            self.assertEqual(second.exitcode, 0)
            self.assertTrue(lock_path.is_file())


if __name__ == "__main__":
    unittest.main()
