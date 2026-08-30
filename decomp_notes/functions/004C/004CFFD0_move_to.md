# Function notes: 004CFFD0 `move_to`

## Earlier notes from `decomp_notes/functions/004C/004CFFD0_move_to.md`

This section is historical. Use the status query for current state.

## TRIBE_Action_Hunt::move_to (004CFFD0)

- PDB source: `C:\\msdev\\work\\age1_x1\\tact_hnt.cpp`, lines 840-883.
- The address sequence and class owner prove this body belongs to `tact_hnt.cpp`.
- The natural source remains in `src/tact_hnt.cpp` at its PDB position.
- Status remains `accepted_drift`.

### Equivalence evidence

The true dropsite path is byte-identical to the original. The remaining six
bytes occur only in the false path parameter-load schedule. Both forms store
`z`, `x`, and `y`, clear the target, enter state `0x0F`, and return `1`.
No call, predicate, cleanup, memory effect, return value, or fault order differs.

The source uses the reviewed typed `RGE_Action` and master-object declarations.
It does not use a manual vtable, byte forcing, or a codegen-only wrapper.
