# tact_rep.cpp source reunification

## Translation-unit context

- PDB source: `C:\\msdev\\work\\age1_x1\\tact_rep.cpp`.
- The packet contains 12 normal owners in source and address order.
- The owner range is `004D1680` through `004D2020`.
- All owners belong to `TRIBE_Action_Repair`.
- The nearby `004D16F0` vector deleting destructor is compiler-generated.
- The canonical declaration surface is `include/tact_rep.h`.
- The module uses `config/flags/004CD210_TRIBE_Action_Build.rsp`.

## Status

The source owns all 12 normal owners in PDB order. Final grouped validation
matches nine registered owners. `004D1BB0` (`TRIBE_Action_Repair::update`)
remains scratch.

`004D18B0` (`set_state`) differs by 603 bytes. `004D2020` (`meet_target`)
differs by 3 bytes. Both retain matching owner, relocation targets, and
boundaries. They are scratch and have no exact translation-unit ownership.
Do not tune headers or restore `sound_context.h` to change these results.

The state-4 range load reads `RGE_Master_Combat_Object::weapon_range` at
`+0x114`. The source uses that named field from the canonical `m_co_obj.h`
owner header. Do not replace it with `RGE_Task::work_range`, a raw offset, or
a local layout.

The source has no inline assembly, byte filler, codegen-only body, or forced
register hint. No matching claim is made for this migration.

## Ownership and cleanup

`src/tact_rep.cpp` is the sole compiler-facing source owner. The old direct
wrapper, all 11 matching fragments, and the update scratch fragment are
removed. The old context header is now the module-owned `include/tact_rep.h`.
The source has no `.cpp` includes, recovery context macros, fallback ABI
declarations, or duplicate owner declarations. It consumes the canonical
`act_move.h` and `obj_list.h` headers now present on main.

The source uses `RGE_Task::work_val1` for the repair rate. This is the
canonical field at the observed `+0x1C` task offset. Action-object-only fields
use the canonical `RGE_Action_Object` surface through typed casts. The source
does not publish packet-local combat, action-list, or action declarations.

The final grouped candidate also reports a 299-byte difference for scratch
`004D1BB0`. It has matching owner, relocation targets, and boundaries.
