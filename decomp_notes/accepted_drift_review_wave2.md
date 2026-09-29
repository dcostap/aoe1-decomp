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

### `drift2-035-airesitm`

The integration review retains the narrow `00412240` approval.
One SIB byte exchanges scale-one terms under DS. All other instructions agree.
The original count-above-eight overlap bug remains in the typed source.
The worker audit found 15 exact neighbors and no exact regression.
All new experiment records passed hash, parent, prerequisite, and input checks.
No source changed, and no runtime cases ran for this review.

### Shared map-table question

The raw PDB record `0x1150` is an `LF_ARRAY` of `T_32PULONG` with length 1,024 bytes.
`S_GDATA32 [0004:00307808]` names `unified_map_offsets` with that type and type `0x11BA`.
The current declaration and definition use 1,024 pointers, which occupy 4,096 bytes.
The raw `0x11BA` record is also an `LF_ARRAY`, but its length is zero.
It describes an unsized array. The doppleganger worker is checking executable
references, actual storage bounds, and the affected closure.
No shared source repair is approved yet. Its first proposal and input records are preserved.

### Inconclusive results

The user requests a fresh subagent for each inconclusive result.
Give each retry a fresh context and separate worktree. Keep the 40-worker limit.
Do not assign two active recovery workers to the same natural module.
Append `004471F0` has the first fresh retry assignment.
An unrun runtime case alone does not invalidate a complete instruction proof.

Fresh retries `retry2-002-taiinfmd`, `retry2-003-sprite`, and `retry2-004-stat_obj`
cover the unresolved questions in their first proposals. Their source changes
and behavior proposals are not approved yet. Each retry starts at
`4ac7be826df092b01102db9cad2cbba9da11f4c2` in a separate worktree.
The original workers remain stopped. Preserve their evidence before cleanup.

Fresh retries `retry2-005-aiconmod` and `retry2-006-pnl_txt` cover the unresolved
save and text targets. Exact candidates `0040B980` and `0047E2A0` remain pending
independent source and behavior review. No candidate source is integrated yet.
The integration verified and preserved 25 aiconmod records and 39 pnl_txt records.

### `drift2-023-player`

The integration retains the narrow approvals at `004706B0` and `00470F80`.
The first exchanges a signed back-edge test for its complementary exit test.
Both paths use unchanged compare flags and reach the same effectful successors.
The second exchanges scale-one SIB terms under DS at six sites.
The complete review covers object accesses, parameter-home reuse, cleanup, and
the original out-of-range group-table behavior. Neither function uses x87.

The worker's 30 new records passed hash, parent, prerequisite, and retained-input checks.
Initial read-only reuse could not extract the ally target. It was not a valid check.
The integration captured its unchanged input before a fresh target and one-job closure check.
State `4cebe1083edb9ba9000aee7eae1e62fe1f312b740decb090179c946c87c048ad`
and event `4df8fc443e4e64269c685a4493b4dbeae26818876fcc87da43e6b48809d72f56`
record the three-byte mismatch and zero exact regressions. Current-artifact
diagnostics then confirmed both complete bodies. Registry statuses stay unchanged.
No linked-image audit or runtime case ran for this note-only integration.

### Pending multiplayer, editor, and Shape proposals

The integration verified and preserved 29 `scr_cj`, 23 `scr_sed`, and 21 Shape records.
Both multiplayer input sets and the retained typed Shape cursor passed input checks.
Fresh retry `retry2-007-scr_cj` covers both unresolved multiplayer targets.
Fresh retry `retry2-008-shape` covers `004B98E0` and its linked `memset` identity.
Typed Tech_Tree indexing and the `byte* save_buffer` proposal remain unapproved.
No compiler-facing source from these workers is integrated.

### Fresh append result

`retry2-001-dstring` reports that `$L2321` names handler code, not a scope table.
It traces original `0055D418` through FuncInfo `00579980` and the cleanup at `0055D410`.
Its authentic-module diagnostic link resolves `__except_list` to zero for `FS:[0]` accesses.
This resolves the prior worker's missing evidence, subject to independent integration review.
The source and scratch status remain unchanged. Its smoke test did not run the original EXE.

### Map-table continuation

The stopped doppleganger continuation tested the unsized extern and 256-entry definition.
The worker reports 3,951 exact checks across 157 affected header groups, with no owner mismatch.
These byte checks do not resolve storage aliases beyond the 256-entry table.
Original row 258 reads `world_update_counter` at `00886C10`.
The candidate row reads `VCALL_LOG` at `005EF570` instead.
Initial zero bytes do not prove equal later values or faults.
Keep the shared source repair as an experiment. Do not add a bounds check.
Fresh retry `retry2-009-dpl_obj` will investigate original neighbors and caller constraints.

### Drawing and game-screen intake

Fresh retry `retry2-010-drawarea` covers `SetClipRect` exception and fault-order obligations.
Its previous proof explains reordered field reads only for valid receivers.
The simpler loop remains a proposal; no source is integrated.
Fresh retry `retry2-011-scr_game` covers both targets and their linked-global obligations.
The narrow line and diplomacy-draw proposals remain in the independent review queue.

The integration verified and preserved 37 drawarea, 30 scr_game, and 17 dlg_dip records.
All three retained drawarea input sets and the diplomacy input set passed verification.
It also preserved 37 append retry records and 42 new map-table continuation files.
Evidence preservation does not approve source, status, or linked behavior.

### dsutil, Command, and victory intake

The integration verified and preserved 20 dsutil, 46 Command, and 106 victory records.
The dsutil proposal and five narrow Command proposals remain in the independent review queue.
Fresh retry `retry2-013-command` covers three explicit global and virtual-target gaps.
No source proposal from these workers is integrated.

The integration withdraws `005324A0 handle_destroy_all` to `scratch`.
Fresh compiled artifacts confirm that its state write moved after EBP restoration.
The shared tail serves both an empty target-player list and a nonpositive player count.
Saved-stack-word aliasing and fault order remain unresolved. No gameplay defect is proved.
Fresh retry `retry2-012-victory` covers this gap. The other seven victory proposals remain pending.
The corrected `00533240` source and its scratch status stay unchanged.

The isolated integration check retained a 199-byte body with 25 differences and no exact regression.
Its run event is `f811103d52cf8d979c0c571ed8caf5bb760920115b8aabecc54f8d5552138dfb`.
An earlier cached diagnostic failed. The experiment runner also refused the main worktree.
Neither failed attempt is validation; the refused experiment remains preserved.
Finding `e78f14b8ad770011ad5c32593f272b32ad330b50bcc94c42be7fdbd11f78513c` records the integration objection.
Registry-only validation and diff checks passed after the status change.
No new game build, linked-image audit, or runtime suite ran.

The integration also preserved 34 move_obj, 50 taiinfmd, 31 sprite, and 49 stat_obj records.
Both retained move_obj input sets passed verification. Their proposals remain unapproved.

### `drift2-033-act_list`

The integration retains accepted drift at `00404590 add_action_at_end`.
Both changed bytes belong to an unreachable block.
A zero successor branches to append; a nonzero successor must branch back to the scan.
The complete review confirms all reachable effects, arguments, faults, and cleanup.
The fresh isolated check retained 114 bytes and two differences. All 24 exact neighbors remain exact.
Its run event is `b42f7a02cc1dfa9d2c0fbb40657c14e669fcc8e529c19919bcbf158969567a22`.
Complete operand review resolves the local numeric-window limitation. No absolute storage operand occurs here.

The integration rejects the successor-local probe for its changed empty-list fault order.
It reads the action vtable before linking, unlike the original.
The correcting finding and both probe runs remain preserved. No source change is integrated.
Registry-only validation and diff checks passed. No new linked-image audit or runtime test ran.

### Scenario and mouse-pointer intake

The integration verified and preserved 40 action-list and 33 scenario records.
It verified 25 mouse-pointer records and imported 24 new files.
The restored action-list input and both mouse-pointer input sets passed verification.
Fresh retry `retry2-014-scenario` covers constructor exception evidence and all four targets' linked references.
Fresh retry `retry2-015-mouseptr` covers drawing references, argument staging, and failure effects.
The cursor-deletion proposal remains queued. Its original over-bound loop must remain.
No scenario or mouse-pointer proposal is approved yet.
