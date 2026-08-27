# `scr_set.cpp`

- PDB source: `C:\msdev\work\age1_x1\scr_set.cpp`.
- Flags: `config/flags/scr_set.rsp`.
- Normal functions: 12.
- Address range: `004B4880` to `004B6870`.

## Module migration

The PDB line bands define the source order in `src/scr_set.cpp`.

The module header is `include/scr_set.h`. It owns the recovered panel and game declarations used only by this compiland.

This merge removes the wrapper, source-bank fragments, fallback declarations, and context selection macro. It keeps the recovered function bodies and ordered calls.

The prior wrapper build reported `MATCH` for all 12 owners. The merged source also reports `MATCH` and `0.0000%` for all 12 owners. The checks ran on 2026-08-27.

## 004B4880 `TribeGameSettingsScreen::TribeGameSettingsScreen`

PDB lines: 162 to 419. Original size: 3949 bytes.

The complete panel surface and screen layout gave the first close module result. The source assigns `missionTextX`, `missionTextY`, `missionTextWidth`, then `missionTextHeight`. Original code at `004B55CC` loads height, Y, then X before the mission setup block. This source order produced the prior exact result.

## 004B5810 `TribeGameSettingsScreen::init_vars`

PDB lines: 425 to 489. Original size: 271 bytes.

The function clears the owned panel pointers, scenario storage, and send timer. It does not clear every screen member.

## 004B5920 `TribeGameSettingsScreen::~TribeGameSettingsScreen`

PDB lines: 495 to 548. Original size: 649 bytes.

The destructor deletes panel members in the executable order. It frees each scenario mission string, then the scenario arrays. Keep this order.

## 004B5BB0 `TribeGameSettingsScreen::handle_idle`

PDB lines: 554 to 582. Original size: 183 bytes.

The shared panel surface places inherited fields and calls correctly. The time test uses `(cur_time - last_send_shared) != 0`. This form produced the prior exact subtraction.

## 004B5C70 `TribeGameSettingsScreen::handle_user_command`

PDB lines: 588 to 596. Original size: 49 bytes.

The chat screen receives the command first. A nonzero result returns. Otherwise the code calls `TPanel::handle_user_command`.

## 004B5CB0 `TribeGameSettingsScreen::action`

PDB lines: 602 to 700. Original size: 329 bytes.

The victory drop-down uses a switch on the list identifier. The late activation tail and base-action fall-through gave the prior exact control flow.

## 004B5E00 `TribeGameSettingsScreen::fillScenarios`

PDB lines: 706 to 802. Original size: 864 bytes.

The recovered panel declarations include the typed list calls and scenario information calls. The three local buffers use their natural bases. The explicit loop body call and break preserve the single scenario-name call site.

## 004B6160 `TribeGameSettingsScreen::fillMissionText`

PDB lines: 808 to 835. Original size: 197 bytes.

The function changes the victory type when the selected line changes. Negative identifiers select a random scenario state.

## 004B6230 `TribeGameSettingsScreen::getSettings`

PDB lines: 841 to 897. Original size: 713 bytes.

The function first selects scenario state and list position. It then reads each control before it handles the victory amount.

## 004B6500 `TribeGameSettingsScreen::sendSettings`

PDB lines: 903 to 964. Original size: 567 bytes.

The victory switch uses the original drop-down identifier. The default arm calls `setVictoryType` with amount 1. This typed switch and shared setter tail gave the prior exact result.

## 004B6740 `TribeGameSettingsScreen::activatePanels`

PDB lines: 970 to 1020. Original size: 296 bytes.

The function uses the canonical screen fields and the inherited `setTabList` slot. It sets the map panels in the retained source order.

## 004B6870 `TribeGameSettingsScreen::activateVictoryPanels`

PDB lines: 1026 to 1064. Original size: 292 bytes.

The function reads the scenario line twice before it checks the fixed-player array. It then reads the victory identifier for the time and score visibility tests.
