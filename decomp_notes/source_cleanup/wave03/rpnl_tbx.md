# `src/rpnl_tbx.cpp` cleanup report

## Delivery

- Module: `src/rpnl_tbx.cpp`
- Branch: `cleanup/staging-20260915-164`
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit from `git rev-parse`: `5f8c66e73c070e5356afaf918d80a4086f4a8ce9`
- The report is committed separately from the source.
- Changed files:
  - `src/rpnl_tbx.cpp`
  - `decomp_notes/source_cleanup/wave03/rpnl_tbx.md`
- Headers not edited by this worker:
  - `include/rpnl_tbx.h`
  - `include/resource_ids.h` (imported from the reviewed root change)

The source owns six normal bodies in PDB address and source order. The PDB
module is `C:\\msdev\\work\\age1_x1\\rpnl_tbx.cpp`.

## Evidence

The source registry selected:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/rpnl_tbx.cpp.json`

The PDB scope records were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The registry-selected original packets were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/004898D0_RGE_Panel_Tool_Box.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00489E90_RGE_Panel_Tool_Box.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/00489F50_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/0048A320_key_down_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/0048A520_game_mode_changed.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/0048A640_draw.txt`

The reviewed resource evidence was read from:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner19/base.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner19/runtime-x.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/reviewer-owner19/pinned-x.json`

The original executable and preserved cleanup baseline are reference inputs:

- Original PE: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Baseline PE: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

The packets confirm the original boundaries, source spans, and direct call
shapes. The original executable remains the behavior oracle.

## Original-name recovery coverage

All six registry functions were inspected. Each PDB scope was checked for
parameters, locals, and registers. Each procedure has the expected `this`
register in `ecx`.

| VA | Function | Recovery result |
| --- | --- | --- |
| `004898D0` | constructor | Recovered `draw_area_in`, `parent_in`, `x`, `y`, `wid`, `hgt`, `font`, `font_wid`, `font_hgt`, `sound`, `screen_panel_in`, `view_in`, `map_in`, and local `mode_buttons`. |
| `00489E90` | destructor | No stack parameter or local name exists. The source keeps only `this`. |
| `00489F50` | `action` | Recovered `from_panel`, `action_in`, `action_val1`, and `action_val2`. The last two remain unused, as in the existing body. |
| `0048A320` | `key_down_action` | Recovered `key`, `count`, `alt_key`, `ctrl_key`, `shift_key`, and locals `x1`, `y1`, `x2`, `y2`. |
| `0048A520` | `game_mode_changed` | Recovered `old_mode` and `new_mode`. The local `button` has no PDB name and remains unchanged. |
| `0048A640` | `draw` | No stack parameter or local name exists. The source keeps only `this`. |

The `key_down_action` PDB stack homes establish the local mapping. The PDB
records `x1` at `-0x4`, `y1` at `-0x8`, `x2` at `-0xC`, and `y2` at `-0x10`.
The prior source used `local_4`, `x1`, `y1`, and `x2` for those same homes.
The cleanup restores the PDB names by home and keeps declaration order, types,
scope, storage, and call order unchanged.

All renamed identifiers are recovered original names. No invented local or
parameter name was added. No reused stack-slot mapping remains unresolved for
this module.

## Constants, resources, and comments

No resource value changed. The source now uses the approved
`STRING_ID_SELECT_OBJECT_TITLE` macro. It expands to the original `0x232A` literal.
No enum or constant was added in this worker change.

The `0x232A` lookup has this evidence:

- Call site: `RGE_Panel_Tool_Box::action` passes it to `TPanel::get_string` as
the `RGE_Dialog_List::setup` title.
- Lookup path: `TPanel::get_string` calls `RGE_Base_Game::get_string`, which
calls `LoadStringA(StringTable, ...)`.
- Staged base resource: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`,
SHA256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
Language `0x0409` contains ID `0x232A` (`9002`) with exact text `Select Object`.
- Staged expansion resource: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`,
SHA256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
ID `0x232A` is missing.
- Pinned original expansion resource: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`,
SHA256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
ID `0x232A` is missing.

The staged base DLL supplied the text. The expansion DLL results are missing
IDs, not empty slots. The staged runtime file is not described as the pinned
original base resource.

Root approved the resource mapping in commit
`8a5c5ef8de2613e7f46e84f70a18dce0bbe76340`.
Git records the worker's exact header import commit as
`f27bf0a3616009dca91c44beb2b3a00f6b4c003b`.
The worker did not edit `include/resource_ids.h`.
The source applies the approved macro:

```cpp
#define STRING_ID_SELECT_OBJECT_TITLE 0x232A
```

This is a new descriptive name, not a recovered original macro.

No source comment was added. Existing control flow and lifetime behavior stay
unchanged.

## Code generation, type, layout, and symbol review

The source changes parameter and local spellings, moves function braces to
1TBS form, and applies the approved resource macro. The macro preserves the
literal value and effective type. The include and replacement do not change
calls, lookup buffers, fallback behavior, or formatting arguments. These
changes do not change types, casts, declaration scope, statement order,
control flow, function boundaries, object layout, relocations, or ABI symbols.

The local rename in `key_down_action` changes only names for the same four
stack homes. The explicit narrowing casts remain in place. No helper, wrapper,
assembly, layout change, or behavior repair was added.

## Header and shared-file requests

- `include/rpnl_tbx.h` remains unchanged. Its owner should apply these exact
parameter names without changing types or ABI:

```cpp
RGE_Panel_Tool_Box(TDrawArea* draw_area_in, TPanel* parent_in, long x,
                   long y, long wid, long hgt, void* font, long font_wid,
                   long font_hgt, TDigital* sound, TScreenPanel* screen_panel_in,
                   RGE_View* view_in, RGE_Diamond_Map* map_in);
virtual long action(TPanel* from_panel, long action_in,
                    unsigned long action_val1, unsigned long action_val2);
virtual long key_down_action(long key, short count, int alt_key, int ctrl_key,
                             int shift_key);
void game_mode_changed(int old_mode, int new_mode);
```

- Root approval and the worker header import cover
`STRING_ID_SELECT_OBJECT_TITLE`; no new resource declaration request remains.
- No other shared declaration request exists.

## Validation and open risks

`git diff --check` passed before the source commit. The complete source diff
was reviewed. Evidence extraction and resource inspection were allowed during
this cleanup.

The source registry marks `0048A320` as `accepted_drift`; this cleanup does not
change its behavior or its existing review status.

Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or runtime harness was run.
