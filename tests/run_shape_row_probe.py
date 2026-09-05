"""Run extracted Shape bodies with the pinned x86 compiler.

This checks selected valid inputs. It does not prove complete semantic equality.
Only AlignedWidth and memset calls are redirected to test implementations.
Run the authoritative target checks first to refresh extracted artifacts.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from common import load_toolchain, tool_env
from coff import load_coff_object, function_symbol_section


def bundle_entry(prefix: str, slug: str, obj_path: Path | None) -> bytes:
    path = ROOT / "build" / "asm" / f"{prefix}_{slug}"
    if prefix == "rebuilt" and obj_path is not None:
        registry = json.loads((ROOT / "config/functions/src/Shape.cpp.json").read_text())
        name = registry["functions"][slug[:8]]["symbol"]
        obj = load_coff_object(obj_path)
        symbols = [s for s in obj.symbols if s.name == name and s.section_number > 0]
        if len(symbols) != 1:
            raise ValueError(f"Expected one owner for {name}")
        section = function_symbol_section(obj, symbols[0])
        code = section.data
        metadata = {"relocations": [
            {"offset": r.offset, "type": f"0x{r.reloc_type:04X}", "symbol_name": r.symbol_name}
            for r in section.relocations
        ]}
    else:
        code = path.with_suffix(".bin").read_bytes()
        metadata = json.loads(path.with_suffix(".json").read_text())
    calls = []
    if prefix == "orig":
        base = int(slug[:8], 16)
        targets = {"00444B40h": 0, "0054DA60h": 1}
        for region in metadata["ranges"]:
            for insn in region["decoded"]:
                if insn["text"].startswith("call "):
                    target = insn["text"].split()[1]
                    if target not in targets:
                        raise ValueError(f"Unsupported original call: {target}")
                    calls.append((int(insn["address"], 16) - base + 1, targets[target]))
    else:
        targets = {"?AlignedWidth@TDrawArea@@QAEJXZ": 0, "_memset": 1}
        for relocation in metadata["relocations"]:
            if relocation["type"] != "0x0014":
                raise ValueError(f"Unsupported relocation: {relocation}")
            calls.append((relocation["offset"], targets[relocation["symbol_name"]]))
    expected = 3 if "color" in slug else 1
    if len(calls) != expected:
        raise ValueError(f"Unexpected call count for {path}: {calls}")
    return struct.pack("<II", len(code), len(calls)) + code + b"".join(
        struct.pack("<II", *call) for call in calls
    )


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output-dir", type=Path, default=ROOT / "build" / "shape_row_probe")
    parser.add_argument("--object", type=Path, help="Use this audited Shape object instead of rebuilt extracts")
    args = parser.parse_args()
    output = args.output_dir.resolve()
    output.mkdir(parents=True, exist_ok=True)
    bundle = output / "bodies.bin"
    bundle.write_bytes(b"".join(
        bundle_entry(prefix, slug, args.object)
        for slug in ("004B9E20_shape_color_trans_clipped", "004BB910_shape_dithered_clipped")
        for prefix in ("orig", "rebuilt")
    ))
    config = load_toolchain()
    env = tool_env(config)
    exe = output / "shape_row_probe.exe"
    obj = output / "shape_row_probe.obj"
    build = subprocess.run([
        config["compiler"]["cl"], "/nologo", "/O2", str(ROOT / "tests" / "shape_row_probe.cpp"),
        f"/Fo{obj}", f"/Fe{exe}", "/link", "kernel32.lib",
    ], cwd=output, env=env, capture_output=True, text=True)
    (output / "compile.txt").write_text(build.stdout + build.stderr)
    build.check_returncode()
    run = subprocess.run([str(exe), str(bundle)], cwd=output, capture_output=True, text=True)
    (output / "result.txt").write_text(run.stdout + run.stderr)
    (output / "inputs.json").write_text(json.dumps({
        "object": str(args.object.resolve()) if args.object else None,
        "object_sha256": hashlib.sha256(args.object.read_bytes()).hexdigest() if args.object else None,
        "bundle_sha256": hashlib.sha256(bundle.read_bytes()).hexdigest(),
        "probe_sha256": hashlib.sha256((ROOT / "tests/shape_row_probe.cpp").read_bytes()).hexdigest(),
        "returncode": run.returncode,
    }, indent=2) + "\n")
    print(run.stdout.splitlines()[-1] if run.stdout else f"Probe exit: {run.returncode}")
    return run.returncode


if __name__ == "__main__":
    raise SystemExit(main())
