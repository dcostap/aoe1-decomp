# `tpnl_obj.cpp` cleanup report

## Module and scope

- Module: `src/tpnl_obj.cpp`
- Registry: `config/functions/src/tpnl_obj.cpp.json`
- Header: `include/tpnl_obj.h` (read-only for this worker)
- PDB source: `C:\msdev\work\age1_x1\tpnl_obj.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final module commit: `23febc8712ab7129c8f9453ffed450903344dd02`
- Changed files:
  - `src/tpnl_obj.cpp`
  - `decomp_notes/source_cleanup/wave03/tpnl_obj.md`

The registry selects the `gx` profile and 13 normal owners. The preserved baseline
record at `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`
confirms the same source, profile, and symbol list. The prior module note names a
source-reunification packet at
`build/source_reunification/terra_system/tpnl_obj_cpp/tpnl_obj_cpp/packet.json`,
but that packet is absent from this checkout. I used the available registry record,
per-function inventory packets, scoped PDB inventory, original Ghidra listing, and
preserved baseline record instead.

## Systematic PDB coverage

I inspected every registered function in `src/tpnl_obj.cpp` through
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The selected extraction is in `build/pdb-tpnl_obj/scoped_selected.json`, with the
name, type, stack offset, and register summary in
`build/pdb-tpnl_obj/scoped_summary.txt`. Every procedure records `this` in `ecx`.

| VA | Procedure | PDB parameters | PDB locals |
| --- | --- | --- | --- |
| `0051ADF0` | constructor | `render_area_in:TDrawArea*`, `parent_panel_in:TPanel*`, `font_in:void*`, `font_wid_in:long`, `font_hgt_in:long`, `unit_pics_in:TShape*`, `bldg_pics_in:TShape**`, `player_in:TRIBE_Player*` | none |
| `0051B070` | destructor | none | none |
| `0051B110` | `set_player` | `player_in:TRIBE_Player*` | none |
| `0051B140` | `set_object` | `game_obj_in:RGE_Static_Object*` | none |
| `0051B160` | `set_mode` | `mode_in:unsigned char` | none |
| `0051B180` | `get_mode` | none | none |
| `0051B190` | `draw` | none | `old_font:void*`, `orig_fval:float`, `name:char[100]`, `bldg_obj:TRIBE_Building_Object*`, `cur_val:short`, `temp:short`, `work_name:char[100]`, `cur_fval:float`, `work_target:short`, `work_type:short`, `progress:short`, `orig_val:short`, `str:char[100]`, `dx:float` |
| `0051BF90` | `draw_score` | none | `old_font:void*`, `y:short`, `i:int`, `x:short`, `x_val:short`, `temp_player:RGE_Player*`, `str:char[100]`, `rect:tagRECT` |
| `0051C220` | `draw_item` | `row:int`, `pic_index:int`, `val_type:ValueType`, `val1:int`, `val2:int` | `val_str:char[20]` |
| `0051C3F0` | `handle_idle` | none | `do_buttons:int`, `orig_fval:float`, `name:char[100]`, `bldg_obj:TRIBE_Building_Object*`, `cur_val:short`, `cur_fval:float`, `work_target:short`, `work_type:short`, `progress:short`, `orig_val:short`, `changed:int`, `temp:short` |
| `0051CA10` | `save_object_info` | none | `orig_fval:float`, `orig_val:short`, `temp:short` |
| `0051CC80` | `mouse_left_down_action` | `x:long`, `y:long`, `ctrl_key:int`, `shift_key:int` | none |
| `0051CC90` | `mouse_left_up_action` | `x:long`, `y:long`, `ctrl_key:int`, `shift_key:int` | none |

The per-function inventory packets are
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051ADF0_TRIBE_Panel_Object.txt`,
`0051B070_TRIBE_Panel_Object.txt`, `0051B110_set_player.txt`,
`0051B140_set_object.txt`, `0051B160_set_mode.txt`, `0051B180_get_mode.txt`,
`0051B190_draw.txt`, `0051BF90_draw_score.txt`, `0051C220_draw_item.txt`,
`0051C3F0_handle_idle.txt`, `0051CA10_save_object_info.txt`,
`0051CC80_mouse_left_down_action.txt`, and
`0051CC90_mouse_left_up_action.txt`.

## Original-name recovery

Recovered PDB parameter names and applied them in the source:

- Constructor: `draw_area` to `render_area_in`, `parent` to `parent_panel_in`,
  `font_` to `font_in`, `font_wid_` to `font_wid_in`, `font_hgt_` to
  `font_hgt_in`, `unit_pics_` to `unit_pics_in`, `bldg_pics_` to `bldg_pics_in`,
  and `player_` to `player_in`.
- `set_player`: `player` to `player_in`.
- `set_object`: `object` to `game_obj_in`.
- `set_mode`: `mode` to `mode_in`.
- `draw_item`: `index` to `row`, `frame` to `pic_index`, `type` to `val_type`,
  `value` to `val1`, and `value2` to `val2`.
- Both mouse handlers: `p0`, `p1`, `p2`, and `p3` to `x`, `y`, `ctrl_key`,
  and `shift_key`.

The PDB names `bldg_obj` and `old_font` share the `draw` stack offset `-0x144`.
I kept their separate declarations and scopes. I changed `handle_idle`'s
`building` to the PDB name `bldg_obj`, which has its own scoped PDB record.
The `building` local in `save_object_info` has no scoped PDB name, so it remains
unchanged. I did not force names for optimized or reused slots.

The remaining current local names match reliable scoped records. They include all
listed `draw`, `draw_score`, `handle_idle`, and `save_object_info` locals. The
unregistered `building_facet` helper has no procedure-scoped PDB record and remains
unchanged. No new descriptive names were invented.

## Constants, resources, and comments

No numeric constants or resource macros changed. No new source comment was added.
The existing invalid-resource branch comment remains because the default branch
jumps to `resource_done` without drawing that resource.

I investigated the `0x69` argument passed to `get_string2` in `draw`. The call site
is `src/tpnl_obj.cpp` near lines 261-266. The dispatch evidence is
`src/tribegam.cpp` near `TRIBE_Game::get_string2` and
`src/basegame.cpp` near `RGE_Base_Game::get_string2`. The top-level `0x69` value is
not a direct string-table ID in either fallback path. Its purpose is not proved as
a resource macro, so the literal remains numeric.

Resource extraction used `tools/inspect_pe_strings.py` after its `--help` command.
The extraction files are under `build/resource-strings/`.

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` has SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
  Language `0x0409` contains RT_STRING ID `0x0069` in block 7, slot 9, with
  UTF-16 length 0 and exact text empty.
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll` has SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
  ID `0x0069` is missing. No language entry exists for this ID.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  has SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
  ID `0x0069` is missing. No language entry exists for this ID.

The runtime README identifies `runtime/` as the staged game input. The XPack file
is the pinned original expansion resource. Empty and missing results do not prove
a purpose or an original macro name. No shared resource-ID request is submitted.

## Type, layout, and symbol review

The edits only rename parameters and one PDB-backed local. Brace placement changed
to 1TBS. No type, cast, scope, storage duration, declaration order, evaluation
order, call target, literal value, layout, ABI, or public symbol changed by intent.
The header was not edited. The source keeps all 13 definitions in registry order.
Final compiler and output checks remain required before any code-generation claim.

## Shared requests and unresolved questions

- Header request: none. `include/tpnl_obj.h` remains read-only.
- Resource header request: none. `0x69` remains unresolved as a direct resource
  mapping.
- The documented source-reunification packet is absent at the path recorded above.
- The `building_facet` helper has no registered procedure-scoped PDB record and was
  left unchanged.

## Validation

Evidence extraction and full Git diff review were allowed. `git diff --check`
passed. Compilation, matching, audits, tests, and game runs were not run.
