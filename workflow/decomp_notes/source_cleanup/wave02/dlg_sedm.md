# `dlg_sedm.cpp` source-cleanup report

## Delivery and Git history

- Module: `src/dlg_sedm.cpp`
- Branch: `cleanup/staging-20260915-90`
- Base commit from `git rev-parse`:
  `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Initial source head from `git rev-parse`:
  `b43aab2ed74523e70c0a514fa59be3807540d245`
- Initial report commit:
  `8243d31a4276905a4a367c411916ef6716e9f98b`
- Worker-local resource-header import provenance:
  `3bff68f3de98c7273f9a41faf3398b68cc17f15a`
- Actual root approval:
  `8c56055b7feee1526f296bd306036a4c34f38041`
- Correction source head from `git rev-parse`:
  `bc983e07915b974a17516dde307dab8a6d6be818`
- Correction source commit: `Apply dlg_sedm resource IDs`
- The correction report commit follows the correction source commit.

Changed files:

- `src/dlg_sedm.cpp`
- `workflow/decomp_notes/source_cleanup/wave02/dlg_sedm.md`

`include/dlg_sedm.h` was read and not edited. Owner 10 owns that header.
No other file changed.

## Scope and packet selection

The source registry is:

`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/dlg_sedm.cpp.json`

It registers these three handwritten procedures in source and address order:

- `00440140` `TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu`
- `00440360` `TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu`
- `00440400` `TRIBE_Dialog_Sed_Menu::action`

The registry marks all three procedures `matching` at the base. No status was
changed in this cleanup. The compiler-generated scalar deleting destructor at
`00440340` is not a handwritten registry procedure.

I selected the function packets through that source registry. The packet paths
are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00440140_TRIBE_Dialog_Sed_Menu.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00440360_TRIBE_Dialog_Sed_Menu.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00440400_action.txt`

The procedure-scoped PDB evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source path is `C:\msdev\work\age1_x1\dlg_sedm.cpp`.
The packet line spans are 41-58, 64-75, and 81-274.

## Systematic PDB coverage

I inspected stack and register symbols for every procedure in this source
module, including the generated scalar deleting destructor.
The PDB records list no function statics for these procedures.

| VA and procedure | PDB stack symbols | PDB register symbols |
| --- | --- | --- |
| `00440140` constructor | `scenario_editor_in` at `+0x4`, `TRIBE_Screen_Sed*` | `this` in ECX, `TRIBE_Dialog_Sed_Menu*` |
| `00440340` scalar deleting destructor | `__flags` at `+0x4`, `unsigned int` | `this` in ECX, `TRIBE_Dialog_Sed_Menu*` |
| `00440360` destructor | none | `this` in ECX, `TRIBE_Dialog_Sed_Menu*` |
| `00440400` `action` | `from_panel` at `+0x4`, `TPanel*`; `action_in` at `+0x8`, `long`; `action_val1` at `+0xc`, `unsigned long`; `action_val2` at `+0x10`, `unsigned long` | `this` in ECX, `TRIBE_Dialog_Sed_Menu*` |

The constructor source local `i`, the destructor locals `buttons` and `count`,
and the action locals `sed` and `scenario` have no procedure-scoped PDB
records. I did not force a mapping for them. The action parameters
`action_val1` and `action_val2` are unused in the source, but their PDB names
remain present in the definition.

## Recovered names and source changes

The source previously used generated or substituted parameter names.
The cleanup restores the exact PDB spellings:

| Procedure | Old source name | Recovered PDB name | Evidence |
| --- | --- | --- | --- |
| `00440140` constructor | `param_1` | `scenario_editor_in` | PDB stack symbol at `+0x4`, `TRIBE_Screen_Sed*` |
| `00440400` `action` | `panel` | `from_panel` | PDB stack symbol at `+0x4`, `TPanel*` |
| `00440400` `action` | `event` | `action_in` | PDB stack symbol at `+0x8`, `long` |
| `00440400` `action` | `param_3` | `action_val1` | PDB stack symbol at `+0xc`, `unsigned long` |
| `00440400` `action` | `param_4` | `action_val2` | PDB stack symbol at `+0x10`, `unsigned long` |

The destructor has no recorded stack name. The generated `__flags` parameter
belongs only to the scalar deleting wrapper and has no source declaration.
The source does not rename it.

The existing source locals are descriptive names, not recovered PDB names:
`i`, `cancel`, `buttons`, `count`, `sed`, and `scenario`. The cleanup does not
claim original names for them. No reused stack-slot mapping remains unresolved
for a recorded parameter or local because the PDB has no other local record.
Ghidra names such as `param_1`, `param_2`, `local_4`, and `local_c` were not
used as source-name evidence.

The source also now uses 1TBS for the three definitions and the `else if`
branch. The source keeps the same statements, scopes, types, casts, calls,
control flow, evaluation order, literal values, and storage.

## Constants, resources, and comments

The seven button IDs now use the approved macros from the root-owned
`include/resource_ids.h`. The macro values equal the original numeric
expressions. No enum, helper, or source-owned shared declaration was added.

No source comment was added. The names and existing control flow make the code
clear without a speculative comment.

### Resource lookup evidence

The constructor passes these IDs to the long-ID overload of
`TEasy_Panel::create_button`:

| Applied macro and ID | Button role | Name status | Provenance |
| --- | --- | --- | --- |
| `STRING_ID_SCENARIO_MENU_QUIT_TO_MAIN_MENU` (`0x2443`) | button 0, Quit to Main Menu | applied approved cleanup name | worker-local import `3bff68f3de98c7273f9a41faf3398b68cc17f15a`; root approval `8c56055b7feee1526f296bd306036a4c34f38041` |
| `STRING_ID_SCENARIO_MENU_SAVE` (`0x2441`) | button 1, Save | applied approved cleanup name | worker-local import `3bff68f3de98c7273f9a41faf3398b68cc17f15a`; root approval `8c56055b7feee1526f296bd306036a4c34f38041` |
| `STRING_ID_SCENARIO_MENU_SAVE_AS` (`0x2442`) | button 2, Save As | applied approved cleanup name | worker-local import `3bff68f3de98c7273f9a41faf3398b68cc17f15a`; root approval `8c56055b7feee1526f296bd306036a4c34f38041` |
| `STRING_ID_SCENARIO_MENU_EDIT_SCENARIO` (`0x2445`) | button 3, Edit Scenario | applied approved cleanup name | worker-local import `3bff68f3de98c7273f9a41faf3398b68cc17f15a`; root approval `8c56055b7feee1526f296bd306036a4c34f38041` |
| `STRING_ID_SCENARIO_MENU_CREATE_SCENARIO` (`0x242E`) | button 4, Create Scenario | applied approved cleanup name | worker-local import `3bff68f3de98c7273f9a41faf3398b68cc17f15a`; root approval `8c56055b7feee1526f296bd306036a4c34f38041` |
| `STRING_ID_SCENARIO_MENU_TEST` (`0x2446`) | button 5, Test | applied approved cleanup name | worker-local import `3bff68f3de98c7273f9a41faf3398b68cc17f15a`; root approval `8c56055b7feee1526f296bd306036a4c34f38041` |
| `STRING_ID_SCENARIO_MENU_CANCEL` (`0x2444`) | button 6, Cancel | applied approved cleanup name | worker-local import `3bff68f3de98c7273f9a41faf3398b68cc17f15a`; root approval `8c56055b7feee1526f296bd306036a4c34f38041` |

The current base resource file is:

`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`

Its SHA256 is:
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`

For language `0x0409` (1033), the exact RT_STRING payloads are:

- `0x2443`: `Quit to Main Menu` (`block_id` 581, slot 3, length 17)
- `0x2441`: `Save` (`block_id` 581, slot 1, length 4)
- `0x2442`: `Save As` (`block_id` 581, slot 2, length 7)
- `0x2445`: `Edit Scenario` (`block_id` 581, slot 5, length 13)
- `0x242E`: `Create Scenario` (`block_id` 579, slot 14, length 15)
- `0x2446`: `Test` (`block_id` 581, slot 6, length 4)
- `0x2444`: `Cancel` (`block_id` 581, slot 4, length 6)

The current expansion resource file is:

`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`

Its SHA256 is:
`4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`

For language `0x0409`, ID `0x242E` is present as an empty slot. IDs
`0x2441`, `0x2442`, `0x2443`, `0x2444`, `0x2445`, and `0x2446` are missing.
The pinned original expansion reference is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`

Its SHA256 is:
`a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

That original expansion reference is missing all seven IDs.

The lookup path is established by these source records:

- `src/Panel_ez.cpp:808-814` calls `this->get_string(id1, text1, 0x78)`.
- `src/Panel.cpp:1914-1916` forwards panel lookup to `rge_base_game`.
- `src/tribegam.cpp:812-816` checks `StringTableX` first, then calls the base
  game lookup when the expansion lookup returns no text.
- `src/tribegam.cpp:388-407` loads `languagex.dll` into `StringTableX`.
- `src/basegame.cpp:160` records the base file name `language.dll`.

Thus the expansion override and base fallback stay in place. The current
expansion file supplies no nonempty text for these IDs. The empty `0x242E`
slot and the six missing slots remain separate findings.

## Code-generation, type, layout, and symbol review

The source changes rename parameters, apply equal-valued resource macros, and
adjust whitespace and brace placement. The source includes the approved
resource header. The macros keep the original unsuffixed integer values and
the `long` overload selection. The changes do not change parameter types,
member layout, declaration scope, storage, ABI signatures, virtual slots,
calls, relocations, boundaries, or symbol names. The lookup and fallback
behavior stays unchanged.

The original behavior oracle is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`

Its SHA256 is:
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup executable is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`

Its SHA256 is:
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

The preserved baseline object for this module is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/dlg_sedm.obj`

Its SHA256 is:
`6ab4a7838e0720e41e3cb5617fee65995eabbbcb805fe933857ae9b9d4ec2ec6`

The identifier edits should not alter generated instructions. Brace and
whitespace edits can alter debug line records. No generated-output claim is
made because the required compiler checks were deferred.

## Shared requests and unresolved questions

### Header request for owner 10

The owner of `include/dlg_sedm.h` may add these parameter names without changing
types or signatures:

```cpp
TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* scenario_editor_in);
virtual long action(TPanel* from_panel, long action_in,
                    unsigned long action_val1, unsigned long action_val2);
```

The request is supported by the procedure-scoped PDB records for `00440140`
and `00440400`. This worker did not edit the header.

### Applied root-owned resource mappings

The worker-local import contains these base-language mappings from commit
`3bff68f3de98c7273f9a41faf3398b68cc17f15a`. The actual root approval is
`8c56055b7feee1526f296bd306036a4c34f38041`:

```cpp
#define STRING_ID_SCENARIO_MENU_QUIT_TO_MAIN_MENU 0x2443
#define STRING_ID_SCENARIO_MENU_SAVE              0x2441
#define STRING_ID_SCENARIO_MENU_SAVE_AS           0x2442
#define STRING_ID_SCENARIO_MENU_EDIT_SCENARIO     0x2445
#define STRING_ID_SCENARIO_MENU_CREATE_SCENARIO   0x242E
#define STRING_ID_SCENARIO_MENU_TEST              0x2446
#define STRING_ID_SCENARIO_MENU_CANCEL            0x2444
```

These are cleanup names. No original macro names were recovered.
The evidence and exact payloads are listed above. The lookup path is the
expansion-first `TRIBE_Game::get_string` path with base-language fallback.

No resource-header request remains. No other shared-file request exists. No
unresolved parameter mapping exists.
The unrecorded source locals remain descriptive names without original-name
claims.

## Validation

I reviewed the complete assigned diff and ran `git diff --check`.

**Compilation, matching, audits, and tests were not run.**

No build, compiler check, game, or runtime test was run.
