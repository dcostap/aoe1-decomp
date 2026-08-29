# Recovery journal: 00435320 `command_order`

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


<!-- recovered:13a596e9c692342eb576 -->
### `target-session` `build/target_sessions/00435320_command_order.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Tested typed compact master-name views at +8 for order target and unit logging.
probe 2 layout; result=MISMATCH; diff=1; shape=98.9010989010989: Added a typed compact signed player-ID view at +0x4A for owner logging.
probe 3 layout; result=MISMATCH; diff=1; shape=98.9010989010989: Made the local player-ID view polymorphic so its signed id remains at +0x4A, matching original movsx.
probe 4 layout; result=MATCH; diff=0; shape=100.0: Replaced the local polymorphic player proxy with a typed header-plus-signed-id aggregate to avoid generated helper symbols while preserving +0x4A. [same emitted code as probe 1]
```
<!-- end-recovered:13a596e9c692342eb576 -->

<!-- recovered:37b7a1897ad682342111 -->
### `912332e8f578` `src/matching/00435320_command_order.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00435320 RGE_Command::command_order (256B)
// PDB: Command.cpp lines 1203-1267
// Attempt log:
// - Replaced the placeholder with the natural Command.cpp packet builder,
//   using the exact neighboring command_move surface for object IDs, owner
//   and master-object names.
```
<!-- end-recovered:37b7a1897ad682342111 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
