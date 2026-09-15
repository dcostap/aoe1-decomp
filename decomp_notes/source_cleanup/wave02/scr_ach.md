# `scr_ach.cpp` source cleanup

## Delivery

- Module: `src/scr_ach.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: pending
- Changed files:
  - `src/scr_ach.cpp`
  - `decomp_notes/source_cleanup/wave02/scr_ach.md`
- Paired header: `include/scr_ach.h`
- Header owner: slot 11

This cleanup changes names, formatting, one existing resource macro use, and comments.
It does not change types, storage, calls, control flow, or resource values.

## Scope and source evidence

The source owns eight functions in PDB module `.\\Release\\scr_ach.obj`.
The procedure-scoped PDB is:

- `inventory/pdb/scoped_symbols.json`
- SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

The original executable is:

- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The function packets are the behavior evidence. They are under
`inventory/functions/0048/`:

| VA | PDB size | Function | Packet |
| --- | ---: | --- | --- |
| `0048D530` | 3256 | `TribeAchievementsScreen::TribeAchievementsScreen` | `0048D530_TribeAchievementsScreen.txt` |
| `0048E210` | 493 | `TribeAchievementsScreen::~TribeAchievementsScreen` | `0048E210_~TribeAchievementsScreen.txt` |
| `0048E400` | 3236 | `TribeAchievementsScreen::set_mode` | `0048E400_set_mode.txt` |
| `0048F0B0` | 215 | `TribeAchievementsScreen::draw` | `0048F0B0_draw.txt` |
| `0048F190` | 226 | `TribeAchievementsScreen::handle_mouse_down` | `0048F190_handle_mouse_down.txt` |
| `0048F280` | 638 | `TribeAchievementsScreen::action` | `0048F280_action.txt` |
| `0048F500` | 33 | `TribeAchievementsScreen::handle_idle` | `0048F500_handle_idle.txt` |
| `0048F530` | 146 | `TribeAchievementsScreen::wnd_proc` | `0048F530_wnd_proc.txt` |

The scalar deleting destructor at `0048E1F0` is compiler-generated.
It has no source body in this module and remains outside the cleanup set.

Every listed procedure has `this` in `ecx`.
No function static appears in these PDB records.

## Original-name recovery

The PDB names below map to the current declarations and uses.
The source now uses the recovered spellings.

| Function | Recovered parameters | Recovered locals | Change |
| --- | --- | --- | --- |
| Constructor `0048D530` | `titleText`, `end_flag` | `tabList`, `info_file`, `str`, `temptxt`, `color` | Named the unused first parameter, renamed `end_game`, and renamed `tab_list`. |
| Destructor `0048E210` | none | none | No name change. |
| `set_mode` `0048E400` | `new_mode` | `player_num`, `temptxt` | Renamed `mode`. |
| `draw` `0048F0B0` | none | none | No name change. |
| `handle_mouse_down` `0048F190` | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key` | none | Restored all five PDB parameter names. |
| `action` `0048F280` | `fromPanel`, `actionIn`, `a1`, `a2` | none | Restored all four PDB parameter names. |
| `handle_idle` `0048F500` | none | none | No name change. |
| `wnd_proc` `0048F530` | `hwnd`, `msg`, `wParam`, `lParam` | none | Restored all four PDB parameter names. |

The constructor PDB records `tabList` as `TPanel*[32 bytes]` at `-0x1c8`.
The source declaration remains `TPanel* tabList[8]`.

The `set_mode` PDB records both `txt[30]` and `temptxt[50]` at `-0x34`.
The source has one `char temptxt[50]` declaration at that storage.
The source does not add a second array because the records overlap.
This is an unresolved declaration mapping, not a safe rename.

The PDB does not establish the source names `message`, `player_name`,
`panel_name`, `column`, or the local `mode` in `wnd_proc`.
Those readable names remain unchanged.

No new source names were inferred.
All changed source names above are PDB names.

## Resource lookup evidence

The source calls `create_text`, `set_text`, and `create_button` with string IDs.
`TRIBE_Game::get_string` first calls `LoadStringA(StringTableX, ...)`.
It then falls back to `RGE_Base_Game::get_string` and `StringTable`.
The base lookup clears the buffer when `LoadStringA` fails.

The checked base-language file is the staged runtime input:

- `runtime/language.dll`
- SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Resource type: `RT_STRING`
- Language: `0x0409` (English, language ID `1033`)

The checked override files are:

- `runtime/languagex.dll`
  - SHA256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  - SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

Both `languagex.dll` files have no entries for the IDs below.
The base runtime file supplies every listed text payload.
The exact extraction is in `build/resource-strings/scr_ach/`.

| ID | Base payload | Call-site purpose | Proposed cleanup name |
| --- | --- | --- | --- |
| `0x03EA` | `X` | Close-button glyph in `create_button` | Existing `IDS_BUTTON_CLOSE` |
| `0x0C1D` | `Are you sure you want to quit this game?` | Close prompt in `wnd_proc` | `IDS_CONFIRM_QUIT_GAME` |
| `0x0FA3` | `Yes` | Yes marker in per-player result fields | `IDS_BUTTON_YES` |
| `0x269C` | `Close` | Close and back-to-summary buttons | `IDS_ACHIEVEMENTS_CLOSE` |
| `0x269E` | `Achievements` | Screen title | `IDS_ACHIEVEMENTS_TITLE` |
| `0x269F` | `Restart` | Restart button | `IDS_ACHIEVEMENTS_RESTART` |
| `0x26AC` | `Military` | Military heading and summary | `IDS_ACHIEVEMENTS_MILITARY` |
| `0x26AD` | `Economy` | Economy heading and summary | `IDS_ACHIEVEMENTS_ECONOMY` |
| `0x26AE` | `Religion` | Religion heading and summary | `IDS_ACHIEVEMENTS_RELIGION` |
| `0x26AF` | `Technology` | Technology heading and summary | `IDS_ACHIEVEMENTS_TECHNOLOGY` |
| `0x26B1` | `Total Score` | Summary-mode total score | `IDS_ACHIEVEMENTS_TOTAL_SCORE_SUMMARY` |
| `0x26B2` | `Aftermath` | Aftermath button and summary | `IDS_ACHIEVEMENTS_AFTERMATH` |
| `0x26B5` | `Total Score` | Category-mode total score | `IDS_ACHIEVEMENTS_TOTAL_SCORE_CATEGORY` |
| `0x26B6` | `Kills` | Military statistic | `IDS_ACHIEVEMENTS_KILLS` |
| `0x26B7` | `Razings` | Military statistic | `IDS_ACHIEVEMENTS_RAZINGS` |
| `0x26B8` | `Kills - Losses` | Military statistic | `IDS_ACHIEVEMENTS_KILLS_LOSSES` |
| `0x26B9` | `Losses` | Military statistic | `IDS_ACHIEVEMENTS_LOSSES` |
| `0x26BA` | `Largest Army` | Military statistic | `IDS_ACHIEVEMENTS_LARGEST_ARMY` |
| `0x26BE` | `Gold Collected` | Economy statistic | `IDS_ACHIEVEMENTS_GOLD_COLLECTED` |
| `0x26BF` | `Villager High` | Economy statistic | `IDS_ACHIEVEMENTS_VILLAGER_HIGH` |
| `0x26C0` | `Villager Bonus` | Economy statistic | `IDS_ACHIEVEMENTS_VILLAGER_BONUS` |
| `0x26C1` | `Exploration` | Economy statistic | `IDS_ACHIEVEMENTS_EXPLORATION` |
| `0x26C2` | `Most Explored` | Economy statistic | `IDS_ACHIEVEMENTS_MOST_EXPLORED` |
| `0x26C3` | `Tribute Given` | Economy statistic | `IDS_ACHIEVEMENTS_TRIBUTE_GIVEN` |
| `0x26C6` | `Conversions` | Religion statistic | `IDS_ACHIEVEMENTS_CONVERSIONS` |
| `0x26C7` | `Most Conversions` | Religion statistic | `IDS_ACHIEVEMENTS_MOST_CONVERSIONS` |
| `0x26C8` | `Ruins` | Religion statistic | `IDS_ACHIEVEMENTS_RUINS` |
| `0x26C9` | `Artifacts` | Religion statistic | `IDS_ACHIEVEMENTS_ARTIFACTS` |
| `0x26CA` | `Temples` | Religion statistic | `IDS_ACHIEVEMENTS_TEMPLES` |
| `0x26CE` | `Technologies` | Technology statistic | `IDS_ACHIEVEMENTS_TECHNOLOGIES` |
| `0x26CF` | `Bronze Age First` | Technology statistic | `IDS_ACHIEVEMENTS_BRONZE_AGE_FIRST` |
| `0x26D0` | `Iron Age First` | Technology statistic | `IDS_ACHIEVEMENTS_IRON_AGE_FIRST` |
| `0x26D1` | `Most Technologies` | Technology statistic | `IDS_ACHIEVEMENTS_MOST_TECHNOLOGIES` |
| `0x26D6` | `Survival` | Summary statistic | `IDS_ACHIEVEMENTS_SURVIVAL` |
| `0x26D7` | `Wonder` | Summary statistic | `IDS_ACHIEVEMENTS_WONDER` |
| `0x26D8` | `Timeline` | Timeline button and summary | `IDS_ACHIEVEMENTS_TIMELINE` |
| `0x26D9` | `Summary` | Summary heading | `IDS_ACHIEVEMENTS_SUMMARY` |
| `0x26DA` | `Back` | Back button | `IDS_ACHIEVEMENTS_BACK` |
| `0x26DB` | `Click a column for more details.` | Instruction text | `IDS_ACHIEVEMENTS_COLUMN_INSTRUCTION` |
| `0x26DC` | `All Artifacts/Ruins.` | Religion statistic | `IDS_ACHIEVEMENTS_ALL_ARTIFACTS_RUINS` |

The payload list proves text and call-site roles.
It does not prove original macro names.
Every proposed name except `IDS_BUTTON_CLOSE` is a new cleanup name.
No proposed name was added in this source-only change.

The source now uses existing `IDS_BUTTON_CLOSE` for `0x03EA`.
The macro is in `include/resource_ids.h` and expands to `0x03EA`.
Its name is a reviewed cleanup name, not a recovered original macro name.

The source also passes these IDs to `TScreenPanel::setup`:

| ID | Evidence | Status |
| --- | --- | --- |
| `0xC389` | `scr7` layout when `game_status == 1` | Binary `RESFILE` ID; not an `RT_STRING` ID. |
| `0xC38A` | `scr8` layout when `game_status != 1` | Binary `RESFILE` ID; not an `RT_STRING` ID. |
| `0xC38D` | `scr10` layout when `end_flag == 0` | Binary `RESFILE` ID; not an `RT_STRING` ID. |

`TEasy_Panel::setup` passes these IDs to `RESFILE_load(0x62696E61, ...)`.
The source keeps the IDs and the load order unchanged.
No string name is proposed for this binary resource namespace.

## Comments and presentation

Function definitions now use one true brace style.
Short four-parameter definitions stay on one line.
The five-parameter mouse definition wraps only for readability.

The source comment now states that mode 3 reads victory IDs 16 and 15.
The packet call order supports this statement.
The comment also records that mode 6 appears before mode 5 in the original handler.

Three incomplete signature fragments were removed near the last three functions.
Their full declarations and PDB records provide the same type facts.
They did not explain behavior.

## Code-generation and ABI limits

The edits do not change function names, classes, members, types, widths, or storage.
They do not change source order, expressions, calls, branches, or resource values.
The macro replacement expands to the same unsuffixed integer literal value.

Parameter and local names affect debug information, not executable instructions.
Brace and comment edits can change debug line records.
The new include adds only preprocessor definitions used by this source.
No compiler output was produced during this cleanup.

The `txt` and `temptxt` overlap remains unresolved.
No layout, lifetime, buffer size, or declaration scope was changed to resolve it.

## Shared-file requests

1. **`include/scr_ach.h` — owner slot 11.**
   Name assigned declarations with the recovered PDB spellings:
   `titleText`, `end_flag`, `new_mode`, `mouse_button_in`, `x`, `y`,
   `ctrl_key`, `shift_key`, `fromPanel`, `actionIn`, `a1`, `a2`, `hwnd`,
   `msg`, `wParam`, and `lParam`.
   The current declarations omit parameter names.
   This request changes no ABI and no type.

2. **`include/resource_ids.h` — resource-ID owner.**
   Review the proposed `IDS_*` mappings in the table above.
   Add one shared definition per base-language ID after owner review.
   Do not add a second name for the existing `IDS_BUTTON_CLOSE` mapping.
   The two `Total Score` IDs have distinct call-site roles and need distinct names.

3. **Binary `RESFILE` IDs.**
   Assign a separate shared domain only after the `RESFILE` namespace owner
   confirms names for `0xC389`, `0xC38A`, and `0xC38D`.
   Do not place these IDs in the base-language `IDS_*` group.

## Validation

The permitted source and Git review checks ran.
`git diff --check` passed before report creation.

Compilation was not run.
Matching was not run.
Audits were not run.
Tests were not run.
No byte-equality or semantic approval claim is made.
