# `src/tobj_lst.cpp` cleanup report

## Scope and commits

- Module: `src/tobj_lst.cpp`
- Header owner: owner 25 owns `include/tobj_lst.h`; this worker did not edit it.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `97869ea32d964341c47cde51aad0bad7ac4fc487`
- Changed files in the source commit: `src/tobj_lst.cpp`
- The report is committed separately after the source commit.

The source has one registered normal function. The cleanup restores two
procedure-scoped PDB parameter names, removes an incomplete comment, and moves
the function brace to 1TBS style. It does not change executable statements.

## Evidence identity

- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tobj_lst.cpp.json`.
  It assigns `00511B00` to `TRIBE_Object_List::load` with status `matching`.
- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
  SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved preparation build:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build`.
  Baseline executable SHA256:
  `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
  Baseline object SHA256:
  `071301d27b287df960da77ee43feea4c1bd5615cff1a638165582bf25db2cfb6` for
  `tobj_lst.obj`.
- Original function packet:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/00511B00_load.txt`.
  SHA256: `a0ef8b623300d603d7b5890da6549750f26f95a9ced5085a2441792a26150376`.
- Scoped PDB index:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
  SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
  The recorded object module is `.\\Release\\tobj_lst.obj`.
- PDB source path: `C:\msdev\work\age1_x1\tobj_lst.cpp`.
- Original disassembly and decompiler references:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tobj_lst.cpp.asm`
  and `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tobj_lst.cpp.decomp`.

The packet records one body range, `00511B00-00511BC3`, with 196 bytes. It
records `__thiscall`, source lines 24-37, and eight line records. The original
body compares `object_type` with `'F'` and `'P'`, allocates `0x1C8` or `0x204`
bytes, calls the matching constructor with `infile`, `world`, and `1`, and
delegates other values to `RGE_Object_List::load`.

## PDB coverage and name recovery

Coverage is 1 of 1 registered functions.

`00511B00` (`TRIBE_Object_List::load`) has these procedure-scoped records:

- Stack `+0x4`: `object_type`, type `unsigned char`.
- Stack `+0x8`: `infile`, type `int`.
- Stack `+0xC`: `world`, type `RGE_Game_World*`.
- Register `ecx`: `this`, type `TRIBE_Object_List*`.
- Function statics: none.
- Other named locals or register locals: none.

The source changed these recovered original names:

- `type` to `object_type`.
- `mode` to `infile`.

`world` and `this` already matched the PDB. The names map directly to the
three distinct parameter stack offsets. No invented parameter or local name
was added. Ghidra's `local_4` and `local_c` are exception-handling slots, not
source declarations, so this cleanup does not map them to source names.

No declaration mapping remains unresolved for the source parameters. The PDB
function type index is `0x145E`; the packet and existing declarations provide
the supported `void __thiscall` signature.

## Constants, resources, and comments

No constant changed. The character values `'F'` and `'P'`, allocation sizes
`0x1C8` and `0x204`, constructor flag `1`, and delegated call remain unchanged.
No resource lookup or resource ID occurs in this module. No resource mapping
request is needed. No resource DLL was inspected.

The source had an incomplete two-line comment. The cleanup removed it. No new
comment was added. No shared declaration request is needed. Parameter names in
the definition do not change the declaration or ABI in
`include/tobj_lst.h`.

## Type and code-generation risks

The edits change parameter identifiers, call-site identifier spelling, comment
text, and brace placement only. They do not change types, casts, declaration
scope, storage, evaluation order, calls, literals, control flow, layouts, or
symbols. The source diff has no executable statement change. Compiler output,
line records, and matching remain unverified in this wave.

## Validation status

Evidence inspection, Git diff review, and `git diff --check` ran.
Compilation, builds, matching, audits, validation tools, tests, and games were
not run. No prohibited command started. No incident evidence exists.
