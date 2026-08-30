from __future__ import annotations

import argparse
import gzip
import hashlib
import json
import re
from dataclasses import dataclass
from datetime import datetime, timezone
from difflib import SequenceMatcher
from pathlib import Path
from typing import Iterable

from build_cache import build_artifact_lock, build_input_manifest
from common import (
    BUILD_DIR,
    INVENTORY_DIR,
    REPO_ROOT,
    compiler_artifact_slug,
    compiler_source_path,
    function_entry_for_va,
    function_record_by_va,
    function_slug,
    load_functions,
    load_toolchain,
    preferred_flags_rsp_path,
)
from source_listing import source_line_for_offset


INDEX_SCHEMA = 1
INDEX_PATH = BUILD_DIR / "asm_search" / f"matching-index-v{INDEX_SCHEMA}.json.gz"
INDEX_LOCK = BUILD_DIR / "locks" / "asm_search_index.lock"
PACKET_LINE_RE = re.compile(r"^\s*([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{2,})\s+(.+?)\s*$")
ADDRESS_LINE_RE = re.compile(r"^\s*([0-9A-Fa-f]{8})\s*[: ]\s*(.+?)\s*$")
DIRECT_TARGET_RE = re.compile(r"^(?:call|jmp)\s+([0-9A-Fa-f]{6,8})h?$", re.IGNORECASE)
BRANCH_TARGET_RE = re.compile(
    r"^(j[a-z]+|loop(?:e|ne|nz|z)?|jecxz)\s+(?:short\s+|near\s+)?([0-9A-Fa-f]{6,8})h?$",
    re.IGNORECASE,
)
REGISTER_RE = re.compile(
    r"\b(?:e(?:ax|bx|cx|dx|si|di|bp|sp)|(?:ax|bx|cx|dx|si|di|bp|sp)|[abcd][lh]|st[0-7])\b",
    re.IGNORECASE,
)
NUMBER_RE = re.compile(r"(?<![A-Za-z0-9_])(?:0x)?([0-9A-Fa-f]+)h?(?![A-Za-z0-9_])")
MEMORY_RE = re.compile(r"\[([^\]]+)\]")
SIZE_WORD_RE = re.compile(r"\b(?:short|near|far|ptr)\b\s*", re.IGNORECASE)
GPR_ROOTS = {
    "eax": ("a", "d"), "ax": ("a", "w"), "al": ("a", "l"), "ah": ("a", "h"),
    "ebx": ("b", "d"), "bx": ("b", "w"), "bl": ("b", "l"), "bh": ("b", "h"),
    "ecx": ("c", "d"), "cx": ("c", "w"), "cl": ("c", "l"), "ch": ("c", "h"),
    "edx": ("d", "d"), "dx": ("d", "w"), "dl": ("d", "l"), "dh": ("d", "h"),
    "esi": ("si", "d"), "si": ("si", "w"),
    "edi": ("di", "d"), "di": ("di", "w"),
    "ebp": ("bp", "d"), "bp": ("bp", "w"),
    "esp": ("sp", "d"), "sp": ("sp", "w"),
}
CONDITIONAL_BRANCHES = {
    "jo", "jno", "jb", "jnae", "jc", "jnb", "jae", "jnc", "je", "jz", "jne", "jnz",
    "jbe", "jna", "ja", "jnbe", "js", "jns", "jp", "jpe", "jnp", "jpo", "jl", "jnge",
    "jge", "jnl", "jle", "jng", "jg", "jnle", "jecxz", "loop", "loope", "loopne", "loopz",
    "loopnz",
}


@dataclass(frozen=True)
class Instruction:
    address: int
    offset: int
    data: str
    text: str
    mnemonic: str
    strict: str
    shape: str
    operand_classes: str

    def to_json(self) -> dict[str, object]:
        return {
            "address": self.address,
            "offset": self.offset,
            "data": self.data,
            "text": self.text,
            "mnemonic": self.mnemonic,
            "strict": self.strict,
            "shape": self.shape,
            "operand_classes": self.operand_classes,
        }

    @classmethod
    def from_json(cls, row: dict[str, object]) -> "Instruction":
        return cls(
            address=int(row["address"]),
            offset=int(row["offset"]),
            data=str(row.get("data") or ""),
            text=str(row["text"]),
            mnemonic=str(row["mnemonic"]),
            strict=str(row["strict"]),
            shape=str(row["shape"]),
            operand_classes=str(row["operand_classes"]),
        )


def packet_path(record: dict[str, str]) -> Path:
    return INVENTORY_DIR / "functions" / record["va"][:4] / f"{function_slug(record)}.txt"


def matching_source_paths() -> dict[str, Path]:
    result: dict[str, Path] = {}
    for record in load_functions():
        entry = function_entry_for_va(record["va"])
        if entry is None or entry.get("status") != "matching":
            continue
        module = entry.get("module")
        if not isinstance(module, dict):
            continue
        result[record["va"].upper()] = REPO_ROOT / str(module["source"])
    return result


def _strip_comment(text: str) -> str:
    return text.split(";", 1)[0].strip()


def _parse_number(text: str) -> int | None:
    value = text.strip().lower()
    if value.endswith("h"):
        value = value[:-1]
    if value.startswith("0x"):
        value = value[2:]
    try:
        return int(value, 16)
    except ValueError:
        return None


def _branch_direction(text: str, address: int, addresses: set[int]) -> str | None:
    match = BRANCH_TARGET_RE.match(text)
    if match is None:
        return None
    target = _parse_number(match.group(2))
    if target is None:
        return None
    if target not in addresses:
        return "external"
    return "back" if target < address else "forward"


def _register_class(name: str) -> str:
    lowered = name.lower()
    if lowered.startswith("st"):
        return "st"
    root_width = GPR_ROOTS.get(lowered)
    if root_width is None:
        return "reg"
    return "r32" if root_width[1] == "d" else "r16" if root_width[1] == "w" else "r8"


def _replace_memory_absolute(match: re.Match[str]) -> str:
    expression = match.group(1)
    has_register = REGISTER_RE.search(expression) is not None

    def replace_number(number_match: re.Match[str]) -> str:
        value = int(number_match.group(1), 16)
        if not has_register and value >= 0x10000:
            return "ABS"
        if has_register and value >= 0x10000:
            return "ABS"
        return f"{value:X}h"

    return "[" + NUMBER_RE.sub(replace_number, expression) + "]"


def _operand_class(operand: str) -> str:
    lowered = operand.lower().strip()
    width = ""
    for candidate in ("byte", "word", "dword", "qword", "tword"):
        if lowered.startswith(candidate + " "):
            width = candidate + ":"
            lowered = lowered[len(candidate):].strip()
            break
    if "[" in lowered:
        if "esp" in lowered or "ebp" in lowered:
            return width + "stack"
        if REGISTER_RE.search(lowered):
            return width + "mem"
        return width + "absolute"
    register = REGISTER_RE.fullmatch(lowered)
    if register:
        return _register_class(register.group(0))
    if _parse_number(lowered) is not None:
        return "imm"
    return "symbol"


def _split_operands(text: str) -> list[str]:
    parts = text.split(None, 1)
    if len(parts) < 2:
        return []
    return [part.strip() for part in parts[1].split(",")]


def normalize_instruction(
    text: str,
    address: int,
    addresses: set[int],
    names_by_va: dict[int, str],
) -> tuple[str, str, str, str]:
    lowered = re.sub(r"\s+", " ", SIZE_WORD_RE.sub("", text.lower())).strip()
    mnemonic = lowered.split(None, 1)[0] if lowered else ""
    direction = _branch_direction(lowered, address, addresses)
    direct = DIRECT_TARGET_RE.match(lowered)
    if direct and mnemonic == "call":
        target = _parse_number(direct.group(1))
        symbol = names_by_va.get(target or -1, f"{target:08X}" if target is not None else "unknown")
        strict = f"call {symbol.casefold()}"
        shape = "call direct"
        return mnemonic, strict, shape, "direct-call"
    if direction is not None:
        strict = f"{mnemonic} {direction}"
        return mnemonic, strict, strict, "branch"

    memory_normalized = MEMORY_RE.sub(_replace_memory_absolute, lowered)
    strict = memory_normalized
    shape = REGISTER_RE.sub(lambda match: _register_class(match.group(0)), memory_normalized)
    operands = _split_operands(lowered)
    classes = ",".join(_operand_class(operand) for operand in operands)
    return mnemonic, strict, shape, classes


def make_instructions(rows: list[tuple[int, str, str]], names_by_va: dict[int, str]) -> list[Instruction]:
    addresses = {address for address, _data, _text in rows}
    result: list[Instruction] = []
    offset = 0
    for address, data, raw_text in rows:
        text = _strip_comment(raw_text)
        if not text:
            continue
        mnemonic, strict, shape, classes = normalize_instruction(text, address, addresses, names_by_va)
        result.append(Instruction(address, offset, data.lower(), text, mnemonic, strict, shape, classes))
        byte_size = len(data) // 2 if data and len(data) % 2 == 0 else 1
        offset += max(1, byte_size)
    return result


def parse_packet_asm(path: Path, names_by_va: dict[int, str]) -> list[Instruction]:
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    try:
        start = lines.index("=== OriginalAsm ===") + 1
    except ValueError:
        return []
    rows: list[tuple[int, str, str]] = []
    for line in lines[start:]:
        if line.startswith("=== "):
            break
        match = PACKET_LINE_RE.match(line)
        if match:
            rows.append((int(match.group(1), 16), match.group(2), match.group(3)))
    return make_instructions(rows, names_by_va)


def parse_asm_text(text: str, names_by_va: dict[int, str]) -> list[Instruction]:
    rows: list[tuple[int, str, str]] = []
    synthetic_address = 0x10000000
    for raw_line in text.splitlines():
        line = _strip_comment(raw_line)
        if not line or line.endswith(":") or re.fullmatch(r"[0-9A-Fa-f]{6,8}-[0-9A-Fa-f]{6,8}", line):
            continue
        match = PACKET_LINE_RE.match(line)
        if match:
            rows.append((int(match.group(1), 16), match.group(2), match.group(3)))
            continue
        addressed = ADDRESS_LINE_RE.match(line)
        if addressed:
            rows.append((int(addressed.group(1), 16), "", addressed.group(2)))
            continue
        if re.match(r"^[A-Za-z][A-Za-z0-9]*\s*(?:\s|$)", line):
            rows.append((synthetic_address, "", line))
            synthetic_address += 1
    return make_instructions(rows, names_by_va)


def _index_fingerprint(sources: dict[str, Path]) -> str:
    inventory = INVENTORY_DIR / "all_functions.csv"
    payload = [f"schema={INDEX_SCHEMA}", f"inventory={inventory.stat().st_mtime_ns}:{inventory.stat().st_size}"]
    payload.extend(sorted(f"{va}:{path.relative_to(REPO_ROOT).as_posix()}" for va, path in sources.items()))
    return hashlib.sha256("\n".join(payload).encode("utf-8")).hexdigest()


def build_index() -> dict[str, object]:
    records = load_functions()
    names_by_va = {int(record["va"], 16): record["name"] for record in records}
    sources = matching_source_paths()
    functions: list[dict[str, object]] = []
    missing_packets = 0
    for record in records:
        slug = function_slug(record)
        source = sources.get(record["va"].upper())
        if source is None:
            continue
        packet = packet_path(record)
        if not packet.exists():
            missing_packets += 1
            continue
        instructions = parse_packet_asm(packet, names_by_va)
        if not instructions:
            missing_packets += 1
            continue
        functions.append(
            {
                "va": record["va"].upper(),
                "name": record["name"],
                "slug": slug,
                "size_bytes": int(record.get("size_bytes") or 0),
                "pdb_source_file": record.get("pdb_source_file") or "",
                "calling_convention": record.get("calling_convention") or "",
                "source_path": str(source.relative_to(REPO_ROOT)),
                "packet_path": str(packet.relative_to(REPO_ROOT)),
                "instructions": [instruction.to_json() for instruction in instructions],
            }
        )
    payload: dict[str, object] = {
        "schema": INDEX_SCHEMA,
        "generated_utc": datetime.now(timezone.utc).isoformat(),
        "fingerprint": _index_fingerprint(sources),
        "function_count": len(functions),
        "instruction_count": sum(len(row["instructions"]) for row in functions),
        "missing_packets": missing_packets,
        "functions": functions,
    }
    INDEX_PATH.parent.mkdir(parents=True, exist_ok=True)
    temporary = INDEX_PATH.with_name(INDEX_PATH.name + ".tmp")
    with gzip.open(temporary, "wt", encoding="utf-8", compresslevel=6) as handle:
        json.dump(payload, handle, separators=(",", ":"))
    temporary.replace(INDEX_PATH)
    return payload


def load_index(refresh: bool = False) -> tuple[dict[str, object], str]:
    sources = matching_source_paths()
    fingerprint = _index_fingerprint(sources)
    def cached() -> dict[str, object] | None:
        if refresh or not INDEX_PATH.exists():
            return None
        try:
            with gzip.open(INDEX_PATH, "rt", encoding="utf-8") as handle:
                payload = json.load(handle)
            if payload.get("schema") == INDEX_SCHEMA and payload.get("fingerprint") == fingerprint:
                return payload
        except (OSError, json.JSONDecodeError):
            return None
        return None

    payload = cached()
    if payload is not None:
        return payload, "cache"
    with build_artifact_lock(INDEX_LOCK):
        payload = cached()
        if payload is not None:
            return payload, "cache"
        return build_index(), "rebuilt"


def _instruction_similarity(left: Instruction, right: Instruction, profile: str) -> float:
    if left.strict == right.strict:
        return 4.5
    if profile == "strict":
        if left.mnemonic == right.mnemonic and left.operand_classes == right.operand_classes:
            return 1.2
        return 0.4 if left.mnemonic == right.mnemonic else -2.0
    if left.mnemonic == right.mnemonic:
        if left.shape == right.shape:
            return 4.1 if profile == "structural" else 3.7
        if left.operand_classes == right.operand_classes:
            return 3.1 if profile == "structural" else 2.7
        return 2.0 if profile == "structural" else 1.6
    if left.mnemonic in CONDITIONAL_BRANCHES and right.mnemonic in CONDITIONAL_BRANCHES:
        return 1.0
    return -2.0


def _canonical_tokens(instructions: Iterable[Instruction]) -> list[str]:
    roots: dict[str, str] = {}

    def replace(match: re.Match[str]) -> str:
        lowered = match.group(0).lower()
        if lowered.startswith("st"):
            return lowered
        root, width = GPR_ROOTS.get(lowered, (lowered, "?"))
        if root not in roots:
            roots[root] = f"R{len(roots)}"
        return roots[root] + width

    return [REGISTER_RE.sub(replace, instruction.strict) for instruction in instructions]


def align_fragment(
    query: list[Instruction], donor: list[Instruction], profile: str = "mapped"
) -> dict[str, object] | None:
    if not query or not donor:
        return None
    query_size = len(query)
    gap = 1.75
    previous_score = [0.0] * (query_size + 1)
    previous_qstart = [0] * (query_size + 1)
    previous_dstart = [0] * (query_size + 1)
    previous_pairs = [0] * (query_size + 1)
    best: tuple[float, int, int, int, int, int] | None = None

    for donor_index, donor_instruction in enumerate(donor):
        score = [0.0] * (query_size + 1)
        qstart = [0] * (query_size + 1)
        dstart = [donor_index] * (query_size + 1)
        pairs = [0] * (query_size + 1)
        for query_index, query_instruction in enumerate(query, 1):
            similarity = _instruction_similarity(query_instruction, donor_instruction, profile)
            options = (
                (0.0, query_index - 1, donor_index, 0),
                (
                    previous_score[query_index - 1] + similarity,
                    (
                        previous_qstart[query_index - 1]
                        if previous_score[query_index - 1] > 0
                        else query_index - 1
                    ),
                    (
                        previous_dstart[query_index - 1]
                        if previous_score[query_index - 1] > 0
                        else donor_index
                    ),
                    previous_pairs[query_index - 1] + 1,
                ),
                (
                    previous_score[query_index] - gap,
                    previous_qstart[query_index],
                    previous_dstart[query_index],
                    previous_pairs[query_index],
                ),
                (
                    score[query_index - 1] - gap,
                    qstart[query_index - 1],
                    dstart[query_index - 1],
                    pairs[query_index - 1],
                ),
            )
            chosen = max(options, key=lambda row: row[0])
            score[query_index], qstart[query_index], dstart[query_index], pairs[query_index] = chosen
            if score[query_index] <= 0:
                continue
            candidate = (
                score[query_index],
                qstart[query_index],
                query_index,
                dstart[query_index],
                donor_index + 1,
                pairs[query_index],
            )
            if best is None or candidate[0] > best[0]:
                best = candidate
        previous_score, previous_qstart, previous_dstart, previous_pairs = score, qstart, dstart, pairs

    if best is None:
        return None
    raw_score, query_start, query_end, donor_start, donor_end, pair_count = best
    query_coverage = (query_end - query_start) / query_size
    query_slice = query[query_start:query_end]
    donor_slice = donor[donor_start:donor_end]
    canonical_ratio = SequenceMatcher(
        None, _canonical_tokens(query_slice), _canonical_tokens(donor_slice), autojunk=False
    ).ratio()
    raw_ratio = min(1.0, raw_score / (4.5 * query_size))
    coverage_factor = 0.45 + 0.55 * query_coverage
    consistency_factor = 1.0 if profile != "mapped" else 0.82 + 0.18 * canonical_ratio
    score_percent = 100.0 * raw_ratio * coverage_factor * consistency_factor
    longest_block = max(
        (
            block.size
            for block in SequenceMatcher(
                None,
                [row.shape for row in query_slice],
                [row.shape for row in donor_slice],
                autojunk=False,
            ).get_matching_blocks()
        ),
        default=0,
    )
    return {
        "score": round(score_percent, 3),
        "raw_score": round(raw_score, 3),
        "query_start": query_start,
        "query_end": query_end,
        "donor_start": donor_start,
        "donor_end": donor_end,
        "query_coverage": round(query_coverage, 4),
        "canonical_ratio": round(canonical_ratio, 4),
        "aligned_pairs": pair_count,
        "longest_shape_block": longest_block,
    }


def _source_excerpt(
    row: dict[str, object], instructions: list[Instruction], context: int, max_lines: int
) -> dict[str, object]:
    source = REPO_ROOT / str(row["source_path"])
    lines = source.read_text(encoding="utf-8", errors="replace").splitlines()
    source_map = BUILD_DIR / "asm" / f"rebuilt_{row['slug']}.lines.json"
    mapped_lines: list[int] = []
    if source_map.exists() and source_map.stat().st_mtime_ns >= source.stat().st_mtime_ns:
        try:
            metadata = json.loads(source_map.read_text(encoding="utf-8"))
            mapped_lines = sorted(
                {
                    line
                    for instruction in instructions
                    if (line := source_line_for_offset(metadata, instruction.offset)) is not None
                }
            )
        except (OSError, json.JSONDecodeError):
            mapped_lines = []
    if mapped_lines:
        start = max(1, min(mapped_lines) - context)
        end = min(len(lines), max(mapped_lines) + context)
        mapping = "VC5 listing"
    else:
        name = str(row["name"])
        candidates = [
            index for index, line in enumerate(lines)
            if name in line and "(" in line and not line.lstrip().startswith("//") and ";" not in line
        ]
        start = (candidates[-1] + 1) if candidates else 1
        end = len(lines)
        mapping = "function fallback"
    if max_lines and end - start + 1 > max_lines:
        end = start + max_lines - 1
    rendered = [f"{number:5d}: {lines[number - 1]}" for number in range(start, end + 1)]
    return {"mapping": mapping, "start_line": start, "end_line": end, "text": "\n".join(rendered)}


def current_validation(
    row: dict[str, object],
    toolchain: dict,
    records_by_va: dict[str, dict[str, str]],
) -> dict[str, object]:
    """Return authoritative current-check evidence for one matching-bank source."""
    slug = str(row["slug"])
    diff_path = BUILD_DIR / "diff" / f"{slug}.json"
    if not diff_path.exists():
        return {"status": "unchecked", "reason": "no current build/diff artifact"}
    try:
        record = records_by_va[str(row["va"]).upper()]
    except (KeyError, ValueError) as error:
        return {"status": "stale", "reason": f"could not resolve source owner: {error}"}
    try:
        build_slug = compiler_artifact_slug(record)
    except KeyError:
        build_slug = slug
    manifest_path = BUILD_DIR / "manifests" / f"build_{build_slug}.json"
    if not manifest_path.exists():
        return {"status": "unchecked", "reason": "no current build artifact"}
    try:
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        diff = json.loads(diff_path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return {"status": "unchecked", "reason": "unreadable build/diff artifact"}
    if manifest.get("returncode") != 0:
        return {"status": "stale", "reason": "last build failed"}
    try:
        try:
            source = compiler_source_path(record)
        except KeyError:
            source = REPO_ROOT / str(row["source_path"])
        rsp_path = preferred_flags_rsp_path(record, toolchain)
        current = build_input_manifest(source, rsp_path, toolchain)
    except (OSError, KeyError, ValueError) as error:
        return {"status": "stale", "reason": f"could not fingerprint current inputs: {error}"}
    if manifest.get("input_fingerprint") != current.get("fingerprint"):
        return {"status": "stale", "reason": "source/flags/includes/toolchain changed since build"}
    object_text = str(manifest.get("object") or "")
    object_path = Path(object_text) if object_text else Path()
    if not object_text or not object_path.exists() or diff_path.stat().st_mtime_ns < object_path.stat().st_mtime_ns:
        return {"status": "stale", "reason": "diff predates the current object"}
    # Requiring this key rejects artifacts from the older relocation-masking
    # checker that could report MATCH despite a wrong direct-call symbol.
    if "relocation_target_mismatches" not in diff:
        return {"status": "stale", "reason": "checker artifact predates direct-call identity validation"}
    if diff.get("result") != "MATCH" or diff.get("relocation_target_mismatches"):
        return {
            "status": "mismatch",
            "reason": f"current checker result is {diff.get('result') or 'unknown'}",
        }
    extraction = diff.get("rebuilt_extraction") or {}
    if extraction.get("size_status") == "code-overflow" or extraction.get("boundary_escape_offsets"):
        return {"status": "mismatch", "reason": "entry-reachable code exceeds the original boundary"}
    return {
        "status": "fresh-match",
        "reason": "current input fingerprint and authoritative checker MATCH",
        "input_fingerprint": str(current["fingerprint"]),
    }


def search_index(
    payload: dict[str, object],
    query: list[Instruction],
    *,
    profile: str = "mapped",
    exclude_va: str = "",
    include_self: bool = False,
    min_score: float | None = None,
    min_coverage: float | None = None,
    limit: int = 0,
    source_context: int = 0,
    max_source_lines: int = 0,
    source_results: int = 0,
    query_pdb_source: str = "",
    candidate_pool: int = 0,
    validation: str = "fresh",
    validation_scan: int = 0,
) -> list[dict[str, object]]:
    def ngrams(values: list[str], size: int) -> set[tuple[str, ...]]:
        return {tuple(values[index:index + size]) for index in range(max(0, len(values) - size + 1))}

    query_mnemonics = [row.mnemonic for row in query]
    query_shapes = [row.shape for row in query]
    query_strict = [row.strict for row in query]
    query_mnemonic_set = set(query_mnemonics)
    query_mnemonic_bigrams = ngrams(query_mnemonics, 2)
    query_mnemonic_trigrams = ngrams(query_mnemonics, 3)
    query_shape_bigrams = ngrams(query_shapes, 2)
    query_strict_bigrams = ngrams(query_strict, 2)
    prescored: list[tuple[float, dict[str, object]]] = []
    for row in payload["functions"]:
        assert isinstance(row, dict)
        if not include_self and exclude_va and str(row["va"]).upper() == exclude_va.upper():
            continue
        instructions = row["instructions"]
        mnemonics = [str(item["mnemonic"]) for item in instructions]
        shapes = [str(item["shape"]) for item in instructions]
        strict = [str(item["strict"]) for item in instructions]
        prefilter_score = (
            10.0 * len(query_strict_bigrams & ngrams(strict, 2))
            + 6.0 * len(query_shape_bigrams & ngrams(shapes, 2))
            + 4.0 * len(query_mnemonic_trigrams & ngrams(mnemonics, 3))
            + 2.0 * len(query_mnemonic_bigrams & ngrams(mnemonics, 2))
            + len(query_mnemonic_set & set(mnemonics)) / max(1, len(query_mnemonic_set))
        )
        prescored.append((prefilter_score, row))
    prescored.sort(key=lambda item: (-item[0], str(item[1]["va"])))
    if candidate_pool:
        prescored = prescored[:candidate_pool]

    candidates: list[dict[str, object]] = []
    for prefilter_score, row in prescored:
        donor = [Instruction.from_json(item) for item in row["instructions"]]
        alignment = align_fragment(query, donor, profile)
        if alignment is None:
            continue
        if min_score is not None and float(alignment["score"]) < min_score:
            continue
        if min_coverage is not None and float(alignment["query_coverage"]) < min_coverage:
            continue
        same_tu = (
            bool(query_pdb_source)
            and str(row.get("pdb_source_file") or "").casefold() == query_pdb_source.casefold()
        )
        donor_start = int(alignment["donor_start"])
        donor_end = int(alignment["donor_end"])
        matched = donor[donor_start:donor_end]
        result = {key: value for key, value in row.items() if key != "instructions"}
        result.update(alignment)
        result["prefilter_score"] = round(prefilter_score, 3)
        result["same_pdb_tu"] = same_tu
        result["match_start_address"] = f"{matched[0].address:08X}"
        result["match_end_address"] = f"{matched[-1].address:08X}"
        result["match_instruction_count"] = len(matched)
        result["matched_asm"] = [
            f"{instruction.address:08X}  {instruction.data:<16}  {instruction.text}" for instruction in matched
        ]
        result["_matched_instructions"] = matched
        candidates.append(result)
    candidates.sort(
        key=lambda row: (
            -float(row["score"]),
            -int(bool(row["same_pdb_tu"])),
            -float(row["query_coverage"]),
            -int(row["longest_shape_block"]),
            str(row["va"]),
        )
    )
    toolchain = load_toolchain() if validation == "fresh" else {}
    records_by_va = {record["va"].upper(): record for record in load_functions()} if validation == "fresh" else {}
    selected: list[dict[str, object]] = []
    scanned = 0
    for candidate in candidates:
        if limit and len(selected) >= limit:
            break
        if validation == "fresh":
            if validation_scan and scanned >= validation_scan:
                break
            scanned += 1
            evidence = current_validation(candidate, toolchain, records_by_va)
            if evidence["status"] != "fresh-match":
                continue
            candidate["validation"] = evidence
        else:
            candidate["validation"] = {
                "status": "matching-status",
                "reason": "the source-module status is matching; fresh checker evidence was not required",
            }
        selected.append(candidate)
    for index, result in enumerate(selected):
        matched = result.pop("_matched_instructions")
        if source_results == 0 or index < source_results:
            result["source_excerpt"] = _source_excerpt(result, matched, source_context, max_source_lines)
        else:
            result["source_excerpt"] = None
    return selected


def _parse_range(value: str, base: int) -> tuple[int, int]:
    if "-" not in value:
        raise ValueError("range must be START-END, for example +70-+A5 or 00401070-004010A5")
    start_text, end_text = value.split("-", 1)

    def parse_part(part: str) -> int:
        part = part.strip()
        return base + int(part[1:], 16) if part.startswith("+") else int(part.removeprefix("0x"), 16)

    start, end = parse_part(start_text), parse_part(end_text)
    if end < start:
        raise ValueError("range end precedes start")
    return start, end


def _parse_at(value: str, base: int) -> int:
    value = value.strip()
    return base + int(value[1:], 16) if value.startswith("+") else int(value.removeprefix("0x"), 16)


def _basic_block_at(instructions: list[Instruction], address: int) -> list[Instruction]:
    if not instructions:
        return []
    addresses = {row.address for row in instructions}
    leaders = {0}
    for index, instruction in enumerate(instructions):
        branch = BRANCH_TARGET_RE.match(instruction.text.lower())
        if branch:
            target = _parse_number(branch.group(2))
            if target in addresses:
                leaders.add(next(i for i, row in enumerate(instructions) if row.address == target))
        if instruction.mnemonic in CONDITIONAL_BRANCHES or instruction.mnemonic in {"jmp", "ret", "retn", "retf"}:
            if index + 1 < len(instructions):
                leaders.add(index + 1)
    ordered = sorted(leaders)
    containing = max((index for index, row in enumerate(instructions) if row.address <= address), default=-1)
    if containing < 0:
        return []
    start = max(leader for leader in ordered if leader <= containing)
    end = next((leader for leader in ordered if leader > containing), len(instructions))
    return instructions[start:end]


def format_report(report: dict[str, object], source_results: int) -> str:
    query = report["query"]
    assert isinstance(query, dict)
    lines = [
        f"Assembly donor search: {query['description']}",
        f"Query: {query['instruction_count']} instructions, profile={report['profile']}, "
        f"validation={report['validation_mode']}",
        f"Corpus: {report['corpus_function_count']} matching-bank functions / "
        f"{report['corpus_instruction_count']} instructions; aligned pool={report['candidate_pool']} "
        f"(index {report['index_status']})",
        "Policy: hits are exact-source codegen examples, not proof that the target used the same source.",
        "",
        "Query assembly:",
    ]
    lines.extend(f"  {item}" for item in query["asm"])
    results = report["results"]
    assert isinstance(results, list)
    lines.extend(["", f"Ranked donors ({len(results)}):"])
    if not results:
        lines.append("  <none>")
    for index, row in enumerate(results, 1):
        same_tu = " same-TU" if row["same_pdb_tu"] else ""
        lines.extend(
            [
                "",
                f"{index:02d}. score={float(row['score']):5.1f} coverage={float(row['query_coverage']) * 100:4.0f}% "
                f"canonical={float(row['canonical_ratio']) * 100:4.0f}%{same_tu}",
                f"    {row['va']} {row['name']}  [{row['match_start_address']}-{row['match_end_address']}]",
                f"    source={row['source_path']}  packet={row['packet_path']}",
                f"    validation={row['validation']['status']}: {row['validation']['reason']}",
                f"    evidence: aligned_pairs={row['aligned_pairs']} longest_shape_block={row['longest_shape_block']} "
                f"TU={row['pdb_source_file'] or '<none>'}",
                "    Matched assembly:",
            ]
        )
        lines.extend(f"      {item}" for item in row["matched_asm"])
        excerpt = row.get("source_excerpt")
        if excerpt and (source_results == 0 or index <= source_results):
            lines.append(
                f"    Source excerpt ({excerpt['mapping']}, lines {excerpt['start_line']}-{excerpt['end_line']}):"
            )
            lines.extend(f"      {item}" for item in str(excerpt["text"]).splitlines())
    return "\n".join(lines) + "\n"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=(
            "Search exact functions for a local assembly pattern and show its C/C++ source.\n"
            "\n"
            "Use a distinctive block of roughly 5-20 instructions. Avoid generic prologues and\n"
            "epilogues. Fresh validation is authoritative; bank validation trusts folder status.\n"
            "A hit is codegen evidence, not proof of common source, layout, or ABI.\n"
            "\n"
            "Examples:\n"
            "  python tools/search_asm_donors.py --va 004407A0 --range +80-+C0\n"
            "  python tools/search_asm_donors.py --va 004407A0 --at +9A\n"
        )
    )
    query = parser.add_mutually_exclusive_group(required=True)
    query.add_argument("--va", help="Function VA whose original assembly supplies the query.")
    query.add_argument(
        "--asm-file", type=Path, help="Text file containing disassembly or plain assembly instructions."
    )
    selection = parser.add_mutually_exclusive_group()
    selection.add_argument(
        "--range",
        dest="asm_range",
        help="Inclusive VA/offset range: +70-+A5 or 00401070-004010A5.",
    )
    selection.add_argument("--at", help="VA/offset inside a basic block; selects that complete block.")
    parser.add_argument("--profile", choices=("strict", "mapped", "structural"), default="mapped")
    parser.add_argument("--limit", type=int, default=0, help="Maximum results (default 0, all results).")
    parser.add_argument("--min-score", type=float, help="Optional minimum alignment score.")
    parser.add_argument("--min-coverage", type=float, help="Optional minimum query coverage.")
    parser.add_argument(
        "--candidate-pool",
        type=int,
        default=0,
        help="N-gram-prefiltered functions to align (default 0, full matching bank).",
    )
    parser.add_argument(
        "--validation",
        choices=("fresh", "bank"),
        default="fresh",
        help="fresh requires a current authoritative checker MATCH (default); bank trusts folder ownership only.",
    )
    parser.add_argument(
        "--validation-scan",
        type=int,
        default=0,
        help="Maximum aligned hits fingerprinted while seeking fresh matches (default 0, all hits).",
    )
    parser.add_argument("--include-self", action="store_true", help="Include the query VA in results.")
    parser.add_argument("--source-results", type=int, default=0, help="Top hits with source excerpts (default 0, all hits).")
    parser.add_argument("--source-context", type=int, default=0)
    parser.add_argument("--max-source-lines", type=int, default=0, help="Maximum source lines per excerpt (default 0, all lines).")
    parser.add_argument("--refresh-index", action="store_true")
    parser.add_argument("--json", action="store_true")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    if args.limit < 0 or args.source_results < 0 or args.candidate_pool < 0 or args.validation_scan < 0:
        raise SystemExit(
            "--limit, --validation-scan, --source-results, and --candidate-pool must be nonnegative"
        )
    records = load_functions()
    names_by_va = {int(record["va"], 16): record["name"] for record in records}
    exclude_va = ""
    query_pdb_source = ""
    if args.va:
        base = int(args.va, 16)
        record = function_record_by_va(base)
        exclude_va = record["va"].upper()
        query_pdb_source = record.get("pdb_source_file") or ""
        query_instructions = parse_packet_asm(packet_path(record), names_by_va)
        description = f"{record['va']} {record['name']}"
        if args.asm_range:
            start, end = _parse_range(args.asm_range, base)
            query_instructions = [row for row in query_instructions if start <= row.address <= end]
            description += f" range {start:08X}-{end:08X}"
        elif args.at:
            at = _parse_at(args.at, base)
            query_instructions = _basic_block_at(query_instructions, at)
            description += f" basic block at {at:08X}"
    else:
        path = args.asm_file if args.asm_file.is_absolute() else REPO_ROOT / args.asm_file
        query_instructions = parse_asm_text(path.read_text(encoding="utf-8", errors="replace"), names_by_va)
        description = str(path)
        if args.asm_range or args.at:
            raise SystemExit("--range/--at currently require --va")
    if not query_instructions:
        raise SystemExit("Query contains no parsed instructions")

    payload, index_status = load_index(args.refresh_index)
    results = search_index(
        payload,
        query_instructions,
        profile=args.profile,
        exclude_va=exclude_va,
        include_self=args.include_self,
        min_score=args.min_score,
        min_coverage=args.min_coverage,
        limit=args.limit,
        source_context=args.source_context,
        max_source_lines=args.max_source_lines,
        source_results=args.source_results,
        query_pdb_source=query_pdb_source,
        candidate_pool=args.candidate_pool,
        validation=args.validation,
        validation_scan=args.validation_scan,
    )
    report: dict[str, object] = {
        "version": 1,
        "profile": args.profile,
        "index_status": index_status,
        "index_path": str(INDEX_PATH.relative_to(REPO_ROOT)),
        "corpus_function_count": payload["function_count"],
        "corpus_instruction_count": payload["instruction_count"],
        "candidate_pool": args.candidate_pool or payload["function_count"],
        "validation_mode": args.validation,
        "query": {
            "description": description,
            "va": exclude_va,
            "instruction_count": len(query_instructions),
            "asm": [f"{row.address:08X}  {row.data:<16}  {row.text}" for row in query_instructions],
        },
        "policy": [
            "The corpus contains only matching-status owners. Default fresh validation also requires "
            "current checker MATCH evidence.",
            "A similar emitted block is empirical source/codegen evidence, not proof of common "
            "original source.",
            "Listing-derived source lines are approximate under optimization; fallback excerpts are "
            "function-level only.",
        ],
        "results": results,
    }
    print(json.dumps(report, indent=2) if args.json else format_report(report, args.source_results), end="")


if __name__ == "__main__":
    main()
