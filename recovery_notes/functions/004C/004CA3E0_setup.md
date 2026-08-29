# Recovery journal: 004CA3E0 `setup`

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


<!-- recovered:12a414f425aa8dc8d2ab -->
### `3edbfd6aad1c` `src/scratch/004CA3E0_setup.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004CA3E0 TRIBE_Combat_Object::setup(int, RGE_Game_World*)
// PDB source: t_c_obj.cpp:152-180
//
// Binary-supported ownership used here:
//   RGE_Combat_Object owns master_obj (+0x08), owner (+0x0c), type (+0x4e),
//   and the UnitAIModule pointer (+0x74); TRIBE_Combat_Object adds
//   own_master at +0x1c4.  The vtable padding mirrors the exact sibling
//   setup in this translation unit so initUnitAI remains at +0x250.
//
// Baseline: natural deserialization setup with the original parameter-home
// reuse for the one-byte master kind and final four-byte presence flag.
// Main-agent audit restored canonical player/world/combat destructor ownership
// and renamed the persistent file handle; emitted code remains exact.
```
<!-- end-recovered:12a414f425aa8dc8d2ab -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
