"""
Comprehensive auto-matching for small VC5 functions.
Handles ALL simple patterns found in the AOE1 corpus.
"""
import csv, re, subprocess, sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
TOOLS_DIR = REPO_ROOT / "tools"
SCRATCH_DIR = REPO_ROOT / "src" / "scratch"
MATCHING_DIR = REPO_ROOT / "src" / "matching"

sys.path.insert(0, str(TOOLS_DIR))
from common import load_toolchain, repo_path


def extract_asm(content):
    """Get clean instruction list from packet."""
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


def extract_offsets(instr_text):
    """Extract hex offsets from [ecx+OFF] patterns."""
    return [int(m.group(1), 16) for m in re.finditer(r'\[ecx\+([0-9A-Fa-f]+)h?\]', instr_text)]


def has_abs_refs(instrs):
    """Check if asm has absolute memory references or direct calls."""
    joined = " ".join(instrs)
    if re.search(r'\[[0-9A-Fa-f]{6,8}h?\]', joined):
        return True
    if re.search(r'(?<!^)call\s+[0-9A-Fa-f]{4,8}h?', joined):
        return True
    return False


def is_ret(i):
    """Check if i is a return instruction of any form."""
    return i == "ret" or re.match(r'ret\s+', i)


def get_meta(content):
    nm = re.search(r'Name: (\w+)', content)
    name = nm.group(1) if nm else "FUNC"
    cc = re.search(r'CallingConvention: (\S+)', content)
    conv = cc.group(1) if cc else "__thiscall"
    ghidra = content.split("=== GhidraListingExcerpt ===\n")
    class_name = None
    if len(ghidra) > 1:
        m = re.search(r'(\w+)::' + re.escape(name), ghidra[1])
        if m:
            class_name = m.group(1)
    return name, conv, class_name


def make_source(name, conv, class_name, pattern_type, offsets):
    """Generate C/C++ source code."""
    cls = class_name if class_name else "__Unk"
    
    if pattern_type in ("void_ret",):
        if conv == "__thiscall":
            return f"class {cls} {{ public: void {name}(); }};\nvoid {cls}::{name}() {{}}\n"
        return f"void {name}() {{}}\n"
    
    if pattern_type in ("ret0",):
        if conv == "__thiscall":
            return f"class {cls} {{ public: int {name}(); }};\nint {cls}::{name}() {{ return 0; }}\n"
        return f"int {name}() {{ return 0; }}\n"
    
    if pattern_type in ("ret1",):
        if conv == "__thiscall":
            return f"class {cls} {{ public: int {name}(); }};\nint {cls}::{name}() {{ return 1; }}\n"
        return f"int {name}() {{ return 1; }}\n"
    
    if pattern_type in ("retm1",):
        if conv == "__thiscall":
            return f"class {cls} {{ public: int {name}(); }};\nint {cls}::{name}() {{ return -1; }}\n"
        return f"int {name}() {{ return -1; }}\n"
    
    if pattern_type == "accessor_i32" and len(offsets) == 1:
        off = offsets[0]
        if conv == "__thiscall":
            return f"class {cls} {{ public:\n    int {name}();\n}};\nint {cls}::{name}() {{ return *(int*)((char*)this + {hex(off)}); }}\n"
        return f"int __cdecl {name}() {{ return 0; }}\n"
    
    if pattern_type == "accessor_u8" and len(offsets) == 1:
        off = offsets[0]
        if conv == "__thiscall":
            return f"class {cls} {{ public:\n    int {name}();\n}};\nint {cls}::{name}() {{ return *(unsigned char*)((char*)this + {hex(off)}); }}\n"
    
    if pattern_type == "accessor_s8" and len(offsets) == 1:
        off = offsets[0]
        if conv == "__thiscall":
            return f"class {cls} {{ public:\n    int {name}();\n}};\nint {cls}::{name}() {{ return *(signed char*)((char*)this + {hex(off)}); }}\n"
    
    if pattern_type == "mutator_i32" and len(offsets) == 1:
        off = offsets[0]
        if conv == "__thiscall":
            return f"class {cls} {{ public:\n    void {name}(int val);\n}};\nvoid {cls}::{name}(int val) {{ *(int*)((char*)this + {hex(off)}) = val; }}\n"
    
    if pattern_type == "clear_i32" and len(offsets) == 1:
        off = offsets[0]
        if conv == "__thiscall":
            return f"class {cls} {{ public:\n    void {name}();\n}};\nvoid {cls}::{name}() {{ *(int*)((char*)this + {hex(off)}) = 0; }}\n"
    
    return None


def classify(instrs):
    """Classify asm instruction sequence into a known pattern."""
    if not instrs:
        return None, None
    
    last = instrs[-1]
    
    # Check if last instruction is a ret
    if not is_ret(last):
        return None, None
    
    n = len(instrs)
    
    # Single instruction: `ret` or `ret 4`
    if n == 1:
        return "void_ret", []
    
    # Two instructions: one operation + ret
    if n == 2:
        op = instrs[0]
        
        # return 0
        if op == "xor eax,eax":
            return "ret0", []
        
        # return 1
        if re.match(r'mov\s+eax,\s*1\s*$', op):
            return "ret1", []
        
        # return -1
        if re.match(r'mov\s+eax,\s*-1\s*$', op):
            return "retm1", []
        
        # return CONSTANT
        m = re.match(r'mov\s+eax,\s*([0-9A-Fa-f]+)h?\s*$', op)
        if m:
            val = int(m.group(1), 16)
            if val == 1:
                return "ret1", []
            if val == 0:
                return "ret0", []
            if val == 0xFFFFFFFF or val == 0xFFFF:
                return "retm1", []
            return "ret1", []
        
        # accessor: mov eax,[ecx+OFF]
        if op.startswith("mov eax,[ecx+"):
            offs = extract_offsets(op)
            if len(offs) == 1:
                return "accessor_i32", offs
        
        # mutator: mov [ecx+OFF],eax
        if op.startswith("mov [ecx+") and re.search(r',eax\s*$', op):
            offs = extract_offsets(op)
            if len(offs) == 1:
                return "mutator_i32", offs
        
        # clear field: mov [ecx+OFF],0
        if op.startswith("mov [ecx+") and re.search(r',0\s*$', op):
            offs = extract_offsets(op)
            if len(offs) == 1:
                return "clear_i32", offs
        
        # movzx eax,byte ptr [ecx+OFF]
        if "movzx" in op and re.search(r'\[ecx\+', op):
            offs = extract_offsets(op)
            if len(offs) == 1:
                return "accessor_u8", offs
        
        # movsx eax,byte ptr [ecx+OFF]
        if "movsx" in op and re.search(r'\[ecx\+', op):
            offs = extract_offsets(op)
            if len(offs) == 1:
                return "accessor_s8", offs
    
    return None, None


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--max-size", type=int, default=20)
    parser.add_argument("--verbose", action="store_true")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()
    
    with open(REPO_ROOT / "project_full_status.csv", encoding="utf-8", errors="replace") as f:
        rows = list(csv.DictReader(f))
    
    remaining = [r for r in rows if r.get("is_remaining") == "yes"]
    remaining.sort(key=lambda x: int(x["size_bytes"]))
    
    matched, failed, skipped = 0, 0, 0
    already_has = set()
    for d in [MATCHING_DIR, SCRATCH_DIR, REPO_ROOT / "src/accepted_drift", REPO_ROOT / "src/verified_logic"]:
        if d.exists():
            for f in d.glob("0*.cpp"):
                already_has.add(f.name.split("_")[0])
    
    for r in remaining:
        va = r["va"]
        size = int(r["size_bytes"])
        if size > args.max_size:
            continue
        if va in already_has:
            continue
        if r.get("corpus_bucket") != "normal":
            continue
        
        p = REPO_ROOT / "inventory" / "functions" / va[:4]
        matches = list(p.glob(f"{va}_*.txt"))
        if not matches:
            skipped += 1
            continue
        content = matches[0].read_text(encoding="utf-8", errors="replace")
        
        instrs = extract_asm(content)
        if not instrs:
            skipped += 1
            continue
        
        if has_abs_refs(instrs):
            if args.verbose:
                print(f"  X {va} {r['name']} - abs refs")
            skipped += 1
            continue
        
        pattern_type, offsets = classify(instrs)
        if not pattern_type:
            if args.verbose:
                print(f"  ? {va} {r['name']} ({size}B) - unknown pattern: {' '.join(instrs[:3])}")
            skipped += 1
            continue
        
        name, conv, class_name = get_meta(content)
        source = make_source(name, conv, class_name, pattern_type, offsets)
        if not source:
            skipped += 1
            continue
        
        slug = f"{va}_{name}".replace("?", "_")
        scratch_path = SCRATCH_DIR / f"{slug}.cpp"
        
        if args.dry_run:
            print(f"\n[DRY] {va} {name} ({size}B, {pattern_type})")
            print(source)
            continue
        
        scratch_path.write_text(source, encoding="utf-8")
        
        result = subprocess.run(
            [sys.executable, str(TOOLS_DIR / "check_function.py"), "--va", va, "--no-history"],
            capture_output=True, text=True, timeout=30
        )
        
        if result.returncode == 0:
            matching_path = MATCHING_DIR / f"{slug}.cpp"
            scratch_path.rename(matching_path)
            print(f"  [MATCH] {va} {name} ({size}B, {pattern_type}) -> {matching_path.name}")
            matched += 1
        else:
            print(f"  [FAIL] {va} {name} ({size}B, {pattern_type})")
            scratch_path.unlink(missing_ok=True)
            failed += 1
    
    print(f"\n=== RESULTS ===")
    print(f"Matched: {matched}  Failed: {failed}  Skipped: {skipped}")


if __name__ == "__main__":
    main()
