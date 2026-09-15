# `src/mystring.cpp` source-cleanup report

## Delivery

- Module: `src/mystring.cpp`
- Branch: `cleanup/staging-20260915-197`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `ec9343cfb6a4d2874c1399789aba470a747aed9c`
- Report commit: this report commit; Git output gives its full hash.
- Changed files:
  - `src/mystring.cpp`
  - `decomp_notes/source_cleanup/wave03/mystring.md`

The source owner is `src/mystring.cpp`. The report owner is this file. No
header, registry, inventory, or other tracked file changed.

## Evidence checked

I read the repository contract and all source-cleanup, comment, resource-ID,
ownership, testing, and wave 03 assignment guides before editing.

I inspected the complete source and read-only header:

- `src/mystring.cpp`
- `include/mystring.h`
- `config/functions/src/mystring.cpp.json`
- existing `decomp_notes/mystring.md`

The registry selects four normal owners with default flags. I inspected each
registry-selected original packet:

- `inventory/functions/0046/00462D70_convert_us.txt`
- `inventory/functions/0046/00462D90_unconvert_us.txt`
- `inventory/functions/0046/00462DB0_addstring.txt`
- `inventory/functions/0046/00462E30_getstring.txt`

I also inspected the original module evidence:

- Source path: `C:\msdev\work\age1_x1\mystring.cpp`
- `inventory/pdb/scoped_symbols.json`, SHA-256
  `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- Original PDB, `orig/age1_x1.pdb`, SHA-256
  `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- Original listing, `orig/ghidra_decomp/mystring.cpp.asm`, SHA-256
  `6e17c3b9853dd3579459ac9f71ba4629a9b4f5f307835b4cb1dbe177e64937cc`
- Original decompiler excerpt, `orig/ghidra_decomp/mystring.cpp.decomp`,
  SHA-256 `e7fbdb16d785cd5c63ef08b05db309a2228a0bd1b9b6239c2cdb52b6a5f76f54`
- Original executable,
  `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
  SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The original module has four owners in source order. Their boundaries are
`00462D70` (26 bytes), `00462D90` (26 bytes), `00462DB0` (125 bytes), and
`00462E30` (76 bytes). The registry marks all four `matching`.

## Original-name recovery coverage

I inspected every procedure-scoped PDB record for the four owners. Each record
has no register symbols and no function statics.

| VA | Function | PDB names and source result |
| --- | --- | --- |
| `00462D70` | `convert_us` | The `+0x4` `char*` parameter is `string`. The source renames `str` to recovered `string` in the full loop. |
| `00462D90` | `unconvert_us` | The `+0x4` `char*` parameter is `string`. The source renames `str` to recovered `string` in the full loop. |
| `00462DB0` | `addstring` | PDB parameters are `out` (`char**`), `first` (`char*`), and `last` (`char*`). The source restores all three names. The PDB also records `last_length` as an `int` at reused slot `+0xc`; the source maps the second length local to recovered `last_length`. |
| `00462E30` | `getstring` | PDB parameters are `out` (`char**`) and `in` (`char*`). The source restores both names. |

The `addstring` `last` parameter and `last_length` local share `+0xc` in the
PDB. Use sites and the source line records separate their lifetimes. I did not
split or merge declarations. The source retains its existing `unsigned int`
type for both length locals. The PDB says `int` for `last_length`; this type
mismatch remains unresolved because this cleanup does not change a proved source
type or arithmetic width.

The source names `first_length` as a new descriptive cleanup name. The PDB has
no procedure-scoped record for it. The locals `dst` in `addstring`, `len` and
`dst` in `getstring` also have no safe PDB name mapping. They remain concise
inferred names. No parameter or local type, scope, storage, register, cast,
call, expression order, or public symbol changed. Only identifier spelling
changed.

## Constants, resources, and comments

No constants or resource IDs changed. This module has no resource lookup. No
resource extraction was needed.

The existing `getstring` comments remain. The original packet and assembly
prove that the old value is freed before allocation, the new pointer is
published after `calloc`, and the copy follows publication. The comments record
that order and the resulting allocation-failure behavior. No new comment was
needed.

## Shared requests and unresolved questions

Root owns `include/mystring.h`. Please review these declaration-name updates;
they do not change the ABI or types:

```cpp
void convert_us(char* string);
void unconvert_us(char* string);
void addstring(char** out, char* first, char* last);
void getstring(char** out, char* in);
```

The header currently uses `output`, `first`, `second`, and `value` for these
parameters. The source does not depend on header parameter names.

Open questions are limited to the PDB `int` type for reused-slot
`last_length`, and the missing procedure-scoped names for `first_length`,
`dst`, and `len`. No resource or declaration-value question remains.

## Possible code-generation effects

The source change is identifier-only. It keeps source order, declarations,
types, storage, expressions, calls, control flow, literals, and function
boundaries. It can change debug names. No compiler-output, relocation,
program-data, or direct-target check was run.

## Validation

I reviewed the complete Git diff and ran `git diff --check`. I did not run
compilation, matching, audits, tests, or games. Generated-output equality and
runtime behavior remain unvalidated.
