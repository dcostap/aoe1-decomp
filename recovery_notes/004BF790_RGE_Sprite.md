# 004BF790 `RGE_Sprite::RGE_Sprite`

- PDB source: `sprite.cpp`, lines 78 to 135.
- Original size: 656 bytes.
- State: accepted drift.

The source reads the serialized sprite header. It resolves the main sound and
allocates the picture and facet sound lists. It reads three sound records per
facet and stores the same frame and sound values as the executable.

The rebuild has the same size, frame, calls, serialized destinations, null
branches, allocation effects, fault order, and return behavior. The remaining
bytes come from the VC5 allocation and register schedule. The function has no
SEH frame.

## Module merge

The body moved into `src/sprite.cpp` in PDB order. The merge removes the
fragment include and the context header include.
