# `pnl_btn.cpp` source-cleanup report

## Delivery

- Module: `src/pnl_btn.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `1bd0f91f81586f564df4f1dc7f1d70efe79a0417`
- Changed files:
  - `src/pnl_btn.cpp`
  - `decomp_notes/source_cleanup/wave03/pnl_btn.md`
- PDB source: `C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp`
- Registry: `config/functions/src/pnl_btn.cpp.json`
- Build flags: `default`
- Header read: `include/pnl_btn.h`
- Header owner: owner 17

The source commit restores PDB parameter names and proven symbols. It keeps
all types, casts, calls, scopes, declarations, and source order.

## Evidence checked

I inspected the registry and all 56 selected packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`:

- `00471EC0_TButtonPanel.txt`, `00472030_TButtonPanel.txt`, `004720A0_setup.txt`.
- `00472110_buttonType.txt`, `00472120_drawType.txt`, `00472130_notifyType.txt`.
- `00472140_setDrawType.txt`, `00472150_setButtonType.txt`.
- `00472160_set_picture_info.txt`, `004721A0_set_text_info.txt`,
  `004721E0_set_text_info.txt`, `00472220_set_text_pos.txt`.
- `00472240_set_radio_info.txt`, `004722C0_set_state_info.txt`,
  `004722E0_set_id.txt`, `00472300_set_picture.txt`.
- `00472330_set_text.txt`, `00472440_set_text.txt`, `00472540_set_text.txt`,
  `00472580_set_text.txt`, `004725F0_set_font.txt`.
- `00472620_set_text_color.txt`, `00472650_set_highlight_text_color.txt`,
  `00472680_set_sound.txt`, `00472690_set_radio_button.txt`.
- `00472700_set_state.txt`, `00472720_set_state_by_id.txt`,
  `00472760_set_bevel_info.txt`, `004727B0_set_disabled.txt`,
  `004727F0_set_rect.txt`.
- `00472810_get_state.txt`, `00472820_get_id.txt`, `00472830_get_id2.txt`,
  `00472840_get_text.txt`, `00472880_get_text_color.txt`, `004728C0_draw.txt`.
- `00473120_handle_mouse_down.txt`,
  `00473180_mouse_left_dbl_click_action.txt`,
  `00473190_mouse_left_down_action.txt`,
  `00473240_mouse_left_move_action.txt`, `00473310_mouse_left_up_action.txt`.
- `00473390_mouse_right_dbl_click_action.txt`,
  `004733A0_mouse_right_down_action.txt`,
  `00473450_mouse_right_move_action.txt`, `00473520_mouse_right_up_action.txt`.
- `004735B0_handle_key_down.txt`, `004736F0_key_down_action.txt`,
  `00473890_wnd_proc.txt`, `00473920_char_action.txt`,
  `00473930_hit_button.txt`.
- `004739B0_do_action.txt`, `00473AA0_do_right_action.txt`,
  `00473B80_reset.txt`, `00473BB0_set_sound_number.txt`,
  `00473BC0_stop_sound_system.txt`, `00473BE0_restart_sound_system.txt`.

I inspected `inventory/pdb/scoped_symbols.json`, whose SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
I also inspected `inventory/pdb/function_source_map.csv`, whose SHA256 is
`aead4dde6d2839dbd667e0c2d1a2f266ca19c8e559ae23757c969c4c443de8b8`.
The registry packet SHA256 is `d530974fe171b23928b1d3a82e2105533877b7e4596dba108c07a098b85ef0e6`.

The original disassembly and decompiler sources were also checked:

- `orig/ghidra_decomp/pnl_btn.cpp.asm`, SHA256
  `332315713561343a29714e9bf43eb41f2ccbbe80e427c44ce6f0c0ca3c5abf2e`.
- `orig/ghidra_decomp/pnl_btn.cpp.decomp`, SHA256
  `49f1020a05d4fd36c79518675058ff99207bbe99ee5bbb74c73776c84e2e9338`.
- Original PDB:
  `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`,
  SHA256 `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

The original executable is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved baseline executable is under
`build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`.
Its SHA256 is
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
The preserved baseline `pnl_btn.obj` SHA256 is
`d81d5a9db01884bec450ed75f9e6e64ef816fb3238d28501e34ce0f6c65c64a7`.

I checked resource provenance without changing resources. The pinned
`orig/.../XPack/languagex.dll` has SHA256
`a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
The staged runtime `runtime/language.dll` has SHA256
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
The staged runtime `runtime/languagex.dll` has SHA256
`4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
This module passes caller-supplied IDs to `get_string`; it defines no ID.

## Function-by-function PDB coverage

All 56 registered procedures were inspected. Each has a `this` register in
`ecx`, with type `TButtonPanel*`, except the three const accessors, which use
`const TButtonPanel*`. No registered procedure has a function-static record.
The generated scalar deleting destructor at `00472010` was also inspected.
It has `__flags` at `+0x4` and `this` in `ecx`.

| VA | Procedure | PDB parameters | PDB locals |
| --- | --- | --- | --- |
| `00471EC0` | `TButtonPanel::TButtonPanel` | none | none |
| `00472030` | `TButtonPanel::~TButtonPanel` | none | none |
| `004720A0` | `setup` | `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `drawTypeIn`, `sound_in`, `notifyTypeIn`, `id_in` | none |
| `00472110` | `buttonType` | none | none |
| `00472120` | `drawType` | none | none |
| `00472130` | `notifyType` | none | none |
| `00472140` | `setDrawType` | `drawTypeIn` | none |
| `00472150` | `setButtonType` | `buttonTypeIn` | none |
| `00472160` | `set_picture_info` | `pic_in`, `pic_index_in`, `pic_x_in`, `pic_y_in`, `all_hot_in`, `auto_pic_pos_in` | none |
| `004721A0` | `set_text_info(char*)` | `text_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `text_x_in`, `text_y_in` | none |
| `004721E0` | `set_text_info(long)` | `string_id_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `text_x_in`, `text_y_in` | none |
| `00472220` | `set_text_pos` | `text_x_in`, `text_y_in` | none |
| `00472240` | `set_radio_info` | `buttons_in`, `button_count_in` | none |
| `004722C0` | `set_state_info` | `num_states_in` | none |
| `004722E0` | `set_id` | `state_in`, `id_in`, `id2_in` | none |
| `00472300` | `set_picture` | `state_in`, `pic_in`, `pic_index_in` | none |
| `00472330` | `set_text(char*)` | `state_in`, `text_in` | none |
| `00472440` | `set_text(char*, char*)` | `state_in`, `text1_in`, `text2_in` | none |
| `00472540` | `set_text(long)` | `state_in`, `string_id_in` | `str` at `-0x100` |
| `00472580` | `set_text(long, long)` | `state_in`, `string_id1_in`, `string_id2_in` | `str2` at `-0x200`, `str1` at `-0x100` |
| `004725F0` | `set_font` | `font_in`, `font_wid_in`, `font_hgt_in` | none |
| `00472620` | `set_text_color` | `state`, `text_color1_in`, `text_color2_in` | none |
| `00472650` | `set_highlight_text_color` | `state`, `text_color1_in`, `text_color2_in` | none |
| `00472680` | `set_sound` | `sound_in` | none |
| `00472690` | `set_radio_button` | none | none |
| `00472700` | `set_state` | `state_in` | none |
| `00472720` | `set_state_by_id` | `id_in` | none |
| `00472760` | `set_bevel_info` | `bevel_type_in`, `c1`, `c2`, `c3`, `c4`, `c5`, `c6` | none |
| `004727B0` | `set_disabled` | `val` | none |
| `004727F0` | `set_rect` | `x_in`, `y_in`, `wid_in`, `hgt_in` | none |
| `00472810` | `get_state` | none | none |
| `00472820` | `get_id` | none | none |
| `00472830` | `get_id2` | none | none |
| `00472840` | `get_text` | `state_in`, `text1_in`, `text2_in` | none |
| `00472880` | `get_text_color` | `state_in`, `color1`, `color2` | none |
| `004728C0` | `draw` | none | `old_font`, `calc_x`, `x_max`, `calc_y`, `y_min`, `y`, `x`, `text`, `y_max`, `x_min`, `text_size` |
| `00473120` | `handle_mouse_down` | `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key` | none |
| `00473180` | `mouse_left_dbl_click_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `00473190` | `mouse_left_down_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `00473240` | `mouse_left_move_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `00473310` | `mouse_left_up_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `00473390` | `mouse_right_dbl_click_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `004733A0` | `mouse_right_down_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `00473450` | `mouse_right_move_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `00473520` | `mouse_right_up_action` | `x`, `y`, `ctrl_key`, `shift_key` | none |
| `004735B0` | `handle_key_down` | `key`, `count`, `alt_key`, `ctrl_key`, `shift_key` | none |
| `004736F0` | `key_down_action` | `key`, `count`, `alt_key`, `ctrl_key`, `shift_key` | none |
| `00473890` | `wnd_proc` | `hwnd`, `msg`, `wParam`, `lParam` | none |
| `00473920` | `char_action` | `key`, `count` | none |
| `00473930` | `hit_button` | `x`, `y` | none |
| `004739B0` | `do_action` | none | none |
| `00473AA0` | `do_right_action` | `shift_key` | none |
| `00473B80` | `reset` | none | none |
| `00473BB0` | `set_sound_number` | `sound_number_in` | none |
| `00473BC0` | `stop_sound_system` | none | none |
| `00473BE0` | `restart_sound_system` | none | none |

The `draw` record gives `calc_y` and `y` at the same stack home, `-0x2c`.
The source keeps one `y` declaration and does not force two lifetimes into
that reused slot. The record also has no `text_length` local. The source keeps
`text_length` as an inferred name. The source keeps `text_x_pos` and
`text_y_pos` as inferred names because the PDB does not record them.

## Recovered names and inferred names

The source restores every named PDB parameter that differed from the prior
source. This includes the original mixed styles `drawTypeIn`, `notifyTypeIn`,
`wParam`, `lParam`, and terse `c1` through `c6`.

The changed parameter mappings are:

- `004720A0`: `draw_area` -> `render_area_in`, `parent` -> `parent_panel_in`,
  `x` -> `x_in`, `y` -> `y_in`, `width` -> `wid_in`, `height` -> `hgt_in`,
  `draw_type` -> `drawTypeIn`, `sound` -> `sound_in`,
  `notify_type` -> `notifyTypeIn`, `button_id` -> `id_in`.
- `00472140`: `v` -> `drawTypeIn`.
- `00472150`: `v` -> `buttonTypeIn`.
- `00472160`: `shape` -> `pic_in`, `index` -> `pic_index_in`, `x` -> `pic_x_in`,
  `y` -> `pic_y_in`, `all_hot_value` -> `all_hot_in`,
  `auto_pic_pos_value` -> `auto_pic_pos_in`.
- `004721A0`: `text` -> `text_in`, `font` -> `font_in`, `width` -> `font_wid_in`,
  `height` -> `font_hgt_in`, `x` -> `text_x_in`, `y` -> `text_y_in`.
- `004721E0`: `string_id` -> `string_id_in`, `font` -> `font_in`,
  `width` -> `font_wid_in`, `height` -> `font_hgt_in`, `x` -> `text_x_in`,
  `y` -> `text_y_in`.
- `00472220`: `a` -> `text_x_in`, `b` -> `text_y_in`.
- `00472240`: `buttons` -> `buttons_in`, `count` -> `button_count_in`.
- `004722C0`: `param` -> `num_states_in`.
- `004722E0`: `param_1` -> `state_in`, `param_2` -> `id_in`,
  `param_3` -> `id2_in`.
- `00472300`: `param_1` -> `state_in`, `param_2` -> `pic_in`,
  `param_3` -> `pic_index_in`.
- `00472330`: `state` -> `state_in`, `text` -> `text_in`.
- `00472440`: `state` -> `state_in`, `text1_arg` -> `text1_in`,
  `text2_arg` -> `text2_in`.
- `00472540`: `state` -> `state_in`, `string_id` -> `string_id_in`.
- `00472580`: `state` -> `state_in`, `string_id1` -> `string_id1_in`,
  `string_id2` -> `string_id2_in`.
- `004725F0`: `param_1` -> `font_in`, `param_2` -> `font_wid_in`,
  `param_3` -> `font_hgt_in`.
- `00472620` and `00472650`: `color1` -> `text_color1_in`,
  `color2` -> `text_color2_in`.
- `00472680`: `v` -> `sound_in`.
- `00472700`: `param_1` -> `state_in`.
- `00472720`: `target_id` -> `id_in`.
- `00472760`: `type` -> `bevel_type_in`.
- `004727B0`: `is_disabled` -> `val`.
- `004727F0`: `a`, `b`, `c`, `d` -> `x_in`, `y_in`, `wid_in`, `hgt_in`.
- `00472840`: `state` -> `state_in`, `out_text1` -> `text1_in`,
  `out_text2` -> `text2_in`.
- `00472880`: `state` -> `state_in`.
- `00473120`: `button` -> `mouse_button_in`, `ctrl` -> `ctrl_key`,
  `shift` -> `shift_key`.
- `00473180` and `00473390`: `p0`, `p1`, `p2`, `p3` -> `x`, `y`,
  `ctrl_key`, `shift_key`.
- `00473190`, `00473240`, `00473310`, `004733A0`, `00473450`, and `00473520`:
  `ctrl` -> `ctrl_key`, `shift` -> `shift_key`.
- `004735B0` and `004736F0`: `ch` -> `count`, `a3` -> `alt_key`,
  `a4` -> `ctrl_key`, `a5` -> `shift_key`.
- `00473890`: `wp` -> `wParam`, `lp` -> `lParam`.
- `00473920`: `p0` -> `key`, `p1` -> `count`.
- `00473930`: `param_1` -> `x`, `param_2` -> `y`.
- `00473AA0`: `ctrl` -> `shift_key`.
- `00473BB0`: `v` -> `sound_number_in`.

The source had no differing names for the remaining PDB parameters.

The PDB has no local records for the constructor loop, destructor loop,
`set_radio_info`, `set_radio_button`, `set_state_by_id`, mouse moves, or
`do_right_action`. The source uses inferred names `i`, `old_radio`,
`button_count`, `index`, `remaining`, `newline`, `length`, `new_state`,
`target`, `new_is_down`, `buttonType`, `state`, `id_value`, and `id2_value`.
It uses `hit`, `shape_index`, `shape_x`, and `shape_y` in `hit_button`.
These are new or existing descriptive names, not recovered originals.

The PDB records `str`, `str1`, and `str2` in the string overloads. The source
keeps those names as recovered originals. It also keeps the draw names
`old_font`, `calc_x`, `x_max`, `y_min`, `y`, `x`, `text`, `y_max`, `x_min`, and
`text_size`. The `calc_y` mapping remains unresolved because its stack home
is shared with `y`.

## Constants, resources, comments, and formatting

The source replaces values with symbols that have the same value and role:

- `DrawText`, `DrawFillAndText`, `Radio`, `State`, and `NotifyAction` replace
  their proven enum values from `include/pnl_btn.h`.
- `WM_PAINT`, `WM_COMMAND`, and `WM_KEYUP` replace `0x0F`, `0x111`, and `0x101`.
- `VK_DOWN`, `VK_UP`, `VK_RETURN`, and `VK_SPACE` replace `0x28`, `0x26`,
  `0x0D`, and `0x20`.
- `TRANSPARENT` replaces `1` in `SetBkMode`.

The enum values come from `include/pnl_btn.h`. The pinned VC5 headers prove
`WM_PAINT`, `WM_KEYUP`, `WM_COMMAND`, and the virtual-key values in
`C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H`.
`C:/Program Files (x86)/DevStudio/VC/Include/WINGDI.H` proves `TRANSPARENT`.
No resource ID occurs in this module. No resource mapping request is needed.

No source comment was added. I removed comments that only stated loop counts,
accessor sizes, or source file line ranges. I kept the comment about the
shipped `set_disabled` field and the input-gate behavior. The draw comment
also remains because it records the non-obvious virtual and bevel structure.

The source now uses 1TBS for the constructor. It keeps short signatures and
calls on one line where practical. It keeps the original evaluation order,
casts, calls, and declaration order. No structural rewrite was made.

## Type, layout, code-generation, and symbol review

- Parameter renames do not change types, calling conventions, or decorated symbols.
- Local renames do not change types, storage, scopes, or declaration points.
- Enum and SDK replacements retain the original integer values and effective types.
- Formatting and comment changes do not change executable statements.
- No class layout, vtable, virtual slot, global, or public symbol changed.
- No helper, wrapper, macro-context fragment, assembly, or manual vtable was added.
- The unresolved `calc_y` and `y` stack-home reuse remains unchanged.
- The registered `draw` function remains `new_verified_logic`; its existing
  scratch and relocation limits were not changed by this cleanup.

The identifier and symbolic-constant changes can alter debug names and source
line records. No executable effect is expected, but compilation was deferred.

## Header and root requests

I did not edit `include/pnl_btn.h`, which owner 17 owns. No header change is
required for this source cleanup. Owner 17 may publish the recovered parameter
names in declarations without changing types or ABI.

No root-owned declaration or shared resource mapping is requested.

## Unresolved questions

- The PDB records `calc_y` and `y` at `-0x2c`. Stronger source evidence is
  needed before splitting their lifetimes or changing the draw declarations.
- PDB local records do not prove the inferred local names listed above.
- The source map repeats `draw` at `004730F1`; the selected draw packet owns
  `004728C0-004730F0`. No separate source procedure is registered.
- Existing accepted drift remains registered at `00472240` and `00473930`.
  This cleanup does not claim to resolve either drift.

Compilation, matching, audits, and tests were not run. No compiler, build,
matching check, audit, test, or game command was run.
