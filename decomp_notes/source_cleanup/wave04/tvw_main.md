# `src/tvw_main.cpp` cleanup

## Delivery

- Module: `src/tvw_main.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `b7ec693e8adf1c0c226f534d1a6787ccd77cdb3f`
- Changed files: `src/tvw_main.cpp` and this report
- No header file changed.

## Scope

This cleanup restores procedure-scoped PDB names. It does not change types, scopes, storage, calls, control flow, constants, or comments.

The assigned packet set covers `0052CAF0` through `0052DE40`:

- `draw_multi_object_outline`
- `draw_wall_outline`
- `command_place_object`
- `command_place_multi_object`
- `place_line_of_walls`
- `mouse_left_up_action`
- `mouse_right_up_action`
- `pick_through_fog`
- `pick_weight`
- `command_make_do`
- `mouse_left_dbl_click_action`

## Recovered original names

The names below come from `inventory/pdb/scoped_symbols.json`. Each name matches its procedure, type, and use.

- `draw_multi_object_outline`: `master` to `master_bldg`.
- `draw_wall_outline`: parameters `x`, `y`, and `mode` to `col`, `row`, and `facet`; local `master` to `master_bldg`; local `local_12` to `y2`; local `coordinate_x` to `world_x`.
- `command_place_object`: `param_3` to `reset_mode`.
- `command_place_multi_object`: `param_1` through `param_4` to `x1`, `y1`, `x2`, and `y2`; `mode` to `reset_mode`.
- `place_line_of_walls`: parameter `master` to `master_obj`; locals `coordinate_x` and `coordinate_y` to `world_x` and `world_y`.
- `mouse_left_up_action`: `param_1` through `param_4` to `x`, `y`, `ctrl_key`, and `shift_key`.
- `mouse_right_up_action`: `param_1` through `param_4` to `x`, `y`, `ctrl_key`, and `shift_key`.
- `pick_weight`: `param_1` and `param_2` to `obj` and `confidence`.
- `command_make_do`: `mode` and `flag` to `work_on_tile` and `action_type`.
- `mouse_left_dbl_click_action`: `key` and `flags` to `ctrl_key` and `shift_key`.

`pick_through_fog` already used the PDB name `obj`, so it was unchanged.

## Unresolved mappings

- `draw_wall_outline` keeps `short local_4[2]`. The PDB records `x1` as a scalar `short`. The storage and type do not prove a safe rename.
- The PDB also records overlapping `calc_col1`, `calc_col2`, `calc_row1`, and `calc_row2` homes in `draw_multi_object_outline`. The current `row_distance` and `col_distance` declarations do not map to those homes with enough certainty. They remain unchanged.
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

## Evidence

- PDB-scoped names: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Function packets: `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/`
- PDB source path recorded by each packet: `C:/msdev/work/age1_x1/tvw_main.cpp`
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- Original PDB: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`
- Pre-cleanup object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tvw_main.obj`

Recorded SHA-256 values:

- `empiresx.exe`: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- `age1_x1.pdb`: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- `scoped_symbols.json`: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- baseline `tvw_main.obj`: `cd68dff90f2218f01c4ff56ecd5f181ee49e7ca4fb2107047c39586f865d8bf4`

Compilation, matching, audits, validation, and tests were not run.
