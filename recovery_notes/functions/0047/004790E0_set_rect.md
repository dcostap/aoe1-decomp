# Recovery journal: 004790E0 `set_rect`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Pnl_msg.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_msg.cpp`.
- Earlier recovery note: `recovery_notes/pnl_msg_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d78d18b592401c8d42c8 -->
### `44679cc1b979` `src/matching/004790E0_set_rect.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// MODULE NOTE: the standalone /GX owner is exact. The complete Pnl_msg.cpp
// wrapper uses the reviewed shared context and observes a 228-byte mismatch;
// keep this owner natural and do not tune it for the wrapper metric.
// first pass: typed local reconstruction of image-buffer recreate path
// FLAGS: config/flags/004790E0_set_rect.rsp uses /GX for new/delete EH state around TDrawArea construction
```
<!-- end-recovered:d78d18b592401c8d42c8 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
