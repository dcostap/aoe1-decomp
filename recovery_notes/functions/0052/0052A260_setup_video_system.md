# Recovery journal: 0052A260 `setup_video_system`

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


<!-- recovered:f28454a747712742a824 -->
### `bf81de068f12` `src/scratch/0052A260_setup_video_system.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0052A260 TRIBE_Game::setup_video_system (450 B)
// PDB source: tribegam.cpp
// Packet-grounded: EH-framed, create TDrawSystem, set up TDrawArea chain
// [non-comment lines omitted during migration]
    // EH frame via FS:[0]
    // ...

    // Create TDrawSystem (operator_new + constructor)
```
<!-- end-recovered:f28454a747712742a824 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
