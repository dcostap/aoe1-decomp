# Recovery journal: 005213A0 `~TRIBE_Game`

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


<!-- recovered:2cf8b187c90b980bdd96 -->
### `bf81de068f12` `src/scratch/005213A0_TRIBE_Game.cpp:1-18`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005213A0 TRIBE_Game::~TRIBE_Game (625 B)
// PDB source: tribegam.cpp
// Packet-grounded: EH-framed, cleanup panels, comm, shutdown systems
// [non-comment lines omitted during migration]
    // EH frame via FS:[0]

    // Restore vtable
    *(int**)self = (int*)0x5771A8;

    // Close game screens
```
<!-- end-recovered:2cf8b187c90b980bdd96 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
