"""
Auto-match tool for small VC5 functions.

Generates C/C++ source from asm patterns, compiles, and promotes exact matches.
Handles the most common patterns found in the AOE1 decompilation corpus.
"""
import csv
import re
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
TOOLS_DIR = REPO_ROOT / "tools"
SCRATCH_DIR = REPO_ROOT / "src" / "scratch"
MATCHING_DIR = REPO_ROOT / "src" / "matching"

sys.path.insert(0, str(TOOLS_DIR))
from common import load_toolchain, repo_path, tool_env, ensure_build_subdir


def get_function_packet(va):
    """Read function packet from inventory."""
    p = REPO_ROOT / "inventory" / "functions" / va[:4]
    matches = list(p.glob(f"{va}_*.txt"))
    if not matches:
        return None
    return matches[0].read_text(encoding="utf-8", errors="replace")


def parse_asm(content):
    """Extract instructions from OriginalAsm section."""
    m = re.search(r'=== OriginalAsm ===(.*?)(?:===|\$)', content, re.DOTALL)
    if not m:
        return []
    asm = m.group(1)
    instrs = []
    for line in asm.strip().split("\n"):
        line = line.split(";", 1)[0].strip()
        if not line or re.match(r'^[0-9A-Fa-f]{8}-[0-9A-Fa-f]{8}$', line):
            continue
        parts = line.split()
        if len(parts) >= 3 and all(c in "0123456789abcdef" for c in parts[1].lower()):
            instrs.append(" ".join(parts[2:]))
    return instrs


def classify_pattern(instrs, size, conv, name):
    """Classify into known pattern categories."""
    joined = " ".join(instrs)
    
    # void __thiscall with just `ret`
    if instrs == ["ret"]:
        return "void_ret"
    
    # int __thiscall with `xor eax,eax; ret`  
    if instrs == ["xor eax,eax", "ret"]:
        return "return_zero"
    
    # mov eax, 1; ret
    if re.match(r'mov eax,1h?$', instrs[0]) and instrs[-1] == "ret":
        return "return_one"
    
    # mov eax, CONSTANT; ret
    if re.match(r'mov eax,[0-9A-Fa-f]+h?$', instrs[0]) and instrs[-1] == "ret":
        return "return_constant"
    
    # Simple accessor: mov eax,[ecx+OFFSET]; ret
    if (re.match(r'mov eax,\[ecx\+[0-9A-Fa-f]+h?\]$', instrs[0]) and 
        instrs[-1] == "ret" and len(instrs) == 2):
        m = re.search(r'mov eax,\[ecx\+([0-9A-Fa-f]+)h?\]', instrs[0])
        return ("accessor", int(m.group(1), 16))
    
    # Simple mutator: mov [ecx+OFFSET],edi/something; ret
    if (re.match(r'mov \[ecx\+[0-9A-Fa-f]+h?\],\w+$', instrs[0]) and 
        instrs[-1] == "ret" and len(instrs) == 2):
        m = re.search(r'mov \[ecx\+([0-9A-Fa-f]+)h?\],', instrs[0])
        return ("mutator", int(m.group(1), 16))
    
    # Two-field accessor: mov eax, [ecx+OFF]; mov edx, [ecx+OFF2]; ... ret
    # (e.g., returning a struct or pair)
    
    return None


def generate_source(va, pattern, info, content):
    """Generate C/C++ source for a function pattern."""
    # Get function metadata
    name_m = re.search(r'Name: (\w+)', content)
    name = name_m.group(1) if name_m else "FUNC"
    conv_m = re.search(r'CallingConvention: (\S+)', content)
    conv = conv_m.group(1) if conv_m else "__thiscall"
    src_m = re.search(r'PdbSourceFile: (\S+)', content)
    src_file = src_m.group(1) if src_m else "unknown"
    
    # Get the class name from Ghidra listing
    ghidra = content.split("=== GhidraListingExcerpt ===\n")
    class_name = None
    if len(ghidra) > 1:
        m = re.search(r'(\w+)::' + re.escape(name), ghidra[1])
        if m:
            class_name = m.group(1)
    
    if isinstance(pattern, str):
        if pattern == "void_ret":
            if class_name:
                return f"class {class_name} {{ public: void {name}(); }};\nvoid {class_name}::{name}() {{}}\n"
            elif conv == "__thiscall":
                return f"class SomeClass {{ public: void {name}(); }};\nvoid SomeClass::{name}() {{}}\n"
            else:
                return f"void {name}() {{}}\n"
        
        elif pattern == "return_zero":
            if class_name:
                return f"class {class_name} {{ public: int {name}(); }};\nint {class_name}::{name}() {{ return 0; }}\n"
            elif conv == "__thiscall":
                return f"class SomeClass {{ public: int {name}(); }};\nint SomeClass::{name}() {{ return 0; }}\n"
            else:
                return f"int {name}() {{ return 0; }}\n"
        
        elif pattern == "return_one":
            if class_name:
                return f"class {class_name} {{ public: int {name}(); }};\nint {class_name}::{name}() {{ return 1; }}\n"
            elif conv == "__thiscall":
                return f"class SomeClass {{ public: int {name}(); }};\nint SomeClass::{name}() {{ return 1; }}\n"
            else:
                return f"int {name}() {{ return 1; }}\n"
        
        elif pattern == "return_constant":
            # Extract the constant
            instrs = parse_asm(content)
            m = re.match(r'mov eax,([0-9A-Fa-f]+)h?$', instrs[0])
            val = int(m.group(1), 16) if m else 0
            if class_name:
                return f"class {class_name} {{ public: int {name}(); }};\nint {class_name}::{name}() {{ return {val}; }}\n"
            elif conv == "__thiscall":
                return f"class SomeClass {{ public: int {name}(); }};\nint SomeClass::{name}() {{ return {val}; }}\n"
            else:
                return f"int {name}() {{ return {val}; }}\n"
    
    elif isinstance(pattern, tuple):
        ptype, offset = pattern
        if ptype == "accessor":
            if class_name:
                return f"class {class_name} {{ public:\n    char gap_00[{hex(offset)}];\n    int field_{hex(offset)};\n    int {name}();\n}};\nint {class_name}::{name}() {{ return this->field_{hex(offset)}; }}\n"
            elif conv == "__thiscall":
                return f"class SomeClass {{ public:\n    char gap_00[{hex(offset)}];\n    int field_{hex(offset)};\n    int {name}();\n}};\nint SomeClass::{name}() {{ return this->field_{hex(offset)}; }}\n"
            else:
                return None  # Non-thiscall accessors need more info
        
        elif ptype == "mutator":
            if class_name:
                return f"class {class_name} {{ public:\n    char gap_00[{hex(offset)}];\n    int field_{hex(offset)};\n    void {name}(int val);\n}};\nvoid {class_name}::{name}(int val) {{ this->field_{hex(offset)} = val; }}\n"
            elif conv == "__thiscall":
                return f"class SomeClass {{ public:\n    char gap_00[{hex(offset)}];\n    int field_{hex(offset)};\n    void {name}(int val);\n}};\nvoid SomeClass::{name}(int val) {{ this->field_{hex(offset)} = val; }}\n"
            else:
                return None
    
    return None


def check_function(va):
    """Compile and compare."""
    result = subprocess.run(
        [sys.executable, str(TOOLS_DIR / "check_function.py"), "--va", va, "--no-history"],
        capture_output=True, text=True, timeout=30
    )
    return result.returncode == 0, result.stdout


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--dry-run", action="store_true")
    parser.add_argument("--limit", type=int, default=0)
    parser.add_argument("--min-size", type=int, default=1)
    parser.add_argument("--max-size", type=int, default=30)
    parser.add_argument("--verbose", action="store_true")
    args = parser.parse_args()
    
    # Load remaining functions
    with open(REPO_ROOT / "project_full_status.csv", encoding="utf-8", errors="replace") as f:
        rows = list(csv.DictReader(f))
    
    remaining = [r for r in rows if r.get("is_remaining") == "yes"]
    print(f"Total remaining: {len(remaining)}")
    
    matched = 0
    failed = 0
    skipped = 0
    
    for r in sorted(remaining, key=lambda x: int(x["size_bytes"])):
        va = r["va"]
        size = int(r["size_bytes"])
        
        if size < args.min_size or size > args.max_size:
            continue
        if args.limit and (matched + failed + skipped) >= args.limit:
            break
        
        # Skip if already processed
        slug_base = va
        if any((SCRATCH_DIR / f).exists() for f in SCRATCH_DIR.glob(f"{va}_*.cpp")):
            skipped += 1
            continue
        if any((MATCHING_DIR / f).exists() for f in MATCHING_DIR.glob(f"{va}_*.cpp")):
            skipped += 1
            continue
        
        content = get_function_packet(va)
        if not content:
            skipped += 1
            continue
        
        instrs = parse_asm(content)
        if not instrs:
            skipped += 1
            continue
        
        # Skip functions with absolute memory/call/jump references
        joined = ' '.join(instrs)
        if re.search(r'\[[0-9A-Fa-f]{6,8}h?\]', joined):
            if args.verbose: print(f'  X {va} {r["name"]} - abs mem ref')
            skipped += 1
            continue
        if re.search(r'(?<!^)call\s+[0-9A-Fa-f]{4,8}h?', joined):
            if args.verbose: print(f'  X {va} {r["name"]} - direct call')
            skipped += 1
            continue
        
        pattern = classify_pattern(instrs, size, r["calling_convention"], r["name"])
        if pattern is None:
            if args.verbose:
                print(f"  ? {va} {r['name']} ({size}B) - unsupported pattern: {' '.join(instrs[:3])}")
            skipped += 1
            continue
        
        source = generate_source(va, pattern, None, content)
        if source is None:
            skipped += 1
            continue
        
        slug = f"{va}_{re.sub(r'[^a-zA-Z0-9]', '_', r['name']).strip('_')}".rstrip('_')
        if not slug.endswith('.cpp'):
            slug += '.cpp'
        
        scratch_path = SCRATCH_DIR / slug
        
        if args.dry_run:
            print(f"\n[DRY-RUN] {va} {r['name']} ({size}B, {pattern})")
            print(source)
            continue
        
        # Write source
        scratch_path.write_text(source, encoding="utf-8")
        
        # Compile and check
        ok, output = check_function(va)
        
        if ok:
            # Move to matching
            matching_path = MATCHING_DIR / slug
            scratch_path.rename(matching_path)
            print(f"  [MATCH] {va} {r['name']} ({size}B, {pattern}) -> {matching_path.name}")
            matched += 1
        else:
            print(f"  [FAIL] {va} {r['name']} ({size}B, {pattern}) - kept in scratch")
            if args.verbose:
                # Show first mismatch
                for line in output.split("\n"):
                    if "Result:" in line:
                        print(f"    {line.strip()}")
            failed += 1
    
    print(f"\n=== RESULTS ===")
    print(f"  Matched: {matched}")
    print(f"  Failed:  {failed}")
    print(f"  Skipped: {skipped}")


if __name__ == "__main__":
    main()
