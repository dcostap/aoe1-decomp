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
| LOS tables | `Edge_Offsets_N0` through `Edge_Offsets_N16`, `Edge_Offsets_T0` through `Edge_Offsets_T16`, `NormalLOS`, `SquareLOS` | `visible.cpp` GDATA records and section contribution; table bytes and pointer relocations match the original |
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

## Natural global objects

The PDB proves `pathSystem` and `aiPathSystem` as complete `PathingSystem`
objects in `pathsys.cpp`. The source now defines both objects with the
original constructor arguments and declaration order. VC5 owns their startup
and destructor-registration helpers. The old placement wrappers are removed.

The PDB proves `iMap`, `losMap`, and `attackMap` as adjacent `0x28`
`InfluenceMap` objects in `taiinfmd.cpp`. The source now defines all three
objects with the original constructor arguments and declaration order. The
old fixed-address carriers and handwritten initializer bodies are removed.

The natural definitions change the old direct initializer boundaries. This is
an accepted structural change for compiler-generated startup code. It does
not change the constructor arguments or source declaration order.

The compiler-generated manifest classifies `0046B060`, `0046B0B0`, `004D6AD0`,
`004D6B20`, and `004D6B70` as static initializers. Their owning source modules
no longer list these entries as ordinary functions.

Natural helper validation maps the direct constructor bodies to the old ranges:
`0046B060` and `0046B0B0` return `MATCH`, `0.0000%`; `004D6AD0`, `004D6B20`,
and `004D6B70` return `MATCH`, `0.0000%`. The surrounding VC5 startup and
destructor-registration helpers remain compiler-generated.

## Fresh WinMain exact-policy audit

The PDB assigns `004549E0` to `main.cpp`, lines 66-192. Its original body is
`004549E0-00454FF0` (1553 bytes). The direct compiler-facing owner is
`src/main.cpp`, registered by the `main` source module.

The standalone check rebuilds `_WinMain@16` and passes owner validation. It
emits 1553 meaningful bytes with no boundary escape or trailing non-padding
body. All 37 relocations are compatible. No actionable relocation target
mismatch exists.

The four direct calls keep their original targets: the VC5 stack-probe alias
`__alloca_probe`/`__chkstk`, `sprintf`, `operator_new`, and the
`TRIBE_Game` constructor. The eight indirect or virtual call sites keep their
slots and order. The function has no tail jump. The grouped `main` candidate
check also passes with `MATCH` and `0.0000%`.

`src/main.cpp` uses the named `RGE_Prog_Info` fields, canonical `TRIBE_Game`
methods, and reviewed `TRIBE_GUID` and `ZONE_GUID` globals. It has no wrapper,
raw address, fake vtable, or compiler-only alias.

## Validation for natural storage

The natural table definitions are in `src/visible.cpp`. The object contains
all 34 table symbols, 7356 data bytes, and 34 pointer relocations. Each table
byte sequence matches its original image range. The full visible candidate
check compiled all 27 PDB owners. Its exact proposal returned 13 of 13 exact
rows. The observed rows returned 6 of 14 matches. The observed mismatches are
existing source drift, not table ownership changes.

The pathsys candidate compiled all 20 ordinary owners. Its 13 exact proposal
rows matched. The seven observed rows had three matches. The taiinfmd
candidate compiled all 121 ordinary owners. It returned 83 matches and 38
existing source mismatches, with no comparison errors.

Fresh exact anchors after the move:

- `0053C3C0`, `0053C400`, `0053C490`, `0053C670`, `0053C6C0`, `0053CE80`,
  `0053CF10`, `0053CFC0`, `0053CFF0`, `0053D040`, `0053D0C0`, `0053D110`, and
  `0053D150`: `MATCH`, `0.0000%`.
- `0053B5A0` `Visible_Unit_Manager`: `MATCH`, `0.0000%`.

The source now owns all five objects naturally. Their ownership and startup
evidence are recorded above.
