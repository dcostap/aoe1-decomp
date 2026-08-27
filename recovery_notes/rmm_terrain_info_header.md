# RMM Terrain Info record header

## Recommendation

Use `include/rmm_terrain_info.h` as the owner-only candidate for the three
runtime Terrain Info records. The header has no includes and no dependency on
Tile, the random-map base, a generator, globals, padding, or context aliases.

Do not include `include/rmm_terr.h` from DBCT or CNTR. That header carries
module-local Tile, base, Map, and generator declarations. It causes type
redefinition errors in those consumer contexts.

This note does not change `rmm_terr.cpp`, DBCT, CNTR, or any consumer.

## Proven layout

CodeView type dumps prove the following records:

| Record | Fields | Size |
| --- | --- | ---: |
| `RGE_Terrain_Info_Line` | eight `long` fields at `+0x00` through `+0x1C` | `0x20` |
| `RGE_Terrain_Hot_Spots` | `x`, `y`, `radius`, `fade` at `+0x00` through `+0x0C` | `0x10` |
| `RGE_Terrain_Info` | `terrain[99]` at `+0x00`, `terrain_num` at `+0x0C60`, `hot_spots[99]` at `+0x0C64`, and `hot_spot_num` at `+0x1294` | `0x1298` |

Evidence:

- `inventory/types/dumps/RGE_Terrain_Info_Line.txt`
- `inventory/types/dumps/RGE_Terrain_Hot_Spots.txt`
- `inventory/types/dumps/RGE_Terrain_Info.txt`

The CodeView records give complete field names, order, offsets, and sizes.
The candidate header repeats only those fields. It adds a size check for each
record.

## Owner and consumer evidence

The PDB assigns the Terrain generator body sequence to
`C:\\msdev\\work\\age1_x1\\rmm_terr.cpp`. `src/rmm_terr.cpp` defines the
constructor, `generate`, and all nine helper methods in that order.

The generator CodeView record proves `info` at `+0x30`, `map_zone` at `+0x12C8`,
and a total size of `0x12CC`. The constructor at `004888E0` copies `0x4A6`
dwords from the input record into `this + 0x30`.

The two consumers pass complete records:

- CNTR calls the Terrain generator constructor at `00482864`.
- DBCT calls it at `00483475` with its `terrain_info` field at `+0x1474`.

CNTR and DBCT each keep a duplicate Terrain Info definition today. Their
record fields match the CodeView layout, but their full context headers cannot
include `rmm_terr.h` directly.

## Validation

`build/probes/rmm_terrain_info_layout.cpp` checks every named field offset and
all three record sizes. It compiled with the pinned VC5 compiler and
`config/flags/default.rsp` with return code 0.

The probe is a build artifact. It does not claim a source-owner change.

## Integration boundary

This candidate is ready for record-level fanout after review. A later change
may replace the duplicate record definitions in DBCT and CNTR with this header.
That change needs focused builds for `rmm_terr`, DBCT, and CNTR. It must not
move the Terrain generator or random-map base declarations into this header.
