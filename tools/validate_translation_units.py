from __future__ import annotations

"""Validate natural source builds and matching function symbols."""

import argparse
import json
import re
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable

from coff import load_coff_object
from common import (
    REPO_ROOT,
    load_build_modules,
    load_function_modules,
    load_functions,
    load_pdb_function_source_map,
    pdb_module_stream_procedure_for_va,
    preferred_source_path,
    slugify_name,
)
from extract_obj_function import select_exact_function_symbol
from function_diagnostics import owning_function_symbol_validation


_HEX_VA = re.compile(r"^[0-9A-Fa-f]{8}$")


@dataclass(frozen=True)
class ValidationIssue:
    code: str
    message: str

    def __str__(self) -> str:
        return f"{self.code}: {self.message}"


def _issue(code: str, message: str) -> ValidationIssue:
    return ValidationIssue(code, message)


def _relative_path(path: Path, root: Path) -> str:
    try:
        return path.resolve().relative_to(root.resolve()).as_posix()
    except ValueError:
        return path.resolve().as_posix().lower()


def _manifest_path(value: object, root: Path) -> str:
    if not isinstance(value, str) or not value.strip():
        return ""
    candidate = Path(value.strip().replace("\\", "/"))
    if not candidate.is_absolute():
        candidate = root / candidate
    return _relative_path(candidate, root)


def _resolve_path(value: object, root: Path) -> Path:
    candidate = Path(str(value or "").strip().replace("\\", "/"))
    return candidate if candidate.is_absolute() else root / candidate


def _function_records() -> dict[str, dict[str, str]]:
    return {row["va"].upper(): row for row in load_functions()}


def _matching_entries(module: dict[str, object]) -> dict[str, dict[str, str]]:
    functions = module.get("functions")
    if not isinstance(functions, dict):
        return {}
    return {
        str(va).upper(): entry
        for va, entry in functions.items()
        if isinstance(entry, dict) and entry.get("status") == "matching"
    }


def _mapped_matching_symbols(
    module: dict[str, object], object_dir: Path
) -> dict[str, str] | None:
    name = slugify_name(str(module.get("name") or ""))
    object_path = object_dir / f"tu_{name}.obj"
    if not object_path.is_file():
        return None
    try:
        obj = load_coff_object(object_path)
    except (OSError, ValueError, KeyError):
        return {}

    result: dict[str, str] = {}
    for va, entry in _matching_entries(module).items():
        try:
            symbol = select_exact_function_symbol(obj, str(entry["symbol"]))
        except (KeyError, ValueError):
            continue
        result[va] = symbol.name
    return result


def _manifest_mtime(path: Path) -> int:
    try:
        return path.stat().st_mtime_ns
    except OSError:
        return -1


def find_isolated_owner_overlaps(
    modules: Iterable[dict[str, object]],
    *,
    manifests_dir: Path,
    root: Path = REPO_ROOT,
) -> list[ValidationIssue]:
    """Find current isolated builds for a source that also has a module build."""
    source_to_name = {
        _manifest_path(module.get("source"), root): str(module.get("name") or "<unnamed>")
        for module in modules
    }
    if not manifests_dir.is_dir():
        return []

    grouped_mtimes: dict[str, int] = {}
    payloads: list[tuple[Path, dict[str, object]]] = []
    for path in sorted(manifests_dir.glob("build_*.json")):
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue
        if not isinstance(payload, dict):
            continue
        payloads.append((path, payload))
        source = _manifest_path(payload.get("source"), root)
        if path.name.startswith("build_tu_") and source in source_to_name:
            grouped_mtimes[source] = max(grouped_mtimes.get(source, -1), _manifest_mtime(path))

    issues: list[ValidationIssue] = []
    for path, payload in payloads:
        if path.name.startswith("build_tu_"):
            continue
        source = _manifest_path(payload.get("source"), root)
        name = source_to_name.get(source)
        if name is None or grouped_mtimes.get(source, -1) >= _manifest_mtime(path):
            continue
        issues.append(
            _issue(
                "isolated-source-overlap",
                f"{path} builds {source} outside module {name}",
            )
        )
    return issues


def validate_translation_units(
    modules: Iterable[dict[str, object]],
    *,
    root: Path = REPO_ROOT,
    manifests_dir: Path | None = None,
    object_dir: Path | None = None,
    require_complete: bool = False,
) -> list[ValidationIssue]:
    """Return structural and exact-symbol issues for natural source builds."""
    modules = list(modules)
    root = root.resolve()
    records = _function_records()
    pdb_sources = load_pdb_function_source_map()
    issues: list[ValidationIssue] = []
    seen_names: set[str] = set()
    seen_sources: set[str] = set()
    seen_vas: set[str] = set()

    for module in modules:
        name = str(module.get("name") or "").strip()
        source_value = str(module.get("source") or "").strip()
        label = name or "<unnamed>"
        source = _resolve_path(source_value, root)
        source_key = _manifest_path(source_value, root)

        if not name:
            issues.append(_issue("missing-name", "build module has no derived name"))
        elif name in seen_names:
            issues.append(_issue("duplicate-name", f"duplicate build module name {name}"))
        seen_names.add(name)

        if not source_value or not source.is_file():
            issues.append(_issue("missing-source", f"{label} source is missing: {source}"))
        elif source.suffix.casefold() not in {".c", ".cpp"}:
            issues.append(_issue("source-extension", f"{label} source is not C or C++: {source}"))
        if source_key in seen_sources:
            issues.append(_issue("duplicate-source", f"duplicate build source {source_value}"))
        seen_sources.add(source_key)

        build = module.get("build")
        if not isinstance(build, dict):
            issues.append(_issue("missing-build", f"{label} has no build recipe"))
            continue
        flags_value = str(build.get("flags_path") or "").strip()
        flags_path = _resolve_path(flags_value, root)
        if not flags_path.is_file():
            issues.append(_issue("missing-flags", f"{label} flags are missing: {flags_value}"))
        elif source.suffix.casefold() == ".c":
            tokens = flags_path.read_text(encoding="utf-8", errors="replace").upper().split()
            if "/TC" not in tokens:
                issues.append(_issue("c-language-mode", f"{label} C flags need /TC"))

        functions = module.get("functions")
        if not isinstance(functions, dict) or not functions:
            issues.append(_issue("missing-functions", f"{label} has no functions"))
            continue

        matching = _matching_entries(module)
        for raw_va, entry in functions.items():
            va = str(raw_va).upper()
            if not _HEX_VA.fullmatch(va):
                issues.append(_issue("invalid-va", f"{label} has invalid VA {raw_va!r}"))
                continue
            if va in seen_vas:
                issues.append(_issue("duplicate-va", f"VA {va} appears in more than one build"))
            seen_vas.add(va)
            if va not in records:
                issues.append(_issue("unknown-va", f"{label} function {va} is absent from inventory"))
                continue
            if not isinstance(entry, dict):
                issues.append(_issue("invalid-entry", f"{label} function {va} is not an object"))
                continue
            symbol = str(entry.get("symbol") or "").strip()
            if not symbol or any(character.isspace() for character in symbol):
                issues.append(_issue("invalid-symbol", f"{label} function {va} has no valid symbol"))
            if preferred_source_path(records[va]).resolve() != source.resolve():
                issues.append(_issue("source-mismatch", f"{label} function {va} has another source owner"))

        for va, entry in matching.items():
            pdb_symbol = str((pdb_sources.get(va) or {}).get("symbol_name") or "").strip()
            if module.get("pdb_no_line_info"):
                stream = pdb_module_stream_procedure_for_va(module, va)
                if stream is None:
                    issues.append(_issue("missing-pdb-module-symbol", f"{label} matching function {va} lacks stream evidence"))
                elif str(stream.get("name") or "") != pdb_symbol:
                    issues.append(_issue("pdb-symbol-mismatch", f"{label} matching function {va} stream symbol differs"))
            if not pdb_symbol:
                issues.append(_issue("missing-pdb-symbol", f"{label} matching function {va} lacks a PDB symbol"))

        if object_dir is not None:
            object_path = object_dir / f"tu_{slugify_name(name)}.obj"
            if not object_path.is_file():
                issues.append(_issue("missing-grouped-object", f"{label} object is missing: {object_path}"))
            mapped = _mapped_matching_symbols(module, object_dir)
            if mapped is not None:
                for va, entry in matching.items():
                    actual = mapped.get(va)
                    if actual is None:
                        issues.append(_issue("symbol-not-defined", f"{label} matching function {va} is absent from the object"))
                        continue
                    pdb_symbol = str((pdb_sources.get(va) or {}).get("symbol_name") or "").strip()
                    validation = owning_function_symbol_validation(
                        records[va]["name"], actual, pdb_symbol
                    )
                    if validation["status"] != "match":
                        issues.append(_issue("pdb-symbol-mismatch", f"{label} matching function {va} has the wrong object symbol"))

    if manifests_dir is not None:
        issues.extend(find_isolated_owner_overlaps(modules, manifests_dir=manifests_dir, root=root))

    if require_complete:
        expected = {
            str(module["source"]): set(module["functions"])
            for module in load_function_modules()
            if module.get("build")
        }
        actual = {
            str(module.get("source") or ""): set(module.get("functions") or {})
            for module in modules
        }
        for source in sorted(set(expected) - set(actual)):
            issues.append(_issue("missing-build-module", f"{source} is absent from build validation"))
        for source in sorted(set(actual) & set(expected)):
            if actual[source] != expected[source]:
                issues.append(_issue("incomplete-build-module", f"{source} has an incomplete function set"))

    return issues


def _parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Validate configured natural source builds.")
    parser.add_argument(
        "--manifests-dir",
        type=Path,
        default=REPO_ROOT / "build" / "manifests",
        help="Build manifests used for isolated-source checks.",
    )
    parser.add_argument(
        "--objects-dir",
        type=Path,
        default=REPO_ROOT / "build" / "obj",
        help="Grouped COFF objects used for exact symbol checks.",
    )
    parser.add_argument(
        "--no-build-checks",
        action="store_true",
        help="Skip object and isolated-build checks.",
    )
    return parser.parse_args()


def main() -> int:
    args = _parse_args()
    kwargs: dict[str, object] = {}
    if not args.no_build_checks:
        kwargs["manifests_dir"] = args.manifests_dir
        kwargs["object_dir"] = args.objects_dir
    issues = validate_translation_units(load_build_modules(), require_complete=True, **kwargs)
    if issues:
        for issue in issues:
            print(issue, file=sys.stderr)
        print(f"Translation-unit validation failed: {len(issues)} issue(s)", file=sys.stderr)
        return 1
    print("Translation-unit validation passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
