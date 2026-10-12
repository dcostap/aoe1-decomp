# `src/basegame.cpp` source-cleanup report

## Scope and commits

- Module: `src/basegame.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Prior source commit: `e2add30e8ef690448fd884c6a2c2fae024e624ed`
- Final source commit: `479e131d4ab37c319112f7d4c2e744a3bf81cc98`
- Changed files: `src/basegame.cpp` and this report.
- Header owner: this worker did not edit any header.
- Registry: `config/functions/src/basegame.cpp.json`.

The original behavior reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The procedure-scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

I inspected all 202 registry-selected BaseGame functions. Every selected
function has a scoped PDB record. The records include stack, register, and
function-static names. `RGE_Base_Game::setup` at `0041BAA0` remains the
accepted-drift function.

## Original-name recovery

The following source names now match the scoped PDB records. These are
recovered original names, not new descriptive names.

| Functions | Recovered parameters and locals |
| --- | --- |
| `write_draw_log`, `write_draw_log2` | `s` |
| `rge_base_game_wnd_proc` | `wnd`, `msg`, `wparam`, `lparam` |
| `RGE_Base_Game` constructor | `prog_info_in` |
| `RGE_Base_Game::setup` | `DXVersion`, `DXPlatform`; the other PDB names were already present |
| Timing getters and setters | `id`, `time` |
| `get_string` overloads | `text_id`; `string_id`, `str`, `max_len`; `string_type`, `id`, `str`, `max_len` |
| `get_string2` | `string_type`, `id`, `id2`, `str`, `max_len` |
| Scenario and campaign helpers | `scenario_file`, `from_campaign`, `outfile`, `infile`, `scenario_info`, `campaign_player`, `campaign_scenario` |
| `setup_cmd_options` | `cmd_line`, `temp_str`, `character`, `argument` |
| Both `make_font` overloads | `string_id`, `strike_out`; `face_name`, `point_size`, `wgt`, `strike_out` |
| `check_for_cd`, `check_expiration` | `num_players`; `kill_def` |
| Dialog and mode helpers | `dialog_ptr`, `new_dialog`, `new_mode`, `new_sub_mode`, `new_player_id` |
| Font, shape, sound, pause, and mouse helpers | `font_id`, `shape_id`, `sound_id`, `paused_in`, `non_user_pause_in`, `wparam`, `lparam`, `point`, `left_btn`, `right_btn`, `ctrl_key`, `shift_key`, `val`, `facet` |
| Window enumeration callbacks | `hwnd`, `lParam`, `wnd_title` |
| Window callbacks and handlers | `wnd`, `msg`, `wparam`, `lparam`; `retval`, `mouse_down`, `save_debug_timeGetTime_on` |
| Game-option transfer helpers | `size`, `options` |
| Player-option getters and setters | `player_num`, `ver`, `v`, `val`, `n`, `x`, `y`, `z`, `has_cd`, `player_version`, `difficulty`, `team`, `flag` |
| Checksum helpers | `player`; `new_checksum`, `new_position_checksum`, `new_action_checksum`, `checksum1`, `checksum2`, `checksum3` |
| Scenario checks and countdown helpers | `argument`, `cmd_line`, `scenario_file`, `scenario`, `checksum`, `file_name`, `player_index`, `player_id`, `in_countdown_player_id`, `in_countdown_timer`, `out_countdown_player_id`, `out_countdown_timer` |
| Video, sound, and speed helpers | `file_name`, `sound_id`, `val` |
| Debug random helpers | `source_name`, `source_line`, `seed`, `temp_name` |

The `gameSummary` file-static buffer now uses the PDB name `temp`. Its
`static char` type, storage duration, and scope remain unchanged. The
`GetWorldChecksums` local checksum names do not change the three output
references, initialization order, player loop, or checksum call order.

## Shared string buffer and comments

`RGE_Base_Game::get_string(long)` still writes to the file-static
`g_string_buffer[0x200]` and returns that pointer. The new comment states:

```cpp
// The next get_string(long) call overwrites this shared buffer.
```

This records the observed lifetime constraint. It does not change the buffer,
lookup order, fallback behavior, buffer size, or return value.

No resource ID, constant, API call, string payload, or shared declaration was
added or changed. Existing resource lookups and fixed debug source-line
arguments remain unchanged.

## Unresolved declaration mappings

I did not force names onto records without a one-to-one source declaration.

- `RGE_Base_Game::wnd_proc` has PDB stack names `fMinimized` and `fActive`.
  The current source uses direct `LOWORD` and `HIWORD` expressions. Adding
  locals would change declaration structure without evidence.
- `RGE_Base_Game::handle_paint` has function statics `do_show` and
  `start_wait_time` in the PDB. The current source has palette-restore globals,
  but no proof maps those names to these statics. No aliases were added.
- PDB records do not name every current local. I left those declarations in
  their existing scopes and types instead of guessing from a reused slot.

## Formatting correction

The source received a module-wide whitespace-only formatting pass. Function
and control opening braces now use 1TBS. Braced `else` clauses use `} else {`.
Continuation indentation now follows the surrounding four-space style. This
includes the `debug_srand` declaration and definition.

The pass did not add or remove braces, change scopes, reorder statements, or
change tokens. The prior names and shared-buffer comment remain unchanged.

## Code-generation risks and validation

The source changes recover parameter and local spellings. They do not change
ABI names, types, object layout, storage duration, call targets, relocations,
control flow, evaluation order, or resource behavior. The static buffer rename
keeps its type and file scope. The comment can affect debug line records, as
expected for source cleanup.

## Owner-header parameter-label request

The source definitions now use the PDB-backed labels below. The header owner
should add these labels to the matching declarations in `include/basegame.h`.
This worker did not edit that header.

| Class method declaration | Requested parameter labels |
| --- | --- |
| `RGE_Base_Game(RGE_Prog_Info*, int)` | `prog_info_in`, `do_setup` |
| `add_to_timing(int, unsigned long)` | `id`, `time` |
| `set_last_single_time(int, unsigned long)` | `id`, `time` |
| `get_last_time(int)` | `id` |
| `get_last_single_time(int)` | `id` |
| `get_accum_time(int)` | `id` |
| `get_max_time(int)` | `id` |
| `get_last_max_time(int)` | `id` |
| `get_string(long)` | `text_id` |
| `get_string(long, char*, int)` | `string_id`, `str`, `max_len` |
| `get_string(int, long, char*, int)` | `string_type`, `id`, `str`, `max_len` |
| `get_string2(int, long, long, char*, int)` | `string_type`, `id`, `id2`, `str`, `max_len` |
| `get_scenario_info(char*, int)` | `scenario_file`, `from_campaign` |
| `get_scenario_header(char*, int)` | `scenario_file`, `from_campaign` |
| `write_scenario_header(int)` | `outfile` |
| `new_scenario_header(int)` | `infile` |
| `new_scenario_header(RGE_Scenario*)` | `scenario_info` |
| `new_scenario_info(int)` | `infile` |
| `get_campaign_info(long&, long&, long&)` | `campaign`, `campaign_player`, `campaign_scenario` |
| `set_campaign_info(long, long, long)` | `campaign`, `campaign_player`, `campaign_scenario` |
| `make_font(HDC, long, int)` | `dc`, `string_id`, `strike_out` |
| `make_font(HDC, char*, int, int, int)` | `dc`, `face_name`, `point_size`, `wgt`, `strike_out` |
| `check_for_cd(int)` | `num_players` |
| `create_dialog(TPanel**, TPanel*)` | `dialog_ptr`, `new_dialog` |
| `delete_dialog(TPanel**)` | `dialog_ptr` |
| `set_game_mode(int, int)` | `new_mode`, `new_sub_mode` |
| `set_player(short)` | `new_player_id` |
| `get_font(int)` | `font_id` |
| `get_shape(int)` | `shape_id` |
| `get_sound(int)` | `sound_id` |
| `set_paused(int, int)` | `paused_in`, `non_user_pause_in` |
| `get_mouse_info(WPARAM, LPARAM, tagPOINT&, int&, int&, int&, int&)` | `wparam`, `lparam`, `point`, `left_btn`, `right_btn`, `ctrl_key`, `shift_key` |
| `get_mouse_pos(tagPOINT&)` | `point` |
| `set_windows_mouse(int)` | `val` |
| `set_mouse_cursor(HCURSOR)` | `val` |
| `set_mouse_facet(long)` | `facet` |
| `wnd_proc(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_mouse_move(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_key_down(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_user_command(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_command(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_music_done(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_paint(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_activate(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_init_menu(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_exit_menu(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_size(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_palette_changed(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_query_new_palette(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_close(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `handle_destroy(HWND, UINT, WPARAM, LPARAM)` | `wnd`, `msg`, `wparam`, `lparam` |
| `set_game_options(RGE_Game_Options*)` | `options` |
| `playerHasCD(int)` | `player_num` |
| `playerVersion(int)` | `player_num` |
| `playerVersionString(int)` | `player_num` |
| `playerCDAndVersion(int)` | `player_num` |
| `playerTeam(int)` | `player_num` |
| `setVersion(float)` | `val` |
| `setScenarioName(char*)` | `n` |
| `setMapSize(int, int, int)` | `x`, `y`, `z` |
| `setPlayerHasCD(int, int)` | `player_num`, `has_cd` |
| `setPlayerVersion(int, unsigned char)` | `player_num`, `player_version` |
| `setPlayerCDAndVersion(int, unsigned char)` | `player_num`, `val` |
| `setDifficulty(int)` | `difficulty` |
| `setPlayerTeam(int, int)` | `player_num`, `team` |
| `setPathFinding(unsigned char)` | `val` |
| `setMpPathFinding(unsigned char)` | `val` |
| `set_map_visible(unsigned char)` | `flag` |
| `set_map_fog(unsigned char)` | `flag` |
| `GetChecksum(long)` | `player` |
| `GetWorldChecksums(long&, long&, long&)` | `new_checksum`, `new_position_checksum`, `new_action_checksum` |
| `check_prog_argument(char*)` | `argument` |
| `get_scenario_checksum(char*)` | `scenario_file` |
| `check_scenario_checksum(char*, long)` | `scenario`, `checksum` |
| `dump_memory_usage(char*)` | `file_name` |
| `playerID(int)` | `player_index` |
| `setPlayerID(int, int)` | `player_index`, `player_id` |
| `reset_countdown_timer(long)` | `in_countdown_player_id` |
| `set_countdown_timer(long, long)` | `in_countdown_player_id`, `in_countdown_timer` |
| `get_countdown_timer(long, long&)` | `out_countdown_player_id`, `out_countdown_timer` |
| `play_video(char*)` | `file_name` |
| `play_sound(int)` | `sound_id` |
| `set_game_speed(float)` | `val` |
| `set_single_player_difficulty(int)` | `val` |

No registry change is needed. The historical root request for
`STRING_ID_HELP_WINDOW_TITLE` (`0x03EB`) remains pending. This correction does not
resolve it. The source keeps numeric `0x3EB`. The destructor loads `0x03EB`
and passes the result to `FindWindowA("MS_WINHELP", str)`. The wave02 root
review records base text `Age of Empires Help` and missing expansion text.

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, validation, test, or game command was run for this assignment.
