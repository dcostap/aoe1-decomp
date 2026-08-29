# Recovery journal: 004F0190 `doSomething`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taitacmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taitacmd.cpp`.
- Earlier recovery note: `recovery_notes/taitacmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:80c1ae7b05736ac67ad5 -->
### `d050eea3c` `src/taitacmd.cpp:4011-4015`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// ---------------------------------------------------------------------------
// PDB source owner: 004F0190_doSomething.cpp
// ---------------------------------------------------------------------------
// 004F0190 TribeTacticalAIModule::doSomething
// Canonical baseline: named tactical-AI arrays/modules, natural switch dispatch,
```
<!-- end-recovered:80c1ae7b05736ac67ad5 -->

<!-- recovered:839b68e1e261fc8eab70 -->
### `d050eea3c` `src/taitacmd.cpp:4233-4233`

Mapping: `ambiguous`. comment lies after mapped function doSomething at old line 4073.

```text
                                // BINARY NOTE: PDB gives each branch its own position home.
```
<!-- end-recovered:839b68e1e261fc8eab70 -->

<!-- recovered:3fc56243d1f947bd8336 -->
### `d050eea3c` `src/taitacmd.cpp:4374-4374`

Mapping: `ambiguous`. comment lies after mapped function doSomething at old line 4073.

```text
                // BINARY NOTE: Wrap as unsigned, then use signed age division.
```
<!-- end-recovered:3fc56243d1f947bd8336 -->

<!-- recovered:7bfdcf9d2d6f8609ebc1 -->
### `target-session` `build/target_sessions/004F0190_doSomething.json:1-62`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MISMATCH; diff=420; shape=92.61538461538461: Hypothesis 1: debug_timeGetTime is an extern-C import-like direct symbol, as exact same-TU donor saveTheTown declares; this should restore direct call identity without changing body.
probe 2 liveness; result=MISMATCH; diff=420; shape=92.61538461538461: Hypothesis 2: swap startTime/updateTime declaration order so VC5 assigns the observed entry homes: updateTime +0x20 and startTime +0x1C, while availableTime can reuse the start home. [same emitted code as probe 1]
probe 3 control-flow; result=MISMATCH; diff=420; shape=92.61538461538461: Hypothesis 3: source case-label order controls VC5 switch block layout; place empty default before case 21 so the terminal case can land after the common outer timing return, matching original +0xA5C ordering. [same emitted code as probe 2]
probe 4 abi; result=MISMATCH; diff=506; shape=87.89625360230548: Hypothesis 4: lastBuildTime participates in signed world-time subtraction; original case 21 uses signed IMUL/SAR/JLE, while unsigned long caused MUL/SHR/JBE. Narrow to signed int to recover the proven arithmetic family.
probe 5 abi; result=MISMATCH; diff=506; shape=87.89625360230548: Hypothesis 5: keep the field ABI unsigned but cast only the elapsed world-time difference to signed long, seeking original signed IMUL/SAR/JLE without changing field liveness or object layout.
probe 6 liveness; result=MISMATCH; diff=420; shape=92.61538461538461: Hypothesis 6: use the PDB/decompiler local order (incUpdateArea, update-time, available-time, start-time, current-time, then points) to reproduce VC5 stack-slot coloring and the observed entry home reuse. [same emitted code as probe 3]
probe 7 control-flow; result=MISMATCH; diff=420; shape=92.61538461538461: Hypothesis 7: express the PDB-visible do-loop as an explicit positive break (elapsed >= budget) followed by while(true), testing whether VC5 emits the oracle's direct JB backedge instead of the current JAE exit plus register restore.
probe 8 liveness; result=MISMATCH; diff=420; shape=92.61538461538461: Hypothesis 8: scope each current-time local to its case/tail and use an explicit break, allowing updateTime to retain its loop register across the temporary timer result and removing function-wide currentTime liveness.
probe 9 liveness; result=MISMATCH; diff=506; shape=87.89625360230548: Hypothesis 9: materialize the world-time delta into a signed int local before dividing by 60000, matching original signed IMUL/SAR/JLE while retaining the unsigned field layout. [same emitted code as probe 5]
probe 10 control-flow; result=MISMATCH; diff=417; shape=92.92307692307692: Hypothesis 10: case 19's resource scan is a period for-loop with IV/cursor updates in the increment clause; the oracle's positive JL backedge contrasts with the current do/while JGE-plus-jump lowering.
probe 11 control-flow; result=MISMATCH; diff=417; shape=92.92307692307692: Hypothesis 11: use a positive continue for elapsed < budget and a following break in an infinite do-loop, testing whether VC5 preserves the oracle's JB backedge and late exit order.
probe 12 liveness; result=MISMATCH; diff=417; shape=92.92307692307692: Hypothesis 12: initialize updateTime and startTime at declaration, testing whether VC5 assigns the original entry homes before the first timer call rather than after separate assignments. [same emitted code as probe 10]
probe 13 liveness; result=MISMATCH; diff=417; shape=92.92307692307692: Hypothesis 13: scope availableTime inside the do-loop because it only lives from the per-iteration probe through that iteration's accounting; this may restore the original separate stack home from startTime. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=465; shape=91.84615384615384: Hypothesis 14: reverse the independent initial source assignments, testing whether VC5 keeps the observed field-load-before-call scheduling but swaps updateTime/startTime homes to match the oracle.
probe 15 liveness; result=MISMATCH; diff=419; shape=92.46153846153847: Hypothesis 15: reverse case 14's coordinate assignment order to test the oracle's x87 sequence, which loads world_x, converts, loads world_y, then stores the first result.
probe 16 liveness; result=MISMATCH; diff=419; shape=92.46153846153847: Hypothesis 16: reverse case 15's point assignment order to test the same x87 scheduling evidence in its repair-target coordinate conversion.
probe 17 liveness; result=MISMATCH; diff=419; shape=92.46153846153847: Hypothesis 17: reverse case 16's point assignment order to test the last repeated x87 coordinate block against the oracle's delayed first-result store.
probe 18 control-flow; result=MISMATCH; diff=418; shape=92.76923076923077: Hypothesis 18: use the proven fixed four-iteration bound as i != 4 rather than i < 4, testing whether VC5 keeps the same positive JL backedge while removing a signed-bound compare.
probe 19 liveness; result=MISMATCH; diff=417; shape=92.92307692307692: Hypothesis 19: combine case 19 IV/cursor initialization in the for header, testing whether VC5 schedules the zero/index LEA pair like the oracle while preserving the proven JL backedge. [same emitted code as probe 13]
probe 20 abi; result=MISMATCH; diff=503; shape=88.18443804034582: Hypothesis 20: make both the elapsed expression and 60000 divisor explicitly signed long, testing whether the original signed magic divide appears without changing the field declaration.
probe 23 control-flow; result=MISMATCH; diff=417; shape=92.92307692307692: Hypothesis 1: brace case 21 as a scoped switch arm, testing whether VC5 places the terminal arm after the outer timing return while preserving its source calls. [same emitted code as probe 22]
probe 24 control-flow; result=MISMATCH; diff=417; shape=92.92307692307692: Hypothesis 2: route case 21 through a late finish label after the ordinary outer return, with function-scope availableTime required by the late arm; test the oracle's late jump-table arm and terminal timing tail. [same emitted code as probe 11]
probe 27 abi; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: use a local inherited BuildAIModule virtual view in the registered context, preserving the original +0x44 dispatch while leaving shared anchor declarations unchanged.
probe 28 control-flow; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: move case 21 to a late finish label with function-scope availableTime, preserving the original terminal publication and cleanup placement after the ordinary timing return.
probe 29 control-flow; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: put the empty default arm before case 21, using PDB/source-order evidence to place the terminal case after the shared timing return without labels or helper code. [same emitted code as probe 27]
probe 30 liveness; result=MISMATCH; diff=350; shape=92.61538461538461: Hypothesis: reverse case-14 point assignment order so VC5 can carry the x conversion across the y87 load, matching the original delayed x home store while preserving the civilian call and fault order.
probe 31 abi; result=MISMATCH; diff=446; shape=88.07471264367815: Hypothesis: use explicit signed long operands only for the build-list age predicate, testing the original imul/sar/sign-correction/jle lowering while preserving the terminal call and publication order.
probe 32 liveness; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: restore the PDB/decompiler local order: update-area flag, update-time, available-time, start-time, current-time, then point and buffer locals; preserve all state and terminal calls. [same emitted code as probe 29]
probe 33 control-flow; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: place the empty default arm before all numbered cases, testing whether authentic switch default placement moves the ordinary timing and publication path ahead of cold case 21.
probe 34 liveness; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: combine case-14 coordinate assignments in one comma expression, testing whether VC5 schedules the second float load before the first converted value store as in the original. [same emitted code as probe 32]
probe 35 abi; result=MISMATCH; diff=446; shape=88.07471264367815: Hypothesis: narrow only lastBuildTime to the proven signed int arithmetic domain, testing whether VC5 emits the original signed age divide without the long-cast expansion.
probe 36 liveness; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: join updateTime and startTime declaration with their proven initializers, testing whether VC5 recovers the distinct entry homes and initial timing schedule without changing later state or calls. [same emitted code as probe 34]
probe 37 control-flow; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: route case 21 through a cold finish label before the ordinary outer timing label, with an explicit normal-path jump over terminal publication; test the original case-21 and 0xBC9 ordering without helper calls.
probe 38 control-flow; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: order the normal outer-timing label before the cold case-21 finish label, with explicit jumps for both paths; test whether source label order recovers the original 0xBC9-before-case21 layout. [same emitted code as probe 37]
probe 41 baseline; result=MISMATCH; diff=348; shape=93.07692307692308: Fresh registered taitacmd TU baseline after context, PDB bands, address order, exact anchors, fields, calls, and fault-order review.
probe 42 liveness; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: declare availableTime before updateTime so VC5 assigns the proven +0x14 and +0x18 homes while preserving the start-time spill and all call paths. [same emitted code as probe 41]
probe 43 liveness; result=MISMATCH; diff=348; shape=93.07692307692308: Hypothesis: restore the PDB local order and names: startTime, availableTime, incUpdateArea, updateAreaStartTime, temp buffer, then point locals. Preserve all behavior and calls. [same emitted code as probe 42]
probe 44 variant; result=MISMATCH; diff=348; shape=93.07692307692308: variant lab build\variant_lab\004F0190_doSomething\20260823_231044: 1 variants, 1 invariant-eligible, 0 exact
probe 45 variant; result=MISMATCH; diff=348; shape=93.07692307692308: variant lab build\variant_lab\004F0190_doSomething\20260823_231204: 20 variants, 20 invariant-eligible, 0 exact
probe 46 variant; result=MISMATCH; diff=417; shape=92.92307692307692: variant lab build\variant_lab\004F0190_doSomething\20260823_231349: 200 variants, 200 invariant-eligible, 0 exact
probe 47 variant; result=MISMATCH; diff=417; shape=92.92307692307692: variant lab build\variant_lab\004F0190_doSomething\20260823_231532: 20 variants, 20 invariant-eligible, 0 exact
probe 48 liveness; result=MISMATCH; diff=396; shape=93.38461538461539: Hypothesis: restore the three PDB-proven branch-local XYPoint variables, each named position at -0x108, -0x118, and -0x110. Test their authentic scopes against x87 store scheduling and whole-function layout.
probe 49 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_232356: 5 variants, 5 invariant-eligible, 0 exact
probe 50 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_232546: 12 variants, 12 invariant-eligible, 0 exact
probe 51 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_232657: 8 variants, 8 invariant-eligible, 0 exact
probe 52 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_232811: 2 variants, 2 invariant-eligible, 0 exact
probe 53 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_232837: 4 variants, 4 invariant-eligible, 0 exact
probe 54 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_232944: 8 variants, 8 invariant-eligible, 0 exact
probe 55 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233009: 4 variants, 4 invariant-eligible, 0 exact
probe 56 variant; result=MISMATCH; diff=327; shape=93.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233026: 3 variants, 3 invariant-eligible, 0 exact
probe 57 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233126: 512 variants, 512 invariant-eligible, 0 exact
probe 58 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233214: 12 variants, 12 invariant-eligible, 0 exact
probe 59 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233301: 12 variants, 12 invariant-eligible, 0 exact
probe 60 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233331: 6 variants, 6 invariant-eligible, 0 exact
probe 61 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233437: 4 variants, 4 invariant-eligible, 0 exact
probe 62 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233549: 2 variants, 2 invariant-eligible, 0 exact
probe 63 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233605: 10 variants, 8 invariant-eligible, 0 exact
probe 64 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233750: 2 variants, 2 invariant-eligible, 0 exact
probe 65 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233817: 2 variants, 2 invariant-eligible, 0 exact
probe 66 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_233932: 1 variants, 1 invariant-eligible, 0 exact
probe 67 variant; result=MISMATCH; diff=280; shape=95.53846153846153: variant lab build\variant_lab\004F0190_doSomething\20260823_234034: 2 variants, 2 invariant-eligible, 0 exact
probe 68 control-flow; result=MISMATCH; diff=395; shape=89.97134670487107: Hypothesis: combine the PDB-proven branch-local positions with direct member timing accumulation and the executable-proven signed cast of the unsigned world-time delta. This preserves wrap behavior and tests the authentic late CFG.
```
<!-- end-recovered:7bfdcf9d2d6f8609ebc1 -->

<!-- recovered:8e9a2640513825b6b925 -->
### `cf4b323f4c4e` `src/scratch/004F0190_doSomething.cpp:1-58`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004F0190 TribeTacticalAIModule::doSomething
// Canonical baseline: named tactical-AI arrays/modules, natural switch dispatch,
// and the period source's shared update-area timing tails.
//
// Attempt log:
// - baseline: canonical md/module ownership and natural dense switch; frame 0x128,
//   73/78 calls, 83.23% shape, 182 bytes short.
// - restored case 0x15's unskip/timing/select-next terminal path and direct
//   updateBuildAIWithObjects call; size and call count became exact (2514/78).
// - branch-local mostDamaged calls recovered the binary's push/jump dispatch;
//   current best remained structurally aligned through the tactical cases.
// - direct buildListLength call predicates recovered three test-eax blocks.
// - fixed common timing average to the executable's fixed /20 division; case 0x15
//   retains its separate total/count division.
// - declaration/name and goto/break normalization were codegen-neutral; retained
//   the natural source reconstruction rather than compiler-only CFG scaffolding.
// - final bounded result: 420 positional bytes / 92.62% shape, 78 calls, frame
//   0x128, first mismatch remains the initial timing local home and late timing
//   tail/block placement. Left in scratch after the 10-hypothesis budget.
// - follow-up: out-of-line case-21 labels, switch default/case order, timing
//   declaration permutations, and declaration initialization were codegen
//   duplicates; the direct world-time guard widened the body by 102 bytes.
//   Explicit common-tail labels widened it by 94 bytes. Restored the clean
//   natural source; the structural blocker remains unchanged.
// - Restored virtual ownership and the named build-file format string. The
//   raw vtable fields and absolute string address were diagnostic surfaces.
// - Fresh pass: extern-C timer linkage, timer declaration/assignment order,
//   switch-label order, scoped timer locals, explicit loop breaks, and several
//   coordinate assignment orders were duplicate or worse.
// - The PDB-backed case-19 resource scan is best written as a for-loop with
//   cursor updates in its increment clause. This restores the original JL
//   backedge and improves the clean result to 417 differing bytes, 92.92%
//   shape, 78/78 calls, and 0x128 frame.
// - The registered context now exposes a narrow nonvirtual TribeBuildAIModule
//   surface for exact anchors. A local inherited virtual view restores the
//   original +0x44 loadBuildList call without changing shared declarations.
//   Fresh output is 2514 bytes, 78 calls, frame 0x128, and 348 differing bytes.
// - CVDump proves four stack locals and their names. They are startTime at
//   -0x11C, availableTime at -0x120, incUpdateArea at -0x128, and
//   updateAreaStartTime at -0x124.
// - CVDump also proves three branch-local XYPoint variables named position.
//   Their homes are -0x108, -0x118, and -0x110. These scopes restore all three
//   x87 conversion blocks without fake aliases.
// - Direct member timing updates restore the four timing homes and the complete
//   common timing block. Local elapsed, total, and count values were decompiler
//   artifacts.
// - The executable casts the unsigned world-time delta to signed int before
//   division. This source keeps unsigned wrap, then applies signed division and
//   the signed <= 5 test.
// - The signed age block and direct timing source restore the internal case-21
//   blocks. The remaining mismatch is the late block order and boundary.
// - Gotos, shared returns, loop forms, timer scopes, switch order, missing
//   default, nested calls, duplicate exits, 512 ambient contexts, and supported
//   flag axes did not recover that order.
// BLOCKER: The executable puts the 0xBC9 finish block before cold case 21.
// VC5 puts case 21 first, adds a loop jump, and places the finish block last.
// With the required signed age source, the rebuilt reachable boundary is 98
// bytes too large because it also includes the following switch table.
```
<!-- end-recovered:8e9a2640513825b6b925 -->

<!-- recovered:b4f281f41d7991a56c23 -->
### `cf4b323f4c4e` `src/scratch/004F0190_doSomething.cpp:327-329`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// The original call uses the BuildAIModule virtual slot at +0x44.  The
// registered shared header keeps the derived loadBuildList declaration narrow
// for its exact owner, so use the inherited virtual surface only at this site.
```
<!-- end-recovered:b4f281f41d7991a56c23 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
