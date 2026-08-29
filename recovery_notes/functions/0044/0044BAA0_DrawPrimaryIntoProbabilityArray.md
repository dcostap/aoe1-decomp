# Recovery journal: 0044BAA0 `DrawPrimaryIntoProbabilityArray`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/fractal.cpp`.
- PDB source: `C:\msdev\work\age1_x1\fractal.cpp`.
- Earlier recovery note: `recovery_notes/fractal_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:c15eaa3a652ef4a3afe6 -->
### `d050eea3c` `src/fractal.cpp:477-477`

Mapping: `strong`. next mapped function definition is DrawPrimaryIntoProbabilityArray at old line 493.

```text
        // ORIGINAL BUG: The shipped lower-y correction negates dx, not dy.
```
<!-- end-recovered:c15eaa3a652ef4a3afe6 -->

<!-- recovered:6e6680eb59b3541a9857 -->
### `0b3aa46fe5b9` `src/accepted_drift/0044BAA0_DrawPrimaryIntoProbabilityArray.cpp:1-10`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// PointMaker::DrawPrimaryIntoProbabilityArray
// VA: 0044BAA0
// Retry 2026-05-26: shape locals to original stack/register loop.
// Revalidated best: 182B exact size, MISMATCH 6 positional / 6 edit, first mismatch +104.
// Tried 10 variants: baseline + dummy stack local, explicit original stack-temp topology, desty-first,
// reordered call/updates, while/continue, member-reread PrimaryRadius, casted call args, oldleft/oldbottom
// locals, volatile destx, and manual a/b/c/d call locals. Best source matches all setup/clipping/loop/tail
// and differs only in the inner AddingRect call setup register coloring: rebuilt uses ECX for left and EDX
// for bottom while original uses EDX for left and ECX for bottom; pushed argument values/order are equivalent.
// PROPOSED_ACCEPTED_DRIFT: localized benign register-choice drift in one call-setup hunk only.
```
<!-- end-recovered:6e6680eb59b3541a9857 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
