# Recovery journal: 004A6290 `~TRIBE_Screen_Disconnect`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_mps.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_mps.cpp`.
- Earlier recovery note: `recovery_notes/scr_mps_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:527e173d44c11a0ac777 -->
### `5868718576a8` `src/scratch/004A6290_TRIBE_Screen_Disconnect.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: simple class, /GX; only 32 bytes (no EH frame generated)
// attempt 2: inheritance + /GX; 80 bytes, 6 short (missing explicit vtable store)
// attempt 3: explicit vtable ptr with extern; only 48 bytes (worse)
// attempt 4: back to 80-byte shape; same 80
// attempt 5: stdlib.h/stddef.h include; same 80
// attempt 6: vtable ptr assignment with local; 48 bytes (worse)
// attempt 7: lea for message addr, fixed delete_panel(0, p); same 80
// Left in scratch: 80 vs 86 bytes; VC5 doesn't emit explicit destroying vtable store
// (mov dword [esi], 0x573518 = 6 bytes) with this class hierarchy. Behavior correct.
```
<!-- end-recovered:527e173d44c11a0ac777 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
