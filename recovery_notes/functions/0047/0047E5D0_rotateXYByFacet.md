# Recovery journal: 0047E5D0 `rotateXYByFacet`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/point.cpp`.
- PDB source: `C:\msdev\work\age1_x1\point.cpp`.
- Earlier recovery note: `recovery_notes/0047E5D0_rotateXYByFacet.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5a2f55ae8feedbcf262f -->
### `d050eea3c` `src/point.cpp:70-70`

Mapping: `strong`. comment lies after mapped function rotateXYByFacet at old line 54.

```text
        // BINARY NOTE: Keep this product separate to preserve the shipped FPU order.
```
<!-- end-recovered:5a2f55ae8feedbcf262f -->

<!-- recovered:d1667442079aa6323d37 -->
### `a5fb96a1e6de` `src/scratch/0047E5D0_rotateXYByFacet.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// XYZ::rotateXYByFacet
// VA: 0047E5D0
// PDB: point.cpp:86-109
//
// Attempt log:
// - draft 1: inline literal 0.78539f, cos before sin → 21.77% diff
// - draft 2: sin before cos, extern DAT_00571ce8 → 14.97% diff, post-ftol order off
// - draft 3-6: various term orders for y expression → same 14.97% diff
// - Remaining diff: VC5 FPU scheduling chooses sin*dx before cos*dy vs original's cos*dy before sin*dx.
//   Classic register-pressure scheduling difference. Math is identical.
// Left in scratch.
```
<!-- end-recovered:d1667442079aa6323d37 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
