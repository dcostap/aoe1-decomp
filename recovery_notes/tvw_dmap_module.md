# TVW diamond map module

## Context

The PDB source module is `C:\msdev\work\age1_x1\tvw_dmap.cpp`.

The four normal owners follow PDB line and address order:

1. `0052C9E0`, lines 38 to 41, constructor.
2. `0052CA30`, lines 47 to 54, `set_redraw`.
3. `0052CA60`, lines 60 to 73, `draw_objects`.
4. `0052CAB0`, lines 79 to 95, `draw_object`.

`0052CA00` is the compiler-generated scalar deleting destructor.
The empty virtual destructor at `0052CA20` is emitted by the module source.

## Header evidence

`TRIBE_Diamond_Map_View` is a class derived from `RGE_Diamond_Map_View`.
The PDB type is 0x174 bytes and has two public fields:

- `unsigned long last_attack_time`.
- `int flash_on`.

The fields follow the inherited `RGE_Diamond_Map_View` object.
The PDB virtual order keeps `set_redraw` at the panel redraw slot.
It keeps `draw_objects` and `draw_object` at the map slots.

`include/tvw_dmap.h` uses the canonical `vw_dimap.h` provider.
It does not copy the base class or use placeholder fields.

## Provider chain

`include/scr_game.h` owns `TRIBE_Screen_Game`.
`include/vw_dimap.h` owns `RGE_Diamond_Map_View`.
`include/diam_map.h` owns `RGE_Diamond_Map`.
`include/basegame.h` owns the C++ `debug_timeGetTime` declaration.

The module includes `scr_game.h` and `tvw_dmap.h`.
This order supplies the complete screen provider for the redraw call.

## Validation

`src/tvw_dmap.cpp` is the only compiler-facing owner.
The old wrapper, context header, and four source-bank fragments are removed.

The candidate module check reports `MATCH` for all four normal owners.
Each result has zero positional bytes, boundary escapes, and relocation target
mismatches. The generated deleting destructor also reports `MATCH`.

The focused checks report `MATCH` and `0.0000%` for all four normal owners.
Their direct call targets and relocation counts match the original.

The rebased grouped proof is `build/candidate_tus/tvw_dmap_integration_proof`.
It confirms all four registered owners with no comparison errors.
