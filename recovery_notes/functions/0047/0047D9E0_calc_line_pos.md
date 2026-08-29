# Recovery journal: 0047D9E0 `calc_line_pos`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Pnl_txt.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_txt.cpp`.
- Earlier recovery note: `recovery_notes/Pnl_txt_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:38f07c4e0f4b6d098822 -->
### `target-session` `build/target_sessions/0047D9E0_calc_line_pos.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 variant; result=MISMATCH; diff=1; shape=100.0: variant lab build\variant_lab\0047D9E0_calc_line_pos\20260823_181329: 6 variants, 6 invariant-eligible, 0 exact
probe 2 variant; result=MISMATCH; diff=1; shape=100.0: variant lab build\variant_lab\0047D9E0_calc_line_pos\20260823_181350: 8 variants, 8 invariant-eligible, 0 exact
```
<!-- end-recovered:38f07c4e0f4b6d098822 -->

<!-- recovered:c70bef7ee8296c9870d3 -->
### `5ea464107b0b` `src/scratch/0047D9E0_calc_line_pos.cpp:1-30`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0047D9E0 TTextPanel::calc_line_pos (555 bytes)
// Pnl_txt.cpp:1235-1346
//
// Canonical reconstruction from the original call/field evidence:
//   get_text(current) supplies the line; col_offset is the cursor-prefix
//   width, while text_size.cx is subsequently reused for the whole-line width.
//   The four alignment values are the period TTextPanel enum values:
//   center=0, left=1, right=2, top=3, bottom=4, horizontal-scroll=5,
//   wordwrap=6.
//
// Attempt log:
// - Baseline had the correct frame, six calls, and formulas but an inverted
//   guard/enum CFG.  Inverting the live-text guard, preserving the original
//   signed compare, and using switches for horizontal/vertical alignment
//   recovered the original shared tails.
// - A shared short byte-length local and, importantly, measuring the original
//   text with the copied-prefix byte count recovered exact size, all calls,
//   and the original control flow.  Initializing the null-text width recovered
//   all 192 instructions and left one operand-order byte in the final RECT
//   right-edge LEA.  Bottom-alignment term and right-edge expression variants
//   were duplicate; source is left typed and period-plausible.
// - In this assignment, width-minus-one-plus-x, grouped subtraction,
//   sequential right temporaries, and equivalent algebraic forms all emitted
//   the same [edi+ebp-1] LEA.  A decompiler-style one-field `cy` size changed
//   the frame; an eight-byte padded alias was a duplicate.  A named width
//   alias worsened structural output.  Restored the clean typed source.
// - Fresh probes repeated direct/grouped right-edge forms and an eight-variant
//   focused lab.  All preserved 555 bytes and emitted [edi+ebp-1]; the original
//   remains [ebp+edi-1].  A `text_size.cy` alias changed an earlier null-width
//   store and broke structure.  No source-backed lead remains for this byte.
```
<!-- end-recovered:c70bef7ee8296c9870d3 -->

<!-- recovered:04b6e8db2c364fe9d549 -->
### `5ea464107b0b` `src/scratch/0047D9E0_calc_line_pos.cpp:118-119`

Mapping: `exact`. historical standalone source path names this target VA.

```text
        // This call is present in the original line-measurement path even
        // though the following byte-length expression supplies the count.
```
<!-- end-recovered:04b6e8db2c364fe9d549 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
