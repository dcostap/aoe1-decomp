# World owner audit

## Evidence

The two oracle copies are identical. Their SHA-256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40` for the
PDB and `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
for the EXE. The PDB source map assigns the World owners to `World.cpp` and
the TRIBE owners to `tworld.cpp`.

Primary evidence:

- `orig/ghidra_decomp/world.cpp.asm` and `world.cpp.decomp`.
- `inventory/pdb/function_source_map.csv`.
- `inventory/types/dumps/RGE_Game_World.txt`, `RGE_Map.txt`, `RGE_Player.txt`,
  `PathingSystem.txt`, `TMousePointer.txt`, and `TRIBE_World.txt`.
- `include/world.h`, `tworld.h`, `pathsys.h`, `Mouseptr.h`, `map.h`, and
  `player.h`.

Generated inventories are reference evidence. The original assembly proves the
call target and decorated ABI.

## Proven layouts

The current six focus headers have these binary layouts:

| Owner | Size | Important fields and offsets |
| --- | ---: | --- |
| `RGE_Game_World` | `0x104` | `map +0x28`; `player_num` `short` +0x3C; `players +0x40`; `master_players +0x48`; `effects +0x4C`; `commands +0x58`; `scenario +0x5C`; `color_tables +0x64`; `random_seed +0x78`; `curr_player` `short` +0x7C; `sound_driver +0x80`; object arrays and counts +0x88..+0x9C; `playbook +0xA0`; campaign values +0xA4..+0xAC; `player_time_delta[9]` +0xB4; reusable lists +0xD8..+0xF0; update budget +0xF4..+0x100. |
| `TRIBE_World` | `0x124` | `tech +0x104`; `victory_type +0x108`; `artifact_count +0x10C`; `ruin_count +0x110`; `countdown_victory` `uchar` +0x114; `countdown_clock` `float` +0x118; `score_displayed` +0x11C; `controllingComputerPlayer` +0x11D; `sent_zone_score +0x120`. |
| `PathingSystem` | `0x11DCF8` | `facetValue[255][255]` +0x0C; `MGP_costValue[255][255]` +0xFE10; `MGP_openPaths[65026]` +0x4F614; `obstructionValue[1020][255]` +0xCE624; `miscValue[255][255]` +0x10DE28; tail state +0x11DC2C..+0x11DCF4. `MGP_FloatHeap` is `uchar x`, `uchar y`, `ushort next`, `int total`, size `0x08`. |
| `TMousePointer` | `0x254` | `cursors[16]` +0x18; six `RECT`s +0xBC..+0x11B; surfaces +0x11C..+0x124; state +0x128..+0x148; `cursor_file[260]` +0x14C; `cursor_file_id` +0x250. |
| `RGE_Map` | `0x8DD0` | `map +0x04`; `map_width` +0x08 and `map_height` +0x0C are four-byte `long` fields; `world_width` +0x10 and `world_height` +0x14; `tilesizes[19]` +0x18; `terrain_types[32]` +0x8C; `border_types[16]` +0x338C; `map_row_offset` +0x8D8C; map flags and managers +0x8D90..+0x8DCC. |
| `RGE_Player` | `0x220` | pathing/checksum state +0x04..+0x20; `master_objects` +0x24; object lists +0x28..+0x30; `world +0x3C`; `doppleganger_creator +0x40`; `name +0x44`; `type +0x48`; `id` `short` +0x4A; attributes +0x50; tile lists +0x58 and +0x6C; relations +0x84; diplomacy arrays +0x88 and +0xAC; masks +0xD0..+0xFC; LOS/allied state +0x100..+0x110; view and selection state +0x114..+0x12C; selected object/list +0x130..+0x198; groups +0x19E. `select_area(short,short,short,short)` is the PDB ABI. |

The current headers omit explicit pad members. That is acceptable here: natural
VC5 alignment produces the observed offsets and the size checks pass. Do not
replace these owners with raw offset classes.

`include/map.h` uses `int` for `map_width` and `map_height` at lines 130-131.
The type dump and donor owner use `long`. Both are four bytes in this ABI, but
`long` is the recovered source type.

## World virtual-slot ABI

The `RGE_Game_World` vtable starts at `0x00577910`. The assembly XREFs identify
slot `0xF0` at `0x00577A00` as `scenario_init(RGE_Game_World*)` and slot
`0xF4` at `0x00577A04` as `scenario_init(int,RGE_Game_World*)`. The overload
implementations are `00541BC0` and `00541B60`.

The PDB source order is pointer form, then integer form. Pinned VC5 reverses
same-name virtual overload entries in this group. The current int-first
declarations in `world.h` and `tworld.h` emit pointer `+0xF0`, then integer
`+0xF4`. This matches the original vtable. Do not reorder these declarations.

The VC5 probe and World, TRIBE, and three registered consumer checks report
`MATCH`, `0.0000%`. `logStatus` is `protected` in the PDB
(`world.cpp.asm`, `00540A10`), and `include/world.h` now keeps it in the
protected section. Access does not alter the decorated name, but it records the
original class surface.

All other World slots are supported by the current declarations: slots 0-39
cover the protected loader/init surface, slots 41-59 cover the public game
surface, and slots 62-63 are `addObject(RGE_Static_Object*)` and
`removeObject(int)`.

## Missing or conflicting owner declarations

These facts block one natural compiler-facing `World.cpp`:

1. `RGE_Player_Info` has no clean owner header. The World body reads
   `name`, `type`, `tribe`, `color`, `player_num`, `scenario`, `map_info`,
   `map_width`, `map_height`, and `campaign`. The PDB layout is `0x2AC`.
   `RGE_Map_Gen_Info` is `0x520`, with `base_terrain` at `+0x00`; World
   reads that field in `new_scenario`. The only current definitions are
   module/context copies, such as `scr_sed.h` and `world_scenario_context.h`.
   The latter uses a raw `void*` or one-field carrier in places. Publish clean
   `RGE_Player_Info` and `RGE_Map_Gen_Info` owners instead.

2. `RGE_Master_Player` has no current canonical header. Its proven size is
   `0x2C`: `name[20] +0x04`, `master_object_num` `short` +0x18,
   `master_objects +0x1C`, `attribute_num` `short` +0x20,
   `attributes +0x24`, `culture +0x28`, `type +0x29`, and
   `tribe_effect` `short` +0x2A. World calls its `FILE*` and `int`
   constructors, `finish_init(int,RGE_Sprite**,RGE_Sound**)`,
   `create_master_object_space(short)`, and
   `load_object(FILE*,uchar,RGE_Sprite**,RGE_Sound**,short)`.
   The PDB owners are `00460FD0`, `004610C0`, `004611D0`, `00461530`, and
   `00461560` in `mst_play.cpp`.

3. Resolved on current main by `fad6eff19`: `include/effects.h` is the
   canonical `RGE_Effects` owner. Its proven size is `0x0C`: vptr +0x00,
   `effects +0x04`, and `effect_num +0x08`. World calls the `int` and
   `char*` constructors. Use this owner, not `effects_context.h`.

4. `TCommunications_Handler` has no clean current owner. World calls
   `GetRandomSeed() -> uint`, `GetPlayerHumanity(int) -> int`,
   `DoCycle(unsigned long) -> int`, and `LastWorldRandom(int) -> void`.
   The complete PDB layout is `0x1774`, but the current definitions are
   context or module fragments. Do not copy one of them into World.cpp.

5. `RGE_Prog_Info` is complete in `include/main.h` and has size `0x1238`.
   It has `scenario_dir[261]` at `+0xC17` and `cmd_line[256]` at `+0x518`.
   `scenario.h`, `gameinfo.h`, and several context headers define conflicting
   partial `RGE_Prog_Info` classes. World uses `rge_base_game->prog_info->scenario_dir`.
   Include the canonical owner and remove the partial competing declarations.

6. `include/basegame.h` owns the `RGE_Base_Game` layout (`0xA24`) but does
   not declare all direct helpers used by World. The PDB proves these exact
   declarations:

   ```cpp
   int multiplayerGame() const;
   int randomGame() const;
   int campaignGame() const;
   int singlePlayerGame() const;
   int playerTeam(int);
   int playerID(int);
   int difficulty();
   int campaign_open_scenario();
   float get_game_speed();
   unsigned char check_prog_argument(char*);
   void write_scenario_header(int);
   void get_campaign_info(long&, long&, long&);
   unsigned char set_campaign_info(long, long, long);
   void set_campaign_win();
   void add_to_timing(int, unsigned long);
   ```

   The const forms use `QBE` PDB symbols. `check_prog_argument` uses `char*`,
   not `const char*`. `get_campaign_info` uses references, not pointer
   parameters. The current `world_context.h` spelling is not a replacement.

7. `include/Command.h` is not safe as a shared owner. It defines partial
   duplicate `RGE_Map`, `RGE_Player`, `RGE_Static_Object`, `RGE_Base_Game`,
   and `TCommunications_Handler` classes before its `RGE_Command` body. The
   PDB proves `RGE_Command` size `0x18`; World needs its constructor,
   `reset_communications(TCommunications_Handler*)`, and `do_commands()`.
   Publish a clean `RGE_Command` owner with forward declarations for foreign
   classes.

8. `include/sprite.h`, `scenario.h`, `gameinfo.h`, and `aipbook.h` also define
   foreign partial owners. They conflict with `basegame.h`, `sound.h`,
   `world.h`, or `stat_obj.h` when combined. This explains why
   `src/world_tu.cpp` still uses `world_context.h`. That wrapper and the
   per-function World wrappers are migration scaffolds, not natural source.

## Direct-call ownership ledger

The direct calls in `orig/ghidra_decomp/world.cpp.asm` resolve as follows:

- `RGE_Map`: both constructors, `new_map`, `load_map`, `save_map`,
  `scenario_load`, `scenario_save`, `save_map`, `load_terrain_obj_types`,
  `clear_map`, `set_map_visible`, and `set_map_fog`. Current `map.h` owns
  these calls. Keep the `RGE_Tile`/`RGE_Object_List` surface typed.
- `RGE_Player`: the two relevant constructor forms, `load_info`,
  `remake_visible_map`, `destroy_objects`, `set_color_table`,
  `set_map_visible`, `set_relation`, `set_allied_victory`, `relation`,
  `victory_if_game_on`, `loss_if_game_on`, and `check_victory`. Current
  `player.h` owns the exact methods. Do not use the donor's incorrect
  `long` spelling for `select_area`; the PDB uses four `short` parameters.
- `RGE_Object_List`: constructor/destructor, `add_node`, `remove_node`,
  `removeAllObjects`, and `update`. `include/obj_list.h` owns the `0x0C`
  list and `0x10` node.
- `RGE_Sound`, `RGE_Sprite`, and `RGE_Color_Table`: current `sound.h`,
  `sprite.h`, and `color.h` own the calls. `sprite.h` still has foreign
  partial `RGE_Sound` and `RGE_Base_Game` declarations, so use a cleaned
  owner set when combining headers.
- `RGE_Scenario` and `RGE_Game_Info`: current `scenario.h` and `gameinfo.h`
  provide the called methods, but both headers carry conflicting partial
  foreign owners. `RGE_Scenario` calls are `update`, `save`,
  `Get_conquest_victory`, `GetPlayerPosture`, `Get_player_AI`, `Get_CityPlan`,
  and `Get_BuildList`.
- `RGE_Master_Player` and `TCommunications_Handler`: use the missing clean
  owners described above. World currently reaches these calls through
  context headers. `RGE_Effects` is resolved by `include/effects.h`.
- `RGE_Doppleganger_Creator`: `include/dpl_obj.h` is the clean current owner.
  World calls `perform_doppleganger_checks()` at `0054310E`; the PDB owner is
  `00442390` in `dpl_obj.cpp`, and the object size is `0x1C`.
- `RGE_Unified_Visible_Map`: `include/visible.h` owns `suppress_updates(int)`.
- `RGE_Static_Object`: `include/stat_obj.h` plus `include/m_s_obj.h` own the
  `id`, `owner`, `master_obj`, `world_x/y/z`, `object_state`, `facet`, and
  `master_type/object_group` reads. The master-object owner is required for
  `objectGroupOnTile` and scenario save filters.
- `PathingSystem`: `include/pathsys.h` owns the globals and calls
  `initialize(int,int,RGE_Map*,RGE_Game_World*)` and
  `zeroObstructionMap()`.
- `TMousePointer`: `include/Mouseptr.h` owns `Poll()`. World calls it at
  `005430BD`.
- `TDebuggingLog`: `include/debuglog.h` owns the vararg `Log(char*,...)` call.
- `RGE_Base_Game`: add the exact direct helper declarations above. The World
  call sites are in `new_game`, `new_scenario`, `check_game_state`,
  `save_scenario`, and `load_scenario`.

No World source or header was changed by this audit. The next migration step is
to publish the missing clean owners, correct the two World overload declarations,
and remove context-header dependencies from the candidate TU.
