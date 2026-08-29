# `scr_set.cpp`

- PDB source: `C:\msdev\work\age1_x1\scr_set.cpp`.
- Flags: `config/flags/scr_set.rsp`.
- Normal functions: 12.
- Address range: `004B4880` to `004B6870`.

## Natural source ownership

`include/scr_set.h` now contains only the module include surface. It consumes
`Pnl_scr.h` and `scr_set_screen.h`. The panel, tribe-game, scenario, and
communications declarations come from their canonical owner headers.

`scr_set_screen.h` owns the settings-screen fields. Its option controls use
ordinary arrays. The old unions and duplicate field aliases are removed.

`src/scr_set.cpp` keeps all 12 PDB bodies in source order. It uses the canonical
`TRIBE_Game`, `TRIBE_Scenario_Header`, `RGE_Scenario_File_Info`, panel, and
communications types. The base-game friend is narrow and grants this screen
access to the proven `draw_area`, `scenario_info`, and `input_enabled` fields.

The source has no copied provider declarations, absolute addresses, or wrapper
source. It uses natural string literals for panel names, setup names, score
labels, and the numeric format. The shared empty string remains
`s_592A40`, which is the canonical global owner.

## Exactness classification

Fresh grouped candidate validation reports `MATCH` and `0.0000%` for every
registered owner. All existing manifest claims remain honest `matching` claims.
The source-module manifest records the same 12 owners and their shared recovery
note.

| VA | owner | result | size |
| --- | --- | --- | ---: |
| `004B4880` | `TribeGameSettingsScreen` | `MATCH` | 3949 |
| `004B5810` | `init_vars` | `MATCH` | 271 |
| `004B5920` | `~TribeGameSettingsScreen` | `MATCH` | 649 |
| `004B5BB0` | `handle_idle` | `MATCH` | 183 |
| `004B5C70` | `handle_user_command` | `MATCH` | 49 |
| `004B5CB0` | `action` | `MATCH` | 329 |
| `004B5E00` | `fillScenarios` | `MATCH` | 864 |
| `004B6160` | `fillMissionText` | `MATCH` | 197 |
| `004B6230` | `getSettings` | `MATCH` | 713 |
| `004B6500` | `sendSettings` | `MATCH` | 567 |
| `004B6740` | `activatePanels` | `MATCH` | 296 |
| `004B6870` | `activateVictoryPanels` | `MATCH` | 292 |

Focused standalone checks for `004B4880`, `004B5E00`, and `004B6870` also
report `Result: MATCH` and `0.0000%`. The grouped check reports matching owner
symbols, relocations, boundaries, and direct targets for all 12 owners.

## Source order notes

The PDB line bands define the source order in `src/scr_set.cpp`.

- `004B4880` lines 162 to 419: constructor.
- `004B5810` lines 425 to 489: `init_vars`.
- `004B5920` lines 495 to 548: destructor.
- `004B5BB0` lines 554 to 582: `handle_idle`.
- `004B5C70` lines 588 to 596: `handle_user_command`.
- `004B5CB0` lines 602 to 700: `action`.
- `004B5E00` lines 706 to 802: `fillScenarios`.
- `004B6160` lines 808 to 835: `fillMissionText`.
- `004B6230` lines 841 to 897: `getSettings`.
- `004B6500` lines 903 to 964: `sendSettings`.
- `004B6740` lines 970 to 1020: `activatePanels`.
- `004B6870` lines 1026 to 1064: `activateVictoryPanels`.

The constructor keeps the mission position assignments in their observed
order. `fillScenarios` keeps its explicit scenario-name loop call. The
victory switch and activation tails retain their original control flow.
