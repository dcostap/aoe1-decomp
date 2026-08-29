# Recovery journal: 00528DE0 `start_scenario_editor`

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


<!-- recovered:4a78718b53c44fd93d2b -->
### `bf81de068f12` `src/scratch/00528DE0_start_scenario_editor.cpp:1-23`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00528DE0 TRIBE_Game::start_scenario_editor (374 B)
// PDB source: tribegam.cpp
// Packet-grounded: start scenario editor with setup calls
// [non-comment lines omitted during migration]
    // Call TRIBE_Screen_Scenario_Editor constructor
    // ...
```
<!-- end-recovered:4a78718b53c44fd93d2b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
