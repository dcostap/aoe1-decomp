# 004C01A0 `RGE_Sprite::do_draw`

- PDB source: `sprite.cpp`, lines 475 to 590.
- State: scratch.

The source lazily creates a `TShape`. It selects the facet, draw level, clip
box, color table, and normal or mirrored draw call. It keeps both draw-log
paths and the timing calls.

The current natural source has the correct ownership, calls, argument order,
color-table paths, and lazy-load behavior. It is not exact. The remaining
question is VC5 frame and register scheduling around the first local buffer.

## Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes the old
scratch context and local fallback class declarations.
