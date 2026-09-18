# `tpnl_tim.cpp` cleanup report

## Delivery

- Module: `src/tpnl_tim.cpp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Source/resource mapping commit: `5aca07cc7ac08068cbfa5a03a866213081dff99b`
- Root approval commit: `8a5c5ef8de2613e7f46e84f70a18dce0bbe76340`
- Worker header import commit: `c76e13f7e04debf152a6342fe4b435876f4a6130`
- Changed files:
  - `src/tpnl_tim.cpp`
  - `decomp_notes/source_cleanup/wave03/tpnl_tim.md`
- The matching header `include/tpnl_tim.h` was read only.
- The header owner must apply the recovered declaration names listed below.
- The source keeps the original function order and ABI declarations.

## Source changes

The PDB names replaced descriptive parameter names in four functions:

- `TRIBE_Panel_Time::TRIBE_Panel_Time`
  - `draw_area` -> `render_area_in`
  - `parent` -> `parent_in`
- `TRIBE_Panel_Time::set_rect`
  - `x` -> `x_in`
  - `y` -> `y_in`
  - `width` -> `wid_in`
  - `height` -> `hgt_in`
- `TRIBE_Panel_Time::set_clock_type`
  - `clock_type` -> `clock_type_in`
  - `player_id` -> `player_id_in`
- `TRIBE_Panel_Time::get_true_render_rect`
  - `rect` -> `drawRect`

These names are recovered originals. Their spelling is not normalized.

The PDB confirms these existing locals:

- `draw`: `old_font` (`void*`), `str` (`char[256]`), and `rect` (`tagRECT`)
- `handle_idle`: `countdown_timer` (`long`)
- `render_to_image_buffer`: `old_font` (`void*`), `str` (`char[256]`), and `rect` (`tagRECT`)

I left those locals unchanged. Other source locals have no named PDB record.
I did not force mappings from optimized or reused slots.

I changed function-definition braces to 1TBS form. I changed no statement order,
scope, storage, call target, cast, type, literal value, or macro boundary.

I replaced verified SDK values:

- `SetBkMode(..., 1)` -> `SetBkMode(..., TRANSPARENT)`
- `0x20` DrawText flags -> `DT_SINGLELINE`
- `0x22` DrawText flags -> `DT_SINGLELINE | DT_RIGHT`

The pinned VC5 headers define `TRANSPARENT` as `1` in `WINGDI.H:1302`.
They define `DT_SINGLELINE` as `0x20` and `DT_RIGHT` as `0x2` in
`WINUSER.H:4878-4891`. These replacements keep the original values and int use.

No source comments were added. No new source identifiers were invented.

The approved resource names replaced the numeric IDs in both call paths:

- `0x2C24` -> `STRING_ID_COUNTDOWN_YEARS_FORMAT`
- `0x2C25` -> `STRING_ID_WONDER_YEARS_FORMAT`
- `0x2C26` -> `STRING_ID_ARTIFACTS_YEARS_FORMAT`
- `0x2C27` -> `STRING_ID_RUINS_YEARS_FORMAT`

The source includes `../include/resource_ids.h`. The substitutions preserve the
numeric values, calls, arithmetic, buffers, fallback, and formatting arguments.

## Owner-header request

Request to the owner of `include/tpnl_tim.h`:

```cpp
TRIBE_Panel_Time(TDrawArea* render_area_in, TPanel* parent_in);
void set_rect(long x_in, long y_in, long wid_in, long hgt_in);
void set_clock_type(int clock_type_in, int player_id_in);
virtual void get_true_render_rect(tagRECT& drawRect);
```

These parameter names come from the procedure-scoped PDB records. The request
changes names only. It does not change types, qualifiers, layouts, or symbols.

## Systematic PDB coverage

All 12 procedures in `.\\Release\\tpnl_tim.obj` were checked in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The 12 matching original packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/` were also read.

Each procedure records `this` in `ecx` as `TRIBE_Panel_Time*`.

| VA | Procedure | PDB parameters and locals | PDB register |
| --- | --- | --- | --- |
| `0051D790` | constructor | `render_area_in: TDrawArea*`; `parent_in: TPanel*` | `this: ecx` |
| `0051D890` | scalar deleting destructor | `__flags: unsigned int` | `this: ecx` |
| `0051D8B0` | destructor | none | `this: ecx` |
| `0051D940` | `set_rect` | `x_in`, `y_in`, `wid_in`, `hgt_in`: `long` | `this: ecx` |
| `0051DAD0` | `startup` | none | `this: ecx` |
| `0051DB00` | `set_clock_type` | `clock_type_in`, `player_id_in`: `int` | `this: ecx` |
| `0051DC60` | `get_clock_type` | none | `this: ecx` |
| `0051DC70` | `get_player_id` | none | `this: ecx` |
| `0051DC90` | `draw` | `old_font: void*`; `str: char[256]`; `rect: tagRECT` | `this: ecx` |
| `0051E0E0` | `get_true_render_rect` | `drawRect: tagRECT&` | `this: ecx` |
| `0051E150` | `handle_idle` | `countdown_timer: long` | `this: ecx` |
| `0051E2B0` | `render_to_image_buffer` | `old_font: void*`; `str: char[256]`; `rect: tagRECT` | `this: ecx` |

The scalar deleting destructor has no source body and remains compiler generated.
Its PDB parameter is `__flags`. I did not edit it.

The packet evidence shows the same boundaries and original direct calls used by
the registry. It does not support any further source-name mapping.

## Resource evidence and approval

The four IDs are formatted year strings used by both `draw` and
`render_to_image_buffer`. The calls are at `src/tpnl_tim.cpp:268,271,274,277`
and `src/tpnl_tim.cpp:420,423,426,429`.

The inherited `TPanel::get_string` call reaches `rge_base_game->get_string`.
`TRIBE_Game::get_string` checks `StringTableX` first, then falls back to the
base `StringTable`. The base game loads `language.dll` into `StringTable`.

The lookup path is `src/Panel.cpp:1919-1922`,
`src/tribegam.cpp:812-818`, and `src/basegame.cpp:318-320`.

The inspected base runtime resource is:

- File: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
- SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Language: `0x0409`

The checked expansion resources are:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

Both expansion files report missing IDs for the requested language `0x0409`.
They do not report empty slots or a matching language resource.
The base runtime file supplies these fallback strings:

| ID | Base text | Expansion status | Call-site purpose |
| --- | --- | --- | --- |
| `0x2C24` | `%d Years` | missing in both `languagex.dll` files | default year format |
| `0x2C25` | `Wonder: %d Years` | missing in both `languagex.dll` files | wonder timer |
| `0x2C26` | `Artifacts: %d Years` | missing in both `languagex.dll` files | artifact timer |
| `0x2C27` | `Ruins: %d Years` | missing in both `languagex.dll` files | ruin timer |

The IDs form one logical game string namespace. The game checks the expansion
resource first and uses the base resource as fallback.

The runtime language file is staged evidence, not the pinned original base DLL.
The pinned original tree contains only the XPack language module for this
lookup. This provenance remains unresolved for the base DLL.

I reviewed the owner evidence files under
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner19/`.
Their resource text and hashes agree with the evidence above.

Root approval and worker import:

- Root approved the substitutions in commit
  `8a5c5ef8de2613e7f46e84f70a18dce0bbe76340`.
- The worker imported only `include/resource_ids.h` in commit
  `c76e13f7e04debf152a6342fe4b435876f4a6130`.
- The worker did not edit the imported header.

```cpp
#define STRING_ID_COUNTDOWN_YEARS_FORMAT 0x2C24
#define STRING_ID_WONDER_YEARS_FORMAT    0x2C25
#define STRING_ID_ARTIFACTS_YEARS_FORMAT 0x2C26
#define STRING_ID_RUINS_YEARS_FORMAT     0x2C27
```

These reviewed names describe one logical game string namespace and their
formatted-message roles. The source now uses all four names.

## Unresolved items and scope requests

- No unresolved named PDB declaration mapping remains for the 11 source-backed
  functions.
- Optimized temporaries and EH slots remain unnamed. I did not map them.
- The base DLL provenance remains unresolved, as noted above.
- The `include/tpnl_tim.h` owner must apply the declaration-name request above.
- The root-owned resource definitions are imported. No header edit was made in
  this worktree.

## Validation

I ran evidence extraction and full Git diff review. I ran `git diff --check`.
I did not run compilation, matching, audits, builds, or tests.
I did not run the game.
