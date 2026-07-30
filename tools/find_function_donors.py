from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

from common import REPO_ROOT, function_record_by_va, function_slug, load_functions, preferred_source_path
from target_dossier import infer_class_name


CALL_RE = re.compile(r"\bcall\s+([0-9a-f]{8})h\b", re.IGNORECASE)
VSLOT_RE = re.compile(r"\bcall\s+dword\s+\[e(?:ax|bx|cx|dx|si|di|bp)\+([0-9a-f]+)h\]", re.IGNORECASE)
MEMORY_RE = re.compile(r"\[[^\]]*?([+-])([0-9a-f]+)h(?:[^\]]*)\]", re.IGNORECASE)
SUB_ESP_RE = re.compile(r"\bsub\s+esp,([0-9a-f]+)h?\b", re.IGNORECASE)
PUSH_REG_RE = re.compile(r"\bpush\s+(e(?:bx|bp|si|di))\b", re.IGNORECASE)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Rank exact-match donor functions by TU, class, ABI, call, field-offset, and prologue similarity."
    )
    parser.add_argument("--va", required=True, help="Target function VA in hex.")
    parser.add_argument("--limit", type=int, default=20, help="Maximum donors (default 20; 0 all scored candidates).")
    parser.add_argument("--min-score", type=float, default=5.0)
    parser.add_argument("--include-accepted-drift", action="store_true")
    parser.add_argument("--json", action="store_true")
    return parser.parse_args()


def packet_path(record: dict[str, str]) -> Path:
    return REPO_ROOT / "inventory" / "functions" / record["va"][:4] / f"{function_slug(record)}.txt"


def source_owner_paths(include_accepted: bool = False) -> dict[str, tuple[str, Path]]:
    buckets = [("matching", REPO_ROOT / "src" / "matching")]
    if include_accepted:
        buckets.append(("accepted_drift", REPO_ROOT / "src" / "accepted_drift"))
    result: dict[str, tuple[str, Path]] = {}
    for bucket, root in buckets:
        if not root.exists():
            continue
        for path in root.iterdir():
            if path.suffix.lower() in {".c", ".cpp"}:
                result[path.stem] = (bucket, path)
    return result


def _original_asm_lines(path: Path) -> list[str]:
    if not path.exists():
        return []
    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    try:
        start = lines.index("=== OriginalAsm ===") + 1
    except ValueError:
        return []
    end = next((index for index in range(start, len(lines)) if lines[index].startswith("=== ")), len(lines))
    return lines[start:end]


def packet_features(path: Path, names_by_va: dict[int, str]) -> dict[str, object]:
    lines = _original_asm_lines(path)
    calls: set[str] = set()
    vslots: set[int] = set()
    displacements: set[int] = set()
    saved_registers: list[str] = []
    frame_size = 0
    eh_frame = False
    for index, line in enumerate(lines):
        lowered = line.lower()
        call = CALL_RE.search(lowered)
        if call:
            address = int(call.group(1), 16)
            calls.add(names_by_va.get(address, f"{address:08X}").casefold())
        slot = VSLOT_RE.search(lowered)
        if slot:
            vslots.add(int(slot.group(1), 16))
        for sign, value in MEMORY_RE.findall(lowered):
            displacement = int(value, 16)
            if sign == "-":
                displacement = -displacement
            if 0 <= displacement <= 0x4000:
                displacements.add(displacement)
        if index < 40:
            frame = SUB_ESP_RE.search(lowered)
            if frame and frame_size == 0:
                frame_size = int(frame.group(1), 16)
            pushed = PUSH_REG_RE.search(lowered)
            if pushed and pushed.group(1).lower() not in saved_registers:
                saved_registers.append(pushed.group(1).lower())
            if "fs:" in lowered:
                eh_frame = True
    return {
        "calls": calls,
        "vslots": vslots,
        "displacements": displacements,
        "frame_size": frame_size,
        "saved_registers": saved_registers,
        "eh_frame": eh_frame,
    }


def _jaccard(left: set, right: set) -> float:
    if not left and not right:
        return 0.0
    return len(left & right) / len(left | right)


def _name_tokens(value: str) -> set[str]:
    spaced = re.sub(r"([a-z0-9])([A-Z])", r"\1 \2", value)
    return {token.casefold() for token in re.split(r"[^A-Za-z0-9]+", spaced) if len(token) >= 3}


def _function_family(record: dict[str, str], class_name: str) -> str:
    name = record.get("name", "")
    if name.startswith("~"):
        return "destructor"
    if class_name and name.casefold() == class_name.casefold():
        return "constructor"
    lowered = name.casefold()
    if "deleting_destructor" in lowered:
        return "deleting-destructor"
    if lowered in {"load", "save", "setup", "update", "draw"}:
        return lowered
    return "ordinary"


def preliminary_score(target: dict, donor: dict) -> tuple[float, list[str]]:
    score = 0.0
    reasons: list[str] = []
    if target["pdb_source_file"] and target["pdb_source_file"].casefold() == donor["pdb_source_file"].casefold():
        score += 45
        reasons.append("same PDB translation unit +45")
    if target["class_name"] and target["class_name"].casefold() == donor["class_name"].casefold():
        score += 35
        reasons.append("same inferred owner class +35")
    if target["family"] == donor["family"] and target["family"] != "ordinary":
        score += 10
        reasons.append(f"same {target['family']} family +10")
    if target["calling_convention"] == donor["calling_convention"]:
        score += 4
        reasons.append("same calling convention +4")
    target_size = max(1, int(target["size_bytes"]))
    donor_size = max(1, int(donor["size_bytes"]))
    size_score = 8 * min(target_size, donor_size) / max(target_size, donor_size)
    score += size_score
    if size_score >= 5:
        reasons.append(f"similar size +{size_score:.1f}")
    token_score = 10 * _jaccard(_name_tokens(target["name"]), _name_tokens(donor["name"]))
    score += token_score
    if token_score:
        reasons.append(f"name-token overlap +{token_score:.1f}")
    return score, reasons


def score_donor(target: dict, donor: dict) -> tuple[float, list[str]]:
    score, reasons = preliminary_score(target, donor)
    target_features = target.get("packet_features") or {}
    donor_features = donor.get("packet_features") or {}
    axes = (
        ("calls", 25.0, "direct-call overlap"),
        ("vslots", 20.0, "virtual-slot overlap"),
        ("displacements", 8.0, "memory-displacement overlap"),
    )
    for key, weight, label in axes:
        overlap = _jaccard(set(target_features.get(key) or []), set(donor_features.get(key) or []))
        contribution = weight * overlap
        score += contribution
        if contribution >= 1:
            reasons.append(f"{label} +{contribution:.1f}")
    if target_features.get("eh_frame") == donor_features.get("eh_frame"):
        score += 5
        reasons.append(f"same EH-frame class +5")
    if target_features.get("frame_size") == donor_features.get("frame_size"):
        score += 4
        reasons.append("same frame size +4")
    register_overlap = _jaccard(
        set(target_features.get("saved_registers") or []),
        set(donor_features.get("saved_registers") or []),
    )
    if register_overlap:
        contribution = 4 * register_overlap
        score += contribution
        reasons.append(f"saved-register overlap +{contribution:.1f}")
    return score, reasons


def _record_feature(record: dict[str, str], source: Path) -> dict[str, object]:
    class_name = infer_class_name(source) if source.exists() else ""
    return {
        "va": record["va"],
        "name": record["name"],
        "slug": function_slug(record),
        "size_bytes": int(record.get("size_bytes") or 0),
        "calling_convention": record.get("calling_convention", ""),
        "pdb_source_file": record.get("pdb_source_file", ""),
        "pdb_source_path": record.get("pdb_source_path", ""),
        "class_name": class_name,
        "family": _function_family(record, class_name),
        "source_path": str(source.relative_to(REPO_ROOT)) if source.exists() else "",
        "packet_path": str(packet_path(record).relative_to(REPO_ROOT)),
    }


def find_donors(va: int, include_accepted: bool = False, limit: int = 20, min_score: float = 5.0) -> dict[str, object]:
    target_record = function_record_by_va(va)
    target_source = preferred_source_path(target_record)
    target = _record_feature(target_record, target_source)
    owners = source_owner_paths(include_accepted)
    records = load_functions()
    names_by_va = {int(row["va"], 16): row["name"] for row in records}
    candidates = []
    for record in records:
        if record["va"] == target_record["va"]:
            continue
        owner = owners.get(function_slug(record))
        if owner is None:
            continue
        bucket, source = owner
        donor = _record_feature(record, source)
        donor["source_bucket"] = bucket
        score, reasons = preliminary_score(target, donor)
        donor["preliminary_score"] = score
        donor["reasons"] = reasons
        candidates.append(donor)

    candidates.sort(key=lambda row: (-float(row["preliminary_score"]), abs(int(row["size_bytes"]) - int(target["size_bytes"])), row["va"]))
    pool_size = min(len(candidates), max(300, (limit or 20) * 20))
    pool = candidates[:pool_size]
    target["packet_features"] = packet_features(packet_path(target_record), names_by_va)
    for donor in pool:
        donor_record = next(row for row in records if row["va"] == donor["va"])
        donor["packet_features"] = packet_features(packet_path(donor_record), names_by_va)
        score, reasons = score_donor(target, donor)
        donor["score"] = round(score, 3)
        donor["reasons"] = reasons
    pool = [row for row in pool if float(row["score"]) >= min_score]
    pool.sort(key=lambda row: (-float(row["score"]), -float(row["preliminary_score"]), row["va"]))
    if limit:
        pool = pool[:limit]
    return {
        "version": 1,
        "target": target,
        "policy": [
            "Ranking is heuristic donor discovery, not proof of shared source or canonical ABI.",
            "Matching sources are exact codegen evidence; accepted-drift donors are labeled and opt-in.",
            "Memory-displacement overlap is intentionally low weight because not every displacement is a this-field.",
        ],
        "candidate_pool_scored": pool_size,
        "donors": pool,
    }


def format_report(payload: dict[str, object]) -> str:
    target = payload["target"]
    assert isinstance(target, dict)
    lines = [
        f"Function donors for {target['va']} {target['name']}",
        f"Target: donor={target['pdb_source_file'] or '<none>'} class={target['class_name'] or '<unknown>'} "
        f"family={target['family']} size={target['size_bytes']}",
        f"Candidate pool with packet features: {payload['candidate_pool_scored']}",
        "",
        "Policy:",
    ]
    for item in payload["policy"]:
        lines.append(f"  - {item}")
    donors = payload["donors"]
    assert isinstance(donors, list)
    lines.extend(["", f"Ranked donors ({len(donors)}):"])
    if not donors:
        lines.append("  <none above threshold>")
    for index, donor in enumerate(donors, 1):
        lines.append(
            f"  {index:02d} score={float(donor['score']):6.2f} {donor['va']} {donor['name']} "
            f"[{donor['source_bucket']}]"
        )
        lines.append(
            f"     TU={donor['pdb_source_file'] or '<none>'} class={donor['class_name'] or '<unknown>'} "
            f"size={donor['size_bytes']} source={donor['source_path']}"
        )
        lines.append("     " + "; ".join(donor["reasons"]))
    return "\n".join(lines) + "\n"


def main() -> None:
    args = parse_args()
    if args.limit < 0:
        raise SystemExit("--limit must be zero or positive")
    payload = find_donors(
        int(args.va, 16),
        include_accepted=args.include_accepted_drift,
        limit=args.limit,
        min_score=args.min_score,
    )
    print(json.dumps(payload, indent=2, default=list) if args.json else format_report(payload))


if __name__ == "__main__":
    main()
