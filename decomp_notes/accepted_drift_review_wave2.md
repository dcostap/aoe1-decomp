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

### Text-panel retry intake

The completed `retry2-006-pnl_txt` restored its byte-neutral width probe.
It still leaves eleven word-wrap references unproved. Fresh retry `retry2-016-pnl_txt` covers those linked identities.
The calc_draw_info proposal remains queued; unrun runtime cases alone do not require another retry.
The original exact getter candidate still needs independent ownership, source, and compiler-context checks.
The integration verified 33 retry records and preserved 32 new files. No text-panel source changed.

### Independent dispatch checks, 2026-09-30

Direct PE reads confirmed the `004D1BB0` repair-action defect.
The original table sends states 9 and 12 to the no-write return.
It sends state 10 to the timer, state 11 to sub-actions, and state 13 to completion.
The old source sent each state to a different handler.
The integration restores these labels and removes the extra state-12 write.
It withdraws the old approval to `scratch`.

The independent baseline has two body differences but the wrong table.
The repair has 691 differences and the correct outer and inner tables.
Both one-job checks keep all 11 exact neighbors exact. Only the target changes.
The emitted x87 status masks and their successors agree with the original.
Shared call sites, return-address effects, linked dependencies, and runtime coverage remain open.
State `1ad3f3ba36928f904758c42ba1f161393a94584d3d345da411c224a62554963b`
and finding `356c9d84c423db1cfacf17a998d02b613a53ee5271d9db90970806d77e2d5cc8`
preserve the independent source, objects, table reads, and comparison.

The same direct-read method disproved the `00539510 sprite_check` defect report.
The original table agrees with the current source, not the worker's proposed repair.
Reject the selector changes and added stream increment. Keep source and status unchanged.
Finding `bcbf7343f5cff4873d2fc9a7eb7fdc93d87bc454d3c0dbb1a9d6110cd6694648`
preserves the raw table and the rejected worker note.
The separate view exact candidate remains unapproved.

### Stopped-worker evidence intake, 2026-09-30

Hash checks covered the following new record sets before import.
These counts describe preservation, not behavior approval or retained-input verification.

| Worker | Verified records | New files imported |
| --- | ---: | ---: |
| `drift2-017-view` | 53 | 53 |
| `drift2-029-spanlist` | 25 | 25 |
| `drift2-034-act_move` | 14 | 14 |
| `drift2-038-diam_map` | 30 | 30 |
| `drift2-056-tact_rep` | 40 | 40 |
| `drift2-066-world` | 19 | 19 |
| `retry2-002-taiinfmd` | 45 | 40 |
| `retry2-003-sprite` | 27 | 27 |
| `retry2-004-stat_obj` | 34 | 30 |
| `retry2-005-aiconmod` | 16 | 16 |
| `retry2-007-scr_cj` | 8 | 8 |
| `retry2-008-shape` | 26 | 26 |
| `retry2-009-dpl_obj` | 32 | 30 |
| `retry2-010-drawarea` | 27 | 26 |
| `retry2-011-scr_game` | 29 | 28 |
| `retry2-012-victory` | 10 | 9 |
| `retry2-013-command` | 36 | 35 |
| Failed `retry2-014-scenario` | 16 | 16 |
| Failed `retry2-015-mouseptr` | 15 | 15 |

The import added 487 files. Separate reported events archive changed notes and candidate patches.
The failed text retry had no new records. Its empty import stopped the batch after the successful imports.
No hash check failed. No worktree was reused or cleared.

### Pending retry findings

All results below remain proposals. Their registry labels do not grant independent approval.
No source from these retries entered the game.

- `taiinfmd`: the early-return proposal remains private. Fault, allocation-reentry, and alias checks remain open.
- `sprite`: five unchanged proposals have added linked evidence. Their independent complete reviews remain pending.
- `stat_obj`: four unchanged proposals have added call and storage evidence. Four tag-string links remain open.
- `aiconmod`: save's private-home proof and compression lifetime review remain pending independent approval.
- `Shape`: the linked `memset` body matches. `004B98E0` remains a 132-byte mismatch awaiting independent review.
- `scr_cj`: moved EH state may skip base cleanup on initialization faults. Handler behavior and reachability need review.
- `drawarea`: a malformed stack-alias receiver changes `SetSpanRegions` arguments. No valid-caller defect is proved.
- `victory`: heap ownership excludes the saved-EBP alias for live entries. Malformed-list behavior remains unresolved.
- `Command`: three targets have added import, string, and slot evidence. Startup values and dispatch claims remain pending.
- `scr_game`: both unchanged targets have added vtable and image evidence. Dynamic classes and startup state remain open.
- `dpl_obj`: the new private storage proposal moves ownership to visible and World modules.
  Its reported initial window matches. Later-value and out-of-range alias proof still needs independent review.
- `act_move`: the two-byte virtual-call difference remains pending ten linked references.
- `spanlist`: `DeleteShape` has a narrow register proposal. `DecodeLine` has an unresolved saved-register alias.
- `diam_map`: the unchanged 82-byte-difference result has a complete local instruction proposal, not new approval.

### Failed workers and fresh assignments

Managed state confirmed no active workers before the new launches.
Retries 014, 015, and 016 failed with connection errors. World 066 failed with an access error.
World nevertheless left source edits and two states. Preserve them as unapproved failed-worker evidence.
Retries 014 and 015 also left records. Failure does not mean the worktree is empty.

Fresh workers 017 scenario, 018 mouseptr, 019 pnl_txt, and 020 world have separate contexts and worktrees.
They use the established model, thinking level, and one-job compiler limit.
Their baseline is `b872d7c1396a66290e19d3655dc4ddf794ed1b90`.
Batch `batch-174bd1e5` records their managed launch.
The failed workers remain stopped. Their earlier findings are evidence, not approvals.

Registry-only validation and diff checks passed after the repair and note changes.
A fresh game build has started. Its result and later validation remain pending.

### `004471F0 DString::append` resolution

The independent integration review restores the narrow accepted-drift approval.
Fresh source inputs reproduce 223 bytes and three commutative scale-one SIB differences.
All 47 exact neighbors remain exact.

Original, fresh COFF, and a hash-checked authentic-module diagnostic link agree on EH ownership.
The handler loads one-state FuncInfo. Its unwind action destroys by-value parameter `d` at entry `+4`.
All three `__except_list` operands resolve to `FS:[0]`.
The prior scope-table label was wrong: it names handler code.
No source change or artificial register steering is needed.
State `052c56731e0b59f307c04cd6c003f41f388ee7097561b4799c50cbca95520cb8`
and run `4352ca0f83e089e29998c9a38686cbb525c76d219f9993d02b8c3dc4e5f9f882`
record the independent target and closure check.

### Latest focused decisions

- `00405850 RGE_Action_Move_To::update` stays accepted drift.
  The complete review covers 890 bytes, 31 calls, five switch targets, and eight x87 tests.
  Linked selectors and constants agree.
  Two bytes select EAX versus EDX for the same virtual `set_state(1)` call.
  Fresh state `111728290da21f9f764434ba655f8649e1917f084066eaa51662640ff9ce854a`
  reproduces the result without exact-neighbor regressions.
- `0047C640 TTextPanel::word_wrap_append` stays accepted drift.
  All 29 calls and 33 relocations are resolved.
  Eleven storage references, both complete strings, and three GDI imports agree.
  Its 27 differences only move private stack homes.
  State `55e94372f800c48469d59e506ee0dfbb9c9bf3a9084712c7d120008e260d749f`
  records the result.
- `004BE4B0 TSpan_List_Manager::DeleteShape` stays accepted drift.
  Three bytes only recolor registers while forming the same typed record pointer.
  State `df354c79fa1e90e6c5961cb4094eedee4cbd568022697f73aa8c690e066fcbdd`
  records the result.
- `004BEAD0 TSpan_List_Manager::DecodeLine` moves to scratch.
  Unchecked writes can reach swapped ESI and EDI save slots.
  The rebuild can return with different saved-register values for the same input.
  No proved caller contract excludes this alias.
  State `120cf9182efcd296d933b92c20b8a16b01142cc9f60be2b059d226cce0fe662f`
  records the counterexample.
- `00430ED0 RGE_Combat_Object::gather` remains open.
  Its EH cleanup home is proved equal.
  Four storage references and one numeric dependency still lack linked identity.
- Repaired `004D1BB0 TRIBE_Action_Repair::update` stays scratch.
  The corrected dispatch is proved.
  The merged `set_state(1)` call still changes return-address effects.
  Linked storage identity also remains incomplete.
- `00546A90 RGE_Zone_Map::do_zone_map` stays accepted drift.
  The original threshold is read-only double zero with seven direct `FCOMP` references.
  The rebuilt declaration and definition now use `const double`.
  A 157-group audit kept all 3,951 matching owners exact.
  The two target bytes compare signed height with known-zero ESI instead of `TEST`.
- `004F7E80 idleCivilian` remains open after retry 028.
  PDB names protected `ManagedArray<int>::resize` at seven direct calls.
  The shared-header candidate reduced the mismatch but changed three matching owners.
  Fresh retry 043 must resolve those owners and the proposed friend access.
- `0053D0D0 RGE_Visible_Map::checksumVisible` stays accepted drift.
  Signed bounds, table and row fault order, extreme counters, and the byte XOR agree.
  One byte only exchanges scale-one EDX and ESI in `row[x]`.
  The alternate `x[row]` spelling emits the same byte.
- `0044B760 RGE_Fractal::MakeNewLink` remains open.
  Public settings reach `Point[500]`, `NumNodes`, both distance divisors, and `ProbArray`.
  Original and rebuild reload `NumNodes` after the x store.
  The original restores EDI before that store. The rebuild restores it after the store.
  Retry 044 will trace the first later fault or normal return in both images.

### Const-threshold linked validation

Build `build/executable/user/20260930T082357895238Z` linked 226 C/C++ sources and one assembly source.
It has no unresolved symbol or link error.
The executable SHA-256 is `e5495e93bfa2eee3c0d05488e41926901947e6b5f574ea0aeba294dd26ea81e7`.

The image dependency audit found 11,393 passes, 48,162 unknowns, and no failure.
The linked-reference audit found 7,515 passes and 5,350 unknowns.
Automated tests passed 1,000 tests and 31 subtests. Two optional tests skipped.
No gameplay or UI suite ran for this build.

`0045BA60 TMousePointer::draw` stays accepted drift.
Fresh COFF and linked-image evidence resolves its four prior reference gaps.
The source now names `DDERR_NOCLIPPERATTACHED` instead of its raw HRESULT.
The pinned header proves the value, and the target bytes remain unchanged.

`005420F0 RGE_Game_World::load_world` stays accepted drift.
Fresh linked evidence resolves its four storage operands and numeric dependency.
The changed compare uses known-zero BP and feeds the same signed `JLE` flags.
Local `type` now uses the PDB-supported `unsigned char` width.
The source change keeps the target bytes unchanged.

`0047E2A0 TTextPanel::get_text(long)` becomes `matching`.
The exact source follows the same-class `get_text2` declaration and loop form.
It matches all 61 bytes and keeps all exact module neighbors exact.
Focused linked evidence proves its one-byte static remains distinct from `get_text2`.

`00535A80 pick_multi` stays accepted drift.
The target and both helpers use one 768-byte, zero-initial `Picked_Objects` array.
All nine linked target and helper relocations resolve to that array.
Reviewed callbacks do not write it.

The exact `0040B980 setReferencePoint` candidate remains rejected.
Its comma expressions force compiler scheduling without PDB, period-source, or donor support.
Keep the clearer direct bounds expressions and accepted-drift status.
Retry 047 will close only their linked numeric storage.

Repaired `004D1BB0 TRIBE_Action_Repair::update` remains scratch.
The original state-11 call and rebuilt merged call have different return addresses.
A callee, unwinder, stack walker, or hook can observe this difference.
No natural source supports a forced call-site split.

`0052A0B0 TRIBE_Game::randomComputerName` stays accepted drift.
No saved natural variant emits exact bytes.
Its 16 differences swap ESI and EDI roles and prologue order.
Calls, stack-slot reuse, signed division, retries, fallback, aliases, and fault order agree.

`004C8CB0 TRIBE_Building_Object::change_ownership` stays accepted drift.
The retained source keeps the proved `actions` and `on_build_make_obj` repairs.
It removes two redundant decrement locals without changing target bytes.
Six SIB bytes exchange scale-one registers and equal-base DS/SS segments.

The four scenario targets stay accepted drift.
Original bytes, COFF relocations, and a linked image resolve their storage references.
The constructor handler, FuncInfo, unwind action, vtable, and timeline cleanup agree.
The getters keep separate buffers, unchecked indices, unbounded formatting, and original sentinel bugs.

`004F7E80 idleCivilian` stays accepted drift.
Reject the protected-resize and explicit-friend candidates.
VC5 rejects direct protected calls, and no source evidence supports friendship.
The friend workaround also changes three matching owners.

Historical exact source for `0053B300 LocateIDbyDrawLevel` passed its old closure.
Retry 045 could not prove that closure against current inputs.
Fresh retry 048 will rebuild only the target source hunk from current HEAD.

Retry 048 promotes `0053B300 LocateIDbyDrawLevel` to `matching`.
The current-base natural guard form matches all 103 bytes.
The 79-owner view closure has no failed exact claim or code-byte regression.
The rejected `sprite_check` source remains unchanged.

`0044B760 PointMaker::MakeNewLink` moves to scratch.
A deterministic seed-1 trace reached indices 500 through 507 four times.
Corruption changed `NumNodes` to minus 30 and caused 57 writes before the object.
Both tested layouts returned normally with equal normalized traces.
The original restores EDI before the x store; the rebuild restores it after the store.
An inaccessible adjacent page can expose different fault-time register state.

`004920C0 TribeMPCreateDialog` and `004923C0 action` stay accepted drift.
The constructor drift is limited to EH-state timing around stores within a valid allocation.
No call can throw before both builds activate the same state.
The action's 42 linked storage references and final action vtable slot resolve.

`00430ED0 RGE_Combat_Object::gather` stays accepted drift after a header repair.
The linked EH graph, allocation, constructor, and Gather vtable now resolve.
VC5 reverses same-name overload declaration order in the vtable.
Declaring the infile `setup` overload first restores the original two slot identities.
The 37-module closure keeps all 1,092 exact targets exact.
