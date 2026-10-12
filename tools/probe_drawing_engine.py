"""Check src/Asm_draw.asm against the original drawing engine and run native tests.

The assembled THIS_COD and THIS_DAT sections must equal the original bytes once
each relocation is resolved, and every relocation must land on the address that
config/drawing_binary.json records for it. The setup, HLine, and sprite fixtures
then run against the assembled object at two image bases.
"""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import struct
import subprocess

import pefile

from build_assembly import assemble_source
from build_cache import compiler_admission
from coff import load_coff_object
from common import REPO_ROOT, load_toolchain, tool_env

SOURCE = REPO_ROOT / "src/Asm_draw.asm"
MANIFEST = REPO_ROOT / "config/drawing_binary.json"
ORIGINAL = REPO_ROOT / "orig/empiresx.exe"
SECTION_NAMES = ("THIS_COD", "THIS_DAT")


def drawing_engine_issues(obj_path: Path, original: Path = ORIGINAL) -> list[str]:
    """Compare an assembled drawing engine with the original sections and relocations."""
    manifest = json.loads(MANIFEST.read_text())
    pe = pefile.PE(str(original))
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    obj = load_coff_object(obj_path)
    issues = []
    sections = {}
    for name in SECTION_NAMES:
        found = [(i + 1, s) for i, s in enumerate(obj.sections) if s.name == name]
        if len(found) != 1:
            return [f"{name} must appear once"]
        sections[name] = found[0]
    addresses = {sections[name][0]: spec["original_va"]
                 for name, spec in zip(SECTION_NAMES, manifest["sections"])}
    symbols = {s.name: s for s in obj.symbols}
    for name, spec in zip(SECTION_NAMES, manifest["sections"]):
        _, section = sections[name]
        if section.characteristics != spec["characteristics"]:
            issues.append(f"{name} characteristics {section.characteristics:#x} differ")
        data = bytearray(section.data)
        expected_targets = {r["offset"]: manifest["sections"][r["target_section"]]["original_va"] + r["target_offset"]
                            for r in spec["relocations"]}
        actual_targets = {}
        for relocation in section.relocations:
            target = symbols[relocation.symbol_name]
            if relocation.reloc_type != 6 or target.section_number not in addresses:
                issues.append(f"{name} relocation at {relocation.offset:#x} has an unexpected target")
                continue
            addend = struct.unpack_from("<I", data, relocation.offset)[0]
            value = (addresses[target.section_number] + target.value + addend) & 0xFFFFFFFF
            struct.pack_into("<I", data, relocation.offset, value)
            actual_targets[relocation.offset] = value
        if actual_targets != expected_targets:
            issues.append(f"{name} relocations differ from the reviewed manifest")
        va = spec["original_va"]
        if bytes(data) != bytes(image[va - base:va - base + spec["size"]]):
            issues.append(f"{name} bytes differ from the original")
    exports = {s.name: addresses.get(s.section_number, 0) + s.value
               for s in obj.symbols if s.storage_class == 2 and s.section_number > 0}
    if exports != manifest["exports"]:
        issues.append("exports differ from the original entry points")
    return issues


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output-dir", default="build/probes/drawing_engine",
                        help="Output directory under build/. Each run uses a new subdirectory.")
    args = parser.parse_args()
    root = (REPO_ROOT / args.output_dir).resolve()
    if not root.is_relative_to((REPO_ROOT / "build").resolve()):
        parser.error("Output must be under build/.")
    output = root / datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S%fZ")
    output.mkdir(parents=True)
    obj = output / "Asm_draw.obj"
    assembled = assemble_source(SOURCE, obj)
    if not assembled["compiled"]:
        raise RuntimeError(assembled["stdout"] + assembled["stderr"])
    issues = drawing_engine_issues(obj)
    toolchain = load_toolchain()
    commands, fixtures = [], []

    def run(command):
        with compiler_admission():
            result = subprocess.run([str(x) for x in command], cwd=output, env=tool_env(toolchain),
                                    capture_output=True, text=True, timeout=120)
        row = dict(command=[str(x) for x in command], returncode=result.returncode,
                   stdout=result.stdout, stderr=result.stderr)
        commands.append(row)
        (output / "commands.json").write_text(json.dumps(commands, indent=2) + "\n")
        if result.returncode:
            raise RuntimeError(row)

    for index, name in enumerate(("drawing_setup", "drawing_hline", "drawing_sprite")):
        source = REPO_ROOT / ("tests/fixtures/masm/" + name + ".cpp")
        fixtures.append(dict(source=str(source), sha256=hashlib.sha256(source.read_bytes()).hexdigest()))
        run([toolchain["compiler"]["cl"], "@" + str(REPO_ROOT / "config/flags/default.rsp"), "/Focaller.obj", source])
        for base in (0x400000, 0x10000000):
            exe = output / ("native_%d_%08x.exe" % (index, base))
            run([toolchain["compiler"]["link"], "/nologo", "/subsystem:console", "/fixed:no",
                 "/base:0x%x" % base, "/out:" + str(exe), "caller.obj", obj, "kernel32.lib"])
            run([exe])
    report = dict(assembly=assembled, issues=issues, fixtures=fixtures, commands=commands,
                  image_bases=[0x400000, 0x10000000], native_tests_passed=True)
    (output / "report.json").write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(dict(issues=issues, native_tests_passed=True, report=str(output / "report.json")), indent=2))
    return 1 if issues else 0


if __name__ == "__main__":
    raise SystemExit(main())
