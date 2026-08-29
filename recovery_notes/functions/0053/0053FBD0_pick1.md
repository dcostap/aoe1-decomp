# Recovery journal: 0053FBD0 `pick1`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/vw_main.cpp`.
- PDB source: `C:\msdev\work\age1_x1\vw_main.cpp`.
- Earlier recovery note: `recovery_notes/vw_main_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b5d9290bd0bea5bbe23d -->
### `target-session` `build/target_sessions/0053FBD0_pick1.json:1-41`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=566; shape=48.553054662379424: Baseline current clean scratch reconstruction before new hypotheses; establish metrics and call alignment.
probe 2 layout; result=MISMATCH; diff=567; shape=48.87459807073955: Hypothesis 18: model Picked_Objects as the proven absolute table address 0x87D4A0 instead of an unresolved C++ extern; test whether this removes global relocations and restores loop addressing.
probe 3 liveness; result=MISMATCH; diff=559; shape=48.07692307692308: Hypothesis 19: use a moving PickedInfo cursor from Picked_Objects in both scans, matching the oracle's global-base pointer and add-0Ch loop shape instead of indexed field addresses.
probe 4 liveness; result=MISMATCH; diff=563; shape=48.07692307692308: Hypothesis 20: reorder no-exclude locals to declare the two short screen outputs before chosen object and score, testing the original frame-home ordering shown by stack stores.
probe 5 liveness; result=MISMATCH; diff=559; shape=48.07692307692308: Hypothesis 21: reuse the dead x parameter as the no-exclude best-score accumulator, matching the decompiler's proven parameter-home reuse after pick_objects.
probe 6 liveness; result=MISMATCH; diff=574; shape=48.70967741935484: Hypothesis 22: leave exclude-branch screen outputs uninitialized until a chosen object path assigns them, matching the oracle's absence of zero stores and preserving proven valid-path use.
probe 7 liveness; result=MISMATCH; diff=573; shape=48.38709677419355: Hypothesis 23: share one function-scope screen coordinate pair across both 0x29 branches, testing whether the oracle's EBX/EBP screen registers reflect one reused pair rather than branch-local pairs.
probe 8 abi; result=MISMATCH; diff=559; shape=48.07692307692308: Hypothesis 24: declare the picked-object table as an external byte buffer and cast it to PickedInfo, testing the lesson-supported symbol-relative buffer ABI against the typed C++ array.
probe 9 liveness; result=MISMATCH; diff=559; shape=48.07692307692308: Hypothesis 25: scope the pick count inside the 0x29 arm, testing whether the oracle's 8-byte frame comes from shorter count lifetime across the wrapper path.
probe 10 liveness; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis 26: remove the explicit self alias and use direct this member expressions after pointer-cursor recovery, testing whether alias lifetime still affects the local frame.
probe 11 layout; result=MISMATCH; diff=819; shape=49.03225806451613: Hypothesis 27: bias each picked-table cursor by one entry and preincrement before access, testing whether this natural cursor variant recovers the oracle's global-base plus field-offset addressing.
probe 12 liveness; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis 28: declare exclude-branch screen shorts before seen/chosen locals, testing declaration-order effects on the oracle's EBX/EBP screen register ownership.
probe 13 control-flow; result=MISMATCH; diff=878; shape=66.45161290322581: Hypothesis 29: express the no-exclude scan as an explicit count-mutating while loop with pointer advance at the bottom, testing source loop form against the oracle's decrement-and-add sequence.
probe 14 liveness; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis 30: reuse dead x as the exclude-branch scan index, matching the decompiler's param_3 increment and the oracle's dedicated index home.
probe 15 liveness; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis 31: isolate direct-this gains by restore a named no-exclude bestScore local, testing whether x-home reuse remains necessary after alias removal.
probe 16 behavior; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis 33: use an unqualified recursive pick1 call in the 0x2A wrapper, testing whether VC5 emits the oracle's internal self-call identity rather than a named external relocation. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=548; shape=74.03846153846153: Hypothesis 34: reuse dead y as the pick count after pick_objects, matching the decompiler's param_4 count reuse and testing whether it removes the local count home.
probe 18 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis 35: combine y-count reuse with dead x reuse as the no-exclude score, matching both decompiler parameter mutations and testing the reduced-local basin.
probe 19 liveness; result=MISMATCH; diff=547; shape=72.11538461538461: Hypothesis 36: combine y-count reuse with x as the exclude scan index, matching the decompiler's repeated param_3 mutation and testing full parameter-home reuse.
probe 20 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis 37: split exclude screen-short declarations into separate statements, testing whether VC5 pairs or colors the two output homes differently. [same emitted code as probe 18]
probe 21 liveness; result=MISMATCH; diff=558; shape=75.16129032258064: Hypothesis 38: declare the exclude-branch table cursor before seen/chosen/screen locals, testing whether pointer lifetime ordering frees one negative frame home.
probe 22 liveness; result=MISMATCH; diff=580; shape=74.83870967741936: Hypothesis 39: declare and initialize the exclude scan index before seen/chosen locals, testing stack-home order while retaining the typed moving cursor.
probe 23 liveness; result=MISMATCH; diff=563; shape=48.38709677419355: Hypothesis 40: share screen_x/screen_y across both mutually exclusive branches while retaining y-count and x-score reuse, testing whether one function-scope pair removes the cy frame home.
probe 26 control-flow; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis A: replace the no-exclude for index with a y-mutating while loop and explicit PickedInfo cursor advance; original decrements the result count home and has no separate loop-index home. [same emitted code as probe 25]
probe 28 liveness; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis B: preserve a function-scope target_count local from pick_objects, reuse y as the no-exclude countdown, and use x as the exclude index; original has a distinct local count home plus parameter-home loop state.
probe 31 liveness; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis C: add only a distinct target_count result local while preserving the clean scan forms; original stores pick_objects result in a negative local before branch selection.
probe 33 layout; result=MISMATCH; diff=614; shape=72.34726688102894: Hypothesis D: use direct Picked_Objects[j] indexed expressions in the exclude scan instead of a moving cursor, testing whether VC5 spills the cursor and frees EBP/EBX for the original screen-coordinate pair.
probe 35 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis E: order exclude-branch screen-coordinate assignments before chosen-object assignment, matching the oracle's view loads, chosen store, then 16-bit additions. [same emitted code as probe 26]
probe 37 abi; result=MISMATCH; diff=524; shape=72.58064516129032: Hypothesis F: type the exclude-seen flag as bool, following the decompiler's bool evidence, to test whether VC5 uses the oracle's two local slots and dword flag operations.
probe 39 layout; result=MISMATCH; diff=565; shape=72.9903536977492: Hypothesis G: make the exclude cursor a loop-local pointer derived from Picked_Objects[j] each iteration, testing whether VC5 spills the moving cursor and preserves the oracle's EBP/EBX screen-coordinate registers.
probe 41 control-flow; result=MISMATCH; diff=923; shape=13.82636655948553: Hypothesis H: invert the outer command guard into the decompiler-shaped early non-0x29 return, then keep the 0x29 body as the fall-through block; this tests source block scope and declaration lifetime against the oracle's entry branch.
probe 43 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis I: retain y as the no-exclude result/count, but copy it to a distinct target_count used only by the exclude scan and fallback; this tests the oracle's separate negative target-count home without changing the first scan. [same emitted code as probe 35]
probe 45 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis J: declare exclude screen shorts before seenExclude and chosen, testing whether VC5 assigns the oracle's BP/BX screen homes before pointer/flag locals.
probe 47 liveness; result=MISMATCH; diff=548; shape=48.3974358974359: Hypothesis K: use target_count directly as the pick result and as both scan bounds, with x as the exclude index and no y reassignment; this tests the distinct original result home plus parameter-home index reuse. [same emitted code as probe 28]
probe 49 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis L: exploratory register-qualified exclude screen shorts, testing the binary's BP/BX live screen pair; this is not a retained form without donor or exact-source support. [same emitted code as probe 43]
probe 51 control-flow; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis M: split exclude score-positive and visibility predicates into nested if statements, matching the decompiler's nested condition and testing whether this removes the cached vtable register that blocks BP/BX screen allocation. [same emitted code as probe 49]
probe 53 liveness; result=MISMATCH; diff=562; shape=48.38709677419355: Hypothesis N: leave exclude screen outputs uninitialized until a valid chosen object path, matching the oracle's lack of screen zero stores on the branch setup.
probe 55 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis O: use one function-scope PickedInfo cursor assigned in both mutually exclusive scans, matching the decompiler's one ppRVar8 and testing branch-specific cursor allocation. [same emitted code as probe 51]
probe 57 liveness; result=MISMATCH; diff=551; shape=74.35897435897436: Hypothesis P: declare the no-exclude screen shorts before the selected-object pointer, testing the original no-exclude parameter-home rotation and screen register ownership.
probe 59 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis Q: use a separately initialized no-exclude countdown local i=y with bottom cursor advance, testing whether VC5 maps the count to the oracle's y home instead of the current cmd home. [same emitted code as probe 55]
probe 61 liveness; result=MISMATCH; diff=547; shape=74.35897435897436: Hypothesis R: split the no-exclude screen short declarations, testing whether separate homes recover the oracle's best-object, score, y-count, and screen-y parameter rotation. [same emitted code as probe 59]
```
<!-- end-recovered:b5d9290bd0bea5bbe23d -->

<!-- recovered:beb59546ae2da785571b -->
### `ed3a3f85db1c` `src/scratch/0053FBD0_pick1.cpp:1-68`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0053FBD0 RGE_Main_View::pick1
// Attempt log:
// try 1: packet-grounded reconstruction using vw_main pick family context. Models 0x29 pick path, output zeroing, pick_objects radius variants, no-exclude best scan, exclude-object alternate scan, output fill, 0x2a recursive wrapper, and fallback pick_multi call.
// try 2: fixed Picked_Objects entry stride/fields and helper declaration; reached exact configured size 982.
// try 3: first 0x60 bytes nearly match: parameter byte test, 0x29 branch, out struct zeroing, and pick_objects argument variants are in the right basin.
// try 4: modeled no-exclude best-object scan over Picked_Objects, player object array at +0xfc/+88, owner < 7, master byte +0x8d >= small.
// try 5: modeled optional terrain/path filter: alt param, terrain flag +0x8db8, virtual can_pick at vtable +0xe0, tile helper returning 0x0f.
// try 6: modeled score_pick virtual at +0xe4 and best-score update with view offsets +0x8c/+0x90 plus picked dx/dy.
// try 7: modeled exclude-object path with seen-exclude flag and alternate selection, including fallback to last picked entry.
// try 8: modeled output fill fields: world x/y from object +0x38/+0x3c, screen shorts, object pointer, and 0x34/0x32 return codes.
// try 9: modeled 0x2a wrapper that retries as 0x29 with alt=1 and returns early on 0x34.
// try 10: tried casting float positions directly to int for tile helper instead of ftol calls; worsened to 78.5132% positional / 111.6090% edit, rolled back.
// try 11: restored the vw_main/view ABI surface: pick_through_fog and pick_weight
// are RGE_View virtuals at +0xe0/+0xe4, get_visible is the direct two-argument
// RGE_Visible_Map member, and output stores are inline rather than a helper call.
// try 12: corrected get_visible to the natural (int)x,(int)y source order so
// VC5 emits the two right-to-left __ftol conversions without explicit cdecl calls.
// This fixed the call set and reduced the strict diff to 602 bytes at exact size.
// try 13: restored TPanel::render_rect ownership for the +0x8c/+0x90 screen
// offsets; this is codegen-neutral to the prior short-field stub but is the
// canonical period layout. The fallback now preserves the oracle's proven
// `chosen = exclude` behavior and uses the count-indexed picked screen pair.
// try 14: removed the redundant `self` alias and used direct `this` member
// calls throughout. Emitted code was unchanged; the wrapper call remains the
// natural recursive `pick1` call, while the checker labels the oracle target
// as internal+0x0 because it is the function entry.
// try 15: qualified the recursive call as `RGE_Main_View::pick1`. Emitted code
// was unchanged and the source was restored to the ordinary unqualified
// member-call spelling.
// Final retained reconstruction: typed TPanel/RGE_View/world/player/map and
// virtual pick helpers, natural casts/member calls, inline output stores. The
// remaining 602-byte drift is a broad local-home/frame basin (rebuilt frame
// 0xc versus original 0x8), plus the self-call relocation classification; no
// further blind source-shape lead remains in this bounded pass.
// Current validation: exact size, 602 strict differing bytes (61.3035%) and
// 404 edit-diff bytes (41.14%), with 13/13 ordered calls aligned except the
// self-call relocation classification. Frame remains 0xc versus original 0x8;
// no inline asm or accepted-drift proposal.
// try 16: shared selected-object and screen-pair ownership across both 0x29
// branches reduced the frame to 0x8 but worsened the strict diff to 896 bytes;
// rolled back to the clean branch-local reconstruction.
// try 17: express successful output as the positive selected-object branch,
// matching the oracle's `cmp selected,0; je return32` block shape.
// try 18: an absolute Picked_Objects address was rejected; it changed the
// relocation basin and worsened the strict diff.
// try 19: moving PickedInfo cursors recovered the oracle's 12-byte cursor
// updates and improved the strict diff from 566 to 559 bytes.
// try 20: split screen declarations were a codegen duplicate.
// tries 21-23: biased cursors, explicit while scans, and shared screen pairs
// worsened code or shape; restored typed branch-local forms.
// try 24: direct this calls, y reused for the post-pick count, and x reused
// for the no-exclude score reached 547 strict differing bytes and 74.36%
// shape similarity. This is the best clean unresolved source.
// BINARY NOTE: the oracle walks Picked_Objects with a 12-byte moving cursor.
// BINARY NOTE: the oracle reuses dead coordinate parameter homes for the
// post-pick count and no-exclude score after pick_objects returns.
// Open: the oracle has an 8-byte local frame; this source remains at 0xC.
// Worker pass 2026-08-22: tested a y-mutating no-exclude countdown, an explicit
// target_count local, indexed and loop-local PickedInfo cursors, screen
// assignment order, bool and register-qualified flags/shorts, outer-guard
// inversion, nested visibility checks, shared cursor scope, and declaration
// order. The best unchanged natural source remains 547 strict differing bytes
// at exact size with 74.36% shape similarity. These variants did not recover
// the original 8-byte frame or its BP/BX exclude-screen register pair.
// Open: source-level cause of the remaining local-home rotation is unknown.
// TU pass: using owner_type restores the proven +48h field without a source
// fork. A grouped-only render-rectangle view reduced the diff to 548 bytes,
// but it was rejected. The shared RGE_View layout needs a reviewed +8Ch field.
```
<!-- end-recovered:beb59546ae2da785571b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
