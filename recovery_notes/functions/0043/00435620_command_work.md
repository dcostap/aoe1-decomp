# Recovery journal: 00435620 `command_work`

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


<!-- recovered:3c43504ce1e36de0582a -->
### `target-session` `build/target_sessions/00435620_command_work.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Tested typed compact master-name views for target and unit log accesses at the proven +8 field.
probe 2 layout; result=MISMATCH; diff=1; shape=98.9010989010989: Added a typed compact signed player-ID view at +0x4A for owner logging.
probe 3 layout; result=MISMATCH; diff=1; shape=98.9010989010989: Made the local player-ID view polymorphic so its signed id remains at +0x4A, matching original movsx.
probe 4 layout; result=MATCH; diff=0; shape=100.0: Replaced the local polymorphic player proxy with a typed header-plus-signed-id aggregate to avoid generated helper symbols while preserving +0x4A. [same emitted code as probe 1]
```
<!-- end-recovered:3c43504ce1e36de0582a -->

<!-- recovered:130872e73528dcb99ee6 -->
### `9b81182dceff` `src/scratch/00435620_command_work.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00435620 RGE_Command::command_work (256B)
// PDB: Command.cpp lines 1405-1468
// Attempt log:
// - Replaced the placeholder with the natural selected-unit work packet builder.
// - The packet uses the proven +0x14 variable ID array, target ID, count, and
//   coordinate fields; logging follows the original target-name then unit-name
//   and owner evaluation order.
// - The best reconstruction is 256 bytes with the original three direct calls,
//   exact size/frame, and 86.96% instruction-shape similarity (180 positional
//   bytes remain). Count/pointer aliases and source-order variants were
//   codegen duplicates or introduced an 8-byte frame; the remaining mismatch
//   is the early VC5 prologue/list-pointer coloring and later logging topology.
```
<!-- end-recovered:130872e73528dcb99ee6 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
