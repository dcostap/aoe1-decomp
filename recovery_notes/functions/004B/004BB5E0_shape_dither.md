# Recovery journal: 004BB5E0 `shape_dither`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Shape.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Shape.cpp`.
- Earlier recovery note: `recovery_notes/Shape_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:efe9f2a8b9936ba9978c -->
### `target-session` `build/target_sessions/004BB5E0_shape_dither.json:1-36`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=241; shape=89.79591836734694: Baseline current scratch reconstruction before new hypotheses; prior log says 380B and prologue aligned.
probe 2 control-flow; result=MISMATCH; diff=246; shape=81.63265306122449: Hypothesis 2: use four explicit clipped locals initialized from four original bounds, matching sibling shape_draw source model; test whether optimizer recovers original coordinate schedule.
probe 4 liveness; result=MISMATCH; diff=249; shape=88.43537414965986: Hypothesis 3: reorder four bound locals to sy1, sx2, sy2, sx1, matching the original emitted add order while keeping parameter-home clipping model.
probe 6 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 4: seed each bound local from x/y, then compound-add header offsets, to test whether source-level mutation preserves original y/x add schedule. [same emitted code as probe 1]
probe 8 context; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 5: restore the canonical full Shape.cpp Shape_Header and TShape member surface used by exact sibling donors; test translation-unit declaration context. [same emitted code as probe 6]
probe 10 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 6: keep sx1 in a named register-backed original and use one separate clipped x local, allowing VC5 to coalesce only the dead x home while retaining the other parameter mutations. [same emitted code as probe 8]
probe 12 layout; result=MISMATCH; diff=344; shape=83.78378378378379: Hypothesis 7: replace aggregate ClipRect initialization with four explicit member assignments, matching the exact SetClipRect donor's period source style.
probe 14 liveness; result=MISMATCH; diff=249; shape=89.1156462585034: Hypothesis 8: initialize each bound from the header field, then compound-add the x/y parameter, testing alternate VC5 expression-tree scheduling.
probe 16 liveness; result=MISMATCH; diff=247; shape=89.1156462585034: Hypothesis 9: reorder parameter-home assignments so clipped x is assigned after y/shape_num/sy2, testing whether VC5 keeps sx1 in ECX and loads rect.left into EBP.
probe 18 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 10: name the assigned Shape_Header pointer before reading bounds, testing whether stable header ownership changes coordinate scheduler or preserves the original member reload basin. [same emitted code as probe 10]
probe 20 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 11: mark the four original bounds const, testing whether VC5 treats them as immutable register values and leaves clipped incoming homes in memory. [same emitted code as probe 18]
probe 22 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 12: apply period register hints to the four register-carried original bounds, testing a controlled register-color basin change. [same emitted code as probe 20]
probe 24 liveness; result=MISMATCH; diff=249; shape=88.43537414965986: Hypothesis 13: split coordinate declarations and assign in original emitted add order sy1, sx2, sy2, sx1 while keeping the existing parameter-home clipping source. [same emitted code as probe 4]
probe 26 liveness; result=MISMATCH; diff=244; shape=89.1156462585034: Hypothesis 14: assign shape_num before clipped x, then y and sy2, testing parameter-home assignment order as a source-level register allocator axis.
probe 28 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 15: use a local reference alias for clipped x, testing whether addressable incoming x storage preserves sx1 in ECX without volatile or assembly. [same emitted code as probe 22]
probe 31 layout; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 17: split tagRECT declaration from aggregate assignment, testing local lifetime and scheduler timing without changing the typed aggregate. [same emitted code as probe 28]
probe 33 liveness; result=MISMATCH; diff=271; shape=83.91608391608392: Hypothesis 18 diagnostic only: force clipped x through a volatile local to test whether the original x-home/register topology is compiler-enforced; do not retain without source evidence.
probe 35 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 19: reverse arithmetic operand order to header-bound plus coordinate, a natural source spelling that may alter VC5 add scheduling. [same emitted code as probe 31]
probe 37 liveness; result=MISMATCH; diff=284; shape=60.54421768707483: Hypothesis 20: initialize clipped sy2 directly from ymax, then copy it to sy2_orig, testing reversed original/clipped declaration order and local-home allocation.
probe 41 behavior; result=MISMATCH; diff=246; shape=81.63265306122449: Replace forbidden incoming-parameter reuse with typed clip_x1/clip_y1/clip_x2/clip_y2 locals; preserve the natural typed shape and draw-area model. [same emitted code as probe 2]
probe 43 control-flow; result=MISMATCH; diff=246; shape=81.63265306122449: Use typed clip locals with a positive visible-area guard; this matches the decompiler-supported original predicate shape without parameter-home reuse. [same emitted code as probe 41]
probe 45 behavior; result=MISMATCH; diff=246; shape=81.63265306122449: Hypothesis 21: use the period source literal "RGL_shape_draw" instead of an unresolved extern symbol; test the observed Check_shape string without raw addresses.
probe 48 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 1: restore binary-proven incoming parameter-home reuse for clipped x/y bounds, matching Ghidra's parameter assignments and testing whether the coordinate-add schedule is the original source shape. [same emitted code as probe 40]
probe 49 liveness; result=MISMATCH; diff=249; shape=88.43537414965986: Hypothesis 2: order the four coordinate declarations as binary/Ghidra emits them (sy1, sx2, sy2, sx1), while retaining parameter-home clipping, to test declaration-driven add scheduling. [same emitted code as probe 24]
probe 50 layout; result=MISMATCH; diff=249; shape=88.43537414965986: Hypothesis 3: separate coordinate declarations from assignments and assign in the observed y1, x2, y2, x1 order, testing whether statement order controls the coordinate-add schedule without changing behavior. [same emitted code as probe 49]
probe 51 behavior; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 4: use long zero literals for the two clipped lower-bound assignments, testing whether VC5 selects the original immediate-zero store and test topology. [same emitted code as probe 48]
probe 52 liveness; result=MISMATCH; diff=247; shape=89.1156462585034: Hypothesis 5: reorder clipped-bound assignments to y1, x2, y2, x1, testing whether parameter-home write order drives the original coordinate-add and rect-left register schedule. [same emitted code as probe 16]
probe 53 liveness; result=MISMATCH; diff=249; shape=88.43537414965986: Hypothesis 6: combine decompiler-order coordinate initializers with register-qualified x/y parameters, testing whether source parameter register hints recover the original y1/x2/y2/x1 scheduling basin. [same emitted code as probe 50]
probe 54 behavior; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 7: reverse coordinate-add operand spelling to header-bound plus caller coordinate in the binary-proven parameter-home model, testing VC5 expression-tree scheduling. [same emitted code as probe 51]
probe 55 behavior; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 8: compare each original bound local against the clip rectangle before assigning the mutated parameter home, matching Ghidra's iVar-to-parameter predicate shape and testing register-home scheduling. [same emitted code as probe 54]
probe 56 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 9: mark original coordinate bounds const while retaining parameter-home clipping, testing whether immutability keeps ECX/EBX/EDX/EAX bounds live through the clip schedule. [same emitted code as probe 55]
probe 57 layout; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 10: declare the clipped y2 local before parameter-home assignments and assign it with the other bound copies, testing whether local declaration timing recovers the original home and register topology. [same emitted code as probe 56]
probe 58 liveness; result=MISMATCH; diff=249; shape=88.43537414965986: Hypothesis 11: preload x/y into named base locals before decompiler-order y1/x2/y2/x1 calculations, testing whether early parameter reads preserve original EBX/EBP colors while recovering add order. [same emitted code as probe 53]
probe 59 control-flow; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 12: use the decompiler-supported positive visible-area guard (x <= x2 && y <= y2) with the parameter-home model, testing whether VC5 emits the original reversed compare operands and CFG layout. [same emitted code as probe 57]
probe 60 liveness; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 13: name the assigned Shape_Header pointer before coordinate loads, testing whether a local owner changes the field-load/add schedule in the parameter-home basin. [same emitted code as probe 59]
probe 61 control-flow; result=MISMATCH; diff=241; shape=89.79591836734694: Hypothesis 14: nest the two positive visible-area comparisons instead of using &&, testing whether the original failure-edge layout came from nested source guards. [same emitted code as probe 60]
```
<!-- end-recovered:efe9f2a8b9936ba9978c -->

<!-- recovered:0e85cf5d6d0c455e1383 -->
### `0923cad7edb1` `src/scratch/004BB5E0_shape_dither.cpp:1-44`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004BB5E0 TShape::shape_dither
// Source: Shape.cpp lines 2761-2801
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// v1-11: prior passes — frame mismatches, wrong register layout, broad drift.
// v12: removed int ret local, direct returns — sub esp still 0x18, 384B.
// v13: variable reuse refactor — VC5 over-optimized to 336B (52B short).
// v14: fixed sy2_orig/sy2 separation—still 336B, VC5 eliminates redundant
//   comparisons and bounds checks through constant propagation.
// normal-BB5E0-r1 baseline: the old source rebuilt 335B with a 0x08 frame.
// Materializing the local tagRECT before Check_shape restored the 0x14 frame,
// the early ClipRect copy, and the original prologue block.
// The aggregate tagRECT copy improved the candidate to 380B and 241 strict
// differing bytes. Direct shape_header member ownership retained this basin.
// Swapped pointer-add operands and explicit x/y base locals were duplicates.
// Reordered bound declarations widened register and parameter-home drift.
// Split coordinate declarations from their assignments; this was a codegen duplicate and was rolled back.
// sa-bc555cb0-r1 fresh pass: baseline revalidated at 380B, 241 strict bytes,
// 0x14 frame, and all three direct calls aligned. Explicit clipped locals,
// declaration and assignment reorders, header aliases, full sibling class
// declarations, split RECT initialization, register/const hints, and reversed
// add operands were duplicate or worse basins. A volatile clipped-x test was
// also worse at 368B/271 bytes and is rejected as compiler steering. Adding
// <windows.h> failed because the local tagRECT then redefined the SDK type.
// No natural source axis moved the first +0040 coordinate-add hunk.
// BLOCKER: remaining drift is the coordinate-add and local-home schedule after
// the exact prologue. All three direct calls and the stack frame are aligned.
// sa-a35cfb68-r1 fresh pass: the pinned reconstruction reused incoming x, y,
// and shape_num homes as clipped coordinates. That form is not retained under
// the source policy. Typed clip locals with a positive visible-area guard keep
// the natural ownership model, but rebuild at 380B/246 bytes. The old 241-byte
// basin is therefore metric-only evidence, not the clean source model.
// sa-e1e7aa19-r1 revisit: replacing the unresolved string symbol with the
// period literal "RGL_shape_draw" was codegen-identical at 380B/246 bytes.
// The pinned typed-local source was restored; the remaining gap is unchanged.
// sa-8ce9d19d-r1 revisit: the binary-supported parameter-home form from the
// Ghidra reconstruction rebuilt 380B/241 bytes, with 89.80% shape similarity,
// 67.83% exact-block coverage, and all three calls aligned. Decompiler-order
// coordinate declarations, base-coordinate aliases, register-qualified inputs,
// and nested guards were worse or codegen duplicates. Reversed add operands,
// original-bound predicates, const bounds, long zero literals, and a named
// header alias were codegen duplicates. The remaining mismatch starts at the
// coordinate-add schedule; this source keeps the best natural binary basin.
```
<!-- end-recovered:0e85cf5d6d0c455e1383 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
