# `tvw_dmap.cpp` source-cleanup report

## Delivery and Git history

Module: `src/tvw_dmap.cpp`

Base commit:

`c22ba4258c45b1178181e185d60a3b09a1add617`

Final source commit:

`04074397d97c118efc8d1a6f4a93348f0e68fe56`

The report commit follows the source commit.

Branch: `cleanup/staging-20260915-215`

Changed files:

- `src/tvw_dmap.cpp`
- `decomp_notes/source_cleanup/wave04/tvw_dmap.md`

The source registry is `config/functions/src/tvw_dmap.cpp.json`.
Owner 24 owns `include/tvw_dmap.h`; this worker did not edit it.

## Scope and evidence

The source registry owns four matching procedures:

- `0052C9E0` `TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View`
- `0052CA30` `TRIBE_Diamond_Map_View::set_redraw`
- `0052CA60` `TRIBE_Diamond_Map_View::draw_objects`
- `0052CAB0` `TRIBE_Diamond_Map_View::draw_object`

The source also defines the virtual destructor at `0052CA20`. It is a five-byte
tail jump to `RGE_Diamond_Map::~RGE_Diamond_Map` and has no source-line record.
The scalar deleting destructor at `0052CA00` is a compiler-generated helper.
It is outside the source registry and was not edited.

The PDB source path is `C:\msdev\work\age1_x1\tvw_dmap.cpp`. The PDB module
object path is `.\\Release\\tvw_dmap.obj`.

I reviewed the procedure-scoped records in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- PDB SHA256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`

I reviewed the complete original procedure packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C9E0_TRIBE_Diamond_Map_View.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052CA00_scalar_deleting_destructor.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052CA20_TRIBE_Diamond_Map_View.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052CA30_set_redraw.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052CA60_draw_objects.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052CAB0_draw_object.txt`

The original executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The original boundaries and direct targets are:

| VA | Size | Procedure evidence and direct calls |
| --- | ---: | --- |
| `0052C9E0` | 32 | Calls `RGE_Diamond_Map_View::RGE_Diamond_Map_View` at `0053D360`. |
| `0052CA20` | 5 | Tail-jumps to `RGE_Diamond_Map::~RGE_Diamond_Map` at `00436930`. |
| `0052CA30` | 46 | Calls `RGE_Diamond_Map::set_redraw` at `00437090` and `TRIBE_Screen_Game::set_map_buttons_redraw` at `00495A90`. |
| `0052CA60` | 70 | Calls `debug_timeGetTime` at `004231E0` and `RGE_Diamond_Map::draw_objects` at `00437CC0`. |
| `0052CAB0` | 60 | Calls `RGE_Diamond_Map::draw_object` at `00438060`. |

## Original-name recovery

The table covers every source procedure and the adjacent compiler-generated
destructor helper. Every member procedure records `this` in `ecx` with the
owning `TRIBE_Diamond_Map_View*` type.

| VA and function | PDB parameters and locals | Source result |
| --- | --- | --- |
| `0052C9E0` constructor | No stack parameters or locals; `this` in `ecx`. | No rename. |
| `0052CA00` scalar deleting destructor | `__flags` at `+0x4`, `unsigned int`; `this` in `ecx`. | Compiler-generated helper. No source change. |
| `0052CA20` destructor | No stack parameters or locals; `this` in `ecx`. | No rename. The PDB has no source-line record. |
| `0052CA30` `set_redraw` | `redraw_mode` at `+0x4`, `TPanel::RedrawMode`; `this` in `ecx`. | Renamed source parameter `mode` to recovered `redraw_mode`. |
| `0052CA60` `draw_objects` | No stack parameters or locals; `this` in `ecx`. | Retained existing local `now`. The PDB does not record a local spelling. |
| `0052CAB0` `draw_object` | `col` at `+0x4`, `short`; `row` at `+0x8`, `short`; `color` at `+0xc`, `unsigned char`; `size` at `+0x10`, `short`; `game_obj` at `+0x14`, `RGE_Static_Object*`; `this` in `ecx`. | Renamed all five source `param_*` names to the recovered PDB names. |

Recovered original spellings are `redraw_mode`, `col`, `row`, `color`, `size`,
and `game_obj`. The PDB uses these mixed and terse spellings. I preserved them.

`now` in `draw_objects` is an existing descriptive cleanup name, not a claimed
PDB recovery. The scoped PDB record has no stack local or register record for
it. No declaration mapping was forced from the optimized register use.
Members `last_attack_time`, `flash_on`, and `draw_objects_mode` were already
named and were not changed.

## Source changes

The source now uses the PDB parameter names in `set_redraw` and `draw_object`.
It also applies 1TBS brace placement, joins short signatures and calls, and
keeps the original initializer, declarations, expressions, casts, order, and
calls.

The following behavior remains unchanged:

- `set_redraw` calls the base implementation before its visible and active checks.
- `draw_objects` updates the flash state when the unsigned elapsed time reaches
  `0x14D`, then calls the base object drawing routine.
- `draw_object` changes only the color argument in base draw mode `4`.
- The color expressions remain `0x57 - 1` and `0 - 1`.
- The fixed debug source path and line argument `0x40` remain unchanged.

No helper, wrapper, layout change, assembly, structural rewrite, or behavior
repair was added.

## Constants, resources, and comments

`TPanel::RedrawNone` remains the existing enum symbol from
`C:/Projects/my_decomps/aoe1_attempt3/include/Panel.h:101-105`; its value is
`0`.

The original packet for `0052CA60` proves the `0x14D` comparison. The original
packet for `0052CAB0` proves the mode `4` comparison and the `0x57` mask and
subtract-one operations. No existing symbol proves a more specific meaning for
these values, so the numeric expressions remain unchanged. The related base
source sets `draw_objects_mode` to `4` before drawing the player's objects that
are under attack (`src/diam_map.cpp`, lines 724-730); this supports the call
context without changing this module's literals.

This source has no resource lookup and no resource ID. No resource DLL was
inspected, so no per-ID language, text, empty or missing status, resource hash,
or lookup path applies. No resource-header request is needed.

No source comment was added. The recovered names and existing code provide
sufficient context without a speculative comment.

## Code-generation and type risks

The edits rename parameters and change presentation only. They do not change
parameter types, local types, declaration scope, storage duration, declaration
order, evaluation order, casts, calls, control flow, literals, virtual slots,
class layout, function boundaries, relocations, or ABI symbols.

Formatting can change debug line records. The source has no `__LINE__` use, and
the fixed debug path and original debug line value remain intact. The generated
code remains unvalidated until the final validation stage.

## Header and shared-file requests

Request to owner 24 for `include/tvw_dmap.h`:

- Name the `set_redraw` declaration parameter `redraw_mode`.
- Name the `draw_object` declaration parameters `col`, `row`, `color`, `size`,
  and `game_obj`.

The evidence is the procedure-scoped PDB record for `0052CA30` and
`0052CAB0` in the shared inventory. The request changes parameter names only;
it does not change a type, layout, virtual slot, or ABI symbol.

No request is needed for root-owned headers, `include/resource_ids.h`, or
shared declarations.

## Review and validation

I reviewed the complete Git diff for the assigned source and report scope.
Compilation, matching, audits, and tests were not run.

No build, compiler check, validation command, game, or runtime harness was run.
