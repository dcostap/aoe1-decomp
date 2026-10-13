# Linked data findings, 2026-10-13

The first linked pairing ran on `build/noref-build/20261013T021925797320Z`; see
[linked image comparison](../docs/linked_image_diff.md). Each finding below is data that an exact function addresses.
The function's instructions match, so the rebuilt game read different data at that point. All findings below are
fixed. Rerun `tools/diff_linked_image.py` and read `linked_checks.csv`, `linked_pairs.csv`, and `linked_items.csv`
for the current state.

## Switch tables

Registry sizes end before a function's jump tables, so the function audit never compared them. The linked pairing now
does. Seven exact functions had matching code bytes but a different case-to-block table:

- `RGE_Action_List::get_action_name` (`004048C0`) and `TRIBE_Action_List::get_action_name` (`004D0C50`): the case
  order differed. Each action type still got its own name, but the table differed. The cases are now in the
  original order.
- `TScrollBarPanel::handle_idle` (`0047ACC0`): state 3, the tab drag, scrolled up a page. The original ignores it,
  and only state 4 tests the top rectangle and scrolls.
- `TRIBE_Action_Convert::set_state` (`004CDE10`): states 8, 9, 10, and 12 set the master sprite. The original only
  returns.
- `TRIBE_Panel_Time::handle_idle` (`0051E150`): clock type 0 now returns at once, without the redraw check.
- `Time_Line_Panel::draw_icon` (`00520AE0`): events 4, 5, and 7 now clear `text1`.
- `TRIBE_Game::notification` (`00524D70`): notify types 2 and 3 showed each other's message. The earlier "original
  bug" note about swapped transport messages was wrong; see [game notifications](game_notifications.md).

## Data defects

- `game_globals`: the PathingSystem constructor read the √2 scale where the original reads −16.0, and the reverse.
  VC5 multiplies by the later-declared global first, so `include/game_globals.h` now declares the sign before the
  scale.
- `com_hand`: the function-local `Sequence` in `TCommunications_Handler::GetNextSequence` is zero-filled in the
  original (`0062CF2C`). The rebuild started it at 1.
- `basegame` `RGE_Base_Game::close` (`004200B0`): the original sends `WM_CLOSE` with `SendMessageA`. The rebuild
  used `PostMessageA`.
- `AIModule::AIModule` (`0040E2D0`) starts the player name as `"Unknown"`, not `""`.
- `RGE_Communications_Addresses::GetAddress` and `GetAlias`, and `TCommunications_Handler::PackPlayersDown`, use
  `" "` (a single space) where the rebuild used `""`.
- `TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario` (`004AE9D0`) shows `"0"` for an unset victory value,
  not `""`.
- `RGE_Game_World::update_mutual_allies` prints `RemoveVisibleBits` with `"%8.8x"`, not `"%d"`.
- `TRIBE_Panel_Button::draw` releases its garrison DC as `tpnl_inv::draw2`.

## Log and diagnostic text

About 70 strings were guessed or abbreviated. They now match the original text:

- truncated format strings, in `aibldmod`, `basegame`, `com_hand`, `com_q`, `com_spd`, `tact_mob`, `taibldmd`,
  `taitacmd`, and `tcommand`. The pushed arguments were already right; only the text was short;
- reworded strings, such as `world` (`  Player #%d Lost.`), `com_hand` (`DP Open Create`), `com_err` (two messages
  swapped), `drawarea` (`Back Buffer`, `Primary Surface`), `rmm_tdbc` (`elevation`), and `cdaudio`
  (`Unknow Error`);
- source path strings: `Pnl_scbr.cpp` and `scr_cj.cpp` now use full `C:\msdev\work\age1_x1\...` paths, and
  `tpnl_obj` uses `tpnl_obj::draw_item`;
- `tribegam` sync text starts with `, `;
- `act_obj` writes a newline, not a literal `\n`;
- `move_obj` path traces end without a newline, and `TXResendRequest` logs `!!!GetNextSequence slow - %ld msec`, as
  the original does.

## Validation

- Full function audit before and after: 5,013 exact, and every row's result and byte counts unchanged.
- Linked image diff on `build/fixdata-final/20261013T175927175018Z`: 270 switch tables, 23,495 function fields,
  786 import fields, and 270 internal labels pass. Paired items: 2,210 equal, 257 zero-fill, 2 tail-unproved, and
  no different or conflicting items.

## Layout differences that remain

- 148 splits: the original keeps one copy where the rebuild has two. The original linker shares identical string
  literals across modules, such as `"%d"`, `"Unknown"`, and the version strings. Most others are `$T`
  floating-point temporaries that duplicate a `game_globals` constant.
- 2 `tail_unproved` `$T` constants: the compared value agrees, but the item size is not proved.

These do not change what an exact function reads. They matter for a matching image layout.
