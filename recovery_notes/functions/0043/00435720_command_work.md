# Recovery journal: 00435720 `command_work`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Command.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Command.cpp`.
- Earlier recovery note: `recovery_notes/Command_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:bf7374567d4de5c0106e -->
### `912332e8f578` `src/matching/00435720_command_work.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// MATCH: 00435720 RGE_Command::command_work (231B)
// PDB: Command.cpp lines 1474-1516
// Packet-copy command builder, modeled from original asm and matched command_stop idioms.
```
<!-- end-recovered:bf7374567d4de5c0106e -->

<!-- recovered:715a107916d433f1ada8 -->
### `912332e8f578` `src/matching/00435720_command_work.cpp:38-39`

Mapping: `exact`. historical standalone source path names this target VA.

```text
            *(int*)(buf + 4) = target;
            *(float*)(buf + 0x10) = y;
```
<!-- end-recovered:715a107916d433f1ada8 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
