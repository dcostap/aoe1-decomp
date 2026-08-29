# t_histry.cpp source module

`src/t_histry.cpp` owns all 11 normal functions from the PDB `t_histry.cpp`
compiland. The source follows PDB line order and shipped address order.

The module uses the canonical providers for `TRIBE_History_Info`,
`RGE_Game_World`, `RGE_Base_Game`, `rge_base_game`, and file I/O. It does not
use a copied class view, a wrapper, a context header, or a translation-unit
scaffold.

`RGE_Base_Game::world` is a protected field in its canonical declaration. The
canonical declaration lists `TRIBE_History_Info` as a friend. The binary proves
the direct `rge_base_game->world->world_time` load in `004CC990`. The source
keeps that access and its fault order.

The constructor, destructor, save and load methods, entry methods, and event
methods retain their shipped behavior. In particular, `load` keeps the
zero-filled terminating event link, and the indexed event overload returns
only when its index is zero.

The full candidate build is recorded in
`build/candidate_tus/t_histry_canonical_providers/report.json`. All 11 owners
return `MATCH`, `0.0000%`, the original boundary, and the expected direct
symbols. The candidate emits no compiler-generated function in this range.
