# Function notes: 004C8E90 `transform`

Module notes: `decomp_notes/t_b_obj_module.md`.

## Translation-unit context

- PDB module: `t_b_obj.cpp`, owned by `TRIBE_Building_Object`.
- Source owner: `src/t_b_obj.cpp`; the function is in the module's PDB address
  sequence at `004C8E90`.
- Original body: `004C8E90-004C8ECB`, 60 bytes, `__thiscall`.
- Exact anchors are the direct `TRIBE_Combat_Object::transform` call, the
  virtual call at vslot `0x38`, and the `build_pts` store at `+0x1DC`.

## Current mismatch

- Baseline before integration: 60 rebuilt bytes, 11 strict-diff bytes
  (`18.3333%`), 18 rebuilt instructions versus 19 original instructions.
  The mismatch came from resetting `built` at `+0x1E5`, and from testing the
  parameter's `build_pts_required` instead of the transformed `master_obj`.
- Final focused check: 60 rebuilt bytes, 0 strict-diff bytes (`0.0000%`),
  19 instructions, matching frame and owner symbol, two aligned calls, one
  safely masked relocation, and the original `004C8E90-004C8ECB` boundary.
- Grouped `t_b_obj` audit: this row is `MATCH` with `NEW_DIFF 0`, owner
  `match`, relocation `0`, and boundary `0`. The group has unrelated drift.

## Recovered attempt history

- The natural body now calls the base transform, resets `object_state`, reads
  `build_pts_required` through a typed `TRIBE_Master_Combat_Object*` view of
  `master_obj`, selects `construction_sprite` from the typed parameter when
  the threshold is positive, and resets `build_pts`.
- The final source emits a focused `MATCH` with `0.0000%` difference.

## Rejected approaches

- `built = 0` was rejected. Original bytes write `object_state` at `+0x48`,
  not `built` at `+0x1E5`.
- `master->build_pts_required` was rejected. Original bytes load `this->master_obj`
  at `+0x8` and read `build_pts_required` at `+0x15A` from that object.

## Open questions

- The grouped module audit may still report unrelated neighbor drift while
  shared vtable work continues. This target's focused owner and boundary are
  exact.

## Next useful approaches

- Preserve this body during any shared vtable or translation-unit repair.
- Re-run the focused checker and the registered `t_b_obj` group audit after
  shared changes.

## Worker updates

- `wave21-t-b-obj-integrate`: Integrated the proven natural body. Focused
  validation is exact; grouped validation is recorded under the worker audit
  directory.
