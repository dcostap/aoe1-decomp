# BaseGame panel provider surface

## Evidence

CodeView from `age1_x1.pdb` proves these interfaces.

- `TPanel::handle_reactivate()` is public virtual slot 55 at `+0xDC`.
- `TPanel::handle_size(long, long)` is public virtual slot 20 at `+0x50`.
- `TEasy_Panel::get_palette()` is a public nonvirtual `void*` method.
- `TPanelSystem::destroyPanel(char*)` is a public nonvirtual `int` method.
- `TPanel` has a virtual deleting destructor at slot zero.
- `RGE_Base_Game::create_dialog(TPanel**, TPanel*)` and `delete_dialog(TPanel**)`
  are public nonvirtual methods.
- The BaseGame handler and action virtuals are protected. `action_activate`,
  `action_deactivate`, and `action_size` are slots `+0x110`, `+0x114`, and
  `+0x120`.

The evidence comes from `cvdump -t` field lists. The panel-system type record
is `0x1118`.

## BaseGame source use

`basegame.cpp` owners use the existing canonical interfaces.

- Dialog cleanup uses `delete` on a `TPanel*`.
- Activation calls `handle_reactivate()`.
- Resize calls `handle_size(long, long)`.
- Palette query converts the current `TPanel*` to `TEasy_Panel*` before it
  calls `get_palette()`.

Do not add `destroy`, `activate_panel`, `HandleSize`, or a palette getter to
`TPanel`. They are not canonical TPanel interfaces.

## Validation

The focused candidate is
`build/candidate_tus/basegame_panel_surface/proposal.json`.

It reports `MATCH` and `0.0000%` for all five owners. The `Pnl_scr` grouped
candidate keeps its seven exact owners. `TPanel::handle_reactivate` at
`004669D0` also reports `MATCH` and `0.0000%`.
