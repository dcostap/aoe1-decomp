# Function notes: 00404DB0 `set_state`

Module notes: `decomp_notes/act_misl_migration.md`.

## Recovered attempt history

<!-- recovered:f4645a3bd69d6d3a81f5 -->
### `d050eea3c` `src/act_misl.cpp:76-76`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// VA: 00404DB0 RGE_Action_Missile::set_state (805 bytes)
```
<!-- end-recovered:f4645a3bd69d6d3a81f5 -->

<!-- recovered:10b752a1171798009332 -->
### `target-session` `build/target_sessions/00404DB0_set_state.json:1-51`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=436; shape=86.71875: Baseline clean reconstruction: 805-byte frame and 12-call topology match; 436 positional bytes differ, with first structural drift in guided FPU locals and extra cleanup.
probe 2 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 1: reverse target_vy/target_vx declaration order to test whether VC5 assigns original cosine/sine stack homes by declaration order. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=439; shape=84.375: Hypothesis 2: name target_x and target_y intermediate sums before the guided distance to test whether real source temporaries recover the original [esp+18]/[esp+1C] FPU homes.
probe 7 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 3: reverse multiplication operand order for cosine/sine velocity terms to test source expression order without changing calls or types. [same emitted code as probe 2]
probe 9 layout; result=MISMATCH; diff=747; shape=63.03501945525292: Hypothesis 4: bind the missile master once at the start of state 3 and use its typed fields throughout, testing pointer lifetime and reload topology.
probe 11 liveness; result=MISMATCH; diff=435; shape=85.9375: Hypothesis 5: reverse ballistic field assignment order to test whether source store order controls the original [this+50] then [this+4C] sequence and stack temp reuse.
probe 13 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 6: move time and acceleration declarations to function scope before guided locals, testing declaration order and lifetime effects on VC5 stack-home reuse.
probe 15 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 7: declare target_distance inside the guided positive arm immediately before its assignment, testing narrower lifetime and frame/home allocation. [same emitted code as probe 7]
probe 17 control-flow; result=MISMATCH; diff=424; shape=85.546875: Hypothesis 8: reverse the guided threshold comparison operand order while preserving the predicate, testing x87 compare topology and branch polarity.
probe 19 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 9: reverse the threshold multiplication operands while keeping target_distance on the left, testing literal/load and x87 scheduling. [same emitted code as probe 15]
probe 21 liveness; result=MISMATCH; diff=526; shape=64.61538461538461: Hypothesis 10: cache target_obj in a typed local across guided getters, testing whether the original reloads are source-member access or compiler scheduling.
probe 23 layout; result=MISMATCH; diff=739; shape=67.56756756756756: Hypothesis 11: use a guided-only typed master local, separating its lifetime from the missile switch and ballistic master to test local scope effects.
probe 25 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 12: split target_distance into subtraction then compound addition of master speed, testing whether source statement boundaries delay the master-speed load to the original x87 position. [same emitted code as probe 19]
probe 26 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 13: build target_distance with initialized speed and compound subtraction before adding master speed, testing VC5 compound-assignment lowering. [same emitted code as probe 25]
probe 28 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 14: make target_distance hold only the guided square-root result, then form speed-minus-distance-plus-master in the guard and scale, following PDB line-137/138 boundaries and original FPU stores.
probe 29 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 15: combine the sqrt-only target_distance model with reversed target_vy/target_vx declaration order, testing whether the improved FPU topology then gets original cosine/sine homes. [same emitted code as probe 28]
probe 30 liveness; result=MISMATCH; diff=434; shape=85.9375: Hypothesis 16: remove the named target_distance and repeat the same sqrt expression in the guard and scale, testing VC5 common-subexpression handling and temporary-home reuse.
probe 32 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Restore improved hypothesis 14 after direct-expression probe: retain sqrt-only target_distance and explicit speed-minus-distance-plus-master guard/scale. [same emitted code as probe 29]
probe 33 liveness; result=MISMATCH; diff=415; shape=87.05882352941177: Hypothesis 17: after sqrt-only target_distance, mutate it through speed subtraction and master-speed addition before the guard, testing source statement boundaries for the delayed original load.
probe 34 liveness; result=MISMATCH; diff=443; shape=87.05882352941177: Hypothesis 18: keep sqrt-only target_distance and explicit guard, but write x-term before y-term to test whether VC5 scheduling recovers the original late master-speed load.
probe 35 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 19: scope target_vx and target_vy inside the guided arm, matching their PDB-local use and testing home/color allocation against the original cosine/sine slots. [same emitted code as probe 32]
probe 36 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 20: scope target_distance with target_vx/target_vy inside guided state, testing whether narrower lifetime allows its sqrt result to reuse the original launch-speed home. [same emitted code as probe 35]
probe 37 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 21: swap the semantic local roles of target_vx/target_vy while preserving cosine on x and sine on y, testing whether source local coloring matches original homes. [same emitted code as probe 36]
probe 38 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 22: materialize half_speed as a named float before the guided guard, testing whether an explicit threshold local reproduces the original retained half-speed x87 value.
probe 39 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 23: restore semantic guided expressions and reverse the ballistic product operands, testing x87 product order for the remaining tail spill. [same emitted code as probe 37]
probe 40 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 24: compute sqrt into target_distance, then assign one combined speed-minus-distance-plus-master expression before the guard, testing a natural single-statement mutation. [same emitted code as probe 26]
probe 41 liveness; result=MISMATCH; diff=207; shape=87.45098039215686: Hypothesis 25: reorder the guided sum to speed plus master speed minus distance, testing whether alternate natural associativity recovers VC5 x87 instruction order.
probe 42 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 26: declare target_distance before target_vx/target_vy in the guided block, testing stack-home assignment order without semantic changes. [same emitted code as probe 39]
probe 43 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 27: join target_distance declaration with its sqrt initializer after target velocity assignments, testing VC5 declaration/initialization placement. [same emitted code as probe 42]
probe 44 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 28: join target_vx and target_vy declarations with their cosine/sine initializers, testing declaration-site effects on their stack homes. [same emitted code as probe 43]
probe 45 control-flow; result=MISMATCH; diff=434; shape=85.15625: Hypothesis 29: express the equivalent guided guard as distance less than speed plus half master speed, testing a direct source predicate while retaining the original scale denominator.
probe 46 liveness; result=MISMATCH; diff=461; shape=86.66666666666667: Hypothesis 30: reverse the independent guided d/dx updates, testing whether update order selects original target velocity homes and x87 multiply order.
probe 47 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 31: scope time and acceleration inside the positive ballistics branch, testing whether natural branch-local lifetimes recover the original tail stack temporary. [same emitted code as probe 44]
probe 51 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 1: split target_vx/target_vy declarations from their initializers while retaining the natural guided threshold expression; tests whether declaration-site homes recover the original cosine spill without restoring the previously rejected metric-only operand order. [same emitted code as probe 50]
probe 52 liveness; result=MISMATCH; diff=436; shape=86.71875: Hypothesis 2: initialize one denominator local directly as speed minus the guided square root plus master speed, then reuse it for guard and scale; this follows the PDB line-138 denominator boundary and tests retention of x87 sqrt precision through the arithmetic. [same emitted code as probe 40]
probe 54 liveness; result=MISMATCH; diff=451; shape=83.13725490196079: Hypothesis 3: materialize lead_x and lead_y as named local sums before the guided square root; the original stores both sums in distinct stack homes, so this tests whether explicit source temporaries recover the observed FPU order and homes.
probe 56 liveness; result=MISMATCH; diff=212; shape=86.27450980392157: Hypothesis 4: reverse the two ballistic member assignments in source while preserving their observed final store order; tests whether the original float acceleration spill comes from source-use order rather than a metric-only temporary.
probe 58 context; result=MISMATCH; diff=495; shape=84.70588235294117: Hypothesis 5: bind the four observed ACT_misl constant-pool addresses to reviewed DAT_0056e380/388/390/394 globals instead of literal spellings; tests relocation identity and compiler treatment of shared period constants.
probe 60 context; result=MISMATCH; diff=210; shape=85.88235294117646: Hypothesis 6: use reviewed DAT constants only for original comparisons and half-speed multiplication, but keep the clamp assignment as literal 1.0f; tests constant-pool identity without the prior global-assignment scheduling regression.
probe 62 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 7: reverse branch-local target vector declaration order while preserving cosine-to-x and sine-to-y semantics; tests whether branch-local stack color differs from the previously tested function-scope order. [same emitted code as probe 51]
probe 64 liveness; result=MISMATCH; diff=452; shape=85.99221789883268: Hypothesis 8: remove the named guided-distance local and repeat the exact denominator expression, but omit explicit float casts around sqrt; tests the period intrinsic's natural promoted FPU form against the original compiler temporary.
probe 66 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 9: declare target_vx and target_vy in one declaration statement, then assign them separately; tests old VC5 front-end declaration grouping as a source-level register/home basin. [same emitted code as probe 62]
probe 69 liveness; result=MISMATCH; diff=424; shape=85.546875: Hypothesis 1: materialize the guided denominator as a post-distance lead_time local, matching the decompiler's carried float before guard and scale; tests whether source reuse recovers original fdiv and x87 topology.
probe 71 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 2: move target_vx, target_vy, and target_distance to function scope while preserving assignment sites; tests whether original PDB stack-home reuse is scope-driven rather than branch-local. [same emitted code as probe 68]
probe 73 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 3: remove only the explicit float cast from the guided square-root assignment; tests VC5 natural sqrt precision while retaining the named target-distance lifetime and all call/control anchors.
probe 75 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 4: declare the two target-vector locals before launch_speed and assign them at the existing getter lines; tests declaration-order register and stack-home coloring without changing semantics or anchors. [same emitted code as probe 71]
probe 77 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 5: reorder the function-scope intercept/vector locals to the PDB stack-variable order while retaining all expressions; tests declaration order as the remaining source of the original local-home coloring. [same emitted code as probe 75]
probe 79 context; result=MISMATCH; diff=210; shape=85.88235294117646: Hypothesis 6: bind all four observed ACT_misl constants to reviewed game globals; tests authentic relocation and constant-pool identity while preserving the natural guided and ballistic source. [same emitted code as probe 60]
probe 81 liveness; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 7: mutate the existing acceleration local after publishing ballistic_acceleration, then publish ballistic_velocity from that local; tests whether a natural two-statement local lifetime forces the original rounded stack spill. [same emitted code as probe 77]
probe 83 abi; result=MISMATCH; diff=241; shape=81.56862745098039: Hypothesis 8: use a period-plausible double guided-distance local to test whether the original extended-precision guard comes from source type rather than expression lifetime; no anchor or call changes intended.
probe 85 control-flow; result=MISMATCH; diff=210; shape=87.05882352941177: Hypothesis 9: order outer switch case 3 before case 1, matching ACT_misl PDB line order (guided body at line 107, die handler at line 197); preserves state publication, calls, and switch semantics while testing late-handler layout.
```
<!-- end-recovered:10b752a1171798009332 -->

<!-- recovered:ef3d3723887f0af8312e -->
### `ed11451d5630` `src/scratch/00404DB0_set_state.cpp:1-68`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00404DB0 RGE_Action_Missile::set_state (805 bytes)
// ACT_misl.cpp, lines 91-200
//
// Initial clean reconstruction.  The action owns the five float values at
// +0x40, while its object/master pair is the period action-object surface.
//
// Attempt log:
// - baseline: replaced the stub with typed missile/master/object ownership;
//   recovered all 12 calls, but the virtual surface was initially two slots high.
// - switched state dispatch to a natural switch and changed ballistics to a
//   positive guard; size/frame and call-site topology then matched.
// - corrected guided getters to target_obj (+0x10), not the missile obj (+0x08).
// - reversed the distance comparison for VC5's fcompp direction; declaration,
//   expression, and local-order probes did not close the remaining FPU hunk.
// - two focused variant labs (guided block and ballistic tail) found no exact
//   variant; their codegen-only winners were not retained as source.
// - final source keeps canonical vector ownership: cos contributes x+d and
//   sin contributes y+dx.  Validated best source remains in scratch: drift is
//   localized to VC5 temporary homes/FPU scheduling and the ballistic spill.
// - reordered the guided-distance terms to evaluate x+d before y+dx, matching
//   the original x87 sequence; this worsened positional diff 436 -> 448, so
//   restored the clean source.
// - block-scoped target_distance to model the packet's guided stack reuse;
//   emitted code was unchanged at diff 436, so restored the top-level local.
// - revisit: 33 evidence-led probes covered declaration scope/order, guided
//   expression grouping, typed master/target aliases, update order, and the
//   ballistic tail.  The useful change makes target_distance hold only the
//   guided square-root result, then uses speed - target_distance + master speed
//   in both the guard and scale.  This reduces positional drift to 210 bytes
//   while preserving the 0x28 frame, all 12 calls, and exact case islands.
// - direct repeated-sqrt, split-assignment, reversed-term, branch-local, and
//   threshold-local variants did not improve this result.  Keep the natural
//   float source; do not retain metric-only operand reordering.
// Review blocker: the original keeps the intercept square root in x87 extended
// precision for the lead-correction guard. The rebuild spills and reloads it
// as float first, which can change a threshold result. The ballistic tail has
// the reverse problem: the original rounds acceleration through a float stack
// home before both outputs, while the rebuild uses its extended value.
//
// Context audit: the PDB owner and all original line bands identify ACT_misl.cpp,
// not ACT_make.cpp.  ACT_make.cpp set_state is 00404A70 and is already exact.
// This target was kept in its authentic ACT_misl.cpp owner context.
// Current claim probes: a post-distance denominator local worsened 210 to 424;
// function-scope and declaration-order changes, an uncast guided sqrt, constants,
// acceleration mutation, and PDB switch-case order did not change the 210 basin.
// A double guided-distance local changed the frame to 0x2C and worsened 210 to 241.
// All variants were restored to the pinned 210-byte clean source.
// Captain pass: the authentic-TU baseline remains 805B, frame 0x28, 12 ordered
// calls, and 210 positional diff bytes. H1/H2/H3 tested inline, grouped, and
// denominator-local guided forms; results were 434/451/436 diff bytes.
// H4/H7 tested vector declaration scope and order; both reproduced 210 bytes.
// H5/H10 tested dead launch-speed-home reuse; both reproduced the 436-byte
// denominator basin. H8/H9/H12 tested acceleration scope, rounding, and
// initialization; all reproduced 210 bytes. H11 reversed ballistic stores and
// worsened the result to 212 bytes. The clean source is restored.
//
// Authentic-TU probe: src/act_misl_tu.cpp includes the PDB-ordered ACT_misl.cpp
// owners through include/act_misl_context.h.  The module flag evidence is
// /nologo /c /O2 /Oy /GX: the two constructors at 00404BB0 and 00404C90 carry
// the original EH setup. Fresh wrapper extraction kept exact sibling anchors
// 00404BB0, 00404C90, 00404D10, 00404D50, and 004054B0 after relocation
// masking. The shared wrapper keeps the 0x28 frame and 12 ordered calls here,
// but this body still has an 0x330-byte section with a 0x325-byte original
// boundary and a larger positional drift than the standalone clean source. It
// did not resolve the switch/register hunk. The x87 differences below are also
// behavior-relevant, so this owner stays scratch and unregistered. Do not
// replace this target owner until a source-level fix preserves the calls,
// state publication, size, CFG, x87 precision, and fault order.
```
<!-- end-recovered:ef3d3723887f0af8312e -->
