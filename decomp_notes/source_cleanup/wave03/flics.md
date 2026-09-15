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

## Post-cleanup matching investigation

The final validation row for `00449DF0` reports `matching_regression`.
It reports 3 changed bytes in a 14-byte function. The previous result was
`UNKNOWN`, so that result did not prove cleanup causation.

I compared the preserved baseline object with the fresh cleanup object:

- Baseline: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/flics.obj`.
- Baseline SHA256: `766653c06ace7fba825a70373c97784ed217fb12e98c5c24fc33e1e3519b8ae6`.
- Fresh: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/final-validation/functions/objects/flics.obj`.
- Fresh SHA256: `5496c8f3ad10b7dbd06e248fabc6d18fbb535888d838bb0d018533d69aae3d89`.

The baseline resolution bytes are
`0fbf41100fbf4912c1e0100bc1c3`. The fresh bytes are
`0fbf41120fbf4910c1e1000bc1c3`. The changed bytes reverse the two field
loads and change the shift destination.

The baseline source commit was
`6d46835cdc6e31ba879a2e6e31415327a7c7e341`. Its source SHA256 was
`9f8b2449475155db4049aa08677f883460032a0cf0fa9e7eb1e8bfa1ac28c98d`.
The pre-repair cleanup source SHA256 was
`1bd46f7fe7535e048f5dbeadf92c8e86bd3696a6c7f17fb753313c50c4d615f7`.
The cleanup body did not change the resolution expression before the repair.
It changed the surrounding compiland through names, braces, source lines, and
CRT macros. The same cleaned source produced the fresh byte order in a second
object. Older pre-cleanup objects produced the baseline byte order.

The baseline source places the resolution declaration at line 173, its brace
at line 174, and its return at line 175. The cleaned source placed the
declaration and brace at line 171 and the return at line 172. The palette
closing brace moved from line 171 to line 169. Two added CRT include lines
and four earlier joined braces caused the net two-line shift.

The recovered renames do not occur in `resolution`. The `_O_BINARY` and
`SEEK_*` macros occur in earlier functions and do not occur in `resolution`.
The assigned header stayed unchanged. Existing evidence therefore identifies
the changed source context as the trigger for VC5's code-generation choice,
but does not isolate one rename, include, macro, or brace without compiling
intermediate candidates.

The object comparison also finds two changed bytes in `delta_flc`. Its prior
status was `new_verified_logic`, not `matching`, so this is not a new
matching regression. This repair does not change that function.

The prior commutative-OR experiment is commit
`dee72a75fe4885309a67715731d978566c439d70`. It is rejected because it
changed operand and read order. The current source restores the original
resolution expression tokens and order.

The current source candidate is commit
`c5660f2b948e1201790d96c104d3b6a99be3eec8`. It restores the original
resolution brace form and its baseline physical lines. Two blank lines keep
the resolution declaration and return at baseline lines 173 and 175. It does
not revert recovered names, CRT macros, or unrelated formatting.

Requested isolated root experiment, not run: compile only this candidate
`src/flics.cpp` with the pinned VC5 toolchain and `config/flags/default.rsp`.
Compare symbol `?resolution@RGE_Flic_Player@@QAEJXZ` with the preserved
baseline object. Check all 15 flics sections and the known `delta_flc` drift.
Do not run a full build, audit, matching sweep, test, or game.

No post-candidate compiler, build, audit, matching check, test, or game run
was allowed. The candidate therefore remains unvalidated by a new object.

## Code-generation and review limits

The source edits change identifiers, brace placement, includes, and macro
spellings only. The rejected experiment is not part of the accepted source.
The accepted candidate restores the original resolution expression, brace
form, and physical lines. It does not change public symbols, function
boundaries, casts, storage, field layout, calls, or decoder state.
`_O_BINARY`, `SEEK_END`, and `SEEK_SET` expand to the original numeric values.
The PDB/source type differences listed above remain intentionally unresolved.

I reviewed the complete source diff against the base and ran `git diff --check`.
I did not run a compiler, build, matching check, audit, test, or game.
Compilation, matching, audits, and tests were not run.
