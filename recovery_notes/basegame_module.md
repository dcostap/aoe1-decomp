# BaseGame source-module checkpoint

P0 checkpoint for `C:\\msdev\\work\\age1_x1\\basegame.cpp`.

## PDB order and anchors

The source-line order starts with these owners:

- `0041B620 write_draw_log`, lines 199-205, 44 bytes.
- `0041B650 write_draw_log2`, lines 208-215, 67 bytes.
- `0041E7A0 rge_base_game_wnd_proc`, lines 230-235, 43 bytes.
- `0041B6A0 RGE_Base_Game::RGE_Base_Game`, lines 247-481, 988 bytes.

The two accepted prefix anchors are the first two owners. Their grouped
candidate uses `config/flags/0041BAA0_setup.rsp` and the symbols
`?write_draw_log@@YAXPAD@Z` and `?write_draw_log2@@YAXPAD@Z`.

## Candidate result

One direct grouped candidate was compiled after the prefix wrapper existed:

- `0041B620`: `MATCH`, 44/44 bytes, 0.0000%, no relocation mismatch.
- `0041B650`: `MATCH`, 67/67 bytes, 0.0000%, no relocation mismatch.
- `0041E7A0`: `MISMATCH`, 32 differing bytes, 43/43 bytes.

The final checkpoint keeps only the two exact owners in `src/basegame.cpp`.
It uses `include/basegame.h` directly and defines no owner fallback type.

## First remaining source blocker

`0041E7A0` cannot join this prefix with the current shared header. The header
spells `RGE_Base_Game::wnd_proc` with the default `__thiscall` convention. The
original wrapper uses the stdcall member surface: it pushes `this` as a fifth
argument and calls the slot at `vtable + 8`. The candidate instead loads `this`
into `ECX` and omits that push. The original symbol is
`?wnd_proc@RGE_Base_Game@@UAGJPAXIIJ@Z`; the header selects
`?wnd_proc@RGE_Base_Game@@UAEJPAXIIJ@Z`.

After that ABI blocker, the next owner, `0041B6A0`, needs a complete
`RGE_Prog_Info` definition. `basegame.h` only forward-declares that type.
Do not add either declaration in this module checkpoint.
