# Recovery journal: 005381C0 `Update_Render_Pointers`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.
- Earlier recovery note: `recovery_notes/view_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:f4cb115d2def445d35bb -->
### `81c9f7784e17` `src/matching/005381C0_Update_Render_Pointers.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 005381C0 Update_Render_Pointers (view.cpp:4254-4278)
// PDB source: view.cpp (RGE_View::Update_Render_Pointers)
//
// Attempt log:
// first pass: exact MATCH on first compile. Local TPanel/TDrawArea stubs with
// exact layout + natural control flow. 190 bytes, 0 diff, 2 masked relocations.
```
<!-- end-recovered:f4cb115d2def445d35bb -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
