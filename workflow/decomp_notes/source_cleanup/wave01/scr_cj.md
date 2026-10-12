# `scr_cj.cpp` source-cleanup report

## Delivery

- Module: `src/scr_cj.cpp`
- Header read: `include/scr_cj.h` (not edited)
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Source cleanup commit: `441a3579803fb8d6a8d6e00b71fef0422ec1bf7f`
- Report commit: `80b2c28ae3dfb82c38fccf3e4d71e59d615a42f4`.
- Changed files: `src/scr_cj.cpp`, `workflow/decomp_notes/source_cleanup/wave01/scr_cj.md`

The source commit restores procedure-scoped PDB names and uses existing button resource macros. It does not change declarations, types, storage, control flow, call order, data, or resource numbers.

## Function coverage and name evidence

Evidence source: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`. The PDB source is `C:\msdev\work\age1_x1\scr_cj.cpp`. Every procedure has a register record for `this`; generated deleting destructors also have the `__flags` stack record.

| VA | Procedure | PDB stack records | Cleanup result |
| --- | --- | --- | --- |
| `00491650` | `TribeJoinScreen::TribeJoinScreen` | `tabList` (`TPanel*[20 bytes]` at `-0x20`), `this` in `ecx` | `tabList` already matched. No rename. |
| `00491970` | scalar deleting destructor | `__flags` (`unsigned int` at `+0x4`), `this` in `ecx` | Compiler-generated entry. No source body. |
| `00491990` | `TribeJoinScreen::~TribeJoinScreen` | `this` in `ecx` | No stack or parameter names to recover. |
| `00491A80` | `TribeJoinScreen::handle_idle` | `this` in `ecx` | No stack or parameter names to recover. |
| `00491B20` | `TribeJoinScreen::handle_user_command` | `wParam` (`unsigned int` at `+0x4`), `lParam` (`long` at `+0x8`), `this` in `ecx` | Recovered `cmd` as `wParam` and `param` as `lParam`. |
| `00491C42` | padding-only entry | Reviewed padding manifest entry | Not a source function. No edit. |
| `00491C70` | `TribeJoinScreen::fillList` | `szTemp` (`char[126]` at `-0x8c`), `this` in `ecx` | `szTemp` already matched. No rename. |
| `00491E20` | `TribeJoinScreen::action` | `fromPanel` (`TPanel*` at `+0x4`), `actionIn` (`long` at `+0x8`), `a1` and `a2` (`unsigned long` at `+0xc` and `+0x10`), `temp` and `string` (`char[256]` at `-0x20c` and `-0x10c`), `this` in `ecx` | Recovered `panel`, `command`, `param3`, and `param4` as `fromPanel`, `actionIn`, `a1`, and `a2`. `temp` and `string` already matched. |
| `004920C0` | `TribeMPCreateDialog::TribeMPCreateDialog` | `parentPanel` (`TPanel*` at `+0x4`), `tab_list` (`TPanel*[12 bytes]` at `-0x11c`), `str` (`char[256]` at `-0x10c`), `this` in `ecx` | Recovered `parent` as `parentPanel`. `tab_list` and `str` already matched. |
| `00492310` | scalar deleting destructor | `__flags` (`unsigned int` at `+0x4`), `this` in `ecx` | Compiler-generated entry. No source body. |
| `00492330` | `TribeMPCreateDialog::~TribeMPCreateDialog` | `this` in `ecx` | No stack or parameter names to recover. |
| `004923C0` | `TribeMPCreateDialog::action` | `fromPanel` (`TPanel*` at `+0x4`), `actionIn` (`long` at `+0x8`), `a1` and `a2` (`unsigned long` at `+0xc` and `+0x10`), `this` in `ecx` | Recovered `panel`, `command`, `param3`, and `param4` as `fromPanel`, `actionIn`, `a1`, and `a2`. |

No new source parameter or local name was invented. Existing locals without a scoped PDB record remain unchanged: `player`, `cancel`, `p`, `now`, `i`, `line`, the dialog's `inputGamename` pointer, `s`, `draw_area`, `service_guid`, `create_result`, `window`, and `parent`. Their source roles are clear, but the PDB does not prove their original spellings. This avoids forcing a mapping across optimized or reused storage.

### Proposed header edit

The header owner may add the recovered names below. This request does not change any type or ABI spelling, and this worker did not edit `include/scr_cj.h`:

```cpp
virtual long handle_user_command(unsigned int wParam, long lParam);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
TribeMPCreateDialog(TPanel* parentPanel);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

## Constants and comments

- Added `#include "../include/resource_ids.h"`.
- Replaced `0x0FA1` with existing `STRING_ID_BUTTON_OK` and `0x0FA2` with existing `STRING_ID_BUTTON_CANCEL` in button creation calls. The macros expand to the same numeric values.
- No new constant was defined.
- No source comment was added. The module has no comment need that is stronger than the existing code evidence.
- The eleven proved join-screen IDs now use shared resource macros. Their numeric values remain unchanged.

## Resource mapping request

Shared resource commit `c9ba20d160541d928b5d9e55e1d02dce5a784e0c` adds the reviewed macros to `include/resource_ids.h`. The source now applies all eleven proved mappings below. These are new cleanup names, not recovered original macro names. The requested resource type is `RT_STRING` for every entry.

This worker cherry-picked the shared commit locally as `ce7c965ff82f640183c8e7207f7a6d3cbb26d923` (`Add reviewed screen resource names without changing resource data`). The owner must not include that worker-local header commit in the module commit set. The owner should use the shared commit `c9ba20d160541d928b5d9e55e1d02dce5a784e0c` separately.

The call path is established by the source: `TEasy_Panel::create_text`, `create_button`, `popupOKDialog`, and `TPanel::get_string` use the virtual string lookup. `TRIBE_Game::get_string` tries `languagex.dll` first, then `RGE_Base_Game::get_string` falls back to `language.dll`. The inspected files are:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; all requested IDs are missing.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; all requested IDs are missing.

The base `language.dll` results use language `0x0409` and provide the exact text below. The fallback path therefore supplies these IDs in the inspected runtime. The expansion files have explicit missing results, not empty slots.

| ID | Purpose evidence in `scr_cj.cpp` | Exact base text | Proposed cleanup macro |
| --- | --- | --- | --- |
| `0x25A0` | Join button caption in `TribeJoinScreen` | `Join` | `STRING_ID_MULTIPLAYER_JOIN` |
| `0x25A1` | Refresh/show-games button caption | `Show Games` | `STRING_ID_MULTIPLAYER_SHOW_GAMES` |
| `0x25A2` | Create button caption | `Create` | `STRING_ID_MULTIPLAYER_CREATE` |
| `0x25A3` | Join-failure format lookup and timeout dialog | `Unable to join game.` | `STRING_ID_MULTIPLAYER_UNABLE_TO_JOIN_GAME` |
| `0x25A4` | No-games dialog | `There are no games to join.` | `STRING_ID_MULTIPLAYER_NO_GAMES_TO_JOIN` |
| `0x25A6` | Create-game dialog title | `Create Game` | `STRING_ID_MULTIPLAYER_CREATE_GAME_TITLE` |
| `0x25A8` | Join-screen list title | `Select Game to Join` | `STRING_ID_MULTIPLAYER_SELECT_GAME_TO_JOIN` |
| `0x25A9` | List refresh progress text | `Looking for games...` | `STRING_ID_MULTIPLAYER_LOOKING_FOR_GAMES` |
| `0x25AA` | Create-dialog game-name label | `Game Name` | `STRING_ID_MULTIPLAYER_GAME_NAME` |
| `0x25AB` | Empty-list instructions | `Click Show Games to see a list of games. Click Create to start a new game.` | `STRING_ID_MULTIPLAYER_NO_GAMES_INSTRUCTIONS` |
| `0x25AD` | Create-failure dialog | `Unable to create game. For TCP/IP games, you may need to connect to the Internet before starting Age of Empires.` | `STRING_ID_MULTIPLAYER_UNABLE_TO_CREATE_GAME` |

Existing shared mappings `STRING_ID_BUTTON_OK` (`0x0FA1`, text `OK`) and `STRING_ID_BUTTON_CANCEL` (`0x0FA2`, text `Cancel`) are already defined in `include/resource_ids.h` and are used by this cleanup. No duplicate definitions are requested.

## Output-risk review

- Recovered identifier names do not change the function signatures, types, storage, symbol names, calls, relocations, or data.
- The resource macro replacements preserve the original numeric values and effective integer expressions.
- The action definitions now use 1TBS brace placement. No executable statement moved.
- The source includes one existing macro-only header. No conflicting local declaration was added.
- No inline assembly, wrapper, structural rewrite, or resource lookup change was made.
- Compilation, matching, audits, and tests were not run, as required for this cleanup wave.

## Correction round

- Applied 1TBS to `TribeMPCreateDialog::TribeMPCreateDialog`.
- The opening brace now shares the initializer-list line:
  `: TDialogPanel("Create Dialog") {`.
- No statement, declaration, initializer, source order, or behavior changed.
- Correction commit: `81e922ce1a56d570661ffe3d6b63eae7a67f9154`.
- Compilation, matching, audits, and tests were not run.

## Shared-resource application round

- Cherry-picked reviewed shared commit `c9ba20d160541d928b5d9e55e1d02dce5a784e0c`.
- The worker-local cherry-pick is `ce7c965ff82f640183c8e7207f7a6d3cbb26d923`. It changes only `include/resource_ids.h` and is not a module commit for owner integration.
- Applied the eleven proved resource substitutions in `src/scr_cj.cpp`: `0x25A0`, `0x25A1`, `0x25A2`, `0x25A3`, `0x25A4`, `0x25A6`, `0x25A8`, `0x25A9`, `0x25AA`, `0x25AB`, and `0x25AD`.
- The source keeps the same numeric values, lookup calls, argument order, and fallback behavior.
- The 1TBS constructor correction remains in place.
- Module commit for this application round: `1672368289a0cdc665ae9563fab4f084394549c4`.
- Compilation, matching, audits, and tests were not run.
