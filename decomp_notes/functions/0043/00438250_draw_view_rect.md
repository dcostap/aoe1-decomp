# Function notes: 00438250 `draw_view_rect`

Module notes: `decomp_notes/diam_map_module.md`.

## Recovered attempt history

<!-- recovered:6582dfc57f53d80310af -->
### `target-session` `build/target_sessions/00438250_draw_view_rect.json:1-26`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=548; shape=80.56872037914692: Clean scratch baseline before new hypotheses; establish current metrics.
probe 2 liveness; result=MISMATCH; diff=548; shape=80.56872037914692: H2: model converted view_y as a short local, matching binary word comparisons and stack dword home. [same emitted code as probe 1]
probe 4 layout; result=MISMATCH; diff=548; shape=80.56872037914692: H3: mirror exact draw_tile donor tile-row index form, with post-index decrement. [same emitted code as probe 2]
probe 6 behavior; result=MISMATCH; diff=548; shape=80.56872037914692: H4: use direct map_wid and player view expressions in the tile-row index, following original two conversion sites. [same emitted code as probe 4]
probe 7 context; result=MISMATCH; diff=548; shape=80.56872037914692: H5: restore the complete known TPanel virtual surface from the same-TU exact donor, without changing fields. [same emitted code as probe 6]
probe 9 layout; result=MISMATCH; diff=666; shape=90.38461538461539: H6: use binary-supported narrow short x/y coordinate locals, matching original low-word register use before FPU conversion.
probe 11 layout; result=MISMATCH; diff=564; shape=81.99052132701422: H7: narrow only the x projection while retaining long y, testing the original DI x register and float conversion path.
probe 13 layout; result=MISMATCH; diff=642; shape=88.51674641148325: H8: narrow only the y projection while retaining long x, testing original EBX y low-word use.
probe 15 control-flow; result=MISMATCH; diff=548; shape=80.56872037914692: H9: use direct view_rect.bottom reads in the scan guard, endpoint test, and backedge. [same emitted code as probe 7]
probe 17 control-flow; result=MISMATCH; diff=548; shape=80.56872037914692: H10: express the image-row bounds as a positive conjunction instead of a negated disjunction. [same emitted code as probe 15]
probe 19 liveness; result=MISMATCH; diff=548; shape=80.56872037914692: H11: split initial view coordinate declarations from assignments to test source lifetime and initialization-site effects. [same emitted code as probe 17]
probe 21 liveness; result=MISMATCH; diff=558; shape=79.62085308056872: H12: reverse the declaration order of the two initial converted view coordinates.
probe 23 behavior; result=MISMATCH; diff=548; shape=77.72511848341232: H13: reverse ratio guard and arm order to match original fld ratio; fcomp DAT; JE draw-step topology.
probe 25 behavior; result=MISMATCH; diff=659; shape=78.30188679245283: H14: spell the ratio guard as DAT <= row->ratio, retaining draw-step success arm.
probe 27 liveness; result=MISMATCH; diff=548; shape=79.62085308056872: H15: cache the proven tile-row ratio in a typed float local before the threshold test.
probe 29 behavior; result=MISMATCH; diff=659; shape=78.77358490566037: H16: reverse the ratio comparison operands as DAT > row->ratio while preserving strict behavior.
probe 31 abi; result=MISMATCH; diff=659; shape=80.66037735849056: H17: use the reviewed period global declaration DAT_0056f604 instead of an absolute macro, following same-TU donor evidence.
probe 33 layout; result=MISMATCH; diff=548; shape=80.56872037914692: H18: represent the proven tile-row lvalue as a typed reference instead of a pointer. [same emitted code as probe 19]
probe 35 variant; result=MISMATCH; diff=548; shape=80.56872037914692: variant lab build\variant_lab\00438250_draw_view_rect\20260817_131618: 64 variants, 64 invariant-eligible, 0 exact
probe 38 control-flow; result=MISMATCH; diff=548; shape=80.56872037914692: H20: spell map bounds in original member-left form, map_width <= view_x and map_height <= view_y. [same emitted code as probe 33]
probe 39 control-flow; result=MISMATCH; diff=548; shape=79.14691943127963: H20 actual: spell map bounds in original member-left form, map_width <= view_x and map_height <= view_y.
probe 43 liveness; result=MISMATCH; diff=548; shape=80.56872037914692: H21: add the PDB-proven but decompiler-unmapped short vwid local at function scope; test whether original local declaration context causes the spilled second coordinate home. [same emitted code as probe 42]
probe 45 variant; result=MISMATCH; diff=548; shape=80.56872037914692: variant lab build\variant_lab\00438250_draw_view_rect\20260822_142015: 8 variants, 8 invariant-eligible, 0 exact
probe 46 liveness; result=MISMATCH; diff=667; shape=79.22705314009661: H22: remove the named second coordinate local and repeat the natural player-view conversion expressions; test whether VC5 forms the original spilled conversion temporary.
probe 48 layout; result=MISMATCH; diff=548; shape=80.56872037914692: H23: use period-natural implicit float-to-short/long initialization for the two initial view coordinates; test whether explicit double casts select the wrong VC5 lowering basin. [same emitted code as probe 43]
probe 50 liveness; result=MISMATCH; diff=669; shape=76.88679245283019: H24: move the two get_max_size output locals to function scope, matching the PDB local-symbol scope; test declaration lifetime effects on the first coordinate spill.
```
<!-- end-recovered:6582dfc57f53d80310af -->

<!-- recovered:ca0241e91db173b9a0e0 -->
### `5c06e112e88d` `src/scratch/00438250_draw_view_rect.cpp:1-36`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00438250 RGE_Diamond_Map::draw_view_rect (diam_map.cpp:1206-1310)
// Natural reconstruction of the diamond-map viewport outline.
// Attempt log (bf16-diam-8250, bounded 10-probe pass):
// - Typed DMap/player/map/view reconstruction established all 13 calls,
//   exact 0x10 frame, viewport formulas, and clipped endpoint/horizontal-line
//   drawing. Initial candidate was exact-size with 73.93% shape similarity.
// - Fractional-first ratio spelling, negative loop guards, nested line-clipping
//   comparisons, sequential map bounds, and the signed vhgt / 2 formula moved
//   the best reconstruction to 80.57% shape and 548 differing bytes.
// - The remaining drift is chiefly the second view-coordinate local home,
//   register coloring, x87/local scheduling, and expression operand order.
//   A player-pointer CSE variant deleted one required ftol and was rolled back;
//   a 16-bit coordinate-lifetime variant crossed the exact function boundary
//   and was rolled back. Left in scratch after the bounded pass.
// - Re-tested a natural typed player-pointer local across coordinate recomputation;
//   it deleted one ftol and worsened the first hunk, so the clean direct-access
//   reconstruction remains preferred.
// - This pass tested declaration/initialization splits, narrow/full coordinate
//   locals, function-scope map/tile locals, and explicit panel-x loads. These
//   forms were codegen duplicates or worsened structure; no new source-backed
//   lead displaced the clean direct-access reconstruction.
// Second pass (sa-e73ff662, 21 recorded probes plus one lab family):
// - The short view-y local, draw_tile-style tile-row index, full TPanel surface,
//   direct bottom reads, positive image bounds, split initializations, and a
//   tile-row reference were codegen duplicates.
// - Narrow x/y locals changed the frame or worsened positional drift. Reversed
//   coordinate declaration order also worsened the first load order.
// - Ratio guard operand and arm variants changed CFG or worsened shape. The
//   reviewed external DAT_0056f604 declaration recovered one-level fcomp, but
//   it added a relocation/call-set mismatch, so the absolute target form stays.
// - The reviewed global header could not compile because it redefined tagRECT.
//   Member-left map bounds worsened shape without changing size or calls.
// - A 64-sample ambient declaration lab produced two codegen groups, both with
//   the same first mismatch and no exact result. Clean direct access remains.
// - Current claim: narrowing local_8 to short was codegen-identical. The long
//   local and direct-coordinate source remain authoritative.
```
<!-- end-recovered:ca0241e91db173b9a0e0 -->
