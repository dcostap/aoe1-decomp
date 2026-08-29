# Recovery journal: 0048E210 `~TribeAchievementsScreen`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_ach.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_ach.cpp`.
- Earlier recovery note: `recovery_notes/scr_ach_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:199f2c064a831b42974f -->
### `d050eea3c` `src/scr_ach.cpp:165-165`

Mapping: `ambiguous`. next mapped function definition is ~TribeAchievementsScreen at old line 289.

```text
    // BINARY NOTE: The shipped loop creates eight player rows.
```
<!-- end-recovered:199f2c064a831b42974f -->

<!-- recovered:4795bb3354217d61fea2 -->
### `d050eea3c` `src/scr_ach.cpp:219-219`

Mapping: `strong`. next mapped function definition is ~TribeAchievementsScreen at old line 289.

```text
    // BINARY NOTE: The shipped layout tests the non-null message arm first.
```
<!-- end-recovered:4795bb3354217d61fea2 -->

<!-- recovered:727a21b7a581b07bbc61 -->
### `98727635e181` `src/matching/0048E210_TribeAchievementsScreen.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0048E210 TribeAchievementsScreen::~TribeAchievementsScreen (493 B)
// PDB source: scr_ach.cpp (lines 360-435)
//
// Attempt log:
// - Replaced the unrelated offset/free shim with the packet-grounded destructor
//   surface: destroy YesNoDialog, delete the decal, delete the named panels,
//   then clean title/statistics arrays before the TScreenPanel base destructor.
```
<!-- end-recovered:727a21b7a581b07bbc61 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
