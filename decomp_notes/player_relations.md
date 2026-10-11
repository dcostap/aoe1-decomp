# Player relations and unit-diplomacy lists

`include/player.h` names two related sets of values.

## `RGE_Player::relations`

| Value | Macro | Evidence |
| --- | --- | --- |
| 0 | `RGE_RELATION_ALLY` | `RGE_Player::isAlly` and `UnitAIModule::isAllyOwner` test it. |
| 1 | `RGE_RELATION_NEUTRAL` | `isNeutral` and `isNeutralOwner` test it. New players start with it. |
| 3 | `RGE_RELATION_ENEMY` | `isEnemy` and `isEnemyOwner` test it. |

These are developer function names, so the macros restate them. No code tests value 2.

## `RGE_Player::unitDiplomacy`

`RGE_Player::set_relation` and the two load paths store one list index per player.
`Visible_Unit_Manager::GetVisibleUnits` uses the index to sort visible units into
`VisibleUnitList[0..4]`.

| Value | Macro | Assigned for |
| --- | --- | --- |
| 0 | `UNIT_DIPLOMACY_GAIA` | player 0 |
| 1 | `UNIT_DIPLOMACY_SELF` | the player itself |
| 2 | `UNIT_DIPLOMACY_ALLY` | relation 0 |
| 3 | `UNIT_DIPLOMACY_NEUTRAL` | relation 1 |
| 4 | `UNIT_DIPLOMACY_ENEMY` | any other relation |

`UnitAIModule::closestObject` matches its `desiredRelation` argument against these lists. Its
encoding is different:

| `desiredRelation` | Lists it matches |
| --- | --- |
| 0 | self or ally |
| 1 | neutral |
| 2 | enemy |
| 3 | self |

Callers pass `desiredRelation` as a literal, and it has no name.

Validation: a full translation-unit audit kept all 5,013 exact claims. 224 of 225 object payloads
equal the baseline. The one difference is `rmm_tdbc.obj`, from the earlier include change.
