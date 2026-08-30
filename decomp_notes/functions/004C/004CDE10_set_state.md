# Function notes: 004CDE10 `set_state`

## Earlier notes from `decomp_notes/functions/004C/004CDE10_set_state.md`

This section is historical. Use the status query for current state.

## 004CDE10 `TRIBE_Action_Convert::set_state`

- PDB source: `tact_cnv.cpp`, lines 222 to 305.
- Original size: 541 bytes.

### Recovery record

The natural switch reconstruction first emitted 618 bytes. Grouping the master-sprite states did not recover the binary tail. Reordering the state cases to match the PDB handler bands, then routing state 3, state 6, and states 1, 2, 13, and 14 through the shared master-sprite tail, produced the 541-byte exact body.

The final cleanup replaced generic virtual slots with named repository methods. It retained the typed task, sprite, world, action, and player surfaces. The source body remains unchanged in the merged module.
