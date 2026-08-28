# Terra 5 T_Scenario/BaseGame composition

## Scope

This note records the Base Game owner repair for the T_Scenario fanout.
The change starts from main commit `0f7a8622f`.

## Owner evidence

The PDB source map assigns `0041C240 RGE_Base_Game::set_prog_mode` to
`C:\\msdev\\work\\age1_x1\\basegame.h:309`. The function packet gives one
body range, `0041C240-0041C24C`, and the decorated `__thiscall` symbol
`?set_prog_mode@RGE_Base_Game@@UAEXH@Z`.

The original body loads its argument and stores it at `[ecx+0x1B0]`. The
CodeView class dump at `inventory/types/dumps/RGE_Base_Game.txt` gives the
complete `RGE_Base_Game` size as `0xA24`, with `prog_info` at `+0x0C` and
`prog_mode` at `+0x1B0`. The canonical declaration is
`include/basegame.h`.

Direct source users are:

- `src/scenario.cpp`, which reads `rge_base_game->prog_info->ai_dir`.
- `src/tscenaro.cpp`, which reads `rge_base_game->prog_mode` in
  `T_Scenario::set_player_tech`.

The `0052C230` packet confirms the latter at `0052C372` and `0052C378`.
The global pointer uses the canonical `include/rge_base_game_global.h` owner.

## Composition repair

- `include/scenario.h` now includes `basegame.h` and
  `rge_base_game_global.h`. Its partial `RGE_Base_Game` body is removed.
- `include/tscenaro.h` now includes the same canonical Base Game and global
  owners. Its partial `RGE_Base_Game` body is removed.
- `src/matching/0041C240_set_prog_mode.cpp` includes `basegame.h` and no
  longer carries a fallback Base Game layout.

No T_Scenario accessor, carrier, copy, macro, cast, overlay, or fallback layout
was added.

## Focused validation

These checks report `MATCH`, `0.0000%`, matching owner symbols, and original
boundaries:

- `0041C240 set_prog_mode`: 13 bytes.
- `0041B620 write_draw_log`: 44 bytes.
- `0041B650 write_draw_log2`: 67 bytes.
- `0048B6C0 RGE_Scenario::InitializeTextValues`: 584 bytes.
- `0048C3E0 RGE_Scenario::save`: 2108 bytes.
- `0048CE40 RGE_Scenario::Get_message`: 66 bytes.

The grouped `0052C230` check reaches the canonical Base Game declaration but
still stops on older unrelated T_Scenario owner errors: the local
`TRIBE_Player_Tech` conflicts with `tech.h`, and the local player surface does
not define the canonical `RGE_Player` members. This repair does not change
those Victory, Player, or Tech owners.
