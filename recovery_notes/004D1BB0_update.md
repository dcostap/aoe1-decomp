# TRIBE_Action_Repair::update (004D1BB0)

Status: `scratch`.

- PDB source: `C:\\msdev\\work\\age1_x1\\tact_rep.cpp`, lines 229-441.
- Body range: `004D1BB0-004D1EEB` (828 bytes).
- The owner is `TRIBE_Action_Repair::update` in authentic tact_rep.cpp
  source order.
- The source uses the canonical action and task owner headers.
- The repair-rate field is `RGE_Task::work_val1`, the named field at the
  observed `+0x1C` task offset.
- No exact claim is made for this owner. Keep it in scratch.

The state-4 range load uses `RGE_Master_Combat_Object::weapon_range` at
`+0x114` through the canonical `RGE_Master_Combat_Object` surface. Do not
replace it with `RGE_Task::work_range`, a raw offset, or a local layout.

No compiler, candidate, or grouped validation was run for this packet under
the P0 validation budget. Do not use register hints, byte forcing, or inline
assembly.
