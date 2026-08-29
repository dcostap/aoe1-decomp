# Recovery journal: 004C4680 `teleport`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/stat_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\stat_obj.cpp`.
- Earlier recovery note: `recovery_notes/stat_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:a49926da20921858cd78 -->
### `d050eea3c` `src/stat_obj.cpp:1726-1727`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004C4680 RGE_Static_Object::teleport
// BINARY NOTE: teleport uses the canonical named terrain methods.
```
<!-- end-recovered:a49926da20921858cd78 -->

<!-- recovered:814dfadeacc3d566d37a -->
### `d050eea3c` `src/stat_obj.cpp:1751-1751`

Mapping: `strong`. comment lies after mapped function teleport at old line 1723.

```text
    // BINARY NOTE: The upper-bound loads come directly from map width and height.
```
<!-- end-recovered:814dfadeacc3d566d37a -->

<!-- recovered:5e4ed343699d136a851a -->
### `target-session` `build/target_sessions/004C4680_teleport.json:1-26`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1199; shape=67.75818639798489: Baseline current typed reconstruction before new probes
probe 2 liveness; result=MISMATCH; diff=1199; shape=67.75818639798489: H1 join result declaration and ZERO_F initialization to test early spill timing [same emitted code as probe 1]
probe 3 context; result=MISMATCH; diff=1212; shape=65.65656565656566: H2 use original double-zero and float zero/one data symbols instead of compiler literals
probe 5 liveness; result=MISMATCH; diff=1239; shape=50.25125628140704: H3 scope result after inside guard and return ZERO_F directly, testing original preloaded zero lifetime
probe 7 control-flow; result=MISMATCH; diff=1117; shape=69.52141057934509: H4 keep top result lifetime but return ZERO_F directly to test inline early return block
probe 8 liveness; result=MISMATCH; diff=1223; shape=46.09375: H5 volatile result to force original early stack spill ordering
probe 10 control-flow; result=MISMATCH; diff=1117; shape=69.52141057934509: H6 keep top result but use literal 0.0f for inside early return
probe 12 liveness; result=MISMATCH; diff=1117; shape=69.52141057934509: H7 name owner as a player local before result/map initialization to test source evaluation order
probe 13 control-flow; result=MISMATCH; diff=1117; shape=69.52141057934509: H8 move map initialization before result assignment to test compiler scheduling order [same emitted code as probe 12]
probe 14 context; result=MISMATCH; diff=1119; shape=67.42424242424242: H9 use only proven float ZERO_F/ONE_F symbols for clamp and tile formulas
probe 16 control-flow; result=MISMATCH; diff=802; shape=71.53652392947103: H10 put coordinate on left of upper-bound clamp comparisons to recover fcomp stack order
probe 17 liveness; result=MISMATCH; diff=802; shape=68.26196473551637: H12 swap fractional-local declaration order to test original shared [esp+14] home
probe 18 liveness; result=MISMATCH; diff=802; shape=68.26196473551637: H13 swap tile-index declaration order to test width/height temporary-home coalescing [same emitted code as probe 17]
probe 19 control-flow; result=MISMATCH; diff=802; shape=68.26196473551637: H14 split upper clamp into assignment then compound subtraction to test direct fsub memory form [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=1243; shape=47.67726161369193: H15 reuse coordinate parameter home as the switch result and return value
probe 22 control-flow; result=MISMATCH; diff=802; shape=71.53652392947103: H16 reverse sum operand order to match original rz-then-rx loads in switch and offsets [same emitted code as probe 16]
probe 23 context; result=MISMATCH; diff=802; shape=71.53652392947103: H17 use ONE_F only for switch result arithmetic while retaining literal threshold predicates
probe 24 control-flow; result=MISMATCH; diff=819; shape=72.544080604534: H18 reverse sum threshold predicate operands to test fcomp versus fcompp and branch polarity
probe 25 liveness; result=MISMATCH; diff=802; shape=71.53652392947103: H19 scoped named case sums to test retained x87 temporary versus direct compare
probe 26 abi; result=MISMATCH; diff=814; shape=71.78841309823677: H20 widen movement_type local to int to match original zero-extend and sub/dec dispatch
probe 28 context; result=MISMATCH; diff=1173; shape=70.85427135678393: H21 use an absolute double-zero data macro for both radius tests
probe 29 layout; result=MISMATCH; diff=800; shape=72.04030226700252: H22 use direct map width/height expressions for upper clamps, then initialize integer indices
probe 30 control-flow; result=MISMATCH; diff=800; shape=72.04030226700252: H23 split direct-map upper clamp into assignment plus compound subtraction [same emitted code as probe 29]
probe 31 layout; result=MISMATCH; diff=815; shape=72.544080604534: H24 read tile elevation through this->tile, as proven by original +2345 load
probe 32 liveness; result=MISMATCH; diff=815; shape=72.544080604534: H25 name current tile before master and movement to test original post-switch load order
probe 33 liveness; result=MISMATCH; diff=804; shape=72.04030226700252: H26 evaluate tile-level addition before declaring master and movement locals
```
<!-- end-recovered:5e4ed343699d136a851a -->

<!-- recovered:064052e99eafacba4caa -->
### `912332e8f578` `src/scratch/004C4680_teleport.cpp:1-27`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C4680 RGE_Static_Object::teleport(float, float, float)
// PDB: stat_obj.cpp:2105-2373
// Attempt log:
// - The packet's initial scratch used a reduced tile-shape switch and helper
//   shims; it was 409 bytes short and had direct add/remove/update calls.
// - Current pass restores the typed RGE world/map/tile/object-list ownership,
//   the 17-case switch, parameter-home coordinate clamps, and vslot D8/DC
//   terrain calls from the executable's original control flow.
// - Canonical typed calls align all 12 call sites and full switch/terrain
//   behavior; natural double-zero comparison improved the FPU shape.
// - Volatile-result and parameter-home/goto diagnostics were rolled back; the
//   remaining structural lead is the original zero-temporary spill and VC5
//   switch block placement (best rebuilt size 1208 vs 1285).
// - Kept one typed result initialized at entry for the early return and switch
//   default; the original zero spill supports this lifetime, but VC5 emitted
//   the same code (no positional gain, edit/resync 45.84%).
// - Leaving the initialized result unchanged in switch default produced the
//   binary frame/size (0x10 / 1285) and raised shape to 67.76%; keep this
//   natural default path while the entry block and FPU switch still drift.
// - Inverted-guard, declaration-order, global-constant, and constant-left
//   predicate variants did not improve the 1199-byte structural best.
// - A direct zero return restores the original nearby return block. Coordinate-left
//   upper clamps restore the original x87 compare and improve the body by 397 bytes.
// - Direct map width/height expressions preserve the original map-bound load basin;
//   temporary width/height locals produce the wrong fsubr form.
// - The cleanest current source is 800-byte strict diff, 72.04% shape, and 46.72%
//   exact-block coverage. Calls remain 12/12 and frame remains 0x10.
```
<!-- end-recovered:064052e99eafacba4caa -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
