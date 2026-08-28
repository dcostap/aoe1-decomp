# tscenaro.cpp source module

The module owns 82 normal functions in PDB source order.

The direct translation unit keeps 79 matching owners. The following owners stay accepted drift:

- `0052B5F0` has an 8-byte grouped difference.
- `0052B630` has an 8-byte grouped difference.
- `0052C0B0` has a 7-byte scheduling difference.

The source merge does not change their recovery status.

`tscenaro.h` includes `tplayer.h`. It no longer defines a local TRIBE_Player
or TRIBE_Player_Tech surface. Calls use tech_abling(long, unsigned char).
tscenaro.cpp includes tech.h for check_for_new_tech().
The fanout candidate has 79 exact matches.

## Composition hold

The canonical-owner candidate is held. `include/tscenaro.h` cannot remove its
foreign bodies until these owner edges compose.

### Tribal Victory `add_tech`

`T_Scenario::Save_victory_conditions_into_players` calls `add_tech` for the
technology condition. The old T_Scenario header incorrectly puts that method
on `RGE_Victory_Conditions`.

The PDB names the real method
`?add_tech@TRIBE_Victory_Conditions@@QAEEEJ@Z`. It is `unsigned char
__thiscall TRIBE_Victory_Conditions::add_tech(unsigned char, long)` at
`0052C9B0`, in `tvictory.cpp:71`. `TRIBE_Victory_Conditions` derives from
`RGE_Victory_Conditions`. Both types are `0x20` bytes. The derived class adds
no fields.

Route the method through the canonical `include/tvictory.h` owner. Do not add
it to `include/victory.h`. The Player victory-condition declaration must prove
the derived static type before T_Scenario can call the derived-only method.

### Base Game `prog_mode`

`T_Scenario::set_player_tech` reads `rge_base_game->prog_mode`. The old
T_Scenario header declares a local `RGE_Base_Game` body only for that field.

The PDB type is `0xA24`. It has `prog_info` at `+0x0C` and `prog_mode` at
`+0x1B0`. The canonical owner is `include/basegame.h`; the global owner is
`include/rge_base_game_global.h`. Terra 5 owns both surfaces.

`include/scenario.h` currently declares another partial `RGE_Base_Game`. It
conflicts with `basegame.h` when T_Scenario consumes the canonical owner.
Terra 5 must remove that Scenario-local Base Game body and preserve the
canonical 0xA24 layout. T_Scenario must then include the canonical owner. Do
not add a local field, cast, overlay, or compatibility declaration.

### Validation and reopening

The owner-composition candidate retained the proven `T_Scenario` size `0x514C`,
base slots, constructors, and derived offsets. Its grouped validation stopped
at the two owner errors above. Evidence is in
`build/candidate_tus/tscenaro_owner_composition/composition_report.json`.

Keep Tworld held. Reopen the T_Scenario owner only after the canonical Tribal
Victory and Base Game surfaces compose with `include/scenario.h`.
