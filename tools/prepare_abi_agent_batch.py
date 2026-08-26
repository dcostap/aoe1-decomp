from __future__ import annotations

import argparse
import json
from pathlib import Path

from common import repo_path


SHARED_PROMPT = """Repair assigned VC5 translation-unit ABI symbols and source-policy findings.

Read the complete LESSONS.md and docs/agentic_matching_workflow.md before target work.
The original executable and build/004AB300_dumpbin_fpo.txt are the behavior and ABI oracles.
Use the pinned VC5 toolchain and the configured translation-unit flags.

Edit only the exclusive files in your task packet. Treat include/game_types.h and
include/game_globals.h as read-only. If a correct repair requires another file,
stop that part and report the required path. Preserve all unrelated worktree changes.

Restore natural declarations that emit each expected decorated symbol. Preserve grouped
bytes, boundaries, relocations, calls, fault order, and source order. Remove reported fake
virtual slots and raw vtable fields when the same canonical declaration repair can do so.
Do not add aliases, synthetic uses, replacement ABI classes, manual vtables, raw vptr
stores, fake volatility, inline assembly, or grouped-only body forks.

Do not edit config/translation_units.json. Do not commit. Keep experiments under a unique
build/abi_agents/<task-id>/ directory. Validate every registered owner in each assigned
group after any shared declaration change. Report exact symbols, byte results, policy
results, unresolved blockers, and every changed file.
"""


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Prepare one managed ABI repair batch.")
    parser.add_argument("--queue", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--offset", type=int, default=0)
    parser.add_argument("--limit", type=int, default=40)
    parser.add_argument("--model", required=True)
    parser.add_argument("--thinking", required=True,
                        choices=("off", "minimal", "low", "medium", "high", "xhigh", "max"))
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if args.limit < 1 or args.limit > 40:
        raise SystemExit("--limit must be between 1 and 40")
    report = json.loads(repo_path(args.queue).read_text(encoding="utf-8"))
    groups = {entry["group"]: entry for entry in report["groups"]}
    selected = report["queue"][args.offset:args.offset + args.limit]
    agents: list[dict[str, object]] = []
    for task in selected:
        details = [groups[name] for name in task["groups"]]
        packet = {
            "task_id": task["task_id"],
            "groups": details,
            "exclusive_files": task["exclusive_files"],
            "read_only_shared_headers": report["read_only_shared_headers"],
        }
        agents.append({
            "title": f"Repair {task['task_id']} ({len(task['groups'])} groups)",
            "task": (
                "Complete this ABI and source-policy repair packet. The JSON packet is "
                "authoritative for scope.\n\n" + json.dumps(packet, indent=2)
            ),
            "model": args.model,
            "thinking": args.thinking,
            "context": "fresh",
            "context_files": True,
        })
    payload = {
        "batch": {
            "title": f"ABI repair queue {args.offset + 1}-{args.offset + len(selected)}",
            "shared_prompt": SHARED_PROMPT,
            "context_files": True,
            "agents": agents,
        }
    }
    output = repo_path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
    print(f"Prepared {len(agents)} agents in {output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
