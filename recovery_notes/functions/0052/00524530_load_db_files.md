# Recovery journal: 00524530 `load_db_files`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tribegam.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tribegam.cpp`.
- Earlier recovery note: `recovery_notes/tribegam_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1c4c4eaa3a460982ff6a -->
### `912332e8f578` `src/matching/00524530_load_db_files.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00524530 TRIBE_Game::load_db_files
// Source: tribegam.cpp lines 1850-1879
// Attempt log:
// initial: packet-modeled local TRIBE_Game/RGE_Game_World layout and natural source.
// fixed: avoid non-polymorphic base subobject (+4 this adjustment); declare input methods on local TRIBE_Game.
```
<!-- end-recovered:1c4c4eaa3a460982ff6a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
