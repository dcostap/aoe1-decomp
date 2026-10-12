# TACT_HNT.cpp source-cleanup report

## Delivery

- Module: `src/tact_hnt.cpp`
- Owner: owner 05, worker slot 43
- Branch: `cleanup/staging-20260915-43`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Source cleanup commit from `git rev-parse`: `e7f7fb4623c53775d1678744e07bfd203e0b537e`
- Final source head: `e7f7fb4623c53775d1678744e07bfd203e0b537e`
- Changed files:
  - `src/tact_hnt.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/tact_hnt.md`
- Header request target: `include/tact_hnt.h` only; this worker did not edit it.
- Registry: `config/functions/src/tact_hnt.cpp.json`
- Registry build flags: `gx`
- Source SHA-256 before cleanup: `79f49103fca202c9bd83a60836e2d5c69757ab274bde20438ca954c57bef42e8`
- Source SHA-256 after cleanup: `3cd0407d7f19b95f67af8897ba30e717cbe670abbfa92d5bf2c8f19bab776e5c`

The source change restores PDB names and applies 1TBS braces. It keeps types,
declaration points, scopes, storage, expressions, calls, literals, and source
order unchanged.

## Evidence checked

I selected the assigned procedures through
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tact_hnt.cpp.json`.
The source registry lists these twelve source-owned procedures:

- `004CF090` `TRIBE_Action_Hunt::TRIBE_Action_Hunt(int, RGE_Action_Object*)`
- `004CF130` `TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*)`
- `004CF1C0` `TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, float, float, float)`
- `004CF210` `TRIBE_Action_Hunt::save`
- `004CF240` `TRIBE_Action_Hunt::first_in_stack`
- `004CF300` `TRIBE_Action_Hunt::set_state`
- `004CF860` `TRIBE_Action_Hunt::update`
- `004CFF20` `TRIBE_Action_Hunt::get_move_sprite`
- `004CFF50` `TRIBE_Action_Hunt::get_wait_sprite`
- `004CFF90` `TRIBE_Action_Hunt::stop`
- `004CFFD0` `TRIBE_Action_Hunt::move_to`
- `004D0080` `TRIBE_Action_Hunt::work`

I inspected the corresponding function packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004C/` and
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004D/`.
The packet paths are:

- `inventory/functions/004C/004CF090_TRIBE_Action_Hunt.txt`
- `inventory/functions/004C/004CF130_TRIBE_Action_Hunt.txt`
- `inventory/functions/004C/004CF1C0_TRIBE_Action_Hunt.txt`
- `inventory/functions/004C/004CF210_save.txt`
- `inventory/functions/004C/004CF240_first_in_stack.txt`
- `inventory/functions/004C/004CF300_set_state.txt`
- `inventory/functions/004C/004CF860_update.txt`
- `inventory/functions/004C/004CFF20_get_move_sprite.txt`
- `inventory/functions/004C/004CFF50_get_wait_sprite.txt`
- `inventory/functions/004C/004CFF90_stop.txt`
- `inventory/functions/004C/004CFFD0_move_to.txt`
- `inventory/functions/004D/004D0080_work.txt`

The procedure-scoped records are in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its SHA-256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
Every assigned procedure has a PDB `this` record in `ecx` with type
`TRIBE_Action_Hunt*`.

The original behavior reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup build is under
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`.
Its `empiresx.exe` SHA-256 is
`492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
Its `tact_hnt.obj` SHA-256 is
`44bdad51914b1d7ac5d131e3d30a52dcdb8bb6f9e8d4178d24541cfd8c2bb52e`.
The original PDB is
`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`.
Its SHA-256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

## Original-name recovery coverage

The names marked **recovered** below come from the procedure-scoped PDB.
The `this` register record was checked for every row. Names marked
**existing/inferred** have no distinct PDB record and remain unchanged.

| VA | Function | PDB names and source result |
| --- | --- | --- |
| `004CF090` | File constructor | **Recovered:** `infile`, `obj_in`. Both replace `param_1` and `param_2`. |
| `004CF100` | Compiler-generated scalar deleting destructor | PDB `__flags` at `+0x4`; no source body exists here. It was inspected and not edited. |
| `004CF120` | Compiler-generated destructor thunk | No stack names; only the `this` register record. No source body exists here. |
| `004CF130` | Object-target constructor | **Recovered:** `obj_in`, `task_in`, `target_obj_in`. They replace `obj`, `tsk`, and `target`. |
| `004CF1C0` | Position-target constructor | **Recovered:** `obj_in`, `task_in`; PDB `x`, `y`, and `z` were already present. |
| `004CF210` | `save` | PDB `outfile` was already present. |
| `004CF240` | `first_in_stack` | **Recovered:** `first_time`, replacing `param_1`. |
| `004CF300` | `set_state` | **Recovered:** `new_state`, replacing `param_1` in the declaration, assignment, and switch. |
| `004CF860` | `update` | PDB locals `give_amount`, `modifier`, `attr`, and `max_hold` were checked. **Recovered:** the state-7 `short attribute` is now `attr`. PDB records `attr` and `max_hold` use the same `-0x4` stack home. |
| `004CFF20` | `get_move_sprite` | No stack names. Existing/inferred locals `task` and `task_facet` remain unchanged. |
| `004CFF50` | `get_wait_sprite` | No stack names. Existing/inferred locals `task` and `task_facet` remain unchanged. |
| `004CFF90` | `stop` | No stack names beyond `this`. No local rename was needed. |
| `004CFFD0` | `move_to` | **Recovered:** `obj_in`, replacing `target`; PDB `x`, `y`, and `z` were already present. |
| `004D0080` | `work` | **Recovered:** `obj_in`, `x`, `y`, and `z`, replacing `param_1` through `param_4`. |

### Renamed parameters

The PDB records establish these source changes:

- `004CF090`: `param_1` -> `infile`; `param_2` -> `obj_in`.
- `004CF130`: `obj` -> `obj_in`; `tsk` -> `task_in`; `target` -> `target_obj_in`.
- `004CF1C0`: `obj` -> `obj_in`; `task` -> `task_in`.
- `004CF240`: `param_1` -> `first_time`.
- `004CF300`: `param_1` -> `new_state`.
- `004CFFD0`: `target` -> `obj_in`.
- `004D0080`: `param_1` -> `obj_in`; `param_2` -> `x`; `param_3` -> `y`; `param_4` -> `z`.

`outfile`, `x`, `y`, and `z` that already matched their PDB names remain
unchanged in the other procedures.

### Locals and unresolved mappings

The PDB has no distinct local records for `first_in_stack`, `set_state`, the
sprite helpers, `stop`, `move_to`, or `work`. Existing/inferred names such as
`tsk`, `attr_val`, `target`, `unit`, `target_master`, `unit_master`,
`target_id`, `task`, `task_facet`, `master`, and `obj_id` remain unchanged.
They are not claimed as original developer names.

The `004CF860` PDB gives `give_amount` at `-0xc`, `modifier` at `-0x8`, and
both `attr` (`short`) and `max_hold` (`float`) at `-0x4`. The source renames
only the state-7 `short attribute` declaration to recovered `attr`. It keeps
the later state-8 `short attribute` declaration because the PDB has no distinct
record for that lifetime. It also keeps `adjusted_amount` and `excess`, which
have no procedure-scoped PDB names. No reused stack-slot mapping was forced.

No new descriptive name was added. Existing descriptive names are not claimed
as recovered originals unless the table says so.

## Constants, resources, and comments

No numeric constant, enum, resource ID, or global name changed. Existing state,
notification, sentinel, and floating-global literals remain unchanged.

This module has no resource lookup. The runtime resource inputs
`C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` and
`C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll` were not needed or
inspected. No resource mapping or `include/resource_ids.h` request exists.

No source comment was added or removed. Existing evidence comments remain.
The source only receives identifier changes and 1TBS opening-brace changes.

## Type, layout, code-generation, and symbol review

The edits change identifier spelling and brace placement only. They do not
change a type, declaration point, scope, storage duration, expression, control
flow, call, relocation, boundary, virtual slot, public symbol, class layout,
or calling convention. No inline assembly, wrapper, helper, layout change, or
registry change was added.

The source registry currently marks ten neighboring procedures as `matching`,
`004CF860` as `new_verified_logic`, and `004CFFD0` as `accepted_drift`.
Those claims and statuses were not changed. The preserved baseline object and
executable hashes above are evidence only. This cleanup did not rebuild them.

Identifier spelling should not change generated instructions, but formatting
can change debug line records. The overlapping `attr`/`max_hold` PDB home and
all unproven local mappings remain unresolved for later review.

## Header request

I did not edit `include/tact_hnt.h`, owned by owner 05. The owner may add these
PDB-proven parameter names without changing types, order, access, or symbols:

```cpp
TRIBE_Action_Hunt(int infile, RGE_Action_Object* obj_in);
TRIBE_Action_Hunt(RGE_Action_Object* obj_in, RGE_Task* task_in, RGE_Static_Object* target_obj_in);
TRIBE_Action_Hunt(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);
virtual void save(int outfile);
virtual void first_in_stack(unsigned char first_time);
virtual void set_state(unsigned char new_state);
virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
```

`update`, `stop`, `get_move_sprite`, and `get_wait_sprite` have no named
parameters. No other header request exists.

## Validation status

Compilation, matching, audits, and tests were not run. No compiler, build,
game, or runtime command was run. Only evidence inspection, Git review, and
`git diff --check` were run. Generated code, program data, relocations, and
call targets remain unvalidated.
