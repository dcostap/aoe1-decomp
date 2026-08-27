# 00484D00 `base_elevation_generate` owner audit

## Proven owner and types

- The PDB owner is the protected `RGE_RMM_Elevation_Generator` member in `rmm_elev.cpp`, lines 290-403.
- The by-value parameter is `RGE_Elevation_Info_Line`. It is 0x18 bytes and has six `long` fields:
  `elevation_size`, `elevation`, `clumps`, `spacing`, `base_elevation`, and `base_terrain_type`.
- `RGE_RMM_Elevation_Generator` inherits the 0x30-byte `RGE_Random_Map_Module`. Its `info` starts at +0x30. The complete class is 0xFB0 bytes.
- The base fields used by this function are:
  - +0x10: `RGE_Tile** map_row_offset`;
  - +0x14: `long map_width`;
  - +0x18: `long map_height`;
  - +0x24: `unsigned char** search_map_rows`.
- `RGE_Tile` records are 0x18 bytes. The terrain/elevation byte is at +0x05. Bits 0-4 hold terrain. Bits 5-7 hold elevation.
- `Map_Stack` is 0x18 bytes. Its fields are two `long` coordinates, two `float` costs, and two links.

## Coordinate and array ownership

The target uses the first `pop_stack` output as the row index and the second output as the column index.
The resulting map expressions are:

- `search_map_rows[row][column]`;
- `map_row_offset[row] + column * 0x18`;
- `map_width` bounds the column;
- `map_height` bounds the row.

The elevation helpers use their formal `(x, y)` order. The caller therefore passes `(column, row)`:

- `check_start_elevation(column, row, terrain, elevation, spacing)`;
- `remove_area_from_lists(column, row, clump_size)`;
- `check_elevation(elevation, column, row, spacing, terrain, base_elevation)`;
- `fig_chance(result, column, row)`;
- `push_stack(stack, column, row, cost, total_cost)`.

The four first-phase neighbor calls and the four weighted phase calls keep this order.

The tile neighbors prove the same layout. Column neighbors use `-0x18` and `+0x18` tile strides.
Row neighbors use `-map_width * 0x18` and `+map_width * 0x18`.

## Frame and array boundary

The original prologue is `sub esp, 0x988`, followed by four saved registers.
The original local addresses are entry-relative:

- `local_stack`: `entry ESP - 0x960` (`[esp+0x38]` after the saves);
- `stack[0]`: `entry ESP - 0x948` (`[esp+0x50]` after the saves);
- `stack[99]` ends at entry ESP because `99 * 0x18 == 0x948`.

This is the required array boundary. It does not write above entry ESP.
With a 0x980 frame and four saved registers, the same absolute array base is `[esp+0x48]`.
A `[esp+0x4C]` base with a 0x980 frame starts four bytes too high and makes the 0x948-byte array end at `entry ESP + 4`.

The width and height limits are real scalar locals. They are not `Map_Stack` fields:

- `map_width - 1` is stored at entry-relative `-0x964` (`[esp+0x34]` after the saves).
- `map_height - 1` is stored at entry-relative `-0x96C` (`[esp+0x2C]` after the saves).

The phase-B column and row neighbor checks read these locals at 00485056 and 00485135.
The phase-A checks instead reload `this->map_width` and `this->map_height` at 00484E6A and 00484E89.
Do not use the saved limits for both phases.

The Ghidra label `loc_stack.x` is an alias error. The target does not store the width limit into `local_stack.x`.
It passes `local_stack` at 00484D3F, writes `local_stack.prev` at 00484D46, and writes `stack[0].x` at 00484D4A.
There is no proven initialization of `local_stack.x`.

The target also leaves the two `pop_stack` coordinate output homes uninitialized before the first call.
The output helper writes them. A source initializer for `x` or `y` adds prologue stores that the target does not have.

The target uses integer homes for `chance` and the weighted random result. The `chance` home is incremented with integer `inc` instructions.
The pop cost home and `fig_chance` result are `float` homes.
The weighted random result uses one repeated dword home across all four branches.

## Direct call set

The 23 direct call operations are in this order:

1. 00480CC0 `init_stack` (one static call site in the clump loop).
2. 00484B90 `link_stack_randomly`.
3. 0054B700 `__ftol` after `sqrt`.
4. 00480DA0 `pop_stack`.
5. 004847C0 `check_start_elevation`.
6. 00484C80 `remove_area_from_lists`.
7-10. 00480D10 `push_stack` for the four first-phase neighbors.
11. 00480DA0 `pop_stack` for the weighted phase.
12. 004230A0 `debug_rand`, line 0x171.
13. 004848A0 `check_elevation`.
14. 00484B30 `fig_chance`.
15-22. Four pairs of 004230A0 `debug_rand` and 00480D10 `push_stack`, with debug lines 0x17D, 0x17F, 0x181, and 0x183.
23. 00480CF0 `deinit_stack`.

All calls are direct. The member helpers use the reviewed RMM ABI. `pop_stack` writes node `x`, node `y`, and `cost` through three pointer arguments.

## Evidence sources

- `inventory/functions/0048/00484D00_base_elevation_generate.txt`.
- `inventory/types/dumps/RGE_Elevation_Info_Line.txt`.
- `inventory/types/dumps/RGE_Elevation_Info.txt`.
- `inventory/types/dumps/RGE_RMM_Elevation_Generator.txt`.
- `inventory/types/dumps/RGE_Random_Map_Module.txt`.
- `inventory/types/dumps/RGE_Tile.txt`.
- `inventory/types/dumps/Map_Stack.txt`.
- `inventory/functions/0048/00480DA0_pop_stack.txt` and `00480D10_push_stack.txt`.

The current natural source still rebuilds at 0x980. This audit does not claim an exact source form.
It records binary ownership and boundary facts for the next source attempt.
