# Source cleanup: `rmm_obj.cpp`

- Module: `src/rmm_obj.cpp`
- Branch: `cleanup/staging-20260915-17`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Final code commit: `4dc6a43d1100249b8a163032741960915621c844`
- Assigned header: `include/rmm_obj.h` (read only; not changed)
- Registry: `config/functions/src/rmm_obj.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\rmm_obj.cpp`
- PDB evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Inventory evidence: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/`

## Changed files

- `src/rmm_obj.cpp`
- `decomp_notes/source_cleanup/wave01/rmm_obj.md`

The source commit changes names and brace placement only. It keeps types, scopes,
storage, statements, calls, constants, and source order. It adds no executable
statement or declaration.

## PDB recovery coverage

All 13 VAs in the registry were inspected. Every PDB `this` record is `ecx`.

| VA | Status | PDB records and result |
| --- | --- | --- |
| `00485C50` | `matching` | Restored `in_map`, `parent_module`, `in_world`, `in_info`, and `add_terrain_objects` from `param_1` through `param_5`. |
| `00485CB0` | `matching` | Kept `obj_id`. Restored `count` from `number_of_groups` and `er` from `object_exclusion_zone`. |
| `00485DC0` | `matching` | No stack records. |
| `00485E50` | `matching` | Restored `info_line` from `line`. |
| `00485F10` | `accepted_drift` | Restored `inner_radius` and `outer_radius` from `unused` and `range`. Kept PDB names `y1`, `y0`, `x1`, `x0`, and `last`. Renamed the non-PDB `local_4` temporary to `rows_remaining`. |
| `00486110` | `matching` | `info_line`, `x`, and `y` were already present. No PDB local records were present. |
| `00486180` | `matching` | Restored `set_num` from `fill`. Kept `end_y` and `y_cur`; PDB `y2` and `y_index` share parameter slots, so these mappings remain unresolved. |
| `00486210` | `matching` | Restored parameters `x`, `y`, and `spacing` from `left`, `right`, and `y`. Kept `y_start`, `x_end`, and `cur_y`; PDB `y1`, `x1`, and `y_index` share parameter slots. |
| `004862B0` | `accepted_drift` | Restored `info_line` and `inner_radius` from `info` and `unused`. PDB locals `tile_y`, `tile_x`, `y`, `x`, `count`, `obj_stack`, and `zone` were already present. |
| `004864F0` | `new_verified_logic` | Restored `info_line` from `info`. PDB locals `tile_y`, `tile_x`, `y`, `x`, `count`, `obj_stack`, and `zone` were already present. |
| `00486700` | `matching` | Restored `info_line`, `map_x`, `map_y`, and `land_id` from `line`, `x`, `y`, and `land_index`. Restored PDB locals `min_x1`, `min_y1`, `min_y0`, `y`, and `map_zone`. Restored `land_zone` and `zone`: the former is the zone byte from `get_zone_info`, and the latter is the float output from `pop_stack`. Kept `tile_y`, `tile_x`, and `x` unresolved because their records reuse parameter slots. |
| `00486A60` | `matching` | Restored `info_line`, `map_x`, and `map_y` from `info`, `px`, and `py`. Kept `col`, `fx`, and `fy`; PDB coordinate records reuse optimized slots or conflict with the current coordinate role. |
| `00486C40` | `new_verified_logic` | Restored `info_line`, `map_x`, and `map_y` from `info`, `px`, and `py`. Restored `y0`, `x1`, and `y1`. Kept `min_x` for PDB `x0` because that record shares the `player` slot. PDB `x`, `y`, `tile_x`, `tile_y`, `count`, `obj_stack`, and `zone` were already present. |

PDB names that share a slot with another record were not forced onto source
variables. PDB register records and stack types were inspected before each
rename. No public symbol, class name, member name, or ABI name changed.

## Recovered and invented names

Recovered names came from procedure-scoped PDB records. These include the
constructor names, `count`, `er`, `info_line`, the placement parameters, the
land-boundary names, `map_zone`, `land_zone`, and the float `zone` output.

`rows_remaining` is the only new descriptive cleanup name. It replaces the
Ghidra-style `local_4` counter in `make_placement_stack`. Its scope and type
remain unchanged. Existing descriptive names remain where PDB mapping is not
safe.

## Constants, resources, and comments

- No new constant or enum was added.
- No resource lookup or resource ID occurs in this module.
- No resource extraction was needed.
- No source comment was added. Existing comments remain unchanged.
- No header or `include/resource_ids.h` request is needed.

## Code-generation-sensitive points

- Renames do not change effective types, storage, scopes, or evaluation order.
- Brace changes use 1TBS and do not add or remove scopes.
- The `local_4` to `rows_remaining` change keeps the same declaration and loop.
- No expression, literal, call target, relocation, virtual call, or data layout was changed.
- PDB line records can change after formatting. This is expected and was not
  used as a byte-equality claim.

## Validation and limits

I reviewed the complete Git diff and ran `git diff --check`.

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave. No build, compiler, game, or runtime validation was run.
