# zone_map.cpp source reunification

## Translation-unit context

- PDB source: `C:\\msdev\\work\\age1_x1\\zone_map.cpp`.
- The packet contains 22 normal owners in source and address order.
- The owner range is `00546720` through `005474D0`.
- The class owners are `RGE_Zone_Map` through `00547080`, then
  `RGE_Zone_Map_List` from `00547180` through `005474D0`.
- The reviewed declaration surface is `include/zone_map.h`.
- The queue record is shared through the existing
  `include/rge_zone_queue_context.h` declaration.

## Status

The module keeps 20 matching owners and two accepted-drift owners. The source
now owns all 22 normal owners in one PDB-ordered file.

`005467B0` (`RGE_Zone_Map::RGE_Zone_Map(int, RGE_Map*)`) stays accepted drift.
The constructor size, allocation calls, serialized read order, row setup, and
field offsets match. The remaining difference is a prologue register choice
that cascades through the body. VC5 keeps the second constructor argument in
EDI, while the shipped body first loads it into EAX and reloads `this->map`.

`00546A90` (`RGE_Zone_Map::do_zone_map`) stays accepted drift. The nested flood
fill preserves the shipped loops, bounds, terrain lookup, passability test,
zone writes, and area calls. VC5 emits `test edx, edx` where the executable
uses an equivalent `cmp edx, esi`, and hoists the y-zero store before the
conditional jump. The difference is localized to equivalent instruction
selection and scheduling.

All other normal owners are matching. Their exact claims use the grouped
`zone_map` translation unit and the module source. No status changed during
source reunification.

## Ownership and deletion

The old wrapper, context-selection header, complete-TU probe, and all 22
VA-named owner fragments are removed. The source has no `.cpp` includes, owner
fallback declarations, or recovery context macros. The module header owns the
complete class and layout declarations.
