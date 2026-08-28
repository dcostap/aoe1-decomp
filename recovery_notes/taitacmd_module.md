# taitacmd.cpp source module

The module source is `src/taitacmd.cpp`.

The PDB source is `C:\\msdev\\work\\age1_x1\\taitacmd.cpp`.
The source follows the 216 normal owners in PDB address and source-line order.
The two compiler-generated scalar deleting destructors remain outside this list.

The source reunification selects the full body from each former source-bank file.
It removes bank guards, fallback bodies, and `.cpp` includes.
The module header owns the reviewed class and layout declarations.

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
