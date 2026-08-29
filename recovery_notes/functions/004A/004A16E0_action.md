# Recovery journal: 004A16E0 `action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_mps.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_mps.cpp`.
- Earlier recovery note: `recovery_notes/scr_mps_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:a5a9af06555b38e4a725 -->
### `target-session` `build/target_sessions/004A16E0_action.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=2220; shape=96.8895800933126: Baseline current indexed loop and shared TEasy_Panel fallback; establish metrics before new hypotheses.
probe 2 control-flow; result=MISMATCH; diff=2220; shape=96.8895800933126: Hypothesis 1: make final name/civ/scenario dispatch an else-if chain; equivalent source branches may preserve original loop-header layout and avoid the compiler's extra rotated name compare.
probe 4 layout; result=MISMATCH; diff=2191; shape=94.12673879443585: Hypothesis 2: use one typed playerCivDrop cursor with -8/0/+8 slots, as original assembly proves a +5D0 cursor and adjacent name/scenario comparisons; test whether canonical ownership recovers loop topology.
probe 6 control-flow; result=MISMATCH; diff=1608; shape=95.84615384615384: Hypothesis 3: replace the explicit end-of-outer-block goto with natural fall-through to the shared TEasy_Panel action tail; this may retain one merged call while reducing param_2 liveness and matching the deferred stack reload.
probe 7 control-flow; result=MISMATCH; diff=2220; shape=96.8895800933126: Hypothesis 4: replace internal gotos to the return-1 tail with direct returns, leaving only the outer-block fall-through for the base action; this preserves unsupported non-null fallback behavior while testing natural tail merging.
probe 10 control-flow; result=MISMATCH; diff=2200; shape=97.21362229102168: Hypothesis 5: express the final player dispatch as a natural for loop rather than a do-while; the original has an outer positive-count guard and bottom count reload, so this tests loop-form lowering without changing behavior.
probe 12 control-flow; result=MISMATCH; diff=2200; shape=97.21362229102168: Hypothesis 6: use a top-tested while loop for final player dispatch under the existing positive-count guard; this tests whether original loop rotation is expressed as while rather than do-while. [same emitted code as probe 10]
probe 15 layout; result=MISMATCH; diff=2220; shape=97.66718506998444: Hypothesis 7: pass file_name itself rather than file_name+4; original LEAs are exactly 4 bytes earlier at sprintf, findfirst, fallback sprintf, and checksum, so source local ownership may already account for the observed offset.
probe 16 layout; result=MISMATCH; diff=2220; shape=97.66718506998444: Hypothesis 8: reverse file_info and file_name declaration order; VC5 stack-home order may explain the original reuse of a local slot and preserve exact filename LEAs without address arithmetic. [same emitted code as probe 15]
probe 18 control-flow; result=MISMATCH; diff=2116; shape=91.37134052388289: Hypothesis 9: inline the not-ready CD value as a ternary argument; original keeps host zero in EAX, while the current named cd local allocates EDI, so evaluation shape may recover the ready tail.
probe 20 liveness; result=MISMATCH; diff=2116; shape=91.37134052388289: Hypothesis 10: initialize named cd from a host ternary instead of zero plus assignment; this tests whether VC5 keeps the original EAX path while retaining the call argument local.
probe 22 control-flow; result=MISMATCH; diff=2220; shape=92.86821705426357: Hypothesis 11: move the name-drop handler after civ/scenario checks in source; arrays are disjoint, and the original emits the name handler as a late block despite its first loop predicate, so source order may control layout.
probe 24 control-flow; result=MISMATCH; diff=2220; shape=97.66718506998444: Hypothesis 12: split the first start-button conjunction into nested receiver and param_2 guards; original loads param_2 only after startButton field load, so this tests deferred parameter scheduling.
probe 26 control-flow; result=MISMATCH; diff=2159; shape=98.13374805598755: Hypothesis 13: express final-loop rotation as while(1) with an explicit bottom break after i++ and numberPlayers(); this preserves one outer positive-count guard and matches the original bottom test order.
probe 28 layout; result=MISMATCH; diff=2199; shape=96.42301710730949: Hypothesis 14: combine the explicit +5D0 playerCivDrop cursor with the while(1) bottom break; this tests whether proven pointer ownership plus original loop rotation recovers EDI cursor/EBP index colors and the loop CFG.
probe 30 liveness; result=MISMATCH; diff=2159; shape=98.13374805598755: Hypothesis 15: mark only the final-loop index register; original keeps player index in EBP while pointer/cursor work uses EDI, so a period-plausible register hint may recover this color without changing behavior. [same emitted code as probe 29]
probe 31 control-flow; result=MISMATCH; diff=2159; shape=98.13374805598755: Hypothesis 16: invert the explicit bottom break to ; original emits cmp/jl backedge then a separate fallback jump, so this tests branch polarity and removes the synthetic extra jump. [same emitted code as probe 30]
probe 32 control-flow; result=MISMATCH; diff=2159; shape=98.13374805598755: Hypothesis 17: use an equality break at the bottom of the bounded player loop; this tests whether the original compiler preserved an equality termination form rather than signed less-than.
probe 33 control-flow; result=MISMATCH; diff=2159; shape=98.13374805598755: Hypothesis 18: express the bottom termination as  continue; break; this tests whether VC5 emits the original signed backedge from a not-equal source predicate. [same emitted code as probe 32]
probe 34 control-flow; result=MISMATCH; diff=2159; shape=98.13374805598755: Hypothesis 19: use prefix increment at the final-loop update; VC5 can schedule pre/post increment differently, so this tests the original update expression without changing the count. [same emitted code as probe 33]
probe 37 layout; result=MISMATCH; diff=2202; shape=95.70552147239263: Hypothesis 1: use an explicit playerCivDrop cursor with natural indexed offsets and bottom numberPlayers test; original uses EDI cursor plus EBP index, so this tests canonical pointer ownership and register topology.
probe 39 layout; result=MISMATCH; diff=2199; shape=96.42301710730949: Hypothesis 2: use one explicit playerCivDrop base cursor without mutating it; fixed offsets -8/0/+8 model the proven adjacent arrays while preserving the original bottom loop. [same emitted code as probe 28]
probe 41 control-flow; result=MISMATCH; diff=2145; shape=91.41104294478528: Hypothesis 3: express not-ready CD selection as a host ternary; original has one IsHost test, a zero EAX path, and one merged readiness call, so this tests natural conditional-expression lowering.
probe 43 control-flow; result=MISMATCH; diff=2145; shape=91.41104294478528: Hypothesis 4: inline the host/CD ternary inside SetMyReadiness; this removes a named call-crossing local while preserving the original one-call branch merge.
probe 45 layout; result=MISMATCH; diff=2159; shape=97.35614307931571: Hypothesis 5: restore the binary-proven file_name+4 API spelling for sprintf, findfirst, fallback sprintf, and checksum; inventory and PDB evidence name file_name[4], so this tests the real local ownership rather than effective-pointer equivalence.
probe 47 control-flow; result=MISMATCH; diff=2220; shape=97.66718506998444: Hypothesis 6: use a natural do-while final player dispatch followed by the shared fallback; original emits a bottom signed jl backedge and a separate fallback jump, which this source CFG can preserve without behavior loss. [same emitted code as probe 16]
probe 49 control-flow; result=MISMATCH; diff=2185; shape=93.77916018662519: Hypothesis 7: use an early null-to-fallback guard with natural fall-through for all nonmatching input; this keeps one behavior-correct base-action tail while avoiding an outer wrapper that may hoist param_2.
probe 51 liveness; result=MISMATCH; diff=2159; shape=98.13374805598755: Hypothesis 8: keep a named fallback_panel alias for param_1 and pass it to the shared base-action tail; the original tail pushes EBX rather than a known zero, so this tests a natural alias that may block null-path constant propagation.
probe 53 control-flow; result=MISMATCH; diff=1652; shape=97.39263803680981: Hypothesis 9: make the no-match base action a natural return inside the non-null arm while retaining the null tail; equivalent source paths may let VC5 keep param_1 live without an explicit shared-tail goto.
probe 54 layout; result=MISMATCH; diff=1652; shape=97.39263803680981: Hypothesis 10: reverse file_info and file_name declaration order within the improved natural-return fallback model; original address gap is 0x104 while VC5 currently emits 0x108, so this tests local-home ordering. [same emitted code as probe 53]
probe 56 layout; result=MISMATCH; diff=1657; shape=96.62576687116564: Hypothesis 12: apply the inventory/PDB-proven file_name+4 spelling inside the improved natural-return fallback model; this tests whether canonical local ownership improves the remaining filename and tail shifts.
probe 57 control-flow; result=MISMATCH; diff=2091; shape=92.3076923076923: Hypothesis 13: use a named host/CD ternary in the improved natural-return model; original zero path and merged readiness call may favor conditional-expression lowering without changing the return-tail structure.
probe 58 control-flow; result=MISMATCH; diff=1641; shape=96.93251533742331: Hypothesis 14: combine the improved natural base-action return with a do-while player loop; the original has a signed bottom jl backedge and separate fallback tail, and this tests whether both natural CFGs are required together.
probe 59 liveness; result=MISMATCH; diff=1641; shape=96.93251533742331: Hypothesis 14: pass a reference alias of param_1 to both natural base-action returns; unlike a copied pointer, a reference may preserve the ABI value through the common fallback without null constant propagation.
probe 60 layout; result=MISMATCH; diff=1607; shape=95.37037037037037: Hypothesis 15: combine the improved natural-return/do-while model with one proven playerCivDrop cursor; fixed -8/0/+8 offsets may recover the original pointer-owned loop without the compiler's peeled first name test.
```
<!-- end-recovered:a5a9af06555b38e4a725 -->

<!-- recovered:780bf27f3c930f636ac1 -->
### `f51a58fe5bf4` `src/scratch/004A16E0_action.cpp:1-30`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004A16E0 TribeMPSetupScreen::action
// scr_mps.cpp lines 812-1134
//
// Attempt log:
// - Recovered the typed panel arrays, helper ABIs, 0x220 EH frame, and 105 direct calls.
// - BINARY NOTE: The fallback is shared by null input, nonzero param_2, and exhausted loops.
//   Keep the TEasy_Panel call as one emitted tail. The source keeps a natural base-action
//   return in the non-null arm and a second null-path return; VC5 merges the call itself.
// - BINARY NOTE: All four scenario filename LEAs are four bytes before file_name+4.
//   Direct file_name access restores the three scenario blocks without changing calls.
// - BINARY NOTE: The final player loop has one initial numberPlayers call and one bottom call.
//   A do-while loop recovers the signed bottom-test shape better than an explicit break.
// - Tested 15 additional hypotheses across fallback structure, loop form, cursor ownership,
//   local order, filename base, CD evaluation, and liveness. The natural fallback form reduced
//   the strict diff from 2159 to 1641 bytes and raised exact-block coverage to 91.60%.
//   A cursor variant reached 1607 bytes but lost exact blocks and produced call-target drift;
//   it was discarded. The current source keeps the behavior-correct do-while and direct base.
//
// Current unresolved result: 1641 strict differing bytes, 96.93% shape similarity,
// 91.60% exact-block coverage, and 105/105 ordered calls. The main gaps are the shared
// fallback tail size, the file_info stack home, and final-loop register coloring.
// Authentic scr_mps.cpp context selected the PDB virtual symbol and reduced the
// body to 2468 bytes. It kept 105 calls and reduced the strict diff to 1639 bytes.
// BINARY NOTE: The ready-version dialog target is TEasy_Panel::popupOKDialog(long,
// char*, int, int). Explicit base qualification preserves that target in the wrapper.
// BINARY NOTE: Readiness payload arguments use the unsigned-long overload. Explicit
// casts preserve the direct target when the wrapper has an extra int overload.
// GROUPED BLOCKER: The shared wrapper TEditPanel surface places active at +0x130, but
// the executable reads the inherited TPanel active field at +0x6C. Do not replace this
// proven field with a raw local offset view; the shared context needs main-agent repair.
```
<!-- end-recovered:780bf27f3c930f636ac1 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
