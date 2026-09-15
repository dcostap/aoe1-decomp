# Cleanup wave 03: `src/tmap.cpp`

## Delivery

- Module: `src/tmap.cpp`.
- Header owner: `include/tmap.h`; read only. No header request.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final code commit: `bfff338e220a3b8fcd0ad8bd62a4f04578fafc1e`.
- Changed files: `src/tmap.cpp` and this report.
- Source order, declarations, types, storage, calls, and executable statements remain unchanged.

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

The source uses only the existing `TRIBE_Map` and shared declarations. No
header, registry, resource mapping, or ABI request is pending.

## Unresolved questions

- The PDB does not preserve names for several optimized locals. I left those
  names descriptive instead of forcing reused stack-slot mappings.
- `setup_cliff_type` has no PDB local records. `info_index` and `cliff_index`
  are new names and should not be treated as recovered source names.
- The existing `TRIBE_Map` header still owns unnamed declaration parameters.
  No header edit is required for definition-only PDB name recovery.

## Validation status

Compilation, matching checks, audits, builds, and tests were not run, as
required for this cleanup phase.
