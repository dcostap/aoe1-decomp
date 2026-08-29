# Recovery journal: 00433D40 `RGE_Command`

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


<!-- recovered:de9bd1441356a0af6179 -->
### `target-session` `build/target_sessions/00433D40_RGE_Command.json:1-3`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=8; shape=90.0: Standalone baseline before grouped repair; constructor differs by 8 bytes.
probe 2 variant; result=MISMATCH; diff=11; shape=90.0: Store-order variant tested zeros before com_hand to seek the observed world/com_hand/vptr order.
probe 3 liveness; result=MISMATCH; diff=14; shape=80.0: Tested a natural member-initializer constructor form to seek the observed delayed vptr store.
```
<!-- end-recovered:de9bd1441356a0af6179 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
