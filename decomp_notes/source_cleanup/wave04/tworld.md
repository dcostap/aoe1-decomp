# `tworld.cpp` source-cleanup report

## Delivery

- Module: `src/tworld.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final prior report commit: `cad41fd0133f640144cb7cfb774f39c4a12be364`
- Prior correction source commit: `72fe153494f42409f66797cd6fbd39e68422e8eb`
- Prior correction report commit: `cb00ce396f9b2a5bc0ad4cf9a1f6ee323607248a`
- Final brace correction commit: `b1a138720126836367f4271ad44a589e8fdc7c53`
- Report commit: pending until this correction report is committed
- Changed files:
  - `src/tworld.cpp`
  - `decomp_notes/source_cleanup/wave04/tworld.md`
- PDB source: `C:\\msdev\\work\\age1_x1\\tworld.cpp`
- Registry: `config/functions/src/tworld.cpp.json`
- Header owner: group owner 26 owns `include/tworld.h`.

The prior source commit contains only the assigned source. This correction
commit contains only the assigned source. This report is a separate
assigned-file commit.

## Evidence checked

I inspected all 30 registered procedures in source and address order. The
procedure-scoped records came from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  - SHA256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
  - SHA256 `aead4dde6d2839dbd667e0c2d1a2f266ca19c8e559ae23757c969c4c443de8b8`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`
  - SHA256 `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

The scoped inventory was generated from `cvdump -s`. Every assigned procedure
has an `ecx` register record named `this`.

I also inspected the original executable references:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tworld.cpp.asm`
  - SHA256 `c260f98faf46bc41852d2dee274a70cd92cf68ea23a5dc59050c339ec4510b63`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tworld.cpp.decomp`
  - SHA256 `1f39110d918b3b967b14c773178d93957f027f682e3ac37a659f6fc20f8540ad`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Complete PDB coverage and name recovery

The table lists every assigned procedure. It lists all scoped PDB names that
were recorded for the procedure. The repeated offsets in the PDB are noted
below the table.

| VA | Function | PDB parameters and locals |
| --- | --- | --- |
| `0052DF60` | `TRIBE_World::TRIBE_World` | no stack names |
| `0052E040` | `TRIBE_World::~TRIBE_World` | no stack names |
| `0052E0B0` | `logStatus` | `out`, `firstTime`, `clock`, `tempString` |
| `0052E220` | `data_load_players_type` | `id`, `type`, `infile` |
| `0052E2B0` | `data_load_map` | `border_file`, `overlay_file`, `terrain_file`, `map_file`, `tile_width`, `tile_height`, `elev_height`, `sounds`, `terr_obj_file` |
| `0052E350` | `data_load_world` | `infile`, `tech_file` |
| `0052E400` | `init_player_type` | `infile`, `index`, `type` |
| `0052E4C0` | `map_init` | `infile`, `sound_dvr` |
| `0052E530` | `command_init` | `infile`, `com_hand` |
| `0052E590` | `scenario_init(int, RGE_Game_World*)` | `infile`, `world` |
| `0052E5F0` | `scenario_init(RGE_Game_World*)` | `world` |
| `0052E650` | `effects_init` | `infile` |
| `0052E6B0` | `world_init` | `infile`, `sound_dvr`, `com_hand` |
| `0052E750` | `init` | `base_name`, `sound_dvr`, `com_hand` |
| `0052E770` | `base_save` | `outfile` |
| `0052E790` | `save` | `outfile` |
| `0052E830` | `load_player` | `infile`, `type`, `index` |
| `0052E920` | `setup_gaia` | no stack names |
| `0052E990` | `setup_players` | `info` |
| `0052EAC0` | `check_destructables` | `player_id`, `obj_id`, `col`, `row`, `delete_flag`, `x2`, `x1`, `ry`, `rx`, `ry2` |
| `0052ECF0` | `scenario_make_player` | `index`, `player_type`, `info_type`, `master_player_id`, `name` |
| `0052EDF0` | `load_world` | `infile1` |
| `0052EF30` | `new_game` | `info`, `myPlayerNum`, `ret_num`, `str3`, `description`, `str2`, `str1`, `victoryAmount` |
| `00530370` | `new_scenario` | `info`, `random_seed_in` |
| `005303F0` | `check_game_state` | `player_count`, `team_score`, `j`, `i`, `team_count`, `player_team`, `team_player`, `team_size`, `held_time` |
| `00530A70` | `get_achievement` | `achievement`, `info` |
| `00530AC0` | `send_cheat` | `cheat_code` |
| `00530AE0` | `cheat` | `player`, `cheat_code` |
| `00531240` | `fill_in_score` | `info`, `score_group`, `hi_player`, `count` |
| `00531350` | `send_zone_score_info` | `index`, `info`, `count`, `options` |

I restored these original PDB names in the source:

- `logStatus`: `stream` to `out`; `verbose` to `firstTime`.
- `data_load_players_type`: `p1`, `p2`, and `f` to `id`, `type`, and `infile`.
- `data_load_map`: `p1` through `p9` to the nine recorded file and dimension names.
- `data_load_world`: `f` to `infile`.
- `init_player_type`: `player` to `infile`.
- `map_init`: `param_1` and `param_2` to `infile` and `sound_dvr`.
- `command_init`: `unused` and `handler` to `infile` and `com_hand`.
- Both `scenario_init` overloads: `param_1` and `param_2` to `world` and
  `infile` as recorded by each overload.
- `effects_init`: `param_1` to `infile`.
- `world_init`: `param_1`, `sound`, and `comm` to `infile`, `sound_dvr`, and
  `com_hand`.
- `init`: `file`, `sound`, and `communications` to `base_name`, `sound_dvr`,
  and `com_hand`.
- `base_save` and `save`: the handle parameter to `outfile`.
- `load_player`: `player` and `player_id` to `infile` and `index`.
- `check_destructables`: `master_id`, `x`, `y`, and `flag` to `obj_id`, `col`,
  `row`, and `delete_flag`.
- `scenario_make_player`: `player_id`, `type`, `civ`, `master_id`, and
  `player_info` to `index`, `player_type`, `info_type`, `master_player_id`,
  and `name`.
- `load_world`: `handle` to `infile1`.
- `new_scenario`: `flags` to `random_seed_in`.
- `check_game_state`: the inner loop names `ally` and `player` to the PDB
  spelling `j`.
- `get_achievement`: `achievement_id` and `buffers` to `achievement` and
  `info`.
- `send_cheat`: `code` to `cheat_code`.
- `fill_in_score`: `group` to `score_group`.
- `send_zone_score_info`: `computer_players` and `player` to `count` and
  `index`.

These are recovered original names. I did not rename public functions, class
members, globals, or ABI symbols. The current `map_row` loop name is a new
cleanup name. It prevents the restored `row` parameter from being shadowed by
the map-row loop.

In `scenario_make_player`, the positional uses remain those of the base
source. Position 2, named `player_type`, supplies `master_players[...]` and
the constructor argument. Position 3, named `info_type`, controls the `0` and
`4` tests. Position 4, named `master_player_id`, remains unused. This avoids a
semantic change during parameter renaming.

The PDB records `x1` and `x2` in `check_destructables` at parameter-home
offsets. It also records `rx`, `ry`, and `ry2` at slots that the assembly uses
for different values. I did not map those names onto `x_min`, `y_min`,
`x_max`, `y_max`, `radius_x`, `radius_y`, `object_radius_x`, `object_radius_y`,
`dx`, or `dy`.

The PDB records `j` and `held_time` at one reused slot in `check_game_state`.
The current source has scoped loop declarations. I restored `j` for the
inner alliance and team-member loops without changing their scopes.

The PDB records `index` and `count` at one reused slot in
`send_zone_score_info`. Their uses identify `index` as the player index and
`count` as the computer-player count. The PDB records both as `long`; the
existing source uses `int`. I preserved the existing types in this naming pass.

The PDB has no direct records for several current locals, including `pb`, `m`,
`p`, `s`, `e`, `g`, `player` in `setup_players`, and the descriptive locals in
`new_game`. I kept those names and did not force stack-slot mappings. The
`new_game` PDB records match the existing `ret_num`, `str1`, `str2`, `str3`,
`description`, and `victoryAmount` declarations.

## Constants, resources, comments, and formatting

I reused existing shared resource macros. The source now includes
`include/resource_ids.h` and uses:

- `IDS_BUTTON_YES` for resource ID `0x0FA3`.
- `IDS_BUTTON_NO` for resource ID `0x0FA4`.
- `IDS_PATH_FINDING_OPTION_BASE` for base ID `0x260E`.

The existing macros preserve the original integer values and expression types.
I did not define a new resource macro.

I inspected the actual runtime lookup path. `TRIBE_Game::setup` loads
`languagex.dll` by default. `TRIBE_Game::get_string` tries that module first,
then calls the base-game lookup when `LoadStringA` returns zero. The relevant
source is `src/tribegam.cpp` lines 388-406 and 812-818.

The resource tool was `tools/inspect_pe_strings.py`. Its extraction output is
under the worker build directory:

- `build/resource-strings/tworld-language.json`.
- `build/resource-strings/tworld-logstatus-language.json`.
- `build/resource-strings/tworld-languagex.json`.
- `build/resource-strings/runtime-languagex-all.json`.
- `build/resource-strings/pinned-languagex-all.json`.
- `build/resource-strings/pinned-map-slots.json`.
- `build/resource-strings/pinned-map-types.json`.

All present entries below use language `0x0409`. The runtime base module is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/language.dll`
- SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.

Its exact text is:

- `0x0FA3` `Yes`; `0x0FA4` `No`.
- `0x1069` `Stone Age`; `0x106A` `Tool Age`; `0x106B` `Bronze Age`;
  `0x106C` `Iron Age`; `0x106E` `Nomad`; `0x10E7` `Default`.
- `0x25B6` `Map Type: %s`; `0x25B8` `Reveal Map: %s`;
  `0x25BB` `Enable Cheating: %s`; `0x25DA` `Map Size: %s`;
  `0x25E0` `Difficulty Level: %s`; `0x25E4` `Age: %s`;
  `0x25E5` `Resources: %s`; `0x25E6` `Low`; `0x25E7` `Medium`;
  `0x25E8` `High`; `0x25E9` `Fixed Positions: %s`;
  `0x25EC` `Full Tech Tree: %s`; `0x25F0` `Population Limit: %d`;
  `0x25F1` `Path Finding: %s`.
- `0x260E` `Default`; `0x260F` `Medium`; `0x2610` `High`.
- `0x265C` standard-game description; `0x265D` time-limit description;
  `0x265E` score-game description; `0x265F` conquest-game description.
- `0x296A` `Small Islands`; `0x296B` `Large Islands`; `0x296C` `Coastal`;
  `0x296D` `Inland`; `0x296E` `Highland`.
- `0x296F`, `0x2970`, and `0x2971` are empty slots.
- `0x2972` is `******* SIZE *******`; `0x2973` `Tiny`; `0x2974` `Small`;
  `0x2975` `Medium`; `0x2976` `Large`; `0x2977` `Huge`; `0x2978` is empty.
- `0x2BD0` `Hardest`; `0x2BD1` `Hard`; `0x2BD2` `Moderate`;
  `0x2BD3` `Easy`; `0x2BD4` `Easiest`; `0x2BD5` `Up`; `0x2BD6` `Down`;
  `0x2BD7` through `0x2BD9` are empty slots.
- `0x28A6`, `0x28A7`, `0x28AD`, `0x28AE`, and `0x28AF` are empty slots.

The actual runtime override is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/languagex.dll`
- SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.

For language `0x0409`, it has these exact entries:

- `0x296F` `Continental`; `0x2970` `Mediterranean`; `0x2971` `Hill Country`;
  `0x2972` `Narrows`; `0x2978` `Gigantic`.
- `0x296A` through `0x296E` are empty slots.
- `0x2973` through `0x2977` are empty slots.

The override has missing blocks for every other inspected ID:
`0x0FA3`, `0x0FA4`, `0x1069`-`0x106C`, `0x106E`, `0x10E7`,
`0x25B6`, `0x25B8`, `0x25BB`, `0x25DA`, `0x25E0`, `0x25E4`-`0x25E9`,
`0x25EC`, `0x25F0`, `0x25F1`, `0x260E`-`0x2610`, `0x265C`-`0x265F`,
and `0x28A6`, `0x28A7`, `0x28AD`, `0x28AE`, `0x28AF`, `0x2BD0`-`0x2BD9`.
The base lookup supplies the nonempty text for those IDs. Base empty slots
remain empty.

The pinned original override is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
- SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

For language `0x0409`, its exact entries are the same map override entries:
`0x296F` `Continental`, `0x2970` `Mediterranean`, `0x2971` `Hill Country`,
`0x2972` `Narrows`, and `0x2978` `Gigantic`. It has empty slots at
`0x296A`-`0x296E` and `0x2973`-`0x2977`. It has missing blocks for every
other inspected ID listed above. The runtime and pinned override hashes differ,
but the inspected entries have the same results.

The resource purpose is established by the `TRIBE_Game` enums and the switches
in `new_game`, plus the `victoryType()`, `mapSize()`, and `mapType()` calls in
`logStatus`. I did not replace numeric IDs whose shared names are not yet
approved.

Please add these proposed shared mappings to `include/resource_ids.h` in the
root-owned resource namespace. These are new cleanup names, not recovered
original macro names:

- Victory descriptions: `0x265C` standard, `0x265D` time limit, `0x265E`
  score, and `0x265F` conquest.
- Victory condition log labels: `0x28A6` default, `0x28A7` conquest,
  `0x28AD` time, `0x28AE` score, and `0x28AF` standard. Their runtime text is
  empty or missing, but the enum and lookup arithmetic establish their roles.
- Map-type text range: `0x296A`-`0x2972`, with names for Small Islands,
  Large Islands, Coastal, Inland, Highland, Continental, Mediterranean,
  Hill Country, and Narrows.
- Map-size text range: `0x2973`-`0x2978`, with names for Tiny, Small, Medium,
  Large, Huge, and Gigantic.
- Format IDs: `0x25B6` map type, `0x25B8` reveal map, `0x25BB` cheating,
  `0x25DA` map size, `0x25E0` difficulty, `0x25E4` age, `0x25E5` resources,
  `0x25E9` fixed positions, `0x25EC` full tech tree, `0x25F0` population
  limit, and `0x25F1` path finding.
- Age and resource text: `0x1069`-`0x106C`, `0x106E`, `0x10E7`, and
  `0x25E6`-`0x25E8`.
- Difficulty text range: `0x2BD0`-`0x2BD4` only. The inspected `0x2BD5`-
  `0x2BD6` entries are `Up` and `Down`, and `0x2BD7`-`0x2BD9` are empty.
  The source does not prove those entries are valid difficulty values.

Please update `include/tworld.h` with a declaration-name-only change for owner
26. Its declarations omit parameter names. Add the PDB names from the table to
all declarations that have parameters:

```cpp
void logStatus(FILE* out, int firstTime);
void data_load_players_type(short id, short type, FILE* infile);
void data_load_map(char* border_file, char* overlay_file, char* terrain_file,
                   char* map_file, short tile_width, short tile_height,
                   short elev_height, RGE_Sound** sounds, char* terr_obj_file);
unsigned char data_load_world(FILE* infile);
unsigned char init_player_type(int infile, short index, unsigned char type);
void load_player(int infile, unsigned char type, short index);
void setup_players(RGE_Player_Info& info);
void save(int outfile);
void scenario_make_player(short index, unsigned char player_type,
                          unsigned char info_type,
                          unsigned char master_player_id, char* name);
unsigned char init(char* base_name, TSound_Driver* sound_dvr,
                   TCommunications_Handler* com_hand);
unsigned char load_world(int infile1);
unsigned char new_game(RGE_Player_Info& info, int myPlayerNum);
unsigned char new_scenario(RGE_Player_Info& info, int random_seed_in);
void base_save(int outfile);
void scenario_init(int infile, RGE_Game_World* world);
void scenario_init(RGE_Game_World* world);
long get_achievement(unsigned char achievement, char** info);
void send_cheat(short cheat_code);
void cheat(short player, short cheat_code);
void fill_in_score(TRIBE_Zone_High_Score_Info& info, long score_group);
```

Also add `infile` and `sound_dvr` to `map_init`, `infile` and `com_hand` to
`command_init`, `infile` to `effects_init`, and `infile`, `sound_dvr`, and
`com_hand` to `world_init`. These edits do not change types, layouts, calling
conventions, decorated names, or interfaces.

The existing comment in `check_destructables` records the proven `+3.0` and
`-3.0` constants. I kept it. I added no new behavior comment. Function
braces now use 1TBS placement, and I fixed one existing indentation error.
No executable statement or declaration moved.

This correction restores the baseline nested scope around `case 101` in
`cheat`. The prior 1TBS conversion removed the closing brace before its
`break`, which left `case 102` inside the `case 101` block. The closing brace
is now present before the break. The `case 100` closing brace remains before
`case 101`, and `case 102` remains at switch scope. Only brace placement and
scope tokens changed.

## Code-generation and validation limits

The edits change parameter and local identifiers, one include, two existing
resource macro spellings, brace placement, indentation, and wrapping. They do
not change public symbols, function boundaries, control flow, expression order,
casts, storage, field layout, or call targets. The new macro spellings expand
to the original values. The restored `row` parameter required the new
`map_row` local name to keep the existing expression target unchanged.

Compilation, matching, audits, and tests were not run. I did not run a build,
validation command, or game. I reviewed the complete Git diff and ran only
non-build evidence inspection and `git diff --check`.
