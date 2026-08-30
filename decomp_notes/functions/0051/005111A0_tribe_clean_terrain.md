# Function notes: 005111A0 `tribe_clean_terrain`

Module notes: `decomp_notes/tmap_module.md`.

## Recovered attempt history

<!-- recovered:0c218a0557c86735fd49 -->
### `target-session` `build/target_sessions/005111A0_tribe_clean_terrain.json:1-37`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1291; shape=69.0978886756238: Baseline current scratch source; establish exact metrics and call/frame alignment.
probe 2 control-flow; result=MISMATCH; diff=1291; shape=69.28982725527831: Hypothesis 1: replace guarded do/while inner scan with canonical pointer-plus-index for loop, matching exact RGE_Map clean_terrain donor loop form.
probe 3 control-flow; result=MISMATCH; diff=1417; shape=56.35673624288425: Hypothesis 2: model decompiler-proven independent current row/column locals, parameter-bound resets, and nested guarded do-loops instead of direct for bounds.
probe 5 liveness; result=MISMATCH; diff=1432; shape=61.036468330134355: Hypothesis 3: introduce decompiler-supported independent col_start/row_start/end_x/end_y locals while retaining baseline guarded inner loop, syncing bounds back to parameters.
probe 8 liveness; result=MISMATCH; diff=1478; shape=61.228406909788866: Hypothesis 4: keep only decompiler-supported independent end_x/end_y loop bounds, syncing expanded values to original parameter homes.
probe 10 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 5: move width and neighbor-offset declarations before tile/flag declarations, following the exact RGE_Map donor and decompiler local ordering. [same emitted code as probe 1]
probe 12 control-flow; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 6: express the two-pass loop as a natural do/while counter, matching the original late increment and less-than-two backedge. [same emitted code as probe 10]
probe 14 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 7: scope tile to one row scan, matching the exact donor's row-local tile ownership and reducing cross-row lifetime. [same emitted code as probe 12]
probe 16 liveness; result=MISMATCH; diff=1292; shape=68.90595009596929: Hypothesis 9: reorder neighbor locals and zeroing to decompiler allocation order, placing upper_left first as the original BX-held predicate.
probe 18 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 10 diagnostic only: apply register storage to mutable x2 to test whether the original EBX-held end bound is a source-color basin; do not retain without stronger evidence. [same emitted code as probe 14]
probe 20 context; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 11: use implicit period C++ member expressions for map width, height, and row table, matching exact tmap donor spelling. [same emitted code as probe 18]
probe 22 control-flow; result=MISMATCH; diff=1207; shape=67.94625719769674: Hypothesis 12: express the row scan as a guarded do/while with explicit y increment, matching the original row-loop block layout.
probe 23 liveness; result=MISMATCH; diff=1207; shape=67.94625719769674: Hypothesis 13: move the row induction variable to function scope before clamps, so VC5 can preload y1 in the original early register band. [same emitted code as probe 22]
probe 24 liveness; result=MISMATCH; diff=1207; shape=67.94625719769674: Hypothesis 14: move the column induction variable to function scope before clamps, matching decompiler current-column lifetime and testing earlier x1 preload. [same emitted code as probe 23]
probe 25 liveness; result=MISMATCH; diff=1207; shape=67.94625719769674: Hypothesis 15: initialize the function-scope row variable immediately after y1 clamp, testing whether the original early y1 load is source-visible. [same emitted code as probe 24]
probe 27 abi; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 16: use the reviewed RGE_Game_World pointer type for game_world and the six-argument set_terrain receiver, matching decompiler ownership.
probe 29 liveness; result=MISMATCH; diff=1291; shape=69.28982725527831: Hypothesis 17: order neighbor locals and zeroing by first orthogonal use (north, south, west, east), then diagonal groups.
probe 31 liveness; result=MISMATCH; diff=1349; shape=63.531669865642996: Hypothesis 18: name the decompiler-proven row byte offset (x1 multiplied by 24) and use it in row-table tile setup.
probe 33 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 19: reverse row-pointer addition order to x plus row table, testing the exact donor's address-expression basin. [same emitted code as probe 20]
probe 35 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 20: scope the eight neighbor flags inside the non-water tile block, matching the exact donor's natural local lifetime. [same emitted code as probe 33]
probe 38 abi; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 1: use int coordinate parameters, matching the exact RGE clean_terrain donor declaration and ABI candidate.
probe 40 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 2: declare the eight neighbor flags before the tile cursor, following Ghidra's local order so upper_left can occupy EBX and tile can spill. [same emitted code as probe 37]
probe 42 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 3: qualify upper_left as register, testing the binary-proven EBX-held upper_left predicate without changing behavior. [same emitted code as probe 40]
probe 44 abi; result=MISMATCH; diff=1374; shape=56.630824372759854: Hypothesis 4: use binary-decompiler bool flag types for all eight neighbors, testing whether VC5's bool lowering recovers the original flag homes.
probe 46 control-flow; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 5: scope the tile cursor inside each row, matching the exact RGE clean_terrain donor's natural row-local declaration and testing the original spill topology. [same emitted code as probe 42]
probe 48 liveness; result=MISMATCH; diff=1291; shape=69.28982725527831: Hypothesis 6: order neighbor zeroing as up, upper_right, left, lower_left, down, lower_right, right, upper_left, matching original zero-store order.
probe 50 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 7: use the decompiler's semantic local order: upper_left, up, down, right, left, upper_right, lower_left, lower_right, then tile. [same emitted code as probe 46]
probe 52 layout; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 8: use a proven byte cursor at tile stride 24 with terrain offset 5, matching the original's raw cursor address topology. [same emitted code as probe 50]
probe 54 control-flow; result=MISMATCH; diff=1291; shape=69.28982725527831: Hypothesis 9: reverse the two cardinal conjunction operands to test whether VC5 preserves the target's up-then-down and left-then-right compare order.
probe 56 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 10: make place a function-scope local, matching the decompiler's function-scope bVar2 and testing its effect on upper_left and tile allocation. [same emitted code as probe 52]
probe 58 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 11: retain a row base before forming tile, testing whether a natural row-pointer local recreates the original spilled tile and EBX end-bound topology. [same emitted code as probe 56]
probe 60 liveness; result=MISMATCH; diff=1291; shape=69.28982725527831: Hypothesis 12: combine the decompiler local declaration order with the target's observed zero-store order. [same emitted code as probe 48]
probe 62 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 13: declare change_flag after tile, neighbor, and offset locals, matching the decompiler local listing. [same emitted code as probe 58]
probe 64 control-flow; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 14: initialize tile from row plus x1, matching the exact RGE donor and original row setup before the independent column cursor. [same emitted code as probe 62]
probe 66 control-flow; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 15: use the exact donor's natural for-column loop with tile and x updates in the increment clause. [same emitted code as probe 64]
probe 68 liveness; result=MISMATCH; diff=1291; shape=69.0978886756238: Hypothesis 16: qualify y2 as register, testing the original ECX-held y2 allocation against the natural source. [same emitted code as probe 66]
probe 72 baseline; result=MISMATCH; diff=1291; shape=69.0978886756238: Fresh Phase 4 baseline after prior-results review; authentic tmap.cpp wrapper and exact-size predicate source retained. [same emitted code as probe 71]
```
<!-- end-recovered:0c218a0557c86735fd49 -->

<!-- recovered:824daed2db49dfa273eb -->
### `7219a9ef8fce` `src/scratch/005111A0_tribe_clean_terrain.cpp:1-44`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 005111A0 TRIBE_Map::tribe_clean_terrain
// Attempt log:
// try 1: direct behavioral skeleton from packet: clamp/expand brush rect, scan neighbor passability, place terrain around edges, redraw/final cleanup; default /O2 too small (.text 1392 vs 1562).
// try 2: /GX no change from try 1; rolled back.
// try 3: /Od exact-size comparable but debug-basin broad mismatch: 93.8540% positional / 154.0333% edit, first mismatch prologue; rolled back.
// try 4: /O1 too small (.text 1179); rolled back.
// try 5: /O2 without /Oy no change from default; rolled back.
// left in scratch: no custom flags retained. Not accepted_drift quality; likely needs exact original nested condition topology and real TRIBE_Map/terrain helper declarations; current skeleton captures main behavior but not VC5 local/register/frame shape.
//
// sa-e4d7ed85-111a0 baseline: model the RGE_Map row table as 0x18-byte tiles,
// use terrain byte +5 and water/do_terrain_brush_check/set_terrain helper ABIs,
// and use the decorated four-long/two-uchar parameter ABI.
// probe: function-scope tile/neighbor locals and packet-derived short offset order did not change the initial basin.
// probe: executable bVar placement predicates (two straight passes plus four staged diagonal tests) recovered 178 bytes and brought the emitted size to 1570 vs 1562; all 21 calls and the 0x44 frame align.
// probe: long loop cursors and register qualifications were codegen duplicates.
// probe: grouped the diagonal water checks under top/bottom row guards from the packet; size 1562 and first mismatch moved to 005111F9.
// new-worker probe: matched the exact RGE_Map::clean_terrain donor's nested int row/column loops,
// tile-before-column increment, and compass local order; size stayed 1562, resync drift worsened, restored.
// new-worker probe: initialized the packet's BX-held upper-left predicate before the stack flags; no structural gain, restored.
// left in scratch: remaining drift is the VC5 local/register basin and loop/prologue topology; current source keeps the named tile/neighbor ownership and executable predicate structure.
// luna-r2 lead: a guarded row do-loop reproduced the oracle's spilled tile cursor,
// BX-held upper-left flag, and several long exact islands; it grew to 1570 bytes
// with a 0x40 frame and 1423 positional bytes, so the exact-size row-for source remains best.
// luna-r2 negative: register x2/y2, row-offset aliases, tile scope, and orthogonal operand order were codegen duplicates.
// managed sa-e986718e pass: 20 measured hypotheses, all restored to this clean source.
// The nested current-row/current-column model followed the decompiler but grew the frame
// and worsened shape. A guarded row do-loop kept exact size and improved positional diff
// to 1207 bytes, but lost shape and the early exact prologue; it was not retained.
// Independent bound aliases, declaration orders, scoped locals, ABI pointer spelling,
// register storage, member spelling, row-offset locals, and address-expression order
// were duplicates or worse. Calls, frame, CFG counts, and boundary remain aligned;
// the open blocker is the EBX tile/end-bound allocation and related flag homes.
// sa-7e83054e-r1 fresh context gate: module tmap.cpp, source band 1091-1270,
// owner TRIBE_Map, address sequence follows 005110E0, with exact wrapper
// anchors 00510C90 and 00511000 before this owner. Fresh original assembly
// proves the 0x44 frame, 21 ordered calls, and tile row-slot sequence. The
// current exact-size predicate source remains authoritative; no rejected row,
// alias, or register-steering form was repeated in this pass.
// sa-11e4b4c9-r1 captain validation: the fresh dossier confirms module tmap.cpp,
// band 1091-1270, TRIBE_Map ownership, and the address sequence above. Wrapper
// anchors remain exact. Baseline is 1558 rebuilt bytes versus 1562, with 1291
// strict differing bytes and 21 ordered calls. The clean source is restored;
// the EBX tile/end-bound allocation and predicate control-flow basin remain
// unresolved.
```
<!-- end-recovered:824daed2db49dfa273eb -->
