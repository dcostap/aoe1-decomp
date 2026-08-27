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
## Include-order probe

Focused VC5 probes use `config/flags/default.rsp`. These include orders pass:

- `rmm_base.h` then `rmm_terrain_info.h`
- `rmm_terrain_info.h` then `rmm_base.h`
- `map.h`, `world.h`, `rmm_base.h`, then `rmm_terrain_info.h`
- `rmm_terrain_info.h`, `rmm_base.h`, `world.h`, then `map.h`

The consumer probe constructs all three records after the canonical Map, World,
and random-map base declarations. All checks return zero.

Before the internal Terrain migration, these legacy combinations failed with
the following exact C2011 conflicts:

- `rmm_terrain_info.h` plus `rmm_dbct.h`: `RGE_Terrain_Info_Line` at
  `rmm_dbct.h:130`, `RGE_Terrain_Hot_Spots` at `rmm_dbct.h:144`, and
  `RGE_Terrain_Info` at `rmm_dbct.h:154`.
- `rmm_terrain_info.h` plus `rmm_cntr_context.h`: the same three records at
  `rmm_cntr_context.h:60`, `:74`, and `:81`.
- `rmm_terrain_info.h` plus the old `rmm_terr.h`: the same three records.

### Direct fanout gate

**PASS:** Include `rmm_terrain_info.h` with canonical `rmm_base.h`, `map.h`,
and `world.h` declarations.

**BLOCK:** Include it while DBCT or CNTR still defines the three records.
First replace those duplicate definitions in a separate integration change.
Do not add include-order guards that hide competing record owners.

## Internal owner migration

`rmm_terr.h` now includes `rmm_terrain_info.h` and no longer repeats the three
record definitions. Tile, base, Map, zone-map, and generator declarations did
not change. DBCT, CNTR, and all source files did not change.

The rebuilt `rmm_terr` object keeps all ten matching owners exact. The focused
comparison reports `MATCH`, `0.0000%`, equal boundaries, and matching owner
symbols for `004888E0`, `00488920`, `004889D0`, `004889F0`, `00488D50`,
`00488E40`, `00488E60`, `00488EA0`, `00488F90`, and `00489030`.

The accepted-drift `00488B90` remains unchanged at 295 differing bytes in a
433-byte rebuilt body versus 437 original bytes. It remains accepted drift.

Authoritative focused checks for the constructor, `check_borders`, and
`base_terrain_generate` each report `Result: MATCH`. The source module has no
exact regression from this internal include migration.
