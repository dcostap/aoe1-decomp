# rmm_dbct.cpp source module

`src/rmm_dbct.cpp` owns all twelve PDB functions in source order.
`include/rmm_dbct.h` owns the controller and database records.

The source uses canonical Map, Land, Terrain, Object, Elevation, World, and
base-module headers. It has no local context header, wrapper, copied class,
raw byte cursor, integer cursor, or alias union.

## Current validation

The grouped source compile succeeds with
`config/flags/gx.rsp`.

These direct owners report `MATCH` and `0.0000%`:

- `00483020` constructor from file
- `00483200` destructor
- `004832E0` save
- `00483430` generate
- `00483540` init
- `004835A0` de_init

`00482B70`, `00483600`, and `00483A20` remain scratch. Their direct source
uses typed records and explicit field access.

`00484160` remains scratch. Fresh configured-`gx` validation reports a 448-byte
body with 16 differing bytes, a `0x0C` frame, 137 instructions, and one aligned
`__ftol` call. The raw edit cost is 14. The only strict mismatch is the initial
width/height/grown-percent multiplication order at `+0x1E`.

`00484320` remains accepted_drift. A typed
`RGE_Land_Point_Info_Line` cursor has a 10-byte register and address
difference. The old exact form used a forbidden pointer to the `y` field.

`00484470` remains accepted drift. It uses typed elevation and land records.

## Header evidence

The controller size is `0x4F5C`. Its `world`, `map_type`, and player count are
at `+0x30`, `+0x34`, and `+0x38`. Database records use their measured widths.

The direct header includes the canonical Land, Terrain, Object, and Elevation
record owners. It does not copy their declarations.

## Reopen conditions

Reopen `00484320` only with a natural typed source form that retains the
typed record cursor and removes its final ten-byte difference.

Reopen `00484160` only with evidence that proves its full-width load order and
fault behavior.

Worker `sa-b6a39359-r1` tested map-pointer declaration initialization, counter
initialization, area/count order, scalar field locals, and a typed land aggregate
alias. These variants emitted the same configured-TU body. Moving terrain-count
publication before area calculation produced a 449-byte non-invariant body.
The retained direct typed source preserves area calculation before publication.
The original body has no allocation or explicit failure call.

## Worker pass: rmm_dbct

The unchanged `00483A20` source passed a fresh one-job closure check and final
target validation. It remains a natural typed reconstruction with the proven
land expansion, field publication, distance and relation phases, and ordered
calls. The target PDB's one-based `long[8]` homes remain unsafe source bounds
without a proven land-count limit. Completed `00483600` land-start and
`00484160` terrain-module evidence was preserved. No shared header or global
defect was found. Further probes need new source or compiler-context evidence.

## Accepted-drift repair pass: repair-06

`00484320` now uses direct typed destination indexing. This restores the
original `x`, `y`, `id`, then `player_id` memory order. Its remaining 12-byte
difference exchanges two non-faulting address calculations.

`00484470` is not safe accepted drift. Its generated dimension reads and rule
field writes do not keep original fault order. No source change is retained.
The neighboring `00484320` edit changes its grouped result from 373 to 183
positional differences, so `00484470` is in the affected closure.
