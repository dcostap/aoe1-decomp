# Recovery journal: 0047BB60 `set_focus`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Pnl_scr.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_scr.cpp`.
- Earlier recovery note: `recovery_notes/Pnl_scr_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:95f5167194ea30331ec1 -->
### `947c55021709` `src/scratch/0047BB60_set_focus.cpp:1-16`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 0047BB60 TScreenPanel::set_focus
// Source: Pnl_scr.cpp lines 106-145
// Size: 383 bytes
// FLAGS: default (/nologo /c /O2 /Oy)
//
// Attempt log:
// - Baseline had the correct 0x408 frame after adding a local PALETTEENTRY, but
//   used a direct GetPaletteEntries call and reversed the palette-handle arms.
// - Restored the Windows stdcall import, DAT_0086b248 relocation, null-handle
//   fall-through, and the binary-proven zeroed PALETTEENTRY dword as every fade's
//   color argument. Calls/CFG then aligned 11/11; no behavior gap remains known.
// - Direct draw_area rereads plus bool is_new recover the original saved EBX and
//   92.42% instruction-shape similarity, but VC5 keeps focus_copy in EBP and
//   allocates a 0x404 frame instead of the original EBP parameter/0x408 frame.
// - Tried declaration-order and parameter-local variants; emitted code duplicated.
// Left in scratch — remaining drift is the documented VC5 register/frame basin.
```
<!-- end-recovered:95f5167194ea30331ec1 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
