# Source-cleanup wave 01: `src/scr_name.cpp`

## Handoff

- Module: `src/scr_name.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Initial source-cleanup commit: `78712f28a6170cc700e25fed568dc7cc42cc5503`
- Shared resource commit: `c9ba20d160541d928b5d9e55e1d02dce5a784e0c` (cherry-picked locally as `08253bca4342fefa97129a115b95bd36c97438ef`)
- Branch: `cleanup/staging-20260915-21`
- Assigned header: `include/scr_name.h` (read only)
- Changed paths:
  - `src/scr_name.cpp`
  - `decomp_notes/source_cleanup/wave01/scr_name.md`

The source registry uses `config/functions/src/scr_name.cpp.json`. It lists 11
normal functions. The module uses the `gx` flag profile.

## Scope and evidence

I read the repository contract and the complete source-cleanup, source-comment,
resource-ID, ownership, testing, and wave-assignment guides. I read
`include/scr_name.h` and the existing `decomp_notes/scr_name.md`.

I inspected the registry entries, the scoped PDB records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`, and
the matching packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004A/`.
The packets cover all assigned functions. They include register records and
procedure-scoped stack records. The original executable reference is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.

The scoped records name `this` in `ecx` for all 11 normal functions. The two
compiler-generated deleting destructors also have `this` in `ecx`; their
`__flags` stack records do not have source declarations. I changed no generated
function body.

## Original-name recovery

The following PDB names are recovered originals. The types and declaration
storage remain unchanged.

| VA and function | Recovered names and prior source spelling |
| --- | --- |
| `004A6800` `TRIBE_Screen_Name::get_player_names` | `curr_player` replaces `current_player`; `players` already matched. |
| `004A69B0` `TRIBE_Screen_Name::action` | `from_panel` replaces `panel`; `action_in` replaces `event`; `action_val1` replaces `p3`; `action_val2` replaces `p4`; `str` already matched. |
| `004A6D50` `TRIBE_Dialog_Name::TRIBE_Dialog_Name` | `parent_panel_in` replaces `screen`; `tab_list` already matched. |
| `004A6FF0` `TRIBE_Dialog_Name::action` | `from_panel` replaces `panel`; `action_in` replaces `p2`; `action_val1` replaces `p3`; `action_val2` replaces `p4`. |
| `004A71D0` `TRIBE_Dialog_Name::wnd_proc` | `hwnd`, `msg`, `wParam`, and `lParam` replace `param1`, `param2`, `param3`, and `param4`. |

The packets and scoped records show these source-local names:

- `004A6800`: `curr_player` is `long`; `players` is `char**`.
- `004A68C0`: `tab_list` is `TPanel*[20 bytes]`. The source keeps five entries.
- `004A69B0`: `str` is `char[256]`. The four parameters have the types in the existing declaration.
- `004A6D50`: `parent_panel_in` is `TScreenPanel*`; `tab_list` is `TPanel*[12 bytes]`. The source keeps three entries.
- `004A71D0`: `hwnd` is `void*`; `msg` and `wParam` are `unsigned int`; `lParam` is `long`.

The other six normal functions have no named stack locals or named parameters
besides their `this` register record. I did not force names for reused or
unrecorded storage. Existing non-PDB names remain descriptive and are not
claimed as recovered originals: `name_selection_screen`, `setup_info_file`,
`info`, `count`, `i`, `disabled`, `line`, and `cancel`. No new invented
parameter or local names were added.

Coverage includes these source-order records and line spans:

| VA | Function | PDB source span | Result |
| --- | --- | --- | --- |
| `004A63D0` | `TRIBE_Screen_Name::TRIBE_Screen_Name` | 50-96 | Reviewed; no named source parameter or local. |
| `004A66E0` | `TRIBE_Screen_Name::~TRIBE_Screen_Name` | 102-114 | Reviewed; no named source parameter or local. |
| `004A67C0` | `TRIBE_Screen_Name::init_vars` | 120-130 | Reviewed; no named source parameter or local. |
| `004A6800` | `TRIBE_Screen_Name::get_player_names` | 136-163 | Recovered `curr_player`. |
| `004A68C0` | `TRIBE_Screen_Name::setup_tab_order` | 169-197 | Confirmed `tab_list`; no forced rename. |
| `004A6980` | `TRIBE_Screen_Name::handle_idle` | 204-219 | Reviewed; no named source parameter or local. |
| `004A69B0` | `TRIBE_Screen_Name::action` | 225-322 | Recovered four parameters; confirmed `str`. |
| `004A6D50` | `TRIBE_Dialog_Name::TRIBE_Dialog_Name` | 329-361 | Recovered `parent_panel_in`; confirmed `tab_list`. |
| `004A6F60` | `TRIBE_Dialog_Name::~TRIBE_Dialog_Name` | 367-373 | Reviewed; no named source parameter or local. |
| `004A6FF0` | `TRIBE_Dialog_Name::action` | 379-423 | Recovered four parameters. |
| `004A71D0` | `TRIBE_Dialog_Name::wnd_proc` | 429-440 | Recovered four parameters. |

The PDB also lists compiler-generated deleting destructors at `004A66C0`
and `004A6F40`. They have no standalone source body in the registry and were
not edited.

## Resource IDs

The source now reuses these existing macros from the root-owned
`include/resource_ids.h`:

- `0x0FA1` -> `STRING_ID_BUTTON_OK`
- `0x0FA2` -> `STRING_ID_BUTTON_CANCEL`
- `0x7531` -> `STRING_ID_HELP_OK`
- `0x7532` -> `STRING_ID_HELP_CANCEL`

The shared resource commit defines the following new mappings. The names are
new cleanup names. No name is claimed as an original macro name.

The common resource evidence for every row is:

- Base DLL: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
- Base SHA-256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Resource type: `RT_STRING`
- Language: `0x0409` (`1033`)
- Lookup: `StringTableX` is checked first, then `StringTable` through the base lookup.
- Expansion DLL: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`; all requested IDs are missing.
- Pinned XPack expansion reference: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`; all requested IDs are missing.
- Fallback: a miss in `StringTableX` calls `RGE_Base_Game::get_string`, which reads the base `language.dll` table. Both checked expansion files miss the help IDs; the base `language.dll` supplies the recorded text.

| Numeric ID | Purpose evidence in `src/scr_name.cpp` | Exact text or status in base DLL | Applied macro |
| --- | --- | --- | --- |
| `0x29FE` | Screen title passed to `create_text` for `title`. | `Select Player` | `STRING_ID_SELECT_PLAYER_TITLE` (applied) |
| `0x29FF` | Player-name list label passed to `create_text` for `name_text`. | `Name` | `STRING_ID_PLAYER_NAME_LABEL` (applied) |
| `0x2A00` | New-player button caption passed to `create_button`. | `New` | `STRING_ID_BUTTON_NEW_PLAYER` (applied) |
| `0x2A01` | Remove-player button caption passed to `create_button`. | `Remove` | `STRING_ID_BUTTON_REMOVE_PLAYER` (applied) |
| `0x2A02` | Format string passed to `get_string` before `sprintf`; the format consumes the selected player name. | `Are you sure you want to remove player %s?` | `STRING_ID_CONFIRM_REMOVE_PLAYER` (applied) |
| `0x2A03` | New-player dialog heading passed to `create_text` for `title`. | `Name` | `STRING_ID_NAME_DIALOG_TITLE` (applied) |
| `0x2A04` | New-player dialog name label passed to `create_text` for `name_text`. | `New Player` | `STRING_ID_NEW_PLAYER_NAME_LABEL` (applied) |
| `0x03EA` | Close control caption passed to `create_button` for `close_button`. | `X` | `STRING_ID_BUTTON_CLOSE` (applied) |
| `0x765C` | Help ID passed to `set_help_info` for the player-name scrollbar. | `Select a player name.` | `STRING_ID_HELP_PLAYER_NAME_LIST` (applied) |
| `0x765D` | Help ID passed to `set_help_info` for the New button. | `Click to add a new player name.` | `STRING_ID_HELP_ADD_PLAYER_NAME` (applied) |
| `0x765E` | Help ID passed to `set_help_info` for the Remove button. | `Click to remove a player name.` | `STRING_ID_HELP_REMOVE_PLAYER_NAME` (applied) |

The source now uses these shared macros. It also uses the existing OK and
Cancel macros. The shared header remains outside this module's commit.

The extraction tool was run with an explicit DLL path. It reads PE bytes and
does not load or execute the DLL. The exact strings and hashes above come from
that extraction. The source keeps all lookup calls, formatting tokens, buffer
sizes, and fallback behavior.

## Header request

I read `include/scr_name.h` and did not edit it. Please apply these parameter
name-only changes in the owner-03 header commit:

```cpp
virtual long action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2);
TRIBE_Dialog_Name(TScreenPanel* parent_panel_in);
long action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2);
virtual long wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam);
```

These names match the procedure-scoped PDB records. The types, order, virtual
status, size checks, and ABI remain unchanged. This request does not block the
source cleanup. Root owns all new resource definitions.

## Source changes and output risk

- Restored procedure-scoped PDB parameter and local names.
- Reused four existing resource macros and applied 11 reviewed resource
  macros from the shared commit. Their expansions retain the original
  literals and effective integer types.
- Added the existing resource-ID header include. It adds macros only.
- Applied 1TBS function braces and joined short calls and signatures.
- Preserved source order, control flow, declarations, types, scopes, storage,
  calls, literals, string contents, buffer sizes, and lookup order.
- Added no source comments. No structural rewrite or bug repair was made.
- No public function, class, member, global, layout, calling convention, or
  symbol identity changed.

Formatting can change debug line records. Macro use and the include can change
source line mapping. Compiler output, relocations, data, and direct-call target
equality remain unvalidated.

## Unresolved items

- The PDB has no source-local records for `info`, `count`, `i`, `disabled`,
  `line`, or either `cancel` local. I left those declarations unchanged.
- The PDB function-static list is empty, so the existing static names are not
  claimed as recovered original names.
- The 11 resource mappings are applied from shared commit
  `c9ba20d160541d928b5d9e55e1d02dce5a784e0c`. Their text and purpose evidence
  remain recorded above.
- The proposed header names need owner-03 integration.

## Shared-header integration note

I cherry-picked shared commit
`c9ba20d160541d928b5d9e55e1d02dce5a784e0c` locally. Git created worker-local
commit `08253bca4342fefa97129a115b95bd36c97438ef`, which changes only
`include/resource_ids.h`.

Owner integration must use the shared commit already approved by root. Exclude
worker-local cherry-pick `08253bca4342fefa97129a115b95bd36c97438ef` from the
scr_name module commits. This worker does not edit `include/resource_ids.h`.

## Validation status

Compilation, matching, audits, tests, and games were **NOT run**. I did not
invoke a compiler, build command, matching command, audit, test, or game.
I performed only evidence extraction and source/Git diff review.

## Commit record

- Initial source cleanup commit: `78712f28a6170cc700e25fed568dc7cc42cc5503`
- Initial report commit: `5345cb57e024f094e4e78c389e0c05850cbda1d7`
- Shared root commit: `c9ba20d160541d928b5d9e55e1d02dce5a784e0c`
- Worker-local shared-header cherry-pick: `08253bca4342fefa97129a115b95bd36c97438ef` (exclude from module integration)
- Resource substitution and report update: this commit; Git records its full hash in the delivery summary.
- Final source-cleanup commit: this report-update commit; Git records its full hash in the delivery summary.
