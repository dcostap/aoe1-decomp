# `act_expl.cpp` cleanup report

## Scope and commits

- Module: `src/act_expl.cpp`.
- PDB source: `C:\\msdev\\work\\age1_x1\\act_expl.cpp`.
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`.
- Final source cleanup commit: `b4f4a2be81247053b5bc7fbb4ab4ed762134b5c4`.
- Changed files:
  - `src/act_expl.cpp`
  - `decomp_notes/source_cleanup/wave01/act_expl.md`
- `include/act_expl.h` was read but not edited. It is owner 01's header.

The registry `config/functions/src/act_expl.cpp.json` assigns six normal
functions. It lists all six as `matching` at the base. This cleanup changes
identifiers and one brace position only. It does not claim a new match.

## Original-name recovery

The PDB records a register symbol named `this` in ECX for every assigned
function. Its type is `RGE_Action_Explore*`. The PDB records no local symbols
for these six functions. The following stack records are the complete assigned
parameter evidence:

| VA | Function | PDB parameters | Source recovery |
| --- | --- | --- | --- |
| `00402B40` | first constructor | `infile` (`int`, `+0x4`), `obj_in` (`RGE_Action_Object*`, `+0x8`) | Renamed `param_1` to `infile` and `param_2` to `obj_in`. |
| `00402BA0` | second constructor | `obj_in` (`RGE_Action_Object*`, `+0x4`), `task_in` (`RGE_Task*`, `+0x8`), `x`, `y`, `z` (`float`, `+0xC`, `+0x10`, `+0x14`) | Renamed `obj` to `obj_in` and `task` to `task_in`. `x`, `y`, and `z` already matched the PDB. |
| `00402BE0` | `first_in_stack` | `first_time` (`unsigned char`, `+0x4`) | Renamed `value` to `first_time`. The parameter is unused, as in the original body. |
| `00402C00` | `set_state` | `new_state` (`unsigned char`, `+0x4`) | Renamed `param_1` to `new_state`. |
| `00402D90` | `update` | none | No parameter or local rename was possible. |
| `00402E40` | `work` | `obj_in` (`RGE_Static_Object*`, `+0x4`), `x`, `y`, `z` (`float`, `+0x8`, `+0xC`, `+0x10`) | Renamed `param_1` to `obj_in` and `param_2`/`param_3`/`param_4` to `x`/`y`/`z`. `obj_in` remains unused. |

No Ghidra-generated `param_*`, `local_*`, or register-carrier names were
copied into the source. The PDB has no local mapping for the existing
function-local values. I renamed these locals as new cleanup names, not as
recovered originals:

- `id` to `obj_id` in the state-3 and state-13 notification blocks. The value
  is loaded from `this->obj->id` and passed as both notification ID arguments.
- `ms` to `move_sprite`. The value is an `RGE_Sprite*` selected from the task
  or the moving master, then passed to `RGE_Action_Move_To`.
- `action` to `move_action`. The value is an `RGE_Action_Move_To*` whose
  sub-action is set and which is added to `sub_actions`.

The PDB evidence is in `inventory/pdb/scoped_symbols.json`. The parameter
uses and types also agree with the six function packets under
`inventory/functions/0040/`.

## Constants, resources, and comments

No constants or resource IDs were added. The source preserves the original
numeric state values, notification codes, and sentinel:

- `00402BE0` compares `target_x` with bit pattern `0xBF800000`.
- `00402C00` stores the requested state and retains states `1`, `2`, `3`,
  `11`, `13`, and `14`.
- `00402C42` emits notification values `0x202` and `0x25D`.
- `00402DC2` emits notification values `0x1F9` and `0x25D`.

These facts come from the original assembly in the function packets. No
established shared symbols prove these values in this module, so the literals
remain unchanged. The module has no resource lookup. No source comments were
added.

## Type, layout, and symbol review

The changes do not alter types, declarations, scopes, storage, source order,
control flow, calls, casts, member access, or public symbols. The work
parameter `obj_in` remains unused. The `set_state` opening brace now follows
1TBS style. The proposed local names are snake_case invented names only.

The generated destructor records near this module (`00402B70` and `00402B90`)
are not registry-owned source functions and were not edited. No compiler,
layout, or code-generation result is available for this cleanup because the
required validation stages were deferred.

## Header requests and unresolved items

Owner 01 may add these names to `include/act_expl.h`; the declaration types,
order, and ABI stay unchanged:

```cpp
RGE_Action_Explore(int infile, RGE_Action_Object* obj_in);
RGE_Action_Explore(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);
virtual void first_in_stack(unsigned char first_time);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
virtual void set_state(unsigned char new_state);
```

The names are supported by the PDB records listed above. Root-owned headers,
including `include/action.h` and `include/resource_ids.h`, need no change.
There are no unresolved resource mappings. The only unresolved name question
is the original spelling of locals absent from the PDB; the report marks their
cleanup names as inferred rather than recovered.

Compilation, matching, audits, and tests were not run. Games were not run.
