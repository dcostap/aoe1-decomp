# Recovery journal: 00479050 `~TMessagePanel`

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


<!-- recovered:83076233b91c3252df67 -->
### `38b27027ca41` `src/matching/00479050_TMessagePanel.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// first pass: natural destructor with /GX-visible virtual destructors for EH frame/vptr restore
// use IAT-style extern function pointer for DeleteObject and explicit vptr restore to match original
```
<!-- end-recovered:83076233b91c3252df67 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
