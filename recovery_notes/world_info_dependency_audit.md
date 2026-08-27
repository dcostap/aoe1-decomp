# World information dependency audit

Status: evidence only. No production header or source file changed.

## PDB evidence

The oracle PDB is `orig/age1_x1.pdb`. The DIA query found one UDT for each
record. The UDT records have no base class, no source file, and no type-definition
line. `getSrcLineOnTypeDefn` returned `S_FALSE` for all three records.

DIA reported `udtKind = UdtStruct`. The generated type dump calls them classes,
but the decorated World functions use `AAURGE_Player_Info@@`. This is the
struct reference form. Use `struct` for the shared declarations.

DIA `findChildren(SymTagFunction)` returned no children for these UDTs. The PDB
also has no decorated `RGE_Player_Info` or `RGE_Map_Gen_Info` constructor,
destructor, or member-method symbol. These are plain records. They need no
method declaration or out-of-line function owner.

The PDB record sizes are:

| Record | Size | DIA type kind |
| --- | ---: | --- |
| `RGE_Info_Line` | `0x14` (20) | `UdtStruct` |
| `RGE_Map_Gen_Info` | `0x520` (1312) | `UdtStruct` |
| `RGE_Player_Info` | `0x2AC` (684) | `UdtStruct` |

`RGE_Info_Line` is required to define `RGE_Map_Gen_Info`. Its exact fields are:

| Offset | Type | Name |
| ---: | --- | --- |
| `0x00` | `float` | `clump_num` |
| `0x04` | `short` | `percent_of_tiles_covered` |
| `0x06` | `short` | `percent_updown` |
| `0x08` | `short` | `min_elevation` |
| `0x0A` | `short` | `max_elevation` |
| `0x0C` | `short` | `terrain_type` |
| `0x0E` | `short` | `terrain_base` |
| `0x10` | `char` | `obj_id` |

The final three bytes are natural tail alignment. The PDB field record has the
same `0x14` size.

`RGE_Map_Gen_Info` has these exact fields:

| Offset | Type | Name |
| ---: | --- | --- |
| `0x000` | `short` | `base_terrain` |
| `0x004` | `RGE_Info_Line` | `land` |
| `0x018` | `RGE_Info_Line[20]` | `elevation` |
| `0x1A8` | `short` | `elevation_num` |
| `0x1AC` | `RGE_Info_Line[20]` | `terrain` |
| `0x33C` | `short` | `terrain_num` |
| `0x340` | `RGE_Info_Line[20]` | `objects` |
| `0x4D0` | `short` | `objects_num` |
| `0x4D2` | `short` | `player_num` |
| `0x4D4` | `short[9]` | `player_x` |
| `0x4E6` | `short[9]` | `player_y` |
| `0x4F8` | `short[9]` | `player_connect` |
| `0x50A` | `short[9]` | `player_base_land` |
| `0x51C` | `short` | `space_between_islands_or_edge` |

`base_terrain` is followed by natural two-byte alignment. `land` is at `+4`.
The three 20-entry arrays use a `0x14` stride.

`RGE_Player_Info` has these exact fields:

| Offset | Type | Name |
| ---: | --- | --- |
| `0x000` | `char[9][65]` | `name` |
| `0x249` | `char[9]` | `type` |
| `0x252` | `char[9]` | `tribe` |
| `0x25C` | `short[9]` | `color` |
| `0x270` | `long[9]` | `player_id_hash` |
| `0x294` | `short` | `player_num` |
| `0x298` | `char*` | `scenario` |
| `0x29C` | `RGE_Map_Gen_Info*` | `map_info` |
| `0x2A0` | `short` | `map_type` |
| `0x2A2` | `short` | `map_width` |
| `0x2A4` | `short` | `map_height` |
| `0x2A6` | `short` | `ai_info` |
| `0x2A8` | `unsigned char` | `campaign` |

Natural alignment creates gaps at `0x25B`, `0x26E`, `0x296`, and the final
three bytes. No explicit pad fields are needed for this order on the pinned
32-bit VC5 target.

## Binary and PDB source-module use

The UDT records do not identify one source module. The PDB source map identifies
the owning function modules below. This is use evidence, not UDT ownership:

| PDB module | Functions or local records | Use |
| --- | --- | --- |
| `World.cpp` | `005424F0`, `005425B0`, `00542750`, `00542BF0`, `00542D10`, `00543E00`, `00544090`, `00544300`, `005445C0`, `00544880`, `00544B90`, `00544E70`, `005451A0`, `005454D0`, `00545800` | `RGE_Player_Info` parameters and fields; `00542BF0` reads `map_info->base_terrain` and `map_width/map_height` |
| `tworld.cpp` | `0052E990`, `0052EF30`, `00530370` | `RGE_Player_Info` parameters and fields |
| `tribegam.cpp` | `00526E60` | Local `RGE_Player_Info` and `RGE_Map_Gen_Info` records |
| `scr_sed.cpp` | `004AD340` | Local `RGE_Player_Info` and `RGE_Map_Gen_Info` records |
| `map.cpp` | `004578A0` | `RGE_Player_Info*` map-generation parameter |
| `tmap.cpp` | `0050F7C0`, `0050F7F0` | `RGE_Player_Info*` map-generation parameters |

The PDB source map gives these line bands:

- `tribegam.cpp:3234-3697` for `00526E60`;
- `scr_sed.cpp:3308-3408` for `004AD340`;
- `tworld.cpp:355-380`, `525-1128`, and `1132-1147` for the three TRIBE World functions;
- `World.cpp:1163-1589`, `2309-2465`, and `2489-3455` for the World functions; and
- `map.cpp:1450`, `tmap.cpp:148-160` for the map functions.

The original `World.cpp` assembly at `00542BF0` proves the field offsets. It
loads `map_width` from `info + 0x2A2`, `map_height` from `info + 0x2A4`, and
`map_info` from `info + 0x29C`. It then reads `base_terrain` at offset zero of
that pointed record.

The original `tribegam.cpp` assembly at `00526E60` places the local records in
PDB order. `RGE_Player_Info` occupies `0x2AC` bytes from local offset
`-0x9EC` to `-0x740`. `RGE_Map_Gen_Info` occupies `0x520` bytes from
`-0x524` to `-0x004`. The original `scr_sed.cpp` assembly at `004AD340`
places the records adjacent: Player Info is `-0x7D0` to `-0x524`, and Map Gen
Info is `-0x524` to `-0x004`. It also emits `map_info.land` at local offset
`+4`, not at offset zero.

## Conflicting current copies

These copies are compiler context or module-local scaffolds. They are not
canonical owners.

| Path | Current copy | Conflict |
| --- | --- | --- |
| `include/world_context.h:145` | `RGE_Map_Gen_Info { short base_terrain; }` | Size is `2`, not `0x520`; all later fields are absent. |
| `include/world_context.h:147` | Full `RGE_Player_Info` field order | Layout is usable, but it is in a candidate context header. |
| `include/world_scenario_context.h:153` | One-field Map Gen Info | Wrong size and missing fields. |
| `include/world_scenario_context.h:157` | Full Player Info with unions | `player_num_minus1` and `victory` are unsupported aliases. |
| `src/world_phase2_context.h:157` | One-field Map Gen Info | Wrong size and missing fields. |
| `src/world_phase2_context.h:161` | Full Player Info with unions | Unsupported aliases for `player_num` and `map_type`. |
| `include/tworld_prefix_context.h:40` | Full Player Info | `map_info` is `void*`, not `RGE_Map_Gen_Info*`. |
| `include/scr_sed.h:706` | `RGE_Info_Line` with `short clump_num` | PDB field is `float`; remaining fields are missing. |
| `include/scr_sed.h:711` | Map Gen Info with `land` at offset zero | PDB has `base_terrain` at zero and `land` at `+4`. |
| `include/scr_sed.h:716` | Full Player Info | Module-local copy; its preceding class forward declaration also conflicts with the PDB struct kind. |
| `src/tribegam.cpp:3138` | Raw `RGE_Info_Line` bytes | Field ownership and `clump_num` type are lost. |
| `src/tribegam.cpp:3142` | Map Gen Info with `land` at offset zero | Wrong field offsets. |
| `src/tribegam.cpp:3147` | `class RGE_Player_Info` | PDB UDT kind and decorated references use `struct`. |
| `include/t_c_obj_context.h:151` | Gap through `+0x270` and one pointer | Partial record; size and fields do not match. |

`include/game_types.h:193`, `:204`, and `:231`, plus several matching and
candidate files, use `class RGE_Info_Line`, `class RGE_Map_Gen_Info`, or
`class RGE_Player_Info` forward declarations. These are only forward
references, but a later owner definition must use the same `struct` tag kind.

## Canonical owner requirements

Publish one narrow shared owner header. A name such as
`include/world_info.h` is suitable, but the PDB does not prove a historical
header name. The header must own these three records:

1. `struct RGE_Info_Line` with its seven scalar fields and `obj_id`;
2. `struct RGE_Map_Gen_Info` with the complete arrays and player fields; and
3. `struct RGE_Player_Info` with the complete scenario and map fields.

Use natural VC5 layout. Do not use raw carriers, `void* map_info`, alias unions,
or context-only definitions. Do not add constructors or methods. Add old-style
size checks for `0x14`, `0x520`, and `0x2AC` if the owner-header policy needs
them.

The World, TRIBE World, TRIBE Game, and scenario-editor source modules must
consume this owner. Map and TRIBE Map need only the forward declaration when
they pass the pointer without field access. Replace the current duplicate
bodies and change class-key forward declarations to `struct` before the owner
header is included.

The source module with the two local records is `tribegam.cpp`, but that is not
exclusive UDT ownership. The PDB evidence supports a shared record header and
no standalone implementation file.
