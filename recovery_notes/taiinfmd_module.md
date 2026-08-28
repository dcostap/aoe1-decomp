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

The source module manifest records all 123 normal owners. It preserves the
prior source-bank status: 98 matching, 9 accepted drift, and 16 scratch.
Compiler-generated entries `004D6B20`, `004D7050`, `004DE980`, and `004DE9D0`
remain outside the normal owner manifest.

The merged source retains 58 exact registered owners. Owner `004E0FD0` has an
11-byte merged-context regression. It is not in the direct exact-owner entry.

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

The record owner uses natural alignment. It has no manual padding carriers.
The Taiinf grouped candidate remains 58/58 exact after the move.

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
