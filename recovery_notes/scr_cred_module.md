# scr_cred.cpp source reunification

## Source context

The PDB source is `C:\\msdev\\work\\age1_x1\\scr_cred.cpp`.

It owns sixteen normal functions in this address order:

`004926E0`, `00492970`, `00492A40`, `00492A50`, `00492CC0`, `00492D50`,
`00492D70`, `00492DB0`, `00492E70`, `00492F70`, `00492F80`, `00492FB0`,
`00493070`, `00493160`, `00493420`, and `00493540`.

`TRIBE_Credits_Screen` owns the first eight methods.
`TScrollTextPanel` owns the next six methods. The last two owners are palette
functions. The scalar deleting destructor at `00492950` and vector deleting
destructor at `00492F50` are compiler generated.

The PDB gives `TScrollTextPanel` size `0x198` and
`TRIBE_Credits_Screen` size `0x8B8`. The canonical bases are `TTextPanel`
and `TScreenPanel`.

## Canonical ownership

`include/scr_cred.h` owns only `TScrollTextPanel` and
`TRIBE_Credits_Screen`. It consumes the canonical panel, screen, text,
drawing, shape, font, Base Game, and control surfaces.

`src/scr_cred.cpp` uses canonical field and virtual names. It includes
`music.h` privately for `TMusic_System`. It has no copied foreign layout,
local vtable, context macro, or raw cursor.

The source keeps `TRIBE_Screen_Main_Menu` opaque. That class belongs to
`scr_main.cpp`. Its current header copies the screen hierarchy.

## Provider handoffs

### Base Game pause method

The owner is `RGE_Base_Game::set_paused(int, int)` at `00420220`.

The PDB places it in `basegame.cpp`, lines 3299 through 3311. Its symbol is
`?set_paused@RGE_Base_Game@@QAEXHH@Z`. The current matching body is
`src/matching/00420220_set_paused.cpp`. A focused check returns `MATCH` and
`0.0000%`.

`include/basegame.h` does not yet publish this nonvirtual method. The Base Game
owner must add that one declaration beside `get_paused()`. Do not add it here.

`RGE_Base_Game::singlePlayerGame() const` is already published. It calls
`004223F0` from the same `basegame.cpp` provider.

### Main-menu screen

The fallback in `TRIBE_Credits_Screen::close_screen` constructs
`TRIBE_Screen_Main_Menu` at `0049E6D0`. The original allocates `0x4B0` bytes
at `00492E0B`. This provider belongs to `scr_main.cpp`.

`scr_cred` must wait for a composable `scr_main` owner header. Do not add a
local menu layout or allocation substitute.

## Status

The source now has one natural compiler-facing owner for this PDB module.
The accepted-drift owner `00492FB0` and scratch owner `00493160` retain their
reviewed status.

The prior grouped exact audit used the old copied panel header. It is useful
codegen evidence only. It does not validate this canonical composition.

A focused canonical compile stopped only at these two provider boundaries:

- `RGE_Base_Game::set_paused(int, int)` is not declared in `basegame.h`.
- `TRIBE_Screen_Main_Menu` is incomplete at its fallback construction.

No comparison ran after those compile errors. Re-run the grouped module check
when both provider headers are available.
