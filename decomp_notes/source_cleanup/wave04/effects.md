# Source cleanup report: `effects.cpp`

## Delivery

- Module: `src/effects.cpp`
- Base commit from `git rev-parse`: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit from `git rev-parse`: `956b86418ac3abc0bfc54e730ba1cb6a02d8521f`
- Changed files: `src/effects.cpp`; this report.
- Branch: `cleanup/staging-20260915-234`
- The source commit contains only the assigned source change.
- The report commit follows the source commit.

The cleanup covers all five handwritten registry functions in `src/effects.cpp`.
The PDB module also contains the compiler-generated scalar deleting destructor at
`00449240`. It has no handwritten source owner and was inspected without source
changes.

## Evidence

The original PDB module stream was extracted from:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
- PDB SHA256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`

The extraction used the pinned `cvdump.exe` and wrote evidence only under this
worktree's `build/` directory:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-234/build/pdb-effects/module_streams/00A4_effects.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-234/build/pdb-effects/module_streams/00A4_effects.json`

The module stream is PDB module `00A4` and object `Release/effects.obj`. The
scoped records contain six procedures, 13 stack symbols, and six `this` register
records. The original assembly and decompiler evidence were also inspected at:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/effects.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/effects.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/classes/dumps/RGE_Effects.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/effects.cpp.json`

The original executable behavior oracle is the configured file:
`C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`.

## Original-name recovery and PDB coverage

Every handwritten function has complete procedure-scoped PDB coverage below.
Each function has a `this` record in `ecx`.

| VA | Function and size | PDB stack symbols | PDB register symbols |
| --- | --- | --- | --- |
| `004490E0` | `RGE_Effects::RGE_Effects(int)`, 352 bytes | `infile` `+0x4` (`int`); `index` `-0x10` (`int`) | `this` (`RGE_Effects*`) in `ecx` |
| `00449240` | compiler-generated scalar deleting destructor, 30 bytes | `__flags` `+0x4` (`unsigned int`) | `this` (`RGE_Effects*`) in `ecx` |
| `00449260` | `RGE_Effects::RGE_Effects(char*)`, 478 bytes | `effect_file` `+0x4` (`char*`); `index` `-0x8` (`long`); `this_effect_num` `-0xc` (`long`); `count` `-0x4` (`long`); `effect_command` `+0x8` (`short`) | `this` (`RGE_Effects*`) in `ecx` |
| `00449440` | `RGE_Effects::~RGE_Effects()`, 99 bytes | none | `this` (`RGE_Effects*`) in `ecx` |
| `004494B0` | `RGE_Effects::save(int)`, 265 bytes | `outfile` `+0x4` (`int`); `index` `-0x14` (`int`) | `this` (`RGE_Effects*`) in `ecx` |
| `004495C0` | `RGE_Effects::do_effect(short, RGE_Player*)`, 328 bytes | `current_effect` `+0x4` (`short`); `player` `+0x8` (`RGE_Player*`); `amount` `+0x8` (`float`) | `this` (`RGE_Effects*`) in `ecx` |

The PDB has one unnamed `S_LDATA32` record in `do_effect` at `004486F0`.
It does not provide a source local name and remains unchanged.

Recovered original names are:

- `004490E0`: parameter `fd` became `infile`; local `outer_count` became `index`.
- `00449260`: parameter `path` became `effect_file`.
- `004494B0`: parameter `fd` became `outfile`.
- `004495C0`: parameter `effect_id` became `current_effect`.

The existing `count`, `index`, `this_effect_num`, and `effect_command` names in
the text constructor already match the PDB records. The existing `player` and
`amount` names in `do_effect` also match PDB records.

## New descriptive names and unresolved mappings

These names have no direct PDB declaration record. They are new cleanup names,
not recovered original names. They use `snake_case` and retain the original
types, scopes, storage, and declaration order:

- The binary constructor uses `file` as `input_file`, `peffect` as
  `effect_num_ptr`, `effect` as `base_effect`, `fields` as `effect_record`,
  `inner_count` as `command_index`, and `list` as `effect_list`.
- The text constructor uses `sVar7` as `command_index`.
- The destructor uses `i` as `effect_index`.
- `save` uses `num` as `effect_num_ptr`, `handle` as `output_file`, and
  `inner` as `command_index`.
- `do_effect` uses `eff` as `effect`, `i` as `command_index`, and `cmd` as
  `command`.

The PDB does not name the aliases or optimized locals listed above. Their names
come from their direct uses and pointer roles. No stack home was reassigned.
The PDB maps `player` and `amount` to the same `+0x8` stack offset in
`do_effect`; the source keeps the separate parameter and block-local
`float amount` declarations. No reused stack-slot mapping was forced.

## Constants, resources, and comments

No numeric constant changed. No new constant, enum, macro, or resource ID was
added. The existing `0x1F`, `0x2C`, and `0x0C` values remain unchanged. The
record sizes are supported by `include/effects.h`,
`inventory/classes/dumps/RGE_Effects.txt`, and the original assembly's byte
reads and writes. Command tags `0` through `5` remain numeric because no shared
symbol with a proved meaning was found.

This module has no resource lookup. No resource DLL was inspected, no resource
ID mapping is proposed, and no request for `include/resource_ids.h` exists.

No source comment was added. The existing constructor comment remains because
the original assembly reads the first record name through the base pointer while
it reads the indexed record's list fields. This is a useful compatibility note.

## Code generation, type, layout, and symbol review

The source changes rename identifiers only. They do not change types, storage,
declaration scope, declaration order, evaluation order, casts, literals, control
flow, function boundaries, call targets, relocations, layouts, or ABI symbols.
The paired header remains unchanged. No inline assembly, wrapper, helper, or
structural rewrite was added.

The constructors remain `accepted_drift`, and the destructor, `save`, and
`do_effect` statuses remain as recorded in the function registry. This report
does not claim byte equality or validation.

## Header requests

The paired header `include/effects.h` was read but not edited. Its owner should
rename only these declaration parameters to match the recovered source names:

```cpp
RGE_Effects(int infile);
RGE_Effects(char* effect_file);
virtual void save(int outfile);
virtual void do_effect(short current_effect, RGE_Player* player);
```

These are parameter-name requests only. They do not change types, signatures, or
ABI. No request exists for root-owned headers or shared resource declarations.

## Validation

Compilation, matching, audits, and tests were not run. No build, compiler check,
game, or runtime harness was run. Only PDB and original-binary evidence
inspection, source diff review, and `git diff --check` were run.
