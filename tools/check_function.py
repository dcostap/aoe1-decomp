from __future__ import annotations

import argparse
import json
import shutil
import subprocess
import sys
from pathlib import Path

from build_cache import build_input_manifest, build_manifest_matches
from common import (
    REPO_ROOT,
    compiler_artifact_slug,
    compiler_source_path,
    function_record_by_va,
    function_slug,
    load_toolchain,
    preferred_flags_rsp_path,
)
from function_history import (
    format_checkpoint_comparison,
    format_history,
    format_history_comparison,
    format_history_source_comparison,
    prune_history,
    record_checkpoint,
    restore_checkpoint,
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        formatter_class=argparse.RawDescriptionHelpFormatter,
        description=(
            "Build, compare, and diagnose one function.\n"
            "\n"
            "This is the authoritative local exactness check. MATCH requires positional byte\n"
            "equality, the original reachable boundary, a provable owning function symbol,\n"
            "and known direct-control symbol identity.\n"
            "A completed MISMATCH normally exits with status 1; inspect the report.\n"
            "\n"
            "The default build path uses fingerprinted cache entries. Diagnostic-only reuse\n"
            "rejects missing or stale artifacts. Call counts alone do not prove call-site order.\n"
            "Mismatch pattern labels are audit-only evidence. They never establish equivalence.\n"
            "\n"
            "Examples:\n"
            "  python tools/check_function.py --va 00449750\n"
            "  python tools/check_function.py --va 00449750 --call-map-unmatched --map-limit 40\n"
            "  python tools/check_function.py --va 00449750 --block-map-differences --map-limit 40\n"
            "  python tools/check_function.py --va 00449750 --range orig:+40-+80\n"
            "  python tools/check_function.py --va 00449750 --stack-map --no-build\n"
        ),
    )
    parser.add_argument("--va", required=True, help="Function VA in hex, for example 00449750.")
    parser.add_argument("--verbose", action="store_true", help="Show subprocess chatter and the longer diff report.")
    parser.add_argument("--quiet", action="store_true", help="Compatibility flag for batch callers; use concise diagnostics.")
    parser.add_argument("--refresh-original", action="store_true", help="Re-extract immutable original bytes.")
    build_group = parser.add_mutually_exclusive_group()
    build_group.add_argument("--rebuild", action="store_true", help="Force compilation and extraction, ignoring the build cache.")
    build_group.add_argument(
        "--no-build",
        action="store_true",
        help="Run diagnostics only; fail if cached rebuilt artifacts are missing or stale.",
    )
    parser.add_argument(
        "--reuse-latest",
        action="store_true",
        help="Compatibility spelling for the default fingerprinted build-cache behavior.",
    )
    parser.add_argument(
        "--detail",
        choices=("auto", "concise", "full"),
        default="auto",
        help="Diagnostic detail level. Auto is concise for giant functions.",
    )
    parser.add_argument("--call-map", action="store_true", help="Print the full context-aware call-site alignment.")
    parser.add_argument(
        "--call-map-unmatched",
        action="store_true",
        help="Print only non-equal call-map rows (implies --call-map).",
    )
    call_filter = parser.add_mutually_exclusive_group()
    call_filter.add_argument(
        "--call-map-target",
        metavar="TEXT",
        help="Print call-map rows whose target/display contains TEXT (implies --call-map).",
    )
    call_filter.add_argument(
        "--call-map-target-exact",
        metavar="TARGET",
        help="Print call-map rows whose normalized target exactly equals TARGET (implies --call-map).",
    )
    call_filter.add_argument(
        "--call-map-target-regex",
        metavar="REGEX",
        help="Print call-map rows whose kind/target/display matches REGEX, ignoring case (implies --call-map).",
    )
    parser.add_argument("--block-map", action="store_true", help="Print the full basic-block alignment.")
    parser.add_argument(
        "--stack-map",
        action="store_true",
        help="Pair durable original and rebuilt stack homes at exact entry-relative coordinates.",
    )
    parser.add_argument(
        "--block-map-differences",
        action="store_true",
        help="Print only non-equal basic-block rows (implies --block-map).",
    )
    parser.add_argument(
        "--map-limit",
        type=int,
        metavar="N",
        help="Limit rows printed by call/block maps after filtering (0 means unlimited).",
    )
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
    parser.add_argument(
        "--compare-history-source",
        nargs=2,
        metavar=("LEFT", "RIGHT"),
        help="Show a unified source diff between two checkpoint labels/ids/selectors without rebuilding.",
    )
    parser.add_argument(
        "--history-diff-limit",
        type=int,
        default=500,
        metavar="N",
        help="Maximum unified-diff lines shown by --compare-history-source (0 means unlimited).",
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


def rebuilt_cache_state(record: dict[str, str], slug: str) -> tuple[bool, bool, str]:
    toolchain = load_toolchain()
    source_path = compiler_source_path(record)
    rsp_path = preferred_flags_rsp_path(record, toolchain)
    fingerprint = str(build_input_manifest(source_path, rsp_path, toolchain)["fingerprint"])
    build_slug = compiler_artifact_slug(record)
    obj_path = REPO_ROOT / "build" / "obj" / f"{build_slug}.obj"
    manifest_path = REPO_ROOT / "build" / "manifests" / f"build_{build_slug}.json"
    asm_dir = REPO_ROOT / "build" / "asm"
    source_map_path = asm_dir / f"rebuilt_{build_slug}.lines.json"
    build_current = build_manifest_matches(manifest_path, fingerprint, obj_path) and source_map_path.is_file()
    extracted_paths = [
        asm_dir / f"rebuilt_{slug}.bin",
        asm_dir / f"rebuilt_{slug}.json",
        asm_dir / f"rebuilt_{slug}.txt",
    ]
    extracted_manifest_fingerprint = ""
    extracted_metadata_path = extracted_paths[1]
    if extracted_metadata_path.is_file():
        try:
            extracted_metadata = json.loads(extracted_metadata_path.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            extracted_metadata = {}
        if isinstance(extracted_metadata, dict):
            extracted_manifest_fingerprint = str(
                extracted_metadata.get("build_input_fingerprint") or ""
            )
    extraction_current = bool(
        build_current
        and extracted_manifest_fingerprint == fingerprint
        and all(path.is_file() for path in extracted_paths)
        and all(path.stat().st_mtime_ns >= obj_path.stat().st_mtime_ns for path in extracted_paths)
    )
    return build_current, extraction_current, fingerprint


def main() -> None:
    args = parse_args()
    va = int(args.va, 16)
    record = function_record_by_va(va)
    slug = function_slug(record)

    if args.no_history and (args.checkpoint or args.compare_checkpoint):
        raise SystemExit("--no-history cannot be combined with --checkpoint or --compare-checkpoint")
    if args.checkpoint == "clean-source":
        raise SystemExit(
            "clean-source is reserved for target_session.py pin-clean so the source audit and session metadata stay together"
        )

    if args.apply_prune and not args.prune_history:
        raise SystemExit("--apply-prune requires --prune-history")
    if args.map_limit is not None and args.map_limit < 0:
        raise SystemExit("--map-limit must be zero or positive")
    if args.history_diff_limit < 0:
        raise SystemExit("--history-diff-limit must be zero or positive")
    if args.history:
        print("\n".join(format_history(record, max(args.history_limit, 1))))
        return
    if args.compare_history:
        print("\n".join(format_history_comparison(record, args.compare_history[0], args.compare_history[1])))
        return
    if args.compare_history_source:
        print(
            "\n".join(
                format_history_source_comparison(
                    record,
                    args.compare_history_source[0],
                    args.compare_history_source[1],
                    limit=args.history_diff_limit,
                )
            )
        )
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

    if args.refresh_original or not original_artifacts_exist(slug):
        run_step("extract_original_function.py", args.va, verbose=args.verbose)
    elif args.verbose:
        print(f"Using cached original artifacts for {slug}")

    build_current, extraction_current, fingerprint = rebuilt_cache_state(record, slug)
    did_rebuild = False
    did_extract = False
    if args.rebuild:
        build_current = extraction_current = False
    if args.no_build and not extraction_current:
        state = "missing" if not build_current else "not extracted"
        raise SystemExit(
            f"Cached rebuilt artifacts are {state} or stale for {slug}; "
            "run without --no-build (or pass --rebuild)."
        )
    if not build_current:
        snapshot_previous(slug)
        run_step("build_function.py", args.va, verbose=args.verbose, extra=["--force"])
        did_rebuild = True
        extraction_current = False
    if not extraction_current:
        if not did_rebuild:
            snapshot_previous(slug)
        run_step("extract_obj_function.py", args.va, verbose=args.verbose)
        did_extract = True
    elif args.verbose or args.reuse_latest or args.no_build:
        print(f"Using cached rebuilt artifacts for {slug} ({fingerprint[:12]})")
    detail = "full" if args.verbose else ("concise" if args.quiet else args.detail)
    diff_extra = ["--detail", detail]
    if not (did_rebuild or did_extract):
        diff_extra.append("--no-iteration")
    if args.verbose:
        diff_extra.append("--verbose")
    if args.call_map:
        diff_extra.append("--call-map")
    if args.call_map_unmatched:
        diff_extra.append("--call-map-unmatched")
    if args.call_map_target:
        diff_extra.extend(["--call-map-target", args.call_map_target])
    if args.call_map_target_exact:
        diff_extra.extend(["--call-map-target-exact", args.call_map_target_exact])
    if args.call_map_target_regex:
        diff_extra.extend(["--call-map-target-regex", args.call_map_target_regex])
    if args.block_map:
        diff_extra.append("--block-map")
    if args.stack_map:
        diff_extra.append("--stack-map")
    if args.block_map_differences:
        diff_extra.append("--block-map-differences")
    if args.map_limit is not None:
        diff_extra.extend(["--map-limit", str(args.map_limit)])
    if args.focus_range:
        diff_extra.extend(["--range", args.focus_range])
    result = run_step(
        "diff_function.py",
        args.va,
        verbose=True,
        extra=diff_extra,
        allowed_returncodes={0, 1},
    )
    # Keep the checker report tied to the same complete compiler-input
    # fingerprint that selected the object. Grouped exact release checks use
    # this value to reject a sibling-owner or wrapper change.
    metrics_path = REPO_ROOT / "build" / "diff" / f"{slug}.json"
    if metrics_path.is_file():
        metrics_payload = json.loads(metrics_path.read_text(encoding="utf-8"))
        metrics_payload["build_input_fingerprint"] = fingerprint
        metrics_path.write_text(json.dumps(metrics_payload, indent=2), encoding="utf-8")
    if args.no_history:
        raise SystemExit(result)
    if not (did_rebuild or did_extract or args.checkpoint or args.compare_checkpoint):
        if args.verbose:
            print("History checkpoint: skipped for cached diagnostic-only run")
        raise SystemExit(result)
    try:
        checkpoint = record_checkpoint(record, args.checkpoint)
        labels = ",".join(checkpoint.get("labels") or [])
        label_text = "" if not labels else f" labels={labels}"
        print(
            f"History checkpoint: {checkpoint['id']}"
            f"{' [Codegen frontier]' if checkpoint.get('pareto') else ''}{label_text}"
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
