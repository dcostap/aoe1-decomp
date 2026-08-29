# Recovery journal: 00435420 `command_stop`

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


<!-- recovered:227cbce5b3a4f6ea78aa -->
### `target-session` `build/target_sessions/00435420_command_stop.json:1-4`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Tested a typed compact master-name view at +8, matching the command log's proven access while avoiding raw pointer arithmetic.
probe 2 layout; result=MISMATCH; diff=1; shape=98.63013698630137: Added a typed compact signed player-ID view at +0x4A, matching original movsx owner logging.
probe 3 layout; result=MISMATCH; diff=1; shape=98.63013698630137: Made the local player-ID view polymorphic so its signed id remains at +0x4A, matching original movsx.
probe 4 layout; result=MATCH; diff=0; shape=100.0: Replaced the local polymorphic player proxy with a typed header-plus-signed-id aggregate to avoid generated helper symbols while preserving +0x4A. [same emitted code as probe 1]
```
<!-- end-recovered:227cbce5b3a4f6ea78aa -->

<!-- recovered:93fdac11f6f5893f8fc8 -->
### `7051f0b5bdc7` `src/matching/00435420_command_stop.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00435420 RGE_Command::command_stop (200B)
// Baseline: natural command-packet construction from the Command.cpp call and
// field evidence.  Keep the proven RGE_Static_Object ownership surface local.
// Attempt log:
// - Hoisted the packet-size calculation before the input guard; this restored the
//   original 8-byte frame and early short-count load.
// - Spelled the count guard as >= 1; this restored cmp ax,1 / jl.
// - Kept name and owner selection as sibling null-tested blocks; exact match.
```
<!-- end-recovered:93fdac11f6f5893f8fc8 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
