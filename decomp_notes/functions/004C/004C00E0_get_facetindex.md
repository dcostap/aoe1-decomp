# Function notes: 004C00E0 `get_facetindex`

## Earlier notes from `decomp_notes/functions/004C/004C00E0_get_facetindex.md`

This section is historical. Use the status query for current state.

## 004C00E0 `RGE_Sprite::get_facetindex`

- PDB source: `sprite.cpp`, lines 441 to 471.
- State: accepted drift.

The function maps a facet and frame to a shape frame. The mirror cases preserve
the two-facet special case and the mirrored facet transform.

The remaining drift is a local register and store-reload choice in the mirrored
transform. The output value, return value, predicates, and field reads match.

### Reunification audit

The 2026-08-27 grouped compile rebuilt the owner at 181 meaningful bytes
against the 185-byte original. It has 93 strict positional differences and no
relocation or boundary error.

The audit confirms four returns, seven conditional branches, the two mirror
paths, and the same output and field values. The rebuilt source removes the
original store and reload through the output reference. This shortens one
mirrored-transform block by four bytes. Keep `accepted_drift`; the difference
is local and behavior-equivalent.

### Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes the old
context header include.
