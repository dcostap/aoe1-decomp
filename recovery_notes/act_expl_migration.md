# act_expl.cpp source-module recovery packet

## Result

The PDB source is
`C:\\msdev\\work\\age1_x1\\act_expl.cpp`.

The natural owner closure is complete. `include/act_expl.h` owns
`RGE_Action_Explore`, and commit `f7f784d3a` publishes the canonical public
`RGE_Master_Moving_Object::move_sprite` field.

The source no longer uses `include/act_expl_context.h`, a local carrier, or a
function-fragment include. Direct metadata now points all six normal owners at
`src/act_expl.cpp`.

The grouped candidate reports all six normal owners as `MATCH` with `0.0000%`
difference, zero relocation mismatches, and zero boundary escapes. Both
compiler-generated destructors also report `MATCH` with zero difference.

## PDB source order and boundaries

Normal owners, in PDB and source order, are:

1. `00402B40` `RGE_Action_Explore::RGE_Action_Explore(int,
   RGE_Action_Object*)`, 40 bytes, lines 36-38.
2. `00402BA0` `RGE_Action_Explore::RGE_Action_Explore(RGE_Action_Object*,
   RGE_Task*, float, float, float)`, 61 bytes, lines 46-56.
3. `00402BE0` `RGE_Action_Explore::first_in_stack(unsigned char)`, 29 bytes,
   lines 62-67.
4. `00402C00` `RGE_Action_Explore::set_state(unsigned char)`, 359 bytes,
   lines 73-133.
5. `00402D90` `RGE_Action_Explore::update()`, 150 bytes, lines 139-220.
6. `00402E40` `RGE_Action_Explore::work(RGE_Static_Object*, float, float,
   float)`, 85 bytes, lines 227-240.

The PDB line bands and address sequence prove one compiler-facing module. The
sequence also contains these non-normal ranges:

- `00402B70-00402B8D` is the compiler-generated scalar deleting destructor.
  It has no PDB source owner. Its class owner is `RGE_Action_Explore`.
- `00402B90-00402B94` is the generated virtual destructor tail. It has no PDB
  source owner and jumps to `RGE_Action::~RGE_Action` at `004074F0`.
- `00402E26-00402E27` is reviewed padding-only data. The update jump table is
  at `00402E28-00402E3C`. Neither range is a source owner.

The source module owns the six normal functions in this order. The two
generated destructors remain compiler-generated entries. The padding entry
remains config-only and has no source owner.

## Direct and virtual call ownership

Direct calls from `act_expl.cpp` have these proven owners:

- `00402B40` calls `00407460`, `RGE_Action::RGE_Action(int,
  RGE_Action_Object*, int)`, owned by `action.cpp`.
- `00402BA0` calls `004074C0`, `RGE_Action::RGE_Action(RGE_Action_Object*,
  int)`, owned by `action.cpp`.
- `00402C00` calls `00403FA0`, `RGE_Action_List::delete_list()`, owned by
  `act_list.cpp`.
- `00402C00` calls `004055A0`, the six-argument
  `RGE_Action_Move_To` constructor, owned by `act_move.cpp`.
- `00402C00` calls `00407D70`, `RGE_Action::setSubAction(unsigned char)`,
  owned by `action.cpp`.
- `00402C00` calls `00404540`, `RGE_Action_List::add_action(RGE_Action*)`,
  owned by `act_list.cpp`.
- `00402B70` calls the generated `00402B90` destructor and `operator delete`.

The required indirect slots are:

- `RGE_Action::set_target_obj` at vtable `+0x54`.
- `RGE_Action::set_target_obj2` at vtable `+0x58`.
- `RGE_Action::set_state` at vtable `+0x5C`.
- `RGE_Action_List::update` at vtable `+0x0C`.
- `RGE_Action_Object::new_sprite` at vtable `+0x38`.
- `RGE_Action_Object::notify` at vtable `+0x148`.

The canonical `action.h`, `act_list.h`, `act_obj.h`, `stat_obj.h`, and
`act_move.h` headers declare these surfaces. The direct target identities are
not evidence for a local function-pointer shim.

## Proven fields and owners

`RGE_Action` owns these fields used by the module:

- `action_type` at `+0x04`, a `short`.
- `obj` at `+0x08`, an `RGE_Action_Object*`.
- `state` at `+0x0C`, an `unsigned char`.
- `target_x`, `target_y`, and `target_z` at `+0x20`, `+0x24`, and `+0x28`.
- `task` at `+0x30`, an `RGE_Task*`.
- `sub_actions` at `+0x34`, an `RGE_Action_List*`.

`RGE_Static_Object`, inherited by `RGE_Action_Object`, owns `id` at `+0x04`
and `master_obj` at `+0x08`. The module uses the object virtual surface for
`notify` and `new_sprite`.

`RGE_Task` owns `move_sprite` at `+0x34`. The state-11 path reads it when the
task exists and falls back to the moving master sprite.

`RGE_Master_Moving_Object` owns the fallback `move_sprite` at `+0xBC`.
`include/m_mo_obj.h` now exposes this field through its canonical public owner
surface. Commit `f7f784d3a` also preserves the field access in the owner source.
No local derived carrier or raw `+0xBC` overlay is used.

`RGE_Action_Move_To` owns size `0x44` and the constructor at `004055A0`.
The allocation immediate `0x44` is part of the original codegen evidence.

`RGE_Action_Explore` has no own data fields. Its derived object size is `0x40`.
The owner header declares these constructors and overrides:

```cpp
RGE_Action_Explore(int, RGE_Action_Object*);
RGE_Action_Explore(RGE_Action_Object*, RGE_Task*, float, float, float);
virtual void first_in_stack(unsigned char);
virtual unsigned char update();
virtual int work(RGE_Static_Object*, float, float, float);
protected:
virtual void set_state(unsigned char);
```

Do not add a standalone destructor body. The no-source destructor entries are
compiler-generated from the derived class.

## Canonical dependency audit

The natural source uses these owner headers:

- `include/act_expl.h` — owns `RGE_Action_Explore`.
- `include/action.h` — owns `RGE_Action`.
- `include/act_obj.h` — owns `RGE_Action_Object` and its inherited object
  fields and virtual surface.
- `include/stat_obj.h` — owns `RGE_Static_Object`.
- `include/act_list.h` — owns `RGE_Action_List`.
- `include/task.h` — owns `RGE_Task`.
- `include/act_move.h` — owns `RGE_Action_Move_To`.
- `include/m_mo_obj.h` — owns `RGE_Master_Moving_Object` and its public
  `move_sprite` field.

The source does not use `RGE_Master_Combat_Object`, `RGE_Combat_Object`,
`RGE_Map`, `RGE_Game_World`, or `RGE_Player` fields or methods. These types
appear only as pointer parameters in inherited owner declarations. Do not
include `m_co_obj.h`, `com_obj.h`, `map.h`, `world.h`, or `player.h` only to
replace the context header. Extra full interfaces would add foreign context.

The former `act_expl_context.h` pulled in all of those unrelated surfaces.
The former per-function files also included that context header. Those files
and the local destructor carrier are removed. The padding-only source is also
removed; its reviewed status remains in `config/padding_only_functions.txt`.

## Natural source proposal

`include/act_expl.h` and `src/act_expl.cpp` now own the module. The source keeps
the six-owner PDB order. It includes the canonical action, action-object,
action-list, task, moving-master, static-object, and move-action headers.

Use the existing source bodies as behavior evidence, but remove their context
include and disabled local carrier blocks. Preserve the source-local shared
label in `set_state`; PDB line 130 and the emitted block topology prove that
the case-3 notification falls through to the shared new-sprite statement.

The canonical overload set has two `notify` methods. The source uses local
`int` IDs and `long` event arguments to select the virtual owner slot at
`+0x148`. This keeps the canonical overload surface and the original bytes.

The candidate uses `config/flags/00402C00_set_state.rsp` (`/O2 /GX`). Direct
metadata is in `config/translation_units.json` and
`config/source_modules/act_expl.json`.

## Validation

The grouped candidate is `build/candidate_tus/act_expl.json`. Its report is
`build/candidate_tus/act_expl/report.txt`.

The grouped result is 8/8 `MATCH`: six normal owners and two generated
destructors. Every row has zero byte difference, zero relocation target
mismatches, and zero boundary escapes.

The direct checks cover `00402B40`, `00402BA0`, `00402BE0`, `00402C00`,
`00402D90`, and `00402E40`. The global translation-unit structural check still
reports unrelated pre-existing failures in other modules.

## Evidence paths

- `inventory/functions/0040/00402B40_RGE_Action_Explore.txt`
- `inventory/functions/0040/00402BA0_RGE_Action_Explore.txt`
- `inventory/functions/0040/00402BE0_first_in_stack.txt`
- `inventory/functions/0040/00402C00_set_state.txt`
- `inventory/functions/0040/00402D90_update.txt`
- `inventory/functions/0040/00402E40_work.txt`
- `inventory/functions/0040/00402B70_scalar_deleting_destructor.txt`
- `inventory/functions/0040/00402B90_RGE_Action_Explore.txt`
- `orig/ghidra_decomp/act_expl.cpp.asm`
- `orig/ghidra_decomp/act_expl.cpp.decomp`
- `config/compiler_generated_functions.txt`
- `config/padding_only_functions.txt`
- `config/translation_units.json`
