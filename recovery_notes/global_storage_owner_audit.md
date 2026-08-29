# Canonical global storage audit

## Evidence

The original `age1_x1.pdb` `S_GDATA32` and `S_PUB32` records prove the global
names, linkage, and types. The original listings prove the direct uses and
relocations. Generated inventory is reference evidence only.

## Implemented owners

`include/game_globals.h` declares these process globals. Their definitions are
in `src/game_globals.cpp`.

| Group | Globals | Evidence |
| --- | --- | --- |
| World update | `world_update_counter`, `computerPlayerSetup`, `DVlogf`, `debug_random_on`, `global_save_debug_random_on1`, `global_save_debug_random_on2`, `debug_timeGetTime_on`, `debug_timeGetTime_cnt`, `debug_timeGetTime_time`, `all_cp`, `logStatusOn`, `do_fixed_update`, `fixed_update_time`, `save_game_version`, `allow_user_commands` | `World.cpp` GDATA records and direct World relocations |
| World status | `visible_combats`, `logStatusFile`, `lastStatusLogTime` | `World.cpp` GDATA records at the three adjacent storage records |
| AI controls | `allowAIToCheat`, `useComputerPlayers`, `die_die_die` | BaseGame, TPlayer, TWorld, and screen relocations |
| Visibility | `VIS_UNIT_objectsValue`, `VisibleUnitList`, `VisibleUnitList_Size`, `VisibleUnitManager` | `vis_unit.cpp` and World GDATA records |
| Map visibility | `unified_map_offsets[1024]` | `visible.cpp`, object, view, and map relocations; PDB type `0x1150` |
| Main and BaseGame | `AppInst`, `TRIBE_GUID`, `ZONE_GUID` | BaseGame and WinMain relocations; GUIDs use C linkage |
| Visibility log | `Map_Update_Suppresion`, `VCALL_LOG_HEAD`, `VCALL_LOG_TAIL`, `VCALL_LOG[1024]` | `visible.cpp` GDATA records and direct stores |

`visible_combats` keeps its PDB `short` type. `logStatusFile` keeps its PDB
`FILE*` type. `lastStatusLogTime` keeps its PDB `unsigned long` type. The GUID
objects keep their 16-byte `_GUID` layout and their original C linkage.

The old `World.cpp` static status definitions are removed. The old
`vis_unit.cpp` definitions for the visible-unit result arrays and manager are
removed. The old local declarations for the moved map and visibility globals
are removed. `main.cpp` now uses the PDB names `TRIBE_GUID` and `ZONE_GUID`.
`basegame.cpp` now stores the program instance in `AppInst`.

## Validation

- `004549E0 _WinMain@16`: `MATCH`, `0.0000%`.
- `0041B6A0 RGE_Base_Game`: `MATCH`, `0.0000%`.
- `00540750 RGE_Game_World`: `MATCH`, `0.0000%`.
- `00542ED0 RGE_Game_World::update`: `MATCH`, `0.0000%`.
- `0052E990 TRIBE_World::setup_players`: `MATCH`, `0.0000%`.
- `0053B5A0 Visible_Unit_Manager`: `MATCH`, `0.0000%`.
- `0053B670 Visible_Unit_Manager` destructor: `MATCH`, `0.0000%`.
- `0053BB30`, `0053BBE0`, `0053BD10`, and `0053BFD0` visibility-resource
  owners: `MATCH`, `0.0000%`.
- `0053C3C0`, `0053C400`, `0053C490`, `0053CE80`, and `0053D040` visibility
  owners: `MATCH`, `0.0000%`.
- `0042FA50 RGE_Combat_Object` destructor: `MATCH`, `0.0000%`.
- `00441E00 RGE_Doppleganger_Object::rehook`: `MATCH`, `0.0000%`.
- `004C1D60 RGE_Static_Object::create_object_list`: `MATCH`, `0.0000%`.
- `004C8370 TRIBE_Building_Object::recycle_out_of_game`: `MATCH`, `0.0000%`.

The full standalone builds for `game_globals.cpp`, World, Main, visibility,
combat, doppleganger, static-object, and building-object sources completed.
The full `scr_game.cpp` and one overloaded static-object constructor check stay
blocked by existing class-access and symbol-selection issues. They are not
caused by this storage change.

## Held storage

The PDB proves `NormalLOS`, `SquareLOS`, the edge tables, `pathSystem`, and
`aiPathSystem`. Their current sources use table initialization or placement
construction that needs its original owner. This pass does not move them or
invent a raw-address carrier. Reopen this hold after a source-owner review.

The PDB also proves the fixed `InfluenceMap` objects `iMap`, `losMap`, and
`attackMap`. Their current `taiinfmd.cpp` source uses fixed-address carriers.
This pass leaves them unchanged. A separate natural-object migration must
replace those carriers and validate the three generated initializer owners.
