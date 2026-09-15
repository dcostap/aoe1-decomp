# Source cleanup report: `dlg_msg.cpp`

## Delivery

- Module: `src/dlg_msg.cpp`
- Registry: `config/functions/src/dlg_msg.cpp.json`
- Branch: `cleanup/staging-20260915-89`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup commit from `git rev-parse`: `271528deff0e82898e192751675c56855b7a09a4`
- The report follows the source cleanup commit.
- Changed files: `src/dlg_msg.cpp`; this report.

The registry assigns seven handwritten functions to this module. The source cleanup covers all seven. The nearby scalar deleting destructor at `0043FCB0` is compiler-generated and has no source body.

The source changes recover procedure-scoped PDB names, use two existing button resource macros, and apply 1TBS function braces. They do not change control flow, calls, types, storage, declaration scope, or values.

## Evidence reviewed

I read the complete source-cleanup, source-comment, resource-ID, owner, assignment, and testing guides. I inspected the assigned header but did not edit it.

The procedure-scoped PDB evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The source registry selected these packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043FC70_TMessageDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043FCD0_TMessageDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043FD50_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043FFF0_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00440070_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00440100_key_down_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00440110_handle_idle.txt`

I also inspected the compiler-generated packet:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043FCB0_scalar_deleting_destructor.txt`

The original executable evidence is:

- File: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup build remains at:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`
- `dlg_msg.obj` SHA-256: `d438f672d3d4c8bd50ca18d11f33ad271dc3424ca183e86ad3b36b3864e8d883`
- `empiresx.exe` SHA-256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## Original-name recovery coverage

All PDB records below came from `scoped_symbols.json`. Every record also has a `this` register in `ecx`, except the compiler-generated procedure, which has no PDB record.

| VA | Function | PDB names and source coverage |
| --- | --- | --- |
| `0043FC70` | `TMessageDialog::TMessageDialog` | Parameter `name` at `+0x4`; source already uses `name`. No PDB locals. |
| `0043FCD0` | `TMessageDialog::~TMessageDialog` | No PDB stack names. The source loop keeps existing local `i`; no PDB mapping exists. |
| `0043FD50` | `TMessageDialog::setup` with text | Parameters `parent_panel_in`, `info_file_in`, `info_id_in`, `wid_in`, `hgt_in`, `dlg_type_in`, `text_in`, `btn_wid_in`, and `btn_hgt_in`. Locals `button_num`, `index`, `y`, and `space`. The existing `button_x` has no PDB record and remains unchanged. |
| `0043FFF0` | `TMessageDialog::setup` with text ID | Parameters `parent_panel_in`, `info_file_in`, `info_id_in`, `wid_in`, `hgt_in`, `dlg_type_in`, `text_id`, `btn_wid_in`, and `btn_hgt_in`. Local `str`. |
| `00440070` | `TMessageDialog::action` | Parameters `from_panel`, `action_in`, `action_val1`, and `action_val2`. No PDB locals. |
| `00440100` | `TMessageDialog::key_down_action` | Parameters `key`, `count`, `alt_key`, `ctrl_key`, and `shift_key`. No PDB locals. |
| `00440110` | `TMessageDialog::handle_idle` | No PDB stack names. No source parameter or local names require recovery. |

The source restores these names from the PDB:

- `0043FD50`: `parent` to `parent_panel_in`.
- `0043FD50`: `panel_file` to `info_file_in`.
- `0043FD50`: `panel_id` to `info_id_in`.
- `0043FD50`: `x` to `wid_in`.
- `0043FD50`: `y` to `hgt_in`.
- `0043FD50`: `type` to `dlg_type_in`.
- `0043FD50`: `message` to `text_in`.
- `0043FD50`: `button_width` to `btn_wid_in`.
- `0043FD50`: `button_height` to `btn_hgt_in`.
- `0043FD50`: `button_count` to `button_num`.
- `0043FD50`: `button_gap` to `space`.
- `0043FD50`: `i` to `index`.
- `0043FD50`: `button_y` to `y` at the same declaration and initialization point.
- `0043FFF0`: `parent` to `parent_panel_in`.
- `0043FFF0`: `panel_file` to `info_file_in`.
- `0043FFF0`: `panel_id` to `info_id_in`.
- `0043FFF0`: `x` to `wid_in`.
- `0043FFF0`: `y` to `hgt_in`.
- `0043FFF0`: `type` to `dlg_type_in`.
- `0043FFF0`: `message_id` to `text_id`.
- `0043FFF0`: `button_width` to `btn_wid_in`.
- `0043FFF0`: `button_height` to `btn_hgt_in`.
- `0043FFF0`: `message` to `str`.
- `00440070`: `panel` to `from_panel`.
- `00440070`: `action_id` to `action_in`.
- `00440070`: `param_3` to `action_val1`.
- `00440070`: `param_4` to `action_val2`.
- `00440100`: unnamed parameters to `key`, `count`, `alt_key`, `ctrl_key`, and `shift_key`.

The PDB lists `button_num` and `index` as `long`. The current source keeps their established `int` types. This cleanup changes names only. The PDB lists `space` and `y` as `long`, matching the source declarations.

The first `setup` PDB records reuse stack offsets across lifetimes:

- `button_num` and `text_in` both use `+0x1c`.
- `index` and `info_id_in` both use `+0xc`.
- `y` and `dlg_type_in` both use `+0x18`.
- `space` and `wid_in` both use `+0x10`.

The packet line ranges and distinct uses support these mappings. The source keeps separate declarations, types, scopes, and initialization points. No uncertain storage mapping was forced. `button_x` has no scoped PDB name, so it remains an existing descriptive source name.

The destructor's `i` local has no scoped PDB record. It remains an existing descriptive source name. The scalar deleting destructor at `0043FCB0` has no PDB source or procedure record. It remains compiler-generated and unchanged.

## Constants and resource evidence

`include/resource_ids.h` already defines `IDS_BUTTON_OK` as `0x0FA1` and `IDS_BUTTON_CANCEL` as `0x0FA2`. The source now uses those existing macros. The macros preserve the original literal values and types after expansion.

The source keeps numeric literals for `0x0FA3`, `0x0FA4`, `0x0FA5`, and `0x0FA7` until the root owner reviews the shared definitions. No local macros were added.

The resource extraction outputs are under the worker build directory:

- `build/resource-strings/runtime-language-dialog-buttons.json`
- `build/resource-strings/runtime-languagex-dialog-buttons.json`
- `build/resource-strings/original-xpack-languagex-dialog-buttons.json`

The extraction tool inspected PE bytes. It did not load or execute a DLL.

The base lookup evidence is:

- `src/basegame.cpp` sets `string_dll_name` to `language.dll`.
- `src/basegame.cpp` loads the base string table and clears the buffer on lookup failure.
- `src/Panel.cpp` routes `TPanel::get_string` to `rge_base_game->get_string`.
- `src/pnl_btn.cpp` implements `TButtonPanel::set_text(short,long)` with a string lookup.
- `src/tribegam.cpp` checks `StringTableX` before the base lookup.
- The `0043FD50` packet annotates the matching base-language strings at every button call.

The checked base file is `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`. Its SHA-256 is `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`. Language `0x0409` (`1033`) contains all requested entries.

The checked expansion override is `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`. Its SHA-256 is `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`. The requested entries are missing.

The pinned original expansion reference is `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`. Its SHA-256 is `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`. The requested entries are missing there as well.

| ID | Proposed cleanup name | Proven purpose and lookup path | Base result (`language.dll`, SHA-256 above, language `0x0409`) | Expansion result |
| --- | --- | --- | --- | --- |
| `0x0FA3` | `IDS_BUTTON_YES` | First caption for dialog types 2 and 4. `TMessageDialog::setup` calls `TButtonPanel::set_text` with this ID. | Exact text `Yes`; block 251, slot 3. | Missing in runtime `languagex.dll` (SHA-256 above) and pinned original `XPack/languagex.dll` (SHA-256 above). Base fallback applies. |
| `0x0FA4` | `IDS_BUTTON_NO` | Second caption for dialog types 2 and 4. `TMessageDialog::setup` calls `TButtonPanel::set_text` with this ID. | Exact text `No`; block 251, slot 4. | Missing in runtime `languagex.dll` (SHA-256 above) and pinned original `XPack/languagex.dll` (SHA-256 above). Base fallback applies. |
| `0x0FA5` | `IDS_BUTTON_RETRY` | First caption for dialog type 3. `TMessageDialog::setup` calls `TButtonPanel::set_text` with this ID. | Exact text `Retry`; block 251, slot 5. | Missing in runtime `languagex.dll` (SHA-256 above) and pinned original `XPack/languagex.dll` (SHA-256 above). Base fallback applies. |
| `0x0FA7` | `IDS_BUTTON_ABORT` | Second caption for dialog type 3. `TMessageDialog::setup` calls `TButtonPanel::set_text` with this ID. | Exact text `Abort`; block 251, slot 7. | Missing in runtime `languagex.dll` (SHA-256 above) and pinned original `XPack/languagex.dll` (SHA-256 above). Base fallback applies. |

ID `0x0FA6` was inspected in the same string block. It contains `Cancel`, but this module does not use it. No name or declaration request is made for it.

The proposed names are new cleanup names. No original macro name is claimed. The existing `IDS_BUTTON_OK` and `IDS_BUTTON_CANCEL` names belong to the shared header and were not created by this module.

## Comments and formatting

No source comment was added. The source code and this report provide the useful evidence without a repetitive comment.

Function opening braces now use 1TBS. No statements moved. The source retains source order, evaluation order, calls, explicit casts, and literal semantics.

## Code-generation and ABI review

The changes rename parameters and locals, use two existing macros that expand to the same numeric literals, add the existing resource header include, and change brace placement.

The source preserves all function signatures, parameter types, local types, scopes, declaration points, member layouts, function boundaries, calling conventions, and direct call targets. No helper, wrapper, assembly, layout change, bug fix, or structural rewrite was added.

The `y` local keeps its original declaration and initialization point. The `button_num` and `index` declarations keep their established `int` types despite the PDB display type `long`.

Compiler output, relocations, call targets, and line records remain unvalidated. The preserved baseline object is available at the absolute path listed above.

## Shared requests

### Owner 10: `include/dlg_msg.h`

The header owner may add these recovered parameter names without changing types, order, or ABI:

```cpp
long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
           long wid_in, long hgt_in, unsigned char dlg_type_in, char* text_in,
           long btn_wid_in, long btn_hgt_in);
long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in,
           long wid_in, long hgt_in, unsigned char dlg_type_in, int text_id,
           long btn_wid_in, long btn_hgt_in);
virtual long action(TPanel* from_panel, long action_in,
                    unsigned long action_val1, unsigned long action_val2);
virtual long key_down_action(long key, short count, int alt_key, int ctrl_key,
                             int shift_key);
```

### Root: `include/resource_ids.h`

Please review these shared cleanup definitions:

```cpp
#define IDS_BUTTON_YES   0x0FA3
#define IDS_BUTTON_NO    0x0FA4
#define IDS_BUTTON_RETRY 0x0FA5
#define IDS_BUTTON_ABORT 0x0FA7
```

The source leaves these four IDs numeric until the shared owner adds reviewed definitions. No resource header was edited in this worktree.

## Validation

Compilation, matching, audits, and tests were not run.

No compiler, build, matching, audit, test, game, or runtime command was run. Only evidence extraction, source review, Git diff review, and `git diff --check` were run. Final validation must compare the integrated source with the preserved pre-cleanup build.
