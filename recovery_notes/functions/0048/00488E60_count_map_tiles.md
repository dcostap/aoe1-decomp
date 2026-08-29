# Recovery journal: 00488E60 `count_map_tiles`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/rmm_terr.cpp`.
- PDB source: `C:\msdev\work\age1_x1\rmm_terr.cpp`.
- Earlier recovery note: `recovery_notes/rmm_terr_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:10cb44ec182fa35c9214 -->
### `d050eea3c` `src/rmm_terr.cpp:257-257`

Mapping: `strong`. comment lies after mapped function count_map_tiles at old line 253.

```text
    // BINARY NOTE: The executable scans +0x10 rows with +0x18 tile records.
```
<!-- end-recovered:10cb44ec182fa35c9214 -->

<!-- recovered:2232fd3030e0905fee3f -->
### `00492347d989` `src/scratch/00488E60_count_map_tiles.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_RMM_Terrain_Generator::count_map_tiles
// VA: 00488E60
// rmm_terr.cpp:231-241
// 54 bytes, 19 diff bytes (35.19%)
// Body (35 bytes) is exact match. Prolog register scheduling differs:
// Original: eax=width*total, ecx=total*3 (overwrites this), esi=end
// Rebuilt: esi=height*total→end, ecx=total*3, eax=tileInfo (discarded)
// TU-context register allocation issue. 7+ source forms tried.
// Cleanest version kept below.
```
<!-- end-recovered:2232fd3030e0905fee3f -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
