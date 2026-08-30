# Function notes: 0052CAF0 `draw_multi_object_outline`

Module notes: `decomp_notes/tvw_main_module.md`.

## Recovered attempt history

<!-- recovered:8dbbf7c06f750fb22085 -->
### `d050eea3c` `src/tvw_main.cpp:2-2`

Mapping: `strong`. next mapped function definition is draw_multi_object_outline at old line 44.

```text
// Definitions follow the PDB source order.  The normal owners are kept in
```
<!-- end-recovered:8dbbf7c06f750fb22085 -->

<!-- recovered:e5fa89f5053182bd56c1 -->
### `d050eea3c` `src/tvw_main.cpp:21-21`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 0052CAF0 remains scratch. Its natural body preserves all 28 wall calls and
```
<!-- end-recovered:e5fa89f5053182bd56c1 -->

<!-- recovered:7e10770dd44c1c1eea34 -->
### `d050eea3c` `src/tvw_main.cpp:23-23`

Mapping: `strong`. next mapped function definition is draw_multi_object_outline at old line 44.

```text
// drift with 14 caller-saved register-color bytes each.  The other eight
```
<!-- end-recovered:7e10770dd44c1c1eea34 -->

<!-- recovered:b45641175b01a02fb7d9 -->
### `6a2aef2e2` `src/tvw_main.cpp:1-9`

Mapping: `strong`. next mapped function definition is draw_multi_object_outline at old line 29.

```text
// Authentic source module for C:\\msdev\\work\\age1_x1\\tvw_main.cpp.
// this one compiler-facing source file.  The original executable is the
// behavior oracle; nonexact bodies remain documented below.
//
//
// The nearby 00495470/00495490 destructor entries are compiler-generated.
//
// has a 1203-byte strict difference. 0052D600 and 0052D970 remain accepted
// normal bodies are exact in the grouped module check.
```
<!-- end-recovered:b45641175b01a02fb7d9 -->

<!-- recovered:ca10b607a0e825455d0f -->
### `target-session` `build/target_sessions/0052CAF0_draw_multi_object_outline.json:1-23`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1081; shape=51.851851851851855: Baseline clean source: exact size/frame, 28 ordered calls, but 1081-byte diff; first divergence at +18 around master-id guard and get_selection_area stack homes.
probe 2 control-flow; result=MISMATCH; diff=1197; shape=47.265625: Hypothesis 1: use natural abs(int) for both distances; original has branchless cdq/xor/sub abs lowering, unlike baseline branchy manual abs.
probe 3 control-flow; result=MISMATCH; diff=1196; shape=47.265625: Hypothesis 2: remove compiler-only distance locals and compare direct abs expressions; original keeps both branchless abs results in ESI/EAX with no distance-home stores.
probe 4 liveness; result=MISMATCH; diff=1275; shape=50.09708737864078: Hypothesis 3: remove the short master_id local and use direct global master_obj_id expressions; original PDB has no user master-id local and this may free the this register.
probe 5 abi; result=MISMATCH; diff=1078; shape=51.851851851851855: Hypothesis 4: replace the raw-storage inline accessor with the reviewed extern rge_base_game declaration; dossier says extern form can restore relocation and register behavior.
probe 6 layout; result=MISMATCH; diff=1239; shape=44.3359375: Hypothesis 5: route get_selection_area's fourth output through calc_row2, then copy it to end_row; target's fourth-output address is an original local home unlike baseline end_row.
probe 7 control-flow; result=MISMATCH; diff=1154; shape=52.25048923679061: Hypothesis 6: encode the original diagonal duplicate predicates literally as end_col < start_col followed by end_col <= start_col, instead of comparing the loop local.
probe 8 control-flow; result=MISMATCH; diff=1154; shape=52.25048923679061: Hypothesis 8: preserve the original impossible reverse predicate as an explicit cleanup-return block before the second diagonal loop; target has a second compare and edge to shared cleanup. [same emitted code as probe 7]
probe 9 control-flow; result=MISMATCH; diff=1081; shape=51.851851851851855: Hypothesis 9: mirror the decompiler's horizontal setup: assign end_row from main_row and compare/store main_row directly, instead of routing through end_col alias. [same emitted code as probe 1]
probe 10 liveness; result=MISMATCH; diff=1197; shape=47.265625: Hypothesis 10: initialize int distance locals at their first use with natural abs; declaration timing may keep branchless results in registers like the original. [same emitted code as probe 2]
probe 11 control-flow; result=MISMATCH; diff=1223; shape=52.054794520547944: Hypothesis 12: make the unequal distance arm an else-if so VC5 can reuse the equality compare flags; original jumps from the equality cmp directly to a signed jl.
probe 12 control-flow; result=MISMATCH; diff=1081; shape=50.292397660818715: Hypothesis 13: reverse the unequal distance spelling to row_distance < col_distance, matching original cmp/ jl operand order while retaining separate if topology.
probe 13 liveness; result=MISMATCH; diff=1081; shape=51.851851851851855: Hypothesis 14: delay master pointer declaration and initialization until after the master-id guard; original may scope this pointer after the early return. [same emitted code as probe 9]
probe 14 layout; result=MISMATCH; diff=1081; shape=51.851851851851855: Hypothesis 15: restore function-scope master declaration in the PDB/decompiler declaration order, before end_col/end_row, to change local-home allocation. [same emitted code as probe 13]
probe 15 liveness; result=MISMATCH; diff=1249; shape=52.5: Hypothesis 16: assign fallback pick coordinates in x, y, x-end, y-end order; original stores x to start_col before y conversion, then copies x to main_row and y to end_row homes.
probe 16 liveness; result=MISMATCH; diff=1249; shape=52.19885277246654: Hypothesis 17: name converted pick x/y values as int locals before assigning four traversal endpoints; original carries x across the y conversion and duplicates each result into homes.
probe 17 abi; result=MISMATCH; diff=1081; shape=51.851851851851855: Hypothesis 18: test the Ghidra int coordinate model with an int-pointer selection ABI; this isolates whether 32-bit int versus long controls branchless abs and homes.
probe 18 control-flow; result=MISMATCH; diff=1196; shape=47.265625: Hypothesis 19: combine the int coordinate model with direct natural abs expressions, testing whether VC5 then keeps the two abs results in ESI/EAX without distance homes. [same emitted code as probe 3]
probe 19 control-flow; result=MISMATCH; diff=1196; shape=47.265625: Hypothesis 20: cast long coordinate differences to int before abs, matching the original decompiler's int temporaries while retaining long API locals. [same emitted code as probe 18]
probe 23 context; result=MISMATCH; diff=1100; shape=44.2495126705653: Hypothesis 21: remove the now-unused stdlib header. Same-TU exact donor draw_wall_outline has no stdlib include; this tests period translation-unit context without changing source behavior.
probe 26 context; result=MISMATCH; diff=1100; shape=44.2495126705653: Hypothesis 1: use the period Windows SDK header and its tagPOINT/tagRECT definitions. This tests supported API translation-unit context without changing function behavior. [same emitted code as probe 23]
probe 29 abi; result=MISMATCH; diff=1081; shape=51.851851851851855: Hypothesis 2: restore the reviewed RGE_View/RGE_Main_View virtual surface through draw_multi_object_outline and command slots. This tests whether the canonical inherited vtable context changes body codegen. [same emitted code as probe 28]
probe 31 control-flow; result=MISMATCH; diff=1134; shape=56.53021442495127: Hypothesis 3: place the vertical dominant arm in source fall-through and the horizontal arm after it. Original CFG places the row-dominant body at +CD13 and jumps to the horizontal body at +CEB9.
```
<!-- end-recovered:ca10b607a0e825455d0f -->

<!-- recovered:a1e9444cfb3e40492953 -->
### `bb56c07fdf64` `src/scratch/0052CAF0_draw_multi_object_outline.cpp:1-67`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0052CAF0 draw_multi_object_outline (1385B)
// PDB: tvw_main.cpp, lines 39-210
//
// Baseline reconstruction from the original call order and the matching
// tvw_main.cpp donors.  The outline has four diagonal paths and two explicit
// edge paths for each non-diagonal orientation.
//
// Attempt log:
// - Baseline: typed player/master/view ownership, direct mouse and selection
//   calls, and explicit diagonal and edge outline paths.  All 28 calls align;
//   the remaining gap is structural, with a 0x38 frame versus 0x48 original.
// - Layout lead: named the binary-backed calculation and fixed-edge locals
//   and changed grid temporaries to int.  It improved size and frame, but
//   reduced code shape.  Restored the baseline source.
// - Left in scratch: call order is exact, but branch topology, frame locals,
//   and the global relocation remain unresolved.
// - Fresh r2 layout probe: restored the same-TU proven TPanel and RGE_View
//   offsets (+8C/+90 and +FC/+100); this changed only early field accesses.
// - Fresh r2 control-flow probe: tested the binary sentinel edge setup; it
//   reduced the byte diff but removed four real draw calls, so it was rolled back.
// - Fresh r2 liveness probe: named the binary boundary aliases while keeping
//   all 28 calls; size moved closer but shape moved farther, so it was rolled back.
// - Restored the binary diagonal nesting and duplicated edge-loop order guards;
//   this restored all 28 calls and improved structural coverage.
// - Scoped row-boundary and saved-end-row lifetime probes reached the frame
//   size, but changed early register homes; rolled back to the better basin.
// - Coordinate-home swap and direct abs spelling were tested and rolled back.
// - Final source: typed sentinel edge paths, 28 ordered calls, 0x44 frame versus
//   the original 0x48; remaining drift is structural and starts at the frame.
// - r4 ABI audit: used the landed canonical storage accessor so the global
//   loads now encode 0062C574 instead of an unresolved extern relocation.
// - r5 selection-home probe: let get_selection_area fill main_row as the
//   third coordinate and carry that x-end directly through the outline paths.
// - r6 moved the sentinel stores before distance selection, matching PDB lines
//   71/74 without changing the frame or call set.
// - r6 removed the compiler-only row_end alias and reused point.x for the
//   binary-proven horizontal row boundary; this removed the 20-byte excess.
// - r6 diagonal guard and operand forms were codegen duplicates. Best current
//   source is exact-size/frame with 28 calls and a 1081-byte strict diff.
// - Current matching pass: 19 meaningful probes tested distance lowering,
//   selection-home aliases, coordinate widths, fallback assignment order,
//   declaration scope, and branch topology.  Every probe was rolled back.
// - BINARY NOTE: The clean source emits 28 ordered calls, a 0x48 frame, and
//   all four saved registers.  Its first mismatch is at +0x18 because VC5
//   keeps this in ESI instead of the original EBP and chooses other output
//   homes for get_selection_area.
// - BINARY NOTE: The original distance block uses branchless signed-absolute
//   arithmetic in ESI/EAX.  Natural abs expressions entered a worse basin and
//   added 14 bytes, so the clean manual form remains pinned.
// - Claim probe: the real Windows SDK tagPOINT/tagRECT context changed the
//   result to 1100 bytes and 44.25% shape.  The local API clones remain closer.
// - Claim probe: the reviewed RGE_View/RGE_Main_View virtual surface was a
//   codegen duplicate.  It changed no emitted byte.
// - Claim probe: source fall-through for the row-dominant arm raised shape to
//   56.53% and exact blocks to 32.49%, but strict drift rose to 1134 bytes.
//   The clean source remains pinned.  This is a useful CFG lead, not a final
//   source model.
// - TU repair pass: fresh grouped validation keeps the target at 1100 strict
//   bytes, with 28 ordered calls, matching ownership, and no boundary escapes.
// - TU repair probes tested abs/labs/manual distance forms, endpoint copies,
//   declaration order, loop-index reuse, and the pre-r5 selection home. Each
//   result was worse or a codegen duplicate. The pinned source is restored.
// - Candidate proposal validates all eight exact neighbors. Accepted drift
//   0052D600 and 0052D970 remain unchanged at 14 bytes each.
// - Next lead: recover the original local-home and register basin from the
//   period tvw_main.cpp declaration and translation-unit context.  Do not add
//   aliases or fake volatility without new binary evidence.
```
<!-- end-recovered:a1e9444cfb3e40492953 -->
