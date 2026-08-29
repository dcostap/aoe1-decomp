# Recovery journal: 004C6400 `find_drop_location`

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


<!-- recovered:1b101fef55003f487966 -->
### `d050eea3c` `src/stat_obj.cpp:2937-2938`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004C6400 RGE_Static_Object::find_drop_location
// BINARY NOTE: the x and y outputs are float references in the shipped symbol.
```
<!-- end-recovered:1b101fef55003f487966 -->

<!-- recovered:8817320650a841dd47f8 -->
### `d050eea3c` `src/stat_obj.cpp:2990-2990`

Mapping: `strong`. comment lies after mapped function find_drop_location at old line 2934.

```text
                    // BINARY NOTE: success returns from inside the retry loop.
```
<!-- end-recovered:8817320650a841dd47f8 -->

<!-- recovered:c2fb9d7f073f49db909f -->
### `target-session` `build/target_sessions/004C6400_find_drop_location.json:1-35`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 2 control-flow; result=MISMATCH; diff=152; shape=93.05555555555556: Tested a binary-supported late success label: original success return follows the failure epilogue, so goto success was used to test block layout.
probe 3 layout; result=MISMATCH; diff=150; shape=93.48837209302326: Tested short retry counter because original uses cmp ax,32h while the clean int source emits cmp eax,32h; compare frame and full codegen.
probe 4 layout; result=MISMATCH; diff=149; shape=93.48837209302326: Added narrow outer retry counter after original cmp ax,2 evidence; tested both bounded-loop counter widths together.
probe 5 control-flow; result=MISMATCH; diff=149; shape=93.48837209302326: Tested an explicit outer backedge label because original ends the update block with signed jl to the retry entry, then falls through to the failure epilogue.
probe 7 variant; result=MISMATCH; diff=149; shape=93.48837209302326: variant lab build\variant_lab\004C6400_find_drop_location\20260817_130300: 64 variants, 32 invariant-eligible, 0 exact
probe 8 control-flow; result=MISMATCH; diff=149; shape=93.02325581395348: Hypothesis 1: Ghidra source evidence shows short outer index followed by if (1 < index) return 0 and an infinite loop; tested that natural source form.
probe 10 behavior; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 2: Ghidra decomp shows strict map bounds (*x < map_width and *y < map_height), while the source used >= on map-left operands; tested strict bounds.
probe 11 behavior; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 3: tested the Ghidra operand spelling directly (*x < map_width, *y < map_height) instead of equivalent map-left strict comparisons. [same emitted code as probe 10]
probe 12 liveness; result=MISMATCH; diff=172; shape=86.93693693693693: Hypothesis 4: Ghidra shows master radius terms written before existing radius values; tested master-first final radius update expressions.
probe 13 control-flow; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 5: Ghidra shows a positive terrain != -1 guard with a mismatch jump to the retry label; tested explicit retry goto and moved placement outside the terrain condition.
probe 14 behavior; result=MISMATCH; diff=165; shape=90.69767441860465: Hypothesis 6: matched Ghidra lower-bound operand order (zero <= x and zero <= y) instead of x/y-left comparisons.
probe 15 context; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 7: same-TU exact donors pass the stat_obj.cpp path as a direct string literal; tested direct pooled literals instead of a named static array.
probe 16 abi; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 8: exact stat_obj.cpp donors declare debug_rand with default C++ linkage and __cdecl; tested that reviewed same-TU declaration.
probe 17 liveness; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 9: Ghidra lists map as a function local; tested a function-scope typed map pointer with assignment inside the lower-bound guard.
probe 19 control-flow; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 10: original passable success uses a near jump to a success epilogue after failure; tested explicit success label/goto with current strict-bound source.
probe 20 control-flow; result=MISMATCH; diff=147; shape=94.4186046511628: Hypothesis 11: split placement/passable short-circuit into nested positive guards, testing whether VC5 places the success return after the retry/failure tail.
probe 21 control-flow; result=MISMATCH; diff=30; shape=96.22641509433963: Hypothesis 12: reran the Ghidra-indicated if (1 < outer) return 0; while(true) form with strict bounds and explicit terrain retry guard.
probe 22 control-flow; result=MISMATCH; diff=147; shape=93.95348837209302: Hypothesis 13: replaced do/while(true) with an equivalent infinite for loop around the Ghidra-style outer return guard, testing VC5 source-loop basin.
probe 23 liveness; result=MISMATCH; diff=30; shape=96.22641509433963: Hypothesis 14: with the Ghidra outer return-loop retained, expanded initial radius assignments may restore the original pre-push parameter FPU loads; tested radius_x = radius_x + master radius spelling. [same emitted code as probe 21]
probe 24 liveness; result=MISMATCH; diff=30; shape=96.22641509433963: Hypothesis 15: named initial x/y temporaries may preserve the original parameter-first x87 loads while retaining the late outer return loop.
probe 25 liveness; result=MISMATCH; diff=619; shape=95.75471698113208: Hypothesis 16: reversed initial radius assignment order may recover the original y-then-x FPU load order; tested y before x.
probe 26 liveness; result=MISMATCH; diff=30; shape=96.22641509433963: Hypothesis 17: declare radius_2x/radius_2y before the initial radius assignments to test the original FPU/local-home declaration basin. [same emitted code as probe 23]
probe 27 liveness; result=MISMATCH; diff=73; shape=92.45283018867924: Hypothesis 19: named expanded-radius temporaries may force parameter-first evaluation before master loads in the late outer-return source basin.
probe 28 control-flow; result=MISMATCH; diff=28; shape=97.16981132075472: Hypothesis 20: tested the equivalent outer >= 2 return spelling against the Ghidra 1 < outer condition, checking branch direction and late epilogue layout.
probe 30 control-flow; result=MISMATCH; diff=28; shape=97.16981132075472: Hypothesis 1: restore the Ghidra direct return 1 inside the passable-tile success guard instead of a source goto label; original line 3932 and jmp-to-success epilogue support this shape. [same emitted code as probe 28]
probe 32 control-flow; result=MISMATCH; diff=28; shape=97.16981132075472: Hypothesis 2: mirror the Ghidra nested positive terrain guard and nested placement/passable guard with direct success return; this tests source nesting while preserving original call order.
probe 34 behavior; result=MISMATCH; diff=28; shape=97.16981132075472: Hypothesis 3: use the original decompiler's character literal return '\x01' in the direct success arm; this tests return-width/literal typing without changing behavior or call topology. [same emitted code as probe 30]
probe 36 behavior; result=MISMATCH; diff=285; shape=90.8256880733945: Hypothesis 4: return the passableTile result directly after placement success; this tests whether the original AL already carries the required 1, but behavior evidence requires the original explicit == 1 guard.
probe 38 liveness; result=MISMATCH; diff=28; shape=97.16981132075472: Hypothesis 5: combine direct success return with function-scope declare-then-assign radius_2x/radius_2y; this tests declaration timing as the cause of the direct-return FPU schedule shift. [same emitted code as probe 34]
probe 40 behavior; result=MISMATCH; diff=5; shape=99.05660377358491: Hypothesis 6: explicitly cast the success literal to unsigned char at the existing success label; this tests return-width materialization while preserving the clean control-flow basin.
probe 41 behavior; result=MISMATCH; diff=5; shape=99.05660377358491: Hypothesis 7: use the C++ bool literal true at the success label; this tests the source return type's boolean spelling against the shipped unsigned-char result. [same emitted code as probe 29]
probe 42 control-flow; result=MATCH; diff=0; shape=99.52830188679245: Hypothesis 8: express the outer retry as while (outer < 2) with failure return after the loop and direct success return; the original tail's jl backedge plus fall-through failure supports this natural form.
probe 43 control-flow; result=MATCH; diff=0; shape=99.52830188679245: Exact-finish walkback A: reverted only the direct success return to the prior goto-success label while retaining while (outer < 2); tests whether direct return is necessary for the exact epilogue.
probe 44 control-flow; result=MISMATCH; diff=5; shape=99.05660377358491: Exact-finish walkback B: reverted only while (outer < 2) to the prior do-loop with inner outer>=2 return; the known 5-byte epilogue drift should return if the while form is decisive. [same emitted code as probe 41]
probe 47 abi; result=MATCH; diff=0; shape=99.52830188679245: Changed x and y outputs to float references. Dumpbin expects QAEEHAAM0 and standalone exact check matches 674 bytes. [same emitted code as probe 46]
```
<!-- end-recovered:c2fb9d7f073f49db909f -->

<!-- recovered:54665ad970705315f685 -->
### `7d614dbca5c7` `src/scratch/004C6400_find_drop_location.cpp:1-48`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004C6400 RGE_Static_Object::find_drop_location
// Fresh typed reconstruction from stat_obj.cpp:3881-3940.
// The candidate keeps the canonical argument order, master/object ownership,
// map bounds, placement virtual, and passable-tile virtual from the binary.
// Attempt log:
// - baseline typed reconstruction reached the original 0x8 frame, all four
//   saved registers, and the complete ten-call set. It emits 672 versus 674
//   bytes with 84.65% instruction-shape similarity.
// - inlining or splitting the random side expression was codegen-neutral.
// - grouped y-offset arithmetic made the body 704 bytes and was rolled back.
// - a shared x-coordinate tail removed two debug_rand calls and was rolled
//   back. The four separate calls are required by the original switch.
// - binary final-loop stores update the expanded radii, not the drop center;
//   restored typed radius updates before testing the ordered object calls.
// - prior validation: 548 positional diff bytes; call sites and targets align.
//   Remaining drift starts at random side scaling (original mov/shl/imul).
//   The natural typed spatial reconstruction remains in scratch.
// - radius ownership probe kept 548 positional-diff bytes and the 0x8 frame;
//   shape improved to 85.58% and edit diff to 176, so the radius form remains.
// - inlining the side-selection debug_rand call reproduced the original
//   mov/magic-multiply/shl division sequence; this removed the early hunk and
//   reduced positional diff to 178 bytes.
// - parenthesizing case-1 as drop_y + (scaled_y - radius_y) stopped VC5 from
//   tail-sharing the case-0 y calculation; both original y blocks now align.
// - spelling final updates as existing-radius + master increment preserved the
//   typed ownership and restored the original 674-byte function size; current
//   best is 152 positional bytes, 93.06% shape, and all ten calls aligned.
// - remaining drift begins at the first bound-failure branch displacement and
//   includes late block/return layout; no call, frame, or size uncertainty.
// - Restored the named stat_obj.cpp debug source. The former raw address was
//   diagnostic data plumbing.
// - revisit: signed short retry counters reproduce the original cmp ax,32h
//   and cmp ax,2 forms; both counters improve the strict diff from 152 to
//   149 bytes and shape from 93.06% to 93.49% without changing size, frame,
//   saved registers, or calls. The first late-success label test was neutral
//   in the old loop basin.
// - revisit r2: a 64-variant lab covered counter widths, passable tests,
//   retry conditions, radius update forms, and outer conditions. No variant
//   matched. Ghidra-supported strict map bounds and a positive terrain guard
//   improved the clean source to 147 differing bytes and 94.42% shape.
// - Ghidra-supported `if (outer >= 2) return 0; do { ... } while (true)` fixed
//   the late loop and return layout. It reduced the diff to 28 bytes and
//   raised shape to 97.17%; the exact late body now spans +00CA through +0296.
// - A binary-supported success goto after the infinite loop fixes the initial
//   FPU schedule. The result is 5 differing bytes and 99.06% shape. A local
//   success result and braces were neutral. The remaining bytes move `mov al,1`
//   across the success epilogue pops.
// - final validation follows this source and the documented probe.
```
<!-- end-recovered:54665ad970705315f685 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
