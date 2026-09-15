# Pnl_txt.cpp cleanup report

## Commits and scope

- Module: `src/Pnl_txt.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Pnl_txt.cpp`.
- Header read only: `include/Pnl_txt.h`.
- Class declaration owner: `include/pnl_lst.h`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit copied from Git: `84f985573e95f679d8ed59106577bd3319c72a34`.
- Changed files: `src/Pnl_txt.cpp` and this report.

This worker changed only the assigned source and report.
No header change is needed.

The source now uses 1TBS function braces.
The cleanup restores procedure-scoped PDB parameter names.
It replaces the proven `AlignWordwrap` literal.
It does not change control flow, storage, casts, calls, or layouts.

## Evidence used

The PDB index is:
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.

The source map is:
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`.

The registry is:
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Pnl_txt.cpp.json`.

The per-function oracle packets are under:
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`.

The registry has 65 normal owners.
All 65 selected packet files exist.
Each packet has one body range and the Pnl_txt PDB source path.
The scoped PDB index has 66 procedures.
The extra procedure is the compiler-generated scalar deleting destructor at `0047C090`.
It is not a source owner.

The original executable is:
`C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`.
Its SHA256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The expansion executable has the same SHA256.
The pinned expansion language DLL is:
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
Its SHA256 is `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

The requested reunification packet path was absent:
`C:/Projects/my_decomps/aoe1_attempt3/build/source_reunification/packet/Pnl_txt_cpp`.
The inventory packets supplied the original procedure evidence instead.
The requested baseline path was also absent:
`C:/Projects/my_decomps/aoe1_attempt3/preparation/baseline-build`.

## Every-function PDB coverage

Every row below has a PDB procedure record, a matching packet, and `this` in `ecx`.
The three `const` accessors use `const TTextPanel*` for `this`.
The table gives the original PDB source line span.

| VA | Procedure | PDB lines |
| --- | --- | --- |
| `0047BF40` | `TTextPanel::TTextPanel` | 73-78 |
| `0047C0B0` | `TTextPanel::~TTextPanel` | 84-92 |
| `0047C120` | `TTextPanel::setup` | 102-120 |
| `0047C1E0` | `TTextPanel::setup` | 130-151 |
| `0047C2F0` | `TTextPanel::setup` | 161-179 |
| `0047C3B0` | `TTextPanel::set_rect` | 185-231 |
| `0047C4D0` | `TTextPanel::set_scrollbar` | 237-246 |
| `0047C520` | `TTextPanel::char_type` | 254-262 |
| `0047C560` | `TTextPanel::set_text` | 268-314 |
| `0047C640` | `TTextPanel::word_wrap_append` | 320-560 |
| `0047CA70` | `TTextPanel::set_text` | 566-570 |
| `0047CAB0` | `TTextPanel::set_text` | 576-592 |
| `0047CB10` | `TTextPanel::set_font` | 598-604 |
| `0047CB50` | `TTextPanel::set_alignment` | 610-614 |
| `0047CB70` | `TTextPanel::set_word_wrap` | 620-623 |
| `0047CB90` | `TTextPanel::set_style` | 629-632 |
| `0047CBB0` | `TTextPanel::set_text_color` | 638-642 |
| `0047CBD0` | `TTextPanel::set_highlight_text_color` | 648-652 |
| `0047CBF0` | `TTextPanel::set_fill_back` | 658-661 |
| `0047CC10` | `TTextPanel::set_back_pic` | 667-685 |
| `0047CCF0` | `TTextPanel::set_outline` | 691-699 |
| `0047CD40` | `TTextPanel::set_bevel_info` | 705-738 |
| `0047CE00` | `TTextPanel::set_spacer_size` | 744-747 |
| `0047CE20` | `TTextPanel::set_active` | 753-763 |
| `0047CE70` | `TTextPanel::calc_draw_info` | 769-833 |
| `0047D060` | `TTextPanel::scroll` | 839-878 |
| `0047D120` | `TTextPanel::key_down_action` | 884-921 |
| `0047D200` | `TTextPanel::action` | 927-955 |
| `0047D2C0` | `TTextPanel::draw` | 961-1000 |
| `0047D3D0` | `TTextPanel::draw_background` | 1006-1089 |
| `0047D570` | `TTextPanel::draw_border` | 1095-1133 |
| `0047D760` | `TTextPanel::draw_line` | 1139-1229 |
| `0047D9E0` | `TTextPanel::calc_line_pos` | 1235-1346 |
| `0047DC10` | `TTextPanel::mouse_left_down_action` | 1352-1356 |
| `0047DC30` | `TTextPanel::numberLines` | 1361-1363 |
| `0047DC40` | `TTextPanel::numberDrawLines` | 1368-1370 |
| `0047DC50` | `TTextPanel::currentLineNumber` | 1375-1377 |
| `0047DC60` | `TTextPanel::setCurrentLineNumber` | 1382-1384 |
| `0047DC70` | `TTextPanel::currentLine` | 1389 |
| `0047DC80` | `TTextPanel::set_line` | 1399-1402 |
| `0047DCA0` | `TTextPanel::set_line_by_id` | 1408-1418 |
| `0047DCD0` | `TTextPanel::append_line` | 1424-1426 |
| `0047DCF0` | `TTextPanel::append_line` | 1432-1434 |
| `0047DD10` | `TTextPanel::append_line` | 1440-1442 |
| `0047DD30` | `TTextPanel::append_line` | 1448-1450 |
| `0047DD50` | `TTextPanel::insert_line` | 1456-1458 |
| `0047DD70` | `TTextPanel::insert_line` | 1464-1582 |
| `0047DF90` | `TTextPanel::insert_line` | 1588-1592 |
| `0047DFE0` | `TTextPanel::insert_line` | 1598-1606 |
| `0047E050` | `TTextPanel::change_line` | 1612-1628 |
| `0047E0B0` | `TTextPanel::change_line` | 1634-1650 |
| `0047E110` | `TTextPanel::delete_line` | 1656-1710 |
| `0047E1E0` | `TTextPanel::get_line` | 1716-1721 |
| `0047E200` | `TTextPanel::get_line` | 1727-1740 |
| `0047E230` | `TTextPanel::get_line` | 1746-1760 |
| `0047E290` | `TTextPanel::get_text` | 1766-1768 |
| `0047E2A0` | `TTextPanel::get_text` | 1774-1790 |
| `0047E2E0` | `TTextPanel::get_text2` | 1796-1798 |
| `0047E2F0` | `TTextPanel::get_text2` | 1804-1820 |
| `0047E330` | `TTextPanel::get_id` | 1826-1828 |
| `0047E340` | `TTextPanel::get_id` | 1834-1848 |
| `0047E370` | `TTextPanel::empty_list` | 1854 |
| `0047E380` | `TTextPanel::free_text` | 1862-1886 |
| `0047E3F0` | `TTextPanel::set_second_column_pos` | 1892-1895 |
| `0047E410` | `TTextPanel::get_text_rect` | 1901-1916 |

The PDB procedure-scoped parameter and local records were inspected for all rows.
The recovered names and unresolved records follow.

## Recovered original names

The following names come from the PDB stack records.
The `_in` suffix and mixed spellings are original evidence.

- `0047C120`: `draw` -> `render_area_in`; `parent` -> `parent_panel_in`; `x` -> `x_in`; `y` -> `y_in`; `w` -> `wid_in`; `h` -> `hgt_in`; `font` -> `font_in`; `font_arg2` -> `font_wid_in`; `font_arg3` -> `font_hgt_in`; `back_pic` -> `back_pic_in`; `fill` -> `fill_back_in`; `backColor` -> `back_color_in`; `outlineValue` -> `outline_in`; `outlineColor` -> `outline_color_in`; `fixedLenValue` -> `fixed_len_in`; `text` -> `text_in`.
- `0047C1E0`: `draw` -> `render_area_in`; `parent` -> `parent_panel_in`; `x` -> `x_in`; `y` -> `y_in`; `w` -> `wid_in`; `h` -> `hgt_in`; `font` -> `font_in`; `font_width` -> `font_wid_in`; `font_height` -> `font_hgt_in`; `back_picture` -> `back_pic_in`; `fill` -> `fill_back_in`; `backColor` -> `back_color_in`; `outlineValue` -> `outline_in`; `outlineColor` -> `outline_color_in`; `fixedLen` -> `fixed_len_in`; `text_id` -> `string_id_in`.
- `0047C2F0`: `param_1` through `param_17` -> `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `back_pic_in`, `fill_back_in`, `back_color_in`, `outline_in`, `outline_color_in`, `fixed_len_in`, `text_in`, and `num_lines_in`.
- `0047C3B0`: `left`, `top`, `width`, and `height` -> `x_in`, `y_in`, `wid_in`, and `hgt_in`.
- `0047C4D0`: `panel` and `auto_scbar_value` -> `scbar_panel_in` and `auto_scbar_in`.
- `0047C520`: `text` -> `c`.
- `0047C560`: `text` -> `text_in`.
- `0047CA70`: `id` -> `string_id_in`.
- `0047CAB0`: `texts` and `count` -> `text_in` and `num_lines_in`.
- `0047CB10`: `param_1`, `param_2`, and `param_3` -> `font_in`, `font_wid_in`, and `font_hgt_in`.
- `0047CB50`: `a` and `b` -> `vert_align_in` and `horz_align_in`.
- `0047CB70`: `value` -> `word_wrap_in`.
- `0047CB90`: `value` -> `text_style_in`.
- `0047CBB0` and `0047CBD0`: `a` and `b` -> `text_color1_in` and `text_color2_in`.
- `0047CBF0`: `a` and `b` -> `fill_back_in` and `back_color_in`.
- `0047CC10`: `name` -> `back_pic_in`.
- `0047CCF0`: `outline` and `color` -> `outline_in` and `outline_color_in`.
- `0047CD40`: `type` -> `bevel_type_in`.
- `0047CE00`: `size` -> `size_in`.
- `0047CE20`: `active` -> `activ_in`.
- `0047CE70`: `recalc_scrollbar` -> `update_scbar`.
- `0047D060`: `amount` and `param_3` -> `scroll_val` and `update_scbar`.
- `0047D120`: `param_1` through `param_5` -> `key`, `count`, `alt_key`, `ctrl_key`, and `shift_key`.
- `0047D200`: `panel`, `msg`, `p1`, and `p2` -> `from_panel`, `action_in`, `action_val1`, and `action_val2`.
- `0047D760`: `line_index` and `line` -> `draw_row` and `text_line`.
- `0047D9E0`: `line_index`, `line`, and `column_offset` -> `draw_row`, `text_line`, and `cursor_x_offset`.
- `0047DC10`: `buttons` and `keys` -> `ctrl_key` and `shift_key`.
- `0047DC60`: `p` -> `v`.
- `0047DC80`: `line` -> `line_in`.
- `0047DCA0`: `id` -> `id_in`.
- `0047DCD0`: `text` and `value` -> `text_in` and `id_in`.
- `0047DCF0`: `text1`, `text2`, and `value` -> `text_in`, `text2_in`, and `id_in`.
- `0047DD10`: `a1` and `a2` -> `string_id_in` and `id_in`.
- `0047DD30`: `a1`, `a2`, and `a3` -> `string_id_in`, `string_id2_in`, and `id_in`.
- `0047DD50`: `line`, `text1`, and `value` -> `line_in`, `text_in`, and `id_in`.
- `0047DD70`: `line`, `text1`, `text2`, and `value` -> `line_in`, `text_in`, `text2_in`, and `id_in`.
- `0047DF90`: `line`, `text`, and `value` -> `line_in`, `string_id_in`, and `id_in`.
- `0047DFE0`: `param_1` through `param_4` -> `line_in`, `string_id_in`, `string_id2_in`, and `id_in`.
- `0047E050`: `param_1` through `param_4` -> `line_in`, `text_in`, `text2_in`, and `id_in`.
- `0047E0B0`: `a1` through `a4` -> `line_in`, `string_id_in`, `string_id2_in`, and `id_in`.
- `0047E110`: `line` -> `line_in`.
- `0047E200`: `index` -> `id_in`.
- `0047E230`: `s` -> `text_in`.
- `0047E2A0`, `0047E2F0`, and `0047E340`: `index` -> `line_in`.
- `0047E3F0`: `value` -> `val`.

The PDB records for constructors, destructors, zero-argument methods, and the remaining accessors have no named parameters.

The PDB local names were also checked.
The source already uses the PDB names for most mapped locals.
The cleanup renamed `calc_line_pos` local `temp_text` to `temp_text2`.
The PDB proves that name at stack offset `-0x100`.
The first `change_line` overload renamed `iVar1` to `saved_sorted` and `iVar2` to `insert_result`.
Those two names are new cleanup names.
The PDB has no local records for that overload.

## Unresolved declaration mappings

The PDB records several reused stack slots.
This report does not force those records into new declarations.

- `0047C640` records `next_type` and `next_char` at `-0x154`.
- `0047C640` records `last_fit_len` and `last_char` at `-0x160`.
- `0047D760` records `x2` at `+0xc` and `x` at `+0x10`.
  Those offsets overlap the five declared ABI parameters.
  The decorated symbol has five explicit parameters.
  The source keeps its five-parameter signature.
- `0047C640` records `temp_text` as `unsigned char[256]`.
  The source keeps its existing `char[256]` declaration.
- `0047D9E0` records `temp_text2` as `char[256]`.
  The source keeps its existing `unsigned char[256]` declaration.
  Changing either type needs a separate code-generation review.
- The PDB omits several source locals that the compiler keeps in registers.
  Existing declarations remain unchanged.

The PDB function statics are also preserved.
`0047E2A0` records `empty_text` at `0086B250`.
`0047E2F0` records `empty_text` at `0086B24C`.
No static declaration changed.

## Constants, resources, and comments

The enum declaration in `C:/Projects/my_decomps/aoe1_attempt3/include/pnl_lst.h` proves `AlignWordwrap` has value `6`.
The `set_text(char*)` comparison uses that enum symbol now.
The replacement has the same role and value.
No other numeric constant changed.

This module has no direct resource ID literal.
It calls `get_string` only with caller-provided values.
No resource mapping request is needed.
No resource string lookup was run.
The language DLL hash above is recorded because the module has no resource use.

No new source comment was added.
The old `6 == AlignWordwrap` comment was removed when the proven enum replaced the literal.
The source has sparse existing comments only.

## Recovered and invented names

Recovered original names are all names listed in the PDB parameter bullets.
The names include `activ_in`, `val`, `v`, `c`, and the mixed `_in` forms.
The `temp_text2` local name is also recovered from the PDB.

Invented cleanup names are `saved_sorted` and `insert_result`.
They describe existing local use.
They use snake case.
No public function, class, member, global, or ABI symbol was renamed.
`AlignWordwrap` is an existing enum symbol, not a new name.

## Type, code-generation, layout, and symbol effects

Parameter and local renames do not change ABI types or symbol decoration.
The source keeps all function signatures and call targets.
The source keeps all explicit casts and evaluation order.
The source keeps the original local declaration order and storage shape.

The enum substitution keeps the proven value and role.
Its enum type can affect C++ expression typing.
A fresh build must check generated code.
Formatting can change PDB line records.
No executable output claim is made here.

The two PDB/source array-type differences remain unresolved.
The reused stack records remain unresolved.
No layout, vtable, global, relocation, or symbol declaration changed.

## Header and shared-file requests

No header change is requested.
`include/Pnl_txt.h` is a stub and was read only.
`include/pnl_lst.h` owns `TTextPanel`, `TextNode`, and their layouts.
The owner should review source parameter names against its unnamed declarations.
No shared resource ID declaration is needed.

## Unresolved questions

1. The reunification packet path is absent from the main root.
   The per-function inventory packets remain the packet evidence.
2. The PDB stack aliases at `0047C640` and `0047D760` need no forced source mapping.
3. The two array type differences need a separate type and code-generation review.
4. The missing baseline-build path prevented baseline artifact inspection.

## Validation status

I ran Git diff review and `git diff --check`.
I inspected all 65 selected procedure packets and all 65 source-owner PDB records.
I did not run compilation.
I did not run matching checks.
I did not run audits.
I did not run tests.
I did not run the game.
