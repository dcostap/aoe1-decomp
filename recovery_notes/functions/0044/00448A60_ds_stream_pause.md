# Recovery journal: 00448A60 `ds_stream_pause`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Dsutil.c`.
- PDB source: `C:\msdev\work\age1_x1\Dsutil.c`.
- Earlier recovery note: `recovery_notes/dsutil_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d84993e308e93755bb0f -->
### `7adef504ea1e` `src/scratch/00448A60_ds_stream_pause.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00448A60 ds_stream_pause (11 B)
// PDB source: Dsutil.c
// Pauses the stream
// ACCEPTED_DRIFT: VC5 generates mov dword [addr],1 while original uses mov eax,1/mov [addr],eax.
// Both are functionally identical with equivalent address encoding after relocation.
```
<!-- end-recovered:d84993e308e93755bb0f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
