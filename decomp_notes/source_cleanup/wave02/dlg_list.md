# Source cleanup report: `dlg_list.cpp`

## Delivery

- Module: `src/dlg_list.cpp`
- Header read: `include/dlg_list.h`
- Source registry: `config/functions/src/dlg_list.cpp.json`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup commit from `git rev-parse`: `e35339a1abc5f1350e26a7f8b44aea3fd4008088`
- Report commit: the follow-up commit that adds this report. Its full hash is copied from Git in the final delivery.
- Branch: `cleanup/staging-20260915-87`
- Changed files: `src/dlg_list.cpp`; `decomp_notes/source_cleanup/wave02/dlg_list.md`
- The header remains unchanged. Owner 10 owns `include/dlg_list.h`.

The source registry assigns six normal functions to this module. Coverage is complete.
The source has no wrapper, fragment include, context macro, raw field cursor, or new helper.
No expression, control flow, call, type, storage, layout, or data value changed.

## Evidence

The procedure-scoped PDB records came from:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The source registry selected these function packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043EE70_TListDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043EEE0_TListDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043EF80_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043F130_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043F210_key_down_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043F220_action.txt`

The original executable was inspected as the behavior oracle at:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/dlg_list.obj`

Its SHA256 is `1c8d0bc6484c3d14ca68d6128451cc20191a72964e6de23bcd39f589f9dd87ad`.
The preserved baseline build directory is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`

The packets provide the original boundaries and assembly. The PDB records provide the original names.
The existing module note is `decomp_notes/dlg_list.md`.

## Original-name recovery

All names in this table come from PDB records unless marked as existing.
Each assigned function has a `this` register record in `ecx`.
The PDB records have no function statics for these functions.

| VA | Function | PDB parameters, locals, and registers | Result |
| --- | --- | --- | --- |
| `0043EE70` | `TListDialog::TListDialog` | Parameter `name` at `+0x4`; register `this` in `ecx` | Existing `name` already matched. |
| `0043EEE0` | `TListDialog::~TListDialog` | No stack symbols; register `this` in `ecx` | No source name change. Ghidra's `local_4` and `local_10` are not PDB symbols. |
| `0043EF80` | `TListDialog::setup` | Parameters `parent_panel_in`, `info_file_in`, `info_id_in`, `wid_in`, `hgt_in`, `title_x_in`, `title_y_in`, `title_wid_in`, `title_hgt_in`, `title_in`, `list_x_in`, `list_y_in`, `list_wid_in`, `list_hgt_in`, `list_in`, `list_num_lines_in`, `list_id_in`, `ok_btn_x_in`, `cancel_btn_x_in`, `btn_y_in`, `btn_wid_in`, and `btn_hgt_in`; register `this` in `ecx` | Restored all 22 parameter names. |
| `0043F130` | `TListDialog::setup` | The same 22 parameters, with `title_string_id` at `+0x28`; local `str` at `-0x100` with type `char[256]`; register `this` in `ecx` | Restored all 22 parameter names and local `str`. |
| `0043F210` | `TListDialog::key_down_action` | Parameters `key`, `count`, `alt_key`, `ctrl_key`, and `shift_key`; register `this` in `ecx` | Restored all five unused parameter names. |
| `0043F220` | `TListDialog::action` | Parameters `from_panel`, `action_in`, `action_val1`, and `action_val2`; register `this` in `ecx` | Restored all four parameter names. |

The source changes restore these names:

- In both `setup` overloads, `parent_panel` became `parent_panel_in`.
- In both `setup` overloads, `name` became `info_file_in`.
- In both `setup` overloads, `x` became `info_id_in`.
- In both `setup` overloads, `y` became `wid_in`.
- In both `setup` overloads, `width` became `hgt_in`.
- `title_x`, `title_y`, `title_width`, and `title_height` became `title_x_in`, `title_y_in`, `title_wid_in`, and `title_hgt_in`.
- In the string overload, `title_text` became `title_in`.
- `list_x`, `list_y`, `list_width`, and `list_height` became `list_x_in`, `list_y_in`, `list_wid_in`, and `list_hgt_in`.
- `list_text`, `list_count`, and `selected` became `list_in`, `list_num_lines_in`, and `list_id_in`.
- `ok_x`, `cancel_x`, `button_y`, `button_width`, and `button_height` became `ok_btn_x_in`, `cancel_btn_x_in`, `btn_y_in`, `btn_wid_in`, and `btn_hgt_in`.
- In the integer overload, `title_id` became `title_string_id`.
- The integer overload's `title_text[256]` became PDB local `str[256]`.
- The unnamed key handler parameters became `key`, `count`, `alt_key`, `ctrl_key`, and `shift_key`.
- In `action`, `panel`, `message`, `param_3`, and `param_4` became `from_panel`, `action_in`, `action_val1`, and `action_val2`.

The parameter names `info_id_in`, `wid_in`, and `hgt_in` look unusual at their original stack offsets.
The source keeps their original argument positions. It does not rename them by inferred meaning.

The source retains existing descriptive locals `result` and `cancel`.
Neither local has a PDB stack symbol. Their storage and scope remain unchanged.
No uncertain reused-stack-slot mapping was forced.
The compiler-generated scalar deleting destructor at `0043EEC0` has PDB parameter `__flags` and register `this`.
It has no standalone source body and was not edited.
The inline header-owned getters at `0043F320` and `0043F330` have only register `this`.
They were not edited.

## Constants and resources

The source now includes the existing shared header `include/resource_ids.h`.
It reuses these existing resource macros:

| Macro | Value | Use |
| --- | --- | --- |
| `IDS_BUTTON_OK` | `0x0FA1` | `TListDialog::setup` OK button label |
| `IDS_BUTTON_CANCEL` | `0x0FA2` | `TListDialog::setup` Cancel button label |

The macro values preserve the old integer literals and their effective type.
No new macro, enum, or constant was defined.
The panel style `0xB`, scrollbar value `0x14`, Escape hotkey `0x1B`, and other numeric values remain unchanged.
No source comment was added.

### Resource evidence

The extraction tool inspected these exact files:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  - SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  - SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  - SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

The resource type is `RT_STRING`.
The base runtime `language.dll` supplies both labels in language `0x0409` (`1033`):

1. ID `0x0FA1` (`4001`), block `251`, slot `1`: exact text `OK`.
2. ID `0x0FA2` (`4002`), block `251`, slot `2`: exact text `Cancel`.

`runtime/languagex.dll` has missing IDs `0x0FA1` and `0x0FA2`.
The checked original XPack `languagex.dll` also has missing IDs `0x0FA1` and `0x0FA2`.
No empty slot was reported for either ID.

The call site is the numeric overload of `TEasy_Panel::create_button` in:

`C:/Projects/my_decomps/aoe1_attempt3/src/Panel_ez.cpp`

That overload calls `get_string` for each ID with a 120-byte buffer.
`RGE_Base_Game::get_string` loads `StringTable` from `language.dll` and calls `LoadStringA`.
`TRIBE_Game::get_string` checks `StringTableX` first, then falls back to the base lookup.
The original packet labels both IDs as `language.dll` matches.
This establishes the button-label purpose and the base fallback path.
The proposed cleanup names are the existing shared macros, not recovered original macro names.

## Inferred names and unresolved mappings

- `result` and `cancel` have no procedure-scoped PDB records. The source keeps both existing names.
- The destructor's Ghidra-only `local_4` and `local_10` do not map to source declarations. No mapping was forced.
- PDB evidence does not establish original names for the shared resource macros. The source uses the existing root-owned definitions.
- No resource ID request is needed.
- No layout, type, ABI, symbol, or shared global request is needed.

## Header request for owner 10

The owner of `include/dlg_list.h` may add these parameter names without changing types or signatures:

```cpp
TListDialog(char* name);
long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
           long wid_in, long hgt_in, long title_x_in, long title_y_in,
           long title_wid_in, long title_hgt_in, char* title_in,
           long list_x_in, long list_y_in, long list_wid_in, long list_hgt_in,
           char** list_in, short list_num_lines_in, short list_id_in,
           long ok_btn_x_in, long cancel_btn_x_in, long btn_y_in,
           long btn_wid_in, long btn_hgt_in);
long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
           long wid_in, long hgt_in, long title_x_in, long title_y_in,
           long title_wid_in, long title_hgt_in, int title_string_id,
           long list_x_in, long list_y_in, long list_wid_in, long list_hgt_in,
           char** list_in, short list_num_lines_in, short list_id_in,
           long ok_btn_x_in, long cancel_btn_x_in, long btn_y_in,
           long btn_wid_in, long btn_hgt_in);
virtual long key_down_action(long key, short count, int alt_key, int ctrl_key,
                             int shift_key);
virtual long action(TPanel* from_panel, long action_in, unsigned long action_val1,
                    unsigned long action_val2);
```

These names are a shared declaration request only. This worker did not edit the header.

## Code-generation review

The renames change only source identifiers and debug names.
The 1TBS brace changes affect presentation and possible debug line records only.
The resource macros expand to the same integer values as the old literals.
The added include adds no storage or call.

The source preserves the original call order, argument positions, casts, types, declaration scopes,
initialization points, evaluation order, virtual calls, function boundaries, and direct targets.
It does not alter the class layout or ABI symbols.

The existing module note records a three-byte difference for the long `setup` overload.
It records no relocation mismatch or boundary escape and attributes the issue to the PDB-proven overload order.
This cleanup did not claim to repair that difference.

## Validation

Allowed review work completed:

- Read the complete cleanup guides, source, header, source registry, PDB records, and six function packets.
- Inspected the original executable path, preserved baseline object, and resource DLL paths.
- Ran `python tools/inspect_pe_strings.py --help` before extraction.
- Extracted IDs `0x0FA1` and `0x0FA2` from the listed runtime files.
- Ran `git diff --check`.
- Reviewed the complete source diff before commit.

Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime harness was run.
The final wave validation remains required against the preserved baseline build.
