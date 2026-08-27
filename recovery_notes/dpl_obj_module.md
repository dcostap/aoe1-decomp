# dpl_obj.cpp source reunification

## Translation-unit context

- PDB source: `C:\\msdev\\work\\age1_x1\\dpl_obj.cpp`.
- The module owns 15 normal functions in PDB source order.
- The exact source owner is `src/dpl_obj.cpp`.
- The current main owner declarations remain in `include/dpl_obj.h` and its
  included headers.
- The compiler-generated scalar deleting destructor at `00441A40` has no
  source owner. It stays source-free and remains in
  `config/compiler_generated_functions.txt`.

## Status

The module has 13 matching owners and two accepted-drift owners. The translation
unit registers only the 13 matching owners as exact. The accepted-drift owners
remain outside exact registration.

`00441BB0` (`RGE_Doppleganger_Object::recycle_in_to_game`) has two LEA register
recolor bytes. The call sequence, branches, memory effects, cleanup, boundary,
relocations, and direct targets remain equivalent.

`004421F0` (`RGE_Doppleganger_Creator::add_doppleganger_check`) has four owner-
comparison register recolor bytes. The checks, loop bounds, array updates,
return paths, boundary, relocations, and direct targets remain equivalent.

The source uses the natural indexed loop in `004421F0`. It keeps the required
serialization casts, allocation conversions, and downcasts. It removes only
the redundant `RGE_Player*` self-cast in `perform_doppleganger_checks`.

The old translation-unit wrapper and all 15 source-bank owner fragments are
removed. No generated destructor source is added.

## Integration validation

The grouped candidate validation reports `MATCH` and `0.0000%` for all 13
exact owners. It also reports `MATCH` and `0.0000%` for generated `00441A40`.
Each row has the expected owner symbol, boundary, relocations, and direct
targets.

Focused grouped checks report the approved differences:

- `00441BB0`: 2 bytes, `0.5208%`, two LEA register-recolor bytes.
- `004421F0`: 4 bytes, `2.1622%`, four owner-comparison register-recolor bytes.

Both drift checks keep equal size, CFG shape, calls, relocations, boundaries,
and owner symbols. They remain accepted drift, not exact registrations.
