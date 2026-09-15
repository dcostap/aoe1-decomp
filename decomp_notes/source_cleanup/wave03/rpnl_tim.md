# `rpnl_tim.cpp` source-cleanup report

## Delivery

- Module: `src/rpnl_tim.cpp`.
- Worker slot: 165.
- Branch: `cleanup/staging-20260915-165`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source commit: `22a613f83286b1b916056e38c1722d4312215b43`.
- Final report commit: this report commit. Git output supplies its full hash.
- Changed files:
  - `src/rpnl_tim.cpp`.
  - `decomp_notes/source_cleanup/wave03/rpnl_tim.md`.
- PDB source: `C:\\msdev\\work\\age1_x1\\rpnl_tim.cpp`.
- Registry: `config/functions/src/rpnl_tim.cpp.json`.
- Registry flags: `gx`.
- Read-only header: `include/rpnl_tim.h`.

The source commit changes identifier names, two verified GDI mode constants, and
presentation. It keeps types, scopes, declarations, storage, calls, literals,
source order, and control flow unchanged.

## Evidence checked

I inspected these assigned function packets:

- `inventory/functions/0048/0048A680_RGE_Panel_Time.txt`.
- `inventory/functions/0048/0048A740_draw.txt`.
- `inventory/functions/0048/0048AA70_handle_idle.txt`.

I also inspected the compiler-generated and tail-jump destructor packet:

- `inventory/functions/0048/0048A730_RGE_Panel_Time.txt`.

Other evidence included:

- `inventory/pdb/scoped_symbols.json`.
- `inventory/pdb/function_source_map.csv`.
- `inventory/pdb/function_line_changes.csv`.
- `orig/ghidra_decomp/rpnl_tim.cpp.asm`.
- `orig/ghidra_decomp/rpnl_tim.cpp.decomp`.
- `include/rpnl_tim.h` and its included reviewed declarations.
- `decomp_notes/rpnl_tim.md`.

The original executable reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
I did not execute it.

## Original-name recovery

The registry assigns three source functions. The PDB records `this` in `ecx`
for each function.

| VA | Function | PDB records and source result |
| --- | --- | --- |
| `0048A680` | `RGE_Panel_Time::RGE_Panel_Time` | Stack parameters `draw_area_in` (`TDrawArea*`), `parent_in` (`TPanel*`), and `font_in` (`void*`) were recovered. |
| `0048A740` | `RGE_Panel_Time::draw` | Stack locals `old_font` (`void*`), `player_num` (`long`), `countdown_timer` (`long`), `str` (`char[100]`), and `paletteColor` (`tagPALETTEENTRY`) are recorded. The source now uses the three changed PDB names. `old_font` and `str` already matched. |
| `0048AA70` | `RGE_Panel_Time::handle_idle` | The PDB records no stack locals or parameters beyond `this`. Existing inferred names remain unchanged. |

The scalar deleting destructor at `0048A710` has only the compiler `__flags`
parameter record. It has no source body. The destructor at `0048A730` has no
PDB source map and tail-jumps to `TPanel::~TPanel`. Its empty source body
remains in place.

### Renamed parameters

The constructor parameter names changed as follows:

- `draw_area` -> `draw_area_in`.
- `parent` -> `parent_in`.
- `font_arg` -> `font_in`.

These names match the PDB stack records and their types. No header declaration
was changed.

### Renamed locals

The draw local names changed as follows:

- `pc` -> `player_num`, recovered from the PDB.
- `ct` -> `countdown_timer`, recovered from the PDB.
- `pe` -> `paletteColor`, recovered from the PDB.
- `t` -> `seconds`, a new descriptive cleanup name.
- `m` -> `minutes`, a new descriptive cleanup name.
- `h` -> `hours`, a new descriptive cleanup name.
- `pi` -> `player_index`, a new descriptive cleanup name.
- `yo` -> `y_offset`, a new descriptive cleanup name.
- `color` -> `text_color`, a new descriptive cleanup name.

The PDB displays `player_num` as `long`. The existing source declaration stays
`int`; this cleanup changes its spelling only. The source type mapping remains
an open question.

The PDB has one `str` record. The source has separate `char str[100]`
declarations in distinct paused, clock, and countdown scopes. The source keeps
the declarations separate. It does not merge or add storage.

The existing `map_color`, `palette`, and `current_old_time` names have no PDB
local records. They remain concise descriptive cleanup names. No placeholder
parameter or local remains in the assigned source functions.

## Constants, resources, and comments

The pinned VC5 header `C:/Program Files (x86)/DevStudio/VC/Include/WINGDI.H`
defines `OPAQUE` as `2` and `TRANSPARENT` as `1`. The source now uses these
symbols for the matching `SetBkMode` calls. Their effective values and types
remain unchanged.

No other numeric constant was added, removed, or changed. Existing redraw,
color, geometry, sentinel, buffer-size, and timer values remain numeric. No
comment was added. Existing calls, casts, string contents, and lookup order
remain unchanged.

The source looks up resource ID `0x2C24` through `TPanel::get_string(int)`.
The result formats one per-player countdown line. The proposed shared cleanup
name is `IDS_COUNTDOWN_TIMER_FORMAT`. This is a new descriptive name, not a
recovered original macro. The source keeps the numeric ID until the root header
owner reviews and adds that definition.

Resource evidence for `0x2C24`:

| File | SHA-256 | Language | Result |
| --- | --- | --- | --- |
| `runtime/language.dll` | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5` | `0x0409` | `%d Years` |
| `runtime/languagex.dll` | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39` | not present | ID missing |
| `orig/.../XPack/languagex.dll` | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2` | not present | ID missing |

`TRIBE_Game::get_string` checks the expansion table before the base table. The
checked expansion files lack this ID, so the checked base file supplies the
text. The extracted JSON files are under this worktree's ignored
`build/resource-strings/` directory.

## Formatting and code-generation risk

Function definitions now use 1TBS braces. The source uses moderate wrapping
for long expressions and signatures. No statement moved. No scope, declaration
point, storage duration, type, cast, call, virtual slot, public symbol, class
layout, or ABI changed.

Parameter and local renames do not change generated code. The GDI symbols
expand to the original immediate values. Brace and wrapping changes can alter
PDB line records. No compiler-output, program-data, relocation, or direct-call
target comparison was run.

## Header requests and unresolved questions

I did not edit `include/rpnl_tim.h` or `include/resource_ids.h`.

The root header owner may add this descriptive resource definition after review:

```cpp
#define IDS_COUNTDOWN_TIMER_FORMAT 0x2C24
```

The request is non-blocking. The source keeps `0x2C24` until that shared
mapping is approved. The PDB `player_num` type spelling and the one-to-many
mapping of the PDB `str` record remain unresolved source questions. No layout,
ABI, global, or other shared declaration request is open.

## Validation status

Compilation, matching, audits, and tests were not run. Builds and games were
not run. Only evidence extraction, source review, and complete Git diff review
were performed.
