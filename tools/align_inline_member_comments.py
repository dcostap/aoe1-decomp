#!/usr/bin/env python3
"""Align trailing comments within detected contiguous comment runs."""

from __future__ import annotations

import argparse
from pathlib import Path


DEFAULT_INPUT = Path("build/inline_member_comment_runs.txt")


def split_body(line: str) -> tuple[str, str]:
    if line.endswith("\r\n"):
        return line[:-2], "\r\n"
    if line.endswith("\n") or line.endswith("\r"):
        return line[:-1], line[-1:]
    return line, ""


def load_groups(path: Path) -> dict[Path, list[list[int]]]:
    locations: dict[Path, list[int]] = {}
    for raw_line in path.read_text(encoding="utf-8").splitlines():
        if not raw_line:
            continue
        raw_path, raw_number = raw_line.rsplit(":", 1)
        file_path = Path(raw_path)
        locations.setdefault(file_path, []).append(int(raw_number))

    groups: dict[Path, list[list[int]]] = {}
    for file_path, numbers in locations.items():
        numbers = sorted(set(numbers))
        file_groups: list[list[int]] = []
        current: list[int] = []
        for number in numbers:
            if current and number != current[-1] + 1:
                file_groups.append(current)
                current = []
            current.append(number)
        if current:
            file_groups.append(current)
        groups[file_path] = file_groups
    return groups


def find_comment_indices(lines: list[str]) -> dict[int, int]:
    """Find real // markers while ignoring strings and block comments."""

    result: dict[int, int] = {}
    state = "normal"

    for line_number, line in enumerate(lines, start=1):
        body, _ = split_body(line)
        index = 0
        while index < len(body):
            char = body[index]
            if state == "block_comment":
                if body.startswith("*/", index):
                    state = "normal"
                    index += 2
                else:
                    index += 1
                continue
            if state == "string" or state == "character":
                quote = '"' if state == "string" else "'"
                if char == "\\":
                    index += 2
                else:
                    if char == quote:
                        state = "normal"
                    index += 1
                continue

            if body.startswith("//", index):
                result[line_number] = index
                break
            if body.startswith("/*", index):
                state = "block_comment"
                index += 2
                continue
            if char == '"':
                state = "string"
            elif char == "'":
                state = "character"
            index += 1

        if state == "string" or state == "character":
            # C/C++ source rarely continues a literal across physical lines.
            # Reset here so a malformed or generated line cannot hide later // markers.
            state = "normal"

    return result


def align_file(path: Path, groups: list[list[int]], write: bool) -> tuple[int, int]:
    raw = path.read_bytes()
    text = raw.decode("latin-1")
    lines = text.splitlines(keepends=True)
    comment_indices = find_comment_indices(lines)
    changed_lines = 0
    changed_groups = 0

    for group in groups:
        positions = [comment_indices[number] for number in group if number in comment_indices]
        if len(positions) < 2:
            continue
        target = max(positions)
        group_changed = False
        for number in group:
            if number not in comment_indices:
                continue
            position = comment_indices[number]
            if position >= target:
                continue
            body, ending = split_body(lines[number - 1])
            lines[number - 1] = body[:position] + (" " * (target - position)) + body[position:] + ending
            changed_lines += 1
            group_changed = True
        if group_changed:
            changed_groups += 1

    transformed = "".join(lines)
    if write and transformed != text:
        path.write_bytes(transformed.encode("latin-1"))
    return changed_groups, changed_lines


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--input",
        type=Path,
        default=DEFAULT_INPUT,
        help="detector output (default: build/inline_member_comment_runs.txt)",
    )
    parser.add_argument(
        "--apply",
        action="store_true",
        help="write aligned comments; otherwise report the planned changes",
    )
    args = parser.parse_args()

    groups = load_groups(args.input)
    total_groups = 0
    total_lines = 0
    for path, file_groups in groups.items():
        changed_groups, changed_lines = align_file(path, file_groups, args.apply)
        if changed_groups:
            mode = "apply" if args.apply else "dry-run"
            print(f"{mode}: {path}: {changed_groups} block(s), {changed_lines} line(s)")
            total_groups += changed_groups
            total_lines += changed_lines

    action = "changed" if args.apply else "would change"
    print(f"Summary: {action} {total_groups} block(s), {total_lines} line(s).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
