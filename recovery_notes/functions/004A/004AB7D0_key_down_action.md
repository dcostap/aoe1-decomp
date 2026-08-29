# Recovery journal: 004AB7D0 `key_down_action`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sed.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sed.cpp`.
- Earlier recovery note: `recovery_notes/scr_sed.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:0fa52c666174e2548614 -->
### `54d8af8b2642` `src/scratch/004AB7D0_key_down_action.cpp:1-15`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004AB7D0 TRIBE_Screen_Sed::key_down_action
// scr_sed.cpp
// Attempt log:
// try 1: broad reconstruction from packet: modal guard, key-with-modifier shortcuts, numeric panel shortcuts, scenario-editor command shortcuts.
// try 2: modeled initial global input/modal guard through 0x62E870 and early return when busy.
// try 3: modeled flags/nonzero branch using key range 'A'..'W', including view mode toggle for 'A'.
// try 4: modeled Ctrl/modified B..K cases as repeated button(+0x4D8..+0x4FC)->setMode(1) followed by set_panel(1..10) and return 0.
// try 5: modeled scenario cycle key using global 0x87D7B4, main-view test, wrap to 0/1/4, and messageButton->setMode(2).
// try 6: modeled no-flags numeric key dispatch range '0'..'9' for panelMode 8/3/4/6/5 and generic commandNum path.
// try 7: modeled panelMode 8 path: refreshList, list select, virtual doAction(...,3,0,0), commandNum, selectedNum, updateAfter.
// try 8: modeled panelMode 3/6 lockPanel +0x3C guards and panelMode 4 direct selection.
// try 9: modeled function-key/editor command cases 0x70..0x73, including openThing(openA/openB), otherAction, current player close/cancel flow and message button update.
// try 10: fixed local layout typo (p8/p5 offsets) so source compiles.
// try 11: default compile matches original size exactly at 1121B, but mismatch is broad: 930 positional bytes / 82.96%, first mismatch at early branch distance/parameter slot and large switch table/control topology. /GX not needed.
// left in scratch: broad behavior and size are present, but exact switch-table grouping, parameter ordering, repeated early-return layout, and virtual call surfaces differ too widely. No accepted_drift: broad control-flow/register mismatch.
```
<!-- end-recovered:0fa52c666174e2548614 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
