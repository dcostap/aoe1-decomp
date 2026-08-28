# map.cpp source module

`src/map.cpp` is the compiler-facing source for
`C:\msdev\work\age1_x1\map.cpp`. It owns all 64 normal functions in PDB
source order. The vector-deleting destructor at `00455080` is generated.

The module uses `map.h` and canonical Map dependencies. It has no source
wrapper, context selection, copied class, raw Map layout, or Tile alias.
Tiles use named `terrain_type`, `height`, `border_type`, `border_shape`, and
`RGE_Object_List` fields.

## Validation

A pinned VC5 module build completed. Candidate validation used
`build/map_natural_candidate.json` and compiled all 64 normal owners.

`004550A0` and `0045A6D0` are current exact claims. Both report `MATCH`,
`0.0000%`, correct owner, relocation targets, and boundary.

The candidate also found 30 other byte matches. They remain scratch. The
candidate has 18 unresolved overloaded-symbol rows. Do not promote them from
this migration checkpoint.

The natural Tile rewrite changes `00457510` from an old exact row to scratch.
It now differs by 56 bytes. This is a source composition regression.

## Current status

All rows except `004550A0` and `0045A6D0` remain scratch. This preserves the
natural module without false exact claims.

The stale `map_context.h` and `map_tile_context.h` headers had no Map consumer.
The RMM terrain header now includes the complete canonical `map.h` owner. Both
stale headers were removed after this consumer audit.
