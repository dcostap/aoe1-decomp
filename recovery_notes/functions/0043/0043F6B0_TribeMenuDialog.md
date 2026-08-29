# Recovery journal: 0043F6B0 `~TribeMenuDialog`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_menu.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dlg_menu.cpp`.
- Earlier recovery note: `recovery_notes/dlg_menu_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3f1785c332a54681f0ef -->
### `74a18731f249` `src/matching/0043F6B0_TribeMenuDialog.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0043F6B0 TribeMenuDialog::~TribeMenuDialog
//
// Probe 1: while loop with pointer — wrong loop structure
// Probe 2: fixed TPanel size (0xF4) — button at +0x490 ✓, but while loop uses pointer-compare not count-down
// Probe 3: count-down loop to match original `dec ebx; jne`
```
<!-- end-recovered:3f1785c332a54681f0ef -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
