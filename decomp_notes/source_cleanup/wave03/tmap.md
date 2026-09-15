# Cleanup wave 03: `src/tmap.cpp`

## Delivery

- Module: `src/tmap.cpp`.
- Header owner: `include/tmap.h`; read only. A declaration-name request is
  recorded below; no header edit is included in this task.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final code commit: `d8b5e8cc95981016674b785e13fa8c2ae308190d`.
- Changed files: `src/tmap.cpp` and this report.
- Source order, declarations, types, storage, calls, and executable statements remain unchanged.

## Correction history

- Owner review correction: recorded the complete `include/tmap.h`
  declaration-name request as declaration-only and ABI-neutral. Joined the
  readable random-map constructor and terrain-setting calls. No tokens, casts,
  call targets, argument order, or executable statements changed.

## Original-name inspection

I inspected all 29 normal source procedures in the module. I also inspected the
compiler-generated scalar-deleting destructor at `0050F740`; it has no source
body and was not changed.

Primary evidence:

- PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
- Extracted module PDB view: `build/tmap-evidence/scoped_symbols_tmap.json`.
- Parameter, local, and register view: `build/tmap-evidence/pdb-details.txt`.
- Registry-selected packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/` and `.../0051/` for every listed VA.
- Packet metadata review: `build/tmap-evidence/packet-metadata.txt`.
- Source registry: `config/functions/src/tmap.cpp.json`.

The PDB records `this` in `ecx` for every procedure. The restored names below
come from procedure-scoped PDB records. The separate new-names section lists
cleanup names that are not original names.

| VA | Procedure | Restored parameters and locals |
| --- | --- | --- |
| `0050F410` | first constructor | `infile`, `sound`, `setup` |
| `0050F760` | file constructor | `border_tbl`, `overlay_tbl`, `terrain_tbl`, `map_tbl`, `TileWid`, `TileHgt`, `ElevHgt`, `sound` |
| `0050F7A0` | destructor | no stack names |
| `0050F7B0` | `save` | `outfile` |
| `0050F7C0` | wrapper `map_generate` | `owner`, `gworld`, `player_info`, `zone_terrain` |
| `0050F7F0` | empty `map_generate` | `player_info` |
| `0050F800` | `data_load_random_map` | `infile` |
| `0050F860` | `load_random_map` | `rmm_map_file`, `rmm_land_file`, `rmm_terr_file`, `rmm_obj_file` |
| `0050F8D0` | `check_tile_for_forest_change` | `x`, `y`, `world`, `success`, `x0`, `x1`, `y1`; `y0` has no PDB record |
| `0050FA90` | `change_terrain` | `map_col`, `map_row`, `new_terrain`, `world`, `col1`, `col2`, `player`, `row2`, `save_border_shape` |
| `0050FC40` | `do_terrain_brush` | `x`, `y`, `brush_size`, `terrain_id`, `x1`, `y2` |
| `0050FD40` | `do_terrain_brush_stroke` | `x1`, `y1`, `x2`, `y2`, `brush_size`, `terrain_id` |
| `0050FDD0` | `do_elevation_brush_stroke` | `x1`, `y1`, `x2`, `y2`, `brush_size`, `elevation_height` |
| `0050FE90` | `setup_cliff_type` | `r`, `d`, `l`, `u`, `id`, `facet`, `id2`, `facet2`, `offset_x`, `offset_y` |
| `0050FF20` | `find_cliff` | `x`, `y` |
| `00510020` | `get_cliff_info` | hidden return slot and `cliff` |
| `005100D0` | `check_cliff_valid` | `info` |
| `00510110` | `make_new_cliff` | `x`, `y`, `info`, `id`, `world_y`, `world_x`, `facet`, `new_cliff`, `i` |
| `005102A0` | `remove_cliff_edge` | `x`, `y`, `direction`, `cliff_info` |
| `00510410` | `reverse_cliff_direction` | `direction` |
| `00510430` | `add_cliff_edge` | `x`, `y`, `direction`, `facing`, `save_direction`, `cliff_info`, `ret_num`, `possible_facing1`, `possible_facing2`, `possible_direction1`, `possible_direction2` |
| `00510960` | `delete_cliff` | `x`, `y`, `cliff_info`, `i` |
| `00510A50` | `do_cliff_brush` | `x`, `y`, `cliff_id`, `delete_cliff_flag`, `dx`, `facing` |
| `00510C10` | `do_cliff_brush_stroke` | `x1`, `y1`, `x2`, `y2`, `cliff_id`, `delete_cliff` |
| `00510C90` | `water` | `terrain` |
| `00510CB0` | `clean_borders` | `x1`, `y1`, `x2`, `y2`, `terrain_id`, `border`, `x` |
| `00511000` | `do_terrain_brush_check` | `x`, `y` |
| `005110E0` | `tribe_clean_elevation` | `x1`, `y1`, `x2`, `y2` |
| `005111A0` | `tribe_clean_terrain` | `x1`, `y1`, `x2`, `y2`, `check_terrain`, `replacement_terrain`, `place2`, `place3`, `place4`, `place5`, `place6`, `place7`, `place8`, `pass_index`, `change_flag`, `offset1`, `offset2`, `offset3`, `offset5`, `offset7`, `til` |

The mixed spellings are intentional. This includes `TileWid`, `TileHgt`,
`ElevHgt`, `r`, `d`, `l`, `u`, `place2` through `place8`, and `til`.

## `include/tmap.h` declaration-name request

Owner 16 should add the following parameter names to the existing declarations
in `include/tmap.h`. This is a declaration-only request. Parameter names do
not change the function type, calling convention, vtable, object layout, or
ABI. No header edit is included in this cleanup commit.

```cpp
TRIBE_Map(int infile, RGE_Sound** sound, unsigned char setup);
TRIBE_Map(char* border_tbl, char* overlay_tbl, char* terrain_tbl,
          char* map_tbl, short TileWid, short TileHgt, short ElevHgt,
          RGE_Sound** sound);
virtual ~TRIBE_Map();
virtual void data_load_random_map(int infile);
virtual void load_random_map(char* rmm_map_file, char* rmm_land_file,
                             char* rmm_terr_file, char* rmm_obj_file);
virtual unsigned char do_terrain_brush(long x, long y, long brush_size,
                                       unsigned char terrain_id);
virtual unsigned char do_terrain_brush_stroke(
    long x1, long y1, long x2, long y2, long brush_size,
    unsigned char terrain_id);
virtual unsigned char do_elevation_brush_stroke(
    long x1, long y1, long x2, long y2, long brush_size,
    unsigned char elevation_height);
virtual unsigned char do_cliff_brush(long x, long y, unsigned char cliff_id,
                                     unsigned char delete_cliff_flag);
virtual unsigned char do_cliff_brush_stroke(
    long x1, long y1, long x2, long y2, unsigned char cliff_id,
    unsigned char delete_cliff);
virtual void map_generate(RGE_Player* owner, RGE_Game_World* gworld,
                          RGE_Player_Info* player_info,
                          unsigned char* zone_terrain);
void map_generate(RGE_Player_Info* player_info);
virtual void save(int outfile);
virtual void delete_cliff(long x, long y);

void check_tile_for_forest_change(short x, short y, RGE_Game_World* world);
void change_terrain(short map_col, short map_row,
                    unsigned char new_terrain, RGE_Game_World* world);
void setup_cliff_type(long r, long d, long l, long u, long id, long facet,
                      long id2, long facet2, float offset_x, float offset_y);
RGE_Static_Object* find_cliff(long x, long y);
TRIBE_Cliff_Info get_cliff_info(RGE_Static_Object* cliff);
unsigned char check_cliff_valid(TRIBE_Cliff_Info info);
RGE_Static_Object* make_new_cliff(long x, long y, TRIBE_Cliff_Info info);
void remove_cliff_edge(long x, long y, long direction);
long reverse_cliff_direction(long direction);
long add_cliff_edge(long x, long y, long direction, long facing,
                    long save_direction);
unsigned char water(unsigned char terrain);
void clean_borders(long x1, long y1, long x2, long y2,
                   unsigned char terrain_id);
unsigned char do_terrain_brush_check(long x, long y);
void tribe_clean_elevation(long x1, long y1, long x2, long y2);
void tribe_clean_terrain(long x1, long y1, long x2, long y2,
                         unsigned char check_terrain,
                         unsigned char replacement_terrain);
```

## New names and unresolved mappings

- `info_index`, `cliff_index`, and `master_obj_id` are new cleanup names.
  Their roles come from the surrounding expressions, not PDB names.
- Existing descriptive names remain where PDB records do not prove a mapping.
  This includes loop cursors, object-list locals, `y0`, `rad`, `end_x`,
  `start_y`, `current_player`, `old_border`, `count`, `valid`, `result`,
  `cliff_x`, `cliff_y`, `old_x`, `delta_y`, `outer`, `inner`, `max_x`,
  `max_y`, `fix`, `west`, `srow`, and `scol`.
- Reused PDB stack homes were not forced into unrelated declarations. The
  `x1` and `y2` names in `do_terrain_brush` and the bound names in
  `change_terrain` were mapped only where their value flow supports the role.
- No function has an unresolved parameter type. The only unresolved mappings
  are locals without a procedure-scoped PDB symbol or optimized stack-slot
  aliases.

## Constants, resources, and comments

- No constants, enums, resource IDs, or resource macros were added or changed.
- No resource lookup exists in this module. No resource extraction was needed.
- I read the pinned VC5 `float.h` and `stdlib.h` before reviewing literal
  changes. No SDK or CRT constant replacement was proposed.
- I corrected one existing comment in `map_generate`. The original packet at
  `0050F7C0` writes the player to `+0x8DD4` and the world to `+0x8DD8` before
  the overload call. The comment now states those proven offsets.
- No other comments were added.

## Risk-sensitive review

The source changes restore PDB parameter and local names and apply 1TBS brace
formatting. They do not change an expression, type, scope, declaration order,
call target, literal, layout, storage duration, or symbol name. The corrected
comment is based on the original packet and does not change behavior.

The source uses only the existing `TRIBE_Map` and shared declarations. The
header request above is declaration-only and ABI-neutral. No header edit,
registry change, or resource mapping is included.

## Unresolved questions

- The PDB does not preserve names for several optimized locals. I left those
  names descriptive instead of forcing reused stack-slot mappings.
- `setup_cliff_type` has no PDB local records. `info_index` and `cliff_index`
  are new names and should not be treated as recovered source names.
- The existing `TRIBE_Map` header still owns unnamed declaration parameters.
  Owner 16 should apply the declaration-name request above in a separate
  header-owned cleanup. The request does not change ABI.

## Validation status

Compilation, matching checks, audits, builds, and tests were not run, as
required for this cleanup phase.
