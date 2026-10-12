# Source cleanup report: `Pnl_msg.cpp`

## Delivery

- Module: `src/Pnl_msg.cpp`
- Branch: `cleanup/staging-20260915-157`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `c3f611e101572c480c32fcfa0fdedce4a1529a63`
- Changed files: `src/Pnl_msg.cpp`; this report
- Paired header: `include/pnl_msg.h` (read only)

The source commit changes names and established symbolic constants only. It keeps
all types, declarations, scopes, storage, expressions, order, calls, literal
values, class layout, and ABI symbols unchanged.

## Evidence reviewed

I reviewed the source registry at:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Pnl_msg.cpp.json`

I reviewed procedure-scoped PDB records at:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source path for the source functions is
`C:\msdev\work\age1_x1\Pnl_msg.cpp`. The PDB records identify `this` in
`ecx` for every member function.

I reviewed the registry-selected original packets for all 12 source functions:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478F40_TMessagePanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00479050_TMessagePanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004790E0_set_rect.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00479270_set_justification.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004792A0_show_message.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004793C0_show_message2.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00479540_remove_message.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00479590_draw.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00479A10_get_true_render_rect.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00479A80_handle_idle.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00479AE0_render_to_image_buffer.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A190_set_font.txt`

I also reviewed the three header-owned inline function packets. They are not
source definitions in this file:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A160_handle_mouse_down.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A170_handle_mouse_move.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A180_handle_mouse_up.txt`

## Original-name recovery

The table lists every function owned by this source registry. Names marked as
recovered come from the matching procedure-scoped PDB record.

| VA | Function | PDB names and cleanup result |
| --- | --- | --- |
| `00478F40` | `TMessagePanel` | Recovered parameters `font_in`, `font_wid_in`, and `font_hgt_in`. |
| `00479050` | `~TMessagePanel` | PDB has only `this`. No local mapping was forced. |
| `004790E0` | `set_rect` | Recovered parameters `x_in`, `y_in`, `wid_in`, and `hgt_in`. |
| `00479270` | `set_justification` | Recovered parameters `horz_just_in`, `vert_just_in`, and `word_wrap_in`. |
| `004792A0` | `show_message` | Recovered parameters `message_type_in`, `text_in`, `colorIn`, `backColorIn`, `font_in`, `font_wid_in`, and `font_hgt_in`. |
| `004793C0` | `show_message2` | Recovered parameters `message_type_in`, `text_in`, `color1`, `color2`, `font_in`, `font_wid_in`, `font_hgt_in`, `Icon1_in`, `Frame1_in`, `Icon2_in`, and `Frame2_in`. |
| `00479540` | `remove_message` | PDB has only `this`. No local mapping was forced. |
| `00479590` | `draw` | Recovered locals `old_font`, `paletteColor`, `ts`, `y`, `x`, `wid`, `hgt`, `font_rgb`, and `rect`. The source now uses `paletteColor`, `x`, and `y`. |
| `00479A10` | `get_true_render_rect` | Recovered parameter `drawRect`. |
| `00479A80` | `handle_idle` | PDB has only `this`. No local mapping was forced. |
| `00479AE0` | `render_to_image_buffer` | Recovered locals `old_font`, `paletteColor`, `ts`, `y`, `x`, `wid`, `hgt`, `Display_hgt`, `font_rgb`, `back_rgb`, and `rect`. The source now uses `paletteColor`, `x`, `y`, and `Display_hgt`. The PDB types `Display_hgt` as `int`; the source keeps its existing `long` declaration. |
| `0047A190` | `set_font` | Recovered parameters `font_in`, `font_wid_in`, and `font_hgt_in`. |

All listed PDB records include the owning `TMessagePanel` type and the `this`
register. The source keeps the PDB mixed spelling, including `colorIn`,
`backColorIn`, `Icon1_in`, `Frame1_in`, `Icon2_in`, `Frame2_in`, `drawRect`, and
`Display_hgt`.

The current source retains names with no reliable PDB declaration mapping:
`image_buffer`, `right`, `bottom`, `i`, `back_rgb` in `draw`, `flags`, `now`,
`image_rect`, `used_x`, `used_y`, `used_w`, `tight`, `text`, `info`, `frame`,
`width`, and `frame_info`. These names use existing descriptive spelling. No
new local name was invented in this change.

The `Display_hgt` name maps to the text-height local by its PDB name and use.
Its PDB type is `int`, while the existing source declaration is `long`. This
cleanup keeps the source type and does not force a type change.

The three header-owned inline functions have these PDB parameter names:

- `handle_mouse_down`: `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`.
- `handle_mouse_move`: `x`, `y`, `ctrl_key`, `shift_key`.
- `handle_mouse_up`: `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`.

Their declarations remain unchanged because this worker does not edit
`include/pnl_msg.h`.

## Constants, resources, and comments

The source now uses existing enum names for message and justification values.
The source now uses the pinned VC5 SDK macros for the same drawing values:

- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H:4878-4885` proves
  `DT_CENTER`, `DT_RIGHT`, `DT_VCENTER`, `DT_BOTTOM`, `DT_WORDBREAK`, and
  `DT_SINGLELINE` values.
- `C:/Program Files (x86)/DevStudio/VC/Include/WINGDI.H:1302-1303` proves
  `TRANSPARENT` equals `1` and `OPAQUE` equals `2`.

These replacements keep the original integer values and call arguments. The
source has no resource lookup or resource ID. No resource DLL was inspected,
so no resource hash or mapping applies. The packet note for `0x80` is a match
annotation for the zeroing loop, not a resource lookup; the source uses the
loop bound `0x200` to clear the text buffer.

No source comment was added. The recovered names and SDK symbols explain the
code without a new comment.

## Shared requests and unresolved questions

Request to owner 18 for `include/pnl_msg.h`:

- Name the inline `handle_mouse_down` parameters
  `mouse_button_in`, `x`, `y`, `ctrl_key`, and `shift_key`.
- Name the inline `handle_mouse_move` parameters `x`, `y`, `ctrl_key`, and
  `shift_key`.
- Name the inline `handle_mouse_up` parameters
  `mouse_button_in`, `x`, `y`, `ctrl_key`, and `shift_key`.

Evidence for this request is the three header packets listed above and the
matching records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The request does not change any type, signature, layout, or ABI symbol.

No request is needed for `include/resource_ids.h` or other root-owned headers.
No unresolved source mapping blocks this delivery. The non-PDB locals listed
above remain unchanged because their declaration mappings are uncertain.

## Code-generation risks and validation limits

Parameter and local renames do not change generated instructions. Existing enum
values and pinned SDK macros expand to the original numeric values. No cast,
type, declaration order, evaluation order, call target, control flow, storage,
layout, or symbol identity changed.

Compilation, matching, audits, and tests were not run. No compiler, build,
matching check, audit, test, or game command was run. The final generated code
remains unvalidated until the final validation stage.
