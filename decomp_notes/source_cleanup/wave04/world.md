# `src/world.cpp` source cleanup

## Delivery

- Branch: `cleanup/staging-20260915-227` (`slot-227`)
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source owner: `src/world.cpp`
- Changed files: `src/world.cpp`, this note
- Cleanup commit: recorded in the delivery response after commit
- Headers changed: none

This pass changes names and local presentation only. It does not change public
signatures, layouts, globals, file formats, calls, or control flow by intent.

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

The scenario loaders use the PDB `header_size` name for each object-count
field. The PDB uses `long` for the recovered scenario IDs, counts, and index
locals. The source keeps those types. The scenario wrapper functions retain
local `file` variables because their scoped records do not prove a better
local name.

## Resource evidence

The random-game path still uses the numeric lookup `0x277B` in
`RGE_Base_Game::get_string`. The inspected evidence is:

- `build/world-cleanup-evidence/runtime-language-277b.json`: runtime
  `language.dll` contains `Random`.
- `build/world-cleanup-evidence/runtime-languagex-277b.json`: runtime
  `languagex.dll` does not contain the entry.
- `build/world-cleanup-evidence/original-languagex-277b.json`: the pinned
  original XPack `languagex.dll` does not contain the entry.

The call passes the returned string as random-game AI information. This proves
the call purpose but does not prove an original macro name. No shared resource
header was changed, and no new resource name was added in this pass.

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
