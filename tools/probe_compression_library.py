"""Check the recovered compression library sources against the original executable.

src/Inf32.asm must assemble to the original Inf32 bytes and relocation targets.
src/Deflate.c must behave like the original Deflate object: a differential test
links both and compares output, return codes, and final state. Finally, data is
compressed and decoded with the source-built objects alone and checked with zlib.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path
import struct
import subprocess
import zlib

import pefile

from build_assembly import assemble_source
from build_cache import compiler_admission
from coff import load_coff_object
from common import REPO_ROOT, load_toolchain, repo_path, tool_env
from compression_binary import build_compression_object

ORIGINAL = REPO_ROOT / "orig/empiresx.exe"
ORACLE_MANIFEST = REPO_ROOT / "config/compression_binary.json"
DEFLATE = REPO_ROOT / "src/Deflate.c"
INF32 = REPO_ROOT / "src/Inf32.asm"
FIXTURES = REPO_ROOT / "tests/fixtures/compression_library"
INF32_START = 0x54A620
INF32_END = 0x54B186
PUBLIC_NAMES = ("deflate_data", "deflate_init", "deflate_deinit", "deflate_buf_size")


def inf32_issues(obj_path: Path, original: Path = ORIGINAL) -> list[str]:
    """Compare an assembled Inf32 object with the original code and data."""
    pe = pefile.PE(str(original))
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    expected = bytes(image[INF32_START - base:INF32_END - base])
    obj = load_coff_object(obj_path)
    code = [s for s in obj.sections if s.name.startswith(".text")]
    if len(code) != 1:
        return ["Inf32 must have one code section"]
    section = code[0]
    issues = []
    data = bytearray(section.data)
    if len(data) != len(expected):
        issues.append(f"Inf32 code is {len(data)} bytes; the original is {len(expected)}")
    symbols = {s.name: s for s in obj.symbols}
    section_number = obj.sections.index(section) + 1
    for relocation in section.relocations:
        target = symbols[relocation.symbol_name]
        if relocation.reloc_type != 6 or target.section_number != section_number:
            issues.append(f"Inf32 relocation at {relocation.offset:#x} has another target section")
            continue
        addend = struct.unpack_from("<I", data, relocation.offset)[0]
        value = (INF32_START + target.value + addend) & 0xFFFFFFFF
        struct.pack_into("<I", data, relocation.offset, value)
    if bytes(data) != expected:
        mismatch = next((i for i, (a, b) in enumerate(zip(data, expected)) if a != b), None)
        issues.append(f"Inf32 bytes differ from the original (first at {mismatch})")
    infdat = [s for s in obj.sections if s.name == "Inf32Dat"]
    if len(infdat) != 1 or infdat[0].data != bytes(0xAD90) or infdat[0].characteristics != 0xC0500040:
        issues.append("Inf32Dat must be 0xAD90 zero bytes of 16-byte-aligned writable data")
    exports = {s.name: s.value for s in obj.symbols if s.storage_class == 2 and s.section_number == section_number}
    if exports != {"_Inf32BufSize": 0x54B0C5 - INF32_START, "_Inf32Decode": 0x54B0CB - INF32_START}:
        issues.append(f"Inf32 exports differ: {exports}")
    return issues


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output-dir", default="build/probes/compression_library",
                        help="Output directory under build/. Each run uses a new subdirectory.")
    parser.add_argument("--quick", action="store_true",
                        help="Skip differential inputs larger than 40,000 bytes and external files.")
    args = parser.parse_args()
    output_root = repo_path(args.output_dir).resolve()
    if not output_root.is_relative_to((REPO_ROOT / "build").resolve()):
        parser.error("Output must be under build/.")
    out = output_root / datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S%fZ")
    out.mkdir(parents=True)
    toolchain = load_toolchain()
    env = tool_env(toolchain)
    cl = str(repo_path(toolchain["compiler"]["cl"]))
    link = str(repo_path(toolchain["compiler"]["link"]))
    commands = []

    def run(command: list, check: bool = True) -> subprocess.CompletedProcess:
        command = [str(part) for part in command]
        with compiler_admission():
            result = subprocess.run(command, cwd=out, env=env, capture_output=True, text=True, timeout=1800)
        commands.append(dict(command=command, returncode=result.returncode,
                             stdout=result.stdout[-4000:], stderr=result.stderr[-4000:]))
        (out / "commands.json").write_text(json.dumps(commands, indent=2) + "\n")
        if check and result.returncode:
            raise RuntimeError(f"Command failed: {command}\n{result.stdout}{result.stderr}")
        return result

    report: dict = {}
    assembled = assemble_source(INF32, out / "Inf32.obj")
    if not assembled["compiled"]:
        raise RuntimeError(assembled["stdout"] + assembled["stderr"])
    report["inf32_issues"] = inf32_issues(out / "Inf32.obj")

    # The original object is only the test oracle. It is never linked into the game.
    build_compression_object(ORIGINAL, ORACLE_MANIFEST, out / "original.obj")
    flags = "@" + str(REPO_ROOT / "config/flags/default.rsp")
    run([cl, flags, "/FoDeflate.obj", DEFLATE])
    run([cl, flags, *[f"/D{name}=src_{name}" for name in PUBLIC_NAMES], "/Fosrc_deflate.obj", DEFLATE])
    run([cl, flags, "/Fodeflate_diff.obj", FIXTURES / "deflate_diff.c"])
    run([link, "/nologo", "/subsystem:console", "/out:deflate_diff.exe",
         "deflate_diff.obj", "src_deflate.obj", "original.obj", "kernel32.lib"])
    inputs = []
    game = REPO_ROOT / "runtime/data2/empires.dat"
    if not args.quick and game.is_file():
        (out / "empires_dat.raw").write_bytes(zlib.decompress(game.read_bytes(), -15))
        inputs.append("empires_dat.raw")
    result = run([out / "deflate_diff.exe", *(["-quick"] if args.quick else []), *inputs], check=False)
    summary = result.stdout.strip().splitlines()[-1] if result.stdout.strip() else ""
    report["differential"] = dict(returncode=result.returncode, summary=summary,
                                  external_inputs=inputs, quick=args.quick,
                                  mismatches=[line for line in result.stdout.splitlines()
                                              if line.startswith("MISMATCH")][:50])

    # Round trips with the source-built objects only, at two link bases.
    run([cl, flags, "/Focompression_test.obj", FIXTURES / "compression_test.c"])
    runs = []
    for base in (0x400000, 0x10000000):
        exe = "compression_test_%08x.exe" % base
        run([link, "/nologo", "/subsystem:console", "/fixed:no", "/base:0x%x" % base, "/out:" + exe,
             "compression_test.obj", "Deflate.obj", "Inf32.obj", "kernel32.lib"])
        run([out / exe])
        fixtures = []
        for index in range(24):
            raw = (out / ("fixture_%02d.raw" % index)).read_bytes()
            packed = (out / ("fixture_%02d.deflate" % index)).read_bytes()
            if zlib.decompress(packed, -15) != raw:
                raise RuntimeError(f"zlib does not decode fixture {index}")
            fixtures.append(dict(index=index, raw_size=len(raw), packed_size=len(packed),
                                 sha256=hashlib.sha256(packed).hexdigest()))
        decoded = []
        if game.is_file():
            expected = zlib.decompress(game.read_bytes(), -15)
            (out / "game_expected.raw").write_bytes(expected)
            run([out / exe, game, out / "game_expected.raw"])
            decoded.append("runtime/data2/empires.dat")
            for level in (0, 1, 6, 9):
                encoder = zlib.compressobj(level, zlib.DEFLATED, -15)
                (out / ("zlib_level%d.deflate" % level)).write_bytes(encoder.compress(expected) + encoder.flush())
                run([out / exe, out / ("zlib_level%d.deflate" % level), out / "game_expected.raw"])
                decoded.append("zlib level %d" % level)
        runs.append(dict(image_base=base, fixtures=fixtures, decoded=decoded))
    if runs[0]["fixtures"] != runs[1]["fixtures"]:
        raise RuntimeError("Output differs between link bases")
    report["round_trips"] = runs
    report["passed"] = not report["inf32_issues"] and report["differential"]["returncode"] == 0
    (out / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(dict(passed=report["passed"], inf32_issues=report["inf32_issues"],
                          differential=summary, round_trip_cases=len(runs[0]["fixtures"]),
                          decoded=runs[0]["decoded"], report=str(out / "report.json")), indent=2))
    return 0 if report["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
