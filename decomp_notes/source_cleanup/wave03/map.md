# Source cleanup report: `map.cpp`

## Delivery

- Module: `src/map.cpp`
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source commits: `312a3a1d3c51dfda6485c03df12777a95dbafbd6`, `e64f320a6e9a02878db26feb07099348cdbc3927`, `823efaa9326ff318b22e6a024053ad2cdcaa95cd`, `e203c682ef21333de6d86b2283262d63fbb5c596`, `673598b4d2b677635ff2c7c003ba3dbc830ecf76`, `6a63d459c10a9cff2dcfad9f9161e2c9812602a9`
- Final source commit: `6a63d459c10a9cff2dcfad9f9161e2c9812602a9`
- Initial report commit: `99f0fc6f4131bfc5028fb51cc5cdad3503980b59`
- Report correction commit before this update: `a96a6b75532bfc56fda16ea39269684876e87b55`
- Final report commit: this report correction commit.
- Branch: `cleanup/staging-20260915-137`
- Changed files: `src/map.cpp`; this report.

The report covers all 64 assigned registry functions.
The vector-deleting destructor at `00455080` is compiler-generated.
It is not an assigned normal function.

The name-cleanup source commits change names only.
The formatting source commits change whitespace only.
The latest correction restores omitted local declarations and alias reads.
It also applies two PDB-backed local names.
No function boundary, ABI symbol, or member layout changed.
`include/map.h` was read and was not changed.

## Correction history

- `312a3a1d3c51dfda6485c03df12777a95dbafbd6`: applied the PDB-guided source name cleanup.
- `e64f320a6e9a02878db26feb07099348cdbc3927`: corrected a local declaration layout without changing behavior.
- `99f0fc6f4131bfc5028fb51cc5cdad3503980b59`: recorded the initial report.
- `e36684052cf94fa7185151aad858092386cf9753`: recorded the initial report metadata correction.
- `6cca60ccb37be9e8a3f495b1fc00d73718f64004`: recorded the final name-cleanup evidence before formatting.
- `823efaa9326ff318b22e6a024053ad2cdcaa95cd`: applied the first 1TBS format and corrected indentation.
- `e203c682ef21333de6d86b2283262d63fbb5c596`: restored `Type* name`, `Type& name`, and `(Type*)` style and rewrapped long lines.
- `673598b4d2b677635ff2c7c003ba3dbc830ecf76`: joined the short `clean_terrain` call on one line.
- `6a63d459c10a9cff2dcfad9f9161e2c9812602a9`: restored the five reviewed map source items listed below.

The formatting commits change whitespace only.
They use the module's `Type* name`, `Type& name`, and `(Type*)` presentation.
Short signatures and calls stay on one line.
Long `fscanf` lists, `debug_rand` expressions, and declarations use readable wraps.
The formatting does not add or remove braces.
It does not change scopes or non-whitespace tokens.

## Reviewer corrections

Earlier claims that the cleanup was nonstructural and complete were inaccurate.
The corrections below restore source evidence without changing function boundaries,
ABI symbols, member layout, or behavior.

- `scenario_load` now has `int iVar3 = infile;` before its local map values.
  All five `rge_read` calls use `iVar3`, as in baseline line 523 and the
  `00455FF0_scenario_load` packet.
- `get_border_type` now has ten `unsigned char` declarations.
  Their type positions are seven bytes, three ints, and three bytes.
  The final restored declaration is `ter_top_rgt_unused`; the active
  `ter_top_rgt` name remains the cleaned east-neighbor name.
  This restores the baseline declaration order at lines 2542-2554.
- The terrain loader uses one format-string literal:
  `"%hd %s %s %d %hd %hd %hd %hd %hd %hd %hd %f %f %hd %hd %hd %hd %hd %hd %hd %hd"`.
  It does not use adjacent string literals.
- `place_terrain_object` uses `obj_owner` for its parameter and all local
  reads. `inventory/pdb/scoped_symbols.json` records `obj_owner` at `00458C90`
  with stack offset `+0x4`, lines 172868-172886.
- `get_terrain` uses `unsigned char type` for the terrain byte local.
  Packet `00459400_get_terrain.txt` shows the byte store at `0045941F` to
  `[esp+0c]`, which is the local PDB maps to `type`.

## Evidence

The name evidence comes from `inventory/pdb/scoped_symbols.json`.
The PDB source path is `C:\msdev\work\age1_x1\map.cpp`.
Every assigned function has a PDB `this` record in `ecx`.
No assigned function has another PDB register-symbol record.

The original assembly, line records, and Ghidra stack records were inspected in these packets:

- `inventory/functions/0045/00455000_RGE_Map.txt`
- `inventory/functions/0045/004550A0_RGE_Map.txt`
- `inventory/functions/0045/00455430_RGE_Map.txt`
- `inventory/functions/0045/00455570_init_tile_sizes.txt`
- `inventory/functions/0045/004557C0_data_load_random_map.txt`
- `inventory/functions/0045/00455820_load_random_map.txt`
- `inventory/functions/0045/00455890_set_map_visible.txt`
- `inventory/functions/0045/004558A0_set_map_fog.txt`
- `inventory/functions/0045/004558B0_clear_map.txt`
- `inventory/functions/0045/00455910_new_map.txt`
- `inventory/functions/0045/00455C20_clear_map.txt`
- `inventory/functions/0045/00455CB0_request_redraw.txt`
- `inventory/functions/0045/00455D60_clear_map_view_info.txt`
- `inventory/functions/0045/00455DB0_coordinate_map.txt`
- `inventory/functions/0045/00455DD0_set_map_screen_pos.txt`
- `inventory/functions/0045/00455F10_scenario_save.txt`
- `inventory/functions/0045/00455FF0_scenario_load.txt`
- `inventory/functions/0045/00456140_give_up_map_offsets.txt`
- `inventory/functions/0045/00456150_get_map_width.txt`
- `inventory/functions/0045/00456160_get_map_height.txt`
- `inventory/functions/0045/00456170_postclean_elevation.txt`
- `inventory/functions/0045/004564E0_preclean_elevation.txt`
- `inventory/functions/0045/004568C0_clean_elevation.txt`
- `inventory/functions/0045/00456E90_clean_terrain.txt`
- `inventory/functions/0045/00457300_clean_borders.txt`
- `inventory/functions/0045/00457310_clean_border_tile.txt`
- `inventory/functions/0045/00457320_do_terrain_brush.txt`
- `inventory/functions/0045/004573C0_do_terrain_brush_stroke.txt`
- `inventory/functions/0045/00457510_do_elevation_brush.txt`
- `inventory/functions/0045/004575C0_do_elevation_brush_stroke.txt`
- `inventory/functions/0045/00457750_do_cliff_brush.txt`
- `inventory/functions/0045/00457760_do_cliff_brush_stroke.txt`
- `inventory/functions/0045/004578A0_map_generate.txt`
- `inventory/functions/0045/004578B0_map_generate2.txt`
- `inventory/functions/0045/004579C0_load_map.txt`
- `inventory/functions/0045/00457C50_save_map.txt`
- `inventory/functions/0045/00457DF0_save.txt`
- `inventory/functions/0045/00457EB0_load_terrain_types.txt`
- `inventory/functions/0045/00457F80_load_terrain_types.txt`
- `inventory/functions/0045/00458280_load_border_types.txt`
- `inventory/functions/0045/00458350_load_border_types.txt`
- `inventory/functions/0045/00458600_load_terrain_obj_types.txt`
- `inventory/functions/0045/00458760_delete_objects_on_tile.txt`
- `inventory/functions/0045/004587D0_delete_all_objects_on_tile.txt`
- `inventory/functions/0045/00458820_create_terrain_object.txt`
- `inventory/functions/0045/00458B40_clear_terrain_object.txt`
- `inventory/functions/0045/00458C90_place_terrain_object.txt`
- `inventory/functions/0045/00458FD0_create_terrain_objects.txt`
- `inventory/functions/0045/00459020_set_tile_size.txt`
- `inventory/functions/0045/00459060_tile_map_coords.txt`
- `inventory/functions/0045/004593A0_check_map_coords.txt`
- `inventory/functions/0045/004593D0_get_elev.txt`
- `inventory/functions/0045/00459400_get_terrain.txt`
- `inventory/functions/0045/00459460_get_border.txt`
- `inventory/functions/0045/004594B0_set_terrain_passablity.txt`
- `inventory/functions/0045/004595E0_set_elev.txt`
- `inventory/functions/0045/00459900_set_terrain.txt`
- `inventory/functions/0045/00459A00_set_terrain_absolute.txt`
- `inventory/functions/0045/00459A90_set_terrain.txt`
- `inventory/functions/0045/00459D20_get_tile_type.txt`
- `inventory/functions/0045/0045A030_get_border_type.txt`
- `inventory/functions/0045/0045A490_check_for_border.txt`
- `inventory/functions/0045/0045A500_update.txt`
- `inventory/functions/0045/0045A6D0_get_point.txt`

The packets confirm each assigned boundary, call target, and line range.
The original executable remains the behavior oracle.
Temporary evidence files were kept under `build/`.
They include the PDB record and packet indexes used during review.

## PDB stack and register inventory

The table lists every PDB stack symbol for each assigned function.
For each function, the signature names come first.
The remaining names are local symbols or reused stack symbols.
A reused PDB slot was not forced into a new declaration.
The register column records the PDB `this` symbol.

| VA | Function | PDB stack names | Register |
| --- | --- | --- | --- |
| `00455000` | constructor | `infile, sounds, setup` | `this:ecx` |
| `004550A0` | constructor | `border_tbl, terrain_tbl, map_tbl, TileWid, TileHgt, ElevHgt, sounds` | `this:ecx` |
| `00455430` | destructor | none | `this:ecx` |
| `00455570` | `init_tile_sizes` | none | `this:ecx` |
| `004557C0` | `data_load_random_map` | `infile` | `this:ecx` |
| `00455820` | `load_random_map` | `rmm_map_file, rmm_land_file, rmm_terr_file, rmm_obj_file` | `this:ecx` |
| `00455890` | `set_map_visible` | `flag` | `this:ecx` |
| `004558A0` | `set_map_fog` | `flag` | `this:ecx` |
| `004558B0` | `clear_map` | `player, world, new_terrain, width, height` | `this:ecx` |
| `00455910` | `new_map` | `width, height` | `this:ecx` |
| `00455C20` | `clear_map` | `terrain, elev` | `this:ecx` |
| `00455CB0` | `request_redraw` | `x1, y1, x2, y2, attribute` | `this:ecx` |
| `00455D60` | `clear_map_view_info` | none | `this:ecx` |
| `00455DB0` | `coordinate_map` | none | `this:ecx` |
| `00455DD0` | `set_map_screen_pos` | `x1, y1, x2, y2` | `this:ecx` |
| `00455F10` | `scenario_save` | `outfile, height_info, y, overlay_info, terrain_info` | `this:ecx` |
| `00455FF0` | `scenario_load` | `infile, zone_terrain, height_info, y, x, h, w, overlay_info, terrain_info` | `this:ecx` |
| `00456140` | `give_up_map_offsets` | none | `this:ecx` |
| `00456150` | `get_map_width` | none | `this:ecx` |
| `00456160` | `get_map_height` | none | `this:ecx` |
| `00456170` | `postclean_elevation` | `x1, y1, x2, y2, elevation_height, index2, index1, was_bad, offset3, offset1, offset2` | `this:ecx` |
| `004564E0` | `preclean_elevation` | `x1, y1, x2, y2, elevation_height, place3, index2, place5, index1, place4, change_flag, place1, offset7, offset5, offset3, place7, offset1, place6, offset2, place8` | `this:ecx` |
| `004568C0` | `clean_elevation` | `x1, y1, x2, y2, elevation_height, place3, place2, index2, place5, index1, place4, change_flag, offset7, offset5, offset3, place7, offset1, place6, offset2, place8` | `this:ecx` |
| `00456E90` | `clean_terrain` | `x1, y1, x2, y2, replacement_terrain, place3, place2, index2, place5, index1, place4, pass_index, change_flag, place1, offset7, offset5, offset3, offset1, place6, offset2` | `this:ecx` |
| `00457300` | `clean_borders` | `x1, y1, x2, y2` | `this:ecx` |
| `00457310` | `clean_border_tile` | `this_terrain, other_terrain, matrix` | `this:ecx` |
| `00457320` | `do_terrain_brush` | `x, y, brush_size, terrain_id, y2, x1` | `this:ecx` |
| `004573C0` | `do_terrain_brush_stroke` | `x1, y1, x2, y2, brush_size, terrain_id, dy, dx, index, y, x` | `this:ecx` |
| `00457510` | `do_elevation_brush` | `x, y, brush_size, elevation_height, y2, x2, y_index` | `this:ecx` |
| `004575C0` | `do_elevation_brush_stroke` | `x1, y1, x2, y2, brush_size, elevation_height, dy, dx, index, y, x` | `this:ecx` |
| `00457750` | `do_cliff_brush` | `x, y, cliff_id, delete_cliff` | `this:ecx` |
| `00457760` | `do_cliff_brush_stroke` | `x1, y1, x2, y2, cliff_id, delete_cliff, dy, dx, index, y, x` | `this:ecx` |
| `004578A0` | `map_generate` | `owner, gworld, player_info, zone_terrain` | `this:ecx` |
| `004578B0` | `map_generate2` | `gworld, new_width, new_height, type, player_num` | `this:ecx` |
| `004579C0` | `load_map` | `infile, index1, h, w, c, y, x` | `this:ecx` |
| `00457C50` | `save_map` | `outfile, c, y` | `this:ecx` |
| `00457DF0` | `save` | `outfile` | `this:ecx` |
| `00457EB0` | `load_terrain_types` | `sounds, filename2` | `this:ecx` |
| `00457F80` | `load_terrain_types` | `terrain_table, sounds, rt_cliff_color, id, name, border, terrain_to_draw, interval, resource_id, border_num, infile, low_color, med_color, lt_cliff_color, animation_frames, pause_between_loops, is_animated, hi_color, impassable_terrain, pict_name, random, sound_id, row, passable_terrain, col` | `this:ecx` |
| `00458280` | `load_border_types` | `sounds, filename2` | `this:ecx` |
| `00458350` | `load_border_types` | `border_table, sounds, id, underlay_terrain, name, interval, resource_id, infile, low_color, med_color, tile_flag, animation_frames, pause_between_loops, is_animated, hi_color, pict_name, random, border_style, sound_id` | `this:ecx` |
| `00458600` | `load_terrain_obj_types` | `terr_obj_tbl, id, num, density, flag, obj_id` | `this:ecx` |
| `00458760` | `delete_objects_on_tile` | `obj_owner, gworld, x, y, no_delete_start, no_delete_end` | `this:ecx` |
| `004587D0` | `delete_all_objects_on_tile` | `x, y` | `this:ecx` |
| `00458820` | `create_terrain_object` | `obj_owner, gworld, row, col, old_terrain, delete_obj, no_delete_start, no_delete_end, y, x, end_i, obj_flag` | `this:ecx` |
| `00458B40` | `clear_terrain_object` | `gworld, row, col, old_terrain, delete_obj, no_delete_start, no_delete_end, list, next_list` | `this:ecx` |
| `00458C90` | `place_terrain_object` | `obj_owner, gworld, row, col, obj_type_id, FillFlag, obj_density, y, i, x, end_i, obj_flag, terrain` | `this:ecx` |
| `00458FD0` | `create_terrain_objects` | `obj_owner, gworld` | `this:ecx` |
| `00459020` | `set_tile_size` | `tile_type, width, height, y_delta` | `this:ecx` |
| `00459060` | `tile_map_coords` | `x, y, tile, offset_x, offset_y, z` | `this:ecx` |
| `004593A0` | `check_map_coords` | `mapcol, maprow` | `this:ecx` |
| `004593D0` | `get_elev` | `mapcol, maprow` | `this:ecx` |
| `00459400` | `get_terrain` | `mapcol, maprow, type` | `this:ecx` |
| `00459460` | `get_border` | `mapcol, maprow, border_type` | `this:ecx` |
| `004594B0` | `set_terrain_passablity` | `mapcol1, maprow1, mapcol2, maprow2, passabilty` | `this:ecx` |
| `004595E0` | `set_elev` | `mapcol1, maprow1, mapcol2, maprow2, elev, delta, set_flag, maprow, cur_player` | `this:ecx` |
| `00459900` | `set_terrain` | `gworld, mapcol, maprow, terrain, no_delete_start, no_delete_end, cur_player, old_terrain, obj_owner` | `this:ecx` |
| `00459A00` | `set_terrain_absolute` | `gworld, mapcol, maprow, terrain, no_delete_start, no_delete_end, obj_owner` | `this:ecx` |
| `00459A90` | `set_terrain` | `obj_owner, gworld, mapcol1, maprow1, mapcol2, maprow2, terrain, set_flag, delete_obj, maprow` | `this:ecx` |
| `00459D20` | `get_tile_type` | `map_col, map_row, ecl, et, eb, ebl, ech, etr, el, etl` | `this:ecx` |
| `0045A030` | `get_border_type` | `map_col, map_row, tile, ter_bot, ter_top_lft, ter_lft, ter_bot_rgt, bor_ter, ter_bot_lft, ter_cur, ter_rgt, ter_top_rgt, ter_top` | `this:ecx` |
| `0045A490` | `check_for_border` | `cur_ter, bor_ter` | `this:ecx` |
| `0045A500` | `update` | `world_time, cur_time, i` | `this:ecx` |
| `0045A6D0` | `get_point` | `screen_x, screen_y, x, y, z, x_offset, y_offset` | `this:ecx` |

## Original-name recovery

The source restores every recorded function parameter name.
It also restores direct local names where the source mapping is clear.

The source changes include:

- Constructors: `infile`, `setup`, `border_tbl`, `terrain_tbl`, `map_tbl`, `TileWid`, `TileHgt`, and `ElevHgt`.
- Map setup: `infile`, `rmm_map_file`, `rmm_land_file`, `rmm_terr_file`, `rmm_obj_file`, `flag`, `player`, `world`, `new_terrain`, `width`, `height`, `terrain`, `elev`, `x1`, `y1`, `x2`, `y2`, and `attribute`.
- Scenario I/O: `outfile`, `infile`, `zone_terrain`, `w`, `h`, `terrain_info`, and `c`.
- Elevation and terrain cleanup: `elevation_height`, `replacement_terrain`, and `pass_index`.
- Brush routines: `brush_size`, `terrain_id`, `elevation_height`, `cliff_id`, `delete_cliff`, and the `x1`/`y1`/`x2`/`y2` endpoint names.
- Map generation: `owner`, `gworld`, `player_info`, `zone_terrain`, `new_width`, `new_height`, `type`, and `player_num`.
- File loaders: `outfile`, `border_table`, `terr_obj_tbl`, `tile_flag`, and `c`.
- Object routines: `obj_owner`, `gworld`, `no_delete_start`, and `no_delete_end`.
- Coordinate and terrain APIs: `tile_type`, `mapcol`, `maprow`, `mapcol1`, `maprow1`, `mapcol2`, `maprow2`, `passabilty`, `elev`, and `set_flag`.
- Border APIs: `map_col`, `map_row`, `tile`, `ter_bot`, `ter_top_lft`, `ter_lft`, `ter_bot_rgt`, `bor_ter`, `ter_bot_lft`, `ter_cur`, `ter_rgt`, `ter_top_rgt`, `ter_top`, `cur_ter`, and `screen_x`/`screen_y`/`x`/`y`/`z`/`x_offset`/`y_offset`.

The source also replaces decompiler names in `clear_map_view_info`.
It uses `col`, `row`, and `view_data` for the existing byte traversal.
It replaces `fVar1` through `fVar4` in `tile_map_coords`.
It uses `offset`, `x_ratio`, `y_value`, and `y_ratio`.
It renames the unrecorded `load_map` temporary `local_10` to `map_height`.
These are inferred names, not PDB names.

## Inferred names and unresolved mappings

The PDB contains optimized and reused stack symbols in cleanup functions.
The source keeps separate descriptive variables where one PDB slot covers several values.
This avoids forced stack-slot mapping.

- `scenario_save` keeps `local_bytes[2]` for the adjacent height and overlay bytes.
  PDB records name those bytes `height_info` and `overlay_info`.
  The source restores `height_info` and `terrain_info`.
  It does not reshape the two-byte temporary.
- `scenario_load` keeps the existing long `y` loop temporary and the `int i` conversion temporary.
  PDB records also include short `y` and int `x` stack symbols.
  The source keeps the inferred `map_height` temporary.
  It does not change those types or force an alias.
- `preclean_elevation`, `clean_elevation`, and `clean_terrain` keep descriptive directional flags.
  PDB `place*` and `offset*` records cover optimized and reused slots.
  The source restores `change_flag`, `pass_index`, `index1`, and `index2` where direct.
- `get_tile_type` keeps its existing height names.
  PDB `ecl`, `et`, `eb`, `ebl`, `ech`, `etr`, `el`, and `etl` overlap parameters and optimized values.
  No stack-slot declaration was reshaped.
- `tile_map_coords` keeps the PDB `z` declaration.
  The four arithmetic names are inferred from their effects.
- `load_map` keeps the two loop variables `h` and `y`.
  PDB also records optimized `index1`, `x`, and stack aliases.
  No extra loop or storage was added.

No recorded parameter or local was left as a placeholder.
The unresolved items above are only optimized or reused local mappings.

## Constants, resources, and comments

No numeric constant changed.
No enum or resource ID was added.
No resource lookup is present in this cleanup.
No source comment was added.

The source keeps the original debug source strings and line values.
It keeps the original `0x1f`, `0x0f`, `0x10`, and map-size operations.

## Code generation, type, layout, and symbol review

The name cleanup renames identifiers and removes decompiler-only names.
The latest correction restores source-local declarations and alias reads.
It does not change types, member order, evaluation order, control flow, call targets,
relocations, function boundaries, or ABI symbols.
The `TileWid`, `TileHgt`, `ElevHgt`, and `FillFlag` spellings preserve PDB case.
The `passabilty` spelling preserves the PDB misspelling.
No inline assembly or wrapper was added.

## Diff review

The complete base-to-head diff was reviewed.
It contains only `src/map.cpp` and this report.
The source diff contains the earlier name cleanup, formatting passes, and listed evidence corrections.
The report contains the evidence, correction history, and declaration-only header request.
No `include/map.h` edit is present.
No build, compiler, check, match, test, or game run was used for this review.

## Header requests

`include/map.h` is owned outside this assignment.
It was read and not edited.
Owner 16 may apply parameter names to declarations only.
Use these exact declarations for the definitions changed in this wave:

```cpp
RGE_Map(int infile, RGE_Sound **sounds, unsigned char setup);
RGE_Map(char *border_tbl, char *terrain_tbl, char *map_tbl, short TileWid,
        short TileHgt, short ElevHgt, RGE_Sound **sounds);
virtual ~RGE_Map();
virtual void data_load_random_map(int infile);
virtual void load_random_map(char *rmm_map_file, char *rmm_land_file,
                             char *rmm_terr_file, char *rmm_obj_file);
virtual unsigned char do_terrain_brush(long x, long y, long brush_size,
                                       unsigned char terrain_id);
virtual unsigned char do_terrain_brush_stroke(long x1, long y1, long x2,
                                              long y2, long brush_size,
                                              unsigned char terrain_id);
virtual unsigned char do_elevation_brush(long x, long y, long brush_size,
                                         unsigned char elevation_height);
virtual unsigned char do_elevation_brush_stroke(long x1, long y1, long x2,
                                                long y2, long brush_size,
                                                unsigned char elevation_height);
virtual unsigned char do_cliff_brush(long x, long y, unsigned char cliff_id,
                                     unsigned char delete_cliff);
virtual unsigned char do_cliff_brush_stroke(long x1, long y1, long x2,
                                             long y2, unsigned char cliff_id,
                                             unsigned char delete_cliff);
virtual void map_generate(RGE_Player *owner, RGE_Game_World *gworld,
                          RGE_Player_Info *player_info,
                          unsigned char *zone_terrain);
virtual void map_generate2(RGE_Game_World *gworld, long new_width,
                           long new_height, unsigned char type,
                           long player_num);
virtual void save(int outfile);

void init_tile_sizes();
void set_map_visible(unsigned char flag);
void set_map_fog(unsigned char flag);
void clear_map(RGE_Player *player, RGE_Game_World *world,
               unsigned char new_terrain, long width, long height);
void clear_map(unsigned char terrain, unsigned char elev);
void new_map(long width, long height);
void request_redraw(int x1, int y1, int x2, int y2, unsigned char attribute);
void clear_map_view_info();
void coordinate_map();
void set_map_screen_pos(int x1, int y1, int x2, int y2);
void scenario_save(int outfile);
void scenario_load(int infile, unsigned char *zone_terrain);
RGE_Tile **give_up_map_offsets();
long get_map_width();
long get_map_height();
void preclean_elevation(long x1, long y1, long x2, long y2,
                        unsigned char elevation_height);
unsigned char postclean_elevation(long x1, long y1, long x2, long y2,
                                  unsigned char elevation_height);
void clean_elevation(long x1, long y1, long x2, long y2,
                     unsigned char elevation_height);
void clean_terrain(long x1, long y1, long x2, long y2,
                   unsigned char replacement_terrain);
void clean_borders(long x1, long y1, long x2, long y2);
long clean_border_tile(long this_terrain, long other_terrain,
                       long (* const matrix)[32]);
void load_map(int infile);
void save_map(int outfile);
void load_terrain_types(char *terrain_table, RGE_Sound **sounds);
void load_terrain_types(RGE_Sound **sounds);
void load_border_types(char *border_table, RGE_Sound **sounds);
void load_border_types(RGE_Sound **sounds);
void load_terrain_obj_types(char *terr_obj_tbl);
void delete_objects_on_tile(RGE_Player *obj_owner, RGE_Game_World *gworld,
                            int x, int y, int no_delete_start,
                            int no_delete_end);
void delete_all_objects_on_tile(int x, int y);
void create_terrain_object(RGE_Player *obj_owner, RGE_Game_World *gworld,
                           short row, short col, short old_terrain,
                           int delete_obj, int no_delete_start,
                           int no_delete_end);
int clear_terrain_object(RGE_Game_World *gworld, short row, short col,
                         short old_terrain, int delete_obj,
                         int no_delete_start, int no_delete_end);
void place_terrain_object(RGE_Player *player, RGE_Game_World *gworld,
                          short row, short col, int obj_type_id,
                          int FillFlag);
void create_terrain_objects(RGE_Player *obj_owner, RGE_Game_World *gworld);
void set_tile_size(unsigned char tile_type, short width, short height,
                   short y_delta);
void tile_map_coords(short x, short y, RGE_Tile *tile, float *offset_x,
                     float *offset_y);
unsigned char check_map_coords(short mapcol, short maprow);
unsigned char get_elev(short mapcol, short maprow);
unsigned char get_terrain(short mapcol, short maprow);
unsigned char get_border(short mapcol, short maprow);
void set_terrain_passablity(short mapcol1, short maprow1, short mapcol2,
                            short maprow2, unsigned char passabilty);
void set_elev(short mapcol1, short maprow1, short mapcol2, short maprow2,
              unsigned char elev, short delta, unsigned char set_flag);
void set_terrain(RGE_Game_World *gworld, short mapcol, short maprow,
                 unsigned char terrain, int no_delete_start,
                 int no_delete_end);
void set_terrain_absolute(RGE_Game_World *gworld, short mapcol, short maprow,
                          unsigned char terrain, int no_delete_start,
                          int no_delete_end);
void set_terrain(RGE_Player *obj_owner, RGE_Game_World *gworld,
                 short mapcol1, short maprow1, short mapcol2, short maprow2,
                 unsigned char terrain, unsigned char set_flag, int delete_obj);
unsigned char get_tile_type(short map_col, short map_row);
void get_border_type(short map_col, short map_row);
void check_for_border(unsigned char cur_ter, unsigned char &bor_ter);
void update(unsigned long world_time);
void get_point(short &screen_x, short &screen_y, float x, float y, float z,
               short x_offset, short y_offset);
```

The existing `RGE_Map(RGE_Game_World *, long, long)` declaration has no
assigned source definition in this wave. Leave that declaration unchanged.
Add names only. Keep all types, parameter order, overloads, virtual slots,
function boundaries, ABI symbols, and calling conventions unchanged.
Keep all class members, declaration order, and layout assertions unchanged.

## Validation

Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime harness was run.
The source commit contains only the assigned source file.
The report correction commit contains only this report.
