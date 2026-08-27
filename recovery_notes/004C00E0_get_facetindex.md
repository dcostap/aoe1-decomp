# 004C00E0 `RGE_Sprite::get_facetindex`

- PDB source: `sprite.cpp`, lines 441 to 471.
- State: accepted drift.

The function maps a facet and frame to a shape frame. The mirror cases preserve
the two-facet special case and the mirrored facet transform.

The remaining drift is a local register and store-reload choice in the mirrored
transform. The output value, return value, predicates, and field reads match.

## Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes the old
context header include.
