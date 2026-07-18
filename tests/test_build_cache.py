from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

import build_cache  # noqa: E402


class BuildCacheTests(unittest.TestCase):
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


if __name__ == "__main__":
    unittest.main()
