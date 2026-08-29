from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path

from common import (
    REPO_ROOT,
    function_recovery_note_relative_path,
    load_functions,
    load_source_modules,
)
from status_core import build_status_rows


DEFAULT_CLEANUP_COMMITS = ("d050eea3c", "6a2aef2e2")
VA_RE = re.compile(r"(?<![0-9A-Fa-f])(?:0x)?(00[0-9A-Fa-f]{6})(?![0-9A-Fa-f])")
HUNK_RE = re.compile(r"^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@")
STANDALONE_VA_RE = re.compile(r"/(00[0-9A-Fa-f]{6})_")
COMMENT_PREFIXES = ("//", "/*", "*", "*/")
ATTEMPT_TERMS = (
    "attempt",
    "baseline",
    "binary",
    "blocker",
    "byte",
    "call",
    "checker",
    "codegen",
    "decomp",
    "differ",
    "donor",
    "exact",
    "fix",
    "frame",
    "ghidra",
    "kept",
    "layout",
    "match",
    "metric",
    "mismatch",
    "offset",
    "original",
    "probe",
    "register",
    "rejected",
    "relocation",
    "replaced",
    "restored",
    "slot",
    "stack",
    "target",
    "tested",
    "vtable",
)
CONTROL_NAMES = {"if", "for", "while", "switch", "catch", "sizeof", "return"}


@dataclass(frozen=True)
class RemovedBlock:
    commit: str
    path: str
    old_start: int
    old_end: int
    lines: tuple[str, ...]

    @property
    def text(self) -> str:
        return "\n".join(self.lines).rstrip()

    @property
    def stable_id(self) -> str:
        payload = f"{self.commit}\0{self.path}\0{self.old_start}\0{self.text}"
        return hashlib.sha256(payload.encode("utf-8", errors="surrogateescape")).hexdigest()[:20]

    @property
    def attempt_score(self) -> int:
        lowered = self.text.casefold()
        return sum(term in lowered for term in ATTEMPT_TERMS)


@dataclass(frozen=True)
class FunctionLocation:
    va: str
    name: str
    line: int


@dataclass(frozen=True)
class BlockAssignment:
    va: str
    confidence: str
    reason: str
    block: RemovedBlock


def run_git(*args: str, check: bool = True) -> str:
    result = subprocess.run(
        ["git", "-C", str(REPO_ROOT), *args],
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
        check=False,
    )
    if check and result.returncode != 0:
        raise RuntimeError(result.stderr.strip() or f"git {' '.join(args)} failed")
    return result.stdout


def cleanup_parent(commit: str) -> str:
    return run_git("rev-parse", f"{commit}^").strip()


def _is_comment_line(line: str) -> bool:
    stripped = line.strip()
    return not stripped or stripped.startswith(COMMENT_PREFIXES)


def _meaningful_comment_lines(lines: list[tuple[int, str]]) -> tuple[str, ...]:
    while lines and not lines[0][1].strip():
        lines.pop(0)
    while lines and not lines[-1][1].strip():
        lines.pop()
    return tuple(line for _number, line in lines)


def parse_removed_comment_blocks(patch: str, commit: str) -> list[RemovedBlock]:
    blocks: list[RemovedBlock] = []
    path = ""
    old_line = 0
    active: list[tuple[int, str]] = []

    def flush() -> None:
        nonlocal active
        content = _meaningful_comment_lines(active)
        if content:
            nonblank = [line for line in content if line.strip()]
            if nonblank and all(line.strip().startswith(COMMENT_PREFIXES) for line in nonblank):
                numbered = [number for number, line in active if line.strip()]
                blocks.append(
                    RemovedBlock(
                        commit=commit,
                        path=path,
                        old_start=min(numbered),
                        old_end=max(numbered),
                        lines=content,
                    )
                )
        active = []

    for raw in patch.splitlines():
        if raw.startswith("diff --git "):
            flush()
            match = re.match(r"diff --git a/(.+?) b/(.+)$", raw)
            path = match.group(1) if match else ""
            continue
        hunk = HUNK_RE.match(raw)
        if hunk:
            flush()
            old_line = int(hunk.group(1))
            continue
        if not path or raw.startswith(("index ", "--- ", "+++ ", "new file", "deleted file")):
            continue
        if raw.startswith("-"):
            text = raw[1:]
            if _is_comment_line(text):
                active.append((old_line, text))
            else:
                flush()
            old_line += 1
            continue
        if raw.startswith("+"):
            continue
        if raw.startswith(" "):
            flush()
            old_line += 1
            continue
        flush()
    flush()
    return blocks


def removed_blocks_for_commit(commit: str) -> list[RemovedBlock]:
    parent = cleanup_parent(commit)
    patch = run_git(
        "diff",
        "--no-ext-diff",
        "--no-color",
        "--unified=0",
        parent,
        commit,
        "--",
        "src",
        "include",
    )
    return parse_removed_comment_blocks(patch, commit)


def source_comment_blocks(text: str, revision: str, path: str) -> list[RemovedBlock]:
    """Extract leading C/C++ comment runs from one historical source snapshot."""
    blocks: list[RemovedBlock] = []
    active: list[tuple[int, str]] = []
    in_block = False

    def flush() -> None:
        nonlocal active
        content = _meaningful_comment_lines(active)
        if content:
            numbered = [number for number, line in active if line.strip()]
            blocks.append(
                RemovedBlock(
                    commit=revision,
                    path=path,
                    old_start=min(numbered),
                    old_end=max(numbered),
                    lines=content,
                )
            )
        active = []

    for number, line in enumerate(text.splitlines(), 1):
        stripped = line.strip()
        is_comment = False
        if in_block:
            is_comment = True
            if "*/" in stripped:
                in_block = False
        elif stripped.startswith("//"):
            is_comment = True
        elif stripped.startswith("/*"):
            is_comment = True
            in_block = "*/" not in stripped
        elif stripped.startswith("*"):
            is_comment = True

        if is_comment or (not stripped and active):
            active.append((number, line))
        else:
            flush()
    flush()
    return blocks


def historical_standalone_blocks(row: dict[str, str]) -> list[RemovedBlock]:
    """Recover the last rich comment notebook from the old VA-named source owner."""
    slug = str(row["slug"])
    candidates = [
        f"src/scratch/{slug}.cpp",
        f"src/accepted_drift/{slug}.cpp",
        f"src/verified_logic/{slug}.cpp",
        f"src/matching/{slug}.cpp",
    ]
    best: tuple[int, list[RemovedBlock]] | None = None
    for path in candidates:
        revisions = run_git("log", "--all", "-n", "16", "--format=%H", "--", path).splitlines()
        existing_versions = 0
        for revision in revisions:
            text = git_file_text(revision, path)
            if not text:
                continue
            existing_versions += 1
            blocks = [
                block
                for block in source_comment_blocks(text, revision[:12], path)
                if block.attempt_score >= 2
                or (
                    block.attempt_score == 1
                    and len([line for line in block.lines if line.strip()]) >= 2
                )
                or re.search(r"\b(?:attempt|probe|mismatch|exact|blocker)\b", block.text, re.IGNORECASE)
            ]
            score = sum(block.attempt_score * 10 + len(block.lines) for block in blocks)
            if blocks and (best is None or score > best[0]):
                best = (score, blocks)
            if existing_versions >= 3:
                break
        if best is not None:
            break
    return [] if best is None else best[1]


def target_session_assignment(row: dict[str, str]) -> BlockAssignment | None:
    """Reduce local generated probe notes into one durable historical block."""
    relative = Path("build") / "target_sessions" / f"{row['slug']}.json"
    path = REPO_ROOT / relative
    if not path.is_file():
        return None
    try:
        session = json.loads(path.read_text(encoding="utf-8"))
    except (json.JSONDecodeError, OSError):
        return None
    lines: list[str] = []
    seen_notes: set[str] = set()
    for probe in session.get("probes") or []:
        if probe.get("meaningful") is False or probe.get("kind") in {"restore", "validation"}:
            continue
        note = str(probe.get("note") or "").strip()
        if not note or note in seen_notes:
            continue
        seen_notes.add(note)
        metrics = probe.get("metrics") or {}
        summary = (
            f"probe {probe.get('number', '?')} {probe.get('kind') or 'other'}; "
            f"result={metrics.get('result') or '?'}; diff={metrics.get('diff_bytes', '?')}; "
            f"shape={metrics.get('shape_percent', '?')}: {note}"
        )
        duplicate = probe.get("same_emitted_code_as_probe")
        if duplicate is not None:
            summary += f" [same emitted code as probe {duplicate}]"
        lines.append(summary)
    if not lines:
        return None
    block = RemovedBlock(
        commit="target-session",
        path=relative.as_posix(),
        old_start=1,
        old_end=len(lines),
        lines=tuple(lines),
    )
    return BlockAssignment(
        va=str(row["va"]).upper(),
        confidence="exact",
        reason="target-session probe notes name this target",
        block=block,
    )


def git_file_text(revision: str, path: str) -> str:
    return run_git("show", f"{revision}:{path}", check=False)


def _sanitize_cpp(text: str) -> str:
    output = list(text)
    index = 0
    state = "code"
    quote = ""
    while index < len(text):
        char = text[index]
        next_char = text[index + 1] if index + 1 < len(text) else ""
        if state == "code":
            if char == "/" and next_char == "/":
                output[index] = output[index + 1] = " "
                index += 2
                state = "line-comment"
                continue
            if char == "/" and next_char == "*":
                output[index] = output[index + 1] = " "
                index += 2
                state = "block-comment"
                continue
            if char in {'"', "'"}:
                quote = char
                output[index] = " "
                index += 1
                state = "string"
                continue
        elif state == "line-comment":
            if char == "\n":
                state = "code"
            else:
                output[index] = " "
            index += 1
            continue
        elif state == "block-comment":
            if char == "*" and next_char == "/":
                output[index] = output[index + 1] = " "
                index += 2
                state = "code"
                continue
            if char != "\n":
                output[index] = " "
            index += 1
            continue
        elif state == "string":
            if char == "\\":
                output[index] = " "
                if index + 1 < len(text) and text[index + 1] != "\n":
                    output[index + 1] = " "
                index += 2
                continue
            if char == quote:
                output[index] = " "
                state = "code"
            elif char != "\n":
                output[index] = " "
            index += 1
            continue
        index += 1
    return "".join(output)


def _top_level_open_braces(text: str) -> list[int]:
    braces: list[int] = []
    depth = 0
    for index, char in enumerate(text):
        if char == "{":
            if depth == 0:
                braces.append(index)
            depth += 1
        elif char == "}" and depth:
            depth -= 1
    return braces


def _definition_name(header: str) -> str:
    candidates = re.findall(
        r"((?:[A-Za-z_]\w*(?:\s*<[^;{}()]*>)?\s*::\s*)*(?:~?[A-Za-z_]\w*|operator\s*[^\s(]+))\s*\(",
        header,
        flags=re.MULTILINE,
    )
    for raw in candidates:
        qualified = re.sub(r"\s+", "", raw)
        simple = qualified.rsplit("::", 1)[-1]
        if simple not in CONTROL_NAMES:
            return simple
    return ""


def parse_function_definitions(text: str) -> list[tuple[str, int]]:
    sanitized = _sanitize_cpp(text)
    definitions: list[tuple[str, int]] = []
    prior_boundary = 0
    for brace in _top_level_open_braces(sanitized):
        boundary = max(
            sanitized.rfind(";", prior_boundary, brace),
            sanitized.rfind("}", prior_boundary, brace),
            sanitized.rfind("{", prior_boundary, brace),
        )
        start = max(boundary + 1, brace - 1600)
        header = sanitized[start:brace]
        name = _definition_name(header)
        if name:
            definitions.append((name, sanitized.count("\n", 0, start) + 1))
        prior_boundary = brace
    return definitions


def _function_name_by_va() -> dict[str, str]:
    return {str(row["va"]).upper(): str(row["name"]) for row in load_functions()}


def function_locations_for_module(path: str, revision: str) -> list[FunctionLocation]:
    modules = {str(module["source"]): module for module in load_source_modules()}
    module = modules.get(path)
    if module is None:
        return []
    text = git_file_text(revision, path)
    if not text:
        return []
    definitions = parse_function_definitions(text)
    names = _function_name_by_va()
    functions = module["functions"]
    assert isinstance(functions, dict)
    vas_by_name: dict[str, list[str]] = defaultdict(list)
    for va in functions:
        vas_by_name[names.get(str(va).upper(), "")].append(str(va).upper())
    used: dict[str, int] = defaultdict(int)
    locations: list[FunctionLocation] = []
    for name, line in definitions:
        candidates = vas_by_name.get(name) or []
        index = used[name]
        if index >= len(candidates):
            continue
        locations.append(FunctionLocation(va=candidates[index], name=name, line=line))
        used[name] += 1
    return locations


def explicit_vas(block: RemovedBlock) -> set[str]:
    return {match.group(1).upper() for match in VA_RE.finditer(block.text)}


def declared_owner_vas(block: RemovedBlock) -> set[str]:
    owners: set[str] = set()
    patterns = (
        re.compile(r"PDB\s+source\s+owner:\s*(00[0-9A-Fa-f]{6})", re.IGNORECASE),
        re.compile(r"^\s*//\s*(?:VA:\s*)?(00[0-9A-Fa-f]{6})\b", re.IGNORECASE),
    )
    for line in block.lines:
        for pattern in patterns:
            match = pattern.search(line)
            if match:
                owners.add(match.group(1).upper())
    return owners


def _source_paths_for_rows(rows: list[dict[str, str]]) -> dict[str, set[str]]:
    by_path: dict[str, set[str]] = defaultdict(set)
    for row in rows:
        for raw in str(row.get("source_path") or "").split(" | "):
            path = raw.strip().replace("\\", "/")
            if path:
                by_path[path].add(str(row["va"]).upper())
    return by_path


def assign_blocks(
    blocks: list[RemovedBlock],
    rows: list[dict[str, str]],
    commits: tuple[str, ...],
) -> tuple[list[BlockAssignment], list[RemovedBlock], list[RemovedBlock]]:
    scratch_vas = {str(row["va"]).upper() for row in rows}
    rows_by_va = {str(row["va"]).upper(): row for row in rows}
    scratch_paths = _source_paths_for_rows(rows)
    modules = {str(module["source"]): module for module in load_source_modules()}
    location_cache: dict[tuple[str, str], list[FunctionLocation]] = {}
    assignments: list[BlockAssignment] = []
    unmapped: list[RemovedBlock] = []
    ignored: list[RemovedBlock] = []

    for block in blocks:
        if block.attempt_score == 0:
            ignored.append(block)
            continue

        standalone = STANDALONE_VA_RE.search("/" + block.path)
        if standalone and standalone.group(1).upper() in scratch_vas:
            assignments.append(
                BlockAssignment(
                    va=standalone.group(1).upper(),
                    confidence="exact",
                    reason="standalone source path names the target VA",
                    block=block,
                )
            )
            continue

        path_targets = scratch_paths.get(block.path) or set()
        if block.path not in modules and len(path_targets) == 1:
            target = next(iter(path_targets))
            assignments.append(
                BlockAssignment(
                    va=target,
                    confidence="exact",
                    reason="living standalone source path has one scratch owner",
                    block=block,
                )
            )
            continue

        declared = declared_owner_vas(block)
        if len(declared) == 1:
            target = next(iter(declared))
            if target in scratch_vas:
                assignments.append(
                    BlockAssignment(
                        va=target,
                        confidence="exact",
                        reason="removed comment declares this PDB source owner VA",
                        block=block,
                    )
                )
            else:
                ignored.append(block)
            continue

        next_location: FunctionLocation | None = None
        if block.path in modules:
            parent = cleanup_parent(block.commit)
            key = (parent, block.path)
            if key not in location_cache:
                location_cache[key] = function_locations_for_module(block.path, parent)
            following = [location for location in location_cache[key] if location.line >= block.old_end]
            if following:
                next_location = min(following, key=lambda location: location.line)
                distance = next_location.line - block.old_end
                if next_location.va in scratch_vas and distance <= 400:
                    confidence = "strong" if distance <= 80 else "ambiguous"
                    assignments.append(
                        BlockAssignment(
                            va=next_location.va,
                            confidence=confidence,
                            reason=f"next mapped function definition is {next_location.name} at old line {next_location.line}",
                            block=block,
                        )
                    )
                    continue
            preceding = [location for location in location_cache[key] if location.line <= block.old_start]
            if preceding:
                previous_location = max(preceding, key=lambda location: location.line)
                previous_distance = block.old_start - previous_location.line
                before_next = next_location is None or block.old_start < next_location.line
                if before_next and previous_location.va in scratch_vas:
                    confidence = "strong" if previous_distance <= 80 else "ambiguous"
                    assignments.append(
                        BlockAssignment(
                            va=previous_location.va,
                            confidence=confidence,
                            reason=(
                                f"comment lies after mapped function {previous_location.name} "
                                f"at old line {previous_location.line}"
                            ),
                            block=block,
                        )
                    )
                    continue
                if before_next and previous_location.va not in scratch_vas:
                    ignored.append(block)
                    continue
            if next_location is not None and next_location.va not in scratch_vas:
                ignored.append(block)
                continue

        mentioned = explicit_vas(block) & scratch_vas
        if len(mentioned) == 1:
            target = next(iter(mentioned))
            assignments.append(
                BlockAssignment(
                    va=target,
                    confidence="strong",
                    reason="removed comment names one current scratch VA",
                    block=block,
                )
            )
            continue

        if block.path in modules and any(
            str(va).upper() in scratch_vas for va in (modules[block.path]["functions"] or {})
        ):
            unmapped.append(block)
        else:
            ignored.append(block)

    deduplicated: dict[tuple[str, str], BlockAssignment] = {}
    for assignment in assignments:
        key = (assignment.va, assignment.block.stable_id)
        prior = deduplicated.get(key)
        rank = {"exact": 3, "strong": 2, "ambiguous": 1}
        if prior is None or rank[assignment.confidence] > rank[prior.confidence]:
            deduplicated[key] = assignment
    return list(deduplicated.values()), unmapped, ignored


def merge_adjacent_assignments(assignments: list[BlockAssignment]) -> list[BlockAssignment]:
    """Join fragmented cleanup hunks that belong to one adjacent function note."""
    if not assignments:
        return []
    rank = {"exact": 3, "strong": 2, "ambiguous": 1}
    ordered = sorted(
        assignments,
        key=lambda item: (item.va, item.block.commit, item.block.path, item.block.old_start),
    )
    merged: list[BlockAssignment] = []
    for assignment in ordered:
        if not merged:
            merged.append(assignment)
            continue
        prior = merged[-1]
        same_owner = (
            prior.va == assignment.va
            and prior.block.commit == assignment.block.commit
            and prior.block.path == assignment.block.path
            and prior.reason == assignment.reason
        )
        gap = assignment.block.old_start - prior.block.old_end
        if not same_owner or gap > 20:
            merged.append(assignment)
            continue
        combined = RemovedBlock(
            commit=prior.block.commit,
            path=prior.block.path,
            old_start=prior.block.old_start,
            old_end=assignment.block.old_end,
            lines=(
                *prior.block.lines,
                "// [non-comment lines omitted during migration]",
                *assignment.block.lines,
            ),
        )
        confidence = min((prior.confidence, assignment.confidence), key=lambda value: rank[value])
        merged[-1] = BlockAssignment(
            va=prior.va,
            confidence=confidence,
            reason=prior.reason,
            block=combined,
        )
    return merged


def deduplicate_assignment_text(assignments: list[BlockAssignment]) -> list[BlockAssignment]:
    seen: set[tuple[str, str]] = set()
    result: list[BlockAssignment] = []
    for assignment in assignments:
        normalized = "\n".join(line.strip() for line in assignment.block.lines if line.strip())
        digest = hashlib.sha256(normalized.encode("utf-8", errors="surrogateescape")).hexdigest()
        key = (assignment.va, digest)
        if key in seen:
            continue
        seen.add(key)
        result.append(assignment)
    by_va: dict[str, list[BlockAssignment]] = defaultdict(list)
    for assignment in result:
        by_va[assignment.va].append(assignment)

    filtered: list[BlockAssignment] = []
    for va, va_assignments in by_va.items():
        historical_lines: set[str] = set()
        for assignment in va_assignments:
            if "historical standalone source path" not in assignment.reason:
                continue
            historical_lines.update(_normalized_evidence_lines(assignment.block))
        for assignment in va_assignments:
            lines = _normalized_evidence_lines(assignment.block)
            overlap = len(lines & historical_lines) / len(lines) if lines else 0.0
            if (
                "historical standalone source path" not in assignment.reason
                and assignment.block.commit in DEFAULT_CLEANUP_COMMITS
                and len(lines) >= 3
                and overlap >= 0.6
            ):
                continue
            filtered.append(assignment)
    return filtered


def _normalized_evidence_lines(block: RemovedBlock) -> set[str]:
    lines: set[str] = set()
    for raw in block.lines:
        line = raw.strip()
        line = re.sub(r"^(?://+|/\*+|\*+|\*/+)\s?", "", line).strip()
        if not line or "non-comment lines omitted during migration" in line:
            continue
        lines.add(re.sub(r"\s+", " ", line).casefold())
    return lines


def _journal_header(row: dict[str, str]) -> str:
    source_paths = str(row.get("source_path") or "").replace(" | ", ", ") or "<missing>"
    module_note = str(row.get("recovery_note_path") or "")
    lines = [
        f"# Recovery journal: {row['va']} `{row['name']}`",
        "",
        "<!-- recovery-journal-schema:1 -->",
        "",
        "## Current state",
        "",
        f"- Status: `{row['source_bucket']}`.",
        f"- Living source: `{source_paths}`.",
        f"- PDB source: `{row.get('pdb_source_path') or row.get('pdb_source_file') or '<none>'}`.",
    ]
    if module_note:
        lines.append(f"- Earlier recovery note: `{module_note}`.")
    logic_review = str(row.get("logic_review_path") or "")
    if logic_review:
        lines.append(f"- Logic-review ledger: `{logic_review}`.")
    lines.extend(
        [
            "",
            "## Translation-unit context",
            "",
            "Record the PDB module, source order, owning class, address sequence, and exact anchors here.",
            "",
            "## Current mismatch",
            "",
            "Record the current frame, size, calls, boundaries, relocations, and first structural difference here.",
            "",
            "## Recovered attempt history",
            "",
        ]
    )
    return "\n".join(lines)


def _assignment_markdown(assignment: BlockAssignment) -> str:
    block = assignment.block
    marker = f"recovered:{block.stable_id}"
    return "\n".join(
        [
            f"<!-- {marker} -->",
            f"### `{block.commit}` `{block.path}:{block.old_start}-{block.old_end}`",
            "",
            f"Mapping: `{assignment.confidence}`. {assignment.reason}.",
            "",
            "```text",
            block.text,
            "```",
            f"<!-- end-{marker} -->",
            "",
        ]
    )


def render_journal(row: dict[str, str], assignments: list[BlockAssignment], existing: str = "") -> str:
    if existing:
        text = existing.rstrip() + "\n"
        for assignment in assignments:
            marker = f"<!-- recovered:{assignment.block.stable_id} -->"
            if marker not in text:
                text += "\n" + _assignment_markdown(assignment)
        return text.rstrip() + "\n"

    text = _journal_header(row) + "\n"
    if assignments:
        for assignment in assignments:
            text += "\n" + _assignment_markdown(assignment)
    else:
        text += "\nNo function-specific cleanup block was mapped automatically. Review the earlier note and Git history before work.\n"
    text += "\n".join(
        [
            "",
            "## Rejected approaches",
            "",
            "Record disproved source forms and repeated code-generation basins here.",
            "",
            "## Open questions",
            "",
            "Record unknown facts and the evidence needed to answer them here.",
            "",
            "## Next useful approaches",
            "",
            "Record specific evidence-led approaches for the next worker here.",
            "",
            "## Worker updates",
            "",
            "Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.",
            "",
        ]
    )
    return text


def _unmapped_archive_path(block: RemovedBlock) -> Path:
    safe = re.sub(r"[^A-Za-z0-9_.-]+", "_", block.path)
    return Path("recovery_notes") / "functions" / "_unmapped" / f"{safe}.md"


def render_unmapped_archive(path: Path, blocks: list[RemovedBlock], existing: str = "") -> str:
    text = existing.rstrip() + "\n" if existing else (
        f"# Unmapped recovered comments: `{path.stem}`\n\n"
        "These historical comment blocks came from modules with scratch owners. "
        "The migration could not assign them without guessing.\n\n"
    )
    for block in blocks:
        marker = f"<!-- recovered:{block.stable_id} -->"
        if marker in text:
            continue
        text += "\n".join(
            [
                marker,
                f"## `{block.commit}` `{block.path}:{block.old_start}-{block.old_end}`",
                "",
                "```text",
                block.text,
                "```",
                f"<!-- end-recovered:{block.stable_id} -->",
                "",
            ]
        )
    return text.rstrip() + "\n"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Recover removed matching-attempt comments into tracked per-function journals."
    )
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--audit", action="store_true", help="Analyze and report without writing tracked notes.")
    mode.add_argument("--apply", action="store_true", help="Create or update tracked recovery journals.")
    parser.add_argument(
        "--cleanup-commit",
        action="append",
        dest="cleanup_commits",
        help="Comment-cleanup commit to compare with its parent. Repeat as needed.",
    )
    parser.add_argument("--va", action="append", dest="vas", help="Limit work to one VA. Repeat as needed.")
    parser.add_argument("--limit", type=int, default=0, help="Limit sorted scratch rows after VA filtering.")
    parser.add_argument(
        "--replace-existing",
        action="store_true",
        help="Rebuild selected journals from migration evidence. Use only before workers add updates.",
    )
    parser.add_argument(
        "--report",
        default="build/recovery_journal_migration/report.json",
        help="JSON report path.",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    commits = tuple(args.cleanup_commits or DEFAULT_CLEANUP_COMMITS)
    rows = build_status_rows(
        include_source_preview=False,
        include_source_notes=False,
        include_diff_metrics=False,
        include_comment_lines=False,
        source_bucket_filter="scratch",
        corpus_bucket_filter="normal",
    )
    rows.sort(key=lambda row: str(row["va"]))
    if args.vas:
        selected = {va.upper().removeprefix("0X").zfill(8) for va in args.vas}
        rows = [row for row in rows if str(row["va"]).upper() in selected]
    if args.limit > 0:
        rows = rows[: args.limit]
    selected_vas = {str(row["va"]).upper() for row in rows}

    blocks: list[RemovedBlock] = []
    for commit in commits:
        blocks.extend(removed_blocks_for_commit(commit))
    assignments, unmapped, ignored = assign_blocks(blocks, rows, commits)
    assignments = merge_adjacent_assignments(assignments)
    historical_block_count = 0
    target_session_count = 0
    for row in rows:
        historical = historical_standalone_blocks(row)
        historical_block_count += len(historical)
        assignments.extend(
            BlockAssignment(
                va=str(row["va"]).upper(),
                confidence="exact",
                reason="historical standalone source path names this target VA",
                block=block,
            )
            for block in historical
        )
        session_assignment = target_session_assignment(row)
        if session_assignment is not None:
            assignments.append(session_assignment)
            target_session_count += 1
    assignments = deduplicate_assignment_text(merge_adjacent_assignments(assignments))
    assignments_by_va: dict[str, list[BlockAssignment]] = defaultdict(list)
    for assignment in assignments:
        if assignment.va in selected_vas:
            assignments_by_va[assignment.va].append(assignment)
    for rows_for_va in assignments_by_va.values():
        rows_for_va.sort(
            key=lambda item: (
                commits.index(item.block.commit) if item.block.commit in commits else len(commits),
                item.block.path,
                item.block.old_start,
            )
        )

    writes: list[str] = []
    if args.apply:
        for row in rows:
            relative = function_recovery_note_relative_path(str(row["va"]), str(row["slug"]))
            path = REPO_ROOT / relative
            existing = (
                ""
                if args.replace_existing
                else path.read_text(encoding="utf-8") if path.exists() else ""
            )
            rendered = render_journal(row, assignments_by_va.get(str(row["va"]).upper(), []), existing)
            if rendered != existing:
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(rendered, encoding="utf-8")
                writes.append(relative.as_posix())

        unmapped_by_path: dict[Path, list[RemovedBlock]] = defaultdict(list)
        for block in unmapped:
            unmapped_by_path[_unmapped_archive_path(block)].append(block)
        for relative, path_blocks in sorted(unmapped_by_path.items(), key=lambda item: item[0].as_posix()):
            path = REPO_ROOT / relative
            existing = (
                ""
                if args.replace_existing
                else path.read_text(encoding="utf-8") if path.exists() else ""
            )
            rendered = render_unmapped_archive(relative, path_blocks, existing)
            if rendered != existing:
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(rendered, encoding="utf-8")
                writes.append(relative.as_posix())

    confidence_counts: dict[str, int] = defaultdict(int)
    for assignment in assignments:
        confidence_counts[assignment.confidence] += 1
    report = {
        "schema": 1,
        "mode": "apply" if args.apply else "audit",
        "cleanup_commits": list(commits),
        "summary": {
            "scratch_function_count": len(rows),
            "removed_comment_block_count": len(blocks),
            "historical_standalone_block_count": historical_block_count,
            "target_session_import_count": target_session_count,
            "mapped_block_count": len(assignments),
            "mapped_function_count": len(assignments_by_va),
            "unmapped_attempt_block_count": len(unmapped),
            "ignored_block_count": len(ignored),
            "confidence_counts": dict(sorted(confidence_counts.items())),
            "journal_write_count": len([path for path in writes if "/_unmapped/" not in path]),
            "unmapped_archive_write_count": len([path for path in writes if "/_unmapped/" in path]),
        },
        "functions": [
            {
                "va": row["va"],
                "name": row["name"],
                "slug": row["slug"],
                "journal": function_recovery_note_relative_path(str(row["va"]), str(row["slug"])).as_posix(),
                "mapped_blocks": [
                    {
                        "id": assignment.block.stable_id,
                        "commit": assignment.block.commit,
                        "path": assignment.block.path,
                        "old_start": assignment.block.old_start,
                        "old_end": assignment.block.old_end,
                        "confidence": assignment.confidence,
                        "reason": assignment.reason,
                    }
                    for assignment in assignments_by_va.get(str(row["va"]).upper(), [])
                ],
            }
            for row in rows
        ],
        "unmapped_blocks": [
            {
                "id": block.stable_id,
                "commit": block.commit,
                "path": block.path,
                "old_start": block.old_start,
                "old_end": block.old_end,
            }
            for block in unmapped
        ],
        "writes": writes,
    }
    report_path = REPO_ROOT / args.report
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")

    summary = report["summary"]
    print(f"Scratch functions: {summary['scratch_function_count']}")
    print(f"Removed comment blocks: {summary['removed_comment_block_count']}")
    print(f"Mapped blocks/functions: {summary['mapped_block_count']}/{summary['mapped_function_count']}")
    print(f"Mapping confidence: {summary['confidence_counts']}")
    print(f"Unmapped attempt blocks: {summary['unmapped_attempt_block_count']}")
    if args.apply:
        print(
            "Tracked writes: "
            f"{summary['journal_write_count']} journal(s), "
            f"{summary['unmapped_archive_write_count']} archive(s)"
        )
    else:
        print("Audit only: no tracked notes changed.")
    print(f"Report: {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
