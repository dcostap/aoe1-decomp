#!/usr/bin/env python3
"""Find consecutive class or struct fields with trailing // comments."""

from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path
from typing import Optional


DEFAULT_EXTENSIONS = frozenset({".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp"})


@dataclass
class FileScan:
    candidate_lines: list[int]


def collect_files(paths: list[Path], extensions: frozenset[str]) -> list[Path]:
    result: list[Path] = []
    for path in paths:
        if path.is_file():
            if path.suffix.lower() in extensions:
                result.append(path)
        elif path.is_dir():
            result.extend(
                child
                for child in path.rglob("*")
                if child.is_file() and child.suffix.lower() in extensions
            )
        else:
            raise FileNotFoundError(path)
    return sorted(set(result))


def scan_file(path: Path) -> FileScan:
    lines = path.read_bytes().decode("latin-1").splitlines()
    scope_stack: list[str] = []
    lexical_state = "normal"
    pending_class = False
    previous_identifier: Optional[str] = None
    candidate_lines: list[int] = []

    for line_number, line in enumerate(lines, start=1):
        code_before_comment: list[str] = []
        inline_comment = False
        index = 0
        length = len(line)

        while index < length:
            char = line[index]

            if lexical_state == "line_comment":
                break
            if lexical_state == "block_comment":
                if line.startswith("*/", index):
                    lexical_state = "normal"
                    index += 2
                else:
                    index += 1
                continue
            if lexical_state == "string" or lexical_state == "character":
                quote = '"' if lexical_state == "string" else "'"
                if char == "\\":
                    index += 2
                    continue
                if char == quote:
                    lexical_state = "normal"
                index += 1
                continue

            if line.startswith("//", index):
                inline_comment = bool("".join(code_before_comment).strip())
                if (
                    inline_comment
                    and ";" in code_before_comment
                    and scope_stack
                    and scope_stack[-1] == "class"
                ):
                    candidate_lines.append(line_number)
                lexical_state = "line_comment"
                break
            if line.startswith("/*", index):
                lexical_state = "block_comment"
                index += 2
                continue
            if char == '"':
                lexical_state = "string"
                code_before_comment.append(char)
                index += 1
                continue
            if char == "'":
                lexical_state = "character"
                code_before_comment.append(char)
                index += 1
                continue

            if char.isalpha() or char == "_":
                end = index + 1
                while end < length and (line[end].isalnum() or line[end] == "_"):
                    end += 1
                identifier = line[index:end]
                if identifier in {"class", "struct"}:
                    pending_class = previous_identifier != "enum"
                elif identifier not in {"public", "protected", "private"}:
                    previous_identifier = identifier
                code_before_comment.extend(line[index:end])
                index = end
                continue

            if char == "{":
                scope_stack.append("class" if pending_class else "other")
                pending_class = False
                previous_identifier = None
                code_before_comment.append(char)
                index += 1
                continue
            if char == "}":
                if scope_stack:
                    scope_stack.pop()
                pending_class = False
                previous_identifier = None
                code_before_comment.append(char)
                index += 1
                continue
            if char == ";":
                pending_class = False
                previous_identifier = None
                code_before_comment.append(char)
                index += 1
                continue

            if not char.isspace():
                code_before_comment.append(char)
            index += 1

        if lexical_state == "line_comment":
            lexical_state = "normal"

    return FileScan(candidate_lines)


def qualifying_lines(lines: list[int], minimum_run: int) -> list[int]:
    result: list[int] = []
    run: list[int] = []
    previous = None

    for line in lines:
        if previous is None or line == previous + 1:
            run.append(line)
        else:
            if len(run) >= minimum_run:
                result.extend(run)
            run = [line]
        previous = line

    if len(run) >= minimum_run:
        result.extend(run)
    return result


def parse_extensions(value: str) -> frozenset[str]:
    extensions = set()
    for item in value.split(","):
        item = item.strip().lower()
        if item:
            extensions.add(item if item.startswith(".") else "." + item)
    if not extensions:
        raise argparse.ArgumentTypeError("at least one extension is required")
    return frozenset(extensions)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("paths", nargs="+", type=Path)
    parser.add_argument(
        "--minimum-run",
        type=int,
        default=2,
        help="require at least this many consecutive lines (default: 2)",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=Path("build/inline_member_comment_runs.txt"),
        help="output text file (default: build/inline_member_comment_runs.txt)",
    )
    parser.add_argument(
        "--extensions",
        type=parse_extensions,
        default=DEFAULT_EXTENSIONS,
    )
    args = parser.parse_args()
    if args.minimum_run < 2:
        parser.error("--minimum-run must be at least 2")

    try:
        paths = collect_files(args.paths, args.extensions)
    except FileNotFoundError as error:
        parser.error(f"path not found: {error.args[0]}")

    matches: list[str] = []
    for path in paths:
        lines = qualifying_lines(scan_file(path).candidate_lines, args.minimum_run)
        absolute_path = path.resolve()
        matches.extend(f"{absolute_path}:{line}" for line in lines)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("\n".join(matches) + ("\n" if matches else ""), encoding="utf-8")
    print(f"Wrote {len(matches)} location(s) to {args.output}.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
