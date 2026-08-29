# Recovery journal: 0050F410 `TRIBE_Map`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tmap.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tmap.cpp`.
- Earlier recovery note: `recovery_notes/tmap_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:385f138386fcd17d54df -->
### `d050eea3c` `src/tmap.cpp:1-2`

Mapping: `strong`. next mapped function definition is TRIBE_Map at old line 15.

```text
// PDB source module: C:\\msdev\\work\\age1_x1\\tmap.cpp.
// Definitions follow the original source order.
```
<!-- end-recovered:385f138386fcd17d54df -->

<!-- recovered:afcb52576c256b8a25bf -->
### `bf81de068f12` `src/scratch/0050F410_TRIBE_Map.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0050F410 TRIBE_Map ctor (805B)
// tmap.cpp
// EH frame (/GX)
```
<!-- end-recovered:afcb52576c256b8a25bf -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
