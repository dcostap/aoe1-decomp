from __future__ import annotations

"""Validate configured grouped translation units and their build ownership.

This tool checks source ownership before a grouped object is used for matching.
It does not infer ownership from object names. Build manifests are evidence of
compiler inputs, so an isolated manifest is stale when a newer grouped manifest
already compiled that owner.
"""

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
    load_functions,
    load_pdb_function_source_map,
    load_translation_units,
    preferred_source_path,
    slugify_name,
)
from extract_obj_function import select_exact_function_symbol, select_record_function_symbol
from function_diagnostics import owning_function_symbol_validation


_HEX_VA = re.compile(r"^[0-9A-Fa-f]{8}$")
_INCLUDE = re.compile(r'^\s*#\s*include\s*"([^"]+)"(?:\s*//.*)?\s*$')


@dataclass(frozen=True)
class ValidationIssue:
    code: str
    message: str

    def __str__(self) -> str:
        return f"{self.code}: {self.message}"


def _issue(code: str, message: str) -> ValidationIssue:
    return ValidationIssue(code, message)


def _relative_path(path: Path, root: Path) -> str:
    """Return one stable slash-normalized path for manifest comparison."""
    try:
        return path.resolve().relative_to(root.resolve()).as_posix()
    except ValueError:
        return path.resolve().as_posix().lower()


def _manifest_path(value: object, root: Path) -> str:
    if not isinstance(value, str) or not value.strip():
        return ""
    raw = value.strip().replace("\\", "/")
    candidate = Path(raw)
    if not candidate.is_absolute():
        candidate = root / candidate
    return _relative_path(candidate, root)


def _resolve_path(value: object, root: Path) -> Path:
    """Resolve one manifest path without using the process-global repository."""
    raw = str(value or "").strip().replace("\\", "/")
    candidate = Path(raw)
    return candidate if candidate.is_absolute() else root / candidate


def _owner_include_positions(source: Path, owner: Path) -> list[int]:
    """Find all direct includes that resolve to one owner path."""
    try:
        lines = source.read_text(encoding="utf-8").splitlines()
    except OSError:
        return []

    positions: list[int] = []
    owner_resolved = owner.resolve()
    for index, line in enumerate(lines):
        match = _INCLUDE.match(line)
        if match is None:
            continue
        include_path = (source.parent / Path(match.group(1).replace("\\", "/"))).resolve()
        if include_path == owner_resolved:
            positions.append(index)
    return positions


def _all_local_includes(source: Path) -> list[tuple[int, Path]]:
    try:
        lines = source.read_text(encoding="utf-8").splitlines()
    except OSError:
        return []

    includes: list[tuple[int, Path]] = []
    for index, line in enumerate(lines):
        match = _INCLUDE.match(line)
        if match is None:
            continue
        includes.append(
            (
                index,
                (source.parent / Path(match.group(1).replace("\\", "/"))).resolve(),
            )
        )
    return includes


def _function_records() -> dict[str, dict[str, str]]:
    return {row["va"].upper(): row for row in load_functions()}


def _mapped_owner_symbols(
    group: dict[str, object], object_dir: Path, records: dict[str, dict[str, str]]
) -> dict[str, str] | None:
    """Resolve each configured owner to its defined grouped-object symbol."""
    name = slugify_name(str(group.get("name") or ""))
    object_path = object_dir / f"tu_{name}.obj"
    if not object_path.is_file():
        return None
    try:
        obj = load_coff_object(object_path)
    except (OSError, ValueError, KeyError):
        return {}

    symbols = group.get("symbols")
    exact_symbols = (
        {str(key).upper(): value for key, value in symbols.items()}
        if isinstance(symbols, dict)
        else {}
    )
    result: dict[str, str] = {}
    for va in (group.get("owners") or {}):
        key = str(va).upper()
        try:
            exact_name = exact_symbols.get(key)
            if exact_name:
                symbol = select_exact_function_symbol(obj, str(exact_name))
            else:
                record = records[key]
                symbol = select_record_function_symbol(obj, record["name"])
        except (KeyError, ValueError):
            continue
        result[key] = symbol.name
    return result


def _grouped_owner_paths_from_manifest(payload: dict[str, object], root: Path) -> set[str]:
    inputs = payload.get("build_inputs")
    if not isinstance(inputs, dict):
        return set()
    raw_inputs = inputs.get("inputs")
    if not isinstance(raw_inputs, list):
        return set()
    paths: set[str] = set()
    for item in raw_inputs:
        if not isinstance(item, dict):
            continue
        normalized = _manifest_path(item.get("path"), root)
        if normalized:
            paths.add(normalized)
    return paths


def _manifest_mtime(path: Path) -> int:
    try:
        return path.stat().st_mtime_ns
    except OSError:
        return -1


def find_isolated_owner_overlaps(
    groups: Iterable[dict[str, object]],
    *,
    manifests_dir: Path,
    root: Path = REPO_ROOT,
) -> list[ValidationIssue]:
    """Find current isolated build manifests that own grouped source files.

    A grouped build manifest records owner files in ``build_inputs.inputs``.
    If it is newer than an isolated manifest for the same owner, the isolated
    manifest is old cache history and is not an active competing owner.
    """
    owner_to_group: dict[str, str] = {}
    for group in groups:
        group_name = str(group.get("name") or "<unnamed>")
        owners = group.get("owners")
        if not isinstance(owners, dict):
            continue
        for owner in owners.values():
            normalized = _manifest_path(owner, root)
            if normalized:
                owner_to_group[normalized] = group_name

    if not manifests_dir.is_dir():
        return []

    # Identify grouped manifests by their wrapper source, not only by the
    # conventional ``build_tu_`` filename. This keeps the check useful for
    # hand-created or future manifest names.
    grouped_wrappers = {
        _manifest_path(group.get("source"), root): str(group.get("name") or "<unnamed>")
        for group in groups
        if _manifest_path(group.get("source"), root)
    }
    grouped_manifest_paths: list[tuple[Path, set[str]]] = []
    manifest_payloads: dict[Path, dict[str, object]] = {}
    for manifest_path in sorted(manifests_dir.glob("build_*.json")):
        try:
            payload = json.loads(manifest_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue
        if isinstance(payload, dict):
            manifest_payloads[manifest_path] = payload
            source = _manifest_path(payload.get("source"), root)
            if source in grouped_wrappers:
                grouped_manifest_paths.append(
                    (manifest_path, _grouped_owner_paths_from_manifest(payload, root))
                )

    issues: list[ValidationIssue] = []
    for manifest_path, payload in manifest_payloads.items():
        if manifest_path.name.startswith("build_tu_"):
            continue
        source = _manifest_path(payload.get("source"), root)
        if not source:
            inputs = payload.get("build_inputs")
            source = _manifest_path(inputs.get("source") if isinstance(inputs, dict) else None, root)
        group_name = owner_to_group.get(source)
        if group_name is None:
            continue

        isolated_mtime = _manifest_mtime(manifest_path)
        superseded = any(
            source in owner_paths and _manifest_mtime(grouped_path) >= isolated_mtime
            for grouped_path, owner_paths in grouped_manifest_paths
            if grouped_path.is_file()
        )
        if superseded:
            continue
        issues.append(
            _issue(
                "isolated-owner-overlap",
                f"{manifest_path} builds grouped owner {source} outside TU {group_name}",
            )
        )
    return issues


def validate_translation_units(
    groups: Iterable[dict[str, object]],
    *,
    root: Path = REPO_ROOT,
    manifests_dir: Path | None = None,
    object_dir: Path | None = None,
) -> list[ValidationIssue]:
    """Return all structural issues in grouped translation-unit manifests."""
    groups = list(groups)
    root = root.resolve()
    records = _function_records()
    pdb_sources = load_pdb_function_source_map()
    issues: list[ValidationIssue] = []
    seen_names: dict[str, str] = {}
    seen_sources: dict[str, str] = {}
    seen_vas: dict[str, str] = {}
    seen_owner_paths: dict[str, str] = {}

    for group in groups:
        name = str(group.get("name") or "").strip()
        source_value = str(group.get("source") or "").strip()
        group_label = name or "<unnamed>"
        if not name:
            issues.append(_issue("missing-name", "translation unit has no name"))
        elif name in seen_names:
            issues.append(_issue("duplicate-name", f"{name} is also used by {seen_names[name]}"))
        else:
            seen_names[name] = group_label

        source = _resolve_path(source_value, root)
        source_key = _manifest_path(source_value, root)
        if source_key in seen_sources and source_key:
            issues.append(
                _issue("duplicate-source", f"{source_value} is also used by {seen_sources[source_key]}"),
            )
        elif source_key:
            seen_sources[source_key] = group_label

        if not source_value:
            issues.append(_issue("missing-source", f"{group_label} has no wrapper source"))
        elif not source.is_file():
            issues.append(_issue("missing-source", f"{group_label} wrapper is missing: {source}"))
        elif source.suffix.lower() != ".cpp":
            issues.append(_issue("wrapper-extension", f"{group_label} wrapper is not C++: {source}"))

        flags = str(group.get("flags") or "").strip()
        if flags and not _resolve_path(flags, root).is_file():
            issues.append(_issue("missing-flags", f"{group_label} flags are missing: {flags}"))

        owners = group.get("owners")
        if not isinstance(owners, dict) or not owners:
            issues.append(_issue("missing-owners", f"{group_label} has no owners"))
            continue

        owner_records: list[tuple[str, Path, dict[str, str] | None]] = []
        for raw_va, raw_owner in owners.items():
            va = str(raw_va).upper()
            owner_value = str(raw_owner).replace("\\", "/").strip()
            if not _HEX_VA.fullmatch(va):
                issues.append(_issue("invalid-va", f"{group_label} has invalid owner VA {raw_va!r}"))
                continue
            if va in seen_vas:
                issues.append(_issue("duplicate-va", f"VA {va} is also owned by {seen_vas[va]}"))
            else:
                seen_vas[va] = group_label
            if not owner_value:
                issues.append(_issue("missing-owner", f"{group_label} has an empty owner for {va}"))
                continue

            owner_path = _resolve_path(owner_value, root)
            owner_key = _manifest_path(owner_value, root)
            if owner_key in seen_owner_paths:
                issues.append(
                    _issue(
                        "duplicate-owner-path",
                        f"{owner_value} is also a compiler-facing owner for {seen_owner_paths[owner_key]}",
                    )
                )
            else:
                seen_owner_paths[owner_key] = f"{group_label}:{va}"
            record = records.get(va)
            if record is None:
                issues.append(_issue("unknown-va", f"{group_label} owner {va} is absent from inventory"))
            elif owner_path.resolve() != preferred_source_path(record).resolve():
                issues.append(
                    _issue(
                        "noncanonical-owner",
                        f"{group_label} owner {va} is {owner_value}, expected {preferred_source_path(record)}",
                    )
                )
            if not str((pdb_sources.get(va) or {}).get("symbol_name") or "").strip():
                issues.append(
                    _issue(
                        "missing-pdb-symbol",
                        f"{group_label} owner {va} has no PDB-qualified symbol ownership",
                    )
                )
            if not owner_path.is_file():
                issues.append(_issue("missing-owner", f"{group_label} owner {va} is missing: {owner_value}"))
            owner_records.append((va, owner_path, record))

        symbols = group.get("symbols", {})
        if symbols is None:
            symbols = {}
        if not isinstance(symbols, dict):
            issues.append(_issue("invalid-symbols", f"{group_label} symbols are not an object"))
            symbols = {}

        symbol_values: set[str] = set()
        for raw_va, raw_symbol in symbols.items():
            va = str(raw_va).upper()
            symbol = str(raw_symbol).strip()
            if va not in {entry[0] for entry in owner_records}:
                issues.append(_issue("symbol-not-owner", f"{group_label} symbol VA {va} is not an owner"))
            if not symbol or any(character.isspace() for character in symbol):
                issues.append(_issue("invalid-symbol", f"{group_label} has invalid exact symbol for {va}"))
            if symbol in symbol_values:
                issues.append(_issue("duplicate-symbol", f"{group_label} maps more than one VA to {symbol}"))
            symbol_values.add(symbol)

        names = [record["name"] for _, _, record in owner_records if record is not None]
        duplicate_names = {name for name in names if names.count(name) > 1}
        for va, _, record in owner_records:
            if record is not None and record["name"] in duplicate_names and va not in symbols:
                issues.append(
                    _issue(
                        "missing-exact-symbol",
                        f"{group_label} must map exact symbol for duplicate owner {va} ({record['name']})",
                    )
                )

        if object_dir is not None:
            owner_symbols = _mapped_owner_symbols(group, object_dir, records)
            if owner_symbols is not None:
                for va, _, record in owner_records:
                    actual_symbol = owner_symbols.get(va)
                    if actual_symbol is None:
                        issues.append(
                            _issue(
                                "symbol-not-defined",
                                f"{group_label} owner {va} has no uniquely selected grouped-object symbol",
                            )
                        )
                        continue
                    pdb_symbol = str((pdb_sources.get(va) or {}).get("symbol_name") or "").strip()
                    if not pdb_symbol:
                        continue
                    expected_name = record["name"] if record is not None else ""
                    owner_validation = owning_function_symbol_validation(
                        expected_name,
                        actual_symbol,
                        pdb_symbol,
                    )
                    if owner_validation["status"] != "match":
                        issues.append(
                            _issue(
                                "pdb-owner-mismatch",
                                f"{group_label} owner {va} PDB {pdb_symbol!r} does not match "
                                f"grouped symbol {actual_symbol!r}",
                            )
                        )

        if source.is_file():
            positions: list[int] = []
            known_owner_paths = {owner.resolve() for _, owner, _ in owner_records}
            for va, owner_path, _ in owner_records:
                matches = _owner_include_positions(source, owner_path)
                if len(matches) != 1:
                    issues.append(
                        _issue(
                            "owner-include-count",
                            f"{group_label} must include {owner_path} once; found {len(matches)} for {va}",
                        )
                    )
                positions.append(matches[0] if matches else -1)

            valid_positions = [position for position in positions if position >= 0]
            if valid_positions != sorted(valid_positions):
                issues.append(_issue("owner-include-order", f"{group_label} owner includes are out of manifest order"))

            for _, included_path in _all_local_includes(source):
                if included_path in known_owner_paths:
                    continue
                other = seen_owner_paths.get(_manifest_path(included_path, root))
                if other is not None:
                    issues.append(
                        _issue(
                            "foreign-owner-include",
                            f"{group_label} includes owner {included_path} belonging to {other}",
                        )
                    )

    if manifests_dir is not None:
        issues.extend(find_isolated_owner_overlaps(groups, manifests_dir=manifests_dir, root=root))
    return issues


def _parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Validate configured grouped translation units.")
    parser.add_argument(
        "--manifests-dir",
        type=Path,
        default=REPO_ROOT / "build" / "manifests",
        help="Build manifest directory used for isolated-owner overlap checks.",
    )
    parser.add_argument(
        "--objects-dir",
        type=Path,
        default=REPO_ROOT / "build" / "obj",
        help="Grouped COFF object directory used for exact symbol checks.",
    )
    parser.add_argument(
        "--no-build-checks",
        action="store_true",
        help="Skip build object and isolated-manifest checks.",
    )
    return parser.parse_args()


def main() -> int:
    args = _parse_args()
    kwargs: dict[str, object] = {}
    if not args.no_build_checks:
        kwargs["manifests_dir"] = args.manifests_dir
        kwargs["object_dir"] = args.objects_dir
    issues = validate_translation_units(load_translation_units(), **kwargs)
    if issues:
        for issue in issues:
            print(issue, file=sys.stderr)
        print(f"Translation-unit validation failed: {len(issues)} issue(s)", file=sys.stderr)
        return 1
    print("Translation-unit validation passed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
