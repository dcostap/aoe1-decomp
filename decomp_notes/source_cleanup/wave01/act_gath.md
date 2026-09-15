# ACT_GATH.cpp source-cleanup report

## Delivery

- Module: `src/act_gath.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Source head commit: `b8ddcf77fdc325ca73b7ed5e35c78462a8425cde`
- Changed files:
  - `src/act_gath.cpp`
  - `decomp_notes/source_cleanup/wave01/act_gath.md`
- PDB source: `C:\\msdev\\work\\age1_x1\\ACT_GATH.cpp`
- Registry: `config/functions/src/act_gath.cpp.json`
- Build flags recorded by the registry: `gx`

The source commit restores PDB parameter names and one PDB local name. It
keeps types, scopes, declarations, storage, calls, and source order unchanged.

## Evidence checked

I inspected all assigned functions in these packets:

- `inventory/functions/0040/00402EA0_RGE_Action_Gather.txt`
- `inventory/functions/0040/00402F40_RGE_Action_Gather.txt`
- `inventory/functions/0040/00402FD0_RGE_Action_Gather.txt`
- `inventory/functions/0040/00403020_save.txt`
- `inventory/functions/0040/00403050_first_in_stack.txt`
- `inventory/functions/0040/00403110_set_state.txt`
- `inventory/functions/0040/00403590_update.txt`
- `inventory/functions/0040/00403C60_get_move_sprite.txt`
- `inventory/functions/0040/00403C90_get_wait_sprite.txt`
- `inventory/functions/0040/00403CD0_stop.txt`
- `inventory/functions/0040/00403CE0_move_to.txt`
- `inventory/functions/0040/00403D90_work.txt`

I checked the matching records in
`inventory/pdb/scoped_symbols.json`. Every assigned procedure has a `this`
register record in `ecx` with type `RGE_Action_Gather*`. The generated scalar
Deleting destructor also has its PDB `__flags` stack record.

## Original-name coverage

| VA | Function | PDB names and source result |
| --- | --- | --- |
| `00402EA0` | File constructor | Recovered `infile` and `obj_in`. |
| `00402F10` | Compiler-generated scalar deleting destructor | PDB `__flags` remains generated code. No source body exists. |
| `00402F30` | Destructor thunk | No stack names. The `this` register record was checked. |
| `00402F40` | Object-target constructor | Recovered `obj_in`, `task_in`, and `target_obj_in`. |
| `00402FD0` | Position-target constructor | Recovered `obj_in` and `task_in`. PDB `x`, `y`, and `z` were already present. |
| `00403020` | `save` | PDB `outfile` was already present. |
| `00403050` | `first_in_stack` | Recovered parameter `first_time`. |
| `00403110` | `set_state` | Recovered parameter `new_state`. |
| `00403590` | `update` | PDB locals `give_amount`, `modifier`, `attr`, and `max_hold` are present. The local formerly named `attribute` is now `attr`. |
| `00403C60` | `get_move_sprite` | No stack names. The `this` register record was checked. |
| `00403C90` | `get_wait_sprite` | No stack names. The `this` register record was checked. |
| `00403CD0` | `stop` | No stack names. The `this` register record was checked. |
| `00403CE0` | `move_to` | Recovered parameter `obj_in`. PDB `x`, `y`, and `z` were already present. |
| `00403D90` | `work` | Recovered parameter `obj_in`. PDB `x`, `y`, and `z` were already present. |

### Renamed parameters

The PDB records establish these changes:

- `00402EA0`: `file` -> `infile`; `object` -> `obj_in`.
- `00402F40`: `object` -> `obj_in`; `task` -> `task_in`; `target` -> `target_obj_in`.
- `00402FD0`: `object` -> `obj_in`; `task` -> `task_in`.
- `00403050`: `param1` -> `first_time`.
- `00403110`: `param1` -> `new_state`.
- `00403CE0`: `target` -> `obj_in`.
- `00403D90`: `target` -> `obj_in`.

`outfile`, `x`, `y`, and `z` already matched their PDB names.

### Local names

The `00403590` PDB record gives `attr` at stack offset `-0x4`. It also gives
`max_hold` at the same offset after the short local's lifetime. The source now
uses `attr` for `task->attribute_type2` and keeps the type and declaration
point unchanged.

The PDB has no distinct record for the later short local used with
`attribute_type3`. The source keeps that local as `attribute`. It also keeps
existing non-PDB names such as `adjusted_amount`, `excess`, `task_facet`,
`value`, `target_master`, `object_master`, and `id`. These names are inferred
or existing cleanup names, not recovered original names. No reused slot was
forced.

## Constants, resources, and comments

- No constants were added or changed.
- Existing state, notification, and sentinel literals remain unchanged.
- No resource lookup or resource ID occurs in this module.
- No resource mapping request is needed.
- No comment was added. The existing destructor thunk comment remains.

## Type, layout, and symbol review

The edits change identifier spelling only. They do not change a type, scope,
declaration point, storage duration, expression, call, virtual slot, public
symbol, class layout, or source order. No inline assembly or wrapper was
added. The PDB local overlay at `-0x4` remains intact.

## Header and root requests

I did not edit `include/act_gath.h`, which is owned by owner 01. The header
currently leaves these parameter names unnamed. Owner 01 may add the PDB names
below without changing the interface:

```cpp
RGE_Action_Gather(int infile, RGE_Action_Object* obj_in);
RGE_Action_Gather(RGE_Action_Object* obj_in, RGE_Task* task_in,
                  RGE_Static_Object* target_obj_in);
RGE_Action_Gather(RGE_Action_Object* obj_in, RGE_Task* task_in,
                  float x, float y, float z);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
```

No root-owned header change is requested. No resource declaration is requested.

## Validation status

Compilation, matching, audits, and tests were not run.
