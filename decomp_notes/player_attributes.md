# Player attribute slots

`RGE_Player::attributes` is a float array. Slots 0 to 3 are the resources, named
`RGE_RESOURCE_FOOD`, `WOOD`, `STONE`, and `GOLD` in `include/player.h`. The other slots now have
`PLAYER_ATTRIBUTE_*` macros in the same header.

The developer names are not available. The PDB has no enum for them, and the expansion
`languagex.dll` holds only 358 delta strings. The base-game language DLL is not in the repository.
Each name is therefore a cleanup label taken from what the code does with that slot. The one
developer string found is the `"  Writing=%f\n"` debug print of slot 50 in `tribegam.cpp`. Writing
is the technology that shares allied line of sight.

| Slot | Macro | Evidence in the code |
| --- | --- | --- |
| 4 | `POPULATION_HEADROOM` | The population panel shows `pop + [4]` as the maximum. Houses change it. Units cost it as build type 4. |
| 6 | `CURRENT_AGE` | Saved as `save_age`. `age + 100` gives the next age technology. |
| 7 | `ARTIFACTS` | Summed per team against `artifact_count` for the artifact victory. |
| 9 | `TRADE_GOODS` | Trade carts take goods from it. `update` adds slot 10 each tick, up to 100. |
| 10 | `TRADE_PRODUCTION` | Added to slot 9 each update. |
| 11 | `POPULATION` | Compared with slot 32 before training. Shown as population. |
| 13 | `DISCOVERIES` | Shown with slots 7 and 14 as artifacts/discoveries/ruins. |
| 14 | `RUINS` | Summed per team against `ruin_count` for the ruins victory. |
| 19 | `TOTAL_UNITS_OWNED` | `[19] - [11]` is shown as units lost. |
| 20 | `KILLS` | Shown as kills. Used in slot 44. |
| 21 | `TECHNOLOGY_COUNT` | Shown in the statistics. Reset on load. |
| 22 | `PERCENT_EXPLORED` | `percentExplored() * 100`. |
| 23 | `BRONZE_AGE_TECH` | A Bronze Age scenario start researches slot 25, then slot 23. |
| 24 | `IRON_AGE_TECH` | An Iron Age start researches 25 and 23, then 24. |
| 25 | `TOOL_AGE_TECH` | A Tool Age start researches only slot 25. |
| 26 | `ATTACK_WARNING_SOUND` | Indexes `world->sounds` for the attack warning. |
| 27 | `PRIEST_CONVERSION` | When it is zero, priests (group 0x12) cannot be converted. |
| 28 | `BUILDING_CONVERSION` | When it is zero, buildings (group 3) cannot be converted. |
| 29 | `GOLD_REPLACEMENT` | When it is below 1, `TRIBE_Player::check_obj_cost` and `TRIBE_Player_Tech::tech_cost` cannot cover a missing resource with gold. |
| 32 | `POPULATION_LIMIT` | Training stops when slot 11 reaches it. `check_obj_cost` reports it as the missing attribute. |
| 33 | `FOOD_MAINTENANCE` | Food drains by `dt * [33] * [11] / 60`. |
| 35 | `FAITH_RECHARGE_RATE` | Each tick, priests regain `[35] * dt` faith. |
| 37 | `CIVILIAN_POPULATION` | Counts civilians, fishing boats, and trade boats as they are created and destroyed. |
| 39 | `ALL_TECHNOLOGIES` | Set to 1 when no technology is left to research. |
| 40 | `MILITARY_POPULATION` | Counts military units and towers as they are created and destroyed. |
| 41 | `CONVERSIONS` | `TRIBE_Action_Convert` adds 1 after each successful conversion. |
| 44 | `KILLS_MINUS_LOSSES` | `[20] - ([19] - [11])`, clamped at 0. |
| 46 | `TRIBUTE_FEE` | The fraction charged on tribute. The diplomacy dialog shows it as a percent. |
| 49 | `GOLD_EARNED` | `add_attribute_num` adds earned gold to it. |
| 50 | `ALLIED_LOS` | Adding to it or loading a positive value turns on `allied_LOS_Enable`. The debug label is "Writing". |
| 53 | `TRIBUTE_SENT` | A tribute command adds the amount plus the fee to the sender, and subtracts the amount from the receiver. |
| 54 | `ALL_RUINS` | Set when one team holds every ruin. |
| 55 | `ALL_ARTIFACTS` | Set when one team holds every artifact. |
| 56 | `HEAL_RATE` | Multiplies the heal work in `tact_hea.cpp`. |
| 57 | `MARTYRDOM` | When it is at least 1, a dying priest calls `martyrdom()` on its conversion. |

These slots stay numeric because their use does not identify them:

| Slot | What the code does |
| --- | --- |
| 30 | Reset to 0 on load. The `nofoodcap` argument sets it to 500. |
| 31 | The `nofoodcap` argument sets it to 5000. |
| 36 | The timer of `RGE_Action_Make`. |
| 45 | Set to 0 when the player loses all qualifying units. |
| 48 | Set by a scenario disabled-technology slot. It changes builder handling when the Town Center is unavailable. |

The same pass named related literals:

- the `TRIBE_Player::rev_tech` case labels and their scenario arguments, which are slots 23 to 25;
- the `check_obj_cost` build types 3 and 4 and its missing-attribute values;
- the slot test in `add_attribute_num`;
- the priest and building groups in the conversion check;
- `'O'` and `'E'` in `TRIBE_Combat_Object`, which are master IDs 79 (Watch Tower) and 69 (Guard
  Tower).

## `TRIBE_Player::check_obj_cost` locals

The PDB names two locals in this function: `inventory_cost` and `gold_replace`. In the source they
were called `amount` and `population`. The local called `population` held
`attributes[RGE_RESOURCE_GOLD]`, or 0 when slot 29 is below 1. The function uses it to cover a
missing resource with gold, so it is `gold_replace`. The local called `amount` held
`build_inventory[i].amount * modifier`, so it is `inventory_cost`. The bool that records whether
slot 29 allows this is held in a register, so it has no PDB name; it is now
`gold_replace_allowed`.

The PDB stack offsets for these two locals do not match the original stack slots (`00513AF0`), so
the names were matched to the locals by their use, not by their offsets.

Validation: a full translation-unit audit kept all 5,013 exact claims. 224 of 225 object payloads
equal the baseline. The one difference is `rmm_tdbc.obj`, from the earlier include change.
