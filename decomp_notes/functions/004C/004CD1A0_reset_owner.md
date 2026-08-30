# Function notes: 004CD1A0 `reset_owner`

## Earlier notes from `decomp_notes/functions/004C/004CD1A0_reset_owner.md`

This section is historical. Use the status query for current state.

## 004CD1A0 `TRIBE_Action_Artifact::reset_owner`

- PDB source: `tact_art.cpp`, lines 263 to 265.
- Original size: 8 bytes.

The function dispatches state `100` through the class `set_state` virtual slot.

### Module merge transition

The function moved from its matching fragment into `src/tact_art.cpp` in PDB
order. The merge removes the context guard and keeps the virtual dispatch.
