# `src/Pnl_inp.cpp` source-cleanup report

## Scope and commits

- Module: `src/Pnl_inp.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `d069ff193af752baa8ad403802b6567a553e1930`
- Changed files: `src/Pnl_inp.cpp` and this report.
- Header owner: owner 18 owns `include/Pnl_inp.h`. This worker did not edit it.
- Registry: `config/functions/src/Pnl_inp.cpp.json`, build flags `gx`.

The source keeps the 22 registered normal functions in source order. It also
keeps the compiler-generated scalar deleting destructor outside the source.
The original executable evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The PDB scoped-symbol evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The preserved baseline report is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`.

I inspected the registry-selected packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/` for every
assigned VA. I also inspected
`C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/TInputPanel.txt`.

## Original-name recovery

All 22 assigned functions were reviewed. Every review included the procedure
scoped PDB stack, local, and register records. Each function has the `this`
register in `ecx`. The PDB source path is
`C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp`.

| VA | Function | Scoped names and source action |
| --- | --- | --- |
| `00476C10` | `TInputPanel` | PDB has only `this`; no source name change. |
| `00476CF0` | `~TInputPanel` | PDB has only `this`; no source name change. |
| `00476D80` | `setup` | Recovered all 19 PDB parameters: `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `back_pic_in`, `fill_back_in`, `back_color_in`, `outline_in`, `outline_color_in`, `caret_color_in`, `max_len_in`, `overLengthSoundIn`, `text_in`, and `format_type_in`. |
| `00476EE0` | `set_focus` | Recovered `have_focus_in`. |
| `00476F20` | `set_format` | Recovered `format_type_in`. |
| `00476F30` | `handle_idle` | PDB has only `this`; no source parameter name change. |
| `00476FA0` | `char_action` | Recovered `key`; `count` already matched the PDB. |
| `00477220` | `key_down_action` | Recovered `key`, `count`, `alt_key`, `ctrl_key`, and `shift_key`. The prior source had two unnamed parameters and used `control` and `shift`. |
| `004777C0` | `draw` | PDB locals `cursor_x_offset` and `line_rect` already matched the source. No other PDB source name exists. |
| `00477910` | `set_text(char*)` | Recovered `text_in`. |
| `00477990` | `set_text(char**, short)` | Recovered `text_in` and `num_lines_in`. |
| `004779A0` | `get_input_buffer` | PDB has only `this`; no source name change. |
| `004779B0` | `append_character` | Recovered `c`. |
| `004779D0` | `insert_character` | Recovered `c`. |
| `00477AF0` | `delete_character` | PDB locals `cur_dest` and `move_back_one` already matched the source. |
| `00477C90` | `backspace_character` | PDB has only `this`; no source name change. |
| `00477CB0` | `paste` | PDB locals `data_handle` and `new_str` already matched the source. |
| `00477E90` | `reformat` | PDB has only `this`; no source name change. |
| `00477EF0` | `calc_input_pos` | PDB has only `this`; no source name change. |
| `00478010` | `calc_cur_line_col` | PDB has only `this`; no source name change. |
| `00478150` | `is_blank` | PDB has only `this`; no source name change. |
| `004781A0` | `get_trimmed_str` | Recovered `str` and `str_len`; `temp_str` already matched the PDB. |

The names above are recovered original names from the procedure-scoped PDB.
The source preserves the original mixed style, including `overLengthSoundIn`.
The source keeps all parameter types and declaration order.

## Locals and unresolved mappings

The PDB has no local records for most functions. I did not force names onto
reused or optimized stack slots. The following existing source locals remain
unclaimed as original names:

- `setup` has the new descriptive local `setup_max`.
- `handle_idle` keeps `now`; `char_action` keeps `i`.
- `key_down_action` keeps `line_len` and `column`.
- `draw` keeps `dc`, `select_object`, `old_font`, `cur`, `diff`, `locked`,
  `x`, `y`, and `h`. Only `cursor_x_offset` and `line_rect` have PDB local
  records.
- The first `set_text` keeps `buf` and `len`.
- `insert_character` keeps `src_buffer` and `dst_buffer`.
- `delete_character` keeps `deleted_len` and the generated-looking
  `pcVar2`, `pcVar3`, and `pcVar4`. The PDB proves `cur_dest` and
  `move_back_one`, but it does not name the other pointer declarations. Those
  pointers change roles while the function handles CR/LF pairs, so this work
  does not force a mapping.
- `paste` keeps `len`, `locked`, `old_str`, `new_cur`, `old_tail`,
  `dst_tail`, `total_len`, `max_len`, and its loop index. The PDB proves only
  `data_handle` and `new_str` in this procedure.
- `reformat` keeps `top`, `cur`, and `n`.
- `calc_input_pos` keeps `node`, `i`, `len`, `col`, `pos`, `col2`, and
  `pos2`. `calc_cur_line_col` keeps `node`, `offset`, and `len`.
- `is_blank` keeps `p`. `get_trimmed_str` keeps `base`, `p`, and `cur`.

These names are descriptive source names, not recovered PDB names. No new
local declaration, storage slot, scope, or type was added.

## Constants, resources, comments, and formatting

The source now uses the pinned VC5 SDK names for virtual-key values in
`key_down_action`. The local header
`C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H` proves these values:

- `VK_BACK` `0x08`, `VK_RETURN` `0x0D`, and `VK_ESCAPE` `0x1B`;
- `VK_PRIOR` `0x21`, `VK_NEXT` `0x22`, `VK_END` `0x23`, `VK_HOME` `0x24`;
- `VK_LEFT` `0x25`, `VK_UP` `0x26`, `VK_RIGHT` `0x27`, `VK_DOWN` `0x28`;
- `VK_INSERT` `0x2D` and `VK_DELETE` `0x2E`.

The same header proves `CF_TEXT` is `1`. The clipboard calls now use
`CF_TEXT` instead of the equal literal `1`. The source keeps `0x56` because
the pinned header has no `VK_V` macro. The character-input control values in
`char_action` remain numeric because their separate role is not established
by the SDK header.

No resource ID occurs in this module. No resource DLL was queried. Therefore,
no resource mapping, DLL hash, or shared resource declaration is needed.
No comment was added. Existing comments and fixed debug-time source-line
arguments remain unchanged.

Function opening braces now use 1TBS style. The source keeps statement order,
expressions, casts, calls, and control flow unchanged. The only literal changes
are the equal-value SDK macro substitutions listed above.

## Recovered versus invented names

The PDB names listed in the function table are recovered originals. The only
new local name is `setup_max`, which uses the required snake_case form and has
no PDB claim. `VK_*` and `CF_TEXT` are established SDK names, not invented
project names. Existing descriptive locals remain unclaimed where the PDB
provides no reliable mapping.

## Code-generation risks

Parameter and local renames do not change ABI symbols, types, layout, storage,
call targets, relocations, or evaluation order. Brace movement can change
source debug line records. The SDK macros expand to the same integer values as
the replaced literals, but compilation was deferred, so this was not checked.
No line-dependent macro was added. The source has no header or registry edit.

## Shared requests and unresolved questions

No shared declaration or resource-ID request is open. No header change is
needed for the source edits. The paired header remains read-only for this
worker. The unresolved local mappings are listed above. The generated-looking
pointer names in `delete_character` need stronger PDB or source evidence before
renaming.

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, test, or game command was run for this assignment.
