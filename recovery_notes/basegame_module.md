# BaseGame source-module checkpoint

The PDB module is `C:\msdev\work\age1_x1\basegame.cpp`.

## Direct owners

`src/basegame.cpp` owns this PDB source-order prefix:

- `0041B620 write_draw_log`, lines 199-205, 44 bytes.
- `0041B650 write_draw_log2`, lines 208-215, 67 bytes.
- `0041E7A0 rge_base_game_wnd_proc`, lines 230-235, 43 bytes.
- `0041B6A0 RGE_Base_Game::RGE_Base_Game`, lines 247-481, 988 bytes.
- `0041CDA0 RGE_Base_Game::write_scenario_header`, lines 1503-1518, 89 bytes.

The direct candidate uses `config/flags/0041BAA0_setup.rsp`.

This is a partial provider checkpoint.
`src/basegame_candidate_tu.cpp` still owns the remaining bodies.
It does not complete the BaseGame module.

The direct owners use these PDB symbols:

- `?write_draw_log@@YAXPAD@Z`
- `?write_draw_log2@@YAXPAD@Z`
- `?rge_base_game_wnd_proc@@YGKIIII@Z`
- `??0RGE_Base_Game@@QAE@PAURGE_Prog_Info@@H@Z`
- `?write_scenario_header@RGE_Base_Game@@QAEXH@Z`

The direct candidate report is
`build/candidate_tus/basegame_direct_0041CDA0/report.json`.
All five rows report `MATCH` and `0.0000%`.

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

## Scenario-header overload

The PDB declares the integer overload before the pointer overload.
The integer owner is `0041CE00`.
The pointer owner is `0041CE60`.
VC5 emits the pointer slot at `+0x34`.
It emits the integer slot at `+0x38`.

## Hold

`0041BAA0 RGE_Base_Game::setup`, lines 491-871, remains an accepted-drift hold.
It has no exact registration.

## Command calls

`004212E0` calls World vtable slot `+0xEC`.
The PDB owner is `00540D30 RGE_Game_World::pause(unsigned char)`.
The old `set_world_chat_flag` name was false.

`004212E0` calls Player vtable slot `+0xD4`.
The PDB owner is `00471A70 RGE_Player::command_resign(int, int)`.
Its decorated symbol is `?command_resign@RGE_Player@@UAEEHH@Z`.
It is a public virtual member at slot 53.

The RGE and TRIBE Player vtables both use that owner at slot `+0xD4`.
The PDB and CodeView evidence contain no `set_chat_flag` member.
Do not add that unsupported declaration to `include/player.h`.

The final `004212E0` self call uses BaseGame vtable slot `+0x104`.
The PDB maps it to `RGE_Base_Game::action_user_command(unsigned long,
unsigned long)`.
The base owner is `0041C740`.
The decorated symbol is `?action_user_command@RGE_Base_Game@@MAEHKK@Z`.
`TRIBE_Game` overrides the same slot at `00529A70`.
The old `default_handle_user_command` context name had no PDB support.

`0041EFF0` calls BaseGame virtual slot `+0x88` after its cleanup.
The PDB maps that slot to `setup_comm()`.
The old `reset_comm_tail` context name had no PDB support.

`00421110` calls BaseGame virtual slots `+0xFC` and `+0xBC`.
The PDB maps them to `action_mouse_move` and `handle_idle`.
The old `v_mouse_move` and `handle_mouse_click` context names had no PDB support.

## Complete composition gate

The current PDB plan has 202 normal owners.
The direct source owns five of them.
The candidate wrapper holds the other 197 bodies.

The probe is `build/basegame_composition_probe.cpp`.
It contains all 202 bodies in PDB order.
It uses canonical provider headers.
It does not include `basegame_candidate_context.h`.

The probe does not compile. It exposed these provider gaps:

- The direct probe still uses a stale local `TPanel` declaration.
- BaseGame header-owned helpers lack reviewed canonical declarations.

Some candidate bodies also use raw IAT addresses and false field aliases.
The direct source must replace them with canonical API and field access.

Keep the candidate wrapper until those provider owners repair their interfaces.
Do not add copied contexts or raw access to bypass this gate.

## Canonical field cleanup

`0041C270` now uses `TDrawSystem::ScreenWidth`.
It uses `RGE_Prog_Info::mouse_scroll_interval`.
The 163 registered candidate owners remain exact.

`0041CDA0` now uses canonical World and Scenario providers.
It reads `world->scenario` at `+0x5C`.
It calls the pointer `new_scenario_header` overload at `+0x34`.
It calls `RGE_Scenario_Header::save` at `+0x4`.
`delete header` emits the original direct destructor and operator-delete pair.
