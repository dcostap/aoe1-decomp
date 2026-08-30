# Function notes: 004BB770 `shape_dithered_unclipped`

Module notes: `decomp_notes/Shape_module.md`.

## Recovered attempt history

<!-- recovered:2146fa7e799fa6fa5d59 -->
### `target-session` `build/target_sessions/004BB770_shape_dithered_unclipped.json:1-21`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=326; shape=81.08108108108108: Current clean typed RLE source; establish baseline metrics and first mismatch.
probe 2 variant; result=MISMATCH; diff=326; shape=81.08108108108108: Named orientation local before pitch; test original orientation/pitch register coloring. [same emitted code as probe 1]
probe 3 variant; result=MISMATCH; diff=324; shape=81.08108108108108: Payload cursor before height; test PDB/decompiler evaluation order.
probe 4 variant; result=MISMATCH; diff=305; shape=84.24657534246575: Binary-supported x/count home plus carry-destination row topology: exact size/frame/call set, best natural diagnostic 305 strict bytes; retain only if no exact reduction.
probe 7 behavior; result=MISMATCH; diff=363; shape=73.97260273972603: Natural local payload count removes parameter-home reuse and preserves original odd-run payload advance; test behavior-correct pixel loops.
probe 10 other; result=MISMATCH; diff=347; shape=80.3921568627451: Removed forbidden x and param_5 parameter-home reuse; ordinary count locals now own run length and source advance.
probe 12 baseline; result=MISMATCH; diff=347; shape=80.3921568627451: Revalidate the current policy-clean typed RLE source before natural source probes. [same emitted code as probe 11]
probe 13 liveness; result=MISMATCH; diff=347; shape=80.3921568627451: Natural declaration-order probe: give the persistent row base an earlier typed local declaration without parameter-home reuse. [same emitted code as probe 12]
probe 14 liveness; result=MISMATCH; diff=345; shape=76.71232876712328: Natural branch-scope probe: keep skip and nonzero run counts scoped to their packet arms, matching binary byte-home lifetimes without parameter reuse.
probe 16 layout; result=MISMATCH; diff=341; shape=81.57894736842105: Natural row-base ownership probe: assign the persistent typed row pointer in orientation arms, then derive the working cursor at each row.
probe 17 layout; result=MISMATCH; diff=347; shape=80.3921568627451: Natural row-base handoff probe: materialize the working cursor once before parity setup, then reset it from the persistent row pointer only at row end.
probe 21 liveness; result=MISMATCH; diff=389; shape=70.54794520547945: Natural separate row counter inside positive-height guard: binary uses EDI for rows while EAX height remains register-only; test whether freeing the height home recovers the target row-pointer local at [esp+10].
probe 23 liveness; result=MISMATCH; diff=305; shape=84.24657534246575: Binary-supported parameter-home hypothesis: preserve odd-run count through param_5 because the oracle writes and reloads its byte home, and use dead x as the widened fill span for the duplicated mask/end topology; omit unsupported even-path param_5 reuse. [same emitted code as probe 9]
probe 25 control-flow; result=MISMATCH; diff=347; shape=80.3921568627451: Natural CFG probe: make the even zero terminator an explicit inner-loop continue, because the oracle bypasses the source-cursor increment and jumps directly to the done test. [same emitted code as probe 20]
probe 27 behavior; result=MISMATCH; diff=347; shape=80.3921568627451: Natural packed-command probe: mutate the command byte with >>= 1, then reuse the shifted count, matching the oracle's retained command-bit copy plus shift topology. [same emitted code as probe 25]
probe 29 layout; result=MISMATCH; diff=349; shape=80.3921568627451: Natural sibling-topology probe: direct orientation member, payload after header height, and row-base handoff at outer-loop entry, matching the exact Shape.cpp unclipped siblings without parameter mutation.
probe 31 layout; result=MISMATCH; diff=348; shape=68.42105263157895: Natural packed-stream ownership probe: keep a row-local working cursor copied from the persistent payload pointer, as shown by the decompiler's pSVar10/pSVar11 split, then commit it at row end.
probe 33 control-flow; result=MISMATCH; diff=347; shape=80.3921568627451: Binary-supported shared-tail probe: encode the oracle's odd/even packet exits with explicit labels, so nonzero runs share the source advance while the zero terminator bypasses it.
probe 35 layout; result=MISMATCH; diff=347; shape=80.3921568627451: Natural row-tail order probe: commit the next parity before advancing the persistent row base, following the decompiler's uVar12 update before loop continuation. [same emitted code as probe 27]
probe 37 liveness; result=MISMATCH; diff=347; shape=80.3921568627451: Natural store-order probe: initialize the persistent row base immediately after destination formation, before the second parity predicate, matching the oracle's row-base store before its test. [same emitted code as probe 17]
probe 38 liveness; result=MISMATCH; diff=347; shape=80.3921568627451: Natural parity/store ordering probe: assign the row base between the two parity expressions, matching the oracle's store after the first parity sum and before the second parity test. [same emitted code as probe 37]
```
<!-- end-recovered:2146fa7e799fa6fa5d59 -->

<!-- recovered:78fc611c48e12057b384 -->
### `0923cad7edb1` `src/scratch/004BB770_shape_dithered_unclipped.cpp:1-98`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004BB770 TShape::shape_dithered_unclipped
// Shape.cpp lines 2805-2898
// Attempt log:
// 1: decompiler-shaped source with explicit locals: too short (384 B), push-ecx one-local frame.
// 2: parameter-slot reuse/lower-local form got two-local sub esp,8 frame but much worse register/order drift (91.6% pos).
// 3: delayed pitch multiply was 400 B but push-ecx frame, still broad drift.
// 4: return to best decompiler shape plus dummy local still 400 B, too short.
// 5: volatile dummy forced comparable 404-byte output but store before AlignedWidth shifts first mismatch to offset 18; broad drift.
// tried flags /O1, no /Oy, /Ox, /Ob0: /O1 too short, others same as /O2.
// left in scratch: behavior modeled, but VC5 register/stack-slot allocation for the RLE+dither loop is still broad; not accepted_drift-safe.
// sa508a60b0_shape4 probes (2026-08-09):
// - Replaced the diagnostic volatile dummy with a binary-supported persistent
//   save_buffer row base and a separate working destination; this preserves the
//   proven row reset behavior and yields a 0x8 frame, 405B output, and 343
//   strict differing bytes (versus 404B/364 for the dummy baseline).
// - A single height counter and delayed save_buffer initialization were tested;
//   the direct orientation/save-buffer candidate remained the best natural
//   source. Split pitch arithmetic and a named row-offset temporary worsened
//   the basin and were discarded. Remaining gap is broad VC5 register/home and
//   RLE block scheduling, not behavior or the AlignedWidth ABI.
// normal-BB770-r1 probes (2026-08-12):
// - The exact mirror-sibling row topology without the current dither local
//   surface lost the call/frame basin (355B, 385 strict bytes); restored.
// - Making the PDB-proven done flag a byte improved shape, but alone reached
//   399B/350 strict bytes. Mapping fill length through x's home also worsened
//   the natural candidate (370B/349); both changes are not retained alone.
// - Removing save_buffer in favor of x as the row base was a 395B/346-byte
//   basin and did not recover the target homes; restored the named row base.
// - Reversing the even-command test to keep the zero terminator inline matched
//   the oracle block layout and exact 404-byte size (320 strict bytes).
// - Combining that CFG with byte done reached 398B/326 strict bytes and is
//   retained because the oracle writes done as a byte. Swapping old/next parity
//   roles improved edit shape but reached 342 strict bytes and was restored.
// - Reordering locals to the same-TU donor family was codegen-identical. The
//   remaining gap is the early VC5 register/home schedule and height/pitch
//   coloring; calls, frame size, CFG count, and RLE effects are aligned.
// sa262083c2-shape probes (2026-08-12):
// - Splitting orientation and AlignedWidth evaluation, reusing pitch for the
//   orientation, and initializing shape_header before pitch all worsened the
//   prologue or frame; restored the clean source.
// - A while outer loop, explicit row-counter copy, signed int height, and
//   local declaration reorder were duplicate or worse basins; restored.
// - Final lead remains the original source's height/pitch register coloring
//   and save_buffer home, with calls, frame, CFG count, and RLE behavior known.
// shardE-4BB770 probes (2026-08-13):
// - Moving the payload cursor before the height expression improved the clean
//   source from 326 to 324 strict bytes; it did not change the broad setup.
// - A long done flag plus that payload order reached the prior 404-byte basin,
//   then improved it to 318 bytes; this diagnostic source was not retained
//   because the oracle's done home is byte-width and the natural source uses
//   the proven byte flag.
// - Splitting aligned width, copying rows, and local declaration reordering
//   were worse or duplicate basins. Reversed pitch terms were duplicate.
// - Restored the natural typed byte-RLE source. Remaining gap is the early
//   pitch/height/source register coloring and save_buffer home allocation.
// orch-4BB770-a probe (2026-08-13):
// - Split the command count from the fill count to test the oracle's distinct
//   byte homes and first structural loop hunk. Exact-block coverage improved
//   from 32.88% to 42.47%, but size fell to 391B and strict diff worsened to
//   349B. Restored the clean source. The next lead remains source/TU context
//   for the early pitch/height and parameter-home schedule.
// sa-d8797fda-r1 probes (2026-08-16):
// - Restored the canonical full TShape/TDrawArea field surfaces and moved the
//   payload cursor before the height expression. These are codegen-neutral.
// - Diagnostic reuse of the x and p5 parameter homes produced 404B, the 0x8
//   frame, the aligned AlignedWidth call, and 305 strict differing bytes.
// - A 64-sample ambient VC5 declaration sweep was codegen-identical. Narrow
//   pitch, orientation, and height types, declaration reordering, and a local
//   row-counter copy were duplicate or worse. Reversed zero/nonzero branches
//   worsened the block layout. The remaining gap is early register/home
//   allocation and parity/destination spill placement.
// sa-127fa25c-r1 probes (2026-08-17):
// - Restored the pinned typed source and rebuilt it: 404B, 0x8 frame, one
//   AlignedWidth call, and 305 strict differing bytes remain.
// - Main review removed parameter-home reuse. The metric-closer 404-byte form
//   was compiler steering. The living source keeps ordinary count locals.
// sa-51969701-r1 probes (2026-08-17):
// - Reordering the row-base declaration was codegen-identical.
// - Scoping skip and nonzero-run count locals was natural but worsened the
//   frame to 0xC and reached 381B/345 strict bytes; restored.
// - Assigning the persistent row base directly in orientation arms reached
//   391B/341 strict bytes and a slightly closer block basin, but remained a
//   broad nonexact source family; restored.
// - Materializing the working cursor once before parity setup returned to the
//   389B/347-byte basin. No policy-valid exact source was found.
// sa-54e2dadc-r1 probes (2026-08-22):
// - A separate row counter inside the positive-height guard removed the 0x8
//   frame and reached 382B/389 strict bytes; restored.
// - Binary-supported x and p5 count-home reuse reproduced the prior 404B/305B
//   diagnostic basin. It was a duplicate compiler-steering form; restored.
// - Explicit terminator continues, shared packet-tail labels, mutable command
//   bytes, and a split payload cursor were duplicate or worse basins.
// - Direct sibling-style setup and row-tail declaration orders were duplicate
//   or worse. Moving row-base initialization before parity kept 347B but added
//   one exact block only; the clean source remains the smallest natural form.
// - Final clean validation: 389B/347 strict bytes, 0x8 frame, one ordered
//   AlignedWidth call, and 32.88% exact-block coverage. The blocker remains
//   early VC5 register/home allocation and parity/destination spill placement.
```
<!-- end-recovered:78fc611c48e12057b384 -->
