# Source cleanup report: `dlg_msg.cpp`

## Delivery

- Module: `src/dlg_msg.cpp`
- Registry: `config/functions/src/dlg_msg.cpp.json`
- Branch: `cleanup/staging-20260915-89`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Previous source cleanup commit: `271528deff0e82898e192751675c56855b7a09a4`
- Approved resource-ID commit: `8adda677299caa9f9be07fbaa96f476c70c30e56`
- Latest source cleanup commit from `git rev-parse`: `fa6cac77c18b489ce2d4892ce13df8858fae9b62`
- Head before this report update from `git rev-parse`: `fa6cac77c18b489ce2d4892ce13df8858fae9b62`
- The report follows the latest source cleanup commit.
- Changed files: `src/dlg_msg.cpp`; this report.

The registry assigns seven handwritten functions to this module. The source cleanup covers all seven. The nearby scalar deleting destructor at `0043FCB0` is compiler-generated and has no source body.

The source changes recover procedure-scoped PDB names, use six approved button resource macros, and apply 1TBS function braces. They do not change control flow, calls, types, storage, declaration scope, or values.

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

The PDB lists `button_num`, `index`, `y`, and `space` as `long` (`T_LONG(0012)`). The current source keeps the established `int` types for `button_num` and `index`, and `long` types for `y` and `space`. This cleanup changes names only. The packet shows 32-bit dword operations for all four values, but it does not justify changing the C++ declarations.

The following instruction and use evidence proves each local mapping. Stack-home overlap is only supporting evidence.

- `button_num`: The PDB record is `long` at `+0x1c`. The source declaration is `int button_num`. The original instructions write `1`, `3`, or `2` at `0043FDF7`, `0043FE01`, and `0043FE0B`. `0043FE13` reads the value for the button-width multiplication. `0043FE53` tests it before the button loop. `0043FE9D` reads it for the loop comparison at `0043FEAD`. `0043FF92` reads it for `set_tab_order`. These uses prove a button count, not only a reused stack home.
- `index`: The PDB record is `long` at `+0xc`. The source declaration is `int index`. `0043FE4B` initializes the loop value to zero. `0043FEA8` reads it, `0043FEAC` increments it, and `0043FEAF` compares it with `button_num`. The value selects `button[index]` in the `create_button` call. These uses prove the loop index, not only a reused stack home.
- `y`: The PDB record is `long` at `+0x18`. The source declaration is `long y`, initialized at the existing declaration point. `0043FE3B` loads the panel height, `0043FE42` subtracts the button height, and `0043FE48` subtracts `7`. `0043FE55` stores the result, and `0043FE6D` reloads it for later iterations. The value is pushed as the vertical coordinate at `0043FE7D`. These uses prove the button y-coordinate, not only a reused stack home.
- `space`: The PDB record is `long` at `+0x10`. The source declaration is `long space`. `0043FE13` begins the remaining-width calculation. `0043FE23` subtracts the button total. `0043FE29` stores zero for the narrow case. Otherwise, `0043FE33` through `0043FE37` divide by `button_num + 1`. `0043FE44` reads the result for the initial x-coordinate at `0043FE7E`. `0043FE99` reads it again for the increment at `0043FEA1`. These uses prove the button spacing, not only a reused stack home.

The first `setup` PDB records reuse stack offsets across lifetimes:

- `button_num` and `text_in` both use `+0x1c`.
- `index` and `info_id_in` both use `+0xc`.
- `y` and `dlg_type_in` both use `+0x18`.
- `space` and `wid_in` both use `+0x10`.

The distinct instruction and use evidence above supports the mappings. The source keeps separate declarations, types, scopes, and initialization points. `button_x` has no scoped PDB name, so its baseline name remains unchanged. The destructor's baseline local `i` also remains unchanged because its PDB record has no local name.

The destructor's `i` local has no scoped PDB record. It remains an existing descriptive source name. The scalar deleting destructor at `0043FCB0` has no PDB source or procedure record. It remains compiler-generated and unchanged.

## Constants and resource evidence

`include/resource_ids.h` defines all six button IDs used by this module. The approved definitions landed in commit `8adda677299caa9f9be07fbaa96f476c70c30e56`. The source now uses `IDS_BUTTON_OK`, `IDS_BUTTON_CANCEL`, `IDS_BUTTON_YES`, `IDS_BUTTON_NO`, `IDS_BUTTON_RETRY`, and `IDS_BUTTON_ABORT`. Each macro preserves its original literal value and type after expansion. No local macros were added.

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

The four names approved in commit `8adda677299caa9f9be07fbaa96f476c70c30e56` are new cleanup names. No original macro name is claimed. The existing `IDS_BUTTON_OK` and `IDS_BUTTON_CANCEL` names belong to the shared header and were not created by this module.

## Comments and formatting

No source comment was added. The source code and this report provide the useful evidence without a repetitive comment.

Function opening braces now use 1TBS. No statements moved. The source retains source order, evaluation order, calls, explicit casts, and literal semantics.

## Code-generation and ABI review

The changes rename parameters and locals, use six reviewed macros that expand to the same numeric literals, add the existing resource header include, and change brace placement.

The source preserves all function signatures, parameter types, local types, scopes, declaration points, member layouts, function boundaries, calling conventions, and direct call targets. No helper, wrapper, assembly, layout change, bug fix, or structural rewrite was added.

The `y` local keeps its original declaration and initialization point. The `button_num` and `index` declarations keep their established `int` types despite the PDB display type `long`.

Compiler output, relocations, call targets, and line records remain unvalidated. The preserved baseline object is available at the absolute path listed above.

## Shared requests

### Owner 10: `include/dlg_msg.h`

The header owner may add these recovered parameter names without changing types, order, or ABI:

```cpp
long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in, long wid_in, long hgt_in, unsigned char dlg_type_in, char* text_in, long btn_wid_in, long btn_hgt_in);
long setup(TPanel* parent_panel_in, char* info_file_in, long info_id_in, long wid_in, long hgt_in, unsigned char dlg_type_in, int text_id, long btn_wid_in, long btn_hgt_in);
virtual long action(TPanel* from_panel, long action_in, unsigned long action_val1, unsigned long action_val2);
virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
```

### Root: `include/resource_ids.h`

The resource-ID request from the previous report is complete in commit `8adda677299caa9f9be07fbaa96f476c70c30e56`. The source uses the approved definitions. No resource header was edited in this worktree.

## Validation

Compilation, matching, audits, and tests were not run.

No compiler, build, matching, audit, test, game, or runtime command was run. Only evidence extraction, source review, Git diff review, and `git diff --check` were run. Final validation must compare the integrated source with the preserved pre-cleanup build.
