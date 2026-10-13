# Linked data findings, 2026-10-13

The first linked pairing ran on `build/noref-build/20261013T021925797320Z`; see
[linked image comparison](../docs/linked_image_diff.md). Each finding below is a data item that an exact function
addresses. The function's instructions match, so the rebuilt game reads different data at that point. Rerun
`tools/diff_linked_image.py` and read `linked_items.csv` and `linked_checks.csv` for the current list.

## Behavior defects

- `game_globals`: `g_path_diagonal_scale` holds −16.0 and `g_path_diagonal_sign` holds √2 in the original
  (`00570E4C` and `00570E48`). The rebuild has the two values swapped, so the path code reads the wrong constant.
- `com_hand`: the function-local `Sequence` in `TCommunications_Handler::GetNextSequence` is zero-filled in the
  original (`0062CF2C`). The rebuild initializes it to 1.
- `act_list` and `tact_lst`: the action and task name tables return different strings for the same entry. For
  example, the original's `0057F08C` is `MoveTo`, and the rebuild's paired string is `Bird`. The strings exist in both
  images; the source assigns them to the wrong entries.
- `basegame` `RGE_Base_Game::close` (`004200B0`): the import field at offset 12 addresses `SendMessageA` in the
  original. The rebuild calls `PostMessageA`.

## Wrong log and diagnostic text

About 70 strings differ in text. The original is the reference; the rebuilt text was guessed or abbreviated:

- truncated format strings, which also drop arguments from the output, such as `aibldmod` build-list dumps,
  `basegame` timing output, `com_hand`, `com_q`, `com_spd`, `tact_mob`, `taibldmd`, `taitacmd`, and `tcommand`;
- reworded strings, such as `world` (`  Player #%d Lost.`), `com_hand` (`DP Open Create`), `com_err` (two messages
  swapped), `drawarea` (`Back Buffer`, `Primary Surface`), `rmm_tdbc` (`elevation`), and `cdaudio` (`Unknow Error`);
- source path strings: `Pnl_scbr.cpp` and `scr_cj.cpp` are full `C:\msdev\work\age1_x1\...` paths in the original,
  and `tpnl_obj` names `tpnl_obj::draw_item`;
- `tribegam` sync text starts with `, ` in the original;
- `act_obj` writes a literal `\n` (backslash and n) where the original has a newline.

## Layout differences

- 152 splits: the rebuild has two copies of an item where the original has one. Most are `$T` floating-point
  temporaries in a module that duplicate a `game_globals` constant, and static strings.
- 6 conflicts: the original keeps several copies where the rebuild has one, such as the empty string `""`.
- 2 `tail_unproved` `$T` constants: the compared value agrees, but the item size is not proved.

These differences do not change what an exact function reads. They matter for a matching image layout.
