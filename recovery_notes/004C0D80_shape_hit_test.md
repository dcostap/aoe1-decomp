# 004C0D80 `RGE_Sprite::shape_hit_test`

- PDB source: `sprite.cpp`, lines 855 to 915.
- State: accepted drift.

The function lazily loads the shape, maps the facet and frame, and handles the
transparent picking modes. Mode one calls `shape_check`. Mode two calls
`shape_minmax` and tests the transformed bounds.

The source keeps the eleven ordered calls, the `/GX` frame, the bounds, and the
fault order. The remaining difference is the shared upper-x compare and later
register coloring. No call, cleanup, or result behavior changes.

## Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes the old
context header include.
