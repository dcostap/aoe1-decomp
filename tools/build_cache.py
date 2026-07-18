from __future__ import annotations

import hashlib
import json
import re
from pathlib import Path

from common import CONFIG_DIR, REPO_ROOT, repo_path


CACHE_SCHEMA = 2
_INCLUDE_RE = re.compile(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', re.MULTILINE)
_SOURCE_SUFFIXES = {".c", ".cc", ".cpp", ".cxx", ".h", ".hh", ".hpp", ".hxx", ".inl"}


def _sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def _display_path(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(REPO_ROOT.resolve())).replace("\\", "/")
    except ValueError:
        return str(path.resolve())


def _resolve_include(name: str, including: Path, include_dirs: tuple[Path, ...] = ()) -> Path | None:
    normalized = Path(name.replace("\\", "/"))
    candidates = (
        including.parent / normalized,
        REPO_ROOT / normalized,
        REPO_ROOT / "include" / normalized,
        REPO_ROOT / "src" / normalized,
        *(directory / normalized for directory in include_dirs),
    )
    for candidate in candidates:
        if candidate.is_file():
            return candidate.resolve()
    return None


def source_dependencies(source_path: Path, include_dirs: tuple[Path, ...] = ()) -> list[Path]:
    """Return transitive textual dependencies resolved through the build includes."""
    pending = [source_path.resolve()]
    seen: set[Path] = set()
    while pending:
        path = pending.pop()
        if path in seen or not path.is_file():
            continue
        seen.add(path)
        if path.suffix.lower() not in _SOURCE_SUFFIXES:
            continue
        try:
            text = path.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        for name in _INCLUDE_RE.findall(text):
            resolved = _resolve_include(name, path, include_dirs)
            if resolved is not None and resolved not in seen:
                pending.append(resolved)
    return sorted(seen, key=_display_path)


def build_input_manifest(source_path: Path, rsp_path: Path, toolchain: dict) -> dict[str, object]:
    source_path = source_path.resolve()
    rsp_path = rsp_path.resolve()
    compiler_path = repo_path(toolchain["compiler"]["cl"]).resolve()
    include_dirs = tuple(Path(value).resolve() for value in toolchain.get("environment", {}).get("include", []))
    input_paths = source_dependencies(source_path, include_dirs)
    for extra in (rsp_path, CONFIG_DIR / "toolchain.json"):
        resolved = extra.resolve()
        if resolved not in input_paths:
            input_paths.append(resolved)
    input_paths.sort(key=_display_path)
    inputs = [
        {
            "path": _display_path(path),
            "size": path.stat().st_size,
            "sha256": _sha256(path),
        }
        for path in input_paths
    ]
    compiler_stat = compiler_path.stat()
    payload = {
        "schema": CACHE_SCHEMA,
        "compiler": {
            "path": str(compiler_path),
            "size": compiler_stat.st_size,
            "mtime_ns": compiler_stat.st_mtime_ns,
        },
        "source": _display_path(source_path),
        "response_file": _display_path(rsp_path),
        "inputs": inputs,
    }
    encoded = json.dumps(payload, sort_keys=True, separators=(",", ":")).encode("utf-8")
    payload["fingerprint"] = hashlib.sha256(encoded).hexdigest()
    return payload


def load_build_manifest(path: Path) -> dict[str, object] | None:
    if not path.is_file():
        return None
    try:
        value = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return None
    return value if isinstance(value, dict) else None


def build_manifest_matches(path: Path, fingerprint: str, object_path: Path) -> bool:
    manifest = load_build_manifest(path)
    return bool(
        manifest
        and manifest.get("returncode") == 0
        and manifest.get("input_fingerprint") == fingerprint
        and object_path.is_file()
    )
