# Recovery journal: 00435AE0 `command_formation`

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


<!-- recovered:45ccc7503a639246e4a9 -->
### `target-session` `build/target_sessions/00435AE0_command_formation.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Tested a typed compact master-name view at +8 for the formation log.
probe 2 layout; result=MISMATCH; diff=1; shape=98.66666666666667: Added a typed compact signed player-ID view at +0x4A for owner logging.
probe 3 layout; result=MISMATCH; diff=1; shape=98.66666666666667: Made the local player-ID view polymorphic so its signed id remains at +0x4A, matching original movsx.
probe 4 layout; result=MATCH; diff=0; shape=100.0: Replaced the local polymorphic player proxy with a typed header-plus-signed-id aggregate to avoid generated helper symbols while preserving +0x4A. [same emitted code as probe 1]
```
<!-- end-recovered:45ccc7503a639246e4a9 -->

<!-- recovered:e653f1357bbe6f1d6a84 -->
### `7051f0b5bdc7` `src/matching/00435AE0_command_formation.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00435AE0 RGE_Command::command_formation (207B)
// Command.cpp lines 1724-1767.
//
// Attempt log:
// - Replaced the stale placeholder with the period-plausible formation packet
//   builder supported by the original calloc, ID-copy, logging, and submit
//   sequence.
// - The natural typed ownership surface and default VC5 flags matched all 207
//   bytes; no codegen-only scaffolding was needed.
```
<!-- end-recovered:e653f1357bbe6f1d6a84 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
