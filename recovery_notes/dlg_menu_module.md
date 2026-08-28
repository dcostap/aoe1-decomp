# dlg_menu.cpp canonical dependency hold

The PDB module owns three `TribeMenuDialog` methods. Its source range is
`0043F340` through `0043FC64`.

Do not replace `dlg_menu_context.h` with local class copies. The direct source
constructs these complete foreign types:

- `TribeSaveGameScreen` at 0x6A4 bytes;
- `TribeConfigDialog` at 0x564 bytes;
- `TribeAchievementsScreen` at 0x5F8 bytes;
- `TribeAboutDialog` at 0x4C4 bytes; and
- `TRIBE_Mission_Screen` at 0x49C bytes.

The canonical Panel, Easy Panel, Dialog Panel, Screen Panel, button, drawing,
scenario, and Base Game providers are available in `panel.h`, `panel_ez.h`,
`pnl_dlg.h`, `Pnl_scr.h`, `pnl_btn.h`, `drawarea.h`, `scenario.h`, and
`basegame.h`. `basegame.h` also publishes the required `multiplayerGame()`,
`singlePlayerGame()`, `get_player()`, `set_paused(int, int)`, `world`, and
`prog_window` surface.

`dlg_conf.h` and `dlg_abt.h` now compose with those providers. The remaining
foreign owners are not yet composable on this branch:

- `TribeSaveGameScreen` remains in `scr_save_context.h` and `scr_sed.h` with
  copied Panel and Screen hierarchies. No `scr_save.h` owner header exists.
- `TribeAchievementsScreen` remains in `scr_ach.h` with copied Panel, Easy
  Panel, Screen, Panel System, and Base Game declarations.
- `TRIBE_Mission_Screen` remains in `scr_vc_context.h` with copied Panel,
  Screen, Panel System, and Base Game declarations. No `scr_vc.h` owner header
  exists.

The constructor and action use all three blocked types with `new`. Forward
declarations cannot compile these expressions. Importing their legacy headers
would redefine the canonical Panel hierarchy. A caller-side size-only or
partial class would violate ownership and ABI rules.

The action also directly calls `RGE_Base_Game::set_paused(int, int)`. Canonical
`basegame.h` now publishes this nonvirtual method. PDB basegame.cpp lines
3299-3311 and `00420220` prove `?set_paused@RGE_Base_Game@@QAEXHH@Z`.
Do not add a local Base Game class or a compatibility overload.

Recover `scr_save`, `scr_ach`, and `scr_vc` leaf-first. Compose each provider
with the canonical owners, then publish its owner-only header. Revisit this
module after those three providers are available. The existing three matching
fragments remain the validated source checkpoint until then.
