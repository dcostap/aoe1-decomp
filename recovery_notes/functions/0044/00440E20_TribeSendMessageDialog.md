# Recovery journal: 00440E20 `~TribeSendMessageDialog`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_smsg.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dlg_smsg.cpp`.
- Earlier recovery note: `recovery_notes/00440E20_TribeSendMessageDialog.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d8aa980293e32cd48ac1 -->
### `d050eea3c` `src/dlg_smsg.cpp:20-20`

Mapping: `ambiguous`. next mapped function definition is ~TribeSendMessageDialog at old line 157.

```text
// Source order follows the original PDB module.
```
<!-- end-recovered:d8aa980293e32cd48ac1 -->

<!-- recovered:21f856f48636d9c6034b -->
### `bf81de068f12` `src/scratch/00440E20_TribeSendMessageDialog.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TribeSendMessageDialog::~TribeSendMessageDialog — real pass (EH-framed)
// VA: 00440E20
// [non-comment lines omitted during migration]
    // Set vtable
    // delete_panel at +0x490 (title)
```
<!-- end-recovered:21f856f48636d9c6034b -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
