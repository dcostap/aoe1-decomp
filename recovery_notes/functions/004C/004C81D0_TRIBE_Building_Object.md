# Recovery journal: 004C81D0 `TRIBE_Building_Object`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:01115259f3e908bed4df -->
### `44679cc1b979` `src/matching/004C81D0_TRIBE_Building_Object.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C81D0 TRIBE_Building_Object::TRIBE_Building_Object
// PDB source: t_b_obj.cpp:117-124
// Baseline: natural three-argument constructor with the proven production
// queue layout, base constructor, setup gate, and doppleganger registration.
```
<!-- end-recovered:01115259f3e908bed4df -->

<!-- recovered:c2a226781cd688afe8ba -->
### `44679cc1b979` `src/matching/004C81D0_TRIBE_Building_Object.cpp:71-74`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // The separated constructor surface needs the derived vptr store at the
    // original body position; VC5 otherwise schedules its implicit store before
    // these member initializations.
    *(void**)this = (void*)0x574778;
```
<!-- end-recovered:c2a226781cd688afe8ba -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
