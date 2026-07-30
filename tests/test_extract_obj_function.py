from __future__ import annotations

import sys
import unittest
from pathlib import Path
from types import SimpleNamespace


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from extract_obj_function import decode_bytes  # noqa: E402


class ExtractObjFunctionTests(unittest.TestCase):
    def test_decoded_instruction_carries_symbolic_coff_relocation(self) -> None:
        relocation = SimpleNamespace(
            offset=1,
            reloc_type=0x0014,
            width=4,
            symbol_name="?helper@@YAXH@Z",
        )
        rows = decode_bytes(bytes.fromhex("e800000000c3"), 0x00401000, [relocation])
        self.assertEqual(rows[0]["text"], "call 00401005h")
        self.assertEqual(rows[0]["relocations"][0]["symbol_name"], "?helper@@YAXH@Z")
        self.assertEqual(rows[1]["relocations"], [])


if __name__ == "__main__":
    unittest.main()
