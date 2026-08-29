# Recovery journal: 004165F0 `healObject`

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


<!-- recovered:a9be6978073fc7be66c5 -->
### `d050eea3c` `src/aiuaimod.cpp:2280-2280`

Mapping: `strong`. comment lies after mapped function healObject at old line 2278.

```text
// --- matching/004165F0_healObject.cpp ---
```
<!-- end-recovered:a9be6978073fc7be66c5 -->

<!-- recovered:7342f946b37955ebff17 -->
### `6a2aef2e2` `src/aiuaimod.cpp:2138-2139`

Mapping: `strong`. next mapped function definition is healObject at old line 2160.

```text
// Based on matched gatherObject/buildObject siblings.
// Sibling pattern: inverted condition, nested success, shared return-0 tail.
```
<!-- end-recovered:7342f946b37955ebff17 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
