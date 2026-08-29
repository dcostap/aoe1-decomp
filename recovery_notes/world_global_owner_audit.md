# World.cpp global owner audit

## Scope

This audit covers the process globals used by the current World composition
scaffolds and by the `World.cpp` oracle. It does not cover class fields.

The evidence is:

- `orig/age1_x1.pdb` global symbols, read with DIA;
- `orig/_original_empiresx_from_beta_that_was_decompiled.exe`;
- `orig/ghidra_decomp/world.cpp.asm`;
- `include/world_context.h`, `include/world_scenario_context.h`, and
  `src/world_phase2_context.h`;
- the current World owner sources.

The PDB global records have the `age1_x1` lexical parent. They do not carry a
source path for the data definition. Therefore, owner rows below are proposals.
The PDB type, address, and World use are facts.

## PDB and binary results

DIA reports `btInt=6`, `btFloat=8`, and `btLong=13`. The PDB reports these
exact data types and storage addresses:

| Global | Storage VA | Exact type | Current canonical owner proposal |
| --- | ---: | --- | --- |
| `world_update_counter` | `00886C10` | `long` | declaration `include/game_globals.h`; definition `src/game_globals.cpp` |
| `computerPlayerSetup` | `00886C18` | `int[13]` (52 bytes) | `include/game_globals.h`; `src/game_globals.cpp` |
| `visible_combats` | `00886C4C` | `short` | `include/game_globals.h`; `src/game_globals.cpp` |
| `logStatusFile` | `00886C50` | `_iobuf*` (`FILE*`) | `include/game_globals.h`; `src/game_globals.cpp` |
| `lastStatusLogTime` | `00886C54` | `unsigned long` | `include/game_globals.h`; `src/game_globals.cpp` |
| `DVlogf` | `00886C58` | `_iobuf*` (`FILE*`) | `include/game_globals.h`; `src/game_globals.cpp` |
| `VIS_UNIT_objectsValue` | `0087D7FC` | `RGE_Static_Object**` | `include/game_globals.h`; `src/game_globals.cpp` |
| `rge_write_error` | `0086B284` | `int` | `include/rge_fio.h`; `src/rge_fio.cpp` |
| `do_fixed_update` | `0062C4E0` | `int` | `include/game_globals.h`; `src/game_globals.cpp` |
| `debug_random_on` | `0062C4D4` | `int` | `include/game_globals.h`; `src/game_globals.cpp` |
| `debug_timeGetTime_on` | `0062C4E8` | `int` | `include/game_globals.h`; `src/game_globals.cpp` |
| `debug_timeGetTime_cnt` | `0062C4EC` | `int` | `include/game_globals.h`; `src/game_globals.cpp` |
| `debug_timeGetTime_time` | `0062C4F0` | `int` | `include/game_globals.h`; `src/game_globals.cpp` |
| `all_cp` | `0062C51C` | `int` | `include/game_globals.h`; `src/game_globals.cpp` |
| `logStatusOn` | `0062C524` | `int` | `include/game_globals.h`; `src/game_globals.cpp` |
| `L` | `0062C4FC` | `TDebuggingLog*` | `include/game_globals.h`; `src/game_globals.cpp` (already present) |
| `MouseSystem` | `0062E660` | `TMousePointer*` | `include/Mouseptr.h`; `src/Mouseptr.cpp` |
| `rge_base_game` | `0062C574` | `RGE_Base_Game*` | `include/game_globals.h`; definition `src/game_globals.cpp` |
| `aiPathSystem` | `0062F348` | `PathingSystem` (size `0x11DCF8`) | `include/game_globals.h`; `src/pathsys.cpp` |
| `pathSystem` | `0074D440` | `PathingSystem` (size `0x11DCF8`) | `include/game_globals.h`; `src/pathsys.cpp` |
| `fixed_update_time` | `0057F9E4` | `long` | `include/game_globals.h`; `src/game_globals.cpp` |
| `save_game_version` | `0058EBCC` | `float` | `include/game_globals.h`; `src/game_globals.cpp` |

`world_update_counter` and `fixed_update_time` are `long` in the PDB. The
current context headers use `int`. The width is the same on this target, but
the declaration is not exact.

`L` already has the reviewed declaration and definition. The reviewed evidence
is `config/shared_abi_evidence.json`. `rge_base_game` has the reviewed
declaration in the shared global header and its definition in
`src/game_globals.cpp`. `rge_write_error` has a declaration in
`include/rge_fio.h`, but no current definition.

`pathSystem` and `aiPathSystem` are real objects. Their PDB `$E9` and `$E14`
initialization entries belong to the `pathsys.cpp` startup sequence. The
source now defines both objects naturally. Do not replace either object with a
pointer, an absolute-dereference macro, or a raw field carrier.

The PDB pointer element records identify `TDebuggingLog`, `RGE_Base_Game`,
`TMousePointer`, and `_iobuf`. The `VIS_UNIT_objectsValue` record is a pointer
to a pointer. Its use and the PDB pointer nesting prove
`RGE_Static_Object**`.

## Direct World consumers

The following list contains direct symbol uses in the PDB-owned
`World.cpp` address range. It excludes calls made only through a World helper.

| Global | Direct World consumers |
| --- | --- |
| `world_update_counter` | `00540750` constructor; `00541EE0` `del_game_info`; `00542360` `load_game`; `00542750` `new_game`; `00542BF0` `new_scenario`; `00542D10` `new_random_game`; `00542ED0` `update`; `00543E00` and `00544090` scenario loaders; `005445C0`, `00544880`, `00544B90`, `00544E70`, `005451A0`, `005454D0`, `00545800` scenario loaders |
| `computerPlayerSetup` | `00542750` `new_game` |
| `debug_timeGetTime_cnt` | `00542750` `new_game` |
| `debug_timeGetTime_time` | `00542750` `new_game` |
| `all_cp` | `00542750` `new_game` |
| `pathSystem` | `00542750` `new_game`; `00546030` `initializePathingSystem` |
| `aiPathSystem` | `00542750` `new_game`; `00546030` `initializePathingSystem` |
| `L` | `00542750` `new_game`; `00542D10` `new_random_game` |
| `rge_base_game` | `005420F0` `load_world`; `00542360` `load_game`; `00542750` `new_game`; `00542ED0` `update`; `005433C0` `check_game_state`; `00543540` `save`; `00543770` `save_game`; `00543A00` `save_scenario`; `00543E00` and `00544090` scenario loaders; `00545CB0` `difficultyLevel`; `005462D0` `update_mutual_allies` |
| `save_game_version` | `005420F0` `load_world`; `00542360` `load_game`; `00543540` `save`; `00543770` `save_game` |
| `rge_write_error` | `00543770` `save_game`; `00543A00` `save_scenario` |
| `VIS_UNIT_objectsValue` | `00540750` constructor; `00540A40` destructor; `00545E00` `addObject` |
| `DVlogf` | `00540750` constructor; `00540A40` destructor; `005462D0` `update_mutual_allies` |
| `debug_random_on` | `00542ED0` `update` |
| `debug_timeGetTime_on` | `00542ED0` `update` |
| `do_fixed_update` | `00542ED0` `update` |
| `fixed_update_time` | `00542ED0` `update` |
| `visible_combats` | `00542ED0` `update` |
| `logStatusOn` | `00542ED0` `update` |
| `lastStatusLogTime` | `00542ED0` `update` |
| `logStatusFile` | `00540A40` destructor; `00542ED0` `update` |

The current `00542750_new_game.cpp` image aliases match the PDB addresses for
`L`, `rge_base_game`, `world_update_counter`, `computerPlayerSetup`,
`debug_timeGetTime_cnt`, `debug_timeGetTime_time`, `all_cp`, `pathSystem`, and
`aiPathSystem`. They are useful address evidence only. They are not suitable
for the natural owner source.

The original `00542ED0` body also reads `DAT_00577A14` at `00543058`. The
original `005420F0` body reads `DAT_00577A10` at `005422FB`. Both are already
owned by `include/game_globals.h` and defined by `src/game_globals.cpp`.

## Version carrier audit

The current context declarations `version_101` through `version_111` do not
match PDB global records. The PDB has no data symbols with those names. The
binary uses static five-byte strings and compares their first four bytes:

| Current carrier | Binary string | Storage VA |
| --- | --- | ---: |
| `version_101` | `"1.01"` | `0058EE18` |
| `version_102` | `"1.02"` | `0058EE10` |
| `version_103` | `"1.03"` | `0057FB90` |
| `version_104` | `"1.04"` | `0057FB88` |
| `version_105` | `"1.05"` | `0057FB80` |
| `version_106` | `"1.06"` | `0057FB78` |
| `version_107` | `"1.07"` | `0057FB70` |
| `version_108` | `"1.08"` | `0057FB68` |
| `version_109` | `"1.09"` | `0057FB60` |
| `version_110` | `"1.10"` | `0057FB58` |
| `version_111` | `"1.11"` | `0057FB50` |

`00543E00` and `00544090` consume the `1.01` through `1.11` values. The
`00543A00` saver writes the `1.10` and `1.11` strings. Do not add integer
carrier globals for these values. Recover the static strings in the natural
source form that preserves the observed loads.

## Result

The following World globals now have one compiler-facing owner:

- `world_update_counter`, `computerPlayerSetup`, `DVlogf`, the debug flags,
  `all_cp`, `logStatusOn`, `do_fixed_update`, `fixed_update_time`,
  `save_game_version`, and `allow_user_commands` use
  `include/game_globals.h` and `src/game_globals.cpp`.
- `visible_combats`, `logStatusFile`, and `lastStatusLogTime` use the same
  declaration and definition. Their old `World.cpp` static definitions are
  removed.
- `allowAIToCheat`, `useComputerPlayers`, and `die_die_die` use the same
  declaration and definition.
- `VIS_UNIT_objectsValue`, `VisibleUnitList`, `VisibleUnitList_Size`,
  `VisibleUnitManager`, and `unified_map_offsets` use the same declaration and
  definition.
- `pathSystem` and `aiPathSystem` use the shared declarations and natural
  definitions in `src/pathsys.cpp`.

The PDB `S_GDATA32` records and the original relocations prove each name and
type. The retained World checks for `00540750` and `00542ED0` report `MATCH`
and `0.0000%`. The old World destructor remains nonexact for an unrelated
cleanup target difference.

The `NormalLOS`, `SquareLOS`, and edge-table storage now has a natural owner in
`src/visible.cpp`. Do not add address aliases for these values.
