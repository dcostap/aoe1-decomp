# 004C0B70 `RGE_Sprite::get_frame_min_max`

- PDB source: `sprite.cpp`, lines 763 to 803.
- State: accepted drift.

The function maps the facet, obtains shape bounds, applies the mirror transform,
and merges the bounds into the four short outputs.

The source keeps the two helper calls, branch predicates, short stores, and
success and failure returns. The remaining bytes are register and liveness
choices after the second call. The natural direct-output source is retained.

## Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes the old
context header include.
