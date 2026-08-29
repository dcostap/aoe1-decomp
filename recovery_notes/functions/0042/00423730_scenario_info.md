# Recovery journal: 00423730 `scenario_info`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/campaign.cpp`.
- PDB source: `C:\msdev\work\age1_x1\campaign.cpp`.
- Earlier recovery note: `recovery_notes/campaign_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:679f563b4dca72e437b7 -->
### `0c00f3d2dd72` `src/scratch/00423730_scenario_info.cpp:1-3`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: direct scenario table walk with calloc(count, 4), out-param store, and per-entry getstring copies
// attempt 2: switch to the decompiler-style iVar shape and direct *param_1 access; the first exact-match clue was a 4-byte code-size overshoot, so this is a small basin probe
// attempt 3 rolled back: a local source pointer pulled the whole function into the wrong register basin, so keep the decompiler-style shape and only track the remaining LEA-byte drift
```
<!-- end-recovered:679f563b4dca72e437b7 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
