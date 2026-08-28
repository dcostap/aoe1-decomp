# TVW diamond map provider block

## Result

Do not register a direct `tvw_dmap.cpp` source yet.

The four normal owners remain in their existing source-bank files.
The old wrapper remains the compiler-facing source.

## Required providers

A direct source must use these declarations:

- `RGE_Diamond_Map` from `include/diam_map.h`.
- `RGE_Diamond_Map_View` from `include/vw_dimap.h`.
- `TRIBE_Screen_Game` from its owner, `include/scr_game.h`.
- `debug_timeGetTime` from its canonical C++ provider.

The redraw body needs this typed call:

```cpp
static_cast<TRIBE_Screen_Game*>(this->parent_panel)
    ->set_map_buttons_redraw(mode);
```

## Provider result

`include/vw_dimap.h` now includes `include/diam_map.h`. It owns only
`RGE_Diamond_Map_View`.

The complete `vw_dimap.cpp` candidate matches its twelve normal owners. Its
generated deleting destructor also matches.

`include/basegame.h` now declares the C++ `debug_timeGetTime` function.

## Current block

`include/scr_game.h` still defines `TPanel`, `RGE_View`, `RGE_Diamond_Map`,
`RGE_Player`, `RGE_Game_World`, and `RGE_Base_Game`. It defines
`TRIBE_Screen_Game` after those duplicate declarations.

Including `scr_game.h` with `diam_map.h` causes class redefinitions. Its
`debug_timeGetTime` declaration also has C linkage and a mutable path.

A partial `TRIBE_Screen_Game` declaration would make the call compile. It
would not be a canonical owner declaration. Do not add it.

## Next work

Split or compose `scr_game.h` without duplicate panel, map, view, world, and
player classes. Replace its time-function declaration with the Base Game
provider.

After that work, recreate the direct source and validate all four normal
owners and the generated deleting destructor.
