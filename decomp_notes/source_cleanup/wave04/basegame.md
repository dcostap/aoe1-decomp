# `src/basegame.cpp` source-cleanup report

## Scope and commits

- Module: `src/basegame.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `e2add30e8ef690448fd884c6a2c2fae024e624ed`
- Changed files: `src/basegame.cpp` and this report.
- Header owner: this worker did not edit any header.
- Registry: `config/functions/src/basegame.cpp.json`.

The original behavior reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
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

## Code-generation risks and validation

The source changes recover parameter and local spellings. They do not change
ABI names, types, object layout, storage duration, call targets, relocations,
control flow, evaluation order, or resource behavior. The static buffer rename
keeps its type and file scope. The comment can affect debug line records, as
expected for source cleanup.

No shared-file request is open. No header or registry change is needed.

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, validation, test, or game command was run for this assignment.
