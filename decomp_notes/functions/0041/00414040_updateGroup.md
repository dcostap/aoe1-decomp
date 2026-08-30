# Function notes: 00414040 `updateGroup`

Module notes: `decomp_notes/aiuaimod_module.md`.

## Recovered attempt history

<!-- recovered:7465b27fdefea1d4166c -->
### `target-session` `build/target_sessions/00414040_updateGroup.json:1-43`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 control-flow; result=MISMATCH; diff=1646; shape=71.49837133550488: H1: remove the local currentPhase byte and reread playStatus->currentPhaseValue directly. Original has no phase-byte stack store at 004141D8-1E; tests local lifetime and branch structure.
probe 2 control-flow; result=MISMATCH; diff=1646; shape=71.49837133550488: H2: invert the initial null guards into nested positive playStatus/play guards, matching Ghidra's combined positive predicate and common success body. Tests block layout rather than behavior. [same emitted code as probe 1]
probe 3 liveness; result=MISMATCH; diff=1611; shape=72.46621621621621: H3: make case-8 and case-9 lookup results branch-local members instead of reassigning the long-lived target local. Original keeps target only for case-1 coordinates and does not store lookup results at the case-8/9 sites.
probe 4 layout; result=MISMATCH; diff=1708; shape=73.09644670050761: H4: explicitly initialize groupList[0]. Original stores zero at 00414206 before passing groupList+1, proving a live sentinel or base element. Tests array ownership and stack placement.
probe 5 layout; result=MISMATCH; diff=1611; shape=72.46621621621621: H5: model the proven groupList+1 write range as 51 ints, so the 50-member fill cannot overrun the local. Tests whether the missing array element explains the 0xFC frame and +44 pointer.
probe 6 layout; result=MISMATCH; diff=1610; shape=73.14189189189189: H6: extend groupList to 52 ints as a bounded frame-sizing probe after 51 ints moved the frame from 0xF4 to 0xF8. Tests whether the original 0xFC frame needs one more live dword.
probe 7 liveness; result=MISMATCH; diff=1601; shape=73.9424703891709: H7: remove dead play=0 in the phase-255 branch. The following fillGroups call uses memberCount, and original assembly's zero store is the member count home, not a play pointer. Tests early zero-register liveness.
probe 8 abi; result=MISMATCH; diff=1601; shape=73.9424703891709: H8: represent bestUnitToAttack/find_unit results as int selectedTarget, separate from later AIPlayPhaseTrigger*. The original returns and targetValue are integer IDs; this tests the proven ABI width and register coloring.
probe 9 liveness; result=MISMATCH; diff=1601; shape=73.9424703891709: H9: scope memberIndex to target recovery and memberCount/deadCount to phase-255, matching their disjoint PDB bands and avoiding function-wide locals. Tests declaration scope and register/home coalescing. [same emitted code as probe 8]
probe 10 control-flow; result=MISMATCH; diff=1601; shape=73.9424703891709: H10: combine the playStatus and play null guards into the original decompiler-supported positive short-circuit expression. Tests declaration/call scheduling at the first structural hunk.
probe 11 liveness; result=MISMATCH; diff=1601; shape=73.9424703891709: H11: reuse the function-scope i local for the integer target ID and later trigger/group loops. Ghidra maps the target lookup result and later i uses to one local candidate; tests register lifetime and the post-call EBX/EBP color.
probe 12 liveness; result=MISMATCH; diff=1689; shape=73.81756756756756: H12: remove the persistent target-recovery object alias and use direct this->objectValue accesses, while keeping the lookup result branch-local. Original 00414125 reloads [esi+4] directly and has no object stack load there.
probe 13 layout; result=MISMATCH; diff=1650; shape=72.26890756302521: H13: keep a ManagedArray<int>* members alias for the target-recovery scan, matching original edi as the array base at 004140CF and preserving inline operator[] growth plus separate resize.
probe 15 liveness; result=MISMATCH; diff=1601; shape=73.9424703891709: H15: restore deadCount to function scope, matching Ghidra's named local and its source-line reuse across the phase-255 block. Tests whether broader lifetime controls the zero register and frame placement. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=1601; shape=73.9424703891709: H16: move the type-1 group loop index to function scope, matching the decompiler's long-lived integer locals and testing whether VC5 assigns it to the original EBP induction register.
probe 17 control-flow; result=MISMATCH; diff=1707; shape=71.78217821782178: H17: rewrite type-1 nested do loops as positive while conditions (, ). Tests whether source loop form explains the original duplicated satisfaction checks and backedge layout.
probe 18 liveness; result=MISMATCH; diff=1601; shape=73.9424703891709: H18: reverse type-2 matchingGroups/deadGroups declaration order while preserving increment order. Original uses matching in EBX and dead count in a stack home; tests declaration-driven register pressure.
probe 19 liveness; result=MISMATCH; diff=1634; shape=71.66123778501628: H19 diagnostic: narrow volatile on type-2 deadGroups to test the proven stack increment home. This is a codegen probe only and will be removed unless binary behavior requires the reread.
probe 20 liveness; result=MISMATCH; diff=1601; shape=73.9424703891709: H20: use a branch-local condition trigger alias in type-3, matching the original trigger pointer register reuse across the type-2 and type-3 handlers. Tests the trigger-versus-lostHitPoints color without changing calls.
probe 21 layout; result=MISMATCH; diff=1702; shape=73.22033898305085: H21: combine a 51-entry groupList with an explicit zero sentinel. This models the observed groupList+1 range and groupList[0] store while testing the exact 0xFC frame.
probe 22 layout; result=MISMATCH; diff=1702; shape=73.22033898305085: H22: test the decompiler-named gatherDistance local with a 51-entry groupList and explicit sentinel. This combines two binary-supported stack clues: the x87 temporary and groupList plus one address. [same emitted code as probe 21]
probe 24 layout; result=MISMATCH; diff=1602; shape=73.26565143824027: H24: restore the decompiler and donor-supported 50-entry groupList after the provisional 52-entry frame scaffold. This is the clean natural-source validation choice.
probe 27 liveness; result=MISMATCH; diff=1604; shape=73.60406091370558: H23: restore the PDB-proven gatherDistance float and use it for the repeated type-1 command offset; remove the unsupported distance result local. This tests the original x87 temporary and should also recover the 0xFC local frame.
probe 28 liveness; result=MISMATCH; diff=1604; shape=73.60406091370558: H24: restore the PDB-proven newTarget local for find_unit results and reuse i as the member-scan index; this tests the original [esp+14] target home and EBP index lifetime without changing calls. [same emitted code as probe 27]
probe 29 liveness; result=MISMATCH; diff=1604; shape=73.60406091370558: H25: cache the case-2 trigger pointer in a branch-local alias. The original case-2 keeps trigger in EBP across lookup calls while the clean source reloads its stack home; this tests a binary-supported pointer lifetime and may free a register for matchingGroups.
probe 30 control-flow; result=MISMATCH; diff=1628; shape=75.04187604690117: H26: express type-1 outer and inner scans as triggerSatisfied-controlled while loops with count breaks. Original checks satisfaction at each loop head and checks count only after body; this avoids compiler-generated duplicate bottom satisfaction tests from do/while plus break.
probe 31 control-flow; result=MISMATCH; diff=1628; shape=75.04187604690117: H27: encode the type-1 loop edges with explicit labels proven by the original CFG: satisfaction tests at loop heads and count backedges after each body. This is a supported structural goto hypothesis, not metric-only padding.
probe 33 control-flow; result=MISMATCH; diff=1602; shape=73.26565143824027: H28: restore a nested positive play-status/play guard matching the original two-block entry CFG and shared return epilogue, instead of one combined short-circuit expression.
probe 34 layout; result=MISMATCH; diff=1604; shape=73.60406091370558: H29: restore the PDB-local surface: newTarget for target recovery, a for the member scan, groupCount for phase-255 output count, and gatherDistance for the repeated type-1 offset. This tests proven local names and lifetimes together.
probe 35 layout; result=MISMATCH; diff=1605; shape=73.60406091370558: H30: replace the phase-255 group-list cursor's fake AIPlayPhaseTrigger type with a natural int* cursor. The binary proves a four-byte ID stream; this tests whether it frees the real trigger pointer to take its original shared stack home.
probe 36 layout; result=MISMATCH; diff=1605; shape=73.60406091370558: H31: order declarations to match the original PDB local-symbol order (target, play, phase, i, newTarget, arrays, groupCount, a, triggerSatisfied, trigger, gatherDistance, deadCount). This tests declaration-driven VC5 frame and register allocation. [same emitted code as probe 35]
probe 37 layout; result=MISMATCH; diff=1702; shape=73.55932203389831: H32: restore the executable's proven groupList[0] zero store before the phase-255 fill, while retaining the PDB-local reconstruction. This tests sentinel ownership without changing calls.
probe 40 liveness; result=MISMATCH; diff=1602; shape=73.26565143824027: H33: restore the PDB-proven gatherDistance as the distance result local, not as the command offset. This tests the original post-call x87 store/fcompp shape while preserving direct repeated command fields.
probe 41 behavior; result=MISMATCH; diff=1600; shape=73.4006734006734: H34: reverse the equivalent type-1 distance predicate to distance > threshold. Original x87 uses fcompp and tests AH bits 0x41, which proves compare operand order is codegen-active.
probe 43 layout; result=MISMATCH; diff=1600; shape=73.4006734006734: H35: combine the PDB local declaration order with the proven gatherDistance result and reversed distance comparison, without adding unproven locals. Tests whether homes move to original play/target/trigger/gather slots. [same emitted code as probe 41]
probe 44 liveness; result=MISMATCH; diff=1600; shape=73.4006734006734: H36: use the PDB-listed a local as the type-1 group induction value instead of a nested group name. This tests the original branch-local symbol lifetime and EBP/register color.
probe 45 liveness; result=MISMATCH; diff=1600; shape=73.4006734006734: H37: reverse case-2 deadGroups/matchingGroups declarations. Original keeps matchingGroups in EBX and spills deadGroups to [esp+14]; this tests declaration-driven register pressure without volatility.
probe 46 layout; result=MISMATCH; diff=1600; shape=73.4006734006734: H38: add the PDB-listed newTarget and groupCount locals to the best gatherDistance/compare source. This tests target-recovery and phase-255 lifetimes without synthetic storage.
probe 47 liveness; result=MISMATCH; diff=1598; shape=74.91582491582491: H39: use the PDB-listed i local for the three-trigger phase loop instead of reusing totalHitPoints[0]. Original writes and reloads a dedicated counter at [esp+2C], while totalHitPoints starts one slot later; this tests the proven overlay and frame topology.
probe 48 layout; result=MISMATCH; diff=1598; shape=75.25252525252525: H40: combine the dedicated phase-loop i, PDB locals, and a natural int* group-list cursor. Original separates the cursor from the later trigger pointer and keeps i at the total-array edge; tests the complete phase-255/phase-transition topology.
probe 49 layout; result=MISMATCH; diff=1715; shape=75.37942664418212: H41: add the binary-proven groupList[0] zero store to the improved dedicated-i/cursor topology. Tests whether the sentinel now recovers the remaining four-byte frame slot.
probe 52 control-flow; result=MISMATCH; diff=1635; shape=73.48993288590604: H1: make the group-member recovery scan a top-tested newTarget == -1 loop with an explicit post-increment count break, matching the oracle's compare-at-loop-head and count backedge.
probe 57 layout; result=MISMATCH; diff=1532; shape=77.12854757929883: H2: recover the proven five-element hit-point array base and typed group-list cursor. The oracle zeros totalHitPoints[0..4], indexes totals by group, publishes totalHitPoints[i], and scans groupList+1 directly. This reduced the canonical-source diff to 1532 bytes with all 42 direct calls aligned, but the frame remains 0xF8 versus 0xFC.
```
<!-- end-recovered:7465b27fdefea1d4166c -->

<!-- recovered:f6ee149bd49f39b16a48 -->
### `4d8e2101e925` `src/scratch/00414040_updateGroup.cpp:1-66`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00414040 UnitAIModule::updateGroup (1831B)
// aiuaimod.cpp
// Attempt log:
// - Replaced the unrelated placeholder with a typed reconstruction from the
//   play-status, group-member, and phase-trigger ownership in the binary.
// - Baseline follows the original three trigger checks, group rebuild path,
//   and phase-255 group fill path. Exact codegen remains under investigation.
// - Corrected object virtual slots (+1B8, +1BC, +1C8), target coordinates,
//   world_time at +04, and the groupList+1 member array from the assembly.
// - Separated the dead-group count from its eight-byte grouping scan offset.
// - Eight probes reached exact call-set parity, but the remaining gap is a
//   broad VC5 frame and block-layout difference. No productive codegen lead
//   remains in this assignment.
// - Tried the period ManagedArray<int>::operator[] donor at both the first
//   comparison and the later lookup. The repeated operator[] added one growth
//   call pair and was rolled back.
// - Kept operator[] only for the first comparison and phase-255 member read;
//   direct value access remains after the separate resize call. This improved
//   the structural check to 1714 differing bytes with exact call parity.
// - Tried initializing the typed groupList sentinel before the phase-255 fill;
//   the original zero store supports this group-layout hypothesis.
// - Rolled back the sentinel initialization: it worsened the positional diff
//   from 1714 to 1767 bytes and increased the rebuilt size by four bytes.
// - This claim tested the combined outer play guard, array-pointer and loop-index
//   spellings, and a repeated phase-command temporary. The best emitted code
//   stayed at 1714 differing bytes and 42 aligned calls.
// - Reversing the equivalent distance threshold improved resync similarity but
//   worsened positional equality to 1762 bytes; restored the clean source.
// - This claim tested 24 distinct structural, lifetime, ABI, and layout probes.
// - Directly rereading currentPhaseValue removed its stack byte and reduced the
//   diff to 1646 bytes. Branch-local member results in trigger types 8 and 9
//   reduced it to 1611 bytes and kept the source natural.
// - Removing dead play initialization and testing a 52-entry groupList reached
//   the best provisional metric: 1601 bytes, exact 0xFC frame, 42 calls.
//   The 52-entry array is not retained because the binary does not prove it.
// - The clean 50-entry array now gives 1602 bytes, frame 0xF4, and 42 calls.
// - Positive guard forms, integer target-ID typing, local declaration scopes,
//   loop-form changes, address aliases, a volatile diagnostic, and threshold
//   variants either duplicated output or worsened the result.
// - Restored the PDB-listed gatherDistance as the distance result local. The
//   reversed distance > threshold form recovers the original fcompp/test 41h
//   x87 predicate shape and reduced the clean diff to 1600 bytes.
// - Restored the PDB-listed newTarget, groupCount, and a locals. A dedicated i
//   counter for the three-trigger phase loop moved the frame to 0xF8 and the
//   diff to 1598 bytes. A typed int* group-list cursor raises shape similarity
//   to 75.25% with 27.38% exact-block coverage.
// - BINARY NOTE: the phase-255 path zeros all five totalHitPoints entries.
//   It indexes that typed array by group and publishes totalHitPoints[i].
//   The group-list cursor starts at groupList + 1 and advances after each
//   member. These forms preserve the observed typed array addresses.
// - Open blocker: the executable frame is 0xFC and this natural source frame
//   is 0xF8. The first mismatch remains the prologue. Direct calls and their
//   order match, but broad control-flow drift remains.
// MANAGEDARRAY AUDIT: group-member growth guards, copies, publication, resize,
// value reads, and field offsets follow the expected template behavior. No
// shared template change is required.
// BLOCKER: The executable frame is 0xFC and the natural source frame is 0xF8.
// A 52-entry group list fixes only the frame and adds unsupported local storage.
// Broad CFG drift also remains despite all 42 calls aligning.
// Canonical-context pass: this owner uses the PDB aiuaimod.cpp surfaces and
// the real bestUnitToAttack slot at vtable +0x30. The source has 42 direct
// calls in the oracle order. The full prefix through 00414800 keeps this body
// in the same code-generation basin. Do not change 00413AB0 queue indexing
// or its timer and current-order publication while testing this owner.
// - Captain probe: a separate initial-target local was codegen-identical and
//   was restored. The grouped result remains 1520 differing bytes, 0xF8 frame.
```
<!-- end-recovered:f6ee149bd49f39b16a48 -->
