# `act_tran.cpp` source-cleanup report

## Git and scope

- Module: `src/act_tran.cpp`
- Base commit: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Source-cleanup head: `1549b93267a6ec34736e11638b5ba4dded936254`
- Branch: `cleanup/staging-20260915-11`
- Changed files in the module delivery:
  - `src/act_tran.cpp`
  - `decomp_notes/source_cleanup/wave01/act_tran.md`
- This report is the assigned durable report for the module.
- `include/act_tran.h` was read but not edited.

Commit list:

- `1549b93267a6ec34736e11638b5ba4dded936254` — Recover act_tran parameter names.
- `34e1373c909b001d7b5686453d6419fdd7c8fbfd` — Document act_tran cleanup evidence.
- `d6392b32e8f9f90d5b260d93275888dd90fab1ef` — Keep act_tran signatures on one line.

The source change restores PDB parameter names and applies 1TBS braces to
function definitions. It does not change expressions, calls, constants, types,
storage, declaration scope, or source order.

## Evidence inspected

- `inventory/pdb/scoped_symbols.json`, entries `00406D60` through `00407420`.
- The ten assigned packets under `inventory/functions/0040/`:
  `00406D60`, `00406DC0`, `00406E00`, `00406E50`, `00406F90`, `00407160`,
  `00407170`, `004071A0`, `004072B0`, and `00407420`.
- Existing module note: `decomp_notes/act_tran.md`.
- Corresponding declaration: `include/act_tran.h`.

The PDB records the source path as
`C:\\msdev\\work\\age1_x1\\act_tran.cpp`. The scoped records include the
`this` register for each function and the named stack records listed below.

## Function-by-function name coverage

All ten registry functions were inspected. No assigned function retains a
`param_*`, `local_*`, `iVar*`, `uVar*`, or similar decompiler placeholder.

- `00406D60 RGE_Action_Transport(int, RGE_Action_Object*)`: restored
  `infile` and `obj_in` from the PDB stack records. The PDB records `this` in
  `ecx` as `RGE_Action_Transport*`.
- `00406DC0 RGE_Action_Transport(RGE_Action_Object*, RGE_Task*, float, float, float)`:
  restored `obj_in` and `task_in`. The PDB also records `x`, `y`, and `z`,
  which were already present and remain unchanged.
- `00406E00 first_in_stack(unsigned char)`: restored `first_time` from the
  PDB stack record. The `this` register record is unchanged.
- `00406E50 set_state(unsigned char)`: restored `new_state` from the PDB
  stack record. The exception-cleanup storage and `move_to` declaration stay
  unchanged.
- `00406F90 update()`: the PDB records only `this`, with no named stack or
  local records. Existing concise inferred names (`result`, `zone`, `object`,
  `owner`, `id`, and `map`) remain unchanged. The existing explicit notify
  casts remain unchanged.
- `00407160 stop()`: the PDB records only `this`; no parameter or local rename
  was available.
- `00407170 move_to(RGE_Static_Object*, float, float, float)`: restored
  `obj_in` from the PDB. The PDB records `x`, `y`, and `z`, which remain
  unchanged. The unused parameter remains present for the ABI.
- `004071A0 work(RGE_Static_Object*, float, float, float)`: restored `obj_in`
  from the PDB. The PDB records `x`, `y`, `z`, and `distance`; all are present
  in the source. The existing local `zone` remains an inferred name.
- `004072B0 next_to_drop_off_terrain()`: the PDB records `x1`, `x2`, and
  `y2`; the source uses those names for the matching bounds. The source's
  `y1` has no separate PDB name, so it remains the concise inferred lower-Y
  bound name. The existing `target_zone` and loop names remain inferred names.
- `00407420 targetZone()`: the PDB records only `this`; no parameter or local
  rename was available.

The inventory also marks `0040712E` as a parent-owned fragment of `update`,
not as an additional source owner. The generated `00406D90` scalar deleting
destructor and `00406DB0` destructor were inspected through the scoped PDB
records and remain compiler-generated.

## Recovered and inferred names

Recovered from procedure-scoped PDB records:

- `infile`, `obj_in` at `00406D60`.
- `obj_in`, `task_in`, `x`, `y`, `z` at `00406DC0`.
- `first_time` at `00406E00`.
- `new_state` at `00406E50`.
- `obj_in`, `x`, `y`, `z` at `00407170`.
- `obj_in`, `x`, `y`, `z`, `distance` at `004071A0`.
- `x1`, `x2`, and `y2` at `004072B0`.

Retained inferred or source-facing names without a matching PDB local record:
`move_to`, `result`, `zone`, `object`, `owner`, `id`, `map`, `y1`,
`target_zone`, and the `x`/`y` loop indices in `next_to_drop_off_terrain`.
These names are concise and describe their current use. No stack-slot mapping
was forced for an unrecorded name.

## Constants, resources, and comments

No resource lookup occurs in this module. No resource ID mapping or header
request is needed.

No new constant was introduced. Existing state values, terrain values,
notification values, `0xBF800000` sentinel tests, and typed notify casts were
left unchanged. Their use is covered by the existing module recovery note and
function packets. No new source comment was added. The existing comment before
`first_in_stack` was retained; it records the observed callee cleanup and FPU
constant detail.

## Header request

The header owner for `include/act_tran.h` may add the recovered parameter names
below. This is a declaration-only readability change; it keeps all types,
calling conventions, virtual slots, and ABI symbols unchanged:

```cpp
RGE_Action_Transport(int infile, RGE_Action_Object* obj_in);
RGE_Action_Transport(RGE_Action_Object* obj_in, RGE_Task* task_in, float x, float y, float z);
virtual void first_in_stack(unsigned char first_time);
virtual int move_to(RGE_Static_Object* obj_in, float x, float y, float z);
virtual int work(RGE_Static_Object* obj_in, float x, float y, float z);
virtual void set_state(unsigned char new_state);
```

This request is for owner 01. There are no root-owned header requests and no
resource-ID requests.

## Concerns and validation

The changes are identifier and brace-format changes only. They do not alter
function symbols, parameter types, layout, storage, call targets, casts, or
control flow. The existing `first_in_stack` accepted-drift status is unchanged.
The source commit was reviewed with `git diff --check` and a complete Git diff.

Compilation, matching, audits, and tests were not run. Builds and games were
also not run, as required for this cleanup wave.
