# `taiinfmd.cpp` module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\taiinfmd.cpp`.
- Source: `src/taiinfmd.cpp`.
- Header: `include/taiinfmd.h`.
- Flags: `config/flags/004D6BB0_TribeInformationAIModule.rsp`.
- Normal owners: 123.
- Address range: `004D6AD0` to `004E4790`.

## Module migration

The source follows the PDB owner order from lines 103 through 8574. It has one
compiler-facing source owner and one module-local header. The old wrapper,
fragment includes, fallback declarations, context macro, and per-function
source owners were removed.

The source module manifest records all 123 normal owners. It now has 95
matching, 9 accepted-drift, and 19 scratch owners.
Compiler-generated entries `004D6B20`, `004D7050`, `004DE980`, and `004DE9D0`
remain outside the normal owner manifest.

## Provider cleanup

The public header now consumes the canonical `game_globals.h` and
`utmarray.h` providers. Duplicate source-local declarations for file I/O,
random helpers, floating constants, and allocation helpers were removed.
The source now uses direct literals for its known module strings and the
canonical lowercase floating-global spellings. These changes preserve the
PDB source bodies and behavior.

The three fixed `InfluenceMap` objects remain unchanged. Their natural storage
owner and initialization context are not proved, so their absolute carriers
stay under the held-global review.

The merged source retains 56 exact registered owners. Owners `004D9110` and
`004D9160` each have a one-byte natural-context recolor. Owner `004E0FD0` has
an 11-byte merged-context regression. These owners remain scratch.

## Context evidence

The original PDB module is `taiinfmd.cpp`. Its source order is the address
sequence listed in the generated packet. The class owner is
`TribeInformationAIModule`, with the first two static initializers and the
constructor/destructor band preceding its methods. The original FPO dump and
nearby compiler-generated entries provide the boundary and ownership anchors.
The module header keeps the reviewed `InformationAIModule`, `ManagedArray`,
`InfluenceMap`, world/player, and `TribeInformationAIModule` layouts.
`include/taiinf_records.h` owns the PDB-proven ObjectMemory, BuildingLot,
AttackMemory, QuadrantLog, and ResourceMemory record layouts.
`include/ai_attack_state.h` owns the PDB-proven AttackState layout.
`include/ai_placement_state.h` owns the PDB-proven PlacementState layout.
`include/ai_play_phase_command.h` owns the PDB-proven 0x10 class record.
The `PAVAIPlayPhaseCommand` return from `AIPlayPhase::command` proves its
class identity. Its PDB fields are protected. Taiinf consumes its public
accessors without a local copy.
`include/ai_play_phase.h` owns the PDB-proven 0x8C `AIPlayPhase` record.
Taiinf forward-declares it in the public header. The source includes its owner
and uses its public `command` method.
Taicon continues to forward-declare PlacementState in its public signatures.

The record owner uses natural alignment. It has no manual padding carriers.
The Taiinf grouped candidate keeps 56/56 registered exact owners at `MATCH`.
`004D9110` and `004D9160` remain observed scratch with one differing byte
each. Both keep their owner, boundary, and direct targets.

The post-cleanup candidate check for accepted-drift constructor `004D6BB0`
still reports a 94-byte mismatch with matching owner and boundaries. No
registered exact owner regressed.

## Validation

The consolidated source compiles with the pinned VC5 compiler and the module
response file. Migration changes the complete source context, so old exact
results from isolated fragment owners are not claims about the merged source.
Run the registered translation-unit checks after each source-shape repair.

A clean compile reported one existing uninitialized-local warning in the
recovered `loadLearnInfo` path. No inline assembly or synthetic owner is used.

## Ownership hold

Keep the rejected owner-clean packet out of main. It embeds complete
`ConstructionAIModule` at `TribeMainDecisionAIModule +0x6C4`. The full type is
`0x314`. The prior context preserves the PDB-proven later offsets
`tacticalAI +0x1146C` and `aiPlayer +0x1256C`. The rejected header shifts them
to `+0x11780` and `+0x12880`.

The shift causes ABI regressions for `004D9970`, `004D9A90`, `004D9B20`,
`004DA190`, `004DA1C0`, `004DE1F0`, and `004DE4A0`. The first two remaining
rows, `004D9110` and `004D9160`, differ by one SIB recolor byte each.

Do not use a size-one local view or any offset-preserving carrier. It is a
foreign layout. Taiinf resumes only after the Taimd dependency chain supplies
canonical Main Decision and Tactical ownership.

## Legacy wrapper cleanup

The legacy `src/information_dropsites_tu.cpp` wrapper included the taiinfmd
fragment set. The two context headers,
`include/information_dropsites_context.h` and
`include/taiinfmd_prefix_context.h`, had no consumers outside this wrapper
chain. `rg` found no translation-unit entry or other source consumer. The
wrapper and both headers were removed after all included owners moved to this
module.
