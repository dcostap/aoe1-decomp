# `src/aitrdmod.cpp` cleanup report

## Delivery

- Module: `src/aitrdmod.cpp`
- Base commit from `git rev-parse`: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit from `git rev-parse`: `2ba87390363cc6f74aa92940d83e2f8a4712151c`
- Branch: `cleanup/staging-20260915-113`
- Changed files:
  - `src/aitrdmod.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/aitrdmod.md`
- Header read but not changed: `include/aitrdmod.h`

The source keeps the registry order for all five normal owners. The PDB source
module is `C:\\msdev\\work\\age1_x1\\aitrdmod.cpp`.

## Evidence

The source registry was read from:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/aitrdmod.cpp.json`

The procedure-scoped PDB records were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The registry-selected original function packets were read from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/00412E40_TradeAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/00412EA0_TradeAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/00412ED0_TradeAIModule.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/00412EE0_setMainDecisionAI.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0041/00412EF0_save.txt`

The decompiler and assembly unit records were also read from:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aitrdmod.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/aitrdmod.cpp.asm`

The original executable is the behavior oracle:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup executable is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## Original-name recovery coverage

All five source functions were inspected in the scoped PDB records. Each
record has the expected `this` register in `ecx`. No source function has a
PDB function-static or local record beyond the listed parameters.

| VA | Function | PDB stack records | Source result |
| --- | --- | --- | --- |
| `00412E40` | first constructor | `pW` (`void*`, `+0x4`), `playerID` (`int`, `+0x8`) | Recovered both names. |
| `00412EA0` | second constructor | `playerID` (`int`, `+0x4`), `infile` (`int`, `+0x8`) | Recovered both names. |
| `00412ED0` | destructor | none | No source parameter or local to rename. |
| `00412EE0` | `setMainDecisionAI` | `m` (`MainDecisionAIModule*`, `+0x4`) | Recovered `m`. |
| `00412EF0` | `save` | `outfile` (`int`, `+0x4`) | Recovered `outfile`. |

The PDB also records the compiler-generated scalar deleting destructor at
`00412E80`. It has `this` in `ecx` and `__flags` (`unsigned int`, `+0x4`). It
has no standalone source body in this module and was not edited.

Renames in `src/aitrdmod.cpp` are recovered originals, not invented names:

- `ptr` to `pW` and `player` to `playerID` in the `00412E40` constructor.
- `player` to `playerID` and `unused` to `infile` in the `00412EA0` constructor.
- `module` to `m` in `setMainDecisionAI`.
- `unused` to `outfile` in `save`.

The PDB records establish these spellings even when `infile` and `outfile`
are not read by their function bodies. No reused stack-slot mapping was
forced. No invented parameter or local name was added.

## Constants, resources, and comments

No numeric constant changed. The constructor keeps the original module ID
`0x3F2`, null initializers `0`, and `save` result `1`. The reviewed
`include/aimodule.h` does not provide a verified symbol for `0x3F2` in this
context, so the literal remains unchanged.

This source has no resource lookup and no resource ID. No runtime DLL was
inspected because this module does not read a resource. No shared resource
mapping request exists.

No source comment was added. No existing source comment was changed.

## Header request and unresolved mappings

The owner of `include/aitrdmod.h` may align declaration parameter names with
these PDB records without changing types or ABI symbols:

```cpp
TradeAIModule(void* pW, int playerID);
TradeAIModule(int playerID, int infile);
void setMainDecisionAI(MainDecisionAIModule* m);
virtual int save(int outfile);
```

The header remains valid without this spelling update. No root-owned header
request exists. No declaration type, layout, or scope mapping is unresolved.

## Code-generation risks and validation

The source edits rename parameters and move opening braces to 1TBS positions.
They do not change types, casts, declarations, scopes, storage, evaluation
order, calls, literals, function boundaries, layout, relocations, or ABI
symbols. The renamed `infile` and `outfile` remain unused, as in the original
source behavior. Generated output and debug line records were not checked.

The complete assigned diff was reviewed. `git diff --check` passed before the
source commit.

Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or runtime harness was run.
