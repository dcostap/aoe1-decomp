# Recovery journal: 00436C30 `set_world`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/diam_map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\diam_map.cpp`.
- Earlier recovery note: `recovery_notes/diam_map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:6ed448b672c492c44aa1 -->
### `target-session` `build/target_sessions/00436C30_set_world.json:1-77`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=971; shape=66.66666666666667: Baseline current natural reconstruction: 997-byte rebuild, 7/7 ordered calls, frame 0x10, broad first mismatch at prologue; map-row field semantics and x87 topology remain unresolved.
probe 2 behavior; result=MISMATCH; diff=985; shape=60.99290780141844: Restored binary-proven image-line tile_row store, direct short map dimension sum, row col_step/draw_step/num_tiles/ratio semantics, corrected map ratios, and source-row else update. This tests whether semantic field ownership closes the structural gap.
probe 4 layout; result=MISMATCH; diff=971; shape=66.66666666666667: Focused dimension hypothesis: remove the temporary map_hgt and compute map_tile_row_cnt from the two stored short fields. This isolates the original short-width add/dec sequence.
probe 5 liveness; result=MISMATCH; diff=984; shape=67.02127659574468: Tested one float local for the projected tile row: initialize it from map_row_step*0.5 when needed, cast it for the row index, and increment it by map_row_step. This tests the original persistent x87 loop value instead of two named float locals.
probe 7 liveness; result=MISMATCH; diff=969; shape=67.02127659574468: Tested explicit reuse of the dead world parameter as the image-line counter, with the float col_step as the persistent row projection. This follows the original parameter-home writes and loop-header x87 lifetime shown by the oracle.
probe 9 liveness; result=MISMATCH; diff=979; shape=64.8936170212766: Removed the named line-length local and reread the typed image-line member at the arithmetic site. This tests whether VC5 keeps the original short in a register rather than spilling it into the parameter home.
probe 12 behavior; result=MISMATCH; diff=959; shape=67.02127659574468: Added the omitted binary-proven map_image_lines[image_line].tile_row store, without changing the existing projection expressions. This isolates ownership of the input line record from codegen tuning.
probe 13 behavior; result=MISMATCH; diff=962; shape=67.02127659574468: Corrected the two final ratio sources to the decompiler-supported map_tile_draw_wid/map_image_hgt and map_image_hgt/map_tile_row_cnt relationships. This tests late field ownership without changing the loop.
probe 15 control-flow; result=MISMATCH; diff=968; shape=67.02127659574468: Rewrote the second pass to update source_row only in the drawn-row arm. This matches the oracle's mov edi,ebx/jump topology and avoids a per-iteration source temporary.
probe 16 behavior; result=MISMATCH; diff=966; shape=65.60283687943263: Reconstructed the tile-row projection fields from binary x87 dependencies: col_step=row_length/line_width, draw_step=1/col_step, num_tiles=line_width/draw_step, ratio=draw_step/line_width, and col_extra uses ratio versus zero or col_step*0.5. This keeps the persistent row coordinate separate.
probe 18 liveness; result=MISMATCH; diff=950; shape=65.95744680851064: Removed the first-pass table_row pointer alias and used direct typed map_tile_rows[row] member expressions. The oracle reloads the array owner before nearly every store, so this tests canonical row ownership and address scheduling.
probe 19 liveness; result=MISMATCH; diff=877; shape=71.27659574468085: Removed the second-pass destination pointer alias and used direct indexed row members for both source and destination. This tests whether VC5 preserves the oracle's shared array base plus separate byte offsets.
probe 20 control-flow; result=MISMATCH; diff=905; shape=73.75886524822695: Moved the map_tile_rows image_line assignment after row-length and draw-width calculation. The oracle writes map_image_lines.tile_row early but starts the destination row block only at its later line-291 band.
probe 21 layout; result=MISMATCH; diff=905; shape=73.75886524822695: Removed the map_hgt temporary while keeping direct short field assignment and sum. This tests whether the extra frame slot comes from a named map dimension rather than row projection locals.
probe 22 liveness; result=MISMATCH; diff=907; shape=74.11347517730496: Reused col_step as the persistent projected row and removed the separate tile-row coordinate, while keeping a scoped row-length float for the x87 ratio. This tests the oracle's loop-carried FPU value and reduces local lifetime pressure.
probe 23 liveness; result=MISMATCH; diff=907; shape=74.822695035461: Reused the incoming world parameter home as the image-line counter while retaining direct row indexing and loop-carried col_step. This tests the oracle's repeated parameter-home writes against the high-pressure direct-array source.
probe 24 liveness; result=MISMATCH; diff=909; shape=81.20567375886525: Removed the draw_step local and repeated its typed field expression at the width, store, and tile-count sites. This tests whether the oracle's x87 stack carries draw_step without a named home.
probe 25 liveness; result=MISMATCH; diff=906; shape=76.67844522968198: Removed the remaining ratio local and kept the typed projection expressions inline. This tests whether the original four-slot frame is recovered when both x87 intermediates remain expression results.
probe 27 variant; result=MISMATCH; diff=906; shape=76.67844522968198: Grouped follow-up variant: late destination image_line store, persistent col_step, parameter-home image index, and inline draw-step expressions. This tests whether the independently useful source forms cohere into the original frame and line-band topology.
probe 29 behavior; result=MISMATCH; diff=898; shape=79.7872340425532: Corrected first-pass tile-row field meanings while retaining the direct-indexed source shape: col_step=tile/line ratio, num_tiles=line/draw_step, ratio=draw_step/line, and col_extra tests the stored ratio. This tests semantic ownership against the strongest structural source.
probe 30 liveness; result=MISMATCH; diff=898; shape=79.7872340425532: Introduced a typed image-line pointer alias for line_len and tile_row, matching the oracle's carried image-line address while keeping direct tile-row stores. This tests input-record address liveness separately from projection semantics.
probe 31 liveness; result=MISMATCH; diff=898; shape=79.7872340425532: Applied register to the read-only line_len local, testing whether VC5 keeps the original short image-line width in EDI instead of spilling it into the reused parameter home. [same emitted code as probe 30]
probe 32 liveness; result=MISMATCH; diff=902; shape=80.85106382978724: Anchored col_step as the typed destination field and derived draw_step from that stored field, removing the named ratio local. This tests the oracle's early row+8 store and persistent x87 ratio.
probe 33 liveness; result=MISMATCH; diff=902; shape=80.85106382978724: Removed line_width and tile-row float intermediates from the projection expressions, using typed short casts directly. This tests source operand order for the oracle's row-length-then-line-length FILD pair.
probe 34 liveness; result=MISMATCH; diff=883; shape=80.1418439716312: Swapped the row conversion and image-line length declaration order while preserving source semantics. This tests whether VC5 selects EDI for line_len and emits the oracle's load-before-FTOL schedule.
probe 35 liveness; result=MISMATCH; diff=861; shape=80.1418439716312: Split col_step declaration from its zero assignment after map_row_step computation. This tests the oracle's integer zero store at local_c before FIDIV and avoids a global zero constant load.
probe 36 context; result=MISMATCH; diff=861; shape=80.1418439716312: Replaced the literal tile_row zero with the binary-referenced DAT_0056f5fc zero global. The oracle loads that symbol before the image-height guard and again in the col_extra fallback.
probe 37 liveness; result=MISMATCH; diff=737; shape=80.49645390070921: Removed the image-line pointer alias and used direct typed member access for line_len and tile_row. This tests whether freeing the address register lets VC5 color line_len as the oracle's EDI value.
probe 38 control-flow; result=MISMATCH; diff=737; shape=80.49645390070921: Named the second-pass draw byte before its zero test. This tests whether VC5 emits the oracle's MOV AL/TEST/JZ branch instead of a direct CMP byte and removes the copied-row address mismatch.
probe 39 control-flow; result=MISMATCH; diff=852; shape=80.85106382978724: Removed the second-pass source temporary and updated source_row only in the drawn-row arm. This directly tests the oracle's retained EDI source index and its no-move draw-test block.
probe 41 behavior; result=MISMATCH; diff=839; shape=80.49645390070921: Corrected final map_col_ratio/map_row_ratio sources on the strongest direct-array source, testing the decompiler-supported image-height relationships without changing first-pass scheduling.
probe 43 liveness; result=MISMATCH; diff=737; shape=80.49645390070921: Tested a register zero local for the two entry null guards, aiming to reproduce the oracle's EDI zero color and preserve the later EBX row accumulator.
probe 44 liveness; result=MISMATCH; diff=737; shape=80.49645390070921: Split tile_row declaration from its zero assignment before the image-height guard. This tests whether VC5 emits the oracle's local zero home and removes the pre-guard global zero load.
probe 45 liveness; result=MISMATCH; diff=870; shape=72.69503546099291: Bound a local ratio to the col_step field assignment in one expression, then derived draw_step from that ratio. This tests whether VC5 keeps the ratio on x87 while also preserving the destination field.
probe 47 context; result=MISMATCH; diff=823; shape=78.72340425531915: Replaced unresolved extern float globals with their binary-proven absolute addresses as a bounded relocation hypothesis. This tests whether the remaining strict drift is relocation identity rather than source topology.
probe 48 context; result=MISMATCH; diff=737; shape=80.49645390070921: Marked the three binary read-only float globals const. This tests whether period-correct read-only declarations recover the original global load scheduling and relocation identity.
probe 49 liveness; result=MISMATCH; diff=737; shape=80.49645390070921: Reused the dead world parameter home as the image-line counter on the current direct-array field reconstruction. This tests the oracle's parameter-home writes while preserving corrected row field semantics.
probe 51 liveness; result=MISMATCH; diff=880; shape=80.85106382978724: Moved line_len declaration before row conversion in the direct-array source, testing the oracle's image-line load before FTOL despite the stronger metric basin from the opposite declaration order.
probe 53 behavior; result=MISMATCH; diff=836; shape=82.62411347517731: Corrected final ratios to draw_height/map_image_hgt and map_image_hgt/map_tile_row_cnt. This preserves the live draw-height x87 value that the oracle carries into the two final stores.
probe 54 liveness; result=MISMATCH; diff=836; shape=82.62411347517731: Used a register short zero local for the final map_tile_draw_wid zero guard. This tests the oracle's CMP AX,DI form and possible EDI zero color without changing behavior.
probe 57 behavior; result=MISMATCH; diff=876; shape=80.1418439716312: Reconstructed the original FPU dataflow: col_step is the persistent row accumulator, line length loads before row conversion, row col_step stores row_len/line_len, ratio stores draw_step, and tile_row=draw_wid assignment is removed.
probe 58 liveness; result=MISMATCH; diff=825; shape=74.64788732394366: Added a named zero float local for the binary's initial zero FPU load and col_extra fallback, while retaining col_step as the row accumulator.
probe 60 control-flow; result=MISMATCH; diff=864; shape=84.7517730496454: Restored the original first-pass statement topology: load line length before row conversion, compute draw_step from an inline reciprocal of row_len/line_len, and delay image-line and row-field stores until after draw-width conversion.
probe 61 liveness; result=MISMATCH; diff=831; shape=86.52482269503547: Named row_ratio without moving its field store, testing whether VC5 preserves the original row_len/line_len FPU temporary and delayed first-pass stores.
probe 62 behavior; result=MISMATCH; diff=884; shape=85.46099290780141: Applied the binary FPU row ownership: row is converted from the persistent col_step accumulator, ratio stores draw_step, and the separate tile_row/draw_wid accumulator is removed.
probe 63 liveness; result=MISMATCH; diff=746; shape=78.4452296819788: Retained binary row=col_step ownership and reintroduced the independent zero float local to test whether the original initial zero FPU load can coexist without changing the frame.
probe 64 liveness; result=MISMATCH; diff=746; shape=78.4452296819788: Applied register to the loop-invariant zero fallback value, testing whether the original zero FPU live value can avoid the extra local frame while preserving row=col_step. [same emitted code as probe 63]
probe 65 liveness; result=MISMATCH; diff=888; shape=84.7517730496454: Scoped the zero fallback local inside the image-row loop to test stack-home coalescing with row_ratio and total_draw_wid while preserving the original row=col_step model.
probe 66 behavior; result=MISMATCH; diff=888; shape=84.39716312056737: Corrected the two final ratios from the original x87 stack: map_col_ratio uses the persistent col_step over total_draw_wid, and map_row_ratio uses total_draw_wid over map_tile_row_cnt.
probe 67 control-flow; result=MISMATCH; diff=883; shape=85.1063829787234: Rewrote the second pass into explicit draw/non-draw arms: update source_row only in the drawn-row arm, and use the carried source_row directly for copies.
probe 68 context; result=MISMATCH; diff=879; shape=85.81560283687944: Marked the three binary read-only float constants const and removed the scoped fallback alias, testing whether period-correct read-only declarations recover the original global zero FPU scheduling.
probe 69 liveness; result=MISMATCH; diff=901; shape=85.81560283687944: Moved the col_step zero assignment before map_row_step computation, testing the original stack zero store before FIDIV without changing ownership or control flow.
probe 70 liveness; result=MISMATCH; diff=901; shape=85.81560283687944: Joined col_step declaration and zero initialization after restoring source order, testing whether initializer form recovers the original stack home and FPU loop state. [same emitted code as probe 69]
probe 71 context; result=MISMATCH; diff=901; shape=85.81560283687944: Used a natural 0.0f fallback instead of the named zero global in col_extra, testing VC5 literal-constant hoisting and FPU scheduling without a metric-only alias.
probe 72 control-flow; result=MISMATCH; diff=901; shape=86.87943262411348: Inverted the source-level second-pass condition so the drawn-row arm is first, testing the original JE-to-copy polarity and fall-through layout.
probe 73 liveness; result=MISMATCH; diff=901; shape=86.87943262411348: Used integer zero for the float col_step initialization, testing whether VC5 emits the original dword zero home instead of an early FPU zero load. [same emitted code as probe 72]
probe 74 liveness; result=MISMATCH; diff=790; shape=80.49645390070921: Removed the named row_ratio local and restored one outer zero fallback value, testing whether one fewer float home permits the binary zero FPU value and reciprocal topology together.
probe 77 baseline; result=MISMATCH; diff=690; shape=91.19718309859155: Fresh current authentic-TU baseline after shared context changes; preserve current natural source before focused source and x87 analysis. [same emitted code as probe 76]
probe 78 abi; result=MISMATCH; diff=967; shape=89.71631205673759: Use the authentic shared diam_map class surface and name virtual slot +0x20 as TPanel::set_redraw(redraw_all), while keeping only local proven world/map prefixes.
probe 79 context; result=MISMATCH; diff=967; shape=89.71631205673759: Compile after the real diam_map.cpp constructor, destructor, setup, and set_bitmap prefix under its proven /GX flags; test authentic source order without synthetic predecessors.
probe 80 layout; result=MISMATCH; diff=699; shape=90.49295774647888: Express the dependent map height publication inside the tile-row-count assignment; test the oracle load-width, store-height, add, decrement order in the canonical class context.
probe 81 liveness; result=MISMATCH; diff=699; shape=90.49295774647888: Restore PDB locals: outer float tile_row, nested float col_step, short tot_draw_wid, short draw_wid, and short line. Remove the unsupported outer col_step/row_ratio split. [same emitted code as probe 80]
probe 82 liveness; result=MISMATCH; diff=699; shape=90.49295774647888: Declare PDB locals at function scope in symbol-record order: col_step, tot_draw_wid, draw_wid, tile_row, line. Assign them only at binary-supported use points. [same emitted code as probe 81]
probe 83 behavior; result=MISMATCH; diff=699; shape=90.49295774647888: Reverse the commutative half-step source operands so VC5 evaluates the live map-row quotient first and multiplies it by the constant memory operand. [same emitted code as probe 82]
probe 84 liveness; result=MISMATCH; diff=747; shape=85.46099290780141: Remove the unsupported draw_step local absent from PDB symbols. Repeat the reciprocal expression and let VC5 retain its common x87 value across conversion and field publication.
probe 85 abi; result=MISMATCH; diff=699; shape=90.49295774647888: Use the PDB-defined RGE_Map_Image_Line fields tile_row, start_x, and line_len. Remove unsupported aliases from the shared diam_map declaration.
probe 86 layout; result=MISMATCH; diff=699; shape=90.49295774647888: Reverse cvdump local-record order using the exact set_bitmap donor rule. Declare line, tile_row, draw_wid, tot_draw_wid, then col_step to seek the original -12/-16/-4 homes. [same emitted code as probe 85]
probe 87 liveness; result=MISMATCH; diff=158; shape=95.39007092198581: Compute draw_step from the repeated row-length ratio while assigning col_step separately. Test VC5 CSE that stores col_step but keeps the unrounded ratio live for reciprocal division.
probe 88 liveness; result=MISMATCH; diff=158; shape=95.39007092198581: Split the positive tile-row assignment into assignment and compound multiplication. Test whether VC5 retains the quotient on ST0 and selects FMUL memory. [same emitted code as probe 87]
probe 89 liveness; result=MISMATCH; diff=158; shape=95.39007092198581: Repeat the row-count quotient in the positive tile-row expression. Test the same proven VC5 CSE shape that keeps the earlier quotient live and selects FMUL memory.
probe 90 context; result=MISMATCH; diff=148; shape=96.09929078014184: Use the natural 0.5f literal for the row half-step. Test whether the original unnamed rdata constant selects FMUL memory in the new exact CSE basin.
probe 91 liveness; result=MISMATCH; diff=697; shape=91.48936170212765: Join the row ratio assignment into the draw-step reciprocal initializer. Test the target's one combined x87 expression: FLD 1, duplicate ratio, store col_step, then divide without 32-bit reload.
probe 92 behavior; result=MISMATCH; diff=723; shape=93.97163120567376: Spell the reciprocal draw step as 1.0 times line-length over row-length. Test reversed integer materialization while preserving the separate PDB col_step assignment and exact local homes.
probe 93 liveness; result=MISMATCH; diff=148; shape=96.09929078014184: Keep the repeated ratio CSE but join col_step publication and draw-step initialization with the comma operator. Test one ordered expression without changing arithmetic or local lifetimes. [same emitted code as probe 90]
probe 94 behavior; result=MISMATCH; diff=148; shape=96.09929078014184: Remove redundant denominator float casts from the repeated ratio expression. Test the natural C++ conversion form for target numerator-first materialization.
probe 95 behavior; result=MISMATCH; diff=727; shape=80.85106382978724: Correct field ownership from the x87 stack: publish raw row_len_tiles to tile-row col_step, while local col_step keeps row_len/line_len for col_extra. This preserves the raw numerator required by FLD ST1.
probe 96 behavior; result=MISMATCH; diff=736; shape=80.49645390070921: Remove the unsupported draw_step local and publish raw row_len_tiles to field col_step. Repeat the natural reciprocal expression so VC5 can retain row length, ratio, and draw step on x87 as the oracle does.
```
<!-- end-recovered:6ed448b672c492c44aa1 -->

<!-- recovered:3d40ae6271bb0682f441 -->
### `5c06e112e88d` `src/scratch/00436C30_set_world.cpp:1-19`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00436C30 RGE_Diamond_Map::set_world (diam_map.cpp:227-354)
// Attempt log:
// - PDB evidence owns this method to diam_map.cpp after set_bitmap and before
//   set_player. The shared diam_map declarations provide the class and slot.
// - The PDB locals are line, tile_row, draw_wid, tot_draw_wid, and col_step.
//   Their source order restores the original stack homes.
// - Repeating row_len_tiles/line_len for draw_step lets VC5 keep the quotient
//   live. This reduced the mismatch from 690 bytes to 148 bytes.
// - The current build has exact size, frame, saved registers, and all 7 calls.
//   Bytes are exact through +0x147 and again from +0x22A to the boundary.
// - BLOCKER: the target materializes row length before line length, duplicates
//   ST1, and keeps the quotient in extended precision. VC5 instead spills the
//   quotient as float and reloads it. This can change rounded map geometry.
// - A raw-row field interpretation increased the frame to 0x18. The source
//   keeps the simpler ratio ownership until stronger source evidence exists.
// - BINARY NOTE: each image line publishes tile_row before row-table writes.
// - BINARY NOTE: the second pass updates source_row only for a drawn row.
// - Current claim: moving col_step into the loop was codegen-identical; the
//   retained function-scope ratio local remains the clean source.
```
<!-- end-recovered:3d40ae6271bb0682f441 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
