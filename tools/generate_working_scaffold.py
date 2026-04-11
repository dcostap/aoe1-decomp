from __future__ import annotations

import csv

from common import ensure_dir, repo_path


def load_globals() -> list[dict[str, str]]:
    csv_path = repo_path("inventory") / "globals" / "all_globals.csv"
    with csv_path.open("r", encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def load_forward_declarations() -> list[str]:
    source_path = repo_path("inventory") / "types" / "all_types_reference.h"
    lines = source_path.read_text(encoding="utf-8", errors="replace").splitlines()
    forward_decls: list[str] = []
    for line in lines:
        if line.startswith("// Size:"):
            break
        stripped = line.strip()
        if not stripped.startswith(("class ", "struct ")):
            continue
        if "::" in stripped or "<" in stripped:
            continue
        if stripped not in forward_decls:
            forward_decls.append(stripped)
    return forward_decls


def build_game_types_header() -> str:
    lines = [
        "#pragma once",
        "// Generated once by tools\\generate_working_scaffold.py.",
        "// After the first scaffold pass, this file becomes editable project source.",
        "// The full read-only reference dump lives in ..\\inventory\\types\\all_types_reference.h.",
        "// Start by adding real type bodies here only when exact-match function work needs them.",
        "",
    ]
    lines.extend(load_forward_declarations())
    lines.append("")
    return "\n".join(lines)


def build_game_globals_header(rows: list[dict[str, str]]) -> str:
    lines = [
        "#pragma once",
        "// Generated once by tools\\generate_working_scaffold.py.",
        "// After the first scaffold pass, this file becomes editable project source.",
        '// Only globals with one conservative inferred type are auto-emitted here.',
        "",
        "#include <windows.h>",
        "#include <stdio.h>",
        '#include "game_types.h"',
        "",
    ]

    emitted = 0
    for row in rows:
        emit_type = row["emit_c_type"].strip()
        if not emit_type:
            continue
        name = row["primary_name"]
        comment = f"// {row['va']} [{row['section_name']}]"
        if row["emit_mode"] == "array":
            lines.append(comment)
            lines.append(f"extern {emit_type} {name}[{row['emit_array_length']}];")
        else:
            lines.append(comment)
            lines.append(f"extern {emit_type} {name};")
        emitted += 1

    if emitted == 0:
        lines.append("// No globals were safe to auto-emit yet. Add declarations here as function work requires them.")

    lines.append("")
    return "\n".join(lines)


def build_game_globals_source(rows: list[dict[str, str]]) -> str:
    lines = [
        '#include "..\\include\\game_globals.h"',
        "",
        "// Generated once by tools\\generate_working_scaffold.py.",
        "// After the first scaffold pass, this file becomes editable project source.",
        "",
    ]

    emitted = 0
    for row in rows:
        emit_type = row["emit_c_type"].strip()
        if not emit_type:
            continue
        initializer = row["emit_initializer"].strip()
        if not initializer:
            continue
        name = row["primary_name"]
        comment = f"// {row['va']} [{row['section_name']}]"
        if row["emit_mode"] == "array":
            lines.append(comment)
            lines.append(f"{emit_type} {name}[{row['emit_array_length']}] = {initializer};")
        else:
            lines.append(comment)
            lines.append(f"{emit_type} {name} = {initializer};")
        emitted += 1

    if emitted == 0:
        lines.append("// No globals were safe to auto-define yet. Add definitions here as function work requires them.")

    lines.append("")
    return "\n".join(lines)


def main() -> None:
    include_dir = repo_path("include")
    src_dir = repo_path("src")
    ensure_dir(include_dir)
    ensure_dir(src_dir)

    rows = load_globals()
    rows.sort(key=lambda row: row["va"])

    game_types_path = include_dir / "game_types.h"
    game_globals_header_path = include_dir / "game_globals.h"
    game_globals_source_path = src_dir / "game_globals.cpp"

    game_types_path.write_text(build_game_types_header(), encoding="utf-8")
    game_globals_header_path.write_text(build_game_globals_header(rows), encoding="utf-8")
    game_globals_source_path.write_text(build_game_globals_source(rows), encoding="utf-8")

    print(f"Wrote {game_types_path}")
    print(f"Wrote {game_globals_header_path}")
    print(f"Wrote {game_globals_source_path}")


if __name__ == "__main__":
    main()
