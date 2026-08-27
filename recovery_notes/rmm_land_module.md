# rmm_land.cpp recovery

## Source order and status

The PDB source is `C:\\msdev\\work\\age1_x1\\rmm_land.cpp`. The source
contains the five owners in original order:

| VA | PDB lines | Original | Rebuilt | Status |
| --- | --- | ---: | ---: | --- |
| `00485200` | 25-29 | 59 | 59 | matching |
| `00485240` | 33-51 | 133 | 133 | scratch |
| `004852D0` | 57-140 | 417 | 353 | scratch |
| `00485480` | 146-208 | 159 | 160 | scratch |
| `00485520` | 213-353 | 1833 | 1860 | scratch |

Only `00485200` is registered as matching. The other four rows remain scratch.
No CNTR, DBCT, or TDBC fanout was run for this held Land chain.

## Canonical ownership and offset audit

The source includes `map.h` and `rmm_land.h`. The Land header includes the
canonical `rmm_base.h`. It does not redefine Map, Tile, stack, or base-module
records.

The inherited base has a virtual pointer at `+0x00`. Its named fields map as
follows:

| Offset | Field | Type |
| --- | --- | --- |
| `+0x0C` | `map` | `RGE_Map*` |
| `+0x10` | `map_row_offset` | `RGE_Tile**` |
| `+0x14` | `map_width` | `long` |
| `+0x18` | `map_height` | `long` |
| `+0x1C` | `schedule` | `float` |
| `+0x20` | `search_map` | `uchar*` |
| `+0x24` | `search_map_rows` | `uchar**` |
| `+0x28` | `stack_array` | `Map_Stack*` |
| `+0x2C` | `stack_offsets` | `Map_Stack**` |
| `+0x30` | `info` | `RGE_Land_Info` |

The Land line has size `0x34`. Each rewritten field access uses this named
layout:

| Offset | Field | Type |
| --- | --- | --- |
| `+0x00` | `land_size` | `long` |
| `+0x04` | `terrain_type` | `long` |
| `+0x08` | `x` | `long` |
| `+0x0C` | `y` | `long` |
| `+0x10` | `base_size` | `long` |
| `+0x14` | `area` | `long` |
| `+0x18` | `zone` | `uchar` |
| `+0x1C` | `clumpiness_factor` | `long` |
| `+0x20` | `wall_1_avoidance_line` | `long` |
| `+0x24` | `wall_2_avoidance_line` | `long` |
| `+0x28` | `wall_3_avoidance_line` | `long` |
| `+0x2C` | `wall_4_avoidance_line` | `long` |
| `+0x30` | `wall_fade` | `uchar` |

`RGE_Land_Info::land[99]` occupies `+0x0000..+0x141B` with stride `0x34`.
The remaining named fields are `land_num` at `+0x141C`, `base_terrain` at
`+0x1420`, wall lines at `+0x1424..+0x1430`, and `wall_fade` at `+0x1434`.
The complete record size is `0x1438`. The generator size is `0x1468`.

The canonical `RGE_Tile` places the packed `terrain_type` field at byte
`+0x05`. Its five-bit field is used by the typed `RGE_Tile&` writes in Phase B
and Phase C. The local `Map_Stack stack[99]` uses the canonical `0x18` stack
record. The local `land_size[99]` array is indexed by land id plus one.

The former decompiler accesses map to these named fields:

- `this + 0x0C` is `map`.
- `this + 0x14` and `this + 0x18` are `map_width` and `map_height`.
- `this + 0x20` and `this + 0x24` are `search_map` and `search_map_rows`.
- `this + 0x28` and `this + 0x2C` are represented by typed local stacks only
  when the base helpers access them.
- `this + 0x30` is `info`.
- A line base plus `0x00`, `0x04`, `0x08`, `0x0C`, `0x10`, `0x14`, `0x18`,
  `0x1C`, `0x20`, `0x24`, `0x28`, `0x2C`, or `0x30` uses the matching named
  Land-line field above.
- A tile base plus `0x05` is the canonical `terrain_type` bitfield.

Phase B uses the required `current_size < land.land_size` test. This maps the
former `plVar12[-7]` access to Land-line offset `+0x00`. The other former
Phase B offsets map to `terrain_type` at `+0x04`, `zone` at `+0x18`, and
`clumpiness_factor` at `+0x1C`.

## Natural source shape

`generate` keeps the full direct call order:

```text
clear_stack();
memset(search_map, info.land_num, map_height * map_width);
map->set_terrain(..., info.base_terrain, 1, 0);
base_land_generate();
map->clean_terrain(..., info.base_terrain);
return 1;
```

The source uses canonical Map and Tile members, named Land records, and typed
indexes. It has no wrapper, context include, union, adapter, raw cursor, or
synthetic function. The old terrain and stack helpers stay external.

## Fresh five-row validation

The candidate was rebuilt after the chain was rebased onto exact current main
`f102e4bb1`. The candidate used the pinned VC5 toolchain and
`config/flags/default.rsp`. The fresh report is
`build/candidate_tus/rmm_land_self_contained_f102e4bb1/report.json`.

| VA | Result | Diff | Owner | Relocations | Boundary escapes |
| --- | --- | ---: | --- | ---: | ---: |
| `00485200` | MATCH | 0 / 59 (`0.0000%`) | match | 0 | 0 |
| `00485240` | MISMATCH | 2 / 133 (`1.5038%`) | match | 0 | 0 |
| `004852D0` | MISMATCH | 404 / 417 (`96.8825%`) | match | 0 | 0 |
| `00485480` | MISMATCH | 142 / 159 (`88.7500%`) | match | 0 | 1 |
| `00485520` | MISMATCH | 1584 / 1833 (`85.1613%`) | match | 0 | 2 |

The direct target audit for the fresh object is:

| VA | Original direct targets | Rebuilt direct targets |
| --- | --- | --- |
| `00485200` | `00480790 RGE_Random_Map_Module::RGE_Random_Map_Module` | same |
| `00485240` | `00480E50 clear_stack`, `00459A90 set_terrain`, `00485520 base_land_generate`, `00456E90 clean_terrain` | same ordered set |
| `004852D0` | `0054B700 __ftol` | none |
| `00485480` | none | none |
| `00485520` | `00480CC0 init_stack x1`, `00459A90 set_terrain x1`, `00480D10 push_stack x8`, `00480DA0 pop_stack x3`, `00485480 chance x1`, `_debug_rand x5`, `004852D0 check_terrain_and_zone x1`, `00480CF0 deinit_stack x1` | same 21-site ordered set |

The exact owner check for `00485200` reports `Result: MATCH`, strict
positional diff `0 bytes (0.0000%)`, owner match, and zero target mismatch.
The candidate summary reports one exact match, four scratch mismatches, and zero
comparison errors.

This is a held, self-contained Land chain. It is not integrated.
