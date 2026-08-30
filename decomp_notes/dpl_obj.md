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

The module has 14 matching owners and one accepted-drift owner. The translation
unit registers all 14 matching owners as exact.

`00441BB0` (`RGE_Doppleganger_Object::recycle_in_to_game`) has two LEA register
recolor bytes. The call sequence, branches, memory effects, cleanup, boundary,
relocations, and direct targets remain equivalent.

The final grouped reconciliation promotes `004421F0`. It reports `MATCH`,
`0.0000%`, with valid ownership, boundaries, and relocations.

The source uses the natural indexed loop in `004421F0`. It keeps the required
serialization casts, allocation conversions, and downcasts. It removes only
the redundant `RGE_Player*` self-cast in `perform_doppleganger_checks`.

The old translation-unit wrapper and all 15 source-bank owner fragments are
removed. No generated destructor source is added.

## Integration validation

The final grouped validation reports `MATCH` and `0.0000%` for all 14
exact owners. It also reports `MATCH` and `0.0000%` for generated `00441A40`.
Each row has the expected owner symbol, boundary, relocations, and direct
targets.

The focused grouped check reports the approved difference:

- `00441BB0`: 2 bytes, `0.5208%`, two LEA register-recolor bytes.

The `00441BB0` drift check keeps equal size, CFG shape, calls, relocations,
boundaries, and owner symbols. It remains accepted drift.

## Wave20 full-audit reconciliation

The fresh full audit disproves the stale `004421F0 add_doppleganger_check`
exact claim by four bytes. The row is scratch and is no longer registered.
