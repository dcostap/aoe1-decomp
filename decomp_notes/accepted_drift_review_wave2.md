# Remaining accepted-drift review

## Assignment

The user reopened the remaining accepted-drift functions for another review.
The source baseline is `b6fcd7e3e13d8ede9764fe4160e206e82283c072`.
At this baseline, 142 functions in 67 natural modules have `accepted_drift` status.
Scratch functions are context for this assignment, not its primary targets.

Each worker owns one module in a separate worktree.
Workers use `openai-codex/gpt-6-luna` with `xhigh` thinking.
The active limit is 40 workers. Each worker uses one compiler job.
The local assignment list is `build/accepted-drift-wave2/assignments.json`.

## Review rules

Workers check complete executable behavior before source changes or byte tuning.
They preserve original bugs, narrow values, alias effects, and fault order.
They check branch destinations and emitted x87 tests against the original.
The corrected victory review at `00533240` explains why these checks are necessary.
Passing observer hashes did not detect its score difference.

Workers capture each tested input before compilation and preserve failed hypotheses.
They report Behavior, Source, Bytes, and Integration for each finding.
They do not change registry statuses, stage files, or commit changes.
The integration review controls source changes and status decisions.
Unsupported approvals can return to `scratch`.

## Validation limits

The baseline passed five deterministic traces, scripted gameplay parity, and 41 UI cases.
Those tests do not prove whole-game behavior agreement.
This review does not grant new approval until its evidence receives an integration review.
Module checks, exact claims, linked checks, and runtime tests remain separate results.
The baseline registry check passed with `validate_translation_units.py --no-build-checks`.
This check did not compile code or repeat behavior reviews.

## Results

### `drift2-012-dstring`

All three assigned targets received a review. No source change remains.
The integration review retains the two narrow case-change approvals.
Their SIB changes preserve DS addressing, effects, and fault order.
The append exception-path proof remains unresolved. Its approval returns to `scratch`.
The current game map does not name its owner; it cannot supply linked SEH proof.
No source defect was proved. No string runtime cases ran.

The worker audit found 47 exact results and no exact-neighbor regression.
Its states, events, and referenced objects passed hash and input checks before import.
The integration preserves all new experiment records, not only the final metrics.
The registry-only check, line-ending check, and diff check passed after integration.
No source rebuild or runtime test ran for this note and status change.
