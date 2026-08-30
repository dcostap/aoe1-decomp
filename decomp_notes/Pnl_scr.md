# Pnl_scr.cpp module recovery

The PDB assigns eight source-ordered normal owners to `TScreenPanel`.
`0047BA90` is a generated deleting destructor.

The direct module uses `src/Pnl_scr.cpp` and `include/Pnl_scr.h`.
The header owns only TScreenPanel. It uses canonical panel, easy-panel,
draw-area, draw-system, and color owners.

The source has no wrapper, fragment include, copied base layout, context macro,
or raw field cursor. `RGE_fade_palette` stays a local declaration because its
owner header does not publish it.

Candidate validation matched seven normal owners and the generated destructor.
`0047BB60` remains scratch. It differs by four bytes with no relocation mismatch
or boundary escape. It keeps the natural named palette locals.
