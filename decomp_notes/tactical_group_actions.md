# Tactical AI group action names

## Scope

The starting commit is `7b2f32876`.
This change names 13 `TacticalAIGroup::actionValue` IDs.
It changes `include/tactical_group.h`, `src/taitacmd.cpp`, and `src/taiinfmd.cpp`.

The macro names are descriptive cleanup names, not recovered original names.
The `TacticalAIGroup::task` log strings in the executable are empty, so no text names exist.
No layouts, signatures, field types, parameters, locals, or registry entries changed.

Group actions and `task()` IDs are one domain. Callers store an action and pass it back to `task()`,
for example `cur->task(this, this->md, cur->action(), 1, 0)`.

| Value | Name | Evidence |
| --- | --- | --- |
| 0 | `TACTICAL_GROUP_ACTION_NONE` | Constructor default. Shares the stop-units `task()` case with 1. |
| 1 | `TACTICAL_GROUP_ACTION_IDLE` | `task()` stops every unit and clears `inUseValue`. Most common state check. |
| 2 | `TACTICAL_GROUP_ACTION_ATTACK` | Set for ready attack groups. `task()` sends attackers to the target. |
| 3 | `TACTICAL_GROUP_ACTION_RETREAT` | Set when losses pass `SNPercentHealthRetreat` or `SNPercentDeathRetreat`. `task()` moves to `retreatLocation`. |
| 4 | `TACTICAL_GROUP_ACTION_DEFEND` | Set for ready defend groups. `task()` calls `taskDefender`. |
| 7 | `TACTICAL_GROUP_ACTION_ESCORTED_EXPLORE` | Used after an attack fails. The commander explores, and other units may defend it. |
| 8 | `TACTICAL_GROUP_ACTION_EXPLORE` | Set for ready explore groups. `task()` calls `taskExplorer` for each unit. |
| 9 | `TACTICAL_GROUP_ACTION_GATHER` | `task()` gathers units at `gatherLocation`. |
| 10 | `TACTICAL_GROUP_ACTION_FISH` | Set for fishing groups. `task()` calls `taskWaterFisher`. |
| 11 | `TACTICAL_GROUP_ACTION_TRADE` | Set for trade groups. `task()` calls `taskWaterTrader`. |
| 12 | `TACTICAL_GROUP_ACTION_TRANSPORT` | Set on the transport group assigned to carry another group. |
| 19 | `TACTICAL_GROUP_ACTION_ARTIFACT` | Set for ready artifact groups. |
| 20 | `TACTICAL_GROUP_ACTION_ATTACK_ROUNDUP` | `task()` uses `lastAttackRoundupTime` with a 10-second limit. |

## Values left numeric

- 5 and 6 share the hold-units `task()` case, but no caller sets them in this module.
- 13, 15, and 16 are steps of the transport hand-off. 13 boards units, and 15 follows a full or finished load.
  The difference between 15 and 16 is not clear enough to name.
- 14 shares the gather case with 9. It is used on the terrain-exception path.
- 21 shares the attack case with 2 and changes one branch inside it.
- 22 has no `task()` case. One caller sets action 16 and then calls `task(..., 0x16, 0, 1)`.
  That call reaches the default unknown-task path and returns 0. This is original behavior.

## Substituted contexts

- `setAction(N)` and `action() == N` or `!= N` on a group;
- the `taskID` argument of `task()` and its comparisons, and the case labels in `TacticalAIGroup::task`;
- the action arguments of `bestGroup`, `group(-1, type, action, ...)`, and `numberGroups`.
  `-1` means any action and stays numeric.

## Validation

Artifacts are under `build/cleanup-2026-10-10/group-actions`.

- An audit of the nine groups affected by the three edited files compiled all groups.
  All 529 exact claims passed.
- All nine non-debug object payloads equal the `c41e6039a` baseline, using `compare_objects.py`.
  The commits after that baseline left their payloads unchanged.
- clang-format 21.1.8 rewrapped the longer lines with the project settings.

No linked executable build, image audit, automated tests, or runtime suites ran.
