# `Panel_ez.cpp` source-cleanup report

## Delivery

- Module: `src/Panel_ez.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Initial source commit: `de5e4d1c14e9a524652b9dcd4b47268024382600`
- Correction commit: this final correction commit
- Changed files:
  - `src/Panel_ez.cpp`
  - `decomp_notes/source_cleanup/wave03/Panel_ez.md`
- PDB source: `C:\\msdev\\work\\age1_x1\\Panel_ez.cpp`
- Registry: `config/functions/src/Panel_ez.cpp.json`
- Build flags: `gx`
- Header read: `include/panel_ez.h`
- Header owner: owner 17

The source restores names that the procedure-scoped PDB proves. It keeps
function types, calling conventions, casts, calls, source order, and control
flow. It does not edit the header or registry.

## Evidence checked

I inspected all 76 registered Panel_ez packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0046/` for VAs
`00466A20` through `0046A670`. I also inspected the generated scalar deleting
destructor packet at `00466A70`.

The procedure-scoped PDB record is
`build/panel_ez_scoped_symbols.json`. Its SHA256 is
`0e494d1a97f00fc86e2fc3bf0b7ea9ebb71ef40ec381ec2efd5054f09bcfb0bf`.
The source map is
`inventory/pdb/function_source_map.csv`. Its SHA256 is
`aead4dde6d2839dbd667e0c2d1a2f266ca19c8e559ae23757c969c4c443de8b8`.
The complete PDB inventory is
`inventory/pdb/scoped_symbols.json`. Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The original PDB is
`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`.
Its SHA256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

I inspected the original executable evidence:

- `orig/ghidra_decomp/panel_ez.cpp.asm`, SHA256
  `22196460e231ded74354885d6cc2d582b2c1457018de23b0817968814fb29425`.
- `orig/ghidra_decomp/panel_ez.cpp.decomp`, SHA256
  `1ccad18ebf8f659ea7fe14e9271c126220aac17809ca74cf96008c714340dbbe`.
- Original executable:
  `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
  Its SHA256 is
  `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The registry record SHA256 is
`f14fd40be504f73ef0a216a46149f0a8e3f2984892db9e1bd3f68a17e92a733f`.
The registry selects 76 normal procedures. The scalar deleting destructor is
compiler-generated and is not a registry procedure.

## PDB name coverage

The PDB establishes the names for the assigned definitions. The source now
uses these names where the declaration and use mapping is direct:

- `setup`: the existing `*_in`, resource, color, file, and palette names.
- `setup_shadow_area`: `force_redraw`, `area_name`, and the four bounds.
- `draw_setup`: `clear`.
- `draw_background`: `use_background2`, `x_min`, `x_max`, `y_min`, `y_max`,
  and `pic`. The PDB records `pic_y` and `pic_hgt` at one reused stack home.
  The source keeps the prior `tile_w` and `pic_w` names for those lifetimes.
- Mouse and focus paths: `mouse_button_in`, `ctrl_key`, `shift_key`,
  `have_focus_in`, `mouse_x`, and `mouse_y`.
- Resource setters: `file_name`, `file_name2`, `resource_id`,
  `resource_file_id`, `background_pos_in`, `use_bevels_in`, `val`, and
  `enable_ime_in`.
- Color accessors: `c1` through `c6` and the two `c1`/`c2` pairs.
- Button creation: `parent`, `button`, `text_id1`, `text_id2`, `text1`,
  `text2`, `x`, `y`, `width`, `height`, `font_num`, `sound_num`, and
  `action_id`.
- Text and input creation: `text_panel`, `text_id`, `text`, `line_num`,
  `value`, `max_len`, `format_type`, `horz_center`, `vert_center`,
  `word_wrap`, `input_panel`, `edit_panel`, `enable_ime`, and `turn_ime_on`.
- Drop-down, list, scrollbar, and slider creation: `drop_panel`,
  `list_width`, `list_height`, `list_w`, `list_h`, `list`, `list_panel`,
  `scrollbar_panel`, `list_size`, `scale`, `one_step`, `page_step`, and
  `slider_panel`.
- Dialog and help paths: `text_id`, `text`, `panel_title`, `wid`, `hgt`,
  `temp_title`, `in_parent_panel`, `help_string`, `help_page`, `x`, and `y`.
- Action dispatch: the original mixed spellings `fromPanel`, `actionIn`,
  `a1`, and `a2`.
- System colors: `pe`, `cols`, and `elems`.

The PDB records reused positive parameter homes for several locals. The source
does not treat those homes as proof of a source name. It keeps prior names for
these unresolved mappings:

- The char* `create_button` `ideal_y` record shares the `y` parameter home;
  the source keeps `sy`.
- `create_check_box` records `ideal_y` and `ideal_w` share parameter homes;
  the source keeps `sy` and `sw`.
- `create_radio_button` records `ideal_y` and `ideal_w` share parameter homes;
  the source keeps `sx` and `sy`. Its negative-slot `ideal_x` remains.
- `create_list` records `list` at a reused parameter home; the source keeps
  `list_items`.
- `create_scrollbar` records `ideal_h` at a reused parameter home; the source
  keeps `h`.
- `create_edit` records `ideal_w` at a reused parameter home. The source uses
  `scaled_width` because the PDB `width` parameter occupies that identifier.

In `draw_background`, `pic_y` and `pic_hgt` share `-0x18`; the source keeps
`tile_w` and `pic_w`. No uncertain local name was forced into another scope.

## Constants, resources, comments, and formatting

`0x8000` in the binary file open call is replaced by `_O_BINARY`. The pinned
VC5 header `C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H` defines this
CRT flag. The replacement keeps the original value and flag role.

No resource ID is introduced or renamed. Existing string lookups, buffers,
format strings, fallback paths, sentinels, and lookup order remain unchanged.
No resource mapping request is needed.

No source comment was added. The source uses 1TBS brace placement and clearer
wrapping within this module. It does not reorder statements or declarations.

## Deferred checks

Per the assignment, I did not run compilation, matching, audits, tests, or the
game. I only inspected source, PDB, registry, packet, header, CRT, and
original-binary evidence, and reviewed the source diff.

The final validation stage must still check generated output and runtime
behavior after integration. This report does not claim new binary equality.

## Unresolved questions

- Several decompiler temporaries in the control-creation routines have no
  direct PDB local record. They remain descriptive and unchanged in scope.
- The PDB reuses stack homes for locals in `draw_background`, `create_button`,
  `create_check_box`, `create_radio_button`, `create_text`, `create_input`,
  `create_edit`, `create_list`, and the slider routines. Stronger source
  evidence is needed before changing their declarations.
- The registered `draw_background` procedure remains `accepted_drift`, and
  `setup` remains `new_verified_logic`. This cleanup does not claim to resolve
  either existing status.
