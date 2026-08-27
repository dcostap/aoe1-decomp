# rmm_base.cpp source reunification

The PDB source order is lines 23-849. The module owns 24 normal functions from
00480790 through 00481971. The source keeps all bodies in that order.

The 21 matching owners were exact in the prior wrapper. The migration changes
their compiler-facing owner from a source-bank fragment to `src/rmm_base.cpp`.
The focused candidate build is the migration gate.

`remove_module` at 00480A20 remains accepted drift. Its list edits, free call,
return values, boundary, and protected owner symbol match. The 13 differing
bytes are register-color and address-source choices in the list walk.

`randomize_stack` at 00480EC0 remains accepted drift. Its five randomization
calls, list edits, loop counts, and returns match. The remaining difference is
a private local/register basin.

`find_path(Map_Stack&, ...)` at 00481000 remains scratch. The source preserves
the eight-neighbor search and ten ordered helper calls. Its frame, FPU local
homes, and register allocation remain nonexact.

The old wrapper and all 24 source-bank fragments are removed after the direct
module owner is validated. The old context header remains because other
assigned modules include it; this module uses the natural `rmm_base.h` header.

The owner header keeps only the random-map base ABI and `Map_Stack`. `RGE_Map`,
`RGE_Tile`, logging, and global storage declarations stay source-private or
come from the canonical map header.
