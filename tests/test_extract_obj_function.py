from __future__ import annotations

import sys
import unittest
from pathlib import Path
from types import SimpleNamespace


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from extract_obj_function import (  # noqa: E402
    decode_bytes,
    select_exact_function_symbol,
    select_record_function_symbol,
)


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

    def test_uppercase_method_is_not_mistaken_for_constructor(self) -> None:
        obj = SimpleNamespace(
            symbols=[
                SimpleNamespace(
                    name="?PreprocessMessages@Handler@@QAEXXZ",
                    section_number=1,
                    is_function=True,
                ),
                SimpleNamespace(
                    name="?context@@YAHH@Z",
                    section_number=2,
                    is_function=True,
                ),
            ]
        )
        symbol = select_record_function_symbol(obj, "PreprocessMessages")
        self.assertEqual(symbol.name, "?PreprocessMessages@Handler@@QAEXXZ")

    def test_constructor_still_uses_decorated_identity(self) -> None:
        obj = SimpleNamespace(
            symbols=[
                SimpleNamespace(name="??0Thing@@QAE@XZ", section_number=1, is_function=True),
                SimpleNamespace(name="??1Thing@@QAE@XZ", section_number=2, is_function=True),
            ]
        )
        symbol = select_record_function_symbol(obj, "Thing")
        self.assertEqual(symbol.name, "??0Thing@@QAE@XZ")

    def test_exact_symbol_selects_one_overload(self) -> None:
        obj = SimpleNamespace(
            symbols=[
                SimpleNamespace(name="?create@Thing@@QAEHPAD@Z", section_number=1, is_function=True),
                SimpleNamespace(name="?create@Thing@@QAEHPAPAD@Z", section_number=2, is_function=True),
            ]
        )
        symbol = select_exact_function_symbol(obj, "?create@Thing@@QAEHPAPAD@Z")
        self.assertEqual(symbol.name, "?create@Thing@@QAEHPAPAD@Z")


if __name__ == "__main__":
    unittest.main()
