# `src/flics.cpp` cleanup report

## Delivery

- Module: `src/flics.cpp`.
- Branch: `cleanup/staging-20260915-178`.
- Report: `decomp_notes/source_cleanup/wave03/flics.md`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source-cleanup commit: `983605284d47d07e749cf2fedfc6e51f17db0c8f`.
- Changed files:
  - `src/flics.cpp`.
  - `decomp_notes/source_cleanup/wave03/flics.md`.

The source commit contains only the assigned source file. This report is a
separate assigned-file commit.

## Scope and evidence

I inspected the complete module source, the assigned header, the module note,
and every assigned procedure record. The source map at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
assigns these 15 normal owners to `C:\msdev\work\age1_x1\flics.cpp`:

`00449B30`, `00449BE0`, `00449C40`, `00449C50`, `00449DF0`, `00449E00`,
`00449E10`, `00449E20`, `00449E80`, `00449E90`, `0044A090`, `0044A100`,
`0044A2A0`, `0044A390`, and `0044A3E0`.

The procedure records are in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Each normal procedure has `this` in `ecx` with type `RGE_Flic_Player*`.
The reviewed padding-only boundary `0044A05D` belongs to `draw`; it has no
compiler-facing source body and was not changed.

Original instruction and source-line evidence remains in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449B30_RGE_Flic_Player.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449BE0_RGE_Flic_Player.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449C50_palette.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449E90_draw.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A090_literal.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A100_delta_flc.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A2A0_delta_fli.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A3E0_byte_run.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/flics.cpp.asm`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/flics.cpp.decomp`.

I read `include/flics.h` but did not edit it. The module note at
`decomp_notes/flics.md` records the recovered layouts and decoder constraints.

## Original-name recovery

The PDB stack records provide these names:

| VA | PDB names | Source result |
| --- | --- | --- |
| `00449B30` | `filename` parameter | Renamed `path` to `filename`. |
| `00449BE0` | `handle` parameter | Renamed `file_handle` to `handle`. |
| `00449C50` | `palette` parameter; `index1`, `temp_buffer`, and `framehead` locals | Kept `palette` and `framehead`; renamed `chunk_index` to `index1` and `frame_buffer` to `temp_buffer`. |
| `00449E90` | `drawarea_in`, `flic_x`, `flic_y` parameters; `temp_buffer` local | Existing source names already match. |
| `0044A100` | `cur_y` local | Existing source name already matches. |
| `0044A2A0` | `cur_x` local | Renamed the outer `remaining` counter to `cur_x`. The inner horizontal cursor remains the existing `x` name. |
| `0044A3E0` | `cur_x` stack record | No source rename was forced. The original home also saves `this` and is reused by the decoder. |

The PDB records for the remaining procedures contain only `this`. The source
keeps existing descriptive names for locals without a reliable PDB mapping,
including `size`, `fd`, `chunk`, `packets`, `color_index`, `packet_count`,
`count`, `frame`, `chunk_base`, `i`, `command`, `byte_count`, `lines`,
`line_remaining`, `x`, `p`, `copy_count`, `dst`, and `line_offset`.
These are existing names, not new inferred original names.

The source keeps its existing declaration types and scopes. The PDB types
`palette::index1` as `long` and `palette::temp_buffer` as `char*`; the source
keeps `int index1` and `int* temp_buffer`. The PDB types `delta_fli::cur_x`
as `long`; the source keeps `int cur_x`. These names map by the matching stack
home and use, but this cleanup does not change their types.

The `byte_run::cur_x` PDB record is not mapped to `line_offset`. The original
record's stack home is used for the saved `this` pointer during the packed copy
paths. The source retains `line_offset` until a separate declaration review
proves a mapping.

## Constants, comments, and formatting

I read the pinned VC5 headers before replacing the file-I/O literals:

- `C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H:41` defines
  `_O_BINARY` as `0x8000`.
- `C:/Program Files (x86)/DevStudio/VC/Include/STDIO.H:209-211` defines
  `SEEK_CUR` as `1`, `SEEK_END` as `2`, and `SEEK_SET` as `0`.

The source now uses `_O_BINARY` for the binary open mode and `SEEK_END` or
`SEEK_SET` for the existing `lseek` origins. The macro values preserve the
original arguments. No resource lookup or resource ID exists in this module.
No shared constant or resource declaration was added.

I retained the existing comments that explain the complete FLIC header copy,
the draw-area store order, and the separate palette-chunk path. I added no
new source comment. I moved function-definition braces to the module's 1TBS
style. I did not reorder declarations or executable statements.

## Header requests and unresolved questions

Please route these parameter-name updates to the owner of `include/flics.h`:

- `RGE_Flic_Player(char* path)` to `RGE_Flic_Player(char* filename)`.
- `RGE_Flic_Player(int file_handle)` to `RGE_Flic_Player(int handle)`.

The header request changes names only. It does not change the ABI or decorated
symbol. No other shared-file request is needed.

The known non-exact `palette` and `delta_flc` source shapes remain unchanged.
Their reviewed behavior and type constraints are recorded in
`decomp_notes/flics.md`. I did not attempt a structural decoder rewrite.

## Code-generation and review limits

The source edits change identifiers, brace placement, includes, and macro
spellings only. They do not change public symbols, function boundaries,
expression order, casts, storage, field layout, calls, or decoder state.
`_O_BINARY`, `SEEK_END`, and `SEEK_SET` expand to the original numeric values.
The PDB/source type differences listed above remain intentionally unresolved.

I reviewed the complete source diff against the base and ran `git diff --check`.
I did not run a compiler, build, matching check, audit, test, or game.
Compilation, matching, audits, and tests were not run.
