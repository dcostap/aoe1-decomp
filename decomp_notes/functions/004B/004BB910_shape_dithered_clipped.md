# Function notes: 004BB910 `shape_dithered_clipped`

Module notes: `decomp_notes/Shape_module.md`.

## Recovered attempt history

<!-- recovered:ef13fa65d7f8ca00b82c -->
### `target-session` `build/target_sessions/004BB910_shape_dithered_clipped.json:1-36`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=1314; shape=59.660297239915074: Baseline current typed clipped dither reconstruction before new probes; establish exact size, frame, calls, and first mismatch.
probe 2 liveness; result=MISMATCH; diff=1314; shape=59.660297239915074: Hypothesis 1: materialize Orien before AlignedWidth, as Ghidra source and original ESI setup show; derive width from that local. [same emitted code as probe 1]
probe 3 behavior; result=MISMATCH; diff=1302; shape=61.146496815286625: Hypothesis 2: extended odd skip packets consume one extra payload byte after the command, not two; replace explicit src += 2 with post-increment.
probe 4 liveness; result=MISMATCH; diff=1365; shape=60.676532769556026: Hypothesis 3: declare the payload owner before orientation/width, matching the decompiler's pSVar11 = shape_header + 1 before destination setup.
probe 5 liveness; result=MISMATCH; diff=1302; shape=61.146496815286625: Hypothesis 4: scope the top-row command byte to the skip loop, matching the original's transient AL/BL command and reducing the long-lived shared byte local.
probe 6 liveness; result=MISMATCH; diff=1305; shape=60.46511627906977: Hypothesis 5: avoid a named top-skip command local; derive the shifted byte from the packet before incrementing src, so VC5 can spill the shifted count through the existing y home as the oracle does.
probe 8 control-flow; result=MISMATCH; diff=1302; shape=61.146496815286625: Hypothesis 6: preserve the packed command in a separate parity byte before the parity branch, matching the oracle's mov bl,dl; and/cmp pattern. [same emitted code as probe 7]
probe 9 context; result=MISMATCH; diff=1302; shape=61.146496815286625: Hypothesis 7: restore the full same-TU TShape member surface used by exact Shape.cpp donors; this tests compiler context without changing function ownership or body. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=1302; shape=61.146496815286625: Hypothesis 8: retain the decompiler-proven signed char clip coordinate as a named local before parity arithmetic; test operand width and register scheduling. [same emitted code as probe 9]
probe 11 liveness; result=MISMATCH; diff=1302; shape=61.146496815286625: Hypothesis 9: keep the middle visible-run count in a named long local across the clip-right overwrite, matching the oracle's [esp+10] count home in the even middle arm. [same emitted code as probe 10]
probe 12 control-flow; result=MISMATCH; diff=1297; shape=48.61995753715499: Hypothesis 10: use a block-scoped command for the left clipped band and assign the shifted value to y, matching the oracle's byte command plus y-home count form.
probe 13 liveness; result=MISMATCH; diff=1362; shape=47.780126849894295: Hypothesis 11: combine the extra block-scoped command lifetime with payload-owner declaration before area setup, testing whether VC5 swaps area/orientation into the oracle's EDI/ESI colors.
probe 14 liveness; result=MISMATCH; diff=1295; shape=61.111111111111114: Hypothesis 12: mutate the incoming y formal directly as the left-band command/count, eliminating a separate command local and following the decompiler's parameter-home mutation.
probe 15 liveness; result=MISMATCH; diff=1277; shape=61.37339055793991: Hypothesis 13: extend direct y-formal command mutation to the visible middle band, matching the oracle's repeated shr byte then y-home store.
probe 16 liveness; result=MISMATCH; diff=1271; shape=61.206896551724135: Hypothesis 14: extend direct y-formal packet mutation to the tail skip loop, matching the oracle's final y-home command-count writes.
probe 17 liveness; result=MISMATCH; diff=1263; shape=61.03896103896104: Hypothesis 15: use direct y-formal packet mutation in all three RLE command loops, following the repeated oracle y-home stores.
probe 18 liveness; result=MISMATCH; diff=1271; shape=61.206896551724135: Hypothesis 16: retain direct y mutation in visible loops but use a scoped byte command in the top skip, testing whether its local lifetime restores the oracle four-word frame. [same emitted code as probe 16]
probe 19 layout; result=MISMATCH; diff=1253; shape=60.69114470842332: Hypothesis 17: materialize the orientation-dependent row offset before forming save_buffer, matching the oracle's product accumulator and adding a proven destination-offset local.
probe 20 layout; result=MISMATCH; diff=1253; shape=60.69114470842332: Hypothesis 18: restore the Ghidra operand order Bits + clip_left + row_offset for destination formation while retaining the named row offset. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=1253; shape=60.69114470842332: Hypothesis 19: retain a distinct decoded run-count local across the middle clipping comparison, testing whether it recovers the oracle's fourth local home without changing behavior. [same emitted code as probe 20]
probe 22 liveness; result=MISMATCH; diff=1252; shape=60.52060737527115: Hypothesis 20: combine the best row-offset form with direct y mutation in the top skip, testing the complete repeated parameter-home decoder shape.
probe 25 baseline; result=MISMATCH; diff=1252; shape=60.52060737527115: Fresh-claim baseline of current clean source before structural reconstruction; verify the pinned 1337B/1252-diff candidate. [same emitted code as probe 24]
probe 26 liveness; result=MISMATCH; diff=1257; shape=59.488272921108745: Hypothesis 1: cast each decoded y shift back to uchar, testing whether byte-width SHR and the oracle's y-home topology arise without a separate command local.
probe 27 control-flow; result=MISMATCH; diff=1254; shape=61.22004357298475: Hypothesis 2: express the binary-proven x<clip_left / else status setup as one if/else, instead of a second inverse test, to recover the original left-band CFG and block placement.
probe 28 behavior; result=MISMATCH; diff=1307; shape=49.572649572649574: Hypothesis 3: use one natural uchar command local for packet decode in every RLE phase, then assign its shifted value to the proven y state, testing the oracle's byte SHR/store topology.
probe 29 liveness; result=MISMATCH; diff=1272; shape=61.87363834422658: Hypothesis 4: model the clipping phase as a natural uchar state local, testing whether byte assignments and the shared phase loop recover the oracle's byte status home and frame.
probe 30 liveness; result=MISMATCH; diff=1272; shape=61.87363834422658: Hypothesis 5: scope the uchar clipping phase state inside each outer raster row, testing whether original per-row status lifetime recovers byte stores without a persistent local allocation. [same emitted code as probe 29]
probe 31 liveness; result=MISMATCH; diff=1254; shape=61.22004357298475: Hypothesis 6: separate row declaration from its PDB-timed assignment and place it with the early loop locals, testing VC5 local-home order without changing behavior. [same emitted code as probe 27]
probe 32 layout; result=MISMATCH; diff=1208; shape=61.22004357298475: Hypothesis 7: stage AlignedWidth into a natural aligned_width local before multiplying by orientation, testing setup evaluation order and whether VC5 recovers the original stride frame home.
probe 33 layout; result=MISMATCH; diff=1267; shape=61.22004357298475: Hypothesis 8: retain staged AlignedWidth but use direct area->Orien expressions, testing whether removing the orientation alias restores the oracle's area/orientation register colors in this improved setup basin.
probe 34 control-flow; result=MISMATCH; diff=1208; shape=61.43790849673203: Hypothesis 9: spell the outer row-bound guard in the oracle's row>clip_bottom operand order, testing the first loop-entry compare and subsequent branch polarity.
probe 35 layout; result=MISMATCH; diff=1208; shape=61.43790849673203: Hypothesis 10: materialize width then apply compound multiplication, testing whether the natural assignment form restores the oracle's post-call EAX multiply and local-home scheduling. [same emitted code as probe 34]
probe 36 layout; result=MISMATCH; diff=1208; shape=61.43790849673203: Hypothesis 11: reverse the positive row-offset multiplication to width*clip_top, matching the original destination-arm operand order while retaining compound width lowering. [same emitted code as probe 35]
probe 37 liveness; result=MISMATCH; diff=1260; shape=45.610278372591004: Hypothesis 12: preserve a named decoded run_count through both middle visible-run branches, matching the binary local used for clipped-length arithmetic and source advancement in this improved setup basin.
probe 38 liveness; result=MISMATCH; diff=1208; shape=61.43790849673203: Hypothesis 13: cache clip_right as a row-local bound, matching the oracle's reload into a callee-saved register before x clipping and later reuse across all raster bands. [same emitted code as probe 36]
probe 39 liveness; result=MISMATCH; diff=1208; shape=61.43790849673203: Hypothesis 14: order the persistent end pointer before the byte count declaration, following the decompiler's byte/pointer local sequence to test local coloring without changing loop behavior. [same emitted code as probe 38]
```
<!-- end-recovered:ef13fa65d7f8ca00b82c -->

<!-- recovered:cb16266f0e7867240b4b -->
### `0923cad7edb1` `src/scratch/004BB910_shape_dithered_clipped.cpp:1-69`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004BB910 TShape::shape_dithered_clipped
// Shape.cpp lines 2902-3243
// Attempt log:
// try 1: adapted shape_dithered_unclipped skeleton with clipping bounds and packet-observed RLE/dither phases; default /O2 too small (.text 656 vs 1321), because helper stayed out-of-line/logic under-modeled.
// try 2: macro-expanded ZERO_DITHER; default /O2 still too small (.text 624), worse due optimization.
// try 3: /Od reached only .text 1179 vs 1321, still too small; rolled back.
// try 4: /O1 much too small (.text 498), rolled back.
// try 5: no /Oy (/O2 only) unchanged at .text 624, rolled back.
// try 6: restored the binary-supported clipped origin (clip_left/clip_top),
//   corrected the pre-row RLE skip semantics, and expanded the three natural
//   left/middle/tail raster phases instead of hiding them in ZERO_DITHER.
// try 7: coalesced command/count/state updates onto the observed byte/formal
//   parameter homes; frame fell from 0x3c to 0x0c and output stabilized at
//   1387 bytes (original 1321), with all RLE phase blocks and AlignedWidth
//   call present.  A natural left-phase loop without the observed shared exit
//   was worse, so the shared exit is retained.
// try 8: replaced the synthetic save_y local with direct orientation-specific
//   destination arms, following the exact Shape.cpp sibling topology.  This
//   improved the structural basin to 1398 bytes, 1314 differing bytes, and
//   59.66% shape; it remains a natural source-model lead, not codegen tuning.
// try 9: used the exact Shape donor's direct member expression for orientation
//   and width, removing the synthetic orientation local; this tests the first
//   setup hunk without changing the typed clipped RLE phases.
// try 10: modeled the persistent dither state as the binary-supported bool
//   shown by the decompiler; VC5 emitted the unchanged 1398-byte candidate,
//   so the width hypothesis was rolled back.
// try 11: mutated the packed RLE command byte before assigning its count;
//   original uses narrow SHR and byte parameter-home stores in every phase,
//   so this tests the source shape without changing typed ownership.
// left in scratch: canonical typed RLE/dither behavior is reconstructed, but
//   VC5 still chooses a different early register/local-home basin.
//
// sa-22f639d5 fresh claim (2026-08-17):
// - Baseline rebuilt 1398 bytes versus 1321, with one ordered AlignedWidth
//   call and 1314 strict differing bytes.
// - Correcting two extended odd-run pointer advances reduced the candidate to
//   1394 bytes and 1302 strict differing bytes. The call set stayed exact.
// - Explicit orientation and full TShape donor context were codegen-neutral.
//   Payload-owner declaration before setup was worse and was rolled back.
// - Direct mutation of the proven y parameter as the decoded command count in
//   all three packet loops reduced the candidate to 1341 bytes and 1263
//   differing bytes. This follows the repeated oracle y-home byte stores.
// - A named orientation-dependent row offset improved the candidate to 1337
//   bytes and 1252 strict differing bytes. The row offset is typed and natural.
// - A command-local, parity alias, and separate run-count local were duplicate
//   or worse basins. They were removed.
// - Final validation: 1337 rebuilt bytes, 0x0c frame versus the original
//   0x10, one ordered call, 1252 strict differing bytes, 60.52% shape,
//   and first mismatch at +0002. The remaining gap starts in prologue and
//   local-home allocation. No ABI, call, or ownership issue remains.

// sa-9e5deac5-r1 fresh claim (2026-08-22):
// - Baseline revalidated the pinned 1337B / 1252-diff source.
// - A byte cast on each decoded shift was worse: 1369B / 1257 diff.
// - An explicit left-clip if/else improved size and shape, but was a small
//   strict regression alone. It recovered one exact block.
// - A uchar command local across all packet phases was worse: 1383B / 1307
//   diff, despite a 0x10 frame. It was removed.
// - A uchar phase local reduced the body to 1290B / 1272 diff. It was not
//   retained because the original size and local ownership were lost.
// - Separating row declaration from assignment was codegen-neutral.
// - Staging width as `width = AlignedWidth(); width *= orientation;` improved
//   the natural candidate to 1333B / 1208 diff. This is retained.
// - Direct orientation, a named run count, a cached right bound, and local
//   declaration reorders were worse or codegen-neutral.
// - Reversing the outer bound operands to `row > clip_bottom` retained the
//   1208-diff basin and improved the first bound instruction shape.
// - The current source has one ordered AlignedWidth call and no ABI or
//   ownership uncertainty. The remaining gap is the prologue and local homes.
```
<!-- end-recovered:cb16266f0e7867240b4b -->
