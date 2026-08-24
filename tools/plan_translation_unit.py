from __future__ import annotations

"""Create one current PDB-module packet or rank candidate modules."""

import argparse
import json
from collections import Counter
from pathlib import Path

from common import (
    REPO_ROOT,
    load_pdb_function_source_map,
    load_translation_units,
    slugify_name,
)
from status_core import build_status_rows


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Create a current PDB translation-unit work packet or rank modules."
    )
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument(
        "--module",
        help="Exact PDB source basename or full path, for example move_obj.cpp.",
    )
    mode.add_argument(
        "--rank",
        action="store_true",
        help="Rank all normal PDB modules by current exact-source readiness.",
    )
    parser.add_argument("--limit", type=int, default=30, help="Maximum ranked modules to show.")
    parser.add_argument(
        "--unregistered-only",
        action="store_true",
        help="With --rank, show only PDB modules without a registered exact owner.",
    )
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=REPO_ROOT / "build" / "tu_plans",
        help="Generated packet directory.",
    )
    return parser.parse_args()


def _normalized_path(value: str) -> str:
    return value.replace("/", "\\").casefold()


def _module_path(row: dict[str, str], pdb_row: dict[str, str]) -> str:
    return str(
        pdb_row.get("primary_source_path")
        or row.get("pdb_source_path")
        or row.get("pdb_source_file")
        or ""
    ).strip()


def _registered_owner_map() -> dict[str, str]:
    result: dict[str, str] = {}
    for group in load_translation_units():
        for va in group["owners"]:
            result[str(va).upper()] = str(group["name"])
    return result


def _module_groups(
    rows: list[dict[str, str]], pdb_map: dict[str, dict[str, str]]
) -> dict[str, list[dict[str, str]]]:
    result: dict[str, list[dict[str, str]]] = {}
    for row in rows:
        if row["corpus_bucket"] != "normal":
            continue
        module_path = _module_path(row, pdb_map.get(row["va"].upper(), {}))
        if not module_path:
            continue
        result.setdefault(_normalized_path(module_path), []).append(row)
    return result


def rank_modules(
    rows: list[dict[str, str]],
    pdb_map: dict[str, dict[str, str]],
    limit: int,
    *,
    unregistered_only: bool = False,
) -> list[dict[str, object]]:
    ranked: list[dict[str, object]] = []
    registered = _registered_owner_map()
    for module_rows in _module_groups(rows, pdb_map).values():
        banks = Counter(row["source_bucket"] for row in module_rows)
        normal_count = len(module_rows)
        matching = banks["matching"]
        scratch = banks["scratch"]
        module_path = _module_path(
            module_rows[0], pdb_map.get(module_rows[0]["va"].upper(), {})
        )
        if Path(module_path.replace("\\", "/")).suffix.casefold() not in {
            ".c",
            ".cc",
            ".cpp",
            ".cxx",
        }:
            continue
        registered_exact = sum(row["va"].upper() in registered for row in module_rows)
        registered_groups = sorted(
            {registered[row["va"].upper()] for row in module_rows if row["va"].upper() in registered}
        )
        if unregistered_only and registered_groups:
            continue
        unregistered_matching = matching - registered_exact
        ranked.append(
            {
                "module": Path(module_path.replace("\\", "/")).name,
                "pdb_source_path": module_path,
                "normal_owners": normal_count,
                "normal_bytes": sum(int(row["size_bytes"]) for row in module_rows),
                "matching": matching,
                "accepted_drift": banks["accepted_drift"],
                "verified_logic": banks["verified_logic"],
                "scratch": scratch,
                "unclaimed": banks["unclaimed"],
                "registered_exact": registered_exact,
                "registered_groups": registered_groups,
                "registration_status": "registered" if registered_groups else "missing",
                "unregistered_matching": unregistered_matching,
                "matching_ratio": round(matching / normal_count, 4),
                "readiness_score": round(1000 * unregistered_matching / normal_count)
                + min(unregistered_matching, 100) * 2
                - scratch * 10
                - banks["unclaimed"] * 12
                - max(0, normal_count - 150),
            }
        )
    ranked.sort(
        key=lambda item: (
            -int(item["readiness_score"]),
            -float(item["matching_ratio"]),
            -int(item["normal_owners"]),
            str(item["pdb_source_path"]).casefold(),
        )
    )
    return ranked if limit == 0 else ranked[: max(0, limit)]


def build_packet(
    module_query: str,
    rows: list[dict[str, str]],
    pdb_map: dict[str, dict[str, str]],
) -> dict[str, object]:
    groups = _module_groups(rows, pdb_map)
    query_path = _normalized_path(module_query)
    query_name = Path(module_query.replace("\\", "/")).name.casefold()
    matches = [
        (path, module_rows)
        for path, module_rows in groups.items()
        if path == query_path
        or Path(path.replace("\\", "/")).name.casefold() == query_name
    ]
    if not matches:
        raise ValueError(f"No normal PDB module matches {module_query!r}")
    if len(matches) > 1:
        choices = ", ".join(sorted(path for path, _ in matches))
        raise ValueError(f"Module basename {module_query!r} is ambiguous: {choices}")

    _, selected = matches[0]
    registered = _registered_owner_map()
    owners: list[dict[str, object]] = []
    for row in selected:
        va = row["va"].upper()
        pdb_row = pdb_map.get(va, {})
        try:
            line_start = int(str(pdb_row.get("line_start") or 0))
            line_end = int(str(pdb_row.get("line_end") or 0))
        except ValueError:
            line_start = line_end = 0
        owners.append(
            {
                "va": va,
                "name": row["name"],
                "size_bytes": int(row["size_bytes"]),
                "source_bucket": row["source_bucket"],
                "source_path": row["source_path"],
                "pdb_lines": [line_start, line_end],
                "pdb_symbol": str(pdb_row.get("symbol_name") or ""),
                "diff_result": row["diff_result"],
                "positional_diff_bytes": (
                    int(row["positional_diff_bytes"])
                    if row["positional_diff_bytes"]
                    else None
                ),
                "custom_flags_path": row["custom_flags_path"],
                "registered_tu": registered.get(va, ""),
                "blocker": row["source_blocker"],
            }
        )
    owners.sort(key=lambda item: (item["pdb_lines"][0] or 1 << 30, int(item["va"], 16)))

    module_path = _module_path(selected[0], pdb_map.get(selected[0]["va"].upper(), {}))
    banks = Counter(str(owner["source_bucket"]) for owner in owners)
    min_va = min(int(owner["va"], 16) for owner in owners)
    max_va = max(int(owner["va"], 16) for owner in owners)
    nearby_generated = [
        {
            "va": row["va"].upper(),
            "name": row["name"],
            "size_bytes": int(row["size_bytes"]),
            "reason": row["corpus_reason"],
        }
        for row in rows
        if row["corpus_bucket"] == "compiler_generated"
        and min_va <= int(row["va"], 16) <= max_va
    ]

    return {
        "schema": 1,
        "module": Path(module_path.replace("\\", "/")).name,
        "pdb_source_path": module_path,
        "summary": {
            "normal_owners": len(owners),
            "normal_bytes": sum(int(owner["size_bytes"]) for owner in owners),
            "source_banks": dict(sorted(banks.items())),
            "registered_exact": sum(bool(owner["registered_tu"]) for owner in owners),
        },
        "nearby_compiler_generated": nearby_generated,
        "owners": owners,
    }


def render_packet(packet: dict[str, object]) -> str:
    summary = packet["summary"]
    assert isinstance(summary, dict)
    lines = [
        f"Module: {packet['pdb_source_path']}",
        f"Normal owners: {summary['normal_owners']}",
        f"Normal bytes: {summary['normal_bytes']}",
        f"Source banks: {json.dumps(summary['source_banks'], sort_keys=True)}",
        f"Registered exact: {summary['registered_exact']}",
        "",
        "VA        LINES       BANK             SIZE  DIFF  REGISTERED  NAME",
    ]
    owners = packet["owners"]
    assert isinstance(owners, list)
    for owner in owners:
        assert isinstance(owner, dict)
        start, end = owner["pdb_lines"]
        lines.append(
            f"{owner['va']}  {start:>5}-{end:<5}  {owner['source_bucket']:<16} "
            f"{owner['size_bytes']:>5}  {str(owner['positional_diff_bytes'] or ''):>4}  "
            f"{str(owner['registered_tu'] or '-'):<10}  {owner['name']}"
        )
    generated = packet["nearby_compiler_generated"]
    assert isinstance(generated, list)
    if generated:
        lines.extend(["", "Nearby compiler-generated entries:"])
        for row in generated:
            lines.append(
                f"  {row['va']} {row['size_bytes']}B {row['name']} ({row['reason']})"
            )
    return "\n".join(lines) + "\n"


def render_ranking(rows: list[dict[str, object]]) -> str:
    lines = [
        "SCORE  UNREG  SCRATCH  OWNERS  REGISTERED  MODULE",
    ]
    for row in rows:
        lines.append(
            f"{row['readiness_score']:>5}  {row['unregistered_matching']:>5}  {row['scratch']:>7}  "
            f"{row['normal_owners']:>6}  {row['registered_exact']:>10}  {row['pdb_source_path']}"
        )
    return "\n".join(lines) + "\n"


def main() -> int:
    args = parse_args()
    rows = build_status_rows(
        include_source_preview=False,
        include_source_notes=False,
        include_diff_metrics=True,
        include_comment_lines=False,
    )
    pdb_map = load_pdb_function_source_map()
    args.output_dir.mkdir(parents=True, exist_ok=True)

    if args.rank:
        ranking = rank_modules(
            rows,
            pdb_map,
            args.limit,
            unregistered_only=args.unregistered_only,
        )
        json_path = args.output_dir / "ranking.json"
        text_path = args.output_dir / "ranking.txt"
        json_path.write_text(json.dumps(ranking, indent=2) + "\n", encoding="utf-8")
        text = render_ranking(ranking)
        text_path.write_text(text, encoding="utf-8")
        print(text, end="")
        print(f"Wrote {json_path}")
        print(f"Wrote {text_path}")
        return 0

    try:
        packet = build_packet(args.module, rows, pdb_map)
    except ValueError as error:
        print(error)
        return 1
    output_dir = args.output_dir / slugify_name(str(packet["module"]))
    output_dir.mkdir(parents=True, exist_ok=True)
    json_path = output_dir / "packet.json"
    text_path = output_dir / "packet.txt"
    json_path.write_text(json.dumps(packet, indent=2) + "\n", encoding="utf-8")
    text = render_packet(packet)
    text_path.write_text(text, encoding="utf-8")
    print(text, end="")
    print(f"Wrote {json_path}")
    print(f"Wrote {text_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
