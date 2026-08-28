# Dlg_menu.cpp canonical dependency hold

The PDB module owns three `TribeMenuDialog` methods. Its source range is
`0043F340` through `0043FC64`.

Do not replace `dlg_menu_context.h` with local class copies. The direct source
constructs these complete foreign types:

- `TribeSaveGameScreen` at 0x6A4 bytes;
- `TribeConfigDialog` at 0x564 bytes;
- `TribeAchievementsScreen` at 0x5F8 bytes;
- `TribeAboutDialog` at 0x4C4 bytes; and
- `TRIBE_Mission_Screen` at 0x49C bytes.

The current complete declarations for Save, Config, About, and Mission are in
legacy context headers. `scr_ach.h` also copies panel and Base Game surfaces.
None is a composable canonical provider.

The action also directly calls `RGE_Base_Game::set_paused(int, int)`. Canonical
`basegame.h` does not publish this method. Do not add it here or add a local
Base Game class.

Recover these providers leaf-first. Compose each provider with canonical owners.
Then publish its owner-only header. Revisit `dlg_menu` after all five providers
and the Base Game method are available.
