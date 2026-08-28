# tplayer.cpp source module

The module now has one compiler-facing owner at `src/tplayer.cpp`.
The source order follows the 103 normal PDB owners from lines 232 through 5335.
The owner header is `include/tplayer.h`.

The module uses the canonical Player, World, Tech, AI, Victory, Command, and
object provider headers. The old translation-unit wrappers and per-function
fragments are removed.

The natural source rebuild passes the six reviewed tplayer context anchors:
00512620, 00514510, 00514700, 00514710, 00515DF0, and 00519D40. Each result is
`MATCH` with `0.0000%` difference, correct ownership, boundary, and relocation
checks.

A full candidate pass compiled all 103 normal owners and both generated
destructors. It reported 35 exact results among 58 matching-status owners and
26 exact results among 45 observed owners. It reported no symbol or comparison
errors. The remaining differences are temporary migration drift.

The source-module state keeps the prior recovery states. Matching owners remain
matching. Narrow equivalent owners remain accepted drift. Unresolved owners
remain scratch. Exact repair continues on the final source tree.

The complete source file compiles with the pinned VC5 host compiler and default
flags. The global translation-unit audit still reports unrelated pre-existing
issues in other modules.
