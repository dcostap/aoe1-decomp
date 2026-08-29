# Recovery journal: 00512690 `scenario_load`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tplayer.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tplayer.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:96f873351f3730f0d7b3 -->
### `912332e8f578` `src/matching/00512690_scenario_load.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00512690 TRIBE_Player::scenario_load(int, long*, float)
// Source: tplayer.cpp lines 665-706
// FLAGS: config/flags/00512690_scenario_load.rsp
// Attempt log:
// - Initial natural implementation from packet/decompiler with local layouts.
// - Tried default flags first: compiled to only 432 bytes with no EH frame, while original has VC5 EH registration; kept /GX hypothesis.
// - Corrected virtual-base local layout by accounting for the hidden vptr: first gap is 0x1E so objectCount lands at +0x22, while later target offsets remain source offsets.
// - Normal `new TRIBE_Player_Tech(...)` was required for VC5 /GX EH state/unwind scaffolding; placement-new source was too small/no EH.
// - Exact match: duplicate the final do_tech_effect call in the if/else source instead of computing a `techID` temp. VC5 tail-merges the duplicate calls into the original shared call setup; the temp form generated a shorter, different branch family.
```
<!-- end-recovered:96f873351f3730f0d7b3 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
