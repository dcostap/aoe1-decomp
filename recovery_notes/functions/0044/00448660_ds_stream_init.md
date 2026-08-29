# Recovery journal: 00448660 `ds_stream_init`

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


<!-- recovered:47e5937196e9467f253c -->
### `00492347d989` `src/scratch/00448660_ds_stream_init.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// ds_stream_init - initialize DSUTIL globals
// VA: 00448660
// Dsutil.c:1392-1408
// 77 bytes, 9 diff bytes (11.69%)
// Scheduling/encoding quirk: mov eax,1 + mov [addr],eax vs mov dword [addr],1.
// Original: mov eax,1 (b8) before lpBuffer/lpDS stores, reuses eax for ds_ready (a3).
// Rebuilt:  mov dword [addr],1 (c7 05) at end.
// 4+ source forms tried (order tricks, temp var). Invariant encoding choice.
// 10 relocations masked.
```
<!-- end-recovered:47e5937196e9467f253c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
