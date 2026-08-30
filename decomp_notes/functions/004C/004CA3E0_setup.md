# Function notes: 004CA3E0 `setup`

Module notes: `decomp_notes/t_c_obj_module.md`.

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
