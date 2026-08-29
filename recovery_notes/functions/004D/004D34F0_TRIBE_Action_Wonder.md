# Recovery journal: 004D34F0 `~TRIBE_Action_Wonder`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_wnd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_wnd.cpp`.
- Earlier recovery note: `recovery_notes/tact_wnd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d035e05f466d2754f00b -->
### `d050eea3c` `src/tact_wnd.cpp:31-31`

Mapping: `strong`. next mapped function definition is ~TRIBE_Action_Wonder at old line 37.

```text
// PDB lines 42-45; VA 004D34C0; matching before source reunification.
```
<!-- end-recovered:d035e05f466d2754f00b -->

<!-- recovered:1a9fb484ab630676c648 -->
### `a5fb96a1e6de` `src/scratch/004D34F0_TRIBE_Action_Wonder.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Action_Wonder::~TRIBE_Action_Wonder
// VA: 004D34F0
// PDB: tact_wnd.cpp:50-97
//
// FLAGS: /GX
//
// Attempt log:
// - draft 1: standalone class, no base → no EH/no base destructor call, 88.9%
```
<!-- end-recovered:1a9fb484ab630676c648 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
