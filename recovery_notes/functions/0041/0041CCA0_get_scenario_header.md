# Recovery journal: 0041CCA0 `get_scenario_header`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/basegame.cpp`.
- PDB source: `C:\msdev\work\age1_x1\basegame.cpp`.
- Earlier recovery note: `recovery_notes/basegame_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:b21659aa8ad19fffc660 -->
### `bf81de068f12` `src/scratch/0041CCA0_get_scenario_header.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0041CCA0 RGE_Base_Game::get_scenario_header (253 B)
// PDB source: basegame.cpp
// Packet-grounded: sprintf path, rge_open/open_scenario, read 4-byte version, compare against known versions, virtual dispatch
```
<!-- end-recovered:b21659aa8ad19fffc660 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
