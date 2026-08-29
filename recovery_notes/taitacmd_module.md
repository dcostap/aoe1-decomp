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

- 178 owners are `matching`.
- 10 owners are `accepted_drift`.
- 26 owners are `scratch`.
- 2 owners are `verified_logic`.

The 36 non-matching owners keep their current status.
Their attempt logs remain beside their source body in this module.
The two `verified_logic` owners keep their existing ledgers.

The reunited context reports localized drift for two unregistered matching-bank
owners. `004F5FB0` differs by 7 bytes. `00503600` differs by 4 bytes and has a
different virtual path slot count. These owners were not registered exact
claims before migration.

Migration validation must check source order, one compiler-facing owner, and the
registered exact owners after the module config points to this source.

## Tactical group provider checkpoint

`include/tactical_group.h` now owns the PDB-proven `0x330`
`TacticalAIGroup` layout. It uses canonical `Waypoint` from
`include/waypoint.h`. The owner has named fields and no alias unions or byte
carriers. `taitacmd.h` and `taiinfmd.h` consume this provider.

The Tactical grouped candidate kept 109 of 111 registered rows exact. The
Tactical Group owner band remains exact. `004F0D70 addObject` regressed to a
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

The final full-module build uses `config/flags/004ED4F0_TribeTacticalAIModule.rsp`.
The registered grouped gate passes. The module has 178 matching, 10
accepted-drift, 26 scratch, and 2 verified-logic normal owners. Fresh checks
prove `004EA9C0`, `004EEE40`, `00501660`, `00502100`, `00501C70`, and
`00502200` as `MATCH` with `0.0000%` positional difference. `00502920` and
`00502D50` remain scratch after fresh grouped-context mismatches. `004F8E20`
also remains scratch; its typed provider cleanup keeps behavior but changes its
current code size from 1369 to 1365 bytes.
