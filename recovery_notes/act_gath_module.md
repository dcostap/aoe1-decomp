# ACT_GATH.cpp source module

- PDB source: `C:\\msdev\\work\\age1_x1\\ACT_GATH.cpp`.
- Source: `src/act_gath.cpp`.
- Header: `include/act_gath.h`.
- Flags: `config/flags/default_gx.rsp`.

## Context gate

The PDB source module is `ACT_GATH.cpp`.

The source-line bands are 63-66, 74-90, 98-110, 116-119, 125-159,
165-377, 383-752, 758-767, 773-780, 786-789, 796-831, and 837-887.

The address sequence is 00402EA0, 00402F40, 00402FD0, 00403020, 00403050,
00403110, 00403590, 00403C60, 00403C90, 00403CD0, 00403CE0, and 00403D90.

The owner is `RGE_Action_Gather`, derived from `RGE_Action`.
The class size is 0x44. The derived field `targetType` starts at +0x40.

The exact anchors are the eight registered owners at 00402EA0, 00402F40,
00402FD0, 00403020, 00403050, 00403C60, 00403C90, and 00403CD0.
The accepted-drift owners are 00403CE0 and 00403D90.
The scratch owners are 00403110 and 00403590.
The compiler-generated vector deleting destructor is at 00402F10.
The derived-to-base destructor thunk is at 00402F30.

## Dependency closure

`act_gath.h` includes the canonical `action.h` owner.

`act_gath.cpp` includes these complete canonical owners:

- `act_list.h` for `RGE_Action_List::delete_list`, `update`, and `add_action`;
- `act_obj.h` for action-object fields and inherited movement methods;
- `m_ac_obj.h` for action-master `work_rate`, `drop_site`, and
  `backup_drop_site`;
- `m_s_obj.h` for master-static `sprite`, `id`, and `attribute_max_amount`;
- `player.h` for player fields and methods;
- `stat_obj.h` for static-object fields and methods;
- `task.h` for task fields, sprites, and sounds;
- `world.h` for `RGE_Game_World::object` and `world_time_delta_seconds`;
- `basegame.h` for the canonical `RGE_Base_Game::quick_build` field;
- `rge_fio.h` for the canonical C++ `rge_read` and `rge_write` symbols;
- `rge_base_game_global.h` for the reviewed `rge_base_game` symbol.
- `act_move.h` for the canonical `RGE_Action_Move_To` owner.
- `sound.h` for the canonical `RGE_Sound::play` owner.

The source uses the canonical `ani_obj.h` through `act_obj.h` and `move_obj.h`.
The source does not use `ani_obj_context.h`.

The canonical `act_move.h` owner now supplies `RGE_Action_Move_To` and its
proven 0x44 size. The source has no local Action or Move_To declaration.

All direct dependencies now close through canonical owner headers. The source
has no local Sound or Base Game declaration.

The source casts an action object's canonical `master_obj` pointer to
`RGE_Master_Action_Object` where the action-master fields are used. It uses
`attribute_max_amount` for the proven +0x7C field. It uses `work_rate` for the
proven +0xE4 field. These casts do not create raw offset overlays.

## Owner table

| VA | Owner | Status |
| --- | --- | --- |
| 00402EA0 | `RGE_Action_Gather::RGE_Action_Gather(int, RGE_Action_Object*)` | matching |
| 00402F30 | `RGE_Action_Gather::~RGE_Action_Gather()` thunk | matching |
| 00402F40 | `RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)` | matching |
| 00402FD0 | `RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object*, RGE_Task*, float, float, float)` | matching |
| 00403020 | `RGE_Action_Gather::save(int)` | matching |
| 00403050 | `RGE_Action_Gather::first_in_stack(unsigned char)` | matching |
| 00403110 | `RGE_Action_Gather::set_state(unsigned char)` | scratch |
| 00403590 | `RGE_Action_Gather::update()` | scratch |
| 00403C60 | `RGE_Action_Gather::get_move_sprite()` | matching |
| 00403C90 | `RGE_Action_Gather::get_wait_sprite()` | matching |
| 00403CD0 | `RGE_Action_Gather::stop()` | matching |
| 00403CE0 | `RGE_Action_Gather::move_to(RGE_Static_Object*, float, float, float)` | accepted_drift |
| 00403D90 | `RGE_Action_Gather::work(RGE_Static_Object*, float, float, float)` | accepted_drift |

No compiler or candidate validation ran in this source-module pass.
