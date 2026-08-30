# Function notes: 004390A0 `TileDibBlt`

Module notes: `decomp_notes/Dib_module.md`.

## Current mismatch

- Fresh check `probe-044-behavior` (2026-08-29) reports a 1259-byte rebuild
  against the 1265-byte original. The strict positional difference is 1097
  bytes. Shape similarity is 78.16%. The frame is `0x1c`, and all 8 direct
  calls align with the original targets and order. The owner symbol and
  boundary are valid. The function remains `scratch`.
- The first structural mismatch remains the natural module prologue at offset
  `+0009`. The remaining drift is broad VC5 register, stack-home, and loop
  scheduling drift. It is not an accepted-drift candidate.

## Recovered attempt history

<!-- recovered:73eb0968a33761aea78e -->
### `target-session` `build/target_sessions/004390A0_TileDibBlt.json:1-29`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 other; result=MISMATCH; diff=1104; shape=75.4201680672269: Probe 1: remove tileWidth/tileHeight aliases and use direct parameter expressions; original early code reads param15/param16 directly and loads param8 into EBP after push.
probe 2 other; result=MISMATCH; diff=1179; shape=70.64989517819707: Probe 2: remove named xscale/yscale locals and use nested source expressions; Ghidra local inventory has no scale locals, and original stores scale results into reused parameter homes.
probe 3 liveness; result=MISMATCH; diff=1104; shape=75.4201680672269: Probe 3: move scale-local declarations after the binary-supported integer and geometry locals; declaration order can control VC5 register carriers and prologue scheduling. [same emitted code as probe 1]
probe 4 liveness; result=MISMATCH; diff=1104; shape=75.4201680672269: Probe 4: promote branch-local flip arguments to function-scope locals, matching the decompiler's function-wide iVar1/iVar3 lifetimes and possible early register reservation. [same emitted code as probe 3]
probe 5 behavior; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 5: restore the binary-supported fallback split between the current row pointer and row-plus-SrcBotHgt; the decompiler shows distinct param12 and iVar1 destinations, unlike the prior reused param5.
probe 6 abi; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 6: type the fallback row-plus-offset temporary as int, matching the decompiler's iVar1 and the proven 32-bit pointer arithmetic. [same emitted code as probe 5]
probe 7 liveness; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 7: introduce named srcWidth/srcHeight aliases for the scale denominators; test whether explicit parameter lifetime restores the original EBP denominator carrier. [same emitted code as probe 6]
probe 8 liveness; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 8: mark the source-width alias register, a period-plausible VC5 register-color hypothesis for the original persistent EBP denominator. [same emitted code as probe 7]
probe 9 behavior; result=MISMATCH; diff=1155; shape=27.176220806794056: Probe 9: match the fallback decompiler lifetime: reuse iVar1 for the second-row pointer and pass param18 as the flip argument in all fallback calls.
probe 10 liveness; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 10: keep a branch-local fallbackBottom carrier but pass param18 explicitly as the fallback flip argument, isolating lifetime from the function-wide iVar1 spill. [same emitted code as probe 8]
probe 11 liveness; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 11: use the source-width/source-height aliases through all scale, tiling-count, and cursor-update sites to test persistent register carriers instead of repeated parameter reloads. [same emitted code as probe 10]
probe 12 control-flow; result=MISMATCH; diff=1144; shape=77.22567287784679: Probe 12: use the decompiler-supported iVar6/bVar2 ceil-division sequence with assignment before increment, matching original source-line bands 451-457.
probe 13 liveness; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 13: mark read-only source width/height parameters register, testing period VC5 parameter-coloring control for the original EBP/stack denominator schedule. [same emitted code as probe 11]
probe 14 liveness; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 14: mark the long-lived flip carriers register, testing whether VC5 assigns the original EBX/EBP pair instead of reloading homes before every blit call. [same emitted code as probe 13]
probe 15 liveness; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 15: compute the Ghidra-supported int geometry intermediates iVar4/iVar13/iVar8/iVar14/iVar5, then materialize the proven long local fields. [same emitted code as probe 14]
probe 16 abi; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 16: correct the reviewed DibBlt return ABI from long to void; the original decorated symbol and donor declaration are void.
probe 17 control-flow; result=MISMATCH; diff=1130; shape=76.66666666666667: Probe 17: move the transparent-arm return outside its positive-height guard, testing whether VC5 merges the zero-height path into the original common return while keeping the explicit arm result.
probe 18 layout; result=MISMATCH; diff=1111; shape=78.55626326963906: Probe 18: model the proven TRANSINFO AnyTrans anchor and use its address in fallback row arithmetic, matching the decompiler's source-level pointer form. [same emitted code as probe 16]
probe 19 control-flow; result=MISMATCH; diff=1114; shape=78.1316348195329: Probe 19: use the original decompiler's empty for-loop wrap form instead of while, testing source loop syntax as a CFG and scheduling input.
probe 20 abi; result=MISMATCH; diff=1104; shape=75.4201680672269: Probe 20: type the five geometry locals int, matching the decompiler's iVar arithmetic and proven 32-bit widths, while retaining long parameters. [same emitted code as probe 4]
probe 21 other; result=MISMATCH; diff=1179; shape=70.64989517819707: Probe 21: remove named scale locals and inline the Ghidra nested scale expressions after int geometry materialization, testing the no-scale-local source model. [same emitted code as probe 2]
probe 24 abi; result=MISMATCH; diff=1285; shape=33.67556468172484: Hypothesis 1: restore the complete Ghidra-supported source shape: function-scope saved flip locals, bool ceil flags, nested fixed-point scales, AnyTrans fallback cursor, and nontransparent-first branch order; define the proven AnyTrans head field locally.
probe 27 liveness; result=MISMATCH; diff=1104; shape=75.4201680672269: Hypothesis 2: split xscale and yscale declaration from initialization, testing whether delayed local initialization reproduces the original EBP source-width carrier and initial scheduling. [same emitted code as probe 23]
probe 29 context; result=MISMATCH; diff=1104; shape=75.4201680672269: Hypothesis 3: restore the original Dib.cpp standard-header context by adding stdlib.h and string.h beside the existing Win32/stdio/memory headers, testing compiler-context effects without changing the source model. [same emitted code as probe 27]
probe 31 other; result=MISMATCH; diff=1270; shape=36.25: Hypothesis 4: use the complete decompiler local graph with top-scope iVar4/iVar5/iVar8/iVar13/iVar14, top-scope saved flip values, bool ceil flags, and nested scales, while retaining the binary-supported transparent-first source arm and fallback pointer split.
probe 35 liveness; result=MISMATCH; diff=1104; shape=75.4201680672269: Hypothesis 5: move xscale and yscale declarations with their initializers before every geometry local, testing whether declaration order gives the original early EBP parameter carrier. [same emitted code as probe 34]
probe 37 control-flow; result=MISMATCH; diff=1104; shape=75.4201680672269: Hypothesis 6: remove the transparent-arm early return and use the single final product return, testing whether VC5 merges the original shared fallback/zero-count epilogue while preserving the eight call sites. [same emitted code as probe 35]
probe 39 liveness; result=MISMATCH; diff=1109; shape=36.75213675213675: Hypothesis 7: name the transparent-arm bottom-row destination as a per-outer-iteration topY local, matching the original LEA/store before the inner loop and reusing it in both top-half calls.
probe 41 liveness; result=MISMATCH; diff=1142; shape=44.04255319148936: Hypothesis 8: reuse the dead param_19 home for the transparent-arm top-row destination after preserving its original value in iVar3, matching the original EBX carrier plus [esp+78] LEA/store.
```
<!-- end-recovered:73eb0968a33761aea78e -->

<!-- recovered:748bb52cf2c33e564995 -->
### `b25c5800db4c` `src/scratch/004390A0_TileDibBlt.cpp:1-18`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004390A0 TileDibBlt - direct reconstruction from packet and decompiler.
// Probe summary:
// - The source restores the binary's eight cdecl blit calls and quadrant order.
// - Scale setup before coordinate wrapping restores the 0x1c frame.
// - Int geometry locals reproduce the best emitted code. Long versions are
//   codegen duplicates.
// - Direct scale expressions, alternate fallback row pointers, register
//   hints, ABI spelling, and loop forms did not improve the result.
// - The fallback pointer split is a behavior hypothesis. Its codegen is worse.
// Clean checkpoint: 1254/1265 bytes, 75.42% shape, 8/8 calls, 0x1c frame.
// Current blocker: VC5 stack-home, register, and loop-body scheduling differs.
// TU captain, 2026-08-26, owner sa-c6a4d383-r1:
// - Delayed scale expressions worsened the result to 1179 bytes.
// - Parameter-home scale caching, split assignments, and narrow scale types
//   gave 1112, 1104, and 1104 bytes. The latter two were codegen duplicates.
// - A decompiler-shaped row-origin split gave 1111 bytes and a 15-byte escape.
// - The clean source remains 1104 bytes different, 1254/1265 bytes, with
//   8/8 ordered calls, a 0x1c frame, and the correct owner symbol.
```
<!-- end-recovered:748bb52cf2c33e564995 -->

## Open questions

- The original nontransparent arm has two destination Y values for each tile:
  the current tile origin for the bottom source part and that origin plus the
  bottom destination height for the top source part. The Ghidra listing and
  original calls prove this split. The prior module body passed the latter to
  all four calls. The living source now keeps the split with direct arithmetic
  and no pointer overlay.
- The source keeps the proven geometry order: scale setup, coordinate wrap,
  split-width and split-height calculations, then tile-count calculation.
  Explicit per-outer-loop `top_y` storage was tested and rejected. It changed
  the natural VC5 result to 1111 differing bytes from the 1097-byte result.

## Next useful approaches

- Keep the corrected Y behavior and natural geometry order. Investigate the
  first prologue scheduling hunk only after a separate source or ABI fact is
  proved. Do not restore the rejected pointer-based fallback or loop-local
  `top_y` storage.

## Worker updates

- 2026-08-29 `wave21-dib-integrate`: corrected nontransparent destination Y
  behavior in `src/Dib.cpp`. Bottom quadrants use `dest_y`; top quadrants use
  `dest_y + SrcBotHgt`. The final check is a natural nonexact improvement:
  1097 differing bytes, 78.16% shape, 1259/1265 bytes, 8/8 calls, `0x1c`
  frame. The observed Dib TU audit is under
  `build/audits/workers/wave21-dib-integrate/dib/report.txt`.
