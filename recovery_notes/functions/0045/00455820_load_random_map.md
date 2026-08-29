# Recovery journal: 00455820 `load_random_map`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\map.cpp`.
- Earlier recovery note: `recovery_notes/map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:1e4b783159ac77c30e5e -->
### `489810cbdcd9` `src/matching/00455820_load_random_map.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00455820 RGE_Map::load_random_map
// Source: map.cpp lines 262-264
// public: virtual void __thiscall RGE_Map::load_random_map(char*,char*,char*,char*)
//
// Attempt log:
// Probe 1: natural new-expression, default flags -> 80 vs 109, missing EH
// Probe 2: Added /GX rsp, size fixed with dummy array
// BINARY NOTE (map TU wave02): The target controller has size 0x4F5C.
// The shared map TU declaration omits that storage.  No source-only repair is supported.
```
<!-- end-recovered:1e4b783159ac77c30e5e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
