# Recovery journal: 00436150 `command_group_waypoint`

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


<!-- recovered:05a2611c1366c3e4eead -->
### `target-session` `build/target_sessions/00436150_command_group_waypoint.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Tested a typed compact master-name view at +8 for group-waypoint logging.
probe 2 layout; result=MISMATCH; diff=1; shape=98.64864864864865: Added a typed compact signed player-ID view at +0x4A for owner logging.
probe 3 layout; result=MATCH; diff=0; shape=100.0: Made the local player-ID view polymorphic so its signed id remains at +0x4A, matching original movsx. [same emitted code as probe 1]
probe 4 layout; result=MATCH; diff=0; shape=100.0: Replaced the local polymorphic player proxy with a typed header-plus-signed-id aggregate to avoid generated helper symbols while preserving +0x4A. [same emitted code as probe 3]
```
<!-- end-recovered:05a2611c1366c3e4eead -->

<!-- recovered:bdc4a682eba0b0322e81 -->
### `7051f0b5bdc7` `src/matching/00436150_command_group_waypoint.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00436150 RGE_Command::command_group_waypoint (204B)
// Command.cpp lines 2112-2158.
//
// Attempt log:
// - Replaced the stale placeholder with the period-plausible packet builder
//   supported by the original list-copy, object-name, owner-id, log, and submit
//   call sequence.  The command packet is four header bytes followed by one
//   dword per selected object.
```
<!-- end-recovered:bdc4a682eba0b0322e81 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
