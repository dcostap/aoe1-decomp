# `scr_sed.cpp` source cleanup

## Delivery

- Module: `src/scr_sed.cpp`
- Worktree: `slot-183`
- Branch: `cleanup/staging-20260915-183`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- PDB name cleanup commit: `03c9158e16142b5e246a646d0e08605d2e3f924a`
- Formatting correction commit: `785eac73d03094f363c74d56d381c635c844c0ca`
- Changed files:
  - `src/scr_sed.cpp`
  - `decomp_notes/source_cleanup/wave03/scr_sed.md`
- Base source SHA256: `542e902be520698310c53f801e7235480cf3f9ead58e83ef737ef652db336873`
- Final source SHA256: `dbf43378bdb03e5f6bb2216dd8927366377e662365bea094bcb8ce95a5e24e22`

The source commits contain only the assigned source. The report is the second
assigned file and has its own delivery commit.

## Scope and evidence

The registry is `config/functions/src/scr_sed.cpp.json`. It lists 47 normal
owners. Every registry VA has one procedure record in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Every record names module object `.\\Release\\scr_sed.obj`.

The registry has 41 `matching` rows and six `accepted_drift` rows. This cleanup
did not change those statuses. The six accepted-drift VAs are:
`004A8A60`, `004A9CC0`, `004AA730`, `004AB300`, `004AB670`, and `004ABCD0`.

The selected baseline packet is:

- Object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/scr_sed.obj`
- SHA256: `b370df85cfbbe919258401e17e8f8842b02c9b4ad2b7dae68bdf3b90e723fc91`
- Registry build report: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`
- Source input SHA256 in that report: `542e902be520698310c53f801e7235480cf3f9ead58e83ef737ef652db336873`
- Flags: `config/flags/gx.rsp`
- Flags content: `/nologo /c /O2 /Oy /GX`

I read the pinned toolchain configuration, CRT `FCNTL.H`, and SDK `WINUSER.H`.
No numeric CRT or SDK constant changed. The PDB extraction was kept in the
ignored worker path `build/evidence/scr_sed_pdb.json`.

## PDB name recovery

The PDB records supplied names for all parameters and recorded locals. I
restored names when the current declaration mapped to the record. I preserved
current types, scopes, storage, and statement order.

Recovered names by procedure:

| VA | Procedure | Recovered names |
| --- | --- | --- |
| `004A81E0` | constructor | `scenario_name_in`, `is_multi_player_in`; existing `name`, `temp_name` retained |
| `004A8770` | `set_panel_info` | no scoped parameters or locals |
| `004A87D0` | `set_string` | `text`, `text_id`, `max_size` |
| `004A87F0` | `create_button(long)` | `parent`, `button`, `text_id`, `ButtonSelectFlag`, `str1` |
| `004A8840` | `create_button(char*)` | `parent`, `button`, `text1`, `text2`, `text3`, `text4` |
| `004A8910` | `create_text(long)` | `parent`, `text_panel`, `text_id` |
| `004A8960` | `create_text(char*)` | `parent`, `text_panel`, `text` |
| `004A89B0` | `create_input` | `parent`, `input_panel`, `value`, `max_len`, `format_type` |
| `004A8A00` | `create_edit` | `parent`, `edit_panel`, `value`, `max_len`, `format_type`, `enable_ime`, `turn_ime_on` |
| `004A8A60` | `create_drop_down` | `parent`, `drop_panel` |
| `004A9320` | `SetupListOfTerrain` | existing `list` retained |
| `004A93C0` | `create_list` | `parent`, `list_panel`, `scrollbar_panel`; existing `str1`, `str2` retained |
| `004A94A0` | destructor | no scoped parameters or locals |
| `004A9CC0` | `set_scenario_mode` | `new_mode`, `mode`, `activate_counter`; existing `i` retained |
| `004AA730` | `set_paint_object_mode` | no scoped parameters or locals |
| `004AA7A0` | `set_map_type` | `new_val`, `activate_panels` |
| `004AA8F0` | `set_mp_victory_type` | `new_val`, `activate_panels`, `activate_counter` |
| `004AAA90` | `set_brush_size` | `new_val` |
| `004AAB60` | `set_paint_type` | `new_val`, `activate_panels`, `activate_counter`, `val` |
| `004AAD50` | `set_terrain` | `val` |
| `004AADF0` | `set_elevation` | `val` |
| `004AAE20` | `set_player` | `val`, `save_player`, `load_player`, `amount`; existing `str` retained |
| `004AB2B0` | `set_player_active` | `player_num_in`, `active_in` |
| `004AB2D0` | comparator | `arg1`, `arg2` |
| `004AB300` | `set_unit_player` | `val`, `list`, `i`, `is_error` |
| `004AB670` | `set_unit` | `val` |
| `004AB6E0` | `set_message_type` | `new_val`, `activate_panels` |
| `004AB710` | `handle_size` | `win_wid`, `win_hgt` |
| `004AB740` | `handle_idle` | no scoped parameters or locals |
| `004AB7D0` | `key_down_action` | `key`, `count`, `alt_key`, `ctrl_key`, `shift_key` |
| `004ABCD0` | `action` | `from_panel`, `action_in`, `action_val1`, `action_val2`, `y2`, `y1`, `x2`, `x1`, `cy`, `cx`, `msd`, `map_size`, `random_val`, `old_seed` |
| `004AD0F0` | `draw` | `rect` |
| `004AD240` | `command_cancel` | no scoped parameters or locals |
| `004AD270` | `command_menu` | no scoped parameters or locals |
| `004AD300` | `command_new` | no scoped parameters or locals |
| `004AD340` | `command_new_map` | existing `scenario_name_in`, `is_multi_player_in`, `random_seed_in`, `width`, `height`, `display_in`, `player_info`, `tribe`, `map_info` retained |
| `004AD590` | `command_open` | no scoped parameters or locals |
| `004AD630` | `command_outline` | existing `outline_type` retained |
| `004AD680` | `command_player` | `id` |
| `004AD6A0` | `command_quit` | no scoped parameters or locals |
| `004AD700` | `command_save` | `kill_menu`, `quit_after_save`; existing `temp_name` retained |
| `004AD960` | `command_save_as` | `quit_after_save`; existing `scenario_name` retained |
| `004ADA70` | `scenario_get_default_name` | existing `temp_name` retained |
| `004ADAF0` | `command_quick_save` | no scoped parameters or locals |
| `004ADB10` | `scenario_save_defaulted` | existing function-static `temp_name` retained |
| `004ADC30` | `need_to_save` | no scoped parameters or locals |
| `004ADC40` | `set_focus` | `have_focus_in` |

The PDB also records `this` in the ECX register for every member procedure.
The comparator has no register record. No public function or ABI symbol changed.

## Unresolved mappings

- `004A8A60` records locals `player`, `end_i`, and `str`. The current source
  has no matching declarations. I did not add declarations.
- `004A9CC0` records `mode` as `ScenarioMode`. The current declaration is an
  existing `int`; I restored the name but did not change its type. The current
  `active` local has no separate PDB record. I did not merge or remove it.
- `004AB300` reuses stack slots for `j`, `save_map_y`, `default_item`,
  `end_i`, `save_view_x`, and `is_error`. The current `save_map_x`, `out`,
  and traversal locals do not map uniquely to those aliases. I restored only
  `val`, `list`, `i`, and `is_error`.
- `004ABCD0` reuses argument slots for `cy`, `cx`, `msd`, `map_size`, and
  `old_seed`. The current extra selection locals have no reliable PDB mapping.
  I restored only the direct parameter and local mappings listed above.
- Procedures with no PDB stack symbol retain their existing local names unless
  the PDB gave a direct local record.

`player_line` in `set_scenario_mode` is a new descriptive cleanup name. It
replaces the generated `lVar5` name. It is not claimed as an original name.
All names in the recovery table come from the procedure-scoped PDB unless
marked existing or inferred.

## Constants, comments, and resources

No constant changed. No new comment was added. Existing comments remain in
place. No resource ID literal changed, and no new resource macro was requested.
The source leaves numeric resource IDs unchanged until root reviews shared
`include/resource_ids.h`. Therefore there are no new resource IDs to report
with DLL text, language, or lookup paths for this commit. The root owner still
owns that header and all shared resource declarations.

No header request is pending. In particular, I did not edit
`include/scr_sed.h`, `include/resource_ids.h`, or any other header.

## Formatting correction

The follow-up source commit reformats `src/scr_sed.cpp` with 1TBS style. It
puts function and control opening braces on the same line, uses `} else {`,
and corrects indentation. It keeps short signatures and calls on one line
when readable.

The correction changes whitespace and brace placement only. Token and comment
sequence, brace counts, literals, calls, scopes, and statement order remain
unchanged. No header or source file other than `src/scr_sed.cpp` changed.

The complete source diff was reviewed. Validation was limited to formatting
review and token-preservation comparison. No build, compiler, matching, audit,
test, or game run was performed. Final validation must compare generated code,
data, relocations, call targets, and boundaries against the preserved baseline
object.

## Risk and validation limits

The source changes rename parameters and locals, then apply whitespace-only
formatting. They do not intentionally alter layout, types, storage, control
flow, literals, calls, or symbol identity. The accepted-drift status remains
unvalidated after this cleanup.

No compilation, matching, audit, or test was run. No build or game was run.
Final validation must compare generated code, data, relocations, call targets,
and boundaries against the preserved baseline object.
