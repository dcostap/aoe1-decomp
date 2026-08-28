# tmap.cpp source module

`src/tmap.cpp` is the compiler-facing source for
`C:\msdev\work\age1_x1\tmap.cpp`. It owns 29 normal functions in PDB order.
The scalar-deleting destructor at `0050F740` is generated.

`include/tmap.h` owns `TRIBE_Map`, `TRIBE_Cliff_Info`, and
`TRIBE_Master_Cliff_Info`. The module consumes canonical Map, Player, Object,
World, and random-map owners. It does not use a context selector, copied
foreign class, manual vptr, raw Tile layout, or field alias.

## Validation

The pinned VC5 compiler builds `src/tmap.cpp` with
`config/flags/0050F410_TRIBE_Map.rsp`.

Candidate validation at `build/candidate_tus/tmap_natural` compiled all 29
owners. Twelve rows matched byte-for-byte. Seven overloaded rows need explicit
symbol selection. Ten rows remain nonexact. This checkpoint registers no exact
rows.

The natural source keeps each row in scratch. This avoids claims from the old
wrapper. It also records normal source-composition regressions.

## External owner needs

`TRIBE_Map` is a Tmap-owned class. `TRIBE_World` remains the external owner of
`check_destructables`. The source casts `game_world` to that proven derived
receiver for the direct call. No TWorld header changed.
