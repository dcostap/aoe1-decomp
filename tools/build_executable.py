"""Compile all game sources and link with the pinned VC5 toolchain."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
from pathlib import Path

from common import REPO_ROOT, load_build_modules, load_toolchain, repo_path, tool_env
from build_cache import build_input_manifest
from function_compare import compile_source
from pe_resources import compile_resources, extract_icon
from build_assembly import assemble_source
from linked_inputs import digest, registry_digest


def run_command(command: list[str], output: Path, toolchain: dict) -> subprocess.CompletedProcess:
    try:
        return subprocess.run(command, capture_output=True, text=True,
                              cwd=output, env=tool_env(toolchain))
    except OSError as error:
        return subprocess.CompletedProcess(command, 127, "", str(error))


def source_plan(config: dict, modules: list[dict]) -> list[dict]:
    sources = {
        str(m["source"]): {"source": str(m["source"]),
                            "flags": str(m["build"]["flags_path"]),
                            "route": "registry"}
        for m in modules
    }
    for source, profile in config["additional_sources"].items():
        if source.casefold() in {s.casefold() for s in sources}:
            raise ValueError(f"Duplicate build route: {source}")
        sources[source] = {"source": source, "flags": f"config/flags/{profile}.rsp",
                           "route": "integration"}
    actual = {p.relative_to(REPO_ROOT).as_posix()
              for p in (REPO_ROOT / "src").iterdir()
              if p.suffix.lower() in {".c", ".cpp"}}
    missing = {s for s in actual if s.casefold() not in {key.casefold() for key in sources}}
    if missing:
        raise ValueError(f"Sources without build routes: {sorted(missing)}")
    return [sources[key] for key in sorted(sources, key=str.lower)]


def link_diagnostics(text: str) -> dict:
    unresolved: dict[str, list[str]] = {}
    for line in text.splitlines():
        match = re.search(r"^(.*?)\s*:\s*error LNK2001: unresolved external symbol (.*)$", line)
        if match:
            unresolved.setdefault(match[2].strip(), []).append(match[1].strip())
    return {
        "unresolved": unresolved,
        "errors": [line for line in text.splitlines()
                   if re.search(r"\b(?:fatal error|error) LNK\d+:", line)],
        "warnings": [line for line in text.splitlines() if "warning LNK" in line],
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output-dir", default="build/executable",
                        help="Build output directory under build/. Each run uses a new subdirectory.")
    args = parser.parse_args()
    output_root = repo_path(args.output_dir).resolve()
    if not output_root.is_relative_to((REPO_ROOT / "build").resolve()):
        parser.error("Output must be under build/.")
    # Keep previous evidence and never mistake an old EXE for a successful link.
    from datetime import datetime, timezone
    output = output_root / datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S%fZ")
    output.mkdir(parents=True)
    config = json.loads((REPO_ROOT / "config/executable.json").read_text(encoding="utf-8"))
    plan = source_plan(config, load_build_modules())
    report: dict = {"schema": 1, "config": config, "sources": [], "linked": False}
    report['registry_sha256'] = registry_digest()
    toolchain = load_toolchain()
    report["toolchain"] = toolchain
    # The original EXE is the comparison oracle, not a build input.
    original = repo_path(config["original"])
    report["original_sha256"] = hashlib.sha256(original.read_bytes()).hexdigest() if original.is_file() else None
    objects = []
    for index, entry in enumerate(plan, 1):
        source = repo_path(entry["source"])
        obj = output / f"{source.stem}.obj"
        row = dict(entry, object=str(obj), compiled=False)
        try:
            row["inputs"] = build_input_manifest(source, repo_path(entry["flags"]), toolchain)
            row["build"] = compile_source(source, obj, repo_path(entry["flags"]), source.parent)
            row["compiled"] = True
            objects.append(obj)
        except (OSError, RuntimeError, ValueError) as error:
            row["error"] = str(error)
        report["sources"].append(row)
        print(f"[{index}/{len(plan)}] {entry['source']}: {'OK' if row['compiled'] else 'FAILED'}", flush=True)

    report["assembly_sources"] = []
    for source_name in config.get("assembly_sources", []):
        source = repo_path(source_name)
        obj = output / (source.stem + "_asm.obj")
        try:
            row = assemble_source(source, obj)
        except (OSError, ValueError) as error:
            row = dict(source=source_name, compiled=False, error=str(error))
        report["assembly_sources"].append(row)
        if row["compiled"]:
            objects.append(obj)

    exe = output / (config["name"] + ".exe")
    response = output / "link.rsp"
    arguments = config["link_flags"] + [f'/OUT:"{exe}"', f'/MAP:"{output / "empiresx.map"}"']
    if any(flag.upper().split(":")[0] == "/DEBUG" for flag in config["link_flags"]):
        arguments.append(f'/PDB:"{output / "empiresx.pdb"}"')
    arguments += [f'/LIBPATH:"{repo_path(path)}"' for path in config.get("library_dirs", [])]
    arguments += [f'"{path}"' for path in objects] + config["libraries"]
    report["import_libraries"] = []
    for definition in config.get("import_definitions", []):
        definition = repo_path(definition)
        library = output / (definition.stem + ".lib")
        command = [str(repo_path(toolchain["compiler"]["link"]).with_name("LIB.EXE")),
                   "/NOLOGO", "/MACHINE:IX86", f"/DEF:{definition}", f"/OUT:{library}"]
        result = run_command(command, output, toolchain)
        report["import_libraries"].append(dict(command=command, returncode=result.returncode,
                                              stdout=result.stdout, stderr=result.stderr))
        arguments.append(f'"{library}"')
    assets = output / "assets"
    icons = [extract_icon(repo_path(icon["source"]), icon["group"], assets / icon["file"], icon["sha256"])
             for icon in config["icons"]]
    script = repo_path(config["resource_script"])
    resource = output / (script.stem + ".res")
    report["resources"] = dict(compile_resources(
        repo_path(toolchain["compiler"]["rc"]), script, assets, resource, tool_env(toolchain)), icons=icons)
    if report["resources"]["compiled"]:
        arguments.append(f'"{resource}"')
    response.write_text("\n".join(arguments) + "\n", encoding="ascii")
    # Even with compiler failures, collect a diagnostic link report. Never call
    # such an image a complete build.
    command = [str(repo_path(toolchain["compiler"]["link"])), f"@{response}", "/VERBOSE"]
    result = run_command(command, output, toolchain)
    text = result.stdout + result.stderr
    (output / "link.log").write_text(text, encoding="utf-8")
    report["link"] = dict(command=command, returncode=result.returncode,
                          **link_diagnostics(text))
    report["linked"] = (result.returncode == 0 and exe.is_file()
                        and all(row["compiled"] for row in report["sources"])
                        and all(row["compiled"] for row in report["assembly_sources"])
                        and report["resources"]["compiled"]
                        and all(row["returncode"] == 0 for row in report["import_libraries"]))
    report["summary"] = {
        "source_count": len(plan),
        "compiled_count": sum(row["compiled"] for row in report["sources"]),
        "assembly_source_count": len(report["assembly_sources"]),
        "assembled_count": sum(row["compiled"] for row in report["assembly_sources"]),
        "unresolved_symbol_count": len(report["link"]["unresolved"]),
        "link_error_count": len(report["link"]["errors"]),
        "linked": report["linked"],
    }
    report['artifact_sha256'] = {path.name: digest(path) for path in
                                 [*objects, exe, output / 'empiresx.map', output / 'link.log'] if path.is_file()}
    (output / "report.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report["summary"], indent=2))
    print(f"Report: {output / 'report.json'}")
    return 0 if report["linked"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
