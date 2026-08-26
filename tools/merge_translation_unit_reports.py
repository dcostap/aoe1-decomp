from __future__ import annotations

"""Merge focused TU audits into one complete report without recompiling stable TUs."""

import argparse
from collections import Counter
import json
from pathlib import Path

from audit_translation_unit_observed import build_queue, queue_text, text_report
from common import REPO_ROOT, load_translation_units


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Replace groups in one complete TU report with focused audit results."
    )
    parser.add_argument("--base-report", type=Path, required=True)
    parser.add_argument(
        "--update-report",
        type=Path,
        action="append",
        default=[],
        help="Focused report. Repeat in replacement order; later reports win.",
    )
    parser.add_argument("--output-dir", type=Path, required=True)
    return parser.parse_args()


def load_report(path: Path) -> dict[str, object]:
    payload = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(payload, dict) or payload.get("schema") != 1:
        raise ValueError(f"Invalid TU report: {path}")
    if not isinstance(payload.get("groups"), list):
        raise ValueError(f"TU report has no group list: {path}")
    return payload


def merge_reports(
    base: dict[str, object],
    updates: list[dict[str, object]],
    registered_groups: list[dict[str, object]],
) -> dict[str, object]:
    base_groups = base["groups"]
    assert isinstance(base_groups, list)
    by_name = {str(group["group"]): group for group in base_groups}
    registered_names = [str(group["name"]) for group in registered_groups]
    if set(by_name) != set(registered_names):
        missing = sorted(set(registered_names) - set(by_name))
        extra = sorted(set(by_name) - set(registered_names))
        raise ValueError(f"Base report group mismatch; missing={missing}, extra={extra}")

    for update in updates:
        update_groups = update["groups"]
        assert isinstance(update_groups, list)
        for group in update_groups:
            name = str(group["group"])
            if name not in by_name:
                raise ValueError(f"Focused report has unknown group: {name}")
            by_name[name] = group

    groups = [by_name[name] for name in registered_names]
    rows = [row for group in groups for row in group["rows"]]
    compile_errors = [
        {"group": group["group"], "error": group["compile_error"]}
        for group in groups
        if group["compile_error"]
    ]
    category_counts = Counter(str(row["category"]) for row in rows)
    return {
        "schema": 1,
        "summary": {
            "group_count": len(groups),
            "compiled_group_count": len(groups) - len(compile_errors),
            "compile_error_count": len(compile_errors),
            "function_count": len(rows),
            "registered_owner_count": sum(
                bool(row["registered_anywhere"]) for row in rows
            ),
            "unregistered_count": sum(
                not bool(row["registered_anywhere"]) for row in rows
            ),
            "category_counts": dict(sorted(category_counts.items())),
        },
        "compile_errors": compile_errors,
        "groups": groups,
        "rows": rows,
    }


def main() -> int:
    args = parse_args()
    try:
        base = load_report(args.base_report.resolve())
        updates = [load_report(path.resolve()) for path in args.update_report]
        registered_groups = load_translation_units()
        report = merge_reports(base, updates, registered_groups)
    except (OSError, ValueError, KeyError, json.JSONDecodeError) as error:
        raise SystemExit(str(error))

    output_dir = args.output_dir
    if not output_dir.is_absolute():
        output_dir = REPO_ROOT / output_dir
    output_dir.mkdir(parents=True, exist_ok=True)
    queue = build_queue(registered_groups, report["rows"])
    (output_dir / "report.json").write_text(
        json.dumps(report, indent=2) + "\n", encoding="utf-8"
    )
    (output_dir / "report.txt").write_text(text_report(report), encoding="utf-8")
    (output_dir / "queue.json").write_text(
        json.dumps(queue, indent=2) + "\n", encoding="utf-8"
    )
    (output_dir / "queue.txt").write_text(queue_text(queue), encoding="utf-8")
    print(f"Merged {len(updates)} focused reports into {output_dir}")
    print(json.dumps(report["summary"], indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
