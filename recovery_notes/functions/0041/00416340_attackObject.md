# Recovery journal: 00416340 `attackObject`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/aiuaimod.cpp`.
- PDB source: `C:\msdev\work\age1_x1\aiuaimod.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:300a1e97030f96c5aa47 -->
### `d050eea3c` `src/aiuaimod.cpp:2157-2158`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// --- matching/00416340_attackObject.cpp ---
// 00416340 UnitAIModule::attackObject
```
<!-- end-recovered:300a1e97030f96c5aa47 -->

<!-- recovered:6589908e4ae8193d6308 -->
### `70d829c1e6f9` `src/matching/00416340_attackObject.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00416340 UnitAIModule::attackObject
// natural virtual declarations with observed slot padding.
```
<!-- end-recovered:6589908e4ae8193d6308 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
