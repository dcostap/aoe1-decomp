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

Candidate validation at `build/candidate_tus/tmap_natural_exact` compiled all
29 owners. The following 12 exact claims have explicit PDB symbols, matching
owners, relocations, and boundaries:

`0050F7A0`, `0050F7B0`, `0050F800`, `0050FD40`, `0050FDD0`, `0050FE90`,
`00510110`, `00510410`, `00510C10`, `00510C90`, `00510CB0`, and `00511000`.

The other 17 rows remain scratch. This records normal source-composition
regressions without claims from the old wrapper.

## Ten-worker wave audit

The fresh `tmap_cpp` audit keeps 16 registered owners exact. It disproves the
stale exact claim for `00510110 make_new_cliff`, which differs by three bytes.
That owner is now scratch and is not registered as exact. The module has 16
matching bodies and 13 scratch bodies.

The assigned `005100D0 check_cliff_valid` body also remains scratch. Its two
differing bytes come from the canonical `cliff_master_table` offset `0x8DF8`.
The original instruction uses `0x9B40`. The natural body remains unchanged.

## External owner needs

`TRIBE_Map` is a Tmap-owned class. `TRIBE_World` remains the external owner of
`check_destructables`. The source casts `game_world` to that proven derived
receiver for the direct call. No TWorld header changed.
