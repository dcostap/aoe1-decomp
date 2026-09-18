# Source-cleanup pilot: `src/scr_load.cpp`

## Handoff

- Module: `src/scr_load.cpp`
- Base commit: `436d8cf3b02546b68e57e7f79e8c3b8dd1168936`
- Final source-cleanup commit: `18d952270bcbd8354a567dc7078a647456f0030e`
- Branch: `cleanup/pilot2-scr-load-20260915`
- Changed paths:
  - `src/scr_load.cpp`
  - `include/scr_load.h`
  - `include/resource_ids.h`
  - `decomp_notes/source_cleanup/pilot2_scr_load.md`

The report is committed after the source-cleanup commit. The handoff response records the final report commit hash.

## Scope and method

This pilot performed source cleanup only. It did not perform matching or behavior recovery.

I read the repository contract and the complete source-cleanup, comment, resource-ID, and testing guides. I also read `decomp_notes/source_cleanup/scr_load_help_ids.md`.

I used the supplied five procedure packets in `build/source-cleanup-20260915/preparation/pilot-pdb.json` and the scoped PDB reference. I inspected the five function packets under `inventory/functions/0049/`.

I did not inspect the first pilot worktree, commit, or report.

## Original-name recovery

### `0049DD40` — `TribeLoadSavedGameScreen::TribeLoadSavedGameScreen`

The PDB packet records these stack symbols:

- `tabList`, `TPanel*[16 bytes]`, offset `-0x124`.
- `info_file`, `char[260]`, offset `-0x110`.
- `from_panel`, `TEasy_Panel*`, offset `-0x128`.

The source now uses the recovered original spelling `tabList`. The existing `info_file` spelling already matches the PDB.

The current source has no declaration that maps safely to the PDB `from_panel` record. The PDB records a four-pointer `tabList`, while the current source declares `tabList[5]`. I did not add `from_panel` or change the array size. Such changes could alter storage or generated code. This mapping remains unresolved.

The source keeps `draw_area`, `ok_button`, `cancel_button`, `delete_button`, and `line`. The packet has no matching local records for these names. They remain concise snake_case cleanup names, not claimed original names.

### `0049E0A0` — `TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen`

The packet has no local or parameter records. No name change was needed.

### `0049E150` — `TribeLoadSavedGameScreen::fillList`

The PDB packet records:

- `fileInfo`, `_finddata_t`, offset `-0x118`.
- `file_name`, `char[260]`, offset `-0x21c`.

The source now uses recovered `fileInfo`. The existing `file_name` spelling already matches the PDB. `find_handle` and `name_length` have no matching PDB stack records. They remain snake_case cleanup names.

### `0049E2B0` — `TribeLoadSavedGameScreen::handle_idle`

The packet has no local or parameter records. No name change was needed.

### `0049E2E0` — `TribeLoadSavedGameScreen::action`

The PDB records these parameters:

- `fromPanel`, `TPanel*`, offset `+0x4`.
- `actionIn`, `long`, offset `+0x8`.
- `a1`, `unsigned long`, offset `+0xc`.
- `a2`, `unsigned long`, offset `+0x10`.

The definition and assigned header declaration now use these recovered spellings.

The PDB records these locals:

- `str`, `char[256]`, offset `-0x440`.
- `text`, `char[556]`, offset `-0x238`.
- `fileNameNoExt`, `char[260]`, offset `-0x33c`.
- `fileInfo`, `_finddata_t`, offset `-0x238`.
- `fileName`, `char[260]`, offset `-0x440`.

The source now uses `fileNameNoExt`, `fileInfo`, `text`, and `fileName`. The `text` and `fileInfo` records share a stack offset but belong to separate source blocks, so their declarations map safely.

The PDB also records `str` and `fileName` at the same stack offset with different array sizes. The current source has one `char fileName[260]` declaration for both the formatted path and the delete-message lookup buffer. I renamed that declaration to the supported `fileName` path-buffer spelling. I did not add a separate `str[256]` declaration or change the existing storage arrangement. The `str` record remains an unresolved declaration mapping.

The packet has no matching local record for `find_handle` or `loaded`. The source keeps these concise snake_case cleanup names. No public function, class, member, global, type, storage layout, or calling convention changed.

## Resource IDs

I added `include/resource_ids.h`. Every macro is a new descriptive cleanup name. No macro name is claimed as an original developer symbol. Each macro keeps the original hexadecimal literal spelling and introduces no storage.

| ID | New name | Proven role | Text result |
| --- | --- | --- | --- |
| `0x0FA1` | `STRING_ID_BUTTON_OK` | OK button caption | `OK` |
| `0x0FA2` | `STRING_ID_BUTTON_CANCEL` | Cancel button caption | `Cancel` |
| `0x24C9` | `STRING_ID_BUTTON_DELETE` | Delete button caption | `Delete` |
| `0x24CA` | `STRING_ID_CONFIRM_DELETE_FILE` | Delete confirmation format string | `Are you sure you want to delete the file \n'%s'?` |
| `0x24FF` | `STRING_ID_SAVED_GAMES_TITLE` | Load-screen title | `Saved Games` |
| `0x2501` | `STRING_ID_ERROR_CANNOT_LOAD_SAVED_GAME` | Load failure message | `Cannot load that saved game.` |
| `0x2502` | `STRING_ID_SELECT_SAVED_GAME_TITLE` | Saved-game list title | `Select Saved Game` |
| `0x7531` | `STRING_ID_HELP_OK` | Help text ID assigned to the OK button | Missing in all checked files |
| `0x7532` | `STRING_ID_HELP_CANCEL` | Help text ID assigned to the Cancel button | Missing in all checked files |
| `0x7670` | `STRING_ID_HELP_SAVED_GAME_NAME` | Help text ID assigned to the saved-game list scrollbar | `Type a name for the game.` |

The role of `0x7531` and `0x7532` does not depend on recovered text. The executable passes each ID to `TPanel::set_help_info`. The source and cross-screen call sites assign `0x7531` to OK buttons and `0x7532` to Cancel buttons. The supplied help-ID note records the same executable evidence.

### Resource provenance

The extraction tool inspected PE bytes only. It did not load or execute a DLL. Outputs are under the worker build directory:

- `build/resource-strings/runtime-language.json`
- `build/resource-strings/runtime-languagex.json`
- `build/resource-strings/original-xpack-languagex.json`

The checked base runtime file is `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`.

- SHA-256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Resource type: `RT_STRING`
- Language: `0x0409` (`1033`)
- It contains all table entries above except `0x7531` and `0x7532`.

The checked runtime expansion file is `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`.

- SHA-256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Resource type: `RT_STRING`
- The requested IDs are missing. No nonempty string slots were returned.

The pinned original expansion reference is `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.

- SHA-256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
- Resource type: `RT_STRING`
- The requested IDs are missing. No nonempty string slots were returned.

The original base setup sets `string_dll_name` to `language.dll` and loads it into `StringTable`. The expansion setup loads `languagex.dll`, or a command-line `STRING=` override, into `StringTableX`. `TRIBE_Game::get_string` checks `StringTableX` first and then calls the base lookup. The base lookup clears the destination buffer when `LoadStringA` fails.

Therefore, the checked runtime expansion file falls back to the checked runtime base file for the caption and message IDs. The two help IDs are missing from both checked runtime modules. Their text remains unknown. This report does not claim a visually observed tooltip result.

## Source changes and risk

- Replaced generated or cleanup spellings with PDB-supported names.
- Replaced ten opaque resource literals with macros from the new shared header.
- Changed only parameter names in `include/scr_load.h`; ABI types and order remain unchanged.
- Applied 1TBS braces to the assigned source definitions.
- Joined unnecessarily split calls and signatures.
- Preserved source order, control flow, string contents, literal values, buffer sizes, and lookup order.
- Kept the existing reload comment. No new source comments were needed.

Formatting can change debug line records. Resource macros can change line mapping, but their expansions retain the original values and types. Compiler-output equality, relocation equality, and direct-call target equality remain unvalidated.

## Unsafe or unresolved candidates

- The constructor PDB `from_panel` record has no safe current declaration mapping.
- The action PDB `str[256]` record overlaps the PDB `fileName[260]` record and the current source uses one merged declaration. I did not force a separate buffer.
- The constructor PDB describes a four-pointer `tabList`, while the current source declares five entries. I did not change storage.
- No structural rewrites, helper extraction, bug repairs, or modernization were made.

## Validation status

Compilation, matching, audits, tests, and games were **NOT run**. I did not invoke a compiler or build command. Only evidence extraction and source/Git diff review were performed. Compiler-output equality remains unvalidated.

## Guidance review

The revised guidance was sufficient for this pilot. It set clear limits for source cleanup, PDB name recovery, resource provenance, and deferred validation.

A future revision could add one worked example for a PDB stack slot that contains two source declarations while the current source has one merged declaration. That case caused the only material naming decision in this module.
