# Recovery journal: 004CAA00 `calc_attack_modifier`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_c_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_c_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_c_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:fd17dd0da6dd010aa7ec -->
### `57de5af98e5d` `src/scratch/004CAA00_calc_attack_modifier.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004CAA00 TRIBE_Combat_Object::calc_attack_modifier
// Canonical ownership is the shipped TRIBE_Combat_Object class in t_c_obj.cpp.
// The grouped t_c_obj context supplies the body data surface.
// Attempt log (2026-08-26 captain pass): the natural source emits a 74-byte
// body with matching frame, CFG, and field accesses. The grouped call uses vslot
// +0x1BC, but the executable calls vslot +0x24C.  The shared header lacks the
// proven inherited virtual surface between these slots.  A local raw dispatch
// or fake vtable is not a valid repair.  Keep this clean source until the
// shared class declaration is repaired.
// PDB places higher_check_for_cliff at +0x248 and higher_than_target at +0x24C.
// Restoring that named hierarchy, not synthetic slots, is required.
```
<!-- end-recovered:fd17dd0da6dd010aa7ec -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
