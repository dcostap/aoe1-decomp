#!/usr/bin/env python3
"""
Add all UnitAIModule method declarations to the shared header.
Updates include/unit_ai_module.h with declarations extracted from existing files.
"""
import re, glob
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

def main():
    # Read existing header
    header_path = REPO_ROOT / "include" / "unit_ai_module.h"
    header = header_path.read_text()
    
    # Collect all unique method signatures
    methods = {}
    for d in [REPO_ROOT / "src/scratch", REPO_ROOT / "src/matching", REPO_ROOT / "src/accepted_drift", REPO_ROOT / "src/verified_logic"]:
        for f in sorted(d.glob("0041*.cpp")):
            content = f.read_text(errors="replace")
            if "UnitAIModule::" not in content:
                continue
            for m in re.finditer(
                r'((?:unsigned\s+)?\w[\w\s\*]*)\s+UnitAIModule::(\w+)\s*\(([^)]*)\)',
                content
            ):
                ret = m.group(1).strip()
                name = m.group(2)
                params = m.group(3).strip()
                key = f"{name}({params})"
                if key not in methods:
                    methods[key] = (ret, name, params)
    
    # Generate sorted declarations
    decl_lines = []
    for key in sorted(methods.keys()):
        ret, name, params = methods[key]
        # Clean up params - remove parameter names, keep types
        # For simplicity, keep as-is (individual files use different names)
        # Just ensure semicolons and line breaks
        decl_lines.append(f"    {ret} {name}({params});")
    
    # Find the insertion point (after the last field, before the closing brace)
    insert_pos = header.rfind("};")
    if insert_pos < 0:
        print("ERROR: Could not find closing brace in header")
        return
    
    # Insert method declarations
    new_header = header[:insert_pos]
    new_header += "\n\n    // Method declarations (auto-generated)\n"
    new_header += "\n".join(decl_lines) + "\n"
    new_header += header[insert_pos:]
    
    header_path.write_text(new_header)
    print(f"Updated header: {len(decl_lines)} method declarations added")


if __name__ == "__main__":
    main()
