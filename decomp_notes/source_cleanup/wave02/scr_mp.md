# `scr_mp.cpp` cleanup report

## Delivery

- Module: `src/scr_mp.cpp`
- Paired header: `include/scr_mp.h` (owned by owner 11)
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source-state commit: `0a0f4dffe28d63d8279ef278b8d4d0551317ddbf`
- Changed files: `src/scr_mp.cpp`; this report
- The report commit follows the source commit. The worker result gives its full final branch hash.

The final source-state file hash is:

- `src/scr_mp.cpp`: `b41dda77133fbc2f773f9406bdbdfe7f97ab7d99d8b3004977b49bb22a0288dd`

No header was edited.

## Correction history

Owner review requested 1TBS formatting for all function definitions. The source correction moves the constructor brace onto its initializer line and puts the complete four-parameter `action` definition on one line with its brace. No braces, statements, declarations, or control structure changed.

The correction source commit is `0a0f4dffe28d63d8279ef278b8d4d0551317ddbf`. The report update follows it.

## PDB coverage

I inspected the source registry and all six assigned function packets. The registry is:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/scr_mp.cpp.json`
- SHA256: `8a26bcff100757dd96434dfe928e25a08cc71cec43d14b0cc7af99997319ea55`

The scoped PDB evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

| VA | PDB lines and record count | Packet | Scoped names inspected |
| --- | --- | --- | --- |
| `0049F370` | 68-220; 51 records | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/0049F370_TribeMPStartupScreen.txt` | `this`; `gdwDisp`, `tabList`, `dwSize`, `ghUserKey`, `temp_str`, `str`, `dwType`, `Data` |
| `0049F890` | 225-241; 15 records | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/0049F890_TribeMPStartupScreen.txt` | `this` only |
| `0049F9A0` | 247-252; 5 records | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/0049F9A0_handle_idle.txt` | `this` only |
| `0049F9D0` | 258-365; 58 records | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/0049F9D0_action.txt` | `this`; `fromPanel`, `actionIn`, `a1`, `a2`, `Serv` |
| `0049FED0` | 370-410; 20 records | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0049/0049FED0_fillList.txt` | `this`; `lastServiceName`, `file_info`, `lastServiceNumber`, `Serv` |
| `004A00A0` | 415-424; 2 records | `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004A/004A00A0_handle_user_command.txt` | `this`; `wParam`, `lParam` |

The constructor PDB names match the source names for the recorded locals. The PDB type display reports `char[255]` for `Data` and `temp_str`, while the source declares both as `char[256]`. I left the source types and storage unchanged. `cancel_button`, `ok_button`, `cancel`, `result`, `command`, `quote`, `length`, and `zone` have no procedure-scoped PDB record. I left these mappings unchanged.

The destructor and `handle_idle` have no recorded locals beyond `this`. `fillList` already used all recorded local names. The action procedure had a readable but non-PDB name `services`; I restored `Serv`. The action parameters had generated or substitute names; I restored `fromPanel`, `actionIn`, `a1`, and `a2`. I restored `wParam` and `lParam` in `handle_user_command`.

Recovered original spellings changed in this cleanup:

- `action`: `panel` -> `fromPanel`, `event` -> `actionIn`, `param3` -> `a1`, `param4` -> `a2`, `services` -> `Serv`.
- `handle_user_command`: `p0` -> `wParam`, `p1` -> `lParam`.

No invented local or parameter names were added. No public symbol, class member, type, scope, declaration order, or function signature changed. The header has unnamed parameters, so it needs no paired parameter-name edit.

## Constants and resource evidence

I included `../include/resource_ids.h` and reused existing shared names for these unchanged values:

- `IDS_BUTTON_OK` = `0x0FA1`; constructor button text lookup. Base text is `OK`.
- `IDS_BUTTON_CANCEL` = `0x0FA2`; constructor button text lookup. Base text is `Cancel`.
- `IDS_BUTTON_CLOSE` = `0x03EA`; constructor close-button text lookup. Base text is `X`.
- `IDS_HELP_OK` = `0x7531`; OK-button help lookup. Text is missing in every checked file.
- `IDS_HELP_CANCEL` = `0x7532`; Cancel-button help lookup. Text is missing in every checked file.

These are existing shared declarations. They are not new recovered macro names.

The source keeps the following IDs numeric because their shared definitions need root review. The proposed names are new descriptive names, not recovered original macro names.

Common resource checks for every row below:

- F1: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`; SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- F2: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`; SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- F3: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`; SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

F1 is the staged base-language input. F2 is the staged expansion input. F3 is the pinned original expansion reference. F2 and F3 have no RT_STRING entry for any checked ID. The source calls `TEasy_Panel::create_text`, `TEasy_Panel::popupOKDialog`, `TEasy_Panel::popupYesNoDialog`, `TTextPanel::append_line`, and `TPanel::set_help_info`. These paths use `TPanel::get_string` and `RGE_Base_Game::get_string`, whose base DLL name is `language.dll`. No `StringTableX` override call is present in this module. The checked expansion files provide no override or fallback text for these IDs.

| ID | Proposed name | Call-site purpose and lookup path | Language and F1 text | F2/F3 result |
| --- | --- | --- | --- | --- |
| `0x258B` | `IDS_MULTIPLAYER_CONNECTION_TITLE` | `create_text` for the startup screen title; `TEasy_Panel::create_text` -> `TPanel::get_string` -> base `language.dll` | `0x0409`: `Multiplayer Connection` | Missing in both files |
| `0x258C` | `IDS_MULTIPLAYER_NAME_LABEL` | `create_text` for the player-name label; same base lookup path | `0x0409`: `Name` | Missing in both files |
| `0x258D` | `IDS_MULTIPLAYER_CONNECTION_TYPE_LABEL` | `create_text` for the connection-type label; same base lookup path | `0x0409`: `Connection Type` | Missing in both files |
| `0x258E` | `IDS_MULTIPLAYER_GAMING_ZONE` | `TTextPanel::append_line` for the browser-based Gaming Zone service when the browser exists; base `language.dll` lookup | `0x0409`: `Microsoft Internet Gaming Zone` | Missing in both files |
| `0x258F` | `IDS_ERROR_PLAYER_NAME_REQUIRED` | `popupOKDialog` after an empty player-name check; base `language.dll` lookup | `0x0409`: `You must enter a valid player name.` | Missing in both files |
| `0x2592` | `IDS_ERROR_NO_MULTIPLAYER_CONNECTIONS` | `popupOKDialog` when the service list has no lines; base `language.dll` lookup | `0x0409`: `No multiplayer connections are available.` | Missing in both files |
| `0x2593` | `IDS_CONFIRM_START_GAMING_ZONE` | `popupYesNoDialog` before starting the Gaming Zone browser; base `language.dll` lookup | `0x0409`: `Start your Web browser and go to The Internet Gaming Zone?` | Missing in both files |
| `0x7595` | `IDS_HELP_MULTIPLAYER_PLAYER_NAME` | `input->set_help_info`; help text is resolved through the panel/base-game string lookup | `0x0409`: `Type your player name.` | Missing in both files |
| `0x7596` | `IDS_HELP_MULTIPLAYER_CONNECTION_TYPE` | `list->set_help_info`; help text is resolved through the panel/base-game string lookup | `0x0409`: `Select the type of connection to make. For more information, click More Help.` | Missing in both files |

The resource extraction tool reported the missing slots for `0x7531` and `0x7532` in F1, F2, and F3. This is missing text, not an empty slot. Existing shared names remain valid because the call sites prove their help-ID roles. The nine requested IDs have proven purposes and recovered base text in F1. Their proposed names can be added to `include/resource_ids.h` by its root owner without changing lookup order or values.

## Shared-file requests

1. Root owns `include/resource_ids.h`. Add the nine proposed macros in one multiplayer-startup group, with the exact values above. Keep the source numeric until that reviewed declaration exists.
2. Owner 11 owns `include/scr_mp.h`. No declaration change is requested. Its parameters are unnamed, and the recovered definition names do not change the ABI.
3. Do not add expansion-specific definitions. Both checked expansion DLLs lack these IDs. Keep the base-language namespace.

## Comments, code generation, and validation

No source comments were added. The names answer the PDB evidence without a speculative behavior comment. The five reused macros expand to the same integer tokens and values as the replaced literals. The include adds declarations only. Parameter and local renames affect debug names, not executable code. A compiler check is required before making any code-generation claim.

The original executable reference is `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`, SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`. I used it as evidence only.

I ran source reading, PDB and packet extraction, resource extraction, SHA256 checks, `rg` searches, and `git diff --check`. I did not run compilation, a build, matching, audits, tests, or a game command. Byte equality and final code generation remain unvalidated.
