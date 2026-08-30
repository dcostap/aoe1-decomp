# tact_wnd.cpp source reunification

## Result

The source module now has one compiler-facing owner at `src/tact_wnd.cpp`.
The definitions follow PDB source order. The former context header and source
fragments are removed.

The final grouped candidate compiles after Base Game published its countdown
methods. The three matching owners remain exact. The scratch owners stay
scratch pending a separate promotion review.

## PDB order and status

The PDB source is `C:\\msdev\\work\\age1_x1\\tact_wnd.cpp`.

| VA | PDB lines | owner | status |
| --- | ---: | --- | --- |
| `004D3470` | 35-37 | `TRIBE_Action_Wonder::TRIBE_Action_Wonder(int, RGE_Action_Object*)` | matching |
| `004D34C0` | 42-45 | `TRIBE_Action_Wonder::TRIBE_Action_Wonder(RGE_Action_Object*)` | matching |
| `004D34F0` | 50-97 | `TRIBE_Action_Wonder::~TRIBE_Action_Wonder()` | scratch |
| `004D3690` | 101-104 | `TRIBE_Action_Wonder::first_in_stack(unsigned char)` | matching |
| `004D36B0` | 108-148 | `TRIBE_Action_Wonder::set_state(unsigned char)` | scratch |
| `004D3810` | 152-179 | `TRIBE_Action_Wonder::update()` | scratch |

The nearby vector-deleting destructor is compiler generated. It has no
handwritten source owner.

## Canonical ownership

`include/tact_wnd.h` uses the reviewed owner headers:

- `action.h` for `RGE_Action`;
- `act_list.h` for action lists and action nodes;
- `act_obj.h` for `RGE_Action_Object`;
- `stat_obj.h` for `RGE_Static_Object`;
- `m_s_obj.h` for `RGE_Master_Static_Object`;
- `m_ac_obj.h` for the master action-object owner;
- `move_obj.h` for the moving-object base;
- `world.h` for `RGE_Game_World`;
- `obj_list.h` for `RGE_Object_List` and `RGE_Object_Node`;
- `player.h` for `RGE_Player`;
- `basegame.h` and `rge_base_game_global.h` for Base Game ownership.

The module header declares only `TRIBE_Action_Wonder`. It adds no data,
shared base, fake slot, raw vptr write, or copied foreign class.

`tact_wnd.cpp` does not use a concrete scenario object. `basegame.h` supplies
its canonical `RGE_Scenario` and `RGE_Scenario_Header` forwards. Including
`scenario.h` here would add its competing minimal `RGE_Base_Game` declaration.

The old list scan used local `RGE_Action_List`, `RGE_Action_Node`, and
`action_list` names. The canonical scan uses `RGE_Player::objects`,
`RGE_Object_List::list`, and `RGE_Object_Node::node`. The master id comes from
`RGE_Master_Static_Object::id`. The world checks use canonical
`game_end_condition` and `world[1].world_time` fields.

## Final grouped result

`include/basegame.h` now owns `reset_countdown_timer(long)` and
`set_countdown_timer(long, long)`. The module uses those declarations directly.

The final candidate reports `MATCH` for constructors `004D3470` and `004D34C0`
and `first_in_stack` `004D3690`. Scratch `004D36B0 set_state` and `004D3810
update` also rebuild exactly. Scratch `004D34F0` destructor differs by 178
bytes and has two boundary escapes. No scratch owner is promoted in this pass.

## Files

- Added `include/tact_wnd.h`.
- Added `src/tact_wnd.cpp`.
- Added `config/functions/src/tact_wnd.cpp.json`.
- Added `decomp_notes/tact_wnd.md`.
- Recorded the unified source in the function registry.
- Removed `include/tact_wnd_context.h`.
- Removed `src/tact_wnd_tu.cpp` and six source-bank fragments.
