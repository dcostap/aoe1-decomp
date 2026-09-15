# `rmm_cntr.cpp` cleanup report

## Commits and files

- Module: `src/rmm_cntr.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final source commit: `2318ff6ac72bc12f5fbcad04836f6bab839f0f21`
- Branch: `cleanup/staging-20260915-14`
- Changed files:
  - `src/rmm_cntr.cpp`
  - `decomp_notes/source_cleanup/wave01/rmm_cntr.md`

The source commit contains only the assigned source file. This report is the
second assigned commit change.

## PDB recovery coverage

The scoped PDB file is the main-tree file
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The source registry is
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/rmm_cntr.cpp.json`.
I inspected every registered VA and every scoped PDB record.

- `004821A0`, constructor, 181 bytes. The PDB records `in_map`, `world`,
  `type`, `player_num`, `land_info`, and `terrain_info`.
  It records `this` in `ecx`.
- `00482260`, `generate`, 5 bytes. The PDB records `this` in `ecx`.
- `00482270`, `add_land_module`, 1128 bytes. The PDB records parameters
  `info`, `type`, and `player_num`.
  It records `mid_y2`, `index2`, `index`, `mid_x2`, `mid_y1`, `mid_x1`,
  `not_done`, `land_tile_num`, and `bound_square`.
  It records `this` in `ecx`.
- `004826E0`, `add_terrain_module`, 436 bytes. The PDB records parameters
  `info`, `land_info`, and `type`.
  It records `this` in `ecx`.
- `004828A0`, `count_map_tiles`, 10 bytes. The PDB records parameter
  `terrain`. It records `this` in `ecx`.
- `004828B0`, `add_object_module`, 695 bytes. The PDB records parameters
  `world`, `land_info`, and local `object_info`.
  It records `this` in `ecx`.

## Name recovery

I restored these names from the scoped PDB records:

- Constructor `map` became `in_map`.
- Constructor `map_type` became `type`.
- Constructor `number_of_players` became `player_num`.
- The constructor local `type` became `map_type`.
  This local name avoids a parameter collision.
  It is a new cleanup name, not a recovered original name.
- `add_land_module` parameter `number_of_players` became `player_num`.
- The land loop variable `index` became `mid_x1`.
- The collision loop variable `previous` became `mid_y2`.
- The retry flag `retry` became `not_done`.
- The lower X bound `minimum_x` became `mid_x2`.
- The lower Y bound `minimum_y` became `index2`.
- The upper X bound `maximum_x` became `mid_y1`.
- `count_map_tiles` parameter `ignored` became `terrain`.

The stack locations and uses support each land-local mapping. The PDB names
also match the original line records and stack locations.

I retained existing names for `info`, `world`, `land_info`, `object_info`,
`land_tile_num`, and `bound_square`. These names match the PDB records or
existing source evidence.

## Unresolved mappings

The PDB has a stack symbol named `index` at offset `-0x3c`.
Its direct use is not present in the recovered source mapping.
I did not force this name onto another variable.
The stack slot can be reused by optimized code.

The PDB has no scoped records for `land_percent`, `x`, `y`, `maximum_y`,
`delta_x`, `delta_y`, the terrain loop index, or object `land_num` and `i`.
I kept their existing descriptive names.
These are cleanup names, not recovered original names.

The PDB records `not_done` as `unsigned char`.
The source keeps its existing `bool` type.
This preserves the current declaration type and requires later type review.

## Constants, resources, and comments

No resource lookup occurs in this module.
No new resource ID or constant was added.
The numeric object, terrain, and map values remain unchanged.
No `resource_ids.h` request is needed.

No new source comment was needed.
The existing code states the map setup and retry behavior directly.

## Code-generation and interface notes

The cleanup changes identifier names and function brace placement only.
It does not change expressions, types, storage, scopes, layouts, calls, or
call order, except for the retained source type note above.
It does not change a public symbol or a decorated name.
The constructor still uses an `int` local for the map type.
The constructor still passes the same values and uses the same call order.
No generated-data or relocation expression changed by source intent.
Compilation was not run, so this remains an evidence statement.

## Header request

I read `include/rmm_cntr.h` and did not edit it.
Please review these parameter-name-only updates for the header owner:

- Constructor: `map` to `in_map`, `map_type` to `type`,
  `number_of_players` to `player_num`.
- `add_land_module`: `map_type` to `type`,
  `number_of_players` to `player_num`.
- `add_terrain_module`: `terrain_info` to `info`, `map_type` to `type`.
- `count_map_tiles`: `ignored` to `terrain`.

These changes do not alter the interface type or ABI.

Compilation, matching, audits, and tests were not run.
