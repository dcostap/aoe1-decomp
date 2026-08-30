# Function notes: 004F8E20 `updateGathererDistribution`

Module notes: `decomp_notes/taitacmd_module.md`.

## Recovered attempt history

<!-- recovered:f8b731b6cdfcb1111253 -->
### `d050eea3c` `src/taitacmd.cpp:9373-9387`

Mapping: `ambiguous`. next mapped function definition is updateGathererDistribution at old line 9520.

```text
// 482 bytes and worsened the result to diff 419.
// Revisit v23: restored the PDB-proven four-entry assignedResource array and
// [non-comment lines omitted during migration]
// the remaining mismatch is the earlier initialization register basin.
// [non-comment lines omitted during migration]
// the 403-byte metric but changed the final copy to a countdown basin. It was
// rejected because the PDB names three separate arrays.
// [non-comment lines omitted during migration]
// codegen duplicates. The natural unqualified declarations remain authoritative.
// BLOCKER: the current typed reconstruction has the exact frame and 478-byte
// [non-comment lines omitted during migration]
// the first mismatch is local initialization at +0x2B. The original keeps -1
```
<!-- end-recovered:f8b731b6cdfcb1111253 -->

<!-- recovered:9ddbb7c85a040a286bac -->
### `6a2aef2e2` `src/taitacmd.cpp:8105-8139`

Mapping: `ambiguous`. next mapped function definition is updateGathererDistribution at old line 8237.

```text
// - v2: corrected sn from pointer to embedded array at +0x194 (sn[0x93] observed at +0x3e0).
// - v4: modeled assignedResource as 5 ints: counter at [0], flags at [1..4], matching original 0x34 frame.
// - v5: made loop index register to try to force ESI index / EDI this allocation.
// - v7: reordered local array declarations so assignedResource occupies low stack offsets like original.
// - v8: grouped arrays in a local struct to force assigned/tempNeeded/tempDiff contiguous stack layout.
// - v9: reordered one-time array initialization to match original flag/temp output stack stores.
// - v10: tried a fixed four-entry initialization loop; VC5 kept the loop and
//   lost the original unrolled stores, so it was restored.
// - v11: replaced raw md subobject casts with canonical buildAI/resourceAI
//   members and restored the proven AIModule, ResourceItem, and tactical sizes;
//   emitted code stayed unchanged while source ownership became typed.
// - v13: removed the self alias; emitted code stayed unchanged.
// - v14: initialized the fallback assigned-resource pointer at slot 1; this
// - v15: separated the local arrays as a control; it preserved the frame but
//   changed the prologue and was restored.
// - v16: rewrote the final copy as an indexed four-entry loop. VC5 reduced the
//   size to 478 bytes and kept the natural member ownership; this is the
// - v18: changed the final indexed loop to a counted for form; VC5 emitted the
//   same code.
// Revisit v19: restored three direct four-entry arrays and a separate scalar;
// Revisit v20: moved the difference-pointer declaration after scalar locals;
// VC5 emitted duplicate code at diff 403.
// Revisit v21: removed the invented aggregate and used direct typed arrays;
// Revisit v22: used typed parallel pointers for the final copy; VC5 emitted
// kept the byte offset as its own scalar, rather than folding the offset into
// a fifth array slot. This tests the original local ownership and indexing.
// Revisit v24: replaced the fallback pointer walk with direct indexed array
// reads. VC5 now emits the original independent pointer setup and loop bytes;
// Revisit v25: a four-entry local aggregate plus a separate offset retained
// Revisit v26: register hints for the difference cursor and first result were
// size, eight ordered calls, and correct field offsets. It remains non-exact:
// in EDX and EAX and zero in ECX. VC5 keeps only -1 in EAX and zero in ESI.
// The first difference scan also swaps the original EBP result and EBX cursor.
// The indexed fallback and final copy preserve the original pointer topology,
// but no period-plausible source change has recovered the early colors. Leave
```
<!-- end-recovered:9ddbb7c85a040a286bac -->

<!-- recovered:06d0ac62f746eef5ee43 -->
### `target-session` `build/target_sessions/004F8E20_updateGathererDistribution.json:1-37`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1237; shape=82.90816326530613: Baseline current clean reconstruction before new probes; establishes frame, size, calls, and first mismatch.
probe 2 liveness; result=MISMATCH; diff=1240; shape=83.16326530612245: Probe 1: move local_4 initialization between actual distribution slots 1 and 2, mirroring original PDB store order; tests declaration/initialization scheduling.
probe 4 control-flow; result=MISMATCH; diff=1263; shape=81.12244897959184: Probe 2: replace bounded resource scan's post-loop boolean tests with the binary-supported found-label CFG; tests whether the extra clear/reload blocks are source-goto topology.
probe 6 layout; result=MISMATCH; diff=1237; shape=82.90816326530613: Probe 3: split proven +0xF8C builtFirstGranary read from +0xFA4 zoomingToNextAge writes; dossier/original bytes show distinct ownership, testing canonical field layout.
probe 7 liveness; result=MISMATCH; diff=1237; shape=82.90816326530613: Probe 4: reverse each weighted percentage operand pair to match original load order: +370/+40C, +36C/+410, +374/+408, +368/+404; tests expression evaluation order. [same emitted code as probe 6]
probe 8 layout; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 5: add the proven DA8-DB8 class gap before the F8C/F A4 fields; prior source labels did not advance the C++ layout, and rebuilt wrote +F94 instead of original +FA4.
probe 9 liveness; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 6: assign the desired-distribution cursor before initializing the special-result flag, testing original EDI cursor/EAX zero/EBX flag scheduling at the four initial stores. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=1261; shape=84.94897959183673: Probe 7: type the special-distribution predicate as bool, matching Ghidra's proven bVar1 and testing flag-width/register allocation against original EBX 0/1.
probe 12 variant; result=MISMATCH; diff=1276; shape=81.6793893129771: Probe 8: model final remainder as separate unsigned remaining/sign locals and the decompiler-proven signed-unsigned parity expression; tests the original abs/division/parity lowering.
probe 13 variant; result=MISMATCH; diff=1270; shape=81.88775510204081: Probe 9: remove the explicit absolute-value local and use natural signed rem/2 plus rem%2 inside the positive branch; tests whether VC5 emits the original duplicated division/parity sequence.
probe 14 abi; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 10: restore donor-supported polymorphic class surfaces and preserve proven offsets (vptr plus reduced gaps); tests translation-unit/type-context effects on direct member codegen. [same emitted code as probe 11]
probe 15 context; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 11: add donor-supported period <stdlib.h> context from exact same-TU taitacmd.cpp functions; tests front-end header state without changing source behavior. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 12: stage the first gold percentage operands in separate locals to force source-order field loads; tests original +370 then +40C scheduling versus VC5's commutative expression basin. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 13: cache md in a loop-local decision pointer before object(id), testing whether receiver alias liveness restores original push-id-before-receiver-load order. [same emitted code as probe 16]
probe 18 control-flow; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 14: spell the default-distribution guard as special == 0 instead of !special; tests compare polarity and flag register color against original cmp flag,zero. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 15: use a dedicated sumCount local for both four-element totals instead of reusing gatherer index i; decompiler shows distinct count locals and original EAX/ECX sum-pointer roles. [same emitted code as probe 18]
probe 20 context; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 16: add period <string.h> beside the donor-supported <stdlib.h> include; tests standard-header front-end state as a translation-unit basin hypothesis. [same emitted code as probe 19]
probe 21 context; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 17: add period <memory.h> to the standard-header context; tests the documented old-MSVC header-combination basin. [same emitted code as probe 20]
probe 22 liveness; result=MISMATCH; diff=1262; shape=83.6734693877551: Probe 18: declare the special-result local first, matching Ghidra's local ordering (bVar1 before object/index locals); tests declaration-order register coloring.
probe 23 control-flow; result=MISMATCH; diff=1237; shape=83.92857142857143: Probe 19: rewrite the age dispatch from else-if chain to explicit nested if blocks, matching Ghidra's nested inAge(1)->inAge(2)->inAge(3) CFG hypothesis. [same emitted code as probe 21]
probe 27 baseline; result=MISMATCH; diff=1237; shape=83.92857142857143: Baseline after resuming prior clean source; confirm 1369-byte natural reconstruction before new scan/prologue work. [same emitted code as probe 26]
probe 28 control-flow; result=MISMATCH; diff=1282; shape=81.6793893129771: Hypothesis: use the binary-proven clear/found labels around the bounded task scan. A do-loop with an in-body maximum guard and fall-through clear should remove the rebuilt post-loop equality blocks.
probe 30 liveness; result=MISMATCH; diff=1232; shape=82.39795918367346: Hypothesis: reuse the binary-proven local_4 home for negative-resource count, and retain desiredNumberGatherers-sum as the correction numerator. Ghidra shows local_4 reused at +92E2 and this should select the original EBP/EBX roles.
probe 31 liveness; result=MISMATCH; diff=1235; shape=82.90816326530613: Refinement: retain a named rem local across the negative-resource loop while reusing local_4 only for the count, to test the original rem-in-EBP and count-in-ESP topology.
probe 32 variant; result=MISMATCH; diff=1265; shape=80.6615776081425: Hypothesis: restore the Ghidra-proven unsigned remaining/sign parity expression for the final split. The emitted original has abs-and-sign x86 arithmetic, which the current signed odd/if spelling does not reproduce.
probe 33 control-flow; result=MISMATCH; diff=1235; shape=82.90816326530613: Hypothesis: mirror Ghidra's shared LAB_004f8f4c count tail. Both action 261/265 and a matching tasked ID should jump to one increment block; a no-match scan should fall through to the outer gatherer update. [same emitted code as probe 31]
probe 34 liveness; result=MISMATCH; diff=1238; shape=83.16326530612245: Hypothesis: use the Ghidra/PDB initial store order exactly: actual slots 0,1, local_4 zero, then slots 2,3. Combine it with the tested local_4 negative-count reuse to see if later liveness preserves the gain.
probe 35 liveness; result=MISMATCH; diff=1244; shape=82.90816326530613: Hypothesis: separate local_4 assignment after all four actual-distribution clears. This tests whether VC5 then keeps EAX for constant field stores and EBP only for the stack local, matching the original zero-register split.
probe 37 liveness; result=MISMATCH; diff=1246; shape=83.92857142857143: Hypothesis: declare and initialize local_4 at its first source use, after the four actual-distribution clears. This is distinct from declaration-at-function-entry and tests VC5 declaration-scope/register scheduling.
probe 39 liveness; result=MISMATCH; diff=1237; shape=83.92857142857143: Hypothesis: use a distinct zero local for the four actual-distribution stores, while local_4 retains its own zero initialization. This tests whether the original EAX zero plus EBP zero reflects two source values rather than a scheduler choice. [same emitted code as probe 27]
probe 41 variant; result=MISMATCH; diff=1270; shape=81.88775510204081: Hypothesis: simplify the final positive remainder split to natural rem/2 and rem%2 inside the rem>0 guard. This tests branch-first CFG and signed arithmetic against the original's early test before parity lowering. [same emitted code as probe 13]
probe 43 control-flow; result=MISMATCH; diff=1282; shape=81.6793893129771: Hypothesis: write the first task scan as an explicit capacity-positive branch with the count loop at the bottom. This avoids a constant-zero max test and may preserve the original cmp index,max then fall-through clear CFG. [same emitted code as probe 28]
probe 45 liveness; result=MISMATCH; diff=1237; shape=83.92857142857143: Hypothesis: use one natural compound-assignment percentage accumulator for each weighted pair. This tests whether assignment dependencies preserve original first-operand field loads (+370 then +40C, etc.) where commutative expressions reverse them. [same emitted code as probe 39]
probe 47 layout; result=MISMATCH; diff=1242; shape=72.70408163265306: Hypothesis: replace split named strategic-number fields with the canonical int sn[0xE2] array at +194. Ghidra proves sn indices 0x75-0x9F and age flags 0xB5-0xB7; this tests array ownership and indexed field lowering.
probe 48 layout; result=MISMATCH; diff=1237; shape=83.92857142857143: Correction to the canonical sn-array test: remove the obsolete gap474 after sn[0xE2]. The array itself ends at +51C, so gatherers retain their proven +51C ownership.
probe 49 abi; result=MISMATCH; diff=1236; shape=83.16326530612245: Hypothesis: replace raw md-relative BUILD/AGE_RES/RESOURCE macros with a reviewed nested MainDecision surface at +104, +CEC/+540, and +10D7C. This tests natural ownership without changing proven offsets or call ABI.
probe 51 liveness; result=MISMATCH; diff=1237; shape=83.92857142857143: Hypothesis: lift the object receiver local to function scope, matching Ghidra's top-level this_00 declaration. This tests whether longer object lifetime restores the original first-call argument/receiver register topology. [same emitted code as probe 45]
```
<!-- end-recovered:06d0ac62f746eef5ee43 -->

<!-- recovered:04381ea2c887f6d9fad2 -->
### `3789ccb1ae1e` `src/scratch/004F8E20_updateGathererDistribution.cpp:2-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004F8E20 TribeTacticalAIModule::updateGathererDistribution
// Attempt log:
// 1: broad reconstruction from packet: gatherer task counts, age/research special distribution, default weighted percentages, negative-share correction and final food/wood remainder split.
// 2: fixed zero-sized local class gap and compiled; best attempt reaches exact 1369-byte size.
// 3: first mismatch is frame/prologue: rebuilt uses 0x10 frame and pushes EDI before zeroing desired counts, while original uses 0x0C frame, delays EDI push, keeps zero in EAX and zero/index in EBP.
// 4: modeled gatherer stride 0x18, count +0x9CC, desired count +0x9D0, current task/target/priority fields, and resource-id validation scan.
// 5: modeled special cases for advancing ages/research readiness and the 5-priority retask stamping loops for nonzero/non-minus-one gatherers.
// 6: modeled default weighted distribution using integer percent division and late negative distribution correction/remainder split.
// 7: remaining mismatch is broad source/layout: original is highly ordered around explicit stack locals at esp+10/14/18, duplicated age2/age3/age4 blocks, magic multiply divisions, and shared tails; current source has behavior-like structure but wrong register/liveness/block layout. Not accepted_drift-safe.
// 8: replaced the first resource-ID boolean temporary with the bounded scan index as the natural not-found guard; frame reached 0x0C and positional diff improved, but the research call surface remains unresolved.
// 9: replaced guessed ageTime calls with the proven resource(1) calls and inlined the four percent products; all 15 direct call sites now align.
// 10: modeled UnitData, ManagedArray ownership, and the proven data1 cursor; the gatherer stride/address shape improved and the source remains period-plausible.
// 11: rewrote distribution totals and negative-resource correction as pointer loops; exact-block coverage improved to 43.37%, but the prologue remains structurally different.
// 12: retained the desired-distribution cursor and corrected array index ownership from original stores; current structural best is 1258 bytes (91.8919%) with 100% ordered-call alignment.
// 13: tested explicit absolute-remainder parity; it improved positional diff by one byte but reduced shape slightly, and remains the current clean reconstruction after the 10-hypothesis budget.
// 14: nested the age dispatch in original order and removed the incorrect age1-to-age3 and age2-to-age4 fallbacks; structural shape improved.
// 15: corrected the age4 no-research path to write desired distribution slots 0, 1, and 3, as shown by the original stores.
// 16: tested weighted percentage operand order; VC5 emitted the same arithmetic basin.
// 17: cached the proven object gameID after the action/type/state guard; this matches the original EDI overwrite before the first task-list scan and improved the first scan block.
// 18: separated literal actual-distribution clears from the outer loop index; this improved positional diff by four bytes but did not solve the prologue.
// 19: tried a structured found-label task scan to mirror the original skip-zero CFG; it worsened block shape and was rolled back.
// 20: declared the special-result local before the desired cursor; this improved whole-function liveness by seven bytes and remains plausible source order.
// 21: used pointer dereference spelling for first-slot desired writes; VC5 emitted a duplicate, so no codegen lead was found.
// 22: moved outer-index initialization between the first two clears to mirror stack-store order; it worsened codegen and was rolled back.
// Final clean reconstruction: natural typed ownership, corrected age dispatch and slot writes, 15 ordered calls aligned; remaining gap is structural prologue/CFG layout.
// Managed pass: 20 meaningful probes confirmed the pinned 1369-byte source as
// the best clean natural reconstruction (1237 positional bytes, 83.93% shape,
// 48.21% exact-block coverage, 15/15 ordered calls, and a 0x0C frame).
// Evidence-led layout correction: the resource scan fields include a proven
// DA8-DB8 gap, builtFirstGranary is at +F8C, and zoomingToNextAge is at +FA4.
// The earlier single-field model wrote the wrong member, even though its code
// size stayed equal. The corrected model improved exact blocks and is retained.
// Rejected managed probes: initialization reordering, found-label scan CFG,
// unsigned remainder parity, bool special flag, declaration-order changes,
// receiver aliases, sum-count aliases, nested age syntax, and standard-header
// combinations either worsened codegen or emitted the same bytes. Polymorphic
// donor-supported type surfaces also emitted the same bytes. The remaining
// blocker is structural prologue/register scheduling and the first-loop scan
// CFG, not call identity or field ownership.
// Follow-up worker validation: the pinned source still builds at 1369 bytes,
// with a 0x0C frame, 15 ordered calls, 83.93% shape, and 1237 differing bytes.
// Tested Ghidra-shaped task-scan labels, local_4 reuse for the negative count,
// initial-clear order, final remainder spellings, canonical sn-array layout,
// nested MainDecision ownership, and top-level object lifetime. The best new
// natural codegen was 1232 differing bytes but lost structural coverage; it
// was restored. The tested scan and prologue variants were worse or duplicate.
```
<!-- end-recovered:04381ea2c887f6d9fad2 -->
