# scr_info.cpp source recovery

## Source context

- PDB source: `C:\msdev\work\age1_x1\scr_info.cpp`.
- Direct source: `src/scr_info.cpp`.
- Owner header: `include/scr_info.h`.
- Flags: `config/flags/0049D550_TRIBE_Screen_Info.rsp`.

The PDB owns seven normal functions in this order:

- `0049D550` `TRIBE_Screen_Info::TRIBE_Screen_Info`, lines 32 to 52.
- `0049D600` `TRIBE_Screen_Info::~TRIBE_Screen_Info`, line 58.
- `0049D610` `TRIBE_Screen_Info::handle_idle`, lines 65 to 85.
- `0049D690` `TRIBE_Screen_Info::key_down_action`, lines 91 to 95.
- `0049D6B0` `TRIBE_Screen_Info::mouse_left_down_action`, lines 101 to 104.
- `0049D6C0` `TRIBE_Screen_Info::action`, lines 110 to 112.
- `0049D6E0` `TRIBE_Screen_Info::close_screen`, lines 118 to 189.

`0049D5E0` is the compiler-generated scalar deleting destructor. It has no
source body.

## Canonical providers

`include/Pnl_scr.h` provides `TScreenPanel`. `include/panel.h` provides
`TPanel`, `TPanelSystem`, `panel_name`, and `panel_system`.

`include/basegame.h` provides `RGE_Base_Game` and `debug_timeGetTime`.
`include/rge_base_game_global.h` provides the reviewed `rge_base_game` extern.
`include/tribegam.h` provides `TRIBE_Game::start_menu`.

`include/scr_sing.h` provides `TribeSPMenuScreen`. `include/scr_main.h`
provides `TRIBE_Screen_Main_Menu`.

The generated class record names the original donor header
`src\game\include\TRIBE_Screen_Info.h`. It proves the `TScreenPanel` base,
the `0x484` size, the three fields, and the seven declared bodies. The new
owner header uses only these facts.

## Exact finish

The first direct source used `timer_value != 0` for `auto_close`. The constructor
then differed by 44 bytes. The other six normal bodies and the generated
destructor matched.

`timer > 0` produces the original signed compare and matches the constructor.
`timer_value > 0` also matches. The retained form reads the stored timer. It is
the smaller class-state model after the preceding assignment.

The direct source removes the wrapper, fragments, context header, raw field
store, and absolute string addresses. It uses typed fields, canonical calls,
and string literals.

## Validation

`python tools/validate_candidate_tu.py --proposal
build/candidate_tus/scr_info_natural/proposal.json` reports seven normal
`MATCH` rows and one generated `MATCH` row. Every row has `0` differing bytes,
no relocation-target mismatch, and no boundary escape.
