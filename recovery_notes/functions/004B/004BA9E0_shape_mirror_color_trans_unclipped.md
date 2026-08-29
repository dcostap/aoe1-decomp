# Recovery journal: 004BA9E0 `shape_mirror_color_trans_unclipped`

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


<!-- recovered:1c974ad7d06035f895ba -->
### `947c55021709` `src/scratch/004BA9E0_shape_mirror_color_trans_unclipped.cpp:1-57`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004BA9E0 TShape::shape_mirror_color_trans_unclipped (Shape.cpp:1878-1939, 265B)
// RLE color-translated mirror shape rendering.
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt notes:
// - Baseline natural reconstruction used the CRT header and a nested goto-shaped
//   decoder; it was 218B and the optimizer inlined memset (259 differing bytes).
// - A donor-shaped reconstruction with one shared offset, rows, destination, and
//   byte-count local, plus a plain external memset declaration, produced the
//   correct two-call surface and 236B/199 differing bytes after the explicit
//   `(command & 1) == 1` predicate probe.
// - Direct destination formation in both orientation arms is period-plausible and
//   follows the original branch topology, but VC5 drops the expected push-ecx
//   local and is a worse 235B/262-byte basin. Reverted to the better shared-offset
//   reconstruction.
// - Remaining drift is structural setup/home placement (original direct orientation
//   arms and width local), plus localized table-index SIB operand order; calls,
//   RLE control flow, stack cleanup, and field ownership are aligned.
//
// sa-78979d2a-color probes (2026-08-09):
// - `table[*p]` versus explicit pointer addition was codegen-identical; the
//   localized SIB base/index mismatch remains.
// - Splitting a persistent row base from a per-row destination worsened strict
//   bytes (201 versus 199) despite reducing the size gap; rolled back.
// - Direct destination formation in both orientation arms reproduced the
//   branch-shaped source hypothesis but fell to 262 strict bytes; rolled back.
// - Reversed common destination address terms was a duplicate. Retained the
//   canonical shared-offset typed RLE source; unresolved gap is destination
//   parameter-home scheduling plus the one-byte table SIB encoding.
// sa-43841f2d-shape-mirror-color-trans probes (2026-08-09):
// - Direct-call evidence at 00444B40 proves TDrawArea::AlignedWidth returns
//   long; restored that ABI after an int-return trial changed the basin.
// - Matched the same-TU CRT source family with <string.h>, pragma function,
//   and extern-C memset, and restored full TShape/TDrawArea header/clip spans.
//   Calls now carry the original _memset and long-return AlignedWidth symbols;
//   emitted source remains a natural shared-offset RLE decoder.
// sa508a60b0_shape1 probes (2026-08-09):
// - Rechecked the clean typed reconstruction as the session baseline; it stays
//   238B versus the 265B oracle with both ordered calls aligned.
// - Duplicating the natural destination formation in both orientation arms
//   followed the binary branch-local LEAs but moved into a worse 247B basin;
//   restored the shared-offset source.
// - An early height failure return was codegen-identical to the positive guard;
//   the far failure topology provides no new lead. Remaining gap is the
//   binary-proven destination parameter-home spill/row-end reload, not ABI or
//   RLE behavior.
// sa-1684b218-r1 probes (2026-08-11):
// - Branch-local destination formation with a named offset produced a 247B
//   duplicate; declaration-order and split-pitch variants were also duplicates.
// - The Ghidra-supported row-base plus per-row working destination form improved
//   the natural candidate to 254B/197 strict bytes and restored the row-end
//   reload/add/store topology; retained as the best source reconstruction.
// - Direct orientation-arm row formation reached 273B/194 strict bytes, but
//   swapped the proven row/counter parameter homes and added stores; rolled back.
// - Moving the row-count initialization before orientation created an 0x8 frame
//   and 265B/261 strict bytes; rolled back. Remaining gap is the original
//   orientation-arm setup/home allocation and branch-local SIB schedule.
```
<!-- end-recovered:1c974ad7d06035f895ba -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
