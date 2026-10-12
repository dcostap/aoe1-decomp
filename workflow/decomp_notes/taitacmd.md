# taitacmd.cpp source module

The module source is `src/taitacmd.cpp`.

The PDB source is `C:\\msdev\\work\\age1_x1\\taitacmd.cpp`.
The source follows the 216 normal owners in PDB address and source-line order.
The two compiler-generated scalar deleting destructors remain outside this list.

The source reunification selects the full body from each former source-bank file.
It removes bank guards, fallback bodies, and `.cpp` includes.
The module header owns the reviewed class and layout declarations.
It consumes the canonical `TacticalAIModule` and `AIModule` base surface from
`aitacmod.h`.
It consumes canonical `ResourceItem` from `airesitm.h`.
It consumes canonical `InfluenceMap` and `XYPoint` from `infmap.h`.
It consumes canonical `PlacementState` from `ai_placement_state.h`.
`include/tactical_unit_data.h` owns the PDB-proven UnitData record. It is a
`struct`; `gatherer` encodes `PAUUnitData` in its matching symbol.
`include/tactical_old_unit_data.h` owns PDB LF_STRUCTURE records OldUnitData
(0x10) and OldUnitData2 (0x14). The scratch loading constructor reads each
legacy format into its complete typed record. It does not read across objects.
The normalized `004ED4F0` source is observed scratch at 4,993 differing bytes,
with no direct-target mismatch and two boundary escapes. Do not promote it or
treat this record cleanup as a behavior claim.

Current status:

- 169 owners are `matching`.
- 10 owners are `accepted_drift`.
- 35 owners are `scratch`.
- 2 owners are `verified_logic`.

The 47 non-matching owners keep their current status.
The two `verified_logic` owners keep their existing ledgers.

Fresh grouped evidence proves `00502FC0`, `00502FF0`, `00503040`, and
`00503600` exact. All four owners are registered. `004F5FB0` is also matching
and registered.

The final grouped audit checks source order, one compiler-facing owner, and all
registered exact owners from this source.

## Tactical group provider checkpoint

`include/tactical_group.h` now owns the PDB-proven `0x330`
`TacticalAIGroup` layout. It uses canonical `Waypoint` from
`include/waypoint.h`. The owner has named fields and no alias unions or byte
carriers. `taitacmd.h` and `taiinfmd.h` consume this provider.

At this checkpoint, the Tactical grouped candidate kept 109 of 111 registered
rows exact. The Tactical Group owner band remains exact. `004F0D70 addObject`
regressed to a
778-byte mismatch with five boundary escapes. `004F99B0 taskPlay` regressed by
one byte. Both bodies remain in their natural source and are now scratch.
The provider move changed declaration context and Tactical Group member
spelling. The two source bodies are unchanged. Repair them after the next
Tactical ownership surface is complete.

## Final source naturalization pass

The module now uses one canonical declaration for `debug_timeGetTime` near the
source preamble. Its C++ signature is `extern "C" unsigned long __cdecl
debug_timeGetTime(const char*, int)`. The later conflicting declarations were
removed. This fixes the first `doSomething` call before the later task bodies.

The source replaces proven raw member views with typed owners. `sn[]` owns the
tactical strategy values. `zoomingToNextAge` owns `+0xFA4`. `informationAI`
owns `closestDropsiteValue[0]` at `md + 0x122C`. `player->attributes[6]`
owns the age value at `md + 0x1228`. `buildAI`, `resourceAI`, `informationAI`,
and `strategyAI` own their embedded module calls. `lastCoopAttackDemandTime`
owns `+0xFA0`. `RGE_Static_Object::hp` owns object `+0x30`.

The proven strings at `updateAreaName`, debug-time call sites, and log sites
now use typed string literals. One mutable source-path provider serves the
existing `TacticalAIGroup::task`, time, and tribute source forms. No absolute
data address remains in `src/taitacmd.cpp`.

The final full-module build uses `config/flags/gx.rsp`.
The registered grouped gate passes. The module has 169 matching, 10
accepted-drift, 35 scratch, and 2 verified-logic normal owners. Fresh checks
prove `004EA9C0`, `004EEE40`, `00501660`, `00502100`, `00501C70`, and
`00502200` as `MATCH` with `0.0000%` positional difference. `00502920` and
`00502D50` remain scratch after fresh grouped-context mismatches. `004F8E20`
also remains scratch; its typed provider cleanup keeps behavior but changes its
current code size from 1369 to 1365 bytes.

The shared-worktree trial recovered `00500AD0 numberItemsToDefend` as the
natural forwarding call to `md->informationAI.numberItemsToDefend()`. Focused
and complete-module checks report `MATCH` and `0.0000%`, including the correct
relocated tail target. All 169 registered owners match.

## ManagedArray direct-resize migration

The `wave21-resize-taitacmd` pass reconciles the reviewed 52-index plan. The
three `addObject` append sites and five `numberWarshipsWithPriority` append
sites use public `ManagedArray::operator[]`. The two planned
`numberSoldiersWithPriority` append sites use `ManagedArray::add`. The three
`addObject` contains checks remain in place. The priority-count contains checks,
duplicate scans, early returns, and outer loop flow remain in place. The local
elephant-task seed uses `add` as a separate initialization operation. No direct
`resize` call remains in `src/taitacmd.cpp`. `include/utmarray.h` is unchanged.

The full observed audit compiled the `taitacmd` group with one translation
unit, 216 included normal functions, and 170 registered owners. The migration
caused the expected temporary source-group drift in the resize callers. The
audit output is under
`build/audits/workers/wave21-resize-taitacmd/taitacmd-final2/`.
