# Source-cleanup report: `scr_game.cpp`

## Delivery

- Module: `src/scr_game.cpp`
- Header read: `include/scr_game.h`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Cleanup commit: `fcf4ac9da7d74531e4012e0b60bf06047e83f329`
- Source layout correction commit: `d12cc4a7c2a7b0bdf26df0df6d4d61db2b87ec35`
- Source brace correction commit: `3415854c8d148ce993b285c57c4e68639fe54362`
- Report correction commit: `0adf5675caeeb2df4edf1c223235f6321776378a`
- Correction-hash record commit: `b08bf0343d663cc66c26e8d04e12900c6da39a02`
- Hotkey-payload correction commit: `2c102c6dc0fa08035493388370fc6faa8a9617dd`
- Approved resource substitution commit: `f8db2f87fe8e5745284d4c9986ccc464f9883d7f`
- Changed files: `src/scr_game.cpp` and this report only.
- Header owner: owner 21 owns `include/scr_game.h`. This worker did not edit it.
- Shared resource owner: root owns `include/resource_ids.h`. This worker did not edit it.

The cleanup restores procedure-scoped PDB names and improves local layout. It
keeps the existing source owner, calls, casts, types, scopes, storage, source
order, and resource lookup calls. It adds no comments or shared declarations.

## Function coverage

The module registry contains 96 normal owners. I checked all 96 source
functions against the scoped PDB records. The PDB also contains the compiler-
generated scalar deleting destructor at `00495450`; it has no handwritten
source owner and was not edited. The PDB entries for `TRIBE_Main_View` in the
same object file are outside this module.

### Recovered PDB names

These names now match the owning PDB records. Mixed original spelling remains
unchanged.

| VA | Function | Recovered names |
| --- | --- | --- |
| `004959A0` | `set_redraw` | `redraw_mode` |
| `004959B0` | `set_overlapped_redraw` | `redraw_panel`, `calling_panel`, `redraw_mode`; existing locals `dialog`, `this_rect`, `other_rect` remain |
| `00495A90` | `set_map_buttons_redraw` | `redraw_mode` |
| `00495AE0` | `handle_size` | `win_wid`, `win_hgt`; existing `save_score_active` remains |
| `00496550` | `handle_paint` | `draw_all_children`, `other_time` |
| `00496800` | `handle_game_update` | `calc_game_time`, `num_updates`, `update_counter` |
| `004970A0` | `wnd_proc` | `hwnd`, `msg`, `wParam`, `lParam` |
| `00497210` | `handle_mouse_down` | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key` |
| `00497280` | `handle_user_command` | `wParam`, `lParam` |
| `00497330` | `handleChatReceived` | `line_no`; existing `chat_msg` remains |
| `004973F0` | `display_system_message` | `msg` |
| `00497440` | `key_down_action` | `key`, `count`, `alt_key`, `ctrl_key`, `shift_key`; existing `game_over` and `str` remain |
| `00498290` | `char_action` | `key`, `count` |
| `004982E0` | `action` | `from_panel`, `action_in`, `action_val1`, `action_val2` |
| `004987A0` | `do_button_action` | `action_in`, `action2_in`, `right_btn` |
| `00498A10` | `game_mode_changed` | `old_mode`, `new_mode` |
| `00498A50` | `player_changed` | `old_player_id`, `new_player_id`; existing `str` remains |
| `004994B0` | `show_timings` | `str1`, `str2` |
| `00499520` | `show_comm` | `str`, `str2`, `str3`, `str4`, `str5`, `str6` |
| `004995D0` | `show_ai` | `str`, `str2`, `str3`, `str4`, `str5`, `str6` |
| `00499680` | `show_message` | `message_type`, `str`, `font_color_in`, `back_color_in` |
| `004996C0` | `setup_buttons` | `tc_num`, `range_num`, `any_more`, `btn_loc`, `all_moveable_units`, `j`, `tech_cnt`, `make_cnt`, `button`, `i`, `work_target`, `player`, `work_type`, `progress`, `inv_1`, `inv_2`, `inv_3`, `inv_amt_1`, `inv_amt_2`, `inv_amt_3` |
| `0049A8F0` | `calc_text_msg` | `msg_str`, `item`, `button_action_id`, `message_string_id`, `cost_str`, `cost_str3`, `command_str`, `cost_str1`, `cost_str2`, `inven_str` |
| `0049AB10` | `calc_button_loc` | `button_loc` |
| `0049AB60` | `set_button` | `buttons`, `button`, `pic_index`, `id`, `id2`, `help_string_id`, `help_page_id`, `hotkey`, `color_table`, `text2`, `text_msg`, `make_disabled`; existing `text1` remains |
| `0049ADA0` | `reset_clocks` | `found`, `countdown_timer` |
| `0049B000` | `scr_game_score_compare` | `arg1`, `arg2` |
| `0049B560` | `draw` | `save_clip_rect` |
| `0049BC60` | `command_add_attribute` | `attr_id` |
| `0049BDB0` | `command_building` | `id`; existing `msg` and `attr` remain |
| `0049C300` | `command_game_speed` | `increase_speed`, `new_speed`, `cur_speed`; existing `msg` remains |
| `0049C570` | `command_group_by_number` | `id` |
| `0049C650` | `command_score` | `show` |
| `0049C710` | `command_select_group` | `id`, `unsel_prior` |
| `0049CA10` | `command_player` | `id` |
| `0049CAF0` | `command_research` | `id`; existing `msg` and `attr` remain |
| `0049CCB0` | `command_select_building` | `id` |
| `0049CEB0` | `command_trade_with` | `id` |
| `0049CEC0` | `command_train` | `id`, `train_count`; existing `msg` and `attr` remain |
| `0049D290` | `command_formation` | `formationID` |
| `0049D340` | `command_trade_attribute` | `attribute` |
| `0049D370` | `command_tab_selected` | `forward` |
| `0049D4B0` | `set_focus` | `have_focus_in` |
| `0049D540` | `add_log` | `text` |

Names already matching the PDB were kept in the remaining functions. This
includes `TRIBE_Screen_Game` constructor locals `sound`, `i`, `font`,
`num_game_players`, and `str`; `age_changed::str`; `command_move` and
`command_work` locals `list` and `list_num`; and the `reset_score_display`
locals that already have direct source declarations.

The source also replaces generated loop names with new descriptive cleanup
names where no PDB name maps reliably. Examples include `button_index`,
`building_index`, `item_index`, `base_master`, `master`, `make_index`,
`tech_index`, `queue_count`, `allied_player_num`, and `score_index`. These are
new cleanup names, not recovered original names. The PDB names above are
recovered names.

### Unresolved mappings

- `setup_buttons` has reused PDB slots. `temp_value` has no safe direct source
  declaration. The source keeps the existing declarations and does not force
  that name onto `tc_num`, `make_disabled`, or an inventory temporary.
- `setup_buttons` PDB types for `tc_num`, `range_num`, and `btn_loc` are wider
  than the existing source declarations. The cleanup restores names only. It
  keeps the existing `short` and `unsigned char` types.
- `setup_buttons` records `all_moveable_units` as `unsigned char`, while the
  existing source declaration is `bool`. The cleanup does not change that type.
- `reset_score_display` has a PDB name `low_fps_player`, but the existing
  source has no direct declaration with a proven one-to-one mapping. The source
  keeps `best_speed` and the existing score assignment. It does not force the
  PDB name.
- `set_button` has a PDB parameter named `button` and a source pointer local.
  The source keeps the local as `button_panel` to avoid a collision.
- Header declarations in `include/scr_game.h` remain unnamed. The header owner
  should review the cleaned definition names. This request does not change any
  type, calling convention, class layout, or ABI symbol.

### PDB evidence

The main evidence is the module-scoped PDB inventory:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The function packets used for the two highest-risk mappings are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/004996C0_setup_buttons.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/0049B000_scr_game_score_compare.txt`

The existing module note is `decomp_notes/scr_game.md`. It records the natural
source owner and the prior accepted-drift limits. The score comparator keeps
its original stack argument order: `arg1` is cast to `b`, and `arg2` is cast to
`a`, as in the existing comparator body.

## Resource-ID review and approved substitutions

This section first records the worker requests. Root later approved the
payload-backed names in `include/resource_ids.h` at commit
`f5b7d6668f785b97811119493bea0e04403d1d10`. The source now uses those approved
macros. Root owns the shared header, so this worker did not edit it.

The approved names are cleanup names, not original macro names. Numeric
expressions and lookup calls remain unchanged.

`TRIBE_Game::get_string` first calls `LoadStringA` on `StringTableX` and then
falls back to `RGE_Base_Game::get_string`. The runtime files checked were:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

The first two files are the staged runtime inputs. The third file is the
checked original XPack evidence. The extraction output is in the worker build
folder:

- `build/scr_game_language_strings.json`
- `build/scr_game_languagex_strings.json`
- `build/scr_game_language_misc.json`

The exact `RT_STRING` payloads below use language `0x0409` (`1033`). The
language-X file has empty entries for several hotkey IDs. Those entries fall
back to the base language file. Missing entries are not treated as empty
entries.

### Base-language strings

| ID or range | Exact base text | Call-site purpose | Proposed cleanup name |
| --- | --- | --- | --- |
| `0x1023` | `S` | Score button label | `IDS_SCORE_BUTTON_LABEL` |
| `0x1024` | `Score (F4)` | Score button message text | `IDS_SCORE_BUTTON_MESSAGE` |
| `0x1037` | `B` | Build command hotkey | `IDS_HOTKEY_BUILD` |
| `0x1038` | `S` | Stop command hotkey | `IDS_HOTKEY_STOP` |
| `0x1039` | `G` | Group command hotkey | `IDS_HOTKEY_GROUP` |
| `0x103A` | `U` | Ungroup command hotkey | `IDS_HOTKEY_UNGROUP` |
| `0x103B` | `X` | More command hotkey | `IDS_HOTKEY_MORE` |
| `0x103C` | Empty slot | No reviewed source call; no macro request | None |
| `0x103D` | `D` | Stand-ground command hotkey | `IDS_HOTKEY_STAND_GROUND` |
| `0x103E` | `T` | Attack-ground command hotkey | `IDS_HOTKEY_ATTACK_GROUND` |
| `0x103F` | `H` | Town-center view hotkey | `IDS_HOTKEY_VIEW_TOWN_CENTER` |
| `0x1040`–`0x1047` | `N`, `B`, `D`, `A`, `K`, `L`, `P`, `Y` | Eight `command_select_building` hotkeys | `IDS_HOTKEY_SELECT_BUILDING_BASE` with the existing `+ i` range |
| `0x1048` | `E` | Heal command hotkey | `IDS_HOTKEY_HEAL` |
| `0x1049` | `C` | Convert command hotkey | `IDS_HOTKEY_CONVERT` |
| `0x104A` | `M` | Move command hotkey | `IDS_HOTKEY_MOVE` |
| `0x104B` | `W` | Work command hotkey | `IDS_HOTKEY_WORK` |
| `0x104C` | `A` | Attack command hotkey | `IDS_HOTKEY_ATTACK` |
| `0x104D` | `R` | Repair command hotkey | `IDS_HOTKEY_REPAIR` |
| `0x104E` | `L` | Unload command hotkey | `IDS_HOTKEY_UNLOAD` |
| `0x1069` | `Stone Age` | Stone Age help string | `IDS_HELP_AGE_STONE` |
| `0x106A` | `Tool Age` | Tool Age help string | `IDS_HELP_AGE_TOOL` |
| `0x106B` | `Bronze Age` | Bronze Age help string | `IDS_HELP_AGE_BRONZE` |
| `0x106C` | `Iron Age` | Iron Age help string | `IDS_HELP_AGE_IRON` |
| `0x0BE0` | `Click an area to move there.` | Move-command status message | `IDS_MESSAGE_MOVE` |
| `0x0BE1` | `Click an item or unit to work on it.` | Work-command status message | `IDS_MESSAGE_WORK` |
| `0x0BE2` | `Click the item or unit to attack.` | Attack-command status message | `IDS_MESSAGE_ATTACK` |
| `0x0BE3` | `Click the unit to heal.` | Heal-command status message | `IDS_MESSAGE_HEAL` |
| `0x0BE4` | `Click the unit to convert.` | Convert-command status message | `IDS_MESSAGE_CONVERT` |
| `0x0BE5` | `Click an area to attack ground.` | Attack-ground status message | `IDS_MESSAGE_ATTACK_GROUND` |
| `0x0BEC` | `Click the building or boat to repair.` | Repair-command status message | `IDS_MESSAGE_REPAIR` |
| `0x0BED` | `Click where you want the transport to unload.` | Unload-command status message | `IDS_MESSAGE_UNLOAD` |
| `0x0BF3` | `Game speed changed.` | Multiplayer speed-change message | `IDS_GAME_SPEED_CHANGED` |
| `0x0BF4` | `Game paused/unpaused.` | Multiplayer pause message | `IDS_MESSAGE_GAME_PAUSED` |
| `0x0BFE` | `You cannot chat after you have resigned or been defeated.` | Chat restriction error | `IDS_ERROR_CHAT_AFTER_DEFEAT` |
| `0x2329` | `GAME PAUSED` | Pause overlay | `IDS_GAME_PAUSED` |
| `0x232E` | `Game over. Click Menu/Quit Game to exit.` | Quit overlay | `IDS_GAME_OVER_MESSAGE` |
| `0x4E25` | `Inventory` | Inventory panel help | `IDS_HELP_INVENTORY` |
| `0x4E33` | `Diamond Map` | Diamond-map panel help | `IDS_HELP_DIAMOND_MAP` |
| `0x4E35` | `Age` | Age panel help | `IDS_HELP_AGE` |
| `0x4E43` | `Ungroup Button` | Ungroup button help | `IDS_HELP_UNGROUP_BUTTON` |

The base file returns `?` for `0x0FA9`. The source uses that ID as the text
for button panel 15. The text is known, but this pass does not establish a
more exact button purpose. Keep `0x0FA9` numeric until the owner reviews it.

The base file has no `RT_STRING` entries for the help-string and help-page IDs
below. The call sites establish their help role through `set_help_info` or
`set_button`, but they do not establish English text. These are proposed
names only. The missing text does not block a purpose-based name if root
accepts the help-resource namespace.

| ID | Call-site role | Proposed cleanup name |
| --- | --- | --- |
| `0x19BB8` | Inventory panel help string | `IDS_HELP_INVENTORY_STRING` |
| `0x265AC` | Inventory panel help page | `IDS_HELP_INVENTORY_PAGE` |
| `0x1A25C` | Trade-attribute button 0 help string | `IDS_HELP_TRADE_ATTRIBUTE_0` |
| `0x1A25D` | Trade-attribute button 1 help string | `IDS_HELP_TRADE_ATTRIBUTE_1` |
| `0x1A25E` | Trade-attribute button 2 help string | `IDS_HELP_TRADE_ATTRIBUTE_2` |
| `0x265AF` | Trade-attribute help page | `IDS_HELP_TRADE_ATTRIBUTE_PAGE` |
| `0x1D4CD` | Menu button help | `IDS_HELP_MENU` |
| `0x1D4CF` | Chat button help | `IDS_HELP_CHAT` |
| `0x1D4D1` | Diplomacy button help | `IDS_HELP_DIPLOMACY` |
| `0x1D4D7` | More button help | `IDS_HELP_MORE` |
| `0x1D4D9` | Cancel button help | `IDS_HELP_CANCEL_COMMAND` |
| `0x1D4DB` | Help button help | `IDS_HELP_HELP` |
| `0x1D4DC` | Score button help | `IDS_HELP_SCORE` |
| `0x1D4DD` | Stop button help | `IDS_HELP_STOP` |
| `0x1D4DF` | Build button help | `IDS_HELP_BUILD` |
| `0x1D4E1` | Group button help | `IDS_HELP_GROUP` |
| `0x1D4E3` | Ungroup button help | `IDS_HELP_UNGROUP_ALTERNATE` |
| `0x1D4E5` | Cancel-building button help | `IDS_HELP_CANCEL_BUILDING` |
| `0x1D4E9` | Unload button help | `IDS_HELP_UNLOAD` |
| `0x1D4EA` | Stand-ground button help | `IDS_HELP_STAND_GROUND` |
| `0x1D4EB` | Attack-ground button help | `IDS_HELP_ATTACK_GROUND` |
| `0x1D4F1` | Heal button help | `IDS_HELP_HEAL` |
| `0x1D4F2` | Convert button help | `IDS_HELP_CONVERT` |
| `0x1D4F6` | Repair button help | `IDS_HELP_REPAIR` |

The proposed help names remain new cleanup names. The source call sites prove
their button roles, but the checked language DLLs provide no text for them.

### Root approval and runtime evidence

Root approved the payload-backed names in commit
`f5b7d6668f785b97811119493bea0e04403d1d10`. The approved header adds the
score labels, hotkeys, age labels, command messages, overlay labels, and panel
help names used below. The source applies these approved names in commit
`f8db2f87fe8e5745284d4c9986ccc464f9883d7f` and includes
`../include/resource_ids.h`.

The source substitutions are:

- `0x1023` and `0x1024`: `IDS_SCORE_BUTTON_LABEL` and
  `IDS_SCORE_BUTTON_MESSAGE`.
- `0x1037`–`0x103B`, `0x103D`–`0x103F`, and `0x1048`–`0x104E`: the matching
  `IDS_HOTKEY_*` names. The source keeps `i +
  IDS_HOTKEY_SELECT_BUILDING_BASE` for the `0x1040` range.
- `0x1069`–`0x106C`: the four `IDS_HELP_AGE_*` names.
- `0x0BE0`–`0x0BE5`, `0x0BEC`, `0x0BED`, and `0x0BF4`: the matching
  `IDS_MESSAGE_*` names.
- `0x0BF3` uses the existing `IDS_GAME_SPEED_CHANGED` name.
- `0x0BFE`, `0x2329`, `0x232E`, `0x4E25`, `0x4E33`, `0x4E35`, and `0x4E43`:
  the approved error, overlay, and panel-help names.

The source keeps `0x0FA9` numeric. It also keeps the purpose-only missing-help
IDs numeric. No macro is requested for the empty and unused `0x103C` slot.

The resource evidence uses language `0x0409` (`1033`) and these absolute
inputs:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

The staged base language file contains the exact texts in the base-language
table. The pinned original tree has no base language file, so the staged base
file is the base payload evidence.

The staged runtime expansion has empty slots at `0x1023`, `0x1024`, and
`0x1040`–`0x104E`; it also has empty slots at `0x242D`–`0x242F` and at
`0x2800`, `0x2801`, `0x2802`, and `0x2804`. The original expansion has the
same empty slots except that `0x242D`–`0x242F` are missing. Both expansion
files supply `Roman`, `Carthaginian`, `Macedonian`, and `Palmyran` at
`0x2806`–`0x2809`. The base slots for those four IDs are empty.

`TRIBE_Game::get_string` checks the expansion string table first and falls
back to the base game string lookup when the expansion result is missing or
empty. Thus the approved empty expansion slots use the staged base strings,
while the expansion civilization strings at `0x2806`–`0x2809` take priority.
Missing and empty entries do not supply invented text.

## Constants, comments, and output risk

- No new comments were added.
- No numeric constant was changed.
- Root defined the approved resource macros. This worker applied them only in
  `src/scr_game.cpp`.
- No declaration type, cast, class layout, calling convention, ABI symbol,
  call target, relocation expression, control-flow statement, or source order
  was intentionally changed.
- The source correction restores the common-base `setup_buttons` layout. Its
  control flow, declaration scopes, statement order, and expressions now
  differ from the base only through supported identifier names and formatting.
- The brace correction removes four extra braces from the earlier 1TBS edit.
  They surrounded existing standalone `else` lines. The common-base brace
  structure is now restored.
- `command_game_speed` now uses the PDB names `new_speed` and `cur_speed` for
  the existing target and current speed roles. The comparisons and command
  calls keep their original order.
- Formatting moves opening braces to 1TBS form and joins short signatures. It
  does not add or remove braces or statements.
- The final compiler output is unvalidated. Name and line-record changes can
  affect debug metadata even when executable tokens remain equivalent.

## Shared-file requests and questions

1. Owner 21 should review parameter names for `include/scr_game.h` from the
   definitions listed above. Keep declarations unnamed if the owner finds a
   reason to defer them.
2. Root approved the base-language ID requests in
   `include/resource_ids.h`. The source preserves the `i +
   IDS_HOTKEY_SELECT_BUILDING_BASE` range.
3. Root should decide whether the missing RT_STRING help IDs belong in the
   shared base-language namespace or a separate help-resource namespace.
4. Root should review the unresolved `temp_value` and `low_fps_player` PDB
   records before any later structural recovery work.

## Validation status

Allowed checks run:

- Read the complete assigned source, header, module registry, PDB entries,
  function packets, module note, cleanup guides, and resource-ID guide.
- Ran `python tools/inspect_pe_strings.py --help` before resource extraction.
- Extracted the listed IDs from the staged runtime language DLLs.
- Ran `git diff --check` and reviewed the complete source diff.
- Reviewed the complete correction diff against base commit
  `76037279ee11dde077bb7d55aeb46b518b2bb27c`, with special attention to
  `setup_buttons`.
- Compared normalized source tokens against the base. Both files contain
  29,691 tokens, with no non-identifier token difference.

Not run, as required by the wave contract:

- Compilation or build.
- Function matching.
- Audits.
- Automated tests.
- Menu or gameplay tests.
- Game execution.

No byte-equality, semantic-approval, compiler, or runtime-validation claim is
made from this review.
