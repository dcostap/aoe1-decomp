# Rampant scratch cleanup report

Scope: `src/scratch/*.cpp` files modified in the last 3 hours of the cleanup session on 2026-04-27.

This cleanup targeted only very high-confidence low-value files:

1. recent files containing explicit `structural stub` / `stripped function stub` markers, and
2. recent comment-only blocker files with no compiler-facing code.

No real-looking packet-grounded files were moved in this pass.

## Compile-output evidence

A sample of the latest structural stubs was checked with `python tools/check_function.py --va <VA>`. Each compiled to only a tiny stub body while the original function was thousands of bytes long, causing extraction failure such as:

```text
Configured function size 9580 exceeds .text section size 16
Configured function size 5679 exceeds .text section size 16
Configured function size 4235 exceeds .text section size 16
```

Sample output table:

- `build/recent_structural_stub_compile_sample.tsv`

Candidate table before moving:

- `build/recent_structural_stub_candidates.tsv`

## Files moved

Moved 805 explicit structural/stripped stub files to:

```text
trash/rampant_scratch_quarantine_2026-04-27/recent_structural_stubs/
```

Manifest:

```text
trash/rampant_scratch_quarantine_2026-04-27/recent_structural_stubs/MANIFEST.tsv
```

Moved 11 comment-only blocker files to:

```text
trash/rampant_scratch_quarantine_2026-04-27/recent_comment_only_blockers/
```

Manifest:

```text
trash/rampant_scratch_quarantine_2026-04-27/recent_comment_only_blockers/MANIFEST.tsv
```

Earlier in the same cleanup, 14 `FUN_...` split-block/codelet scratches were moved to:

```text
trash/rampant_scratch_quarantine_2026-04-27/fun_fragments/
```

That audit is documented separately in:

```text
docs/fun_fragment_audit_report.md
build/fun_fragment_audit.tsv
```

## Dashboard after cleanup

After regenerating `project_full_status.csv`:

```text
matching=3376
accepted_drift=27
scratch=1655
unclaimed=2932
conflict=0
normal=5874
parent_owned_fragment=14
toolchain_supplied=1519
asm_special=8
asm_region=575
```

## Remaining recent scratch files

After this pass, recent scratch `.cpp` files still exist, but none contain the explicit `structural stub` / `stripped function stub` markers. Many remaining small files still look suspicious and should be reviewed in a second pass, but this cleanup intentionally stopped at the highest-confidence categories.
