# Source cleanup report: `dlg_dip.cpp`

## Delivery

- Module: `src/dlg_dip.cpp`
- Branch: `cleanup/staging-20260915-85`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Previous report commit: `61dbb6ae3d91aedf6eea80279691dea99ce860e4`
- Worker-local `include/resource_ids.h` import commit: `46805ee2a76f12ba7a50fa925461d1f787a00e61`
- Actual root approval commit: `8c56055b7feee1526f296bd306036a4c34f38041`
- Source head from `git rev-parse` before this report commit: `f9d038289fa1d7a46a81b2667839ec08f41abf31`
- Source commits: `d0855b8b272c3d10d8c41aa82a98532ea6ef3c96`, `f9d038289fa1d7a46a81b2667839ec08f41abf31`
- Changed files: `src/dlg_dip.cpp`; this report.

The source registry file is `config/functions/src/dlg_dip.cpp.json`. It selects eight normal procedures. The source also covers one compiler-generated scalar deleting destructor. No header changed.

## Evidence

I read the procedure-scoped PDB records at:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

I selected the function packets named by the source registry. The packets are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043C930_TribeDiplomacyDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043D6C0_scalar_deleting_destructor.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043D6E0_TribeDiplomacyDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043D8A0_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E530_check_gold.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E5C0_check_wood.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E650_check_food.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E6E0_check_stone.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043E770_draw.txt`

The original executable reference is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`

The preserved pre-cleanup build is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`

The original PDB source path is `C:\msdev\work\age1_x1\dlg_dip.cpp`.

## Original-name recovery coverage

Every procedure has a scoped PDB review. Each normal procedure has a `this` register named `this` in `ecx`. The scalar deleting destructor has the same register record.

| VA | Procedure | PDB source span and size | PDB parameters and locals | Source result |
| --- | --- | --- | --- | --- |
| `0043C930` | `TribeDiplomacyDialog::TribeDiplomacyDialog` | Lines 77-369; 3457 bytes | `parentPanel` (`TScreenPanel*`, `+0x4`); `tabList` (`TPanel*[140 bytes]`, `-0x98`); `paletteColor` (`tagPALETTEENTRY`, `-0x100`); `tabCount` (`int`, `-0x118`); `temp_str` (`char[100]`, `-0xFC`); `a` (`int`, `-0x128`); `world` (`RGE_Game_World*`, `-0x124`); `disable_buttons` (`int`, `-0x10C`); `humanity` (`int`, `-0x120`); `this` (`ecx`) | Restored `parentPanel`, `tabList`, `paletteColor`, `tabCount`, and `a`. The other PDB names were already present. |
| `0043D6C0` | scalar deleting destructor | No source span; 30 bytes | `__flags` (`unsigned int`, `+0x4`); `this` (`ecx`) | Compiler-generated. It has no source owner or rename. |
| `0043D6E0` | `TribeDiplomacyDialog::~TribeDiplomacyDialog` | Lines 374-428; 445 bytes | No stack symbols; `this` (`ecx`) | No PDB local rename was available. |
| `0043D8A0` | `TribeDiplomacyDialog::action` | Lines 434-738; 3201 bytes | `fromPanel` (`TPanel*`, `+0x4`); `actionIn` (`long`, `+0x8`); `a1` (`unsigned long`, `+0xC`); `a2` (`unsigned long`, `+0x10`); `temp_str` (`char[256]`, `-0x100`); `cost` (`float`, `-0x108`); `tc` (`TRIBE_Command*`, `-0x104`); `this` (`ecx`) | Restored the four parameters and renamed `commands` to `tc`. `temp_str` and `cost` were already present. |
| `0043E530` | `check_gold` | Lines 744-771; 136 bytes | No stack symbols; `this` (`ecx`) | No PDB local rename was available. |
| `0043E5C0` | `check_wood` | Lines 777-805; 136 bytes | No stack symbols; `this` (`ecx`) | No PDB local rename was available. |
| `0043E650` | `check_food` | Lines 811-840; 135 bytes | No stack symbols; `this` (`ecx`) | No PDB local rename was available. |
| `0043E6E0` | `check_stone` | Lines 846-874; 136 bytes | No stack symbols; `this` (`ecx`) | No PDB local rename was available. |
| `0043E770` | `draw` | Lines 880-903; 195 bytes | No stack symbols; `this` (`ecx`) | No PDB local rename was available. |

The constructor's `a` maps to the row y-coordinate. The scoped PDB record names it `a`, gives type `int` (`T_INT4(0074)`), and gives PDB offset `-0x128`. The packet's Ghidra listing names the same logical slot `Stack[-0x12C] a`.

The original packet shows the declaration's behavior, not only its home. At `0043CD40`, the instruction `mov dword [esp+14h],50h` initializes `a` to `0x50`. The row-control path loads that value at `0043CF4D` and `0043CF84`. The tribute-control path loads it at `0043D05E`. At `0043D1E7`, the loop loads the value, `0043D1EF` adds `0x1E`, and `0043D1F7` stores it back. These uses match the source local previously named `y`: it supplies the row coordinate and advances once per player. This instruction and type evidence proves the `y` to `a` mapping without relying on a reused stack home alone.

The action's `tc` maps to the `TRIBE_Command*` used for the command calls. No reused stack-slot mapping was forced.

### Renames in the source

- Constructor parameter `parent` became recovered PDB name `parentPanel`.
- Constructor local `palette_color` became recovered PDB name `paletteColor`.
- Constructor local `tab_list` became recovered PDB name `tabList`.
- Constructor local `tab_count` became recovered PDB name `tabCount`.
- Constructor local `y` became recovered PDB name `a`.
- Action parameter `panel` became recovered PDB name `fromPanel`.
- Action parameter `event` became recovered PDB name `actionIn`.
- Action parameter `param_3` became recovered PDB name `a1`.
- Action parameter `param_4` became recovered PDB name `a2`.
- Action local `commands` became recovered PDB name `tc`.

The original spellings use both mixed case and underscores. The source preserves them. The PDB does not provide names for the remaining optimized locals. The source retains these existing descriptive or inferred names and does not claim that they are original:

- Constructor: `i`, `player_id`, `row`, `computer_font`, `player_number`, `value`, `buttons`, `relation`, and `market`.
- Destructor: `i`.
- Action: `allied_victory`, `state`, `world`, `player_id`, `row`, `relation`, `player`, `player_count`, `amount`, `available`, and `i`.
- `check_gold`: `gold_ok`, `player`, `i`, and `button`.
- `check_wood`: `result`, `player`, `available`, `i`, and `button`.
- `check_food`: `has_food`, `i`, `buttons`, and `player`.
- `check_stone`: `result`, `i`, `buttons`, and `player`.
- `draw`: `y`, `world`, `i`, `player`, and `colors`.

These retained names use snake case where they are invented names. Short loop names remain unchanged because no PDB mapping proves a different name. No parameter or local with a PDB record remains unresolved.

## Constants and resource evidence

I ran `python tools/inspect_pe_strings.py --help` before extraction. The extraction artifacts are under this worktree:

- `build/resource-strings/dlg_dip-runtime-language-3.json`
- `build/resource-strings/dlg_dip-runtime-languagex-3.json`
- `build/resource-strings/dlg_dip-original-languagex-3.json`

The current base resource input is `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`, SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`. The entries below use language `0x0409` (`1033`). The current expansion input is `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`. The pinned original expansion reference is `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

`TEasy_Panel::create_text` and `create_button` resolve numeric strings through `TPanel::get_string`. That call reaches the game string lookup. `TRIBE_Game::get_string` checks `StringTableX` first, then the base `StringTable`. Thus the lookup is `runtime/languagex.dll` followed by `runtime/language.dll`. `set_help_info` stores an ID. `TPanel::get_help_info` resolves it through the same lookup when help text is requested.

### Base string IDs

The base file returned these exact strings. The current expansion file reported each of these IDs as missing. The pinned original expansion file also reported each as missing.

| ID | Exact base text | Call-site purpose | Applied cleanup macro |
| --- | --- | --- | --- |
| `0x267B` | `Diplomacy` | Dialog title | `STRING_ID_DIPLOMACY_TITLE` |
| `0x267C` | `Civilization` | Civilization column title | `STRING_ID_DIPLOMACY_CIVILIZATION` |
| `0x267D` | `Ally` | Ally column title | `STRING_ID_DIPLOMACY_ALLY` |
| `0x267E` | `Neutral` | Neutral column title | `STRING_ID_DIPLOMACY_NEUTRAL` |
| `0x267F` | `Enemy` | Enemy column title | `STRING_ID_DIPLOMACY_ENEMY` |
| `0x2680` | `Pay Tribute (cost %d%%)` | Formatted tribute-cost title | `STRING_ID_DIPLOMACY_PAY_TRIBUTE_FORMAT` |
| `0x2681` | `Allied Victory` | Allied-victory label | `STRING_ID_DIPLOMACY_ALLIED_VICTORY` |
| `0x2683` | `Clear Tributes` | Clear button label | `STRING_ID_DIPLOMACY_CLEAR_TRIBUTES` |
| `0x2686` | `Name` | Player-name column title | `STRING_ID_DIPLOMACY_NAME` |
| `0x2687` | `You need a Market to pay tribute.` | Market requirement notice | `STRING_ID_DIPLOMACY_NEED_MARKET` |
| `0x0FA9` | `?` | Help button label | `STRING_ID_BUTTON_HELP` |

The existing shared definitions `STRING_ID_BUTTON_OK` (`0x0FA1`) and `STRING_ID_BUTTON_CANCEL` (`0x0FA2`) were reused. The base file contains exact text `OK` and `Cancel` for these IDs. The expansion file and pinned original expansion file report both IDs as missing.

The existing shared definitions `STRING_ID_HELP_OK` (`0x7531`) and `STRING_ID_HELP_CANCEL` (`0x7532`) were reused. The current base file reports both IDs as missing. The current expansion file and pinned original expansion file also report both IDs as missing. Their purpose is established by `set_help_info` on the OK and Cancel buttons. Missing text does not change that purpose.

### Diplomacy help IDs

The base file contains these exact texts. The current expansion file contains the listed result for each ID. The pinned original expansion file reports every listed ID as missing.

| ID | Exact base text | Current expansion result | Call-site purpose | Applied cleanup macro |
| --- | --- | --- | --- | --- |
| `0x7684` | `Click to set your diplomatic stance toward this player as Ally. Your military units do not attack this civilization.` | Empty slot | Ally stance help | `STRING_ID_HELP_DIPLOMACY_ALLY` |
| `0x7685` | `Click to set your diplomatic stance toward this player as Neutral. Your military units attack all buildings and military units (but not villagers) who enter their sight.` | `Click to set your diplomatic stance toward this  player as Neutral. Your military units attack buildings and villagers when commanded and automatically attack all military units in their sight.` | Neutral stance help | `STRING_ID_HELP_DIPLOMACY_NEUTRAL` |
| `0x7686` | `Click to set your diplomatic stance toward this player as Enemy. Your military units (except Scouts) attack all buildings, military units, and villagers who enter their sight.` | Empty slot | Enemy stance help | `STRING_ID_HELP_DIPLOMACY_ENEMY` |
| `0x7687` | `Click to tribute this player 100 wood. Each time you click the button, 125 wood is deducted from your stockpile (100 goes to the player and 25 is paid as a fee).` | Empty slot | Wood tribute help | `STRING_ID_HELP_DIPLOMACY_TRIBUTE_WOOD` |
| `0x7688` | `Click to tribute this player 100 food. Each time you click the button, 125 food is deducted from your stockpile (100 goes to the player and 25 is paid as a fee).` | Empty slot | Food tribute help | `STRING_ID_HELP_DIPLOMACY_TRIBUTE_FOOD` |
| `0x7689` | `Click to tribute this player 100 gold. Each time you click the button, 125 gold is deducted from your stockpile (100 goes to the player and 25 is paid as a fee).` | Empty slot | Gold tribute help | `STRING_ID_HELP_DIPLOMACY_TRIBUTE_GOLD` |
| `0x768A` | `Click to tribute this player 100 stone. Each time you click the button, 125 stone is deducted from your stockpile (100 goes to the player and 25 is paid as a fee).` | Empty slot | Stone tribute help | `STRING_ID_HELP_DIPLOMACY_TRIBUTE_STONE` |
| `0x768B` | `Click to clear all tributes before they are paid.` | Empty slot | Clear-tributes help | `STRING_ID_HELP_DIPLOMACY_CLEAR_TRIBUTES` |
| `0x768C` | `If there is a check in the box, allied players win or lose as a team. Any allied player who achieves the victory condition wins the game for all allies. All players who want to pursue an allied victory must select Allied Victory.` | Empty slot | Allied-victory help | `STRING_ID_HELP_DIPLOMACY_ALLIED_VICTORY` |

The worker-local header import commit `46805ee2a76f12ba7a50fa925461d1f787a00e61` defines all proposed diplomacy names. Root approval is recorded by commit `8c56055b7feee1526f296bd306036a4c34f38041`. The source now uses these approved macros. They are cleanup names, not recovered macro names.

The `0x69` argument to `get_string2` is a string-group selector. It is not a direct string-table ID. `TRIBE_Game::get_string2` uses it to select the civilization-name branch, and `master_player_id` selects the resulting resource. The source keeps `0x69` and the data-driven lookup unchanged. Shape IDs `0xC62C` and `0xC63A` are not RT_STRING IDs and remain numeric.

No source comment was added. The names and this report provide the supported context. The `%d%%` format, lookup order, fallback behavior, buffer sizes, and all numeric values remain unchanged.

## Header requests

`include/dlg_dip.h` belongs to owner 10 and was not edited. The owner may add these recovered parameter names without changing the ABI:

```cpp
TribeDiplomacyDialog(TScreenPanel* parentPanel);
virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
```

The worker-local `include/resource_ids.h` import at commit `46805ee2a76f12ba7a50fa925461d1f787a00e61` contains the applied definitions below. Root approval is recorded by commit `8c56055b7feee1526f296bd306036a4c34f38041`:

```cpp
#define STRING_ID_DIPLOMACY_TITLE 0x267B
#define STRING_ID_DIPLOMACY_CIVILIZATION 0x267C
#define STRING_ID_DIPLOMACY_ALLY 0x267D
#define STRING_ID_DIPLOMACY_NEUTRAL 0x267E
#define STRING_ID_DIPLOMACY_ENEMY 0x267F
#define STRING_ID_DIPLOMACY_PAY_TRIBUTE_FORMAT 0x2680
#define STRING_ID_DIPLOMACY_ALLIED_VICTORY 0x2681
#define STRING_ID_DIPLOMACY_CLEAR_TRIBUTES 0x2683
#define STRING_ID_DIPLOMACY_NAME 0x2686
#define STRING_ID_DIPLOMACY_NEED_MARKET 0x2687
#define STRING_ID_BUTTON_HELP 0x0FA9
#define STRING_ID_HELP_DIPLOMACY_ALLY 0x7684
#define STRING_ID_HELP_DIPLOMACY_NEUTRAL 0x7685
#define STRING_ID_HELP_DIPLOMACY_ENEMY 0x7686
#define STRING_ID_HELP_DIPLOMACY_TRIBUTE_WOOD 0x7687
#define STRING_ID_HELP_DIPLOMACY_TRIBUTE_FOOD 0x7688
#define STRING_ID_HELP_DIPLOMACY_TRIBUTE_GOLD 0x7689
#define STRING_ID_HELP_DIPLOMACY_TRIBUTE_STONE 0x768A
#define STRING_ID_HELP_DIPLOMACY_CLEAR_TRIBUTES 0x768B
#define STRING_ID_HELP_DIPLOMACY_ALLIED_VICTORY 0x768C
```

No resource declaration request remains. No request exists for the already defined OK and Cancel mappings.

## Code-generation review

The source changes rename identifiers, add the existing resource-ID header, replace all approved dialog resource IDs with macros that expand to the same values, and move function braces to 1TBS form. They do not change types, declaration points, scope, storage, field layout, evaluation order, control flow, calls, function boundaries, relocations, or ABI symbols. No helper, wrapper, assembly, or layout change was added.

The constructor's recovered `a` remains an `int` with the same initialization and updates. The action's recovered `tc` remains a `TRIBE_Command*` with the same declaration scope and calls. The resource macros retain integer literal semantics. Compiler output was not checked.

## Validation

I ran `git diff --check` after the source edit. I inspected the complete source diff before committing.

Compilation, matching, audits, and tests were not run. No build, compiler check, game, or runtime harness was run.
