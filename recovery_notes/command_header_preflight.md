# Command header preflight after 96d491aff

This note records evidence only. It does not publish `Command.h`.

## Include path

`src/Command.cpp` is the only direct `Command.h` consumer. Add complete owner
includes to `Command.cpp`, not to `Command.h`:

```cpp
#include "../include/basegame.h"
#include "../include/command_waypoint.h"
#include "../include/com_hand.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include "../include/map.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/unit_ai_module.h"
#include "../include/world.h"
```

`basegame.h` supplies `RGE_Base_Game`. `map.h` supplies `RGE_Map`.
`m_s_obj.h`, `player.h`, and `stat_obj.h` supply the master, player, and
static-object bodies. `world.h` supplies `RGE_Game_World`.
`unit_ai_module.h` supplies the three AI methods called by `Command.cpp`.
`debuglog.h` supplies the complete logger body. `game_globals.h` supplies
`L` and `DAT_0056f4d8`, `DAT_0056f4e0`, and `DAT_0056f4e8` with their reviewed
types. `rge_base_game_global.h` supplies `rge_base_game`.
`com_hand.h` from final rebased communications commit `96d491aff` supplies the
complete communications owner. `1df6c2124` supplies the paired shared types.

Do not include context headers. Do not include `com_hand_context.h`,
`world_context.h`, or `world_scenario_context.h` as owner substitutes.

The header has no need for `<windows.h>` or `<stddef.h>` after foreign bodies
and source-only declarations move out. Keep standard library includes in the
source as needed.

## Command-owned records

Keep these records in the Command-owned surface:

- `RGE_Obj_Info`.
- `RGE_Command_Order`.
- `RGE_Command_Stop`.
- `RGE_Command_Give_Attribute`.
- `RGE_Command_Add_Attribute`.
- `RGE_Command_Create`.
- `RGE_Command_Add_Waypoint`.
- `RGE_Command_AI_Order`.
- `RGE_Command_Group_AI_Order`.
- `RGE_Command_Resign`.
- `RGE_Command_Create_Group`.
- `RGE_Command_Add_To_Group`.
- `RGE_Command_Remove_From_Group`.
- `RGE_Command_Destroy_Group`.
- `RGE_Command_Formation`.
- `RGE_Command_Group_Waypoint`.
- `RGE_Command_Pause`.

`include/command_waypoint.h` owns `XYZBYTEPoint` through `f277b6472`.
`Command.h` consumes that narrow owner header. It does not retain a local
`XYZBYTEPoint` body.

`WayPacket` and `RGE_Command_Work` occur only in `Command.cpp`. Keep them
source-private or move them there during the clean pass. The
`CommandDestroyGroupPacket` record also occurs only in `Command.cpp` and is
source-private.

Remove redundant alternate-name unions from the clean record surface. Use one
canonical field name and update source uses. This applies to `target_id` versus
`target.id`, `pos_x`/`pos_y` versus `location_x`/`location_y`, `ids` versus
`units`, and `attr_amount` versus `amount`. Preserve packet offsets.

## Foreign bodies to remove

Remove these copied bodies from `Command.h`:

- `ManagedArray`.
- `UnitAIModule`.
- `RGE_Map`.
- `RGE_Master_Static_Object`.
- `RGE_Player`.
- `RGE_Static_Object`.
- `RGE_Game_World`.
- `TCommunications_Handler`.
- `TDebuggingLog`.
- `RGE_Base_Game`.

Use forward declarations for these pointer-only types in `Command.h`.
Remove the source-only global declarations from the header as well. The
source can use the reviewed global headers and local declarations for `free`,
`operator delete`, and `debug_timeGetTime`.

The clean source must replace foreign alias uses. The destructor currently uses
`field_04`, `field_08`, and `field_14`; use `world`, `last_order`, and
`com_hand`. The move path currently uses `master`, `width`, and `height`; use
`master_obj`, `map_width`, and `map_height`.

## Focused consumers

No other source directly includes `Command.h`. The player command callers are
compiled through `PLAYER_GROUPED_TU` and use `player_tu_context.h` local
surfaces. They are not `Command.h` consumers and need no change for this
header-only cleanup. Their focused call sites are:

- `0046EEF0_sendUnitAIOrder`, `0046EFB0_sendGameOrder`, and
  `0046EFE0_sendAddWaypointCommand`.
- `00471550_command_make_move`, `004715D0_command_make_work`,
  `004716D0_command_make_do`, `00471760_command_stop`,
  `004717D0_command_place_object`, `00471820_command_add_attribute`,
  `00471860_command_give_attribute`, `004718C0_command_formation`,
  `00471940_command_stand_ground`, `004719D0_command_create_group`,
  `00471A00_command_add_to_group`, `00471A30_command_remove_from_group`,
  `00471A50_command_destroy_group`, `00471A70_command_resign`, and
  `00471AA0_command_add_waypoint`.

The `tcommand` owners use `src/tcommand_context.h` local surfaces. World
owners use their own reviewed context surfaces. Do not replace those contexts
as part of this include cleanup. If a later task reunifies those consumers,
review them as a separate ABI change.

## Communications ABI result

After 96d491aff, `include/com_hand.h` is the complete handler owner. It checks
`sizeof(TCommunications_Handler) == 0x1774`,
`current_turn == 0x10C8`, and `PlayerOptions == 0x1550`.

`Command.cpp` needs only these handler methods:

```cpp
void* get_command();
unsigned char new_command(void*, int);
```

Both declarations are present in the final rebased owner. Do not restore a partial
handler class in `Command.h`. The held `DPCAPS` SDK size mismatch belongs to
`CommGetCaps` local storage. It does not create a `TCommunications_Handler`
ABI gap for Command.
