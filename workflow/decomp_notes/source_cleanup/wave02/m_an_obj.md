# `src/m_an_obj.cpp` cleanup report

## Delivery

- Module: `src/m_an_obj.cpp`
- Worker slot: 66
- Branch: `cleanup/staging-20260915-66`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Head commit for the source cleanup: `0ec83908f65aa3af975899ccd7dc4f917e6a6253`
- Changed files:
  - `src/m_an_obj.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/m_an_obj.md`

The source cleanup changes only parameter names. It does not change types, scopes,
statements, calls, casts, literals, evaluation order, or storage layout.

## Evidence inspected

The cleanup used these repository references:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/m_an_obj.cpp.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_line_changes.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044F9C0_RGE_Master_Animated_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FA20_vector_deleting_destructor.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FA40_RGE_Master_Animated_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FAB0_RGE_Master_Animated_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FB30_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FB60_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FBA0_setup.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FBF0_RGE_Master_Animated_Object.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FC00_make_new_obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FCD0_make_new_master.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FD40_copy_obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FD60_modify.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FD90_modify_delta.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FDC0_modify_percent.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044FDF0_save.txt`

Evidence file hashes copied during review:

- `scoped_symbols.json`: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- Original `XPack/empiresx.exe`: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Preserved baseline `m_an_obj.obj`: `d375bd362700932d71d1f16f574b3a6d3cd6034afd1b796a9f8d60e8bc900368`
- Preserved baseline `empiresx.exe`: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

The module registry marks all 14 source procedures as `matching` and uses the `gx`
flag profile. The source map assigns these procedures to original
`C:\msdev\work\age1_x1\m_an_obj.cpp` spans.

## PDB inspection coverage

I inspected the scoped PDB parameters, locals, function statics, and registers for
every source procedure. Each procedure has only the listed stack parameters and the
`this` register. No procedure has PDB function statics or local symbols.

| VA | Procedure | PDB source span | Scoped stack symbols | Registers and locals |
| --- | --- | --- | --- | --- |
| `0044F9C0` | copy constructor | 24-27 | `other_object`: `RGE_Master_Animated_Object*`; `do_setup`: `int` | `this` in `ecx`; no locals |
| `0044FA40` | integer-input constructor | 33-36 | `infile`: `int`; `sprites`: `RGE_Sprite**`; `sounds`: `RGE_Sound**`; `do_setup`: `int` | `this` in `ecx`; no locals |
| `0044FAB0` | text-input constructor | 42-45 | `infile`: `_iobuf*`; `sprites`: `RGE_Sprite**`; `sounds`: `RGE_Sound**`; `in_id`: `short`; `do_setup`: `int` | `this` in `ecx`; no locals |
| `0044FB30` | `setup` from master | 51-60 | `other_object`: `RGE_Master_Animated_Object*` | `this` in `ecx`; no locals |
| `0044FB60` | `setup` from integer input | 65-74 | `infile`: `int`; `sprites`: `RGE_Sprite**`; `sounds`: `RGE_Sound**` | `this` in `ecx`; no locals |
| `0044FBA0` | `setup` from text input | 79-89 | `infile`: `_iobuf*`; `sprites`: `RGE_Sprite**`; `sounds`: `RGE_Sound**`; `in_id`: `short` | `this` in `ecx`; no locals |
| `0044FBF0` | destructor | 94 | none | `this` in `ecx`; no locals |
| `0044FC00` | `make_new_obj` | 100-114 | `owner`: `RGE_Player*`; `x`: `float`; `y`: `float`; `z`: `float` | `this` in `ecx`; no PDB locals |
| `0044FCD0` | `make_new_master` | 119-121 | none | `this` in `ecx`; no locals |
| `0044FD40` | `copy_obj` | 126-132 | `source`: `RGE_Master_Static_Object*` | `this` in `ecx`; no locals |
| `0044FD60` | `modify` | 136-170 | `amount`: `float`; `flag`: `unsigned char` | `this` in `ecx`; no locals |
| `0044FD90` | `modify_delta` | 174-208 | `amount`: `float`; `flag`: `unsigned char` | `this` in `ecx`; no locals |
| `0044FDC0` | `modify_percent` | 212-246 | `amount`: `float`; `flag`: `unsigned char` | `this` in `ecx`; no locals |
| `0044FDF0` | `save` | 251-255 | `outfile`: `int` | `this` in `ecx`; no locals |

The PDB also contains the compiler-generated scalar deleting destructor at
`0044FA20`. I inspected its `__flags`: `unsigned int` stack symbol and `this` in
`ecx`. It has no PDB source span and is not a source declaration in this module.

The source declares a local `object` in `make_new_obj`, but the scoped PDB has no
local mapping for it. I left that existing source name unchanged. I did not force a
mapping for any reused or compiler-only stack slot.

## Recovered names

All names below are recovered original PDB spellings. They are not inferred cleanup
names:

| VA | Existing name | Recovered name | Evidence |
| --- | --- | --- | --- |
| `0044F9C0` | `source` | `other_object` | Scoped PDB stack symbol at `+0x4` |
| `0044FA40` | `id` | `infile` | Scoped PDB stack symbol at `+0x4`, type `int` |
| `0044FAB0` | `file` | `infile` | Scoped PDB stack symbol at `+0x4` |
| `0044FAB0` | `id` | `in_id` | Scoped PDB stack symbol at `+0x10`, type `short` |
| `0044FB30` | `source` | `other_object` | Scoped PDB stack symbol at `+0x4` |
| `0044FB60` | `file` | `infile` | Scoped PDB stack symbol at `+0x4` |
| `0044FBA0` | `file` | `infile` | Scoped PDB stack symbol at `+0x4` |
| `0044FBA0` | `id` | `in_id` | Scoped PDB stack symbol at `+0x10`, type `short` |
| `0044FC00` | `player` | `owner` | Scoped PDB stack symbol at `+0x4` |
| `0044FD60` | `value` | `amount` | Scoped PDB stack symbol at `+0x4` |
| `0044FD60` | `attribute` | `flag` | Scoped PDB stack symbol at `+0x8` |
| `0044FD90` | `value` | `amount` | Scoped PDB stack symbol at `+0x4` |
| `0044FD90` | `attribute` | `flag` | Scoped PDB stack symbol at `+0x8` |
| `0044FDC0` | `value` | `amount` | Scoped PDB stack symbol at `+0x4` |
| `0044FDC0` | `attribute` | `flag` | Scoped PDB stack symbol at `+0x8` |
| `0044FDF0` | `file` | `outfile` | Scoped PDB stack symbol at `+0x4` |

Names already matching the PDB remain unchanged. These include `do_setup`,
`sprites`, `sounds`, `x`, `y`, `z`, and `source` in `copy_obj`. No new inferred
name remains unresolved.

## Constants, resources, comments, and behavior

No constants changed. The source still writes `master_type = 0x14`, dispatches the
speed field only for flag `5`, and passes byte count `4` to `rge_read` and
`rge_write`. The packet assembly confirms the `0x14` master-type byte, speed field
at offset `+0xB8`, and the existing arithmetic and fallback call paths.

No resource lookup or resource ID occurs in this module. No resource request is
needed. No comment was added because the module has no additional proven lifetime,
unit, sentinel, or compatibility fact that needs a source comment.

## Risks and requests

- Parameter-name changes can alter debug names and line metadata, but they do not
  alter the C++ ABI, types, object layout, call targets, or symbol names.
- The integer parameter named `infile` is preserved exactly from the PDB. I did not
  change its type or interpretation.
- The existing explicit `static_cast<RGE_Master_Animated_Object*>` remains unchanged.
- No structural rewrite, helper, layout change, assembly, or header edit was made.
- Header owner 08: no change is requested for `include/m_an_obj.h`. Its declarations
  omit parameter names, so the recovered definition names do not require a header
  change.
- Root: no change is requested for `include/resource_ids.h` or another shared file.

## Validation status

I reviewed the complete Git diff and ran `git diff --check`. I did not run a
compiler, build, matching check, audit, or test. I did not run the game.
Compilation, matching, audits, and tests were not run.

## Root formatting correction

Root requested a formatting-only correction for the assigned source.

- Correction base commit: `e4c7792626afa357aa1a5791bccac1f1997e4272`
- Source correction head: `e460ef0325e1825fd5ed5c9e90eda477fc56b652`
- Corrected source blob: `6ae5f5d8e9f128e61636fca9a9af312a958977e3`

I reviewed the `setup`, `copy_obj`, `modify`, `modify_delta`, and
`modify_percent` definitions. Each short signature now uses one line where it
remains readable. The changed `setup`, `modify_delta`, and `modify_percent`
signatures no longer use continuation lines. No token, type, scope, expression,
call, literal, or behavior changed.

I reviewed the full base-to-head diff for the correction. I ran `git diff --check`.
I did not run a compiler, build, matching check, audit, or test. I did not run the
game. Compilation, matching, audits, and tests were not run.
