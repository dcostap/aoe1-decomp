# rmm_cntr.cpp source module

`src/rmm_cntr.cpp` owns all six PDB functions in source order.
`include/rmm_cntr.h` owns only the controller declaration.

The header uses canonical random-map, land, terrain, and object owners. It does
not copy DBCT, TDBC, map, or world declarations.

The debug path and `debug_rand` declaration are source-private.

## Status

`004821A0` and `00482260` report `MATCH` and `0.0000%` from the direct module.
They are the only registered exact owners.

`00482270`, `004826E0`, `004828A0`, and `004828B0` are scratch. The direct
bodies use typed records and arrays. They do not retain raw cursor or
interior-field pointer scaffolding.
