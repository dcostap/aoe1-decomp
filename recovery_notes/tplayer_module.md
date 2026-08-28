# tplayer.cpp source module

The module now has one compiler-facing owner at `src/tplayer.cpp`.
The source order follows all 103 normal PDB owners.
The owner header is `include/tplayer.h`.

The module uses the canonical Player, World, Tech, AI, Victory, Command, and
object provider headers. The old translation-unit wrappers and per-function
fragments are removed.

The natural source rebuild passes the six reviewed tplayer context anchors:
00512620, 00514510, 00514700, 00514710, 00515DF0, and 00519D40. Each result is
`MATCH` with `0.0000%` difference, correct ownership, boundary, and relocation
checks.

A full candidate pass compiled all 103 normal owners and both generated
destructors. The final `/GX` comparison pass carried 35 exact candidates and
68 observed candidates. It reported 35 exact results and 31 observed exact
results. It reported no symbol or comparison errors. Twenty-three former
matching owners were demoted to scratch after natural-source cleanup exposed
compiland drift.

The source-module state keeps matching status only for the 35 exact owners.
Fourteen earlier accepted-drift owners remain accepted drift. Twenty-three
former accepted-drift owners now remain scratch. Exact repair continues on the
final source tree.

The source uses canonical semantic global aliases and supported literals. It
does not use raw `DAT_*` names. Local command payloads use stack storage. The
three dialog result arrays retain C allocation because the dialog provider
releases them with `free()`. Object-group property storage has an owned
definition and the three tactical fields use their proven PDB offsets.

The complete source file compiles with the pinned VC5 host compiler and module
`/GX` flags. The global translation-unit audit still reports unrelated
pre-existing issues in other modules.
