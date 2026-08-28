# BaseGame source-module checkpoint

The PDB module is `C:\msdev\work\age1_x1\basegame.cpp`.

## Direct prefix

`src/basegame.cpp` owns this PDB source-order prefix:

- `0041B620 write_draw_log`, lines 199-205, 44 bytes.
- `0041B650 write_draw_log2`, lines 208-215, 67 bytes.
- `0041E7A0 rge_base_game_wnd_proc`, lines 230-235, 43 bytes.
- `0041B6A0 RGE_Base_Game::RGE_Base_Game`, lines 247-481, 988 bytes.

The direct candidate uses `config/flags/0041BAA0_setup.rsp`.

The four owners use these PDB symbols:

- `?write_draw_log@@YAXPAD@Z`
- `?write_draw_log2@@YAXPAD@Z`
- `?rge_base_game_wnd_proc@@YGKIIII@Z`
- `??0RGE_Base_Game@@QAE@PAURGE_Prog_Info@@H@Z`

The candidate report is
`build/candidate_tus/basegame_prefix_direct/report.json`.
All four rows report `MATCH` and `0.0000%`.

## Provider evidence

`0041E7A0` calls virtual slot `+8` as `__stdcall`.
The PDB symbol is `?wnd_proc@RGE_Base_Game@@UAGJPAXIIJ@Z`.
`include/basegame.h` declares that calling convention.

`0041B6A0` reads `RGE_Prog_Info::instance`.
`src/basegame.cpp` includes the canonical owner `include/main.h`.
`basegame.h` keeps only its forward declaration.

The constructor calls the BaseGame option setters.
Their PDB source rows are `004226B0` through `004228B0`.
`include/basegame.h` now publishes their exact parameter types.

## Hold

`0041BAA0 RGE_Base_Game::setup`, lines 491-871, remains an accepted-drift hold.
It has no exact registration in the direct prefix.
The next exact source move must not cross this owner without separate review.
