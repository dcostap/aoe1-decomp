#!/usr/bin/env python3
"""Report or collapse unusually long runs of blank source lines."""

from __future__ import annotations

import argparse
from pathlib import Path


DEFAULT_EXTENSIONS = frozenset({".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp"})


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


def find_runs(path: Path, minimum: int) -> list[tuple[int, int, int]]:
    lines = path.read_bytes().decode("latin-1").splitlines()
    runs: list[tuple[int, int, int]] = []
    start = None

    for index, line in enumerate(lines, start=1):
        if line.strip() == "":
            if start is None:
                start = index
            continue

        if start is not None:
            end = index - 1
            length = end - start + 1
            if length >= minimum:
                runs.append((start, end, length))
            start = None

    if start is not None:
        end = len(lines)
        length = end - start + 1
        if length >= minimum:
            runs.append((start, end, length))

    return runs


def collapse_runs(path: Path, maximum: int) -> tuple[int, int]:
    """Collapse each blank-line run to at most maximum lines."""

    text = path.read_bytes().decode("latin-1")
    lines = text.splitlines(keepends=True)
    output: list[str] = []
    blank_count = 0
    removed = 0
    changed_runs = 0

    for line in lines:
        if line.strip(" \t\r\n") == "":
            blank_count += 1
            if blank_count <= maximum:
                output.append(line)
            else:
                removed += 1
            continue

        if blank_count > maximum:
            changed_runs += 1
        blank_count = 0
        output.append(line)

    if blank_count > maximum:
        changed_runs += 1

    transformed = "".join(output)
    if transformed != text:
        path.write_bytes(transformed.encode("latin-1"))
    return changed_runs, removed


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
        "--minimum",
        type=int,
        default=8,
        help="report runs with at least this many blank lines (default: 8)",
    )
    parser.add_argument(
        "--extensions",
        type=parse_extensions,
        default=DEFAULT_EXTENSIONS,
    )
    parser.add_argument(
        "--apply",
        action="store_true",
        help="collapse runs instead of only reporting them",
    )
    parser.add_argument(
        "--max-blank-lines",
        type=int,
        default=1,
        help="keep at most this many consecutive blank lines (default: 1)",
    )
    args = parser.parse_args()
    if args.minimum < 1:
        parser.error("--minimum must be positive")
    if args.max_blank_lines < 0:
        parser.error("--max-blank-lines cannot be negative")

    try:
        paths = collect_files(args.paths, args.extensions)
    except FileNotFoundError as error:
        parser.error(f"path not found: {error.args[0]}")

    file_count = 0
    run_count = 0
    removed_count = 0
    for path in paths:
        if args.apply:
            changed_runs, removed = collapse_runs(path, args.max_blank_lines)
            if changed_runs:
                file_count += 1
                run_count += changed_runs
                removed_count += removed
                print(
                    f"apply: {path}: {changed_runs} run(s), "
                    f"removed {removed} blank line(s)"
                )
            continue

        runs = find_runs(path, args.minimum)
        if not runs:
            continue
        file_count += 1
        run_count += len(runs)
        for start, end, length in runs:
            print(f"{path}:{start}-{end}: {length} blank lines")

    if args.apply:
        print(
            f"Summary: changed {file_count} file(s), {run_count} run(s), "
            f"removed {removed_count} blank line(s)."
        )
    else:
        print(f"Summary: {file_count} file(s), {run_count} run(s).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
