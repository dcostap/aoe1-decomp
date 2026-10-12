# `asprite.cpp` cleanup report

## Delivery

- Module: `src/asprite.cpp`
- Report: `workflow/decomp_notes/source_cleanup/wave04/asprite.md`
- Branch: `cleanup/staging-20260915-201`
- Base commit from `git rev-parse`: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Initial source cleanup commit from `git rev-parse`: `a99d06fa03378a6f7758b2a19322377d52f36200`
- Review correction commit from `git rev-parse`: `cee47c1b02e097b46319df648e3b89907b49aa75`
- Final source commit: `78e2ff19c76cebe290eb3b74abc8e8c6fdd74166`
- Changed files: `src/asprite.cpp` and this report.
- Registry: `config/functions/src/asprite.cpp.json`
- Build flags: `gx`

The source owns all 35 procedures in its registry. The cleanup recovers names
from the procedure-scoped PDB records. It also applies 1TBS brace placement and
readable wrapping. It does not change types, storage, statements, calls, or
literals.

The report is committed after the source commit. Its commit hash is returned
with the delivery because a report cannot contain its own final hash.

## Review correction

The full diff review requested three short definition signatures on one line:
the two-parameter animated-sprite constructor and both five-parameter
`get_frame` definitions. The constructor keeps its initializer list on the
next line. The longer draw signatures remain wrapped.

Source correction commit: `cee47c1b02e097b46319df648e3b89907b49aa75`.
This correction changes presentation only. It does not change expressions,
types, calls, declarations, or storage.

The updated diff review also requested the animated `get_frame` return call on
one line. Source correction commit: `78e2ff19c76cebe290eb3b74abc8e8c6fdd74166`.
This correction changes presentation only.

## Evidence inspected

Name evidence comes from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_line_changes.csv`

The PDB source path is `C:\msdev\work\age1_x1\asprite.cpp`. The PDB object
module is `.\Release\asprite.obj`.

I inspected the complete procedure unit at:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/asprite.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/asprite.cpp.asm`

The unit covers every registry procedure from `0041AD20` through `0041B600`.
It supplies the original boundaries, calls, literals, source line records, and
control flow. The matching function packets are under:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/`

The original executable used for address and behavior evidence is:

- Path: `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup object is:

- Path: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/asprite.obj`
- SHA-256: `ab44e06008f74c1e5fc7e0495c52b060fa38dc68205780581e3eefd3da30b540`

## PDB name-recovery coverage

I inspected the parameters, locals, and registers for all 35 source procedures.
Each row has one PDB `this` register in `ecx`. The PDB has no function-static
record for any row. Stack offsets and types below come from the scoped records.
A stack record at the same offset as another record shows optimized storage
reuse. It does not merge source declarations.

| VA | Procedure and PDB source span | PDB stack records | PDB register | Source result |
| --- | --- | --- | --- | --- |
| `0041AD20` | `RGE_Active_Sprite::RGE_Active_Sprite`, 23-28 | `new_sprite` `+0x4` `RGE_Sprite*` | `this@ecx` | Recovered `new_sprite`. |
| `0041AD60` | `RGE_Active_Sprite::RGE_Active_Sprite`, 32-43 | `infile` `+0x4` `int`; `sprites` `+0x8` `RGE_Sprite**`; `sprite_id` `+0x8` `short` | `this@ecx` | Recovered `infile`, `sprites`, and `sprite_id`. The last two records share a stack offset. |
| `0041ADD0` | `RGE_Active_Sprite::~RGE_Active_Sprite`, 47-48 | none | `this@ecx` | No source name to recover. |
| `0041ADE0` | `set_offset`, 52-55 | `x` `+0x4` `long`; `y` `+0x8` `long` | `this@ecx` | Recovered `x` and `y`. |
| `0041AE00` | `save`, 59-71 | `outfile` `+0x4` `int` | `this@ecx` | Recovered `outfile`. |
| `0041AE50` | `update`, 75-75 | `time` `+0x4` `float`; `speed` `+0x8` `float` | `this@ecx` | Recovered `time` and `speed`. |
| `0041AE60` | `draw`, 80-82 | `facet` `+0x4` `short`; `x` `+0x8` `long`; `y` `+0xc` `long`; `sx` `+0x10` `long`; `sy` `+0x14` `long`; `player_color` `+0x18` `RGE_Color_Table*`; `draw_area` `+0x1c` `TDrawArea*` | `this@ecx` | Recovered all seven parameter names. |
| `0041AEB0` | `normal_draw`, 86-88 | `facet` `+0x4` `short`; `x` `+0x8` `long`; `y` `+0xc` `long`; `player_color` `+0x10` `RGE_Color_Table*`; `draw_area` `+0x14` `TDrawArea*` | `this@ecx` | Recovered all five parameter names. |
| `0041AEF0` | `shadow_draw`, 92-94 | `facet` `+0x4` `short`; `x` `+0x8` `long`; `y` `+0xc` `long`; `player_color` `+0x10` `RGE_Color_Table*`; `draw_area` `+0x14` `TDrawArea*`; `flag` `+0x18` `unsigned char` | `this@ecx` | Recovered all six parameter names. |
| `0041AF30` | `what_frame`, 98-100 | none | `this@ecx` | No source name to recover. |
| `0041AF40` | `set_frame`, 104-104 | `new_frame` `+0x4` `short` | `this@ecx` | Recovered `new_frame`. |
| `0041AF50` | `is_animating`, 109-111 | none | `this@ecx` | No source name to recover. |
| `0041AF60` | `frame_passed`, 115-117 | `passed_frame` `+0x4` `short` | `this@ecx` | Recovered `passed_frame`. |
| `0041AF70` | `looped`, 121-123 | none | `this@ecx` | No source name to recover. |
| `0041AF80` | `get_facetindex`, 127-133 | `facet` `+0x4` `short`; `facet_index` `-0x4` `long` | `this@ecx` | `facet` and `facet_index` already matched the PDB. |
| `0041AFB0` | `get_frame`, 137-139 | `min_x` `+0x4` `short&`; `min_y` `+0x8` `short&`; `max_x` `+0xc` `short&`; `max_y` `+0x10` `short&`; `facet` `+0x14` `long` | `this@ecx` | Recovered all five parameter names. |
| `0041AFE0` | `get_lowest_draw_level`, 143-148 | none | `this@ecx` | No source name to recover. |
| `0041AFF0` | `setToFirstFrame`, 153-153 | none | `this@ecx` | No source name to recover. |
| `0041B000` | `check_for_shadows`, 158-163 | none | `this@ecx` | No source name to recover. |
| `0041B010` | `RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite`, 170-199 | `new_sprite` `+0x4` `RGE_Sprite*`; `tot_time` `-0x14` `float` | `this@ecx` | Recovered `new_sprite`. `tot_time` already matched. |
| `0041B140` | `RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite`, 204-214 | `infile` `+0x4` `int`; `sprites` `+0x8` `RGE_Sprite**` | `this@ecx` | Recovered `infile` and `sprites`. |
| `0041B200` | `RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite`, 218-218 | none | `this@ecx` | No source name to recover. |
| `0041B210` | `save`, 223-233 | `outfile` `+0x4` `int` | `this@ecx` | Recovered `outfile`. |
| `0041B290` | `update`, 237-301 | `time` `+0x4` `float`; `speed` `+0x8` `float` | `this@ecx` | Recovered `time` and `speed`. |
| `0041B430` | `draw`, 305-312 | `facet` `+0x4` `short`; `x` `+0x8` `long`; `y` `+0xc` `long`; `sx` `+0x10` `long`; `sy` `+0x14` `long`; `player_color` `+0x18` `RGE_Color_Table*`; `draw_area` `+0x1c` `TDrawArea*` | `this@ecx` | Recovered all seven parameter names. |
| `0041B4A0` | `normal_draw`, 316-323 | `facet` `+0x4` `short`; `x` `+0x8` `long`; `y` `+0xc` `long`; `player_color` `+0x10` `RGE_Color_Table*`; `draw_area` `+0x14` `TDrawArea*` | `this@ecx` | Recovered all five parameter names. |
| `0041B4F0` | `shadow_draw`, 327-329 | `facet` `+0x4` `short`; `x` `+0x8` `long`; `y` `+0xc` `long`; `player_color` `+0x10` `RGE_Color_Table*`; `draw_area` `+0x14` `TDrawArea*`; `flag` `+0x18` `unsigned char` | `this@ecx` | Recovered all six parameter names. |
| `0041B520` | `what_frame`, 333-335 | none | `this@ecx` | No source name to recover. |
| `0041B530` | `is_animating`, 339-341 | none | `this@ecx` | No source name to recover. |
| `0041B550` | `set_frame`, 345-347 | `new_frame` `+0x4` `short` | `this@ecx` | Recovered `new_frame`. |
| `0041B560` | `frame_passed`, 351-353 | `passed_frame` `+0x4` `short` | `this@ecx` | Recovered `passed_frame`. |
| `0041B590` | `looped`, 357-359 | none | `this@ecx` | No source name to recover. |
| `0041B5A0` | `get_facetindex`, 363-369 | `facet` `+0x4` `short`; `facet_index` `-0x4` `long` | `this@ecx` | `facet` and `facet_index` already matched the PDB. |
| `0041B5D0` | `get_frame`, 373-375 | `min_x` `+0x4` `short&`; `min_y` `+0x8` `short&`; `max_x` `+0xc` `short&`; `max_y` `+0x10` `short&`; `facet` `+0x14` `long` | `this@ecx` | Recovered all five parameter names. |
| `0041B600` | `setToFirstFrame`, 380-384 | none | `this@ecx` | No source name to recover. |

The PDB also contains two generated deleting-destructor records. They are not
source owners and were not edited:

- `0041AD40`: `__flags` `+0x4` `unsigned int`; `this@ecx`.
- `0041B120`: `__flags` `+0x4` `unsigned int`; `this@ecx`.

## Recovered names and provenance

The following names are recovered PDB spellings. The source changes only the
identifier and its uses. They do not change declarations, types, or scopes.

- `0041AD20`: `sprite` to `new_sprite`.
- `0041AD60`: `param_1` to `infile`; `param_2` to `sprites`; `index` to
  `sprite_id`.
- `0041ADE0`: both generated parameters to `x` and `y`.
- `0041AE00`: `param_1` to `outfile`.
- `0041AE50`: `param_1` and `param_2` to `time` and `speed`.
- `0041AE60`: `param_1` through `param_7` to `facet`, `x`, `y`, `sx`, `sy`,
  `player_color`, and `draw_area`.
- `0041AEB0`: `param_1` through `param_5` to `facet`, `x`, `y`,
  `player_color`, and `draw_area`.
- `0041AEF0`: `param_1` through `param_6` to `facet`, `x`, `y`,
  `player_color`, `draw_area`, and `flag`.
- `0041AF40`: `param_1` to `new_frame`.
- `0041AF60`: `param_1` to `passed_frame`.
- `0041AF80`: `param_1` to `facet`. `facet_index` already matched.
- `0041AFB0`: `param_1` through `param_5` to `min_x`, `min_y`, `max_x`,
  `max_y`, and `facet`.
- `0041B010`: `spr` to `new_sprite`.
- `0041B140`: `param_1` and `param_2` to `infile` and `sprites`.
- `0041B210`: `param_1` to `outfile`.
- `0041B290`: `param_1` and `param_2` to `time` and `speed`.
- `0041B430`: `param_1` through `param_7` to `facet`, `x`, `y`, `sx`, `sy`,
  `player_color`, and `draw_area`.
- `0041B4A0`: `param_1` through `param_5` to `facet`, `x`, `y`,
  `player_color`, and `draw_area`.
- `0041B4F0`: `x`, `a3`, `a4`, `colors`, `area`, and `mode` to `facet`, `x`,
  `y`, `player_color`, `draw_area`, and `flag`.
- `0041B550`: `value` to `new_frame`.
- `0041B560`: `param_1` to `passed_frame`.
- `0041B5A0`: `facet` and `facet_index` already matched.
- `0041B5D0`: `a`, `b`, `c`, `d`, and `e` to `min_x`, `min_y`, `max_x`,
  `max_y`, and `facet`.

The PDB records also confirm existing names that needed no source change:
`facet_index` in both facet-index methods and `tot_time` in `0041B010`.
They confirm all names listed as unchanged in the coverage table.

## Inferred and unresolved declarations

The PDB does not provide a usable source mapping for every declaration.
I left uncertain declarations separate and preserved their existing storage.

- `0041AD60`: `sprites` and `sprite_id` have the same PDB offset, `+0x8`,
  because optimized storage is reused. The source keeps a separate `short
  sprite_id` local and a separate `RGE_Sprite** sprites` parameter. The PDB
  spelling and the read/index use establish the local name. No stack mapping
  was forced.
- `0041B010`: PDB names only `tot_time` among the locals. Existing `count`,
  `rnd`, and `frame_time` have no scoped PDB records. The source keeps their
  declarations and order. The earlier exact-source recovery record also uses
  these names and this order.
- `0041B290`: the existing `short count` local has no scoped PDB record. Its
  type, declaration point, and narrow conversion remain unchanged.
- `0041AFB0`: the old `iVar1` name had no PDB local record. I changed it to the
  new cleanup name `result`. The call returns an `int`, and the source casts
  that value to `unsigned char`. `result` is not claimed as an original name.
- `0041B530`: the existing `int result` local has no PDB record. It remains
  unchanged.
- `0041B560`: the existing `int result` local has no PDB record. It remains
  unchanged.
- `0041B5A0`: the PDB confirms `facet_index`, but its `-0x4` stack home is an
  optimized temporary. The declaration remains a separate `long` local.

The compiler exception slots and the two deleting destructors are generated
records. They are not source declarations. No source names were assigned to
them.

## Constants, resources, comments, and formatting

No constant was added or replaced. The source retains these original values:

- Active-sprite type values `1` and `2`.
- Animation flag masks `4`, `1`, and `8`.
- The null fallback draw level `0x14`.
- The animation minimum literal `0.001f`.
- The debug-random source line `0xB7` and fixed source path.
- All read and write sizes, including `1`, `2`, and `4`.

The executable unit supports the flag masks and the `0x14` fallback. The global
inventory records these existing data values:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/globals/dumps/0056EE78_DAT_0056ee78.txt` records `double 0.001` at `0056EE78`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/globals/dumps/0056EE80_DAT_0056ee80.txt` records the existing `float` at `0056EE80`.

No existing header symbol proves a better name for these values. No header
constant request is open.

This source has no resource lookup. It has no string ID, dialog ID, menu ID, or
resource arithmetic. I did not inspect runtime resource DLLs because no ID is
used. No resource hash, language, payload, missing block, empty slot, lookup
path, or resource mapping applies to this module.

No source comment was added. The fixed debug path remains part of the original
call. The comment guide does not require a comment for this direct evidence.

The source now uses 1TBS opening braces. Long signatures and calls use readable
continuation lines. These presentation changes can alter debug line records.
They do not alter executable expressions or source declaration order.

## Code-generation and identity review

The edits rename parameters and one decompiler temporary. They update only
identifier uses. The edits do not change:

- Parameter or return types.
- Local types, declaration points, scopes, or storage duration.
- Declaration order or evaluation order.
- Explicit `this->` expressions.
- Casts, calls, control flow, literals, or fixed strings.
- Class layout, virtual slots, function boundaries, or ABI symbols.

Identifier names do not change release instructions. The formatting changes can
change compiler debug metadata and line records. Compilation remains deferred,
so no generated-code claim is made.

The source has no helper, wrapper, layout rewrite, assembly change, binary
library dependency, or resource definition. The original `RGE_Sprite` calls and
animation arithmetic remain in place.

## Header and shared-file requests

I did not edit `include/asprite.h`. It only includes `sprite.h`, so it has no
parameter declarations to mirror.

The `RGE_Active_Sprite` and `RGE_Active_Animated_Sprite` declarations are in
`include/asp_list.h`. I did not edit that header. Please mirror these recovered
parameter names in its existing declarations:

- `RGE_Active_Sprite(RGE_Sprite* new_sprite)`.
- `RGE_Active_Sprite(int infile, RGE_Sprite** sprites)`.
- `set_offset(long x, long y)`.
- `save(int outfile)` and `update(float time, float speed)`.
- `draw(short facet, long x, long y, long sx, long sy,
  RGE_Color_Table* player_color, TDrawArea* draw_area)`.
- `normal_draw(short facet, long x, long y, RGE_Color_Table* player_color,
  TDrawArea* draw_area)`.
- `shadow_draw(short facet, long x, long y, RGE_Color_Table* player_color,
  TDrawArea* draw_area, unsigned char flag)`.
- `set_frame(short new_frame)` and `frame_passed(short passed_frame)`.
- `get_facetindex(short facet)`.
- `get_frame(short& min_x, short& min_y, short& max_x, short& max_y,
  long facet)`.
- `RGE_Active_Animated_Sprite(RGE_Sprite* new_sprite)`.
- `RGE_Active_Animated_Sprite(int infile, RGE_Sprite** sprites)`.
- The animated `save`, `update`, `draw`, `normal_draw`, `shadow_draw`,
  `set_frame`, `frame_passed`, `get_facetindex`, and `get_frame` declarations
  use the same names above.

This is a declaration-name request only. It does not request a type, layout,
virtual-order, calling-convention, or ABI change. The header owner should review
this request. No `include/resource_ids.h` request is needed.

## Validation

I inspected the PDB records, original procedure unit, global evidence, source,
and complete Git diff. I did not run `git diff --check`.

Compilation, matching, audits, and tests were not run. No build, compiler check,
game, or runtime harness was run. The result remains reviewed but unvalidated.
