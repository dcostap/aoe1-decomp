# Recovery journal: 0053F2F0 `mouse_right_move_action`

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


<!-- recovered:0130240eb58c849e891e -->
### `912332e8f578` `src/scratch/0053F2F0_mouse_right_move_action.cpp:1-31`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0053F2F0 mouse_right_move_action (vw_main.cpp:1117-1151)
// PDB source: vw_main.cpp (RGE_Main_View::mouse_right_move_action)
//
// long __thiscall RGE_Main_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4)
// ret 10h cleanup (4 params, thiscall)
// Returns: 0 or 1
//
// Attempt log:
// attempt 1: virtual helper struct (58 dummies + 3 real at slots 58-60),
//   __fastcall with dummy edx, member-function externs.
//   EXACT MATCH. 0% diff, 4 relocations masked.
// Key: 58 dummy VTD() macros create vtable padding to reach slots 0xE8/0xEC/0xF0.
// [non-comment lines omitted during migration]
    // Real methods at slots 58, 59, 60
    // vt[58]=0xE8: start_scroll_view(uchar, long, long, int, int)
```
<!-- end-recovered:0130240eb58c849e891e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
