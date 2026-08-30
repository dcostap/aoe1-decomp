from __future__ import annotations

import argparse
import json

from build_cache import close_compiler_gate, compiler_gate_status, open_compiler_gate


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Control compiler admission while the orchestrator integrates shared source. "
            "Closing the gate waits for admitted compiler jobs to finish."
        )
    )
    parser.add_argument("action", choices=("close", "open", "status"))
    parser.add_argument("--json", action="store_true", help="Emit JSON status.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    if args.action == "close":
        close_compiler_gate()
    elif args.action == "open":
        open_compiler_gate()
    status = compiler_gate_status()
    if args.json:
        print(json.dumps(status, indent=2))
    else:
        state = "closed" if status["closed"] else "open"
        print(f"Compiler gate: {state}; active jobs={status['active_compiler_jobs']}")


if __name__ == "__main__":
    main()
