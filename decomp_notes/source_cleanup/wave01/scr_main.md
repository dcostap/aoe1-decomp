# Source cleanup: `src/scr_main.cpp`

## Handoff

- Module: `src/scr_main.cpp`
- Header read-only: `include/scr_main.h`
- Branch: `cleanup/staging-20260915-24`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Source cleanup commit: `e522439b9e165e6da621ed722c6834fc8fcce6eb`
- Changed paths:
  - `src/scr_main.cpp`
  - `decomp_notes/source_cleanup/wave01/scr_main.md`

The source commit changes only the assigned source file. This report is the
second commit and documents the source commit above.

## Scope and evidence

I read the complete source-cleanup, comment, resource-ID, owner, and testing
guides. I also read the repository contracts, the assigned module header, the
source registry, and the existing `scr_main` notes.

I inspected all eleven assigned packets under `inventory/functions/0049/`.
I inspected every assigned VA in `inventory/pdb/scoped_symbols.json`, including
register records. I used the original source spans, procedure types, and stack
offsets as name evidence.

I inspected the pinned toolchain record. I did not inspect or change another
source owner's files.

## Original-name recovery coverage

Every assigned procedure has one PDB register record for implicit `this`. The
record type matches its owning class in all eleven procedures.

| VA | Procedure | PDB names and source result |
| --- | --- | --- |
| `0049E6D0` | `TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu` | PDB stack names are `tabList`, `temp_str`, `rect`, and `diff`. The source now uses `tabList`. The other three names already matched. |
| `0049EC00` | `TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu` | No PDB stack names. No rename was supported. |
| `0049ECD0` | `TRIBE_Screen_Main_Menu::handle_idle` | No PDB stack names. No rename was supported. |
| `0049ED00` | `TRIBE_Screen_Main_Menu::key_down_action` | PDB names are `key`, `count`, `alt_key`, `ctrl_key`, and `shift_key`. The source now uses all five names. |
| `0049EE00` | `TRIBE_Screen_Main_Menu::action` | PDB names are `fromPanel`, `actionIn`, `a1`, and `a2`. The source now uses all four names. |
| `0049F0D0` | `TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error` | No PDB stack names. No rename was supported. |
| `0049F240` | `TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error` | No PDB stack names. No rename was supported. |
| `0049F2B0` | `TRIBE_Screen_Main_Error::set_text(char*)` | PDB name is `message_in`. The source now uses `message_in`. |
| `0049F2D0` | `TRIBE_Screen_Main_Error::set_text(long)` | PDB name is `message_in`. The source now uses `message_in`. |
| `0049F2F0` | `TRIBE_Screen_Main_Error::action` | PDB names are `from_panel`, `action_in`, `val1`, and `val2`. The source now uses all four names. |
| `0049F340` | `TRIBE_Screen_Main_Error::handle_idle` | No PDB stack names. No rename was supported. |

The constructor PDB records `tabList` as `TPanel*[20 bytes]` at offset
`-0x220`. The source declaration is five `TPanel*` entries and matches that
record. The PDB also records `temp_str` as `char[512]`, `rect` as `tagRECT`,
and `diff` as `int`.

The key handler PDB records the five parameter types at offsets `+0x4`
through `+0x14`. The source types and order remain unchanged. The menu action
PDB records `TPanel*`, `long`, `unsigned long`, and `unsigned long` at the four
parameter offsets. The error action has the same four types and offsets.

The PDB has no stack records for the following existing source names:
`i`, `clear_button`, `button_width`, `panel_height`, `copy1`, `copy2`,
`tab_dst`, `tab_src`, `result`, `panel`, and `state`. I kept these declarations
and scopes. I did not claim them as recovered originals. The error action keeps
its `panel` and `state` aliases because the cleanup does not remove declarations
or change storage.

No reused PDB stack slot created an uncertain rename in this module. No public
function, class, member, global, type, storage layout, calling convention, or
source order changed.

## Constants and resources

The source now reuses the existing `IDS_BUTTON_OK` macro for numeric ID
`0x0FA1`. The macro is already defined in `include/resource_ids.h` with the
same value and effective type. No new constant was added by this worker.

The following new shared resource mappings are requested. The proposed names
are cleanup names, not recovered original macro names. The source keeps these
numeric uses until the shared header owner reviews the requests.

All requests use these lookup facts:

- Base DLL: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
- Base SHA-256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Expansion DLL: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
- Expansion SHA-256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Pinned XPack DLL: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
- Pinned XPack SHA-256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
- Resource type: `RT_STRING`
- Checked language: `0x0409` (`1033`)
- Lookup path: `TRIBE_Game::get_string` tries `languagex.dll` first, then falls back to `language.dll`.
- The base lookup clears the destination when the ID is missing.

| ID | Proposed macro | Purpose evidence | Base text | Expansion text | Pinned XPack text |
| --- | --- | --- | --- | --- | --- |
| `0x23F2` | `IDS_MENU_SINGLE_PLAYER` | Main-menu button `button[0]` starts single-player flow. | `Single Player` | Missing; falls back to base. | Missing. |
| `0x23F3` | `IDS_MENU_MULTIPLAYER` | Main-menu button `button[1]` starts multiplayer flow. | `Multiplayer` | Missing; falls back to base. | Missing. |
| `0x23F5` | `IDS_MENU_HELP` | Main-menu button `button[2]` opens the help prompt. | `Help` | Missing; falls back to base. | Missing. |
| `0x23F6` | `IDS_MENU_SCENARIO_BUILDER` | Main-menu button `button[3]` starts the scenario builder. | `Scenario Builder` | Missing; falls back to base. | Missing. |
| `0x23F7` | `IDS_MENU_EXIT` | Main-menu button `button[4]` closes the game. | `Exit` | Missing; falls back to base. | Missing. |
| `0x2419` | `IDS_PRODUCT_TITLE` | Main-menu title text uses this product-title resource. | `Microsoft© Age of Empires™` | `Microsoft® Age of Empires® Expansion:` | `Microsoft© Age of Empires, the Rise of Rome™` |
| `0x241B` | `IDS_COPYRIGHT_PREFIX` | The source uses this text as the first copyright segment. | `© & ` | Empty; falls back to base. | Empty. |
| `0x241C` | `IDS_COPYRIGHT_SUFFIX` | The source uses this text as the final copyright segment. | `1997 Microsoft Corporation. All rights reserved.` | `1997-1998 Microsoft Corporation. All rights reserved.` | `1998 Microsoft Corporation. All rights reserved.` |
| `0x2424` | `IDS_COPYRIGHT_SEPARATOR` | The source checks this resource before choosing split or combined copyright text. | Empty. | Empty. | Missing. |
| `0x2425` | `IDS_COPYRIGHT_WARNING` | The source creates the copyright-law warning panel with this ID. | `This program is protected by U.S. and international copyright laws as described in Menu/About.` | Empty. | Missing. |
| `0x03EA` | `IDS_BUTTON_CLOSE` | The error screen creates its close button with this caption ID. | `X` | Missing; falls back to base. | Missing. |
| `0x07D7` | `IDS_ERROR_LOAD_GAME_DATA` | Developer-mode database reload reports this error. | `Could not load game data.` | Empty; falls back to base. | Missing. |
| `0x07D8` | `IDS_ERROR_INSERT_CD_SINGLE_PLAYER` | The single-player path reports a missing game CD. | `You must insert a game CD to play a single player game, and then restart Age of Empires` | Empty; falls back to base. | Missing. |
| `0x07DA` | `IDS_ERROR_INSERT_CD_SCENARIO_BUILDER` | The scenario-builder path reports a missing game CD. | `You must insert a game CD to use the scenario builder.` | Empty; falls back to base. | Missing. |
| `0x1D4F7` | `IDS_HELP_DIALOG_TITLE` | The Help button passes this ID to the `Confirm Dialog` title before `WinHelpA`. | Missing. | Missing. | Missing. |

The checked DLLs contain no text for `0x1D4F7`. Its resource type remains
inferred from `popupOKDialog(long, char*, int, int)`. Its call path proves the
help-dialog title role, but not its text.

The numeric values `0xC383` and `0xC4E6` are passed to screen and picture
setup calls. They are not `RT_STRING` lookups. This report does not propose
names for those non-string resource values.

## Header request

The header owner should consider these declaration-only parameter names in
`include/scr_main.h`:

```cpp
virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);

void set_text(char* message_in);
void set_text(long message_in);
virtual long action(TPanel* from_panel, long action_in, unsigned long val1, unsigned long val2);
```

These names come from the procedure-scoped PDB records listed above. The
request changes no type, order, ABI, or layout. This worker did not edit the
header.

## Comments, formatting, and output risk

No new source comment was needed. Existing names and control flow explain the
local behavior without speculation.

The cleanup restores PDB identifier spellings and joins short function
signatures. It does not remove aliases, casts, temporaries, calls, or unusual
forms. It does not change literal values, storage, declaration scope, source
order, lookup order, or resource fallback behavior.

Identifier changes can alter debug names and line records. The existing resource
macro expands to the original `0x0FA1` integer value. Compiler output,
relocations, and direct-call targets remain unvalidated.

## Validation

I ran `git diff --check`, source diff inspection, PDB evidence inspection, and
read-only resource extraction. I ran the resource extractor with `--help`
before use.

Compilation, matching, audits, tests, and games were **NOT run**. I did not
invoke a compiler, build command, matcher, audit, test suite, or game.

## Commits

- Base: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Source cleanup: `e522439b9e165e6da621ed722c6834fc8fcce6eb`
- Report: committed separately after this source commit; its full hash is
  recorded in the handoff response.
