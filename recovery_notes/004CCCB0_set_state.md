# 004CCCB0 `TRIBE_Action_Artifact::set_state`

- PDB source: `tact_art.cpp`, lines 78 to 116.
- Original size: 312 bytes.
- Flags: `config/flags/004CCCB0_set_state.rsp`.

## Recovery record

1. A natural C++ `new` expression with the constructor and `/GX` restored the
   state dispatch and allocation shape.
2. Source-order cases `(10, 4, 5)` restored the original dispatch topology.
3. The proven `RGE_Action` base size and `RGE_Action_Move_To::range` field
   restored the `0x44` allocation size.
4. The corrected `RGE_Action_List::add_action` and move constructor surfaces
   produced the exact function under the module flags.

## Module merge transition

The function moved from its matching fragment into `src/tact_art.cpp` in PDB
order. The merge keeps the natural switch, typed fields, constructor call, and
module flags. It removes only fallback declarations and the context guard.
