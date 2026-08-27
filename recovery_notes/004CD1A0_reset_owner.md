# 004CD1A0 `TRIBE_Action_Artifact::reset_owner`

- PDB source: `tact_art.cpp`, lines 263 to 265.
- Original size: 8 bytes.

The function dispatches state `100` through the class `set_state` virtual slot.

## Module merge transition

The function moved from its matching fragment into `src/tact_art.cpp` in PDB
order. The merge removes the context guard and keeps the virtual dispatch.
