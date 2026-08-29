# Recovery journal: 0050A4C0 `do_command_attack_ground`

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


<!-- recovered:0feedcd816b7af8ca690 -->
### `5868718576a8` `src/scratch/0050A4C0_do_command_attack_ground.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// tried a direct loop with a 1-byte counter; VC5 shifted the prolog to push ebp early and changed the jle/je basin
// tried an explicit early exit to force jle; that drifted the stack frame and param load order instead of fixing the branch
// remaining mismatch is still the startup prolog/register-save shape around the count test
```
<!-- end-recovered:0feedcd816b7af8ca690 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
