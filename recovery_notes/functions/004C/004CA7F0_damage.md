# Recovery journal: 004CA7F0 `damage`

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


<!-- recovered:45b008217e5e58ce90ed -->
### `0923cad7edb1` `src/matching/004CA7F0_damage.cpp:1-14`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004CA7F0 TRIBE_Combat_Object::damage
// PDB source: t_c_obj.cpp:330-362
//
// Canonical ownership recovered from the binary and exact same-TU donors:
// RGE_Combat_Object owns owner (+0x0C) and hp (+0x30); the target owns a
// master object at +0x08 and that master has object_group at +0x14.  The
// three virtual calls use the established RGE object/player slots.
//
// Attempt log:
// baseline: natural TRIBE_Combat_Object damage wrapper with a float hp
// snapshot, the base damage call, and typed virtual calls.
// probe 2: kept DAT_00574c78 for the observed FPU operands but used the
// source literal 1.0f for add_attribute_num; the original pushes the IEEE
// immediate rather than loading the shared float global at that call site.
```
<!-- end-recovered:45b008217e5e58ce90ed -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
