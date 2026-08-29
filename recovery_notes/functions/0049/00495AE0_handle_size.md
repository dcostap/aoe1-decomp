# Recovery journal: 00495AE0 `handle_size`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_game.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_game.cpp`.
- Earlier recovery note: `recovery_notes/scr_game.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2d6b8f2de984d7df4902 -->
### `target-session` `build/target_sessions/00495AE0_handle_size.json:1-25`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 liveness; result=MISMATCH; diff=1945; shape=94.17249417249417: H1: swap panel_cols and panel_y declaration order to change VC5 register/home assignment; test original EBX column counter and stack y seed.
probe 3 control-flow; result=MISMATCH; diff=2049; shape=93.6470588235294: H2: replace pointer-cursor do/while button grids with natural indexed row/column for loops and direct button_panel indexing; test whether source loop form recovers original counter homes.
probe 5 liveness; result=MISMATCH; diff=1945; shape=94.17249417249417: H3: make six-column counter block-local inside each outer grid to test whether VC5 keeps it in EBX instead of a stack home while retaining pointer-cursor loops. [same emitted code as probe 1]
probe 7 abi; result=MISMATCH; diff=1945; shape=94.17249417249417: H4: narrow grid y accumulator from long to int to test VC5 width-driven home and register assignment against original dword stack y. [same emitted code as probe 5]
probe 9 liveness; result=MISMATCH; diff=1945; shape=94.17249417249417: H5: apply register qualifier to panel_cols, a non-address-taken six-column counter, to test whether VC5 honors the original EBX residency. [same emitted code as probe 7]
probe 11 abi; result=MISMATCH; diff=1945; shape=94.17249417249417: H6: narrow grid x accumulator from long to int, matching decompiler iVar9 and testing width-sensitive VC5 register/home assignment. [same emitted code as probe 9]
probe 13 liveness; result=MISMATCH; diff=2113; shape=93.22429906542057: H7: rewrite initial score-state save as reverse-declared pointer cursors and a do/while, testing original EDI=save and EBX=score-panel register colors without changing calls.
probe 15 liveness; result=MISMATCH; diff=2113; shape=93.22429906542057: H8: scope reverse-declared score save cursors and register-qualified count to limit lifetime and avoid H7's frame growth while seeking original first-loop register colors. [same emitted code as probe 13]
probe 17 liveness; result=MISMATCH; diff=1945; shape=94.17249417249417: H9: move save_score_active declaration after grid locals to test declaration-order register coloring while preserving its observed stack array and all behavior. [same emitted code as probe 11]
probe 19 liveness; result=MISMATCH; diff=2113; shape=93.22429906542057: H10: use reverse-declared pointer cursors with a C-style counted for index, avoiding explicit count local; test if VC5 preserves frame while swapping save/panel register colors. [same emitted code as probe 15]
probe 21 liveness; result=MISMATCH; diff=1952; shape=94.05594405594405: H11: keep indexed saved-state storage but use one score-panel pointer cursor, testing whether this minimal alias flips the first-loop EDI/EBX allocation without adding a second cursor.
probe 23 liveness; result=MISMATCH; diff=1941; shape=94.17249417249417: H12: use only a saved-state pointer cursor while retaining direct score_panel indexing, testing whether this asymmetric alias produces original EDI=save and EBX=panel colors.
probe 24 liveness; result=MISMATCH; diff=1941; shape=94.17249417249417: H13: model the y accumulator as a one-element local array to force the observed stack home, testing whether VC5 then assigns the six-column counter to EBX. [same emitted code as probe 23]
probe 26 liveness; result=MISMATCH; diff=1941; shape=94.17249417249417: H14 retry: branch-local grid declarations produced identical code to H12; shared versus arm-local cursor scope is codegen-neutral here. [same emitted code as probe 24]
probe 28 control-flow; result=MISMATCH; diff=1941; shape=94.17249417249417: H15: move the six-column counter declaration into each for-loop header, testing declaration scope and VC5 induction lowering against the original EBX countdown. [same emitted code as probe 26]
probe 30 liveness; result=MISMATCH; diff=1941; shape=94.17249417249417: H16: move panel_y declaration before the button cursor and column counter, testing shared-local declaration order for the y-home versus EBX counter assignment. [same emitted code as probe 28]
probe 32 abi; result=MISMATCH; diff=1941; shape=94.17249417249417: H17: widen the six-column counter declaration to long, testing whether matching the coordinate accumulator type changes VC5 register residency while retaining dword countdown semantics. [same emitted code as probe 30]
probe 34 liveness; result=MISMATCH; diff=1945; shape=93.82284382284382: H18: reverse source order of button-pointer and x-coordinate updates in all grid loops, testing VC5 scheduling and loop-register assignment against the observed add edi/add ebp order.
probe 36 liveness; result=MISMATCH; diff=1941; shape=94.17249417249417: H19: reverse source order of outer row decrement and y advance, testing VC5 update scheduling against original add y/dec row/store ordering. [same emitted code as probe 32]
probe 38 liveness; result=MISMATCH; diff=1941; shape=94.17249417249417: H20: declare final_frame before the save and grid locals, testing whether its long-lived declaration changes the shared register basin without changing control flow. [same emitted code as probe 36]
probe 40 abi; result=MISMATCH; diff=1941; shape=94.17249417249417: H21: extend TPanel's declaration-only virtual surface with the adjacent exact scr_game.cpp donor slots, testing translation-unit class context while preserving proven called slots. [same emitted code as probe 38]
probe 42 context; result=MISMATCH; diff=1941; shape=94.17249417249417: H22: replace the local tagRECT clone with period windows.h tagRECT, using adjacent scr_game.cpp donor context to test header-state codegen.
probe 47 control-flow; result=MISMATCH; diff=1957; shape=91.87279151943463: H23: move the shared button-panel[16] resize and draw-type publication after the three size arms, with branch-local x/y state, to test the original 00495F73 shared call tail while preserving child order and state publication.
probe 49 control-flow; result=MISMATCH; diff=1989; shape=92.34393404004712: H24: share button-panel[16] setup only between large and medium arms using branch-local coordinates and a binary-supported skip over the common tail for small layout; preserve small child resize and draw-type order.
probe 52 liveness; result=MISMATCH; diff=1990; shape=92.86549707602339: H25: retain each grid element in a typed button local and publish draw_type after cursor, x, and column updates, matching the original loop's old-element store order without raw aliases.
```
<!-- end-recovered:2d6b8f2de984d7df4902 -->

<!-- recovered:473f29bc64195ec1f7e1 -->
### `d2ec54ebab00` `src/scratch/00495AE0_handle_size.cpp:1-56`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00495AE0 TRIBE_Screen_Game::handle_size
// PDB donor: scr_game.cpp:1215-1431
//
// Baseline reconstruction: the method lays out the three game-screen size
// families, preserves each panel's real TPanel positioning surface, saves the
// score-panel active states, and restores them after the layout pass.  The
// repeated offsets below are the screen's named panel members, not a raw
// decompiler cursor view.
// Attempt log:
// - baseline: canonical TRIBE_Screen_Game/TPanel layout and typed
//   set_positioning/set_fixed_position virtual calls; frame 0x24, 2 missing
//   small-screen fixed-position calls, 1986 strict differing bytes.
// - behavior: restored the small-screen button-panel[5] and [11] positioning
//   and draw-type updates proven by the 00495FA1-004961B8 branch; call count
//   became 82/82 and size moved to +30 bytes.
// - control-flow: changed each repeated 2x6 button layout to a pointer-cursor
//   do/while form with the observed 0x36 column and 0x3A row strides; frame
//   became the original 0x20 and strict diff improved to 1945 bytes.
// - liveness/context: shared the panel cursor/coordinate/counter locals across
//   the three size families, reordered their setup, tested declaration order,
//   register qualification, long coordinate types, and nested size guards;
//   these variants either emitted identical code or only changed scheduling.
// - control-flow: tested a natural small-first threshold dispatch with a named
//   button-16 tail for the medium/large arms; call sites became 82/82 aligned,
//   but the first threshold moved to the wrong compare order and diff grew to
//   2237 bytes, so this source was restored.
// - control-flow: a preliminary tail form kept the first call prefix longer,
//   but added 70 bytes and worsened structural coverage; it was also restored.
// - paused: current source is the best natural reconstruction.  Remaining
//   structural lead is the first button-loop setup at 00495B75: original keeps
//   row y at [esp+38] and the six-column counter in EBX, while VC5 keeps the
//   y seed in EBX and homes the column count.  One branch-local call tail is
//   also physically shared differently (original 00495F73 versus rebuilt).
//
// Fresh bounded pass (sa-946ebf0a):
// - H1-H6 tested declaration order, loop form, local scope, register hints,
//   and int/long widths.  They were duplicate or worse codegen.
// - H7-H10 tested score-panel pointer cursors.  Two cursors added a 0x24 frame
//   and 2113 differing bytes.  The counted-for form kept that basin.
// - H11 used one panel cursor and worsened the result to 1952 bytes.
// - H12 kept direct score-panel indexing and added only a saved-state cursor.
//   This restored the original first save-loop register order and reduced the
//   strict difference to 1941 bytes.  This is the retained clean source.
// - H13-H17 tested an array-backed y local, branch-local cursors, declaration
//   order, and counter width.  They were duplicate codegen.
// - H18-H20 tested update order and final-frame declaration order.  They were
//   duplicate or worse codegen.  H21 added the full adjacent TPanel surface;
//   it was duplicate.  H22 replaced tagRECT with the period windows.h type;
//   it was neutral.
//
// BINARY NOTE: the first save loop uses EDI for save_score_active and EBX for
// score_panel.  The retained pointer shape reproduces this register order.
// BINARY NOTE: each button grid uses a stack y home and an EBX column count in
// the executable.  The clean source still emits the reverse assignment.
// LIKELY INTENT: the large-arm button-16 call shares the medium-arm call tail.
// The current natural nested arms do not reproduce that tail merge.
```
<!-- end-recovered:473f29bc64195ec1f7e1 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
