# `act_move.cpp` source-cleanup report

## Delivery

- Module: `src/act_move.cpp`
- Worker slot: 30
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `91214638ce8628877a82c1a4908af4ea752a4455`
- Changed files:
  - `src/act_move.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/act_move.md`
- PDB source: `C:\\msdev\\work\\age1_x1\\act_move.cpp`
- Registry: `config/functions/src/act_move.cpp.json`
- Registry build flags: `gx`

The source commit restores names from the procedure-scoped PDB records. It
keeps types, scopes, declarations, storage, source order, calls, literals,
and control flow unchanged.

## Evidence checked

I inspected the nine assigned procedure packets:

- `inventory/functions/0040/00405510_RGE_Action_Move_To.txt`
- `inventory/functions/0040/004055A0_RGE_Action_Move_To.txt`
- `inventory/functions/0040/00405620_RGE_Action_Move_To.txt`
- `inventory/functions/0040/004056E0_RGE_Action_Move_To.txt`
- `inventory/functions/0040/00405750_save.txt`
- `inventory/functions/0040/00405780_first_in_stack.txt`
- `inventory/functions/0040/004057E0_set_state.txt`
- `inventory/functions/0040/00405850_update.txt`
- `inventory/functions/0040/00405BF0_is_in_range.txt`

I also inspected the matching records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Each normal procedure has a `this` register record in `ecx` with type
`RGE_Action_Move_To*`. The nearby compiler-generated scalar deleting
destructor at `00405580` has a `__flags` stack record and has no source body.
It was not edited.

The original executable used as the behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Original-name recovery

All nine assigned functions were inspected. The PDB has no function-static
records in this module.

| VA | Function | PDB parameters, locals, and result |
| --- | --- | --- |
| `00405510` | File constructor | Stack `infile` at `+0x4` (`int`) and `obj_in` at `+0x8` (`RGE_Action_Object*`). Both names were recovered. |
| `004055A0` | Position constructor | Stack `obj_in` at `+0x4`, `x` at `+0x8`, `y` at `+0xc`, `z` at `+0x10`, `range_in` at `+0x14`, and `sprite_in` at `+0x18`. The PDB types are `RGE_Action_Object*`, four `float` values, and `RGE_Sprite*`. All names were checked; `x`, `y`, and `z` were already present. |
| `00405620` | Object-target constructor | Stack `obj_in` at `+0x4`, `target_obj_in` at `+0x8`, `range_in` at `+0xc`, and `sprite_in` at `+0x10`. The PDB types are `RGE_Action_Object*`, `RGE_Static_Object*`, `float`, and `RGE_Sprite*`. All names were recovered. |
| `004056E0` | Destructor | No stack parameters or locals. The PDB records only `this` in `ecx`. |
| `00405750` | `save` | Stack `outfile` at `+0x4` (`int`) was already present. The PDB records only `this` in `ecx`. |
| `00405780` | `first_in_stack` | Stack `first_time` at `+0x4` (`unsigned char`) was recovered from the existing placeholder. |
| `004057E0` | `set_state` | Stack `new_state` at `+0x4` (`unsigned char`) was recovered from the existing placeholder. |
| `00405850` | `update` | No parameters beyond `this` and no function statics. PDB locals are `goalPoint` at `-0x8` (`XYZBYTEPoint`), and `yDiff` at `-0x8` and `-0x4` (`float`). The two `y_diff` declarations were renamed to the recovered `yDiff`. |
| `00405BF0` | `is_in_range` | No stack parameters or locals. The PDB records only `this` in `ecx`. |

### Renamed parameters

The PDB establishes these parameter changes:

- `00405510`: `handle` -> `infile`; `object` -> `obj_in`.
- `004055A0`: `object` -> `obj_in`; `range_value` -> `range_in`; `sprite_value` -> `sprite_in`.
- `00405620`: `object` -> `obj_in`; `target` -> `target_obj_in`; `range_value` -> `range_in`; `sprite_value` -> `sprite_in`.
- `00405780`: `param_1` -> `first_time`.
- `004057E0`: `param_1` -> `new_state`.

`x`, `y`, `z`, and `outfile` already matched the PDB names. The destructor,
`update`, and `is_in_range` have no source parameters to rename.

### Local names and unresolved mappings

The PDB identifies `goalPoint` and two `yDiff` records in `update`. The
`goalPoint` record and the two `yDiff` records reuse stack space at `-0x8` or
`-0x4` across different source lifetimes. The source keeps each declaration
and scope separate. It does not force those records into one variable.

`x_diff` has no PDB local record. The source leaves it unchanged as an
inferred snake_case name because the register-backed mapping is uncertain.
`move_result`, `distance`, and `master` also have no PDB local records and
remain existing descriptive names. No new local was added. Exception-chain
slots and compiler temporaries in the packets have no source declaration and
were not mapped.

Recovered names are limited to the PDB names listed above. No invented name
was added in this change.

## Constants, resources, and comments

- No constant was added, renamed, or replaced.
- Existing action states, notification values, target sentinel `-1`, object-state threshold `7`, range fallback `0.4f`, distance threshold `0.25f`, and movement threshold `1.0` remain unchanged.
- The existing `RGE_Moving_Object::PathFound` symbol remains in use.
- The existing `XYZBYTEPoint` type remains in use from `include/command_waypoint.h`.
- Notification values `0x1F9`, `0x1FA`, `0x1FB`, `0x1FC`, and `0x262` remain numeric. No shared declaration proves a more specific role for this module.
- No resource lookup or resource ID occurs in this module. Per-ID text, missing-block, empty-slot, language, lookup-path, purpose, and proposed resource-name evidence are therefore not applicable. No resource-ID request is open.
- No comment was added. Existing control flow, including the two explicit `update()` calls on the reached-target path, remains unchanged.

## Type, layout, and symbol review

The edits change identifier spelling only. They do not change a type,
expression, declaration point, scope, storage duration, call, virtual slot,
public symbol, class layout, or source order. The reused PDB stack mappings
remain intact. No inline assembly, wrapper, helper, layout change, or shared
declaration was added.

The registry still records `00405850 update` as `accepted_drift`; this cleanup
did not change its status or attempt structural recovery.

## Header and root requests

I did not edit `include/act_move.h`, which is owned by owner 04. Its unnamed
parameter declarations remain valid. Owner 04 may add these PDB-proven names
without changing the interface:

```cpp
RGE_Action_Move_To(int infile, RGE_Action_Object* obj_in);
RGE_Action_Move_To(RGE_Action_Object* obj_in, float x, float y, float z,
                   float range_in, RGE_Sprite* sprite_in);
RGE_Action_Move_To(RGE_Action_Object* obj_in, RGE_Static_Object* target_obj_in,
                   float range_in, RGE_Sprite* sprite_in);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
```

This is a non-blocking readability request. No root-owned header change is
requested. No shared layout, global, or resource declaration is requested.

## Validation status

Compilation, matching, audits, and tests were not run.
