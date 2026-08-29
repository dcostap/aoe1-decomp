# Recovery journal: 004A75C0 `~TribeSaveGameScreen`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_save.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_save.cpp`.
- Earlier recovery note: `recovery_notes/scr_save_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d7f1f764f966ea0fe6ee -->
### `6f9783aca4a0` `src/matching/004A75C0_TribeSaveGameScreen.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: natural virtual destructor with TScreenPanel-sized local stub and seven delete_panel calls; default flags missed the EH frame
// MODULE FLAGS: config/flags/scr_save.rsp
```
<!-- end-recovered:d7f1f764f966ea0fe6ee -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
