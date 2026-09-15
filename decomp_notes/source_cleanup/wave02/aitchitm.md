# Source cleanup report: `src/aitchitm.cpp`

## Commits and scope

- Module: `src/aitchitm.cpp`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `676a6b609b8d016a684ab63691ca1a5ec09425d9`.
- Changed files: `src/aitchitm.cpp` and this report.
- Branch: `cleanup/staging-20260915-52`.
- Header read: `include/aitchitm.h`. It was not changed.

The source keeps all 11 registry functions in source order. It keeps their
signatures, types, scopes, storage, calls, expressions, and executable
statements. The cleanup only restores procedure-scoped PDB parameter names.

## Evidence coverage

I inspected every registry VA in
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/aitchitm.cpp.json`.
The registry records PDB source path `C:\msdev\work\age1_x1\aitchitm.cpp` and
`gx` flags.

I inspected every assigned procedure's stack and register records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB coverage is:

| VA | Procedure | PDB stack symbols | PDB register symbols |
| --- | --- | --- | --- |
| `00412BB0` | default constructor | none | `this` in `ecx`, `TechnologyItem*` |
| `00412C20` | `(int, char*, ResourceItem)` constructor | `i` at `+0x4`, `n` at `+0x8`, `r` at `+0xC` | `this` in `ecx`, `TechnologyItem*` |
| `00412CD0` | copy constructor | `ti` at `+0x4`, `const TechnologyItem&` | `this` in `ecx`, `TechnologyItem*` |
| `00412D70` | destructor | none | `this` in `ecx`, `TechnologyItem*` |
| `00412D90` | `operator==` | `one` at `+0x4`, `two` at `+0x8`, both `const TechnologyItem&` | none |
| `00412DB0` | `operator!=` | `one` at `+0x4`, `two` at `+0x8`, both `const TechnologyItem&` | none |
| `00412DD0` | `operator<` | `one` at `+0x4`, `two` at `+0x8`, both `const TechnologyItem&` | none |
| `00412DF0` | `operator>` | `one` at `+0x4`, `two` at `+0x8`, both `const TechnologyItem&` | none |
| `00412E10` | `id` | none | `this` in `ecx`, `const TechnologyItem*` |
| `00412E20` | `name` | none | `this` in `ecx`, `TechnologyItem*` |
| `00412E30` | `resourceCost` | none | `this` in `ecx`, `TechnologyItem*` |

The PDB also contains compiler-generated scalar deleting destructor
`00412C00`, with `__flags` at `+0x4` and `this` in `ecx`. It is not a registry
function or a source body, so it was not changed.

The original decompiler unit at
`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aitchitm.cpp.decomp`
confirms the 11 source procedure boundaries and their call and field-use
roles. The historical notes at
`C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/functions/0041/00412C20.md`
and `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/functions/0041/00412CD0.md`
confirm the by-value `ResourceItem` argument and copy-constructor source role.

The original executable oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
No executable change was claimed. The preserved pre-cleanup build is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`.
Runtime resource inputs are
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` and
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`. These paths were
not extracted because this module has no resource lookup or resource ID.

## Recovered original names

All changed names came from procedure-scoped PDB records. No invented name was
added.

- `00412C20`: `id` to `i`, `name` to `n`, and `cost` to `r`.
- `00412CD0`: `src` to `ti`.
- `00412D90`, `00412DB0`, `00412DD0`, and `00412DF0`: `lhs` to `one` and
  `rhs` to `two`.

The PDB records use the same names and types at the stack offsets used by the
source definitions. No reused stack-slot mapping is uncertain.

## Constants, resources, and comments

No constant changed. No resource ID or resource lookup occurs in this module.
No resource request is needed. No resource file hash or language extraction
applies.

No comment was added. Existing includes, default values, allocation, copy
operations, null check, and destructor behavior remain unchanged.

## Code-generation-sensitive points and risk

The edit changes only parameter identifiers and their uses. It does not change
types, declarations, scopes, storage, evaluation order, calls, literal
semantics, layout, ABI signatures, public symbols, or source order. It does not
add helpers, casts, comments, constants, or assembly.

No shared definition request or unresolved declaration mapping remains.

Compilation, matching, audits, and tests were not run, as required for this
cleanup phase. No compiler, build, matching, audit, test, or game command was
run.
