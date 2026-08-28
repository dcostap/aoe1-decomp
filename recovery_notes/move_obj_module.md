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

Canonical providers changed the emitted result for ten former matching
claims. The changed owners are now scratch in the module manifest. Their
current grouped differences are 3, 2, 113, 1122, 2977, 2912, 1, 29, 34, and
5 bytes in address order. The three accepted-drift entries remain closed.
