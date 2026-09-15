# Source cleanup report: `act_atak.cpp`

## Delivery

- Module: `src/act_atak.cpp`
- Base commit from `git rev-parse`: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Initial source commit from `git rev-parse`: `0fc09d6fdabd16933c324eac22fe873554ac341f`
- Initial report commit: `a2c408e369d3e83c799dd988f108fdb244ff4e08`
- Final source commit from `git rev-parse`: `d041e74f54f917cafeafd9628b0e903ee634f811`
- Prior report-correction commit: `b2b0ddde386ae7ce13edd28632f0fc89d01dfe09`
- Prior commit sequence: `0fc09d6fdabd16933c324eac22fe873554ac341f`, `a2c408e369d3e83c799dd988f108fdb244ff4e08`, `d041e74f54f917cafeafd9628b0e903ee634f811`, `b2b0ddde386ae7ce13edd28632f0fc89d01dfe09`.
- The final source commit contains the source cleanup changes.
- The report commits follow the source commits.
- Changed files: `src/act_atak.cpp`; this report.
- Branch: `cleanup/staging-20260915-04`

The report covers all 13 assigned registry functions.
No expression, control flow, call, type, storage, or data value changed.

## Evidence

The name recovery uses `inventory/pdb/scoped_symbols.json`.
The records use `Act_atak.cpp` from the original PDB.
The records include stack and register symbols for each assigned function.

The original assembly and line records were inspected in these packets:

- `inventory/functions/0040/00401000_RGE_Action_Attack.txt`
- `inventory/functions/0040/00401170_RGE_Action_Attack.txt`
- `inventory/functions/0040/004012B0_RGE_Action_Attack.txt`
- `inventory/functions/0040/004013A0_RGE_Action_Attack.txt`
- `inventory/functions/0040/004013B0_save.txt`
- `inventory/functions/0040/004014B0_first_in_stack.txt`
- `inventory/functions/0040/00401540_stop.txt`
- `inventory/functions/0040/00401550_set_state.txt`
- `inventory/functions/0040/00401780_update.txt`
- `inventory/functions/0040/00401AD0_work.txt`
- `inventory/functions/0040/00401B30_ready_to_attack.txt`
- `inventory/functions/0040/00401EC0_do_attack.txt`
- `inventory/functions/0040/00401F00_copy_obj_sprites.txt`

The packets confirm the original function boundaries and call structure.
The original executable remains the behavior oracle.

## Original-name recovery

All names below are recovered from PDB records unless marked as already present.
Every assigned function has a PDB `this` register record in `ecx`.

| VA | Function | Recovered names and coverage |
| --- | --- | --- |
| `00401000` | load constructor | Parameters `infile`, `obj_in`; local `short_val`. |
| `00401170` | target constructor | Parameters `obj_in`, `target_obj_in`, `move_sprite_in`, `fight_sprite_in`, `wait_sprite_in`, `range_in`, `min_range_in`, `missile_id_in`, `fire_missile_at_frame_in`. |
| `004012B0` | position constructor | Parameters `obj_in`, `x`, `y`, `z`, `move_sprite_in`, `fight_sprite_in`, `wait_sprite_in`, `range_in`, `min_range_in`, `missile_id_in`, `fire_missile_at_frame_in`. |
| `004013A0` | destructor | No stack names. `this` is the only register symbol. |
| `004013B0` | `save` | Parameter `outfile`; local `short_val`. |
| `004014B0` | `first_in_stack` | Parameter `first_time`; local `rangeStatus`. |
| `00401540` | `stop` | No stack names. `this` is the only register symbol. |
| `00401550` | `set_state` | Parameter `new_state`; local `rangeStatus`. |
| `00401780` | `update` | Local `rangeStatus`. No parameter names. |
| `00401AD0` | `work` | Parameters `obj_in`, `x`, `y`, `z`. |
| `00401B30` | `ready_to_attack` | Parameter `rangeState`; locals `rangeDistance`, `y_change`, `z_change`. |
| `00401EC0` | `do_attack` | No stack names. `this` is the only register symbol. |
| `00401F00` | `copy_obj_sprites` | Parameters `source`, `task`, `new_task`. |

The source restores these PDB names:

- `handle` became `infile` at `00401000`.
- `object` became `obj_in` at `00401000`.
- The load constructor's `sprite_id` became PDB `short_val`.
- All nine target-constructor parameters now use their PDB names at `00401170`.
- All eleven position-constructor parameters now use their PDB names at `004012B0`.
- `handle` became `outfile` at `004013B0`.
- The save local `sprite_id` became PDB `short_val`.
- The unnamed `first_in_stack` parameter became `first_time`.
- The `first_in_stack` local `range_status` became `rangeStatus`.
- The `set_state` parameter `state` became `new_state`.
- The `set_state` local `range_status` became `rangeStatus`.
- The `update` local `range_status` became `rangeStatus`.
- The `work` parameter `target` became `obj_in`.
- The `ready_to_attack` parameter `range_status` became `rangeState`.
- The `ready_to_attack` local `distance` became `rangeDistance`.
- The `copy_obj_sprites` parameter `old_task` became `task`.

`rangeDistance` and `z_change` both have PDB stack offset `-0x4`.
The source keeps separate declarations in one function scope.
Their uses do not overlap.
Compiler and PDB evidence maps the reused slot.
No reused stack-slot mapping was forced beyond the supported name mapping.

## Inferred names and unresolved mappings

The PDB has no stack record for `saved_handle` in `save`.
The source retains this existing inferred alias and does not reshape its declaration.

The PDB has no records for several optimized locals.
The source retains their existing descriptive names: `master`, `sprite`, `ai`, `action`,
`attack_frame`, `radius_x`, `radius_y`, `radius_distance`, `x_change`, `visible`, and `object`.
These names are cleanup names, not recovered original names.

No parameter or local with a PDB record remains unresolved.
The PDB register records contain only `this` for these functions.
The unused `first_time` parameter remains named because the PDB records it.

## Constants, resources, and comments

No numeric constant changed.
No new constant or enum was added.
The existing state, notification, and sentinel literals remain unchanged.
`include/action.h` has no established state constants for these values.

This module has no resource lookup.
No resource ID mapping or resource header request is needed.

No source comment was added.
The existing code and the report provide enough evidence for this name-only cleanup.

## Code generation, type, layout, and symbol review

The changes rename identifiers and move function opening braces to 1TBS form.
They do not change types, storage, declaration scope, member order, evaluation order,
control flow, calls, relocations, function boundaries, or ABI symbols.

The `rangeDistance` rename does not change the separate `float` declaration.
The PDB stack-offset overlap with `z_change` remains documented above.
No inline assembly or wrapper was added.

Executable validation is deferred by the wave rules.

## Header requests

`include/act_atak.h` was read and not edited.
Owner 01 controls that header.
The declarations currently omit parameter names.
Owner 01 may add these precise names without changing types or signatures:

```cpp
RGE_Action_Attack(int infile, RGE_Action_Object* obj_in);
RGE_Action_Attack(RGE_Action_Object* obj_in, RGE_Static_Object* target_obj_in,
                  RGE_Sprite* move_sprite_in, RGE_Sprite* fight_sprite_in,
                  RGE_Sprite* wait_sprite_in, float range_in, float min_range_in,
                  short missile_id_in, short fire_missile_at_frame_in);
RGE_Action_Attack(RGE_Action_Object* obj_in, float x, float y, float z,
                  RGE_Sprite* move_sprite_in, RGE_Sprite* fight_sprite_in,
                  RGE_Sprite* wait_sprite_in, float range_in, float min_range_in,
                  short missile_id_in, short fire_missile_at_frame_in);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
virtual void copy_obj_sprites(RGE_Master_Action_Object* source, RGE_Task* task, RGE_Task* new_task);
virtual void set_state(unsigned char new_state);
```

No root-owned header request exists.
No resource declaration request exists.

## Validation

Compilation, matching, audits, and tests were not run.
No build, compiler check, game, or runtime harness was run.
Only evidence inspection, Git review, and `git diff --check` were run.
