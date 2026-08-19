from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

from coff import function_symbol_section, load_coff_object
from common import (
    function_record_by_va,
    load_binaries,
    load_pe_image,
    load_toolchain,
    repo_path,
    tool_env,
)


ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build" / "utmarray_validation"
SOURCE = BUILD / "instantiate.cpp"
OBJECT = BUILD / "instantiate.obj"

EXACT_METHODS = {
    "??1?$ManagedArray@H@@QAE@XZ": 0x00408D20,
    "??A?$ManagedArray@H@@QAEAAHH@Z": 0x004EA750,
    "?contains@?$ManagedArray@H@@QBEHABH@Z": 0x004DE980,
    "?add@?$ManagedArray@H@@QAEHH@Z": 0x004DE9D0,
    "?remove@?$ManagedArray@H@@QAEHH@Z": 0x004F1390,
    "?resize@?$ManagedArray@H@@IAEHH@Z": 0x004147A0,
}

EXPECTED_METHODS = {
    "??0?$ManagedArray@H@@QAE@H@Z",
    "??1?$ManagedArray@H@@QAE@XZ",
    "??A?$ManagedArray@H@@QAEAAHH@Z",
    "?enlarge@?$ManagedArray@H@@QAEHH@Z",
    "?shrink@?$ManagedArray@H@@QAEHH@Z",
    "?contains@?$ManagedArray@H@@QBEHABH@Z",
    "?position@?$ManagedArray@H@@QAEHAAH@Z",
    "?add@?$ManagedArray@H@@QAEHH@Z",
    "?remove@?$ManagedArray@H@@QAEHH@Z",
    "?number@?$ManagedArray@H@@QBE?BHXZ",
    "?desiredNumber@?$ManagedArray@H@@QBE?BHXZ",
    "?setDesiredNumber@?$ManagedArray@H@@QAEXH@Z",
    "?zeroNumber@?$ManagedArray@H@@QAEXXZ",
    "?maximumSize@?$ManagedArray@H@@QBE?BHXZ",
    "?sort@?$ManagedArray@H@@QAEXP6AHHH@Z@Z",
    "?resize@?$ManagedArray@H@@IAEHH@Z",
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Validate the reconstructed utmarray.h with pinned VC5."
    )
    return parser.parse_args()


def compile_header() -> None:
    BUILD.mkdir(parents=True, exist_ok=True)
    SOURCE.write_text(
        '#include "../../include/utmarray.h"\n\n'
        "typedef char ManagedArray_int_size_check[\n"
        "    sizeof(ManagedArray<int>) == 16 ? 1 : -1];\n\n"
        "template class ManagedArray<int>;\n",
        encoding="utf-8",
    )

    toolchain = load_toolchain()
    compiler = repo_path(toolchain["compiler"]["cl"])
    response = ROOT / "config" / "flags" / "default.rsp"
    result = subprocess.run(
        [
            str(compiler),
            f"@{response}",
            f"/Fo{OBJECT}",
            str(SOURCE),
        ],
        cwd=ROOT,
        env=tool_env(toolchain),
        text=True,
        capture_output=True,
    )
    if result.returncode != 0:
        sys.stdout.write(result.stdout)
        sys.stderr.write(result.stderr)
        raise SystemExit(result.returncode)


def masked_pair(
    original: bytes, rebuilt: bytes, relocations: list
) -> tuple[bytes, bytes]:
    original_bytes = bytearray(original)
    rebuilt_bytes = bytearray(rebuilt[: len(original)])
    for relocation in relocations:
        start = relocation.offset
        end = start + relocation.width
        original_bytes[start:end] = b"\0" * relocation.width
        rebuilt_bytes[start:end] = b"\0" * relocation.width
    return bytes(original_bytes), bytes(rebuilt_bytes)


def main() -> None:
    parse_args()
    compile_header()

    obj = load_coff_object(OBJECT)
    symbol_names = {
        symbol.name for symbol in obj.symbols if "ManagedArray" in symbol.name
    }
    missing = sorted(EXPECTED_METHODS - symbol_names)
    if missing:
        for name in missing:
            print(f"MISSING SIGNATURE: {name}")
        raise SystemExit(1)

    binaries = load_binaries()
    executable = load_pe_image(repo_path(binaries["original_exe"]))
    failures = 0

    for name, va in EXACT_METHODS.items():
        symbol = next(symbol for symbol in obj.symbols if symbol.name == name)
        section = function_symbol_section(obj, symbol)
        size = int(function_record_by_va(va)["size_bytes"])
        original = executable.read_va_range(va, va + size - 1)
        original_masked, rebuilt_masked = masked_pair(
            original, section.data, section.relocations
        )
        differences = sum(
            left != right
            for left, right in zip(original_masked, rebuilt_masked)
        )
        differences += abs(len(original_masked) - len(rebuilt_masked))
        result = "MATCH" if differences == 0 else "MISMATCH"
        print(
            f"{va:08X} {result}: {size} bytes, "
            f"{differences} difference(s)"
        )
        failures += differences != 0

    print(f"Signatures: {len(EXPECTED_METHODS)}/{len(EXPECTED_METHODS)}")
    if failures:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
