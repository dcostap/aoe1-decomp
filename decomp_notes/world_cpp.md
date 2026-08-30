# World.cpp source migration

`World.cpp` owns 91 normal functions. The PDB maps them to lines 138 through
4056. `RGE_Game_World` remains in `include/world.h`.

`src/world.cpp` holds all 91 `World.cpp` bodies in PDB source order.
The header-owned `RGE_Game_World::logStatus(FILE*, int)` body is included by
this module. It uses canonical World, Map, Player, Scenario, Object, Command,
and BaseGame owners. It has no
World context include, local class carrier, absolute-address access, or wrapper
include.

`RGE_Player_Info` uses its PDB fields `player_num` and `map_type`. BaseGame
uses `prog_info`. Object-list nodes use `node`. Moving objects provide `angle`.
Scenario version values are source-private strings.

The owned object-pointer arrays use `new[]` and `delete[]`. No local
allocation or file-open declaration remains.

`visible_combats`, `logStatusFile`, and `lastStatusLogTime` are World-only
globals. The source keeps them private. Shared World globals remain in
`game_globals` because other source files use them.

`RGE_Command` comes from its canonical owner, `include/Command.h`. The source
uses canonical GameInfo, Scenario, global, and visible-unit declarations. No
TPlayer surface is required.

The candidate at `build/candidate_tus/world_exact_final/report.json` compiles
76 registered direct owners with the pinned VC5 toolchain and World flags. All
76 report `MATCH`, `0.0000%`, matching symbols, valid boundaries, and valid
direct relocation targets.

The grouped audit at `build/audits/world_grouped_final/report.json` compiles
all 91 owners. It confirms the 76 registered matches. No matching row remains
scratch.

The remaining 15 rows stay scratch. Five rows have code differences:
`005412B0`, `005415B0`, `005420F0`, `00542BF0`, and `005462D0`. Ten rows have
boundary escapes: `00540A40`, `005414A0`, `00541B60`, `00541BC0`, `00541C20`,
`00541C90`, `00542480`, `00542750`, `00543E00`, and `00544090`.

The prior World wrappers and context headers had duplicate foreign owners.
They are migration scaffolds. The natural source replaces them.

## Header-owner closure

The header-owned `00540A10` body is now only in `include/world.h`, under its
PDB-proven protected access. The direct World candidate emits
`?logStatus@RGE_Game_World@@MAEXPAU_iobuf@@H@Z` and reports `MATCH`, `0.0000%`,
with no relocation mismatch or boundary escape. The 76 registered World
owners also remain exact.
