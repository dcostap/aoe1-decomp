from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

from common import REPO_ROOT, function_record_by_va, function_slug
from function_history import (
    format_checkpoint_comparison,
    format_history,
    format_history_comparison,
    prune_history,
    record_checkpoint,
    restore_checkpoint,
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Build, compare, and diagnose one function.")
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    parser.add_argument("--verbose", action="store_true", help="Show subprocess chatter and the longer diff report.")
    parser.add_argument("--quiet", action="store_true", help="Compatibility flag for batch callers; use concise diagnostics.")
    parser.add_argument("--refresh-original", action="store_true", help="Re-extract immutable original bytes.")
    parser.add_argument(
        "--detail",
        choices=("auto", "concise", "full"),
        default="auto",
        help="Diagnostic detail level. Auto is concise for giant functions.",
    )
    parser.add_argument("--call-map", action="store_true", help="Print the full context-aware call-site alignment.")
    parser.add_argument("--block-map", action="store_true", help="Print the full basic-block alignment.")
    parser.add_argument(
        "--range",
        dest="focus_range",
        metavar="[orig:|rebuilt:]START-END",
        help="Print focused aligned blocks/disassembly for an offset or real VA range.",
    )
    parser.add_argument("--checkpoint", metavar="LABEL", help="Label the resulting persistent checkpoint.")
    parser.add_argument("--no-history", action="store_true", help="Do not record an automatic persistent checkpoint.")
    parser.add_argument(
        "--compare-checkpoint",
        metavar="LABEL_OR_ID",
        help="After rebuilding, compare current metrics with any persistent checkpoint.",
    )
    parser.add_argument("--history", action="store_true", help="List persistent checkpoints without rebuilding.")
    parser.add_argument(
        "--compare-history",
        nargs=2,
        metavar=("LEFT", "RIGHT"),
        help="Compare any two checkpoint labels/ids/selectors without rebuilding.",
    )
    parser.add_argument("--history-limit", type=int, default=20, help="Maximum checkpoints shown by --history.")
    parser.add_argument("--prune-history", action="store_true", help="Plan removal of old dominated, unlabeled checkpoints.")
    parser.add_argument("--prune-keep", type=int, default=20, help="Recent checkpoints always retained by --prune-history.")
    parser.add_argument("--apply-prune", action="store_true", help="Actually perform --prune-history deletions.")
    parser.add_argument(
        "--restore-checkpoint",
        metavar="LABEL_OR_ID",
        help="Restore a checkpoint's source and custom-flag state, with an automatic backup.",
    )
    return parser.parse_args()


def run_step(
    script_name: str,
    va: str,
    *,
    verbose: bool = False,
    extra: list[str] | None = None,
    allowed_returncodes: set[int] | None = None,
) -> int:
    command = [sys.executable, str(REPO_ROOT / "tools" / script_name), "--va", va]
    if extra:
        command.extend(extra)
    result = subprocess.run(command, capture_output=True, text=True)
    if verbose or result.returncode != 0:
        sys.stdout.write(result.stdout)
        sys.stderr.write(result.stderr)
    elif script_name == "build_function.py":
        # Compiler warnings remain important even in concise mode.
        warning_lines = [
            line
            for line in (result.stdout + result.stderr).splitlines()
            if "warning" in line.lower() or "error" in line.lower()
        ]
        if warning_lines:
            print("\n".join(warning_lines))
    allowed = allowed_returncodes or {0}
    if result.returncode not in allowed:
        raise SystemExit(result.returncode)
    return result.returncode


def snapshot_previous(slug: str) -> None:
    asm_dir = REPO_ROOT / "build" / "asm"
    diff_dir = REPO_ROOT / "build" / "diff"
    history_dir = REPO_ROOT / "build" / "history" / slug
    candidates = {
        asm_dir / f"rebuilt_{slug}.bin": history_dir / "previous.bin",
        asm_dir / f"rebuilt_{slug}.json": history_dir / "previous.extract.json",
        diff_dir / f"{slug}.json": history_dir / "previous.diff.json",
    }
    existing = [(source, target) for source, target in candidates.items() if source.exists()]
    if not existing:
        return
    history_dir.mkdir(parents=True, exist_ok=True)
    for source, target in existing:
        shutil.copy2(source, target)


def original_artifacts_exist(slug: str) -> bool:
    asm_dir = REPO_ROOT / "build" / "asm"
    return all((asm_dir / f"orig_{slug}.{suffix}").exists() for suffix in ("bin", "json", "txt"))


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)

    if args.no_history and (args.checkpoint or args.compare_checkpoint):
        raise SystemExit("--no-history cannot be combined with --checkpoint or --compare-checkpoint")

    if args.apply_prune and not args.prune_history:
        raise SystemExit("--apply-prune requires --prune-history")
    if args.history:
        print("\n".join(format_history(record, max(args.history_limit, 1))))
        return
    if args.compare_history:
        print("\n".join(format_history_comparison(record, args.compare_history[0], args.compare_history[1])))
        return
    if args.prune_history:
        print("\n".join(prune_history(record, args.prune_keep, args.apply_prune)))
        return
    if args.restore_checkpoint:
        restored = restore_checkpoint(record, args.restore_checkpoint)
        print(f"Restored checkpoint {restored['id']} to {restored['restored_source_path']}")
        print(f"Previous working files backed up under {restored['restore_backup']}")
        print(f"Run: python tools/check_function.py --va {record['va']}")
        return

    snapshot_previous(slug)
    if args.refresh_original or not original_artifacts_exist(slug):
        run_step("extract_original_function.py", args.va, verbose=args.verbose)
    elif args.verbose:
        print(f"Using cached original artifacts for {slug}")

    run_step("build_function.py", args.va, verbose=args.verbose)
    run_step("extract_obj_function.py", args.va, verbose=args.verbose)
    detail = "full" if args.verbose else ("concise" if args.quiet else args.detail)
    diff_extra = ["--detail", detail]
    if args.verbose:
        diff_extra.append("--verbose")
    if args.call_map:
        diff_extra.append("--call-map")
    if args.block_map:
        diff_extra.append("--block-map")
    if args.focus_range:
        diff_extra.extend(["--range", args.focus_range])
    result = run_step(
        "diff_function.py",
        args.va,
        verbose=True,
        extra=diff_extra,
        allowed_returncodes={0, 1},
    )
    if args.no_history:
        raise SystemExit(result)
    try:
        checkpoint = record_checkpoint(record, args.checkpoint)
        labels = ",".join(checkpoint.get("labels") or [])
        label_text = "" if not labels else f" labels={labels}"
        print(
            f"History checkpoint: {checkpoint['id']}"
            f"{' [Pareto]' if checkpoint.get('pareto') else ''}{label_text}"
        )
        if args.compare_checkpoint:
            print("\n".join(format_checkpoint_comparison(record, checkpoint, args.compare_checkpoint)))
    except Exception as exc:
        if args.checkpoint or args.compare_checkpoint:
            raise
        print(f"Warning: could not record persistent history: {exc}", file=sys.stderr)
    raise SystemExit(result)


if __name__ == "__main__":
    main()
