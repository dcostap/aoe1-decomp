# Source cleanup report: `map.cpp`

## Delivery

- Module: `src/map.cpp`
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source commit: `312a3a1d3`
- Initial report commit: `99f0fc6f4`
- Final report commit: this report correction commit.
- Branch: `cleanup/staging-20260915-137`
- Changed files: `src/map.cpp`; this report.

The report covers all 64 assigned registry functions.
The vector-deleting destructor at `00455080` is compiler-generated.
It is not an assigned normal function.

The source commit changes names only.
No expression, control flow, call, type, storage, data value, or ABI symbol changed.
`include/map.h` was read and was not changed.

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
  The source does not change those types or force an alias.
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

The changes rename identifiers and remove decompiler-only names.
They do not change types, declarations that affect storage, member order, evaluation order,
control flow, calls, relocations, function boundaries, or ABI symbols.
The `TileWid`, `TileHgt`, `ElevHgt`, and `FillFlag` spellings preserve PDB case.
The `passabilty` spelling preserves the PDB misspelling.
No inline assembly or wrapper was added.

## Header requests

`include/map.h` is owned outside this assignment.
It was read and not edited.
Its declarations omit parameter names.
A later header cleanup may add the names listed in the PDB table.
No type or signature change is requested.

## Validation

Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime harness was run.
The source commit contains only the assigned source file.
The report commit will contain only this report.
