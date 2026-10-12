# `src/tvw_main.cpp` cleanup

## Delivery

- Module: `src/tvw_main.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Initial source commit: `b7ec693e8adf1c0c226f534d1a6787ccd77cdb3f`
- Correction source commit: `ac33781ca5718e8912559c67f478d6f896369505`
- Changed files: `src/tvw_main.cpp` and this report
- No header file changed.

## Scope

This cleanup restores procedure-scoped PDB names. It does not change types, scopes, storage, calls, control flow, constants, or comments.

The assigned packet set covers these eleven procedures:

- `0052CAF0` `draw_multi_object_outline`
- `0052D060` `draw_wall_outline`
- `0052D1F0` `command_place_object`
- `0052D320` `command_place_multi_object`
- `0052D4F0` `place_line_of_walls`
- `0052D600` `mouse_left_up_action`
- `0052D970` `mouse_right_up_action`
- `0052DCE0` `pick_through_fog`
- `0052DD10` `pick_weight`
- `0052DE20` `command_make_do`
- `0052DE40` `mouse_left_dbl_click_action`

## Complete PDB record coverage

The records below come from `inventory/pdb/scoped_symbols.json`. The offsets are PDB stack offsets. Each procedure has one `this` record in `ecx`. Each procedure has no function-static record.

### `0052CAF0` `draw_multi_object_outline`

- Parameters: none beyond `this`.
- Stack records, all locals: `calc_col2: long @ -0x30`; `pick_info: RGE_Pick_Info @ -0x14`; `calc_col1: long @ -0x38`; `point: tagPOINT @ -0x1c`; `start_col: int @ -0x34`; `master_bldg: TRIBE_Master_Building_Object* @ -0x44`; `main_col: int @ -0x28`; `end_row: int @ -0x3c`; `calc_row2: long @ -0x48`; `main_row: int @ -0x2c`; `end_col: int @ -0x40`; `calc_row1: long @ -0x24`; `start_row: int @ -0x20`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: renamed local `master` to recovered original `master_bldg`.
- The current `row_distance` and `col_distance` names remain. They do not map safely to the four overlapping `calc_*` records.

### `0052D060` `draw_wall_outline`

- Parameters: `col: long @ +0x4`; `row: long @ +0x8`; `master_bldg: TRIBE_Master_Building_Object* @ +0xc`; `facet: long @ +0x10`.
- Stack records, locals: `y4: short @ -0x4`; `y3: short @ -0x16`; `y2: short @ -0x1a`; `y1: short @ -0x12`; `x4: short @ -0x18`; `x3: short @ -0x8`; `x2: short @ -0x14`; `x1: short @ -0x1c`; `scr_y: short @ -0x10`; `scr_x: short @ -0xc`; `world_y: float @ +0xc`; `world_x: float @ +0x8`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: restored parameters `col`, `row`, `facet`; renamed local `master` to `master_bldg`; renamed `local_12` to `y2`; renamed `coordinate_x` to `world_x`.
- The `world_x` and `world_y` records overlap positive parameter homes. The `world_y` expression remains inline. The current `short local_4[2]` remains because the PDB `x1` record is a scalar `short`.

### `0052D1F0` `command_place_object`

- Parameters: `x: long @ +0x4`; `y: long @ +0x8`; `reset_mode: int @ +0xc`.
- Stack records, locals: `pick_info: RGE_Pick_Info @ -0x14`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: renamed parameter `param_3` to recovered original `reset_mode`.

### `0052D320` `command_place_multi_object`

- Parameters: `x1: long @ +0x4`; `y1: long @ +0x8`; `x2: long @ +0xc`; `y2: long @ +0x10`; `reset_mode: int @ +0x14`.
- Stack records, locals: none.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: restored parameters `x1`, `y1`, `x2`, `y2`, and `reset_mode` from `param_1` through `param_4` and `mode`.

### `0052D4F0` `place_line_of_walls`

- Parameters: `player: TRIBE_Player* @ +0x4`; `master_obj: TRIBE_Master_Building_Object* @ +0x8`; `x1: int @ +0xc`; `y1: int @ +0x10`; `x2: int @ +0x14`; `y2: int @ +0x18`.
- Stack records, locals: `y: int @ +0x10`; `x: int @ +0x14`; `world_y: float @ +0xc`; `world_x: float @ +0x8`; `y_skip: int @ -0x8`; `x_skip: int @ -0xc`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: renamed parameter `master` to recovered original `master_obj`; renamed locals `coordinate_x` and `coordinate_y` to recovered originals `world_x` and `world_y`.
- The `x`, `y`, and `world_*` records overlap parameter homes. Their separate declarations remain unchanged.

### `0052D600` `mouse_left_up_action`

- Parameters: `x: long @ +0x4`; `y: long @ +0x8`; `ctrl_key: int @ +0xc`; `shift_key: int @ +0x10`.
- Stack records, locals: `pick_info: RGE_Pick_Info @ -0x14`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: restored parameters `x`, `y`, `ctrl_key`, and `shift_key` from `param_1` through `param_4`.

### `0052D970` `mouse_right_up_action`

- Parameters: `x: long @ +0x4`; `y: long @ +0x8`; `ctrl_key: int @ +0xc`; `shift_key: int @ +0x10`.
- Stack records, locals: `pick_info: RGE_Pick_Info @ -0x14`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: restored parameters `x`, `y`, `ctrl_key`, and `shift_key` from `param_1` through `param_4`.

### `0052DCE0` `pick_through_fog`

- Parameters: `obj: RGE_Static_Object* @ +0x4`.
- Stack records, locals: none.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: none. The source already used the recovered original `obj` name.

### `0052DD10` `pick_weight`

- Parameters: `obj: RGE_Static_Object* @ +0x4`; `confidence: int @ +0x8`.
- Stack records, locals: `select_level: unsigned char @ +0x8`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: restored parameters `obj` and `confidence` from `param_1` and `param_2`.
- The `select_level` record overlaps the `confidence` parameter home. The separate local remains unchanged.

### `0052DE20` `command_make_do`

- Parameters: `x: long @ +0x4`; `y: long @ +0x8`; `work_on_tile: int @ +0xc`; `action_type: short @ +0x10`.
- Stack records, locals: none.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: restored parameters `work_on_tile` and `action_type` from `mode` and `flag`.

### `0052DE40` `mouse_left_dbl_click_action`

- Parameters: `x: long @ +0x4`; `y: long @ +0x8`; `ctrl_key: int @ +0xc`; `shift_key: int @ +0x10`.
- Stack records, locals: `pick_info: RGE_Pick_Info @ -0x14`; `unit_level: unsigned char @ +0xc`.
- Register record: `this: TRIBE_Main_View*` in `ecx`.
- Cleanup: restored parameters `ctrl_key` and `shift_key` from `key` and `flags`.
- The `unit_level` record overlaps the `ctrl_key` parameter home. The separate local remains unchanged.

## Unresolved mappings

- `draw_wall_outline` keeps `short local_4[2]`. The PDB records `x1` as a scalar `short`. The storage and type do not prove a safe rename.
- `draw_multi_object_outline` keeps `row_distance` and `col_distance`. The PDB records four overlapping `calc_*` homes, so their declaration mapping is uncertain.
- No new descriptive names were added. No resource IDs, constants, or comments changed.

## Shared header request

The owner of `include/vw_main.h` should name the assigned `TRIBE_Main_View` declarations as follows. This request was not applied here:

- `draw_wall_outline(long col, long row, TRIBE_Master_Building_Object* master_bldg, long facet)`
- `command_place_object(long x, long y, int reset_mode)`
- `command_make_do(long x, long y, int work_on_tile, short action_type)`
- `command_place_multi_object(long x1, long y1, long x2, long y2, int reset_mode)`
- `mouse_left_up_action(long x, long y, int ctrl_key, int shift_key)`
- `mouse_right_up_action(long x, long y, int ctrl_key, int shift_key)`
- `pick_through_fog(RGE_Static_Object* obj)`
- `pick_weight(RGE_Static_Object* obj, int confidence)`
- `mouse_left_dbl_click_action(long x, long y, int ctrl_key, int shift_key)`
- `place_line_of_walls(TRIBE_Player* player, TRIBE_Master_Building_Object* master_obj, int x1, int y1, int x2, int y2)`

## Resource and DLL scope

This module has no resource lookup. No resource ID appears in the assigned procedures. No per-ID DLL record applies. No resource or DLL evidence was needed for this module.

## Evidence

- PDB-scoped names: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Function packets:
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052CAF0_draw_multi_object_outline.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052D060_draw_wall_outline.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052D1F0_command_place_object.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052D320_command_place_multi_object.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052D4F0_place_line_of_walls.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052D600_mouse_left_up_action.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052D970_mouse_right_up_action.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052DCE0_pick_through_fog.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052DD10_pick_weight.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052DE20_command_make_do.txt`
  - `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052DE40_mouse_left_dbl_click_action.txt`
- PDB source path recorded by each packet: `C:/msdev/work/age1_x1/tvw_main.cpp`
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
- Original PDB: `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
- Pre-cleanup object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tvw_main.obj`

Recorded SHA-256 values:

- `empiresx.exe`: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- `age1_x1.pdb`: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- `scoped_symbols.json`: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- baseline `tvw_main.obj`: `cd68dff90f2218f01c4ff56ecd5f181ee49e7ca4fb2107047c39586f865d8bf4`

## Correction history

### Initial cleanup

Commit `b7ec693e8adf1c0c226f534d1a6787ccd77cdb3f` restored the supported PDB names.

### Correction 1

- Joined the `place_line_of_walls` definition signature on one line.
- Joined short base-action calls and short target-pick calls when readable.
- Expanded this report with every PDB stack record and every `this` register record.
- Added the resource and per-ID DLL scope statement.
- No executable structure changed.

Compilation, matching, validation, audits, tests, and games were not run.
