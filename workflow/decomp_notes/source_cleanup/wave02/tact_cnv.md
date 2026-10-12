# `src/tact_cnv.cpp` source-cleanup report

## Delivery

- Module: `src/tact_cnv.cpp`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Final source commit: `856c7639628abbcb88d4588eace823db8291387b`.
- Changed files:
  - `src/tact_cnv.cpp`.
  - `workflow/decomp_notes/source_cleanup/wave02/tact_cnv.md`.
- Branch: `cleanup/staging-20260915-40`.
- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tact_cnv.cpp.json`.
- Registry build flags: `gx`.
- Header read but not changed: `include/tact_cnv.h`.
- PDB source path: `C:\msdev\work\age1_x1\tact_cnv.cpp`.

The source commit restores procedure-scoped PDB parameter names. It also moves
function opening braces to 1TBS form. It keeps types, scopes, storage,
expressions, calls, source order, and public symbols unchanged.

## Evidence checked

I inspected every registry function packet for this module:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CD9E0_TRIBE_Action_Convert.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CDA90_TRIBE_Action_Convert.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CDB20_TRIBE_Action_Convert.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CDB70_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CDBB0_first_in_stack.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CDE10_set_state.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE070_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE450_work.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CE4B0_martyrdom.txt`

The procedure-scoped records were checked in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The source and original assembly evidence were also checked in:

- `C:/Projects/my_decomps/aoe1_attempt3/src/tact_cnv.cpp`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tact_cnv.cpp.asm`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tact_cnv.cpp.decomp`.

The original executable remains the behavior oracle. Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.

The preserved pre-cleanup build was inspected for source comparison evidence.
Its hashes are:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`:
  `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tact_cnv.obj`:
  `ee8e198e6913b5a601ebdc9ffa09be28f3658920d187988d4eb90cc9e93da494`.

## Correction history

- Initial source cleanup: `caa1e8769bd0dea848c574d9f1953d83157a1cc1`.
- Initial cleanup report: `5c57e486e72cb042de9cda6c8c75a9259493ba5b`.
- Source signature formatting correction: `856c7639628abbcb88d4588eace823db8291387b`.
- This report correction follows the source formatting correction.

## Original-name coverage

All nine registry functions were inspected. The PDB records `this` in `ecx`
as `TRIBE_Action_Convert*` for each one. The source-function PDB records have
no function statics or local symbols.

| VA | Function | PDB stack names and source result |
| --- | --- | --- |
| `004CD9E0` | File constructor | `infile` (`int`, `+0x4`) and `obj_in` (`RGE_Action_Object*`, `+0x8`). Both names now appear in the source. |
| `004CDA90` | Object-target constructor | `obj_in` (`RGE_Action_Object*`, `+0x4`), `task_in` (`RGE_Task*`, `+0x8`), and `target_obj_in` (`RGE_Static_Object*`, `+0xc`). All three names now appear in the source. |
| `004CDB20` | Position-target constructor | `obj_in` (`RGE_Action_Object*`), `task_in` (`RGE_Task*`), `x`, `y`, and `z` (`float`) at `+0x4` through `+0x14`. All names now appear in the source. |
| `004CDB70` | `save` | `outfile` (`int`, `+0x4`). The source now uses `outfile`. |
| `004CDBB0` | `first_in_stack` | `first_time` (`unsigned char`, `+0x4`). The source now uses `first_time`. |
| `004CDE10` | `set_state` | `new_state` (`unsigned char`, `+0x4`). The source now uses `new_state`. |
| `004CE070` | `update` | No stack names. The parameterless source signature remains unchanged. |
| `004CE450` | `work` | `obj_in` (`RGE_Static_Object*`, `+0x4`) and `x`, `y`, `z` (`float`) at `+0x8` through `+0x10`. All names now appear in the source. |
| `004CE4B0` | `martyrdom` | No stack names. The parameterless source signature remains unchanged. |

The PDB also records two compiler-generated functions in this object:

- `004CDA60`, the deleting destructor, has `__flags` (`unsigned int`, `+0x4`)
  and `this` in `ecx`.
- `004CDA80`, the destructor, has only `this` in `ecx`.

These generated functions have no standalone source bodies and are not in the
source registry. I did not edit them.

### Renamed parameters

The source changes use these exact PDB spellings:

- `004CD9E0`: `file` -> `infile`; `object` -> `obj_in`.
- `004CDA90`: `object` -> `obj_in`; `task` -> `task_in`; `target` -> `target_obj_in`.
- `004CDB20`: `object` -> `obj_in`; `task` -> `task_in`.
- `004CDB70`: `file` -> `outfile`.
- `004CDBB0`: `param_1` -> `first_time`.
- `004CDE10`: `param_1` -> `new_state`.
- `004CE450`: `target` -> `obj_in`; the three unnamed `float` parameters are
  now named `x`, `y`, and `z`.

The position-target constructor already used `x`, `y`, and `z`. The PDB proves
those names and their `float` types. The `work` coordinates remain unused.

## Locals and unresolved mappings

The PDB has no procedure-scoped local records for the nine source functions.
The register records contain only `this`. The source keeps its existing local
names. These names are not presented as recovered originals:

- `004CDBB0`: `target`, `object_group`, `object`, and `target_id`.
- `004CDE10`: the two scoped `action` pointer declarations.
- `004CE070`: `r`, `chance`, `tplayer`, and `type`.
- `004CE450`: `state`.
- `004CE4B0`: `target_id` and `source_id`.

The Ghidra packets show reused exception-cleanup slots and optimized register
carriers such as `local_4`, `local_c`, `iVar*`, and `pRVar*`. They do not prove
source local names. I did not force any mapping from those slots. No invented
local name was added.

## Constants, resources, and comments

No numeric constant, macro, enum, or resource ID changed. The source retains
opaque values for the action type, action states, notification codes, object
groups, attribute indexes, object ID, and conversion chance path. The original
assembly packets prove their values and call positions, but no existing shared
symbol proves their roles for this module.

The module makes no direct resource-file lookup. It sends the existing
notification IDs `0x76` through `0x7a` through `rge_base_game->notification`.
The Ghidra packets annotate language matches for these IDs. No new resource
mapping was needed, and no language DLL extraction was performed. The runtime
files were not inspected:

- `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`.
- `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`.

No source comment was added or changed. The existing comment about preserving
the original x87 evaluation order remains in `update`.

## Type, layout, and symbol review

The edits rename parameters and move function opening braces. They do not
change parameter types, declarations, scopes, storage duration, member layout,
expression order, casts, calls, virtual slots, function boundaries, public
symbols, relocations, or runtime data by source inspection.

The new `work` parameter names do not add a read or write. The existing
`requiredRange` and `was_same_owner` fields remain unchanged. No inline
assembly, helper, wrapper, structural rewrite, or layout change was added.

Opening-brace moves can change debug line records. No compiler result is
available to assess that effect. The source commit does not claim byte equality.

## Header request

I did not edit `include/tact_cnv.h`. Owner 05 owns that header. The owner may
add these PDB-proven names without changing types, order, or ABI:

```cpp
TRIBE_Action_Convert(int infile, RGE_Action_Object* obj_in);
TRIBE_Action_Convert(RGE_Action_Object* obj_in, RGE_Task* task_in,
                     RGE_Static_Object* target_obj_in);
TRIBE_Action_Convert(RGE_Action_Object* obj_in, RGE_Task* task_in,
                     float x, float y, float z);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
virtual void set_state(unsigned char new_state);
```

The natural source owner for the current related call sites is
`src/t_c_obj.cpp`. `TRIBE_Combat_Object::convert` constructs the action, and
`RGE_Static_Object::die_die_die` calls `martyrdom`. No line references are
included because the source line mapping is not stable evidence.

The original call packets are
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CB1B0_convert.txt`
and
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/004CA790_die_die_die.txt`.
Both packets correspond to `src/t_c_obj.cpp`. The latter calls `martyrdom`;
the source declaration has no parameters to name.

No other header request exists. No resource declaration request exists.

## Risk and validation

The source changes are limited to PDB-proven identifier recovery and 1TBS
function-brace formatting. They do not change a type, layout, ABI symbol,
call target, relocation, or executable statement by source inspection.
Parameter names and line formatting can affect debug metadata. The required
compiler comparison remains open.

I reviewed the complete source diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run. No build, game, or
runtime harness command was run.
