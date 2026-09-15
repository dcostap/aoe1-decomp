# `scr_mps.cpp` cleanup report

## Delivery

- Module: `src/scr_mps.cpp`
- Header owner: owner 11 owns `include/scr_mps.h`; this worker did not edit it.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `f6dae9c2b92f5ce44d004afdf869bef095f03581`
- Changed files in the source commit: `src/scr_mps.cpp`
- This report is the only file in the follow-up report commit.
- Temporary evidence is under `build/evidence/` and is not tracked.

## Correction history

- Owner review resumed from `381ac8ad845101418d11c79da39d61adfe9399c7`.
- Verified `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
  Its SHA256 is `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Corrected that SHA256 below.
- Changed the split `else` in `src/scr_mps.cpp` to `} else {`.
- A full-source search found no other split `else` clauses or split function
  braces.

The source commit keeps the existing source structure. It recovers PDB names,
uses reviewed shared resource names, and applies 1TBS to changed definitions.
It adds no comments.

## PDB and packet coverage

I inspected the procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
Every source body has a `this` register in `ecx`. The table lists every body,
its packet selected from `config/functions/src/scr_mps.cpp.json`, and its
scoped parameters and locals.

| VA and packet | Scoped parameters | Scoped locals | Result |
| --- | --- | --- | --- |
| `004A00B0` `004A00B0_TribeMPSetupScreen.txt` | none | `str: char[256]` | Recovered constructor `str`. |
| `004A0D80` `004A0D80_init_vars.txt` | none | none | Inspected. No rename. |
| `004A1300` `004A1300_TribeMPSetupScreen.txt` | none | none | Inspected. Loop names remain uncertain. |
| `004A1640` `004A1640_handle_idle.txt` | none | none | Inspected. No rename. |
| `004A16D0` `004A16D0_key_down_action.txt` | `key: long`, `count: short`, `alt_key: int`, `ctrl_key: int`, `shift_key: int` | none | Recovered all five names from PDB. |
| `004A16E0` `004A16E0_action.txt` | `fromPanel: TPanel*`, `actionIn: long`, `a1: unsigned long`, `a2: unsigned long` | `file_info: _finddata_t`, `file_name: char[260]` | Recovered all four parameter names. Existing local names match. |
| `004A2060` `004A2060_startGame.txt` | none | `send_options: int`; `msg: char[1024]` twice; `playerColorUsed: int[8]`; `msg: char[256]` twice; `temp_team: int[8]`; `temp_color: int[8]`; `temp_civ: int[8]` | All current matching names retained. Reused PDB slots remain unchanged. |
| `004A27A0` `004A27A0_calcRandomPositions.txt` | none | `pos: int`, `position_used: int[8]` | Recovered `pos` from `selected_position`. The source keeps its existing `position_used[9]` size. |
| `004A2910` `004A2910_showNetInfo.txt` | none | `num_addr: unsigned int`, `message: char[1024]`, `temp_str: char[256]` | Existing names match. |
| `004A2BA0` `004A2BA0_cancelScreen.txt` | `lobbyTimeout: int` | none | Recovered `lobbyTimeout` from `timed_out`. |
| `004A2D50` `004A2D50_handle_user_command.txt` | `wParam: unsigned int`, `lParam: long` | `user1` through `user7: unsigned long`; `ready: int`; `message: char[256]` twice | Recovered `wParam` and `lParam`. Recovered `user3`, `user6`, `user7`, `user1`, `user4`, and `user2` from the PDB and readiness packet. Existing `ready` and `checksum` names remain because their reused stack roles do not map safely. |
| `004A37C0` `004A37C0_handle_timer_command.txt` | `wParam: unsigned int`, `lParam: long` | none | Recovered both names from PDB. |
| `004A37D0` `004A37D0_fillPlayers.txt` | none | `humanity: long`, `changed: int`, `color1: unsigned long`, `color2: unsigned long`, `text2: char*`, `text1: char*` | Existing names match. The source keeps its existing `humanity` type. |
| `004A4100` `004A4100_fillChat.txt` | `line_no: int` | none | Recovered `line_no` from `n`. |
| `004A4190` `004A4190_updateSummary.txt` | none | `str1`, `str2`, `str3: char[256]`; `file_info: _finddata_t` at two reused slots; `file_name: char[260]` | Recovered the second `file_info` name from `file_info2`. The `file_scratch` union remains because the PDB names `file_info` and `file_name` share one slot. |
| `004A4FC0` `004A4FC0_kickPlayer.txt` | `p: int` | `text: char[256]` | Recovered `p` from `param_1`. |
| `004A5020` `004A5020_handleKickedPlayer.txt` | `really_kicked: int` | none | Recovered `really_kicked` from `player_index`. |
| `004A5060` `004A5060_activateVictoryPanels.txt` | none | none | Inspected. No rename. |
| `004A5130` `004A5130_setupTabOrder.txt` | none | `tabList: TPanel*[4]` | Existing name matches. |
| `004A5210` `004A5210_setupSinglePlayerPlayers.txt` | none | `first_any_civ: int`, `first_any_color: int`, `first_any_player: int` | Recovered `first_any_player` from `first_any_color_index`. |
| `004A5440` `004A5440_fillNumberPlayers.txt` | none | `str: char[16]` | Existing PDB name matches. Other source locals have no scoped PDB names. |
| `004A54C0` `004A54C0_fillPlayerColors.txt` | none | `str: char[16]` | Existing PDB name matches. |
| `004A5610` `004A5610_TRIBE_Screen_Wait.txt` | none | `str1`, `str2`, `str3: char[256]` | Existing names match. Loop names have no scoped PDB records. |
| `004A6050` `004A6050_TRIBE_Screen_Wait.txt` | none | none | Inspected. Destructor loop name remains uncertain. |
| `004A60E0` `004A60E0_set_text.txt` | `message_in: char*` | none | Recovered `message_in` from `param`. |
| `004A6100` `004A6100_set_text.txt` | `message_in: long` | none | Recovered `message_in` from `param`. |
| `004A6120` `004A6120_action.txt` | `from_panel: TPanel*`, `action_in: long`, `val1: unsigned long`, `val2: unsigned long` | none | Recovered all four parameter names. |
| `004A6170` `004A6170_handle_idle.txt` | none | none | Inspected. No rename. |
| `004A61A0` `004A61A0_TRIBE_Screen_Disconnect.txt` | `mode_in: int` | none | Recovered `mode_in` from `mode`. |
| `004A6290` `004A6290_TRIBE_Screen_Disconnect.txt` | none | none | Inspected. No rename. |
| `004A62F0` `004A62F0_set_text.txt` | `message_in: char*` | none | Recovered `message_in` from `param`. |
| `004A6310` `004A6310_set_text.txt` | `message_in: long` | none | Recovered `message_in` from `param`. |
| `004A6330` `004A6330_action.txt` | `from_panel: TPanel*`, `action_in: long`, `val1: unsigned long`, `val2: unsigned long` | none | Recovered all four parameter names. |
| `004A63C0` `004A63C0_handle_idle.txt` | none | none | Inspected. No rename. |

The packet files are under the required absolute directory
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004A/`.
The packet header review is saved temporarily as
`build/evidence/packet_headers.txt`.
The original behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The `004A2D50` packet shows the readiness outputs as `user3`, `user6`,
`user7`, `user1`, `user4`, `ready`, and `user2`. The current source has a
separate first output named `ready` and a checksum variable. These names do not
map to the PDB stack names without changing types or the existing declaration
layout. I left both names unchanged.

The `004A4190` PDB record has `file_info` and `file_name` at the same stack
slot, plus another `file_info` at a reused slot. I changed only the directly
mapped `file_info2` declaration. I did not rewrite the union.

## Resource and constant evidence

The source now uses existing reviewed definitions for these unchanged values:

- `IDS_BUTTON_CANCEL` for `0x0FA2`.
- `IDS_BUTTON_CLOSE` for `0x03EA`.
- `IDS_HELP_CANCEL` for `0x7532`.

The first two IDs are present in base language resources. The cancel help ID
has missing historical text. The role is established by
`decomp_notes/source_cleanup/scr_load_help_ids.md` and repeated button call
sites.

The source does not define new resource macros. `include/resource_ids.h` is
root-owned. The following new descriptive names are requested from root.
They remain numeric in this source until root reviews the declarations.
Every row uses this lookup path: `TRIBE_Game::get_string` checks the loaded
`StringTableX` expansion module first, then calls
`RGE_Base_Game::get_string` for the base `StringTable` module. The base lookup
clears the buffer when the ID is missing.

For every requested ID below, the checked files were:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

The base file returned each text below in language `0x0409`. Both expansion
files reported a missing ID for every row. No requested row reported an empty
slot. Thus, base fallback supplies the listed text at the current lookup path.
The proposed names are new descriptive names, not recovered macro names.

| ID | Proposed name | Call-site purpose | Base text, language |
| --- | --- | --- | --- |
| `0x0FA9` | `IDS_BUTTON_HELP` | Help button glyph in the setup screen. | `"?"`, `0x0409` |
| `0x238C` | `IDS_HOST_NAME_FORMAT` | Host name line in `showNetInfo`. | `"Host name: %s"`, `0x0409` |
| `0x238D` | `IDS_NO_IP_INFO_ERROR` | No-address result in `showNetInfo`. | `"No IP addressing information is available."`, `0x0409` |
| `0x25AE` | `IDS_MP_PLAYER_COLOR_LABEL` | Player-color column heading. | `"Player"`, `0x0409` |
| `0x25AF` | `IDS_MP_TEAM_LABEL` | Team column heading. | `"Team"`, `0x0409` |
| `0x25B5` | `IDS_RANDOM_MAP` | Random-map scenario summary. | `"Random Map"`, `0x0409` |
| `0x25BF` | `IDS_MP_READY_LABEL` | Ready check box label. | `"I'm Ready!"`, `0x0409` |
| `0x25C8` | `IDS_KICK_PLAYER_PROMPT` | Eject-player confirmation format. | `"Do you want to eject %s?"`, `0x0409` |
| `0x25C9` | `IDS_PLAYER_DROPPED_NOTICE` | Notice for a player kicked or dropped from the game. | `"You were dropped from the game."`, `0x0409` |
| `0x25CA` | `IDS_GAME_CANCELED_NOTICE` | Host-cancel and cancel-game notice. | `"The game was canceled."`, `0x0409` |
| `0x25CB` | `IDS_VICTORY_PERCENT_LABEL` | Victory amount label for percent mode. | `"Percent"`, `0x0409` |
| `0x25CC` | `IDS_VICTORY_COUNT_LABEL` | Victory amount label for count modes. | `"Count"`, `0x0409` |
| `0x25CD` | `IDS_VICTORY_QUANTITY_LABEL` | Victory amount label for quantity mode. | `"Quantity"`, `0x0409` |
| `0x25D0` | `IDS_MP_PLAYER_NAME_LABEL` | Player-name column heading. | `"Name"`, `0x0409` |
| `0x25D1` | `IDS_MP_CIV_LABEL` | Civilization column heading. | `"Civ"`, `0x0409` |
| `0x25D2` | `IDS_MP_SETTINGS_LABEL` | Game-settings heading and button text. | `"Settings"`, `0x0409` |
| `0x25D3` | `IDS_MP_COMPUTER_LABEL` | Computer entry in the player list. | `"Computer"`, `0x0409` |
| `0x25D4` | `IDS_MP_CLOSED_LABEL` | Closed entry in the player list. | `"Closed"`, `0x0409` |
| `0x25D5` | `IDS_MP_OPEN_LABEL` | Open entry in the player list. | `"Open"`, `0x0409` |
| `0x25D6` | `IDS_MP_NONE_LABEL` | None entry in the single-player list. | `"None"`, `0x0409` |
| `0x25D7` | `IDS_MP_CHAT_LABEL` | Chat heading. | `"Chat"`, `0x0409` |
| `0x25D8` | `IDS_MP_NUMBER_PLAYERS_LABEL` | Number-of-players heading. | `"Number of Players"`, `0x0409` |
| `0x25E1` | `IDS_SCENARIO_VERSION_ERROR` | Scenario checksum mismatch format. | `"%s does not have this scenario or has a different version of it."`, `0x0409` |
| `0x25E2` | `IDS_PLAYER_VERSION_ERROR` | Player version mismatch format. | `"%s is not running version 1.0b of the game... Everyone must run the same version of Age of Empires before you can start the game."`, `0x0409` |
| `0x25E3` | `IDS_HOST_VERSION_ERROR` | Host version mismatch message. | `"The host is not running version 1.0b of the game... Everyone must run the same version of Age of Empires to play a multiplayer game."`, `0x0409` |
| `0x25ED` | `IDS_SCENARIO_FORMAT` | Scenario name summary format. | `"Scenario: %s"`, `0x0409` |
| `0x25EE` | `IDS_START_GAME` | Start button text. | `"Start Game"`, `0x0409` |
| `0x25EF` | `IDS_IP_LABEL` | Network-information button text. | `"IP"`, `0x0409` |
| `0x25F0` | `IDS_POPULATION_LIMIT_FORMAT` | Population summary format. | `"Population Limit: %d"`, `0x0409` |
| `0x25F1` | `IDS_PATH_FINDING_FORMAT` | Path-finding summary format. | `"Path Finding: %s"`, `0x0409` |

Resource extraction outputs are `build/evidence/request_base.json`,
`build/evidence/request_runtime_expansion.json`, and
`build/evidence/request_pinned_expansion.json`. The source lookup evidence is
`src/tribegam.cpp:812-818` and `src/basegame.cpp:766-773`.

## Shared-file requests

- Root owns `include/resource_ids.h`. Add the requested names only after review
  of the table above. Keep the numeric values unchanged.
- Owner 11 owns `include/scr_mps.h`. No declaration change is required. The
  header has unnamed parameters, so source-only parameter recovery preserves
  the existing ABI declaration.
- No layout, type, enum, global, or shared game declaration request remains.

## Code-generation and behavior limits

The source changes rename identifiers and replace three literals with existing
macros that expand to the same values. They do not change signatures, types,
scopes, evaluation order, calls, control flow, storage sizes, class layout, or
symbol identity. The source keeps the existing `position_used[9]` declaration
and `file_scratch` union despite narrower or reused PDB records.

Formatting moved selected opening braces and changed no executable statement.
It can change debug line records. No compiler output claim is made.
The source keeps the existing readiness alias uncertainty and all existing
narrowing casts and resource lookup order.

## Validation

Evidence extraction, PDB review, resource extraction, SHA256 checks, and full
Git diff review were run. Compilation, matching, audits, and tests were not
run. No build, game, or runtime command was run.
