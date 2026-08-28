# `Scr_main.cpp` source-module migration

- PDB source: `C:\\msdev\\work\\age1_x1\\Scr_main.cpp`.
- Source: `src/scr_main.cpp`.
- Header: `include/scr_main.h`.
- Flags: `config/flags/default_gx.rsp`.

The PDB owns eleven normal functions in this order:

- `0049E6D0` `TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu`, lines 85 to 193, 1281 bytes.
- `0049EC00` `TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu`, lines 199 to 214, 203 bytes.
- `0049ECD0` `TRIBE_Screen_Main_Menu::handle_idle`, lines 220 to 225, 33 bytes.
- `0049ED00` `TRIBE_Screen_Main_Menu::key_down_action`, lines 231 to 258, 250 bytes.
- `0049EE00` `TRIBE_Screen_Main_Menu::action`, lines 264 to 387, 715 bytes.
- `0049F0D0` `TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error`, lines 395 to 420, 335 bytes.
- `0049F240` `TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error`, lines 426 to 429, 100 bytes.
- `0049F2B0` `TRIBE_Screen_Main_Error::set_text(char*)`, lines 435 to 437, 22 bytes.
- `0049F2D0` `TRIBE_Screen_Main_Error::set_text(long)`, lines 443 to 445, 22 bytes.
- `0049F2F0` `TRIBE_Screen_Main_Error::action`, lines 451 to 474, 80 bytes.
- `0049F340` `TRIBE_Screen_Main_Error::handle_idle`, lines 480 to 484, 33 bytes.

The complete source keeps this PDB order. The former wrapper, source-bank
fragments, fallback declarations, and context header were removed. The bodies
were moved without byte-tuning changes.

The standalone source had nine matching owners and two scratch owners. The
standalone exact owners were `0049EC00`, `0049ECD0`, `0049ED00`, `0049F0D0`,
`0049F240`, `0049F2B0`, `0049F2D0`, `0049F2F0`, and `0049F340`. The constructor
and menu action remain scratch because their prior sources reported mismatches.
The module build can report temporary grouped regressions during this source
shape migration. Exact repair resumes on the final source tree.

The nearby entries `0049EBE0` scalar deleting destructor and `0049F220` vector
deleting destructor are compiler-generated. They are not normal source owners.

## Canonical owner header

`include/scr_main.h` now owns only `TRIBE_Screen_Main_Menu` and
`TRIBE_Screen_Main_Error`. The PDB gives their sizes as `0x4B0` and `0x484`.
It includes only the complete `TScreenPanel` base. The three panel pointer
types are forward declarations. Its source consumes panel, screen, drawing,
Base Game, global, and provider headers privately.

`src/scr_cred.cpp` now includes this header for the complete
`TRIBE_Screen_Main_Menu` fallback. No copied menu screen layout remains.

`src/scr_main.cpp` includes the canonical Credits Screen header privately.

## Constructed-screen providers

The PDB layouts now have owner headers. They replace the former opaque
construction types in `scr_main.cpp`.

- `include/scr_sing.h` owns `TribeSPMenuScreen` from `Scr_sing.cpp`. Its
  size is `0x49C`.
- `include/scr_mp.h` owns `TribeMPStartupScreen` from `scr_mp.cpp`. Its size
  is `0x6A0`.
- `include/scr_sedm.h` owns `TRIBE_Screen_Sed_Menu` from `scr_sedm.cpp`. Its
  size is `0x490`.

Each header includes only `Pnl_scr.h` and forwards pointer-only panel types.
Focused checks compiled their current provider TUs:

- `004B69A0 TribeSPMenuScreen`: `MATCH`, `0.0000%`;
- `004B2EF0 TRIBE_Screen_Sed_Menu`: `MATCH`, `0.0000%`; and
- `0049F890 ~TribeMPStartupScreen`: `MATCH`, `0.0000%`.

## Base Game provider and grouped validation

The Base Game provider landed on `e64411bcb`. It publishes these declarations:

- `int RGE_Base_Game::gameDeveloperMode() const;`
  - VA `00422490`, `basegame.cpp:5176-5178`;
  - symbol `?gameDeveloperMode@RGE_Base_Game@@QBEHXZ`.
- `void RGE_Base_Game::close();`
  - VA `004200B0`, `basegame.cpp:3182-3184`;
  - symbol `?close@RGE_Base_Game@@QAEXXZ`.

It also publishes `RGE_Base_Game::set_paused(int, int)` for Credits. Its VA is
`00420220`, its source is `basegame.cpp:3299-3311`, and its symbol is
`?set_paused@RGE_Base_Game@@QAEXHH@Z`.

`load_db_files` is not a Base Game method. The sole owner is nonvirtual
`int TRIBE_Game::load_db_files()` at `00524530`, `tribegam.cpp:1850-1879`,
with symbol `?load_db_files@TRIBE_Game@@QAEHXZ`. The main source includes
`tribegam.h` privately and uses the reviewed `rge_base_game` pointer through
`static_cast<TRIBE_Game*>`.

Do not add local declarations or change the global pointer type.

After rebase, the canonical candidate compiled all eleven normal owners. The
nine registered exact owners report `MATCH`, `0.0000%`, no relocation-target
mismatch, and no boundary escape. See
`build/candidate_tus/scr_main_canonical/out/report.json`.

The two scratch owners remain observed. `0049E6D0` has 1,140 differing bytes.
`0049EE00` has 435 differing bytes. Neither result has a relocation-target
mismatch or boundary escape.
