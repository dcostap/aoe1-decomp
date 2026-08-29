# rmm_cntr.cpp source module

`src/rmm_cntr.cpp` owns all six PDB functions in source order.
`include/rmm_cntr.h` owns only the controller declaration.

The header uses canonical random-map, land, terrain, and object owners. It does
not copy DBCT, TDBC, map, or world declarations.

The debug path and `debug_rand` declaration are source-private.

## Status

`004821A0`, `00482260`, and `004828A0` report `MATCH` and `0.0000%` from the
direct module. They are the registered exact owners.

`00482270`, `004826E0`, and `004828B0` remain scratch. Their direct bodies use
typed records and arrays. They do not retain raw cursor or interior-field
pointer scaffolding.

## Fresh exact-policy audit

The PDB assigns `004821A0` to `rmm_cntr.cpp`, lines 42-49. Its original body
is `004821A0-00482254` (181 bytes). The direct compiler-facing owner is
`src/rmm_cntr.cpp`, in the source-module address order recorded above.

The standalone check rebuilt the constructor as
`??0RGE_RMM_Controller@@QAE@PAVRGE_Map@@PAVRGE_Game_World@@EJ@Z`. The original
owner name is `RGE_RMM_Controller`, and the owner check passes. The rebuild
has 181 meaningful bytes, no boundary escape, and no trailing non-padding
body. The 10 relocations are all compatible, with no actionable target
mismatch.

The constructor has five direct calls in the original and rebuilt code:
`__alloca_probe`/`__chkstk`, `RGE_Random_Map_Module`, `add_land_module`,
`add_terrain_module`, and `add_object_module`. The stack-probe name pair is
the VC5 `chkstk.obj` alias at the same helper body. The other direct symbols
match their decorated owners. There are no tail jumps.

The grouped candidate check for the module passes all three registered owners:
`004821A0`, `00482260`, and `004828A0`. The controller header contains only
the controller declaration and forward declarations. The source includes
the canonical record and generator owners. It uses no wrapper, raw address,
manual vtable, or compiler-only alias.
