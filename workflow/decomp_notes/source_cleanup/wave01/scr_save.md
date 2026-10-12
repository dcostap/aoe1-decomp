# Source-cleanup report: `scr_save.cpp`

## Delivery

- Module: `src/scr_save.cpp`
- Header read: `include/scr_save.h`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Earlier source commit: `ec17792d1c38eaa239fa871d49a30c139dba2126`
- Resource source commit: `d9679c782de075b40b7552839f320276852ddb38`
- Shared header commit: original `c9ba20d160541d928b5d9e55e1d02dce5a784e0c`; worker-local cherry-pick `c79bf91c115c5ae13769847e24444d92b7214dc4`.
- Final report commit: the commit that adds this file; copy its full hash from Git.
- Module changes: `src/scr_save.cpp` and this report only.
- The worker-local shared-header cherry-pick changed `include/resource_ids.h`. Exclude that commit from module integration. Root owns the shared header.
- `include/scr_save.h` was not changed. It remains owned by the screens group owner.

The source cleanup restores names from the procedure-scoped PDB. It reuses existing resource macros. It does not change types, layouts, calls, control flow, storage, or source order.

## Function coverage

The module registry lists five normal functions. Coverage is complete.

| VA | Function | PDB names checked | Result |
| --- | --- | --- | --- |
| `004A71F0` | `TribeSaveGameScreen::TribeSaveGameScreen` | `m`, `file_name`, `quit_after_save_in`, `tabList`, `info_file`, `from_panel`, and register `this` | Restored the three parameters and `from_panel`. Restored names have mixed original style. Kept `tabList` and `info_file`. |
| `004A75C0` | `TribeSaveGameScreen::~TribeSaveGameScreen` | Register `this`; no stack symbols | No name change was needed. |
| `004A7670` | `TribeSaveGameScreen::fillList` | `fileInfo`, `file_name`, and register `this` | Existing names already match the PDB. No type or scope change was made. |
| `004A7850` | `TribeSaveGameScreen::action` | `fromPanel`, `actionIn`, `a1`, `a2`, `str`, `text`, `tempFileName`, `exist_flag`, and register `this` | Restored all four parameters. Kept `text`, `tempFileName`, and `exist_flag`. |
| `004A8060` | `TribeSaveGameScreen::save_for_scenario_editor` | Register `this`; no stack symbols | No name change was needed. |

The PDB also lists compiler-generated vector deleting destructor `004A75A0`. It has register `this` and stack `__flags`. It has no handwritten source owner and was not edited.

### Name details

- Recovered original parameter names: `m`, `file_name`, and `quit_after_save_in` in the constructor; `fromPanel`, `actionIn`, `a1`, and `a2` in `action`.
- Recovered original constructor local: `from_panel`.
- Existing recovered locals: `tabList`, `info_file`, `fileInfo`, `text`, `tempFileName`, and `exist_flag`.
- New descriptive local spellings: `title_ptr`, `cancel_local`, and `delete_local`. These names have no PDB record. They follow the cleanup snake-case rule.
- The action PDB maps `str` and several `tempFileName` records to the same stack slot at `-0x330`. The source keeps one `tempFileName[260]` declaration. It does not force a `str` mapping across reused storage.
- The action PDB records `text[556]` at `-0x22c` and `exist_flag` at `-0x331`. The source keeps these declarations and effective types.
- The PDB has no reliable names for the remaining optimized locals. Their existing names remain unchanged. No reused slot received a forced name.

Evidence sources:

- `inventory/pdb/scoped_symbols.json`, entries `004A71F0`, `004A75C0`, `004A7670`, `004A7850`, and `004A8060`.
- `inventory/functions/004A/004A71F0_TribeSaveGameScreen.txt`.
- `inventory/functions/004A/004A75C0_TribeSaveGameScreen.txt`.
- `inventory/functions/004A/004A7670_fillList.txt`.
- `inventory/functions/004A/004A7850_action.txt`.
- `inventory/functions/004A/004A8060_save_for_scenario_editor.txt`.
- Existing module note `workflow/decomp_notes/scr_save.md` and action note `workflow/decomp_notes/functions/004A/004A7850.md`.

## Existing resource mappings used

The source now includes `include/resource_ids.h` and reuses these existing macros:

| Macro | Value | Use |
| --- | --- | --- |
| `STRING_ID_HELP_SAVED_GAME_NAME` | `0x7670` | Save-name edit help |
| `STRING_ID_BUTTON_OK` | `0x0FA1` | OK button |
| `STRING_ID_BUTTON_DELETE` | `0x24C9` | Delete button |
| `STRING_ID_BUTTON_CANCEL` | `0x0FA2` | Cancel button |
| `STRING_ID_HELP_OK` | `0x7531` | OK-button help |
| `STRING_ID_HELP_CANCEL` | `0x7532` | Cancel-button help |
| `STRING_ID_CONFIRM_DELETE_FILE` | `0x24CA` | Delete confirmation format string |

These replacements preserve the exact literal values and effective argument types. No resource macro was defined in this worktree.

## Applied shared resource mappings

The root owner approved shared commit `c9ba20d160541d928b5d9e55e1d02dce5a784e0c`. Its worker-local cherry-pick is `c79bf91c115c5ae13769847e24444d92b7214dc4`. The source now uses all eight approved macros below. The shared header commit is not part of the module commit set.

Lookup path: `TRIBE_Game::get_string` first calls `LoadStringA` on `StringTableX`, normally `runtime/languagex.dll`. On failure, it calls `RGE_Base_Game::get_string`, which uses the base `runtime/language.dll`. The runtime hashes are:

- `runtime/language.dll`: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `runtime/languagex.dll`: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Checked original XPack `languagex.dll`: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

All listed runtime strings use resource type `RT_STRING`, language `0x0409` (English, language ID `1033`). `languagex.dll` and the checked original XPack `languagex.dll` have no entries for these IDs. The exact text comes from the base runtime `language.dll`.

1. Applied `STRING_ID_SAVE_GAME_TITLE_BASE` for numeric `0x24C3`.
   - The constructor uses `(this->modeValue != SaveGame) + STRING_ID_SAVE_GAME_TITLE_BASE`.
   - The contiguous range is `0x24C3` = `Save Game`, `0x24C4` = `Save Scenario`, and `0x24C5` = `Return to Game`.
   - The macro preserves the `0x24C3` and `0x24C4` arithmetic range.
   - Purpose: save-screen title selected by mode.
2. Applied `STRING_ID_ERROR_SAVE_GAME_NAME_REQUIRED` for `0x24C6`.
   - Text: `You must enter a name to save the game.`
   - Purpose: empty save-game name dialog.
3. Applied `STRING_ID_ERROR_SAVE_SCENARIO_NAME_REQUIRED` for `0x24C7`.
   - Text: `You must enter a name to save the scenario.`
   - Purpose: empty save-scenario name dialog.
4. Applied `STRING_ID_CONFIRM_OVERWRITE_FILE` for `0x24C8`.
   - Text: `That file exists. Overwrite it?`
   - Purpose: overwrite confirmation dialog.
5. Applied `STRING_ID_HELP_SELECT_SAVED_GAME` for `0x7671`.
   - Text: `Select a saved game.`
   - Purpose: save-screen list help.
6. Applied `STRING_ID_ERROR_CANNOT_SAVE_GAME` for `0x0962`.
   - Text: `The game could not be saved. Free some disk space, and then try again.`
   - Purpose: save-game failure dialog.
7. Applied `STRING_ID_ERROR_CANNOT_SAVE_SCENARIO` for `0x0963`.
   - Text: `The scenario could not be saved. Free some disk space, and then try again.`
   - Purpose: save-scenario failure dialog, including the scenario-editor helper.
8. Applied `STRING_ID_STATUS_SAVING_SCENARIO` for `0x0450`.
   - Text: `Saving scenario...`
   - Purpose: scenario-save status message.

No lookup, fallback, format token, buffer size, or call order changed. The save-title expression preserves `(this->modeValue != SaveGame) + STRING_ID_SAVE_GAME_TITLE_BASE` token order. The delete-confirmation text at `0x24CA` contains the `%s` token and uses the existing `STRING_ID_CONFIRM_DELETE_FILE` macro. The source keeps the original format-string call.

## Constants and comments

- No new comments were added. Existing source comments were not changed.
- Reused existing resource macros only. No numeric constant was changed.
- The remaining numeric values are dimensions, panel flags, popup parameters, file buffer limits, modes, or hotkeys. Their meanings were not changed or guessed.
- No header, ABI declaration, class layout, enum value, or registry entry was changed.

## Proposed header edits

The owner of `include/scr_save.h` should review these parameter-name-only edits:

```cpp
TribeSaveGameScreen(Mode m, char* file_name, int quit_after_save_in);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

The header edits do not change types, calling convention, symbol identity, or layout. Do not add a private resource header or duplicate resource macros.

## Output-risk review

- Parameter and local renames can change debug names and line associations. They do not change executable semantics.
- Resource macros expand to the same integer literals. The added include has no runtime storage or call effect.
- No declaration type, cast, scope, storage duration, call target, relocation, data, source order, or control-flow structure changed.
- `004A7850` remains the known action code-generation mismatch. The durable action note reports a 665-byte mismatch and an unresolved second-extension load-order difference. This cleanup did not claim or repair it.
- Final compiler output is unvalidated because the wave forbids compilation and matching.

## Validation and status

Allowed review checks run:

- Read the complete assigned source, header, registry, PDB entries, function packets, durable notes, resource-ID guide, and resource extraction output.
- Ran `python tools/inspect_pe_strings.py --help` before resource extraction.
- Extracted the listed IDs from the actual runtime resource files.
- Ran `git diff --check` and inspected the complete source diff.

Not run, as required by the wave contract:

- Compilation or build.
- Function matching.
- Audits.
- Automated tests.
- Menu or gameplay tests.
- Game execution.

The final Git status and full commit hashes must be copied after the report commit.
