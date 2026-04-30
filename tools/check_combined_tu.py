"""
Check functions using combined TU compilation.

Usage: python check_combined_tu.py --source-file aiuaimod.cpp --va 00413AB0

Compiles ALL functions from the same source file together,
then checks the specified function against the original binary.
"""
import csv, re, subprocess, sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
TOOLS_DIR = REPO_ROOT / "tools"
BUILD_DIR = REPO_ROOT / "build"

sys.path.insert(0, str(TOOLS_DIR))
from common import load_toolchain, repo_path, tool_env, ensure_build_subdir, REPO_ROOT as COMMON_ROOT
from extract_original_function import extract_original
from extract_obj_function import extract_from_obj
from diff_function import diff_functions


def extract_original_function(va: str) -> bytes:
    """Extract function bytes from original EXE."""
    result = subprocess.run(
        [sys.executable, str(TOOLS_DIR / "extract_original_function.py"), "--va", va],
        capture_output=True, text=True
    )
    if result.returncode != 0:
        print(f"extract_original failed for {va}: {result.stderr}")
        return None
    out_path = BUILD_DIR / "orig" / f"{va}.bin"
    return out_path.read_bytes() if out_path.exists() else None


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--source-file", required=True, help="PDB source file name")
    parser.add_argument("--va", required=True, help="Function VA to check")
    args = parser.parse_args()
    
    # Find all functions from this source file
    functions = get_functions_for_source_file(args.source_file)
    print(f"Found {len(functions)} functions from {args.source_file}")
    
    # Build the combined TU
    output = BUILD_DIR / "temp" / f"combined_check_{args.source_file.replace('.cpp','')}.cpp"
    count = build_combined_tu(args.source_file, output, functions)
    print(f"Built combined TU: {count} functions")
    
    # Compile
    toolchain = load_toolchain()
    cl_path = repo_path(toolchain["compiler"]["cl"])
    env = tool_env(toolchain)
    obj_path = ensure_build_subdir("obj") / f"combined_check_{args.source_file.replace('.cpp','')}.obj"
    
    with open(REPO_ROOT / "config" / "flags" / "default.rsp") as f:
        flags = [l.strip() for l in f.read().split() if l.strip()]
    
    result = subprocess.run(
        [str(cl_path)] + flags + ["/GX", f"/Fo{obj_path}", str(output)],
        capture_output=True, text=True, env=env
    )
    
    if result.returncode != 0:
        print(f"Compilation failed:")
        for line in result.stdout.split("\n")[-20:]:
            if "error" in line.lower():
                print(f"  {line}")
        return
    
    print(f"Compilation succeeded: {obj_path}")
    print()
    
    # Extract and diff the specified function
    va = args.va
    original = extract_original_function(va)
    if not original:
        print(f"Failed to extract original function at {va}")
        return
    
    rebuilt = extract_from_obj(va, obj_path)
    if not rebuilt:
        print(f"Failed to extract rebuilt function at {va} from combined obj")
        return
    
    diff_functions(va, original, rebuilt)


def get_functions_for_source_file(source_file):
    """Get all functions from a specific source file."""
    with open(REPO_ROOT / "project_full_status.csv", encoding="utf-8", errors="replace") as f:
        rows = list(csv.DictReader(f))
    
    funcs = []
    for r in rows:
        if r.get("pdb_source_file", "").lower() == source_file.lower():
            funcs.append(r)
    return funcs


def build_combined_tu(source_file, output_path, functions):
    """Build combined TU from individual function files."""
    lines = [
        f'// Combined TU for {source_file}',
        f'#include "include/unit_ai_module.h"',
        ''
    ]
    
    for r in sorted(functions, key=lambda x: int(x["size_bytes"])):
        va = r["va"]
        name = r["name"]
        size = r["size_bytes"]
        bucket = r.get("source_bucket", "?")
        
        # Find source file
        src_path = None
        for d in [TOOLS_DIR.parent / "src/scratch", TOOLS_DIR.parent / "src/matching", TOOLS_DIR.parent / "src/accepted_drift"]:
            matches = list(d.glob(f"{va}_*.cpp"))
            if matches:
                src_path = matches[0]
                break
        
        if not src_path or not src_path.exists():
            lines.append(f'\n// --- {va} {name} ({size}B, {bucket}) - NO SOURCE ---')
            continue
        
        content = src_path.read_text()
        # Remove #include and standalone class definitions
        content = re.sub(r'#include.*', '', content)
        content = re.sub(r'class\s+\w+\s*\{[^}]*\};', '', content, flags=re.DOTALL)
        
        lines.append(f'\n// --- {va} {name} ({size}B, {bucket}) ---')
        lines.append(content.strip())
    
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("\n".join(lines))
    return len(functions)


if __name__ == "__main__":
    main()
