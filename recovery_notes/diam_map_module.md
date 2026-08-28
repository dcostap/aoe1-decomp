# Diamond map module recovery

## Context

The PDB source module is `C:\msdev\work\age1_x1\diam_map.cpp`.
It owns 27 normal functions from `00436830` through `004387D0`.
The source lines run from 40 through 1450.

`RGE_Diamond_Map` derives from `TPanel`. PDB type evidence gives size
`0x16C`. `RGE_Map_Image_Line` is `0x06`. `RGE_Map_Tile_Row` is `0x24`.

`RGE_Map_Image_Line` uses a `struct` source tag. The original decorated
draw-line symbol has the required `PAU` parameter identity.

`include/diam_map.h` uses the canonical Map, View, DrawArea, panel,
Picture, player, world, and object providers. No Player or UI header changed.

## Direct-source validation

The direct candidate compile has 17 exact owners. Each has `MATCH` and
`0.0000%`:

- `00436830`, `00436930`, `004369C0`
- `00437070`, `00437090`, `004370C0`, `00437120`, `004372C0`
- `00437620`, `00437660`
- `00437C20`, `00437CC0`
- `00438630`, `00438670`, `00438720`, `004387C0`, `004387D0`

The generated deleting destructor at `00436910` also matches.

## Retained nonexact bodies

- `00436A10 set_bitmap`: accepted drift. 359 bytes, 66.3586%.
- `00436C30 set_world`: scratch. 148 bytes, 13.6910%.
- `004374C0 clear_image`: scratch. 210 bytes, 62.5000%.
  The rebuilt body crosses the original boundary twice.
- `004376D0 draw_explored_tiles`: scratch. 66 bytes, 48.1752%.
- `00437760 draw_tile`: scratch. 1065 bytes, 93.0131%.
- `00437EC0 draw_visible_object`: scratch. 336 bytes, 84.6348%.
- `00438060 draw_object`: scratch. 10 bytes, 2.7397%.
- `004381D0 draw_clipped_horz_line`: accepted drift. 40 bytes, 32.5203%.
- `00438250 draw_view_rect`: scratch. 662 bytes, 89.5805%.
  The rebuilt body crosses the original boundary once.
- `00438530 pick_tile`: accepted drift. 10 bytes, 4.0650%.

The two former exact wrapper bodies at `004376D0` and `00438060` are now
scratch. The canonical provider surface changed their code generation.
