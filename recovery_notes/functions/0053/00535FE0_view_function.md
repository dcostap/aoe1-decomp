# Recovery journal: 00535FE0 `view_function`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.
- Earlier recovery note: `recovery_notes/view_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:726ce59b0dae386bac59 -->
### `target-session` `build/target_sessions/00535FE0_view_function.json:1-23`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=2423; shape=65.02463054187191: Baseline current clean natural reconstruction; establishes 65.02% shape, 2423 strict diff, exact 15-call set, frame/saved-reg parity; first mismatch local fog slot and corpus overflow remains.
probe 2 layout; result=MISMATCH; diff=2432; shape=65.27093596059113: Hypothesis 1: list_size is a short because original computes max_row_num+6 in AX, shifts AX, tests AX, and stores the 16-bit-sized result without a sign-extension. Test whether this recovers the initial loop setup.
probe 3 abi; result=MISMATCH; diff=2686; shape=60.617283950617285: Hypothesis 2: fog_flag may be a signed char rather than unsigned char; test whether signed byte semantics select the target local slot and comparisons.
probe 4 abi; result=MISMATCH; diff=2645; shape=60.419235511713936: Hypothesis 3: inventory decomp declares picked_type as uchar; test that source width against target's byte-oriented loop dispatcher and initial stack homes.
probe 5 liveness; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 4: Ghidra lists both a compiler-visible temporary  and stack local ; retain both around get_visible results to test whether this recovers target visibility-home and fog-slot liveness.
probe 7 control-flow; result=MISMATCH; diff=2436; shape=64.90147783251231: Hypothesis 5: follow the decompiler line order by initializing tile_screen_row and calc_sel_col1 before copying picked_type into max_row_num2; test whether VC5 schedules the target initial stores.
probe 9 abi; result=MISMATCH; diff=2693; shape=58.917589175891756: Hypothesis 6: Ghidra types direction as uchar; test that narrow loop-state type against target dword home and increment sequence.
probe 11 abi; result=MISMATCH; diff=2735; shape=59.25925925925926: Hypothesis 7: apply the paired Ghidra narrow types picked_type=uchar and direction=uchar together; combined liveness may recover the target frame and stack layout even though each isolated type failed.
probe 13 abi; result=MISMATCH; diff=2441; shape=64.61916461916462: Hypothesis 8: inventory decomp declares tile_screen_row as short; test that width against target dword dispatch load and byte state updates.
probe 15 abi; result=MISMATCH; diff=2454; shape=64.74201474201475: Hypothesis 9: max_row_num2 may be an int because the target stores it as a dword at its home, while only the equality test reads its low word; test this width.
probe 17 liveness; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 10: target initial setup loads four persistent short states before bounds and writes their homes; add register hints to those non-address-taken locals to test whether VC5 selects the target register schedule. [same emitted code as probe 1]
probe 19 abi; result=MISMATCH; diff=2727; shape=55.0061804697157: Hypothesis 11: Ghidra declares col_num as short while the reconstruction uses uchar; test this proven-width candidate in tile-type indexing and the terrain switch.
probe 21 abi; result=MISMATCH; diff=2447; shape=64.37346437346437: Hypothesis 12: picked_type may be int because target writes its value as a dword to both max_row_num2 and its own home; test a full-width loop bound.
probe 24 liveness; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 1: declare fog_flag beside the first visibility byte so VC5 may place its proven target home at [esp+2Ch] instead of rebuilt [esp+30h]. [same emitted code as probe 23]
probe 26 control-flow; result=MISMATCH; diff=2434; shape=65.84766584766585: Hypothesis 2: keep the mode-0B tile visibility test inside the in-bounds arm, matching the target's shared zero-visibility block and avoiding an out-of-bounds tile dereference.
probe 28 layout; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 3: declare the real tile pointer before the fog/draw byte, matching the target's proven pointer home [esp+34h] and the Ghidra local order. [same emitted code as probe 24]
probe 30 control-flow; result=MISMATCH; diff=2434; shape=65.84766584766585: Hypothesis 4: use one explicit visible_zero label for out-of-bounds and the mode-0B tile suppression, matching the target's shared LAB_005362AF successor.
probe 32 abi; result=MISMATCH; diff=2436; shape=63.90243902439025: Hypothesis 5: last_picked_obj may be a full-width source local, as the target stores and reloads its dword home at [esp+44h] despite narrow uses; test int ownership.
probe 34 control-flow; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 6: restore the period assignment order cur_col_num before direction, because PDB bands and target loads read start_scr_row before start_map_row. [same emitted code as probe 28]
probe 36 abi; result=MISMATCH; diff=2432; shape=65.27093596059113: Hypothesis 7: model list_size as a short with a separate natural truncating assignment and shift, matching target AX arithmetic without the int sign-extension emitted by the clean cast.
probe 38 layout; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 8: order the three inner coordinate locals as target stack evidence does: map_row, start_scr_col2, map_col; test whether VC5 recovers the [14]/[18]/[1C] home sequence. [same emitted code as probe 34]
probe 40 abi; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 9: mark view_function protected, matching the target PDB/Ghidra decorated owner (?view_function@RGE_View@@IAE...). [same emitted code as probe 38]
probe 41 control-flow; result=MISMATCH; diff=2423; shape=65.02463054187191: Hypothesis 10: use the target's observed negative visibility guard (visible == 0 || map_visible_flag != 0) and matching branch-local get_visible fallbacks. [same emitted code as probe 5]
```
<!-- end-recovered:726ce59b0dae386bac59 -->

<!-- recovered:4ec863a8c6cd348c3c7a -->
### `056a20c24f68` `src/scratch/00535FE0_view_function.cpp:1-89`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00535FE0 RGE_View::view_function (view.cpp:2562-3006)
// __thiscall, 2354 bytes (corpus range 00535FE0-00536911).
//
// NOTE (corpus split): the original function physically continues past the
// inventory boundary (00536911) with the tile_screen_row switch cases
// (00536912/00536932/00536957...) and the shared loop tail (00536992+), plus
// jump tables at 00536B04/00536B1C/00536B2C.  The corpus tracks those blocks
// separately as parent-owned fragments (00536912, 00536957) and the naked
// fragment 00536932 (caseD_3).  A faithful single-function reconstruction is
// therefore always flagged "code-overflow" by the checker (the original's own
// `ja 00536992`/`jne 00536A9E`/`je 005369DC` targets and the switch jump-table
// entries lie beyond the 2354-byte compared range).  This file keeps the full
// natural source so the parent (and its fragments) stay readable; the exact
// check cannot succeed until the corpus boundary question is resolved.
//
// Attempt log:
//   p1 baseline: full natural reconstruction from Ghidra packet + exact donors
//     (get_selection_area, get_visible, shadow_draw, normal_draw, get_list_info)
//     + type dumps (RGE_View/RGE_Map/RGE_Tile/RGE_Player/TDrawArea). 45.3% shape.
//   p2 types: fixed RGE_Tile_Set sizeof 0x198 (was 0xBA -> shifted all map offsets)
//     and RGE_View gap after y_max (started at 0x98, overlapped; now 0x9C). 53.6%.
//   p3 liveness: removed the `tile_ptr != 0` guard in the terrain-update block; the
//     original derefs tile_ptr unconditionally (mov bl,[ebp+5] at 0053660C). This
//     flipped the frame to 0x78 and raised shape to 62.9%.
//   p4 layout: reversed local declaration order - no emitted-code change (negative).
//   p5 control-flow: swapped function_parm/function_mode store order - slightly worse,
//     reverted (negative).
//   p6 flags: `register` on a1/a2 - no emitted-code change (negative).
//   p7 control-flow: restructured in-bounds check from if/else-if/else to
//     if/else-with-nested-continue so VC5 keeps the out-of-bounds mode check inline
//     (matches original B029/B030 blocks); 63.9%.
//   p8 context: changed the mode-chain conditions (0x28/0x3C/.../0x2C and the 0x0E
//     selection check) to read `this->function_mode` instead of the `a1` parameter.
//     The original reloads the member after the get_list_info call (mov al,[esi+140h]
//     at 00536062), so the source used member reads, not the param. This made the
//     ENTIRE prologue byte-identical and raised shape to 65.0% (first mismatch now
//     only the fog_flag local slot +0x90).
//   p9 layout: restored natural declaration order - no change (negative).
//   p10 control-flow: assigned direction before cur_col_num to match the
//     original PDB statement order at view.cpp:2634/2637; strict diff improved
//     2529 -> 2526 bytes, but edit/resync diff worsened. Rolled back to the
//     clean natural source; the structural stage and corpus-boundary block
//     remain unresolved.
//   continuation claim #1 layout: short list_size matched the observed
//     16-bit max-row arithmetic but enlarged the code; restored int.
//   claim #2 control-flow: direction-before-cur order was a codegen duplicate.
//   claim #3 layout: max_row_num2 = picked_type improved the short-list basin
//     to 2451 bytes; the alias is retained.
//   claim #4 layout: int list_size with that alias reached 2433 bytes.
//   claim #5 layout: reversing the two max-col assignments regressed to 2526;
//     restored the alias direction.
//   claim #6 abi: modeled the binary/decompiler bounds predicate as bool
//     in_bounds; this improved strict diff to 2424 bytes and is retained.
//   claim #7 abi: bool draw_flag was a 2448-byte regression; restored int.
//   claim #8 layout: short list_size with the bool/alias surface was 2432 bytes;
//     restored int.
//   claim #9 layout: cast the short max-row sum before the shift, matching the
//     observed 16-bit add/shift and reaching the current best, 2423 bytes.
//   Status: structurally faithful (frame/saved-regs/calls/prologue exact, 65% shape,
//     ~42% exact-block coverage); remaining drift is VC5 local-slot permutation
//     (picked_type/fog_flag/tile/tile_ptr/start_map_row2/direction/tile_screen_row/
//     last_picked_obj region) and ebx/ebp register roles. Exact check is BLOCKED by
//     the corpus split (see note above); further probing would be blind allocation tuning.
//   latest pass (sa-c5cf6e0b): twelve fresh hypotheses were compiled and checked.
//     Narrow list_size, signed fog_flag, narrow/full picked_type, narrow direction,
//     narrow col_num, short tile_screen_row, full max_row_num2, paired narrow types,
//     reordered initializers, a separate visibility local, and register hints for
//     the persistent short states all regressed or produced duplicate codegen.
//     The clean source remains best at 2423 strict-diff bytes, 65.02% shape,
//     41.72% exact-block coverage, frame 0x78, and all 15 calls aligned.
//     No hypothesis changed the corpus overflow. Restore the clean source before
//     pause; the remaining lead is the proven local-home/register basin, not ABI.
//   latest pass (sa-ac59df96):
//     H1 moved fog_flag beside visible; codegen duplicate.
//     H2 moved the mode-0B tile test inside the in-bounds arm; strict diff 2434,
//     shape 65.85%, then restored because natural strict bytes worsened.
//     H3 swapped tile and tile_ptr declarations; codegen duplicate.
//     H4 used one explicit visible_zero label; same 2434-byte result as H2,
//     restored because it was not the clean natural basin.
//     H5 widened last_picked_obj to int; strict diff 2436, shape 63.90%, restored.
//     H6 restored cur_col_num-before-direction assignment order; codegen duplicate.
//     H7 used a short list_size with a separate shift; strict diff 2432, restored.
//     H8 reordered inner coordinate declarations; codegen duplicate.
//     H9 marked view_function protected. Bytes stayed unchanged and the owner
//     symbol changed from QAE to the target's protected IAE decoration; retained.
//     H10 used the target's negative visibility guard; codegen duplicate.
//     Final clean: 2423 strict diff, 65.02% shape, 41.72% exact blocks, 15 calls,
//     frame 0x78. The target's 2354-byte corpus boundary still truncates the
//     natural function tail and prevents exact boundary validation.
```
<!-- end-recovered:4ec863a8c6cd348c3c7a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
