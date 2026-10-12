# Source cleanup report: `src/rge_fio.cpp`

## Delivery

- Module: `src/rge_fio.cpp`.
- Branch: `cleanup/staging-20260915-246`.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Final source commit: `ee91789eb61073d843829581fc22bae7349710a1`.
- Changed files: `src/rge_fio.cpp` and this report.
- Header read: `include/rge_fio.h`. It was not changed.
- The source registry is `config/functions/src/rge_fio.cpp.json`.
- The header registry is `config/functions/include/rge_fio.h.json`.

The source keeps all ten registry functions in source order. The cleanup
recovers procedure-scoped PDB names and uses 1TBS function braces. It keeps
types, scopes, storage, expressions, statements, calls, casts, literals, and
function symbols unchanged.

## Evidence coverage

I inspected every VA in `config/functions/src/rge_fio.cpp.json`. I inspected
every matching inventory packet under the absolute main-root paths
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/` and
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0048/`:

- `0047FD30_rge_fake_open.txt` (PDB lines 49-65).
- `0047FD90_rge_open.txt` (PDB lines 69-92).
- `0047FE20_rge_open.txt` (PDB lines 96-119).
- `0047FEB0_rge_fake_close.txt` (PDB lines 123-147).
- `0047FF30_rge_close.txt` (PDB lines 151-188).
- `00480000_rge_read_uncompressed.txt` (PDB lines 194-202).
- `00480040_rge_write_uncompressed.txt` (PDB lines 208-216).
- `00480080_rge_read.txt` (PDB lines 222-306).
- `00480290_rge_buffer_full.txt` (PDB lines 310-320).
- `004802C0_rge_write.txt` (PDB lines 326-360).

I inspected every assigned procedure record in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The original PDB source is `C:\msdev\work\age1_x1\rge_fio.cpp`. The PDB used
for this evidence is
`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`,
SHA256
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

The complete scoped-symbol coverage is:

| VA | Procedure | PDB stack names and types | PDB registers |
| --- | --- | --- | --- |
| `0047FD30` | `rge_fake_open` | `file_handle` `+0x4` `int`; `fake_size` `+0x8` `int` | none |
| `0047FD90` | `rge_open` | `filename` `+0x4` `char*`; `flag` `+0x8` `int` | none |
| `0047FE20` | `rge_open` | `filename` `+0x4` `char*`; `flag` `+0x8` `int`; `pmode` `+0xc` `int` | none |
| `0047FEB0` | `rge_fake_close` | `handle` `+0x4` `int` | none |
| `0047FF30` | `rge_close` | `handle` `+0x4` `int` | none |
| `00480000` | `rge_read_uncompressed` | `handle` `+0x4` `int`; `data` `+0x8` `void*`; `size` `+0xc` `int` | none |
| `00480040` | `rge_write_uncompressed` | `handle` `+0x4` `int`; `data` `+0x8` `void*`; `size` `+0xc` `int` | none |
| `00480080` | `rge_read` | `handle` `+0x4` `int`; `data` `+0x8` `void*`; `size` `+0xc` `int`; `temp` `+0xc` `unsigned char*`; `temp_size` `+0x8` `int`; `temp_max` `-0x4` `int` | none |
| `00480290` | `rge_buffer_full` | `out_buf_ofs` `+0x4` `unsigned char*`; `out_buf_size` `+0x8` `int` | none |
| `004802C0` | `rge_write` | `handle` `+0x4` `int`; `data` `+0x8` `void*`; `size` `+0xc` `int` | none |

All ten records have no function-static symbols. No procedure has a PDB
register name. The `rge_read` records show reused stack homes: `temp` shares
`+0xc` with `size`, and `temp_size` shares `+0x8` with `data`. The source
keeps the existing declarations, scopes, and types while applying the names
that match their observed uses. The source keeps `temp` as `void*`; this pass
does not change it to the PDB-recorded `unsigned char*` type.

The original executable behavior reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`,
SHA256
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/rge_fio.obj`,
SHA256
`77df91af88414a8c2308a0b1b5d55da71c83f450a6d61b74180be59c7d9ad175`.
The preserved pre-cleanup executable is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`,
SHA256
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.

## Recovered original names

The source restores these exact PDB spellings:

- `0047FD30`: `param_1` became `file_handle`; `param_2` became `fake_size`.
- `0047FD90`: `param_1` became `filename`; `param_2` became `flag`.
- `0047FE20`: `param_1` became `filename`; `param_2` became `flag`; `param_3` became `pmode`.
- `0047FEB0`: `file` became `handle`.
- `0047FF30`: `file` became `handle`.
- `00480000`: `file` became `handle`; `buffer` became `data`.
- `00480040`: `file` became `handle`; `buffer` became `data`.
- `00480080`: `file` became `handle`; `buffer` became `data`; `fsize` became `temp_size`; `loc` became `temp_max`; `rbuf` became `temp`.
- `00480290`: `buffer` became `out_buf_ofs`; `size` became `out_buf_size`.
- `004802C0`: `file` became `handle`; `buffer` became `data`.

The `size` parameters in `00480000`, `00480040`, `00480080`, and `004802C0`
already matched their PDB records. The inventory assembly maps `temp_size` to
the integer passed as the decompressor file-size pointer, `temp_max` to the
integer initialized to `0x10000` and passed as the output-size pointer, and
`temp` to the output cursor used by the `memcpy` calls. The reused homes are
not treated as evidence for a type or scope change.

All changed source names are recovered originals. No new descriptive name was
introduced. Existing names without a direct PDB record remain unchanged,
including `iVar1`, `state_size`, `remaining`, `total`, `ptr`, and `copy`.
Their mappings were not forced.

## Constants, resources, comments, and mappings

No numeric constant changed. The existing `0x10000`, `0x4B`, `2`, `1`, and
zero values remain in their original expressions and types. No SDK or CRT
constant replacement was needed.

This module has no resource lookup and no resource ID. No DLL resource
extraction was relevant. No resource-ID mapping or shared resource declaration
request exists.

No source comment was added. The only presentation change is the move of
function opening braces to 1TBS lines. No comment, string, fallback, or
lookup order changed.

## Code-generation, type, layout, and symbol review

The source changes rename parameters and locals and move function opening
braces. They do not change declaration types, storage, scopes, expression or
evaluation order, casts, control flow, calls, literals, function boundaries,
public symbols, ABI, data layout, relocations, or direct call targets.
The explicit `(char*)temp` cast remains unchanged. Function-brace changes and
name changes can change debug line and symbol records. Final validation must
compare generated code, program data, relocations, and call targets with the
preserved baseline object and executable. No such comparison was run here.

## Header and shared-file requests

Owner 28 controls `include/rge_fio.h`. Please recover these declaration names
without changing types, order, calling conventions, or ABI:

```cpp
int __cdecl rge_fake_open(int file_handle, int fake_size);
int __cdecl rge_open(char* filename, int flag);
int __cdecl rge_open(char* filename, int flag, int pmode);
int __cdecl rge_fake_close(int handle);
int __cdecl rge_close(int handle);
void __cdecl rge_read_uncompressed(int handle, void* data, int size);
void __cdecl rge_write_uncompressed(int handle, void* data, int size);
void __cdecl rge_read(int handle, void* data, int size);
int __cdecl rge_buffer_full(unsigned char* out_buf_ofs, int out_buf_size);
void __cdecl rge_write(int handle, void* data, int size);
```

No root-owned header request exists. No request exists for
`include/resource_ids.h` or `include/game_globals.h`.

## Unresolved questions

- The PDB records `temp` as `unsigned char*`, while the current source uses
  `void*`. This cleanup retains `void*`; a type change needs separate evidence
  and review.
- The PDB reuses the `data` and `size` stack homes for `temp_size` and `temp`.
  The source keeps the current declaration and scope arrangement.
- `iVar1`, `state_size`, `remaining`, `total`, `ptr`, and `copy` have no
  procedure-scoped PDB names in this inventory. They remain unchanged.

## Validation

I ran the required evidence-tool help commands before evidence inspection:
`generate_pdb_scoped_symbol_reference.py --help`,
`generate_pdb_source_reference.py --help`, `function_diagnostics.py --help`,
`original_fpo.py --help`, and `inspect_pe_strings.py --help`. I reviewed the
complete source diff and ran `git diff --check`.

Compilation, matching, audits, validation commands, and tests were not run.
No compiler, build, game, or executable validation command was run. This
report does not claim byte equality, semantic approval, or final validation.
