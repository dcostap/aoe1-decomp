# move_obj.cpp module recovery

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\move_obj.cpp`.
- Source order is the reviewed address and line sequence from 0045C450 through 00460F40.
- The module has 51 normal owners and 18,917 normal bytes.
- The compiler-facing owner is `src/move_obj.cpp`.
- Shared class and API layouts live in `include/move_obj.h`.
- The nearby 0045C5A0 deleting destructor remains compiler-generated.

## Migration

The former `src/move_obj_tu.cpp` wrapper included one fragment per owner. The
module now defines all 51 normal owners in one source file, in PDB order.
Fallback class declarations, source-bank includes, context macros, and wrapper
machinery are removed. The source keeps the reviewed owner status for each
function in `config/source_modules/move_obj.json`.

The matching owners had standalone exact checks before this structural move.
Grouped output can change when the full source context changes. Such changes
are structural migration regressions, not new behavior claims. Re-run grouped
checks before exact promotion.

## Remaining reviewed status

- `0045D150`, `00460940`, and `00460F40` remain accepted drift.
- `0045C700`, `0045C790`, `0045D3D0`, `0045D6C0`, `0045DB90`, and
  `0045E970` remain scratch.
- `00460210`, `004608D0`, `00460900`, and `00460B20` also remain scratch.
- All other normal owners retain matching status.

## Structural audit

The canonical provider pass compiles all 51 owners from `src/move_obj.cpp`.
The current report is `build/audits/move_obj_final/report.json`. It records 38
matching, 10 scratch, and three accepted-drift source entries.

The pass uses source-only includes for the reviewed sprite, player, moving
master, command waypoint, path system, UnitAIModule, world, game globals,
BaseGame, and file-I/O providers. `include/xyz_point.h` owns the three-int
`XYZPoint` record.

The source now uses `RGE_Sprite::flags`, `Path::initToStart`,
`Path::moveToNextWaypoint`, `RGE_Master_Static_Object::sprite`, and the
aggregate initial-point members. It uses the canonical C++ declarations for
`rge_read`, `rge_write`, and `debug_rand`. Version checks use
`save_game_version` and the lower-case `DAT_00570b54`, `DAT_00570b58`, and
`DAT_00570b5c` globals. No scratch behavior or shared layout changed.

The residue pass removed several unnecessary source forms. The legacy setup
fallback now uses `closestDistanceToWaypoint = 100000.0f`; the checker reports
an exact 862-byte owner and the same `0x47C35000` store. `new_angle` now uses a
direct float assignment; its 18-byte owner remains exact. `facetToNextWaypoint`
now calls `Path` through its typed member; its 34-byte owner remains exact.
The moving-master constructor now uses the proven implicit base conversion; its
333-byte owner remains exact.
The unused `register` hint in `get_waypoint_checksum` and four `debug_rand`
string casts were also removed. They do not change emitted code or the accepted
8-byte drift.

The pass tested the remaining raw and artificial forms. The three action-log
addresses at `0x584C9C`, `0x584C84`, and `0x584C80` map to the original string
records, but replacing them with literals changed module inline decisions and
left `findPath` at 1064 bytes with 1120 differing bytes. Keep those addresses.
Removing `(float*)0` from path calls reduced `doTrivialMove` to 3679 bytes and
did not improve its grouped 2912-byte mismatch; the typed null casts remain.
Typed packed-waypoint indexing caused the extractor to lose the unique owner
record, so the proven three-byte pointer arithmetic remains. `rge_write` needs
the explicit cast because its reviewed ABI takes `void*`, while `waypoint()` is
const. Downcasts to moving-master fields remain required by the base owner ABI.

The final grouped observed audit compiled the authentic module with 51 normal
owners. It reports 38 grouped matches, 10 scratch mismatches, and three
accepted-drift entries. The 38 matches include 15 registered exact owners and
23 unregistered exact owners. The scratch diffs are 3, 2, 113, 1122, 2977,
2912, 1, 29, 34, and 5 bytes in address order. Accepted drift remains 10,
9, and 8 bytes. Five rows still report relocation-target review because the
grouped audit lacks reviewed owner overrides for those source entries.

No declaration in `include/move_obj.h` had a safe shape-only replacement. Its
virtual order, inherited surfaces, field widths, and size check remain tied to
the reviewed PDB and relocation evidence.

Canonical providers changed the emitted result for ten former matching
claims. The changed owners are now scratch in the module manifest. Their
current grouped differences are 3, 2, 113, 1122, 2977, 2912, 1, 29, 34, and
5 bytes in address order. The three accepted-drift entries remain closed.
