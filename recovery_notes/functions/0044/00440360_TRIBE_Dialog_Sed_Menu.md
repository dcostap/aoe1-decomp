# Recovery journal: 00440360 `~TRIBE_Dialog_Sed_Menu`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_sedm.cpp`.
- PDB source: `C:\msdev\work\age1_x1\dlg_sedm.cpp`.
- Earlier recovery note: `recovery_notes/dlg_sedm_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:a979e4a09f99f54f434c -->
### `d050eea3c` `src/dlg_sedm.cpp:1-2`

Mapping: `strong`. next mapped function definition is ~TRIBE_Dialog_Sed_Menu at old line 53.

```text
// PDB source module: C:\\msdev\\work\\age1_x1\\dlg_sedm.cpp.
// The definitions follow the original source-line and address order.
```
<!-- end-recovered:a979e4a09f99f54f434c -->

<!-- recovered:c22e6d83ff16ffeb93ff -->
### `800c924204be` `src/matching/00440360_TRIBE_Dialog_Sed_Menu.cpp:1-6`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00440360 TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu
// Source: dlg_sedm.cpp lines 64-75
//
// Attempt log:
// Probe 1: close but esi/edi registers swapped for this vs loop pointer
// Probe 2: reorder locals to influence register allocation
```
<!-- end-recovered:c22e6d83ff16ffeb93ff -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
