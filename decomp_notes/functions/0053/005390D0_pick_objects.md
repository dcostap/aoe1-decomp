# Function notes: 005390D0 `pick_objects`

Module notes: `decomp_notes/view_module.md`.

## Recovered attempt history

<!-- recovered:2db0f781ec0eeda73046 -->
### `target-session` `build/target_sessions/005390D0_pick_objects.json:1-23`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=956; shape=65.98240469208211: Existing clean scratch source; establish current behavior, frame, calls, and mismatch.
probe 2 control-flow; result=MISMATCH; diff=1025; shape=67.74193548387096: Hypothesis 2: first source guard tests x < 0, matching original test eax after loading entry arg x before saved registers.
probe 4 behavior; result=MISMATCH; diff=956; shape=65.98240469208211: Hypothesis 3: move total_picked declaration to the first scalar slot, testing whether VC5 places its early zero in the binary's [esp+24] output-count home. [same emitted code as probe 1]
probe 5 liveness; result=MISMATCH; diff=956; shape=65.98240469208211: Hypothesis 4: split total_picked declaration from its zero assignment before guards, testing whether explicit statement scheduling recovers the oracle's pre-push count store. [same emitted code as probe 4]
probe 6 layout; result=MISMATCH; diff=1028; shape=65.98240469208211: Hypothesis 5: explicitly zero head[0] before guards, testing the decompiler's pre-prologue head/count stack-home evidence while retaining typed output count.
probe 8 context; result=MISMATCH; diff=956; shape=65.98240469208211: Hypothesis 6: restore the reviewed polymorphic TPanel/RGE_View surface while preserving proven field offsets, testing translation-unit class context. [same emitted code as probe 5]
probe 10 liveness; result=MISMATCH; diff=956; shape=65.98240469208211: Hypothesis 7: use explicit address-of index for pick_list_size[1], testing whether VC5 keeps the binary's member LEA and indirect zero stores. [same emitted code as probe 8]
probe 11 other; result=MISMATCH; diff=956; shape=65.98240469208211: Hypothesis 8: chain the four pick-list size zero stores, testing whether source assignment association preserves the oracle's indirect LEA/store sequence.
probe 13 control-flow; result=MISMATCH; diff=956; shape=65.98240469208211: Hypothesis 9: use a natural top-tested while(level >= min_level) with one post-loop output phase, matching the oracle's pre-loop compare and late output block. [same emitted code as probe 10]
probe 14 liveness; result=MISMATCH; diff=956; shape=65.98240469208211: Hypothesis 10: carry an explicit self alias through all member and sprite calls, testing whether VC5 spills the receiver to the oracle's [esp+10] home. [same emitted code as probe 13]
probe 16 control-flow; result=MISMATCH; diff=1025; shape=67.74193548387096: Hypothesis 11: replace radius<0 with x<0, matching the oracle's first explicit argument load/test and the x-coordinate failure edge. [same emitted code as probe 2]
probe 18 control-flow; result=MISMATCH; diff=952; shape=67.15542521994135: Hypothesis 12: spell upper viewport checks as x > x_max and y > y_max, matching the oracle's parameter-left cmp/jg encodings.
probe 19 control-flow; result=MISMATCH; diff=952; shape=67.15542521994135: Hypothesis 13: combine all early rejection predicates into one ordered short-circuit condition, matching the decompiler's single shared-failure compound guard. [same emitted code as probe 18]
probe 20 layout; result=MISMATCH; diff=1022; shape=69.79472140762464: Hypothesis 14: name all four node rectangle coordinates in y1,y2,x1,x2 declaration order, matching the oracle's y1/y2 then x1/x2 sign-extension sequence.
probe 21 liveness; result=MISMATCH; diff=1022; shape=69.79472140762464: Hypothesis 15: split rectangle local declarations from member assignments in y1,y2,x1,x2 order, testing whether statement order reproduces the oracle's preload schedule. [same emitted code as probe 20]
probe 22 abi; result=MISMATCH; diff=1035; shape=68.32844574780059: Hypothesis 16: type rectangle locals as signed short fields, testing width-aware VC5 extension and geometry arithmetic against the short-backed node layout.
probe 24 layout; result=MISMATCH; diff=1022; shape=69.79472140762464: Hypothesis 17: retain the proven parameter-left viewport bounds and add only a node_y2 local, testing the oracle's early y2 preload without the full four-coordinate alias set. [same emitted code as probe 21]
probe 26 liveness; result=MISMATCH; diff=1023; shape=70.08797653958945: Hypothesis 18: reuse one z local for y2+radius and the later object ID, mirroring the oracle's proven [esp+1c] scalar-home reuse across geometry and duplicate suppression.
probe 27 liveness; result=MISMATCH; diff=1023; shape=70.08797653958945: Hypothesis 19: reuse the dead max_level parameter home as the per-node keep flag, matching oracle writes of 0/1 at [esp+74] after outer level is copied.
probe 28 control-flow; result=MISMATCH; diff=1023; shape=70.08797653958945: Hypothesis 20: spell output-level loop as <=4 instead of <5, testing direct source-bound lowering against the oracle's cmp 4/jle tail. [same emitted code as probe 27]
probe 30 layout; result=MISMATCH; diff=952; shape=67.15542521994135: Hypothesis 21: declare scalar state before pointer arrays, testing a period-plausible source declaration order against the oracle's scalar homes preceding head/tail/free arrays. [same emitted code as probe 19]
probe 31 variant; result=MISMATCH; diff=952; shape=67.15542521994135: variant lab build\variant_lab\005390D0_pick_objects\20260817_154300: 8 variants, 0 invariant-eligible, 0 exact
probe 32 liveness; result=MISMATCH; diff=952; shape=67.15542521994135: Hypothesis 22: carry normalized hot_y and hot_x temporaries before assigning back to parameters, testing whether VC5 keeps x live through the zero-initialization window. [same emitted code as probe 31]
```
<!-- end-recovered:2db0f781ec0eeda73046 -->

<!-- recovered:553459eba5e587e80ef2 -->
### `912332e8f578` `src/scratch/005390D0_pick_objects.cpp:1-29`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 005390D0 RGE_View::pick_objects
// Attempt log:
// try 1-10: prior decompiler-shaped grid/object model was too short (674-688B) and
// used a fake pick_mask_test call; the binary actually walks prior_objs draw levels
// and calls RGE_View::sprite_check while maintaining sorted RGE_SPick_Info lists.
// probe 1 baseline: canonical ownership rewrite pending; prior source was not a
// behavior-backed reconstruction.
// probe 2: replaced the grid/object scaffold with the binary-backed draw-level
// scan, sprite_check call, free-list reuse, sorted insertion, and compact output;
// call set and size became structurally close.
// probe 3: removed artificial head[0] initialization; this recovered the
// compiler's overlapping count/list stack window and improved the diff.
// probe 4: separate validation guards, explicit level cursor, integer keep flag,
// and natural for loops recovered the 0x54 frame and many exact blocks.
// probe 5-7: tested declaration/context and a named pick_list_size[1..4] pointer;
// the contiguous member initialization improved resync similarity.
// probe 8: named all rectangle bounds reached exact size but worsened the
// register basin; restored direct canonical member expressions.
// probe 10: a named normalized hot_y lifetime worsened strict bytes; restored.
// probe 12: register total_picked was a codegen duplicate and was not retained.
// probe 14: paired entry hunk proved the original first test is x < 0; replacing
// the radius guard improved shape but worsened strict bytes and did not recover
// the pre-save x load. Restored the clean canonical source; first-hunk lead is
// exhausted without a natural typed declaration-order explanation.
// best retained check: 1048B rebuilt vs 1081B, 956 strict diff bytes, 65.98%
// shape similarity, exact frame/call set; remaining drift is broad prologue,
// register/liveness, and block-layout scheduling, not a call or layout blocker.
// worker pass: parameter-left upper viewport checks improve strict diff to 952
// bytes; coordinate aliases, scalar-home reuse, and ambient TU samples did not.
```
<!-- end-recovered:553459eba5e587e80ef2 -->
