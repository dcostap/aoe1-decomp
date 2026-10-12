# Source cleanup report: `Pnl_scbr.cpp`

## Delivery

- Module: `src/Pnl_scbr.cpp`
- Header read only: `include/Pnl_scbr.h`
- Registry: `config/functions/src/Pnl_scbr.cpp.json` (`gx` flags)
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit from `git rev-parse`: `a6aa85bb9972c6ca3c325e56762ed0178c690a05`
- Branch: `cleanup/staging-20260915-153`
- Changed files: `src/Pnl_scbr.cpp`; this report
- The source commit contains the source cleanup changes. The report commit follows it.

The source keeps the 19 registered normal functions in PDB source order. It also
keeps the compiler-generated scalar deleting destructor outside source ownership.
No statement, control-flow edge, call target, type, cast, storage, or data value
changed. Function braces now use 1TBS.

## Evidence

The PDB source is `C:\msdev\work\age1_x1\Pnl_scbr.cpp`. I used these shared
records and references:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Pnl_scbr.cpp.json`
- `C:/Projects/my_decomps/aoe1_attempt3/include/Pnl_scbr.h`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/pnl_scbr.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/pnl_scbr.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Pnl_scbr.obj`

The original executable used as the behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved baseline object SHA-256 is
`24543a9ac7ae88b2991662512959d022b96d7f72d888e92105f264c5ba1b32f5`.

I inspected the registry-selected packets for all normal owners:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A700_TScrollBarPanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A8A0_TScrollBarPanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A8B0_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A910_set_rect.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047AA80_calc_item_rects.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047AB20_set_tab_pos.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047AC10_set_list_len.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047AC30_set_buttons.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047AC70_set_bevel_info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047ACC0_handle_idle.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047AE40_mouse_left_down_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047AFD0_mouse_left_move_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047B3D0_mouse_left_up_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047B420_scroll.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047B4E0_draw.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047B660_draw_border.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047B690_draw_border.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047B8B0_draw_back_pic.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047B970_draw_button_pic.txt`

I also inspected the nearby generated packet
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/0047A880_scalar_deleting_destructor.txt`.

## Every-function PDB coverage

Every registered normal function has a PDB procedure record from the same source
file. Every record has the register symbol `this` in `ecx` with type
`TScrollBarPanel*`. The PDB reports no function statics for these functions.
The table lists each packet line span and every stack symbol.

| VA | Function | PDB line span | Stack symbols |
| --- | --- | --- | --- |
| `0047A700` | `TScrollBarPanel::TScrollBarPanel` | 66-76 | none |
| `0047A8A0` | `TScrollBarPanel::~TScrollBarPanel` | 82-82 | none |
| `0047A8B0` | `setup` | 117-133 | `render_area_in` +0x4, `parent_panel_in` +0x8, `x_in` +0xc, `y_in` +0x10, `wid_in` +0x14, `hgt_in` +0x18, `back_pic_in` +0x1c, `up_pic_in` +0x20, `down_pic_in` +0x24, `tab_pic_in` +0x28, `arrowSizeIn` +0x2c, `tabSizeIn` +0x30, `list_panel_in` +0x34, `list_len_in` +0x38, `orientation` +0x3c |
| `0047A910` | `set_rect` | 139-193 | `x_in` +0x4, `y_in` +0x8, `wid_in` +0xc, `hgt_in` +0x10 |
| `0047AA80` | `calc_item_rects` | 198-220 | none |
| `0047AB20` | `set_tab_pos` | 225-253 | `list_num_in` +0x4 |
| `0047AC10` | `set_list_len` | 258-261 | `list_len_in` +0x4, `list_num_in` +0x8 |
| `0047AC30` | `set_buttons` | 267-273 | `button_pics_in` +0x4, `back_frame_in` +0x8, `up_frame_in` +0xc, `down_frame_in` +0x10, `tab_frame_in` +0x14 |
| `0047AC70` | `set_bevel_info` | 279-287 | `bevel_type_in` +0x4, `c1` +0x8, `c2` +0xc, `c3` +0x10, `c4` +0x14, `c5` +0x18, `c6` +0x1c |
| `0047ACC0` | `handle_idle` | 292-340 | none |
| `0047AE40` | `mouse_left_down_action` | 346-394 | `x` +0x4, `y` +0x8, `ctrl_key` +0xc, `shift_key` +0x10 |
| `0047AFD0` | `mouse_left_move_action` | 400-547 | `x` +0x4, `y` +0x8, `ctrl_key` +0xc, `shift_key` +0x10 |
| `0047B3D0` | `mouse_left_up_action` | 553-590 | `x` +0x4, `y` +0x8, `ctrl_key` +0xc, `shift_key` +0x10 |
| `0047B420` | `scroll` | 596-643 | `action` +0x4, `val` +0x8 |
| `0047B4E0` | `draw` | 649-689 | none |
| `0047B660` | `draw_border` (`tagRECT*`) | 695-697 | `button` +0x4, `down` +0x8, `rect` +0xc |
| `0047B690` | `draw_border` (coordinates) | 703-759 | `button` +0x4, `down` +0x8, `x1` +0xc, `y1` +0x10, `x2` +0x14, `y2` +0x18 |
| `0047B8B0` | `draw_back_pic` | 765-799 | `x_max` -0x14, `y_min` -0x8, `y_max` -0xc, `x_min` -0x10, `pic_hgt` -0x4 |
| `0047B970` | `draw_button_pic` | 805-836 | `frame` +0x4, `down` +0x8, `rect` +0xc, `x_max` +0x10, `y_min` -0x4, `y_max` -0x8, `x_min` -0xc |

The scalar deleting destructor at `0047A880` has `__flags` at +0x4 and the
same `this` register record. It has no standalone source body.

## Original-name recovery

The changed parameter names are recovered PDB names. Their types and declaration
positions remain unchanged.

- `0047A8B0 setup`: `param_1` through `param_15` became
  `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`,
  `back_pic_in`, `up_pic_in`, `down_pic_in`, `tab_pic_in`, `arrowSizeIn`,
  `tabSizeIn`, `list_panel_in`, `list_len_in`, and `orientation`.
- `0047A910 set_rect`: `param_1` through `param_4` became `x_in`, `y_in`,
  `wid_in`, and `hgt_in`.
- `0047AB20 set_tab_pos`: `pos` became `list_num_in`.
- `0047AC10 set_list_len`: `len` and `position` became `list_len_in` and
  `list_num_in`.
- `0047AC30 set_buttons`: the five parameters became `button_pics_in`,
  `back_frame_in`, `up_frame_in`, `down_frame_in`, and `tab_frame_in`.
- `0047AC70 set_bevel_info`: `type` became `bevel_type_in`. The existing
  `c1` through `c6` names already match the PDB.
- `0047AE40 mouse_left_down_action`: `param_1` through `param_4` became
  `x`, `y`, `ctrl_key`, and `shift_key`.
- `0047AFD0 mouse_left_move_action`: `param_1` through `param_4` became
  `x`, `y`, `ctrl_key`, and `shift_key`.
- `0047B3D0 mouse_left_up_action`: `param_1` through `param_4` became
  `x`, `y`, `ctrl_key`, and `shift_key`.
- `0047B420 scroll`: `param` became the recovered PDB parameter `val`.
  The existing local `val` was renamed to the new inferred name
  `new_position` to avoid a duplicate identifier. Its `long` declaration,
  scope, initialization, and uses remain unchanged.
- `0047B660 draw_border(tagRECT*)`: `x` and `y` became the recovered names
  `button` and `down`.
- `0047B690 draw_border(coordinates)`: `raised`, `flag`, `left`, `top`,
  `right`, and `bottom` became the recovered names `button`, `down`, `x1`,
  `y1`, `x2`, and `y2`.
- `0047B970 draw_button_pic`: `param_1`, `param_2`, and `param_3` became
  `frame`, `down`, and `rect`.

The source already used the recovered names in `0047ACC0`, `0047B4E0`, and
`0047B8B0`. The constructor, destructor, `calc_item_rects`, and `0047AC10`
source declarations had no generated parameter names left to change.

## Locals and unresolved mappings

The PDB has no function-static records and no named source locals for most
procedures. I did not force names from optimized registers or reused slots.
These existing source locals remain inferred names, not recovered originals:

- `0047A8B0`: `result`.
- `0047A910`: `base_top`, `track_bottom`, `tab_min`, `top_left`, and `top_top`.
- `0047AA80`: `x`, `w`, `r`, `dl`, and the `tab`, `top`, and `bottom` references.
- `0047AB20`: the two `half` locals.
- `0047ACC0`: `now`.
- `0047AE40`: `p`.
- `0047AFD0`: `delta` and `position`.
- `0047B420`: the existing `max`; the cleanup-inferred `new_position` is
  described above.
- `0047B970`: `x` and `y`.

The PDB does name the `draw_back_pic` locals `x_max`, `y_min`, `y_max`,
`x_min`, and `pic_hgt`. It also names the `draw_button_pic` local `x_max`.
The latter has a positive +0x10 stack record beyond the three declared
parameters. I kept the existing local declaration and did not infer a layout
or storage change. The PDB names `y_min`, `y_max`, and `x_min` at negative
offsets as existing locals.

No unresolved PDB parameter mapping remains. The unresolved items are only
optimized or unnamed local declarations. The source keeps their declarations,
types, scopes, storage, and evaluation order.

## Constants, resources, comments, and formatting

- No numeric constant changed.
- No resource lookup or resource ID occurs in this module. No DLL lookup was
  needed, and no resource mapping request is open.
- No source comment was added or removed. The source has no non-obvious new
  behavior that needs a comment.
- Function opening braces now follow 1TBS. This change affects only source
  presentation and debug line placement.
- Existing enum uses, casts, fixed debug-time strings, integer widths, and
  literal values remain unchanged.

## Header and shared-file requests

The header owner may add the recovered parameter names to
`include/Pnl_scbr.h`. The request does not change types, layouts, calling
conventions, virtual slots, or ABI symbols:

```cpp
long setup(TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in,
           long wid_in, long hgt_in, char* back_pic_in, char* up_pic_in,
           char* down_pic_in, char* tab_pic_in, long arrowSizeIn, long tabSizeIn,
           TPanel* list_panel_in, long list_len_in, Orientation orientation);
virtual void set_rect(long x_in, long y_in, long wid_in, long hgt_in);
void set_tab_pos(long list_num_in);
void set_list_len(long list_len_in, long list_num_in);
void set_buttons(TShape* button_pics_in, int back_frame_in, int up_frame_in,
                 int down_frame_in, int tab_frame_in);
void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
virtual long mouse_left_down_action(long x, long y, int ctrl_key, int shift_key);
virtual long mouse_left_move_action(long x, long y, int ctrl_key, int shift_key);
virtual long mouse_left_up_action(long x, long y, int ctrl_key, int shift_key);
void scroll(ActionType action, long val);
void draw_border(int button, int down, tagRECT* rect);
void draw_border(int button, int down, long x1, long y1, long x2, long y2);
void draw_button_pic(int frame, int down, tagRECT* rect);
```

The header remains unchanged in this worktree. No request is open for
`include/resource_ids.h` or another shared header.

## Risk and validation

The edits rename parameters and one inferred local. They also move opening
braces to 1TBS positions. They do not intentionally affect types, code
generation inputs, object layout, symbol identity, calls, relocations, or
runtime data. Final generated output remains unverified.

Compilation, matching, audits, and tests were not run. No compiler, build,
matching check, audit, test, or game command was run.
