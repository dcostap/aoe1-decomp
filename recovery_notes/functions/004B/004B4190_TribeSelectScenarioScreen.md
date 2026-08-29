# Recovery journal: 004B4190 `~TribeSelectScenarioScreen`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Scr_sels.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Scr_sels.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:817e1f28fcb1cc826d51 -->
### `28def1a56af5` `src/matching/004B4190_TribeSelectScenarioScreen.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004B4190 | TribeSelectScenarioScreen::~TribeSelectScenarioScreen() | Scr_sels.cpp:167-179 | 226 bytes
// /GX EH-framed virtual destructor: restores derived vtable, deletes 11 panels in
// member order via TPanel::delete_panel, then tails into base ~TScreenPanel.
// Pattern mirrors matched sibling 004A75C0 TribeSaveGameScreen::~TribeSaveGameScreen.
// FLAGS: config/flags/004B4190_TribeSelectScenarioScreen.rsp (/GX for original EH frame)
```
<!-- end-recovered:817e1f28fcb1cc826d51 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
