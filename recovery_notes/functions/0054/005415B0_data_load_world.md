# Recovery journal: 005415B0 `data_load_world`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/world.cpp`.
- PDB source: `C:\msdev\work\age1_x1\World.cpp`.
- Earlier recovery note: `recovery_notes/world_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:fb849e2742544176db91 -->
### `2b7c866cbb3c` `src/matching/005415B0_data_load_world.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005415B0 RGE_Game_World::data_load_world(FILE*)
// PDB source: World.cpp lines 624-695
// attempt 1: natural named 24-byte filename buffers; frame was 0x188 and local order differed.
// attempt 2: one exact 0x18C stack window with binary-observed offsets for the 16 filename records and scalar outputs; fscanf setup matched through add esp.
// attempt 3: use binary-observed post-fscanf argument offsets rather than nominal filename bases; matched through data_load_effects.
// attempt 4: model three data_load_sprites parameters as by-value dwords reloaded from stack slots, not addresses; only three LEA displacements remain.
// attempt 5: tune the remaining data_load_sprites pointer offsets for VC5's right-to-left argument scheduling.
```
<!-- end-recovered:fb849e2742544176db91 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
