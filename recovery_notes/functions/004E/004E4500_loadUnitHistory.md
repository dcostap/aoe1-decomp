# Recovery journal: 004E4500 `loadUnitHistory`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:f045498595a70b83c10d -->
### `fc4b000c6e8f` `src/matching/004E4500_loadUnitHistory.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004E4500 TribeInformationAIModule::loadUnitHistory()
// Source: taiinfmd.cpp lines 8454-8470
// Size: 149 bytes, __thiscall, ret
// Returns void
// MATCH (0% diff, 8 relocations masked)
//
// Loads unit history from "learn\\{player_name}.uh" or "learn\\Default.uh"
// Key: char[256] local buffer (not 260) for exact stack frame size
```
<!-- end-recovered:f045498595a70b83c10d -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
