# `tribegam.cpp` source cleanup

## Delivery

- Source owner: `src/tribegam.cpp`.
- Cleanup note: `decomp_notes/source_cleanup/wave04/tribegam.md`.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Source commit: `934bc31f8521b39f468a3c22af8fd1c653d68b99`.
- Assigned registry: `config/functions/src/tribegam.cpp.json`.
- Assigned function count: 118.
- Source PDB path: `C:\\msdev\\work\\age1_x1\\tribegam.cpp`.

The source cleanup restores reliable declaration names from the procedure-scoped
PDB records. It applies 1TBS and consistent indentation across the source.
It keeps source order, types, scopes, storage, casts, calls, and constants.

The source also keeps the chat mapping from root commit
`c0ce37473c32dfd6511e884ea1ead7dace6b5cce`.

## Source changes

The cleanup makes these source changes:

- It restores PDB names for parameters and named locals listed in the coverage
  ledger below.
- It adds the existing `../include/resource_ids.h` include.
- It uses approved resource names for age, civilization, save-error, status,
  and dropped-player IDs.
- It adds one comment for expansion-table fallback order.
- It adds one comment for the packed `vidc` and `iv41` identifiers.
- It changes `action_user_command` case value `0x17D5` to `CHAT_RECEIVED`.
- It changes only presentation after these semantic cleanups. It does not
  add helpers, change control flow, or change declarations in headers.

The source retains the explicit `this->` forms. It retains the data-driven
resource ranges and arithmetic lookups.

## PDB coverage ledger

I inspected every function record in the assigned registry. I checked each
procedure's scoped parameters, stack locals, function statics, and registers.
The PDB gives `ecx:this` for the member procedures unless a row states a
stack `this` record. A row marked `none beyond this` has no other named PDB
record. Source locals without a matching scoped record remain unchanged and
are marked unresolved below.

| PDB VA | Procedure | Recovered PDB names in source | Unresolved or reused records |
| ---: | --- | --- | --- |
| `00520FC0` | `encrypt_codes` | parameters `source`, `dest`, `maxlen` | none |
| `00521020` | `run_log` | parameters `str`, `show_time`; local `stime` | PDB also has `ltime` at a reused argument home. The source keeps the address operation on `show_time` and declares no extra local. |
| `00521120` | `TRIBE_Game::TRIBE_Game` | parameter `prog_info_in`, `do_setup`; locals `i`, `player`, `civ` | `do_setup` and `civ` share one PDB home. The source keeps separate parameter and local scopes. |
| `005213A0` | `TRIBE_Game::~TRIBE_Game` | none beyond `this` | none |
| `00521620` | `close_game_screens` | parameter `close_main_game_screen` | none |
| `00521790` | `setup` | locals `ici`, `cmd_line`, `file_data`, `new_string_dll_name`, `str`, `pal_entries`, `file_time` | Source locals `file_handle`, `option`, and `result` have no named scoped record. |
| `00521FA0` | `setup_cmd_options` | locals `encstr`, `cmd_line`, `temp_str` | Source locals `c`, `i`, `p`, and `q` have no named scoped record. |
| `00522200` | `setup_palette` | local `pal_entries` | none |
| `005222C0` | `setup_sounds` | none beyond `this` | Source locals `d` and `i` have no named scoped record. |
| `00522770` | `create_world` | none beyond `this` | none |
| `005227D0` | `set_game_mode` | parameters `new_mode`, `new_sub_mode` | none |
| `00522810` | `set_player` | parameter `new_player_id` | Local `oldPlayer` has no named scoped record. |
| `00522860` | `set_save_game_name` | parameter `file_name` | none |
| `005228A0` | `set_load_game_name` | parameter `file_name` | none |
| `005228E0` | `get_string` | parameter `string_id`; parameters `str`, `max_len` | none |
| `00522930` | `get_string2` | parameters `string_type`, `id`, `id2`, `str`, `max_len` | none |
| `00523450` | `get_view_panel` | none beyond `this` | Local `panel` has no named scoped record. |
| `005234A0` | `get_map_panel` | none beyond `this` | Local `p` has no named scoped record. |
| `005234F0` | `get_save_game_name` | none beyond `this` | none |
| `00523500` | `get_load_game_name` | none beyond `this` | none |
| `00523510` | `new_scenario_header(int)` | parameter `infile` | none |
| `00523570` | `new_scenario_header(RGE_Scenario*)` | parameter `scenario_info` | none |
| `005235D0` | `new_scenario_info` | parameter `infile` | none |
| `00523640` | `show_error_message` | parameter `error_code_in`; locals `title`, `msg` | none |
| `005236A0` | `show_status_message(char*)` | parameters `messageIn`, `info_file`, `info_id` | none |
| `00523750` | `show_status_message(int)` | parameter `string_id`; parameters `info_file`, `info_id`; local `str` | none |
| `005237A0` | `close_status_message` | none beyond `this` | none |
| `005237B0` | `start_video` | parameters `video_num`, `video_file`; locals `temp_name`, `video_rect`, `str` | Other source locals have no named scoped record. |
| `00523AE0` | `video_sub_wnd_proc` | parameters `wnd`, `msg`, `wparam`, `lparam` | This free procedure has no member `this` record. |
| `00523B10` | `stop_video` | parameter `goto_next_video`; locals `save_vid_num`, `str` | none |
| `00523F10` | `start_campaign_menu` | none beyond `this` | Source locals `screen` and `music` have no named scoped record. |
| `00524030` | `start_menu` | none beyond `this` | Source local `screen` has no named scoped record. |
| `00524150` | `quit_game` | locals `campaign`, `temp_test_scenario`, `file_info` | none |
| `005243A0` | `restart_game` | locals `temp_name`, `fileInfo` | Source local `result` has no named scoped record. |
| `00524530` | `load_db_files` | none beyond `this` | Source local `result` has no named scoped record. |
| `005245D0` | `load_game_data` | none beyond `this` | none |
| `00524640` | `save_game` | parameter `fileName`; locals `fileNameNoExt`, `retval` | Source local `extension` has no named scoped record. |
| `00524790` | `save_scenario` | parameter `fileName` | Loop local `i` has no named scoped record. |
| `00524880` | `calc_timing_text` | function static `last_time` | none |
| `00524A60` | `show_timings` | none beyond `this` | none |
| `00524A80` | `show_comm` | none beyond `this` | none |
| `00524AF0` | `show_ai` | local `str` | Other source locals have no named scoped record. |
| `00524D70` | `notification` | parameters `notify_type`, `val1`, `val2`, `val3`, `val4`; locals `msg`, `temp_str` | none |
| `00525D20` | `start_game` | parameter `skip_startup_screens`; local `info_file` | Source local `info_id` has no named scoped record. |
| `00525E50` | `test_scenario` | parameter `scenario_file` | none |
| `00525EE0` | `start_scenario` | parameter `scenario_file`; locals `file_info`, `first_any_player`, `scenario_file2` | Source locals `player_count` and `scenario_info` have no named scoped record. |
| `00526170` | `load_game` | parameter `fileName`; locals `cur_panel`, `fileNameNoExt`, `fn`, `total_checksum`, `action_checksum`, `num4`, `i`, `num3`, `num2`, `temp_position_checksum`, `num1`, `total_action_checksum`, `list`, `p`, `target_name`, `act_node` | `cur_panel` and `i` share a PDB home. `target_name` and `act_node` repeat at reused homes in separate scopes. Other debug locals retain their existing names. |
| `00526DC0` | `do_game_over` | none beyond `this` | Source local `mode` and `player` have no named scoped record. |
| `00526E60` | `create_game` | parameter `not_used`; locals `scenario_info`, `player_info`, `humanity`, `i`, `position_used`, `path_finding_val`, `map_info`, `scenario_file`, `player_index`, `scenario_player`, `file_info` | Other source locals retain their existing names. The PDB array record is eight entries. The source keeps the original nine-entry initialization. |
| `00527830` | `create_game_screen` | none beyond `this` | Source locals have no named scoped record. |
| `00527A70` | `processCheatCode` | parameters `playerID`, `text`; locals `encstr`, `str`, `tempStr1`, `objectID`, `target`, `commander`, `playName` | PDB reuses the `objectID` and `target` home. The source keeps separate block scopes. |
| `00528670` | `let_game_begin` | locals `int_str`, `age_str`, `diff_str`, `map_type_str`, `str`, `map_size_str`, `vic_str`, `res_str` | none |
| `00528DE0` | `start_scenario_editor` | parameters `scenario_name_in`, `is_multi_player_in` | none |
| `00528F60` | `send_game_options` | local `combined_options` | none |
| `00528FB0` | `receive_game_options` | local `size` | Source local `options` has no named scoped record. |
| `00529000` | `set_tribe_options` | parameter `options` | Source local `i` has no named scoped record. |
| `00529100` | `get_tribe_options` | parameter `options` | Source local `i` has no named scoped record. |
| `005291F0` | `mapSize` | none beyond const `this` | none |
| `00529200` | `setMapSize` | parameter `v` | none |
| `005292A0` | `mapType` | none beyond const `this` | none |
| `005292B0` | `setMapType` | parameter `v` | none |
| `005292C0` | `animals` | none beyond const `this` | none |
| `005292D0` | `setAnimals` | parameter `v` | none |
| `005292E0` | `predators` | none beyond const `this` | none |
| `005292F0` | `setPredators` | parameter `v` | none |
| `00529300` | `victoryType` | none beyond `this` | none |
| `00529310` | `victoryAmount` | none beyond `this` | none |
| `00529320` | `setVictoryType` | parameters `victory_type_in`, `amount_in` | none |
| `00529340` | `civilization` | parameter `player_num` | none |
| `00529350` | `setCivilization` | parameters `player_num`, `civilization` | none |
| `00529370` | `scenarioPlayer` | parameter `player_num` | none |
| `00529380` | `setScenarioPlayer` | parameters `player_num`, `scenario_player` | none |
| `005293A0` | `playerColor` | parameter `player_num` | none |
| `005293B0` | `setPlayerColor` | parameters `player_num`, `color` | none |
| `005293D0` | `computerName` | parameter `player_num` | none |
| `005293E0` | `setComputerName` | parameters `player_num`, `val` | none |
| `00529400` | `allowTrading` | none beyond `this` | none |
| `00529410` | `longCombat` | none beyond `this` | none |
| `00529420` | `randomizePositions` | none beyond `this` | none |
| `00529430` | `fullTechTree` | none beyond `this` | none |
| `00529440` | `resourceLevel` | none beyond `this` | none |
| `00529450` | `startingAge` | none beyond `this` | none |
| `00529460` | `startingUnits` | none beyond `this` | none |
| `00529470` | `deathMatch` | none beyond `this` | none |
| `00529480` | `popLimit` | none beyond `this` | none |
| `005294A0` | `quickStartGame` | none beyond `this` | none |
| `005294B0` | `randomStartValue` | none beyond `this` | none |
| `005294C0` | `setAllowTrading` | parameter `val` | none |
| `005294D0` | `setLongCombat` | parameter `val` | none |
| `005294E0` | `setRandomizePositions` | parameter `val` | none |
| `005294F0` | `setFullTechTree` | parameter `val` | none |
| `00529500` | `setResourceLevel` | parameter `val` | none |
| `00529510` | `setStartingAge` | parameter `val` | none |
| `00529520` | `setStartingUnits` | parameter `val` | none |
| `00529530` | `setDeathMatch` | parameter `val` | none |
| `00529540` | `setPopLimit` | parameter `val` | none |
| `00529550` | `setQuickStartGame` | parameter `val` | none |
| `00529560` | `setRandomStartValue` | parameter `val` | none |
| `00529570` | `gameSummary` | function static `temp` | none |
| `00529580` | `wnd_proc` | stack `this`; parameters `wnd`, `msg`, `wparam`, `lparam` | The PDB records `this` on the stack for this procedure. |
| `00529610` | `handle_idle` | function static `last_wait_time`; locals `retval`, `str`, `msg` | Source inner local `player` has no named scoped record. |
| `00529980` | `handle_query_new_palette` | parameters `wnd`, `msg`, `wparam`, `lparam` | Locals `result` and `mode` have no named scoped record. |
| `005299E0` | `handle_activate` | parameters `wnd`, `msg`, `wparam`, `lparam` | none |
| `00529A70` | `action_user_command` | parameters `val1`, `val2`; local `temp_str` | PDB records `fileName` and `msg` at one reused home. The source keeps the existing `msg` buffer and does not force a `fileName` declaration. |
| `00529F60` | `action_key_down` | parameters `key`, `repeat_count`, `ctrl_key`, `alt_key`, `shift_key` | none |
| `0052A000` | `action_close` | none beyond `this` | none |
| `0052A030` | `game_over_msg` | function static `msg` | Source local names `world` and `player` have no named scoped record. |
| `0052A080` | `get_achievement_info` | parameters `achievement`, `info` | none |
| `0052A0B0` | `randomComputerName` | parameter `civ`; local `i`, `scount` | Other source locals retain their existing names. |
| `0052A170` | `resetRandomComputerName` | none beyond `this` | Source local `i` has no named scoped record. |
| `0052A190` | `video_wnd_proc` | parameters `hwnd`, `msg`, `wParam`, `lParam` | none |
| `0052A1E0` | `SetClickTables` | parameters `RC`, `RCS`, `LC`, `LCS` | none |
| `0052A210` | `set_interface_messages` | none beyond `this` | none |
| `0052A260` | `setup_video_system` | none beyond `this` | none |
| `0052A430` | `shutdown_video_system` | none beyond `this` | Source locals have no named scoped record. |
| `0052A510` | `disconnect_multiplayer_game` | none beyond `this` | Source locals have no named scoped record. |
| `0052A630` | `add_notification_loc` | parameters `x`, `y` | Source local `current` has no named scoped record. |
| `0052A6A0` | `goto_notification_loc` | locals `x`, `y` | none |

The ledger records the PDB names that the source can map without changing a
scope or declaration. Reused homes remain unresolved rather than becoming
new declarations.

## Resource and constant evidence

### String lookup

`TRIBE_Game::setup` loads `languagex.dll` into `StringTableX` by default.
The `STRING=` option selects another DLL. `TRIBE_Game::get_string` calls
`LoadStringA(StringTableX, ...)` first. A zero result calls
`RGE_Base_Game::get_string`, which supplies the base-game lookup.

The cleanup comment records this override-first and fallback order. It does
not replace a lookup with English text.

The inspected resource language is `0x0409` (English). The exact resource
extractions are:

- `build/resource-strings/tribegam-runtime-language.json`;
- `build/resource-strings/tribegam-runtime-languagex.json`;
- `build/resource-strings/tribegam-original-xpack-languagex.json`; and
- the matching `*-list.json` files.

| Module | Evidence path | SHA-256 |
| --- | --- | --- |
| Base fallback | `C:\\Projects\\my_decomps\\aoe1_attempt3\\runtime\\language.dll` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5` |
| Runtime override | `C:\\Projects\\my_decomps\\aoe1_attempt3\\runtime\\languagex.dll` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39` |
| Pinned XPack override | `C:\\Projects\\my_decomps\\aoe1_attempt3\\orig\\original_full_game_files_rise_of_romes_beta_17_7_1998\\XPack\\languagex.dll` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2` |

The exact base extraction returned 137 fixed numeric `get_string` IDs. It
reported no missing IDs and nine empty slots. The exact runtime and pinned
XPack override extractions each returned 26 requested IDs, with 110 missing
IDs and 17 empty slots. Missing and empty override entries remain subject to
the existing fallback path. An empty slot does not prove an unused ID.

The non-empty override entries in the checked fixed set are:

| ID | Runtime and pinned XPack text |
| ---: | --- |
| `0x1025` | Runtime: `Increment queue (,)`; XPack: `Increment Queue (,)` |
| `0x1026` | Runtime: `Decrement queue (.)`; XPack: `Decrement Queue (.)` |
| `0x2806` | `Roman` |
| `0x2807` | `Carthaginian` |
| `0x2808` | `Macedonian` |
| `0x2809` | `Palmyran` |
| `0x296F` | `Continental` |
| `0x2970` | `Mediterranean` |
| `0x2978` | `Gigantic` |

The override has empty requested slots at `0x1020`-`0x1022`,
`0x2800`-`0x2802`, `0x2804`, `0x296A`-`0x296E`, and `0x2973`-`0x2977`.
The source does not infer a meaning from an empty slot.

### IDs changed to approved names

The source uses names supplied by the approved root header. The header was
read-only for this assignment. The 22 age, civilization, and dropped-player
mappings were approved by root in commit
`bf943f3339643ee5beca7dd74e98b4cb729e48d3`. That approval produced the
`include/resource_ids.h` blob
`3670c49563f971137b89644d4a0069796cf3d2af`. Later commit
`3f5867e84cda53a3103593a0e74f952a3f0798b7` imported that same blob.

| Source name | ID | Base payload or role | Override state |
| --- | ---: | --- | --- |
| `IDS_STATUS_SAVING_SCENARIO` | `0x0450` | `Saving scenario...` | The override lacks this requested ID, so the base lookup remains effective. |
| `IDS_ERROR_CANNOT_SAVE_GAME` | `0x0962` | `The game could not be saved. Free some disk space, and then try again.` | The override lacks this requested ID. |
| `IDS_ERROR_CANNOT_SAVE_SCENARIO` | `0x0963` | `The scenario could not be saved. Free some disk space, and then try again.` | The override lacks this requested ID. |
| `IDS_HELP_AGE_STONE` | `0x1069` | `Stone Age` | The override lacks this requested ID. |
| `IDS_HELP_AGE_TOOL` | `0x106A` | `Tool Age` | The override lacks this requested ID. |
| `IDS_HELP_AGE_BRONZE` | `0x106B` | `Bronze Age` | The override lacks this requested ID. |
| `IDS_HELP_AGE_IRON` | `0x106C` | `Iron Age` | The override lacks this requested ID. |
| `IDS_CIVILIZATION_EGYPTIAN` through `IDS_CIVILIZATION_CHOSON` | `0x27F7`-`0x2802` | `Egyptian`, `Greek`, `Babylonian`, `Assyrian`, `Minoan`, `Hittite`, `Phoenician`, `Sumerian`, `Persian`, `Shang`, `Yamato`, `Choson` | The override has empty entries for `0x2800`-`0x2802`; the base entries remain effective there. |
| `IDS_CIVILIZATION_UNKNOWN` | `0x2804` | `Unknown` | The override entry is empty. |
| `IDS_CIVILIZATION_ROMAN` through `IDS_CIVILIZATION_PALMYRAN` | `0x2806`-`0x2809` | The base slots are empty. | The override supplies `Roman`, `Carthaginian`, `Macedonian`, and `Palmyran`. |
| `IDS_PLAYER_DROPPED_NOTICE` | `0x25C9` | `You were dropped from the game.` | The override lacks this requested ID. |

The macro substitutions preserve the underlying integer values. They do not
change resource lookup, formatting tokens, buffer sizes, or fallback order.

### Dynamic resource ranges

`randomComputerName` keeps the count lookup
`(civ + 0x1B7) * 10` and the name lookup `slot + civ * 10 - 9`.
The source does not expand the range into a switch or table. The base count
records are seven for `0x1130` through `0x119E`. Base count records
`0x11A8`, `0x11B2`, `0x11BC`, and `0x11C6` are missing. The runtime override
counts are nine for all checked civilization blocks. Missing name slots use
the existing fallback path. The pinned XPack text at `0x1156` is
`Shamash Shu-Mukin`; the staged runtime text is `Shamash`.

The difficulty lookup keeps `0x2BD0 + this->difficulty()`. The source does
not assign a new macro to that arithmetic range.

### Packed video identifiers

`setup` passes `0x63646976` and `0x31347669` to `ICInfo`.
The pinned VC5 header `C:/Program Files (x86)/DevStudio/VC/Include/VFW.H`
defines `ICTYPE_VIDEO` as `mmioFOURCC('v', 'i', 'd', 'c')`, which has value
`0x63646976`. Little-endian bytes of `0x31347669` are `69 76 34 31`, or
lowercase `iv41`. No pinned VC5 header symbol proves an uppercase `IV41`
value for this call. The source keeps both numeric values and documents the
byte interpretation.

## Shared mapping and owner requests

The shared header mapping was inspected read-only from root commit
`c0ce37473c32dfd6511e884ea1ead7dace6b5cce`:

```cpp
#define CHAT_RECEIVED 0x17D5
```

The source changes only the matching `action_user_command` case label. The
chat body still calls `handleChatReceived(val2)`. Root must integrate the
header commit before compiling this source. This worker did not edit
`include/chat.h`.

`include/resource_ids.h` is root-owned. Root approved the 22 age,
civilization, and dropped-player mappings in commit
`bf943f3339643ee5beca7dd74e98b4cb729e48d3`. That approval produced header
blob `3670c49563f971137b89644d4a0069796cf3d2af`. Later commit
`3f5867e84cda53a3103593a0e74f952a3f0798b7` imported the same blob. Owner 27
imports the later root header from commit
`0aa69b43219d638bf1a6667b832257d633635ccf`. That header retains these
mappings and adds `IDS_ERROR_TITLE`. No new resource macro request is needed
for this source. Root must keep this later header available when it integrates
`src/tribegam.cpp`.

### Correction history

This report corrects an earlier claim that every used resource macro existed
in the common base header. That claim was false. Root approved the 22 mappings
in `bf943f3339643ee5beca7dd74e98b4cb729e48d3`, and later commit
`3f5867e84cda53a3103593a0e74f952a3f0798b7` imported the resulting blob.

### Header parameter-label request

The owner of `include/tribegam.h` should update only the parameter labels in
the following `TRIBE_Game` declarations. Keep each type, order, overload, and
calling convention unchanged. These labels match the PDB-backed source names.
The request excludes free procedures and excludes methods whose PDB labels did
not change.

| Method | Exact requested parameter labels |
| --- | --- |
| `TRIBE_Game::TRIBE_Game` | `prog_info_in`, `do_setup` |
| `TRIBE_Game::close_game_screens` | `close_main_game_screen` |
| `TRIBE_Game::set_game_mode` | `new_mode`, `new_sub_mode` |
| `TRIBE_Game::set_player` | `new_player_id` |
| `TRIBE_Game::set_save_game_name` | `file_name` |
| `TRIBE_Game::set_load_game_name` | `file_name` |
| `TRIBE_Game::get_string` | `string_id`, `str`, `max_len` |
| `TRIBE_Game::get_string2` | `string_type`, `id`, `id2`, `str`, `max_len` |
| `TRIBE_Game::new_scenario_header(int)` | `infile` |
| `TRIBE_Game::new_scenario_header(RGE_Scenario*)` | `scenario_info` |
| `TRIBE_Game::new_scenario_info` | `infile` |
| `TRIBE_Game::show_error_message` | `error_code_in` |
| `TRIBE_Game::show_status_message(char*)` | `messageIn`, `info_file`, `info_id` |
| `TRIBE_Game::show_status_message(int)` | `string_id`, `info_file`, `info_id` |
| `TRIBE_Game::start_video` | `video_num`, `video_file` |
| `TRIBE_Game::stop_video` | `goto_next_video` |
| `TRIBE_Game::save_game` | `fileName` |
| `TRIBE_Game::save_scenario` | `fileName` |
| `TRIBE_Game::notification` | `notify_type`, `val1`, `val2`, `val3`, `val4` |
| `TRIBE_Game::start_game` | `skip_startup_screens` |
| `TRIBE_Game::test_scenario` | `scenario_file` |
| `TRIBE_Game::start_scenario` | `scenario_file` |
| `TRIBE_Game::load_game` | `fileName` |
| `TRIBE_Game::processCheatCode` | `playerID`, `text` |
| `TRIBE_Game::start_scenario_editor` | `scenario_name_in`, `is_multi_player_in` |
| `TRIBE_Game::get_tribe_options` | `options` |
| `TRIBE_Game::setMapSize` | `v` |
| `TRIBE_Game::setMapType` | `v` |
| `TRIBE_Game::setAnimals` | `v` |
| `TRIBE_Game::setPredators` | `v` |
| `TRIBE_Game::setVictoryType` | `victory_type_in`, `amount_in` |
| `TRIBE_Game::civilization` | `player_num` |
| `TRIBE_Game::setCivilization` | `player_num`, `civilization` |
| `TRIBE_Game::scenarioPlayer` | `player_num` |
| `TRIBE_Game::setScenarioPlayer` | `player_num`, `scenario_player` |
| `TRIBE_Game::playerColor` | `player_num` |
| `TRIBE_Game::setPlayerColor` | `player_num`, `color` |
| `TRIBE_Game::computerName` | `player_num` |
| `TRIBE_Game::setComputerName` | `player_num`, `val` |
| `TRIBE_Game::wnd_proc` | `wnd`, `msg`, `wparam`, `lparam` |
| `TRIBE_Game::handle_query_new_palette` | `wnd`, `msg`, `wparam`, `lparam` |
| `TRIBE_Game::handle_activate` | `wnd`, `msg`, `wparam`, `lparam` |
| `TRIBE_Game::action_user_command` | `val1`, `val2` |
| `TRIBE_Game::action_key_down` | `key`, `repeat_count`, `ctrl_key`, `alt_key`, `shift_key` |
| `TRIBE_Game::get_achievement_info` | `achievement`, `info` |
| `TRIBE_Game::randomComputerName` | `civ` |
| `TRIBE_Game::video_wnd_proc` | `hwnd`, `msg`, `wParam`, `lParam` |
| `TRIBE_Game::SetClickTables` | `RC`, `RCS`, `LC`, `LCS` |

Keep the mixed spellings exactly as shown. In particular, use lowercase
`wparam` and `lparam` for `wnd_proc`, `handle_query_new_palette`, and
`handle_activate`; use `wParam` and `lParam` for `video_wnd_proc`; and use
uppercase `RC`, `RCS`, `LC`, and `LCS` for `SetClickTables`.

## Code-generation and preservation effects

Parameter and local renames do not change mangled function symbols, types,
scopes, storage, or expressions. Existing PDB name reuse remains represented
by separate source scopes or by the existing declaration. The source keeps
all casts, widths, explicit `this->` uses, evaluation order, calls, and
source-order declarations.

Resource macro uses expand to the same integer constants. `CHAT_RECEIVED`
expands to the same `0x17D5` value after root integrates its header. The
formatting and sparse comments change source presentation and debug line
records. This source has no `__LINE__` use in the changed regions.

No source edit intentionally changes executable data, relocations, direct
call targets, tail jumps, or ABI symbols. A generated-code claim is not proven
until the final comparison stage.

## Diff review and validation status

I reviewed the complete source diff against base commit
`c22ba4258c45b1178181e185d60a3b09a1add617`. The review covered source names,
resource substitutions, comments, brace placement, indentation, repeated PDB
homes, and the single shared mapping.

No build, compiler check, matching check, audit, validation command, test,
or game run was performed. The assignment defers all validation to the final
comparison stage.
