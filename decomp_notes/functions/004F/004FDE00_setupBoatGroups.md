# Function notes: 004FDE00 `setupBoatGroups`

Module notes: `decomp_notes/taitacmd_module.md`.

## Recovered attempt history

<!-- recovered:39d97d4df666d2c42cb4 -->
### `d050eea3c` `src/taitacmd.cpp:12518-12522`

Mapping: `ambiguous`. next mapped function definition is setupBoatGroups at old line 12632.

```text
//   matched 1324/1324 bytes; direct receiver repetition is period-plausible
// [non-comment lines omitted during migration]
//   kept in scratch for main-agent audit as requested.
// Source audit: restored the original format strings as ordinary literals and
```
<!-- end-recovered:39d97d4df666d2c42cb4 -->

<!-- recovered:daa18af880c0f1a9a3d0 -->
### `6a2aef2e2` `src/taitacmd.cpp:10783-10788`

Mapping: `strong`. next mapped function definition is setupBoatGroups at old line 10862.

```text
//   varargs expression, then removed duplicate md/index varargs from the two
//   target and object-to-destroy logs.  This recovered all 99 call sites and
//   and also preserves the original right-to-left varargs evaluation order.
// exact candidate: 0-byte positional and edit/resync diff under default flags;
// modeled the AIModule base plus object/player virtual surfaces.  This keeps
// the direct cdecl member logger and proven field ownership period-plausible.
```
<!-- end-recovered:daa18af880c0f1a9a3d0 -->

<!-- recovered:e9c64798c1fe00bcf4f7 -->
### `target-session` `build/target_sessions/004FDE00_setupBoatGroups.json:1-42`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=745; shape=94.39153439153439: Current clean scratch reconstruction: typed inline ManagedArray, repeated boat phases, canonical group sentinel; establish authoritative metrics.
probe 2 layout; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 2: declare scalar i before the groupsToRemove aggregate, following PDB scalar-first evidence, to move the aggregate and restore the original 0x2C frame/local homes. [same emitted code as probe 1]
probe 3 layout; result=MISMATCH; diff=2712; shape=94.09282700421942: Hypothesis 3: the shipped ManagedArray constructor may leave value uninitialized while clearing its three scalar fields; test constructor field ownership against the four observed entry stores and frame.
probe 4 liveness; result=MISMATCH; diff=766; shape=93.97463002114165: Hypothesis 4: force the PDB-proven stack local i to remain addressable via volatile, testing whether its missing home accounts for the original 0x2C frame and balance-slot placement; diagnostic only unless binary topology supports it.
probe 5 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 5: initialize the PDB-visible loop scalar i at declaration, testing whether an early zero home is the missing 4-byte frame slot and whether it changes balance register lifetime. [same emitted code as probe 2]
probe 6 layout; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 6: match the PDB/decompiler scalar declaration order (i, numEGroups, numPotentialAGroups, numPotentialEGroups, numDGroups, numAGroups) before the local ManagedArray, testing stack-home coloring and frame size. [same emitted code as probe 5]
probe 7 liveness; result=MISMATCH; diff=777; shape=96.71957671957672: Hypothesis 7: keep numPotentialEGroups in its PDB-proven stack home rather than EBP, using narrow volatility as a diagnostic for the original balance local lifetime and register basin.
probe 8 control-flow; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 8: express each non-positive remainder as an explicit goto to the shared balance label, matching the original long branch destinations and testing whether this preserves numPotentialEGroups stack stores without volatile.
probe 9 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 9: bind numPotentialEGroups to a local reference used across the shared balance label, testing address-taken lifetime as a natural cause of the original stack home.
probe 10 liveness; result=MISMATCH; diff=774; shape=96.723044397463: Hypothesis 10: repeat the PDB stack-home test for numPotentialEGroups after the explicit shared-balance goto form, to separate the volatile frame effect from the control-flow effect.
probe 11 other; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 11: reverse the commutative product source operands to match the original mov-then-memory-imul order at the first war-boat balance calculation. [same emitted code as probe 6]
probe 12 other; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 12: split the second remainder into two compound assignments, matching the original warBoats-minus-product then minus-middle-group-product instruction order. [same emitted code as probe 11]
probe 13 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 13: address-take numPotentialEGroups through a local pointer for its ceil/clamp/product path, testing whether VC5 naturally preserves the original stack home without volatile.
probe 14 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 14: make the long-lived balance index register-preferred, testing whether VC5 spills numPotentialEGroups into the original stack home under the same natural scalar set. [same emitted code as probe 13]
probe 15 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 15: initialize numPotentialEGroups at declaration before the mode split, testing whether its wider source lifetime selects the original stack home and frame. [same emitted code as probe 12]
probe 16 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 16: split the computed potential-E-group count from the post-mode balance limit, testing whether the original stack slot reflects two source lifetimes that VC5 cannot coalesce. [same emitted code as probe 14]
probe 17 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 17: promote repeated new_group temporaries to one function-scope pointer, matching the decompiler's single pTVar8 local and testing whether its lifetime supplies the missing stack pressure.
probe 18 liveness; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 18: make numAGroups register-preferred, targeting the original pre-loop EBP load and testing whether register pressure spills numPotentialEGroups to its stack home. [same emitted code as probe 17]
probe 19 control-flow; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 19: use a for-loop update for the first excess-attack-group removal, testing whether source update placement produces the original pre-loop EBP load and branch layout. [same emitted code as probe 18]
probe 20 control-flow; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 20: use a for-loop update for excess defend-group removal, testing whether its decrement placement controls the shared balance register allocation. [same emitted code as probe 19]
probe 24 behavior; result=MISMATCH; diff=745; shape=94.39153439153439: Replace the manual local-array append with the exact ManagedArray add body while keeping resize declaration-only.
probe 25 context; result=MISMATCH; diff=2771; shape=88.98043254376931: Diagnostic full reconstructed header with protected fields exposed only to isolate method visibility and nested inlining effects.
probe 27 behavior; result=MISMATCH; diff=2413; shape=93.9873417721519: Hypothesis 1: preserve the original count-call overlay: ignore numberGroups(0x67), assign the 0x68 count to i, and leave numAGroups uninitialized because the original first balance block reads an unwritten stack home.
probe 29 layout; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 2: restore the period template ManagedArray<int> declaration surface used by exact same-TU donors while keeping resize declaration-only and the target-owned inline add/remove bodies.
probe 31 layout; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 3: use the complete PDB/decompiler declaration order without initialization: i, numEGroups, numPotentialAGroups, numPotentialEGroups, numDGroups, numAGroups, then groupsToRemove. [same emitted code as probe 26]
probe 33 other; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 4: spell the first balance product as a natural compound assignment (copy numPotentialEGroups, then product *= sn[0x3b]) to test the original mov-then-memory-imul topology. [same emitted code as probe 31]
probe 35 context; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 5: restore the period CRT header context used by an exact same-TU donor, without changing the target-owned declarations or source body.
probe 37 layout; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 6: name the else-arm maximum before loading warBoats, matching the original PDB band that loads sn[0x3a] before the war-boat count and compare.
probe 39 abi; result=MISMATCH; diff=745; shape=94.39153439153439: Hypothesis 7: model the reviewed polymorphic TacticalAIModule base used by an exact same-TU donor; its base size preserves md at +0xF0 while restoring the real class ABI context.
probe 41 abi; result=MISMATCH; diff=746; shape=94.28571428571429: Hypothesis 8: restore the reviewed period polymorphic AIModule, InformationAIModule, and derived layout surfaces from the exact same-TU donor while preserving proven offsets.
probe 43 control-flow; result=MISMATCH; diff=643; shape=98.73015873015873: Hypothesis 9: use a natural min ternary for the else-arm potential-group clamp, matching the original load/cmp/move sequence rather than the current if assignment basin.
probe 44 control-flow; result=MISMATCH; diff=643; shape=98.73015873015873: Hypothesis 10: reverse the equivalent min comparison to sn[0x3a] > warBoats.numberValue, targeting the original sn-first load order while keeping the ternary source shape.
probe 45 layout; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 11: bind the sn[0x3a] maximum and warBoats count as named locals before the min ternary, targeting sn-first loads with the original cmp eax,ecx operand order.
probe 46 liveness; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 12: make the arithmetic remainder one function-scope local, matching the original persistent remainder stack window across both mode arms and testing the numAGroups home shift.
probe 47 layout; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 13: reverse the function-scope remainder and numAGroups declaration order, testing the observed four-byte home permutation without changing behavior or control flow. [same emitted code as probe 46]
probe 48 liveness; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 14: preserve the 0x68 call result through a declaration-local numAGroupsAtStart before assigning the long-lived numAGroups, testing whether this natural call-result lifetime selects the original home. [same emitted code as probe 45]
probe 49 liveness; result=MISMATCH; diff=659; shape=97.24867724867725: Hypothesis 15: model the first balance's adjusted type-68 count as a separate natural local, then carry it into the second phase, targeting the original extra numAGroups stack home.
probe 50 other; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 16: use compound assignment for the first product inside the now-matched frame basin, retesting whether VC5 emits the original mov-then-memory-imul form. [same emitted code as probe 47]
probe 51 layout; result=MISMATCH; diff=644; shape=98.62433862433862: Hypothesis 17: model the proven adjacent numAGroups/remainder stack window as a typed two-int balance state, not opaque padding, to test scalar-home ownership.
probe 52 other; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 18: materialize the second balance product as a named compound-assignment local, matching the original register-then-memory-imul topology at sn[0x44]. [same emitted code as probe 48]
probe 53 layout; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 19: declare numAGroups at its 0x68 call site, matching the PDB call band and testing whether a narrower declaration scope selects the original stack home. [same emitted code as probe 50]
probe 54 liveness; result=MISMATCH; diff=643; shape=98.83597883597884: Hypothesis 20: make the first balance product a function-scope local, matching the original PDB-spanning product/remainder lifetime and testing its register topology. [same emitted code as probe 53]
```
<!-- end-recovered:e9c64798c1fe00bcf4f7 -->

<!-- recovered:602cbbb315fdb566304b -->
### `3789ccb1ae1e` `src/scratch/004FDE00_setupBoatGroups.cpp:2-62`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004FDE00 TribeTacticalAIModule::setupBoatGroups
// Source: taitacmd.cpp lines 10322-10681
//
// Baseline reconstruction: the local groupsToRemove is the real inline
// ManagedArray<int> surface. The three boat lists and workingArea are named
// ManagedArray<int> members, while the group list is the TacticalAIGroup
// sentinel owned by TribeTacticalAIModule. The repeated boat phases are kept
// as ordinary source-level loops; their shared remove/copy topology is visible
// in the original CFG.
// FLAGS: config/flags/004FDE00_setupBoatGroups.rsp (/GX for the observed EH frame).
//
// Attempt log:
// - baseline: canonical TacticalAIGroup sentinel, inline ManagedArray ownership,
//   and three ordinary boat-group phases; 2887-byte target rebuilt as 2894
//   bytes with a 0x28/0x2C frame gap and an early type-filter CFG mismatch.
// - negative type guard with explicit continue: matched the original late
//   type-match body and reduced the positional diff from 2602 to 730 bytes.
// - declaration/local-role reorderings (including the retained type-68 count)
//   emitted the same VC5 code; no further declaration archaeology retained.
// - positive nested remainder guards and commutative product-order probes were
//   also codegen duplicates; they remain diagnostic evidence only.
// - /GX balance-shape lab: a named product temporary plus compact positive
//   clamps produced the exact 2887-byte size and exact balance focus range.
// - explicit remainder guards with a separate retained type-68 local restored
//   the 730-byte diagnostic basin but added 16 bytes after the target boundary;
//   rolled back because structural size is authoritative.
// - compact arithmetic with a separate retained local, hoisted product and
//   remainder locals, and the exact setupSoldierGroups scalar declaration order
//   all emitted the clean 745-byte codegen group; no new structural lead.
// - corrected the third balance denominator/cap from sn[0x3d]/sn[0x3c] to
//   sn[0x3e]/sn[0x3d], matching original offsets 0x28C/0x288; shape improved
//   from 94.07% to 94.39% and exact blocks from 70.87% to 71.29%, with the
//   same 745-byte positional diff.
// - fresh pass: 20 evidence-led declaration, lifetime, arithmetic, and loop
//   probes kept the same 745-byte codegen basin. A volatile
//   numPotentialEGroups restored the 0x2C frame and 81.57% exact blocks, but
//   added 16 bytes after the boundary; it is diagnostic evidence only.
// - fresh pass: explicit shared-balance gotos, address-taking, split count
//   lifetimes, register hints, function-scope group pointers, and loop-form
//   rewrites were codegen duplicates or worse. Restored this clean source.
// - current best is still non-exact: 745 positional diff bytes, 94.39% shape,
//   71.29% exact blocks, 93/93 ordered calls, and frame 0x28 versus 0x2C.
//   Remaining lead is the real local-lifetime/register basin around the target
//   stack homes (especially the saved numPotentialEGroups/numAGroups values).
// - ManagedArray recovery pass, 2026-08-19: the exact add body replaces the
//   manual caller-side scan and emits the same 2887-byte frontier. The complete
//   shared header inlines resize at this site, adds one allocator pair and 82
//   bytes, and changes the call surface. Keep resize declaration-only here.
// - fresh pass: a natural min ternary for the else-arm potential-group clamp
//   restores the 0x2C frame and the main balance CFG. Named maximum and count
//   locals preserve the sn-first load order. A function-scope remainder local
//   is codegen-identical in this basin.
// - current best is 643 positional diff bytes, 98.84% shape, 91.10% exact
//   blocks, and 93/93 ordered calls. The rebuilt size is 2889 versus 2887.
// - compound products, declaration-local call results, a typed balance pair,
//   and a function-scope product were codegen duplicates or worse. Restored
//   the smallest natural product and scalar forms.
// BINARY NOTE: the min clamp loads sn[0x3a] before warBoats.numberValue and
//   uses cmp eax,ecx. The ternary source reproduces that local instruction order.
// Remaining mismatch: the original first balance block loads numAGroups from
//   [esp+20h]. The best rebuild loads the same source value from [esp+24h].
```
<!-- end-recovered:602cbbb315fdb566304b -->
