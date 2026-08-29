# Recovery journal: 00471EC0 `TButtonPanel`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/pnl_btn.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_btn.cpp`.
- Earlier recovery note: `recovery_notes/pnl_btn.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:cbf331940c1e3436ff14 -->
### `8558dca82389` `src/scratch/00471EC0_TButtonPanel.cpp:1-20`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00471EC0 TButtonPanel constructor
// PDB source: Pnl_btn.cpp
// Attempt log:
// - 1st attempt: novtable + manual vtable + body field assignments + array loop
// [non-comment lines omitted during migration]
// Minimal TPanel layout (0xF4 bytes)
```
<!-- end-recovered:cbf331940c1e3436ff14 -->

<!-- recovered:75fd3e4e508ed6849834 -->
### `8558dca82389` `src/scratch/00471EC0_TButtonPanel.cpp:182-185`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // Manual vtable write (after all scalar fields, like original)
    *(void**)this = (void*)0x570FC8;

    // Override TPanel's panel_type
```
<!-- end-recovered:75fd3e4e508ed6849834 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
