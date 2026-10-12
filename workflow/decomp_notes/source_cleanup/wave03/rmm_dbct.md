# `rmm_dbct.cpp` cleanup report

## Commits and files

- Module: `src/rmm_dbct.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source commit: `dd9fa36684c73e109a341aed6e555df18cfa3b90`
- Branch: `cleanup/staging-20260915-144`
- Changed files:
  - `src/rmm_dbct.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/rmm_dbct.md`

The source commit contains only the assigned source file. This report is the
assigned durable evidence file.

## Evidence provenance

I used the original executable evidence and the pre-cleanup source.

- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Function registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/rmm_dbct.cpp.json`
- Function packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/`
- Original Ghidra listing: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/rmm_dbct.cpp.asm`
- Original Ghidra decompilation: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/rmm_dbct.cpp.decomp`
- Read-only header: `include/rmm_dbct.h`

I inspected all twelve registered procedures and their PDB records.
Every procedure records `this` in `ecx`. No procedure records another register symbol.

| VA | Procedure | PDB parameters | PDB locals | Register |
| --- | --- | --- | --- | --- |
| `00482B70` | File constructor | `land_file`, `terrain_file`, `object_file`, `map_file` (`char*`) | `infile` (`_iobuf*`), `map_id`, `land_num`, `terrain_num`, `object_num`, `temp_terrain_type`, `temp_zone`, `temp_placement_type`, `temp_amount_of_land_used_percent`, `temp_by_player_flag`, `temp_group_flag`, `temp_scale_flag`, `index1` (`long`) | `this` in `ecx` |
| `00483020` | Stream constructor | `infile` (`int`) | `elevation_info` (`RGE_Elevation_Data*`), `index` (`long`) | `this` in `ecx` |
| `00483200` | Destructor | none | none | `this` in `ecx` |
| `004832E0` | `save` | `outfile` (`int`) | `elevation_info` (`RGE_Elevation_Data*`), `index` (`long`) | `this` in `ecx` |
| `00483430` | `generate` | none | none | `this` in `ecx` |
| `00483540` | `init` | `in_map`, `in_world`, `type`, `player_num`, `fixed_positions` | none | `this` in `ecx` |
| `004835A0` | `de_init` | none | none | `this` in `ecx` |
| `00483600` | `calc_land_start` | `land_index`, `edge`, `land_num`, `info`, `dy` | `dx`, `mid_y2`, `index`, `mid_x2`, `mid_y1`, `mid_x1`, `not_done`, `bound_square` | `this` in `ecx` |
| `00483A20` | `add_land_module` | `fixed_positions` | `index2`, `index`, `index1`, `edge`, `land_tile_num`, `tx`, `swap`, `start_land`, `d2`, `player_teams`, `player_hash`, `distances`, `land_claimed`, `land_wanted`, `team_size`, `current_team`, `ty` | `this` in `ecx` |
| `00484160` | `add_terrain_module` | none | `index2`, `index`, `land_tile_num` | `this` in `ecx` |
| `00484320` | `add_object_module` | none | `index1` | `this` in `ecx` |
| `00484470` | `add_elevation_module` | none | `index2`, `index` | `this` in `ecx` |

The PDB records all listed integer locals as `long`, unless noted otherwise.
It records `not_done` as `unsigned char` and `bound_square` as `float`.

## Recovered names

I restored names with direct PDB support.

- File constructor counters use `land_num`, `terrain_num`, and `object_num`.
- File constructor scan temporaries use the `temp_*` PDB names.
- File constructor scan cursors use the recorded `index1` spelling.
- Stream constructor parameters and locals use `infile`, `index`, and `elevation_info`.
- `save` uses `outfile`, `index`, and `elevation_info`.
- `init` uses `in_map`, `in_world`, `type`, `player_num`, and `fixed_positions`.
- `calc_land_start` uses `land_index`, `edge`, `land_num`, and `info`.
- `add_object_module` uses the recorded `index1` spelling for its object-copy counter.
- `add_elevation_module` uses the recorded `index` spelling for its player counter.

The file also received a module-wide 1TBS brace and indentation cleanup.
No statement or declaration moved during that formatting pass.

## Unresolved declaration mappings

I did not force names from reused or optimized stack slots onto unrelated locals.

- `calc_land_start` has PDB names `mid_x1`, `mid_x2`, `mid_y1`, and `mid_y2`.
  Their slots serve bound values and a land-output pointer at different times.
  The source keeps the existing descriptive bound and pointer names.
- `calc_land_start` records `index` at an offset shared with a parameter.
  The source keeps its existing `index` declaration and scope.
- The file constructor has no direct PDB records for inner land, terrain, or object cursors.
  The source keeps `land_index`, `terrain_index`, and `object_index`.
- The stream constructor has no direct records for the land, terrain, or object pointers.
  The source keeps `land_data`, `terrain_data`, and `object_data`.
- `save` has no direct record for its map pointer cursor.
  The source keeps `map_index` separate from the recovered `index` counter.
- `add_land_module` has PDB slots shared by `index2`, `current_team`, `edge`,
  `land_tile_num`, `land_wanted`, and several arrays.
  The source keeps its existing descriptive declarations.
- `add_terrain_module` has shared slots for `index2`, `index`, and `land_tile_num`.
  The source keeps `terrain_index`, `land_index`, and `hot_spot_index`.
- `add_object_module` has no direct records for `source_index`, `land_index`,
  or `map_land_index`. The source keeps those descriptive names.
- `add_elevation_module` records `index2` without a reliable source declaration mapping.
  The source keeps `land_index` and `hot_spot_index`.

Several PDB records show `long` while the existing source uses `int`.
This includes the recovered `index` and `index1` locals in three procedures.
I kept the existing types because this wave preserves types and declarations.
This remains a later type and code-generation review item.

## Constants, resources, and comments

No resource lookup occurs in this module.
No resource ID, resource symbol, or shared constant was added.

I preserved all numeric values and literal forms.
This includes the random debug line `451`, scan lines `0x1e5`, `0x1e6`,
`0x1fc`, and `0x1fd`, the `0x7fff` scale, and the `13` land stride.
I also preserved clumpiness values, elevation values, percentages, and sentinel values.

I retained the existing comment about the scan reset at original address `00483825`.
The original assembly supports that note.
No new source comment was needed.

## Code-generation and interface notes

The source changes are identifier substitutions and formatting only.
They do not change expressions, casts, types, scopes, storage, calls, or field layouts.
They do not change public symbols, decorated names, call targets, or function boundaries.

The header was not edited.
Please route these parameter-name updates to the header owner:

- Stream constructor: `file` to `infile`.
- `save`: `file` to `outfile`.
- `calc_land_start`: `start`, `radius`, `count`, and `land`
  to `land_index`, `edge`, `land_num`, and `info`.
- `add_land_module`: `value` to `fixed_positions`.
- `init`: `map`, `world`, `map_type`, `players`, and `value`
  to `in_map`, `in_world`, `type`, `player_num`, and `fixed_positions`.

These are parameter-name-only requests. They do not change the interface ABI.

Existing registry status remains unchanged.
The known accepted drift and reviewed reconstruction differences were not addressed.

## Risks and validation status

The main risks are the unresolved PDB slot mappings and the PDB `long` versus
source `int` declarations noted above.
The existing reviewed differences at `00484160` and `00484470` remain open.

Compilation, matching, audits, and tests were not run.
No build, validation, or runtime check was performed.
