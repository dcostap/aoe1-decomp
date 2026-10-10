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

None of the thirteen IDs has text in the checked files:

- `runtime/language.dll`, SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `orig/.../XPack/languagex.dll`, SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

The neighbouring `STRING_ID_HELP_GAME_*` IDs, from `0x1D4CD` to `0x1D4DC`, are also missing from these files.
The names describe the call-site purpose. They do not describe any resource text.

## Validation

Artifacts are under `build/cleanup-2026-10-10/helpids-1/`.
The baseline is the full audit at `c41e6039a`. Neither edited file changed between that commit and the start of this work.

- All 45 groups that depend on the edited files compiled. All 1,171 exact claims passed.
- All 45 non-debug object payloads match the baseline.
- The line-ending check passed. clang-format 21.1.8 was applied.

No linked executable build, image audit, automated tests, or runtime suites ran.
