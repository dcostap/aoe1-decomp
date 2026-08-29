# Recovery journal: 0050A490 `do_command_cancel_build`

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


<!-- recovered:650d0edcb59f104cbe3c -->
### `d050eea3c` `src/tcommand.cpp:427-428`

Mapping: `strong`. next mapped function definition is do_command_cancel_build at old line 494.

```text
// PDB order: lines 531-665.
// BINARY NOTE: Original game fields use draw_system +0x48 and quick_build +0x9A8.
```
<!-- end-recovered:650d0edcb59f104cbe3c -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
