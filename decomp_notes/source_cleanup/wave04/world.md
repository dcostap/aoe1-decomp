# `src/world.cpp` source cleanup

## Delivery

- Branch: `cleanup/staging-20260915-227` (`slot-227`)
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source owner: `src/world.cpp`
- Changed files: `src/world.cpp`, this note
- Previous source cleanup commit: `79849d74ecf5ec1c5fa84cd08d1c38b4169b65c5`
- Previous report commit: `b659e2e1d9e1a92e8e7fb95c64329346896a0562`
- Correction commit: `a76d02bdb0e6470c6906f7c1b032a43adc693db5`
- Reviewer correction: `load_scenario6` keeps the baseline declaration `int index, j;`.
- Headers changed: none

This correction keeps base declaration types, scope, storage, order, and
grouping. It changes names and local presentation only.

The correction also applies 1TBS and four-space indentation to the module.
It does not change public signatures, layouts, globals, file formats, calls,
or control flow.

## Evidence

The procedure evidence is the World.obj PDB record set:

- PDB source: `C:\msdev\work\age1_x1\World.cpp`
- Module: `Release\World.obj`
- Extracted record table: `build/world-cleanup-evidence/world-pdb.tsv`
- Source record set: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The table has 93 World.obj procedure records. The source has 91 natural World
bodies. The extra records are the scalar deleting destructor and the
header-owned `logStatus` body. Each source body in this module was checked
against its procedure record. The records supplied parameter and local names,
types, and stack offsets.

The main recovered PDB names are:

- Loaders: `flag`, `file_name`, `id`, `index`, `count`, `index3`, `type`,
  `infile`, `base_name`, `world_info`, `sound_dvr`, `com_hand`, `world`, and
  `infile1`.
- World state: `tempGameState`, `name`, `new_speed`, `info_player_num`,
  `colors_used`, `players_done`, `myPlayerNum`, `team`, `randomString`,
  `random_seed_in`, `time`, `fileName`, `games_won`, `games_lost`, and
  `games_on`.
- Save and scenario code: `outfile`, `filename`, `scenario`, `header_size`,
  `version`, `tempname`, `scenario_name`, `kill_name`, `scenario_player_num`,
  `infile`, `player_type`, `info_type`, `master_player_id`, `rem`, `world_x`,
  `world_y`, `world_z`, `obj_id`, `obj_state`, `obj_angle`, `master_id`,
  `player_id_hash`, `index`, `count`, and `id`.
- Object and recycle code: `cPType`, `usedTime`, `ownerID`, `groupID`, `x`,
  `y`, `objectCount`, `filename`, `oID`, `newObject`, `lookupSlot`,
  `object_type`, and `obj`.
- Mutual-ally logging: `index` and `pNum`.

The names above are recovered originals where the scoped PDB record supplies
that name. Names such as `color_index`, `max_iter`, `map`, `negative_index`,
`max_negative_objects`, and `player_index` are new descriptive cleanup names.
They have no PDB claim. Existing short locals remain where stack reuse or
optimized register ownership does not prove a source name.

`data_load_objects` has both `type` and `player` entries in the PDB record.
The optimized body maps the loop state to a register while the scoped stack
record also reports `type`. The source keeps the proven `type` use and does
not force the uncertain `player` mapping.

The scenario loaders use PDB names only where the declaration mapping is
reliable. They keep the base declaration types, order, scope, and storage.
The wrapper functions keep their base `file` locals because their scoped
records do not prove a better local name.

## Owner 26 declaration request

Owner 26 owns `include/world.h`. Add these parameter names only. Keep every
type, order, virtual slot, overload, and ABI declaration unchanged:

- `data_load_world(infile)`, `data_load_terrain_tables(file_name)`,
  `data_load_players(file_name)`, `data_load_objects(file_name)`,
  `data_load_sounds(file_name)`, `data_load_color_tables(file_name)`, and
  `data_load_sprites(file_name)`.
- `data_load_players_type(id, type, infile)`,
  `data_load_effects(effects_file)`,
  `data_load_map(border_file, overlay_file, terrain_file, map_file,
  tile_width, tile_height, elev_height, sounds, terr_obj_file)`, and
  `data_load_random_map(rmm_map_file, rmm_land_file, rmm_terr_file,
  rmm_obj_file)`.
- `pause(flag)`, `set_map_visible(flag)`, and `set_map_fog(flag)`.
- `init_player_type(infile, index, type)`, `init_player(infile)`,
  `color_table_init(infile)`, `terrain_tables_init(infile)`,
  `init_sounds(infile, sound_dvr)`, `init_sprites(infile)`,
  `map_init(infile, sound_dvr)`, `effects_init(infile)`,
  `master_player_init(infile)`, `command_init(infile, com_hand)`,
  `world_init(infile, sound_dvr, com_hand)`, and
  `init(base_name, sound_dvr, com_hand)`.
- `data_load(base_name, world_info)`,
  `reset_communications(com_hand)`, `load_player(infile, type, index)`,
  `load_world(infile1)`, `load_game(name)`, `set_game_speed(new_speed)`,
  `setup_players(info)`, `setup_player_colors(info)`,
  `new_random_game(info)`, `new_game(info, myPlayerNum)`, and
  `new_scenario(info, random_seed_in)`.
- `update_sounds(time)`, `update_sprites(time)`,
  `is_player_turn(player_id)`, and `get_accum_time_delta(player_id)`.
- `save(outfile)`, `base_save(outfile)`, `base_save(name)`,
  `save_scenario(filename)`, `load_scenario(scenario, info)`,
  `scenario_make_player(index, player_type, info_type, master_player_id,
  name)`, `scenario_make_map(infile)`, and `load_scenario1` through
  `load_scenario8` with `(infile, info)`.
- `scenario_init(infile, world)`, `scenario_init(world)`,
  `get_scenario_info(filename)`.
- `selectNextComputerPlayer(cPType)`,
  `useComputerPlayerUpdateTime(usedTime)`,
  `objectGroupOnTile(ownerID, groupID, x, y, objectCount)`, `object(oID)`,
  `object_ptr(oID)`, `addObject(newObject)`, `removeObject(oID)`,
  `recycle_object_out_of_game(object_type, obj)`, and
  `recycle_object_in_to_game(object_type)`.

This is a declaration-name-only request. No header edit is part of this
worker's correction.

## Resource evidence

The root resource header approves cleanup macro `IDS_AI_FILE_RANDOM`.
The approval is in root commit `bf943f3339643ee5beca7dd74e98b4cb729e48d3`.
The macro retains value `0x277B`.
The random-game path passes this ID through the virtual `get_string` call.
The call passes the returned string as random-game AI information.
The macro is a cleanup name, not a claimed original macro name.
The DLL extraction proves payload status only. The source lookup path supplies
the runtime base and override behavior.

The inspected DLL evidence is:

- `C:\Projects\my_decomps\aoe1_attempt3\runtime\language.dll`
  - SHA256:
    `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
  - Resource: `RT_STRING`, language `0x0409` (1033).
  - ID `0x277B` is present. Exact text: `Random`.
- `C:\Projects\my_decomps\aoe1_attempt3\runtime\languagex.dll`
  - SHA256:
    `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
  - Query language: `0x0409` (1033).
  - ID `0x277B` is missing. No empty slot was reported.
- `C:\Projects\my_decomps\aoe1_attempt3\orig\original_full_game_files_rise_of_romes_beta_17_7_1998\XPack\languagex.dll`
  - SHA256:
    `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
  - Query language: `0x0409` (1033).
  - ID `0x277B` is missing. No empty slot was reported.

The lookup path is:

1. `RGE_Base_Game` sets `string_dll_name` to `language.dll`.
2. Base setup loads that name with `LoadLibraryA` into `StringTable`.
3. `World::new_game` calls `rge_base_game->get_string(IDS_AI_FILE_RANDOM, ...)`.
4. The virtual `TRIBE_Game::get_string` checks `StringTableX` first.
5. `TRIBE_Game::setup` loads `languagex.dll` into `StringTableX`, unless a
   `STRING=` command option selects another override DLL.
6. If `StringTableX` has no entry, `TRIBE_Game::get_string` calls the base
   method.
7. The base method calls `LoadStringA(StringTable, IDS_AI_FILE_RANDOM, ...)`.
8. The base fallback therefore returns `Random` from `language.dll`.

The inspected runtime files are not called original files. The XPack file is
the pinned original only because its path is under the repository's original
game files. The approved root header owns the cleanup macro. This worker does
not modify that header.

No new constants or comments were added. Existing numeric file flags and
scenario version values remain unchanged.

## Risks and limits

- Compilation was not run.
- Matching checks were not run.
- Audits were not run.
- Tests were not run.
- Generated code, relocations, call targets, and symbol identity remain
  unvalidated after this cleanup.
- No header change was made, so public declarations remain outside this pass.
- PDB stack-slot reuse leaves the `data_load_objects` `player` mapping and
  some wrapper locals unresolved. These are documented rather than guessed.
