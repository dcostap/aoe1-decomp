# Recovery journal: 0050A6E0 `do_command_repair`

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


<!-- recovered:03c86191b25cd0fb0820 -->
### `037950f4de84` `src/scratch/0050A6E0_do_command_repair.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// compact packet-processing shape first
// tried the direct packet decode and then an explicit RGE_Command base; mismatch stayed in the prolog/register basin
// remaining drift is the packet-field packing / register save order at the function entry
```
<!-- end-recovered:03c86191b25cd0fb0820 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
