# `src/Shape.cpp` source-cleanup report

## Delivery

- Module: `src/Shape.cpp`
- Report: `decomp_notes/source_cleanup/wave04/Shape.md`
- Branch: `cleanup/staging-20260915-204`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Source cleanup commit: `a36f10970e39040f9cba4b4b05a4c24c4aeb6408`
- Changed files: `src/Shape.cpp` and this report.
- Registry: `config/functions/src/Shape.cpp.json` (read only)
- Build profile: `config/flags/default.rsp`

The source owns all 26 registered `TShape` procedures in PDB order. The
source cleanup changes names and brace placement. It does not change the
header, types, scopes, storage, statements, calls, literals, or source order.

The report commit is separate from the source commit. Its hash is returned
with delivery because a report cannot contain its own final hash.

## Evidence and hashes

The behavior oracle is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The scoped PDB evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

Its SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The extracted Shape records are in
`build/shape_pdb_scoped.txt`. Its SHA256 is
`d7ebedce4b3db1b787c7266e3d619809cfb5d823283c128d3e084fc00cec2b0f`.

The PDB source path is `C:\msdev\work\age1_x1\Shape.cpp`. The PDB object
module is `.\Release\Shape.obj`. The original function evidence is in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/shape.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/Shape_Header.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/Shape_File_Header.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/Shape_Info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/Shape_Offsets.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/TShape.txt`

The base source SHA256 is
`2a979b1230878e8e0a30cef7c7a7fc2fa39e185be3f824bd48a80495247648c0`.
The final source SHA256 is
`bbbb5b0e989e7904c29d519e4d68aec2021fdf1eaa219540331df31518ca42f5`.

`include/Shape.h` was not changed. Its SHA256 is
`7ec4a27a6ac3d9fef4a01ff633ab5e800ffb2520cb446a972a7d1660f2d0fe86`.
The source registry and build recipe were not changed.

## Original-name recovery

I reviewed parameters, locals, and receiver registers for all 26 procedures.
The PDB records place each member receiver in `ecx`. The recovered names keep
the original mixed spelling, including `NextFile`.

The main recovered names are:

| VA | Procedure | Recovered names used |
| --- | --- | --- |
| `004B8B50` | constructor | `resource_file_id`, `NextFile` |
| `004B8E40` | `Check_shape` | `shape_num`, `proc` |
| `004B8FB0` | `shape_bounds` | `shape_num`, `width`, `height` |
| `004B9070` | `shape_minmax` | `x_min`, `y_min`, `x_max`, `y_max`, `shape_num` |
| `004B9140` | `shape_check` | `check_x`, `check_y`, `shape_num`, local `shape_x0`, local `r` |
| `004B9440` | `shape_draw` | `drawarea`, `flags`, `color_table`, local `clip_x1` |
| `004B97F0` | `shape_draw_unclipped` | `drawarea`, `shape_x0`, `shape_y0`, `shape_num`, local `width`, `command` |
| `004B99F0` | `shape_shadow_unclipped` | `drawarea`, `shape_x0`, `shape_y0`, `color_table`, local `command` |
| `004B9AF0` | `shape_draw_clipped` | `drawarea`, `shape_x0`, `shape_y0` |
| `004B9E20` | `shape_color_trans_clipped` | `drawarea`, `shape_x0`, `shape_y0`, local `temp_buffer` |
| `004BA1C0` | `shape_shadow_clipped` | `drawarea`, `shape_x0`, `shape_y0`, `color_table` |
| `004BA550` | `shape_mirror` | `drawarea`, `flags`, `color_table` |
| `004BA900` | `shape_mirror_unclipped` | `drawarea`, `shape_x1`, `shape_y0`, local `command` |
| `004BA9E0` | `shape_mirror_color_trans_unclipped` | `drawarea`, `shape_x1`, `shape_y0`, `shape_num`, `color_table`, local `command` |
| `004BAAF0` | `shape_mirror_shadow_unclipped` | `drawarea`, `shape_x1`, `shape_y0`, `color_table`, local `command` |
| `004BAC00` | `shape_mirror_clipped` | `drawarea`, `shape_x1`, `shape_y0` |
| `004BAF20` | `shape_mirror_color_trans_clipped` | `drawarea`, `shape_x1`, `shape_y0`, `shape_num`, `color_table` |
| `004BB280` | `shape_mirror_shadow_clipped` | `drawarea`, `shape_x1`, `shape_y0`, `color_table`, local `command` |
| `004BB5E0` | `shape_dither` | `drawarea`, `dx`, `dy` |
| `004BB770` | `shape_dithered_unclipped` | `drawarea`, `shape_x0`, `shape_y0`, `dx`, `dy`, locals `save_flag`, `index1` |
| `004BB910` | `shape_dithered_clipped` | `drawarea`, locals `y`, `save_flag`, `index1` |

The default constructor, destructor, `is_loaded`, `shape_count`, and
`shape_color_trans_unclipped` had no changed PDB name. Their braces now use
1TBS style.

`shape_file_header` is a new descriptive name. The PDB does not name that
local, but its type and use identify the `Shape_File_Header` object. The other
names in the table come from PDB records or direct declaration matches.

## Unresolved mappings

The PDB records reuse stack homes across parameters and locals. I did not
force those homes into new declarations. This applies to the `save_buffer`,
`width`, and temporary records in the clipped drawing procedures, and to the
`save_buffer` records in mirror procedures. Existing `dst`, `pitch`, and
related locals remain descriptive where the declaration mapping is not safe.

The PDB lists `save_buffer` and `temp_buffer` in `004B9E20`. The source's
used row pointer now uses the PDB name `temp_buffer`. The unused or reused
`save_buffer` record does not justify a new declaration.

The PDB does not establish names for many source temporaries, including
`raw_y0`, `shape_y`, `width`, `outline`, `data_offsets`, `source`, `state`,
`transform_count`, and `row_dither`. Their types, scopes, and storage remain
unchanged. The PDB does not prove a public function, class, member, global,
ABI symbol, or calling-convention change.

## Constants, resources, and headers

No numeric constant changed. The constructor keeps the two existing resource
type values:

- `0x73687020`, the packed SHP resource type.
- `0x736c7020`, the packed SLP resource type.

The second `RESFILE_load` argument is the caller-provided
`resource_file_id`. This module owns no concrete resource ID. No resource
macro or `include/resource_ids.h` change is requested.

The original resource files used by this game are:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/data2/graphics.drs`, SHA256
  `82671a2234ae9bb74d40110ad3ba47440761bb44ff51e4f926578c4a98ccafee`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/data2/Interfac.drs`, SHA256
  `f151bc2cffae86b58469873181fe612a2f5942d64b9879dd6cdc48c134e55fef`.

No source-owned ID in `Shape.cpp` selects a resource entry, so no resource
payload mapping or shared resource declaration is requested.

No header change is requested. `include/Shape.h` keeps its existing generic
parameter names because the user reserved that file. The source definitions
use recovered names without changing the declarations or ABI.

No new comment was added. No function, class, member, global, literal, call,
control-flow statement, or source owner changed.

## Code-generation review

The complete source diff was reviewed with Git. The changes rename
identifiers and move opening braces to 1TBS style. They preserve declarations,
types, scopes, storage duration, casts, expressions, calls, control flow,
literals, strings, and source order.

Parameter and local renames do not change ABI symbols, class layout, call
targets, relocations, or data. Brace movement can change debug line records.
No claim is made about release instructions or program-data equality because
compilation was deferred.

## Validation

Compilation, matching, audits, and tests were not run. No build, compiler
check, executable comparison, game, or runtime harness was run for this
assignment. The result is reviewed but unvalidated.
