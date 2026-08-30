# Function notes: 004C0D80 `shape_hit_test`

## Earlier notes from `decomp_notes/functions/004C/004C0D80_shape_hit_test.md`

This section is historical. Use the status query for current state.

## 004C0D80 `RGE_Sprite::shape_hit_test`

- PDB source: `sprite.cpp`, lines 855 to 915.
- State: accepted drift.

The function lazily loads the shape, maps the facet and frame, and handles the
transparent picking modes. Mode one calls `shape_check`. Mode two calls
`shape_minmax` and tests the transformed bounds.

The source keeps the eleven ordered calls, the `/GX` frame, the bounds, and the
fault order. The remaining difference is the shared upper-x compare and later
register coloring. No call, cleanup, or result behavior changes.

### Reunification audit

The 2026-08-27 grouped compile rebuilt the owner at 516 bytes. It has 33 strict
positional differences. The frame, eleven ordered calls, relocations, and
boundary all match the original.

The audit confirms the lazy-load path, facet mapping, three picking modes,
shape arguments, bounds, and shared failure cleanup. The remaining difference
is the equivalent upper-x compare layout and register coloring. Keep
`accepted_drift`; do not promote without a fresh exact check.

### Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes the old
context header include.
