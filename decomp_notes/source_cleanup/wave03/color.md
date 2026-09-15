# `src/color.cpp` source-cleanup report

## Delivery

- Module: `src/color.cpp`
- Branch: `cleanup/staging-20260915-192`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `65f9edaf218070d99a0986246a23764d9eda1f00`
- Changed files:
  - `src/color.cpp`
  - `decomp_notes/source_cleanup/wave03/color.md`
- Paired header: `include/color.h` (read only; owner 22)
- Registry: `config/functions/src/color.cpp.json`
- Build profile: `default`

The source keeps the eight registered normal owners in PDB source order. The
nearby scalar deleting destructor at `00424420` remains compiler-generated and
has no handwritten owner in this file.

The base source blob SHA-256 is
`98886c39022ae6f4424532c8fd33ea8c4fe0391f8004acf317f2373a446c2a07`.
The final source blob SHA-256 is
`2fd8a21ff7e68b2e565262068a56914c8922abd63aaec0dae36329a29bffe268`.

## Evidence reviewed

The original executable is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The procedure-scoped PDB record file is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its SHA-256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The records use PDB source path `C:\msdev\work\age1_x1\color.cpp`.

The preserved baseline report is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`.
Its SHA-256 is
`fddd62868626e21ec7282183fa1cf84ad5b0b14fc719c8830a266d6ed0f155b3`.

I inspected the registry-selected original packets for every source owner:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00423EE0_RGE_translate_palette.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004240B0_RGE_fade_palette.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00424350_RGE_Color_Table.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00424440_RGE_Color_Table.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004244F0_RGE_Color_Table.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004245F0_RGE_Color_Table.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004247A0_RGE_Color_Table.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/004247B0_save.txt`

I also inspected the adjacent generated packet
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0042/00424420_scalar_deleting_destructor.txt`
and the type dump
`C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/RGE_Color_Table.txt`.
The type dump proves the `0x128`-byte class layout. No layout change was made.

## Original-name recovery coverage

All eight source functions have procedure-scoped PDB records. Each member
function records `this` in `ecx`. The PDB records no function statics or
register names beyond `this`.

| VA | Function | PDB names and source action |
| --- | --- | --- |
| `00423EE0` | `RGE_translate_palette` | Parameters `palette1`, `palette2`, `color`, `amount`, `ignore_color1`, and `ignore_color2` already matched. Locals `index1` and `intense` already matched. |
| `004240B0` | `RGE_fade_palette` | Recovered `surface`, `color`, `direction`, `new_palette`, `ignore_color1`, and `ignore_color2`. `fade_time`, `palette1`, `palette2`, `fade_time2`, `done`, `delta_time`, and `old_time` already matched. |
| `00424350` | `RGE_Color_Table::RGE_Color_Table(int)` | Recovered parameter `infile`. PDB locals `tempname` and `temp_color` match fields in the existing `scratch` storage. |
| `00424440` | `RGE_Color_Table::RGE_Color_Table(FILE*, short)` | Recovered parameter `infile`. PDB also records `in_id`, reused `temp_type`, `temp_map_color`, and `file_name`; the body keeps the existing `id_val` mapping because the PDB reuses a stack slot. |
| `004244F0` | `RGE_Color_Table::RGE_Color_Table(char*)` | Recovered parameter `filename`. Locals `tempname` and `temp_color` already matched. |
| `004245F0` | `RGE_Color_Table::RGE_Color_Table(TDrawArea*, long, tagPALETTEENTRY*, tagPALETTEENTRY*)` | Recovered `surface`, `in_color`, and `palette1`. Recovered local `index1` from the existing `index` declaration. `amount`, `palette`, `temp_palette`, `color`, and `temp_color` already matched. |
| `004247A0` | `RGE_Color_Table::~RGE_Color_Table` | PDB records only `this`; no source change. |
| `004247B0` | `RGE_Color_Table::save` | Recovered parameter `outfile`. |

The generated scalar deleting destructor at `00424420` records `this` and
`__flags`. It has no source declaration and was not changed.

The recovered original spellings are `surface`, `color`, `direction`,
`new_palette`, `ignore_color1`, `ignore_color2`, `infile`, `filename`,
`in_color`, `palette1`, `index1`, and `outfile`. The names `palette1`,
`palette2`, `color`, `amount`, `ignore_color1`, `ignore_color2`, `fade_time`,
`index1`, `intense`, `tempname`, `temp_color`, `palette`, `temp_palette`, and
`file_name` were retained where the source already matched the PDB.

No new invented name was added. Existing descriptive names remain unchanged
when the PDB gives no reliable mapping. These include `ColorFileScratch`,
`scratch`, `fp`, `i`, `j`, `temp`, `intensity`, `target`, `source`, `pct`,
`cur_time`, `best_distance`, `red`, `green`, `blue`, and the difference
variables. `ColorFileScratch` is an existing local storage wrapper, not a PDB
source type. This cleanup did not rewrite that storage.

The PDB types `done` as `unsigned char`, while the existing source declares it
as `bool`. The cleanup preserves the existing type. It does not claim a type
recovery from the PDB record.

## Constants, resources, comments, and formatting

No numeric constant changed. The source keeps the original loop bounds,
structure sizes, scan formats, file names, debug-time line values, and
sentinel values. No resource ID or resource lookup occurs in this module.
No resource DLL was queried, and no shared resource mapping is needed.

No source comment was added. Existing comments, declarations, calls, casts,
expression order, and control flow remain unchanged. Function definitions now
use 1TBS braces. Short signatures and calls stay on one line where practical.

## Unresolved declaration mappings

The paired declaration in `include/color.h` remains unchanged because owner 22
owns that header. The PDB and the cleaned definitions support these declaration
names for an owner-22 review:

- `RGE_Color_Table(int infile)`
- `RGE_Color_Table(FILE* infile, short id_val)`
- `RGE_Color_Table(char* filename)`
- `RGE_Color_Table(TDrawArea* surface, long amount, tagPALETTEENTRY* in_color, tagPALETTEENTRY* palette1)`
- `void save(int outfile)`

The body and the requested declaration keep `id_val` rather than forcing the
PDB's `in_id` spelling. The PDB records `in_id` and `temp_type` on the same
stack slot. It also records `temp_map_color` on a reused nearby slot. The
current body uses the existing aliased declarations and does not add fake
locals.

The PDB does not prove original names for the loop indexes and temporary
pointers listed above. Their mappings remain unresolved. No reused stack slot
was forced into a new declaration or name.

### Shared request

Request owner 22 to review the `include/color.h` declaration names listed
above. The request changes parameter spelling only. It keeps `id_val` in the
FILE* constructor to match the cleaned definition. It does not change a
signature, type, layout, calling convention, or ABI symbol. No request is
needed from the root resource-ID owner.

## Code-generation effects

The source changes rename parameters and one local, and move function opening
braces onto the definition lines. Renames keep types, scopes, storage, calls,
casts, evaluation order, control flow, layout, and symbol identity unchanged.
The `index` to `index1` change maps the existing `long` declaration to its PDB
name without changing storage or type. Formatting can change debug line maps,
but no line-dependent macro is present. The existing PDB-versus-source type
mismatch for `done` remains untouched.

The registry statuses remain as selected. This report does not claim byte
matching or behavior approval.

## Validation status

I ran evidence inspection, `git diff --check`, and a complete Git diff review.
I did not run compilation, a build, matching checks, audits, tests, or a game.
No prohibited command started. Generated code, program data, relocations, and
final output equality remain unvalidated until the final validation stage.
