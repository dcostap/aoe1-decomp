# Panel source-cleanup report

## Scope and commits

- Module: `src/Panel.cpp`
- Registry: `config/functions/src/Panel.cpp.json`
- Header read only: `include/panel.h`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `fcc86f54f7c0b1d5218b4247ede72680da9a667d`
- Report delivery commit: recorded by Git after this report is committed
- Changed files:
  - `src/Panel.cpp`
  - `decomp_notes/source_cleanup/wave03/Panel.md`

The source commit contains only the assigned source file. The report commit contains only this assigned report.

## Procedure evidence and coverage

I inspected the registry, the procedure-scoped PDB records, and the selected original packets.
The PDB source is `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB module is `.\\Release\\Panel.obj`.
The selected packets are under `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/`.

The registry selects 116 procedures. Every selected VA has one original packet, one `Panel.cpp` PDB source record, and one body range.
Every selected procedure has an ECX `this` register record with the expected class type.
The 121 `Panel.obj` records contain 171 stack symbols and 117 register symbols.
The extra PDB records are compiler-generated `$E1` through `$E4` records and the scalar deleting destructor.
They are not registry-owned source procedures and were not edited.

The complete selected VA coverage is:

```text
00463BE0, 00463C50, 00463D00, 00463D10, 00463D20, 00463D30, 00463D40, 00463D50,
00463D70, 00463D80, 00463E10, 00463E60, 00463EB0, 00463F40, 00463F50, 00463F60,
00463FF0, 00464010, 00464060, 00464100, 00464120, 00464150, 004641B0, 00464260,
004642C0, 00464480, 004644E0, 00464510, 00464540, 00464550, 00464590, 004645D0,
004645E0, 004645F0, 00464600, 00464610, 00464640, 00464680, 004646F0, 00464720,
004648B0, 004649E0, 00464A80, 00464B50, 00464BF0, 00464C50, 00464D70, 00464DA0,
00464DC0, 00464E00, 00464EB0, 00464EE0, 00464F20, 00465050, 00465160, 004651C0,
00465220, 004652C0, 004652F0, 00465320, 00465370, 004653A0, 004653E0, 00465780,
00465820, 00465A70, 00465B30, 00465BE0, 00465C30, 00465C40, 00465C50, 00465C60,
00465C70, 00465DC0, 00465F70, 00466060, 00466140, 00466170, 004661D0, 00466220,
00466280, 004662C0, 004662E0, 00466320, 00466350, 004663A0, 004663F0, 00466420,
00466430, 00466490, 00466600, 00466650, 00466670, 00466680, 00466690, 004666A0,
004666B0, 004666C0, 00466770, 00466780, 00466790, 004667A0, 004667B0, 004667C0,
004667F0, 00466820, 00466840, 00466870, 00466890, 004668A0, 004668B0, 004668D0,
00466980, 004669A0, 004669D0, 004669F0
```

PDB stack names were checked against the parameter type, stack offset, function body, and packet use.
I did not map a generated name from an unrelated procedure.

## Recovered original names

The following names come from the PDB records. Their spelling is unchanged, including terse names and mixed case.

### `TPanelSystem`

- `panel`: `n`
- `addPanel`: `p`, `makeCurrent`, `makeModal`
- `removePanel`: `n`
- `setCurrentPanel(char*)`: `n`, `makeModal`
- `restorePreviousPanel`: `destroyOldCurrentPanel`
- `setMouseOwner`: `p`
- `setKeyboardOwner`: `p`
- `setModalPanel`: `p`
- `destroyPanel`: `n`
- `inSystem(char*)`: `n`
- `inSystem(TPanel*)`: `p`
- `findPanelNode`: `n`
- `setCurrentPanel(TPanel*)`: `p`, `makeModal`
- `get_palette`: parameters `file_name`, `res_id`; local `file_name2`
- `release_palette`: `pal`

### `TPanel`

- `setup`: `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `color_in`
- `add_panel_node`: `node_in`, `by_node`, `add_after`
- `remove_panel_node`: `node_in`
- `set_rect(long, long, long, long)`: `x_in`, `y_in`, `wid_in`, `hgt_in`
- `set_rect(tagRECT)`: `rect_in`
- `set_color`: `color_in`
- `set_active`: `active_in`
- `set_positioning`: `position_mode_in`, `left_border_in`, `top_border_in`, `right_border_in`, `bottom_border_in`, `min_wid_in`, `max_wid_in`, `min_hgt_in`, `max_hgt_in`, `left_panel_in`, `top_panel_in`, `right_panel_in`, `bottom_panel_in`
- `set_fixed_position`: `left_border_in`, `top_border_in`, `wid_in`, `hgt_in`
- `set_redraw`: `redraw_mode`
- `set_overlapped_redraw`: `redraw_panel`, `calling_panel`, `redraw_mode`; locals `temp_node`, `this_rect`
- `set_any_overlapping_redraw`: `redraw_panel`, `redraw_mode`; locals were already `temp_node`, `this_rect`
- `draw_offset`: `x_offset`, `y_offset`
- `draw_offset2`: `x_offset`, `y_offset`
- `handle_key_down`: `key`, `count`, `alt_key`, `ctrl_key`, `shift_key`
- `handle_char`: `key`, `count`
- `handle_command`: `wParam`, `lParam`
- `handle_user_command`: `wParam`, `lParam`
- `handle_timer_command`: `wParam`, `lParam`
- `handle_scroll`: `scroll_cmd`, `line_num`
- `handle_mouse_down`: `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`
- `handle_mouse_move`: `x`, `y`, `ctrl_key`, `shift_key`
- `handle_mouse_up`: `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`
- `handle_mouse_dbl_click`: `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`
- `action`: `from_panel`, `action_in`, `action_val1`, `action_val2`
- `get_mouse_info`: `wParam`, `lParam`, `point`, `ctrl_key`, `shift_key`
- `get_mouse_pos`: `point`
- `set_curr_child`: `curr_child_in`
- `set_focus`: `have_focus_in`
- `set_z_order`: `z_order_type`, `z_order_in`
- `set_child_z_order`: `child_panel`, `z_order_type`, `z_order_in`
- `set_tab_order(TPanel**, short)`: `panel_list`, `panel_count`
- `set_tab_order(TPanel*, TPanel*)`: `prev_panel`, `next_panel`
- `setPreviousPanel`: `p`
- `setPreviousModalPanel`: `p`
- `setPanelName`: `v`
- `setClipRectangle`: `r`
- `get_string(int, char*, int)`: `text_id`, `str`, `size`
- `get_string(int)`: `text_id`
- `set_help_info`: `string`, `page`
- `get_help_info`: `string`, `page`, `x`, `y`
- `get_true_render_rect`: `drawRect`

Names that already matched the PDB were left unchanged.
No public function, class, member, global, ABI symbol, type, or layout name changed.

## Local mapping limits

The PDB has no stable local record for most optimized locals.
I left those locals unchanged when the PDB did not prove a name.

The PDB records `i` and `calc_hgt` at the same stack offset in `handle_size`.
I kept both source declarations and did not merge or remap them.
The PDB also reuses an offset between `wParam` and `shift_key` in `wnd_proc`.
I kept the parameter and local as separate source identifiers.
The hidden `__$ReturnUdt` record for `clipRectangle` is an ABI return slot, not a source parameter.

`set_overlapped_redraw` had decompiler split names for rectangle fields.
I recovered `this_rect` and `temp_node` from the PDB.
I assigned the descriptive cleanup names `this_left`, `this_top`, `this_right`, `this_bottom`, `panel_rect`, `panel_left`, `panel_top`, `panel_right`, and `panel_bottom`.
These names describe the proven rectangle values.
They are not claims about original source spelling.

## Constants and comments

I read the pinned VC5 SDK header `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H` before changing API constants.

- `COLOR_WINDOW` is `5` and `COLOR_WINDOWTEXT` is `8`.
  The existing saved fields and restore calls prove these roles.
  I replaced both `GetSysColor` uses and both `SetSysColors` element values.
- `WM_KEYDOWN`, `WM_CHAR`, and `WM_SYSKEYDOWN` are `0x0100`, `0x0102`, and `0x0104`.
- `WM_MOUSEFIRST` is `0x0200`.
  `WM_MOUSEMOVE` through `WM_RBUTTONDBLCLK` cover the packet's `0x0200` through `0x0206` cases.
- `WM_COMMAND`, `WM_TIMER`, `WM_HSCROLL`, `WM_VSCROLL`, and `WM_USER` match `0x0111`, `0x0113`, `0x0114`, `0x0115`, and `0x0400`.
- `VK_TAB`, `VK_SHIFT`, `VK_CONTROL`, and `VK_MENU` match `0x09`, `0x10`, `0x11`, and `0x12`.
- `MK_SHIFT` and `MK_CONTROL` match `0x0004` and `0x0008`.
- `TPanel::RedrawImmediate` is the existing `RedrawMode` value `2` in `include/panel.h`.

The original packets `004653E0_wnd_proc.txt`, `00466170_get_mouse_info.txt`, `00464680_restore_system_colors.txt`, `00465820_handle_size.txt`, and `00465B30_handle_key_down.txt` preserve the corresponding numeric values and call paths.
I made no resource-ID change.
`Panel.cpp` has no resource lookup or resource ID use that needs a mapping request.
I added no source comments because no sparse comment would add a proven fact beyond the recovered names.

## Possible generated-code effects

The parameter and local changes do not change storage, evaluation order, call targets, types, scopes, or declarations.
The SDK macros expand to the same integer values as the replaced literals.
The existing enum value expands to the same integer value used by the `int` member.
No class layout, vtable, calling convention, public signature, global, or symbol identity changed.
The source was not compiled, so generated-code stability remains unverified.

## Shared-file requests and unresolved questions

- Header request: none.
- Resource mapping request: none.
- The PDB does not prove original names for optimized locals without stable records.
  Those locals remain unchanged.
- The reused PDB stack offsets described above remain an evidence limit.

Compilation, matching, audits, and tests were not run.
Only evidence extraction and full Git diff review were run.
