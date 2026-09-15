# `src/diam_map.cpp` cleanup report

## Delivery

- Module: `src/diam_map.cpp`
- Worker slot: 211
- Branch: `cleanup/staging-20260915-211`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Previous source commit: `ef4716b4fbe13c21122ed62269471dda8740b9dc`
- Final source commit: `ff35c063adefbb7238b185d2c8a0fac519f980c0`
- Previous report commit: `7707e16f808c4a12629e3ad49380eb8eb8bb8836`
- Report correction commit: follows the final source commit
- Changed files:
  - `src/diam_map.cpp`
  - `decomp_notes/source_cleanup/wave04/diam_map.md`

The source registry is
`config/functions/src/diam_map.cpp.json`. It selects 27 normal procedures.
The PDB source path is `C:\msdev\work\age1_x1\diam_map.cpp`.
The header owner is owner 24. This worker did not edit
`include/diam_map.h`.

The source commit restores procedure-scoped names. It keeps types, scopes,
declaration order, storage duration, expressions, calls, literals, and
control flow. It makes no public symbol or ABI change.

## Correction history

Full review requested a wrapping pass and a precise header-owner request.
Source commit `ff35c063adefbb7238b185d2c8a0fac519f980c0` applies that pass.
It puts the requested short signatures and calls on one line. It keeps the
nine-parameter `setup` signature wrapped. It changes no executable token or
source structure.

The prior source commit is `ef4716b4fbe13c21122ed62269471dda8740b9dc`.
The prior report correction commit is
`7707e16f808c4a12629e3ad49380eb8eb8bb8836`. This report records the new
source commit and the owner-24 header request.

Review correction: the `00437760` row now records the correct 1216-byte PDB
reference size from `scoped_symbols.json`. This is report metadata only. It
does not prove a new executable boundary.

## PDB coverage

The scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The selected function packets are under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/`.
I inspected every selected function owner, packet metadata, and scoped-symbol
record.
All 27 normal procedures have a `this` symbol in `ecx`.

The table lists the PDB reference size, PDB source span, parameters, and
scoped locals. Names in this table are PDB names.

| VA | Procedure | Bytes | PDB source span | Parameters | Locals |
| --- | --- | ---: | --- | --- | --- |
| `00436830` | `RGE_Diamond_Map::RGE_Diamond_Map` | 216 | 40-76 | none | none |
| `00436930` | `RGE_Diamond_Map::~RGE_Diamond_Map` | 137 | 82-96 | none | none |
| `004369C0` | `setup` | 68 | 103-112 | `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `color_in`, `all_visible_in`, `save_area_in` | none |
| `00436A10` | `set_bitmap` | 541 | 118-221 | `map_bmp`, `res_id` | `y`, `pic_pitch`, `pic_hgt` |
| `00436C30` | `set_world` | 1081 | 227-354 | `world_in` | `col_step`, `tot_draw_wid`, `draw_wid`, `tile_row`, `line` |
| `00437070` | `set_player` | 20 | 360-363 | `player_in` | none |
| `00437090` | `set_redraw` | 34 | 380-384 | `redraw_mode` | none |
| `004370C0` | `delete_surfaces` | 67 | 390-397 | none | none |
| `00437120` | `create_surfaces` | 265 | 403-420 | none | none |
| `004372C0` | `draw` | 450 | 426-510 | none | none |
| `004374C0` | `clear_image` | 334 | 519-569 | none | none |
| `00437620` | `copy_image` | 62 | 575-654 | none | `r` |
| `00437660` | `draw_all_tiles` | 102 | 660-673 | none | none |
| `004376D0` | `draw_explored_tiles` | 137 | 679-693 | none | `list`, `list_size` |
| `00437760` | `draw_tile` | 1216 | 699-891 | `col`, `row`, `fog`, `override_color` | `tile`, `j`, `y`, `x`, `draw_wid`, `color`, `tile_row`, `terrain`, `trow` |
| `00437C20` | `draw_selected_area` | 147 | 897-917 | none | `sel_col1`, `sel_col2`, `sel_row1`, `sel_row2` |
| `00437CC0` | `draw_objects` | 498 | 923-1015 | none | `color1`, `color2`, `i` |
| `00437EC0` | `draw_visible_object` | 397 | 1021-1112 | `game_obj`, `color1`, `color2` | `row`, `col` |
| `00438060` | `draw_object` | 365 | 1118-1186 | `col`, `row`, `color`, `size`, `game_obj` | none |
| `004381D0` | `draw_clipped_horz_line` | 123 | 1192-1200 | `x`, `y`, `len`, `color`, `image_line` | none |
| `00438250` | `draw_view_rect` | 732 | 1206-1310 | none | `row`, `vwid`, `vhgt` |
| `00438530` | `pick_tile` | 246 | 1317-1354 | `x`, `y`, `col`, `row`, `tile` | none |
| `00438630` | `handle_size` | 50 | 1360-1370 | `win_wid`, `win_hgt` | none |
| `00438670` | `start_scroll_view` | 165 | 1376-1396 | `x`, `y` | `tile`, `row`, `col` |
| `00438720` | `handle_scroll_view` | 148 | 1402-1423 | `x`, `y` | `tile`, `row`, `col` |
| `004387C0` | `end_scroll_view` | 15 | 1429-1432 | none | none |
| `004387D0` | `is_inside` | 65 | 1439-1450 | `x`, `y` | `tile`, `row`, `col` |

The module also contains compiler-generated `00436910`, the vector deleting
destructor. Its 30-byte packet has no PDB source span and no source owner.
It wraps `00436930` and was not edited. Its generated flag parameter remains
outside this source cleanup.

Several PDB homes overlap because the optimized records reuse stack slots.
Examples include `res_id` and `y` in `set_bitmap`, `draw_wid` and `tile_row`
in `set_world`, and `j` and `trow` in `draw_tile`. The source keeps each
existing declaration separate. It does not infer a new declaration from a
shared home.

## Recovered names

The following source substitutions use direct PDB records and role evidence:

- `setup`: `param_1` to `render_area_in`, `param_2` to `parent_panel_in`,
  `param_3` to `x_in`, `param_4` to `y_in`, `param_5` to `wid_in`,
  `param_6` to `hgt_in`, `param_7` to `color_in`, `param_8` to
  `all_visible_in`, and `param_9` to `save_area_in`.
- `set_bitmap`: `name` to `map_bmp` and `param_2` to `res_id`.
- `set_world`: `world` to `world_in`.
- `set_player`: `value` to `player_in`.
- `set_redraw`: `mode` to `redraw_mode`.
- `draw_explored_tiles`: `count` to `list_size`.
- `draw_tile`: `selected` to `fog`, and the byte parameter `color` to
  `override_color`. The projected `draw_x` and `draw_y` locals are now the
  PDB locals `x` and `y`. The scan locals `check_row` and `check_col` are now
  the PDB locals `trow` and `j`.
- `draw_selected_area`: `x1`, `y1`, `x2`, and `y2` to `sel_col1`, `sel_row1`,
  `sel_col2`, and `sel_row2`, respectively. The mapping follows the four
  PDB homes and the selection call order.
- `draw_visible_object`: `object` to `game_obj`.
- `draw_object`: `param_1` to `col`, `param_2` to `row`, `param_3` to
  `color`, `param_4` to `size`, and `param_5` to `game_obj`.
- `draw_clipped_horz_line`: `width` to `len` and `line` to `image_line`.
- `draw_view_rect`: `view_wid` to `vwid` and `view_hgt` to `vhgt`.
- `pick_tile`: `param_1` to `x`, `param_2` to `y`, `param_3` to `col`,
  `param_4` to `row`, and `param_5` to `tile`.
- `handle_size`: `width` to `win_wid` and `height` to `win_hgt`.
- `start_scroll_view`: `xs` to `col` and `ys` to `row`.
- `handle_scroll_view`: `param_1` to `x`, `param_2` to `y`, `out_1` to `col`,
  and `out_2` to `row`.
- `is_inside`: `out_x` to `col` and `out_y` to `row`.

Names that already matched the PDB remain unchanged. These include `y`,
`pic_pitch`, and `pic_hgt` in `set_bitmap`; the row setup locals in
`set_world`; `r` in `copy_image`; the colors and index in `draw_objects`; the
coordinate locals in `draw_visible_object`; and the `row` local in
`draw_view_rect`.

The PDB records for `draw_tile` list `j` and `trow` with optimized overlapping
homes. Their inner-column and outer-row loop roles, source line records, and
use sites support the mapping. The source keeps both declarations separate.

The source had an existing inner `long x` in the fill block. After recovery of
the outer projected `x`, that identifier became `pixel_x`. The source had an
existing `RGE_Map_Tile_Row* row` local in `draw_object`. After recovery of the
`row` parameter, that identifier became `tile_row`. `pixel_x` and `tile_row`
are new descriptive cleanup names. They do not claim PDB origin.

The PDB lists a `color` local in `draw_tile`, but the current source has no
separate local declaration. The current source uses its one existing working
byte parameter, now named `override_color`, for the same accumulator. I did
not add a declaration or alter storage. The PDB local-to-source declaration
mapping remains unresolved.

Other source locals have no scoped PDB record. I left them unchanged and do
not claim them as recovered originals. Examples include `picture`, `pic_wid`,
`pic_line`, `p`, `start_x`, `line_len`, `ratio_sum`, `draw_step`, `draw_height`,
`source_row`, `owner`, `node`, `object`, `player`, `visible`, `draw_level`,
`map_value`, `max_coord`, `row_index`, `x_offset`, `image_line`, and the
adjusted-coordinate and fill-counter locals. No new variable declaration was
added.

`draw_view_rect` has a PDB `short row` record. The current source already uses
the name `row`, but its existing type is `long`. This cleanup does not change
types or reproduce a different local layout. The type question remains open
for a separate source-recovery task.

## Constants, resources, and comments

No constants changed. Existing values such as `2`, `0x19`, `0xFF`, `0x15`,
`0.5f`, and the tile-type cases remain unchanged. No symbol was substituted
for a value without evidence.

The module has no resource lookup. `res_id` is a recovered parameter name for
the existing `TPicture` call. No resource ID declaration or request is
needed.

No comments were added. Existing lock strings and draw strings remain
unchanged. No comment correction is needed.

## Code generation, layout, and shared files

The source changes identifiers and one call wrapping only. They preserve
expression order, evaluation order, scopes, declaration order, types, storage,
casts, calls, literals, class layout, and public symbols. The two collision
fixes rename existing locals. They do not add aliases or declarations.

The `draw_tile` change keeps one byte accumulator declaration. It does not
materialize the PDB `color` local because that would change declaration and
storage structure. The source remains behavior-preserving at the source
statement level, but generated-code stability was not checked.

### Request for owner 24

Please add all recovered parameter names to the matching declarations in
`include/diam_map.h`. Keep types, order, calling conventions, ABI, and class
layout unchanged. Parameter names help callers and do not change the ABI.

```cpp
long setup(TDrawArea *render_area_in, TPanel *parent_panel_in, long x_in,
           long y_in, long wid_in, long hgt_in, unsigned char color_in,
           int all_visible_in, TDrawArea *save_area_in);
int set_bitmap(char *map_bmp, long res_id);
void set_world(RGE_Game_World *world_in);
void set_player(RGE_Player *player_in);
virtual void set_redraw(TPanel::RedrawMode redraw_mode);
void draw_tile(short col, short row, int fog, unsigned char override_color);
virtual void draw_visible_object(RGE_Static_Object *game_obj, unsigned char color1, unsigned char color2);
virtual void draw_object(short col, short row, unsigned char color, short size, RGE_Static_Object *game_obj);
void draw_clipped_horz_line(short x, short y, short len, unsigned char color, RGE_Map_Image_Line *image_line);
int pick_tile(long x, long y, short *col, short *row, RGE_Tile **tile);
virtual long handle_size(long win_wid, long win_hgt);
void start_scroll_view(long x, long y);
void handle_scroll_view(long x, long y);
virtual int is_inside(long x, long y);
```

The declarations for parameterless procedures need no name change. The
generated vector deleting destructor also has no source declaration here.

## Evidence hashes

These files were used as evidence inputs:

- Baseline object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/diam_map.obj`
  SHA-256: `bc43e2b18476332d03331e6edb1902b29fc1a9d4d6769ad0568646d7fc16c996`
- Preserved baseline executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  SHA-256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

## Validation status

Evidence inspection, hash extraction, source diff review, and Git commit
review were performed. Compilation, builds, matching, audits, validation, and
tests were not run. No runtime, game, or compiler command was run for this
assignment.
