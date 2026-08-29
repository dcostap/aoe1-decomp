# Recovery journal: 004C82A0 `~TRIBE_Building_Object`

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


<!-- recovered:32a6b37bdd3a68a114f0 -->
### `fa987c10075f` `src/matching/004C82A0_TRIBE_Building_Object.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C82A0 TRIBE_Building_Object::~TRIBE_Building_Object
// PDB source: t_b_obj.cpp:129-151
// Baseline: period-plausible derived destructor with the production queue and
// action-list ownership shown by the executable.
// Attempt log:
// - Natural virtual action-list destruction emitted an indirect call; the
//   qualified derived destructor call below preserves the observed direct
//   RGE_Action_List::~RGE_Action_List call at 00403EC0.
```
<!-- end-recovered:32a6b37bdd3a68a114f0 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
