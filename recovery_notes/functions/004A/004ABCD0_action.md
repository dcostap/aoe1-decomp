# Recovery journal: 004ABCD0 `action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sed.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sed.cpp`.
- Earlier recovery note: `recovery_notes/scr_sed.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:45226210a3c8bd15f262 -->
### `d050eea3c` `src/scr_sed.cpp:1762-1762`

Mapping: `strong`. comment lies after mapped function action at old line 1707.

```text
            // BINARY NOTE: the PDB ABI names this parameter unsigned long,
```
<!-- end-recovered:45226210a3c8bd15f262 -->

<!-- recovered:b19e0b7ed71d2f136a88 -->
### `d050eea3c` `src/scr_sed.cpp:1856-1856`

Mapping: `ambiguous`. comment lies after mapped function action at old line 1707.

```text
                // BINARY NOTE: both object-selection arms use redraw mode 0x10.
```
<!-- end-recovered:b19e0b7ed71d2f136a88 -->

<!-- recovered:c6c9a197354576c83d3c -->
### `d050eea3c` `src/scr_sed.cpp:2079-2084`

Mapping: `ambiguous`. comment lies after mapped function action at old line 1707.

```text
                    // BINARY NOTE: the shipped path redraws with status 3.
// [non-comment lines omitted during migration]
                    // BINARY NOTE: status 4 precedes master-panel setup.
// [non-comment lines omitted during migration]
                    // BINARY NOTE: master ownership is world->players[id].
```
<!-- end-recovered:c6c9a197354576c83d3c -->

<!-- recovered:4e18bb5c0b0bd8e4074c -->
### `d050eea3c` `src/scr_sed.cpp:2117-2117`

Mapping: `ambiguous`. comment lies after mapped function action at old line 1707.

```text
                // BINARY NOTE: the list path redraws with flag 1, not 2.
```
<!-- end-recovered:4e18bb5c0b0bd8e4074c -->

<!-- recovered:04e6833297ec148372d0 -->
### `target-session` `build/target_sessions/004ABCD0_action.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 control-flow; result=MISMATCH; diff=4724; shape=61.88186813186813: H1: route null param through a named final action_done label, testing whether VC5 shares the original null return epilogue.
probe 3 behavior; result=MISMATCH; diff=4779; shape=58.94876912840985: H2: replace the message switch with five independent comparisons to preserve five original set_help_info call sites instead of VC5 tail-merging the switch cases.
probe 5 behavior; result=MISMATCH; diff=4558; shape=61.976664378860676: H3: use an if/else-if chain for message help IDs, testing separate source call sites with one mutually exclusive dispatch.
probe 7 behavior; result=MISMATCH; diff=4606; shape=62.71536871123363: H4: restore binary-backed unit-player redraw behavior: game virtual redraw(game_mode,3) for line zero and redraw(game_mode,4) before master setup for nonzero.
probe 8 abi; result=MISMATCH; diff=4576; shape=63.34026334026334: H5: use the binary-proven world->players[player->id]->master_objects owner for set_master_info instead of a direct GAME_PLAYER master_objects field.
probe 9 behavior; result=MISMATCH; diff=4701; shape=61.19601328903654: H6: make the first unit-player master-info call explicit in its null and non-null arms, testing whether direct nested argument evaluation prevents cross-branch tail merging.
probe 10 behavior; result=MISMATCH; diff=4738; shape=61.42668428005284: H7: restore original unit object-panel redraw arguments: push 2 for unit-player changes and push 1 for unit-list changes, which are distinct binary call sites.
probe 11 liveness; result=MISMATCH; diff=4727; shape=61.71617161716171: H8: cache each proven short master_obj_id before nested player calls, matching original DI liveness and evaluation order in both master-info paths.
probe 12 behavior; result=MISMATCH; diff=4889; shape=60.0130890052356: H9: combine the corrected unit owner/redraw reconstruction with five independent message help predicates, testing whether the binary's five direct help calls justify duplicated comparisons.
probe 13 control-flow; result=MISMATCH; diff=4727; shape=61.71617161716171: H10: place an explicit result-return island after the main-view path, routing null and selection success through one local result before continuing to the mode dispatch.
probe 14 liveness; result=MISMATCH; diff=4737; shape=61.01249178172255: H11: use one conditional set_master_info call with a short master-id local and a valid-master predicate, testing direct argument scheduling against the duplicated-arm form.
probe 15 abi; result=MISMATCH; diff=4723; shape=61.12211221122112: H12: restore one shared local master-info call while retaining corrected world ownership, early short ID caching, redraw modes, and the distinct redraw(2)/redraw(1) tails.
probe 16 behavior; result=MISMATCH; diff=4579; shape=65.88072122052705: H13: replace four handwritten byte-string loops with natural strcmp predicates and reviewed string symbols, testing period VC5 strcmp lowering and register order.
probe 17 behavior; result=MISMATCH; diff=4589; shape=66.71309192200557: H14: keep natural strcmp lowering but reread param_1->panelName() for each predicate, matching the original eight panelName call sites and invalid-pointer fault order.
probe 18 behavior; result=MISMATCH; diff=4757; shape=63.362357669122574: H15: combine natural repeated panelName/strcmp predicates with five independent help calls, measuring the full binary-backed call set against the switch basin.
probe 19 control-flow; result=MISMATCH; diff=4602; shape=66.66666666666667: H16: recover the original nested, independently tested victory destination and go-to-destination predicates, including the proven redundant destination recheck.
probe 20 control-flow; result=MISMATCH; diff=4596; shape=66.66666666666667: H17: retain exclusive set-object handling, but nest destination handling and use a separate go-to predicate before the existing fallback.
probe 21 control-flow; result=MISMATCH; diff=5261; shape=54.705882352941174: H18: route every successful and null action exit through one explicit result variable and final action_finish label, testing the Ghidra-proven shared LAB_004abe5a topology.
probe 22 abi; result=MISMATCH; diff=4589; shape=66.71309192200557: H19: call set_help_info through the proven TPanel owner type instead of TTextPanel, testing whether static receiver ownership changes VC5 case tail merging. [same emitted code as probe 17]
probe 23 behavior; result=MISMATCH; diff=4589; shape=66.92200557103064: H20: restore the unit-mode redraw statuses proven by original pushes: modes 0xE, 0xF, and 0x14 with zero flags, instead of GAME_REDRAW0 for all three.
probe 25 control-flow; result=MISMATCH; diff=4684; shape=66.78272980501393: H21: route the null panel path through a final action_done label so VC5 can share the original zero-return cleanup tail at +0x18F.
probe 28 control-flow; result=MISMATCH; diff=4595; shape=66.87543493389005: H22: replace the message help switch with a natural mutually exclusive if/else chain, testing whether VC5 keeps five direct help-call sites without the switch's shared call tail.
probe 30 liveness; result=MISMATCH; diff=4589; shape=66.92200557103064: H23: give each message-help switch case a scoped receiver local, testing whether distinct case-local lifetimes prevent VC5 from tail-merging the proven five receiver loads and calls.
probe 32 behavior; result=MISMATCH; diff=4757; shape=63.563295378432684: H24: use five independent current_message predicates for the proven five help calls, isolating the call-surface fix from the earlier panel-name experiments.
probe 34 abi; result=MISMATCH; diff=4589; shape=66.92200557103064: H25: declare TRIBE_Screen_Sed::action virtual, as the PDB/Ghidra signature proves, testing whether the correct member surface changes this function's VC5 body basin. [same emitted code as probe 27]
probe 35 liveness; result=MISMATCH; diff=4589; shape=66.92200557103064: H26: model Ghidra's lVar5 zero result with one named result local for both zero-return paths, testing whether VC5 shares the original zero cleanup epilogue.
probe 36 layout; result=MISMATCH; diff=4591; shape=66.36490250696379: H27: restore Ghidra's proven 24-byte random_val local instead of the wider 28-byte heuristic buffer, testing stack-window and x87 home placement.
probe 39 control-flow; result=MISMATCH; diff=4589; shape=66.92200557103064: H28: omit the final case's explicit break before the dialog tail, matching Ghidra's implicit last-case fall-through and testing handler placement. [same emitted code as probe 38]
probe 40 control-flow; result=MISMATCH; diff=4743; shape=88.47184986595174: H29: reorder scenario-mode cases to the PDB line order: Messages, Victory, Map, Terrain, Players, Units, VictoryMulti, Diplomacy, Options; this tests source-order-driven handler placement.
probe 41 liveness; result=MISMATCH; diff=4738; shape=88.65771812080537: H30: let the second set_map_loc call use a direct GAME_PLAYER receiver, matching Ghidra's post-__ftol receiver reload and avoiding a named pointer's early get_player.
probe 42 liveness; result=MISMATCH; diff=4739; shape=88.99328859060402: H31: use direct GAME_PLAYER receivers for both post-centering view calls, testing whether this prevents VC5 from hoisting the global receiver load above the x87 arithmetic.
probe 44 control-flow; result=MISMATCH; diff=4517; shape=88.07769591426657: H32: mirror the Ghidra-proven nested victory destination/go-to predicates and fallback loop while retaining the PDB case order.
probe 45 behavior; result=MISMATCH; diff=4714; shape=88.15261044176707: H33: restore the original redraw mode 0x10 for victory set-object and line-1 set-destination paths, proven by the original push operands.
probe 49 layout; result=MISMATCH; diff=4738; shape=88.65771812080537: H49: match Ghidra's local declaration order by placing x/y outputs before random_val, testing the selection-area x87 home order without changing its 28-byte frame requirement. [same emitted code as probe 48]
probe 50 behavior; result=MISMATCH; diff=4752; shape=88.73239436619718: H50: keep the binary-proven redraw mode 0x10 for both victory object-selection arms in the PDB-order source.
```
<!-- end-recovered:04e6833297ec148372d0 -->

<!-- recovered:f041273d7f6e758007ca -->
### `9dc533e87bba` `src/scratch/004ABCD0_action.cpp:1-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004ABCD0 TRIBE_Screen_Sed::action | scr_sed.cpp:2509-3233
// First pass: cleaned Ghidra heuristic decompilation.  The goal of this pass is
// to get a large behavior-shaped source body compiling; exact matching has not
// yet been attempted.
// Attempt log:
// [1] Copied/restructured the Ghidra action body into local typed stubs with the
//     proven TRIBE_Screen_Sed field layout. VC5 compiles and writes an object.
//     check_function could not compare because rebuilt .text was shorter than
//     the original configured 5022-byte body.
// [2] Expanded duplicated map-clear switch, hardcoded/inlined dialog-name string
//     compares, and inlined game/player helper macros. check_function now
//     compares full size; current result is MISMATCH, first mismatch at +0x25
//     from null-param early-return block layout (original jumps to shared early
//     epilogue; current source emits an inline epilogue).
// [3] Added the typed TPanel virtual destructor. This moves activation/redraw
//     calls to the binary-backed +0x14/+0x20 slots and improves call alignment;
//     the remaining first mismatch is the shared early-return epilogue.
// [4] Tried moving the shared result label after the action body. That worsened
//     the first block and was rolled back; the TPanel-destructor candidate stays.
// [5] Direct return and outer non-null guard probes did not reproduce the
//     original null-path epilogue; the direct-return body remains the clean form.
// [6] Modeled InvalidateRect as its proven IAT pointer and new_random_map as the
//     world virtual at +0x28; both restore binary-backed call identities.
// [7] Removed cached GAME_PLAYER results in the two unit branches. The original
//     reloads the player for the master and tribe arguments; call-count parity
//     improved by two.
// [8] Restored the full TPanel virtual surface, TTextPanel E8 text dispatch,
//     and the direct TEditPanel/TPanel ownership. Modeled the victory-button
//     +0xE0 call as a local virtual slot.
// [9] Kept map-center arithmetic as an integer before the float view calls;
//     this removes the rebuilt-only center ftol and is the current best.
// [10-23] Binary checks confirmed the unit redraw status values, the
// world-player master lookup, the distinct object-panel redraw flags, and
// natural repeated panelName/strcmp lowering. Independent help predicates
// restore call count but add an unsupported 190-byte control-flow expansion.
// The PDB-order switch restores the original call order without helper scaffolding.
// Remaining structural gap: VC5 merges the five TPanel::set_help_info arms.
// [24-47] PDB line order shows the scenario-mode source order as Messages,
// Victory, Map, Terrain, Players, Units, VictoryMulti, Diplomacy, Options.
// This order gives 200/200 ordered calls, 88.73% shape, and 70.07% exact blocks.
// It adds 146 bytes of code or padding, so exact size and tail layout remain open.
// [48-50] The x/y declaration order is codegen-neutral.  Original pushes prove
// redraw(0x10,0) in both victory object-selection arms; this gives 70.07% blocks.
// FLAGS: /nologo /c /O2 /Oy /GX
// BINARY NOTE: the authentic wrapper with packet default flags still has eight
// relocated target mismatches and four boundary escapes. The remaining source
// gap is structural, not a reason to add fake dispatch or context scaffolding.
```
<!-- end-recovered:f041273d7f6e758007ca -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

### 2026-08-29 `wave21-scr-sed-integrate`

- Applied the proved direct chained receiver form for the victory go-to path:
  `rge_base_game->get_player()->set_view_loc(f1, f2)`.
- Removed the now-unused local `player`. Preserved the current Victory x87
  expressions and map-generation prelude.
- Fresh baseline: MISMATCH, 5184 rebuilt bytes, frame `0x2C`, diff 4327,
  shape 88.34%, 201 rebuilt calls.
- Final focused check: MISMATCH, 5184 rebuilt bytes, frame `0x2C`, diff 4326,
  shape 88.47%, 201 rebuilt calls. The change improved one byte and one shape
  point without changing call order, size, frame, or block coverage.
- Full `scr_sed` observed audit passed all 38 registered exact neighbors.
  Existing action boundary and relocation differences remain.
- Source remains `scratch`. The pause command timed out on the session lock;
  the coordinator must pause the lease when the lock is available.
