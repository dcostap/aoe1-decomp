# zone_map.cpp source reunification

## Translation-unit context

- PDB source: `C:\\msdev\\work\\age1_x1\\zone_map.cpp`.
- The packet contains 22 normal owners in source and address order.
- The owner range is `00546720` through `005474D0`.
- The class owners are `RGE_Zone_Map` through `00547080`, then
  `RGE_Zone_Map_List` from `00547180` through `005474D0`.
- The reviewed declaration surface is `include/zone_map.h`.
- `include/zone_map.h` owns the zone queue record used by this module.

## Status

The module has 20 matching owners and two accepted-drift owners.
The source owns all 22 normal functions in one PDB-ordered file.

The reopened behavior reviews are in `functions/0054/005467B0.md` and
`functions/0054/00546A90.md`. The worker proposes renewed accepted drift for
`00546A90` after checking its loops, bounds, calls, memory writes, and zero
threshold. The only byte difference is `cmp edx, esi` versus `test edx, edx`.
The worker does not propose renewed acceptance for `005467B0` yet. Its normal
constructor behavior matches, but prologue and cleanup scheduling leave an
unresolved fault-order question for invalid stack or unmapped-object cases.

`005468C0` is matching. The earlier two-byte allocation-product mismatch no
longer describes the current source or registry status.

All other normal owners are matching. Their exact claims use the grouped
`zone_map` translation unit and the module source.

## Ownership and deletion

The old wrapper, context-selection header, complete-TU probe, and all 22
VA-named owner fragments are removed. The source has no `.cpp` includes, owner
fallback declarations, or recovery context macros. The module header owns the
complete class and layout declarations.
