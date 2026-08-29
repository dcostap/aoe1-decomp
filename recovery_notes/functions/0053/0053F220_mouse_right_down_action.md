# Recovery journal: 0053F220 `mouse_right_down_action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/vw_main.cpp`.
- PDB source: `C:\msdev\work\age1_x1\vw_main.cpp`.
- Earlier recovery note: `recovery_notes/vw_main_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:68b97b8904abb644ae30 -->
### `912332e8f578` `src/scratch/0053F220_mouse_right_down_action.cpp:1-17`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0053F220 RGE_Main_View::mouse_right_down_action(long,long,int,int)
// vw_main.cpp:1082-1111
// Attempt 6: nested if structure to force shared epilogue
// [non-comment lines omitted during migration]
    // vtable slots 0-3
// [non-comment lines omitted during migration]
    // remaining vtable slots
```
<!-- end-recovered:68b97b8904abb644ae30 -->

<!-- recovered:3ea76b9b8081e0abe328 -->
### `912332e8f578` `src/scratch/0053F220_mouse_right_down_action.cpp:40-40`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // vtable slots 0-7
```
<!-- end-recovered:3ea76b9b8081e0abe328 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
