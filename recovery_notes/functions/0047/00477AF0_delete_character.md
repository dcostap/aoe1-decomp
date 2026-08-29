# Recovery journal: 00477AF0 `delete_character`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Pnl_inp.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_inp.cpp`.
- Earlier recovery note: `recovery_notes/Pnl_inp_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:443f8fe78244326ab106 -->
### `3719bc4b64cd` `src/matching/00477AF0_delete_character.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00477AF0 TInputPanel::delete_character
// Source: Pnl_inp.cpp lines 663-760
// Attempt log:
// 1: initial reconstruction from packet/decompiler; close but start/p colored EBP/EBX opposite original.
// 2: mark start register no codegen change.
// 3: mark current pointer register no change.
// 4: declare current pointer before source-start pointer no change.
// 5: rewrite with literal decompiler pcVar names/order; only compare polarity/source spelling mismatches remain.
// 6: spell initial and LF-before tests with original operand order.
```
<!-- end-recovered:443f8fe78244326ab106 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
