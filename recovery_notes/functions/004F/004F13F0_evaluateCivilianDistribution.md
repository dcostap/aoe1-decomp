# Recovery journal: 004F13F0 `evaluateCivilianDistribution`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8098ebf193d607cece09 -->
### `d050eea3c` `src/taitacmd.cpp:4688-4722`

Mapping: `ambiguous`. next mapped function definition is evaluateCivilianDistribution at old line 4807.

```text
//   probes reproduced the 768-byte source-shaped basin or regressed it.  The
//   best clean result remains 607 strict diff bytes with all ten ordered calls,
// [non-comment lines omitted during migration]
//   blocker is the original saved-EBX zero/register basin and block layout.
// - ManagedArray recovery restored the exact contains and remove bodies and
//   replaced the caller-side scans with direct API calls. This recovered the
// [non-comment lines omitted during migration]
//   The retained war-boat block is the exact remove donor body. A direct call
// [non-comment lines omitted during migration]
// - Exact-finish removal of temporary inline-depth pragmas remained exact.
// - Fresh exact-finish audit: replacing the fourth war-boat inline remove body
// [non-comment lines omitted during migration]
                // BINARY NOTE: Exact remove body at the fourth inline site.
```
<!-- end-recovered:8098ebf193d607cece09 -->

<!-- recovered:26312e8aac64d5dd6432 -->
### `6a2aef2e2` `src/taitacmd.cpp:3996-4045`

Mapping: `strong`. next mapped function definition is evaluateCivilianDistribution at old line 4097.

```text
//
//   tactical list ownership and the natural repeated scan/compact source.
// - Deferred index initialization until after removeFromTaskLists and routed
//   the normal paths through one group-removal tail; this reduced the build to
//   792 bytes and one extra call.
// - Reset the scan index before each list and let boat removal continue into
//   the war-boat scan; size and all ten ordered call sites then matched.
//   (original 765), with 607 strict diff bytes and 216 edit/resync bytes.
// - An ordinary zero local, register-qualified zero, per-loop pointer aliases,
//   remaining gap is the original EBX zero/prologue allocation and associated
//   block placement; calls, frame, boundary, and size are otherwise aligned.
// - Removing the outer count guards reduced the CFG count but regressed to 744
//   exact 765-byte size and saved EBX, but used EBX for the count and regressed
// - Zero locals derived from objectId or the scan index, and explicit stage-skip
//   gotos, all emitted the clean candidate unchanged; no new structural lead.
//   returns.  EBX and several structural blocks aligned, but size fell to 632
//   bytes and one removeFromGroup call site disappeared; restored.
//   The compiler inlined auxiliary contains calls too, losing four call sites
//   and growing to 804 bytes; restored the clean candidate.
//   recovered the saved-EBX prologue but grew to 839 bytes, with a broad CFG
//   shift; restored the clean candidate.
// - Corrected the boat-removal continuation into the war-boat scan.  This
// - Renewed pass: 21 distinct source, liveness, control-flow, and context
//   the frameless boundary, and the correct owning symbol.  The unresolved
//   original saved EBX, all ten calls, and every block.
// - VC5 inlines the first three remove calls. The original TU also inlines the
//   fourth war-boat call, but the isolated TU exhausts its inline budget there.
//   adds one call and removes 92 bytes, so it cannot model the executable.
// - The original control flow checks war, fishing, trade, and transport only
//   after a successful boat removal. If the boat scan fails, it checks only
//   artifacts. This source preserves that shipped list ownership.
//   with a natural remove call produced 673 bytes, 11 calls, and 397 strict
//   diff bytes. Restoring the body rebuilt the 765-byte exact result in the
//   authentic taitacmd.cpp translation unit.
// [non-comment lines omitted during migration]
                // Exact remove body at the fourth inline site.
```
<!-- end-recovered:26312e8aac64d5dd6432 -->

<!-- recovered:2f56e9b3d6ad9528e5fd -->
### `6a2aef2e2` `src/taitacmd.cpp:4207-4267`

Mapping: `ambiguous`. comment lies after mapped function evaluateCivilianDistribution at old line 4097.

```text
// __thiscall, int, ret 8
//
//   ManagedArray<int> surface (inline operator[] grow, remove, out-of-line
//   resize) and the plain source-level algorithm: new-explorer creation,
//   gatherer->explorer conversion by needed-resource priority, excess-
//   explorer removal, gatherer creation, and the refresh loop that tasks
//   civilians one per tick (return j = count tasked).
//   VC5 emits real ManagedArray<int>::resize calls (call set then fully
//   aligned; target-count gap 0).
//   inside it pass the `tasked` variable (register pushes, not -1 literals);
//   the loop is `do { if (tasked != -1) goto append; ... } while (newExplorer
//   > -1)` under an early-exit check. VC5 still rotates the loop-top tasked
//   check to the loop bottom (proves tasked == -1 at the head) so the
//   original's separate B010 top-check block is not reproduced.
//   == 0) { addGatherer path }` keeps the addGatherer path inline and
//   task_done as the skip target (original's jne layout); call sites 100%
//   aligned.
//   indexing civilians[taskedCount-1]): both regressed; VC5 emits extra
//   explorer scan exposed the refresh-loop operator[] grow at the original
//   top block and restored the 0x14 frame. The value form is the cleanest
//   forms added an unnecessary address alias. Split taskedCount initialization
//   was emitted identically to `i + 1`.
//   1563B strict diff and 90.50% shape. Comma and reverse coordinate forms,
//   separate coordinate locals, local declaration order, direct member-call
//   arguments, and combined refresh IV expressions were duplicate or worse.
//   to 1260B diff, 96.59% shape, and 86.70% exact-block coverage. Explicit
//   excess-removal labels gave 1150B strict diff but poor resynchronization and
// - The final unresolved candidate is 2083B versus 2062B, 39/39 ordered calls,
//   remaining evidence points to VC5 scheduling and refresh register homes.
// - Canonical ownership: md +0xF0, civilians +0xF4 (ManagedArray<int>),
//   civilianExplorers +0x104 (ManagedArray<int>), numberGatherersValue +0x9CC,
//   desiredNumberGatherersValue +0x9D0, neededResourceValue[4] +0xD88,
//   nextCivilianToTaskValue +0xF7C. taskCivilians returns j, the number of
//   civilians tasked this tick.
// - Call set (39): object x5, __ftol x6, idleCivilian x4, removeGatherer,
//   resize x2, operator_new/delete (inline grows), stopUnit, addGatherer x2,
//   highLevelTaskGatherer, highLevelTaskExplorer, updateGathererDistribution,
//   debug_timeGetTime x2.
// - ManagedArray audit: the local template remains the canonical utmarray.h
//   resize stays declaration-only for the real 004147A0 out-of-line call.
//   all metrics remained unchanged.
//   caller-side explorer scan and append. Duplicate failure still exits through
//   the scan to its canonical method owner; resize remains declaration-only.
// - Shared-context pass: restore the nested inline operator[] allocation body.
//   The grouped function then equaled all 2083 standalone bytes. The prior
//   declaration-only shared resize surface had collapsed it to 1312 bytes.
// - Contextual matching pass: retain a civilian-array owner across the setup
//   resize and publication, compare the requested ID against civilians[i],
//   and let operator[] own the timed-return capacity guard. The grouped and
//   standalone bodies now equal 2064 bytes, with exact frame, calls, and CFG.
//   two-byte induction-value register move remains after the refresh search.
//   Adding exact 004F4760 after the excluded 004F21F0 did not change this body.
//   The shared context still declares removeGatherer as void, while the exact
// - Final pin was blocked by a concurrent config/translation_units.json edit:
//   the loader rejects 00543E00 as an owner of world_scenario_sparse. No shared
//   config or helper file was changed by this pass.
//   914 differing bytes, and 39/39 ordered calls. During the pass, the shared
//   taitacmd header changed ManagedArray::resize from declaration-only to an
//   inline body. That changed this owner to 2236 bytes with 10 new/delete calls
//   and removed both resize calls. It also changed 004F13F0 to 679 bytes.
//   The target source was restored; no context bridge was retained.
```
<!-- end-recovered:2f56e9b3d6ad9528e5fd -->

<!-- recovered:0964113d619a0d0555cb -->
### `target-session` `build/target_sessions/004F13F0_evaluateCivilianDistribution.json:1-55`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=73; shape=94.52054794520548: Natural typed baseline from existing source; establish current bytes, calls, CFG, and frame.
probe 2 variant; result=MISMATCH; diff=73; shape=94.52054794520548: Low-count natural field-owned spelling: compare and subtract directly through desiredNumberGatherers, removing temporary max/gatherers aliases. [same emitted code as probe 1]
probe 4 variant; result=MISMATCH; diff=156; shape=92.10526315789474: Low-count source-control hypothesis: assign explorer desired in count-one and non-one arms, then clamp the stored member directly.
probe 6 control-flow; result=MISMATCH; diff=156; shape=92.10526315789474: Natural low-count shared-tail label after explicit explorer assignment, testing the original two low-path final calls without duplicated arm calls.
probe 8 liveness; result=MISMATCH; diff=85; shape=95.17241379310344: Split low-count civilian subtraction into a member read assignment plus compound subtraction, testing whether VC5 reloads the unchanged count.
probe 10 abi; result=MISMATCH; diff=73; shape=94.52054794520548: Canonicalized the local four-int array surface to ManagedArray<int> while preserving tactical ownership and offsets.
probe 11 control-flow; result=MISMATCH; diff=73; shape=95.83333333333333: Low-count field write before the sn[3] clamp, retaining the common final assignment to test natural store elimination and call-tail layout.
probe 13 variant; result=MISMATCH; diff=73; shape=95.83333333333333: variant lab build\variant_lab\004F13F0_evaluateCivilianDistribution\20260817_112502: 4 variants, 0 invariant-eligible, 0 exact
probe 14 control-flow; result=MISMATCH; diff=156; shape=92.10526315789474: Explicit outer-arm display/update tails with typed low-count field assignments, testing the original two return-tail layout without compiler-generated duplication. [same emitted code as probe 4]
probe 16 liveness; result=MISMATCH; diff=73; shape=94.52054794520548: Reused the typed gatherers local for the sn[5] cap before the field assignment, testing original EAX/ECX low-count register roles without raw steering. [same emitted code as probe 2]
probe 18 liveness; result=MISMATCH; diff=80; shape=89.6774193548387: Rewrote the low-count gatherer cap as a natural min-style local selection before the member store, testing the original cap load/store order.
probe 20 liveness; result=MISMATCH; diff=73; shape=94.52054794520548: Reordered only the low-count cap local before desired, testing VC5 declaration-color allocation while preserving typed field logic. [same emitted code as probe 16]
probe 24 liveness; result=MISMATCH; diff=76; shape=94.48275862068965: Reordered low-count source to write explorer desired first, then compute and store gatherers, matching original low-tail ownership and register lifetimes.
probe 25 control-flow; result=MISMATCH; diff=125; shape=75.33333333333333: Removed the post-branch explorer assignment and placed the one-civilian zero store in its arm, matching the original two low-count tails.
probe 27 liveness; result=MISMATCH; diff=91; shape=91.83673469387755: Kept one shared explorer result while ordering the low-count cap before gatherer subtraction, testing natural result liveness against the original low tail.
probe 29 liveness; result=MISMATCH; diff=73; shape=94.52054794520548: Moved only the low-count sn[5] load before the initial gatherer store, testing original constant-register preservation without changing field ownership. [same emitted code as probe 23]
probe 30 behavior; result=MISMATCH; diff=145; shape=90.66666666666667: Matched the Ghidra-supported low-count ownership: cap desired gatherers with sn[5], derive explorer desired directly, then cap it with sn[3].
probe 32 control-flow; result=MISMATCH; diff=145; shape=90.66666666666667: Used a local low-count join label supported by the original shared 15DF tail, while preserving typed field ownership and cap order.
probe 35 behavior; result=MISMATCH; diff=73; shape=94.52054794520548: Replace both manual element-zero resize/value sequences with the exact ManagedArray operator[] body.
probe 36 behavior; result=MISMATCH; diff=96; shape=94.48275862068965: Recover the low-count field ownership shown by the original: set gatherer demand first, derive explorer demand from both members, then cap the stored explorer field.
probe 37 liveness; result=MISMATCH; diff=73; shape=94.52054794520548: Use a period register hint on the shared desired local so the low-count constant can remain in ECX while sn[5] loads into EAX. [same emitted code as probe 35]
probe 38 liveness; result=MISMATCH; diff=96; shape=94.48275862068965: Keep the shared desired=1 local for the original ECX setup, but derive and cap explorer demand through the stored gatherer and explorer members. [same emitted code as probe 36]
probe 39 control-flow; result=MISMATCH; diff=156; shape=92.10526315789474: Store explorer demand before the sn[3] cap while keeping the computed result live; put the one-civilian explorer store in its own arm.
probe 40 liveness; result=MISMATCH; diff=73; shape=95.83333333333333: Add the binary-observed pre-cap explorer store while retaining the common final assignment that preserves one display/update tail.
probe 41 liveness; result=MISMATCH; diff=73; shape=95.83333333333333: Separate the low-count one value into a branch-local local, preserving it across the sn[5] load while the shared desired local owns explorer demand.
probe 42 liveness; result=MISMATCH; diff=93; shape=95.86206896551724: Use a scoped reference for low-count gatherer demand to block stale civilian-count reuse and preserve the original member load/store lifetime.
probe 43 liveness; result=MISMATCH; diff=73; shape=95.83333333333333: Sequence the sn[5] load before the required gatherer store with a comma expression, matching the original load/store/compare order.
probe 44 liveness; result=MISMATCH; diff=73; shape=95.83333333333333: Register-qualify the low-count sn[5] cap local to target its original EAX role while desired remains in ECX. [same emitted code as probe 43]
probe 45 control-flow; result=MISMATCH; diff=75; shape=96.52777777777777: Reconstruct the Ghidra-supported low-count local reuse: one result holds 1, sn[5], then sn[3], with one shared explorer assignment and cap skip.
probe 46 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Apply a register hint to the Ghidra-reused low-count result that holds one, sn[5], and sn[3], targeting the original EAX role.
probe 47 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Swap the two Ghidra-backed low-count result declarations so gatherers precedes the reused desired/cap result. [same emitted code as probe 46]
probe 48 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Scope the Ghidra cap and remaining results to the low-count branch instead of reusing function-wide high-count locals.
probe 50 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Swap low-count assignment order: store desiredNumberGatherers=1 before loading sn[5], preserving the original ECX constant and EAX cap roles. [same emitted code as probe 49]
probe 52 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Use a branch-local lowCountCap separate from desired=1: retain the constant in ECX, load sn[5] into the cap local, then reuse it for sn[3]. [same emitted code as probe 45]
probe 54 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Use direct repeated sn[5] member reads in the low-count cap, avoiding a named cap local while retaining desired=1. [same emitted code as probe 50]
probe 56 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Separate low-count gatherers=1 from the sn[5] result: keep the one constant live across the cap load and use gatherers for the civilian-minus-gatherers result. [same emitted code as probe 54]
probe 58 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Reverse the low-count cap predicate to source form desired > sn[5], matching original compare polarity while retaining the constant desired local. [same emitted code as probe 56]
probe 60 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Carry a named numberCivilians value from the pre-branch load through the low-count branch, matching the Ghidra iVar3 ownership and forcing the original post-cap civilian reload. [same emitted code as probe 52]
probe 61 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Place numberCivilians after the existing desired/gatherers locals, testing Ghidra iVar1/iVar2/iVar3 declaration coloring without changing field ownership. [same emitted code as probe 60]
probe 63 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Use a low-branch-scoped lowDesired result plus pre-branch numberCivilians, separating high-path desired liveness from the original low-count iVar1 reuse. [same emitted code as probe 48]
probe 65 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Use gatherers as the first low-count cap temporary, then overwrite it with numberCivilians minus desired gatherers; this tests the Ghidra iVar1/iVar3 split. [same emitted code as probe 61]
probe 67 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Reuse gatherers for the pre-branch civilian count and low-count one test, matching Ghidra's iVar3 lifetime while leaving the high-path final subtraction explicit. [same emitted code as probe 58]
probe 69 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Force the original low-count load/store/compare evaluation order with a comma expression: sn[5] load, desired gatherer store, then cap predicates.
probe 71 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Mirror Ghidra's three integer lifetimes: percentExplored is reused for the low-count result, gatherers carries the pre-branch civilian count, and numberItems remains separate. [same emitted code as probe 67]
probe 74 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: separate one, gatherer limit, and explorer limit locals for the low-count tail [same emitted code as probe 69]
probe 78 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Keep desired=1 live in ECX while reusing gatherers for sn[5], then the direct civilian-count reread and explorer demand. [same emitted code as probe 77]
probe 79 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Compare the stored desiredNumberGatherers field against named sn[5], matching PDB line 3294 load-store-compare ownership. [same emitted code as probe 78]
probe 81 abi; result=MISMATCH; diff=75; shape=96.52777777777777: Restore the exact same-TU TacticalAIModule inheritance and compiler-owned virtual base instead of a raw 0xF0 prefix.
probe 82 context; result=MISMATCH; diff=75; shape=96.52777777777777: Use the proven numberCivilians accessor as an inline same-TU body for all civilian count reads.
probe 84 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Keep the one local live while a separate gatherer-limit local loads sn[5], then reread the civilian count naturally. [same emitted code as probe 83]
probe 86 liveness; result=MISMATCH; diff=75; shape=96.52777777777777: Use the direct stored-field gatherer cap against sn[5], matching the original load-store-compare ownership without a cap local. [same emitted code as probe 84]
probe 88 variant; result=MISMATCH; diff=75; shape=96.52777777777777: variant lab build\variant_lab\004F13F0_evaluateCivilianDistribution\20260823_170857: 30 variants, 30 invariant-eligible, 0 exact
probe 89 variant; result=MISMATCH; diff=75; shape=96.52777777777777: variant lab build\variant_lab\004F13F0_evaluateCivilianDistribution\20260823_170946: 45 variants, 33 invariant-eligible, 0 exact
probe 90 variant; result=MISMATCH; diff=75; shape=96.52777777777777: variant lab build\variant_lab\004F13F0_evaluateCivilianDistribution\20260823_171023: 51 variants, 36 invariant-eligible, 3 exact
probe 91 behavior; result=MATCH; diff=0; shape=100.0: Use canonical ManagedArray number and setDesiredNumber inline methods at the low-count publication boundary; retain the observable count reread.
```
<!-- end-recovered:0964113d619a0d0555cb -->

<!-- recovered:81ab630ac581d045df4c -->
### `c75cc48eda71` `src/scratch/004F13F0_evaluateCivilianDistribution.cpp:1-59`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004F13F0 TribeTacticalAIModule::evaluateCivilianDistribution()
// Source: taitacmd.cpp lines 3202-3308
// Attempt log:
// - Reconstructed ManagedArray<int> as the proven four-int, 0x10-byte type and modeled the owning
//   TribeTacticalAIModule fields through zoomingToNextAge. This fixed the +0xFA4 field and gave the
//   natural typed baseline 530 bytes, with the original call order but duplicated final calls.
// - Kept the visible-map chain, shared ManagedArray pointer local, ceil expression, and zero local;
//   these reproduce the original prologue and main path through the low-count tail.
// - An early-return small-count spelling and a direct one-civilian explorer assignment were tested
//   and rolled back. The former was broad; the latter improved block coverage but kept duplicated calls.
// - Modeled the low-count result as desired=1, a gatherer cap, and one final explorer assignment.
//   This removed the extra display/update calls and recovered all 13 ordered calls, 3 jumps, 2 returns,
//   and 90.97% exact-block coverage. Best current output is 509 effective bytes versus 514, 73 strict
//   differing bytes, with the remaining drift localized to the low-count register and shared-tail shape.
// - A goto-based shared-tail spelling added a stack slot and caused broad drift, so it was rolled back.
//   Reloading gatherers, reversing the sn5 comparison, and naming the sn5 limit produced duplicate codegen.
// - A focused direct explorer-result assignment with a live one-count predicate added two final-call
//   sites and widened the function by 25 bytes, so it was rolled back.
// - A typed low-count field-order spelling assigned explorer and gatherer results in separate arms;
//   it reproduced that earlier 539-byte basin with two extra calls and was rolled back.
// - An initialized shared-tail result restored exact size, CFG, and call parity, but strict drift was
//   75 bytes versus the clean 73-byte source; reordering the sn5 read was codegen-duplicate, so rolled back.
// - A direct low-count field-order rewrite added a second civilian-count test and widened the function
//   to 530 bytes; it was rolled back because the first structural hunk moved to the setup call.
// - A natural typed field assignment in each low-count arm reproduced the 539-byte, two-extra-call
//   basin; it was rolled back because it split the shared call tail.
// - Tried the PDB-shaped low-count order: store explorers before the sn[3] gate and use a common
//   cap tail. This restored 514-byte size and 144 instructions, but VC5 hoisted the sn[3] load
//   before the explorer store and left 75 differing bytes; rolled back.
// - Left in scratch: current source is the best natural typed reconstruction. No inline asm or custom flags.
// - Rechecked this target from the original 514-byte body. Natural low-count field-store variants either
//   duplicated the two final calls or moved the outer tail; the min-style cap and declaration-order probes
//   were codegen duplicates or worse. Restored the pinned source: 509 bytes, 13 ordered calls, 90.97% exact
//   block coverage, and 73 differing bytes. The first structural drift remains at rebuilt +0x178 (004F1568),
//   where VC5 keeps the low-count cap in a different register/lifetime shape. No policy-invalid steering kept.
// - ManagedArray recovery pass, 2026-08-19: both manual element-zero grow/read
//   sequences now use the exact operator[] body. The emitted bytes are equal,
//   but method ownership is canonical and resize remains out of line.
// - Restored the binary-supported low-count local reuse from the decompiler:
//   one result holds 1, sn[5], then sn[3], and the computed explorer demand is
//   stored before its cap. This gives exact 514-byte size, 144 instructions,
//   13 calls, and CFG. The remaining 75 bytes are one localized register map.
// - Exact addObject and removeObject predecessor contexts did not change this
//   target. Register hints, branch-local result scopes, references, and store
//   sequencing were duplicates or worse. No compiler-context shim is retained.
// - Worker audit, 2026-08-22: Ghidra confirms a low-count civilian-count local
//   and one reused result local. Pre-branch count reuse, result-local reuse,
//   branch-local cap declarations, direct member rereads, assignment order,
//   and comma sequencing all emitted the same 514-byte, 75-byte-diff basin.
//   Restore the pinned source. The first unproved register divergence remains
//   the sn[5] load and later civilian-count reload at +0x178.
// - Accepted-drift audit: do not promote. In the low-count path, the executable
//   reloads civilians.numberValue after it updates desiredNumberGatherers. The
//   rebuild reuses the earlier count read. Concurrent count changes can produce
//   a different civilianExplorers result and different later stores.
// - Fresh contextual pass restored the exact same-TU TacticalAIModule virtual
//   inheritance. The emitted body is unchanged. The decompiler-shaped local
//   reuse, stored-field cap comparison, and inline numberCivilians accessor are
//   also codegen duplicates. The observable count-reread blocker remains.
```
<!-- end-recovered:81ab630ac581d045df4c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
