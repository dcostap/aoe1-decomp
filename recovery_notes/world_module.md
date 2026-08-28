# World.cpp source migration

`World.cpp` owns 91 normal functions. The PDB maps them to lines 138 through
4056. `RGE_Game_World` remains in `include/world.h`.

`src/world.cpp` holds all 91 bodies in PDB source order. It uses canonical
World, Map, Player, Scenario, Object, Command, and BaseGame owners. It has no
World context include, local class carrier, absolute-address access, or wrapper
include.

`RGE_Player_Info` uses its PDB fields `player_num` and `map_type`. BaseGame
uses `prog_info`. Object-list nodes use `node`. Moving objects provide `angle`.
Scenario version values are source-private strings.

`visible_combats`, `logStatusFile`, and `lastStatusLogTime` are World-only
globals. The source keeps them private. Shared World globals remain in
`game_globals` because other source files use them.

`RGE_Command` comes from its canonical owner, `include/Command.h`. The source
uses canonical GameInfo, Scenario, global, and visible-unit declarations. No
TPlayer surface is required.

The candidate at `build/candidate_tus/world_natural_final/report.json`
compiles with the pinned VC5 toolchain and World flags. It observes all 91
normal owners.
It has no registered exact owner. All rows remain scratch during this structural
migration. Some observed rows match. They do not establish an exact claim.

The prior World wrappers and context headers had duplicate foreign owners.
They are migration scaffolds. The natural source replaces them.
