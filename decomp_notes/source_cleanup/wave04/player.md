# `player.cpp` source-cleanup report

## Delivery

- Module: `src/player.cpp`.
- Worker slot: 218.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Base source SHA-256: `d0a7152b8de13fac316723a3714338a10eafa57ff531e789d71f52edd3a8f872`.
- Cleaned source SHA-256: `fe847fec60fb57c0bfb9416be7e3e0a9db9d5bdcc1a9aebee4fcecef29aab2b8`.
- Final commit: see the Git history for this delivery.
- Changed files: `src/player.cpp`; this report.
- Registry: `config/functions/src/player.cpp.json`, build flags `gx`.
- Header request: `include/player.h` remains unchanged.

The original behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Evidence checked

The source registry contains 117 normal source owners. I inspected all 117
procedure-scoped PDB records from `inventory/pdb/scoped_symbols.json`.
The extracted review record is `build/player_pdb_records.txt`.

The source records cover `0046E4B0` through `00471EB0`. They include both
constructors, all Player methods, and all `RGE_Tile_List` methods in source
order. I also inspected the eight header-owned records at `0046EC80`,
`0046EC90`, `0046ECA0`, `0046ECB0`, `0046ECC0`, `0046ECD0`, `0046ED30`, and
`0046ED40`.

The PDB records name `this` in `ecx` for each normal source owner. The header
records remain inline definitions in `include/player.h`. They have no
standalone source bodies to add to this file.

I checked the matching inventory packets for the constructors, scenario
loading, saving, object copying, and waypoint handling. I also checked the
selection, command, and tile-list packets. The original packets support the
PDB names used below.

## Original-name recovery

I restored PDB names for parameters and locals that map to the current source
scope. I kept original mixed spelling. I did not normalize recovered names.

- Constructors now use `infile`, `gworld`, `this_id`, `prototype`, `new_name`,
  `m_player_id`, and `flag`.
- Status, AI, and diplomacy methods now use `new_status`, `dropped`, `sNum`,
  `playerNum`, `rType`, `bL`, `cP`, `rS`, `mood`, and `mapType`.
- AI order methods now use `issuer`, `recipient`, `orderType`, `target`,
  `targetOwner`, `targetX`, `targetY`, `targetZ`, `range`, `immediate`,
  `inFront`, and `priority`.
- Order and waypoint methods now use `unit`, `target`, `targetX`, `targetY`,
  `recipient`, `waypoint`, and `numWaypoints`.
- Play and pathing methods now use `groupUnits`, `groupCount`, `playID`,
  `numWaitDelays`, and the PDB-selected list names.
- The variadic chat method now uses `playerID`, `copySelf`, `textIn`, and
  `textOut`. Its loop temporary is `current_player_id`.
- Scenario and save methods now use `infile`, `outfile`, `player_id_hash`,
  `has_team`, `temp_byte`, `index`, and the PDB-selected list names.
- Loading, checksum, object, and diplomacy methods now use `obj_type`,
  `version_control`, `new_checksum`, `new_position_checksum`,
  `new_action_checksum`, `attribute`, `amount`, `earned`, `obj_category`,
  `on_off_flag`, `obj_id`, `group`, `flag`, `dest`, `source`, and `player_id`.
- Selection and command methods now use `object_category`, `object_group`,
  `Obj_id`, `newFacet`, `text_id`, `list_num`, `listNum`, `commander`,
  `groupList`, `groupLength`, `unitID`, `comm_player_id`, `sleep_flag`,
  `dopple_flag`, and `node`.
- Tile-list methods now use `col`, `row`, `Initial_Size`, `theList`, and
  `list_size`.

The PDB names `j` and `list` in
`get_selected_objects_to_command` were already present. The PDB locals
`num1`, `num2`, `num3`, `num4`, and `temp_position_checksum` were already
present in `create_checksum`.

The source keeps descriptive cleanup names where the PDB has no usable
source mapping. These include `pathing`, `pathing_cap`, `player`, `object`,
`remaining`, `current_player_id`, `object_index`, and `Selection_Locals`.
These names use snake case when they are cleanup names.

The PDB records for `scenario_load` and `scenario_postload` contain a
`relation` record at `+0x8`. That slot overlaps `player_id_hash` and has no
live use in the packets. I did not force that record into a declaration.
The PDB also records `p` at `+0x8` in `save2`. That slot overlaps the input
parameter. The current `save_file` and `master_object_count` declarations
remain descriptive source mappings.

The PDB records `player_count` as `short`, while the existing source reads
one byte into an `unsigned char`. I kept the source type unchanged. This
avoids an unsupported type change. The PDB evidence does not prove a safe
source declaration change for that variable.

## Comments and formatting

I removed stale `update` comments that described compiler instructions and
source line numbers. They did not explain source behavior.

I added one comment for the cdecl varargs stack layout. I added one comment
for the executable's index comparison in scenario loading. The existing
`ungroup_objects` execution-order comment remains.

I applied 1TBS brace placement and readable wrapping throughout this source.
I did not reorder declarations or statements. I did not add a helper,
wrapper, assembly block, or context-selection macro.

## Constants and resources

No constant was added or replaced. The `DAT_00570e90`, `DAT_00570ec0`, and
`DAT_00570ec4` values remain unchanged. No shared declaration proves names
for those data addresses in this module.

No resource lookup occurs in `player.cpp`. Resource IDs, payloads, language,
lookup paths, and resource-name requests are not applicable.

## Type, layout, and symbol review

The source changes preserve types, declaration scopes, storage duration,
casts, evaluation order, calls, literals, virtual slots, and source order.
The changes rename identifiers, remove stale comments, and adjust formatting.
The public function symbols and class layout remain unchanged.

The registry statuses remain unchanged. In particular, accepted drift remains
recorded for `004705A0`, `004706B0`, and `00470CB0`. This cleanup does not
attempt their separate source-recovery questions.

## Header and root requests

I did not edit `include/player.h`. Its unnamed declarations remain valid.
The owner of that header may add the PDB-proven names from the source
definitions. This includes the Player methods listed in the recovery section
and these tile-list declarations:

```cpp
void add_node(int col, int row);
void get_list_info(RGE_Tile_List_Node*& theList, int& list_size);
RGE_Tile_List(int Initial_Size);
```

The header owner should keep all public types, overloads, calling conventions,
virtual slots, and inline bodies unchanged. The eight header-owned bodies need
no source move. No root-owned global, layout, or resource declaration request
is open.

## Validation status

Compilation, builds, matching checks, audits, validation tools, tests, and
games were not run. `git diff --check` was used during review. The cleanup
remains unvalidated until the final comparison stage.
