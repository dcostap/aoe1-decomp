# tscenaro.cpp source module

The module owns 82 normal functions in PDB source order.

## Canonical composition

`include/tscenaro.h` includes `scenario.h`. It owns T_Scenario and its
scenario records only. It has no copied Player, World, Tech, Effects, Victory,
or base Scenario declaration.

`src/tscenaro.cpp` includes the canonical Base Game, Effects, Player, Scenario,
Static Object, Tech, TPlayer, Tribal Victory, and World headers. The global
Base Game pointer comes from `rge_base_game_global.h`. The Base Game owner
grants source access to its protected `prog_info` and `prog_mode` fields for
the two Scenario owners.

The module uses typed scenario fields for saves and single-player victory
records. It has no union overlay, raw object-ID array, byte cursor, or
`this + offset` layout.

`RGE_Scenario::victory_conquest` is an unsigned byte. This preserves the
zero-extension in the file constructor and matches the canonical setter type.

### Exact source shape

The file constructor keeps the original version gates and typed field reads.
The save body uses typed `Player_Start_Info` and `SP_Victory_Info` row loops
with the original fixed byte counts.

`InitializeVictoryValues` clears the typed record storage through an `int*`
record-field pointer. VC5 then emits the original `rep stosd` body.

`Save_victory_conditions_into_players` uses a typed pointer to `AttribType`.
The proven record anchor preserves the original field walk and call order.
It is not a raw overlay.

`WriteDisabledTechnologiesToMainSystem` uses a typed pointer at the second
disabled-technology field. Its negative first-field access and row stride
preserve the original byte extraction order. The Tribal player cast is
required because the canonical World field is `RGE_Player**`, while this loop
calls the Tribal-only `tech_abling` method.

### Validation

The final grouped candidate is in
`build/candidate_tus/tscenaro_natural_final/report.json`. It reports
`MATCH` and `0.0000%` for all 82 module owners. It reports zero boundary
escapes, zero relocation differences, and zero direct-target differences.

The module metadata and registered translation unit list all 82 owners as
matching.
