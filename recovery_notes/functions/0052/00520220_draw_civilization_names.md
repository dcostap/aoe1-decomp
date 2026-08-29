# Recovery journal: 00520220 `draw_civilization_names`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tpnl_tml.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tpnl_tml.cpp`.
- Earlier recovery note: `recovery_notes/tpnl_tml_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d83bc32c46386cf7a0b2 -->
### `6e2375c51785` `src/scratch/00520220_draw_civilization_names.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00520220 Time_Line_Panel::draw_civilization_names
// Attempt log:
// try 1: natural reconstruction from packet/Ghidra with GDI IAT function-pointer surface, game/world/player/history minimal layouts.
// try 2: initial source compiled exact-size 626 but broad drift: frame 0x148 vs original 0x144 and this kept in EBX instead of EBP.
// try 3: nested-control-flow form instead of early returns; still frame 0x148 and this kept in EBX.
// try 4: raw byte-offset player indexing for the population scan; reduced output to 624 bytes but did not recover original prologue/register allocation.
// try 5: raw byte-offset player indexing for the draw loop; same family, original wants EBX as player-array byte offset only after 00520333.
// try 6: /GX tested; no useful change, removed.
// try 7: /Od tested; exact size but completely wrong debug-basin codegen, removed.
// try 8: corrected RGE_Base_Game get_string virtual slot to +0x28; call surface now matches original vtable offset but size/register drift remains.
// try 9: kept GDI calls as extern function pointers to preserve indirect IAT call style.
// try 10: leaving in scratch: clean behavioral source is 624B vs 626B with immediate prologue/frame/register mismatch, so not accepted_drift-safe.
```
<!-- end-recovered:d83bc32c46386cf7a0b2 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
