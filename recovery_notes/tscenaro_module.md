# tscenaro.cpp source module

The module owns 82 normal functions in PDB source order.

Before canonical composition, the direct translation unit had 79 matching rows
and three accepted-drift rows.

## Canonical composition

`include/tscenaro.h` now includes `scenario.h`. It owns T_Scenario and its
scenario records only. It has no copied Player, World, Tech, Effects, Victory,
or base Scenario declaration.

`src/tscenaro.cpp` includes the required canonical private owners: Player,
Tplayer, World, static object, Effects, Tech, and Tribal Victory. It uses the
published `TRIBE_Victory_Conditions::add_tech(unsigned char, long)` owner.
`RGE_Player::victory_conditions` is the derived Tribal Victory pointer.

The module uses typed scenario fields for saves and single-player victory
records. It no longer uses a union overlay, raw object-ID array, byte cursor,
or `this + offset` layout.

### Validation

`python tools/check_function.py --va 0052A990 --no-history --detail concise`
reports `MATCH` and `0.0000%` for the first constructor.

The first grouped candidate is in
`build/candidate_tus/tscenaro_owner_composition/result/report.json`.
It found four exact rows that change under the natural source. These rows have
scratch status:

- `0052AB90` T_Scenario file constructor: 31 differing bytes.
- `0052AF20` T_Scenario::save: 316 differing bytes.
- `0052B240` T_Scenario::InitializeVictoryValues: 52 differing bytes and one
  boundary escape.
- `0052BBC0` T_Scenario::Save_victory_conditions_into_players: 476 differing
  bytes and one boundary escape.

The reconciled grouped candidate is in
`build/candidate_tus/tscenaro_owner_reconciled/result/report.json`.
It reports `MATCH` and `0.0000%` for all 77 exact owners. `0052B5F0` and
`0052B630` now have exact ownership. `0052C0B0` remains accepted drift in the
natural form.

### Tribal Player downcast

`RGE_Game_World::players` has canonical type `RGE_Player**` in `world.h`.
`WriteDisabledTechnologiesToMainSystem` calls the Tribal-only
`TRIBE_Player::tech_abling` method. The scenario loop starts at player one.
PDB maps `0052ECF0 TRIBE_World::scenario_make_player` to `tworld.cpp`, lines
458-470. That recovered owner stores new `TRIBE_Player` objects in these slots.
The explicit `static_cast<TRIBE_Player*>` therefore expresses the proven
runtime type. No canonical World field has a narrower pointer type. Removing
the cast would lose the required Tribal method surface.

Tworld can consume this canonical TScenario surface. Its own provider gates
still apply.
