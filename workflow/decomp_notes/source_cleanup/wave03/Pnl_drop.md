# `src/Pnl_drop.cpp` cleanup report

## Scope and commits

- Module: `src/Pnl_drop.cpp`
- PDB source: `C:\\msdev\\work\\age1_x1\\Pnl_drop.cpp`
- Header read only: `include/pnl_drop.h`
- Header owner: owner 17 owns `include/pnl_drop.h`.
- Branch: `cleanup/staging-20260915-149`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source cleanup commit: `58199bec4efdefed02e745378f2ca1b566850b10`
- Final source commit: `58199bec4efdefed02e745378f2ca1b566850b10`
- Changed files:
  - `src/Pnl_drop.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/Pnl_drop.md`

The source commit changes only the assigned source. The report is committed in
one later report-only commit. The delivery response records that report commit.

The source keeps the registry order for all 40 normal PDB owners. The cleanup
renames parameters and two proven locals. It does not change types, casts,
scopes, storage, calls, literals, evaluation order, or layouts.

## Evidence identity

I inspected the source registry at:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Pnl_drop.cpp.json`

I inspected scoped PDB records at:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

I inspected the registry-selected original packets at these paths:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00473ED0_TDropDownPanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00473F50_TDropDownPanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00473FD0_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474340_draw.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474350_handle_mouse_down.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474400_handle_mouse_move.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474420_handle_mouse_up.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474450_handle_key_down.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004744A0_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474550_set_rect.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004745E0_set_val_text_color.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474600_set_draw_style.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474630_set_draw_val_rect.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474670_set_bevel_info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474820_set_buttons.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00474880_set_mode.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475110_numberLines.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475130_currentLineNumber.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475150_setCurrentLineNumber.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475160_setCurrentLineId.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004751C0_currentLine.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004751E0_set_tab_order.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475210_set_sorted.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475230_get_sorted.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475250_set_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004752A0_append_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004752D0_append_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475300_insert_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475330_insert_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475360_delete_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475380_get_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004753A0_get_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004753C0_get_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004753E0_get_text.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475400_get_text.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475420_get_id.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475440_get_id.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475460_empty_list.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00475470_TDropDownButtonPanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004754C0_handle_mouse_move.txt`

The original executable and preserved build supplied context. Their SHA256
values are:

- Original PE:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  - `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Baseline PE:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- Runtime base language:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  - `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Runtime expansion language:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  - `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Original expansion language:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  - `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

The baseline build report records the registry route, `config/flags/gx.rsp`,
and the baseline source SHA256:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`
- Baseline `src/Pnl_drop.cpp` SHA256:
  `7855f30c4746fecfc7df7d52a04298f26e02b675da1e94537b36fad37f40de39`
- Final `src/Pnl_drop.cpp` SHA256:
  `b0c581ee58d707928445662e8027513785c66b3a4c9ae10aefeea7e76403742e`

## Original-name recovery coverage

The scoped PDB record covers every registry-selected normal owner: 40 of 40.
Every record has `this` in `ecx` with the owning class type. No function-static
record is present. The table lists every scoped stack parameter and named local.
A blank entry means that the scoped record has no named entry.

| VA | Procedure | PDB stack parameters | PDB locals | Register |
| --- | --- | --- | --- | --- |
| `00473ED0` | `TDropDownPanel::TDropDownPanel` | none | none | `this:ecx` |
| `00473F50` | `TDropDownPanel::~TDropDownPanel` | none | none | `this:ecx` |
| `00473FD0` | `TDropDownPanel::setup` | `render_area_in`, `parent_panel_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `fill_back_in`, `back_color_in`, `outline_in`, `outline_color_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `val_len_in`, `val_num_in`, `btn_wid_in`, `btn_hgt_in`, `btn_pic_in`, `list_wid_in`, `list_hgt_in`, `list_in`, `list_num_lines_in`, `scbar_wid_in`, `scbar_back_pic_in`, `scbar_up_pic_in`, `scbar_down_pic_in`, `scbar_tab_pic_in`, `scbar_arrow_hgt_in`, `scbar_tab_hgt_in` | none | `this:ecx` |
| `00474340` | `TDropDownPanel::draw` | none | none | `this:ecx` |
| `00474350` | `TDropDownPanel::handle_mouse_down` | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key` | none | `this:ecx` |
| `00474400` | `TDropDownPanel::handle_mouse_move` | `x`, `y`, `ctrl_key`, `shift_key` | none | `this:ecx` |
| `00474420` | `TDropDownPanel::handle_mouse_up` | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key` | none | `this:ecx` |
| `00474450` | `TDropDownPanel::handle_key_down` | `key`, `count`, `alt_key`, `ctrl_key`, `shift_key` | none | `this:ecx` |
| `004744A0` | `TDropDownPanel::action` | `from_panel`, `action_in`, `action_val1`, `action_val2` | none | `this:ecx` |
| `00474550` | `TDropDownPanel::set_rect` | `x_in`, `y_in`, `wid_in`, `hgt_in` | none | `this:ecx` |
| `004745E0` | `TDropDownPanel::set_val_text_color` | `text_color1_in`, `text_color2_in` | none | `this:ecx` |
| `00474600` | `TDropDownPanel::set_draw_style` | `draw_style_in` | none | `this:ecx` |
| `00474630` | `TDropDownPanel::set_draw_val_rect` | `draw_val_rect_in` | none | `this:ecx` |
| `00474670` | `TDropDownPanel::set_bevel_info` | `bevel_type_in`, `c1`, `c2`, `c3`, `c4`, `c5`, `c6` | none | `this:ecx` |
| `00474820` | `TDropDownPanel::set_buttons` | `button_shape_in`, `btn_frame_in`, `scbar_back_frame_in`, `scbar_up_frame_in`, `scbar_down_frame_in`, `scbar_tab_frame_in` | none | `this:ecx` |
| `00474880` | `TDropDownPanel::set_mode` | `mode_in` | `parent_y`, `parent_x`, `calc_wid`, `save_mode` | `this:ecx` |
| `00475110` | `TDropDownPanel::numberLines` | none | none | `this:ecx` |
| `00475130` | `TDropDownPanel::currentLineNumber` | none | none | `this:ecx` |
| `00475150` | `TDropDownPanel::setCurrentLineNumber` | `line_num_in` | none | `this:ecx` |
| `00475160` | `TDropDownPanel::setCurrentLineId` | `id_in` | none | `this:ecx` |
| `004751C0` | `TDropDownPanel::currentLine` | none | none | `this:ecx` |
| `004751E0` | `TDropDownPanel::set_tab_order` | `prev_panel`, `next_panel` | none | `this:ecx` |
| `00475210` | `TDropDownPanel::set_sorted` | `sorted_in` | none | `this:ecx` |
| `00475230` | `TDropDownPanel::get_sorted` | none | none | `this:ecx` |
| `00475250` | `TDropDownPanel::set_line` | `line_in` | none | `this:ecx` |
| `004752A0` | `TDropDownPanel::append_line(char*,long)` | `text_in`, `id_in` | none | `this:ecx` |
| `004752D0` | `TDropDownPanel::append_line(long,long)` | `string_id_in`, `id_in` | none | `this:ecx` |
| `00475300` | `TDropDownPanel::insert_line(long,char*,long)` | `line_in`, `text_in`, `id_in` | none | `this:ecx` |
| `00475330` | `TDropDownPanel::insert_line(long,long,long)` | `line_in`, `string_id_in`, `id_in` | none | `this:ecx` |
| `00475360` | `TDropDownPanel::delete_line` | `line_in` | none | `this:ecx` |
| `00475380` | `TDropDownPanel::get_line()` | none | none | `this:ecx` |
| `004753A0` | `TDropDownPanel::get_line(long)` | `id_in` | none | `this:ecx` |
| `004753C0` | `TDropDownPanel::get_line(char*)` | `text_in` | none | `this:ecx` |
| `004753E0` | `TDropDownPanel::get_text()` | none | none | `this:ecx` |
| `00475400` | `TDropDownPanel::get_text(long)` | `line_in` | none | `this:ecx` |
| `00475420` | `TDropDownPanel::get_id()` | none | none | `this:ecx` |
| `00475440` | `TDropDownPanel::get_id(long)` | `line_in` | none | `this:ecx` |
| `00475460` | `TDropDownPanel::empty_list` | none | none | `this:ecx` |
| `00475470` | `TDropDownButtonPanel::TDropDownButtonPanel` | `drop_down_panel_in` | none | `this:ecx` |
| `004754C0` | `TDropDownButtonPanel::handle_mouse_move` | `x`, `y`, `ctrl_key`, `shift_key` | none | `this:ecx` |

The PDB types match the existing source declarations. Setup uses the recorded
`TDrawArea*`, `TPanel*`, `void*`, `long`, `int`, `unsigned char`, `short`,
`char*`, and `char**` sequence. The action parameters retain `TPanel*`,
`long`, and two `unsigned long` values. The `set_mode` parameter and
`save_mode` local retain the nested `TDropDownPanel::DropdownMode` type.
The `set_buttons` and button-constructor pointer types remain unchanged.

The following names changed in the source. Each old-to-new mapping is a
procedure-scoped PDB recovery. The PDB record matches the declaration offset,
type, and procedure owner.

| VA | Renamed source names |
| --- | --- |
| `00474350` | `buttons` -> `mouse_button_in`; `param4` -> `ctrl_key`; `param5` -> `shift_key` |
| `00474400` | `a` -> `x`; `b` -> `y`; `c` -> `ctrl_key`; `d` -> `shift_key` |
| `00474420` | `p1` -> `mouse_button_in`; `p2` -> `x`; `p3` -> `y`; `p4` -> `ctrl_key`; `p5` -> `shift_key` |
| `00474450` | `ch` -> `count`; `a3` -> `alt_key`; `a4` -> `ctrl_key`; `a5` -> `shift_key` |
| `004744A0` | `panel` -> `from_panel`; `action_code` -> `action_in`; `line` -> `action_val1`; `param4` -> `action_val2` |
| `00474550` | `p1` -> `x_in`; `p2` -> `y_in`; `p3` -> `wid_in`; `p4` -> `hgt_in` |
| `004745E0` | `fg` -> `text_color1_in`; `bg` -> `text_color2_in` |
| `00474600` | `param_1` -> `draw_style_in` |
| `00474630` | `value` -> `draw_val_rect_in` |
| `00474670` | `type` -> `bevel_type_in` |
| `00474820` | `shape` -> `button_shape_in`; `p2` -> `btn_frame_in`; `p3` -> `scbar_back_frame_in`; `p4` -> `scbar_up_frame_in`; `p5` -> `scbar_down_frame_in`; `p6` -> `scbar_tab_frame_in` |
| `00474880` | `new_mode` -> `mode_in`; local `old_mode` -> `save_mode` |
| `00475150` | `p` -> `line_num_in` |
| `00475160` | `id` -> `id_in` |
| `004751E0` | `a` -> `prev_panel`; `b` -> `next_panel` |
| `00475210` | `val` -> `sorted_in` |
| `00475250` | `line` -> `line_in` |
| `004752A0` | `param_1` -> `text_in`; `param_2` -> `id_in` |
| `004752D0` | `param_1` -> `string_id_in`; `param_2` -> `id_in` |
| `00475300` | `param_1` -> `line_in`; `param_2` -> `text_in`; `param_3` -> `id_in` |
| `00475330` | `param_1` -> `line_in`; `param_2` -> `string_id_in`; `param_3` -> `id_in` |
| `00475360` | `param` -> `line_in` |
| `004753A0` | `param` -> `id_in` |
| `004753C0` | `param` -> `text_in` |
| `00475400` | `param` -> `line_in` |
| `00475440` | `param` -> `line_in` |
| `00475470` | constructor parameter `panel` -> `drop_down_panel_in` |

Names already matching the PDB remain unchanged. These include all setup
parameters, `x` and `y` in the mouse handlers, `key` in the key handler, all
bevel color names, and all `TDropDownButtonPanel::handle_mouse_move`
parameters.

## Unresolved and invented names

The PDB records `parent_y`, `parent_x`, `calc_wid`, and `save_mode` for
`00474880`. The source now uses `parent_y`, `parent_x`, and `save_mode`. A
previous behavior-recovery change removed the source `calc_wid` declaration
and uses `this->list_wid` directly. This cleanup does not reintroduce that
local because it would be a structural and code-generation change.

The current `00474880` source also has `parent_wid`, `parent_hgt`, `total_hgt`,
`list_bottom`, `amount_below`, `amount_above`, `num_lines`, and
`num_draw_lines`. The PDB does not name these source declarations. Their
mapping to PDB registers or reused slots is unresolved. I did not force a
rename or change their scope, type, or declaration order.

The PDB does not name these other existing locals: `result` in `setup`,
`old_mode` in `set_draw_style`, `mapped` in `set_bevel_info`, `line` in
`setCurrentLineId`, `scrollbar` in `setup`, and `list_hit_x` in the button
mouse handler. They remain concise descriptive cleanup names. They are not
claimed as original names. No reused stack-slot mapping was forced.

Unresolved questions remain limited to the `00474880` local mapping described
above. No other source declaration needs a name recovery decision.

All names recovered from PDB records are original spellings. The names listed
as existing locals above are inferred cleanup names. No public function, class,
member, global, or ABI symbol was renamed.

The scoped inventory also contains compiler-generated companion records at
`00473F30` (scalar deleting destructor), `00475490` (scalar deleting
destructor), and `004754B0` (`TDropDownButtonPanel::~TDropDownButtonPanel`).
They have no handwritten source body in this assignment. Their `this` register
records were inspected. They were not edited.

## Constants, resources, and comments

No numeric constant, enum use, literal notation, resource ID, or resource
mapping changed. Existing mode, positioning, redraw, key, and frame values
remain unchanged. No new symbol was added.

This source has no resource lookup. No resource ID request is needed. The
runtime and original resource DLL hashes are recorded above for evidence
identity. No resource extractor was required. No language, text, fallback, or
override path changed.

No source comment was added, removed, or changed. The existing comments and
sparse source form remain unchanged.

## Code-generation, type, layout, and symbol review

The source edit changes identifier spellings only. It does not change a type,
cast, declaration scope, storage duration, statement order, control flow,
call target, literal, class layout, function boundary, or ABI symbol.

The source does not use line-dependent macros. The edit can change debug
identifier metadata. It does not claim unchanged compiler output because this
wave defers compilation and matching validation.

No header change is required. The read-only header uses unnamed parameters, so
it has no declaration-name change to request. The header owner should keep the
existing declarations and layouts.

## Review and validation status

I reviewed the complete source diff and the complete report diff. `git diff --check`
passed. The source commit contains only `src/Pnl_drop.cpp`.
The report commit contains only this assigned report.

Compilation, matching, audits, and tests were not run. I did not run a
compiler, build, matching check, audit, test, or game command.
