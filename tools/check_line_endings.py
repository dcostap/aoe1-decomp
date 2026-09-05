from __future__ import annotations

import subprocess
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
BINARY_SAMPLE_SIZE = 8000
CRLF_SUFFIXES = {".bat", ".cmd"}


def repository_paths(repo_root: Path) -> list[Path]:
    result = subprocess.run(
        [
            "git",
            "-C",
            str(repo_root),
            "ls-files",
            "--cached",
            "--others",
            "--exclude-standard",
            "-z",
        ],
        check=True,
        capture_output=True,
    )
    names = result.stdout.split(b"\0")
    return [repo_root / name.decode("utf-8", errors="surrogateescape") for name in names if name]


def is_binary(data: bytes) -> bool:
    return b"\0" in data[:BINARY_SAMPLE_SIZE]


def path_attributes(repo_root: Path, paths: list[Path]) -> dict[str, dict[str, str]]:
    names = [path.relative_to(repo_root).as_posix() for path in paths]
    if not names:
        return {}
    result = subprocess.run(
        ["git", "-C", str(repo_root), "check-attr", "-z", "--stdin", "text", "eol"],
        input=("\0".join(names) + "\0").encode("utf-8", errors="surrogateescape"),
        check=True, capture_output=True,
    )
    fields = result.stdout.decode("utf-8", errors="surrogateescape").split("\0")
    attributes: dict[str, dict[str, str]] = {}
    for index in range(0, len(fields) - 1, 3):
        name, key, value = fields[index:index + 3]
        attributes.setdefault(name, {})[key] = value
    return attributes


def line_ending_issue(data: bytes, expected: str) -> str | None:
    if is_binary(data):
        return None

    crlf_count = data.count(b"\r\n")
    remainder = data.replace(b"\r\n", b"")
    lf_count = remainder.count(b"\n")
    cr_count = remainder.count(b"\r")
    kinds = sum(count > 0 for count in (crlf_count, lf_count, cr_count))

    if kinds > 1:
        return "mixed line endings"
    if cr_count:
        return "lone CR line endings"
    if expected == "crlf" and lf_count:
        return "expected CRLF line endings"
    if expected == "lf" and crlf_count:
        return "expected LF line endings"
    return None


def check_repository(repo_root: Path = REPO_ROOT) -> list[str]:
    failures: list[str] = []
    paths = repository_paths(repo_root)
    attributes = path_attributes(repo_root, paths)
    for path in paths:
        if not path.is_file():
            continue
        settings = attributes.get(path.relative_to(repo_root).as_posix(), {})
        if settings.get("text") == "unset":
            continue
        expected = settings.get("eol")
        if expected not in ("lf", "crlf"):
            expected = "crlf" if path.suffix.casefold() in CRLF_SUFFIXES else "lf"
        issue = line_ending_issue(path.read_bytes(), expected)
        if issue:
            failures.append(f"{path.relative_to(repo_root).as_posix()}: {issue}")
    return failures


def main() -> int:
    failures = check_repository()
    if failures:
        print("Line-ending check failed:")
        for failure in failures:
            print(f"  {failure}")
        return 1
    print("Line-ending check passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
