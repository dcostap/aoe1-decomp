# Source cleanup report: `teffects.cpp`

## Delivery

- Module: `src/teffects.cpp`
- Base commit from `git rev-parse`: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit from `git rev-parse`: `829abf45ec73d95397b05e9a6944f4ca5621d197`
- Report commit from `git rev-parse`: `e76f8f8c7be80a1eeb58af465cd4e35064d0e786`
- Changed files: `src/teffects.cpp`; this report.
- Branch: `cleanup/staging-20260915-241`
- The source commit contains only the assigned source change.
- A follow-up report commit records this report.

The cleanup covers the four configured handwritten functions in `src/teffects.cpp`.
The PDB module also contains the compiler-generated virtual destructor and scalar
deleting destructor. They have no handwritten source owners and were inspected
without source changes.

## Evidence

The original PDB evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
- SHA256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- PDB source: `C:/msdev/work/age1_x1/teffects.cpp`
- PDB object: `.\\Release\\teffects.obj`

The procedure-scoped symbol index is:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The function inventories are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050D460_TRIBE_Effects.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050D4B0_TRIBE_Effects.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050D4D0_do_effect.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/0050D550_do_tech_effect.txt`

The original assembly and decompiler references are:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/teffects.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/teffects.cpp.decomp`

The original executable behavior oracle is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`

The preserved pre-cleanup object is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/teffects.obj`

## Original-name recovery and PDB coverage

Every configured handwritten function has procedure-scoped PDB coverage. Each
record has `this` in `ecx`. The PDB records expose no function-local stack or
static symbols for these four functions.

| VA | Function and size | PDB stack symbols | PDB register symbols | PDB line span |
| --- | --- | --- | --- | --- |
| `0050D460` | `TRIBE_Effects::TRIBE_Effects(int)`, 25 bytes | `infile` `+0x4` (`int`) | `this` (`TRIBE_Effects*`) in `ecx` | 22-23 |
| `0050D4B0` | `TRIBE_Effects::TRIBE_Effects(char*)`, 25 bytes | `effect_file` `+0x4` (`char*`) | `this` (`TRIBE_Effects*`) in `ecx` | 29-30 |
| `0050D4D0` | `TRIBE_Effects::do_effect(short, RGE_Player*)`, 121 bytes | `current_effect` `+0x4` (`short`); `player` `+0x8` (`RGE_Player*`) | `this` (`TRIBE_Effects*`) in `ecx` | 36-77 |
| `0050D550` | `TRIBE_Effects::do_tech_effect(short, RGE_Player*)`, 90 bytes | `current_effect` `+0x4` (`short`); `player` `+0x8` (`RGE_Player*`) | `this` (`TRIBE_Effects*`) in `ecx` | 83-114 |

The same PDB module records these generated destructor procedures:

- `0050D4A0` `TRIBE_Effects::~TRIBE_Effects`: no stack symbols; `this` in
  `ecx`; no handwritten source line records.
- `0050D480` `TRIBE_Effects::\`scalar deleting destructor\'`: `__flags` `+0x4`
  (`unsigned int`); `this` in `ecx`; no handwritten source line records.

The generated destructor procedures have no source changes. The configured
function registry is `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/teffects.cpp.json`.
It lists all four edited procedures as `matching`.

Recovered original names changed in the source are:

- `0050D460`: constructor parameter `param` became `infile`. The PDB records
  `infile` at `+0x4` as `int`. The original assembly passes that value to
  `RGE_Effects::RGE_Effects(int)` at `0050D468`.
- `0050D4B0`: constructor parameter `param` became `effect_file`. The PDB
  records `effect_file` at `+0x4` as `char*`. The original assembly passes that
  value to `RGE_Effects::RGE_Effects(char*)` at `0050D4B8`.
- `0050D4D0`: parameter `param_1` became `current_effect`. The PDB records a
  `short` at `+0x4`. The source passes the same value to the base
  `RGE_Effects::do_effect` call.
- `0050D550`: parameter `tech_id` became `current_effect`. The PDB records a
  `short` at `+0x4`. The caller at `00512861` supplies the technology effect
  index or the `0xD2` fallback.

The existing `player` parameter name in both effect methods also matches the PDB
record at `+0x8` and was left unchanged.

## New descriptive names and unresolved mappings

No new cleanup names were added. Existing source-level inferred names remain:
`index`, `record`, `i`, and `effect`. The PDB has no declaration records for
these locals. The Ghidra listing identifies `local_4` in `0050D4D0` as an
optimized saved-`this` stack home, but it does not map to a source declaration.
The source keeps the existing declarations and does not force a reused register
or stack-slot mapping.

## Constants, resources, and comments

No numeric constant changed. The command tags `0x65` and `0x66` remain numeric.
The original `0050D4D0` and `0050D550` assembly compares the command byte with
`0x65` and then distinguishes `0x66`; `0x66` calls
`TRIBE_Player::tech_abling` with the command amount converted to `long`. The
base `RGE_Effects::do_effect` implementation in `src/effects.cpp` handles
separate command tags `0` through `5`. No shared symbol proves the tribe command
names, so no constant mapping request was made.

The existing `0` argument to `tech_abling`, record field accesses, casts, loop
steps, and literal widths remain unchanged. No resource lookup exists in this
module. No resource DLL, resource ID, override path, or fallback path applies.
No resource mapping request was made.

No source comment was added. The changed identifiers make the existing control
flow clear without a comment that would repeat the code.

## Code generation, type, layout, and symbol review

The source changes rename parameters only. They preserve types, storage,
declaration scope, declaration order, evaluation order, casts, literals,
control flow, function boundaries, call targets, relocations, object layout, and
ABI symbols. The paired header `include/teffects.h` was read but not edited.
The class size remains `0x0C`, as recorded by
`C:/Projects/my_decomps/aoe1_attempt3/inventory/types/dumps/TRIBE_Effects.txt`.

Parameter names in the owner header remain `file`, `path`, and `effect_id`.
The owner of `include/teffects.h` should consider this parameter-name-only
request, based on the PDB records above:

```cpp
TRIBE_Effects(int infile);
TRIBE_Effects(char* effect_file);
virtual void do_effect(short current_effect, RGE_Player* player);
void do_tech_effect(short current_effect, RGE_Player* player);
```

This request does not change any type, signature, layout, or ABI symbol.

## Validation

Compilation, matching, audits, and tests were not run. No build, compiler check,
validation command, game, or runtime harness was run. Evidence inspection and
complete Git diff review were performed only.
