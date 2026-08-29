# Recovery journal: 004DC490 `objectToAttackWithPlay`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2e55ee1c618b133f004c -->
### `target-session` `build/target_sessions/004DC490_objectToAttackWithPlay.json:1-34`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 control-flow; result=MISMATCH; diff=678; shape=79.0909090909091: Natural block scope variant after declaration repair: declarations after early guards, target-null returns target, int invalid, for-based nested scans, and separate score initialization.
probe 2 control-flow; result=MISMATCH; diff=678; shape=79.0909090909091: For-loop and scoring split with original top-level local declarations; declaration-scope variant was rejected because it moved the prologue and worsened size/CFG. [same emitted code as probe 1]
probe 3 control-flow; result=MISMATCH; diff=670; shape=77.27272727272727: Hypothesis 1: replace the binary nested do-loops with for loops while keeping bool invalid and original score expression; assembly top tests and increment placement support for rotation.
probe 4 liveness; result=MISMATCH; diff=645; shape=75.9090909090909: Hypothesis 2: change only invalid from bool to int; original keeps invalid in EDI and uses full-register tests and writes.
probe 5 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 3: use unsigned char invalid with the original do-loop topology; this tests binary byte-state evidence without bool semantics.
probe 6 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 4: move only the target pointer declaration below the count guard; original early return may avoid target lifetime and preserve direct short epilogue. [same emitted code as probe 5]
probe 7 control-flow; result=MISMATCH; diff=639; shape=81.25: Hypothesis 5: return the proven null target value on the target-null branch, matching the original post-call EAX preservation instead of a literal null. [same emitted code as probe 6]
probe 8 control-flow; result=MISMATCH; diff=639; shape=81.25: Hypothesis 6: use positive count/target guards so the original JNZ body branches and direct null epilogues arise from fall-through rather than early negative returns. [same emitted code as probe 7]
probe 9 liveness; result=MISMATCH; diff=686; shape=73.63636363636364: Hypothesis 7: split score initialization before debug_rand, as PDB line 3398 emits 100-minus-death before the line 3401 random call; then add variation and finish score.
probe 11 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 8 (distinct source axis): make play a function-scope pointer, matching its long use across status and phase loops and the original durable play home. [same emitted code as probe 10]
probe 12 liveness; result=MISMATCH; diff=668; shape=79.63800904977376: Hypothesis 9: function-scope AIPlayStatus to mirror the PDB local stack window and test register coloring; rejected as behaviorally wrong because constructor moves outside the eligible-play branch.
probe 13 control-flow; result=MISMATCH; diff=670; shape=77.27272727272727: Hypothesis 10: combine the byte invalid state with natural for-loop scans; the original has increment/test/backedge bands that may derive from this form. [same emitted code as probe 3]
probe 14 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 11: signed char invalid; same binary byte-state intent, but signedness may alter promotion and full-register scheduling. [same emitted code as probe 11]
probe 15 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 12: reorder the phase-loop index after world/playbook declarations, testing PDB local ordering as a source-level register/home axis. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 13: scope variation/random/strategic/score inside the successful validation block; PDB names only durable scan locals, so branch-local score temporaries are period-plausible. [same emitted code as probe 15]
probe 17 control-flow; result=MISMATCH; diff=646; shape=83.63636363636364: Hypothesis 14: pair full int invalid with for-loop scan topology; this tests whether the original EDI flag and loop backedges arise together.
probe 18 liveness; result=MISMATCH; diff=678; shape=79.0909090909091: Hypothesis 15: branch-local named score initialized after variation and before random, matching PDB line 3398 and the original pre-random death-byte load. [same emitted code as probe 2]
probe 19 control-flow; result=MISMATCH; diff=646; shape=83.63636363636364: Hypothesis 16: express nested scans as while conditions combining bounds and invalid state; this tests whether top invalid checks and rotated backedges come from short-circuit loop predicates. [same emitted code as probe 17]
probe 20 control-flow; result=MISMATCH; diff=649; shape=82.27272727272727: Hypothesis 17: restore natural do/while scans with full int invalid after while/for canonicalization; original explicit top invalid breaks may be source-shaped do loops.
probe 25 abi; result=MISMATCH; diff=639; shape=81.25: Hypothesis 1: use PDB-proven int references for playNumber, outputCount, and outputUnit; test true target ABI rather than pointer spellings. [same emitted code as probe 24]
probe 26 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 2: hoist AIPlay* play to function scope in the Ghidra-declared local order; test whether durable play home recovers EBP and this/world register colors. [same emitted code as probe 25]
probe 27 liveness; result=MISMATCH; diff=645; shape=75.9090909090909: Hypothesis 3: widen invalid to int to match original full-register XOR/TEST and EDI reuse; retain do-scan topology. [same emitted code as probe 4]
probe 28 liveness; result=MISMATCH; diff=639; shape=81.25: Hypothesis 4: swap target and targetNumber declaration order; test stack-home/register coloring against original target/play/index lifetime order. [same emitted code as probe 26]
probe 29 control-flow; result=MISMATCH; diff=461; shape=90.990990990991: Hypothesis 5: invert final result guard to early null return, matching oracle cmp -1/JNZ success tail and separate null cleanup.
probe 30 liveness; result=MISMATCH; diff=461; shape=90.990990990991: Hypothesis 6: restore Ghidra local declaration order with targetNumber before target in the inverted-final-guard basin. [same emitted code as probe 29]
probe 31 control-flow; result=MISMATCH; diff=664; shape=86.36363636363636: Hypothesis 7: express both scans as natural while predicates combining bound and invalid state, testing the oracle's pre-body invalid tests without explicit breaks.
probe 32 liveness; result=MISMATCH; diff=557; shape=80.95238095238095: Hypothesis 8: combine int invalid with the improved inverted-final-guard basin; test full-register zero/store parity while retaining do loops.
probe 33 liveness; result=MISMATCH; diff=461; shape=90.990990990991: Hypothesis 9: use explicit unsigned-char invalid rather than bool; test byte width without changing proven scan structure. [same emitted code as probe 30]
probe 34 liveness; result=MISMATCH; diff=461; shape=90.990990990991: Hypothesis 10: make play a function-scope pointer in the inverted-final basin; test durable play lifetime for EBP coloring. [same emitted code as probe 33]
probe 35 liveness; result=MISMATCH; diff=418; shape=85.45454545454545: Hypothesis 11: stage score base before debug_rand, matching PDB line 3398 and original pre-call 100/death setup; finish score after strategic value.
probe 36 liveness; result=MISMATCH; diff=704; shape=79.82456140350877: Hypothesis 12: keep score base as 100-death before debug_rand, then add variation in the final score; this matches original ESI/EDI x86 schedule.
probe 37 liveness; result=MISMATCH; diff=418; shape=85.45454545454545: Hypothesis 13: scope score inside the eligible-play block, matching its single successful use and testing local lifetime pressure in the staged-score basin. [same emitted code as probe 35]
probe 38 liveness; result=MISMATCH; diff=418; shape=85.45454545454545: Hypothesis 14: scope variation, randomValue, strategicValue, and score together inside the valid-play block, following their exclusive PDB line band. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=418; shape=85.45454545454545: Hypothesis 15: hoist bool invalid to function scope while delaying its zero assignment until after fillGroups, matching the Ghidra local declaration and original store site. [same emitted code as probe 38]
```
<!-- end-recovered:2e55ee1c618b133f004c -->

<!-- recovered:37f0cea7c8a744429bc0 -->
### `fc4b000c6e8f` `src/scratch/004DC490_objectToAttackWithPlay.cpp:1-59`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004DC490 TribeInformationAIModule::objectToAttackWithPlay
// Source: taiinfmd.cpp lines 3277-3451
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: clean typed reconstruction from the binary call set and the matching
//    AIPlay/AIPlayStatus ABI donors; baseline was 688 bytes before the
//    corrected integer phase-loop ownership.
// 2: separated the RGE_Game_World pointer from the integer 10x5 phase index;
//    this removed the erroneous sizeof(RGE_Game_World) loop increment and
//    reached exact frame size with all 13 direct calls aligned.
// 3: explicit top-of-loop invalid breaks improved CFG alignment but shortened
//    the body; restored after the source-shaped for/continue probe below.
// 4-9: canonical base/class layouts, local declaration order, and a target
//    register hint were codegen duplicates; no call or relocation issues.
// 10: modeled the outer play scan as a bounded for-loop with continue paths
//    and `deviationValue > 0`; this reached exact 703-byte size and the
//    oracle's JA polarity, while leaving a register/lifetime permutation.
// 11: removed a redundant positive play-count wrapper; the current direct
//    for-loop is the cleaner source reconstruction (684 bytes, exact frame,
//    exact call set), with remaining drift localized to register coloring,
//    loop-test/tail layout, and the two early shared-return paths.
// Shard B5: changing the zero-count return to null, reordering declarations,
// and using positive count/target guards were codegen duplicates.
// Shard B5: the donor-shaped positive playbook do-scan worsened CFG coverage;
// restored the direct bounded scan. The first hunk remains this/play register
// coloring plus merged early epilogues; no ABI or call-set issue was found.
// luna-4DC490-r2 probe: returning the proven null target value on the
// target-null branch was emitted identically; original EAX preservation alone
// does not prevent VC5 from merging the null exits.
// luna-4DC490-r2 probe: changing the phase-invalid flag from int to bool
// removed some stack traffic and moved 3 positional bytes closer, but worsened
// CFG shape and exact-block coverage; restored the int source reconstruction.
// luna-4DC490-r3 probes: byte-sized invalid state plus binary-supported top-entry
// stops for both nested scans recovered exact size, 45.45% block coverage, and
// diff 639; kept as the best clean reconstruction. Per-iteration play scope,
// top-level score locals, and score-term order were emitted-code duplicates.
// A named death-value temporary added 19 bytes and was rolled back. Remaining
// drift is the early shared epilogues and callee-save rotation (this/play/flag).
// luna-4DC490-r4: the natural positive count/target guard around the best
// current loop basin was a codegen duplicate; restored the direct guard form.
// luna-4DC490-r4: a combined play-null/human-play positive body gate, supported
// by the shared oracle skip tail, was also a duplicate; restored the clean form.
// Revisit sa-41eba353: 19 source probes revisited loop form, invalid
// width, declaration scope, guard polarity, score staging, and local order.
// The byte-sized invalid state with the original do-scan remains the cleanest
// natural basin: exact size/frame and all 13 calls, diff 639. Full int invalid
// with for/while scans improved shape but lost the original local homes.
// Branch-local score staging matched the PDB line split hypothesis but added
// 17-19 bytes and worsened the prologue. A function-scope status moved its
// constructor before the play loop and was rejected. No ABI, call, or layout
// issue was found. The remaining drift is register rotation, early epilogues,
// and loop-tail shape; paused unresolved after validation below.
// sa-4e418261 pass: changed the three output parameters to PDB-proven
// references. This changes the decorated owner symbol but not body bytes.
// Inverting the final play-number test recovered the original early-return
// blocks. Staging the score expression before debug_rand reduced the strict
// diff to 418 bytes. Remaining drift is register coloring, spilled byte state,
// and nested-loop block shape. No call-set or frame issue was found.
```
<!-- end-recovered:37f0cea7c8a744429bc0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
