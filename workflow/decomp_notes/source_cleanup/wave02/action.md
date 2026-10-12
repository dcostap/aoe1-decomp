# `src/action.cpp` cleanup report

## Delivery

- Worker slot: 31
- Module: `src/action.cpp`
- PDB source module: `C:\\msdev\\work\\age1_x1\\action.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `f489c45ac572342bc51f5f8d00128efc857a9ba7`
- Changed files in this work:
  - `src/action.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/action.md`
- Header read but not changed: `include/action.h` (owner 04)

The source registry `config/functions/src/action.cpp.json` assigns 29 normal
functions to this module. The source keeps their original order. The registry
marks every assigned function `matching`. No source function was added or
removed.

The inspected function packets are:

- `inventory/functions/0040/00407460_RGE_Action.txt`
- `inventory/functions/0040/004074C0_RGE_Action.txt`
- `inventory/functions/0040/004074F0_RGE_Action.txt`
- `inventory/functions/0040/00407530_setup.txt`
- `inventory/functions/0040/00407680_setup.txt`
- `inventory/functions/0040/004076D0_create_action_list.txt`
- `inventory/functions/0040/00407740_rehook.txt`
- `inventory/functions/0040/00407790_save.txt`
- `inventory/functions/0040/004078D0_type.txt`
- `inventory/functions/0040/004078E0_first_in_stack.txt`
- `inventory/functions/0040/004078F0_stop.txt`
- `inventory/functions/0040/00407900_move_to.txt`
- `inventory/functions/0040/00407910_work.txt`
- `inventory/functions/0040/00407920_attack_response.txt`
- `inventory/functions/0040/00407930_relation_response.txt`
- `inventory/functions/0040/00407940_set_state.txt`
- `inventory/functions/0040/00407950_inside_obj_update.txt`
- `inventory/functions/0040/00407990_idle_update.txt`
- `inventory/functions/0040/004079D0_update.txt`
- `inventory/functions/0040/00407A20_set_target_obj.txt`
- `inventory/functions/0040/00407A90_set_target_obj2.txt`
- `inventory/functions/0040/00407B00_copy_obj.txt`
- `inventory/functions/0040/00407C00_copy_obj_sprites.txt`
- `inventory/functions/0040/00407C10_get_state_name.txt`
- `inventory/functions/0040/00407D30_targetX.txt`
- `inventory/functions/0040/00407D40_targetY.txt`
- `inventory/functions/0040/00407D50_targetZ.txt`
- `inventory/functions/0040/00407D60_subAction.txt`
- `inventory/functions/0040/00407D70_setSubAction.txt`

The scoped PDB evidence hash is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335` for
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The original executable evidence hash is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90` for
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
The preserved pre-cleanup action object hash is
`bf111639aee18fd97f35564d7236dbcebbac6824c78caafe04ec26fa7e07a542` for
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/action.obj`.

## Function coverage and PDB inspection

The PDB names `this` in `ecx` for every normal function below. The stack names
and types were inspected in `scoped_symbols.json`. The function packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0040/` provide the
matching boundaries and original assembly. `DirectSource` is absent in these
packets, so the PDB is the name source.

| VA | Function | PDB inspection result and source action |
| --- | --- | --- |
| `00407460` | `RGE_Action::RGE_Action(int, RGE_Action_Object*, int)` | Stack parameters `infile` (`int`, `+0x4`), `obj_in` (`RGE_Action_Object*`, `+0x8`), and `do_setup` (`int`, `+0xc`). Renamed `mode`, `object`, and `doSetup` to these recovered names. |
| `004074C0` | `RGE_Action::RGE_Action(RGE_Action_Object*, int)` | Stack parameters `obj_in` (`RGE_Action_Object*`, `+0x4`) and `do_setup` (`int`, `+0x8`). Renamed `object` to recovered `obj_in`; `do_setup` already matched. |
| `004074F0` | `RGE_Action::~RGE_Action()` | No stack names. The PDB has only `this` as `RGE_Action*` in `ecx`. No declaration change. |
| `00407530` | `RGE_Action::setup(int, RGE_Action_Object*)` | Stack parameters `infile` (`int`, `+0x4`) and `obj_in` (`RGE_Action_Object*`, `+0x8`); locals `long_val` (`long`, `+0xc`) and `short_val` (`short`, `-0x4`). Renamed `param_1`, `param_2`, and `int_val` to the recovered PDB names. The source keeps the existing `int` type for the 32-bit `long_val` storage. |
| `00407680` | `RGE_Action::setup(RGE_Action_Object*)` | Stack parameter `obj_in` (`RGE_Action_Object*`, `+0x4`). Renamed `action_object` to recovered `obj_in`. |
| `004076D0` | `RGE_Action::create_action_list(RGE_Action_Object*)` | Stack parameter `obj_in` (`RGE_Action_Object*`, `+0x4`). Added the recovered name to the definition. The parameter remains unused. |
| `00407740` | `RGE_Action::rehook()` | No stack names. The PDB has only `this` as `RGE_Action*` in `ecx`. No declaration change. |
| `00407790` | `RGE_Action::save(int)` | Stack parameter `outfile` (`int`, `+0x4`); locals `long_val` (`long`, `+0x8`) and `short_val` (`short`, `-0x4`). Renamed `param_1`, `id_write`, and `short_write` to the recovered PDB names. |
| `004078D0` | `RGE_Action::type()` | No stack names. The PDB has only `this` as `RGE_Action*` in `ecx`. No declaration change. |
| `004078E0` | `RGE_Action::first_in_stack(unsigned char)` | Stack parameter `first_time` (`unsigned char`, `+0x4`). Added the recovered name to the unused parameter. |
| `004078F0` | `RGE_Action::stop()` | No stack names. The PDB has only `this` as `RGE_Action*` in `ecx`. No declaration change. |
| `00407900` | `RGE_Action::move_to(RGE_Static_Object*, float, float, float)` | Stack parameters `obj_in` (`RGE_Static_Object*`, `+0x4`), `x`, `y`, and `z` (`float`, `+0x8`, `+0xc`, `+0x10`). Added all recovered names to the unused parameters. |
| `00407910` | `RGE_Action::work(RGE_Static_Object*, float, float, float)` | Stack parameters `obj_in` (`RGE_Static_Object*`, `+0x4`), `x`, `y`, and `z` (`float`, `+0x8`, `+0xc`, `+0x10`). Added all recovered names to the unused parameters. |
| `00407920` | `RGE_Action::attack_response(RGE_Static_Object*)` | Stack parameter `obj_in` (`RGE_Static_Object*`, `+0x4`). Added the recovered name to the unused parameter. |
| `00407930` | `RGE_Action::relation_response(long, unsigned char)` | Stack parameters `player_id` (`long`, `+0x4`) and `relation` (`unsigned char`, `+0x8`). Added the recovered names to the unused parameters. |
| `00407940` | `RGE_Action::set_state(unsigned char)` | Stack parameter `new_state` (`unsigned char`, `+0x4`). Renamed `param_1` to recovered `new_state`. |
| `00407950` | `RGE_Action::inside_obj_update()` | No stack names. The PDB has only `this` as `RGE_Action*` in `ecx`. No declaration change. |
| `00407990` | `RGE_Action::idle_update()` | No stack names. The PDB has only `this` as `RGE_Action*` in `ecx`. No declaration change. |
| `004079D0` | `RGE_Action::update()` | No stack names. The PDB has only `this` as `RGE_Action*` in `ecx`. No declaration change. |
| `00407A20` | `RGE_Action::set_target_obj(RGE_Static_Object*)` | Stack parameter `new_obj` (`RGE_Static_Object*`, `+0x4`). Renamed `param_1` to recovered `new_obj` at every use. |
| `00407A90` | `RGE_Action::set_target_obj2(RGE_Static_Object*)` | Stack parameter `new_obj` (`RGE_Static_Object*`, `+0x4`). Renamed `target` to recovered `new_obj` at every use. |
| `00407B00` | `RGE_Action::copy_obj(RGE_Master_Action_Object*)` | Stack parameter `source` (`RGE_Master_Action_Object*`, `+0x4`) and local `new_sprite` (`RGE_Sprite*`, `-0x4`). Renamed `param_1` to recovered `source`; the existing `new_sprite` matches the PDB. |
| `00407C00` | `RGE_Action::copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*)` | Stack parameters `source`, `task`, and `new_task` at `+0x4`, `+0x8`, and `+0xc`, all with the PDB pointer types. Added the recovered names to the empty definition. |
| `00407C10` | `RGE_Action::get_state_name(char*)` | Stack parameter `state_name` (`char*`, `+0x4`). Renamed `buf` to recovered `state_name` at every use. |
| `00407D30` | `RGE_Action::targetX() const` | No stack names. The PDB records `this` as `const RGE_Action*` in `ecx`. No declaration change. |
| `00407D40` | `RGE_Action::targetY() const` | No stack names. The PDB records `this` as `const RGE_Action*` in `ecx`. No declaration change. |
| `00407D50` | `RGE_Action::targetZ() const` | No stack names. The PDB records `this` as `const RGE_Action*` in `ecx`. No declaration change. |
| `00407D60` | `RGE_Action::subAction() const` | No stack names. The PDB records `this` as `const RGE_Action*` in `ecx`. No declaration change. |
| `00407D70` | `RGE_Action::setSubAction(unsigned char)` | Stack parameter `v` (`unsigned char`, `+0x4`). Renamed `param_1` to recovered `v`. |

The PDB also contains the compiler-generated scalar deleting destructor at
`004074A0`. It has stack parameter `__flags` (`unsigned int`, `+0x4`) and
`this` as `RGE_Action*` in `ecx`. It has no handwritten source owner and was
not edited. The registry does not list it as a normal source function. No
vector-deleting destructor or default-constructor body is assigned to this
source module.

All changed names in the source are recovered PDB names. No invented local or
parameter names were added. Existing non-PDB names remain unchanged, including
`action_list`, `action_master`, `task_list`, `previous`, `world`, `old_target`,
`task_array`, and `i`. Their storage and scope mappings are not forced because
the scoped PDB has no corresponding records. The PDB `new_sprite` local in
`copy_obj` is the one recovered local with that spelling.

## Constants, resources, and comments

No constant or enum replacement was made. Existing values remain because no
shared declaration proves a safer name and type for this module:

- `-1` is the serialized null sentinel for target, task, and sprite records.
- `0` and `1` are the base action state and completion result values.
- `7` is the existing object-state cutoff used when clearing dead targets.
- `0` through `15` are the state-name switch values. The strings in the
  `get_state_name` body are unchanged.
- The `1`, `2`, and `4` read and write lengths are part of the serialized action
  record. The original packets show these widths at `00407530` and `00407790`.
- The existing `+0xD8` comment is supported by the `00407530` assembly read
  through the action-master task pointer and by the reviewed action-master
  layout. The comment was retained, not added.

`src/action.cpp` has no resource lookup or resource-ID expression. No resource
extraction was needed. Therefore there are no per-ID text, missing-block, or
empty-slot findings; no language or lookup path applies; and no cleanup resource
name or resource-ID header request is proposed. The runtime resource files were
not used for this module.

No new source comment was added. Existing comments remain sparse and factual.

## Risk, header request, and unresolved questions

The source changes rename parameters and locals, add names to unused parameters,
and move function opening braces to 1TBS form. They do not change types, storage,
scope, declaration order, evaluation order, calls, casts, literals, layouts,
virtual order, or ABI symbols. The `long_val` declarations retain their prior
32-bit `int` type even though the PDB displays the recovered local as `long`.
No structural decompiler rewrite was attempted. Compilation is deferred, so
machine-code and debug-line effects remain unvalidated.

Owner 04 should consider this matching declaration-name request for
`include/action.h`; the request does not change ABI or layout:

```cpp
RGE_Action(int infile, RGE_Action_Object* obj_in, int do_setup);
RGE_Action(RGE_Action_Object* obj_in, int do_setup);
virtual int setup(RGE_Action_Object* obj_in);
virtual int setup(int infile, RGE_Action_Object* obj_in);
virtual RGE_Action_List* create_action_list(RGE_Action_Object* obj_in);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
virtual unsigned char attack_response(RGE_Static_Object* obj_in);
virtual unsigned char relation_response(long player_id, unsigned char relation);
virtual void copy_obj(RGE_Master_Action_Object* source);
virtual void copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task,
                              RGE_Task* new_task);
virtual void get_state_name(char* state_name);
virtual void set_target_obj(RGE_Static_Object* new_obj);
virtual void set_target_obj2(RGE_Static_Object* new_obj);
protected:
virtual void set_state(unsigned char new_state);
unsigned char subAction() const;
void setSubAction(unsigned char v);
```

No root-owned shared declaration or resource-ID request is open. The only
unresolved declaration mappings are the existing non-PDB local names listed
above and the PDB `long` display versus the preserved source `int` spelling.

Compilation, matching, audits, and tests were not run.
