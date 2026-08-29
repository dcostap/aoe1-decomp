# Recovery journal: 004C8690 `destroy_obj`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

- PDB module: `t_b_obj.cpp`; owner: `TRIBE_Building_Object`.
- Natural source order places `take_building_attribute_from_owner` at
  `004C85D0`, `give_building_attribute_to_owner` at `004C8630`, and this
  function at `004C8690`.
- Original body is 42 bytes. It saves `esi`, calls virtual slot `+0x258`,
  calls `RGE_Action_Object::destroy_obj`, removes the doppleganger check, and
  clears `DoppleInstalled`.

## Current mismatch

- Fresh baseline with `die_die_die()` was 39 bytes and used virtual slot
  `+0x6C`, so the stale exact result was not current.
- Natural recovery to `take_building_attribute_from_owner()` restored 42 bytes,
  the original shape, and all non-virtual bytes. The only mismatch is the
  virtual call displacement: rebuilt `+0x25C`, original `+0x258`.
- The checker reports one differing byte, 2.3810%, with 2/2 relocations safely
  masked. Calls and boundaries otherwise match.
- The canonical `TRIBE_Combat_Object` vtable places `higher_than_target` at
  `+0x258`, then `take_building_attribute_from_owner` at `+0x25C` and `give` at
  `+0x260`. Original `t_b_obj.cpp` places `take` at `+0x258` and `give` at
  `+0x25C`. This is a shared-header ABI blocker, not a body reconstruction
  defect.

## Recovered attempt history

- Fresh `baseline`: current `die_die_die()` source mismatched at 39 bytes.
- `behavior`: `take_building_attribute_from_owner()` produced the best natural
  source at 42 bytes, with the one-byte vtable-slot mismatch above.
No function-specific cleanup block was mapped automatically. Review the earlier note and Git history before work.

## Rejected approaches

- `die_die_die()` is rejected. The original first call is virtual `+0x258`, and
  this form emits virtual `+0x6C`.
- Calling `higher_than_target` or adding a manual vtable/pointer cast would tune
  the slot only. It would not be a behavior-supported source reconstruction.

## Open questions

- Can the canonical combat header model the original vtable without changing
  other owners? The missing/extra slot is `higher_than_target` at `+0x258`.
- A shared-header owner should compare the registered `t_b_obj` neighbors after
  any ABI repair.

## Next useful approaches

- Review the original `TRIBE_Combat_Object` virtual surface and the current
  canonical declaration for `higher_than_target`.
- If the shared ABI is repaired, recheck this body without changing its natural
  `take_building_attribute_from_owner()` call.

## Worker updates

- `wave10-tbobj`: Rebuilt stale evidence. Retained the natural `take` call.
  Fresh result is unresolved due to the canonical vtable slot shift. No TU
  audit was run because the target is not exact.
