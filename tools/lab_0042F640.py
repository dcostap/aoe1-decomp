from __future__ import annotations

import csv
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

SCRATCH = Path("src/scratch/0042F640_IsThisHost.cpp")
OUT_TSV = Path("build/notes/0042F640_lab.tsv")
OUT_MD = Path("build/notes/0042F640_lab.md")

PRELUDE = """struct LobbyConnection {
    int unknown_00;
    unsigned int dwFlags;
};

class RGE_Lobby {
public:
    char gap_00[0x10];
    LobbyConnection* glpdplConnection;
    unsigned char lobby_game;

    unsigned char IsThisHost();
};

"""

FUNCTION_TEMPLATE = """unsigned char RGE_Lobby::IsThisHost() {{
    if (!this->lobby_game) {{
        return 0;
    }}
{body}
}}
"""

VARIANTS: list[tuple[str, str, str]] = [
    ("direct", "baseline direct dword expression", "return (this->glpdplConnection->dwFlags >> 1) & 1;"),
    ("direct_cast_all", "cast full result to byte", "return (unsigned char)((this->glpdplConnection->dwFlags >> 1) & 1);"),
    ("direct_cast_field", "cast field before shift", "return ((unsigned char)this->glpdplConnection->dwFlags >> 1) & 1;"),
    ("direct_cast_after_shift", "cast after shift before mask", "return ((unsigned char)(this->glpdplConnection->dwFlags >> 1)) & 1;"),
    ("bool_and2_ne0", "bit-test compare form", "return (this->glpdplConnection->dwFlags & 2) != 0;"),
    ("bool_and2_ternary", "bit-test ternary form", "return (this->glpdplConnection->dwFlags & 2) ? 1 : 0;"),
    ("byte_temp", "direct byte temp mutate", "    unsigned char c = (unsigned char)this->glpdplConnection->dwFlags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("byte_temp_split", "split byte temp declaration", "    unsigned char c;\n    c = (unsigned char)this->glpdplConnection->dwFlags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_byte_temp", "dword temp then byte temp", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_byte_temp_split", "split dword temp then byte temp", "    unsigned int flags;\n    unsigned char c;\n    flags = this->glpdplConnection->dwFlags;\n    c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_reg_byte_temp", "register dword temp then byte temp", "    register unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_reg_cast_return", "register dword temp with cast return", "    register unsigned int flags = this->glpdplConnection->dwFlags;\n    return ((unsigned char)flags >> 1) & 1;"),
    ("flags_cast_return", "dword temp with cast return", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    return ((unsigned char)flags >> 1) & 1;"),
    ("flags_ptr_inline_mutate", "pointer alias inline mutate low byte", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    (*(unsigned char*)&flags) >>= 1;\n    (*(unsigned char*)&flags) &= 1;\n    return *(unsigned char*)&flags;"),
    ("flags_ptr_named_mutate", "named pointer alias mutate low byte", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char* low = (unsigned char*)&flags;\n    *low >>= 1;\n    *low &= 1;\n    return *low;"),
    ("flags_ptr_named_readexpr", "named pointer alias readexpr", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char* low = (unsigned char*)&flags;\n    return (*low >> 1) & 1;"),
    ("flags_ptr_inline_readexpr", "inline pointer alias readexpr", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    return (*(unsigned char*)&flags >> 1) & 1;"),
    ("flags_ref_inline_mutate", "reference cast inline mutate low byte", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    ((unsigned char&)flags) >>= 1;\n    ((unsigned char&)flags) &= 1;\n    return (unsigned char&)flags;"),
    ("flags_ref_named_mutate", "named reference alias mutate low byte", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char& low = (unsigned char&)flags;\n    low >>= 1;\n    low &= 1;\n    return low;"),
    ("flags_ref_named_readexpr", "named reference alias readexpr", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char& low = (unsigned char&)flags;\n    return (low >> 1) & 1;"),
    ("flags_ref_inline_readexpr", "reference cast inline readexpr", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    return (((unsigned char&)flags) >> 1) & 1;"),
    ("union_b0_mutate", "union byte array mutate", "    union { unsigned int u; unsigned char b[4]; } flags;\n    flags.u = this->glpdplConnection->dwFlags;\n    flags.b[0] >>= 1;\n    flags.b[0] &= 1;\n    return flags.b[0];"),
    ("union_b0_readexpr", "union byte array readexpr", "    union { unsigned int u; unsigned char b[4]; } flags;\n    flags.u = this->glpdplConnection->dwFlags;\n    return (flags.b[0] >> 1) & 1;"),
    ("union_named_low_mutate", "union named low field mutate", "    union { unsigned int u; unsigned char low; } flags;\n    flags.u = this->glpdplConnection->dwFlags;\n    flags.low >>= 1;\n    flags.low &= 1;\n    return flags.low;"),
    ("union_named_low_readexpr", "union named low field readexpr", "    union { unsigned int u; unsigned char low; } flags;\n    flags.u = this->glpdplConnection->dwFlags;\n    return (flags.low >> 1) & 1;"),
    ("macro_lowbyte_mutate", "macro lowbyte mutate local flags", "    #define LOWBYTE_LAB(x) (*((unsigned char*)&(x)))\n    unsigned int flags = this->glpdplConnection->dwFlags;\n    LOWBYTE_LAB(flags) >>= 1;\n    LOWBYTE_LAB(flags) &= 1;\n    return LOWBYTE_LAB(flags);"),
    ("macro_lowbyte_readexpr", "macro lowbyte readexpr local flags", "    #define LOWBYTE_LAB(x) (*((unsigned char*)&(x)))\n    unsigned int flags = this->glpdplConnection->dwFlags;\n    return (LOWBYTE_LAB(flags) >> 1) & 1;"),
    ("flags_self_assign_byte_temp", "self-assign dword temp then byte temp", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    flags = flags;\n    unsigned char c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("comma_assign_byte_temp", "comma assignment into byte temp", "    unsigned int flags;\n    unsigned char c = (unsigned char)(flags = this->glpdplConnection->dwFlags);\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("comma_assign_cast_return", "comma assignment then cast return", "    unsigned int flags;\n    return ((unsigned char)(flags = this->glpdplConnection->dwFlags) >> 1) & 1;"),
    ("flags_and_not1_byte_temp", "clear bit0 then byte temp", "    unsigned int flags = this->glpdplConnection->dwFlags & ~1u;\n    unsigned char c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_and_not1_ref_mutate", "clear bit0 then reference alias mutate", "    unsigned int flags = this->glpdplConnection->dwFlags & ~1u;\n    unsigned char& low = (unsigned char&)flags;\n    low >>= 1;\n    low &= 1;\n    return low;"),
    ("flags_and_not1_ptr_mutate", "clear bit0 then pointer alias mutate", "    unsigned int flags = this->glpdplConnection->dwFlags & ~1u;\n    unsigned char* low = (unsigned char*)&flags;\n    *low >>= 1;\n    *low &= 1;\n    return *low;"),
    ("flags_or_10000_byte_temp", "set high bit then byte temp", "    unsigned int flags = this->glpdplConnection->dwFlags | 0x10000u;\n    unsigned char c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_or_10000_ref_mutate", "set high bit then reference alias mutate", "    unsigned int flags = this->glpdplConnection->dwFlags | 0x10000u;\n    unsigned char& low = (unsigned char&)flags;\n    low >>= 1;\n    low &= 1;\n    return low;"),
    ("flags_xor_10000_byte_temp", "xor high bit then byte temp", "    unsigned int flags = this->glpdplConnection->dwFlags ^ 0x10000u;\n    unsigned char c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_xor_10000_ref_mutate", "xor high bit then reference alias mutate", "    unsigned int flags = this->glpdplConnection->dwFlags ^ 0x10000u;\n    unsigned char& low = (unsigned char&)flags;\n    low >>= 1;\n    low &= 1;\n    return low;"),
    ("flags_and_not10000_byte_temp", "clear high bit then byte temp", "    unsigned int flags = this->glpdplConnection->dwFlags & ~0x10000u;\n    unsigned char c = (unsigned char)flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_and_not10000_ref_mutate", "clear high bit then reference alias mutate", "    unsigned int flags = this->glpdplConnection->dwFlags & ~0x10000u;\n    unsigned char& low = (unsigned char&)flags;\n    low >>= 1;\n    low &= 1;\n    return low;"),
    ("flags_copy_low_then_return", "copy low byte via pointer then return expr", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char c = *(unsigned char*)&flags;\n    return (c >> 1) & 1;"),
    ("flags_copy_low_assign_then_mutate", "copy low byte by lvalue read then mutate", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    unsigned char c;\n    c = *(unsigned char*)&flags;\n    c >>= 1;\n    c &= 1;\n    return c;"),
    ("flags_double_low_expr", "two low-byte reads through alias in final expr", "    unsigned int flags = this->glpdplConnection->dwFlags;\n    return ((*(unsigned char*)&flags) >> 1) & 1;"),
]


def extract_tail(output: str) -> list[str]:
    tail = []
    for addr in ["0042F64A", "0042F64D", "0042F650", "0042F652", "0042F654", "0042F656"]:
        m = re.search(rf"\+{addr}\s+(.+)", output, re.M)
        if m:
            tail.append(f"{addr}:{m.group(1).strip()}")
    return tail


def tail_family(tail: list[str]) -> str:
    joined = " | ".join(tail)
    if "mov eax,[eax+4]" in joined and "shr al,1" in joined:
        return "HYBRID_PROMISING"
    if "mov eax,[eax+4]" in joined and "shr eax,1" in joined:
        return "WIDE_LOAD_WIDE_SHIFT"
    if "mov al,[eax+4]" in joined and "shr al,1" in joined:
        return "BYTE_LOAD_BYTE_SHIFT"
    if "mov al,[eax+4]" in joined and "shr eax,1" in joined:
        return "BYTE_LOAD_WIDE_SHIFT"
    if "mov eax,[eax+4]" in joined:
        return "WIDE_LOAD_OTHER"
    if "mov al,[eax+4]" in joined:
        return "BYTE_LOAD_OTHER"
    return "OTHER"


def sort_key(row: dict[str, str]):
    mismatch = row["mismatch"]
    if mismatch == "MATCH":
        rank = -1
    elif mismatch.isdigit():
        rank = int(mismatch)
    else:
        rank = 9999
    fam_rank = {"HYBRID_PROMISING": 0, "BYTE_LOAD_BYTE_SHIFT": 1, "WIDE_LOAD_WIDE_SHIFT": 2}.get(row["family"], 9)
    return (rank, fam_rank, row["variant"])


def run() -> int:
    original = SCRATCH.read_text(encoding="utf-8")
    rows: list[dict[str, str]] = []

    try:
        for variant, note, body in VARIANTS:
            source = PRELUDE + FUNCTION_TEMPLATE.format(body=body)
            SCRATCH.write_text(source, encoding="utf-8")
            proc = subprocess.run(
                [sys.executable, "tools/check_function.py", "--va", "0042F640"],
                capture_output=True,
                text=True,
            )
            output = proc.stdout + proc.stderr
            if proc.returncode == 0:
                mismatch = "MATCH"
            else:
                m = re.search(r"First mismatch offset: (\d+)", output)
                mismatch = m.group(1) if m else "ERR"
            tail = extract_tail(output)
            family = tail_family(tail)
            err = ""
            if mismatch == "ERR":
                lines = [ln for ln in output.splitlines() if ln.strip()]
                err = " | ".join(lines[-6:])[:500]
            rows.append(
                {
                    "variant": variant,
                    "note": note,
                    "result": "MATCH" if proc.returncode == 0 else ("MISMATCH" if mismatch.isdigit() else "ERROR"),
                    "mismatch": mismatch,
                    "family": family,
                    "tail": " || ".join(tail),
                    "err": err,
                }
            )
    finally:
        SCRATCH.write_text(original, encoding="utf-8")

    rows.sort(key=sort_key)
    OUT_TSV.parent.mkdir(parents=True, exist_ok=True)
    with OUT_TSV.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=["variant", "note", "result", "mismatch", "family", "tail", "err"], delimiter="\t")
        writer.writeheader()
        writer.writerows(rows)

    family_map: dict[str, list[dict[str, str]]] = defaultdict(list)
    for row in rows:
        family_map[row["family"]].append(row)

    lines: list[str] = []
    lines.append("# 0042F640 focused variant lab")
    lines.append("")
    lines.append(f"Total variants: {len(rows)}")
    lines.append("")
    lines.append("## Family counts")
    lines.append("")
    for family in sorted(family_map):
        lines.append(f"- `{family}`: {len(family_map[family])}")
    lines.append("")
    lines.append("## Top rows overall")
    lines.append("")
    for row in rows[:20]:
        lines.append(f"- `{row['variant']}` note=`{row['note']}` result=`{row['result']}` mismatch=`{row['mismatch']}` family=`{row['family']}`")
        if row["tail"]:
            lines.append(f"  - `{row['tail']}`")
        if row["err"]:
            lines.append(f"  - `{row['err']}`")
    lines.append("")
    lines.append("## Per-family detail")
    lines.append("")
    for family in sorted(family_map):
        lines.append(f"### {family}")
        lines.append("")
        for row in family_map[family]:
            lines.append(f"- `{row['variant']}` mismatch=`{row['mismatch']}` note=`{row['note']}`")
            if row["tail"]:
                lines.append(f"  - `{row['tail']}`")
            if row["err"]:
                lines.append(f"  - `{row['err']}`")
        lines.append("")

    OUT_MD.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("\n".join(lines[:80]))
    print(f"\nWrote {OUT_TSV}")
    print(f"Wrote {OUT_MD}")
    return 0


if __name__ == "__main__":
    raise SystemExit(run())
