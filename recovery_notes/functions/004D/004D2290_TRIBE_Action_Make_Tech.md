# Recovery journal: 004D2290 `~TRIBE_Action_Make_Tech`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_tek.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_tek.cpp`.
- Earlier recovery note: `recovery_notes/tact_tek_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:9434d8f8f90f99771ca3 -->
### `c6c70134c94b` `src/scratch/004D2290_TRIBE_Action_Make_Tech.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech destructor
// VA: 004D2290
// PDB: tact_tek.cpp:49-64
// EH-framed, needs /GX
// FLAGS: config/flags/004D2290_TRIBE_Action_Make_Tech.rsp
// added /GX rsp after extract showed EH-framed original; current source now extracts full size but has broad register/layout drift
// likely next fixes mirror matched siblings: accurate RGE_Action_Object layout, no fake extra vptr padding, and typed RGE_Base_Game member-call surface
// applied sibling object layout and typed RGE_Base_Game notify; edit diff improved, but EH prolog still has extra EDI save and destructor tail/register topology remains broad
```
<!-- end-recovered:9434d8f8f90f99771ca3 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
