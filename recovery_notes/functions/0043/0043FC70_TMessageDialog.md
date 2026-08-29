# Recovery journal: 0043FC70 `TMessageDialog`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_msg.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Dlg_msg.cpp`.
- Earlier recovery note: `recovery_notes/dlg_msg_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:32e2d9a478c77123b00e -->
### `d050eea3c` `src/dlg_msg.cpp:1-2`

Mapping: `strong`. next mapped function definition is TMessageDialog at old line 8.

```text
// PDB source module: C:/msdev/work/age1_x1/Dlg_msg.cpp.
// Definitions follow the original source order.
```
<!-- end-recovered:32e2d9a478c77123b00e -->

<!-- recovered:bb513e2fccfac103fbc0 -->
### `458aaecbc2e6` `src/scratch/0043FC70_TMessageDialog.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043FC70 TMessageDialog::TMessageDialog (59B)
// PDB source: Dlg_msg.cpp lines 43-48
// tried manual-vtable class with explicit +0x490/+0x494/+0x498/+0x49C/+0x4A0 layout; call/base/prologue matches
// remaining drift: VC5 keeps hoisting the vtable store before dlg_type/text zeroing and reuses eax=0 for all button stores instead of xor ecx,ecx + late mov eax,esi
```
<!-- end-recovered:bb513e2fccfac103fbc0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
