# Recovery journal: 0048D530 `TribeAchievementsScreen`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_ach.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_ach.cpp`.
- Earlier recovery note: `recovery_notes/scr_ach_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:83fbf307dbff804253a1 -->
### `target-session` `build/target_sessions/0048D530_TribeAchievementsScreen.json:1-38`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=2803; shape=80.97087378640776: Baseline current natural reconstruction before new probes; establish exact size, frame, call parity, and first mismatch.
probe 2 liveness; result=MISMATCH; diff=2869; shape=81.07317073170732: H2 remove explicit temptxt zero initializer; test whether compiler-generated EH/local state supplies the four observed dword zero stores and restores 0x1D4 frame.
probe 3 layout; result=MISMATCH; diff=2848; shape=82.38747553816047: H3 replace broad array memsets with original-shaped five choice stores, title-bar memset, and nested 8x7 statistic/player zero loop; add four observed temptxt dword zeroes and move str[1] before end flag.
probe 4 layout; result=MISMATCH; diff=2458; shape=81.28031037827353: H4 use one observed tail-window zero fill (temptxt+35,15) to preserve the proven local lifetime without retaining four dead assignments.
probe 5 liveness; result=MISMATCH; diff=2850; shape=82.28962818003914: H5 assign end_game_flag as first body statement, following donor-supported constructor scheduling, to test early parameter load and original zero-store order.
probe 6 layout; result=MISMATCH; diff=2886; shape=81.08632395732299: H6 widen the observed temptxt tail fill to four dwords (35..50) to test whether VC5 emits the original four zero stores with a stable local footprint.
probe 7 layout; result=MISMATCH; diff=2458; shape=81.28031037827353: H7 diagnostic 48-byte temptxt footprint with the proven 35..49 tail zero range; test whether local packing restores the 0x1D4 frame without broad fill bytes. [same emitted code as probe 4]
probe 8 layout; result=MISMATCH; diff=2909; shape=81.99419167473378: H8 reduce the diagnostic temp declaration to 44 bytes while retaining the observed tail writes, testing VC5 frame rounding threshold.
probe 9 liveness; result=MISMATCH; diff=2848; shape=82.28962818003914: H9 swap nested-loop pointer declaration order to match original ESI=statistics and EDX=player_names register/address topology.
probe 10 liveness; result=MISMATCH; diff=2848; shape=82.38747553816047: H10 restore statistics-before-player pointer declaration order; compare emitted loop register colors and use this as a sustained tenth distinct probe. [same emitted code as probe 3]
probe 11 liveness; result=MISMATCH; diff=2769; shape=76.01547388781431: H12 diagnostic only: volatile four-dword tail stores test whether exact observed stack writes are sufficient; do not retain this forbidden steering form.
probe 12 liveness; result=MISMATCH; diff=2848; shape=82.38747553816047: H13 register-qualified inner colored pointer, testing binary-proven EBX pointer carry through the seven color calls without changing behavior. [same emitted code as probe 10]
probe 13 liveness; result=MISMATCH; diff=2848; shape=82.38747553816047: H14 split player_index declaration from its first assignment, testing original stack-home placement and early loop setup scheduling. [same emitted code as probe 12]
probe 14 layout; result=MISMATCH; diff=2864; shape=82.48031496062993: H15 shorten the evidence-led tail fill to 12 bytes, testing whether the three full dwords preserve the useful temp lifetime with less extra code.
probe 15 variant; result=MISMATCH; diff=2864; shape=82.48031496062993: variant lab build\variant_lab\0048D530_TribeAchievementsScreen\20260817_154030: 32 variants, 0 invariant-eligible, 0 exact
probe 16 liveness; result=MISMATCH; diff=2848; shape=82.38747553816047: H16 close_button address alias before initialization, now with the original 10 post-parent arguments.
probe 17 control-flow; result=MISMATCH; diff=2837; shape=85.09803921568627: H17 invert and reorder the win_loss_text branch to follow the original JE-to-empty-arm layout and positive message fallthrough.
probe 18 control-flow; result=MISMATCH; diff=2837; shape=85.58823529411765: H18 replace branchless ternary mode selection with explicit positive/empty branches, matching the original push-5/jump/push-0 tail.
probe 19 control-flow; result=MISMATCH; diff=2837; shape=85.58823529411765: H19 express the eight-row loop as player_index < 9, testing the original decrement/less-than loop-tail lowering.
probe 20 control-flow; result=MISMATCH; diff=2848; shape=85.79823702252693: H20 express the original loop tail as player_index - 1 < 8, testing the observed inc/store/dec/cmp-8/jl sequence.
probe 21 liveness; result=MISMATCH; diff=2848; shape=85.79823702252693: H21 reorder row-loop declarations to the Ghidra-proven order: player pointer, offset, y, statistics row, then index. [same emitted code as probe 20]
probe 22 layout; result=MISMATCH; diff=2461; shape=84.13926499032883: H22 combine the branch-layout improvements with the proven tail-window fill diagnostic to test whether the original local pressure basin is recovered.
probe 23 layout; result=MISMATCH; diff=2902; shape=85.09196515004841: H24 combine H18 control-flow recovery with a 44-byte diagnostic temp footprint to test exact-frame packing under the observed tail writes.
probe 25 liveness; result=MISMATCH; diff=2848; shape=85.79823702252693: H25 retrospective reversion: remove the close-button alias because H16 produced no measurable gain; retain direct member use unless this worsens codegen.
probe 28 liveness; result=MISMATCH; diff=2596; shape=85.25073746312684: H28 natural aggregate initializer: initialize the declared temptxt[50] with {0}, testing whether the original unaligned tail stores come from source initialization rather than a metric-only memset.
probe 30 liveness; result=MISMATCH; diff=2848; shape=85.79823702252693: H29 natural local use: assign temptxt[0] = 0, testing whether one observable use preserves the original 50-byte stack local without synthetic tail memset. [same emitted code as probe 26]
probe 31 layout; result=MISMATCH; diff=2461; shape=84.13926499032883: H31 natural partial buffer operation: memset(temptxt + 35, 0, 15), testing the original unaligned zero-store footprint and buffer lifetime against the clean model.
probe 32 liveness; result=MISMATCH; diff=2458; shape=84.12391093901259: H32 declaration lifetime/order: place row immediately after player_name and restore player_index <= 8, matching the original loop setup stores and shipped dec/cmp tail while retaining the evidence-led buffer operation.
probe 33 liveness; result=MISMATCH; diff=2458; shape=84.12391093901259: H33 local declaration order: declare temptxt before tabList, testing whether VC5 moves the proven unaligned buffer stores to the original stack home without changing behavior. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=2458; shape=84.12391093901259: H34 local buffer order: declare str before temptxt, testing whether VC5 assigns the evidence-led zero-fill to the original stack coordinate; retain only if emitted topology improves. [same emitted code as probe 33]
probe 35 liveness; result=MISMATCH; diff=2458; shape=84.027105517909: H35 initialization pointer lifetime: declare player_names before statistics, testing the original EDX=player_names and ESI=statistics register topology in the nested zeroing loop.
probe 36 layout; result=MISMATCH; diff=2458; shape=84.12391093901259: H36 source-order test: move the evidence-led temptxt tail zeroing after screen-member initialization, matching the original PDB line band that interleaves local stores with field setup. [same emitted code as probe 34]
probe 37 liveness; result=MISMATCH; diff=2668; shape=85.15240904621436: H37 natural aggregate-init with recovered loop declaration order: use char temptxt[50] = {0} without the partial memset, testing whether the simplest initialized local preserves the best topology.
probe 38 liveness; result=MISMATCH; diff=2458; shape=84.12391093901259: H38 natural color initialization: initialize the switch result local with zero, testing the original early dead-looking [esp+1EC] zero store and its effect on frame scheduling. [same emitted code as probe 36]
probe 39 liveness; result=MISMATCH; diff=2458; shape=84.12391093901259: H39 declaration scope: make the tab-order count block-local instead of function-scope, testing whether the original [esp+14] shared count/index home is recovered naturally.
probe 40 layout; result=MISMATCH; diff=2457; shape=84.22071636011617: H40 buffer-anchor test: shift the zero-fill from temptxt+35 to temptxt+27, testing the observed original [esp+67] store coordinate against the compiler's current local anchor.
probe 41 liveness; result=MISMATCH; diff=2458; shape=84.12391093901259: H41 lifetime scope: declare tabList at its final tab-order use instead of function scope, testing the original overlap between the late tab array and the early scratch buffers.
probe 42 layout; result=MISMATCH; diff=2457; shape=84.70474346563408: H42 local-width diagnostic: reduce info_file from the Ghidra-indicated 260 bytes to 256 to test whether the four-byte frame excess is only stack packing; this form is not retained without stronger layout evidence.
```
<!-- end-recovered:83fbf307dbff804253a1 -->

<!-- recovered:41e41466fe64fb32336c -->
### `9666a5ef808e` `src/scratch/0048D530_TribeAchievementsScreen.cpp:1-28`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0048D530 TribeAchievementsScreen::TribeAchievementsScreen (3222 B)
// PDB source: scr_ach.cpp (lines 110-354)
//
// Attempt log:
// - Replaced the constructor shim with the packet-grounded screen setup:
//   member initialization, localized setup-file selection, text/statistics
//   panels, timeline/buttons, winner decal, tab order, and initial mode.
// - Recovered world-time/player/civilization offsets and all 69 direct/virtual
//   call sites. A 48-byte effective scratch variant matched the frame but was
//   rejected as compiler steering; the PDB-backed 50-byte natural local is kept.
// - Tested an uninitialized temptxt declaration from the decompiler; VC5
//   elided the unused local, changing the frame to 0x1A4 and worsening diff.
//   Rolled back to the validated natural source.
// - The original tail uses an explicit branch for mode selection, not a
//   branchless ternary. The row loop also retains the shipped dec/cmp tail.
// - BINARY NOTE: The original writes a zero tail at the unaligned temptxt
//   stack home. A partial memset preserves this shipped local effect.
// - The row declaration order and <= 8 loop test recover the original setup
//   stores and reduce the measured difference to 2458 bytes.
// - A 256-byte info_file gives the exact frame, but the packet indicates 260
//   bytes and matching period sources use 260-byte file buffers. Keep 260.
// - The scr_ach.cpp TU uses its period panel surface. The broader shared panel
//   surface shifts text and button virtual slots.
// - BINARY NOTE: The setup branch falls through for end_game_flag != 0.
// - Context gate: PDB scr_ach.cpp lines 110-354 owns this constructor and the
//   exact anchors are the base call at 0048D55A and 69 ordered call sites.
// - Grouped candidate: six exact owners remain exact. This owner emits with
//   boundary escape 2 and remains nonexact at 2877 strict-difference bytes.
```
<!-- end-recovered:41e41466fe64fb32336c -->

<!-- recovered:89e83770e326ac0fe462 -->
### `9666a5ef808e` `src/scratch/0048D530_TribeAchievementsScreen.cpp:482-482`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // BINARY NOTE: The shipped layout tests the non-null message arm first.
```
<!-- end-recovered:89e83770e326ac0fe462 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
