# PENDING

Last updated: 2026-02-06

## Scope (Current)

1. Only `Single Player -> Random Map -> Start Game`.
2. Other menu families stay deferred.

## Random Map Path (Left)

1. Replace temporary game-screen fallback in `TRIBE_Game::create_game_screen` with real `TRIBE_Screen_Game` flow (`scr_game` parity).
2. Implement enough `RGE_Game_World` / `TRIBE_World` runtime to actually enter live gameplay after start (current world methods are still broad stubs).
3. Finish `TribeMPSetupScreen` parity against `scr_mps`:
   - replace current inline setting-cycle fallback with original drop-down driven controls,
   - restore full player slot interactivity (name/civ/color/team/scenario player selectors),
   - match original single-player validation/prechecks more closely.
4. Implement `TribeGameSettingsScreen` (`scr_set`) path and wire `gameSettingsButton` to it:
   - map/victory/difficulty/resource controls,
   - apply settings back to `TRIBE_Game`,
   - return flow to MP setup.
5. Replace remaining stubbed UI builders that block `scr_mps/scr_set` parity:
   - `TEasy_Panel::create_input`,
   - `TEasy_Panel::create_edit`,
   - `TEasy_Panel::create_drop_down`,
   - `TEasy_Panel::create_list`,
   - `TEasy_Panel::create_scrollbar`,
   - `TEasy_Panel::create_auto_scrollbar`.

## Deferred (Out Of Scope)

1. Multiplayer startup path from main menu.
2. Scenario editor/builder menus.
3. Credits/help/campaign-name paths not required for Random Map launch.
