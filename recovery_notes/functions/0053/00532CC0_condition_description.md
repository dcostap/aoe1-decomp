# Recovery journal: 00532CC0 `condition_description`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/victory.cpp`.
- PDB source: `C:\msdev\work\age1_x1\victory.cpp`.
- Earlier recovery note: `recovery_notes/victory_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2f0443f5534bfb43c915 -->
### `target-session` `build/target_sessions/00532CC0_condition_description.json:1-20`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=433; shape=84.6590909090909: Clean typed switch baseline before focused source hypotheses.
probe 2 behavior; result=MISMATCH; diff=433; shape=85.22727272727273: Swapped acquire format arguments to match original load/push order: count then number.
probe 3 control-flow; result=MISMATCH; diff=394; shape=90.13157894736842: Tested a direct two-argument shared sprintf tail with typed locals; diagnostic only.
probe 4 context; result=MISMATCH; diff=443; shape=84.6590909090909: Tested repository-period stdio.h declaration context for sprintf; diagnostic only.
probe 5 liveness; result=MISMATCH; diff=433; shape=85.22727272727273: Tested scoped name/id locals in the two two-argument cases; diagnostic only.
probe 6 abi; result=MISMATCH; diff=433; shape=85.22727272727273: Diagnostic only: cast the two name varargs to long to test whether common dword argument types trigger tail merge.
probe 10 control-flow; result=MISMATCH; diff=394; shape=90.13157894736842: Hypothesis: a real union of text/number arguments preserves the original shared case-1/case-9 sprintf tail without raw long casts.
probe 11 liveness; result=MISMATCH; diff=392; shape=92.10526315789474: Hypothesis: reverse case-1 union assignments to match the original pointer/name load before number load while retaining the shared tail.
probe 12 abi; result=MISMATCH; diff=433; shape=85.22727272727273: Hypothesis: direct case-1/case-9 varargs with all dword values cast to long lets VC5 tail-merge the calls without explicit generic locals.
probe 13 liveness; result=MISMATCH; diff=389; shape=96.05263157894737: Hypothesis: reverse case-9 union assignments to load the player id before the name, matching the original case-9 setup.
probe 14 liveness; result=MISMATCH; diff=389; shape=96.05263157894737: Hypothesis: represent the shared two-argument varargs values as a natural two-element long array rather than two union objects.
probe 15 liveness; result=MISMATCH; diff=389; shape=96.05263157894737: Hypothesis: reverse the declaration order of the shared union objects to test VC5 register coloring without changing the common-tail source model. [same emitted code as probe 13]
probe 16 abi; result=MISMATCH; diff=389; shape=96.05263157894737: Hypothesis: use int rather than long for the union's numeric member, since all observed numeric varargs are dwords. [same emitted code as probe 15]
probe 17 abi; result=MISMATCH; diff=389; shape=96.05263157894737: Hypothesis: use the period non-const format pointer type in the shared tail to test whether VC5 changes literal push and register lowering. [same emitted code as probe 16]
probe 18 liveness; result=MISMATCH; diff=389; shape=96.05263157894737: Hypothesis: place the shared-tail temporaries before the text buffer to test declaration-order register coloring while preserving the same frame. [same emitted code as probe 17]
probe 22 context; result=MATCH; diff=0; shape=99.34210526315789: Compile after real 00532C50 victory.cpp owner with shared declarations
probe 23 context; result=MATCH; diff=0; shape=99.34210526315789: Finish reduction: remove target-local duplicate declarations and rely on the reviewed shared victory context header already included by the earlier owner
probe 25 abi; result=MATCH; diff=0; shape=99.34210526315789: Use the PDB-proven struct-tagged entry parameter and protected virtual method access; test ABI symbol repair without changing body code. [same emitted code as probe 24]
probe 26 abi; result=MATCH; diff=0; shape=99.34210526315789: Walkback: make condition_description public while retaining the struct-tagged entry; confirm protected access alone controls the M versus U owner symbol. [same emitted code as probe 25]
probe 27 abi; result=MATCH; diff=0; shape=99.34210526315789: Walkback: revert only the entry tag to class while retaining protected access; confirm the V versus U type tag controls the remaining owner-symbol mismatch. [same emitted code as probe 26]
```
<!-- end-recovered:2f0443f5534bfb43c915 -->

<!-- recovered:aaae09581a93e4eda017 -->
### `05bbf86b02d7` `src/scratch/00532CC0_condition_description.cpp:1-49`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_Victory_Conditions::condition_description
// VA: 00532CC0
// Attempt log:
// - Baseline: reconstructed the binary-supported switch, typed entry/object/player/master
//   ownership, ten period strings, float-to-double varargs, and the getstring output slot.
//   Direct source was 532 bytes versus 479; the initial byte clear also missed the observed
//   whole-dword zero.
// - Whole-dword clear probe improved the direct source to 435 differing bytes; the PDB-sized
//   200-byte temporary still left a 0xC8 frame versus the original 0xCC.
// - A diagnostic 204-byte temporary recovered the original frame and 71.71% exact-block
//   coverage, but conflicts with the PDB's char[200] local and was not retained.
// - An explicit shared two-argument sprintf tail for cases 1/9 recovered exact size, call
//   count, and 100% call-site alignment (394 differing bytes); its generic format/argument
//   locals are compiler-steering scaffolding, so it was restored out of the living source.
// - Case-local destination/name/id declarations, return-type context, and typed shared-tail
//   target/index locals were codegen duplicates or worse.
// - Paused after 10 hypotheses: canonical direct switch source retained; remaining structural
//   gap is VC5 tail merging plus the jump-table/code-layout basin, with no call/ABI/layout
//   behavior defect. Best diagnostic checkpoint is probe-006-control-flow (394 bytes).
// - Main-agent audit removed the diagnostic +4 stack window and pointer-overlaid output slot.
//   The living source uses the declared text buffer and a separate result pointer.
// - New worker initialized a separate result pointer before the 200-byte buffer;
//   this recovered the original 0xCC frame and natural temp base, but the direct
//   switch still has one extra sprintf call from VC5 tail layout (433 bytes).
// - A shared text pointer was codegen-neutral. A behavior-correct common case-1/
//   case-9 tail using long varargs recovered exact size/frame/call count (394 bytes;
//   393 with proven absolute string addresses), but pointer-to-long argument
//   scaffolding is not retained as living source. Argument declaration reordering
//   was a duplicate; restore the clean typed direct switch.
// - Legacy sprintf format constness and return type were unchanged codegen.
// - &temp[0], an inlined two-argument helper, and a shared format pointer were
//   unchanged codegen. The clean typed direct switch remains the best source model.
// - Fresh worker evidence confirms case 6 pushes count before number; the source
//   now uses that binary-supported argument order. A stdio.h context was worse.
//   The remaining gap is the extra direct sprintf call for the two-argument
//   case-1/case-9 tail; no natural source form recovered that tail.
// - This claim re-established canonical ownership from the target dossier and
//   exact victory.cpp donors: the virtual member, entry offsets, player master
//   array, object master, and short player id agree with the surrounding exact
//   functions. No ABI or layout conflict was found.
// - A real union shared tail for cases 1 and 9 recovered exact size/frame and
//   all eight call sites (394 bytes; reversed case-1 assignments 392 bytes).
//   Reversing case-9 assignments reached 389 bytes and 96.05% shape, but the
//   generic union/format locals changed the proven argument setup. An argument
//   array, declaration-order change, int/long change, non-const format, and
//   direct all-long casts were duplicate or worse. These are diagnostic only.
// - Restored the natural direct switch. Final validation remains a 433-byte
//   mismatch with one extra direct sprintf; the best 389-byte shared-tail
//   probe is not retained as canonical source.
```
<!-- end-recovered:aaae09581a93e4eda017 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
