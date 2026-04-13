from __future__ import annotations

import csv
import re
from pathlib import Path

from common import REPO_ROOT, load_functions


HEADER_NOTE_RE = re.compile(r"^//\s*([A-Z_]+):\s*(.*)$")


def source_files(path: Path) -> dict[str, Path]:
    files: dict[str, Path] = {}
    if not path.exists():
        return files
    for child in sorted(path.iterdir()):
        if child.suffix.lower() not in {".c", ".cpp"}:
            continue
        files[child.stem] = child
    return files


def parse_header_notes(path: Path) -> dict[str, str]:
    notes = {
        "STATUS": "",
        "FLAGS": "",
        "BLOCKER": "",
        "NOTE": "",
        "CLASS": "",
        "RISK": "",
        "WHY": "",
        "NEXT": "",
    }
    if not path.exists():
        return notes

    lines = path.read_text(encoding="utf-8", errors="replace").splitlines()
    for line in lines:
        stripped = line.strip()
        if not stripped:
            continue
        if not stripped.startswith("//"):
            break
        match = HEADER_NOTE_RE.match(stripped)
        if match is None:
            continue
        key = match.group(1)
        value = match.group(2).strip()
        if key not in notes:
            continue
        if key == "NOTE" and notes[key]:
            notes[key] = notes[key] + " | " + value
        else:
            notes[key] = value
    return notes


def rank_map(records: list[dict[str, str]], field: str) -> dict[str, int]:
    ordered = sorted(records, key=lambda row: (-int(row[field]), row["va"]))
    return {row["va"]: index + 1 for index, row in enumerate(ordered)}


def main() -> None:
    scratch_dir = REPO_ROOT / "src" / "scratch"
    almost_matched_dir = REPO_ROOT / "src" / "almost_matched"
    matching_dir = REPO_ROOT / "src" / "matching"
    flags_dir = REPO_ROOT / "config" / "flags"
    scratch_files = source_files(scratch_dir)
    almost_matched_files = source_files(almost_matched_dir)
    matching_files = source_files(matching_dir)

    records = load_functions()
    remaining_records: list[dict[str, str]] = []
    rows: list[dict[str, str]] = []

    for record in records:
        slug = record["slug"]
        scratch_path = scratch_files.get(slug)
        almost_matched_path = almost_matched_files.get(slug)
        matching_path = matching_files.get(slug)

        present_paths = [path for path in (matching_path, almost_matched_path, scratch_path) if path is not None]
        if len(present_paths) > 1:
            source_bucket = "conflict"
            source_path = " | ".join(str(path.relative_to(REPO_ROOT)) for path in present_paths)
            note_path = scratch_path or almost_matched_path
        elif matching_path:
            source_bucket = "matching"
            source_path = str(matching_path.relative_to(REPO_ROOT))
            note_path = None
        elif almost_matched_path:
            source_bucket = "almost_matched"
            source_path = str(almost_matched_path.relative_to(REPO_ROOT))
            note_path = almost_matched_path
        elif scratch_path:
            source_bucket = "scratch"
            source_path = str(scratch_path.relative_to(REPO_ROOT))
            note_path = scratch_path
        else:
            source_bucket = "unclaimed"
            source_path = ""
            note_path = None

        custom_flags_path = flags_dir / f"{slug}.rsp"
        header_notes = parse_header_notes(note_path) if note_path is not None else {
            "STATUS": "",
            "FLAGS": "",
            "BLOCKER": "",
            "NOTE": "",
            "CLASS": "",
            "RISK": "",
            "WHY": "",
            "NEXT": "",
        }
        is_remaining = "yes" if source_bucket != "matching" else "no"

        row = {
            "va": record["va"],
            "name": record["name"],
            "slug": slug,
            "size_bytes": record["size_bytes"],
            "asm_lines": record["asm_lines"],
            "calling_convention": record["calling_convention"],
            "source_bucket": source_bucket,
            "source_path": source_path,
            "is_remaining": is_remaining,
            "remaining_size_rank": "",
            "remaining_asm_rank": "",
            "uses_custom_flags": "yes" if custom_flags_path.exists() else "no",
            "custom_flags_path": str(custom_flags_path.relative_to(REPO_ROOT)) if custom_flags_path.exists() else "",
            "source_status": header_notes["STATUS"],
            "source_flags_note": header_notes["FLAGS"],
            "source_blocker": header_notes["BLOCKER"],
            "source_note": header_notes["NOTE"],
            "source_class": header_notes["CLASS"],
            "source_risk": header_notes["RISK"],
            "source_why": header_notes["WHY"],
            "source_next": header_notes["NEXT"],
            "has_blocker": "yes" if header_notes["BLOCKER"] else "no",
        }
        rows.append(row)
        if is_remaining == "yes":
            remaining_records.append(record)

    size_ranks = rank_map(remaining_records, "size_bytes")
    asm_ranks = rank_map(remaining_records, "asm_lines")
    for row in rows:
        if row["is_remaining"] == "yes":
            row["remaining_size_rank"] = str(size_ranks[row["va"]])
            row["remaining_asm_rank"] = str(asm_ranks[row["va"]])

    output_path = REPO_ROOT / "project_full_status.csv"
    with output_path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "va",
                "name",
                "slug",
                "size_bytes",
                "asm_lines",
                "calling_convention",
                "source_bucket",
                "source_path",
                "is_remaining",
                "remaining_size_rank",
                "remaining_asm_rank",
                "uses_custom_flags",
                "custom_flags_path",
                "source_status",
                "source_flags_note",
                "source_blocker",
                "source_note",
                "source_class",
                "source_risk",
                "source_why",
                "source_next",
                "has_blocker",
            ],
        )
        writer.writeheader()
        writer.writerows(rows)

    scratch_count = sum(1 for row in rows if row["source_bucket"] == "scratch")
    almost_matched_count = sum(1 for row in rows if row["source_bucket"] == "almost_matched")
    matching_count = sum(1 for row in rows if row["source_bucket"] == "matching")
    conflict_count = sum(1 for row in rows if row["source_bucket"] == "conflict")
    unclaimed_count = sum(1 for row in rows if row["source_bucket"] == "unclaimed")

    print(f"Wrote {output_path}")
    print(
        "Counts: "
        f"matching={matching_count} "
        f"almost_matched={almost_matched_count} "
        f"scratch={scratch_count} "
        f"unclaimed={unclaimed_count} "
        f"conflict={conflict_count}"
    )


if __name__ == "__main__":
    main()
