#!/usr/bin/env python3
"""Join short source lines that break inside expression parentheses.

The default mode is a dry run.  The script only joins a line when the
resulting physical line is shorter than the selected column limit.
It skips comments, strings, character literals, and preprocessor lines.
Function signatures remain separate from call and control-expression groups.
"""

from __future__ import annotations

import argparse
import difflib
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Optional


DEFAULT_EXTENSIONS = frozenset({".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp"})
CONTROL_KEYWORDS = frozenset(
    {
        "catch",
        "decltype",
        "delete",
        "for",
        "if",
        "sizeof",
        "switch",
        "throw",
        "typeid",
        "while",
    }
)


@dataclass
class LineState:
    """Facts about one physical source line."""

    has_comment: bool = False
    is_preprocessor: bool = False
    join_after: bool = False


@dataclass
class ParenGroup:
    """An expression parenthesis tracked while reindenting continuations."""

    joinable: bool
    first_arg_column: Optional[int]
    open_line: int


def split_body(line: str) -> tuple[str, str]:
    """Return a line without its ending and the original ending."""

    if line.endswith("\r\n"):
        return line[:-2], "\r\n"
    if line.endswith("\n") or line.endswith("\r"):
        return line[:-1], line[-1:]
    return line, ""


def visual_width(text: str, tab_size: int = 8) -> int:
    """Return the display width of text using normal tab stops."""

    column = 0
    for char in text:
        if char == "\t":
            column += tab_size - (column % tab_size)
        else:
            column += 1
    return column


def is_call_open(previous_kind: Optional[str], previous_value: Optional[str]) -> bool:
    """Return whether an opening parenthesis starts a call-like group."""

    if previous_kind == "identifier":
        return previous_value not in CONTROL_KEYWORDS
    return previous_value in {")", "]", ">"
    }


def is_joinable_open(previous_kind: Optional[str], previous_value: Optional[str]) -> bool:
    """Return whether an expression parenthesis can join short continuations."""

    # Calls and postfix expressions were the original cleanup scope.  Control
    # and type-expression keywords use the same safe token-joining rule.  A
    # declaration or definition is excluded separately by the signature test.
    return is_call_open(previous_kind, previous_value) or (
        previous_kind == "identifier" and previous_value in CONTROL_KEYWORDS
    )


def is_function_signature_prefix(
    prefix: str,
    previous_kind: Optional[str],
    previous_value: Optional[str],
) -> bool:
    """Recognize common declarations and definitions before their `(`."""

    if previous_kind != "identifier" or not previous_value:
        return False

    prefix = prefix.strip()
    if not prefix:
        return False

    # These forms are expressions, not declarations.  The parenthesis may be
    # nested inside a condition or may belong to a qualified call.
    if any(marker in prefix for marker in (".", "->", "=", ",", "?", "&&", "||", "(", "[", "<", ">")):
        return False
    if re.search(r"\b(?:if|for|return|switch|throw|while|new|delete)\b", prefix):
        return False

    identifiers = re.findall(r"[A-Za-z_][A-Za-z0-9_]*", prefix)
    if "::" in prefix:
        return True
    return len(identifiers) >= 2 and identifiers[-1] == previous_value


def scan_lines(lines: list[str]) -> list[LineState]:
    """Find safe newline boundaries inside call-like parentheses."""

    states = [LineState() for _ in lines]
    lexical_state = "normal"
    preprocessor_continuation = False
    paren_stack: list[bool] = []
    previous_kind: Optional[str] = None
    previous_value: Optional[str] = None

    for line_index, line in enumerate(lines):
        body, _ = split_body(line)
        line_state = states[line_index]
        stripped = body.lstrip(" \t")
        line_state.is_preprocessor = preprocessor_continuation or stripped.startswith("#")

        if line_state.is_preprocessor:
            preprocessor_continuation = body.rstrip(" \t").endswith("\\")
            lexical_state = "normal"
            previous_kind = None
            previous_value = None
            continue

        preprocessor_continuation = False
        index = 0
        length = len(body)

        while index < length:
            char = body[index]

            if lexical_state == "line_comment":
                line_state.has_comment = True
                break

            if lexical_state == "block_comment":
                line_state.has_comment = True
                if body.startswith("*/", index):
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

            if body.startswith("//", index):
                line_state.has_comment = True
                lexical_state = "line_comment"
                break
            if body.startswith("/*", index):
                line_state.has_comment = True
                lexical_state = "block_comment"
                index += 2
                continue
            if char == '"':
                lexical_state = "string"
                index += 1
                continue
            if char == "'":
                lexical_state = "character"
                index += 1
                continue
            if char.isspace():
                index += 1
                continue

            if char.isalpha() or char == "_":
                end = index + 1
                while end < length and (body[end].isalnum() or body[end] == "_"):
                    end += 1
                previous_kind = "identifier"
                previous_value = body[index:end]
                index = end
                continue

            if char.isdigit():
                end = index + 1
                while end < length and (body[end].isalnum() or body[end] in "._"):
                    end += 1
                previous_kind = "number"
                previous_value = body[index:end]
                index = end
                continue

            if char == "(":
                signature = is_function_signature_prefix(
                    body[:index], previous_kind, previous_value
                )
                paren_stack.append(
                    False if signature else is_joinable_open(previous_kind, previous_value)
                )
                previous_kind = "punctuation"
                previous_value = char
                index += 1
                continue

            if char == ")":
                if paren_stack:
                    paren_stack.pop()
                previous_kind = "punctuation"
                previous_value = char
                index += 1
                continue

            if char == "[":
                previous_kind = "punctuation"
                previous_value = char
                index += 1
                continue
            if char == "]":
                previous_kind = "punctuation"
                previous_value = char
                index += 1
                continue

            previous_kind = "punctuation"
            previous_value = char
            index += 1

        if lexical_state == "line_comment":
            lexical_state = "normal"
            previous_kind = None
            previous_value = None
        elif lexical_state == "string" or lexical_state == "character":
            # A continued literal is not a safe formatting boundary.
            previous_kind = None
            previous_value = None

        line_state.join_after = (
            lexical_state == "normal"
            and not line_state.has_comment
            and not line_state.is_preprocessor
            and any(paren_stack)
        )

    return states


def separator(left: str, right: str) -> str:
    """Choose the whitespace needed between two joined source fragments."""

    if not left or not right:
        return ""
    if left.endswith(("(", "[", ".", "->", "::")):
        return ""
    if right.startswith((")", "]", ",", ";", ".")):
        return ""
    return " "


def join_lines(left: str, right: str) -> str:
    """Join two physical lines without changing their useful tokens."""

    left_body, _ = split_body(left)
    right_body, right_ending = split_body(right)
    left_body = left_body.rstrip(" \t")
    right_body = right_body.lstrip(" \t")
    return left_body + separator(left_body, right_body) + right_body + right_ending


def reindent_call_continuations(text: str) -> tuple[str, int]:
    """Align continued call arguments below the first argument."""

    lines = text.splitlines(keepends=True)
    if len(lines) < 2:
        return text, 0

    groups: list[ParenGroup] = []
    lexical_state = "normal"
    preprocessor_continuation = False
    previous_kind: Optional[str] = None
    previous_value: Optional[str] = None
    output: list[str] = []
    changes = 0

    for line_index, line in enumerate(lines):
        body, ending = split_body(line)
        stripped = body.lstrip(" \t")
        is_preprocessor = preprocessor_continuation or stripped.startswith("#")
        target_column: Optional[int] = None

        if not is_preprocessor and lexical_state == "normal" and stripped:
            for group in reversed(groups):
                if group.joinable and group.first_arg_column is not None:
                    if group.open_line < line_index and groups[-1] is group:
                        target_column = group.first_arg_column
                    break

        if target_column is not None and not stripped.startswith(")"):
            new_body = (" " * target_column) + stripped
            if new_body != body:
                body = new_body
                changes += 1

        output.append(body + ending)

        if is_preprocessor:
            preprocessor_continuation = body.rstrip(" \t").endswith("\\")
            lexical_state = "normal"
            previous_kind = None
            previous_value = None
            continue

        preprocessor_continuation = False
        index = 0
        length = len(body)
        saw_comment = False

        while index < length:
            char = body[index]

            if lexical_state == "line_comment":
                saw_comment = True
                break
            if lexical_state == "block_comment":
                saw_comment = True
                if body.startswith("*/", index):
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

            if body.startswith("//", index):
                saw_comment = True
                lexical_state = "line_comment"
                break
            if body.startswith("/*", index):
                saw_comment = True
                lexical_state = "block_comment"
                index += 2
                continue
            if char == '"':
                lexical_state = "string"
                index += 1
                continue
            if char == "'":
                lexical_state = "character"
                index += 1
                continue
            if char.isspace():
                index += 1
                continue

            if char.isalpha() or char == "_":
                end = index + 1
                while end < length and (body[end].isalnum() or body[end] == "_"):
                    end += 1
                previous_kind = "identifier"
                previous_value = body[index:end]
                index = end
                continue
            if char.isdigit():
                end = index + 1
                while end < length and (body[end].isalnum() or body[end] in "._"):
                    end += 1
                previous_kind = "number"
                previous_value = body[index:end]
                index = end
                continue

            if char == "(":
                signature = is_function_signature_prefix(
                    body[:index], previous_kind, previous_value
                )
                joinable = False if signature else is_joinable_open(previous_kind, previous_value)
                first_arg_column: Optional[int] = None
                after_open = index + 1
                while after_open < length and body[after_open] in " \t":
                    after_open += 1
                if after_open < length and body[after_open] != ")":
                    first_arg_column = visual_width(body[:after_open])
                groups.append(ParenGroup(joinable, first_arg_column, line_index))
                previous_kind = "punctuation"
                previous_value = char
                index += 1
                continue
            if char == ")":
                if groups:
                    groups.pop()
                previous_kind = "punctuation"
                previous_value = char
                index += 1
                continue

            previous_kind = "punctuation"
            previous_value = char
            index += 1

        if lexical_state == "line_comment":
            lexical_state = "normal"
            previous_kind = None
            previous_value = None
        elif lexical_state == "string" or lexical_state == "character":
            previous_kind = None
            previous_value = None
        elif saw_comment:
            previous_kind = None
            previous_value = None

        if body.rstrip(" \t").endswith("\\"):
            preprocessor_continuation = is_preprocessor

    return "".join(output), changes


def transform(text: str, max_column: int) -> tuple[str, int]:
    """Return transformed text and the number of layout changes."""

    lines = text.splitlines(keepends=True)
    if len(lines) < 2:
        return text, 0

    states = scan_lines(lines)
    output: list[str] = []
    changes = 0

    for line_index, line in enumerate(lines):
        right_body, _ = split_body(line)
        if (
            output
            and states[line_index - 1].join_after
            and not states[line_index].has_comment
            and not states[line_index].is_preprocessor
            and right_body.strip()
        ):
            candidate = join_lines(output[-1], line)
            candidate_body, _ = split_body(candidate)
            if visual_width(candidate_body) < max_column:
                output[-1] = candidate
                changes += 1
                continue
        output.append(line)

    joined = "".join(output)
    reindented, indentation_changes = reindent_call_continuations(joined)
    return reindented, changes + indentation_changes


def collect_paths(paths: Iterable[Path], extensions: frozenset[str]) -> list[Path]:
    """Collect source files without traversing unrelated repository folders."""

    result: list[Path] = []
    for path in paths:
        if path.is_file():
            if path.suffix.lower() in extensions:
                result.append(path)
            continue
        if path.is_dir():
            result.extend(
                child
                for child in path.rglob("*")
                if child.is_file() and child.suffix.lower() in extensions
            )
            continue
        raise FileNotFoundError(path)
    return sorted(set(result))


def parse_extensions(value: str) -> frozenset[str]:
    extensions = set()
    for item in value.split(","):
        item = item.strip().lower()
        if not item:
            continue
        extensions.add(item if item.startswith(".") else "." + item)
    if not extensions:
        raise argparse.ArgumentTypeError("at least one file extension is required")
    return frozenset(extensions)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Join short lines broken inside expression parentheses. "
            "Dry-run by default."
        )
    )
    parser.add_argument("paths", nargs="+", type=Path, help="source files or directories")
    parser.add_argument(
        "--max-column",
        type=int,
        default=125,
        help="join only when the resulting line is shorter than this column (default: 125)",
    )
    parser.add_argument(
        "--extensions",
        type=parse_extensions,
        default=DEFAULT_EXTENSIONS,
        help="comma-separated extensions for directory inputs",
    )
    parser.add_argument(
        "--apply",
        action="store_true",
        help="write changes; without this flag, report a dry run",
    )
    parser.add_argument(
        "--diff",
        action="store_true",
        help="print unified diffs for changed files",
    )
    parser.add_argument(
        "--max-diff-lines",
        type=int,
        default=0,
        help="limit printed diff lines; 0 means no limit (default: 0)",
    )
    return parser


def main(argv: Optional[list[str]] = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    if args.max_column <= 0:
        parser.error("--max-column must be positive")
    if args.max_diff_lines < 0:
        parser.error("--max-diff-lines cannot be negative")

    try:
        paths = collect_paths(args.paths, args.extensions)
    except FileNotFoundError as error:
        parser.error(f"path not found: {error.args[0]}")

    total_changes = 0
    changed_files = 0
    diff_lines_printed = 0

    for path in paths:
        raw = path.read_bytes()
        text = raw.decode("latin-1")
        transformed, changes = transform(text, args.max_column)
        if changes == 0:
            continue

        changed_files += 1
        total_changes += changes
        mode = "apply" if args.apply else "dry-run"
        print(f"{mode}: {path}: {changes} layout change(s)")

        if args.diff:
            diff = difflib.unified_diff(
                text.splitlines(keepends=True),
                transformed.splitlines(keepends=True),
                fromfile=str(path),
                tofile=str(path),
            )
            for diff_line in diff:
                if args.max_diff_lines and diff_lines_printed >= args.max_diff_lines:
                    break
                sys.stdout.write(diff_line)
                diff_lines_printed += 1

        if args.apply:
            path.write_bytes(transformed.encode("latin-1"))

    action = "changed" if args.apply else "would change"
    print(f"Summary: {action} {changed_files} file(s), {total_changes} layout change(s).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
