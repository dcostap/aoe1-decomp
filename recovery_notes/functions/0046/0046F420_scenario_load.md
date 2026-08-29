# Recovery journal: 0046F420 `scenario_load`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/player.cpp`.
- PDB source: `C:\msdev\work\age1_x1\player.cpp`.
- Earlier recovery note: `recovery_notes/player_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:14721d661448c2d3b8e4 -->
### `target-session` `build/target_sessions/0046F420_scenario_load.json:1-34`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=386; shape=89.57345971563981: Clean current source baseline: 653-byte body, 20 ordered calls, 0xC frame; strict mismatch starts at delayed file-handle save.
probe 2 liveness; result=MISMATCH; diff=502; shape=87.85046728971963: Use the guarded file_handle for the first name-length and attribute reads, matching the original EBP file stream value at every rge_read.
probe 4 liveness; result=MISMATCH; diff=593; shape=87.09677419354838: Remove the separate file-handle alias and use the incoming file parameter for every stream operation, testing whether VC5 naturally selects EBP for the long-lived parameter.
probe 6 liveness; result=MISMATCH; diff=467; shape=95.23809523809524: Mirror the decompiler's two duplicated human/team flags: keep one predicate flag live through player-count handling and copy the stable relation flag at each loop update.
probe 8 liveness; result=MISMATCH; diff=386; shape=89.57345971563981: Declare the stable relation flag at the count-loop boundary, after the player-count branch, to reduce its register lifetime while retaining the observed loop copy.
probe 11 abi; result=MISMATCH; diff=386; shape=89.57345971563981: Use the guarded file_handle for the initial name-length read too, testing whether first-use aliasing makes VC5 save EBP before the first rge_read. [same emitted code as probe 10]
probe 13 layout; result=MISMATCH; diff=388; shape=86.72985781990522: Model the original player-count stack home as a short with the proven +1 byte read, testing the unaligned local and alias topology shown by the original stack evidence.
probe 15 liveness; result=MISMATCH; diff=403; shape=90.04739336492891: Move the file-handle alias to function scope and use it for the first read, testing whether VC5 preserves the original early EBP save without changing call ownership.
probe 17 liveness; result=MISMATCH; diff=555; shape=92.85714285714286: Split the human-team state into distinct summary and relation guards, both set on the proven team branch, so VC5 can keep the version test in EBX and reload the relation flag from its home.
probe 19 control-flow; result=MISMATCH; diff=386; shape=89.57345971563981: Use the binary-supported comma expression inside the version guard, matching the decompiler's combined version/read/team predicate and testing whether VC5 places cleanup before the EBX test.
probe 21 variant; result=MISMATCH; diff=386; shape=89.57345971563981: variant lab build\variant_lab\0046F420_scenario_load\20260822_142635: 8 variants, 8 invariant-eligible, 0 exact
probe 22 liveness; result=MISMATCH; diff=386; shape=89.57345971563981: Keep the file-handle local at function scope but assign it only inside the version guard, testing whether VC5 preserves the original guarded EBP save without moving it before the FPU guard. [same emitted code as probe 11]
probe 24 control-flow; result=MISMATCH; diff=386; shape=89.57345971563981: Mirror the original count-positive do-while CFG: an outer count guard, an initial jump into the body, and a loop-head reload before later iterations. [same emitted code as probe 22]
probe 26 abi; result=MISMATCH; diff=502; shape=87.85046728971963: Use the preserved file_handle for the attribute block read, matching the original EBP call argument and testing whether the remaining parameter-home reload is unnecessary. [same emitted code as probe 2]
probe 28 liveness; result=MISMATCH; diff=555; shape=92.85714285714286: Mirror the decompiler's end-of-iteration flag assignment while using a separate relation guard, testing whether the explicit source update recovers the original loop-head reload. [same emitted code as probe 17]
probe 31 liveness; result=MISMATCH; diff=386; shape=89.57345971563981: Move human_team declaration and initialization to the post-map player-state block, matching its PDB line 789 lifetime and preventing the name block from borrowing its zero register. [same emitted code as probe 30]
probe 32 control-flow; result=MISMATCH; diff=386; shape=89.57345971563981: Reverse the name ownership guard to the natural binary branch order, testing whether VC5 uses test eax,eax and preserves the late human-team zero without changing malformed-input behavior. [same emitted code as probe 31]
probe 33 abi; result=MISMATCH; diff=386; shape=88.15165876777252: Use the guarded file_handle for the first name-length read, testing whether the natural alias forces the original EBP save before rge_read.
probe 34 liveness; result=MISMATCH; diff=386; shape=89.57345971563981: Remove the separate handle alias and let the incoming file parameter own every stream call, testing whether the address-taken relation-byte read naturally produces the EBP home.
probe 35 liveness; result=MISMATCH; diff=593; shape=87.09677419354838: Model the two binary-supported human-team states: keep a loop predicate separate from a saved team flag, restore the predicate after the relation byte clobber, and use the proven positive-count do-while CFG.
probe 36 liveness; result=MISMATCH; diff=467; shape=95.23809523809524: Reorder the natural callee-saved locals so the persistent file handle precedes the loop predicate in source lifetime, testing the proven EBP=file and EBX=team register colors. [same emitted code as probe 6]
probe 37 liveness; result=MISMATCH; diff=467; shape=95.23809523809524: Mark only the binary-live relation predicate register, not the saved flag or file handle, to test VC5's period-plausible register-coloring input. [same emitted code as probe 36]
probe 38 liveness; result=MISMATCH; diff=467; shape=95.23809523809524: Apply register storage only to the persistent file-handle alias, testing whether VC5 restores the original EBP handle color while retaining the separate team state. [same emitted code as probe 37]
probe 39 layout; result=MISMATCH; diff=467; shape=95.23809523809524: Restore the distinct one-byte relation-read local proven by the original stack window, instead of treating the decompiler's incoming file home as the semantic byte value. [same emitted code as probe 38]
probe 40 liveness; result=MISMATCH; diff=262; shape=94.83568075117371: Make the file-handle alias function-scoped and declare it before the team predicate, testing source declaration order as the register-color axis.
probe 41 liveness; result=MISMATCH; diff=262; shape=94.83568075117371: Remove the manual saved-team assignment and let one human-team local naturally spill and reload around the byte relation value, matching VC5's inferred register-clobber topology. [same emitted code as probe 40]
probe 42 liveness; result=MISMATCH; diff=262; shape=94.83568075117371: Use one register-qualified human-team predicate with the distinct relation local, testing whether VC5 inserts its own loop-head spill/reload instead of a source assignment. [same emitted code as probe 41]
probe 43 control-flow; result=MISMATCH; diff=262; shape=94.83568075117371: Move the relation-loop counter and saved-team assignment into a natural for-header update, testing VC5's loop rotation for the original initial jump and loop-head reload. [same emitted code as probe 42]
probe 44 control-flow; result=MISMATCH; diff=274; shape=94.81132075471699: Encode the proven relation-loop CFG with one initial jump and a backedge reload label, matching the original first-iteration and subsequent-iteration fault order.
probe 45 liveness; result=MISMATCH; diff=274; shape=94.81132075471699: Move the relation byte declaration into the positive-count loop body, matching its PDB lifetime and testing whether VC5 then assigns the proven EBX/EBP colors.
probe 46 liveness; result=MISMATCH; diff=262; shape=94.83568075117371: Move name_buffer into the positive name-length guard, matching its proven lifetime and testing whether reduced EDI pressure restores the callee-saved file/team colors. [same emitted code as probe 43]
probe 48 liveness; result=MISMATCH; diff=577; shape=91.42857142857143: H1: remove the explicit saved human-team alias while retaining the guarded do-while and parameter-home relation byte; test whether VC5 naturally spills the one predicate into the proven -4 reload home and colors file as EBP.
probe 49 layout; result=MISMATCH; diff=252; shape=98.57142857142857: H10 pointer-slot relation model: replacing the local player_id value with a natural long* player_id = &pos[i], then using *player_id throughout, improved strict diff from 262 to 252, size from 647 to 652, shape to 98.57%, and restored the original LEA/address/value schedule. The remaining drift is register coloring and loop-header reload.
probe 50 layout; result=MISMATCH; diff=252; shape=98.57142857142857: Validation of H10 pointer-slot relation model: player_id pointer preserves the original relation address schedule; fresh result is 252 bytes, 652-byte body, 0xC frame, 20 ordered calls, 98.57% shape, with remaining EBP/EBX coloring and loop-head drift.
```
<!-- end-recovered:14721d661448c2d3b8e4 -->

<!-- recovered:2a684b959782cb55c88a -->
### `8c67b3c4c63e` `src/scratch/0046F420_scenario_load.cpp:1-49`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0046F420 RGE_Player::scenario_load (653B)
// PDB source: player.cpp, lines 758-851
//
// Attempt log:
// - Replaced the old allocation-only scaffold with the complete scenario
//   stream and the binary-supported RGE_Player field ownership.
// - Added the preserved file-handle local. This recovered all 20 calls, the
//   0xC frame, and exact body size; the original still saves it in EBP before
//   the first read while VC5 delays that save in this source basin.
// - Moved the diplomacy index to the pre-attribute declaration and reused it
//   in the count loop. This recovered the original loop size and late islands.
// - Kept the byte relation read on the incoming file parameter home. The
//   original reloads the position pointer and keeps the human-team flag in
//   EBX; this clean source reaches the same calls and memory effects but VC5
//   colors those values differently.
// - Final best remains a 653-byte, 20-call reconstruction with 386 differing
//   bytes. Remaining drift is prologue scheduling, register coloring, and the
//   relation-loop flag/pointer topology.
// - Tried the same-TU map serialization donor's function-scope file handle
//   with the first name-length read on the parameter. This saved EBP before
//   ESI, but lost exact prologue blocks and raised strict drift to 403 bytes;
//   restored the clean guarded handle form.
// - Tested direct parameter use, delayed handle assignment, function-scope
//   aliases, and the proven overlapping count home. These widened or left the
//   strict diff unchanged; restored the 653-byte guarded-handle source.
// - Reused the human-team variable for relation player IDs with a saved flag,
//   matching more block islands and 95.24% shape, but strict drift worsened to
//   467 bytes and the source was less plausible. Rolled it back.
// - Tested the first-read alias, function-scope guarded handle, short player
//   count overlay, comma-guard/do-while forms, split relation flags, and the
//   file-handle attribute read. They were unchanged, worsened, or broadened
//   register drift. Restored this clean source after each check.
// - Follow-up binary review proved a distinct one-byte relation local at the
//   incoming file home and a saved team flag at the -4 local. The natural
//   two-flag/do-while form preserves all calls, size, frame, faults, and the
//   late relation islands; its best strict result is 262 differing bytes.
// - For-header and explicit-label loop forms changed block layout without
//   closing the remaining register-color and loop-head gap. The guarded
//   do-while form is retained as the simplest supported source model.
// - Final lead: the remaining 262-byte drift starts at the delayed EBP save;
//   calls, frame, size, and canonical field ownership are already aligned.
// - Exact-finish probe: a natural pointer to the mapped player slot (`&pos[i]`)
//   restores the original LEA/address/value schedule and reduces strict drift
//   to 252 bytes. Keep this pointer because the executable proves its lifetime.
// - Direct file use, declaration reordering, register hints, loop-header forms,
//   and the full player/scenario context were tested. They did not improve the
//   pointer basin. A normal C++ rge_read declaration is codegen-neutral.
// - Exact finish remains blocked by the original EBP file / EBX team coloring,
//   the loop-head reload block, and the one-byte boundary difference.
```
<!-- end-recovered:2a684b959782cb55c88a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
