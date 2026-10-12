# Game command-button help IDs

## Scope

The starting commit is `9e1a12adf`.
This change names the last 43 numeric help-string arguments in `src/scr_game.cpp`.
Thirteen new macros were added to `include/resource_ids.h`, after the existing `STRING_ID_HELP_GAME_*` block.
They are descriptive cleanup names, not recovered original names.

## Evidence

Each value is the `help_string_id` argument of `TribeGameScreen::set_button`.
`STRING_ID_HELP_UNGROUP_BUTTON` already appears in that same argument position.
Every site pairs each ID with exactly one button command, as the table shows:

| ID | Name | Command at every site |
| --- | --- | --- |
| `0x1D4D7` | `STRING_ID_HELP_GAME_MORE` | `TRIBE_UI_COMMAND_MORE` |
| `0x1D4D9` | `STRING_ID_HELP_GAME_CANCEL_UNSELECT` | Final slot-11 button: `CANCEL` or `UNSELECT` |
| `0x1D4DD` | `STRING_ID_HELP_GAME_STOP` | `STOP` |
| `0x1D4DF` | `STRING_ID_HELP_GAME_BUILD` | `BUILD` |
| `0x1D4E1` | `STRING_ID_HELP_GAME_GROUP` | `GROUP` |
| `0x1D4E3` | `STRING_ID_HELP_GAME_UNGROUP` | `UNGROUP` |
| `0x1D4E5` | `STRING_ID_HELP_GAME_CANCEL_CONSTRUCTION` | `CANCEL_CONSTRUCTION` |
| `0x1D4E9` | `STRING_ID_HELP_GAME_UNLOAD` | `UNLOAD` |
| `0x1D4EA` | `STRING_ID_HELP_GAME_STAND_GROUND` | `STAND_GROUND` |
| `0x1D4EB` | `STRING_ID_HELP_GAME_ATTACK_GROUND` | `ATTACK_GROUND` |
| `0x1D4F1` | `STRING_ID_HELP_GAME_HEAL` | `HEAL` |
| `0x1D4F2` | `STRING_ID_HELP_GAME_CONVERT` | `CONVERT` |
| `0x1D4F6` | `STRING_ID_HELP_GAME_REPAIR` | `REPAIR` |

The ungroup button uses two help IDs.
Some paths pass `STRING_ID_HELP_UNGROUP_BUTTON` (`0x4E43`, text "Ungroup Button").
The others pass `0x1D4E3`, and one path selects between them with `special_known`.
They remain separate names.

## Resource text

The first version of this note said these IDs had no text. That was wrong.
The search used the full IDs, which are above 0xFFFF. `LoadStringA` uses only the low 16 bits,
so `0x1D4D7` loads the text at `0xD4D7`. See `workflow/decomp_notes/build_list_names.md` for the evidence.

With the low 16 bits, every ID has text that agrees with its name:

| ID | Loaded ID | Module | Text |
| --- | --- | --- | --- |
| `0x1D4D7` | `0xD4D7` | base | Click to display more buildings. |
| `0x1D4D9` | `0xD4D9` | base | Click to unselect a unit. |
| `0x1D4DD` | `0xD4DD` | base | Click to stop the current action. |
| `0x1D4DF` | `0xD4DF` | base | Click to construct a building. |
| `0x1D4E1` | `0xD4E1` | base | Click to group selected units. |
| `0x1D4E3` | `0xD4E3` | base | Click to ungroup selected units. |
| `0x1D4E5` | `0xD4E5` | base | Click to cancel the current action. |
| `0x1D4E9` | `0xD4E9` | base | Click to unload a transport vessel. |
| `0x1D4EA` | `0xD4EA` | base | Click to order units to stand ground instead of attacking ... |
| `0x1D4EB` | `0xD4EB` | base | Click to order catapult units to target a location, ... |
| `0x1D4F1` | `0xD4F1` | base | Click to order the Priest to heal a friendly or allied unit. |
| `0x1D4F2` | `0xD4F2` | base | Click to order the priest to convert an enemy unit. |
| `0x1D4F6` | `0xD4F6` | base | Click to order units to repair a building or boat. |

Modules: base is `runtime/language.dll`, SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The expansion module is `orig/.../XPack/languagex.dll`, SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
`TRIBE_Game::get_string` tries the expansion module first. The expansion slots for these IDs are empty,
so `LoadStringA` returns 0 and the base module supplies all thirteen texts.

## Validation

Artifacts are under `build/cleanup-2026-10-10/helpids-1/`.
The baseline is the full audit at `c41e6039a`. Neither edited file changed between that commit and the start of this work.

- All 45 groups that depend on the edited files compiled. All 1,171 exact claims passed.
- All 45 non-debug object payloads match the baseline.
- The line-ending check passed. clang-format 21.1.8 was applied.

No linked executable build, image audit, automated tests, or runtime suites ran.
