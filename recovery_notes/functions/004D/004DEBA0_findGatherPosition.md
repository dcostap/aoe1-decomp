# Recovery journal: 004DEBA0 `findGatherPosition`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:621fe96613e23c352f7e -->
### `target-session` `build/target_sessions/004DEBA0_findGatherPosition.json:1-29`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=647; shape=74.31906614785993: Baseline current clean natural reconstruction: typed XYPoint and virtual ABI, 11-call set, but frame 0x50 versus original 0x54 and 647 differing bytes.
probe 2 layout; result=MISMATCH; diff=647; shape=74.31906614785993: Hypothesis 1: match Ghidra/PDB local declaration order by declaring scalar loop state before the eight XYPoint locals; tests whether VC5 frame and point stack homes follow source declaration order. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=647; shape=74.31906614785993: Hypothesis 2: make the score accumulator a function-scope local instead of a block declaration; PDB has separate score initialization and later update bands, so test whether its lifetime crosses the virtual call and changes frame/register pressure. [same emitted code as probe 2]
probe 6 liveness; result=MISMATCH; diff=701; shape=73.92996108949416: Hypothesis 3: initialize bestPointValue at declaration instead of at the post-setup site; tests whether the original -1 home is an early declaration initialization rather than a later assignment.
probe 8 control-flow; result=MISMATCH; diff=647; shape=74.31906614785993: Hypothesis 4: use explicit while loops with visible initialization and updates for the canPlace scan; original PDB has separate loop-init/update bands, so test while topology against the current for/do form. [same emitted code as probe 4]
probe 10 control-flow; result=MISMATCH; diff=613; shape=71.53846153846153: Hypothesis 5: spell the inclusive influence-value scan as explicit guarded do/while loops, reflecting the PDB's separate 4915/4916 bands and original inclusive bounds.
probe 12 control-flow; result=MISMATCH; diff=647; shape=72.76264591439688: Hypothesis 6: express the exclusion test as negated positive in-box conjunction rather than an outside OR chain; it tests whether VC5 preserves the observed comparison order and branch topology.
probe 14 abi; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 7: use the repository-local canonical RGE_Static_Object virtual surface, with passableTile at 0x114 and canLinePath at 0x1B0, instead of fake generic slots; this is the policy-valid ABI test.
probe 15 abi; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 8: rename the second virtual call to the reviewed canonical canLinePath surface at vslot 0x1B0, preserving its exact five-argument typed signature; tests whether source method identity changes VC5 lowering.
probe 16 abi; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 9: keep the reviewed slot count but disambiguate the unused integer can-line overload by a local distinct declaration name, testing whether VC5 overload lookup was selecting 0x1AC instead of the exact XYPoint overload at 0x1B0. [same emitted code as probe 14]
probe 17 abi; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 10: use the exact-donor local ABI spelling void* for the unused canLinePath pointer parameters while restoring the canonical overload name; tests whether VC5 overload resolution needs the period donor's incomplete pointer surface. [same emitted code as probe 15]
probe 18 liveness; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 11: preserve minDistance through the candidate block in a named collisionDistance local before canLinePath; tests whether the original four-byte frame slot is a real call-crossing distance temporary. [same emitted code as probe 16]
probe 19 abi; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 12: retain both canonical canLinePath overload names but give the unused integer overload a default final argument; tests whether VC5 then selects the exact five-argument XYPoint overload at 0x1B0 without a local renamed method. [same emitted code as probe 17]
probe 20 layout; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 13: swap max/maxClear and min/minClear declaration order to match the binary's inferred local addresses: original places min and max eight bytes above the current homes while exclusion points stay fixed. [same emitted code as probe 18]
probe 21 layout; result=MISMATCH; diff=425; shape=75.2895752895753: Hypothesis 14: follow the decompiler/PDB assignment order for the first two point pairs, writing minExclude.x before min.y and minClear.x before max.y; tests independent-store scheduling without aliases or forced ordering.
probe 23 liveness; result=MISMATCH; diff=414; shape=77.34375: Hypothesis 15: use the decompiler's boolean blocked type with the canonical virtual surface; prior generic-surface evidence was negative, so retest whether real ABI context changes bool storage and frame behavior.
probe 25 liveness; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 16: hoist the influence lookup result into a function-scope int; PDB separates lookup, compare, and accumulator-update bands, so test whether a persistent result local changes the one-dword frame basin. [same emitted code as probe 22]
probe 27 liveness; result=MISMATCH; diff=427; shape=76.06177606177606: Hypothesis 17: assign maxClear.x from groupInfluenceDimension before initializing bestPointValue; tests the PDB 4842 order and whether the sentinel store schedules after the call.
probe 29 variant; result=MISMATCH; diff=427; shape=76.06177606177606: variant lab build\variant_lab\004DEBA0_findGatherPosition\20260817_132241: 2 variants, 2 invariant-eligible, 0 exact
probe 30 liveness; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 18: reverse cPosition.y and lineCollisionPoint.x source assignment order before canLinePath; original emits cPosition store before line-point store around line 4906, so test whether VC5 independent-store scheduling follows source order. [same emitted code as probe 25]
probe 34 layout; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 19: use the exact Ghidra/PDB local declaration order maxClear, max, minClear, min, then exclusion and collision points; test whether the original 0x54 frame basin follows declaration order rather than the current max, maxClear, min, minClear order. [same emitted code as probe 33]
probe 35 liveness; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 20: scope lineCollisionPoint inside the successful candidate arm, where PDB line band 4906 first uses it; test whether shorter address-taken lifetime recovers the original point homes and 0x54 frame. [same emitted code as probe 34]
probe 36 context; result=MISMATCH; diff=647; shape=74.70817120622569: Hypothesis 21: restore the same-TU period context with the math.h header used by nearby taiinfmd.cpp donors; test whether VC5 front-end state changes the sticky 0x50 versus 0x54 frame basin.
probe 37 abi; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 22: use the full period polymorphic TribeInformationAIModule surface, including its virtual destructor as in exact taiinfmd.cpp donors; test whether class context changes the local frame basin without changing direct call identities. [same emitted code as probe 35]
probe 39 abi; result=MISMATCH; diff=406; shape=76.44787644787645: Hypothesis 23: use the period donor's pointer spelling for mapBound rather than the current reference spelling; test whether the exact decorated helper surface or address-taking form controls the local frame.
probe 43 liveness; result=MISMATCH; diff=406; shape=77.6470588235294: Hypothesis: reuse the first passableTile loop counters for the later influence scan, matching period nested-loop scope and reducing artificial function-scope liveness while preserving both loop bounds and ordered calls. [same emitted code as probe 42]
probe 44 layout; result=MISMATCH; diff=406; shape=77.6470588235294: Hypothesis: place exclusion points before the map-bound and clearance points, based on their persistent outer-loop use and the original early mapBound address sequence; test whether VC5 restores the 0x54 frame and point homes. [same emitted code as probe 43]
probe 45 layout; result=MISMATCH; diff=623; shape=68.75: Hypothesis: use the period taiinfmd donor's y,x XYPoint field order, which is supported by exact same-TU blotExploredMap source; leave semantic member expressions unchanged to test the canonical layout basin.
probe 46 layout; result=MISMATCH; diff=406; shape=77.6470588235294: Hypothesis: declare scalar loop and result locals before the eight XYPoint objects, following the decompiler's scalar-first local listing and testing whether this changes the VC5 stack allocation basin. [same emitted code as probe 44]
```
<!-- end-recovered:621fe96613e23c352f7e -->

<!-- recovered:740351ef09ec984ea154 -->
### `631a27c6101f` `src/scratch/004DEBA0_findGatherPosition.cpp:1-59`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004DEBA0 TribeInformationAIModule::findGatherPosition
// Attempt log:
// 1: natural decompiler reconstruction using local XYPoint layout and raw virtual calls for object collision/line collision.
// 2: __thiscall function-pointer casts failed under VC5 C4234, replaced with cdecl raw vtable calls (asm pushes object explicitly).
// 3: first compiling attempt had the correct high-level call set and many matching arithmetic islands, but frame 0x50 vs original 0x54.
// 4: parameter order/registers mostly aligned after prologue except the min/max comparison polarity.
// 5: setupInfluenceMap/mapBound/groupInfluenceDimension were initially represented as member calls with pointer stubs.
// 6: stack-slot placement for XYPoint locals differed; early mapBound locals landed at [esp+30]/[esp+20] instead of original [esp+3C]/[esp+2C].
// 7: exclusion-box predicate compiled behaviorally but used register-left comparisons instead of the original memory-left form.
// 8: object virtual collision and line collision calls use observed vtable slots +0x114/+0x1B0 and float push order.
// 9: no inline asm or custom flags tried.
// 10: retained in scratch; the remaining mismatch is source/layout/codegen, not accepted drift.
// Session sa24955f58r1:
// - typed the two object vtable calls as __thiscall virtual methods; this removed caller cleanup and matched the observed indirect-call ABI.
// - changed mapBound/setupInfluenceMap to XYPoint-reference declarations, restoring the original decorated direct-call identities.
// - `maxDistance >= minDistance` reproduces the initial cmp edi,esi/jl guard; memory-left exclusion predicates reproduce two oracle blocks.
// - XYPoint y,x layout, scalar/point declaration reorderings, and same-TU nonvirtual object declarations did not resolve the frame/local basin.
// - bool blocked was tested and rolled back: it removed the one-byte size overflow but worsened the codegen basin.
// - explicit outer do/while scans were tested from the repeated PDB loop bands; VC5 emitted the same bytes as the clean for-loop source, so no new lead was found.
// - PDB declaration-order and first-bound assignment-order probes were codegen-neutral or worse; both were rolled back.
// - field-address mapBound/setup/lineCollision casts improved edit resync but kept the 0x50 frame and 647-byte positional diff; the casts were rolled back as decompiler-shaped.
// Best retained reconstruction: typed virtual/reference ABI and natural nested scans with named XYPoint ownership; frame remains 0x50 vs 0x54.
// The explicit outer do/while spelling was tested and emitted the same code as
// the clean for-loop source. The source stays with the simpler natural form.
//
// Current pass sa-d3dbc29b-r1:
// - Baseline was 746 bytes, frame 0x50 versus 0x54, 11 aligned calls, diff 647.
// - Scalar-before-point declarations and point declaration permutations were
//   codegen-neutral. Function-scope score and lookup temporaries were neutral.
// - Early best-value initialization worsened the diff to 701 bytes.
// - Explicit while scans were duplicate. Guarded do/while influence scans made
//   the body 754 bytes; the strict diff fell to 613 but CFG and size worsened.
// - A negated in-box conjunction worsened shape and exact-block coverage.
// - Replaced fake object slots with the repository-local RGE_Static_Object
//   surface. Real passableTile and canLinePath slots reduced the diff to 406
//   bytes and restored the 745-byte size and all 11 ordered calls.
// - VC5 selected slot 0x1AC when both old canLinePath overloads had that name.
//   The local six-argument slot name canLinePathByInts keeps the proven 0x1B0
//   XYPoint call without a cast or manual vtable. The same-name and void*
//   overload variants returned to slot 0x1AC.
// - A named collision-distance local, bool blocked, assignment-order changes,
//   and group-sentinel order did not improve the 406-byte canonical basin.
// - A two-variant declaration lab confirmed both point orders emit one 745-byte
//   group with the same 395-byte positional diff and frame 0x50.
// Current clean candidate remains scratch: diff 406 (54.4966%), shape 76.45%,
// frame 0x50 versus 0x54, 11/11 ordered calls, and no policy-valid exact match.
// Review blocker: the four-byte frame gap moves address-taken XYPoint locals
// passed to mapBound, setupInfluenceMap, and line/path calls. This changes
// external pointer values and the ESP context of all 11 calls, so the gap is
// not eligible as private local-home drift.
//
// Current pass sa-8052b5e7-r1:
// - Fresh checks retained the natural source and all 11 ordered direct/virtual
//   calls. Reusing loop counters, point declaration orders, and authentic
//   information/object field context emitted the same 0x50-frame basin.
// - The exact same-TU blotExploredMap donor's y,x point declaration was worse
//   (623-byte diff) and was restored. It is not the target's proven layout.
// - The remaining 0x50 versus 0x54 gap remains a real address-taken local
//   topology blocker, not padding or private local-home drift.
```
<!-- end-recovered:740351ef09ec984ea154 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
