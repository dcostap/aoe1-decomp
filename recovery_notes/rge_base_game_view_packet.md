# RGE_Base_Game View packet

Use this packet only for View work. Do not use `include/basegame.h`.

## Scope

The class size is `0xA24`. The class dump gives high confidence.

The global pointer is at `0x0062C574`.

## Required fields

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x1B0` | `int prog_mode` | `view_tu_context.h`; View mouse and scroll owners |
| `0x1B4` | `int game_mode` | `00534530`, `0053AAF0`, View mouse owners |
| `0x1B8` | `int sub_game_mode` | `0053AAF0`, `0053D400`, `0053F810` |
| `0x3F4` | `RGE_Game_World* world` | `view_tu_context.h` and View draw owners |
| `0x3F8` | `int render_all` | View draw state |
| `0x3FC` | `short master_obj_id` | `00535610`, `0053F810` |
| `0x3FE` | `short terrain_id` | `0053AAF0` |
| `0x400` | `short elevation_height` | `0053AAF0` |
| `0x402` | `short brush_size` | `005358B0`, `0053AAF0` |
| `0x404` | `long rollover` | `00536B40` |

## Required virtual slots

| Slot | Offset | Signature |
| --- | --- | --- |
| 2 | `0x08` | `long wnd_proc(void*, uint, uint, long)` |
| 3 | `0x0C` | `void set_prog_mode(int)` |
| 4 | `0x10` | `void set_game_mode(int, int)` |
| 5 | `0x14` | `void set_player(short)` |
| 11 | `0x2C` | `TPanel* get_view_panel()` |
| 12 | `0x30` | `TPanel* get_map_panel()` |
| 13 | `0x34` | `RGE_Scenario_Header* new_scenario_header(RGE_Scenario*)` |
| 14 | `0x38` | `RGE_Scenario_Header* new_scenario_header(int)` |
| 16 | `0x40` | `void notification(int, long, long, long, long)` |
| 21 | `0x54` | `int processCheatCode(int, char*)` |
| 45 | `0xB4` | `RGE_Game_World* create_world()` |
| 46 | `0xB8` | `int handle_message(tagMSG*)` |
| 47 | `0xBC` | `int handle_idle()` |
| 62 | `0xF8` | `int action_update()` |
| 63 | `0xFC` | `int action_mouse_move(long, long, int, int, int, int)` |
| 64 | `0x100` | `int action_key_down(ulong, int, int, int, int)` |
| 65 | `0x104` | `int action_user_command(ulong, ulong)` |
| 66 | `0x108` | `int action_command(ulong, ulong)` |
| 72 | `0x120` | `int action_size()` |
| 73 | `0x124` | `int action_close()` |

## Direct View helpers

Use direct nonvirtual declarations for these View calls:

- `int get_paused()`
- `RGE_Player* get_player()`
- `void get_mouse_pos(POINT&)`
- `TShape* get_shape(int)`
- `void mouse_off()`
- `void mouse_on()`
- `void add_to_timing(int, ulong)`
- `void increment_view_update_count()`

## Exact anchors

- `0041C240 set_prog_mode`
- `0041C250 get_view_panel`
- `0041C260 get_map_panel`
- `0041C6E0 notification`
- `0041C6F0 processCheatCode`
- `0041C700 handle_message`
- `0041C710 action_update`
- `0041C720 action_mouse_move`
- `0041C730 action_key_down`
- `0041C740 action_user_command`
- `0041C750 action_command`
- `0041C7B0 action_size`
- `0041C7C0 action_close`
- `0053D890 draw`
- `0053DBA0 do_auto_scroll`
- `0053F810 command_place_object`

## Sources

- `inventory/classes/dumps/RGE_Base_Game.txt`
- `inventory/classes/all_class_interfaces.csv`, rows 945 onward
- `include/view_tu_context.h`
- `inventory/functions/0053/*` for the listed anchors
