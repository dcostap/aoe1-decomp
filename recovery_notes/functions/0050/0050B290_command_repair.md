# Recovery journal: 0050B290 `command_repair`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tcommand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tcommand.cpp`.
- Earlier recovery note: `recovery_notes/tcommand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:72cade9aec3f0a4d012e -->
### `a5fb96a1e6de` `src/accepted_drift/0050B290_command_repair.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// ACCEPTED_DRIFT: localized tail scheduling/register drift only. Rebuilt prepares the log pushes before loading the count byte, then performs the same target-id load, packet command/target/count stores, log call, submit call, and stack cleanup; the earlier loop and allocation path match exactly.
// started from command_unload's matching donor-file context; moving obj_count/size before the guard fixed the prolog and list-copy loop.
```
<!-- end-recovered:72cade9aec3f0a4d012e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
