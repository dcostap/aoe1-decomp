"""
Batch generator for small automatable functions.

Generates source files in src/scratch/, compiles them, and verifies match.
Successfully matching functions are promoted to src/matching/.

Categories handled:
1. Scalar deleting destructors (30 bytes)
2. Vector deleting destructors (30 bytes)
3. JMP thunks (5 bytes) - destructor inheritance
4. Simple return-constant/void functions
"""
import csv
import glob
import json
import os
import re
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
TOOLS_DIR = REPO_ROOT / "tools"
SCRATCH_DIR = REPO_ROOT / "src" / "scratch"
MATCHING_DIR = REPO_ROOT / "src" / "matching"
ACCEPTED_DRIFT_DIR = REPO_ROOT / "src" / "accepted_drift"


def load_all_functions():
    with open(REPO_ROOT / 'project_full_status.csv', 'r') as f:
        return list(csv.DictReader(f))


def load_funcs_by_va(rows):
    return {r['va'].upper(): r for r in rows}


def parse_asm_from_packet(content):
    """Extract instructions from packet OriginalAsm section."""
    if '=== OriginalAsm ===' not in content:
        return []
    asm_section = content.split('=== OriginalAsm ===')[1]
    if '===' in asm_section:
        asm_section = asm_section.split('===')[0]
    
    instrs = []
    for line in asm_section.strip().split('\n'):
        line = line.split(';', 1)[0].strip()
        if not line or re.match(r'^[0-9A-Fa-f]{8}-[0-9A-Fa-f]{8}$', line):
            continue
        parts = line.split()
        if len(parts) < 3:
            continue
        # parts[0] = address, parts[1] = hex bytes, parts[2:] = mnemonic + operands
        hex_blob = parts[1]
        if all(c in '0123456789abcdef' for c in hex_blob.lower()):
            if len(parts) > 2:
                instr = ' '.join(parts[2:])
                instrs.append(instr)
    return instrs


def read_packet(va):
    prefix = va[:4]
    matches = glob.glob(str(REPO_ROOT / f'inventory/functions/{prefix}/{va}*'))
    if not matches:
        return None
    with open(matches[0], 'r') as f:
        return f.read()


def extract_class_name(content):
    """Extract class name from Ghidra listing."""
    ghidra = content.split('=== GhidraListingExcerpt ===')[1] if '=== GhidraListingExcerpt ===' in content else ''
    m = re.search(r'(\w+)::`(?:scalar|vector) deleting destructor', ghidra)
    if m:
        return m.group(1)
    # Try alternative pattern
    m = re.search(r'__thiscall\s+`(?:scalar|vector)_deleting_destructor.\((\w+)', ghidra)
    return m.group(1) if m else None


def extract_dtor_call_target(content):
    """Extract the destroy call target VA from the asm."""
    asm = content.split('=== OriginalAsm ===')[1].split('===')[0]
    asm = re.sub(r'\s*;.*$', '', asm, flags=re.MULTILINE)
    m = re.search(r'call\s+([0-9A-Fa-f]+)h', asm)
    return m.group(1).upper() if m else None


def slugify(name):
    result = []
    for ch in name:
        if ch.isalnum():
            result.append(ch)
        else:
            result.append('_')
    slug = ''.join(result).strip('_')
    while '__' in slug:
        slug = slug.replace('__', '_')
    return slug or 'unnamed'


def function_slug(va, name):
    return f"{va}_{slugify(name)}"


def check_function(va):
    """Run the check pipeline, return True if match."""
    result = subprocess.run(
        [sys.executable, str(TOOLS_DIR / 'check_function.py'), '--va', va],
        capture_output=True, text=True
    )
    return result.returncode == 0


def generate_deleting_dtor(va, record, funcs_by_va, content):
    """Generate source for a scalar or vector deleting destructor."""
    class_name = extract_class_name(content)
    if not class_name:
        return None, "Could not extract class name"
    
    destroy_target = extract_dtor_call_target(content)
    if not destroy_target:
        return None, "Could not extract destroy call target"
    
    destroy_rec = funcs_by_va.get(destroy_target)
    destroy_name = destroy_rec['name'] if destroy_rec else None
    if not destroy_name:
        return None, f"Unknown destroy target {destroy_target}"
    
    is_scalar = 'scalar' in record['name']
    dtor_kind = 'scalar_deleting_destructor' if is_scalar else 'vector_deleting_destructor'
    
    # The destroy function is a destructor, but we use a plain method name
    # to avoid C++ destructor semantics
    method_name = 'destroy'
    
    source = f"""class {class_name} {{
public:
    void {method_name}(void);
    void *{dtor_kind}(unsigned int param_1);
}};

void operator_delete(void *param_1);

void *{class_name}::{dtor_kind}(unsigned int param_1) {{
    this->{method_name}();
    if ((param_1 & 1) != 0) {{
        operator_delete(this);
    }}
    return this;
}}
"""
    return source, None


def generate_jmp_thunk(va, record, funcs_by_va, content):
    """Generate source for a JMP thunk destructor."""
    # These are destructors that just jump to their parent's destructor
    # The class name comes from Ghidra
    ghidra = content.split('=== GhidraListingExcerpt ===')[1] if '=== GhidraListingExcerpt ===' in content else ''
    
    # Extract class name from mangled symbol or ghidra annotation
    name = record['name']  # e.g., ~TRIBE_Action_Build
    if name.startswith('~'):
        class_name = name[1:]
    else:
        return None, f"Not a destructor JMP thunk: {name}"
    
    # Extract target VA
    instrs = parse_asm_from_packet(content)
    if len(instrs) != 1 or not instrs[0].startswith('jmp '):
        return None, "Not a simple JMP thunk"
    
    target_va = instrs[0].split('jmp ')[1].replace('h', '').strip().upper().zfill(8)
    target_rec = funcs_by_va.get(target_va)
    if not target_rec:
        return None, f"Unknown target {target_va}"
    
    target_name = target_rec['name']
    # Target should be a destructor
    if target_name.startswith('~'):
        parent_class = target_name[1:]
    else:
        return None, f"Target {target_va} ({target_name}) doesn't look like a destructor"
    
    # Generate: class ParentClass { public: ~ParentClass(); };
    # class ChildClass : public ParentClass { public: ~ChildClass(); };
    # ChildClass::~ChildClass() {}
    # This should generate: jmp ParentClass::~ParentClass
    # 
    # But wait - VC5 won't necessarily generate a jmp thunk for an empty destructor.
    # The original code generates this because the destructor is virtual and the child
    # has no extra cleanup. Let me check what pattern works.
    
    # Generate a simple tail-call method that compiles to jmp
    source = f"""class {class_name} {{
public:
    void parent_destroy();
    void destroy();
}};

void {class_name}::destroy() {{
    this->parent_destroy();
}}
"""
    return source, None


def generate_simple_return(va, record, funcs_by_va, content):
    """Generate source for simple return-value functions."""
    instrs = parse_asm_from_packet(content)
    name = record['name']
    conv = record['calling_convention']
    
    if instrs == ['ret']:
        # void function, no args
        if conv == '__cdecl' or conv == 'unknown':
            source = f"void {name}(void) {{}}\n"
            return source, None
    
    if len(instrs) == 2 and instrs[1] == 'ret':
        if instrs[0] == 'xor eax,eax':
            source = f"int {name}(void) {{ return 0; }}\n"
            return source, None
        
        m = re.match(r'mov eax,([0-9A-Fa-f]+)h?$', instrs[0])
        if m:
            val = int(m.group(1), 16)
            # Check if the function has parameters from Ghidra
            ghidra = content.split('=== GhidraListingExcerpt ===')[1] if '=== GhidraListingExcerpt ===' in content else ''
            
            # Look for parameter info
            params = re.findall(r'Stack\[0x[0-9a-fA-F]+\]:\d+\s+(\w+)', ghidra)
            
            if conv == '__cdecl':
                param_str = ', '.join(f'int {p}' for p in params) if params else 'void'
                source = f"int __cdecl {name}({param_str}) {{ return {val}; }}\n"
                return source, None
            else:
                source = f"int {name}(void) {{ return {val}; }}\n"
                return source, None
    
    return None, "Could not generate simple return"


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--dry-run', action='store_true', help='Generate but do not compile/verify')
    parser.add_argument('--category', choices=['dtor', 'jmp', 'ret', 'all'], default='all')
    parser.add_argument('--limit', type=int, default=0, help='Max functions to process (0=all)')
    args = parser.parse_args()
    
    rows = load_all_functions()
    funcs_by_va = load_funcs_by_va(rows)
    
    remaining = [r for r in rows if r['is_remaining'] == 'yes']
    
    results = {'matched': 0, 'failed': 0, 'skipped': 0, 'error': 0}
    matched_list = []
    failed_list = []
    
    count = 0
    
    for r in sorted(remaining, key=lambda x: int(x['size_bytes'])):
        if args.limit and count >= args.limit:
            break
        
        va = r['va']
        name = r['name']
        size = int(r['size_bytes'])
        
        content = read_packet(va)
        if not content:
            continue
        
        source = None
        error = None
        category = None
        
        # Try deleting destructors
        if 'deleting_destructor' in name and size == 30:
            if args.category in ('dtor', 'all'):
                source, error = generate_deleting_dtor(va, r, funcs_by_va, content)
                category = 'dtor'
        
        # Try JMP thunks
        elif size == 5 and r['calling_convention'] == '__thiscall':
            instrs = parse_asm_from_packet(content)
            if len(instrs) == 1 and instrs[0].startswith('jmp ') and '[' not in instrs[0]:
                if args.category in ('jmp', 'all'):
                    source, error = generate_jmp_thunk(va, r, funcs_by_va, content)
                    category = 'jmp'
        
        # Try simple returns
        elif size <= 6:
            instrs = parse_asm_from_packet(content)
            if instrs == ['ret'] or (len(instrs) == 2 and instrs[1] == 'ret'):
                if args.category in ('ret', 'all'):
                    source, error = generate_simple_return(va, r, funcs_by_va, content)
                    category = 'ret'
        
        if source is None:
            if error and category:
                print(f"  SKIP {va} {name}: {error}")
                results['skipped'] += 1
            continue
        
        count += 1
        slug = function_slug(va, name)
        scratch_path = SCRATCH_DIR / f"{slug}.cpp"
        accepted_drift_path = ACCEPTED_DRIFT_DIR / f"{slug}.cpp"
        if accepted_drift_path.exists():
            print(f"[skip] {va} already in accepted_drift")
            results['skipped'] += 1
            continue
        
        print(f"\n[{category}] {va} {name} ({size}B)")
        
        if args.dry_run:
            print(f"  Would write: {scratch_path}")
            print(f"  Source:\n{source}")
            results['matched'] += 1
            continue
        
        # Write source
        scratch_path.write_text(source, encoding='utf-8')
        print(f"  Wrote {scratch_path}")
        
        # Check
        if check_function(va):
            print(f"  OK MATCH!")
            # Move to matching
            matching_path = MATCHING_DIR / f"{slug}.cpp"
            if matching_path.exists():
                scratch_path.unlink()
                print(f"  Already in matching: {matching_path}")
            else:
                scratch_path.rename(matching_path)
            print(f"  Promoted to {matching_path}")
            results['matched'] += 1
            matched_list.append(f"{va} {name}")
        else:
            print(f"  XX MISMATCH")
            results['failed'] += 1
            failed_list.append(f"{va} {name}")
            # Keep in scratch for manual investigation
    
    print(f"\n{'='*60}")
    print(f"RESULTS")
    print(f"{'='*60}")
    print(f"  Matched:  {results['matched']}")
    print(f"  Failed:   {results['failed']}")
    print(f"  Skipped:  {results['skipped']}")
    
    if matched_list:
        print(f"\nMatched functions:")
        for m in matched_list:
            print(f"  OK {m}")
    
    if failed_list:
        print(f"\nFailed functions:")
        for f in failed_list:
            print(f"  XX {f}")


if __name__ == '__main__':
    main()
