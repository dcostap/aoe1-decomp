"""
Scan for functions that can be auto-promoted from accepted_drift to matching
based on diff analysis. Only promotes when positional diff is 0 (exact match)
due to CSV staleness.
"""
import csv, subprocess, sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

def main():
    csv_path = REPO / "project_full_status.csv"
    with open(csv_path, encoding="utf-8", errors="replace") as f:
        rows = list(csv.DictReader(f))
    
    # Find accepted_drift or scratch functions with < 5% positional diff
    candidates = []
    for r in rows:
        if r.get("source_bucket") not in ("accepted_drift", "scratch"):
            continue
        pd = r.get("positional_diff_percent", "")
        if pd and float(pd) < 5 and float(pd) > 0:
            candidates.append(r)
    
    candidates.sort(key=lambda x: float(x["positional_diff_percent"]))
    
    if not candidates:
        print("No close functions found.")
        return
    
    print(f"Found {len(candidates)} functions with <5% positional diff:")
    print()
    
    for r in candidates:
        va = r["va"]
        name = r["name"]
        size = r["size_bytes"]
        pd = r["positional_diff_percent"]
        ed = r["edit_diff_percent"]
        bucket = r["source_bucket"]
        src = r.get("pdb_source_file", "?")
        print(f"{va} {name:40s} {size:>4s}B {bucket:16s} pos={pd:>8s}% edit={ed:>8s}% src={src}")
        print(f"  Diff type: {'Register swap' if float(pd) < 2 else 'Code scheduling'}")
        
        # Find source file
        for d in [REPO / "src/accepted_drift", REPO / "src/scratch"]:
            matches = list(d.glob(f"{va}_*")) + list(d.glob(f"{va}.*"))
            if matches:
                print(f"  Source: {matches[0]}")
                break
        
        # Check if it still compiles and matches
        result = subprocess.run(
            [sys.executable, str(REPO / "tools/check_function.py"), "--va", f"0x{va}", "--quiet", "--no-history"],
            capture_output=True, text=True, timeout=30
        )
        if "Result: MATCH" in result.stdout:
            print(f"  *** NOW MATCHING! ***")
        elif "Result: MISMATCH" in result.stdout:
            for line in result.stdout.splitlines():
                if "positional_diff_percent" in line or "diff percent" in line.lower() or "MISMATCH" in line:
                    print(f"  {line.strip()}")
        print()

if __name__ == "__main__":
    main()
