# Terra 4 handoff: World Scenario and GameInfo owners

Version: 1
Date: 2026-08-27
Status: blocked; audit only

## Scope

This note audits the `World.cpp` candidate. It does not change World headers or
sources. It does not define a substitute ABI surface.

## Facts: canonical owners

| Type | PDB/original evidence | Repository owner |
| --- | --- | --- |
| `RGE_Scenario` | `inventory/classes/dumps/RGE_Scenario.txt:1-3` names donor `src\\game\\include\\RGE_Scenario.h`; `inventory/types/dumps/RGE_Scenario.txt` proves size `0x1990`. | Header: `include/scenario.h`; source: `src/scenario.cpp`; manifest: `config/source_modules/scenario.json`. |
| `RGE_Scenario_Header` | `inventory/classes/dumps/RGE_Scenario_Header.txt:1-3` names donor `src\\game\\include\\RGE_Scenario_Header.h`; `inventory/types/dumps/RGE_Scenario_Header.txt` proves size `0x14`. | Header: `include/scenario.h`; source: `src/scenario.cpp`. |
| `RGE_Game_Info` | `inventory/types/dumps/RGE_Game_Info.txt` proves the six fields and size `0x118`; `inventory/pdb/function_source_map.csv:2012-2029` maps its methods to `gameinfo.cpp`. | Header: `include/gameinfo.h`; source: `src/gameinfo.cpp`; manifest: `config/source_modules/gameinfo.json`. |
| `RGE_Game_World` | `inventory/types/dumps/RGE_Game_World.txt` proves size `0x104` and `scenario` at `+0x5C`; World functions map to `World.cpp` in the PDB source map. | Header: `include/world.h`; current World candidates are `src/world_tu.cpp`, `src/world_scenario_tu.cpp`, and `src/world_cpp_phase2_tu.cpp`. |

`RGE_Scenario` has four shipped virtual slots. Its first slot is protected
`get_object_pointer`; the next slots are the destructor, `rehook`, and `save`.
The current `include/scenario.h` publishes those slots and the complete fields.

`RGE_Game_Info` is a non-virtual `0x118`-byte class. The World update owner
`00542ED0` calls `player_game_info->get_current_player_name()`.

## Facts: direct World conflicts

The current World candidate uses noncanonical context declarations:

| Path | Foreign declaration | Conflict |
| --- | --- | --- |
| `include/world_context.h:315` | `RGE_Scenario` shell | It repeats the type with only a partial field and method surface. |
| `include/world_context.h:575` | `RGE_Game_Info` one-method shell | It repeats the complete `RGE_Game_Info` type and omits its `0x118` layout. |
| `include/world_scenario_context.h:335` | `RGE_Scenario` shell | It repeats the type with a partial field and method surface. |
| `include/world_scenario_context.h:578` | `RGE_Game_Info` shell with two virtual methods | It gives `RGE_Game_Info` a false vtable and conflicts with the non-virtual PDB type. |
| `src/world_phase2_context.h:362` | `RGE_Scenario` shell | It repeats the type with a partial field and method surface. |
| `src/world_phase2_context.h:643` | `RGE_Game_Info` one-method shell | It repeats the complete `RGE_Game_Info` type and omits its layout. |

The three context headers use the same include-guard token. The first context
seen by a candidate controls which foreign declaration wins. `src/world_tu.cpp:20`
selects `include/world_context.h`; `src/world_cpp_phase2_tu.cpp:9` selects
`src/world_phase2_context.h`; the individual World fragments select
`include/world_scenario_context.h`.

The World bodies that need a complete `RGE_Scenario` are:

- `00540A40` destructor, which deletes `scenario`;
- `00541B60` and `00541BC0`, which allocate `RGE_Scenario`;
- `00542ED0`, `005433C0`, `00543540`, and `00543A00`, which call Scenario methods;
- `00544300`, `005445C0`, `00544880`, `00544B90`, `00544E70`, `005451A0`,
  `005454D0`, and `00545800`, which call Scenario getters.

`00542ED0` is the only current World body that needs a complete
`RGE_Game_Info`; it calls `get_current_player_name()` through the base-game
`player_game_info` field.

## Facts: other foreign Scenario and GameInfo definitions

These definitions are not canonical owners and conflict when composed with the
canonical headers. Forward declarations are not listed as conflicts.

### `RGE_Scenario`

- `include/scr_sed.h:462`
- `include/tplayer_context.h:244`
- `include/tpnl_obj.h:567`
- `include/tscenaro.h:123`
- `src/basegame_candidate_context.h:83`
- `src/matching/0048B580_get_object_pointer.cpp:1`
- `src/matching/0048B590_rehook.cpp:1`
- `src/matching/0052E0B0_logStatus.cpp:26`
- `src/matching/00531350_send_zone_score_info.cpp:562`
- `src/scratch/0052EF30_new_game.cpp:154`
- `src/scratch/005303F0_check_game_state.cpp:84`

The two `tworld.cpp` definitions (`0052E0B0` and `00531350`) are separate
foreign surfaces. They are not proof that `World.cpp` may use a reduced
Scenario class.

### `RGE_Scenario_Header`

- `include/tscenaro.h:190`
- `src/basegame_candidate_context.h:72`
- `src/sceninfo_tu.cpp:32`
- `src/matching/0048CFD0_RGE_Scenario_File_Info.cpp:12`
- `src/accepted_drift/0048D040_save.cpp:45`
- `src/accepted_drift/0048D0E0_reload_scenarios.cpp:67`

These copies belong to old or private `sceninfo` and candidate contexts. They
must not enter the World candidate.

### `RGE_Game_Info`

- `include/taiinfmd.h:1145` (the tag is `struct`, unlike the canonical class)
- `src/basegame_candidate_context.h:53`
- `include/world_context.h:575`
- `include/world_scenario_context.h:578`
- `src/world_phase2_context.h:643`

`include/gameinfo.h` also declares foreign support surfaces. Its declarations
for `rge_read`, `rge_write`, `rge_open`, and `rge_close` conflict with the
canonical `include/rge_fio.h` signatures. Its local `RGE_Campaign` shell at
line 28 conflicts with the campaign owner in `include/campaign_context.h:24`.
These are GameInfo header cleanup blockers, not reasons to change the World
layout.

## Minimum World-facing declarations and include edges

The following is the smallest source-composition model supported by current
uses. It is a handoff recommendation, not a claim about the historical include
file names.

1. Keep `RGE_Game_World` in `include/world.h`. Keep only its forward
   `class RGE_Scenario` for the `scenario` field and Scenario-returning method.
2. Let the grouped World source include the canonical `include/scenario.h`
   before the owners listed above. This supplies the complete `RGE_Scenario`
   layout, constructors, destructor, `save`, `update`, `Get_conquest_victory`,
   `Get_BuildList`, `Get_CityPlan`, `Get_player_AI`, and `GetPlayerPosture`.
3. Let `00542ED0` see the canonical `include/gameinfo.h` declaration. A
   module-level include is sufficient for a grouped source, but `world.h` does
   not need to include `gameinfo.h` because it stores no GameInfo object.
4. Keep `RGE_Base_Game` in `include/basegame.h`. Its
   `RGE_Game_Info* player_game_info` field needs only a forward declaration in
   the public World header. Include `gameinfo.h` only where a World body
   dereferences that pointer.
5. Replace the three World context edges with canonical owner edges during the
   later source migration. Do not add a World-specific Scenario or GameInfo
   shell. Do not add an alias, cast, raw layout, or compatibility header.
6. Clean `include/gameinfo.h`'s foreign I/O and campaign declarations before
   composing it with the canonical World dependency set. Use
   `include/rge_fio.h` and the reviewed campaign owner instead.

The PDB proves the layouts and owner source modules. It does not prove that a
single historical header contained all declarations. The include-edge plan
above is therefore a source-composition hypothesis that preserves those facts.

## Handoff decision

Terra 4 should first remove the noncanonical Scenario and GameInfo surfaces from
the World composition plan. World exactness work should resume only after the
canonical headers compose without duplicate type definitions.
