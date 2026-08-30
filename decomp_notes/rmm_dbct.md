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

`00484160` remains scratch. Its direct record-load order changes fault order.

`00484320` remains scratch. A typed `RGE_Land_Point_Info_Line` cursor has a
10-byte register and address difference. The old exact form used a forbidden
pointer to the `y` field.

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
