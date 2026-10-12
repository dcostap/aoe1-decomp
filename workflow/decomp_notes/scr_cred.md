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

The source gets the complete `TRIBE_Screen_Main_Menu` type from `scr_main.h`.
That header owns no foreign screen hierarchy.

## Provider handoffs

### Base Game pause method

The owner is `RGE_Base_Game::set_paused(int, int)` at `00420220`.

The PDB places it in `basegame.cpp`, lines 3299 through 3311. Its symbol is
`?set_paused@RGE_Base_Game@@QAEXHH@Z`. The current matching body is
`src/matching/00420220_set_paused.cpp`. A focused check returns `MATCH` and
`0.0000%`.

The Base Game owner published this nonvirtual method beside `get_paused()` in
main commit `e64411bcb`. Do not redeclare it here.

`RGE_Base_Game::singlePlayerGame() const` is already published. It calls
`004223F0` from the same `basegame.cpp` provider.

### Main-menu screen

The fallback in `TRIBE_Credits_Screen::close_screen` constructs
`TRIBE_Screen_Main_Menu` at `0049E6D0`. The original allocates `0x4B0` bytes
at `00492E0B`. This provider belongs to `scr_main.cpp`.

`include/scr_main.h` now publishes the complete canonical class. The credits
source includes that owner header privately. No local menu layout or allocation
substitute remains.

## Source cleanup

The source now uses panel-name and debug-file literals. It uses `_O_BINARY`,
`SEEK_END`, and `SEEK_SET` for the credits file. It also uses the named
`DAT_00572968` global rather than an absolute float dereference.

The text setup uses a typed null local. This selects the `char*` overload
without a cast.

The source also removes unnecessary panel downcasts and debug-string casts.

## Status

The source now has one natural compiler-facing owner for this PDB module.

After the Base Game provider landed on `e64411bcb`, the canonical candidate
compiled all sixteen normal owners. All fourteen exact owners report `MATCH`,
`0.0000%`, no relocation-target mismatch, and no boundary escape. See
`build/candidate_tus/scr_cred_canonical/out/report.json`.

The accepted-drift owner `00492FB0` remains observed. Its grouped result has
84 differing bytes. The scratch owner `00493160` remains observed with 614
differing bytes. Neither result changes its reviewed status.

## Grouped compile debt

The canonical global header now owns the credits palette state with the types
proved by `RGE_fade_palette_start`: two 256-entry `PALETTEENTRY` tables, the
fade fields, and the active `TDrawArea*`. The module keeps matching declaration
order for VC5 context. The module no longer redeclares
`debug_timeGetTime` with C linkage. `basegame.h` owns its C++ declaration and
the `?debug_timeGetTime@@YAKPADH@Z` symbol.

The candidate compile reaches only protected `RGE_Base_Game` access errors:

- `TRIBE_Credits_Screen` needs `draw_area` at source line 62.
- `TRIBE_Credits_Screen` needs `music_system` at source lines 105 and 127.
- `TRIBE_Credits_Screen` needs `save_paused` at source line 289.

The central access agent must add the evidence-backed `RGE_Base_Game` friend
relation for `TRIBE_Credits_Screen`. Do not replace these reads with wrappers,
raw offsets, or unrelated global state. No `basegame.h` change was made here.
Representative registered-owner checks remain blocked by this relation.
