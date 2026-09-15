# `tact_mob.cpp` source-cleanup report

## Commits and scope

- Module: `src/tact_mob.cpp`.
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Initial source cleanup commit from `git rev-parse`: `0b7483156fe27d2b1cd99563ed4f9683d981e7c2`.
- Initial report commit from `git rev-parse`: `32b47ecab6a9c2cd5a536ac93825f12c00dae410`.
- Constructor-brace correction commit from `git rev-parse`: `1b504117b115d37b2b96a9e384df681b78a88684`.
- Signature-formatting correction commit from `git rev-parse`: `961f50326cbd0f18f95f33ae680c98bd84c4d48b`.
- The report correction commit follows the signature-formatting correction commit.
- Commit history: base, source cleanup, initial report, constructor-brace
  correction, signature-formatting correction, report correction.
- Changed files in this delivery: `src/tact_mob.cpp` and this report.
- Branch: `cleanup/staging-20260915-44`.
- Header read but not changed: `include/tact_mob.h`.
- Registry: `config/functions/src/tact_mob.cpp.json`, build flags `gx`.

The source keeps all ten normal registry functions in source order. It keeps
all function symbols, types, scopes, storage, calls, expressions, and data.
The nearby vector-deleting destructor at `004D0E90` is compiler generated and
has no standalone source body.

## Evidence

The PDB source path is `C:\msdev\work\age1_x1\tact_mob.cpp`.
I inspected every registry function in the procedure-scoped PDB file:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

Its SHA-256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

I inspected these complete function packets:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D0DD0_TRIBE_Action_Make_Obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D0EB0_TRIBE_Action_Make_Obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D0EF0_TRIBE_Action_Make_Obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D0F70_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D0FC0_first_in_stack.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D10E0_set_state.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D10F0_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D12B0_place_obj.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D1550_stop.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/004D15F0_get_info.txt`

The original executable remains the behavior oracle:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The preserved pre-cleanup object is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tact_mob.obj`

Its SHA-256 is
`02a0f2ee25a5dd079f6f4d861dda2eb4f54ea5f24e08f0e8da7feabe114d2421`.

## Original-name recovery coverage

All ten assigned functions have a PDB `this` register record in `ecx`.
The table lists every PDB stack symbol for each assigned function.

| VA | Function | PDB stack symbols | Source coverage |
| --- | --- | --- | --- |
| `004D0DD0` | load constructor | `infile` `+0x4`; `obj_in` `+0x8` | Both parameters restored. |
| `004D0EB0` | value constructor | `obj_in` `+0x4`; `id` `+0x8`; `uniqueID` `+0xc`; `paid` `+0x10` | All four parameters restored. |
| `004D0EF0` | destructor | none | The PDB has only `this`. |
| `004D0F70` | `save` | `outfile` `+0x4` | The parameter `handle` became `outfile`. |
| `004D0FC0` | `first_in_stack` | `first_time` `+0x4` | The parameter `param_1` became `first_time`. |
| `004D10E0` | `set_state` | `new_state` `+0x4` | The parameter `v` became `new_state`. |
| `004D10F0` | `update` | `newObject` `-0x4` | The existing `newObject` declaration already matches the PDB. |
| `004D12B0` | `place_obj` | `rObj` `+0x4`; `radius_2x` `-0x10`; `radius_y` `-0x14`; `index` `-0x8`; `radius_2y` `-0xc`; `radius_x` `-0x18` | The parameter `out` became `rObj`. The five recorded locals were restored. |
| `004D1550` | `stop` | none | The PDB has only `this`. |
| `004D15F0` | `get_info` | `id` `+0x4`; `progress` `+0x8`; `name` `+0xc`; `name_size` `+0x10` | All four parameters restored. |

The recovered spellings preserve the PDB styles. In particular, `uniqueID`
and `rObj` retain their mixed-case spelling.

The source changes these identifiers:

- `004D0DD0`: `param_1` became `infile`; `param_2` became `obj_in`.
- `004D0EB0`: `obj` became `obj_in`; `obj_id` became `id`;
  `unique_id` became `uniqueID`; `pre_paid` became `paid`.
- `004D0F70`: `handle` became `outfile`.
- `004D0FC0`: `param_1` became `first_time`.
- `004D10E0`: `v` became `new_state`.
- `004D12B0`: `out` became `rObj`; `expand` became `index`; `rx` became
  `radius_x`; `ry` became `radius_y`; `r2x` became `radius_2x`; and `r2y`
  became `radius_2y`.
- `004D15F0`: `param_1` became `id`; `param_2` became `progress`;
  `param_3` became `name`; and `param_4` became `name_size`.

The source already used the PDB name `newObject` at `004D10F0`.
No PDB-recorded parameter or local remains unresolved.

## Locals and unresolved mappings

The PDB has no records for these existing locals:
`player`, `paid` in `first_in_stack`, `master`, `needed_obj`, `needed_player`,
`needed`, `proto`, `tries`, `dir`, `divisor`, `pc`, and `info`.
I did not force names without a procedure-scoped record. These names predate
this cleanup and remain descriptive source names. No new local was added.

The `004D12B0` PDB records map the radius locals by their stack homes and by
their use in the original packet. The source keeps their separate `float`
declarations and their existing declaration order. It does not combine them.
The `004D10F0` `newObject` local remains in its existing scope.

The scalar deleting destructor at `004D0E90` has PDB stack symbol `__flags` at
`+0x4` and register symbol `this` in `ecx`. It is compiler generated. It has
no handwritten source mapping.

## Constants, resources, and comments

No numeric constant changed. No constant, enum, or resource macro was added.
This module has no string-resource lookup. No resource ID mapping is needed.
The values for action type, state, notifications, file sizes, random offsets,
and floating-point factors remain unchanged.

No source comment was added. Existing comments remain. They explain the x87
work-rate order, placement retry and publication behavior, owner reloads, and
the `get_info` lookup order. No comment claims new byte equality.

## Header request

Owner 05 owns `include/tact_mob.h`. The header remains unchanged.
The owner may add these PDB-proven names without changing types or ABI:

```cpp
TRIBE_Action_Make_Obj(int infile, RGE_Action_Object* obj_in);
TRIBE_Action_Make_Obj(RGE_Action_Object* obj_in, short id, int uniqueID, uchar paid);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
uchar place_obj(RGE_Static_Object** rObj);
void get_info(short& id, short& progress, char* name, short name_size);
```

`update()` and `stop()` have no parameters to name. No root-owned shared-header
or resource-ID request is open.

## Code generation and risk notes

The edits rename parameters and locals, move five function braces to 1TBS form,
and join the value-constructor parameter list onto one line. The two constructor
braces now share their initializer-list lines. The full source has no other
function-definition brace on a separate line. These edits do not change types,
declaration scope, storage, evaluation order,
control flow, calls, literals, relocations, function boundaries, or ABI symbols.
The value-constructor initializer still passes the same object. The placement
radius expressions and output store keep their original order.

Identifier names do not affect executable code. Brace movement can change debug
line records, but debug metadata is outside the executable code and data review.
The registry statuses remain the existing claims. This report does not promote
or revalidate any status.

## Validation

I ran `git diff --check` before the brace correction and reviewed the complete
source diff. After each correction, I reviewed the correction diff and the full
cumulative source diff with Git.
Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime harness was run.
