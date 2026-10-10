# Tactical AI group type names

## Scope

The starting commit is `c41e6039a`.
This change names the ten `TacticalAIGroup::typeValue` IDs.
It changes `include/tactical_group.h`, `src/taitacmd.cpp`, and `src/tplayer.cpp`.

The macro names are descriptive cleanup names, not recovered original names.
No layouts, signatures, field types, parameters, locals, or registry entries changed.
Group types remain `int` values. The definitions are unsuffixed integer macros in the class owner header.

| Value | Name | Log label |
| --- | --- | --- |
| 100 | `TACTICAL_GROUP_TYPE_ATTACK` | Soldier groups: Attack Group |
| 101 | `TACTICAL_GROUP_TYPE_DEFEND` | Soldier groups: Defend Group |
| 102 | `TACTICAL_GROUP_TYPE_EXPLORE` | Soldier groups: Explore Group |
| 103 | `TACTICAL_GROUP_TYPE_BOAT_ATTACK` | Boat groups: Attack Group |
| 104 | `TACTICAL_GROUP_TYPE_BOAT_DEFEND` | Boat groups: Defend Group |
| 105 | `TACTICAL_GROUP_TYPE_BOAT_EXPLORE` | Boat groups: Explore Group |
| 106 | `TACTICAL_GROUP_TYPE_TRANSPORT` | Boat groups: Transport Group |
| 107 | `TACTICAL_GROUP_TYPE_FISHING` | Boat groups: Fishing Group |
| 108 | `TACTICAL_GROUP_TYPE_TRADE` | Boat groups: Trade Group |
| 109 | `TACTICAL_GROUP_TYPE_ARTIFACT` | Soldier groups: Artifact Group |

## Evidence

Two functions print each group type next to a label from the original executable's strings:

- `TribeTacticalAIModule::displaySoldierGroups`, `004FD8D0`, status `matching`.
- `TribeTacticalAIModule::displayBoatGroups`, `004FFEE0`, status `matching`.

Both functions are byte-exact, so the value-to-label pairing in their source is the executable's pairing.
Group creation agrees: soldier creation paths call `setType` with 100, 101, 102, and 109.
Boat creation paths call `setType` with 103 through 108.

## Substituted contexts

Only values that flow through a group type were named:

- `type()` and `typeValue` comparisons on a `TacticalAIGroup`;
- locals loaded from `type()` (`t`, `gtype`) and the `type` parameter of `bestGroup`;
- `setType`, `group(-1, type, ...)`, `numberGroups`, `numberUnitsInGroups`, `removeAllGroups`,
  `bestGroup`, and `readyAndIdleGroup` type arguments;
- the `bestUnit` loops that iterate over soldier types 100 through 102 and boat types 103 through 106.

The values in these places belong to other domains and stay numeric:

- `targetTypeValue == 109` and `mem->type == 0x6d`. These are object-memory types copied by `setTargetType`.
- `md->object(-1, 109, ...)`, order priorities of 100, strategic-number indices, and build-item types.

## Validation

Artifacts are under `build/cleanup-2026-10-10/`.

- Baseline: a full audit at the starting commit, with all 225 groups compiled and 5,013 exact claims passing.
- Candidate: an audit of the eight groups affected by the three edited files. All 469 exact claims passed,
  and the category counts were unchanged.
- All eight non-debug object payloads match the baseline: section bytes, sizes, flags, relocation targets,
  and symbol identities. The comparison uses `coff_content` from `build/constant-cleanup-compare.py`.
- A negative control confirmed that the comparator reports differing objects.
- `git diff --check` and the line-ending check passed.
- clang-format 21.1.8 rewrapped the longer conditions with the project settings.

No linked executable build, image audit, automated tests, or runtime suites ran.
