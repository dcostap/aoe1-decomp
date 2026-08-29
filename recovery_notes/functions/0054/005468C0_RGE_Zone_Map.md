# Recovery journal: 005468C0 `RGE_Zone_Map`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/zone_map.cpp`.
- PDB source: `C:\msdev\work\age1_x1\zone_map.cpp`.
- Earlier recovery note: `recovery_notes/zone_map_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:473c34febb9929d339f9 -->
### `67301ea15fad` `src/matching/005468C0_RGE_Zone_Map.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005468C0 RGE_Zone_Map::RGE_Zone_Map(RGE_Map *, float *, long)
// PDB source: zone_map.cpp, lines 117-144
// Attempt log:
// - baseline: natural typed constructor with direct member loops and memcpy was 216 B;
//   it omitted the binary-proven 0xFF fill of the allocated zone_map.
// - behavior: restoring the binary-proven zone_map memset produced an exact
//   248-byte match; no custom flags or compiler-steering scaffolding needed.
```
<!-- end-recovered:473c34febb9929d339f9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
