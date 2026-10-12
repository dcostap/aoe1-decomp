# tvw_main.cpp natural module

The PDB source module is `C:\\msdev\\work\\age1_x1\\tvw_main.cpp`.
The source order is monotonic from `0052CAF0` through `0052DE40`.
The canonical owner is `src/tvw_main.cpp`.

## Function status

- `0052CAF0` `draw_multi_object_outline`: scratch. The natural body keeps all
  wall-outline paths and calls. The current strict difference is 1203 bytes.
- `0052D060` `draw_wall_outline`: exact. `MATCH`, `0.0000%`.
- `0052D1F0` `command_place_object`: exact. `MATCH`, `0.0000%`.
- `0052D320` `command_place_multi_object`: exact. `MATCH`, `0.0000%`.
- `0052D4F0` `place_line_of_walls`: exact. `MATCH`, `0.0000%`.
- `0052D600` `mouse_left_up_action`: accepted drift. The 14 differing bytes
  only recolor caller-saved registers. Calls and memory effects remain equal.
- `0052D970` `mouse_right_up_action`: accepted drift. The 14 differing bytes
  only recolor caller-saved registers. Calls and memory effects remain equal.
- `0052DCE0` `pick_through_fog`: exact. `MATCH`, `0.0000%`.
- `0052DD10` `pick_weight`: exact. `MATCH`, `0.0000%`.
- `0052DE20` `command_make_do`: exact. `MATCH`, `0.0000%`.
- `0052DE40` `mouse_left_dbl_click_action`: exact. `MATCH`, `0.0000%`.

## Context and ownership

`TRIBE_Main_View` uses the reviewed `RGE_Main_View` and `RGE_View` surfaces.
The module also uses the canonical Panel, BaseGame, map, object, player, world,
master-object, and tribe-player providers. It has no copied class hierarchy,
raw absolute access, wrapper, fragment include, or context-selection macro.

The nearby `00495470` and `00495490` entries are compiler-generated destructor
functions. They are not normal source bodies in this module.
