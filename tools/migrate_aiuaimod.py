#!/usr/bin/env python3
"""
Migration script to unify all UnitAIModule source files under the shared header.

1. Scans all 0041*.cpp files for their class definitions
2. Creates the canonical method declarations in include/unit_ai_module.h
3. Rewrites each file to include the shared header instead of defining its own class

Run from repo root: python tools/migrate_aiuaimod.py [--dry-run]
"""
import csv, re, glob, sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
SCRATCH = REPO_ROOT / "src" / "scratch"
MATCHING = REPO_ROOT / "src" / "matching"
ACCEPTED = REPO_ROOT / "src" / "accepted_drift"
HEADER_PATH = REPO_ROOT / "include" / "unit_ai_module.h"


def find_all_unitai_files():
    """Find all files that reference UnitAIModule."""
    files = []
    for d in [SCRATCH, MATCHING, ACCEPTED]:
        for f in sorted(d.glob("0041*.cpp")):
            content = f.read_text(errors="replace")
            if "UnitAIModule" in content:
                files.append((f, content))
    return files


def extract_class_body(content):
    """Extract the UnitAIModule class body from a source file."""
    idx = content.find("class UnitAIModule")
    if idx < 0:
        return None, content
    
    brace = content.find("{", idx)
    if brace < 0:
        return None, content
    
    close = content.find("};", brace)
    if close < 0:
        return None, content
    
    class_body = content[brace+1:close]
    after_class = content[close+2:]
    
    return class_body, after_class


def extract_method_defs(content):
    """Extract all UnitAIModule method definitions."""
    methods = []
    for m in re.finditer(
        r'((?:unsigned\s+)?(?:virtual\s+)?\w[\w\s\*]*)\s+UnitAIModule::(\w+)\s*\(([^)]*)\)\s*{',
        content
    ):
        ret = m.group(1).strip()
        name = m.group(2)
        params = m.group(3).strip()
        
        # Clean up return type
        ret = re.sub(r'\s+', ' ', ret)
        
        # Strip parameter names for declaration
        clean_params = re.sub(r'\bconst\s+', '', params)
        clean_params = re.sub(r'\b(\w[\w\s\*]*)\s+(\w+)\s*$', lambda x: x.group(1).strip() + ' ' + x.group(2), clean_params, flags=re.MULTILINE)
        
        methods.append((ret, name, params))
    
    return methods


def main():
    dry_run = "--dry-run" in sys.argv
    
    files = find_all_unitai_files()
    print(f"Found {len(files)} files referencing UnitAIModule")
    
    # Collect all methods
    all_methods = {}
    field_offsets = {}
    
    for fpath, content in files:
        class_body, after_class = extract_class_body(content)
        if class_body:
            # Extract field info
            for line in class_body.split("\n"):
                line = line.strip()
                if not line or line in ("public:", "private:", "protected:"):
                    continue
                if line.startswith("//") or line.startswith("/*"):
                    continue
                if line.startswith("};"):
                    break
                # Check for offset info
                m = re.search(r'//\s*\+?(0x[0-9A-Fa-f]+|\d+)', line)
                if m:
                    off = m.group(1)
                    if off not in field_offsets:
                        field_offsets[off] = line
        
        # Extract method definitions from after class
        methods = extract_method_defs(after_class)
        for ret, name, params in methods:
            key = f"{name}({params})"
            if key not in all_methods:
                all_methods[key] = (ret, name, params)
    
    print(f"\nUnique methods: {len(all_methods)}")
    print(f"Unique offset references: {len(field_offsets)}")
    
    # Generate method declarations
    decls = []
    for key in sorted(all_methods.keys()):
        ret, name, params = all_methods[key]
        decls.append(f"    {ret} {name}({params});")
    
    print(f"\nWould add {len(decls)} method declarations to header")
    if not dry_run:
        for d in decls[:10]:
            print(f"  {d}")
        print(f"  ... ({len(decls)-10} more)")
    
    # Show files that would be modified
    print(f"\nFiles that would be modified: {len(files)}")
    for fpath, _ in files:
        rel = fpath.relative_to(REPO_ROOT)
        print(f"  {rel}")


if __name__ == "__main__":
    main()
