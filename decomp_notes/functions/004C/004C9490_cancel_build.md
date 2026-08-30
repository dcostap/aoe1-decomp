# Function notes: 004C9490 `cancel_build`

Module notes: `decomp_notes/t_b_obj_module.md`.

## Recovered attempt history

<!-- recovered:f99fb7432e13d9cc3d19 -->
### `fa987c10075f` `src/matching/004C9490_cancel_build.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C9490 TRIBE_Building_Object::cancel_build
// PDB source: t_b_obj.cpp
// Baseline: named building/master ownership with the natural percent refund
// calculation and three-element Attribute_Cost scan.
// Attempt log:
// - Baseline natural inventory-element pointer alias matched frame/calls but
//   chose ESI for this, added a loop LEA, and emitted a double-to-float clamp.
// - Direct typed build_inventory[i] accesses plus a float 1.0f clamp matched
//   all 206 bytes; the array element stride produced the original ESI cursor.
// - Moved proven master/owner/hp/selected/state fields into the local
//   RGE_Static_Object base; code remained exact and ownership is canonical.
```
<!-- end-recovered:f99fb7432e13d9cc3d19 -->
