# Recovery journal: 0044AFE0 `DrawMask`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/fractal.cpp`.
- PDB source: `C:\msdev\work\age1_x1\fractal.cpp`.
- Earlier recovery note: `recovery_notes/fractal_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:8b40c26ab4e35aab6bfb -->
### `target-session` `build/target_sessions/0044AFE0_DrawMask.json:1-47`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=482; shape=23.280423280423282: Baseline clean typed mask traversal before new probes; measure current frame, boundary, and loop mismatch.
probe 2 control-flow; result=MISMATCH; diff=477; shape=23.280423280423282: Separated the 2/3 preclip from the 4/5 mask dispatch, reused input homes for mask pointer and inner count, and changed rows to base-pointer plus output-index traversal.
probe 3 control-flow; result=MISMATCH; diff=531; shape=68.2051282051282: Made the 2 and 3 preclip tests independent statements to test the original inline 2/3 dispatch and common 4/5 tail.
probe 4 liveness; result=MISMATCH; diff=544; shape=59.375: Restored the binary-proven running mask pointer update by mask_step after each output row, while retaining independent 2/3 dispatch.
probe 5 abi; result=MISMATCH; diff=544; shape=59.375: Changed the recovered running mask owner from an integer overlay to a typed char pointer; the cursor and displacement are binary-proven. [same emitted code as probe 4]
probe 7 layout; result=MISMATCH; diff=547; shape=61.78010471204188: Tested a parameter-home reconstruction: mutate input parameter homes into mapptr and inner count, retain mask_step and the running pointer, and use literal decompiler loop ownership.
probe 9 liveness; result=MISMATCH; diff=520; shape=25.925925925925927: Introduced the binary-proven per-row mask_base = mask_cursor - write_index, so the inner loop reloads one stable row offset instead of recomputing a subtraction per sample.
probe 10 abi; result=MISMATCH; diff=520; shape=25.925925925925927: Kept the per-row stable mask_base but represented its proven byte-address offset as an int, matching the decompiler's local len and testing the original register basin.
probe 11 context; result=MISMATCH; diff=520; shape=25.925925925925927: Restored the full same-TU PointMaker field surface from exact fractal.cpp donors, preserving all proven offsets, to test translation-unit class context effects. [same emitted code as probe 9]
probe 12 context; result=MISMATCH; diff=551; shape=70.37037037037037: Tested donor-supported fractal.cpp header context with stdlib.h and string.h before the typed class surface.
probe 14 liveness; result=MISMATCH; diff=520; shape=25.925925925925927: Moved mask_base to function scope and split declaration from per-row assignment, testing whether the original local_8 lifetime and frame ownership are declaration-scope driven.
probe 15 control-flow; result=MISMATCH; diff=490; shape=70.8994708994709: Combined the per-row mask_base lifetime with independent size-3 dispatch to recover the original inline 2/3 preclip blocks.
probe 17 layout; result=MISMATCH; diff=537; shape=72.3076923076923: Retested parameter-home ownership with a stable per-row mask_base and running param_1 pointer, matching the target's observed homes at +4/+8/+C.
probe 18 liveness; result=MISMATCH; diff=537; shape=72.3076923076923: Applied register qualification only to the first input in the parameter-home reconstruction, testing the observed EDX first-argument color. [same emitted code as probe 17]
probe 19 control-flow; result=MISMATCH; diff=512; shape=80.10471204188482: Combined parameter-home mask ownership with independent size-3 dispatch, testing whether inline case-3 control dominates the register basin.
probe 21 abi; result=MISMATCH; diff=482; shape=23.280423280423282: Introduced an explicit PointMaker self alias for all field accesses, testing whether callee-saved self ownership reproduces the target EDI receiver. [same emitted code as probe 1]
probe 25 control-flow; result=MISMATCH; diff=532; shape=18.75: Reconstructed the Ghidra-proven natural DrawMask source with canonical full PointMaker ownership, parameter-home mask pointer/width/count reuse, and separate post-tested inner plus bottom-tested outer loops.
probe 26 liveness; result=MISMATCH; diff=532; shape=18.75: Retested the canonical protected full PointMaker source with direct initial Width/Height guards and delayed Width capture, removing the early cached-width hoist. [same emitted code as probe 25]
probe 27 context; result=MISMATCH; diff=532; shape=18.75: Tested the natural parameter-home reconstruction against a minimal reviewed PointMaker field surface, keeping proven mask/array offsets and the protected DrawMask ABI. [same emitted code as probe 26]
probe 28 liveness; result=MISMATCH; diff=526; shape=21.98952879581152: Added the decompiler-proven stable len = mask_pointer - write_index local before the inner loop, replacing repeated cursor subtraction and testing the missing target stack home.
probe 29 control-flow; result=MISMATCH; diff=537; shape=23.83419689119171: Changed the four initial validity tests to separate early-return statements, testing the target's pre-save parameter load and shared-failure CFG basin.
probe 30 liveness; result=MISMATCH; diff=537; shape=23.83419689119171: Carried the original x argument in the proven iVar7 register before the guards and used that owner through size-2/3 clipping, testing the target's pre-save parameter load. [same emitted code as probe 29]
probe 31 abi; result=MISMATCH; diff=537; shape=23.83419689119171: Tested the supported register-qualified first input to recover the target's EDX pre-save argument color without changing the proven parameter-home semantics. [same emitted code as probe 30]
probe 32 abi; result=MISMATCH; diff=537; shape=23.83419689119171: Diagnostic access-control probe: changed only DrawMask declaration from protected to public to test whether the pre-save argument load is access-context driven. [same emitted code as probe 31]
probe 33 context; result=MISMATCH; diff=537; shape=23.83419689119171: Removed donor headers from the natural parameter-home source, testing whether the target's pre-save register and early CFG basin comes from the original minimal DrawMask translation-unit context. [same emitted code as probe 32]
probe 34 control-flow; result=MISMATCH; diff=516; shape=80.0: Tested independent size-2 and size-3 dispatch statements to keep the proven case-3 clipping blocks inline instead of a compiler-relocated else arm.
probe 35 liveness; result=MISMATCH; diff=516; shape=80.0: Used one typed PointMaker self alias for all proven field ownership, testing whether the target's persistent EDI receiver is the natural class-field register basin.
probe 36 layout; result=MISMATCH; diff=516; shape=80.0: Replaced direct parameter-pointer mutation with the decompiler-proven integer mapptr owner while retaining parameter-home width/count reuse and the inline size-3 dispatch. [same emitted code as probe 35]
probe 37 liveness; result=MISMATCH; diff=516; shape=80.0: Moved the proven x-carrier initialization into the local declaration to test VC5 declaration/initialization scheduling for the target's pre-save EDX load. [same emitted code as probe 36]
probe 38 abi; result=MISMATCH; diff=516; shape=80.0: Changed the proven mask owner from an integer decompiler view to a typed char pointer, testing whether canonical pointer arithmetic recovers target receiver and mask-load lowering. [same emitted code as probe 37]
probe 39 liveness; result=MISMATCH; diff=516; shape=80.0: Split the size-3 row adjustment into a parameter assignment plus compound increment, testing whether VC5 preserves the target EAX row value and EBX setcc temporary. [same emitted code as probe 38]
probe 40 control-flow; result=MISMATCH; diff=516; shape=80.0: Replaced the outer for counter with an explicit row_count copy and while countdown, testing the target's initial decrement/restore and separate local-c counter topology. [same emitted code as probe 39]
probe 41 liveness; result=MISMATCH; diff=516; shape=80.0: Removed the optimizer-eliminated self alias and register qualifier, restoring direct canonical member expressions and the protected target ABI while retaining binary-proven len/mapptr and inline case-3 shape. [same emitted code as probe 34]
probe 42 context; result=MISMATCH; diff=516; shape=80.0: Restored the canonical full PointMaker field ownership, including PrimaryPt/PtToPt and all proven mask/probability offsets, while retaining the protected natural DrawMask reconstruction. [same emitted code as probe 41]
probe 45 context; result=MISMATCH; diff=550; shape=67.72486772486772: Replaced the duplicate local PointMaker with the reviewed fractal_arrays_context.h surface; authentic fractal.cpp donor headers are the context hypothesis.
probe 46 layout; result=MISMATCH; diff=531; shape=22.22222222222222: Reused the three incoming homes for mapptr, clipped mask width, and inner countdown, as the original writes and reads those exact entry offsets.
probe 48 liveness; result=MISMATCH; diff=533; shape=67.72486772486772: Cached the proven Width and Height before the initial guard, then reused them through clipping and row strides to test the target's early EBP/ESI field loads.
probe 50 layout; result=MISMATCH; diff=516; shape=80.42328042328042: Kept the original coordinate copy in iVar7, then reused only param_1 for the mask base and row advance, matching the target's parameter-home mask ownership without an artificial alias.
probe 51 control-flow; result=MISMATCH; diff=506; shape=76.71957671957672: Replaced the top-tested outer while with a guarded do-while and explicit countdown, testing the target's pretest plus decrement/restore topology.
probe 54 control-flow; result=MISMATCH; diff=542; shape=24.33862433862434: Restored the complete Ghidra-supported nested guard, size-2/3 else chain, parameter-home mask ownership, direct height countdown, and inner len local as one authentic fractal.cpp source-shape hypothesis.
probe 56 liveness; result=MISMATCH; diff=503; shape=64.02116402116403: Loaded Width and Height into named locals before their guards, then reused those proven dimensions through clipping to test the target's initial field-load order.
probe 58 liveness; result=MISMATCH; diff=516; shape=80.42328042328042: Moved only the Width capture before the first guard while leaving Height direct, isolating the target's pre-save Width load without adding a second cached dimension. [same emitted code as probe 50]
probe 59 abi; result=MISMATCH; diff=476; shape=71.42857142857143: Widened the signed mask sample to int before the byte store and saturation sum, testing the target's entry movsx mask-load and preserving signed sample arithmetic.
probe 60 liveness; result=MISMATCH; diff=482; shape=70.8994708994709: Loaded the probability cell through the named destination pointer before reading its byte, testing the target's EAX pointer and DL byte-register order.
probe 61 liveness; result=MISMATCH; diff=517; shape=69.84126984126983: Named the signed probability sum before its threshold and byte store, testing the target's separate integer saturation accumulator and low-byte update.
probe 63 layout; result=MISMATCH; diff=476; shape=71.42857142857143: Reused param_1 itself for the mask base while retaining the widened signed sample, testing the target's proven +4 parameter-home writes and movsx byte path together. [same emitted code as probe 59]
probe 64 control-flow; result=MISMATCH; diff=474; shape=70.37037037037037: Combined the widened signed sample with a guarded outer do-while, testing the target's first row-count test and bottom countdown as one source shape.
```
<!-- end-recovered:8b40c26ab4e35aab6bfb -->

<!-- recovered:b3c6d9585ac6deb4383e -->
### `b7fd2baf398f` `src/scratch/0044AFE0_DrawMask.cpp:1-33`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// PointMaker::DrawMask
// VA: 0044AFE0 - draws one distance mask into the probability array.
//
// Attempt log:
// - The binary and exact fractal.cpp donors prove PointMaker ownership for the
//   four mask pointers at +0xFA8..+0xFB4, Width/Height at +0xFD4/+0xFD8,
//   ProbabilityTiles at +0xFEC, SizeArrays at +0x1004, and ProbArray at
//   +0x1024.
// - The prior source used independent mask-row, mask-column, width, height,
//   and cursor locals. The target instead reuses the incoming parameter homes:
//   param_1 becomes the mask pointer, param_2 becomes the clipped width, and
//   param_3 becomes the inner countdown. This source follows that proven
//   ownership and the decompiler's natural loop shape.
// - The target performs a first outer-count test, then runs a post-tested inner
//   loop and a bottom-tested outer loop. The source keeps those distinct.
// - This is an unresolved structural probe. Exact validation is recorded in
//   the target session notebook.
// - BINARY NOTE: The mask sample is sign-extended before the first bounds
//   test. An int sample preserves this operation and the best current diff.
// - BINARY NOTE: A guarded post-tested outer loop preserves the target's first
//   row-count test and bottom countdown. The current fresh diff is 474 bytes.
// - Header and reviewed full-context probes changed the basin without an exact
//   result. The source keeps the smallest local class surface and no alias
//   used only to steer code generation.
// - Context pass: PDB source module is fractal.cpp, lines 115-172, with 35
//   records. The address sequence is 0044AFE0-0044B205 and follows
//   DeleteMasks before ClearArrays. Exact anchors are the 0044AFE0 entry,
//   0044B072 Mask_4x4 load, 0044B0DB Mask_5x5 load, 0044B172 sample loop,
//   and 0044B1FC shared return. The owning class is PointMaker.
// - Final standalone validation remains 531 bytes versus 550, with 474
//   differing bytes. Fresh grouped validation in fractal_arrays_tu.cpp is
//   517 differing bytes. No policy-valid source form closed this structural
//   gap, so this owner remains scratch.
```
<!-- end-recovered:b3c6d9585ac6deb4383e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
